#pragma once
#include <iostream>
#include <cmath>
#include <type_traits>
#include <cstdint>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/integer.hpp>

using big_int = boost::multiprecision::number<
    boost::multiprecision::cpp_int_backend<>,
    boost::multiprecision::et_off>;

// Helper trait to detect cpp_int
template <typename T>
struct is_cpp_int : std::false_type {};

template <>
struct is_cpp_int<big_int> : std::true_type {};

// Main templated sqrt function
template <typename T>
auto typed_sqrt(const T& x) {
    if constexpr (std::is_floating_point_v<T>) {
        return std::sqrt(x);
    } else if constexpr (std::is_integral_v<T>) {
        return static_cast<T>(std::sqrt(static_cast<double>(x)));
    } else if constexpr (is_cpp_int<T>::value) {
        return boost::multiprecision::sqrt(x);
    } else {
        static_assert(sizeof(T) == 0, "Unsupported type for my_sqrt");
    }
}
