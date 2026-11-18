#include "admission.hpp"
#include <bit>
#include <iostream>
#include <string>
namespace n=reo::native::movie_admission;
void print(const n::State& state){
    std::cout<<' '<<state.selector<<' '<<state.tolerance<<' '<<state.rate<<' '<<state.increment<<' '<<state.count<<' '<<std::bit_cast<std::uint32_t>(state.tracked)<<' '<<state.cached<<' '<<std::bit_cast<std::uint32_t>(state.previous)<<' '<<state.auxiliary;
}
int main(){
    n::State state;std::uint32_t frequency{},identity{},index{};std::string command;
    while(std::cin>>command){
        if(command=="begin"){
            std::uint32_t tracked{},previous{};
            if(!(std::cin>>identity>>state.selector>>state.tolerance>>state.rate>>state.increment>>state.count>>tracked>>state.cached>>previous>>state.auxiliary>>frequency))return 2;
            state.tracked=std::bit_cast<float>(tracked);state.previous=std::bit_cast<float>(previous);index=0;continue;
        }
        n::Operation operation;
        if(command=="core")operation=n::Operation::core;else if(command=="fallback")operation=n::Operation::fallback;else if(command=="hysteresis")operation=n::Operation::hysteresis;else return 3;
        n::Input input;input.frequency=frequency;std::uint32_t query{},current{},update_mask{},tracked{},previous{};
        n::State update;
        if(!(std::cin>>input.query.numerator>>input.query.denominator>>input.sample.numerator>>input.sample.denominator>>input.slack>>query>>current>>update_mask>>update.selector>>update.tolerance>>update.rate>>update.increment>>update.count>>tracked>>update.cached>>previous>>update.auxiliary))return 4;
        update.tracked=std::bit_cast<float>(tracked);update.previous=std::bit_cast<float>(previous);
        // Apply authored provider effects from original input, never expected
        // output snapshots. The arithmetic boundary begins after that query.
        if(operation==n::Operation::core){
            if(update_mask&1)state.selector=update.selector;
            if(update_mask&2)state.tolerance=update.tolerance;
            if(update_mask&4)state.rate=update.rate;
            if(update_mask&8)state.increment=update.increment;
            if(update_mask&16)state.count=update.count;
            if(update_mask&32)state.tracked=update.tracked;
            if(update_mask&64)state.cached=update.cached;
            if(update_mask&128)state.previous=update.previous;
            if(update_mask&256)state.auxiliary=update.auxiliary;
        }
        input.query_time=std::bit_cast<float>(query);input.current_time=std::bit_cast<float>(current);
        const auto result=n::evaluate(state,operation,input);
        std::cout<<"row "<<identity<<' '<<index++;print(state);std::cout<<' '<<result.decision<<' '<<unsigned(result.status)<<'\n';
    }
    return std::cin.eof()?0:5;
}
