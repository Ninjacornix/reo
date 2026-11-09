#pragma once
#include "game/native/gameplay_collision/postmove.hpp"
// Qualified native provider ports around the unchanged original6636D0 caller.
// These ports do not claim another original-body comparison of their internals.
namespace postmove_fixture {
namespace collision=reo::native::gameplay_collision;
inline const collision::response::Grid* walls;
inline const collision::response::Grid* floors;
inline const collision::regions::World* regions;
inline const collision::room_objects::Owner* objects;
inline collision::actors::Basis basis;
inline collision::postmove::Context context;
inline collision::response::Filter filter;
inline std::vector<collision::response::Triangle> dynamic;
inline collision::ownership::WallState read_wall(const std::uint8_t* m,std::uint32_t at){collision::ownership::WallState state;state.position=ref_read<collision::Vec3>(m,at+0x38);state.previous=ref_read<collision::Vec3>(m,at+0x44);state.local_center=ref_read<collision::Vec3>(m,at+0x1ac);state.previous_center_offset=ref_read<collision::Vec3>(m,at+0x1cc);state.radius=ref_read<float>(m,at+0x1b8);state.include=ref_read<std::uint32_t>(m,at+0x190);state.exclude=ref_read<std::uint32_t>(m,at+0x194);state.disabled=ref_read<std::uint16_t>(m,at+0x54a)&1;state.dynamic_kind_gate=m[at+2]==2;state.contact=m[at+0x16c]&1;return state;}
}
inline void o2_005DA420_0x5da420(std::uint8_t* m,R5900Context* c,PS2Runtime*){using namespace postmove_fixture;const auto at=GPR_U32(c,4);auto state=read_wall(m,at);(void)collision::ownership::move_against_walls(state,basis,*walls,filter,dynamic);ref_write(m,at+0x38,state.position);ref_write(m,at+0x1cc,state.previous_center_offset);m[at+0x16c]=std::uint8_t((m[at+0x16c]&254)|state.contact);if(state.point)ref_write(m,at+0x154,*state.point);if(state.normal)ref_write(m,at+0x160,*state.normal);c->pc=GPR_U32(c,31);}
inline void o2_00616F60_0x616f60(std::uint8_t* m,R5900Context* c,PS2Runtime*){using namespace postmove_fixture;const auto result=floors->floor(ref_read<collision::Vec3>(m,GPR_U32(c,4)),std::uint8_t(GPR_U32(c,6)));m[GPR_U32(c,5)]=result.material;c->f[0]=result.height;c->pc=GPR_U32(c,31);}
inline void o2_00574680_0x574680(std::uint8_t* m,R5900Context* c,PS2Runtime*){using namespace postmove_fixture;c->g[2].lo=regions->select(GPR_U32(c,4)?std::optional(ref_read<collision::Vec3>(m,GPR_U32(c,4))):std::nullopt);c->pc=GPR_U32(c,31);}
inline void o2_0057C0B0_0x57c0b0(std::uint8_t* m,R5900Context* c,PS2Runtime*){using namespace postmove_fixture;const auto result=collision::footprint::constrain(*objects,ref_read<collision::Vec3>(m,GPR_U32(c,4)),ref_read<collision::Vec3>(m,GPR_U32(c,5)),context.room_objects_enabled,context.height_layers,floors);ref_write(m,GPR_U32(c,6),result.position);c->pc=GPR_U32(c,31);}
