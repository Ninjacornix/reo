#include "frame_events.hpp"
#include <cmath>
#include <stdexcept>
namespace reo::native::animation {
namespace {
float finite(float value) {
    if (!std::isfinite(value))
        throw std::domain_error("Native frame crossing finite arithmetic required");
    return value;
}
} // namespace
bool crosses_frame(const FrameRecord& record, float target, float step, std::uint8_t clock_mode) {
    if (record.flags & 0x10)
        return false;
    transform_math::require_profile();
    finite(step);
    if (clock_mode == 1)
        step = finite(step * 2.f);
    const float current = finite(record.frame);
    finite(target);
    const float next = finite(current + step);
    if (record.loop) {
        const float end = finite(record.end);
        if (end < next) {
            if (!(target < current) && target <= end)
                return true;
            const float restart = finite(record.restart);
            if (target < restart)
                return false;
            return target < finite(restart + finite(next - end));
        }
    }
    return !(target < current) && target < next;
}
} // namespace reo::native::animation
