#pragma once
namespace spatial_fixture {
inline bool probe_only{},obstructed{};
inline unsigned probes{},occlusion_calls{};
}
inline void spatial_probe_sphere(std::uint8_t* m,R5900Context* c,PS2Runtime* r){if(spatial_fixture::probe_only){++spatial_fixture::probes;c->g[2].lo=0;c->pc=GPR_U32(c,31);}else o2_00579B40_0x579b40(m,c,r);}
inline void spatial_probe_margin(std::uint8_t* m,R5900Context* c,PS2Runtime* r){if(spatial_fixture::probe_only){++spatial_fixture::probes;c->g[2].lo=0;c->pc=GPR_U32(c,31);}else o2_00579CD0_0x579cd0(m,c,r);}
inline void spatial_occlusion(std::uint8_t* m,R5900Context* c,PS2Runtime*){c->g[2].lo=spatial_fixture::obstructed;ref_write(m,GPR_U32(c,8),0xffu);++spatial_fixture::occlusion_calls;c->pc=GPR_U32(c,31);}
inline void sub_001AEC80_0x1aec80(std::uint8_t*,R5900Context* c,PS2Runtime*){c->g[2].lo=0;c->pc=GPR_U32(c,31);}
inline void o2_005719D0_0x5719d0(std::uint8_t*,R5900Context*,PS2Runtime*){throw std::runtime_error("Post-hit point effect outside spatial oracle");}
inline void o2_005A87A0_0x5a87a0(std::uint8_t*,R5900Context*,PS2Runtime*){throw std::runtime_error("Player response value outside spatial oracle");}
inline void o2_005A8A50_0x5a8a50(std::uint8_t*,R5900Context*,PS2Runtime*){throw std::runtime_error("Player response value outside spatial oracle");}
inline void o2_006683E0_0x6683e0(std::uint8_t*,R5900Context*,PS2Runtime*){throw std::runtime_error("Source multiplier outside spatial oracle");}
