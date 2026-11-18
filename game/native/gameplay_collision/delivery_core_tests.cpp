#include "delivery.hpp"
#include "delivery_reference.hpp"
#include <cstdio>
#include <cstdlib>
#include <random>
namespace c = reo::native::gameplay_collision;
namespace d = c::delivery;
namespace a = reo::native::gameplay_actors;
namespace s = reo::native::gameplay_session;
unsigned checks{}, provenance_cases{}, value_cases{}, multiplier_cases{}, preparation_cases{};
void check(bool value, const char* why) {
    ++checks;
    if (!value) {
        std::fprintf(stderr, "delivery check %u failed: %s\n", checks, why);
        std::exit(1);
    }
}
std::vector<std::uint8_t>& storage() {
    static std::vector<std::uint8_t> data(0x800000);
    return data;
}
std::uint32_t address(unsigned i) {
    return 0x10000 + 0x2000 * i;
}
R5900Context context(std::uint32_t at) {
    R5900Context ctx;
    ctx.pc = at;
    ctx.g[29].lo = 0x7f0000;
    ctx.g[31].lo = 0x1234;
    return ctx;
}
struct Subject {
    a::EntityId id;
    a::HitActor actor;
    d::Component contact;
    c::Vec3 position;
    std::uint8_t character{}, cooldown{};
    d::View view() {
        return {id, actor, contact, character, position, cooldown};
    }
};
struct Roster : d::Actors {
    std::array<Subject, 4> subjects;
    a::EntityStore owner;
    Roster() {
        for (auto& subject : subjects)
            subject.id = owner.create(std::make_unique<a::Entity>()).id;
    }
    std::optional<d::View> find(const a::EntityId& id) override {
        for (auto& subject : subjects)
            if (subject.id == id)
                return subject.view();
        return {};
    }
    unsigned index(const a::EntityId& id) const {
        for (unsigned i = 0; i < subjects.size(); ++i)
            if (subjects[i].id == id)
                return i;
        return 99;
    }
    void write() {
        auto* m = storage().data();
        for (unsigned i = 0; i < subjects.size(); ++i) {
            const auto at = address(i);
            const auto& subject = subjects[i];
            const auto& v = subject.actor;
            const auto& t = subject.contact;
            std::fill(m + at, m + at + 0x2000, 0);
            m[at + 2] = v.category;
            m[at + 3] = v.slot;
            m[at + 6] = t.authored_id;
            m[at + 0xb98] = subject.character;
            m[at + 0x32] = subject.cooldown;
            ref_write(m, at + 0x38, subject.position);
            ref_write(m, at + 0xba0, v.status);
            ref_write(m, at + 0xba4, v.auxiliary_status);
            ref_write(m, at + 0x138, v.damage_word);
            ref_write(m, at + 0x14e, v.progression_amount);
            m[at + 0x13f] = v.pending_hit;
            m[at + 0x13d] = v.damage_kind;
            m[at + 0x140] = v.response_class;
            m[at + 0x143] = v.response_flags;
            m[at + 0x148] = v.source_kind;
            m[at + 0x149] = v.source_slot;
            m[at + 0x150] = v.special_kind;
            m[at + 0x116] = t.serial;
            m[at + 0x13c] = t.priority;
            m[at + 0x141] = t.response_code;
            m[at + 0x142] = t.template_kind;
            m[at + 0x14c] = t.auxiliary_a;
            m[at + 0x14d] = t.auxiliary_b;
            m[at + 0x13e] = t.region;
            ref_write(m, at + 0x117, t.recipient);
            ref_write(m, at + 0x119, t.related_recipient);
            ref_write(m, at + 0x14a, t.source_related);
            ref_write(m, at + 0x120, t.point);
            ref_write(m, at + 0x12c, t.direction);
            ref_write(m, at + 0xbb0, t.probability_bonus);
            ref_write(m, at + 0xbc4, t.damage_scale);
            ref_write(m, at + 0x28, t.related ? address(index(t.related)) : 0u);
            ref_write(m, at + 0x1d8, t.regions.present() ? 0x45000u : 0u);
        }
    }
    void equal() {
        const auto* m = storage().data();
        for (unsigned i = 0; i < subjects.size(); ++i) {
            const auto at = address(i);
            const auto& v = subjects[i].actor;
            const auto& t = subjects[i].contact;
            check(v.source_kind == m[at + 0x148] && v.source_slot == m[at + 0x149] &&
                      v.special_kind == m[at + 0x150],
                  "original receiver source provenance");
            check(t.recipient == ref_read<d::Identity>(m, at + 0x117) &&
                      t.related_recipient == ref_read<d::Identity>(m, at + 0x119) &&
                      t.source_related == ref_read<d::Identity>(m, at + 0x14a),
                  "original asymmetric related provenance identities");
            check(t.serial == m[at + 0x116] && t.priority == m[at + 0x13c] &&
                      t.response_code == m[at + 0x141] && v.response_flags == m[at + 0x143],
                  "original serial/response mutation");
            check(v.damage_word == ref_read<std::int32_t>(m, at + 0x138) &&
                      v.progression_amount == ref_read<std::uint16_t>(m, at + 0x14e) &&
                      v.pending_hit == m[at + 0x13f] && subjects[i].cooldown == m[at + 0x32],
                  "original canonical preparation fields");
        }
    }
};
void write_template(std::span<const std::byte> raw) {
    std::memcpy(storage().data() + 0x30000, raw.data(), raw.size());
    ref_write(storage().data(), 0x31014, 0x30000u);
}
void write_packet(const d::Packet& p, const Roster& roster) {
    auto* m = storage().data();
    ref_write(m, 0x31008, address(roster.index(p.source)));
    m[0x3102a] = p.bank;
    m[0x3101b] = p.event;
    m[0x3100d] = p.key;
}
struct Feedback : d::Feedback {
    std::int32_t result{};
    std::vector<std::uint32_t> trace;
    const Roster& roster;
    explicit Feedback(const Roster& r) : roster(r) {}
    bool authority(d::View actor) override {
        trace.push_back(0x1b0340);
        trace.push_back(address(roster.index(actor.id)));
        return result == 1;
    }
    void vibration(d::View, std::uint8_t pattern) override {
        trace.push_back(0x1ba9f0);
        trace.push_back(pattern);
    }
};
void tables_write(const d::Tables& tables) {
    auto* m = storage().data();
    for (unsigned i = 0; i < 128; ++i) {
        ref_write(m, 0x7346e0 + 2 * i, tables.weights[i]);
        for (unsigned j = 0; j < 3; ++j) {
            const auto entry = (*tables.flat)[i].bins[j];
            ref_write(m, 0x73bb00 + 12 * i + 4 * j, entry.amount);
            ref_write(m, 0x73bb02 + 12 * i + 4 * j, std::int16_t(entry.kind));
        }
    }
    for (unsigned category = 0; category < 8; ++category) {
        const auto& values = tables.categories[category];
        ref_write(m, 0x73b9e0 + 4 * category, values.entries ? 0x40000 + 0x1000 * category : 0u);
        if (values.entries)
            for (unsigned i = 0; i < 128; ++i)
                for (unsigned j = 0; j < 3; ++j) {
                    const auto v = (*values.entries)[i].bins[j];
                    ref_write(m, 0x40000 + 0x1000 * category + 12 * i + 4 * j, v.amount);
                    ref_write(m, 0x40002 + 0x1000 * category + 12 * i + 4 * j,
                              std::int16_t(v.kind));
                }
    }
    for (unsigned i = 0; i < 100; ++i)
        ref_write(m, 0x719a6c + 68 * i, tables.probabilities[i]);
}
int main() {
    static_assert(sizeof(d::Identity) == 2);
    Roster roster;
    auto* m = storage().data();
    PS2Runtime runtime;
    std::mt19937 random(0x578f60);
    auto tables = std::make_unique<d::Tables>();
    tables->flat.emplace();
    for (unsigned i = 0; i < 128; ++i) {
        tables->weights[i] = std::int16_t(random());
        for (auto& entry : (*tables->flat)[i].bins)
            entry = {std::int16_t(random()), std::uint8_t(random() % 5)};
    }
    for (unsigned category = 0; category < 8; ++category) {
        auto& values = tables->categories[category];
        values.admitted = true;
        if (category % 3)
            values.entries = *tables->flat;
    }
    for (unsigned i = 0; i < 100; ++i)
        tables->probabilities[i] = float(int(random() % 201) - 50) / 2;
    tables_write(*tables);
    for (unsigned iteration = 0; iteration < 16000; ++iteration) {
        for (unsigned i = 0; i < 4; ++i) {
            auto& a = roster.subjects[i];
            a.actor.category = std::uint8_t(random() % 5);
            a.actor.slot = std::uint8_t(random() % 8);
            a.character = std::uint8_t(random());
            a.contact.authored_id = std::uint8_t(random());
            a.contact.serial = std::uint8_t(random());
            a.contact.recipient = {std::uint8_t(random()), std::uint8_t(random())};
            a.contact.related_recipient = {std::uint8_t(random()), std::uint8_t(random())};
            a.contact.source_related = {std::uint8_t(random()), std::uint8_t(random())};
            a.actor.source_kind = std::uint8_t(random());
            a.actor.source_slot = std::uint8_t(random());
            a.actor.special_kind = std::uint8_t(random());
            a.contact.related = iteration % 7 ? roster.subjects[random() % 4].id : a::EntityId{};
        }
        d::Packet packet;
        packet.source = roster.subjects[random() % 4].id;
        packet.bank = std::uint8_t(random());
        packet.event = std::uint8_t(random());
        auto& receiver = roster.subjects[random() % 4];
        roster.write();
        write_packet(packet, roster);
        auto ctx = context(0x578f60);
        ctx.g[4].lo = address(roster.index(receiver.id));
        ctx.g[5].lo = 0x31000;
        o2_00578F60_0x578f60(m, &ctx, &runtime);
        check(d::record_provenance(receiver.view(), packet, roster) == d::Status::completed,
              "native provenance admitted");
        roster.equal();
        ctx = context(0x5790e0);
        ctx.g[4].lo = 0x31000;
        o2_005790E0_0x5790e0(m, &ctx, &runtime);
        check(d::restore_provenance(packet, roster) == d::Status::completed,
              "native provenance restore admitted");
        roster.equal();
        ++provenance_cases;
    }
    for (unsigned iteration = 0; iteration < 20000; ++iteration) {
        auto& first = roster.subjects[0];
        auto& second = roster.subjects[1];
        first.actor.slot = std::uint8_t(iteration % 8);
        second.actor.category = std::uint8_t(iteration % 3);
        second.character = std::uint8_t((iteration / 3) % 3);
        first.position = {float(int(random() % 2001) - 1000), float(int(random() % 2001) - 1000),
                          float(int(random() % 2001) - 1000)};
        second.position = {float(int(random() % 2001) - 1000), float(int(random() % 2001) - 1000),
                           float(int(random() % 2001) - 1000)};
        second.contact.damage_scale = float(int(random() % 601) - 100) / 100;
        if (iteration < 6) {
            first.position = {};
            second.position = {
                std::array<float, 6>{199.999f, 200, 200.001f, 599.999f, 600, 600.001f}[iteration],
                0, 0};
        }
        std::array<std::byte, 32> raw;
        for (auto& byte : raw)
            byte = std::byte(random());
        raw[0x13] = std::byte(iteration % 256);
        const auto t = d::import_template(raw);
        const float factor = iteration % 3 ? 1 : 2;
        roster.write();
        write_template(raw);
        for (bool flat : {false, true}) {
            auto ctx = context(flat ? 0x5a8a50 : 0x5a87a0);
            ctx.g[4].lo = address(0);
            ctx.g[5].lo = address(1);
            ctx.g[6].lo = 0x30000;
            ctx.g[7].lo = 0x32000;
            ctx.f[12] = factor;
            if (flat)
                o2_005A8A50_0x5a8a50(m, &ctx, &runtime);
            else
                o2_005A87A0_0x5a87a0(m, &ctx, &runtime);
            const auto got =
                flat ? d::flat_value(first.view(), second.view(), t, factor, *tables)
                     : d::category_value(first.view(), second.view(), t, factor, *tables);
            const auto amount = std::bit_cast<std::int16_t>(std::uint16_t(ctx.g[2].lo));
            if (got.value.amount != amount || got.value.kind != m[0x32000])
                std::fprintf(stderr, "value iter%u flat%u id%u native%d/%u original%d/%u\n",
                             iteration, unsigned(flat), unsigned(t.value_id), got.value.amount,
                             unsigned(got.value.kind), amount, unsigned(m[0x32000]));
            check(got.status == d::Status::completed && got.value.amount == amount &&
                      got.value.kind == m[0x32000],
                  "original integer weighting/special ID/scale/clamp/output kind");
            ++value_cases;
        }
    }
    for (unsigned iteration = 0; iteration < 12000; ++iteration) {
        auto& actor = roster.subjects[0];
        actor.actor.auxiliary_status = iteration % 5 ? 0 : 0x800;
        actor.contact.probability_bonus = float(int(random() % 301) - 150) / 2;
        actor.actor.response_flags = std::uint8_t(random());
        actor.actor.category = std::uint8_t(iteration % 5);
        actor.contact.response_code = std::uint8_t(iteration % 12);
        d::Packet packet;
        packet.key = std::uint8_t(iteration % 256);
        packet.response.probability = std::uint8_t(random());
        roster.write();
        std::array<std::byte, 32> raw{};
        raw[0x1a] = std::byte(packet.response.probability);
        write_template(raw);
        m[0x3100d] = packet.key;
        Feedback feedback(roster);
        feedback.result = std::array<std::int32_t, 3>{0, 1, -1}[iteration % 3];
        ref_write(m, 64, std::uint32_t(feedback.result));
        delivery_oracle::feedback.clear();
        s::Random generator;
        const s::RandomState seed{std::uint16_t(random()), std::uint16_t(random()),
                                  std::uint8_t(random())};
        generator.restore(seed);
        ref_write(m, 0x3244b0, seed.primary);
        ref_write(m, 0x3244b8, seed.secondary);
        m[0x3244ac] = seed.observed;
        auto ctx = context(0x6683e0);
        ctx.g[4].lo = address(0);
        ctx.g[5].lo = 0x31000;
        o2_006683E0_0x6683e0(m, &ctx, &runtime);
        check(d::multiplier(actor.view(), packet, *tables, generator, feedback) == ctx.f[0],
              "original probability/forced-status multiplier");
        check(generator.state().primary == ref_read<std::uint16_t>(m, 0x3244b0) &&
                  feedback.trace == delivery_oracle::feedback,
              "original RNG draw and authority/vibration order");
        ctx = context(0x578ea0);
        ctx.g[4].lo = address(0);
        ctx.g[5].lo = 0x31000;
        o2_00578EA0_0x578ea0(m, &ctx, &runtime);
        d::roll_response(actor.view(), packet.response, generator);
        ctx = context(0x578f10);
        ctx.g[4].lo = address(0);
        o2_00578F10_0x578f10(m, &ctx, &runtime);
        d::convert_response(actor.view());
        check(generator.state().primary == ref_read<std::uint16_t>(m, 0x3244b0),
              "stochastic response always draws once");
        roster.equal();
        ++multiplier_cases;
    }
    for (unsigned cooldown = 0; cooldown < 256; ++cooldown)
        for (bool present : {false, true})
            for (unsigned initial : {0u, 63u, 64u}) {
                auto& actor = roster.subjects[0];
                actor.cooldown = std::uint8_t(cooldown);
                actor.actor.damage_word = 881;
                actor.actor.progression_amount = 929;
                actor.actor.pending_hit = 247;
                actor.contact.priority = 191;
                actor.contact.serial = 255;
                actor.contact.regions.set(
                    present ? std::optional<std::vector<c::hit_regions::Definition>>{std::vector<
                                  c::hit_regions::Definition>{}}
                            : std::nullopt);
                c::hit_regions::Queue queue;
                for (unsigned i = 0; i < initial; ++i)
                    check(queue.add(actor.id), "native original-capacity queue fill");
                roster.write();
                ref_write(m, 0x3c25f8, std::uint16_t(initial));
                auto ctx = context(0x5dc3a0);
                ctx.g[4].lo = address(0);
                o2_005DC3A0_0x5dc3a0(m, &ctx, &runtime);
                d::prepare(actor.view(), queue);
                roster.equal();
                check(queue.entries().size() == ref_read<std::uint16_t>(m, 0x3c25f8),
                      "canonical cooldown/definition/queue admission");
                ++preparation_cases;
            }
    for (unsigned source = 0; source < 256; ++source)
        for (unsigned target = 0; target < 256; ++target) {
            auto& a = roster.subjects[0].actor;
            auto& b = roster.subjects[1].actor;
            a.category = std::uint8_t(source);
            b.category = std::uint8_t(target);
            roster.write();
            auto ctx = context(0x57b650);
            ctx.g[4].lo = address(0);
            ctx.g[5].lo = address(1);
            o2_0057B650_0x57b650(m, &ctx, &runtime);
            check(d::pair_kind(&a, b) == std::uint8_t(ctx.g[2].lo), "all original category pairs");
        }
    check(d::pair_kind(nullptr, roster.subjects[0].actor) == 99,
          "null resolved source selects default pair");
    d::Packet missing;
    check(d::record_provenance(roster.subjects[0].view(), missing, roster) ==
              d::Status::missing_actor,
          "unowned source refuses before provenance writes");
    auto& first = roster.subjects[0];
    auto& second = roster.subjects[1];
    first.actor.slot = 99;
    d::Template t;
    t.value_id = 3;
    check(d::category_value(first.view(), second.view(), t, 1, *tables).status ==
              d::Status::unadmitted_content,
          "unknown category table explicitly refuses");
    std::printf("{\"checks\":%u,\"provenance_cases\":%u,\"value_cases\":%u,\"multiplier_cases\":%u,"
                "\"preparation_cases\":%u,\"category_pairs\":65536,\"game_launched\":false}\n",
                checks, provenance_cases, value_cases, multiplier_cases, preparation_cases);
}
