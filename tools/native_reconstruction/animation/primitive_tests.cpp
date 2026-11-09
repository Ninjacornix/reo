#include "game/native/gameplay_world/animation_primitives.hpp"
#include "reference.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#ifdef REO_WEAPON_PROGRAMS
#include "game/native/gameplay_world/resource_programs.hpp"
#include <set>
#endif
namespace g = reo::native::gameplay_world;
namespace e = g::animation_events;
namespace a = reo::native::animation;
namespace d = reo::native::gameplay_collision::delivery;
#include "functions.h"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#include "original.cpp"
#pragma GCC diagnostic pop
constexpr unsigned actor_at = 0x100000, packet_at = 0x280000;
std::uint64_t checks{}, cases{}, attachments{}, identities{}, equipment_cases{}, refusals{};
bool allocation_full{};
unsigned allocation_count{};
struct Sound {
    unsigned kind{}, cue{};
    friend bool operator==(const Sound&, const Sound&) = default;
};
std::vector<Sound> original_sounds;
std::string location;
void check(bool value, const char* why) {
    ++checks;
    if (!value)
        throw std::runtime_error(location + ": " + why);
}
R5900Context original_call(std::uint8_t* ram, unsigned address, unsigned actor, unsigned arg1 = 0,
                           unsigned arg2 = 0, unsigned arg3 = 0, float step = 0,
                           unsigned profile = 0);
void original_transform_port(std::uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    switch (ctx->pc) {
#include "original_dispatch.hpp"
        case 0x1b8d70:
            original_sounds.push_back({0, unsigned(std::uint8_t(GPR_U32(ctx, 5)))});
            // Declared child-effect observation seam: two canonical RNG requests occur
            // inside this unported surface implementation in this fixture only.
            (void)original_call(ram, 0x1aec80, 1);
            (void)original_call(ram, 0x1aec80, 1);
            break;
        case 0x1b8bb0:
            if (ram[actor_at + 2] == 0)
                original_sounds.push_back({1, GPR_U32(ctx, 5)});
            break;
        case 0x1b8b20:
            if (ram[actor_at + 2] == 1)
                original_sounds.push_back({2, GPR_U32(ctx, 5)});
            break;
        case 0x1b8c70:
            if (ram[actor_at + 2] < 2)
                original_sounds.push_back({3, GPR_U32(ctx, 5)});
            break;
        case 0x595f10:
            original_sounds.push_back({4, std::uint16_t(GPR_U32(ctx, 5))});
            break;
        case 0x1b8930:
            original_sounds.push_back({5, GPR_U32(ctx, 5)});
            break;
        case 0x5da0d0:
            ++allocation_count;
            SET_GPR_U32(ctx, 2, allocation_full ? 0 : packet_at);
            break;
#ifndef REO_WEAPON_PROGRAMS
        case 0x6b4420:
            check(ram[actor_at + 0xc7c] == 0,
                  "declared original resource-program no-resource seam only");
            break;
#endif
        default:
            throw std::runtime_error("undeclared reached original primitive provider " +
                                     std::to_string(ctx->pc));
    }
    ctx->pc = GPR_U32(ctx, 31);
}
R5900Context original_call(std::uint8_t* ram, unsigned address, unsigned actor, unsigned arg1,
                           unsigned arg2, unsigned arg3, float step, unsigned profile) {
    R5900Context ctx;
    PS2Runtime runtime;
    ctx.pc = address;
    SET_GPR_U32(&ctx, 4, actor);
    SET_GPR_U32(&ctx, 5, arg1);
    SET_GPR_U32(&ctx, 6, arg2);
    SET_GPR_U32(&ctx, 7, arg3);
    SET_GPR_U32(&ctx, 8, profile);
    SET_GPR_U32(&ctx, 29, 0x1f00000);
    SET_GPR_U32(&ctx, 31, 0xabcdef);
    ctx.f[12] = step;
    original_transform_port(ram, &ctx, &runtime);
    check(ctx.pc == 0xabcdef && GPR_U32(&ctx, 29) == 0x1f00000, "full original primitive return");
    return ctx;
}
struct Audio final : e::Audio {
    g::World& world;
    std::vector<Sound> sounds;
    explicit Audio(g::World& w) : world(w) {}
    void surface(g::Actor&, std::int8_t key) override {
        sounds.push_back({0, unsigned(std::bit_cast<std::uint8_t>(key))});
        (void)world.session().random.request(1);
        (void)world.session().random.request(1);
    }
    void actor(g::Actor&, std::uint32_t event, bool alternate) override {
        sounds.push_back({alternate ? 2u : 1u, event});
    }
    void resource(g::Actor&, std::uint16_t event) override {
        sounds.push_back({3, event});
    }
    void node(g::Actor&, std::uint16_t key) override {
        sounds.push_back({4, key});
    }
    void position(g::Actor&, std::uint32_t event) override {
        sounds.push_back({5, event});
    }
};
std::vector<std::byte> load(const char* name) {
    std::ifstream f(name, std::ios::binary | std::ios::ate);
    const auto size = f.tellg();
    check(size > 0 && size < 0x800000, "owned small asset bound");
    std::vector<std::byte> bytes(static_cast<std::size_t>(size));
    f.seekg(0);
    f.read(reinterpret_cast<char*>(bytes.data()), size);
    check(bool(f), "complete owned asset");
    return bytes;
}
#ifdef REO_WEAPON_PROGRAMS
#include "source/tools/native_reconstruction/animation/weapon_program_tests.inc"
#endif
int main(int argc, char** argv) try {
    check(argc == 4 || argc==5, "owned overlay/skeleton/catalog required");
    std::vector<std::uint8_t> ram(0x2000000);
    {
        std::ifstream f(argv[1], std::ios::binary);
        f.read(reinterpret_cast<char*>(ram.data() + 0x570000), 0x1d3100);
        check(bool(f), "complete owned overlay");
    }
    const auto corpus = load(argv[2]);
    std::uint32_t size{};
    std::memcpy(&size, corpus.data() + 4, 4);
    check(size < corpus.size() - 8, "owned first skeleton extent");
    const auto skeleton = a::Skeleton::import_raw(std::span(corpus).subspan(8, size));
    const auto catalog = d::Catalog::import(load(argv[3]));
    auto session = std::make_shared<g::Session>();
    g::World world({{g::input::Remap{1, 2, 4}}, 1, {16, UINT64_MAX}}, session);
    auto fresh = std::make_unique<g::Actor>();
    fresh->model = std::make_shared<a::Instance>(skeleton);
    fresh->animation = std::make_shared<a::Playback>(fresh->model);
    const auto created = world.spawn_primary(0, std::move(fresh));
    check(created.status == g::actors::EntityStatus::completed, "canonical actor creation");
    auto actor = world.resolve(created.id);
    Audio audio(world);
    d::Packets packets;
    e::File1Metadata metadata;
    reo::native::gameplay_scenario::SceneResources unused;
    e::NativeConsumer consumer(world, metadata, &audio, &packets, &catalog, &unused);
    const std::array<unsigned, 11> entries{0x595b70, 0x595c00, 0x595c90, 0x595d30,
                                           0x595dd0, 0x595e30, 0x595fa0, 0x596000,
                                           0x596060, 0x596180, 0x596470};
    const std::array<e::EventKind, 11> kinds{
        e::EventKind::surface_pair_one, e::EventKind::surface_pair_zero,
        e::EventKind::actor_audio,      e::EventKind::alternate_audio,
        e::EventKind::resource_audio,   e::EventKind::resource_callback,
        e::EventKind::node_audio,       e::EventKind::position_audio,
        e::EventKind::contact_action,   e::EventKind::model_action,
        e::EventKind::resource_program};
    for (unsigned operation = 0; operation < entries.size(); ++operation)
        for (unsigned variant = 0; variant < 4096; ++variant) {
            location =
                "operation=" + std::to_string(operation) + " variant=" + std::to_string(variant);
            while (packets.head())
                check(packets.release(packets.head()), "release preceding genuine packet");
            actor->category = std::uint8_t(variant % 3);
            actor->slot = std::uint8_t(variant % 8);
            world.selected_actor = std::uint8_t((variant >> 3) % 8);
            actor->selected_resource = 0;
            actor->resource_action = 0;
            actor->status = 0x100;
            actor->notice_flags = std::uint8_t(variant);
            actor->equipment_notice_flags = std::uint16_t(variant * 17);
            actor->equipment_notice_slot = 55;
            actor->equipment_slot = 77;
            actor->auxiliary_status = (variant & 4) ? 0x100003 : 3;
            const a::FrameRecord frame{float((variant >> 8) % 6), 10, 0,
                                       std::int8_t((variant >> 6) & 1), std::uint8_t(variant)};
            for (unsigned ch = 0; ch < 2; ++ch) {
                actor->animation->channel(a::ModelBank::primary, ch).timing = frame;
                const auto at = actor_at + 0x1e4 + 32 * ch;
                transform_write(ram.data(), at, frame.frame);
                transform_write(ram.data(), at + 4, frame.end);
                transform_write(ram.data(), at + 8, frame.restart);
                ram[at + 12] = std::bit_cast<std::uint8_t>(frame.loop);
                ram[at + 13] = frame.flags;
            }
            const float step = variant % 4 == 0   ? -.5f
                               : variant % 4 == 1 ? 0.f
                               : variant % 4 == 2 ? .125f
                                                  : 2.5f;
            world.session().clock_mode = std::uint8_t((variant >> 4) % 4);
            ram[0x3243cc] = world.session().clock_mode;
            const auto seed = std::uint16_t(variant * 131);
            session->random.restore({seed, 7, 9});
            transform_write(ram.data(), 0x3244b0, seed);
            transform_write(ram.data(), 0x3244b8, std::uint16_t(7));
            ram[actor_at + 2] = actor->category;
            ram[actor_at + 3] = actor->slot;
            ram[0x4baded] = world.selected_actor;
            ram[actor_at + 0xc7c] = actor->selected_resource;
            ram[actor_at + 0xc7f] = actor->equipment_slot;
            ram[actor_at + 0xda2] = actor->equipment_notice_slot;
            ram[actor_at + 0x115] = actor->notice_flags;
            transform_write(ram.data(), actor_at + 0xd92, actor->equipment_notice_flags);
            transform_write(ram.data(), actor_at + 0xba0, actor->status);
            transform_write(ram.data(), actor_at + 0xba4, actor->auxiliary_status);
            transform_write(ram.data(), actor_at + 0xca8, actor->resource_action);
            transform_write(ram.data(), actor_at + 0x34, std::uint32_t(0x200000));
            transform_write(ram.data(), actor_at + 0x28, std::uint32_t(0));
            e::Event event{kinds[operation], std::int32_t((variant >> 7) % 12), 0, 0, 0};
            if (operation < 2)
                event.argument = variant % 5;
            if (operation == 2 || operation == 3) {
                event.argument = (variant & 8) ? unsigned((variant % 1023) + 1) : 0;
                event.auxiliary = 0xfff0u + variant;
            }
            if (operation == 4)
                event.auxiliary = variant + 0xffff;
            if (operation == 6 || operation == 7)
                event.argument = variant + 0xffff;
            if (operation == 8) {
                event.argument = (variant & 8) ? 3 : 0;
                event.auxiliary = variant % catalog.size(0);
            }
            if (operation == 9)
                event.argument = (variant & 8) ? 1 : 7;
            if (operation == 10)
                event.argument = variant % 8;
            audio.sounds.clear();
            original_sounds.clear();
            allocation_count = 0;
            allocation_full = false;
            std::memset(ram.data() + packet_at, 0, 64);
            original_call(ram.data(), entries[operation], std::bit_cast<std::uint32_t>(event.frame),
                          actor_at, event.argument, event.auxiliary, step, event.profile);
            consumer.apply(*actor, event, step);
            check(audio.sounds == original_sounds,
                  "actual primitive child calls/order/narrowing with declared audio seams");
            check(session->random.state().primary ==
                      transform_read<std::uint16_t>(ram.data(), 0x3244b0),
                  "shared canonical RNG parity after child and parent requests");
            check(actor->status == transform_read<std::uint32_t>(ram.data(), actor_at + 0xba0) &&
                      actor->auxiliary_status ==
                          transform_read<std::uint32_t>(ram.data(), actor_at + 0xba4) &&
                      actor->notice_flags == ram[actor_at + 0x115],
                  "exact native notice/status effects");
            check(actor->equipment_slot == ram[actor_at + 0xc7f] &&
                      actor->equipment_notice_slot == ram[actor_at + 0xda2] &&
                      actor->equipment_notice_flags ==
                          transform_read<std::uint16_t>(ram.data(), actor_at + 0xd92),
                  "full native equipment notification parity");
            check(packets.size() == allocation_count, "actual stock packet allocation count");
            if (packets.size()) {
                const auto packet_lease = packets.acquire(packets.head());
                const auto& state = packet_lease.state();
                check(state.delivery.source == created.id && state.delivery.bank == 0 &&
                          state.delivery.key == ram[packet_at + 0xd],
                      "genuine canonical packet owner/bank/key");
                check(state.enabled == ram[packet_at + 0xc] &&
                          state.startup == ram[packet_at + 0xe] &&
                          state.lifetime == ram[packet_at + 0xf] &&
                          state.mask == ram[packet_at + 0x19] &&
                          state.attachment_flags == ram[packet_at + 0x1a],
                      "full actual attached packet controls");
                ++attachments;
            }
            ++cases;
        }
    // All raw category/slot pairs: source notify has no active/visible gate.
    for (unsigned category = 0; category < 256; ++category)
        for (unsigned slot = 0; slot < 256; ++slot) {
            actor->category = std::uint8_t(category);
            actor->slot = std::uint8_t(slot);
            actor->selected_resource = 91;
            actor->equipment_slot = 17;
            actor->equipment_notice_flags = 0xa53f;
            actor->equipment_notice_slot = 255;
            ram[actor_at + 2] = actor->category;
            ram[actor_at + 3] = actor->slot;
            ram[actor_at + 0xc7c] = 91;
            ram[actor_at + 0xc7f] = 17;
            ram[actor_at + 0xda2] = 255;
            transform_write(ram.data(), actor_at + 0xd92, std::uint16_t(0xa53f));
            ram[0x4baded] = 3;
            original_call(ram.data(), 0x65e710, actor_at);
            e::notify_equipment_selection(*actor, 3);
            check(actor->equipment_slot == ram[actor_at + 0xc7f] &&
                      actor->equipment_notice_slot == ram[actor_at + 0xda2] &&
                      actor->equipment_notice_flags ==
                          transform_read<std::uint16_t>(ram.data(), actor_at + 0xd92),
                  "full65E710 all category/slot patterns");
            ++equipment_cases;
        }
    g::actors::EntityStore store({1});
    auto item = store.create(std::make_unique<g::actors::Entity>());
    auto retained = store.acquire(item.id);
    g::actors::Entity foreign;
    check(store.identity_of(*retained) == item.id && !store.identity_of(foreign),
          "identity lookup actual versus foreign");
    check(store.retire(item.id) == g::actors::EntityStatus::completed &&
              !store.identity_of(*retained),
          "retired retained entity unregistered");
    auto replacement = store.create(std::make_unique<g::actors::Entity>());
    check(replacement.id != item.id &&
              store.identity_of(*store.acquire(replacement.id)) == replacement.id,
          "slot reuse gives fresh genuine identity");
    store.shutdown();
    check(!store.identity_of(*retained), "closed store rejects retained entity");
    identities += 4;
    auto linked = world.spawn_linked(std::make_unique<g::Actor>());
    auto linked_actor = world.resolve(linked.id);
    check(world.identity_of(*actor) == created.id && world.identity_of(*linked_actor) == linked.id,
          "World sole primary and linked identity domain");
    check(world.retire_linked(linked.id) == g::actors::EntityStatus::completed &&
              !world.identity_of(*linked_actor),
          "linked retirement invalidates reverse lookup");
    identities += 2;
    actor->category = 0;
    actor->selected_resource = 0;
    actor->animation->channel(a::ModelBank::primary, 1).timing = {0, 10, 0, 0, 0};
    e::NativeConsumer limited(world, metadata);
    bool failed{};
    try {
        limited.apply(*actor, {e::EventKind::actor_audio, 0, 0, 1, 0}, 1);
    } catch (const std::runtime_error&) {
        failed = true;
    }
    check(failed, "missing audio refuses reached event");
    ++refusals;
    failed = false;
    try {
        limited.apply(*linked_actor, {e::EventKind::contact_action, 0, 3, 0, 0}, 1);
    } catch (const std::runtime_error&) {
        failed = true;
    }
    check(failed, "retired actor refuses before effects");
    ++refusals;
    g::Actor foreign_actor;
    check(!world.identity_of(foreign_actor), "World rejects an unregistered foreign actor");
    failed = false;
    try {
        limited.apply(foreign_actor, {e::EventKind::contact_action, 0, 3, 0, 0}, 1);
    } catch (const std::runtime_error&) {
        failed = true;
    }
    check(failed && foreign_actor.notice_flags == 0, "foreign actor refuses before first notice");
    ++refusals;
    check(world.retire_primary(0) == g::actors::EntityStatus::completed &&
              !world.identity_of(*actor),
          "World retained primary loses its active identity on retirement");
    const auto next_primary = world.spawn_primary(0, std::make_unique<g::Actor>());
    check(next_primary.status == g::actors::EntityStatus::completed &&
              next_primary.id != created.id &&
              world.identity_of(*world.resolve(next_primary.id)) == next_primary.id &&
              !world.identity_of(*actor),
          "World primary replacement retains genuine fresh identity");
    identities += 3;
    check(world.close() == g::Status::completed && !world.identity_of(*actor),
          "closed World reverse identity unavailable");
    ++identities;
#ifdef REO_WEAPON_PROGRAMS
    check(argc==5,"owned WMD corpus required");compare_weapon_programs(ram,argv[4],skeleton);
    std::cout<<"{\"checks\":"<<checks<<",\"primitive_cases\":"<<cases<<",\"weapon_banks\":"<<weapon_banks<<",\"weapon_selector_cases\":"<<weapon_selector_cases<<",\"weapon_curves\":"<<weapon_curves<<",\"weapon_curve_cases\":"<<weapon_curve_cases<<",\"weapon_refusals\":"<<weapon_refusals<<",\"weapon_event_cases\":"<<weapon_event_cases<<",\"game_run\":false}\n";
#else
    std::cout << "{\"checks\":" << checks << ",\"primitive_cases\":" << cases
              << ",\"stock_contact_attachments\":" << attachments
              << ",\"equipment_cases\":" << equipment_cases << ",\"identity_cases\":" << identities
              << ",\"refusal_cases\":" << refusals << ",\"game_run\":false}\n";
#endif
} catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    return 1;
}
