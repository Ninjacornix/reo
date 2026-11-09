#pragma once
#include "model.hpp"
namespace reo::native::animation {
// Actual native pose-bank ownership. All mutation is simulation-owner-thread
// only; corresponding banks retain one immutable authored Skeleton identity.
class PoseBlend final {
public:
    static std::shared_ptr<Instance> create_sibling(const Instance&);
    static void capture_pose(Instance& destination,const Instance& source,std::uint16_t track);
    static void capture_links(Instance& destination,const Instance& source,std::uint16_t track);
    static void blend(Instance& destination,const Instance& source,std::uint16_t track,float destination_weight,float source_weight);
    static Matrix matrix(const Matrix&,const Matrix&,float destination_weight,float source_weight);
};
} // namespace reo::native::animation
