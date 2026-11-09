#include "impact_shape_effects.hpp"
#include "shapes_support.hpp"
unsigned shape_cases{}, wall_contacts{}, floor_contacts{}, actor_contacts{}, routes{},
    upper_routes{}, debug_lines{};
float maximum_error{};
void vector_equal(c::Vec3 a, c::Vec3 b, const char* why) {
    for (const auto pair : {std::pair{a.x, b.x}, std::pair{a.y, b.y}, std::pair{a.z, b.z}}) {
        if (std::isnan(pair.first) && std::isnan(pair.second))
            continue;
        if (pair.first == pair.second)
            continue;
        const auto error = std::abs(pair.first - pair.second);
        maximum_error = std::max(maximum_error, error);
        if (!(error < 0.002f))
            std::fprintf(stderr, "%s native%g original%g\n", why, double(pair.first),
                         double(pair.second));
        check(error < 0.002f, why);
    }
}
std::vector<std::byte> encoded_grid(std::span<const c::response::Triangle> triangles) {
    std::vector<std::byte> bytes(128 + 56 * triangles.size());
    auto word = [&](unsigned at, std::uint32_t value) {
        std::memcpy(bytes.data() + at, &value, 4);
    };
    word(8, 10000);
    word(12, 10000);
    word(16, 1);
    word(20, 1);
    word(24, 0);
    word(28, 0);
    word(32, 32);
    word(36, 120);
    word(40, 40);
    for (unsigned i = 0; i < triangles.size(); ++i) {
        word(48 + 4 * i, 56 * i);
        std::memcpy(bytes.data() + 128 + 56 * i, &triangles[i], 56);
    }
    word(48 + 4 * unsigned(triangles.size()), 0xffffffffu);
    return bytes;
}
void load_grid(std::span<const std::byte> bytes, bool floor) {
    auto* m = storage().data();
    const auto base = floor ? 0x120000u : 0x100000u;
    std::memcpy(m + base, bytes.data(), bytes.size());
    auto ctx = context(floor ? 0x616310 : 0x6161e0);
    ctx.g[4].lo = base;
    PS2Runtime runtime;
    if (floor)
        o2_00616310_0x616310(m, &ctx, &runtime);
    else
        o2_006161E0_0x6161e0(m, &ctx, &runtime);
}
void basis_write(std::uint32_t at, const c::actors::Basis& basis) {
    auto* m = storage().data();
    ref_write(m, at, basis.x);
    ref_write(m, at + 16, basis.y);
    ref_write(m, at + 32, basis.z);
    ref_write(m, at + 48, basis.translation);
    ref_write(m, at + 60, 1.0f);
}
struct Poses final : d::PacketPoses {
    c::actors::Basis root;
    std::array<c::actors::Basis, 1> joints;
    c::Vec3 point{11, 12, 13}, normal{21, 22, 23};
    bool surface{};
    std::optional<d::ShapePose> pose(d::PacketOwner) override {
        return d::ShapePose{root, joints, point, normal, surface};
    }
};
struct Channels final : d::RouteChannels {
    std::array<d::RouteChannel, 16> states;
    std::optional<d::ChannelView> channel(std::uint8_t edge) override {
        if (edge >= 16)
            return {};
        return d::ChannelView{states[edge].gate, states[edge].active};
    }
};
struct Scene final : d::PacketScenes {
    const c::response::Grid& walls;
    const c::response::Grid& floors;
    Channels& channels;
    Scene(const c::response::Grid& w, const c::response::Grid& f, Channels& c)
        : walls(w), floors(f), channels(c) {}
    std::optional<d::ShapeScene> scene(d::PacketOwner) override {
        c::response::Filter filter;
        for (unsigned i = 0; i < 16; ++i)
            filter.slots[i].state = channels.states[i].gate;
        return d::ShapeScene{walls, floors, {}, filter, channels};
    }
};
struct ScanEffects final : d::Effects {
    bool authority(d::View) override {
        return false;
    }
    void vibration(d::View, std::uint8_t) override {
        check(false, "unexpected multiplier feedback");
    }
    bool class_two_mark_exempt(d::View) override {
        return false;
    }
    void surface_mark(c::Vec3, c::Vec3) override {
        check(false, "shape fixture disables scanner traced mark");
    }
};
struct Visuals final : d::ImpactVisuals {
    Roster& roster;
    std::vector<shape_oracle::Visual> calls;
    explicit Visuals(Roster& r) : roster(r) {}
    d::Status oriented(const reo::native::transform_math::Matrix& matrix, c::Vec3& point,
                       std::uint8_t key) override {
        calls.push_back({1, key, 0, matrix, point});
        point = {point.x + 2, point.y + 3, point.z + 5};
        return d::Status::completed;
    }
    d::Status surface(d::View owner,
                      const std::optional<reo::native::transform_math::Matrix>& basis,
                      c::Vec3& point, std::uint8_t key) override {
        check(!basis, "source event2 surface helper null basis");
        calls.push_back({2, key, address(roster.index(owner.id)), {}, point});
        point = {point.x + 2, point.y + 3, point.z + 5};
        return d::Status::completed;
    }
};
struct Debug final : d::ShapeDebug {
    std::vector<std::array<c::Vec3, 2>> lines;
    unsigned queries{};
    bool enabled() override {
        ++queries;
        return shape_oracle::debug;
    }
    d::Status line(c::Vec3 a, c::Vec3 b) override {
        lines.push_back({a, b});
        return d::Status::completed;
    }
};
void shape_write(unsigned type, c::Vec3 origin, c::Vec3 direction, std::uint16_t range,
                 std::uint16_t extent, std::optional<std::uint16_t> joint) {
    auto* m = storage().data();
    ref_write(m, 0x32000, std::uint32_t(type));
    ref_write(m, 0x32004, 0x33000u);
    ref_write(m, 0x33000, origin);
    if (type == 2) {
        ref_write(m, 0x3300c, extent);
        ref_write(m, 0x3300e, joint.value_or(65535));
    } else {
        ref_write(m, 0x3300c, direction);
        if (type == 1) {
            ref_write(m, 0x33018, range);
            ref_write(m, 0x3301a, joint.value_or(65535));
        } else {
            ref_write(m, 0x33018, extent);
            ref_write(m, 0x3301a, range);
            ref_write(m, 0x3301c, joint.value_or(65535));
        }
    }
}
void one(Roster& roster, unsigned n) {
    auto* m = storage().data();
    PS2Runtime runtime;
    const unsigned type = 1 + n % 4;
    c::response::Triangle wall{std::uint32_t(0x20000u | ((n % 16) << 24) | (n % 5 == 0 ? 14 : 1)),
                               {{{1500, -2000, 0}, {1500, 2000, 0}, {1500, 0, 4000}}},
                               {-1, 0, 0},
                               1500};
    c::response::Triangle ground{
        n % 2 ? 0x81u : 0u, {{{0, 0, 0}, {0, 0, 10000}, {10000, 0, 0}}}, {0, 1, 0}, 0};
    const auto wall_raw =
        encoded_grid(n % 7 == 0 ? std::span<const c::response::Triangle>{} : std::span(&wall, 1));
    const auto floor_raw =
        encoded_grid(n % 3 == 0 ? std::span<const c::response::Triangle>{} : std::span(&ground, 1));
    const auto walls = c::response::Grid::import(wall_raw),
               floors = c::response::Grid::import(floor_raw);
    load_grid(wall_raw, false);
    load_grid(floor_raw, true);
    ref_write(m, 0x743720, 0xffffffffu);
    ref_write(m, 0x3c2748, 0u);
    ref_write(m, 0x241c80, 182.04444885253906f);
    ref_write(m, 0x241c88, 3.1415927410125732f);
    ref_write(m, 0x73def0, 0.0010000000474974513f);
    for (auto& subject : roster.subjects) {
        subject.actor = {};
        subject.contact = {};
        subject.position = {};
        subject.contact.damage_scale = 1;
    }
    auto& source = roster.subjects[0];
    source.position = {1000, 100, 1000};
    if (type == 2)
        source.position.x = 2000;
    source.actor.category = n % 5 == 0 ? 9 : 0;
    source.actor.primary = n % 29 == 0 ? 3 : 1;
    if (n % 29 == 0 && type == 2)
        source.actor.category = 2;
    Poses poses;
    poses.joints[0].translation = {source.position.x + 17, 123, 1031};
    if (n % 11 == 0) {
        poses.root.x = {0, 0, -1};
        poses.root.z = {1, 0, 0};
    }
    const std::optional<std::uint16_t> joint =
        n % 3 == 0 ? std::optional<std::uint16_t>{0} : std::nullopt;
    c::Vec3 origin{float(n % 7), float(n % 3), float(n % 11)},
        direction{1, n % 3 == 0 ? -0.5f : 0, 0};
    if (n % 13 == 0)
        direction = {-2, -1, 0};
    const auto range = std::uint16_t(n % 17 == 0 ? 0 : 1000),
               extent = std::uint16_t(type == 2 ? 25 : 100);
    std::array<std::byte, 32> raw{};
    raw[2] = std::byte(23);
    raw[6] = std::byte(99);
    raw[0xd] = std::byte(1);
    raw[0x13] = std::byte(200);
    raw[0x16] = std::byte(n % 5 == 0 ? 8 : 0);
    if (n >= 2400)
        raw[0x16] |= std::byte(1);
    auto definition = std::make_shared<d::Definition>();
    definition->response = d::import_template(raw);
    if (type == 1)
        definition->geometry = d::SegmentShape{origin, direction, range, joint};
    else if (type == 2)
        definition->geometry = d::SweepShape{origin, extent, joint};
    else if (type == 3)
        definition->geometry = d::MarginShape{origin, direction, extent, range, joint};
    else
        definition->geometry = d::AngularShape{origin, direction, extent, range, joint};
    d::PacketState packet;
    packet.definition = definition;
    packet.delivery = {source.id,
                       n % 3 == 0 ? a::EntityId{} : roster.subjects[2].id,
                       definition->response,
                       0,
                       std::uint8_t(n % 100),
                       0};
    roster.subjects[2].actor.category = n % 7 == 0 ? 2 : 0;
    packet.mask = n % 9 == 0 ? 0 : 0xff;
    packet.previous_valid = (n / 4) % 2 ? 0 : 137;
    packet.previous = {1000, 100, 1000};
    packet.impact = {91, 92, 93};
    packet.contacts = std::uint8_t(n);
    auto& target = roster.subjects[1];
    target.position = {1400, 100, 1000};
    if (n >= 2400 && n % 10 == 0) {
        target.contact.priority = 200;
        target.contact.point = {7, 8, 9};
        target.contact.direction = {11, 12, 13};
    }
    if (n >= 2400) {
        target.contact.regions.set(
            std::vector<c::hit_regions::Definition>{{target.position, 100, 0}});
        check(target.contact.regions.refresh(c::hit_regions::Transform::actor_basis, {}, {}) ==
                  c::hit_regions::Status::complete,
              "admitted native target region");
    }
    roster.write();
    m[address(0) + 8] = source.actor.primary;
    basis_write(address(0) + 0x50, poses.root);
    ref_write(m, address(0) + 0x34, 0x180000u);
    ref_write(m, 0x180820, 0x181000u);
    basis_write(0x181000, poses.joints[0]);
    ref_write(m, address(0) + 0x154, poses.point);
    ref_write(m, address(0) + 0x160, poses.normal);
    m[address(0) + 0x188] = poses.surface;
    write_template(raw);
    write_packet(packet.delivery, roster);
    ref_write(m, 0x3102c, packet.delivery.cached_related ? address(2) : 0u);
    ref_write(m, 0x31010, 0x32000u);
    m[0x31019] = packet.mask;
    m[0x31028] = packet.contacts;
    m[0x3102b] = packet.previous_valid;
    ref_write(m, 0x31030, packet.previous);
    ref_write(m, 0x3101c, packet.impact);
    shape_write(type, origin, direction, range, extent, joint);
    Channels channels;
    for (unsigned edge = 0; edge < 16; ++edge) {
        channels.states[edge].gate = std::uint8_t((n + edge) % 3);
        m[0x4a3621 + 96 * edge] = channels.states[edge].gate;
    }
    const std::array<std::uint8_t, 4> masks{1, 4, 2, 8};
    for (unsigned i = 0; i < 4; ++i)
        m[0x708d70 + i] = masks[i];
    m[0x4bae96] = 0;
    m[0x4bae8a] = 0;
    ref_write(m, 0x3c25f8, std::uint16_t(n >= 2400));
    if (n >= 2400) {
        ref_write(m, 0x3c2600, address(1));
        ref_write(m, address(1) + 0x1d8, 0x50000u);
        ref_write(m, address(1) + 0x1dc, address(1) + 0xaecu);
        m[address(1) + 0x1e0] = 1;
        ref_write(m, 0x5000c, 100.0f);
        ref_write(m, address(1) + 0xaec, target.position);
    }
    ref_write(m, 0x719a6c + 68 * packet.delivery.key, 0.0f);
    shape_oracle::visuals.clear();
    shape_oracle::wall_queries.clear();
    shape_oracle::angular_queries.clear();
    shape_oracle::lines.clear();
    shape_oracle::debug_queries = 0;
    shape_oracle::debug = n % 3 == 0 && !(n >= 2400 && n % 10 == 0);
    const s::RandomState seed{std::uint16_t(n * 773), 19, 0};
    ref_write(m, 0x3244b0, seed.primary);
    ref_write(m, 0x3244b8, seed.secondary);
    const auto entry =
        std::array<std::uint32_t, 4>{0x5dad80, 0x5db320, 0x5db7d0, 0x5dbd30}[type - 1];
    auto ctx = context(entry);
    ctx.g[4].lo = 0x31000;
    ctx.g[5].lo = address(0);
    ctx.g[6].lo = 0x32000;
    ctx.g[7].lo = 0x34000;
    ctx.g[8].lo = 0x34004;
    ref_write(m, 0x34000, 0xdeadbeefu);
    ref_write(m, 0x34004, 0u);
    if (type == 1)
        o2_005DAD80_0x5dad80(m, &ctx, &runtime);
    else if (type == 2)
        o2_005DB320_0x5db320(m, &ctx, &runtime);
    else if (type == 3)
        o2_005DB7D0_0x5db7d0(m, &ctx, &runtime);
    else
        o2_005DBD30_0x5dbd30(m, &ctx, &runtime);
    d::Tables tables;
    ScanEffects feedback;
    s::Random random;
    random.restore(seed);
    c::hit_regions::Queue targets;
    if (n >= 2400)
        targets.add(target.id);
    d::Context environment{roster, tables, random, feedback, masks, false, 0, nullptr};
    Visuals visuals(roster);
    Debug debug;
    d::ImpactShapeEffects effects(roster, visuals, debug);
    Scene scene(walls, floors, channels);
    d::ShapePipeline pipeline(environment, targets, poses, scene, effects);
    const auto result = pipeline.query(packet, {source.view(), true});
    if (result.status != d::Status::completed)
        std::fprintf(stderr, "shape n%u type%u status%u\n", n, type, unsigned(result.status));
    check(result.status == d::Status::completed, "original-defined full shape pass completes");
    if (unsigned(result.contact) != ref_read<std::uint32_t>(m, 0x34004) ||
        unsigned(result.route ? result.route->kind : 0) != ctx.g[2].lo)
        std::fprintf(stderr, "n%u type%u contact%u/%u route%u/%llu event%u/%u\n", n, type,
                     unsigned(result.contact), ref_read<std::uint32_t>(m, 0x34004),
                     unsigned(result.route ? result.route->kind : 0),
                     (unsigned long long)ctx.g[2].lo, packet.delivery.event, m[0x3101b]);
    if (unsigned(result.contact) != ref_read<std::uint32_t>(m, 0x34004))
        for (const auto& q : shape_oracle::wall_queries) {
            const auto native = c::trace::shorten(walls, q.start, q.end, {});
            std::fprintf(stderr,
                         "wall original(%g,%g,%g)->(%g,%g,%g) masks%x/%x result%u nativeSame%u "
                         "table%x flags%x\n",
                         double(q.start.x), double(q.start.y), double(q.start.z), double(q.end.x),
                         double(q.end.y), double(q.end.z), q.include, q.exclude, q.result,
                         unsigned(bool(native.hit)), ref_read<std::uint32_t>(m, 0x3c2720),
                         ref_read<std::uint32_t>(m, 0x100080));
        }
    if (unsigned(result.contact) != ref_read<std::uint32_t>(m, 0x34004))
        for (const auto& q : shape_oracle::angular_queries) {
            const auto native = c::directed::contact({target.position, 100}, q.start, q.direction,
                                                     {q.first, q.second});
            std::fprintf(
                stderr,
                "angular(%g,%g,%g) dir(%g,%g,%g) extents%g/%g count%u result%u nativeSame%u\n",
                double(q.start.x), double(q.start.y), double(q.start.z), double(q.direction.x),
                double(q.direction.y), double(q.direction.z), double(q.first), double(q.second),
                q.count, q.result, unsigned(bool(native)));
        }
    if (unsigned(result.contact) != ref_read<std::uint32_t>(m, 0x34004))
        for (const auto& q : shape_oracle::angular_queries)
            std::fprintf(stderr, "target%x cat%u mask%x sphere(%g,%g,%g)r%g\n", q.actor, q.category,
                         q.mask, double(q.region.x), double(q.region.y), double(q.region.z),
                         double(q.radius));
    check(unsigned(result.contact) == ref_read<std::uint32_t>(m, 0x34004) &&
              unsigned(result.route ? result.route->kind : 0) == ctx.g[2].lo,
          "original shape contact and route outputs");
    if (result.route) {
        check(result.route->index == ref_read<std::uint32_t>(m, 0x34000),
              "original encoded route index");
        ++routes;
        if (result.route->index >= 24)
            ++upper_routes;
    }
    if (packet.delivery.event != m[0x3101b] || packet.contacts != m[0x31028] ||
        packet.previous_valid != m[0x3102b])
        std::fprintf(stderr, "n%u type%u event%u/%u contacts%u/%u cache%u/%u\n", n, type,
                     packet.delivery.event, m[0x3101b], packet.contacts, m[0x31028],
                     packet.previous_valid, m[0x3102b]);
    check(packet.delivery.event == m[0x3101b] && packet.contacts == m[0x31028] &&
              packet.previous_valid == m[0x3102b],
          "event/contact/cache byte mutation order");
    vector_equal(packet.impact, ref_read<c::Vec3>(m, 0x3101c), "original packet impact");
    vector_equal(packet.previous, ref_read<c::Vec3>(m, 0x31030), "original previous sweep center");
    vector_equal(poses.point, ref_read<c::Vec3>(m, address(0) + 0x154),
                 "canonical projectile point");
    vector_equal(poses.normal, ref_read<c::Vec3>(m, address(0) + 0x160),
                 "canonical projectile normal");
    check(poses.surface == bool(m[address(0) + 0x188]), "existing canonical surface valid flag");
    roster.equal();
    if (n >= 2400) {
        vector_equal(target.contact.point, ref_read<c::Vec3>(m, address(1) + 0x120),
                     "actual recipient contact point");
        vector_equal(target.contact.direction, ref_read<c::Vec3>(m, address(1) + 0x12c),
                     "actual recipient contact direction");
    }
    check(random.state().primary == ref_read<std::uint16_t>(m, 0x3244b0),
          "actual composed response RNG state");
    check(visuals.calls.size() == shape_oracle::visuals.size() &&
              debug.queries == shape_oracle::debug_queries &&
              debug.lines.size() == shape_oracle::lines.size(),
          "selected effect/debug service gates");
    for (unsigned i = 0; i < visuals.calls.size(); ++i) {
        const auto& a = visuals.calls[i];
        const auto& b = shape_oracle::visuals[i];
        check(a.kind == b.kind && a.key == b.key && a.actor == b.actor,
              "actual5DD580 child/owner/style dispatch");
        vector_equal(a.point, b.point, "actual5DD580 selected mutable/local point");
        if (a.kind == 1)
            for (unsigned column = 0; column < 4; ++column) {
                vector_equal({a.matrix[column][0], a.matrix[column][1], a.matrix[column][2]},
                             {b.matrix[column][0], b.matrix[column][1], b.matrix[column][2]},
                             "actual composed orientation");
                check(a.matrix[column][3] == b.matrix[column][3], "composed basis W");
            }
    }
    for (unsigned i = 0; i < debug.lines.size(); ++i) {
        vector_equal(debug.lines[i][0], shape_oracle::lines[i][0], "debug start");
        vector_equal(debug.lines[i][1], shape_oracle::lines[i][1], "debug end");
        ++debug_lines;
    }
    if (packet.delivery.event == 1)
        ++wall_contacts;
    if (packet.delivery.event == 2)
        ++floor_contacts;
    if (target.actor.pending_hit)
        ++actor_contacts;
    ++shape_cases;
}
int main() {
    Roster roster;
    auto* m = storage().data();
    ref_write(m, 0x241c90, -3.1415927410125732f);
    ref_write(m, 0x22fe30,
              std::array<float, 4>{0.000002601886990305502f, -0.00019807413627859205f,
                                   0.008333025500178337f, -0.16666656732559204f});
    for (unsigned n = 0; n < 4800; ++n)
        one(roster, n);
    std::printf("{\"checks\":%u,\"shape_cases\":%u,\"wall_contacts\":%u,\"floor_contacts\":%u,"
                "\"actor_contacts\":%u,\"routes\":%u,\"upper_routes\":%u,\"debug_lines\":%u,"
                "\"maximum_error\":%.9g,\"game_launched\":false}\n",
                checks, shape_cases, wall_contacts, floor_contacts, actor_contacts, routes,
                upper_routes, debug_lines, double(maximum_error));
}
