#pragma once
#include <vector>
#include <functional>
namespace packet_oracle {
inline std::uint8_t event{}, route{}, edge{};
inline bool contact{}, audio{};
inline std::int32_t authority{};
inline std::vector<std::uint32_t> trace;
inline std::function<void(std::uint8_t*, PS2Runtime*)> after_shape;
inline void finish(R5900Context* c) {
    c->pc = GPR_U32(c, 31);
}
inline void shape(std::uint8_t* m, R5900Context* c, PS2Runtime* runtime, unsigned type) {
    const auto packet = GPR_U32(c, 4);
    trace.insert(trace.end(), {type, m[packet + 0xd]});
    m[packet + 0x1b] = event;
    ref_write(m, GPR_U32(c, 8), std::uint32_t(contact));
    if (route)
        ref_write(m, GPR_U32(c, 7), std::uint32_t(edge));
    if (contact)
        ++m[packet + 0x28];
    if (type == 2) {
        m[packet + 0x2b] = 1;
        ref_write(m, packet + 0x30, std::array<float, 3>{1, 2, 3});
    }
    c->g[2].lo = route;
    finish(c);
    if (after_shape) {
        auto callback = std::move(after_shape);
        after_shape = {};
        callback(m, runtime);
    }
}
} // namespace packet_oracle
inline void o2_005DAD80_0x5dad80(std::uint8_t* m, R5900Context* c, PS2Runtime* runtime) {
    packet_oracle::shape(m, c, runtime, 1);
}
inline void o2_005DB320_0x5db320(std::uint8_t* m, R5900Context* c, PS2Runtime* runtime) {
    packet_oracle::shape(m, c, runtime, 2);
}
inline void o2_005DB7D0_0x5db7d0(std::uint8_t* m, R5900Context* c, PS2Runtime* runtime) {
    packet_oracle::shape(m, c, runtime, 3);
}
inline void o2_005DBD30_0x5dbd30(std::uint8_t* m, R5900Context* c, PS2Runtime* runtime) {
    packet_oracle::shape(m, c, runtime, 4);
}
inline void sub_001BA5E0_0x1ba5e0(std::uint8_t*, R5900Context* c, PS2Runtime*) {
    packet_oracle::trace.insert(packet_oracle::trace.end(), {0x1ba5e0, GPR_U32(c, 5)});
    packet_oracle::finish(c);
}
inline void sub_001BA520_0x1ba520(std::uint8_t*, R5900Context* c, PS2Runtime*) {
    packet_oracle::trace.push_back(0x1ba520);
    c->g[2].lo = packet_oracle::audio;
    packet_oracle::finish(c);
}
inline void sub_001B0110_0x1b0110(std::uint8_t*, R5900Context* c, PS2Runtime*) {
    packet_oracle::trace.insert(packet_oracle::trace.end(), {0x1b0110, GPR_U32(c, 4)});
    c->g[2].lo = std::uint64_t(std::int64_t(packet_oracle::authority));
    packet_oracle::finish(c);
}
inline void o2_00680B40_0x680b40(std::uint8_t* m, R5900Context* c, PS2Runtime*) {
    packet_oracle::trace.insert(packet_oracle::trace.end(),
                                {0x680b40, ref_read<std::uint16_t>(m, 0x3c25f8)});
    // The pass must clear the queue after the required route consumer returns.
    ref_write(m, 0x3c25f8, std::uint16_t(ref_read<std::uint16_t>(m, 0x3c25f8) + 1));
    packet_oracle::finish(c);
}
