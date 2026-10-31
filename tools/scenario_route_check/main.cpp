#include "../../runtime/input/scenario_test_route.h"
#include <iostream>
#include <stdexcept>
int main() try {
    using namespace reo::scenario_test_route;
    unsigned checks=0;
    auto check=[&](bool ok){if(!ok)throw std::runtime_error("Scenario route check failed");++checks;};
    check(requested(nullptr)==0&&requested("")==0);
    for(int target=0;target<5;++target) {
        char option[]={char('0'+target),0};check(requested(option)==target);
        for(uint32_t cursor=0;cursor<5;++cursor)
            check(choose(target,cursor,5)==(cursor==uint32_t(target)?Choice::Confirm:cursor<uint32_t(target)?Choice::Right:Choice::Left));
        for(uint32_t count:{0u,1u,4u,6u,100u})check(choose(target,0,count)==Choice::Unavailable);
        check(choose(target,5,5)==Choice::Unavailable);
    }
    for(const char* option:{"-1","5","10","1x"," 1","1 "})check(requested(option)==-1);
    check(choose(-1,0,5)==Choice::Unavailable&&choose(5,0,5)==Choice::Unavailable);
    std::cout<<"PASS "<<checks<<" diagnostic chapter-route checks\n";
} catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
