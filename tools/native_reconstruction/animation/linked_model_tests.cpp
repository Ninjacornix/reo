#include "game/native/gameplay_world/linked_models.hpp"
#include "game/native/animation/model.hpp"
#include "game/native/animation/playback.hpp"
#include "game/native/animation/model_blend.hpp"
#include "game/native/animation/constraints.hpp"
#include "game/native/animation/constraint_math.hpp"
#include "game/native/animation/model_math.hpp"
#include "reference.hpp"
#include <fstream>
#include <iostream>
#include <vector>
namespace a = reo::native::animation;
namespace t = reo::native::transform_math;
#include "owned_constants.hpp"
#include "functions.h"
constexpr std::uint32_t nodes = 0x100000, skeleton_resource = 0x800000;
std::string location;
std::array<float, 2> last_weights{};
void (*prelude_hook)(std::uint8_t*, R5900Context*){};
std::vector<std::uint32_t> resources{0, 0x800000};
std::uint64_t config_cases{}, plain_cases{}, tick_cases{}, transition_cases{}, four_cases{},
    whole_model_cases{}, orchestration_cases{}, prelude_calls{};
std::uint64_t capture_cases{}, blend_cases{}, link_cases{}, checks{}, helper_calls{}, model_cases{},
    joint_cases{}, root_cases{}, nonzero_root{}, difference_cases{}, frame_cases{},
    binding_refusals{}, snapshot_cases{}, math_cases{}, constructor_cases{}, callback_cases{};
void check(bool yes, const std::string& why) {
    ++checks;
    if (!yes)
        throw std::runtime_error(why);
}
template <class T> T get(const std::uint8_t* p, std::uint32_t at) {
    return transform_read<T>(p, at);
}
template <class T> void put(std::uint8_t* p, std::uint32_t at, T v) {
    transform_write(p, at, v);
}
void original_transform_port(std::uint8_t* memory, R5900Context* context, PS2Runtime* runtime) {
    ++helper_calls;
    if (context->pc == 0x107ab0) {
        const auto dst = GPR_U32(context, 4), src = GPR_U32(context, 5), n = GPR_U32(context, 6);
        check(src >= 0x400000 && src + n <= 0x410000, "bounded actual template-copy source");
        check((dst == 0x74bb50 && n <= 129 * 24) || (dst == 0x74b940 && n <= 129 * 4) ||
                  (dst == 0x74c770 && n <= 128 * 4) || (dst == 0x74c970 && n <= 384 * 2),
              "declared original native byte-copy seam destinations");
        std::memmove(memory + dst, memory + src, n);
        context->pc = GPR_U32(context, 31);
        return;
    }
    if (context->pc == 0x192690)
        last_weights = {context->f[12], context->f[13]};
    if (context->pc == 0x18dca0) {
        const auto token = GPR_U32(context, 4);
        check(token < resources.size(), "only admitted owned model/Clip token identities");
        SET_GPR_U32(context, 2, resources[token]);
        context->pc = GPR_U32(context, 31);
        return;
    }
    if (context->pc == 0x107c68) {
        check((GPR_U32(context, 6) == 32 || GPR_U32(context, 6) == 0xd90 ||
               GPR_U32(context, 6) == 0x2a620) &&
                  GPR_U32(context, 5) == 0,
              "only original bounded zero-channel record seam");
        std::memset(memory + GPR_U32(context, 4), 0, GPR_U32(context, 6));
        context->pc = GPR_U32(context, 31);
        return;
    }
    if (context->pc == 0x573430) {
        ++prelude_calls;
        if (prelude_hook)
            prelude_hook(memory, context);
        context->pc = GPR_U32(context, 31);
        return;
    }
    switch (context->pc) {
#include "original_dispatch.hpp"
        default:
            throw std::runtime_error("undeclared original model helper " +
                                     std::to_string(context->pc));
    }
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#include "original_models.cpp"
#pragma GCC diagnostic pop
R5900Context call(std::uint8_t* ram, std::uint32_t address, std::uint32_t arg0,
                  std::uint32_t arg1 = 0, std::uint32_t arg2 = 0, std::uint32_t arg3 = 0,
                  float frame = 0, float frame2 = 0, float frame3 = 0) {
    R5900Context ctx;
    ctx.pc = address;
    SET_GPR_U32(&ctx, 4, arg0);
    SET_GPR_U32(&ctx, 5, arg1);
    SET_GPR_U32(&ctx, 6, arg2);
    SET_GPR_U32(&ctx, 7, arg3);
    SET_GPR_U32(&ctx, 29, 0x1f00000);
    SET_GPR_U32(&ctx, 31, 0xabcdef);
    ctx.f[12] = frame;
    ctx.f[13] = frame2;
    ctx.f[14] = frame3;
    PS2Runtime rt;
    original_transform_port(ram, &ctx, &rt);
    check(ctx.pc == 0xabcdef && GPR_U32(&ctx, 29) == 0x1f00000,
          "complete original model helper return address=" + std::to_string(address) +
              " pc=" + std::to_string(ctx.pc) + " sp=" + std::to_string(GPR_U32(&ctx, 29)));
    return ctx;
}
std::vector<std::vector<std::byte>> load(const char* path) {
    std::ifstream f(path, std::ios::binary);
    std::uint32_t count{};
    f.read(reinterpret_cast<char*>(&count), 4);
    check(count && count < 1000, "owned corpus count");
    std::vector<std::vector<std::byte>> result;
    for (unsigned i = 0; i < count; ++i) {
        std::uint32_t size{};
        f.read(reinterpret_cast<char*>(&size), 4);
        check(size && size < 0x400000, "owned corpus extent");
        result.emplace_back(size);
        f.read(reinterpret_cast<char*>(result.back().data()), size);
        check(bool(f), "complete owned corpus bytes");
    }
    return result;
}
void compare_nodes(const a::Instance& instance, const std::vector<std::uint8_t>& ram, bool world) {
    for (unsigned i = 0; i < instance.nodes().size(); ++i) {
        const auto at = nodes + 400 * i;
        const auto& native = instance.nodes()[i];
        check(std::memcmp(native.parameters.data(), ram.data() + at + 0x104,
                          sizeof native.parameters) == 0,
              "sampled parameters joint " + std::to_string(i));
        if (std::memcmp(native.caches.data(), ram.data() + at + 0x15c, sizeof native.caches)) {
            for (unsigned c = 0; c < 10; ++c)
                std::cerr << c << ":" << native.caches[c] << "/"
                          << get<std::int16_t>(ram.data(), at + 0x15c + 2 * c) << " ";
            std::cerr << "\n";
        }
        check(std::memcmp(native.caches.data(), ram.data() + at + 0x15c, sizeof native.caches) == 0,
              "sampled caches joint " + std::to_string(i) +
                  " actual=" + std::to_string(get<std::int16_t>(ram.data(), at + 0x15c)) +
                  " native=" + std::to_string(native.caches[0]));
        check(std::memcmp(&native.local, ram.data() + at + 0x40, 64) == 0,
              "sampled local matrix joint " + std::to_string(i));
        if (world)
            check(std::memcmp(&native.world, ram.data() + at, 64) == 0,
                  "recursive world matrix joint " + std::to_string(i));
        ++joint_cases;
    }
}

namespace g = reo::native::gameplay_world;
std::uint64_t lifetime_guard_cases{}, pool_cases{}, model_passes{}, visible_cases{},
    inactive_visible_cases{}, dependent_copies{}, refusal_cases{}, correction_cases{};
g::Profile world_profile() {
    return {{g::input::Remap{0x100, 0x20, 0x10}}, 4, {128, UINT64_MAX}};
}
std::uint32_t original_address(const g::LinkedModelPool& pool, const g::actors::EntityId& id) {
    if (!id)
        return 0;
    const auto index = pool.physical_slot(id);
    check(index.has_value(), "exact native slot capability");
    return 0x42eb00 + 0xd90 * unsigned(*index);
}
void pool_equal(const g::LinkedModelPool& pool, const std::vector<std::uint8_t>& ram) {
    check(pool.remaining() == get<std::uint16_t>(ram.data(), 0x3b58f0), "actual allocation budget");
    check(original_address(pool, pool.head()) == get<std::uint32_t>(ram.data(), 0x3b58f8) &&
              original_address(pool, pool.tail()) == get<std::uint32_t>(ram.data(), 0x3b5900),
          "actual native head and tail");
    unsigned visited{};
    for (auto id = pool.tail(); id; id = pool.previous(id)) {
        check(original_address(pool, pool.previous(id)) ==
                  get<std::uint32_t>(ram.data(), original_address(pool, id) + 0x1c),
              "complete source reverse linked order");
        check(++visited <= 50, "bounded native linked ownership");
    }
    check(visited == 50 - pool.remaining(), "every allocated source slot remains in list budget");
    ++pool_cases;
}
a::Matrix actor_matrix(const g::Actor& actor) {
    const auto& b = actor.collision.basis;
    return {{{b.x.x, b.x.y, b.x.z, 0},
             {b.y.x, b.y.y, b.y.z, 0},
             {b.z.x, b.z.y, b.z.z, 0},
             {b.translation.x, b.translation.y, b.translation.z, 1}}};
}
void compare_model(const a::Instance& model, const std::vector<std::uint8_t>& ram, unsigned at) {
    for (unsigned n = 0; n < model.nodes().size(); ++n) {
        const auto& v = model.nodes()[n];
        if (std::memcmp(&v.world, ram.data() + at + 400 * n, 64) ||
            std::memcmp(&v.local, ram.data() + at + 400 * n + 0x40, 64)) {
            for (unsigned lane = 0; lane < 16; ++lane) {
                const auto native = std::bit_cast<std::array<std::uint32_t, 16>>(v.world)[lane],
                           actual = get<std::uint32_t>(ram.data(), at + 400 * n + 4 * lane);
                if (native != actual)
                    std::cerr << "world joint=" << n << " lane=" << lane << " native=" << native
                              << " actual=" << actual << "\n";
            }
            std::cerr << "localY native=" << v.local[3][1]
                      << " actual=" << get<float>(ram.data(), at + 400 * n + 0x74) << "\n";
        }
        check(std::memcmp(&v.world, ram.data() + at + 400 * n, 64) == 0 &&
                  std::memcmp(&v.local, ram.data() + at + 400 * n + 0x40, 64) == 0,
              "complete linked original local/world joints");
        check(std::memcmp(v.parameters.data(), ram.data() + at + 400 * n + 0x104, 40) == 0,
              "linked original sampled parameters");
        ++joint_cases;
    }
}
int main(int argc, char** argv) try {
    check(argc == 5, "real owned model/Clip packages required");
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
    const auto clips = load(argv[1]), skeletons = load(argv[2]);
    {
        g::World world(world_profile(), std::make_shared<g::Session>());
        auto& pool = world.linked_models();
        std::shared_ptr<g::Actor> previous;
        g::actors::EntityId old_id;
        for (unsigned epoch = 0; epoch < 16; ++epoch) {
            check(pool.reset() == g::LinkedStatus::completed, "explicit native pool reset");
            call(ram.data(), 0x6ba260, 0);
            if (previous)
                check(!world.resolve(old_id) && previous->position.x == 77,
                      "retained old owner survives but never resolves after reset");
            pool_equal(pool, ram);
            for (unsigned n = 0; n < 50; ++n) {
                const bool head = (n + epoch) % 3 == 0;
                const auto created = pool.allocate(head);
                const auto actual = call(ram.data(), 0x6ba300, head ? 0xffffffffu : 0);
                check(created.status == g::LinkedStatus::completed &&
                          original_address(pool, created.id) == GPR_U32(&actual, 2),
                      "full original50node allocation andphysical reverse slot");
                const auto actor = pool.resolve(created.id);
                check(!actor->active && !actor->visible && actor->category == 0 &&
                          actor->slot == 0 && actor->model_scale.x == 0 && actor->motion_rate == 0,
                      "observed allocated canonical fields have source-zero state");
                check(ram[GPR_U32(&actual, 2) + 6] == *pool.physical_slot(created.id),
                      "physical slot byte6 belongs to native owner metadata");
                pool_equal(pool, ram);
                if (n == 49) {
                    previous = actor;
                    old_id = created.id;
                    previous->position.x = 77;
                }
            }
            const auto exhausted = pool.allocate(false);
            const auto actual = call(ram.data(), 0x6ba300, 0);
            check(exhausted.status == g::LinkedStatus::full && GPR_U32(&actual, 2) == 0,
                  "fullbudget returns without recycling retired entities implicitly");
        }
    }
    for (unsigned si = 0; si < skeletons.size(); ++si) {
        auto skeleton = a::Skeleton::import_raw(skeletons[si]);
        unsigned body_count{};
        for (const auto& n : skeleton->nodes())
            body_count += n.track == 0;
        std::shared_ptr<const a::Clip> clip;
        std::vector<std::byte> raw_clip;
        for (const auto& b : clips) {
            auto c = a::Clip::import_raw(b);
            if (c->tracks().size() == body_count) {
                clip = c;
                raw_clip = b;
                break;
            }
        }
        check(bool(clip), "actual compatible real motion");
        for (unsigned variant = 0; variant < 128; ++variant) {
            location =
                "linked skeleton=" + std::to_string(si) + " variant=" + std::to_string(variant);
            g::World world(world_profile(), std::make_shared<g::Session>());
            auto& pool = world.linked_models();
            g::LinkedPoseRoot root(world);
            world.paused = 1;
            put(ram.data(), 0x4badf8, world.paused);
            put(ram.data(), 0x743120, 0u);
            call(ram.data(), 0x6ba260, 0);
            std::array<g::actors::EntityId, 3> ids;
            std::array<unsigned, 3> node_bases;
            std::array<unsigned, 3> works;
            std::array<float, 3> prior_local_y{};
            std::memcpy(ram.data() + 0x400000, skeletons[si].data(), skeletons[si].size());
            call(ram.data(), 0x1a2e00, 0x10000, skeleton_resource, 0x400000);
            resources = {0, skeleton_resource, 0x900000};
            std::memcpy(ram.data() + 0x500000, raw_clip.data(), raw_clip.size());
            call(ram.data(), 0x1a1fd0, 0x18000, resources[2], 0x500000);
            for (unsigned i = 0; i < 3; ++i) {
                const auto created = pool.allocate((i + variant) % 2 != 0);
                check(created.status == g::LinkedStatus::completed,
                      "native linked model actor allocated");
                ids[i] = created.id;
                const auto actual = call(ram.data(), 0x6ba300, (i + variant) % 2);
                const auto at = GPR_U32(&actual, 2);
                check(at == original_address(pool, created.id), "source linked model slot");
                auto actor = pool.resolve(created.id);
                actor->active = (variant + i) % 2;
                actor->visible = i != 0 && (i == 1 || variant % 3 != 0);
                actor->category = 2;
                actor->slot = i == 0 ? 0x13
                              : i == 1
                                  ? std::array<std::uint8_t, 5>{1, 0x1b, 0x38, 7, 0x1b}[variant % 5]
                                  : 1;
                actor->motion_subtype = std::uint8_t(variant % 2);
                actor->linked_model_variant = std::uint16_t(variant % 100);
                actor->model_pose_class = std::uint8_t(variant % 3 == 0 ? 2 : 0);
                actor->contact_flags = std::uint16_t(variant % 4 == 0 ? 0x12 : 0);
                actor->model_height_correction = .25f;
                actor->position = {float(i * 20), 0, float(i * 30)};
                actor->model_scale = {1.125f, .875f, 1.f};
                actor->collision.basis = {
                    {1, 0, 0},
                    {0, 1, 0},
                    {0, 0, 1},
                    {actor->position.x, actor->position.y, actor->position.z}};
                actor->model = std::make_shared<a::Instance>(skeleton);
                actor->model->bind(0, clip);
                const float frame = clip->last_frame() * float(variant % 5) * .25f;
                actor->model->sample(0, frame);
                auto prior = actor_matrix(*actor);
                prior[3][1] = 1000;
                actor->model->rebuild(prior);
                prior_local_y[i] = actor->model->local_translation(1).y;
                node_bases[i] = 0x100000 + i * 0x10000;
                works[i] = 0x210000 + i * 0x2000;
                const auto node_base = node_bases[i], work = works[i];
                std::fill_n(ram.data() + node_base, skeleton->nodes().size() * 400, 0);
                call(ram.data(), 0x193380, node_base, 1);
                call(ram.data(), 0x192bf0, node_base, 2, 0);
                call(ram.data(), 0x193230, node_base, 0, 0, 0, frame);
                put(ram.data(), 0x270000, prior);
                call(ram.data(), 0x193240, node_base, 0x270000);
                for (unsigned n = 0; n < skeleton->nodes().size(); ++n)
                    put(ram.data(), work + 0x820 + 4 * n, node_base + 400 * n);
                ram[at] = std::uint8_t(actor->active);
                ram[at + 1] = std::uint8_t(actor->visible);
                ram[at + 2] = actor->category;
                ram[at + 3] = actor->slot;
                ram[at + 4] = actor->motion_subtype;
                put(ram.data(), at + 0x34, work);
                put(ram.data(), at + 0x38, actor->position);
                put(ram.data(), at + 0x50, actor_matrix(*actor));
                put(ram.data(), at + 0xb4, actor->model_scale);
                put(ram.data(), at + 0xaa8, actor->model_height_correction);
                put(ram.data(), at + 0xbba, actor->linked_model_variant);
                ram[at + 0x54d] = actor->model_pose_class;
                put(ram.data(), at + 0x54a, actor->contact_flags);
            }
            if (variant % 7 != 0) {
                if (variant % 7 == 2) {
                    pool.resolve(ids[0])->slot = 0x12;
                    ram[original_address(pool, ids[0]) + 3] = 0x12;
                }
                root.select(ids[0]);
            }
            put(ram.data(), 0x755700,
                root.selected() ? original_address(pool, root.selected()) : 0u);
            g::File1ModelCorrectionScales scales;
            g::LinkedModelPass pass(world, pool, root, scales);
            const auto report = pass.run();
            call(ram.data(), 0x376b80, 0);
            check(report.visited == 3, "full linked traversal visits invisible nodes too");
            unsigned visible{};
            for (unsigned i = 0; i < 3; ++i) {
                const auto actor = pool.resolve(ids[i]);
                const auto at = original_address(pool, ids[i]);
                check(std::memcmp(&actor->position, ram.data() + at + 0x38, 12) == 0,
                      "root-dependent canonical position");
                const auto matrix = actor_matrix(*actor);
                check(std::memcmp(&matrix, ram.data() + at + 0x50, 64) == 0,
                      "root-dependent complete affine canonical basis");
                location = "linked skeleton=" + std::to_string(si) +
                           " variant=" + std::to_string(variant) + " actor=" + std::to_string(i) +
                           " type=" + std::to_string(actor->slot);
                compare_model(*actor->model, ram, node_bases[i]);
                if (actor->model->local_translation(1).y != prior_local_y[i])
                    ++correction_cases;
                if (actor->visible) {
                    ++visible;
                    ++visible_cases;
                    if (!actor->active)
                        ++inactive_visible_cases;
                }
            }
            check(report.updated == visible, "source byte1 alone gates model update");
            check((root.observed() ? original_address(pool, root.observed()) : 0u) ==
                      get<std::uint32_t>(ram.data(), 0x743120),
                  "source selected root copied toobserved owner even when mismatching orabsent");
            dependent_copies += report.root_copies;
            ++model_passes;
        }
    }
    {
        location = "native linked ownership/admission";
        g::World world(world_profile(), std::make_shared<g::Session>()),
            foreign_world(world_profile(), std::make_shared<g::Session>());
        auto& pool = world.linked_models();
        check(&pool == &world.linked_models(), "one canonical50slot linked owner perWorld");
        g::LinkedPoseRoot root(world), foreign_root(foreign_world);
        g::File1ModelCorrectionScales scales;
        auto expect_refusal = [&](auto&& action, const char* reason) {
            bool refused{};
            try {
                action();
            } catch (const std::exception&) {
                refused = true;
            }
            check(refused, reason);
            ++refusal_cases;
        };
        const auto primary = world.spawn_primary(0, std::make_unique<g::Actor>());
        check(primary.status == g::actors::EntityStatus::completed,
              "separate primary owner admitted");
        check(world.retire_linked(primary.id) == g::actors::EntityStatus::invalid &&
                  world.primary(0),
              "linked retirement cannot remove primary-owned actor");
        ++refusal_cases;
        expect_refusal([&] { (void)pool.resolve(primary.id); },
                       "primary actor is not a linked-pool member");
        const auto created = pool.allocate(false);
        check(created.status == g::LinkedStatus::completed, "owned linked actor admitted");
        auto actor = pool.resolve(created.id);
        g::LinkedModelPass pass(world, pool, root, scales);
        check(pass.run().visited == 1 && pass.run().updated == 0,
              "invisible actor skipped before missing model admission");
        actor->visible = true;
        expect_refusal([&] { (void)pass.run(); }, "visible actor requires actual canonical model");
        auto skeleton = a::Skeleton::import_raw(skeletons[0]);
        actor->model = std::make_shared<a::Instance>(skeleton);
        actor->model_scale = {1, 1, 1};
        actor->collision.basis = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {}};
        actor->slot = 1;
        actor->linked_model_variant = 100;
        expect_refusal([&] { (void)pass.run(); },
                       "unbounded original type1 variant outside100record profile refused");
        actor->slot = 7;
        actor->contact_flags = 0x12;
        check(pass.run().updated == 1,
              "failed pass clears reentry admission and can be retried honestly");
        {
            struct GuardScales final : g::ModelCorrectionScales {
                g::World& world;
                g::LinkedModelPool& pool;
                g::LinkedModelPass* pass{};
                g::File1ModelCorrectionScales actual;
                mutable unsigned observed{};
                GuardScales(g::World& w, g::LinkedModelPool& p) : world(w), pool(p) {}
                float character(std::uint8_t id) const override {
                    ++observed;
                    check(world.close() == g::Status::busy,
                          "active linked pass prevents World close before effects");
                    check(pool.reset() == g::LinkedStatus::busy,
                          "active linked pass prevents poolreset");
                    bool refused{};
                    try {
                        (void)pass->run();
                    } catch (const std::runtime_error&) {
                        refused = true;
                    }
                    check(refused, "same owner pass reentry refused");
                    return actual.character(id);
                }
                float variant(std::uint16_t id) const override {
                    return actual.variant(id);
                }
            } observer(world, pool);
            actor->category = 0;
            actor->slot = 0x1b;
            actor->model_height_correction = .25f;
            auto old_parent = t::identity();
            old_parent[3][1] = 1000;
            actor->model->rebuild(old_parent);
            g::LinkedModelPass guarded(world, pool, root, observer);
            observer.pass = &guarded;
            check(guarded.run().updated == 1 && observer.observed == 1,
                  "observable native model provider exercises busy/reentry guards");
            check(world.resolve(created.id) == actor && pool.remaining() == 49,
                  "busy refusals preserve same canonical world/pool");
            actor->category = 2;
            actor->slot = 7;
            ++lifetime_guard_cases;
        }
        g::LinkedModelPass wrong(world, pool, foreign_root, scales);
        expect_refusal([&] { (void)wrong.run(); }, "foreign root owner refused before publication");
        g::Actor dependent;
        dependent.position = {11, 22, 33};
        check(!root.copy_joint17(dependent) && dependent.position.y == 22,
              "known absent root preserves dependent pose");
        root.select(primary.id);
        check(!root.copy_joint17(dependent) && dependent.position.y == 22 &&
                  root.observed() == primary.id,
              "wrong root class preserves pose but publishes observed identity");
        const auto root_actor = world.primary(0);
        root_actor->category = 2;
        root_actor->slot = 0x13;
        expect_refusal([&] { (void)root.copy_joint17(dependent); },
                       "matching root requires model publication");
        root_actor->model = std::make_shared<a::Instance>(skeleton);
        expect_refusal([&] { (void)root.copy_joint17(dependent); },
                       "unready root is not guessed a current pose");
        root_actor->model->rebuild(t::identity());
        check(root.copy_joint17(dependent),
              "real default Skeleton publication can supply root pose");
        const auto foreign = foreign_world.spawn_linked(std::make_unique<g::Actor>());
        check(foreign.status == g::actors::EntityStatus::completed,
              "foreign registration admitted initsownWorld");
        expect_refusal([&] { root.select(foreign.id); },
                       "foreign root cannot replace valid selection");
        check(world.retire_linked(created.id) == g::actors::EntityStatus::completed &&
                  pool.remaining() == 49,
              "native entity retirement doesnotrecycle original50allocationbudget");
        expect_refusal([&] { (void)pool.resolve(created.id); },
                       "retired registered Actor refuses future linked lookup");
        const auto lease = actor;
        check(pool.reset() == g::LinkedStatus::completed && pool.remaining() == 50,
              "only explicit reset restores domainbudget");
        check(!world.resolve(created.id) && lease->model,
              "retained model survives without resolving stale identity");
        check(pool.close() == g::LinkedStatus::completed &&
                  pool.allocate(false).status == g::LinkedStatus::closed,
              "close seals allocation before retirement");
        expect_refusal([&] { (void)pass.run(); },
                       "closed linked owner cannot report successful traversal");
        struct ObserveDestroy final : g::Actor {
            g::World& world;
            g::LinkedModelPool& pool;
            unsigned& calls;
            bool& sealed;
            ObserveDestroy(g::World& w, g::LinkedModelPool& p, unsigned& n, bool& s)
                : world(w), pool(p), calls(n), sealed(s) {}
            ~ObserveDestroy() override {
                ++calls;
                bool getter_refused{};
                try {
                    (void)world.linked_models();
                } catch (const std::runtime_error&) {
                    getter_refused = true;
                }
                sealed = getter_refused && pool.allocate(false).status == g::LinkedStatus::closed &&
                         world.spawn_primary(1, std::make_unique<g::Actor>()).status ==
                             g::actors::EntityStatus::closed;
            }
        };
        unsigned destroys{};
        bool sealed{};
        const auto destructor_id =
            world.spawn_linked(std::make_unique<ObserveDestroy>(world, pool, destroys, sealed));
        check(destructor_id.status == g::actors::EntityStatus::completed,
              "native destruction observer owned only byWorld");
        check(world.close() == g::Status::completed && destroys == 1 && sealed,
              "World seals primary/linked metadata before member-aware Actor destruction");
        ++lifetime_guard_cases;
    }
    check(correction_cases > 0, "real height correction changes canonical joint locals");
    check(dependent_copies > 0 && inactive_visible_cases > 0,
          "actual dependent root copying and visible inactive Actors covered");
    std::cout << "{\"checks\":" << checks << ",\"lifetime_guard_cases\":" << lifetime_guard_cases
              << ",\"refusal_cases\":" << refusal_cases
              << ",\"correction_cases\":" << correction_cases << ",\"pool_cases\":" << pool_cases
              << ",\"model_passes\":" << model_passes << ",\"visible_cases\":" << visible_cases
              << ",\"inactive_visible_cases\":" << inactive_visible_cases
              << ",\"dependent_copies\":" << dependent_copies << ",\"joint_cases\":" << joint_cases
              << ",\"original_calls\":" << helper_calls << ",\"game_run\":false}\n";
    return 0;
} catch (const std::exception& e) {
    std::cerr << location << " " << e.what() << '\n';
    return 1;
}
