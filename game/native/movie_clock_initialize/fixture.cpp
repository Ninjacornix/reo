#include "projection.hpp"
#include <iostream>
int main(){
    const auto state=reo::native::movie_clock_initialize::initialize();
    std::cout<<"row";
    for(auto word:reo::native::movie_clock_initialize::testing::project(state))std::cout<<' '<<word;
    std::cout<<'\n';
}
