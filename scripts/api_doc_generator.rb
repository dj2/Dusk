#!/usr/bin/env ruby

require 'json'
require 'yaml'

BASE_DIR = File.expand_path(File.join(File.dirname(__FILE__), ".."))
DAWN_JSON = File.join(BASE_DIR, "third_party", "dawn", "dawn.json")
API_YAML = File.join(BASE_DIR, "src", "api.yaml")

WEBGPU_URL = "https://webgpu.dev"

data = JSON.parse(File.open(DAWN_JSON).read)
['_comment', '_doc', '_metadata'].each { |n| data.delete(n) }

$category_map = {
  'enum' => 'enum',
  'structure' => 'structure',
  'object' => 'class',
  'bitmask' => 'bitmask',
  'function' => 'function',
  'function pointer' => 'function-pointer'
}

@categories = {}
$kinds = {}
data.each_pair do |k, v|
  @categories[v['category']] ||= []
  v['name'] = k
  @categories[v['category']] << v

  $kinds[v['name']] = $category_map[v['category']]
end

$native_types = {}
@categories['native'].each do |v|
  $native_types[v['name']] = true
end

$chain_in = {}
$chain_in_parents = {}

@categories['structure'].each do |struct|
  if struct['chained'] == 'in'
    $chain_in_parents[struct['name']] = struct['chain roots']

    struct['chain roots'].each do |root|
      $chain_in[root] ||= []
      $chain_in[root] << struct['name']
    end
  elsif struct['chained'] == 'out'
    puts "FOUND CHAINED OUT #{struct['name']}"
  end
end

@info = YAML.load(File.open(API_YAML).read)

class String
  def CamelCase
    split(' ').map { |s| s = "#{s[0].capitalize}#{s[1..]}" }.join
  end

  def ParamCase
    parts = split(' ')
    "#{parts[0]}#{parts[1..].map { |s| s = "#{s[0].capitalize}#{s[1..]}" }.join}"
  end

  def UpSnakeCase(prefix = "")
    p = split(' ').map { |s| s.upcase }.join("_")
    return p if prefix.empty?
    "#{prefix}_#{p}"
  end
end

class NilClass
  def strip
    ""
  end
end

def order_by_name(items)
  items.sort { |a, b| a['name'] <=> b['name'] }
end

def gen_header(f, name, length = 2)
  f.puts "#{'#' * length} #{name}"
  f.puts ""
end

def gen_linked_header(f, prefix, name, suffix, lvl, id_kind, &block)
  prefix = "#{prefix} " unless prefix.empty?
  suffix = " #{suffix}" unless suffix.empty?

  gen_header(f,
    "#{prefix}#{block.call(name)}#{suffix} {##{id_kind}-#{name.CamelCase}}",
    lvl)
end

def gen_table(f, lang, name, values, info, &block)
  f.puts ""
  f.puts "| Value | Description |"
  f.puts "|:------|:------------|"
  values.each do |v|
    vn = v['name']
    puts "Unable to find value for #{name} :: #{vn}" unless info.has_key?(vn)
    f.puts "| `#{block.call(vn)}` | #{substitute(lang, info[vn].strip)} |"
  end
  f.puts ""
end

def gen_description_and_ref(f, info)
  if !info["description"].nil?
    f.puts info["description"]
    f.puts ""
  end

  if !info["ref"].nil?
    ref = info['ref']
    f.puts "See [#{ref['name']}](#{WEBGPU_URL}/#{ref['anchor']}) for more information."
    f.puts ""
  end
end

def get_info(type, name)
  info = @info[type].nil? ? nil : @info[type][name]
  if info.nil?
    puts "Unable to find #{type} info for #{name}"
    info = {
      'ref' => nil,
      'values' => {},
      'args' => {},
      'returns' => {}
    }
  end
  info
end

def gen_anchor(type)
  "#{$kinds[type]}-#{type.CamelCase}"
end

def gen_type_link(prefix, page, type)
  return "void" if type.nil?

  if $native_types.has_key?(type)
    type
  else
    "[#{prefix}#{type.CamelCase}]({{ '#{page}##{gen_anchor(type)}' | relative_url }})"
  end
end

def gen_cpp_type_link(type)
  gen_type_link("", "/api/cpp.html", type)
end

def gen_c_type_link(type)
  gen_type_link("WGPU", "/api/c.html", type)
end

def emit_type(f, type, &block)
  order_by_name(@categories[type]).each do |k|
    name = k['name']

    info = get_info(type, name)

    emit_div_block(f, type) do
      block.call(k, name, info)
    end
  end
end

def emit_div_block(f, name, &block)
  f.puts "<div class='#{name}' markdown=1>"
  f.puts ""
  block.call
  f.puts "</div>"
  f.puts ""
end

def emit_params(f, args, &block)
  f.write "("
  args.each_with_index do |a, idx|
    f.write "," if idx > 0
    f.write "<br>&nbsp; &nbsp;&nbsp;"
    f.write block.call(a)
  end
  f.puts ")"
end

def gen_list(f, list, &block)
  list.each do |name|
    f.puts " * #{block.call(name)}"
  end
  f.puts ""
end

def gen_member(member, &block)
  annot = member['annotation'].nil? ? "" : "#{member['annotation']} "

  ty = member['type']
  type = $native_types.has_key?(ty) ? ty : block.call(ty)
  "#{type} #{annot}#{member['name'].ParamCase}".gsub(/\*/, "\\*")
end

def gen_cpp_member(member)
  gen_member(member) { |m| gen_cpp_type_link(m) }
end

def gen_c_member(member)
  gen_member(member) { |m| gen_c_type_link(m) }
end

def gen_nav_section(f, src, title, kind, name_prefix="")
  if "constant" == kind
    f.puts "<h2><a href='{{ '#{src}#constants' | relative_url }}'>Constants</a></h2>"
    return
  end

  f.puts "<h2>#{title}</h2>"
  f.puts "<ul>"

  prefix = if $category_map[kind].empty?
    ""
  else
    "#{$category_map[kind]}-"
  end

  order_by_name(@categories[kind]).each do |e|
    name = e['name']
    f.puts "<li><a href='{{ '#{src}##{prefix}#{name.CamelCase}' | relative_url }}'>#{name_prefix}#{name.CamelCase}</a>"
  end
  f.puts "</ul>"
end

def substitute(lang, str)
  str.gsub(/%%(.*?)%%/) do |m|
    cmd = $1.strip!

    if cmd =~ /method\(([^,]*),\s+([^\)]*)\)/
      obj = $1
      method = $2

      display_name = if lang == "cpp"
        "#{obj.CamelCase}::#{method.CamelCase}"
      else
        "wgpu#{obj.CamelCase}#{method.CamelCase}"
      end

      "[#{display_name}](##{gen_anchor(obj)}-#{method.CamelCase})"
    else
      if lang == "cpp"
        if cmd == 'null'
          "nullptr"
        else
          gen_cpp_type_link(cmd)
        end
      else
        if cmd == 'null'
          "NULL"
        else
          gen_c_type_link(cmd)
        end
      end
    end
  end

end

def emit_value_or_warning(f, lang, info, value, name, default="")
  if info.nil? || info[value].nil?
    puts "Missing #{name} :: value"
    f.write default
  else
    f.write substitute(lang, info[value].strip)
  end
end

def emit_args(f, lang, src_name, args, info)
  return if args.nil? || args.empty?

  gen_header(f, "Arguments", 5)
  args.each do |arg|
    arg_name = arg['name']

    f.write "* *#{arg_name.ParamCase}*: "
    emit_value_or_warning(f, lang, info['args'], arg_name, src_name)
    f.puts ""
  end
  f.puts ""
end

############################################################
##
##
##
##
##          Gen CPP Methods
##
##
##
############################################################

def gen_cpp_constants(f)
  gen_header(f, "Constants")

  info = @info['constant']

  f.puts "| Value | Description |"
  f.puts "|:------|:------------|"
  order_by_name(@categories['constant']).each do |c|
    n = c['name']
    puts "Unable to find constant description for #{n}" unless info.has_key?(n)
    f.puts "| `k#{n.CamelCase}` | #{info[n].strip} |"
  end
  f.puts ""
end

def gen_cpp_enums(f)
  gen_header(f, "Enums")

  emit_type(f, 'enum') do |e, name, info|
    gen_linked_header(f, 'enum class', name, '', 3, 'enum') { |n| n.CamelCase }
    gen_description_and_ref(f, info)
    gen_table(f, "cpp", name, e['values'], info['values']) { |n| n.CamelCase }
  end
end

def gen_cpp_bitmasks(f)
  gen_header(f, "Bitmasks")

  f.puts <<~HERE
    The Dawn WebGPU bitmasks, while `enum class`s support the various bitwise
    operators in order to use them as bitmasks.
    HERE

  emit_type(f, 'bitmask') do |b, name, info|
    gen_linked_header(f, 'enum class', name, '[bitmask]', 3, 'bitmask') { |n| n.CamelCase }
    gen_description_and_ref(f, info)
    gen_table(f, "cpp", name, b['values'], info['values']) { |n| n.CamelCase }
  end
end

def gen_cpp_function(f)
  gen_header(f, "Functions")

  emit_type(f, 'function') do |func, name, info|
    gen_linked_header(f, '', name, '', 3, 'function') { |n| n.CamelCase }

    emit_div_block(f, 'content') do
      gen_description_and_ref(f, info)

      emit_div_block(f, 'signature') do
        f.write "#{gen_cpp_type_link(func['returns'])} #{name.CamelCase}"
        emit_params(f, func['args']) { |p| gen_cpp_member(p) }
      end

      gen_header(f, 'Returns', 5)
      emit_value_or_warning(f, "cpp", info['returns'], func['returns'], func['name'])
      f.puts ""
      f.puts ""

      emit_args(f, "cpp", func['name'], func['args'], info)
    end
  end
end

def gen_cpp_function_pointers(f)
  gen_header(f, "Function Pointers")

  emit_type(f, 'function pointer') do |func, name, info|
    emit_div_block(f, 'function') do
      gen_linked_header(f, '', name, '', 3, 'function-pointer') { |n| n.CamelCase }

      emit_div_block(f, 'content') do
        gen_description_and_ref(f, info)

        emit_div_block(f, 'signature') do
          f.write "void (&#x2a;#{name.CamelCase})"
          emit_params(f, func['args']) { |p| gen_c_member(p) }
        end

        emit_args(f, "cpp", func['name'], func['args'], info)
      end
    end
  end
end

def gen_cpp_structures(f)
  gen_header(f, "Structures")

  emit_type(f, 'structure') do |struct, name, info|
    gen_linked_header(f, 'struct', name, '', 3, 'structure') { |n| n.CamelCase }

    if !struct['members'].empty? || ['in', 'out'].include?(struct['extensible']) ||
          ['in', 'out'].include?(struct['chained'])
      f.puts "| Members | Default | Description |"
      f.puts "|:--------|:--------|:------------|"

      if struct['extensible'] == 'in' || struct['chained'] == 'in'
        f.puts "| `ChainedStruct const* nextInChain` | `nullptr` | " +
               "Pointer to next chained structure. Maybe `nullptr`. |"
      elsif struct['extensible'] == 'out' || struct['chained'] == 'out'
        f.puts "| `ChainedStructOut const* nextInChain` | `nullptr` | " +
               "Pointer to next chained structure. Maybe `nullptr`. |"
      end

      if struct['chained'] == 'in' || struct['chained'] == 'out'
        f.puts "| `SType stype` | `SType::#{struct['name'].CamelCase}` | Structure type |"
      end

      struct['members'].each do |member|
        default = if member['default'].nil?
          ""
        elsif $native_types.has_key?(member['type'])
          "`#{member['default']}`"
        else
          "`#{member['type'].CamelCase}::#{member['default'].CamelCase}`"
        end

        f.write "| #{gen_cpp_member(member)} | #{default} | "
        emit_value_or_warning(f, "cpp", info['values'], member['name'], struct['name'])
        f.puts " |"
      end
      f.puts ""
    end

    if !$chain_in[name].nil?
      gen_header(f, 'Chainable Structures', 5)
      gen_list(f, $chain_in[name]) { |n| gen_cpp_type_link(n) }
    end

    if !$chain_in_parents[name].nil?
      gen_header(f, 'Chain Parent Structures', 5)
      gen_list(f, $chain_in_parents[name]) { |n| gen_cpp_type_link(n) }
    end
  end
end

def gen_cpp_classes(f)
  gen_header(f, "Classes")

  emit_type(f, 'object') do |klass, name, info|
    emit_div_block(f, 'object') do
      gen_linked_header(f, 'class', name, '', 3, 'class') { |n| n.CamelCase }

      emit_div_block(f, 'content') do
        emit_div_block(f, 'description') do
          gen_description_and_ref(f, info)
        end

        (klass['methods'] || []).sort { |a, b| a['name'] <=> b['name'] }.each do |method|
          emit_div_block(f, 'method') do
            gen_linked_header(f, '', method['name'], '', 4, "#{gen_anchor(name)}") do |n|
              n.CamelCase
            end

            method_info = (info['methods'] || {})[method['name']] || {}
            gen_description_and_ref(f, method_info)

            emit_div_block(f, 'signature') do
              f.write "#{gen_cpp_type_link(method['returns'])} #{method['name'].CamelCase}"
              emit_params(f, method['args'] || []) { |p| gen_cpp_member(p) }
              f.puts ""
            end

            if !method['returns'].nil? && method['returns'] != 'void'
              gen_header(f, "Returns", 5)
              emit_value_or_warning(f, "cpp", method_info['returns'],
                      method['returns'], method['name'])
              f.puts ""
            end

            emit_args(f, "cpp", method['name'], method['args'], method_info)
          end
        end
      end
    end
  end
end

def gen_cpp_nav(f)
  gen_nav_section(f, "/api/cpp.html", "Constants", "constant")
  gen_nav_section(f, "/api/cpp.html", "Enums", "enum")
  gen_nav_section(f, "/api/cpp.html", "Bitmasks", "bitmask")
  gen_nav_section(f, "/api/cpp.html", "Functions", "function")
  gen_nav_section(f, "/api/cpp.html", "Function Pointers", "function pointer")
  gen_nav_section(f, "/api/cpp.html", "Structures", "structure")
  gen_nav_section(f, "/api/cpp.html", "Classes", "object")
end

def gen_cpp
  File.open(File.join(BASE_DIR, "docs", "api", "cpp.md"), "w") do |f|
    f.puts <<~HERE
      ---
      layout: page
      title: C++ API
      parent: API Documentation
      ---

      # C++ API Documentation
      HERE

    gen_cpp_constants(f)
    gen_cpp_enums(f)
    gen_cpp_bitmasks(f)
    gen_cpp_function(f)
    gen_cpp_function_pointers(f)
    gen_cpp_structures(f)
    gen_cpp_classes(f)
  end

  File.open(File.join(BASE_DIR, "docs", "_includes", "cpp_nav.html"), "w") do |f|
    gen_cpp_nav(f)
  end
end

############################################################
##
##
##
##
##          Gen C Methods
##
##
##
############################################################

def gen_c_constants(f)
  gen_header(f, "Constants")

  info = @info['constant']

  f.puts "| Value | Description |"
  f.puts "|:------|:------------|"
  order_by_name(@categories['constant']).each do |c|
    n = c['name']
    puts "Unable to find constant description for #{n}" unless info.has_key?(n)
    f.puts "| `#{n.UpSnakeCase("WGPU")}` | #{info[n].strip} |"
  end
  f.puts ""
end

def gen_c_enums(f)
  gen_header(f, "Enums")

  emit_type(f, 'enum') do |e, name, info|
    gen_linked_header(f, 'enum', name, '', 3, 'enum') { |n| "WGPU#{n.CamelCase}" }
    gen_description_and_ref(f, info)
    gen_table(f, "c", name, e['values'], info['values']) do |n|
      "WGPU#{name.CamelCase}_#{n.CamelCase}"
    end
  end
end

def gen_c_bitmasks(f)
  gen_header(f, "Bitmasks")

  f.puts <<~HERE
    Each bitmask enum provides an associated `Flags` typedef for which is,
    in effect, a uint32_t type. The `Flags` type is what is used in method
    signatures.
    HERE

  emit_type(f, 'bitmask') do |b, name, info|
    gen_linked_header(f, 'enum', name, '[bitmask]', 2, 'bitmask') { |n| "WGPU#{n.CamelCase}" }
    gen_description_and_ref(f, info)
    gen_table(f, "c", name, b['values'], info['values']) do |n|
      "WGPU#{name.CamelCase}_#{n.CamelCase}"
    end
    f.puts "`typedef WGPUFlags WGPU#{name.CamelCase}Flags`"
  end
end


def gen_c_function(f)
  gen_header(f, "Functions")

  emit_type(f, 'function') do |func, name, info|
    gen_linked_header(f, '', name, '', 3, 'function') { |n| "wgpu#{n.CamelCase}" }

    emit_div_block(f, 'content') do
      gen_description_and_ref(f, info)

      emit_div_block(f, 'signature') do
        f.write "#{gen_c_type_link(func['returns'])} wgpu#{name.CamelCase}"
        emit_params(f, func['args']) { |p| gen_c_member(p) }
      end

      gen_header(f, 'Returns', 5)
      emit_value_or_warning(f, "c", info['returns'], func['returns'], func['name'])
      f.puts ""
      f.puts ""

      emit_args(f, "c", func['name'], func['args'], info)
    end
  end
end

def gen_c_function_pointers(f)
  gen_header(f, "Function Pointers")

  emit_type(f, 'function pointer') do |func, name, info|
    emit_div_block(f, 'function') do
      gen_linked_header(f, '', name, '', 3, 'function-pointer') { |n| "WGPU#{n.CamelCase}" }

      emit_div_block(f, 'content') do
        gen_description_and_ref(f, info)

        emit_div_block(f, 'signature') do
          f.write "void (&#x2a;WGPU#{name.CamelCase})"
          emit_params(f, func['args']) { |p| gen_c_member(p) }
        end

        emit_args(f, "c", func['name'], func['args'], info)
      end
    end
  end
end

def gen_c_structures(f)
  gen_header(f, "Structures")

  emit_type(f, 'structure') do |struct, name, info|
    gen_linked_header(f, 'struct', name, '', 3, 'structure') { |n| "WGPU#{n.CamelCase}" }

    if !struct['members'].empty? || ['in', 'out'].include?(struct['extensible']) ||
          ['in', 'out'].include?(struct['chained'])
      f.puts "| Members | Description |"
      f.puts "|:--------|:------------|"

      if struct['extensible'] == 'in'
        f.puts "| `WGPUChainedStruct const* nextInChain` | " +
               "Pointer to next chained structure. Maybe `NULL`. |"
      elsif struct['extensible'] == 'out'
        f.puts "| `WGPUChainedStructOut* nextInChain` | " +
               "Pointer to next chained structure. Maybe `NULL`. |"
      end

      if struct['chained'] == 'in'
        f.puts "| `WGPUChainedStruct chain` | | ChainedStruct base object|"
      end

      struct['members'].each do |member|
        f.write "| #{gen_c_member(member)} | "
        emit_value_or_warning(f, "c", info['values'], member['name'], struct['name'])
        f.puts " |"
      end
      f.puts ""
    end

    if !$chain_in[name].nil?
      gen_header(f, 'Chainable Structures', 5)
      gen_list(f, $chain_in[name]) { |n| gen_c_type_link(n) }
    end

    if !$chain_in_parents[name].nil?
      gen_header(f, 'Chain Parent Structures', 5)
      gen_list(f, $chain_in_parents[name]) { |n| gen_c_type_link(n) }
    end
  end
end

def gen_c_objects(f)
  gen_header(f, "Methods")

  emit_type(f, 'object') do |klass, name, info|
    emit_div_block(f, 'object') do
      gen_linked_header(f, 'Methods of', name, '', 3, 'class') { |n| "WGPU#{n.CamelCase}" }

      emit_div_block(f, 'content') do
        emit_div_block(f, 'description') do
          gen_description_and_ref(f, info)
        end

        methods = (klass['methods'] || [])
        methods.push({
          "name" => "reference"
        })
        methods.push({
          "name" => "release"
        })

        methods.sort { |a, b| a['name'] <=> b['name'] }.each do |method|
          emit_div_block(f, 'method') do
            args = method['args'] || []
            args.unshift({
              "name" => klass['name'],
              "type" => klass['name']
            })

            to_method_name = lambda { |n| "wgpu#{klass['name'].CamelCase}#{n.CamelCase}" }
            gen_linked_header(f, '', method['name'], '', 4, "#{gen_anchor(name)}") do |n|
                to_method_name.call(n)
            end

            method_info = (info['methods'] || {})[method['name']] || {}
            gen_description_and_ref(f, method_info)

            emit_div_block(f, 'signature') do
              f.write "#{gen_c_type_link(method['returns'])} #{to_method_name.call(method['name'])}"
              emit_params(f, args) { |p| gen_c_member(p) }
              f.puts ""
            end

            if !method['returns'].nil? && method['returns'] != 'void'
              gen_header(f, "Returns", 5)
              emit_value_or_warning(
                  f, "c", method_info['returns'], method['returns'], method['name'])
              f.puts ""
            end

            emit_args(f, "c", method['name'], args, method_info)
          end
        end
      end
    end
  end
end

def gen_c_nav(f)
  gen_nav_section(f, "/api/c.html", "Constants", "constant", "WGPU")
  gen_nav_section(f, "/api/c.html", "Enums", "enum", "WGPU")
  gen_nav_section(f, "/api/c.html", "Bitmasks", "bitmask", "WGPU")
  gen_nav_section(f, "/api/c.html", "Functions", "function", "wgpu")
  gen_nav_section(f, "/api/c.html", "Function Pointers", "function pointer", "WGPU")
  gen_nav_section(f, "/api/c.html", "Structures", "structure", "WGPU")
  gen_nav_section(f, "/api/c.html", "Methods", "object", "WGPU")
end

def gen_c
  File.open(File.join(BASE_DIR, "docs", "api", "c.md"), "w") do |f|
    f.puts <<~HERE
      ---
      layout: page
      title: C API
      parent: API Documentation
      ---

      # C API Documentation
      HERE

    gen_c_constants(f)
    gen_c_enums(f)
    gen_c_bitmasks(f)
    gen_c_function(f)
    gen_c_function_pointers(f)
    gen_c_structures(f)
    gen_c_objects(f)
  end

  File.open(File.join(BASE_DIR, "docs", "_includes", "c_nav.html"), "w") do |f|
    gen_c_nav(f)
  end
end

gen_cpp
gen_c
