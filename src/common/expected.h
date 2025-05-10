#pragma once

//! @file expected.h

#include <expected>
#include <print>
#include <type_traits>

namespace dusk {

/// Checks if `item` is valid, if so returns the expected value. If not, prints
/// the error and calls `exit`.
template <typename T, typename K>
  requires(!std::is_void_v<T>)
T valid_or_exit(std::expected<T, K> item) {
  if (!item) {
    std::println(stderr, "{}", item.error());
    exit(1);
  }
  return std::move(item.value());
}

/// Checks if `item` is valid, if so returns. If not, prints the error and calls
/// `exit`.
template <typename T, typename K>
  requires(std::is_void_v<T>)
void valid_or_exit(std::expected<T, K> item) {
  if (!item) {
    std::println(stderr, "{}", item.error());
    exit(1);
  }
}

/// Checks if `item` is valid, otherwise propagates the result of the `error`
/// call as an `expected`.
#define VALID_OR_PROPAGATE(item)              \
  do {                                        \
    if (!(item)) {                            \
      return std::unexpected((item).error()); \
    }                                         \
  } while (false)

/// Checks if `check` is true, otherwise returns an `unexpected` result with
/// `err` as the error value.
#define VALID_OR_RETURN(check, err)  \
  do {                               \
    if (!(check)) {                  \
      return std::unexpected((err)); \
    }                                \
  } while (false)

}  // namespace dusk
