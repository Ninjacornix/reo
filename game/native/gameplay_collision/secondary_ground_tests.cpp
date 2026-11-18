#include "secondary_ground.hpp"
#include "secondary_reference.hpp"
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iterator>
#include <random>
namespace c = reo::native::gameplay_collision;
namespace g = c::ground;
namespace r = c::response;
unsigned checks{}, pass_cases{}, probe_cases{}, classified_cases{}, owned_assets{}, stock_probes{};
float maximum_error{};
void check(bool value, const char* why) {
    ++checks;
    if (!value) {
        std::fprintf(stderr, "secondary ground check %u failed: %s\n", checks, why);
        std::exit(1);
    }
}
std::vector<std::uint8_t>& storage() {
    static std::vector<std::uint8_t> value(0x800000);
    return value;
}
R5900Context context(std::uint32_t at) {
    R5900Context result;
    result.pc = at;
    result.g[29].lo = 0x7f0000;
    result.g[31].lo = 0x1234;
    return result;
}
std::uint32_t address(unsigned index) {
    return 0x10000 + 0x2000 * index;
}
void install(std::span<const std::byte> bytes) {
    auto& memory = storage();
    check(bytes.size() < 0x1b0000, "owned floor grid fits isolated oracle range");
    std::memcpy(memory.data() + 0x40000, bytes.data(), bytes.size());
    auto ctx = context(0x616310);
    ctx.g[4].lo = 0x40000;
    PS2Runtime runtime;
    o2_00616310_0x616310(memory.data(), &ctx, &runtime);
}
std::vector<std::byte> floor_bytes(std::span<const r::Triangle> triangles) {
    // One immutable native grid cell with independently relocated original copy.
    std::vector<std::byte> result(48 + 4 * (triangles.size() + 1) + 56 * triangles.size());
    const auto put = [&](std::size_t at, std::uint32_t value) {
        std::memcpy(result.data() + at, &value, 4);
    };
    put(8, 2000);
    put(12, 2000);
    put(16, 1);
    put(20, 1);
    put(24, 0);
    put(28, 0);
    put(32, 32);
    const auto records = std::uint32_t(48 + 4 * (triangles.size() + 1));
    put(36, records - 8);
    put(40, 40);
    for (unsigned i = 0; i < triangles.size(); ++i) {
        put(48 + 4 * i, 56 * i);
        std::memcpy(result.data() + records + 56 * i, &triangles[i], 56);
    }
    put(48 + 4 * triangles.size(), 0xffffffffu);
    return result;
}
r::Triangle triangle(float nx, float nz, float height, std::uint32_t flags) {
    const c::Vec3 n{nx, 1, nz};
    const auto y = [&](float x, float z) { return (height - nx * x) - nz * z; };
    return {flags, {{{0, y(0, 0), 0}, {2000, y(2000, 0), 0}, {0, y(0, 2000), 2000}}}, n, -height};
}
struct Subject {
    c::actors::EntityId id;
    c::Vec3 position, normal{0, 1, 0}, displacement;
    float height{-177};
    std::uint8_t surface{77}, material{88}, subtype{};
    std::uint16_t attributes{999}, controls{};
    std::uint32_t auxiliary{};
    std::array<std::int16_t, 3> rotation{};
    g::ProbeStates states;
    g::View view() {
        return {position, normal,     height,    surface,
                material, attributes, auxiliary, {rotation[0], rotation[1], rotation[2]}};
    }
    g::Entry entry() {
        return {id, view(), displacement, controls, subtype, states};
    }
};
void write(const Subject& a, unsigned index) {
    auto& m = storage();
    const auto at = address(index);
    std::fill(m.begin() + at, m.begin() + at + 0x2000, 0);
    ref_write(m.data(), at + 0x38, a.position);
    ref_write(m.data(), at + 0x178, a.normal);
    ref_write(m.data(), at + 0x170, a.height);
    ref_write(m.data(), at + 0xb28, a.displacement);
    ref_write(m.data(), at + 0xba4, a.auxiliary);
    ref_write(m.data(), at + 0x54a, a.controls);
    ref_write(m.data(), at + 0x176, a.attributes);
    for (unsigned j = 0; j < 3; ++j)
        ref_write(m.data(), at + 0x90 + 2 * j, a.rotation[j]);
    m[at + 3] = a.subtype;
    m[at + 0x174] = a.surface;
    m[at + 0x175] = a.material;
    ref_write(m.data(), at + 0xd45, a.states.kind_one);
    ref_write(m.data(), at + 0xd39, a.states.kind_twenty_nine);
    ref_write(m.data(), at + 0xd25, a.states.kind_twenty_d);
}
void scalar_equal(float actual, float expected, const char* why) {
    maximum_error = std::max(maximum_error, std::abs(actual - expected));
    check(actual == expected, why);
}
void equal(const Subject& a, unsigned index) {
    const auto* m = storage().data();
    const auto at = address(index);
    const auto pos = ref_read<c::Vec3>(m, at + 0x38);
    scalar_equal(a.position.x, pos.x, "original secondary X");
    scalar_equal(a.position.y, pos.y, "original secondary Y/snap");
    scalar_equal(a.position.z, pos.z, "original secondary Z");
    scalar_equal(a.height, ref_read<float>(m, at + 0x170),
                 "original secondary selected floor height");
    const auto normal = ref_read<c::Vec3>(m, at + 0x178);
    scalar_equal(a.normal.x, normal.x, "original floor normal X");
    scalar_equal(a.normal.y, normal.y, "original floor normal Y");
    scalar_equal(a.normal.z, normal.z, "original floor normal Z");
    check(a.surface == m[at + 0x174] && a.material == m[at + 0x175] &&
              a.attributes == ref_read<std::uint16_t>(m, at + 0x176),
          "original surface/material/attributes");
    check(a.states.kind_one == ref_read<std::int8_t>(m, at + 0xd45) &&
              a.states.kind_twenty_nine == ref_read<std::int8_t>(m, at + 0xd39) &&
              a.states.kind_twenty_d == ref_read<std::int8_t>(m, at + 0xd25),
          "original selected state record only");
}
class Walls final : public g::Walls {
  public:
    std::span<Subject> subjects;
    std::vector<unsigned> calls;
    explicit Walls(std::span<Subject> s) : subjects(s) {}
    void correct(const c::actors::EntityId& id, g::View actor) override {
        unsigned index{};
        while (index < subjects.size() && subjects[index].id != id)
            ++index;
        check(index < subjects.size(), "native wall query retains owned identity");
        calls.push_back(index);
        actor.position.x += 1.25f;
        actor.position.z -= 0.5f;
    }
};
void compare_pass(std::array<Subject, 4> subjects, const r::Grid& floors, bool reverse) {
    auto& m = storage();
    secondary_oracle::wall_calls.clear();
    std::array<g::Entry, 4> entries{
        subjects[reverse ? 3 : 0].entry(), subjects[reverse ? 2 : 1].entry(),
        subjects[reverse ? 1 : 2].entry(), subjects[reverse ? 0 : 3].entry()};
    for (unsigned i = 0; i < 4; ++i)
        write(subjects[i], i);
    for (unsigned i = 0; i < 4; ++i) {
        const unsigned current = reverse ? 3 - i : i;
        const auto next = i == 3 ? 0u : address(reverse ? 2 - i : i + 1);
        ref_write(m.data(), address(current) + 0x1c, next);
    }
    ref_write(m.data(), 0x3b5900, address(reverse ? 3 : 0));
    auto ctx = context(0x637740);
    PS2Runtime runtime;
    o2_00637740_0x637740(m.data(), &ctx, &runtime);
    Walls walls(subjects);
    const auto result = g::update(entries, floors, walls);
    check(result.visited == 4 && result.unknown_probes == 0,
          "all native ordered secondary entries processed");
    check(walls.calls.size() == secondary_oracle::wall_calls.size(), "wall provider call count");
    for (unsigned i = 0; i < walls.calls.size(); ++i)
        check(address(walls.calls[i]) == secondary_oracle::wall_calls[i],
              "original reverse-list wall evaluation order");
    for (unsigned i = 0; i < 4; ++i)
        equal(subjects[i], i);
    ++pass_cases;
}
void classify_compare(c::Vec3 point, std::uint16_t yaw, const r::Grid& floors) {
    auto& m = storage();
    ref_write(m.data(), 0x8000, point);
    ref_write(m.data(), address(0) + 0x92, yaw);
    auto ctx = context(0x6379d0);
    ctx.g[4].lo = address(0);
    ctx.g[5].lo = 0x8000;
    PS2Runtime runtime;
    o2_006379D0_0x6379d0(m.data(), &ctx, &runtime);
    const auto expected = std::bit_cast<std::int8_t>(std::uint8_t(ctx.g[2].lo));
    check(g::classify(point, yaw, floors) == expected,
          "original floor-basis heading signed classification");
    ++classified_cases;
}
void probe_compare(Subject actor, const r::Grid& floors) {
    write(actor, 0);
    auto& m = storage();
    ref_write(m.data(), 0x8001, actor.states.kind_one);
    auto ctx = context(0x637860);
    ctx.g[4].lo = address(0);
    ctx.g[5].lo = 0x8000;
    PS2Runtime runtime;
    o2_00637860_0x637860(m.data(), &ctx, &runtime);
    check(g::probe(actor.view(), actor.states.kind_one, floors) == g::ProbeStatus::completed,
          "defined native offset probe");
    ref_write(m.data(), address(0) + 0xd45, ref_read<std::int8_t>(m.data(), 0x8001));
    equal(actor, 0);
    ++probe_cases;
}
void stock(const char* path) {
    std::ifstream input(path, std::ios::binary);
    std::vector<char> data((std::istreambuf_iterator<char>(input)), {});
    const auto bytes = std::as_bytes(std::span(data));
    const auto grid = r::Grid::import(bytes);
    install(bytes);
    for (const auto& t : grid.triangles()) {
        const c::Vec3 point{(t.vertices[0].x + t.vertices[1].x + t.vertices[2].x) / 3,
                            (t.vertices[0].y + t.vertices[1].y + t.vertices[2].y) / 3 + 20,
                            (t.vertices[0].z + t.vertices[1].z + t.vertices[2].z) / 3};
        classify_compare(point, std::uint16_t(stock_probes * 3571u), grid);
        Subject actor;
        actor.position = point;
        actor.auxiliary = stock_probes % 2 ? 0x100u : 0x80000001u;
        actor.rotation = {std::int16_t(stock_probes * 71u), std::int16_t(stock_probes * 3571u),
                          std::int16_t(stock_probes * 509u)};
        actor.states.kind_one = std::int8_t(int(stock_probes % 3) - 1);
        probe_compare(actor, grid);
        ++stock_probes;
    }
    ++owned_assets;
}
int main(int argc, char** argv) {
    auto& memory = storage();
    ref_write(memory.data(), 0x740168, 9.999999747378752e-05f);
    ref_write(memory.data(), 0x710638, std::uint16_t(0x3000));
    ref_write(memory.data(), 0x71063a, std::uint16_t(0x5000));
    ref_write(memory.data(), 0x241c80, 182.04444885253906f);
    ref_write(memory.data(), 0x241c88, 3.1415927410125732f);
    c::actors::EntityId ids[4];
    reo::native::gameplay_actors::EntityStore owner;
    for (auto& id : ids)
        id = owner.create(std::make_unique<reo::native::gameplay_actors::Entity>()).id;
    const std::array flat{triangle(0, 0, 20, 0x12340301)};
    auto raw = floor_bytes(flat);
    auto grid = r::Grid::import(raw);
    install(raw);
    for (unsigned yaw = 0; yaw < 65536; ++yaw)
        classify_compare({600, 30, 600}, std::uint16_t(yaw), grid);
    std::mt19937 random(0x637860);
    for (unsigned fixture = 0; fixture < 8; ++fixture) {
        const float slope = float(int(fixture) - 4) / 12;
        const std::array triangles{triangle(slope, 0.05f, 60, 0x12340301),
                                   triangle(-0.03f, slope, 25, 0x34560602)};
        raw = floor_bytes(triangles);
        grid = r::Grid::import(raw);
        install(raw);
        for (unsigned i = 0; i < 200; ++i) {
            std::array<Subject, 4> subjects;
            for (unsigned j = 0; j < 4; ++j) {
                auto& actor = subjects[j];
                actor.id = ids[j];
                actor.position = {float(200 + random() % 1100), float(int(random() % 300) - 100),
                                  float(200 + random() % 300)};
                actor.displacement = {2.5f, -3, 1.5f};
                actor.controls = random() % 2 ? 0x20 : 0;
                actor.subtype = std::array<std::uint8_t, 4>{1, 0x29, 0x2d, 9}[j];
                actor.auxiliary = std::array<std::uint32_t, 4>{0, 1, 0x100, 0x80000001u}[i % 4];
                for (auto& angle : actor.rotation)
                    angle = std::int16_t(random());
                actor.states = {std::int8_t(int(random() % 3) - 1),
                                std::int8_t(int(random() % 3) - 1),
                                std::int8_t(int(random() % 3) - 1)};
            }
            compare_pass(subjects, grid, i % 2);
        }
    }
    // The source leaves local probe XYZ uninitialized outside its result domain.
    // Qualify the deterministic refusal separately from original defined parity.
    unsigned unknown{};
    raw = floor_bytes(flat);
    grid = r::Grid::import(raw);
    install(raw);
    for (int state = -128; state <= 127; ++state)
        if (state < -1 || state > 1) {
            Subject actor;
            actor.position = {600, 40, 600};
            actor.auxiliary = 1;
            auto value = std::int8_t(state);
            check(g::probe(actor.view(), value, grid) == g::ProbeStatus::uninitialized_source_probe,
                  "unknown original probe refused");
            check(actor.height == 20 && actor.position.y == 20 && actor.surface == 1 &&
                      value == state,
                  "known preceding floor effects preserved before refusal");
            ++unknown;
        }
    std::array<Subject, 2> invalid;
    invalid[0].id = ids[0];
    invalid[1].id = ids[0];
    std::array entries{invalid[0].entry(), invalid[1].entry()};
    Walls walls(invalid);
    bool rejected{};
    try {
        (void)g::update(entries, grid, walls);
    } catch (const std::invalid_argument&) {
        rejected = true;
    }
    check(rejected && walls.calls.empty() && invalid[0].surface == 77,
          "duplicate identity refused before first write");
    entries[1].id = {};
    rejected = false;
    try {
        (void)g::update(entries, grid, walls);
    } catch (const std::invalid_argument&) {
        rejected = true;
    }
    check(rejected && walls.calls.empty(), "absent identity refused before first write");
    if (argc == 2) {
        std::ifstream list(argv[1]);
        std::string line;
        while (std::getline(list, line))
            if (!line.empty())
                stock(line.c_str());
    }
    std::printf("{\"checks\":%u,\"pass_cases\":%u,\"probe_cases\":%u,\"classifications\":%u,"
                "\"owned_floor_assets\":%u,\"stock_triangle_probes\":%u,\"separate_undefined_"
                "refusals\":%u,\"maximum_error\":%g,\"game_launched\":false}\n",
                checks, pass_cases, probe_cases, classified_cases, owned_assets, stock_probes,
                unknown, double(maximum_error));
}
