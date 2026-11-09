#include "contacts.hpp"
#include <bit>
#include <cstring>
#include <iostream>
#include <source_location>
namespace cw = reo::native::gameplay_contact_world;
namespace w = reo::native::gameplay_world;
namespace c = reo::native::gameplay_collision;
namespace d = c::delivery;
namespace a = reo::native::gameplay_actors;
namespace s = reo::native::gameplay_scenario;
namespace e = reo::native::gameplay_effects;
namespace an = reo::native::animation;
namespace math = reo::native::transform_math;
unsigned checks{}, cases{}, gate_queries{}, retirements{}, model_rebuilds{}, full_passes{};
void check(bool value, const std::source_location at = std::source_location::current()) {
    ++checks;
    if (!value)
        throw std::runtime_error("Canonical contact check " + std::to_string(checks) + " line " +
                                 std::to_string(at.line()));
}
template <class T> void put(std::vector<std::byte>& bytes, unsigned at, T value) {
    std::memcpy(bytes.data() + at, &value, sizeof value);
}
c::response::Grid grid(bool wall) {
    std::vector<std::byte> bytes(128 + (wall ? 56 : 0));
    for (const auto [at, value] : {std::pair{8u, 10000u},
                                   {12u, 10000u},
                                   {16u, 1u},
                                   {20u, 1u},
                                   {32u, 32u},
                                   {36u, 120u},
                                   {40u, 40u}})
        put(bytes, at, value);
    put(bytes, 48, wall ? 0u : 0xffffffffu);
    if (wall) {
        put(bytes, 52, 0xffffffffu);
        const c::response::Triangle triangle{
            0x20000, {{{1500, -1000, 0}, {1500, 1000, 0}, {1500, 0, 3000}}}, {-1, 0, 0}, 1500};
        std::memcpy(bytes.data() + 128, &triangle, sizeof triangle);
    }
    return c::response::Grid::import(bytes);
}
std::shared_ptr<an::Instance> model() {
    std::vector<std::byte> raw(12 + 16 + 3 * 84);
    put(raw, 4, 4u);
    put(raw, 8, std::uint32_t(raw.size()));
    put(raw, 12, 0u);
    put(raw, 16, 1u);
    put(raw, 20, 16u);
    put(raw, 24, 0u);
    for (unsigned i = 0; i < 3; ++i) {
        const auto record = 28 + 84 * i, data = record + 12;
        put(raw, record, 1u);
        put(raw, record + 4, 1u);
        put(raw, record + 8, 84u);
        put(raw, data, std::uint32_t(0xffff));
        put(raw, data + 8, i < 2 ? std::int32_t(i + 1) : -1);
        put(raw, data + 12, std::int32_t(-1));
        for (unsigned j = 0; j < 3; ++j)
            put(raw, data + 0x10 + 4 * j, 1.0f);
        put(raw, data + 0x40, std::uint32_t(i));
    }
    auto instance = std::make_shared<an::Instance>(an::Skeleton::import_raw(raw));
    instance->local_translation(1, {2, 3, 5});
    instance->local_translation(2, {7, 11, 13});
    auto parent = math::identity();
    parent[3] = {17, 19, 23, 1};
    instance->rebuild(parent);
    return instance;
}
std::shared_ptr<w::World> world() {
    w::Profile profile;
    profile.layouts.push_back({0x100, 0x10, 0x20});
    profile.entities.capacity = 16;
    auto session = std::make_shared<w::Session>();
    session->room = 7;
    return std::make_shared<w::World>(profile, session);
}
a::EntityId spawn(w::World& world, unsigned physical, std::uint8_t authored = 29) {
    auto actor = std::make_unique<w::Actor>();
    actor->active = true;
    actor->slot = authored;
    actor->room = 7;
    actor->collision.pose_ready = true;
    actor->position = {1000, 100, 1000};
    actor->collision.basis.translation = {1000, 100, 1000};
    auto created = world.spawn_primary(physical, std::move(actor));
    check(created.status == a::EntityStatus::completed);
    return created.id;
}
struct Room final : cw::RoomInvocation {
    a::EntityStore ids{{1}};
    cw::RoomId id{ids.create(std::make_unique<a::Entity>()).id};
    std::uint16_t number{7};
    c::response::Grid walls = grid(true), floors = grid(false);
    c::regions::World regions;
    c::room_objects::Owner objects;
    std::array<c::response::Triangle, 1> dynamic{};
    s::SceneControls controls;
    s::SceneModels models{{}, {}};
    a::EntityStore scene;
    s::SceneModelBindings bindings{models, scene};
    s::FlagState flags;
    std::shared_ptr<s::SceneMatrixPrograms> matrix =
        std::make_shared<s::SceneMatrixPrograms>(controls, models, bindings, flags, number);
    w::CollisionRoom geometry_value{walls, floors, regions, objects, {}, dynamic, false, false};
    cw::RoomId identity() const noexcept override {
        return id;
    }
    bool current(cw::RoomId candidate) const noexcept override {
        return bool(ids.acquire(candidate.entity));
    }
    std::uint16_t room_number() const noexcept override {
        return number;
    }
    const w::CollisionRoom& geometry() const override {
        return geometry_value;
    }
    std::shared_ptr<s::SceneMatrixPrograms> programs() const override {
        return matrix;
    }
    void expire() {
        check(ids.retire(id.entity) == a::EntityStatus::completed);
        id = {ids.create(std::make_unique<a::Entity>()).id};
    }
};
struct Resources final : cw::RoomResources {
    std::shared_ptr<Room> value;
    explicit Resources(std::shared_ptr<Room> v) : value(std::move(v)) {}
    std::shared_ptr<cw::RoomInvocation> retain(std::uint16_t number) override {
        return value && value->number == number ? value : nullptr;
    }
};
struct Edit final : e::WorkEdit {
    a::EntityId identity() const noexcept override {
        return {};
    }
    bool uniform_scale(float) noexcept override {
        return true;
    }
    bool third_angle(std::int16_t) noexcept override {
        return true;
    }
    bool set_attributes(std::uint16_t) noexcept override {
        return true;
    }
    bool add_attributes(std::uint16_t) noexcept override {
        return true;
    }
    bool feedback(math::Vector, float) noexcept override {
        return true;
    }
};
struct Work final : e::WorkBackend {
    reo::native::gameplay_session::Random& random;
    std::vector<e::WorkRequest> requests;
    explicit Work(reo::native::gameplay_session::Random& r) : random(r) {}
    bool admitted() const noexcept override {
        return true;
    }
    bool bound_to(const reo::native::gameplay_session::Random& value) const noexcept override {
        return &value == &random;
    }
    e::WorkCreated create(const e::WorkRequest& request) noexcept override {
        requests.push_back(request);
        return {e::WorkStatus::completed, std::make_shared<Edit>()};
    }
    e::WorkStatus refresh_companion() noexcept override {
        return e::WorkStatus::unavailable;
    }
};
struct Parameters final : d::ImpactParameters {
    math::Vector modulation() const override {
        return {};
    }
    float scalar() const override {
        return 0;
    }
    bool sound(std::uint8_t, c::Vec3, std::uint16_t) override {
        check(false);
        return false;
    }
};
struct Effects final : d::Effects {
    bool authority(d::View) override {
        return false;
    }
    void vibration(d::View, std::uint8_t) override {
        check(false);
    }
    bool class_two_mark_exempt(d::View) override {
        return false;
    }
    void surface_mark(c::Vec3, c::Vec3) override {
        check(false);
    }
};
struct Debug final : d::ShapeDebug {
    std::vector<std::array<c::Vec3, 2>> lines;
    bool enabled() override {
        return true;
    }
    d::Status line(c::Vec3 a, c::Vec3 b) override {
        lines.push_back({a, b});
        return d::Status::completed;
    }
};
struct Events final : d::PacketEvents {
    unsigned sounds{}, finished{};
    bool audio_admitted(d::PacketOwner) override {
        return true;
    }
    void sound(d::PacketOwner, std::uint8_t) override {
        ++sounds;
    }
    std::int32_t selected_authority(std::uint8_t) override {
        return 0;
    }
    std::optional<std::uint16_t> room_mask(std::uint16_t) override {
        return 0;
    }
    std::int16_t* pending(std::uint8_t) override {
        check(false);
        return nullptr;
    }
    d::Status finish_routes() override {
        ++finished;
        return d::Status::completed;
    }
};
int main() try {
    for (unsigned n = 0; n < 256; ++n) {
        auto owner = world();
        const auto id = spawn(*owner, 0, std::uint8_t(n));
        auto actor = owner->resolve(id);
        auto room = std::make_shared<Room>();
        Resources resources(room);
        auto invocation = cw::retain(owner, resources);
        check(bool(invocation));
        auto selected = invocation->owner(id);
        check(selected && &selected->contact.actor == static_cast<a::HitActor*>(actor.get()) &&
              selected->active);
        selected->contact.position.x = 101;
        selected->contact.cooldown = 203;
        check(actor->position.x == 101 && actor->normalized_marker == 203 &&
              selected->contact.actor.slot == n);
        c::hit_regions::Queue enrolled;
        actor->damage_word = 999;
        actor->pending_hit = 7;
        actor->contact.priority = 101;
        check(!invocation->enroll(id, enrolled) && actor->normalized_marker == 202 &&
              actor->damage_word == 0 && actor->pending_hit == 0 && actor->contact.priority == 0);
        actor->normalized_marker = 0;
        actor->contact.regions.set(std::vector<c::hit_regions::Definition>{{{}, 1, 0}});
        check(invocation->enroll(id, enrolled) && enrolled.entries().size() == 1 &&
              enrolled.entries()[0] == id);
        d::Packets attachments;
        d::Catalog absent_catalog;
        check(invocation->attach(attachments, absent_catalog, 0, 0, id).status ==
                  d::PacketStatus::invalid &&
              attachments.size() == 0);
        auto pose = invocation->pose(*selected);
        check(pose && pose->joints.empty() && &pose->root == &actor->collision.basis);
        pose->projectile_point = c::Vec3{3, 5, 7};
        pose->projectile_normal = c::Vec3{11, 13, 17};
        pose->surface_valid = true;
        check(actor->projectile_contact.point.y == 5 && actor->projectile_contact.normal.z == 17 &&
              actor->sampled_surface_valid);
        actor->collision.pose_ready = false;
        check(!invocation->pose(*selected));
        actor->collision.pose_ready = true;
        actor->model = model();
        auto weak_model = std::weak_ptr<an::Instance>(actor->model);
        auto first = invocation->pose(*selected);
        check(first && first->joints.size() == 3);
        const auto previous = first->joints[2].translation;
        const auto old_data = first->joints.data();
        check(invocation->pose(*selected)->joints.data() == old_data);
        actor->model->local_translation(2, {100, 200, 300});
        actor->model->rebuild(math::identity());
        auto next = invocation->pose(*selected);
        check(next && next->joints.data() != old_data &&
              next->joints[2].translation.x != previous.x);
        check(first->joints[2].translation.x == previous.x &&
              first->joints[2].translation.y == previous.y);
        actor->model = model();
        check(!weak_model.expired());
        check(invocation->pose(*selected)->joints.size() == 3);
        ++model_rebuilds;
        for (unsigned i = 0; i < 16; ++i) {
            room->matrix->channel(std::uint8_t(i))->gate = std::uint8_t(n + i);
            room->geometry_value.filter.slots[i].kind = std::uint8_t(255 - i);
        }
        auto scene = invocation->scene(*selected);
        check(scene && &scene->walls == &room->walls && &scene->floors == &room->floors &&
              scene->dynamic.data() == room->dynamic.data() &&
              &scene->channels == room->matrix.get());
        for (unsigned i = 0; i < 16; ++i) {
            check(scene->filter.slots[i].state == std::uint8_t(n + i) &&
                  scene->filter.slots[i].kind == 255 - i);
            ++gate_queries;
        }
        room->matrix->channel(3)->gate = 2;
        check(invocation->scene(*selected)->filter.slots[3].state == 2);
        room->matrix->channel(3)->active = 37;
        check(scene->channels.channel(3)->active == 37);
        // A valid identity paired with somebody else's scalar references refuses.
        w::Actor other;
        d::PacketOwner mismatched{
            {id, other, other.contact, other.character, other.position, other.normalized_marker},
            true};
        check(!invocation->pose(mismatched) && !invocation->scene(mismatched));
        owner->room = 8;
        check(!invocation->scene(*selected));
        owner->room = 7;
        auto old_matrix = room->matrix;
        room->matrix = std::make_shared<s::SceneMatrixPrograms>(
            room->controls, room->models, room->bindings, room->flags, room->number);
        check(scene->channels.channel(3)->active == 37 &&
              &invocation->scene(*selected)->channels == room->matrix.get());
        room->matrix->close();
        check(!invocation->scene(*selected));
        room->expire();
        check(!invocation->scene(*selected));
        check(owner->retire_primary(0) == a::EntityStatus::completed);
        check(!invocation->owner(id) && !invocation->pose(*selected));
        check(!invocation->enroll(id, enrolled) &&
              invocation->attach(attachments, absent_catalog, 0, 0, id).status ==
                  d::PacketStatus::missing_actor);
        const auto replacement = spawn(*owner, 0, std::uint8_t(n));
        check(replacement != id && invocation->owner(replacement));
        check(first->joints[2].translation.x == previous.x);
        ++retirements;
        auto foreign = world();
        const auto foreign_id = spawn(*foreign, 0);
        check(!invocation->owner(foreign_id));
        std::weak_ptr<w::World> held = owner;
        owner.reset();
        check(!held.expired());
        invocation.reset();
        check(held.expired());
        check(weak_model.expired());
        ++cases;
    }
    for (unsigned n = 0; n < 32; ++n) {
        auto owner = world();
        const auto id = spawn(*owner, 0, 0);
        auto actor = owner->resolve(id);
        owner->selected_actor = 0;
        const reo::native::gameplay_session::RandomState seed{std::uint16_t(n * 773), 19, 0};
        owner->session().random.restore(seed);
        auto room = std::make_shared<Room>();
        Resources resources(room);
        auto invocation = cw::retain(owner, resources);
        d::Packets packets;
        auto created = packets.create(true);
        check(created.status == d::PacketStatus::completed);
        auto lease = packets.acquire(created.id);
        auto& packet = lease.state();
        auto definition = std::make_shared<d::Definition>();
        definition->geometry = d::SegmentShape{{}, {1, 0, 0}, 1000, {}};
        packet.definition = definition;
        packet.delivery.source = id;
        packet.delivery.cached_related = id;
        packet.delivery.key = 1;
        packet.delivery.response.max_contacts = 255;
        packet.enabled = 1;
        packet.lifetime = 255;
        packet.mask = 16;
        c::hit_regions::Queue targets;
        d::Tables tables;
        Effects effects;
        Work work(owner->session().random);
        Parameters parameters;
        Debug debug;
        Events events;
        const std::array<std::uint8_t, 4> masks{1, 4, 2, 8};
        reo::native::gameplay_session::Random foreign_random;
        Work foreign_work(foreign_random);
        const auto refused = invocation->run(packets, targets, tables, effects, foreign_work,
                                             parameters, debug, events, {masks});
        check(refused.detail == d::Status::unadmitted_content && foreign_work.requests.empty() &&
              owner->session().random.state() == seed && packet.lifetime == 255 &&
              packet.contacts == 0);
        const auto result = invocation->run(packets, targets, tables, effects, work, parameters,
                                            debug, events, {masks});
        check(result.status == d::ServiceStatus::completed && result.queries == 1 &&
              result.contacts == 1 && events.sounds == 1 && events.finished == 1);
        const float stopped = 1500.0f - 0.0010000000474974513f;
        check(packet.impact.x == stopped + 1.0f && packet.impact.y == 100 &&
              packet.impact.z == 1000); // oriented local -Z points toward +X.
        check(work.requests.size() == 3 && work.requests[0].effect == 0x28 &&
              work.requests[1].effect == 0x29 && work.requests[2].effect == 0x2a);
        check(work.requests[0].position && work.requests[0].position->x == packet.impact.x &&
              work.requests[0].position->z == packet.impact.z);
        check(debug.lines.size() == 1 && debug.lines[0][1].x == stopped &&
              debug.lines[0][1].z == 1000);
        reo::native::gameplay_session::Random expected(seed);
        for (unsigned i = 0; i < 1; ++i)
            (void)expected.request(1);
        check(owner->session().random.state() == expected.state());
        check(invocation
                  ->run(packets, targets, tables, effects, work, parameters, debug, events, {masks})
                  .detail == d::Status::invalid_roster);
        check(actor->contact.serial == 1 && actor->contact.recipient == d::Identity{} &&
              actor->contact.related_recipient == d::Identity{});
        ++full_passes;
    }
    Resources absent(nullptr);
    check(!cw::retain(world(), absent));
    check(!cw::retain({}, absent));
    std::cout << "{\"checks\":" << checks << ",\"canonical_cases\":" << cases
              << ",\"gate_queries\":" << gate_queries << ",\"retirements\":" << retirements
              << ",\"model_rebuilds\":" << model_rebuilds << ",\"full_passes\":" << full_passes
              << ",\"game_launched\":false}\n";
} catch (const std::exception& error) {
    std::cerr << error.what() << '\n';
    return 1;
}
