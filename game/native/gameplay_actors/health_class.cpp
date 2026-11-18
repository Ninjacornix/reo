#include "health_class.hpp"

namespace reo::native::gameplay_actors {
ClassResult derive_health_class(HealthState& a,std::span<const float,2> thresholds)noexcept{
    if(a.category>=2)return ClassResult::unchanged;
    if(a.status&8){a.class_marker=3;return ClassResult::updated;}
    if(a.status&2){a.class_marker=2;return ClassResult::updated;}
    if(a.maximum==0)return ClassResult::invalid_maximum;
    const float numerator=100.0f*float(a.current);
    const float percentage=numerator/float(a.maximum);
    for(std::uint8_t i=0;i<2;++i)if(!(percentage<thresholds[i])){a.class_marker=i;return ClassResult::updated;}
    a.class_marker=2;return ClassResult::updated;
}
} // namespace reo::native::gameplay_actors
