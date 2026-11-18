#pragma once
#include "../transform_math/direction_basis.hpp"
namespace reo::native::gameplay_scenario {
// Fields consumed by375A50. Other camera/projection properties belong to their
// enclosing owner, rather than an opaque copied original memory record.
struct CameraPose {
    transform_math::Vector eye,aim,up;
    std::uint32_t roll{};
};
transform_math::Matrix camera_view(const CameraPose&);
}
