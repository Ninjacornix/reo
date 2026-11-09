#pragma once
#include "postmove.hpp"
namespace reo::native::gameplay_collision::postmove {
// This borrows scalar components directly; it does not alias unrelated vector
// types or retain a second actor position. All refs last for the synchronous call.
struct VectorRef {
    float& x;float& y;float& z;
    template<class V> VectorRef(V& v)noexcept:x(v.x),y(v.y),z(v.z){}
    operator Vec3()const noexcept{return{x,y,z};}
    VectorRef& operator=(Vec3 v)noexcept{x=v.x;y=v.y;z=v.z;return *this;}
};
class FlagRef {
public:
    FlagRef(bool& value)noexcept:flag_(&value){}
    FlagRef(std::uint8_t& value)noexcept:byte_(&value){}
    operator bool()const noexcept{return byte_?*byte_!=0:*flag_;}
    FlagRef& operator=(bool value)noexcept{if(byte_)*byte_=std::uint8_t(value);else *flag_=value;return *this;}
private:
    bool* flag_{};std::uint8_t* byte_{};
};
struct WallView {
    VectorRef position,previous;
    Vec3& local_center;Vec3& previous_center_offset;
    float& radius;
    std::uint32_t& include;std::uint32_t& exclude;
    bool dynamic_kind_gate;bool& contact;
    std::optional<Vec3>& point;std::optional<Vec3>& normal;
};
struct View {
    WallView wall;
    Vec3& wall_displacement;
    const std::optional<Vec3>& joint_two_position;
    float& height;float& surface_target;
    std::uint32_t& movement_flags;std::uint32_t& height_flags;
    std::uint16_t& controls;std::uint16_t& room;std::uint16_t& route_ticks;std::uint16_t& region;
    std::uint8_t& kind;std::uint8_t& surface;std::uint8_t& material;
    bool& active;FlagRef pose_dirty;
};
View references(State&)noexcept;
Result update(View,Context,const actors::Basis&,const response::Grid& walls,
              const response::Grid& floors,const regions::World&,
              const room_objects::Owner&,response::Filter,
              std::span<const response::Triangle> dynamic={});
}
