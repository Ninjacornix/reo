#pragma once
#include "model.hpp"
namespace reo::native::animation {
//58C810 uses a standalone timing record. It preserves flags and does not
// apply the ordinary channel's odd-end or loop-bit normalization.
void bind_scalar_frame(Instance&,FrameRecord&,std::shared_ptr<const Clip>,float initial_frame);
//58C8A0 returns early for an already-complete nonlooping record, without
// sampling. Otherwise advance once, then sample track0 even on completion.
std::int8_t advance_scalar_frame(Instance&,FrameRecord&,float step,std::uint8_t clock_mode);
}
