#include "filter.hpp"
#include <bit>
#include <iostream>
#include <string>
#include <utility>
namespace n=reo::native::movie_audio_filter;
constexpr std::pair<const char*,std::uint32_t n::State::*> raw_fields[]{
    {"enabled",&n::State::enabled},{"pause",&n::State::pause},{"active",&n::State::active},{"mode",&n::State::mode},{"window",&n::State::window},{"sample_counter",&n::State::sample_counter},
    {"reanchors",&n::State::reanchors},{"positive_steps",&n::State::positive_steps},{"negative_steps",&n::State::negative_steps},{"resets",&n::State::resets},{"excess_resets",&n::State::excess_resets}};
constexpr std::pair<const char*,std::int32_t n::State::*> signed_fields[]{
    {"average_before",&n::State::average_before},{"average_after",&n::State::average_after},{"inactive_max",&n::State::inactive_max},{"inactive_min",&n::State::inactive_min},{"active_max",&n::State::active_max},{"active_min",&n::State::active_min}};
constexpr std::pair<const char*,n::Pair n::State::*> pair_fields[]{
    {"previous_input",&n::State::previous_input},{"previous_helper",&n::State::previous_helper},{"previous_output",&n::State::previous_output},{"quantum",&n::State::quantum},{"threshold",&n::State::threshold},{"first_offset",&n::State::first_offset},{"later_offset",&n::State::later_offset}};
constexpr std::pair<const char*,std::uint64_t n::State::*> lane_fields[]{
    {"helper_anchor",&n::State::helper_anchor},{"master_anchor",&n::State::master_anchor},{"raw_maximum",&n::State::raw_maximum}};
std::int32_t word(std::uint64_t value){return std::bit_cast<std::int32_t>(static_cast<std::uint32_t>(value));}
int main(){
    n::State state;n::Pair input,helper,output;bool observed=false;unsigned identity{};int index=-1;std::string command;
    const auto print=[&](bool defined,std::uint64_t returned,n::Status status){
        std::cout<<"row "<<identity<<' '<<index;
        for(const auto& f:raw_fields)std::cout<<' '<<state.*f.second;
        for(const auto& f:signed_fields)std::cout<<' '<<static_cast<std::uint32_t>(state.*f.second);
        for(const auto& f:pair_fields){const auto pair=state.*f.second;std::cout<<' '<<pair.numerator<<' '<<pair.denominator;}
        for(const auto& f:lane_fields)std::cout<<' '<<state.*f.second;
        for(auto value:state.history)std::cout<<' '<<static_cast<std::uint32_t>(value);
        std::cout<<" 0 0 0 "<<observed<<" 0 0 "<<input.numerator<<' '<<input.denominator<<' '<<helper.numerator<<' '<<helper.denominator<<' '<<output.numerator<<' '<<output.denominator<<' '<<defined<<' '<<returned<<' '<<unsigned(status)<<'\n';
    };
    while(std::cin>>command){
        if(command=="begin"){
            if(!(std::cin>>identity))return 2;
            state=n::initialize();input=helper=output={0x5A5A5A5A5A5A5A5Aull,0x5A5A5A5A5A5A5A5Aull};observed=false;index=-1;print(false,0,n::Status::completed);continue;
        }
        if(command=="seed_history"){
            for(auto& entry:state.history){std::uint64_t value;if(!(std::cin>>value))return 3;entry=word(value);}continue;
        }
        if(command=="seed_word" || command=="seed_lane" || command=="seed_pair"){
            std::string key;std::uint64_t value;if(!(std::cin>>key>>value))return 4;bool found=false;
            if(command=="seed_word"){
                for(const auto& f:raw_fields)if(key==f.first){state.*f.second=static_cast<std::uint32_t>(value);found=true;}
                for(const auto& f:signed_fields)if(key==f.first){state.*f.second=word(value);found=true;}
            }else if(command=="seed_lane"){for(const auto& f:lane_fields)if(key==f.first){state.*f.second=value;found=true;}}
            else{std::uint64_t denominator;if(!(std::cin>>denominator))return 5;for(const auto& f:pair_fields)if(key==f.first){state.*f.second={value,denominator};found=true;}}
            if(!found)return 6;
            continue;
        }
        ++index;bool defined=false;std::uint64_t returned=0;n::Status status=n::Status::completed;
        if(command=="filter"){
            if(!(std::cin>>input.numerator>>input.denominator>>helper.numerator>>helper.denominator))return 7;
            const auto result=n::process(state,input,helper);status=result.status;
            if(status==n::Status::completed){output=result.output;observed|=result.observed;}
        }else if(command=="quantum" || command=="threshold" || command=="first_offset" || command=="later_offset" || command=="baseline"){
            n::Pair pair;if(!(std::cin>>pair.numerator>>pair.denominator))return 8;
            if(command=="baseline")status=n::baseline(state,pair);
            else n::ratio(state,command=="quantum"?n::Ratio::quantum:command=="threshold"?n::Ratio::threshold:command=="first_offset"?n::Ratio::first_offset:n::Ratio::later_offset,pair);
        }else if(command=="clear")n::clear_history(state);
        else if(command=="average"){const auto result=n::average(state);status=result.status;defined=true;returned=static_cast<std::uint64_t>(static_cast<std::int64_t>(result.value));}
        else{
            std::uint64_t value;if(!(std::cin>>value))return 9;
            if(command=="enabled")n::enabled(state,static_cast<std::uint32_t>(value));else if(command=="pause")n::pause(state,static_cast<std::uint32_t>(value));else if(command=="mode")n::mode(state,static_cast<std::uint32_t>(value));
            else if(command=="window")status=n::window(state,static_cast<std::uint32_t>(value));
            else if(command=="push" || command=="shift"){
                const auto result=command=="push"?n::push(state,word(value)):n::shift(state,word(value));status=result.status;defined=command=="push";returned=static_cast<std::uint64_t>(static_cast<std::int64_t>(result.value));
            }else return 10;
        }
        print(defined,returned,status);
    }
    return std::cin.eof()?0:11;
}
