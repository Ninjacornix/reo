#include "clock.hpp"
#include <bit>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
namespace n=reo::native::movie_audio_clock;
namespace f=n::filter;
constexpr std::pair<const char*,std::uint32_t f::State::*> raw_fields[]{
    {"enabled",&f::State::enabled},{"pause",&f::State::pause},{"active",&f::State::active},{"mode",&f::State::mode},{"window",&f::State::window},{"sample_counter",&f::State::sample_counter},
    {"reanchors",&f::State::reanchors},{"positive_steps",&f::State::positive_steps},{"negative_steps",&f::State::negative_steps},{"resets",&f::State::resets},{"excess_resets",&f::State::excess_resets}};
constexpr std::pair<const char*,std::int32_t f::State::*> signed_fields[]{
    {"average_before",&f::State::average_before},{"average_after",&f::State::average_after},{"inactive_max",&f::State::inactive_max},{"inactive_min",&f::State::inactive_min},{"active_max",&f::State::active_max},{"active_min",&f::State::active_min}};
constexpr std::pair<const char*,f::Pair f::State::*> pair_fields[]{
    {"previous_input",&f::State::previous_input},{"previous_helper",&f::State::previous_helper},{"previous_output",&f::State::previous_output},{"quantum",&f::State::quantum},{"threshold",&f::State::threshold},{"first_offset",&f::State::first_offset},{"later_offset",&f::State::later_offset}};
constexpr std::pair<const char*,std::uint64_t f::State::*> lane_fields[]{
    {"helper_anchor",&f::State::helper_anchor},{"master_anchor",&f::State::master_anchor},{"raw_maximum",&f::State::raw_maximum}};
void print(const n::State& owner){
    const auto& state=owner.filter;
    for(const auto& item:raw_fields)std::cout<<' '<<state.*item.second;
    for(const auto& item:signed_fields)std::cout<<' '<<static_cast<std::uint32_t>(state.*item.second);
    for(const auto& item:pair_fields){const auto pair=state.*item.second;std::cout<<' '<<pair.numerator<<' '<<pair.denominator;}
    for(const auto& item:lane_fields)std::cout<<' '<<state.*item.second;
    for(auto value:state.history)std::cout<<' '<<static_cast<std::uint32_t>(value);
    std::cout<<' '<<owner.filter_observed<<' '<<owner.cache.numerator<<' '<<owner.cache.denominator<<' '<<owner.diagnostic;
}
struct Trace {unsigned kind{};n::State state;};
struct Shared {n::Clock* owner{};std::vector<Trace> trace;n::Words sample;std::uint8_t status{};std::uint64_t counter{},frequency{};};
struct Audio final:n::AudioSource {
    Shared& shared;explicit Audio(Shared& value):shared(value){}
    n::ProviderStatus status(std::uint8_t& value)noexcept override{value=shared.status;return n::ProviderStatus::completed;}
    n::ProviderStatus estimate(n::Words& value)noexcept override{shared.trace.push_back({1,shared.owner->snapshot().state});value=shared.sample;return n::ProviderStatus::completed;}
};
struct Helper final:n::HelperClock {
    Shared& shared;explicit Helper(Shared& value):shared(value){}
    n::ProviderStatus counter(std::uint64_t& value)noexcept override{shared.trace.push_back({2,shared.owner->snapshot().state});value=shared.counter;return n::ProviderStatus::completed;}
    n::ProviderStatus frequency(std::uint64_t& value)noexcept override{value=shared.frequency;return n::ProviderStatus::completed;}
};
int main(){
    n::State state;Shared shared;shared.trace.reserve(2);auto audio=std::make_shared<Audio>(shared);auto helper=std::make_shared<Helper>(shared);
    std::unique_ptr<n::Clock> clock;unsigned identity{},index{};n::Words prior;std::string command;
    while(std::cin>>command){
        if(command=="begin"){
            if(!(std::cin>>identity>>state.cache.numerator>>state.cache.denominator>>state.diagnostic>>prior.numerator>>prior.denominator))return 2;
            state.filter=f::initialize();state.filter_observed=false;clock.reset();index=0;continue;
        }
        if(command=="seed_history"){
            for(auto& value:state.filter.history){std::uint64_t raw;if(!(std::cin>>raw))return 3;value=std::bit_cast<std::int32_t>(static_cast<std::uint32_t>(raw));}continue;
        }
        if(command=="seed_word" || command=="seed_lane" || command=="seed_pair"){
            std::string key;std::uint64_t value;if(!(std::cin>>key>>value))return 4;bool found=false;
            if(command=="seed_word"){
                for(const auto& item:raw_fields)if(key==item.first){state.filter.*item.second=static_cast<std::uint32_t>(value);found=true;}
                for(const auto& item:signed_fields)if(key==item.first){state.filter.*item.second=std::bit_cast<std::int32_t>(static_cast<std::uint32_t>(value));found=true;}
            }else if(command=="seed_lane"){for(const auto& item:lane_fields)if(key==item.first){state.filter.*item.second=value;found=true;}}
            else{std::uint64_t denominator;if(!(std::cin>>denominator))return 5;for(const auto& item:pair_fields)if(key==item.first){state.filter.*item.second={value,denominator};found=true;}}
            if(!found)return 6;
            continue;
        }
        if(command!="slot" && command!="envelope")return 7;
        std::uint32_t actual{},raw_status{};
        if(!(std::cin>>actual>>raw_status>>shared.sample.numerator>>shared.sample.denominator>>shared.counter>>shared.frequency))return 8;
        shared.status=static_cast<std::uint8_t>(raw_status);
        if(!clock){clock=std::make_unique<n::Clock>(state,audio,helper);shared.owner=clock.get();}
        shared.trace.clear();
        const auto result=clock->execute(command=="slot"?n::Operation::slot:n::Operation::envelope,actual,prior);
        if(result.written)prior=result.words;
        std::cout<<"row "<<identity<<' '<<index++;
        print(clock->snapshot().state);
        std::cout<<' '<<prior.numerator<<' '<<prior.denominator<<' '<<result.return_defined<<' '<<result.callback_status<<' '<<unsigned(result.status)<<' '<<shared.trace.size();
        for(const auto& event:shared.trace){std::cout<<' '<<event.kind;print(event.state);}
        std::cout<<'\n';
    }
    return std::cin.eof()?0:9;
}
