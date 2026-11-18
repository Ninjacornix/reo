#include "movie_position.hpp"
#include <cstdlib>
#include <iostream>
#include <limits>

using namespace reo::native::movie_position;
unsigned checks{};
void check(bool value) { ++checks; if (!value) std::abort(); }
int main() {
    Input input{120, 30, 5, 10, false, 0, 0, 0};
    auto result = publish(input, {100, 99});
    check(result.descriptor.position == 125);
    check(result.descriptor.source_position == 120);
    check(result.descriptor.offset_position == 130);
    check(result.descriptor.denominator == 30);
    check(result.latest_advanced && result.latest.numerator == 125 && result.latest.denominator == 30);
    check(result.final_value == 30 && !result.zero_divisor_saturated);
    result = publish(input, {125, 99});
    check(!result.latest_advanced && result.latest.denominator == 99 && result.final_value == 0);
    input.inner_clock_enabled = true;
    input.inner_counter = 11; input.inner_baseline = 4; input.rate = 30000;
    result = publish(input, {0, 0});
    check(result.descriptor.source_position == 7);
    check(result.descriptor.position == 17 && result.descriptor.offset_position == 17);
    input.inner_counter = 0; input.inner_baseline = 7; input.rate = 29000;
    result = publish(input, {100, 77});
    check(result.descriptor.source_position == -7); // signed truncation, not floor
    check(result.descriptor.position == 3 && !result.latest_advanced && result.latest.denominator == 77);
    input.rate = 0;
    result = publish(input, {0, 0});
    check(result.zero_divisor_saturated && result.descriptor.source_position == std::numeric_limits<int>::min());
    input.denominator = 0;
    result = publish(input, {0, 0});
    check(result.descriptor.source_position == std::numeric_limits<int>::min()); // zero * negative
    input.inner_counter = 7; input.inner_baseline = 0;
    check(publish(input, {}).descriptor.source_position == std::numeric_limits<int>::max());
    input.inner_clock_enabled = false;
    input.counter = std::numeric_limits<int>::max(); input.subtract_counter = -1; input.bias = -1;
    result = publish(input, {std::numeric_limits<int>::min(), 5});
    check(result.descriptor.source_position == std::numeric_limits<int>::max());
    check(result.descriptor.position == std::numeric_limits<int>::max());
    check(result.descriptor.offset_position == std::numeric_limits<int>::max()-1);
    check(result.latest_advanced && !result.zero_divisor_saturated);
    std::cout << checks << " synthetic movie-position checks passed\n";
}
