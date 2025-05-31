#pragma once
#include <cstdint>
#include <boost/multiprecision/cpp_int.hpp>

uint64_t n_choose_r(uint64_t n, uint64_t r);
uint64_t catalan(uint64_t n);
boost::multiprecision::cpp_int factorial(int n);
