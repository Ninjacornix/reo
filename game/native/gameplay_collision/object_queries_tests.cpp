#include "object_queries.hpp"
#include "ownership_reference.hpp"
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iterator>
#include <random>
#include <sstream>
namespace c = reo::native::gameplay_collision;
namespace r = c::room_objects;
namespace q = c::object_queries;
unsigned checks{}, rooms{}, queries{}, blocked_entry_zero{}, fallback_cases{}, unknown_cases{};
float maximum_error{};
std::vector<std::uint8_t> memory(0x800000);
void check(bool value, const char* why) {
    ++checks;
    if (!value) {
        std::fprintf(stderr, "object query check%u failed: %s\n", checks, why);
        std::exit(1);
    }
}
std::vector<std::byte> load(const char* path) {
    std::ifstream f(path, std::ios::binary);
    const std::vector<char> bytes{std::istreambuf_iterator<char>(f), {}};
    const auto span = std::as_bytes(std::span(bytes));
    return {span.begin(), span.end()};
}
std::uint32_t invoke(std::uint32_t pc, std::uint32_t a0 = 0, std::uint32_t a1 = 0,
                     std::uint32_t a2 = 0) {
    R5900Context ctx;
    ctx.pc = pc;
    ctx.g[29].lo = 0x7f0000;
    ctx.g[31].lo = 0x1234;
    ctx.g[4].lo = a0;
    ctx.g[5].lo = a1;
    ctx.g[6].lo = a2;
    PS2Runtime runtime;
    runtime.lookupFunction(pc)(memory.data(), &ctx, &runtime);
    return std::uint32_t(ctx.g[2].lo);
}
void equal(c::Vec3 a, c::Vec3 b) {
    for (const auto p : {std::pair{a.x, b.x}, std::pair{a.y, b.y}, std::pair{a.z, b.z}}) {
        const auto error = std::abs(p.first - p.second);
        maximum_error = std::max(maximum_error, error);
        check(error <= 0.001f, "original retained approach coordinates");
    }
}
void predicate(q::Predicate native, std::uint32_t pc, std::uint32_t a0, std::uint32_t a1 = 0) {
    const auto original = invoke(pc, a0, a1);
    if (native.status != q::Status::complete) {
        ++unknown_cases;
        return;
    }
    check(native.value == bool(original), "unchanged original directional predicate");
}
void mask(const r::Grid::Mask& m) {
    for (unsigned i = 0; i < m.size(); ++i)
        check(m[i] == ref_read<std::uint32_t>(memory.data(), 0x745d70 + i * 4),
              "combined mask publication follows exact source gates");
}
void counts(const r::Owner& owner, const r::InteractionOwner& interactions) {
    for (const auto& id : owner.objects())
        check(owner.get(id)->count ==
                  std::bit_cast<std::int8_t>(
                      memory[0x3c459b + 60 * (*interactions.source_ordinal(id))]),
              "authoritative capacity mutations after entry/exit");
}
std::vector<c::room_geometry::Occupant> actors(c::Vec3 center, unsigned profile) {
    std::vector<c::room_geometry::Occupant> result;
    constexpr std::array<unsigned, 3> bases{0x4a5c30, 0x417090, 0x42eb00},
        strides{0x10e0, 0x1170, 0xd90}, sizes{8, 10, 50};
    for (unsigned family = 0; family < 3; ++family)
        for (unsigned i = 0; i < sizes[family]; ++i) {
            const auto at = bases[family] + strides[family] * i;
            c::room_geometry::Occupant value{
                {center.x + float(int((i + profile) % 11) - 5) * 40,
                 center.y + float((i + profile) % 3) * 50,
                 center.z + float(int((i * 3 + profile) % 13) - 6) * 40},
                (i + profile) % 5 == 0,
                (i + profile) % 7 == 0};
            memory[at] = value.active;
            memory[at + 1] = value.visible;
            ref_write(memory.data(), at + 0x38, value.position);
            result.push_back(value);
        }
    return result;
}
void setup(r::Owner& owner, const std::vector<std::byte>& types, const std::vector<std::byte>& sto,
           unsigned room, const std::vector<std::byte>& grid) {
    const auto* t = reinterpret_cast<const std::uint8_t*>(types.data());
    const auto* s = reinterpret_cast<const std::uint8_t*>(sto.data());
    const auto count = ref_read<std::uint32_t>(t, 4), offset = ref_read<std::uint32_t>(t, 8),
               models = ref_read<std::uint32_t>(t, 12), placements = ref_read<std::uint32_t>(s, 4);
    invoke(0x6acf80);
    std::memset(memory.data() + 0x74b1c0, 0, 256);
    std::memcpy(memory.data() + 0x74b1c0, t + offset, count * 8);
    std::memcpy(memory.data() + 0x74b180, t + models, count * 2);
    for (unsigned i = 0; i < placements; ++i) {
        std::memcpy(memory.data() + 0x1000, s + 8 + 16 * i, 16);
        check(invoke(0x6ad0f0, 0x1000) != 0, "source room-object allocation");
    }
    ref_write(memory.data(), 0x3243dc, std::uint16_t(room));
    std::memcpy(memory.data() + 0x20000, grid.data(), grid.size());
    invoke(0x6ad860, 0x20000);
    check(owner.install_grid(std::uint16_t(room), grid), "native grid ready");
    r::InteractionOwner interactions(owner);
    for (const auto& id : owner.objects())
        if (owner.get(id)->room == room) {
            const auto at = 0x3c4580 + 60 * (*interactions.source_ordinal(id));
            invoke(0x6ad360, at + 8, at);
        }
}
void room(const char* type_path, const char* sto_path, unsigned room, const char* grid_path,
          unsigned variant) {
    auto types = load(type_path), sto = load(sto_path);
    const auto grid = load(grid_path);
    if (variant) {
        auto* t = reinterpret_cast<std::uint8_t*>(types.data());
        const auto count = ref_read<std::uint32_t>(t, 4), offset = ref_read<std::uint32_t>(t, 8);
        for (unsigned i = 0; i < count; ++i) {
            t[offset + 8 * i + 1] = 2;
            t[offset + 8 * i + 2] = 1;
        }
        auto* s = reinterpret_cast<std::uint8_t*>(sto.data());
        for (unsigned i = 0; i < ref_read<std::uint32_t>(s, 4); ++i)
            s[8 + 16 * i + 6] = 15;
    }
    auto owner = r::Owner::import(types, sto);
    setup(owner, types, sto, room, grid);
    r::InteractionOwner interactions(owner);
    r::Grid::Mask combined;
    for (const auto& id : owner.objects()) {
        const auto* o = owner.get(id);
        if (o->room != room)
            continue;
        const auto slot = *interactions.source_ordinal(id), external = o->external_id;
        const auto center = owner.center(*o);
        const auto at = 0x3c4580 + 60 * unsigned(slot);
        for (unsigned i = 0; i < 96; ++i) {
            const auto token = std::uint8_t(slot | ((i % 8) << 5)), direction = std::uint8_t(i % 9);
            const auto occupants = actors(center, i);
            combined.fill(0xa5a5a5a5);
            for (unsigned n = 0; n < combined.size(); ++n)
                ref_write(memory.data(), 0x745d70 + 4 * n, 0xa5a5a5a5u);
            predicate(q::padded_direction(owner, id, direction), 0x6af4b0, token, direction);
            const auto allowed = q::allowed_direction(owner, id, direction, occupants, combined);
            predicate(allowed, 0x6afe90, token, direction);
            mask(combined);
            const auto heading = std::uint16_t(i * 997);
            const auto classification =
                q::classify_direction(owner, id, heading, occupants, combined);
            ref_write(memory.data(), 0x10092, heading);
            const auto original_class = invoke(0x6b0680, token, 0x10000);
            check(classification.status == q::Status::complete &&
                      classification.value == original_class,
                  "original directional interaction class");
            mask(combined);
            for (const auto pair : {std::pair{1u, 0x6b0200u}, std::pair{2u, 0x6afff0u},
                                    std::pair{4u, 0x6b0310u}, std::pair{8u, 0x6b0100u}})
                predicate(q::leading_edge(owner, id, std::uint8_t(pair.first), combined),
                          pair.second, at);
            q::Approach approach{{123, 456, 789}, 321};
            ref_write(memory.data(), 0x10abc, approach.position);
            ref_write(memory.data(), 0x10ac8, approach.heading);
            check(q::approach(owner, id, heading, approach), "native approach admitted");
            invoke(0x6b0b80, 0x10000, token);
            equal(approach.position, ref_read<c::Vec3>(memory.data(), 0x10abc));
            check(approach.heading == ref_read<std::uint16_t>(memory.data(), 0x10ac8),
                  "original approach preserves cross coordinate and publishes facing");
            c::actors::Basis basis{{0.8f, 0, -0.6f}, {0, 1, 0}, {0.6f, 0, 0.8f}, {}};
            const c::Vec3 local{float(i % 7) - 3, 1, float(i % 9) - 4},
                position{center.x + float(int(i % 11) - 5) * 25,
                         center.y + float((i % 5) * 50) - 0.5f,
                         center.z + float(int(i % 13) - 6) * 25};
            ref_write(
                memory.data(), 0x10050,
                std::array<float, 16>{0.8f, 0, -0.6f, 0, 0, 1, 0, 0, 0.6f, 0, 0.8f, 0, 0, 0, 0, 1});
            ref_write(memory.data(), 0x101ac, local);
            ref_write(memory.data(), 0x10038, position);
            predicate(q::probe(owner, interactions, id, token, basis, local, position, heading),
                      0x6b0cf0, 0x10000, token);
            memory[80] = i % 2;
            const auto entry = q::enter(owner, interactions, token, position, i % 2);
            const auto original_entry = std::uint8_t(invoke(0x6af8b0, token, 0x10000));
            check(entry.status == q::Status::complete &&
                      std::uint8_t(entry.value) == original_entry,
                  "original entry half height and count mutation");
            if (owner.type(o->type)->capacity == 0) {
                check(original_entry == 0, "6AF8F0delay slot resets blocked entry return tozero");
                ++blocked_entry_zero;
            }
            counts(owner, interactions);
            const auto located = q::elevated(owner, interactions, position);
            memory[0x1100] = 77;
            ref_write(memory.data(), 0x1200, position);
            const auto original_located = invoke(0x6afd70, 0x1100, 0x1200);
            check(bool(located.object) == bool(original_located),
                  "source elevated object resolution");
            check(located.written ? memory[0x1100] == located.authored_ordinal
                                  : memory[0x1100] == 77,
                  "source conditional object-ordinal writes");
            const auto leave = q::exit(owner, interactions, position, i % 2);
            const auto original_leave = std::uint8_t(invoke(0x6af9e0, 0x10000));
            check(leave.status == q::Status::complete &&
                      std::uint8_t(leave.value) == original_leave,
                  "source exit half height/counter/fallback behavior");
            counts(owner, interactions);
            auto ctx = R5900Context{};
            ctx.pc = 0x6afe10;
            ctx.g[29].lo = 0x7f0000;
            ctx.g[31].lo = 0x1234;
            ctx.g[4].lo = token;
            PS2Runtime runtime;
            runtime.lookupFunction(0x6afe10)(memory.data(), &ctx, &runtime);
            check(q::height_offset(owner, id) == ctx.f[0], "source nonexplicit height offset");
            check(owner.get(id)->external_id == external,
                  "queries preserve authored logical identity");
            ++queries;
        }
    }
    ++rooms;
}
void fallback(const char* type_path, const char* grid_path) {
    auto types = load(type_path);
    auto* t = reinterpret_cast<std::uint8_t*>(types.data());
    const auto offset = ref_read<std::uint32_t>(t, 8);
    t[offset + 1] = 2;
    t[offset + 2] = 1;
    std::vector<std::byte> sto(8 + 31 * 16);
    auto* s = reinterpret_cast<std::uint8_t*>(sto.data());
    ref_write(s, 0, 2u);
    ref_write(s, 4, 31u);
    for (unsigned i = 0; i < 31; ++i) {
        s[8 + 16 * i] = 1;
        s[9 + 16 * i] = std::uint8_t(i + 1);
        s[11 + 16 * i] = 10;
        s[12 + 16 * i] = 10;
    }
    const auto grid = load(grid_path);
    auto owner = r::Owner::import(types, sto);
    setup(owner, types, sto, 1, grid);
    r::InteractionOwner interactions(owner);
    const auto id = *interactions.masked(31);
    interactions.increment(id);
    invoke(0x6af380, 31);
    const auto* g = owner.grid();
    const c::Vec3 point{g->origin.x - 100, g->origin.y + 49.5f, g->origin.z - 100};
    ref_write(memory.data(), 0x10038, point);
    memory[80] = 0;
    const auto value = q::exit(owner, interactions, point, false);
    check(value.used_slot31_fallback && value.value == std::uint8_t(invoke(0x6af9e0, 0x10000)) &&
              owner.get(id)->count == 0,
          "positive band but below50leavesFF and decrements physical31");
    counts(owner, interactions);
    ++fallback_cases;
}
int main(int argc, char** argv) {
    check(argc == 4, "owned room/profile/geometry arguments");
    const auto profiles = load(argv[2]), tables = load(argv[3]);
    std::memcpy(memory.data() + 0x723740, profiles.data(), profiles.size());
    std::memcpy(memory.data() + 0x719900, tables.data(), tables.size());
    for (unsigned i = 0; i < 4; ++i)
        memory[0x719900 + i] = std::uint8_t(i * 2);
    std::ifstream manifest(argv[1]);
    std::string line;
    bool first = true;
    while (std::getline(manifest, line)) {
        std::istringstream f(line);
        std::array<std::string, 5> fields;
        for (unsigned i = 0; i < 5; ++i)
            std::getline(f, fields[i], '\t');
        if (fields[0].empty())
            continue;
        for (unsigned variant = 0; variant < 2; ++variant)
            room(fields[0].c_str(), fields[1].c_str(), unsigned(std::stoi(fields[2])),
                 fields[3].c_str(), variant);
        if (first) {
            fallback(fields[0].c_str(), fields[3].c_str());
            first = false;
        }
    }
    check(rooms == 14 && queries > 0 && blocked_entry_zero > 0 && fallback_cases == 1,
          "query/policy/source-delay-slot coverage");
    std::printf("{\"checks\":%u,\"rooms\":%u,\"queries\":%u,\"blocked_entry_zero\":%u,\"fallback_"
                "cases\":%u,\"unknown_cases\":%u,\"maximum_error\":%.9g,\"game_launched\":false}\n",
                checks, rooms, queries, blocked_entry_zero, fallback_cases, unknown_cases,
                double(maximum_error));
}
