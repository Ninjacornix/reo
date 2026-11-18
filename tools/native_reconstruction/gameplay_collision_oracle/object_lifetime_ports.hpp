#pragma once
#include "game/native/gameplay_collision/object_lifetime.hpp"
namespace lifetime_fixture {
namespace c=reo::native::gameplay_collision;
inline const c::response::Grid* floors;
inline std::vector<std::pair<unsigned,unsigned>> events;
inline bool missing_model{};
inline bool real_model_bindings{};
}
namespace model_binding_original {
void o2_00581830_0x581830(std::uint8_t*,R5900Context*,PS2Runtime*);
void o2_005D8280_0x5d8280(std::uint8_t*,R5900Context*,PS2Runtime*);
void o2_005D8300_0x5d8300(std::uint8_t*,R5900Context*,PS2Runtime*);
}
inline void lifetime_identity(std::uint8_t* m,R5900Context* c,PS2Runtime*){ref_write(m,GPR_U32(c,4),std::array<float,16>{1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1});c->pc=GPR_U32(c,31);}
inline void lifetime_model(std::uint8_t* m,R5900Context* c,PS2Runtime* r){if(lifetime_fixture::real_model_bindings)return model_binding_original::o2_00581830_0x581830(m,c,r);const auto slot=GPR_U32(c,4)&255;lifetime_fixture::events.emplace_back(0,slot);c->g[2].lo=lifetime_fixture::missing_model?255:(slot+3)&255;c->pc=GPR_U32(c,31);}
inline void lifetime_bind(std::uint8_t* m,R5900Context* c,PS2Runtime* r){if(lifetime_fixture::real_model_bindings)return model_binding_original::o2_005D8280_0x5d8280(m,c,r);lifetime_fixture::events.emplace_back(1,GPR_U32(c,4)&255);c->pc=GPR_U32(c,31);}
inline void lifetime_unbind(std::uint8_t* m,R5900Context* c,PS2Runtime* r){if(lifetime_fixture::real_model_bindings)return model_binding_original::o2_005D8300_0x5d8300(m,c,r);lifetime_fixture::events.emplace_back(2,GPR_U32(c,4)&255);c->pc=GPR_U32(c,31);}
inline void lifetime_floor(std::uint8_t* m,R5900Context* c,PS2Runtime*){const auto p=ref_read<lifetime_fixture::c::Vec3>(m,GPR_U32(c,4));const auto floor=lifetime_fixture::floors->floor(p);ref_write(m,GPR_U32(c,5),floor.material);c->f[0]=floor.height;c->pc=GPR_U32(c,31);}
inline void o2_00581830_0x581830(std::uint8_t* m,R5900Context* c,PS2Runtime* r){lifetime_model(m,c,r);}
inline void o2_005D8280_0x5d8280(std::uint8_t* m,R5900Context* c,PS2Runtime* r){lifetime_bind(m,c,r);}
inline void o2_005D8300_0x5d8300(std::uint8_t* m,R5900Context* c,PS2Runtime* r){lifetime_unbind(m,c,r);}
inline void o2_00616F60_0x616f60(std::uint8_t* m,R5900Context* c,PS2Runtime* r){lifetime_floor(m,c,r);}
