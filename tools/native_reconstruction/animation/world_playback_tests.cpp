#include "game/native/gameplay_world/animation.hpp"
#include <functional>
struct R5900Context;struct PS2Runtime;
void linked_actor_original_port(std::uint8_t*,R5900Context*,PS2Runtime*);
#define PLAYBACK_ACTOR_ADDRESS 0x4a5c30
#define main standalone_playback_main
#include "tools/native_reconstruction/animation/playback_tests.cpp"
#undef main
namespace g = reo::native::gameplay_world;
std::uint64_t lifetime_cases{}, special_frame_cases{}, selection_cases{}, dual_cases{},
    world_cases{}, resource_cases{}, prelude_native{}, world_refusals{}, profile_cases{};
std::vector<std::uint32_t> native_prelude_steps, original_prelude_steps;
g::Profile world_profile() {
    return {{g::input::Remap{0x100, 0x20, 0x10}}, 4, {16, UINT64_MAX}};
}
struct Prelude final : g::MotionPrelude {
    void run(g::World&, g::Actor& actor, float step) override {
        native_prelude_steps.push_back(bits(step));
        ++prelude_native;
        actor.animation->channel(a::ModelBank::primary, 1).skip_flags = 1;
        actor.animation->progress_threshold = 2;
        actor.input.held = 0xf3f;
    }
};
void original_prelude(std::uint8_t* memory, R5900Context* context) {
    original_prelude_steps.push_back(bits(context->f[12]));
    memory[actor + 0x21e] = 1;
    memory[actor + 0xce3] = 2;
    put(memory, actor + 0xf80, std::uint32_t(0xf3f));
}
void body_equal(const g::Actor& value, const std::vector<std::uint8_t>& ram) {
    const auto& collision = value.collision;
    check(collision.body_definition.has_value(),
          "real descriptor publishes canonical collision definition");
    const auto& body = *collision.body_definition;
    const auto at = get<std::uint32_t>(ram.data(), actor + 0x1a8);
    check(body.kind == (get<std::uint16_t>(ram.data(), at) == 0
                            ? reo::native::gameplay_collision::actors::ShapeKind::sphere
                            : reo::native::gameplay_collision::actors::ShapeKind::capsule) &&
              body.radius == float(get<std::int16_t>(ram.data(), at + 2)),
          "actual original body kind/radius metadata");
    const auto joint = [&](unsigned offset) {
        return ram[at + offset] == 255 ? std::optional<std::uint16_t>{}
                                       : std::optional<std::uint16_t>{ram[at + offset]};
    };
    check(body.first.first_joint == joint(4) && body.first.second_joint == joint(5) &&
              body.second.first_joint == joint(6) && body.second.second_joint == joint(7),
          "actual original body joint references");
    for (auto [v, offset] : {std::pair{body.first.first_offset, 8u},
                             {body.first.second_offset, 20u},
                             {body.second.first_offset, 32u},
                             {body.second.second_offset, 44u}})
        check(std::memcmp(&v, ram.data() + at + offset, 12) == 0,
              "original concrete joint-relative body offset");
    check(collision.interpolation_target.has_value(), "real local-shape target owned natively");
    const auto target = get<std::uint32_t>(ram.data(), actor + 0xcb8);
    check(std::memcmp(&collision.interpolation_target->center, ram.data() + target, 12) == 0 &&
              bits(collision.interpolation_target->radius) ==
                  get<std::uint32_t>(ram.data(), target + 12),
          "actual original local-shape target, not a body shadow");
    check(collision.interpolation_ticks == ram[actor + 0xcb2] &&
              std::memcmp(&collision.interpolation_step, ram.data() + actor + 0xcc8, 12) == 0,
          "actual complete local-shape interpolation preparation");
    check(std::memcmp(&collision.local_center, ram.data() + actor + 0x1ac, 12) == 0 &&
              bits(collision.radius) == get<std::uint32_t>(ram.data(), actor + 0x1b8),
          "source current center/radius preserved or snapped in exact branch");
    check(value.auxiliary_status == get<std::uint32_t>(ram.data(), actor + 0xba4),
          "source consume blend-reset flag ordering");
    check(value.animation->source_kind == ram[actor + 0xce0] &&
              value.animation->source_slot == ram[actor + 0xce1],
          "actual source family identity cache");
    check(std::bit_cast<std::uint16_t>(value.animation->motion) ==
              get<std::uint16_t>(ram.data(), actor + 0x520),
          "actual current-motion halfword ownership");
    check(value.class_marker == ram[actor + 0xb9b] &&
              value.previous_motion_class == ram[actor + 0xb9c],
          "actual current/previous motion classification");
    ++profile_cases;
}
#include "scripted_motion_tests.inc"
#include "linked_actor_update_tests.inc"
int main(int argc, char** argv) try {
    check(argc == 4, "owned World animation inputs required");
    const auto old = _mm_getcsr();
    struct Reset {
        unsigned old;
        ~Reset() {
            _mm_setcsr(old);
        }
    } reset{old};
    _mm_setcsr(0x1f80);
    std::vector<std::uint8_t> ram(0x2000000);
    owned_constants(ram.data());
    put(ram.data(), 0x294e00, t::identity());
    const auto skeletons = load(argv[2]), raw_banks = load(argv[3]);
    scripted_motion_tests(raw_banks,skeletons,ram);
    linked_expiry_tests(ram);
    linked_full_pool_tests(ram);
    std::shared_ptr<const a::Skeleton> skeleton;
    std::vector<std::byte> raw_skeleton;
    for (const auto& raw : skeletons) {
        auto candidate = a::Skeleton::import_raw(raw);
        if (candidate->nodes().size() == 36) {
            skeleton = candidate;
            raw_skeleton = raw;
        }
    }
    check(bool(skeleton), "actual player skeleton");
    auto bank = std::make_shared<a::MotionBank>();
    bank->load_sparse(raw_banks[0], 8, 0, "pc000");
    bank->load_sparse(raw_banks[1], 8, 1, "pc001");
    a::File1MotionDescriptors catalog;
    g::File1MotionProfiles profiles;
    Prelude prelude;
    for (unsigned variant = 0; variant < 64; ++variant) {
        location = "World variant=" + std::to_string(variant);
        std::fill_n(ram.data() + nodes, skeleton->nodes().size() * 400, 0);
        std::fill_n(ram.data() + second, skeleton->nodes().size() * 400, 0);
        std::fill_n(ram.data() + actor, 0x10e0 * 3, 0);
        std::fill_n(ram.data() + work, 0x1468, 0);
        std::fill_n(ram.data() + bank_at, 0x10000, 0);
        std::memcpy(ram.data() + 0x400000, raw_skeleton.data(), raw_skeleton.size());
        call(ram.data(), 0x1a2e00, 0x10000, skeleton_resource, 0x400000);
        call(ram.data(), 0x193380, nodes, 1);
        call(ram.data(), 0x193380, second, 1);
        put(ram.data(), actor + 0x34, work);
        put(ram.data(), actor + 0x524, std::uint8_t(5));
        put(ram.data(), work, work + 0x820);
        put(ram.data(), work + 4, work + 0xa20);
        put(ram.data(), work + 0x816, std::uint16_t(skeleton->nodes().size()));
        for (unsigned i = 0; i < skeleton->nodes().size(); ++i) {
            put(ram.data(), work + 0x820 + 4 * i, nodes + 400 * i);
            put(ram.data(), work + 0xa20 + 4 * i, second + 400 * i);
        }
        g::World world(world_profile(), std::make_shared<g::Session>());
        auto native = std::make_unique<g::Actor>();
        native->active = true;
        native->category = std::uint8_t(variant % 2);
        native->character = std::uint8_t(variant % 8);
        native->motion_subtype = std::uint8_t((variant / 2) % 8);
        native->motion_style = std::uint8_t(variant % 3);
        native->motion_rate = .75f;
        native->class_marker = std::uint8_t(variant % 4);
        native->auxiliary_status = variant % 3 == 0 ? 2 : 0;
        native->root_motion_delta = {3, 4, 5};
        native->collision.local_center = {1, 2, 3};
        native->collision.radius = 37;
        native->model = std::make_shared<a::Instance>(skeleton);
        native->animation = std::make_shared<a::Playback>(native->model);
        native->animation->resources_known = true;
        native->animation->progress_flags = std::uint8_t(variant % 4 == 0 ? 0x20 : 0);
        native->animation->progress_threshold = 7;
        const auto resource0 = std::make_shared<a::MotionBank>(*bank),
                   resource1 = std::make_shared<a::MotionBank>(*bank),
                   resource2 = std::make_shared<a::MotionBank>(*bank);
        native->animation->resources = {resource0, resource1, resource2};
        check(world.spawn_primary(0, std::move(native)).status ==
                  g::actors::EntityStatus::completed,
              "canonical Actor animation admission");
        const auto id = world.identity(0);
        const auto current = world.primary(0);
        auto& player = *current->animation;
        world.session().clock_mode = std::uint8_t(variant % 2);
        world.selected_actor = 0;
        a::MotionIdentity identity{current->status,    current->resource_action,
                                   current->category,  current->motion_subtype,
                                   current->character, current->class_marker};
        std::vector<unsigned> candidates;
        for (unsigned index = 0; index < 568; ++index) {
            try {
                const auto decoded = catalog.unpack(identity, catalog.at(index));
                if (decoded.family >= 6)
                    continue;
                bool okay = true;
                for (unsigned track = 0; track < 5; ++track) {
                    const auto key = track == 0 ? decoded.channel_zero : decoded.channel_one;
                    if (key >= 2000)
                        continue;
                    const auto block = bank->find(key, std::uint16_t(track));
                    if (!block) {
                        if (track < 2)
                            okay = false;
                        continue;
                    }
                    unsigned count{};
                    for (const auto& d : skeleton->nodes())
                        count += d.track == track;
                    if (block->clip()->tracks().size() != count)
                        okay = false;
                }
                if (okay)
                    candidates.push_back(index);
            } catch (const std::exception&) {
            }
        }
        check(!candidates.empty(), "actual descriptor with compatible consumed real motion rows");
        const auto& descriptor = catalog.at(candidates[variant % candidates.size()]);
        const auto decoded = catalog.unpack(identity, descriptor);
        resources.resize(2);
        std::vector<std::shared_ptr<const a::MotionBlock>> blocks;
        std::optional<std::uint8_t> special_marker;
        std::vector<unsigned> special_keys;
        for (unsigned marker = 0; marker < 2 && !special_marker; ++marker) {
            auto special = identity;
            special.character = 5;
            special.class_marker = std::uint8_t(marker);
            special.resource_action = 11;
            special.status = 0;
            const auto d = catalog.unpack(special, catalog.resolve(special, 0x2003));
            bool okay = d.family < 6;
            for (unsigned track = 0; track < 5; ++track) {
                const auto key = track ? d.channel_one : d.channel_zero;
                if (key >= 2000) {
                    okay = false;
                    break;
                }
                const auto block = bank->find(key, std::uint16_t(track));
                if (!block) {
                    if (track < 2)
                        okay = false;
                    continue;
                }
                try {
                    unsigned count{};
                    for (const auto& n : skeleton->nodes())
                        count += n.track == track;
                    if (block->clip()->tracks().size() != count)
                        okay = false;
                } catch (const std::exception&) {
                    okay = false;
                }
            }
            if (okay) {
                special_marker = std::uint8_t(marker);
                special_keys = {d.channel_one, d.channel_zero};
            }
        }

        for (unsigned key : {unsigned(decoded.channel_zero), unsigned(decoded.channel_one)})
            if (key < 2000)
                for (unsigned track = 0; track < 5; ++track) {
                    auto block = bank->find(key, std::uint16_t(track));
                    if (block && std::find(blocks.begin(), blocks.end(), block) == blocks.end())
                        blocks.push_back(block);
                }
        for (unsigned key : special_keys)
            for (unsigned track = 0; track < 5; ++track) {
                auto block = bank->find(key, std::uint16_t(track));
                if (block && std::find(blocks.begin(), blocks.end(), block) == blocks.end())
                    blocks.push_back(block);
            }
        check(blocks.size() <= 15, "bounded real descriptor source packing");
        for (unsigned b = 0; b < 3; ++b) {
            const auto table = bank_at + b * 0x4000;
            ram[table] = bank->first_track();
            ram[table + 1] = bank->track_count();
            ram[table + 2] = std::uint8_t(bank->kind());
            for (unsigned i = 0; i < 2000; ++i)
                put(ram.data(), table + 0xfa4 + 2 * i, bank->rows()[i]);
            put(ram.data(), actor + 0x514 + 4 * b, table);
        }
        for (const auto& block : blocks) {
            const auto token = unsigned(resources.size()),
                       packed = 0x900000 + 0x80000 * (token - 2);
            resources.push_back(packed);
            check(block->bytes().size() < 0x40000, "owned descriptor Clip packed extent");
            std::memcpy(ram.data() + 0x500000, block->bytes().data(), block->bytes().size());
            call(ram.data(), 0x1a1fd0, 0x18000, packed, 0x500000);
            for (unsigned i = 0; i < 2000; ++i)
                if (bank->slots()[i] == block)
                    for (unsigned b = 0; b < 3; ++b)
                        put(ram.data(), bank_at + b * 0x4000 + 4 + 2 * i, std::uint16_t(token));
        }
        put(ram.data(), actor + 2, current->category);
        put(ram.data(), actor + 4, current->motion_subtype);
        put(ram.data(), actor + 0xb98, current->character);
        put(ram.data(), actor + 0xb99, current->motion_style);
        put(ram.data(), actor + 0xb9b, current->class_marker);
        put(ram.data(), actor + 0xba0, current->status);
        put(ram.data(), actor + 0xba4, current->auxiliary_status);
        put(ram.data(), actor + 0xba8, current->motion_rate);
        put(ram.data(), actor + 0x4e4, a::Vector{3, 4, 5});
        put(ram.data(), actor + 0x1ac, current->collision.local_center);
        put(ram.data(), actor + 0x1b8, current->collision.radius);
        ram[actor + 0xce2] = player.progress_flags;
        ram[actor + 0xce3] = player.progress_threshold;
        put(ram.data(), 0x3243cc, world.session().clock_mode);
        for (unsigned track = 0; track < 5; ++track) {
            player.channel(a::ModelBank::primary, track).timing.flags = std::uint8_t(variant * 17);
            export_channel(ram.data(), 0, track, player.channel(a::ModelBank::primary, track));
        }
        g::MotionRelations relations(world);
        check(relations.bind(id, {std::nullopt, std::nullopt, std::nullopt}),
              "confirmed native absent relation set");
        g::WorldMotionResources resources_owner(world, &relations);
        g::WorldAnimation animations(world, resources_owner, profiles, prelude);
        const float start = float(variant % 5) * .5f, blend = variant % 4 == 0   ? 0
                                                              : variant % 4 == 1 ? -6.f
                                                                                 : 10.f;
        std::memcpy(ram.data() + 0x230000, descriptor.bytes.data(), 8);
        if (variant % 2) {
            animations.apply_named(id, descriptor, start, blend);
            call(ram.data(), 0x5d50e0, actor, 0x230000, 0, 0, start, blend);
        } else {
            animations.apply(id, descriptor, start, blend);
            call(ram.data(), 0x5d50f0, actor, 0x230000, 0, 0, start, blend);
        }
        records(player, ram,
                {current->root_motion_delta.x, current->root_motion_delta.y,
                 current->root_motion_delta.z});
        body_equal(*current, ram);
        ++world_cases;
        player.activate(5);
        call(ram.data(), 0x58c7b0, actor);
        prelude_hook = original_prelude;
        const float original_step = std::array<float, 4>{-1.f, .125f, -0.f, 2.5f}[variant % 4];
        const auto boundary = animations.tick(id, original_step);
        const auto original = call(ram.data(), 0x58c300, actor, 0, 0, 0, original_step);
        prelude_hook = nullptr;
        check(boundary == std::int8_t(GPR_U32(&original, 2)),
              "actual required prelude effects precede ordered native channel service");
        records(player, ram,
                {current->root_motion_delta.x, current->root_motion_delta.y,
                 current->root_motion_delta.z});
        body_equal(*current, ram);
        std::optional<unsigned> matching_code;
        for (unsigned family : {1u, 2u, 3u}) {
            for (unsigned key = 0; key < 100; ++key) {
                try {
                    if (catalog.resolve(identity, (family << 12) | key) == descriptor) {
                        matching_code = (family << 12) | key;
                        break;
                    }
                } catch (const std::exception&) {
                }
            }
            if (matching_code)
                break;
        }
        if (matching_code) {
            animations.select(id, *matching_code, start, blend);
            call(ram.data(), 0x5d4cf0, actor, *matching_code, 0, 0, start, blend);
            records(player, ram,
                    {current->root_motion_delta.x, current->root_motion_delta.y,
                     current->root_motion_delta.z});
            body_equal(*current, ram);
            ++selection_cases;
            std::memcpy(ram.data() + 0x230010, descriptor.bytes.data(), 8);
            animations.apply_blended(id, descriptor, descriptor, .375f);
            call(ram.data(), 0x5d56d0, actor, 0x230000, 0x230010, 0, .375f);
            records(player, ram,
                    {current->root_motion_delta.x, current->root_motion_delta.y,
                     current->root_motion_delta.z});
            body_equal(*current, ram);
            ++dual_cases;
            prelude_hook = original_prelude;
            const float original_dual_step =
                std::array<float, 4>{0.f, -.5f, .25f, 2.f}[variant % 4];
            const auto r = animations.tick_blended(id, original_dual_step, .375f);
            const auto o = call(ram.data(), 0x5d57d0, actor, 0, 0, 0, original_dual_step, .375f);
            prelude_hook = nullptr;
            check(r == std::int8_t(GPR_U32(&o, 2)),
                  "actual World four-bank service follows required observed prelude");
            records(player, ram,
                    {current->root_motion_delta.x, current->root_motion_delta.y,
                     current->root_motion_delta.z});
            animations.select_blended(id, *matching_code, *matching_code, .625f);
            call(ram.data(), 0x5d5580, actor, *matching_code, *matching_code, 0, .625f);
            records(player, ram,
                    {current->root_motion_delta.x, current->root_motion_delta.y,
                     current->root_motion_delta.z});
            body_equal(*current, ram);
            ++dual_cases;
        }
        // Known unloaded banks retain the source's earlier metadata/flag effects.
        player.resources = {};
        for (unsigned b = 0; b < 3; ++b)
            put(ram.data(), actor + 0x514 + 4 * b, std::uint32_t(0));
        animations.apply(id, descriptor, 0, 0);
        call(ram.data(), 0x5d50f0, actor, 0x230000);
        records(player, ram,
                {current->root_motion_delta.x, current->root_motion_delta.y,
                 current->root_motion_delta.z});
        body_equal(*current, ram);
        ++world_cases;
        const std::array<unsigned, 10> requests{0x2050, 0x2051, 0x2003, 0x2005, 0x2010,
                                                0x2015, 0x2050, 0x2051, 0x1001, 0xffff};
        for (unsigned si = 0; si < requests.size(); ++si) {
            current->status = si % 4 == 0 ? 0x80u : si % 4 == 1 ? 8u : 0;
            current->class_marker = std::uint8_t(si % 4);
            current->resource_action = std::uint16_t(si % 3 == 0 ? 11 : 0);
            current->character = 5;
            current->auxiliary_status = si % 2 ? 2 : 0;
            player.channel(a::ModelBank::primary, 1).selector = std::uint16_t(si % 2 ? 0x82 : 0x13);
            put(ram.data(), actor + 0xba0, current->status);
            put(ram.data(), actor + 0xb9b, current->class_marker);
            put(ram.data(), actor + 0xca8, current->resource_action);
            put(ram.data(), actor + 0xb98, current->character);
            put(ram.data(), actor + 0xba4, current->auxiliary_status);
            export_channel(ram.data(), 0, 1, player.channel(a::ModelBank::primary, 1));
            animations.select(id, requests[si], 0, 10);
            call(ram.data(), 0x5d4cf0, actor, requests[si], 0, 0, 0, 10);
            records(player, ram,
                    {current->root_motion_delta.x, current->root_motion_delta.y,
                     current->root_motion_delta.z});
            body_equal(*current, ram);
            ++selection_cases;
        }
        for (unsigned si = 0; si < 4; ++si) {
            const unsigned requested = si == 1 || si == 3 ? 0x2051u : si == 2 ? 0x2003u : 0x2050u;
            current->status = si == 1 ? 8 : 0;
            current->class_marker = std::uint8_t(si == 0 || si == 2 ? 0 : 1);
            current->resource_action = std::uint16_t(si <= 2 ? 11 : 0);
            current->auxiliary_status = 2;
            current->character = 5;
            player.channel(a::ModelBank::primary, 1).selector =
                std::uint16_t(si == 3 ? 0x13 : 0x82);
            put(ram.data(), actor + 0xba0, current->status);
            put(ram.data(), actor + 0xb9b, current->class_marker);
            put(ram.data(), actor + 0xca8, current->resource_action);
            put(ram.data(), actor + 0xb98, current->character);
            put(ram.data(), actor + 0xba4, current->auxiliary_status);
            export_channel(ram.data(), 0, 1, player.channel(a::ModelBank::primary, 1));
            animations.select(id, requested, 0, 10);
            call(ram.data(), 0x5d4cf0, actor, requested, 0, 0, 0, 10);
            records(player, ram,
                    {current->root_motion_delta.x, current->root_motion_delta.y,
                     current->root_motion_delta.z});
            body_equal(*current, ram);
            ++selection_cases;
        }
        if (special_marker) {
            player.resources = {resource0, resource1, resource2};
            for (unsigned b = 0; b < 3; ++b)
                put(ram.data(), actor + 0x514 + 4 * b, bank_at + b * 0x4000);
            current->status = 0;
            current->class_marker = *special_marker;
            current->resource_action = 11;
            current->character = 5;
            current->auxiliary_status = 0;
            player.progress_flags = 0;
            put(ram.data(), actor + 0xba0, current->status);
            put(ram.data(), actor + 0xb9b, current->class_marker);
            put(ram.data(), actor + 0xca8, current->resource_action);
            put(ram.data(), actor + 0xb98, current->character);
            put(ram.data(), actor + 0xba4, current->auxiliary_status);
            ram[actor + 0xce2] = 0;
            for (unsigned track = 0; track < 2; ++track) {
                player.channel(a::ModelBank::primary, track).timing.flags = 0;
                export_channel(ram.data(), 0, track, player.channel(a::ModelBank::primary, track));
            }
            animations.select(id, 0x2003, 0, 0);
            call(ram.data(), 0x5d4cf0, actor, 0x2003, 0, 0, 0, 0);
            check(player.channel(a::ModelBank::primary, 0).timing.frame == 62 &&
                      get<float>(ram.data(), actor + 0x1e4) == 62,
                  "actual special character five branch supplies62 to live original/native motion "
                  "samplers");
            records(player, ram,
                    {current->root_motion_delta.x, current->root_motion_delta.y,
                     current->root_motion_delta.z});
            body_equal(*current, ram);
            ++special_frame_cases;
        }
        bool refused{};
        player.resources_known = false;
        try {
            animations.apply(id, descriptor, 0, 0);
        } catch (const std::runtime_error&) {
            refused = true;
        }
        check(refused, "unadmitted loading state is not guessed successfully unloaded");
        ++world_refusals;
        player.resources_known = true;
        current->model = std::make_shared<a::Instance>(skeleton);
        refused = false;
        try {
            animations.apply(id, descriptor, 0, 0);
        } catch (const std::runtime_error&) {
            refused = true;
        }
        check(refused, "stale exact model/Playback identity refused");
        ++world_refusals;
    }
    {
        g::World world(world_profile(), std::make_shared<g::Session>());
        std::array<std::array<std::shared_ptr<const a::MotionBank>, 3>, 3> owned;
        std::array<g::actors::EntityId, 3> ids;
        std::fill_n(ram.data() + actor, 0x10e0 * 3, 0);
        for (unsigned i = 0; i < 3; ++i) {
            auto value = std::make_unique<g::Actor>();
            value->active = true;
            value->slot = std::uint8_t(i);
            value->character = std::uint8_t(i + 2);
            value->motion_style = std::uint8_t(i % 2);
            value->model = std::make_shared<a::Instance>(skeleton);
            value->animation = std::make_shared<a::Playback>(value->model);
            value->animation->resources_known = true;
            for (unsigned b = 0; b < 3; ++b) {
                owned[i][b] = std::make_shared<a::MotionBank>(*bank);
                value->animation->resources[b] = owned[i][b];
                put(ram.data(), actor + 0x10e0 * i + 0x514 + 4 * b, bank_at + (i * 3 + b) * 0x4000);
            }
            ram[actor + 0x10e0 * i + 3] = value->slot;
            ram[actor + 0x10e0 * i + 0xb98] = value->character;
            ram[actor + 0x10e0 * i + 0xb99] = value->motion_style;
            check(world.spawn_primary(i, std::move(value)).status ==
                      g::actors::EntityStatus::completed,
                  "live native related motion actor");
            ids[i] = world.identity(i);
        }
        auto current = world.primary(0);
        g::MotionRelations relations(world);
        check(relations.bind(ids[0], {ids[1], g::MotionActorLocator{g::MotionActorPool::primary, 1},
                                      g::MotionActorLocator{g::MotionActorPool::primary, 2}}),
              "native direct generation reference and distinct late slot locators");
        put(ram.data(), actor + 0xb24, actor + 0x10e0);
        ram[actor + 0x148] = 0;
        ram[actor + 0x149] = 1;
        ram[actor + 0x14a] = 0;
        ram[actor + 0x14b] = 2;
        g::WorldMotionResources resolver(world, &relations);
        for (unsigned category = 0; category < 2; ++category) {
            current->category = std::uint8_t(category);
            ram[actor + 2] = std::uint8_t(category);
            for (unsigned selector = 0; selector < 15; ++selector) {
                const auto result = resolver.resolve(ids[0], selector);
                const auto original = call(ram.data(), 0x5d4810, actor, selector);
                const auto address = GPR_U32(&original, 2);
                check(address >= bank_at && address < bank_at + 9 * 0x4000 &&
                          ((address - bank_at) % 0x4000) == 0,
                      "actual original family bank address in admitted live owners");
                const auto index = (address - bank_at) / 0x4000;
                check(result == owned[index / 3][index % 3],
                      "complete original self/category-one/three-related-resource family routing");
                check(current->animation->source_kind == ram[actor + 0xce0] &&
                          current->animation->source_slot == ram[actor + 0xce1],
                      "actual family routing identity cache order");
                ++resource_cases;
            }
        }
        check(relations.bind(ids[0], {std::nullopt, std::nullopt, std::nullopt}),
              "explicit known absent native relations");
        put(ram.data(), actor + 0xb24, std::uint32_t(0));
        ram[actor + 0x148] = ram[actor + 0x14a] = 255;
        for (unsigned selector = 6; selector < 15; ++selector) {
            const auto result = resolver.resolve(ids[0], selector);
            const auto original = call(ram.data(), 0x5d4810, actor, selector);
            check(!result && GPR_U32(&original, 2) == 0 &&
                      current->animation->source_kind == ram[actor + 0xce0] &&
                      current->animation->source_slot == ram[actor + 0xce1],
                  "actual absent direct/unsupported-key lookup returns without guessed resource");
            ++resource_cases;
        }
        check(relations.bind(ids[0], {ids[1], g::MotionActorLocator{g::MotionActorPool::primary, 1},
                                      std::nullopt}),
              "fresh typed relation bindings");
        const auto old_actor = world.primary(1);
        check(world.retire_primary(1) == g::actors::EntityStatus::completed,
              "related owner retirement");
        auto replacement = std::make_unique<g::Actor>();
        replacement->slot = 1;
        replacement->model = std::make_shared<a::Instance>(skeleton);
        replacement->animation = std::make_shared<a::Playback>(replacement->model);
        replacement->animation->resources_known = true;
        const auto fresh_bank = std::make_shared<a::MotionBank>(*bank);
        replacement->animation->resources[0] = fresh_bank;
        check(world.spawn_primary(1, std::move(replacement)).status ==
                  g::actors::EntityStatus::completed,
              "native related slot replacement");
        check(!resolver.resolve(ids[0], 6),
              "retired direct B24 generation cannot retarget replacement actor");
        check(resolver.resolve(ids[0], 9) == fresh_bank &&
                  old_actor->animation->resources[0] == owned[1][0],
              "intentional source category/slot lookup selects current occupant while retained old "
              "owner stays unchanged");
        ram[actor + 0x148] = 0;
        ram[actor + 0x149] = 1;
        put(ram.data(), actor + 0x10e0 + 0x514, std::uint32_t(bank_at + 0x30000));
        const auto original = call(ram.data(), 0x5d4810, actor, 9);
        check(GPR_U32(&original, 2) == bank_at + 0x30000,
              "full original633350 also performs late slot lookup after explicit slot resource "
              "replacement");
        ++resource_cases;
        bool refused{};
        g::WorldMotionResources unknown(world);
        try {
            (void)unknown.resolve(ids[0], 6);
        } catch (const std::runtime_error&) {
            refused = true;
        }
        check(refused, "unbound relation ownership unavailable, not presumed absent");
        ++world_refusals;
        refused = false;
        try {
            (void)resolver.resolve(ids[0], 15);
        } catch (const std::out_of_range&) {
            refused = true;
        }
        call(ram.data(), 0x5d4470, actor, 15);
        check(refused && current->animation->source_kind == ram[actor + 0xce0] &&
                  current->animation->source_slot == ram[actor + 0xce1],
              "unsupported family exposes verified cache prefix then refuses undefined original "
              "return");
        ++world_refusals;
    }

    for (unsigned kind = 0; kind < 5; ++kind) {
        g::World world(world_profile(), std::make_shared<g::Session>());
        auto candidate = std::make_unique<g::Actor>();
        candidate->slot = 0;
        candidate->model = std::make_shared<a::Instance>(skeleton);
        candidate->animation = std::make_shared<a::Playback>(candidate->model);
        candidate->animation->resources_known = true;
        const auto admitted = world.spawn_primary(0, std::move(candidate));
        check(admitted.status == g::actors::EntityStatus::completed,
              "lifetime test owner admitted");
        const auto retained = world.primary(0);
        const auto id = admitted.id;
        struct ObservedProfiles final : g::MotionProfiles {
            g::File1MotionProfiles base;
            std::function<void()> effect;
            unsigned at{};
            reo::native::gameplay_collision::actors::ShapeDefinition
            body(std::uint8_t m, std::uint8_t o) const override {
                auto result = base.body(m, o);
                if (at == 0)
                    effect();
                return result;
            }
            g::MotionShapeProfile shape(std::uint8_t m, std::uint8_t o) const override {
                auto result = base.shape(m, o);
                if (at == 1)
                    effect();
                return result;
            }
        } observed;
        struct ObservedPrelude final : g::MotionPrelude {
            std::function<void()> effect;
            void run(g::World&, g::Actor&, float) override {
                effect();
            }
        } observed_prelude;
        auto retire = [&] {
            check(world.retire_primary(0) == g::actors::EntityStatus::completed,
                  "provider can retire exact actor generation");
        };
        observed.at = kind == 1 ? 1 : 0;
        observed.effect = kind == 2 ? std::function<void()>([&] {
            retained->model = std::make_shared<a::Instance>(skeleton);
        })
                                    : std::function<void()>(retire);
        observed_prelude.effect = retire;
        g::WorldMotionResources resolver(world);
        g::WorldAnimation animations(world, resolver, observed, observed_prelude);
        bool refused{};
        try {
            if (kind < 3)
                animations.apply(id, catalog.resolve({}, 0x1001), 0, 0);
            else if (kind == 3)
                (void)animations.tick(id, 1);
            else
                (void)animations.tick_blended(id, 1, .5f);
        } catch (const std::runtime_error&) {
            refused = true;
        }
        check(refused, "retired/replaced owner cannot publish remaining animation effects");
        check(retained->animation->channel(a::ModelBank::primary, 0).timing.frame == 0,
              "retained prior animation remains alive without later channel advancement");
        ++lifetime_cases;
    }
    check(special_frame_cases > 0, "live real motion demonstrates special initial-frame branch");
    check(native_prelude_steps == original_prelude_steps &&
              native_prelude_steps.size() == prelude_native,
          "exact callerstep bits observed atactualoriginalandnativeprelude");
    check(std::find(native_prelude_steps.begin(), native_prelude_steps.end(), bits(-1.f)) !=
                  native_prelude_steps.end() &&
              std::find(native_prelude_steps.begin(), native_prelude_steps.end(), bits(.125f)) !=
                  native_prelude_steps.end(),
          "arbitrary negative/fractional originalsteps are forwarded");
    check(prelude_native >= 64, "required native prelude invoked once per World tick");
    std::cout << "{\"checks\":" << checks << ",\"lifetime_cases\":" << lifetime_cases
              << ",\"world_application_cases\":" << world_cases
              << ",\"special_frame_cases\":" << special_frame_cases
              << ",\"resource_routing_cases\":" << resource_cases
              << ",\"selection_cases\":" << selection_cases
              << ",\"dual_application_cases\":" << dual_cases
              << ",\"metadata_observations\":" << profile_cases
              << ",\"scripted_motion_cases\":" << scripted_motion_cases
              << ",\"scripted_motion_ticks\":" << scripted_motion_ticks
              << ",\"scripted_motion_refusals\":" << scripted_motion_refusals
              << ",\"scripted_positive_tracks\":" << scripted_positive_tracks
              << ",\"cutscene_actor_calls\":" << cutscene_actor_calls
              << ",\"cutscene_actor_gate_calls\":" << cutscene_actor_gate_calls
              << ",\"cutscene_actor_refusals\":" << cutscene_actor_refusals
              << ",\"linked_actor_cases\":" << linked_actor_cases
              << ",\"linked_expiry_cases\":" << linked_expiry_cases
              << ",\"linked_full_pool_cases\":" << linked_full_pool_cases
              << ",\"linked_update_refusals\":" << linked_update_refusals
              << ",\"required_prelude_cases\":" << prelude_native
              << ",\"refusal_cases\":" << world_refusals << ",\"joint_cases\":" << joint_cases
              << ",\"original_calls\":" << helper_calls << ",\"game_run\":false}\n";
} catch (const std::exception& e) {
    std::cerr << location << " " << e.what() << '\n';
    return 1;
}
