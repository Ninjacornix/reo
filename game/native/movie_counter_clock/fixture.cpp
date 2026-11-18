#include "clock.hpp"
#include <iostream>
#include <string>
namespace n=reo::native::movie_counter_clock;
int main(){
    std::string operation;
    while(std::cin>>operation){
        n::State s;n::Words words;std::uint32_t frequency{};
        if(!(std::cin>>s.actual>>s.requested>>s.pause>>s.buffering_pause>>s.property_47>>s.active_counter>>s.increment>>s.elapsed_counter>>s.elapsed_origin>>s.external_accumulator>>frequency>>words.numerator>>words.denominator))return 2;
        n::Operation op;
        if(operation=="tick")op=n::Operation::tick;else if(operation=="active_gate")op=n::Operation::active_gate;
        else if(operation=="elapsed_gate")op=n::Operation::elapsed_gate;else if(operation=="rebase")op=n::Operation::rebase;
        else if(operation=="unavailable")op=n::Operation::unavailable;else if(operation=="counter")op=n::Operation::counter;
        else if(operation=="contextual")op=n::Operation::contextual;else if(operation=="admit")op=n::Operation::admit;else return 3;
        const auto effects=n::execute(s,op,words,frequency);
        std::cout<<s.actual<<' '<<s.requested<<' '<<s.pause<<' '<<s.buffering_pause<<' '<<s.property_47<<' '<<s.active_counter<<' '<<s.increment<<' '<<s.elapsed_counter<<' '<<s.elapsed_origin<<' '<<s.external_accumulator<<' '<<words.numerator<<' '<<words.denominator<<' '<<effects.status_defined<<' '<<effects.status<<' '<<effects.count;
        for(unsigned k=0;k<effects.count;++k){std::cout<<' '<<unsigned(effects.writes[k]);}std::cout<<'\n';
    }
    return std::cin.eof()?0:4;
}
