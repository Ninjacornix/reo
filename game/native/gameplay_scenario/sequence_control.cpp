#include "sequence_control.hpp"

namespace reo::native::gameplay_scenario {
bool SequenceControl::active(std::uint32_t index,bool value)noexcept{
    if(index>=state_.active.size())return false;
    state_.active[index]=value?1:0;return true;
}
void SequenceControl::enable_all()noexcept{
    for(int i=0;i<state_.count;++i)state_.active[std::size_t(i)]=1;
}
void SequenceControl::select(std::uint8_t id,std::uint16_t selection)noexcept{
    state_.selection=selection;state_.selected_id=id;state_.phase=4;state_.active[id]=1;
}
void SequenceControl::cancel_if_selected(std::uint8_t id)noexcept{
    if(id==state_.selected_id){state_.selection=0;state_.active[id]=0;}
}
void SequenceControl::percentage(std::uint8_t mode,std::int16_t first,std::int16_t second,std::uint32_t amount)noexcept{
    float converted;
    if(amount<=0x7fffffffu)converted=static_cast<float>(amount);
    else{const float half=static_cast<float>((amount>>1)|(amount&1));converted=half+half;}
    state_.mode=mode;state_.parameter_b=std::uint16_t(second);state_.phase=5;
    state_.parameter_a=std::uint16_t(first);state_.fraction=converted/100.0f;state_.restart_byte=0;
}
} // namespace reo::native::gameplay_scenario
