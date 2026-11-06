#include "integer_clock.hpp"
#include <cstdint>
#include <iostream>
namespace c = reo::native::adxt_integer_clock;
int main() {
    std::uint32_t count;
    if (!(std::cin>>count) || count>1000) return 1;
    for(std::uint32_t i=0;i<count;++i) {
        std::uint32_t entry,state,decoded,total,frequency,base,offset,present,bytes,free,selection,ratio,counter,argument;
        std::int32_t depth_mode,depth_code;
        if(!(std::cin>>entry>>state>>decoded>>total>>frequency>>base>>offset>>depth_mode>>depth_code
             >>present>>bytes>>free>>selection>>ratio>>counter>>argument)) return 2;
        c::Observation o{static_cast<std::uint8_t>(state),decoded,total,frequency,base,offset,
            static_cast<std::int16_t>(depth_mode),static_cast<std::int16_t>(depth_code),bool(present),bytes,free};
        c::Mode mode{selection,ratio,counter};c::Ratio output{0x5a5a5a5a,0x5a5a5a5a};
        if(entry==0x131f60 || entry==0x132028) {
            auto result=c::query(entry==0x131f60?c::Query::rna_ratio:c::Query::decoded_minus_queued,o);
            if(result.status!=c::Status::completed) return 3;
            output=result.ratio;
        } else if(entry==0x131f28) c::select_mode(mode,argument);
        else if(entry==0x132148) c::count_resynchronization(mode);
        else return 4;
        std::cout<<output.numerator<<' '<<output.denominator<<' '<<mode.selection<<' '<<mode.ratio
                 <<' '<<mode.resynchronizations<<'\n';
    }
}
