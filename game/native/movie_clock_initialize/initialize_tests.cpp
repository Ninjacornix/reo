#include "projection.hpp"
#include <algorithm>
#include <array>
#include <cstdio>
int main(){
    constexpr std::array<std::uint32_t,168> original{
#include "original_clock_words.inc"
    };
    const auto state=reo::native::movie_clock_initialize::initialize();
    const auto words=reo::native::movie_clock_initialize::testing::project(state);
    if(words.size()!=original.size() || !std::equal(words.begin(),words.end(),original.begin())){
        std::fputs("Native clock initialization differs from normalized frozen original words\n",stderr);return 1;
    }
    std::puts("168 normalized original constructor words match");return 0;
}
