#pragma once

#include <cstdint>

namespace sc {
template <typename...> struct args;
template <typename, auto, typename T, T...> struct undefined;

template <typename> struct message {};
template <typename> struct module_string {};
} // namespace sc

using string_id = std::uint32_t;
using module_id = std::uint32_t;

template <typename> extern auto catalog() -> string_id;
template <typename> extern auto module() -> module_id;
