#include "game/native/gameplay_audio/owner.hpp"
#include "game/native/gameplay_audio/options.hpp"
#include "game/native/gameplay_audio/stream_levels.hpp"
#ifdef REO_ANIMATION_AUDIO_TESTS
#include "game/native/gameplay_world/animation_audio.hpp"
#endif
#include "audio_reference.hpp"
#include <fstream>
#include <future>
#include <iostream>
#include <thread>
#include <vector>
#include <source_location>
#ifdef REO_NODE_POSITION_AUDIO_TESTS
#include "game/native/gameplay_audio/scenario_cues.hpp"
#include "game/native/animation/model.hpp"
#include <filesystem>
#endif
#ifdef REO_SURFACE_AUDIO_TESTS
#include "game/native/gameplay_contact_world/contacts.hpp"
#include "game/native/gameplay_world/footwear.hpp"
#include <filesystem>
const reo::native::gameplay_collision::regions::World* original_audio_regions{};
std::string audio_test_directory;
#endif
namespace a = reo::native::gameplay_audio;
namespace b = reo::native::audio_banks::v2;
namespace s = reo::native::gameplay_session;
namespace b_inputs {
#include "game/native/audio_banks/v2/test_inputs.hpp"
}
using Event = std::array<std::uint32_t, 8>;
std::vector<Event> original_events;
std::uint64_t checks{}, calls{}, route_cases{}, import_cases{}, spatial_cases{}, settings_cases{},
    positional_cases{}, stock_banks{}, refused_banks{}, stock_events{}, mixed_frames{};
unsigned fail_at = UINT32_MAX;
a::SpatialContext spatial;
std::string active_case;
void check(bool value,const std::source_location& where=std::source_location::current()) {
    ++checks;
    if (!value)
        throw std::runtime_error("audio check " + std::to_string(checks) + " " + active_case+" at "+where.file_name()+":"+std::to_string(where.line()));
}
template <class T> T read(const std::uint8_t* m, unsigned at) {
    return transform_read<T>(m, at);
}
template <class T> void write(std::uint8_t* m, unsigned at, T v) {
    transform_write(m, at, v);
}
Event event(const b::Command& command) {
    return std::visit(
        [](const auto& c) -> Event {
            using T = std::decay_t<decltype(c)>;
            if constexpr (std::is_same_v<T, b::StartRequest>)
                return {0, c.port, c.index, c.group, c.volume, c.pan, c.pitch, c.program_offset};
            else if constexpr (std::is_same_v<T, b::ChangeRequest>)
                return {1, c.port, c.index, c.group, c.volume, c.pan, c.pitch, 0};
            else if constexpr (std::is_same_v<T, b::CancelRequest>)
                return {2, c.port, c.index, c.group, 0, 0, 0, 0};
            else if constexpr (std::is_same_v<T, b::SetAllVolumes>)
                return {3, c.value, 0, 0, 0, 0, 0, 0};
            else if constexpr (std::is_same_v<T, b::SetPortVolume>)
                return {4, c.port, c.value, 0, 0, 0, 0, 0};
            else if constexpr (std::is_same_v<T, b::SetMuted>)
                return {5, c.value, 0, 0, 0, 0, 0, 0};
            else if constexpr (std::is_same_v<T, b::SetMono>)
                return {6, c.value, 0, 0, 0, 0, 0, 0};
            else
                throw std::runtime_error("unexpected native command");
        },
        command);
}
struct Sink final : a::CommandSink {
    std::vector<Event> events;
    bool apply(const b::Command& command) noexcept override {
        if (events.size() == fail_at)
            return false;
        events.push_back(event(command));
        return true;
    }
};
void original_transform_port(std::uint8_t* m, R5900Context* c, PS2Runtime* r) {
    ++calls;
    const auto target = c->pc;
    if (target == 0x1a7310 || target == 0x1a7430 || target == 0x1a7550) {
        write(m, 0x2b0a68, 0u);
        write(m, 0x2b0a70, 0u);
        write(m, 0x2b0a80, original_events.size() == fail_at ? 0u : UINT32_MAX);
        if (target == 0x1a7310)
            sub_001A7310_0x1a7310(m, c, r);
        if (target == 0x1a7430)
            sub_001A7430_0x1a7430(m, c, r);
        if (target == 0x1a7550)
            sub_001A7550_0x1a7550(m, c, r);
        if (GPR_S64(c, 2) >= 0 && read<std::uint32_t>(m, 0x2b0a68) == 1) {
            const auto packed = read<std::uint32_t>(m, 0x2b0a80), op = packed >> 24;
            const auto port = (packed >> 16) & 255, index = (packed >> 8) & 255,
                       group = packed & 255;
            if (op == 8)
                original_events.push_back({2, port, index, group, 0, 0, 0, 0});
            else
                original_events.push_back(
                    {op & 8 ? 1u : 0u, port, index, group,
                     op & 1 ? read<std::uint8_t>(m, 0x2b0a84) : (op & 8 ? 255u : 127u),
                     op & 2 ? read<std::uint8_t>(m, 0x2b0a85) : (op & 8 ? 255u : 64u),
                     op & 4 ? read<std::uint16_t>(m, 0x2b0a86) : (op & 8 ? 65535u : 8192u),
                     op & 8 ? 0u : read<std::uint8_t>(m, 0x2b0a88)});
        }
        return;
    }
    switch (target) {
        case 0x1ac7f0:
            return sub_001AC7F0_0x1ac7f0(m, c, r);
        case 0x1acb60:
            return sub_001ACB60_0x1acb60(m, c, r);
        case 0x1aec80:
            return sub_001AEC80_0x1aec80(m, c, r);
        case 0x1b93d0:
            return sub_001B93D0_0x1b93d0(m, c, r);
        case 0x1b94b0:
            return sub_001B94B0_0x1b94b0(m, c, r);
#ifdef REO_ANIMATION_AUDIO_TESTS
        case 0x1b8bb0:return sub_001B8BB0_0x1b8bb0(m,c,r);
        case 0x1b8b20:return sub_001B8B20_0x1b8b20(m,c,r);
        case 0x5b4ce0:return o2_005B4CE0_0x5b4ce0(m,c,r);
#endif
#ifdef REO_NODE_POSITION_AUDIO_TESTS
        case 0x1b8870:return sub_001B8870_0x1b8870(m,c,r);
        case 0x1b8a10:return sub_001B8A10_0x1b8a10(m,c,r);
        case 0x1b93b0:return sub_001B93B0_0x1b93b0(m,c,r);
#endif
#ifdef REO_SURFACE_AUDIO_TESTS
        case 0x1b8f40:return sub_001B8F40_0x1b8f40(m,c,r);
        case 0x574680:{check(original_audio_regions!=nullptr);const auto p=read<reo::native::gameplay_collision::Vec3>(m,GPR_U32(c,4));SET_GPR_U32(c,2,original_audio_regions->select(p));return;}
#endif
        case 0x1aceb0:
            return sub_001ACEB0_0x1aceb0(m, c, r);
        case 0x107c68:
            std::memset(m + GPR_U32(c, 4), GPR_U32(c, 5) & 255, GPR_U32(c, 6));
            SET_GPR_U32(c, 2, GPR_U32(c, 4));
            return;
        case 0x1be6d0:
            SET_GPR_U32(c, 2, 128);
            return;
        case 0x1a7900:
        case 0x1a7de0:
        case 0x1148a0:
            SET_GPR_U32(c, 2, 0);
            return;
        case 0x108ed0:
            SET_GPR_U32(c, 2, 0);
            return;
        case 0x191430: {
            const auto dest = GPR_U32(c, 4);
            for (unsigned n = 0; n < 16; ++n)
                write(m, dest + 4 * n, n % 5 == 0 ? 1.0f : 0.0f);
            write(m, dest + 48, spatial.listener.x);
            write(m, dest + 52, spatial.listener.y);
            write(m, dest + 56, spatial.listener.z);
            return;
        }
        case 0x371880:
            c->f[0] = std::sqrt(c->f[12]);
            return;
        case 0x18fdf0:
        case 0x1af780:
            return;
        case 0x192040: {
            // Execute the complete original final projection, with the canonical
            // already-composed matrix in place of the retired scratchpad pipeline.
            const auto matrix = 0x680000u;
            std::memcpy(m + matrix, spatial.world_to_screen.data(), 64);
            SET_GPR_U32(c, 6, matrix);
            return sub_00191AB0_0x191ab0(m, c, r);
        }
        case 0x1921f0:
            c->f[0] = std::floor(c->f[12]);
            return;
        case 0x1a7bb0:
        case 0x1a7690:
        case 0x1a7730:
        case 0x1a7c50:
        case 0x1ae0c0: {
            if (original_events.size() == fail_at) {
                SET_GPR_S32(c, 2, -1);
                return;
            }
            if (target == 0x1a7bb0)
                original_events.push_back({5, GPR_U32(c, 4) != 0, 0, 0, 0, 0, 0, 0});
            if (target == 0x1a7690)
                original_events.push_back({3, GPR_U32(c, 4) & 65535, 0, 0, 0, 0, 0, 0});
            if (target == 0x1a7730)
                original_events.push_back(
                    {4, GPR_U32(c, 4) & 255, GPR_U32(c, 5) & 65535, 0, 0, 0, 0, 0});
            if (target == 0x1a7c50)
                original_events.push_back({6, GPR_U32(c, 4) == 0, 0, 0, 0, 0, 0, 0});
            if (target == 0x1ae0c0)
                original_events.push_back({7, GPR_U32(c, 4), GPR_U32(c, 5) & 127, 0, 0, 0, 0, 0});
            SET_GPR_U32(c, 2, 0);
            return;
        }
        default:
            throw std::runtime_error("undeclared original audio target " + std::to_string(target));
    }
}
R5900Context context(unsigned target) {
    R5900Context c;
    c.pc = target;
    SET_GPR_U32(&c, 29, 0x7f0000);
    SET_GPR_U32(&c, 31, 0x1234);
    return c;
}
void put_rows(std::uint8_t* m, unsigned bank, const a::Descriptors& rows) {
    auto* p = m + 0x2b3950 + bank * 1536;
    std::memset(p, 0, 1536);
    for (unsigned n = 0; n < 128; ++n, p += 12) {
        const auto& d = rows[n];
        p[0] = d.type;
        std::memcpy(p + 2, &d.pitch, 2);
        p[4] = d.gain;
        p[5] = d.pan;
        p[6] = d.gain_variation;
        p[7] = d.pitch_variation;
        p[8] = d.group;
        p[9] = d.replace_group;
        p[11] = d.next;
    }
}
std::uint32_t rng_state = 0x9635ab12;
unsigned random_word() {
    rng_state ^= rng_state << 13;
    rng_state ^= rng_state >> 17;
    rng_state ^= rng_state << 5;
    return rng_state;
}
void compare_route(std::vector<std::uint8_t>& m) {
    PS2Runtime runtime;
    for (unsigned test = 0; test < 32768; ++test) {
        a::Descriptors rows{};
        for (auto& row : rows)
            row.type = 2;
        const unsigned length = 1 + (random_word() % 8), bank = random_word() % 14,
                       start = random_word() % 100;
        for (unsigned n = 0; n < length; ++n) {
            auto& row = rows[start + n];
            row.type = random_word() % 5 == 0 ? 1 : 0;
            row.pitch = static_cast<std::uint16_t>(random_word());
            row.gain = static_cast<std::uint8_t>(random_word());
            row.pan = random_word() % 3 ? 255 : static_cast<std::uint8_t>(random_word());
            row.gain_variation = random_word() % 3 ? static_cast<std::uint8_t>(random_word()) : 0;
            row.pitch_variation = random_word() % 3 ? static_cast<std::uint8_t>(random_word()) : 0;
            row.group = static_cast<std::uint8_t>(random_word());
            row.replace_group = static_cast<std::uint8_t>(random_word());
            row.next = static_cast<std::uint8_t>(n + 1 == length ? 255 : start + n + 1);
        }
        if (test % 31 == 0)
            rows[start].next = static_cast<std::uint8_t>(start);
        a::Request request{bank,
                           start,
                           test % 5 ? random_word() % 256 : UINT32_MAX,
                           test % 4 ? random_word() % 256 : UINT32_MAX,
                           static_cast<std::uint8_t>(random_word()),
                           bool(test & 1)};
        if (request.change && rows[start].next == start)
            rows[start].next = 255;
        s::RandomState seed{static_cast<std::uint16_t>(random_word()),
                            static_cast<std::uint16_t>(random_word()), 0};
        s::Random native(seed);
        write(m.data(), 0x3244b0, seed.primary);
        write(m.data(), 0x3244b8, seed.secondary);
        const bool requested = test % 7 != 0;
        const auto phase = static_cast<std::uint8_t>(test % 11 == 0 ? 1 : 2);
        m[0x2b3934 + bank] = requested;
        m[0x2b3924 + bank] = phase;
        put_rows(m.data(), bank, rows);
        fail_at = test % 13 == 0 ? random_word() % length : UINT32_MAX;
        original_events.clear();
        auto c = context(request.change ? 0x1acb60 : 0x1ac7f0);
        SET_GPR_U32(&c, 4, bank);
        SET_GPR_U32(&c, 5, start);
        SET_GPR_U32(&c, 6, 0x76543210);
        SET_GPR_U32(&c, 7, request.gain);
        SET_GPR_U32(&c, 8, request.pan);
        SET_GPR_U32(&c, 9, 0x1234);
        SET_GPR_U32(&c, 10, request.tag);
        if (request.change)
            sub_001ACB60_0x1acb60(m.data(), &c, &runtime);
        else
            sub_001AC7F0_0x1ac7f0(m.data(), &c, &runtime);
        Sink sink;
        const auto result = a::route(rows, requested, phase, request, native, sink);
        if (result.source_return != GPR_S64(&c, 2) || sink.events != original_events) {
            std::cerr << "native=" << result.source_return << " original=" << GPR_S64(&c, 2)
                      << " counts=" << sink.events.size() << '/' << original_events.size()
                      << " bank=" << bank << " event=" << start << " requested=" << requested
                      << " phase=" << unsigned(phase) << " fail=" << fail_at
                      << " type=" << unsigned(rows[start].type) << '\n';
            throw std::runtime_error("route case " + std::to_string(test));
        }
        check(result.source_return == GPR_S64(&c, 2));
        check(sink.events == original_events);
        check(native.state().primary == read<std::uint16_t>(m.data(), 0x3244b0));
        check(native.state().secondary == read<std::uint16_t>(m.data(), 0x3244b8));
        ++route_cases;
    }
    fail_at = UINT32_MAX;
    a::Descriptors rows{};
    rows[0].next = 1;
    rows[1].next = 0;
    s::Random random;
    Sink sink;
    check(a::route(rows, false, 0, {0, 0}, random, sink).status == a::Status::cycle);
}
std::vector<std::uint8_t> snd(unsigned rows) {
    std::vector<std::uint8_t> bytes(64 + 16 + rows * 16);
    for (unsigned n = 0; n < 3; ++n) {
        write(bytes.data(), 8 + n * 8, 0u);
        write(bytes.data(), 12 + n * 8, 0u);
    }
    write(bytes.data(), 32, 64u);
    write(bytes.data(), 36, 16 + rows * 16);
    for (unsigned n = 0; n < rows * 16; ++n)
        bytes[80 + n] = static_cast<std::uint8_t>(random_word());
    return bytes;
}
void compare_import(std::vector<std::uint8_t>& m) {
    PS2Runtime runtime;
    for (unsigned mode = 0; mode < 2; ++mode)
        for (unsigned test = 0; test < 256; ++test) {
            const unsigned slot = test % (mode ? 16 : 14), count = 1 + (test % 140);
            auto bytes = snd(count);
            std::copy(bytes.begin(), bytes.end(), m.begin() + 0x600000);
            write(m.data(), 0x32440c, 0x600000u);
            auto c = context(mode ? 0x1ad220 : 0x1acfb0);
            SET_GPR_U32(&c, 4, mode ? 0x400000 : 0x600000);
            SET_GPR_U32(&c, 5, mode ? 0x410000 : slot);
            SET_GPR_U32(&c, 6, slot);
            if (mode)
                sub_001AD220_0x1ad220(m.data(), &c, &runtime);
            else
                sub_001ACFB0_0x1acfb0(m.data(), &c, &runtime);
            const auto imported =
                a::import_snd(bytes, slot, mode ? a::ImportMode::staged : a::ImportMode::direct);
            check(imported.status == a::Status::completed);
            for (unsigned n = 0; n < 128; ++n) {
                const auto* p = m.data() + 0x2b3950 + 1536 * slot + n * 12;
                const auto& d = imported.value.descriptors[n];
                check(d.type == p[0]);
                check(d.pitch == read<std::uint16_t>(p, 2));
                check(d.gain == p[4]);
                check(d.pan == p[5]);
                check(d.gain_variation == p[6]);
                check(d.pitch_variation == p[7]);
                check(d.group == p[8]);
                check(d.replace_group == p[9]);
                check(d.next == p[11]);
            }
            check(mode ? GPR_S64(&c, 2) == 0 : imported.value.source_return == GPR_U32(&c, 2));
            ++import_cases;
        }
    for (unsigned n = 0; n < 96; ++n) {
        auto bytes = snd(1);
        bytes.resize(n);
        check(a::import_snd(bytes, 0).status != a::Status::completed);
    }
    check(a::import_snd(snd(1), 14).status == a::Status::invalid_input);
    for (const unsigned declared : {0u, 16u, 31u}) {
        auto bytes = snd(1);
        write(bytes.data(), 36, declared);
        check(a::import_snd(bytes, 0).status == a::Status::invalid_asset);
    }
}
void compare_spatial(std::vector<std::uint8_t>& m) {
    PS2Runtime runtime;
    write(m.data(), 0x250230, 5.039370059967041f);
    for (unsigned test = 0; test < 16384; ++test) {
        spatial.listener = {float(int(random_word() % 1000) - 500),
                            float(int(random_word() % 1000) - 500),
                            float(int(random_word() % 1000) - 500)};
        spatial.world_to_screen = {};
        spatial.world_to_screen[0][0] = float(int(random_word() % 100) - 50) / 128;
        spatial.world_to_screen[1][0] = .17f;
        spatial.world_to_screen[2][0] = -.31f;
        spatial.world_to_screen[3][0] = 320;
        spatial.world_to_screen[3][3] = (test & 1) ? 1.0f : -1.0f;
        a::Vector point{float(int(random_word() % 10000) - 5000),
                        float(int(random_word() % 10000) - 5000),
                        float(int(random_word() % 10000) - 5000)};
        if (test < 6)
            point = {spatial.listener.x +
                         std::array<float, 6>{0, 100, 100.001f, 299.999f, 4799.999f, 4800}[test],
                     spatial.listener.y, spatial.listener.z};
        const auto* table = a::attenuation(test % 4);
        for (unsigned n = 0; n < 17; ++n)
            write(m.data(), 0x610000 + n * 4, (*table)[n]);
        std::memcpy(m.data() + 0x620000, &point, 12);
        auto c = context(0x1b94b0);
        SET_GPR_U32(&c, 4, 0x620000);
        SET_GPR_U32(&c, 5, 0x610000);
        SET_GPR_U32(&c, 6, 0x630000);
        SET_GPR_U32(&c, 7, 0x630004);
        sub_001B94B0_0x1b94b0(m.data(), &c, &runtime);
        const auto result = a::locate(point, spatial, *table);
        check((result.status == a::Status::completed) == bool(GPR_U32(&c, 2)));
        check(result.gain == read<std::uint32_t>(m.data(), 0x630000));
        check(result.pan == read<std::uint32_t>(m.data(), 0x630004));
        ++spatial_cases;
    }
}
void numeric_refusals() {
    a::SpatialContext context{};
    for (const float w : {0.0f, std::numeric_limits<float>::denorm_min()}) {
        context.world_to_screen[3][3] = w;
        check(a::locate({200, 0, 0}, context, *a::attenuation(0)).status == a::Status::numeric_domain);
        context.world_to_screen[3][0] = 1;
        check(a::locate({200, 0, 0}, context, *a::attenuation(0)).status == a::Status::numeric_domain);
        context.world_to_screen[3][0] = 0;
    }
}
void compare_positional(std::vector<std::uint8_t>& m, const char* path) {
    std::ifstream file(path, std::ios::binary);
    std::array<std::uint8_t, 292> bytes{};
    file.read(reinterpret_cast<char*>(bytes.data()), bytes.size());
    check(bool(file));
    std::copy_n(bytes.begin(), 16, m.begin() + 0x234bf0);
    for (unsigned selector = 0; selector < 4; ++selector) {
        const auto address = read<unsigned>(bytes.data(), selector * 4);
        const auto* native = a::attenuation(selector);
        for (unsigned n = 0; n < 17; ++n) {
            const auto value = read<unsigned>(bytes.data(), 16 + 68 * selector + 4 * n);
            check((*native)[n] == value);
            write(m.data(), address + 4 * n, value);
        }
    }
    const auto constant = read<float>(bytes.data(), 288);
    check(constant == 5.039370059967041f);
    write(m.data(), 0x250230, constant);
    PS2Runtime runtime;
    for (unsigned test = 0; test < 4096; ++test) {
        const unsigned actor_slot = test % 6, bank = actor_slot + 8, index = test % 128,
                       selector = test % 4;
        a::Descriptors rows{};
        for (auto& row : rows)
            row.type = 255;
        rows[index] = {0, std::uint16_t(test), 100, 255, 13, 11, 7, 1, 255};
        put_rows(m.data(), bank, rows);
        m[0x2b3934 + bank] = 0;
        s::RandomState seed{0, static_cast<std::uint16_t>(random_word()), 0};
        s::Random random(seed);
        write(m.data(), 0x3244b0, seed.primary);
        write(m.data(), 0x3244b8, seed.secondary);
        spatial.listener = {10, 20, 30};
        spatial.world_to_screen = {};
        spatial.world_to_screen[0][0] = .5f;
        spatial.world_to_screen[3][0] = 320;
        spatial.world_to_screen[3][3] = 1;
        const a::Vector point{float(int(random_word() % 10000) - 5000), 20, 30};
        std::memcpy(m.data() + 0x620000, &point, 12);
        const bool wrapper = test & 1, change = !wrapper && bool(test & 2);
        const std::uint8_t tag = wrapper ? 0 : std::uint8_t(test);
        original_events.clear();
        auto c = context(wrapper ? 0x1b8d40 : 0x1b93d0);
        SET_GPR_U32(&c, 4, wrapper ? actor_slot : bank);
        SET_GPR_U32(&c, 5, wrapper ? 0x620000 : index);
        SET_GPR_U32(&c, 6, wrapper ? index : 0x87654321);
        SET_GPR_U32(&c, 7, 0x620000);
        SET_GPR_U32(&c, 8, selector);
        SET_GPR_U32(&c, 9, change);
        SET_GPR_U32(&c, 10, tag);
        if (wrapper)
            sub_001B8D40_0x1b8d40(m.data(), &c, &runtime);
        else
            sub_001B93D0_0x1b93d0(m.data(), &c, &runtime);
        Sink sink;
        const auto result = a::positional(rows, false, 0, {bank, index, 0, 0, tag, change}, point,
                                          spatial, wrapper ? 1 : selector, random, sink);
        check(result.status == a::Status::completed || result.status == a::Status::skipped);
        check(sink.events == original_events);
        check(random.state().secondary == read<std::uint16_t>(m.data(), 0x3244b8));
        ++positional_cases;
    }
}
struct Streams final : a::StreamLevels {
    std::vector<Event>* events;
    bool maximum(unsigned c, std::uint8_t v) noexcept override {
        events->push_back({7, c, v, 0, 0, 0, 0, 0});
        return true;
    }
};
void compare_settings(std::vector<std::uint8_t>& m) {
    PS2Runtime runtime;
    for (unsigned test = 0; test < 256; ++test) {
        s::Options options{};
        options.effects_volume = static_cast<std::uint8_t>(test);
        options.music_volume = static_cast<std::uint8_t>(255 - test);
        options.audio_mode = test & 1;
        Sink sink;
        Streams streams;
        streams.events = &sink.events;
        a::Settings settings(options, sink, streams);
        original_events.clear();
        fail_at = UINT32_MAX;
        write(m.data(), 0x2b3838, 0u);
        auto c = context(0x1b86f0);
        SET_GPR_U32(&c, 4, test);
        sub_001B86F0_0x1b86f0(m.data(), &c, &runtime);
        const auto effects = settings.effects();
        check(effects.banks && effects.streams);
        check(sink.events == original_events);
        c = context(0x1b8780);
        SET_GPR_U32(&c, 4, 255 - test);
        sub_001B8780_0x1b8780(m.data(), &c, &runtime);
        check(settings.music());
        check(sink.events == original_events);
        c = context(0x1acf60);
        SET_GPR_U32(&c, 4, test & 1);
        sub_001ACF60_0x1acf60(m.data(), &c, &runtime);
        check(settings.mode());
        check(sink.events == original_events);
        ++settings_cases;
    }
    for (unsigned test = 0; test < 128; ++test) {
        Sink sink;
        a::GainControl gain;
        write(m.data(), 0x2b3838, 0u);
        original_events.clear();
        for (unsigned step = 0; step < 4; ++step) {
            const unsigned value = (step % 2) ? test : 0;
            fail_at = (test % 7 == 0) ? unsigned(sink.events.size()) : UINT32_MAX;
            auto c = context(0x1aceb0);
            SET_GPR_S32(&c, 4, -1);
            SET_GPR_U32(&c, 5, value);
            sub_001ACEB0_0x1aceb0(m.data(), &c, &runtime);
            const bool ok = gain.apply(sink, -1, value);
            check(ok == (GPR_S64(&c, 2) >= 0));
            check(sink.events == original_events);
            check(gain.zero_gate() == bool(read<std::uint32_t>(m.data(), 0x2b3838)));
        }
    }
    fail_at = UINT32_MAX;
}
void actual_engine() {
    auto engine = std::make_shared<b::Session>();
    s::Random random({5, 7, 0});
    a::Owner owner(engine, random);
    const auto input = b_inputs::bank();
    a::Descriptors rows{};
    for (auto& row : rows)
        row.type = 2;
    rows[0] = {0, 0, 96, 31, 0, 0, 7, 1, 255};
    auto first = owner.begin_bank(8);
    auto second = owner.begin_bank(8);
    check(owner.request({8, 0}).status == a::Status::pending);
    const std::array<std::span<const std::uint8_t>, 3> parts{input.hd, input.bd, input.tq};
    check(owner.install_parts(first, rows, parts).status == a::Status::stale);
    check(!engine->snapshot().ports[8].loaded);
    check(owner.install_parts(second, rows, parts).status == a::Status::completed);
    check(owner.state(8) == a::Status::completed);
    check(owner.request({8, 0}).status == a::Status::completed);
    const auto snap = engine->snapshot();
    bool found = false;
    for (const auto& r : snap.ports[8].requests)
        if (r.sequence.active) {
            check(r.index == 0);
            check(r.group == 7);
            check(r.cancel_flags == 2);
            check(r.request_volume == 96);
            check(r.request_pan == 31);
            found = true;
        }
    check(found);
    auto foreign_engine = std::make_shared<b::Session>();
    a::Owner foreign(foreign_engine, random);
    auto foreign_ticket = foreign.begin_bank(8);
    check(owner.install_parts(foreign_ticket, rows, parts).status == a::Status::stale);
    check(owner.unload(8).status == a::Status::completed);
    check(owner.state(8) == a::Status::unavailable);
    check(!engine->snapshot().ports[8].loaded);
    check(owner.bound_to(random));
    s::Random other;
    check(!owner.bound_to(other));
    a::SessionCommands commands(engine);
    check(commands.apply(b::SetMono{true}));
    check(engine->snapshot().mono);
    check(commands.apply(b::SetAllVolumes{0}));
    check(engine->snapshot().ports[1].volume == 0);
}
struct Gains final : b::GainProvider {
    float gain(unsigned, unsigned, std::uint64_t) noexcept override {
        return 1;
    }
};
struct StreamOutput final : reo::native::gameplay_scenario::StreamBackend {
    using Status = reo::native::gameplay_scenario::StreamStatus;
    std::array<int, 3> gains{};
    reo::native::gameplay_scenario::StreamValue phase(std::uint8_t) noexcept override {
        return {Status::completed, 0};
    }
    Status start(std::uint8_t, reo::native::gameplay_scenario::StreamRequest,
                 std::uint32_t) noexcept override {
        return Status::completed;
    }
    Status stop(std::uint8_t) noexcept override {
        return Status::completed;
    }
    Status pause(std::uint8_t, bool, std::uint32_t) noexcept override {
        return Status::completed;
    }
    Status attenuation(std::uint8_t c, std::int32_t v) noexcept override {
        gains[c] = v;
        return Status::completed;
    }
    Status service(std::uint32_t) noexcept override {
        return Status::completed;
    }
};
void settings_composition() {
    using namespace reo::native::gameplay_scenario;
    auto engine = std::make_shared<b::Session>();
    a::SessionCommands commands(engine);
    const auto curve = file1_stream_gain_curve();
    StreamChannels channels(curve);
    StreamOutput output;
    a::StreamLevelsBinding levels(channels, output);
    s::Options options{};
    a::Settings settings(options, commands, levels);
    for (unsigned value = 0; value < 8; ++value) {
        options.audio_mode = value & 1;
        options.effects_volume = std::uint8_t(value);
        options.music_volume = std::uint8_t(7 - value);
        check(settings.mode());
        const auto result = settings.effects();
        check(result.banks && result.streams);
        check(settings.music());
        const auto snap = engine->snapshot();
        check(snap.mono == bool(value & 1));
        check(snap.muted == (value == 0));
        const auto master = unsigned(256.0f * (float(value) / 7));
        for (const auto& port : snap.ports)
            check(port.volume == master);
        const auto fx = unsigned(127.0f * (float(value) / 7)),
                   music = unsigned(127.0f * (float(7 - value) / 7));
        check(channels.snapshot().channels[1].maximum == int(fx));
        check(channels.snapshot().channels[2].maximum == int(fx));
        check(channels.snapshot().channels[0].maximum == int(music));
        check(output.gains[1] == curve[fx] / 10);
        check(output.gains[0] == curve[music] / 10);
    }
}
struct PausedAllocation final : b::AllocationSource {
    b::HeapSource heap;
    bool first{true};
    std::promise<void> entered, resume;
    std::shared_future<void> released = resume.get_future().share();
    void* allocate(std::size_t size, std::size_t alignment) override {
        if (first) {
            first = false;
            entered.set_value();
            released.wait();
        }
        return heap.allocate(size, alignment);
    }
    void deallocate(void* p, std::size_t size, std::size_t alignment) noexcept override {
        heap.deallocate(p, size, alignment);
    }
};
void replacement_composition() {
    auto source = std::make_shared<PausedAllocation>();
    b::Config config;
    config.allocation_source = source;
    auto engine = std::make_shared<b::Session>(config);
    s::Random random;
    a::Owner owner(engine, random);
    const auto input = b_inputs::bank();
    const std::array<std::span<const std::uint8_t>, 3> parts{input.hd, input.bd, input.tq};
    a::Descriptors descriptors{};
    const auto old = owner.begin_bank(0);
    a::BankResult result;
    std::thread worker([&] { result = owner.install_parts(old, descriptors, parts); });
    source->entered.get_future().wait();
    const auto replacement = owner.begin_bank(0);
    source->resume.set_value();
    worker.join();
    check(result.status == a::Status::stale);
    check(!engine->snapshot().ports[0].loaded);
    check(owner.state(0) == a::Status::pending);
    check(owner.install_parts(replacement, descriptors, parts).status == a::Status::completed);
    check(engine->reset() == b::Status::ok);
    check(owner.state(0) == a::Status::unavailable);
    const auto seed = random.state();
    check(owner.request({0, 0}).status == a::Status::unavailable);
    check(random.state() == seed);
    check(owner.install_parts(old, descriptors, parts).status == a::Status::stale);
}
b::Command command_from_event(const Event& e) {
    switch (e[0]) {
        case 0:
            return b::StartRequest{std::uint8_t(e[1]), std::uint8_t(e[2]), std::uint8_t(e[3]),
                                   std::uint8_t(e[4]), std::uint8_t(e[5]), std::uint16_t(e[6]),
                                   std::uint8_t(e[7])};
        case 1:
            return b::ChangeRequest{std::uint8_t(e[1]), std::uint8_t(e[2]), std::uint8_t(e[3]),
                                    std::uint8_t(e[4]), std::uint8_t(e[5]), std::uint16_t(e[6])};
        case 2:
            return b::CancelRequest{std::uint8_t(e[1]), std::uint8_t(e[2]), std::uint8_t(e[3])};
        default:
            throw std::runtime_error("unexpected stock audio command");
    }
}
void stock_composition(std::vector<std::uint8_t>& m, const char* path) {
    std::ifstream corpus(path, std::ios::binary);
    check(bool(corpus));
    unsigned count{};
    corpus.read(reinterpret_cast<char*>(&count), 4);
    check(count == 104);
    PS2Runtime runtime;
    Gains gains;
    for (unsigned asset = 0; asset < count; ++asset) {
        active_case = "stock asset " + std::to_string(asset);
        unsigned size{};
        corpus.read(reinterpret_cast<char*>(&size), 4);
        check(size > 40 && size < 0x400000);
        std::vector<std::uint8_t> bytes(size);
        corpus.read(reinterpret_cast<char*>(bytes.data()), size);
        check(bool(corpus));
        auto engine = std::make_shared<b::Session>();
        b::Session reference;
        s::Random random({123, 234, 0});
        a::Owner owner(engine, random);
        const auto imported = a::import_snd(bytes, 0);
        if (asset == 57) {
            check(read<unsigned>(bytes.data(), 32) == 0 && read<unsigned>(bytes.data(), 36) == 0);
            check(imported.status == a::Status::invalid_asset);
            ++refused_banks;
            continue;
        }
        check(imported.status == a::Status::completed);
        const auto ticket = owner.begin_bank(0);
        const auto installed = owner.install(ticket, bytes);
        if (installed.status != a::Status::completed)
            throw std::runtime_error("stock bank install " + std::to_string(asset) + " status " +
                                     std::to_string(int(installed.engine)));
        check(installed.status == a::Status::completed);
        auto token = reference.begin_submission();
        check(token.status == b::Status::ok);
        const auto& p = imported.value.parts;
        auto capture = reference.capture(token.value, {p[0].size, p[1].size, p[2].size});
        check(capture.status == b::Status::ok);
        const std::array<std::span<std::uint8_t>, 3> dest{capture.value.hd(), capture.value.bd(),
                                                          capture.value.tq()};
        for (unsigned n = 0; n < 3; ++n)
            std::copy_n(bytes.begin() + p[n].offset, p[n].size, dest[n].begin());
        auto prepared = reference.prepare(token.value, std::move(capture.value));
        check(prepared.status == b::Status::ok);
        check(reference.install(token.value, 0, prepared.value) == b::Status::ok);
        token.value = {};
        std::copy(bytes.begin(), bytes.end(), m.begin() + 0x600000);
        auto import_context = context(0x1acfb0);
        SET_GPR_U32(&import_context, 4, 0x600000);
        SET_GPR_U32(&import_context, 5, 0);
        sub_001ACFB0_0x1acfb0(m.data(), &import_context, &runtime);
        write(m.data(), 0x3244b0, std::uint16_t(123));
        write(m.data(), 0x3244b8, std::uint16_t(234));
        m[0x2b3934] = 0;
        for (unsigned index = 0; index < 128; ++index) {
            if (imported.value.descriptors[index].type != 0)
                continue;
            for (unsigned change = 0; change < 2; ++change) {
                active_case = "stock asset " + std::to_string(asset) + " index " +
                              std::to_string(index) + " change " + std::to_string(change);
                original_events.clear();
                auto c = context(change ? 0x1acb60 : 0x1ac7f0);
                SET_GPR_U32(&c, 4, 0);
                SET_GPR_U32(&c, 5, index);
                SET_GPR_U32(&c, 6, 99);
                SET_GPR_U32(&c, 7, 127);
                SET_GPR_U32(&c, 8, 63);
                SET_GPR_U32(&c, 10, 0);
                if (change)
                    sub_001ACB60_0x1acb60(m.data(), &c, &runtime);
                else
                    sub_001AC7F0_0x1ac7f0(m.data(), &c, &runtime);
                for (const auto& e : original_events) {
                    const auto cmd = command_from_event(e);
                    check(reference.apply({&cmd, 1}).status == b::Status::ok);
                }
                const auto result = owner.request({0, index, 127, 63, 0, bool(change)});
                check(result.status == a::Status::completed);
                check(result.commands == original_events.size());
                check(random.state().secondary == read<std::uint16_t>(m.data(), 0x3244b8));
                const auto actual = engine->snapshot(), expected = reference.snapshot();
                check(actual.request_age == expected.request_age);
                for (unsigned slot = 0; slot < 16; ++slot) {
                    const auto& x = actual.ports[0].requests[slot];
                    const auto& y = expected.ports[0].requests[slot];
                    check(x.index == y.index && x.group == y.group && x.priority == y.priority &&
                          x.cancel_flags == y.cancel_flags &&
                          x.request_volume == y.request_volume && x.request_pan == y.request_pan &&
                          x.request_pitch == y.request_pitch &&
                          x.sequence.active == y.sequence.active &&
                          x.sequence.cursor == y.sequence.cursor &&
                          x.sequence.program_offset == y.sequence.program_offset);
                }
                std::array<float, 400> output{}, expected_output{};
                check(engine->mix_add(output.data(), 200, gains) == b::Status::ok);
                check(reference.mix_add(expected_output.data(), 200, gains) == b::Status::ok);
                check(output == expected_output);
                mixed_frames += 200;
                ++stock_events;
            }
        }
        ++stock_banks;
    }
}
#ifdef REO_ANIMATION_AUDIO_TESTS
#include "animation_audio_tests.inc"
#endif
#ifdef REO_SURFACE_AUDIO_TESTS
#include "surface_audio_tests.inc"
#endif
#ifdef REO_NODE_POSITION_AUDIO_TESTS
#include "node_position_audio_tests.inc"
#endif
int main(int argc, char** argv) {
    try {
        check(argc == 3);
        std::vector<std::uint8_t> memory(0x2000000);
#ifdef REO_ANIMATION_AUDIO_TESTS
        compare_positional(memory,argv[2]);
#ifdef REO_NODE_POSITION_AUDIO_TESTS
        compare_node_position_audio(memory,std::filesystem::path(argv[1]).parent_path());
        std::cout<<"{\"checks\":"<<checks<<",\"node_cases\":"<<node_cases<<",\"position_cases\":"<<position_cases<<",\"remap_cases\":"<<remap_cases<<",\"commands\":"<<node_position_commands<<",\"mixed_frames\":"<<node_position_mixed_frames<<",\"signal_samples\":"<<node_position_signal<<",\"refusals\":"<<node_position_refusals<<",\"original_calls\":"<<calls<<",\"game_launched\":false}\n";
        return 0;
#endif
#ifdef REO_SURFACE_AUDIO_TESTS
        audio_test_directory=std::filesystem::path(argv[1]).parent_path().string();
        compare_surface_audio(memory);
        std::cout<<"{\"checks\":"<<checks<<",\"surface_audio_cases\":"<<surface_audio_cases<<",\"footwear_cases\":"<<footwear_cases<<",\"surface_audio_commands\":"<<surface_audio_commands<<",\"surface_audio_mixed_frames\":"<<surface_audio_mixed_frames<<",\"surface_audio_refusals\":"<<surface_audio_refusals<<",\"original_calls\":"<<calls<<",\"game_launched\":false}\n";
        return 0;
#endif
        compare_animation_frontends(memory);
        std::cout<<"{\"checks\":"<<checks<<",\"frontend_cases\":"<<frontend_cases<<",\"frontend_commands\":"<<frontend_commands<<",\"frontend_family_commands\":["<<frontend_family_commands[0]<<','<<frontend_family_commands[1]<<','<<frontend_family_commands[2]<<"],\"frontend_mixed_frames\":"<<frontend_mixed_frames<<",\"frontend_signal_samples\":"<<frontend_signal_samples<<",\"frontend_refusals\":"<<frontend_refusals<<",\"original_calls\":"<<calls<<",\"game_launched\":false}\n";
        return 0;
#endif
        compare_route(memory);
        compare_import(memory);
        compare_spatial(memory);
        numeric_refusals();
        compare_positional(memory, argv[2]);
        compare_settings(memory);
        actual_engine();
        settings_composition();
        replacement_composition();
        stock_composition(memory, argv[1]);
        std::cout << "{\"checks\":" << checks << ",\"route_cases\":" << route_cases
                  << ",\"import_cases\":" << import_cases << ",\"spatial_cases\":" << spatial_cases
                  << ",\"positional_cases\":" << positional_cases
                  << ",\"settings_cases\":" << settings_cases << ",\"stock_banks\":" << stock_banks
                  << ",\"refused_banks\":" << refused_banks << ",\"stock_events\":" << stock_events
                  << ",\"mixed_frames\":" << mixed_frames << ",\"original_calls\":" << calls
                  << ",\"game_launched\":false}\n";
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }
}
