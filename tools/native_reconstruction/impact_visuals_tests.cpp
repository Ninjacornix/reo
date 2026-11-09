#include "game/native/gameplay_collision/impact_populations.hpp"
#include "effect_visual_support.hpp"
#include "fog_tests.inc"
namespace delivery = reo::native::gameplay_collision::delivery;
namespace collision = reo::native::gameplay_collision;
namespace entities = reo::native::gameplay_actors;
unsigned population_cases{}, population_frames{}, population_sounds{}, population_capacity{},
    empty_group_work{};
std::vector<unsigned> empty_group_ids;
struct Parameters final : delivery::ImpactParameters {
    m::Vector modulation() const override {
        return {.25f, .75f, 1.25f};
    }
    float scalar() const override {
        return .625f;
    }
    std::vector<ImpactSound> sounds;
    bool sound(std::uint8_t slot, collision::Vec3 point, std::uint16_t event) override {
        sounds.push_back({slot, {point.x, point.y, point.z}, event});
        return true;
    }
};
std::vector<std::uint32_t> active_work(const std::uint8_t* memory) {
    std::vector<std::uint32_t> result;
    for (auto at = get<std::uint32_t>(memory, 0x3b5848); at;
         at = get<std::uint32_t>(memory, at + 0x20)) {
        check(result.size() < 168 && memory[at] != 0);
        result.push_back(at);
    }
    return result;
}
void compare_population_frame(e::PeriodicVisuals& owner, const std::uint8_t* memory) {
    const auto active = active_work(memory);
    const auto frame = owner.retain();
    check(frame && owner.size() == active.size() && frame->visuals.size() == active.size());
    std::size_t pieces{};
    for (unsigned i = 0; i < active.size(); ++i) {
        const auto at = active[i];
        const auto& output = frame->visuals[i];
        check(output.visible == (memory[at + 1] != 0) && output.pieces.size() == memory[at + 0x31]);
        for (unsigned j = 0; j < output.pieces.size(); ++j) {
            const auto& part = output.pieces[j];
            const auto child = get<std::uint32_t>(memory, at + 0x134 + 4 * j);
            ++pieces;
            if (!output.visible)
                continue;
            check(part.visible == (memory[at + 0xf4 + j] != 0));
            if (!part.visible)
                continue;
            check(part.root == get<std::uint16_t>(memory, child + 2) &&
                  part.material == memory[child + 1] &&
                  part.flags == get<std::uint32_t>(memory, child + 4));
            check(std::memcmp(&part.parameters.translation, memory + child + 0x24, 12) == 0);
            check(std::memcmp(part.parameters.rotation.data(), memory + child + 0x30, 6) == 0);
            check(std::memcmp(&part.parameters.scale, memory + child + 0x38, 12) == 0);
            check(std::memcmp(&part.parameters208, memory + child + 0xc, 12) == 0);
            const auto* mesh = output.bank->geometry().material(part.root, part.material);
            check(mesh != nullptr);
            for (unsigned k = 0; k < mesh->indices.size(); ++k)
                check(std::bit_cast<std::uint32_t>(part.material_values[k]) ==
                      get<std::uint32_t>(memory, child + 0x50 + 4 * k));
        }
    }
    check(owner.piece_count() == pieces &&
          pieces == std::size_t(256 - get<std::uint16_t>(memory, 0x3b5820)));
    check(active.size() == std::size_t(168 - get<std::uint16_t>(memory, 0x3b5828)));
}
void one_population(std::uint8_t* memory, const std::vector<std::vector<std::byte>>& corpus,
                    std::span<const std::byte> fog_asset, unsigned asset, unsigned key,
                    bool surface, unsigned occupied = 0) {
    general_context = "population asset=" + std::to_string(asset) + " key=" + std::to_string(key) +
                      " surface=" + std::to_string(surface) +
                      " occupied=" + std::to_string(occupied);
    std::fill_n(memory, 0x2000000, 0);
    prepare(memory, corpus[asset], corpus[asset + 1]);
    owned_math_constants(memory);
    const auto identity = m::identity();
    std::memcpy(memory + 0x294e00, identity.data(), 64);
    const auto initial = initial_fog(key + asset);
    s::Fog fog(initial);
    export_fog(memory, initial);
    std::memcpy(memory + 0x1a00000, fog_asset.data(), fog_asset.size());
    call(memory, 0x6b23e0, {0x1a00000});
    check(fog.import_fog(fog_asset) == s::FogStatus::completed);
    const auto bank = e::EffectBank::import(corpus[asset], corpus[asset + 1]);
    reo::native::gameplay_session::Random random;
    random.restore({std::uint16_t(1 + key * 773 + asset), 19, std::uint8_t(asset)});
    put(memory, 0x3244b0, random.state().primary);
    put(memory, 0x3244b8, random.state().secondary);
    memory[0x2b8de8] = random.state().observed;
    e::PeriodicVisuals owner(bank, random, fog);
    for (unsigned i = 0; i < occupied; ++i) {
        const auto at = call(memory, 0x6525d0, {0, 0x70000, 0, 36, 0, 0x1a193, 0x6535c0});
        check(GPR_U32(&at, 2) != 0);
        check(owner.emit({36, {}}).status == s::EmissionStatus::completed);
    }
    Parameters parameters;
    put(memory, 0x4bac84, parameters.modulation());
    put(memory, 0x4bac90, parameters.scalar());
    auto basis = m::identity();
    basis[0] = {.5f, .125f, -.25f, 0};
    basis[1] = {.25f, 1.5f, .375f, 0};
    basis[2] = {-.125f, .25f, .75f, 0};
    basis[3] = {-13, 7.25f, 3.75f, 1};
    std::memcpy(memory + 0x70100, basis.data(), 64);
    collision::Vec3 point{float(key) - 40, -7.25f, float(key % 7) * 3.5f};
    put(memory, 0x70000, point);
    entities::EntityStore actor_domain;
    const auto id = actor_domain.create(std::make_unique<entities::Entity>()).id;
    entities::HitActor actor;
    actor.slot = std::uint8_t(asset * 17 + key);
    delivery::Component contact;
    std::uint8_t character{}, cooldown{};
    delivery::View view{id, actor, contact, character, point, cooldown};
    memory[0x60003] = actor.slot;
    const auto optional_basis = surface && key % 3 == 0 ? std::optional<m::Matrix>{} : basis;
    original_impact_sounds.clear();
    call(memory, surface ? 0x5dd9d0 : 0x5dd6f0,
         {0x60000, optional_basis ? 0x70100u : 0u, 0x70000, key});
    delivery::ContactVisuals visuals(owner, random, parameters);
    const auto status = surface ? visuals.surface(view, optional_basis, point, std::uint8_t(key))
                                : visuals.oriented(basis, point, std::uint8_t(key));
    if (status != delivery::Status::completed) {
        std::cerr << "native status=" << unsigned(status)
                  << " source work=" << active_work(memory).size() << " nativework=" << owner.size()
                  << '\n';
        for (const auto at : active_work(memory))
            std::cerr << "source at=" << at << " logical=" << get<std::uint16_t>(memory, at + 0x204)
                      << " group=" << get<std::uint16_t>(memory, at + 0x206)
                      << " remaining=" << get<std::int16_t>(memory, at + 0xe)
                      << " original_duration=" << get<std::int16_t>(memory, at + 0x240)
                      << " pieces=" << unsigned(memory[at + 0x31]) << '\n';
        for (unsigned logical : {0x2eu}) {
            try {
                (void)bank->bind(std::uint16_t(logical), 0);
            } catch (const std::exception& error) {
                std::cerr << "bind effect=" << logical << " " << error.what() << '\n';
            }
            if (const auto group = bank->tracks().resolve(std::uint16_t(logical), 0)) {
                const auto* entries = bank->tracks().group(*group);
                std::cerr << "group=" << *group << " parts=" << entries->parts.size() << '\n';
                for (const auto& part : entries->parts) {
                    const auto root = bank->geometry().resolve(part.resource);
                    const auto* mesh =
                        root ? bank->geometry().material(*root, part.material) : nullptr;
                    std::cerr << "resource=" << unsigned(part.resource)
                              << " mat=" << unsigned(part.material)
                              << " selector=" << unsigned(part.selector)
                              << " root=" << (root ? int(*root) : -1) << " palette="
                              << (root ? bank->geometry().roots()[*root].palette_admitted : false)
                              << " mesh=" << bool(mesh)
                              << " channels=" << (mesh ? int(mesh->indices.size()) : -1)
                              << " complete=" << (mesh && bank->materials().complete(*mesh))
                              << '\n';
                }
            }
        }
    }
    check(status == delivery::Status::completed);
    check(std::memcmp(&point, memory + 0x70000, 12) == 0);
    check(parameters.sounds.size() == original_impact_sounds.size());
    for (unsigned i = 0; i < parameters.sounds.size(); ++i) {
        const auto& a = parameters.sounds[i];
        const auto& b = original_impact_sounds[i];
        check(a.slot == b.slot && a.event == b.event && std::memcmp(&a.point, &b.point, 12) == 0);
        ++population_sounds;
    }
    check(random.state().primary == get<std::uint16_t>(memory, 0x3244b0) &&
          random.state().secondary == get<std::uint16_t>(memory, 0x3244b8) &&
          random.state().observed == memory[0x2b8de8]);
    check(owner.size() == active_work(memory).size() &&
          owner.piece_count() == std::size_t(256 - get<std::uint16_t>(memory, 0x3b5820)));
    for (const auto at : active_work(memory)) {
        if (get<std::uint16_t>(memory, at + 0x206) != 255)
            continue;
        check(asset == 8 && memory[at + 0x31] == 0 && get<std::int16_t>(memory, at + 0xe) == 12 &&
              get<std::int16_t>(memory, at + 0x240) == 12);
        const auto logical = get<std::uint16_t>(memory, at + 0x204);
        if (std::find(empty_group_ids.begin(), empty_group_ids.end(), logical) ==
            empty_group_ids.end())
            empty_group_ids.push_back(logical);
        ++empty_group_work;
    }
    if (occupied) {
        ++population_capacity;
        owner.close();
        return;
    }
    const m::Vector camera{12, -3, 27};
    auto camera_view = identity;
    camera_view[3] = {-13, 7.25f, 3.75f, 1};
    for (unsigned tick = 0; tick < 4096; ++tick) {
        put(memory, 0x324138, camera);
        std::memcpy(memory + 0x3240e0, camera_view.data(), 64);
        const auto active = active_work(memory);
        for (const auto at : active) {
            const auto callback = get<std::uint32_t>(memory, at + 0x14);
            check(callback == 0x653010 || callback == 0x6531d0 || callback == 0x653e80 ||
                  callback == 0x654d90);
            call(memory, callback, {at});
        }
        check(owner.update_with_view(camera, camera_view).status == e::VisualStatus::completed);
        compare_population_frame(owner, memory);
        compare_fog_state(memory, fog);
        check(random.state().primary == get<std::uint16_t>(memory, 0x3244b0));
        ++population_frames;
        if (owner.size() == 0)
            break;
        check(tick + 1 < 4096);
    }
    owner.close();
    ++population_cases;
}
int main(int argc, char** argv) try {
    check(argc == 3);
    const auto corpus = load(argv[1]);
    const auto fog = fog_assets(argv[2]);
    std::vector<std::uint8_t> ram(0x2000000);
    const std::array<unsigned, 3> rejected{68, 127, 255};
    for (unsigned asset = 0; asset < corpus.size(); asset += 2) {
        for (unsigned key = 0; key < 68; ++key)
            for (bool surface : {false, true})
                one_population(ram.data(), corpus, fog[0], asset, key, surface);
        for (unsigned key : rejected)
            for (bool surface : {false, true})
                one_population(ram.data(), corpus, fog[0], asset, key, surface);
        for (unsigned occupied : {167u, 168u})
            for (unsigned key : {1u, 11u, 20u, 24u, 26u})
                for (bool surface : {false, true})
                    one_population(ram.data(), corpus, fog[0], asset, key, surface, occupied);
    }
    std::sort(empty_group_ids.begin(), empty_group_ids.end());
    check(empty_group_ids == std::vector<unsigned>{46, 47, 48, 49, 50, 55, 73});
    std::cout << "{\"checks\":" << checks
              << ",\"banks\":6,\"population_cases\":" << population_cases
              << ",\"population_frames\":" << population_frames
              << ",\"sounds\":" << population_sounds
              << ",\"capacity_cases\":" << population_capacity
              << ",\"empty_group_work\":" << empty_group_work
              << ",\"empty_group_logical_ids\":[46,47,48,49,50,55,73]"
              << ",\"source_helpers\":" << calls << ",\"game_launched\":false}\n";
} catch (const std::exception& error) {
    std::cerr << error.what() << '\n';
    return 1;
}
