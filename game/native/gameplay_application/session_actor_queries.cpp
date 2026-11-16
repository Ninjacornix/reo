#include "session_actor_queries.hpp"
#include "native_session.hpp"
#include "../gameplay_collision/object_queries.hpp"
#include <functional>

namespace reo::native::gameplay_application {
namespace collision = gameplay_collision;
namespace world = gameplay_world;

namespace {
class QueryGates final : public collision::QueryStateProvider {
public:
    std::function<std::optional<std::uint16_t>(const collision::ActorQuery&,const collision::Proxy&)> content;
    std::function<std::optional<bool>(const collision::Proxy&)> slot;
    std::function<std::optional<bool>(const collision::Proxy&,const collision::ActorQuery&)> grid;
    std::optional<std::uint16_t> selected_content(const collision::ActorQuery& q,const collision::Proxy& p)override{return content(q,p);}
    std::optional<bool> slot_idle(const collision::Proxy& p)override{return slot(p);}
    std::optional<bool> grid_span_admitted(const collision::Proxy& p,const collision::ActorQuery& q)override{return grid(p,q);}
};
}

SessionActorQueries::SessionActorQueries(NativeSession& session, SessionRooms& rooms,
                                         SessionActorQueryEffects& effects) noexcept
    : session_(session), rooms_(rooms), effects_(effects) {}

std::optional<bool> SessionActorQueries::room_grid_span(world::Actor& actor,
                                                         std::uint8_t slot) noexcept {
    const auto objects = rooms_.objects();
    if (!objects || !objects->initialized() || objects->grid_room() !=
        std::optional<std::uint16_t>(session_.world().room)) return {};
    collision::room_objects::InteractionOwner interactions(*objects);
    const auto object = interactions.masked(slot);
    if (!object) return false; //6B0CF0 rejects an inactive low-five-bit slot
    const auto predicate = collision::object_queries::probe(*objects, interactions,
        *object, slot, actor.collision.basis, actor.collision.local_center,
        {actor.position.x, actor.position.y, actor.position.z},
        static_cast<std::uint16_t>(actor.orientation[1])); // complete6B0CF0
    if (predicate.status != collision::object_queries::Status::complete) return {};
    return predicate.value;
}

std::optional<bool> SessionActorQueries::query(world::World& world, world::Actor& actor,
    std::uint8_t selector, std::uint8_t mode) {
    if (selector == 4) return false; // source has no spatial call or state read
    if (selector > 4) return {};
    if (!session_.open() || &world != &session_.world() || world.closed() ||
        rooms_.world().get() != &world) return {};

    // Keep the host alive through every callback. The room invocation retains
    // the exact geometry/record graph for this room generation.
    const auto host_lease = rooms_.world();
    if (!host_lease || host_lease.get() != &world) return {};
    const auto actor_id = world.identity_of(actor);
    auto actor_lease = world.resolve(actor_id);
    if (!actor_id || actor_lease.get() != &actor) return {};
    std::shared_ptr<gameplay_contact_world::RoomInvocation> room_lease;
    try { room_lease = rooms_.retain(world.room); }
    catch (...) { return {}; }
    if (!room_lease || room_lease->room_number() != world.room ||
        !room_lease->current(room_lease->identity())) return {};

    auto& proxies = session_.scene_proxies();
    const auto handles = proxies.ordered();
    collision::ActorQuery query;
    query.actor_id = actor.slot;
    query.character_id = actor.character;
    query.actor_class = actor.category;
    query.query_class = selector == 2
        ? actor.interaction_control_selector.value_or(0) : mode;
    if (selector == 2 && !actor.interaction_control_selector) return {};
    query.position = {actor.position.x, actor.position.y, actor.position.z};
    query.point = query.position;
    const auto heading = static_cast<std::uint16_t>(actor.orientation[1]);
    const float center_z = actor.collision.local_center.z; // original +1B4
    if (selector == 1)
        query.point = collision::forward_probe(query.position, heading, 46.0f + center_z);
    else if (selector == 2)
        query.point = collision::forward_probe(query.position, heading, 46.0f);
    else if (selector == 3)
        query.point = collision::forward_probe(query.position, heading, center_z);
    query.radius = selector == 3 ? 60.0f : 50.0f;
    if (selector == 2)
        query.radius = static_cast<float>(heading) * 0.0000958738019107841f;
    query.local = world.locally_controlled(actor);
    query.primary_owner = query.local; //1B0340
    query.secondary_owner = actor.category == 0 && world.mode == 0 && actor.slot != 0; //1B03C0

    if (selector == 2) {
        const auto point = collision::integer_xz(query.point);
        if (!point || !actor.interaction_control_selector) return {};
        const auto selector_byte = *actor.interaction_control_selector;
        //5DCA90 has its own ordered type-83 outside-polygon search. It does
        //not use the common5DC570 class/radius/height/admission pipeline and
        //does not write the proxy's runtime+3E byte.
        for (auto handle = handles.rbegin(); handle != handles.rend(); ++handle) {
            const auto* proxy = proxies.get(*handle);
            if (!proxy) return {};
            if (proxy->geometry.kind != 0x83 || !proxy->owner_snapshot ||
                *proxy->owner_snapshot != selector_byte || !proxy->geometry.active ||
                collision::contains(proxy->geometry.bounds, *point)) continue;
            if (!proxies.publish_owner(*handle, actor_id)) return {};
            const auto record_lease = proxies.acquire(*handle);
            const auto* record = record_lease.canonical();
            if (!record || record->owner != actor_id) return {};
            const collision::ownership::Selected selected{*handle, actor_id,
                record->last_query_class.value_or(0)};
            const auto result = effects_.dispatch(world, actor, selected, *record);
            if (!session_.open() || world.closed() ||
                !room_lease->current(room_lease->identity()) ||
                world.resolve(actor_id).get() != &actor) return {};
            return result;
        }
        return false;
    }

    const auto programs = room_lease->programs();
    if (!programs) return {};
    QueryGates gates;
    gates.content = [&](const collision::ActorQuery&,const collision::Proxy& p){
        return effects_.selected_content(world,actor,p);
    };
    gates.slot = [&](const collision::Proxy& p)->std::optional<bool>{
        if(p.identifier>=16)return{};
        const auto channel=programs->inspect(p.identifier);
        if(!channel)return{};
        return channel->contact.gate==0;
    };
    gates.grid = [&](const collision::Proxy& p,const collision::ActorQuery&)->std::optional<bool>{
        if(actor.category==2)return true;
        if(actor.category!=0)return false;
        return room_grid_span(actor,static_cast<std::uint8_t>(p.identifier));
    };
    const auto lazy=proxies.select_lazy(query,actor_id,gates);
    if(lazy.status!=collision::LazySelectionStatus::completed)return{};
    const auto& selected=lazy.selected;
    if(!selected)return false;
    if (!session_.open() || world.closed() || !room_lease->current(room_lease->identity()) ||
        world.resolve(actor_id).get() != &actor) return {};

    // 5DC570 writes the selected native actor at proxy+34 before dispatch.
    // Do not overwrite CollisionShape::query_class: it is the authored filter,
    // not the source's separate runtime byte at proxy+3E.
    const auto* projection = proxies.get(selected->proxy);
    if (!projection) return {};
    auto updated = *projection;
    updated.owner = actor_id;
    if (!proxies.replace(selected->proxy, std::move(updated)) ||
        !proxies.publish_query(selected->proxy, actor_id, selected->query_class)) return {};
    auto record_lease = proxies.acquire(selected->proxy);
    const auto* record = record_lease.canonical();
    if (!record || record->owner != actor_id) return {};

    const auto result = effects_.dispatch(world, actor, *selected, *record);
    // A source callback may retire the actor, room, or record synchronously.
    // The shared leases preserve readable prefixes; identity checks prevent a
    // stale callback result from being reported as a live query result.
    if (!session_.open() || world.closed() || !room_lease->current(room_lease->identity()) ||
        world.resolve(actor_id).get() != &actor) return {};
    return result;
}
} // namespace reo::native::gameplay_application
