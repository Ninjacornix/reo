#include "packet_service.hpp"
#include "service_support.hpp"
unsigned service_cases{}, timer_cases{}, route_cases{}, refusal_cases{}, ordered_cases{};
struct PacketRoster final : d::PacketActors {
    Roster& roster;
    bool active{true}, present{true};
    explicit PacketRoster(Roster& r) : roster(r) {}
    std::optional<d::PacketOwner> owner(const a::EntityId& id) override {
        if (!present)
            return {};
        auto v = roster.find(id);
        if (!v)
            return {};
        return d::PacketOwner{*v, active};
    }
};
struct Shapes final : d::PacketShapes {
    std::vector<std::uint32_t>& trace;
    d::Status result{d::Status::completed};
    d::Packets* close{};
    std::function<void()> after;
    explicit Shapes(std::vector<std::uint32_t>& t) : trace(t) {}
    d::ShapeResult query(d::PacketState& p, d::PacketOwner) override {
        trace.insert(trace.end(), {std::uint32_t(p.definition->geometry.index()), p.delivery.key});
        p.delivery.event = packet_oracle::event;
        if (packet_oracle::contact)
            ++p.contacts;
        if (p.definition->geometry.index() == 2) {
            p.previous_valid = 1;
            p.previous = {1, 2, 3};
        }
        if (close)
            close->close();
        if (after) {
            auto callback = std::move(after);
            after = {};
            callback();
        }
        return {result, packet_oracle::contact,
                packet_oracle::route
                    ? std::optional<d::EdgeRoute>{{packet_oracle::route, packet_oracle::edge}}
                    : std::nullopt};
    }
};
struct Events final : d::PacketEvents {
    std::vector<std::uint32_t> trace;
    std::array<std::int16_t, 32> values;
    std::uint16_t room{}, mask{};
    c::hit_regions::Queue& queue;
    a::EntityId add;
    d::Status finish{d::Status::completed};
    explicit Events(c::hit_regions::Queue& q, a::EntityId id) : queue(q), add(id) {}
    bool audio_admitted(d::PacketOwner) override {
        trace.push_back(0x1ba520);
        return packet_oracle::audio;
    }
    void sound(d::PacketOwner, std::uint8_t cue) override {
        trace.insert(trace.end(), {0x1ba5e0, cue});
    }
    std::int32_t selected_authority(std::uint8_t selected) override {
        trace.insert(trace.end(), {0x1b0110, selected});
        return packet_oracle::authority;
    }
    std::optional<std::uint16_t> room_mask(std::uint16_t actual) override {
        check(actual == room, "canonical room used for route mask");
        return mask;
    }
    std::int16_t* pending(std::uint8_t edge) override {
        return edge < 32 ? &values[edge] : nullptr;
    }
    d::Status finish_routes() override {
        trace.insert(trace.end(), {0x680b40, std::uint32_t(queue.entries().size())});
        queue.add(add);
        return finish;
    }
};
void write_state(std::uint32_t at, const d::PacketState& p, const Roster& roster, unsigned type) {
    auto* m = storage().data();
    ref_write(m, at + 8, p.delivery.source ? address(roster.index(p.delivery.source)) : 0u);
    m[at + 0xc] = p.enabled;
    m[at + 0xd] = p.delivery.key;
    m[at + 0xe] = p.startup;
    m[at + 0xf] = p.lifetime;
    ref_write(m, at + 0x10, 0x32000u);
    ref_write(m, 0x32000, std::uint32_t(type));
    ref_write(m, at + 0x14, 0x30000u);
    m[at + 0x19] = p.mask;
    m[at + 0x1b] = p.delivery.event;
    m[at + 0x28] = p.contacts;
    m[at + 0x29] = p.cooldown;
    m[at + 0x2a] = p.delivery.bank;
    m[at + 0x2b] = p.previous_valid;
    ref_write(m, at + 0x2c,
              p.delivery.cached_related ? address(roster.index(p.delivery.cached_related)) : 0u);
    ref_write(m, at + 0x30, p.previous);
}
void one(Roster& roster, std::mt19937& rng, unsigned serial, unsigned timer = 99, unsigned byte = 0,
         unsigned mode = 0) {
    auto* m = storage().data();
    PS2Runtime runtime;
    auto init = context(0x5da040);
    o2_005DA040_0x5da040(m, &init, &runtime);
    auto allocate = context(0x5da0d0);
    allocate.g[4].lo = 1;
    o2_005DA0D0_0x5da0d0(m, &allocate, &runtime);
    const auto original = std::uint32_t(allocate.g[2].lo);
    std::array<std::byte, 32> raw;
    for (auto& b : raw)
        b = std::byte(rng());
    write_template(raw);
    const auto response = d::import_template(raw);
    auto& actor = roster.subjects[0];
    auto& related = roster.subjects[1];
    actor.actor = {};
    related.actor = {};
    actor.contact = {};
    related.contact = {};
    actor.actor.category = std::array<std::uint8_t, 4>{0, 2, 9, 6}[rng() % 4];
    actor.actor.slot = std::uint8_t(rng() % 4);
    related.actor.category = std::uint8_t((rng() % 2) ? 0 : 2);
    related.actor.slot = std::uint8_t(rng() % 4);
    actor.contact.authored_id = std::uint8_t(rng());
    related.contact.authored_id = std::uint8_t(rng());
    actor.contact.related = (rng() % 2) ? related.id : a::EntityId{};
    actor.actor.notice_flags =
        timer == 99 ? std::uint8_t((rng() % 10 == 0) ? 1 : (rng() % 7 == 0 ? 2 : 0)) : 0;
    actor.contact.priority = 19;
    actor.contact.serial = 9;
    actor.contact.recipient = {7, 8};
    roster.write();
    m[address(0)] = 1;
    m[address(1)] = 1;
    m[address(0) + 0x115] = actor.actor.notice_flags;
    d::Packets packets;
    const auto created = packets.create(true);
    auto lease = packets.acquire(created.id);
    auto& p = lease.state();
    auto def = std::make_shared<d::Definition>();
    def->response = response;
    const unsigned type = timer == 99 ? rng() % 6 : 1;
    switch (type) {
        case 1:
            def->geometry = d::SegmentShape{};
            break;
        case 2:
            def->geometry = d::SweepShape{};
            break;
        case 3:
            def->geometry = d::MarginShape{};
            break;
        case 4:
            def->geometry = d::AngularShape{};
            break;
        default:
            break;
    }
    p.definition = def;
    p.delivery = {actor.id,
                  (rng() % 2) ? related.id : a::EntityId{},
                  response,
                  std::uint8_t(rng() % 3),
                  std::uint8_t(serial),
                  std::uint8_t(rng() % 3)};
    p.enabled = timer == 99 ? std::uint8_t(rng() % 7 != 0) : 1;
    p.startup = 0;
    p.lifetime = 255;
    p.cooldown = 0;
    p.previous_valid = 91;
    p.contacts = std::uint8_t(rng());
    if (timer == 0)
        p.startup = std::uint8_t(byte);
    else if (timer == 1)
        p.lifetime = std::uint8_t(byte);
    else if (timer == 2)
        p.cooldown = std::uint8_t(byte);
    else {
        p.startup = (rng() % 4 == 0) ? std::uint8_t(rng()) : 0;
        p.lifetime = std::uint8_t(rng());
        p.cooldown = (rng() % 4 == 0) ? std::uint8_t(rng()) : 0;
    }
    p.previous = {11, 12, 13};
    p.mask = std::uint8_t(rng());
    write_state(original, p, roster, type);
    packet_oracle::event = std::uint8_t(rng() % 3);
    packet_oracle::contact = rng() % 2;
    packet_oracle::route = std::uint8_t(rng() % 3);
    packet_oracle::edge = std::uint8_t(rng() % 32);
    packet_oracle::audio = rng() % 2;
    packet_oracle::authority = std::array<std::int32_t, 3>{0, 1, -1}[rng() % 3];
    packet_oracle::trace.clear();
    a::HitSession session;
    session.clock_mode = std::uint8_t(timer == 99 ? rng() % 3 : mode);
    session.selected_actor = std::uint8_t(rng() % 4);
    session.room = std::uint16_t(rng() % 180);
    m[0x3243cc] = session.clock_mode;
    m[0x4baded] = session.selected_actor;
    ref_write(m, 0x3243dc, session.room);
    c::hit_regions::Queue targets;
    targets.add(actor.id);
    targets.add(related.id);
    ref_write(m, 0x3c25f8, std::uint16_t(targets.entries().size()));
    Events events(targets, roster.subjects[2].id);
    events.room = session.room;
    events.mask = std::uint16_t(rng());
    ref_write(m, 0x4b9a80 + 12u * session.room + 0x3a6, events.mask);
    for (unsigned i = 0; i < 32; ++i) {
        events.values[i] = std::bit_cast<std::int16_t>(std::uint16_t(rng()));
        ref_write(m, 0x4a35f0 + 2 * i, events.values[i]);
    }
    auto ctx = context(0x5da720);
    o2_005DA720_0x5da720(m, &ctx, &runtime);
    PacketRoster actors(roster);
    Shapes shapes(events.trace);
    const auto report = d::service(packets, actors, session, targets, shapes, events);
    check(report.status == d::ServiceStatus::completed, "full original-defined pass completes");
    if (events.trace != packet_oracle::trace) {
        std::fprintf(stderr,
                     "case serial=%u timer=%u byte=%u mode=%u cat=%u related=%u event=%u route=%u "
                     "contact=%u\n",
                     serial, timer, byte, mode, actor.actor.category,
                     unsigned(bool(p.delivery.cached_related)), packet_oracle::event,
                     packet_oracle::route, unsigned(packet_oracle::contact));
        for (auto n : events.trace)
            std::fprintf(stderr, "%x ", n);
        std::fprintf(stderr, "\noriginal ");
        for (auto n : packet_oracle::trace)
            std::fprintf(stderr, "%x ", n);
        std::fprintf(stderr, "\n");
    }
    check(events.trace == packet_oracle::trace,
          "shape/audio/authority/finalizer original call order");
    check(targets.entries().empty() && ref_read<std::uint16_t>(m, 0x3c25f8) == 0,
          "queue clears only after required route consumer");
    check(p.enabled == m[original + 0xc] && p.startup == m[original + 0xe] &&
              p.lifetime == m[original + 0xf] && p.cooldown == m[original + 0x29] &&
              p.previous_valid == m[original + 0x2b] && p.contacts == m[original + 0x28] &&
              p.delivery.event == m[original + 0x1b],
          "exact packet timer/counter/event byte states");
    check(bool(packets.acquire(created.id)) == (ref_read<std::uint32_t>(m, 0x3b54c8) != 0),
          "actual retirement matches lifetime/source/shape/contact limit");
    const auto old = ref_read<c::Vec3>(m, original + 0x30);
    check(p.previous.x == old.x && p.previous.y == old.y && p.previous.z == old.z,
          "sweep cache writes versus pause reset");
    for (unsigned i = 0; i < 32; ++i)
        check(events.values[i] == ref_read<std::int16_t>(m, 0x4a35f0 + 2 * i),
              "original signed pending route arithmetic");
    roster.equal();
    ++service_cases;
    if (timer != 99)
        ++timer_cases;
    if (report.contacts && packet_oracle::route)
        ++route_cases;
}
void ordered(Roster& roster, unsigned variant) {
    auto* m = storage().data();
    PS2Runtime runtime;
    auto init = context(0x5da040);
    o2_005DA040_0x5da040(m, &init, &runtime);
    roster.subjects[0].actor = {};
    roster.subjects[0].contact = {};
    roster.write();
    m[address(0)] = 1;
    std::array<std::byte, 32> raw{};
    raw[0xa] = std::byte(255);
    write_template(raw);
    auto response = d::import_template(raw);
    auto definition = std::make_shared<d::Definition>();
    definition->response = response;
    definition->geometry = d::SegmentShape{};
    auto make_state = [&](unsigned key) {
        d::PacketState p;
        p.enabled = 1;
        p.lifetime = 10;
        p.delivery = {roster.subjects[0].id, {}, response, 0, std::uint8_t(key), 0};
        p.definition = definition;
        if (key == 2 && variant % 2)
            p.lifetime = 0;
        return p;
    };
    auto original_add = [&](unsigned key, bool prepend) {
        auto ctx = context(0x5da0d0);
        ctx.g[4].lo = prepend;
        o2_005DA0D0_0x5da0d0(m, &ctx, &runtime);
        write_state(std::uint32_t(ctx.g[2].lo), make_state(key), roster, 1);
    };
    d::Packets packets;
    auto native_add = [&](unsigned key, bool prepend) {
        auto added = packets.create(prepend);
        auto packet = packets.acquire(added.id);
        packet.state() = make_state(key);
    };
    for (unsigned i = 0; i < 8; ++i) {
        original_add(i, (variant >> i) & 1);
        native_add(i, (variant >> i) & 1);
    }
    packet_oracle::event = 0;
    packet_oracle::contact = true;
    packet_oracle::route = 0;
    packet_oracle::audio = false;
    packet_oracle::trace.clear();
    packet_oracle::after_shape = [&](std::uint8_t*, PS2Runtime*) { original_add(42, true); };
    a::HitSession session;
    m[0x3243cc] = 0;
    ref_write(m, 0x3c25f8, std::uint16_t(0));
    auto ctx = context(0x5da720);
    o2_005DA720_0x5da720(m, &ctx, &runtime);
    PacketRoster actors(roster);
    c::hit_regions::Queue queue;
    Events events(queue, roster.subjects[1].id);
    Shapes shapes(events.trace);
    shapes.after = [&] { native_add(42, true); };
    const auto report = d::service(packets, actors, session, queue, shapes, events);
    check(report.status == d::ServiceStatus::completed && events.trace == packet_oracle::trace,
          "mixed reverse-list order including synchronous new head in same pass");
    check(report.queries == 9 - variant % 2 && packets.size() == 9 - variant % 2,
          "retiring predecessor preserves subsequent traversal");
    ++ordered_cases;
}
int main() {
    Roster roster;
    std::mt19937 rng(0x5da720);
    for (unsigned type = 0; type < 3; ++type)
        for (unsigned mode = 0; mode < 2; ++mode)
            for (unsigned byte = 0; byte < 256; ++byte)
                one(roster, rng, service_cases, type, byte, mode);
    for (unsigned i = 0; i < 16000; ++i)
        one(roster, rng, i);
    for (unsigned variant = 0; variant < 256; ++variant)
        ordered(roster, variant);
    // Native-only failure paths retain completed work and the unconsumed queue.
    for (unsigned failure = 0; failure < 3; ++failure) {
        d::Packets packets;
        auto created = packets.create(true);
        auto lease = packets.acquire(created.id);
        auto& p = lease.state();
        p.enabled = 1;
        p.lifetime = 8;
        p.startup = 0;
        p.delivery.source = roster.subjects[0].id;
        auto definition = std::make_shared<d::Definition>();
        definition->geometry = d::SegmentShape{};
        p.definition = definition;
        roster.subjects[0].actor.notice_flags = 0;
        PacketRoster actors(roster);
        c::hit_regions::Queue queue;
        queue.add(roster.subjects[0].id);
        Events events(queue, roster.subjects[1].id);
        Shapes shapes(events.trace);
        packet_oracle::event = 0;
        packet_oracle::contact = false;
        packet_oracle::route = 0;
        if (failure == 0)
            shapes.result = d::Status::unadmitted_content;
        if (failure == 1)
            shapes.close = &packets;
        if (failure == 2)
            events.finish = d::Status::unadmitted_content;
        a::HitSession session;
        const auto report = d::service(packets, actors, session, queue, shapes, events);
        check(report.status != (d::ServiceStatus::completed) && p.lifetime == 7 &&
                  !queue.entries().empty(),
              "failure retains prior tick and queue without legacy replay");
        ++refusal_cases;
    }
    std::printf("{\"checks\":%u,\"service_cases\":%u,\"timer_cases\":%u,\"route_cases\":%u,"
                "\"refusal_cases\":%u,\"ordered_cases\":%u,\"game_launched\":false}\n",
                checks, service_cases, timer_cases, route_cases, refusal_cases, ordered_cases);
}
