#pragma once
#include "motion_transforms.hpp"
#include "../gameplay_collision/response.hpp"

namespace reo::native::gameplay_world {
// Original return zero includes rejected/cleared blends. It is not a success bit.
enum class SurfaceOrientationResult : unsigned {processed=0,not_requested=1};
class SurfaceOrientationFloors {
public:
    virtual ~SurfaceOrientationFloors()=default;
    // Required native floor source. Exactly three ordered probes with type FF;
    // the original consumer uses height even if the returned class is FF.
    virtual gameplay_collision::response::Floor sample(World&,Actor&,gameplay_collision::Vec3)=0;
};
SurfaceOrientationResult update_surface_orientation(World&,Actor&,SurfaceOrientationFloors&);

// Concrete remaining pose provider backed by an owned, immutable native grid.
// The caller must keep the grid alive throughout this synchronous provider.
class GridSurfaceOrientation final:public MotionTransformServices,private SurfaceOrientationFloors {
public:
    explicit GridSurfaceOrientation(const gameplay_collision::response::Grid& grid):grid_(grid){}
    void orient_surface(World&,Actor&)override;
private:
    gameplay_collision::response::Floor sample(World&,Actor&,gameplay_collision::Vec3)override;
    const gameplay_collision::response::Grid& grid_;
};
} // namespace reo::native::gameplay_world
