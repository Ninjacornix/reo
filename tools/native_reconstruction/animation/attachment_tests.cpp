#include "game/native/gameplay_world/model_attachments.hpp"
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
        check(GPR_U32(context, 6) == 32 && GPR_U32(context, 5) == 0,
              "only original bounded zero-channel record seam");
        std::memset(memory + GPR_U32(context, 4), 0, 32);
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
namespace s = reo::native::gameplay_scenario;
constexpr std::uint32_t actor_at = 0x4a5c30, work = 0x210000, instance_at = 0x280000,
                        resource_at = 0x3c5630 + 60 * 7;
std::uint64_t admission_cases{}, template_cases{}, attachment_cases{}, primary_cases{},
    special_cases{}, lifetime_cases{};
void compare_templates(const s::ResourceTemplates& catalog, const std::vector<std::uint8_t>& ram) {
    const auto& x = catalog.state();
    check(x.count == get<std::uint16_t>(ram.data(), 0x74ccf0), "actual template count");
    check(std::memcmp(x.templates.data(), ram.data() + 0x74bb50, sizeof x.templates) == 0,
          "all actual and retained template records");
    check(std::memcmp(x.y_offsets.data(), ram.data() + 0x74b940, sizeof x.y_offsets) == 0,
          "actual/retained Y offsets");
    check(std::memcmp(x.offsets.data(), ram.data() + 0x74c770, sizeof x.offsets) == 0,
          "actual/retained numeric offsets");
    check(std::memcmp(x.compatibility.data(), ram.data() + 0x74c970, sizeof x.compatibility) == 0,
          "actual/retained compatibility words");
    check(std::memcmp(x.selectors.data(), ram.data() + 0x74b6e0, sizeof x.selectors) == 0,
          "full last-wins normalized content selector including retained entries");
    ++template_cases;
}
void instance_equal(const g::ResourceModel& native, const std::vector<std::uint8_t>& ram) {
    check(std::memcmp(&native.pose, ram.data() + instance_at + 0x1c0, 64) == 0,
          "complete source attachment pose");
    check(std::memcmp(&native.position, ram.data() + instance_at + 0x200, 12) == 0,
          "source attachment output position");
}
int main(int argc, char** argv) try {
    check(argc == 5, "actual model, animation and version3 template packages required");
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
    const auto clips = load(argv[1]), skeletons = load(argv[2]), template_sections = load(argv[4]);
    check(template_sections.size() == 5, "all five actual scenario template sections");
    for (unsigned asset = 0; asset < template_sections.size(); ++asset) {
        location = "template asset=" + std::to_string(asset);
        s::ResourceTemplates catalog;
        std::fill_n(ram.data() + 0x74bb50, 129 * 24, 0);
        std::fill_n(ram.data() + 0x74b940, 129 * 4, 0);
        std::fill_n(ram.data() + 0x74c770, 128 * 4, 0);
        std::fill_n(ram.data() + 0x74c970, 384 * 2, 0);
        std::fill_n(ram.data() + 0x74b6e0, 600, 255);
        put(ram.data(), 0x74ccf0, std::uint16_t(0));
        for (unsigned pass = 0; pass < 3; ++pass) {
            auto bytes = template_sections[(asset + pass) % template_sections.size()];
            if (pass == 2) {
                std::uint32_t zero = 0;
                std::memcpy(bytes.data() + 16, &zero, 4);
                std::memcpy(bytes.data() + 24, &zero, 4);
            }
            std::memcpy(ram.data() + 0x400000, bytes.data(), bytes.size());
            check(catalog.load(bytes), "actual accepted version3 template load");
            const auto result = call(ram.data(), 0x5921d0, 0x400000);
            check(GPR_U32(&result, 2) == 1, "complete original template load result");
            compare_templates(catalog, ram);
        }
        // Duplicate content selectors overwrite in source scan order; an omitted
        // template source reuses already imported rows rather than clearing them.
        {
            auto bytes = template_sections[asset];
            const auto table =
                get<std::uint32_t>(reinterpret_cast<const std::uint8_t*>(bytes.data()), 16);
            const auto n =
                get<std::uint32_t>(reinterpret_cast<const std::uint8_t*>(bytes.data()), 4);
            std::memcpy(bytes.data() + table + 24 * (n - 1) + 18, bytes.data() + table + 18, 2);
            std::memcpy(ram.data() + 0x400000, bytes.data(), bytes.size());
            check(catalog.load(bytes), "duplicate actual content load");
            call(ram.data(), 0x5921d0, 0x400000);
            compare_templates(catalog, ram);
        }
        {
            auto bytes = template_sections[asset];
            std::uint32_t wrong_version = 2;
            std::memcpy(bytes.data(), &wrong_version, 4);
            std::memcpy(ram.data() + 0x400000, bytes.data(), bytes.size());
            const auto count_before = catalog.state().count;
            check(!catalog.load(bytes), "version mismatch has original false result");
            const auto result = call(ram.data(), 0x5921d0, 0x400000);
            check(GPR_U32(&result, 2) == 0, "original bad version result");
            check(catalog.state().count == count_before, "rejected header preserves native count");
            compare_templates(catalog, ram);
            ++admission_cases;
        }
        // Restore this scenario's actual catalog for downstream resource resolution.
        const auto& section = template_sections[asset];
        std::memcpy(ram.data() + 0x400000, section.data(), section.size());
        check(catalog.load(section), "real scenario catalog restored");
        call(ram.data(), 0x5921d0, 0x400000);
        compare_templates(catalog, ram);
        auto skeleton = a::Skeleton::import_raw(skeletons[0]);
        unsigned body_count{};
        for (const auto& node : skeleton->nodes())
            body_count += node.track == 0;
        std::shared_ptr<const a::Clip> clip;
        std::vector<std::byte> clip_raw;
        for (const auto& bytes : clips) {
            auto candidate = a::Clip::import_raw(bytes);
            if (candidate->tracks().size() == body_count) {
                clip = candidate;
                clip_raw = bytes;
                break;
            }
        }
        check(bool(clip), "actual matching body motion");
        std::fill_n(ram.data() + nodes, skeleton->nodes().size() * 400, 0);
        std::memcpy(ram.data() + 0x400000, skeletons[0].data(), skeletons[0].size());
        call(ram.data(), 0x1a2e00, 0x10000, skeleton_resource, 0x400000);
        call(ram.data(), 0x193380, nodes, 1);
        std::memcpy(ram.data() + 0x500000, clip_raw.data(), clip_raw.size());
        resources = {0, skeleton_resource, 0x900000};
        call(ram.data(), 0x1a1fd0, 0x18000, resources[2], 0x500000);
        call(ram.data(), 0x192bf0, nodes, 2, 0);
        const float frame = clip->last_frame() * .5f;
        call(ram.data(), 0x193230, nodes, 0, 0, 0, frame);
        g::World world({{{g::input::Remap{0x100, 0x20, 0x10}}}, 4, {16, UINT64_MAX}},
                       std::make_shared<g::Session>());
        auto value = std::make_unique<g::Actor>();
        value->active = true;
        value->slot = 0;
        value->model = std::make_shared<a::Instance>(skeleton);
        value->model->bind(0, clip);
        value->model->sample(0, frame);
        value->model->rebuild(t::identity());
        value->contact_flags = 0x12;
        value->model_correction_skip = 1;
        const auto admitted = world.spawn_primary(0, std::move(value));
        check(admitted.status == g::actors::EntityStatus::completed, "canonical actor owner");
        const auto actor = world.primary(0);
        world.paused = 1;
        put(ram.data(), 0x4badf8, world.paused);
        std::fill_n(ram.data() + actor_at, 8 * 0x10e0, 0);
        put(ram.data(), actor_at, std::uint8_t(1));
        put(ram.data(), actor_at + 0x34, work);
        put(ram.data(), actor_at + 0x54a, actor->contact_flags);
        put(ram.data(), actor_at + 0xb40, actor->model_correction_skip);
        put(ram.data(), actor_at + 0xb4, actor->model_scale);
        put(ram.data(), actor_at + 0x50, t::identity());
        for (unsigned n = 0; n < skeleton->nodes().size(); ++n)
            put(ram.data(), work + 0x820 + 4 * n, nodes + 400 * n);
        put(ram.data(), 0x270000, t::identity());
        call(ram.data(), 0x193240, nodes, 0x270000);
        s::SceneResources descriptors;
        g::WorldResourceAttachments attachments(world, descriptors, catalog);
        g::File1AttachmentProfiles profiles;
        unsigned special_action{};
        while (special_action < 64 && profiles.at(std::uint16_t(special_action)).kind != 12)
            ++special_action;
        check(special_action < 64, "actual metadata kind12 exists");
        for (unsigned index = 0; index < catalog.state().count; ++index)
            for (unsigned style = 0; style < 2; ++style)
                for (unsigned variant = 0; variant < 5; ++variant) {
                    location = "attachment asset=" + std::to_string(asset) +
                               " template=" + std::to_string(index) +
                               " style=" + std::to_string(style) +
                               " variant=" + std::to_string(variant);
                    s::SceneDescriptor descriptor;
                    descriptor.active = variant == 4 ? 0 : 128;
                    descriptor.template_index = std::uint8_t(index);
                    const auto correction = actor->model->nodes()[3].local;
                    auto target = std::make_shared<g::ResourceModel>(correction, t::identity(),
                                                                     a::Vector{17, 18, 19}, 0x123);
                    descriptor.primary = target;
                    const auto prior = descriptors.slot(7);
                    const auto installed = descriptors.load(7, descriptor);
                    check(installed.has_value() && !descriptors.get(*prior),
                          "reload retires previous exact descriptor identity");
                    std::fill_n(ram.data() + resource_at, 60, 0);
                    ram[resource_at] = descriptor.active;
                    ram[resource_at + 0x2b] = descriptor.template_index;
                    put(ram.data(), resource_at + 0x1c, instance_at);
                    put(ram.data(), instance_at + 0x180, correction);
                    put(ram.data(), instance_at + 0x1c0, target->pose);
                    put(ram.data(), instance_at + 0x200, target->position);
                    actor->motion_style = std::uint8_t(style);
                    actor->motion_class = variant >= 1 && variant <= 3 ? 128 : 0;
                    actor->secondary = variant == 1 ? 0 : variant == 2 ? 7 : 5;
                    actor->resource_action = std::uint16_t(special_action);
                    ram[actor_at + 0xb99] = actor->motion_style;
                    ram[actor_at + 0x54f] = actor->motion_class;
                    ram[actor_at + 9] = actor->secondary;
                    put(ram.data(), actor_at + 0xca8, actor->resource_action);
                    const unsigned node = variant % 2 ? 15 : 19;
                    attachments.bind(admitted.id, 0x107, node);
                    call(ram.data(), 0x662db0, actor_at, 0x107, node);
                    instance_equal(*target, ram);
                    check(target->flags == 0x123, "pose binding does not alter flags");
                    ++attachment_cases;
                    if (variant >= 1 && variant <= 3)
                        ++special_cases;
                }
        {
            const auto descriptor_id = *descriptors.slot(7);
            const auto saved = *descriptors.get(descriptor_id);
            auto target = std::dynamic_pointer_cast<g::ResourceModel>(saved.primary);
            check(bool(target), "actual attachment retained for refusal cases");
            const auto prior_style = actor->motion_style;
            actor->motion_style = 2;
            bool refused{};
            try {
                attachments.bind(admitted.id, 7, 19);
            } catch (const std::out_of_range&) {
                refused = true;
            }
            check(refused, "unadmitted style refuses after preceding copy/normalization effects");
            actor->motion_style = prior_style;
            ++admission_cases;
            refused = false;
            try {
                attachments.bind(admitted.id, 7, 100000);
            } catch (const std::out_of_range&) {
                refused = true;
            }
            check(refused, "unbounded original node index cannot overrun native model owner");
            ++admission_cases;
            auto empty = saved;
            empty.primary.reset();
            check(descriptors.replace(descriptor_id, empty) == s::SceneStatus::completed,
                  "known null attachment installed");
            const auto prior_pose = target->pose;
            attachments.bind(admitted.id, 7, 100000);
            check(target->pose == prior_pose,
                  "known null source attachment returns before node admission");
            check(descriptors.replace(descriptor_id, saved) == s::SceneStatus::completed,
                  "same exact descriptor capability restored");
            ++admission_cases;
            s::SceneResources foreign;
            check(!foreign.get(descriptor_id), "foreign resource domain rejected");
            ++admission_cases;
        }
        // Same descriptor used twice must expose the second node15 write last.
        actor->selected_resource = actor->secondary_resource = 7;
        ram[actor_at + 0xc7c] = ram[actor_at + 0xc7d] = 7;
        g::File1ModelCorrectionScales scales;
        const auto report = g::rebuild_primary_model_with_attachments(world, admitted.id, scales,
                                                                      nullptr, attachments);
        check(report.visited, "primary model then attachments consumer visits");
        call(ram.data(), 0x3769f0, 0);
        const auto current = std::dynamic_pointer_cast<g::ResourceModel>(
            descriptors.get(*descriptors.slot(7))->primary);
        instance_equal(*current, ram);
        compare_nodes(*actor->model, ram, true);
        ++primary_cases;
        const auto old_descriptor = *descriptors.slot(7);
        const auto lease = current;
        check(descriptors.load(7, {}).has_value() && !descriptors.get(old_descriptor),
              "retired resource generation rejected while model lease survives");
        const auto prior_pose = lease->pose;
        attachments.bind(admitted.id, 7, 19);
        check(lease->pose == prior_pose, "retired attachment is not retargeted");
        check(!descriptors.slot(256) && descriptors.slot(0).has_value(),
              "exact slot zero/inactive versus bounds");
        check(world.retire_primary(0) == g::actors::EntityStatus::completed, "actor retired");
        s::SceneDescriptor d;
        d.primary = lease;
        check(descriptors.load(7, d).has_value(),
              "restore actual capability for stale actor check");
        bool refused{};
        try {
            attachments.bind(admitted.id, 7, 19);
        } catch (const std::runtime_error&) {
            refused = true;
        }
        check(refused, "stale actor identity cannot publish to resource");
        ++lifetime_cases;
    }
    std::cout << "{\"checks\":" << checks << ",\"admission_cases\":" << admission_cases
              << ",\"template_cases\":" << template_cases
              << ",\"attachment_cases\":" << attachment_cases
              << ",\"special_cases\":" << special_cases << ",\"primary_cases\":" << primary_cases
              << ",\"lifetime_cases\":" << lifetime_cases << ",\"joint_cases\":" << joint_cases
              << ",\"original_calls\":" << helper_calls << ",\"game_run\":false}\n";
    return 0;
} catch (const std::exception& e) {
    std::cerr << location << " " << e.what() << '\n';
    return 1;
}
