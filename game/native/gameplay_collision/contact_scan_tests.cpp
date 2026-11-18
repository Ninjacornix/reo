#include "contact_scan.hpp"
#include "scan_support.hpp"
unsigned scans{}, known_deliveries{}, unknown_prefixes{}, last_scanned_differences{}, mark_calls{},
    repair_cases{};
struct Effects final : d::Effects {
    Roster& roster;
    std::int32_t authority_result{};
    bool mark_exempt{};
    std::vector<std::uint32_t> trace;
    std::vector<std::array<c::Vec3, 2>> marks;
    explicit Effects(Roster& r) : roster(r) {}
    bool authority(d::View actor) override {
        trace.push_back(0x1b0340);
        trace.push_back(address(roster.index(actor.id)));
        return authority_result == 1;
    }
    void vibration(d::View, std::uint8_t pattern) override {
        trace.push_back(0x1ba9f0);
        trace.push_back(pattern);
    }
    bool class_two_mark_exempt(d::View) override {
        return mark_exempt;
    }
    void surface_mark(c::Vec3 point, c::Vec3 direction) override {
        marks.push_back({point, direction});
    }
};
struct Obstacle final : c::spatial::Occlusion {
    mutable unsigned calls{};
    bool blocked(c::Vec3, c::Vec3) const override {
        ++calls;
        return contact_scan_oracle::obstructed;
    }
};
void vector_equal(c::Vec3 a, c::Vec3 b, const char* why) {
    const auto equal = [](float x, float y) { return x == y || (std::isnan(x) && std::isnan(y)); };
    if (!(equal(a.x, b.x) && equal(a.y, b.y) && equal(a.z, b.z)))
        std::fprintf(stderr, "%s native(%g,%g,%g) original(%g,%g,%g)\n", why, double(a.x),
                     double(a.y), double(a.z), double(b.x), double(b.y), double(b.z));
    check(equal(a.x, b.x) && equal(a.y, b.y) && equal(a.z, b.z), why);
}
void compare_scan(Roster& roster, d::Packet packet, std::array<std::byte, 32> raw, d::Query query,
                  d::Tables& tables, unsigned seed, bool partial) {
    const auto initial_subjects = roster.subjects;
    auto* m = storage().data();
    roster.write();
    write_template(raw);
    write_packet(packet, roster);
    m[0x31019] = query.mask;
    ref_write(m, 0x3102c,
              packet.cached_related ? address(roster.index(packet.cached_related)) : 0u);
    for (unsigned i = 0; i < 4; ++i) {
        auto& actor = roster.subjects[i];
        const auto regions = actor.contact.regions.spheres();
        ref_write(m, address(i) + 0x1d8, 0x50000 + 0x400 * i);
        ref_write(m, address(i) + 0x1dc, address(i) + 0xaec);
        m[address(i) + 0x1e0] = std::uint8_t(regions.size());
        ref_write(m, address(i) + 0xc94, seed % 3 ? 0u : 0x1000u);
        for (unsigned j = 0; j < regions.size(); ++j) {
            ref_write(m, 0x5000c + 0x400 * i + 20 * j, regions[j].radius);
            ref_write(m, address(i) + 0xaec + 12 * j, regions[j].center);
        }
        // Explicit test scratch for the source's one-past direction read. Only
        // known prefix effects are compared if the native path refuses it.
        ref_write(m, address(i) + 0xaec + 12 * unsigned(regions.size()),
                  c::Vec3{23.0f + float(seed % 11), 29.0f - float(seed % 7),
                          std::bit_cast<float>(address((seed + i) % 4))});
    }
    const std::array<unsigned, 5> order{1, 2, 3, 1, 0};
    const unsigned count = seed % 7 == 0 ? 5 : 3;
    std::vector<a::EntityId> recipients;
    for (unsigned i = 0; i < count; ++i) {
        recipients.push_back(roster.subjects[order[i]].id);
        ref_write(m, 0x3c2600 + 4 * i, address(order[i]));
    }
    ref_write(m, 0x3c25f8, std::uint16_t(count));
    const std::array<std::uint8_t, 4> masks{1, 4, 2, 8};
    for (unsigned i = 0; i < 4; ++i)
        m[0x708d70 + i] = masks[i];
    m[0x4bae96] = seed % 2 ? 2 : 0;
    m[0x4bae8a] = std::uint8_t(seed % 4);
    ref_write(m, 0x32000, query.start);
    ref_write(m, 0x32100, query.mode == d::Mode::angular ? query.direction : query.end);
    const c::Vec3 marker{701, 702, 703};
    ref_write(m, 0x32200, marker);
    Effects effects(roster);
    effects.authority_result = std::array<std::int32_t, 3>{-1, 0, 1}[seed % 3];
    effects.mark_exempt = seed % 3 == 0;
    ref_write(m, 64, std::uint32_t(effects.authority_result));
    delivery_oracle::feedback.clear();
    contact_scan_oracle::marks.clear();
    contact_scan_oracle::occlusion_calls = 0;
    contact_scan_oracle::obstructed = seed % 19 == 0;
    Obstacle obstacles;
    s::Random random;
    const s::RandomState initial{std::uint16_t(seed * 773), 19, 0};
    random.restore(initial);
    ref_write(m, 0x3244b0, initial.primary);
    ref_write(m, 0x3244b8, initial.secondary);
    const auto entry = query.mode == d::Mode::segment  ? 0x579fc0
                       : query.mode == d::Mode::margin ? 0x57ac60
                                                       : 0x57b6f0;
    auto ctx = context(entry);
    ctx.g[4].lo = 0x31000;
    ctx.g[5].lo = 0x32000;
    ctx.g[6].lo = 0x32100;
    ctx.g[7].lo = 0x32200;
    ctx.f[12] = query.mode == d::Mode::angular ? query.extents.second : query.margin;
    ctx.f[13] = query.extents.first;
    PS2Runtime runtime;
    if (query.mode == d::Mode::segment)
        o2_00579FC0_0x579fc0(m, &ctx, &runtime);
    else if (query.mode == d::Mode::margin)
        o2_0057AC60_0x57ac60(m, &ctx, &runtime);
    else
        o2_0057B6F0_0x57b6f0(m, &ctx, &runtime);
    d::Context environment{
        roster, tables, random, effects, masks, bool(seed % 2), std::uint8_t(seed % 4), &obstacles};
    std::optional<c::Vec3> output = marker;
    const auto result = d::scan(recipients, packet, query, environment, output);
    if (result.status != d::Status::completed &&
        result.status != d::Status::unknown_advanced_direction)
        std::fprintf(stderr, "scan seed%u mode%u status%u\n", seed, unsigned(query.mode),
                     unsigned(result.status));
    check(result.status == d::Status::completed ||
              (partial && result.status == d::Status::unknown_advanced_direction),
          "native scan completes or explicitly refuses only source unknown direction");
    if (result.region_hits != ctx.g[2].lo)
        std::fprintf(stderr, "seed%u mode%u regions %u/%llu\n", seed, unsigned(query.mode),
                     result.region_hits, (unsigned long long)ctx.g[2].lo);
    check(result.region_hits == ctx.g[2].lo, "original full scanner region-hit count");
    check(result.last_scanned == recipients.back(),
          "last scanned retains actual final recipient including filtered source");
    check(random.state().primary == ref_read<std::uint16_t>(m, 0x3244b0) &&
              effects.trace == delivery_oracle::feedback,
          "complete source RNG and feedback order");
    check(obstacles.calls == contact_scan_oracle::occlusion_calls,
          "occlusion provider order/count");
    if (result.status == d::Status::completed)
        roster.equal();
    else
        for (unsigned i = 0; i < 4; ++i) {
            const auto& subject = roster.subjects[i];
            const auto& actor = subject.actor;
            const auto& contact = subject.contact;
            const auto at = address(i);
            check(actor.source_kind == m[at + 0x148] && actor.source_slot == m[at + 0x149] &&
                      actor.special_kind == m[at + 0x150],
                  "original provenance prefix before unknown direction");
            check(contact.recipient == ref_read<d::Identity>(m, at + 0x117) &&
                      contact.related_recipient == ref_read<d::Identity>(m, at + 0x119) &&
                      contact.source_related == ref_read<d::Identity>(m, at + 0x14a) &&
                      contact.serial == m[at + 0x116],
                  "original identity/serial prefix before unknown direction");
            check(contact.priority == m[at + 0x13c] && actor.response_flags == m[at + 0x143] &&
                      actor.damage_word == ref_read<std::int32_t>(m, at + 0x138) &&
                      actor.progression_amount == ref_read<std::uint16_t>(m, at + 0x14e) &&
                      actor.pending_hit == m[at + 0x13f],
                  "original numeric and priority prefix before unknown direction");
            check(
                contact.response_code ==
                    (subject.id == result.selected ? packet.response.response_code : m[at + 0x141]),
                "known response-code store before original unknown read; no later conversion "
                "invented");
        }
    for (unsigned i = 0; i < 4; ++i) {
        const auto& actor = roster.subjects[i];
        const auto at = address(i);
        const auto& contact = actor.contact;
        check(actor.actor.damage_kind == m[at + 0x13d] &&
                  actor.actor.response_class == m[at + 0x140] &&
                  contact.template_kind == m[at + 0x142] && contact.auxiliary_a == m[at + 0x14c] &&
                  contact.auxiliary_b == m[at + 0x14d],
              "original prioritized response metadata");
        const bool unknown =
            result.status == d::Status::unknown_advanced_direction && result.selected == actor.id;
        if (!unknown) {
            check(contact.region == m[at + 0x13e], "original selected region index");
            vector_equal(contact.direction, ref_read<c::Vec3>(m, at + 0x12c),
                         "original normalized response direction");
        }
        vector_equal(contact.point, ref_read<c::Vec3>(m, at + 0x120),
                     "original point/vector before direction refusal");
        const auto native_address = [&](const a::EntityId& id) {
            return id ? address(roster.index(id)) : 0u;
        };
        check(native_address(contact.recorded_source) == ref_read<std::uint32_t>(m, at + 0x11c) &&
                  native_address(contact.recorded_related) ==
                      ref_read<std::uint32_t>(m, at + 0x144),
              "original variant-specific recorded native identities");
    }
    if (result.status == d::Status::unknown_advanced_direction)
        ++unknown_prefixes;
    else {
        ++known_deliveries;
        check(output.has_value(), "known caller output retained");
        vector_equal(*output, ref_read<c::Vec3>(m, 0x32200),
                     "source segment output only changes inside priority overwrite");
    }
    if (result.selected && result.selected != result.last_scanned)
        ++last_scanned_differences;
    check(effects.marks.size() == contact_scan_oracle::marks.size(),
          "source traced-mark effect count");
    for (unsigned i = 0; i < effects.marks.size(); ++i) {
        vector_equal(effects.marks[i][0], contact_scan_oracle::marks[i][0],
                     "read-only traced-mark point");
        vector_equal(effects.marks[i][1], contact_scan_oracle::marks[i][1],
                     "read-only traced-mark normalized direction");
        ++mark_calls;
    }
    if (partial) {
        // Candidate repair is separate from original parity: compare every
        // unaffected final field and use full191D80 for selected-center direction.
        roster.subjects = initial_subjects;
        random.restore(initial);
        effects.trace.clear();
        effects.marks.clear();
        obstacles.calls = 0;
        environment.direction_policy = d::DirectionPolicy::selected_region_repair;
        std::optional<c::Vec3> candidate_output = marker;
        const auto candidate = d::scan(recipients, packet, query, environment, candidate_output);
        check(candidate.status == d::Status::completed &&
                  candidate.region_hits == result.region_hits &&
                  candidate.selected == result.selected,
              "explicit selected-region candidate preserves selection and completes");
        check(random.state().primary == ref_read<std::uint16_t>(m, 0x3244b0) &&
                  effects.trace == delivery_oracle::feedback &&
                  obstacles.calls == contact_scan_oracle::occlusion_calls,
              "candidate preserves unaffected RNG/feedback/occlusion order");
        roster.equal();
        for (unsigned i = 0; i < 4; ++i) {
            const auto& subject = roster.subjects[i];
            const auto at = address(i);
            const auto& contact = subject.contact;
            check(subject.actor.damage_kind == m[at + 0x13d] &&
                      subject.actor.response_class == m[at + 0x140] &&
                      contact.template_kind == m[at + 0x142] &&
                      contact.auxiliary_a == m[at + 0x14c] &&
                      contact.auxiliary_b == m[at + 0x14d] && contact.region == m[at + 0x13e],
                  "candidate preserves all unaffected final response metadata");
            vector_equal(contact.point, ref_read<c::Vec3>(m, at + 0x120),
                         "candidate preserves original selected contact point");
            if (result.status == d::Status::unknown_advanced_direction &&
                subject.id == candidate.selected) {
                const auto center = subject.contact.regions.spheres()[contact.region].center;
                const c::Vec3 direction{query.start.x - center.x, query.start.y - center.y,
                                        query.start.z - center.z};
                ref_write(m, 0x33000, direction);
                auto normal = context(0x191d80);
                normal.g[4].lo = 0x33000;
                sub_00191D80_0x191d80(m, &normal, &runtime);
                vector_equal(
                    contact.direction, ref_read<c::Vec3>(m, 0x33000),
                    "candidate direction equals complete original191D80 on saved selected center");
            } else
                vector_equal(contact.direction, ref_read<c::Vec3>(m, at + 0x12c),
                             "unaffected candidate direction remains original");
            const auto native_address = [&](const a::EntityId& id) {
                return id ? address(roster.index(id)) : 0u;
            };
            check(native_address(contact.recorded_source) ==
                          ref_read<std::uint32_t>(m, at + 0x11c) &&
                      native_address(contact.recorded_related) ==
                          ref_read<std::uint32_t>(m, at + 0x144),
                  "candidate preserves recorded source identities");
        }
        ++repair_cases;
        if (seed >= 3000)
            check(candidate.selected == roster.subjects[1].id &&
                      roster.subjects[1].contact.region == 0,
                  "explicit equal-distance ties keep first actor and first region with zero "
                  "selected-center direction");
    }
    ++scans;
}
int main() {
    auto* m = storage().data();
    ref_write(m, 0x241c88, 3.1415927410125732f);
    ref_write(m, 0x241c90, -3.1415927410125732f);
    ref_write(m, 0x22fe30,
              std::array<float, 4>{0.000002601886990305502f, -0.00019807413627859205f,
                                   0.008333025500178337f, -0.16666656732559204f});
    auto tables = std::make_unique<d::Tables>();
    tables->flat.emplace();
    for (unsigned i = 0; i < 128; ++i) {
        tables->weights[i] = std::int16_t(i % 3 ? 100 : -91);
        for (unsigned j = 0; j < 3; ++j)
            (*tables->flat)[i].bins[j] = {std::int16_t(int(i) * 13 - int(j) * 17 - 341),
                                          std::uint8_t(j)};
    }
    for (unsigned category = 0; category < 8; ++category) {
        auto& values = tables->categories[category];
        values.admitted = true;
        if (category % 3)
            values.entries = *tables->flat;
    }
    for (unsigned i = 0; i < 100; ++i)
        tables->probabilities[i] = std::array<float, 4>{0, 7.5f, 100, -3}[i % 4];
    tables_write(*tables);
    for (std::int16_t row = -3; row <= 3; ++row) {
        d::RandomValues values;
        for (unsigned difficulty = 0; difficulty < 4; ++difficulty)
            for (unsigned roll = 0; roll < 8; ++roll) {
                values.damage[difficulty][roll] =
                    std::uint16_t(41 + row * 3 + difficulty * 7 + roll);
                values.progression[difficulty][roll] = std::uint16_t(3 + row + roll);
                ref_write(m, 0x72bea0 + 64 * row + 16 * difficulty + 2 * roll,
                          values.damage[difficulty][roll]);
                ref_write(m, 0x72d460 + 64 * row + 16 * difficulty + 2 * roll,
                          values.progression[difficulty][roll]);
            }
        tables->random.emplace(row, values);
    }
    Roster roster;
    std::mt19937 random(0x579fc0);
    for (unsigned seed = 0; seed < 2400; ++seed) {
        for (unsigned i = 0; i < 4; ++i) {
            auto& actor = roster.subjects[i];
            actor.actor = {};
            actor.contact = d::Component{};
            actor.cooldown = 0;
            actor.actor.category = std::uint8_t((seed / 4 + i) % 4);
            actor.actor.slot = std::uint8_t(i);
            actor.character = std::uint8_t(i % 2);
            actor.contact.authored_id = std::uint8_t(21 + i);
            actor.actor.status = seed % 3 ? 0 : 0x80;
            actor.contact.damage_scale = float((seed % 5) + 1) / 2;
            actor.actor.damage_word = int((seed + i) * 1771) % 140001 - 70000;
            actor.actor.progression_amount = std::uint16_t(65000 + seed + i);
            actor.actor.pending_hit = std::uint8_t(254 + i);
            actor.contact.priority = std::uint8_t(seed % 4);
            actor.contact.serial = std::uint8_t(254 + i);
            actor.position = {float(i * 20), float(int(seed % 13) - 6), float(i * 10)};
            std::vector<c::hit_regions::Definition> definitions;
            const auto region_count = std::array<unsigned, 4>{0, 1, 3, 4}[(seed / 7 + i) % 4];
            for (unsigned region = 0; region < region_count; ++region) {
                const auto center =
                    c::Vec3{float(int(random() % 61) - 30), float(int(random() % 21) - 10),
                            float(int(random() % 31) - 15)};
                definitions.push_back({center, float(random() % 17 + 1), 0});
            }
            if (i == 3 && seed % 2 == 0)
                for (auto& region : definitions)
                    region.offset = {300, 300, 300};
            actor.contact.regions.set(std::move(definitions));
            check(actor.contact.regions.refresh(c::hit_regions::Transform::actor_basis, {}, {}) ==
                      c::hit_regions::Status::complete,
                  "admitted native hit-region ownership");
        }
        auto& source = roster.subjects[0];
        source.actor.category = std::array<std::uint8_t, 5>{0, 2, 9, 4, 1}[seed % 5];
        source.contact.related = seed % 3 ? roster.subjects[3].id : a::EntityId{};
        roster.subjects[3].actor.category = std::uint8_t((seed / 5) % 3);
        std::array<std::byte, 32> raw{};
        const auto base = std::int16_t(int(seed % 7) - 3);
        std::memcpy(raw.data() + 2, &base, 2);
        raw[4] = std::byte(seed % 11);
        raw[6] = std::byte(seed % 5 + 1);
        raw[7] = std::byte(seed);
        raw[8] = std::byte(seed + 1);
        raw[0xd] = std::byte((seed / 3) % 3 ? 1 : 0);
        raw[0x11] = std::byte(seed % 4);
        raw[0x12] = std::byte(3);
        raw[0x13] = std::byte(seed % 256);
        raw[0x16] = std::byte(seed % 5 ? 0 : 0x20);
        raw[0x17] = std::byte(seed % 8);
        raw[0x18] = std::byte(seed % 17);
        raw[0x1a] = std::byte(seed % 121);
        d::Packet packet;
        packet.source = source.id;
        packet.cached_related = source.contact.related;
        packet.bank = std::uint8_t(seed % 3);
        packet.key = std::uint8_t(seed % 101);
        packet.response = d::import_template(raw);
        d::Query query;
        query.mode = d::Mode(seed % 3);
        query.start = {-40, 0, 0};
        query.end = seed % 11 ? c::Vec3{40, 0, 0} : query.start;
        query.direction = {1, 0, 0};
        query.margin = float(seed % 3 ? 0 : 5);
        query.extents = {float(seed % 4 + 1) * 10, float(seed % 7 + 1) * 10};
        query.mask = std::uint8_t(seed % 4 ? 255 : seed % 16);
        // Preserve the source domain of global margin/angular undefined reads.
        // Their priority-overwrite prefix is checked independently below.
        const bool partial = query.mode != d::Mode::segment && !(packet.response.flags & 1);
        compare_scan(roster, packet, raw, query, *tables, seed, partial);
    }
    for (unsigned mode = 1; mode <= 2; ++mode) {
        for (unsigned i = 0; i < 4; ++i) {
            auto& actor = roster.subjects[i];
            actor.actor = {};
            actor.contact = d::Component{};
            actor.character = std::uint8_t(i);
            actor.position = {};
            actor.contact.authored_id = std::uint8_t(i);
            std::vector<c::hit_regions::Definition> definitions;
            if (i == 1)
                definitions = {{{10, 0, 10}, 3, 0}, {{10, 0, 10}, 3, 0}};
            else if (i == 2)
                definitions = {{{10, 0, 10}, 3, 0}};
            actor.contact.regions.set(std::move(definitions));
            check(actor.contact.regions.refresh(c::hit_regions::Transform::actor_basis, {}, {}) ==
                      c::hit_regions::Status::complete,
                  "tie fixture pose admission");
        }
        roster.subjects[0].actor.category = 4;
        std::array<std::byte, 32> raw{};
        raw[2] = std::byte(5);
        raw[6] = std::byte(4);
        raw[0x12] = std::byte(3);
        raw[0x13] = std::byte(200);
        d::Packet packet;
        packet.source = roster.subjects[0].id;
        packet.response = d::import_template(raw);
        d::Query query;
        query.mode = d::Mode(mode);
        query.start = {10, 0, 10};
        query.end = query.start;
        query.direction = {1, 0, 0};
        query.extents = {10, 20};
        query.mask = 1;
        compare_scan(roster, packet, raw, query, *tables, 3000 + mode, true);
    }
    check(unknown_prefixes > 10 && mark_calls > 10 && last_scanned_differences > 100,
          "global unknown prefixes, mark effects and distinct clamp targets exercised");
    // Refusal cases are native ownership/admission checks, not comparisons
    // against source calls that would read an absent/unknown value.
    auto& source = roster.subjects[0];
    auto& target = roster.subjects[1];
    source.actor.category = 4;
    source.contact.related = {};
    target.actor = {};
    target.actor.category = 0;
    target.actor.damage_word = 0;
    target.contact = d::Component{};
    target.contact.priority = 9;
    target.contact.regions.set(std::vector<c::hit_regions::Definition>{{{0, 0, 0}, 3, 0}});
    check(target.contact.regions.refresh(c::hit_regions::Transform::actor_basis, {}, {}) ==
              c::hit_regions::Status::complete,
          "refusal fixture owns finite region");
    Effects effects(roster);
    Obstacle obstacle;
    s::Random generator;
    const std::array<std::uint8_t, 4> masks{1, 4, 2, 8};
    d::Context environment{roster, *tables, generator, effects, masks, false, 0, &obstacle};
    d::Packet packet;
    packet.source = source.id;
    packet.response.base = 2;
    packet.response.priority = 1;
    d::Query query;
    query.start = {-10, 0, 0};
    query.end = {10, 0, 0};
    query.margin = 1;
    query.mask = 1;
    const std::array recipient{target.id};
    std::optional<c::Vec3> uninitialized;
    auto refused = d::scan(recipient, packet, query, environment, uninitialized);
    check(refused.status == d::Status::uninitialized_output_point &&
              target.actor.pending_hit == 1 && target.actor.damage_word == 2 &&
              effects.marks.empty() && !uninitialized,
          "unknown caller point refuses mark after known numeric effects");
    uninitialized = c::Vec3{201, 202, 203};
    refused = d::scan(recipient, packet, query, environment, uninitialized);
    check(refused.status == d::Status::completed && effects.marks.size() == 1,
          "known caller point permits priority-rejected mark");
    packet.response.query_flags = 0x20;
    environment.obstacles = nullptr;
    const auto pending = target.actor.pending_hit;
    refused = d::scan(recipient, packet, query, environment, uninitialized);
    check(refused.status == d::Status::unadmitted_content && target.actor.pending_hit == pending,
          "required occlusion owner missing refuses before response writes");
    packet.response.query_flags = 0;
    std::array<a::EntityId, 65> too_many;
    too_many.fill(target.id);
    refused = d::scan(too_many, packet, query, environment, uninitialized);
    check(refused.status == d::Status::invalid_roster && target.actor.pending_hit == pending,
          "fixed enrollment capacity refuses before response writes");
    packet.source = {};
    refused = d::scan(recipient, packet, query, environment, uninitialized);
    check(refused.status == d::Status::missing_actor && target.actor.pending_hit == pending,
          "missing native source identity is explicit");
    std::printf(
        "{\"checks\":%u,\"scan_cases\":%u,\"known_complete_cases\":%u,\"separate_undefined_prefix_"
        "cases\":%u,\"last_scanned_differs\":%u,\"mark_effects\":%u,\"candidate_repair_cases\":%u,"
        "\"game_launched\":false}\n",
        checks, scans, known_deliveries, unknown_prefixes, last_scanned_differences, mark_calls,
        repair_cases);
}
