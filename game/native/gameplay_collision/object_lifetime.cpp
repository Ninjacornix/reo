#include "object_lifetime.hpp"
#include <bit>
#include <cmath>
#include "../transform_math/transform_math.hpp"
namespace reo::native::gameplay_collision::room_objects {
namespace {
bool numeric_ready()noexcept {
    try{transform_math::require_profile();return true;}catch(const std::exception&){return false;}
}
void set_yaw(ObjectInstance& object) {
    auto matrix=transform_math::identity();
    transform_math::reset_euler_axes(matrix,{0,object.yaw,0});
    object.basis.x={matrix[0][0],matrix[0][1],matrix[0][2]};
    object.basis.y={matrix[1][0],matrix[1][1],matrix[1][2]};
    object.basis.z={matrix[2][0],matrix[2][1],matrix[2][2]};
}
std::int8_t narrow(int value) {
    return std::bit_cast<std::int8_t>(std::uint8_t(value));
}
} // namespace
InteractionOwner::Lifetime::Lifetime(InteractionOwner& objects, gameplay_actors::EntityStore& scene,
                                     ownership::Proxies& proxies, ModelBindings& bindings,
                                     const response::Grid& walls, const response::Grid& floors)
    : interactions_(objects), scene_(scene), proxies_(proxies), bindings_(bindings), walls_(walls),
      floors_(floors) {}
InteractionOwner::Lifetime::~Lifetime() {
    close();
}
std::shared_ptr<ObjectInstance>
InteractionOwner::Lifetime::acquire(gameplay_actors::EntityId id) const noexcept {
    auto result = std::dynamic_pointer_cast<ObjectInstance>(scene_.acquire(id));
    if (!result || result->object_ordinal >= owned_.size())
        return {};
    const auto& entry = owned_[result->object_ordinal];
    const auto* object = interactions_.owner_.get(entry.object);
    return entry.instance == id && entry.object == result->object && object &&
                   object->instance == id
               ? result
               : nullptr;
}
std::optional<ObjectId> InteractionOwner::Lifetime::external(std::int8_t key) const noexcept {
    if (key < 0)
        return {};
    auto& owner = interactions_.owner_;
    for (unsigned i = 0; i < 32; ++i)
        if (owner.objects_[i].external_id == std::uint8_t(key))
            return owner.objects_[i].active ? std::optional<ObjectId>(owner.id(i)) : std::nullopt;
    return {};
}
void InteractionOwner::Lifetime::refresh_quad(const ownership::Handle& handle, const Quad& quad) {
    if (const auto* p = proxies_.get(handle)) {
        auto next = *p;
        next.geometry.bounds = quad;
        (void)proxies_.replace(handle, std::move(next));
    }
}
bool InteractionOwner::Lifetime::owns(const Owner& owner)const noexcept {
    return &owner==&interactions_.owner_;
}
bool InteractionOwner::Lifetime::available()const noexcept {
    return !closed_&&!closing_&&bool(interactions_.owner_.grid_);
}
InstanceStatus InteractionOwner::Lifetime::move_external(std::uint8_t external_id,std::uint8_t x,std::uint8_t z) {
    if(closed_||closing_)return InstanceStatus::closed;
    auto& owner=interactions_.owner_;
    if(!owner.grid_)return InstanceStatus::missing_grid;
    if(external_id>=32||std::int32_t(x)>=owner.grid_->width||std::int32_t(z)>=owner.grid_->depth)return InstanceStatus::complete;
    for(unsigned slot=0;slot<32;++slot){
        auto& object=owner.objects_[slot];
        if(!object.active||object.external_id!=external_id)continue;
        if(!owner.move_external(external_id,x,z))return InstanceStatus::invalid_object;
        return publish_center(owner.id(slot));
    }
    return InstanceStatus::complete;
}
InstanceStatus InteractionOwner::Lifetime::publish_center(const ObjectId& id) {
    if (closed_ || closing_)
        return InstanceStatus::closed;
    auto* o = interactions_.edit(id);
    if (!o)
        return InstanceStatus::invalid_object;
    auto& owner = interactions_.owner_;
    if (!owner.grid_)
        return InstanceStatus::missing_grid;
    o->center = owner.center(*o);
    if (o->instance) {
        const auto instance = acquire(o->instance);
        if (!instance)
            return InstanceStatus::stale_instance;
        instance->position = o->center;
        instance->material = floors_.floor(o->center).material;
    }
    if (o->proxies[0])
        if (const auto geometry = room_geometry::quads(owner, *o))
            refresh_quad(o->proxies[0], geometry->expanded);
    return InstanceStatus::complete;
}
InstanceResult InteractionOwner::Lifetime::recreate_proxies(const ObjectId& id) {
    if (closed_ || closing_)
        return {InstanceStatus::closed};
    auto* o = interactions_.edit(id);
    if (!o)
        return {InstanceStatus::invalid_object};
    const auto instance = acquire(o->instance);
    if (!instance)
        return {InstanceStatus::stale_instance};
    auto& owner = interactions_.owner_;
    if (!owner.grid_)
        return {InstanceStatus::missing_grid};
    const auto descriptions = room_geometry::proxies(
        owner, *o, {o->instance, instance->position, instance->object_ordinal});
    InstanceResult result{InstanceStatus::complete, o->instance};
    const auto retire = [&](unsigned slot) {
        if (o->proxies[slot])
            (void)proxies_.retire(o->proxies[slot]);
    };
    const auto create = [&](unsigned slot) {
        const auto created = proxies_.create(*descriptions.records[slot]);
        o->proxies[slot] = created.value_or(ownership::Handle{});
        if (!created)
            ++result.missing_proxies;
    };
    if (descriptions.records[0]) {
        retire(0);
        create(0);
    }
    if (descriptions.records[1]) {
        retire(1);
        retire(2);
        create(1);
        create(2);
        retire(3);
        create(3);
    }
    return result;
}
InstanceResult InteractionOwner::Lifetime::create(const ObjectId& id) {
    if (closed_ || closing_)
        return {InstanceStatus::closed};
    auto* o = interactions_.edit(id);
    if (!o)
        return {InstanceStatus::invalid_object};
    if (o->control_flags & 4)
        return {InstanceStatus::explicit_shape};
    auto& owner = interactions_.owner_;
    if (!owner.grid_)
        return {InstanceStatus::missing_grid};
    if (o->instance)
        return {InstanceStatus::already_bound, o->instance};
    if (scene_.size() >= 64)
        return {InstanceStatus::pool_full};
    if (!numeric_ready())
        return {InstanceStatus::numeric_refused};
    const auto* type = owner.type(o->type);
    const auto ordinal = interactions_.source_ordinal(id);
    if ((o->control_flags & 8) && !bindings_.admit(std::uint8_t(type->model_slot),ModelOperation::create))
        return {InstanceStatus::model_refused};
    auto instance = std::make_unique<ObjectInstance>();
    instance->object = id;
    instance->type = o->type;
    instance->model_slot = std::uint8_t(type->model_slot);
    instance->yaw = std::uint16_t(o->rotation << 14);
    instance->flags = o->control_flags;
    instance->object_ordinal = *ordinal;
    const auto created = scene_.create(std::move(instance));
    if (!created.id)
        return {InstanceStatus::allocation_failed};
    o->instance = created.id;
    owned_[*ordinal] = {id, created.id};
    const auto live = acquire(created.id);
    if (live->flags & 8) {
        const auto index = bindings_.resolve(live->model_slot);
        bindings_.mark(index);
        if (index != 255)
            bindings_.bind(index, created.id);
        if (!bindings_.healthy()) {
            if (index != 255)
                bindings_.unbind(index);
            (void)scene_.retire(created.id);
            o->instance = {};
            owned_[*ordinal] = {};
            return {InstanceStatus::model_refused};
        }
    }
    set_yaw(*live);
    (void)publish_center(id);
    return recreate_proxies(id);
}
void InteractionOwner::Lifetime::rebuild_dynamic() {
    if (closed_ || closing_)
        return;
    const auto& owner = interactions_.owner_;
    if (!owner.grid_)
        return;
    dynamic_ = room_geometry::build_dynamic(owner, owner.room_, walls_, {});
}
InstanceResult InteractionOwner::Lifetime::enable(std::int8_t key) {
    if (closed_ || closing_)
        return {InstanceStatus::closed};
    const auto id = external(key);
    if (!id)
        return {InstanceStatus::invalid_object};
    auto* o = interactions_.edit(*id);
    if (o->room == interactions_.owner_.room_ && !o->instance && !numeric_ready())
        return {InstanceStatus::numeric_refused};
    if (o->room == interactions_.owner_.room_ && !o->instance && (o->control_flags & 8)) {
        const auto* type=interactions_.owner_.type(o->type);
        if (!bindings_.admit(std::uint8_t(type->model_slot),ModelOperation::create))
            return {InstanceStatus::model_refused};
    }
    o->control_flags |= 1;
    InstanceResult result{InstanceStatus::complete, o->instance};
    if (o->room == interactions_.owner_.room_ && !o->instance)
        result = create(*id);
    rebuild_dynamic();
    return result;
}
InstanceStatus InteractionOwner::Lifetime::disable(std::int8_t key) {
    if (closed_ || closing_)
        return InstanceStatus::closed;
    const auto id = external(key);
    if (!id)
        return InstanceStatus::invalid_object;
    auto* o = interactions_.edit(*id);
    if (const auto live=acquire(o->instance);live && (live->flags&8) && !bindings_.admit(live->model_slot,ModelOperation::retire))
        return InstanceStatus::model_refused;
    o->control_flags &= ~1u;
    auto result = InstanceStatus::complete;
    if (o->instance) {
        const auto live = acquire(o->instance);
        if (!live)
            result = InstanceStatus::stale_instance;
        else {
            if (live->flags & 8) {
                const auto index = bindings_.resolve(live->model_slot);
                bindings_.unbind(index);
                bindings_.retain_pose_full(index, live->basis,live->pose_w);
                if (!bindings_.healthy())
                    result=InstanceStatus::model_refused;
            }
            for (unsigned slot = 0; slot < 3; ++slot)
                if (o->proxies[slot])
                    (void)proxies_.retire(o->proxies[slot]);
            // Source retains the three released handles and does not retire slot3.
            (void)scene_.retire(o->instance);
            o->instance = {};
        }
    }
    rebuild_dynamic();
    return result;
}
InstanceUpdate InteractionOwner::Lifetime::update(gameplay_actors::EntityId id) {
    if (closed_ || closing_)
        return {InstanceStatus::closed};
    const auto instance = acquire(id);
    if (!instance)
        return {InstanceStatus::stale_instance};
    auto& owner = interactions_.owner_;
    const auto slot = instance->object_ordinal;
    if (slot >= owned_.size() || owned_[slot].instance != id)
        return {InstanceStatus::invalid_object};
    auto* o = interactions_.edit(owned_[slot].object);
    if (!o || o->instance != id)
        return {InstanceStatus::invalid_object};
    const auto* type = owner.type(o->type);
    instance->visible = !(instance->flags & 8);
    InstanceUpdate result;
    if (type->request_threshold > 0) {
        if (o->control_flags & 2) {
            if (o->proxies[0]) {
                if (const auto geometry = room_geometry::quads(owner, *o))
                    refresh_quad(o->proxies[0], geometry->expanded);
                o->center = instance->position;
            }
        } else if (o->requests >= type->request_threshold && o->direction) {
            switch (o->direction) {
                case 1:
                    o->z = narrow(int(o->z) + 1);
                    break;
                case 2:
                    o->x = narrow(int(o->x) + 1);
                    break;
                case 4:
                    o->z = narrow(int(o->z) - 1);
                    break;
                case 8:
                    o->x = narrow(int(o->x) - 1);
                    break;
                default:
                    break;
            }
            if (const auto geometry = room_geometry::quads(owner, *o)) {
                if (o->proxies[1] && o->proxies[2]) {
                    refresh_quad(o->proxies[1], geometry->first);
                    refresh_quad(o->proxies[2], geometry->second);
                }
                if (o->proxies[3])
                    refresh_quad(o->proxies[3], geometry->exact);
            }
            o->control_flags |= 2;
            o->direction = 0;
            result.geometry_changed = true;
        }
    }
    if (instance->flags & 8)
        instance->basis.translation = instance->position;
    return result;
}
InstanceStatus InteractionOwner::Lifetime::reset_requests(std::uint8_t slot) {
    if (closed_ || closing_)
        return InstanceStatus::closed;
    if (slot >= 32)
        return InstanceStatus::invalid_object;
    const auto id = interactions_.masked(slot);
    if (!id)
        return InstanceStatus::invalid_object;
    auto* o = interactions_.edit(*id);
    o->control_flags &= ~2u;
    o->requests = 0;
    o->direction = 0;
    o->secondary_direction = 0;
    auto result = InstanceStatus::complete;
    if ((o->control_flags & 1) && o->room == interactions_.owner_.room_)
        result = publish_center(*id);
    rebuild_dynamic();
    return result;
}
void InteractionOwner::Lifetime::close() noexcept {
    (void)close_checked();
}
InstanceStatus InteractionOwner::Lifetime::close_checked() noexcept {
    if (closed_)
        return close_status_;
    if (closing_)
        return InstanceStatus::busy;
    closing_=true;
    if (!bindings_.healthy())close_status_=InstanceStatus::model_refused;
    for (auto& entry : owned_) {
        if (auto* o = interactions_.edit(entry.object)) {
            if (const auto instance = acquire(o->instance))
                if (instance->flags & 8) {
                    if (bindings_.admit(instance->model_slot,ModelOperation::retire)) {
                        const auto index = bindings_.resolve(instance->model_slot);
                        bindings_.unbind(index);
                        bindings_.retain_pose_full(index, instance->basis,instance->pose_w);
                    } else close_status_=InstanceStatus::model_refused;
                    if (!bindings_.healthy())close_status_=InstanceStatus::model_refused;
                }
            for (auto& proxy : o->proxies) {
                if (proxy)
                    (void)proxies_.retire(proxy);
                proxy = {};
            }
            if (o->instance == entry.instance)
                o->instance = {};
        }
        (void)scene_.retire(entry.instance);
        entry = {};
    }
    dynamic_ = {};
    closed_ = true;
    closing_=false;
    return close_status_;
}
} // namespace reo::native::gameplay_collision::room_objects
