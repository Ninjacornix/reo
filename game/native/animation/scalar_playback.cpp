#include "scalar_playback.hpp"
#include <bit>
#include <cmath>
#include <stdexcept>
namespace reo::native::animation {
void bind_scalar_frame(Instance& model,FrameRecord& record,std::shared_ptr<const Clip> clip,float frame){
    if(!clip)throw std::invalid_argument("Native scalar playback requires an admitted clip");
    if(!std::isfinite(frame))throw std::domain_error("Native scalar playback finite initial frame required");
    record.frame=frame;
    model.bind_prefix(0,clip);model.sample(0,frame);
    record.end=clip->last_frame();record.restart=clip->loop_start();record.loop=std::int8_t(clip->looping());
    if(record.restart<0)record.restart=0;
}
std::int8_t advance_scalar_frame(Instance& model,FrameRecord& record,float step,std::uint8_t clock_mode){
    if(record.loop==0&&!(record.frame<record.end))return 1;
    if(clock_mode)step*=2.f;
    const auto result=advance(record,step);
    model.sample(0,record.frame);
    return std::bit_cast<std::int8_t>(std::uint8_t(result));
}
}
