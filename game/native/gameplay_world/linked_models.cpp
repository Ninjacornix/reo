#include "linked_models.hpp"
#include <stdexcept>
#include <utility>
#include <bit>
namespace reo::native::gameplay_world {
namespace {
#include "linked_model_profile.inc"
#include "linked_model_definitions.inc"
void clear_authored_defaults(Actor& a) {
    a.linked_frame.emplace();
    a.material_uv = MaterialUv{};
    a.motion_rate = 0;
    a.model_scale = {};
    a.motion_multiplier = 0;
    a.surface_kind = 0;
    a.surface_material = 0;
    a.surface_normal = {};
    a.collision.basis.x = {};
    a.collision.basis.y = {};
    a.collision.basis.z = {};
    a.collision.basis.translation = {};
}
} // namespace
LinkedModelPool::~LinkedModelPool() {
    if (updating_)
        std::terminate();
    (void)close();
}
LinkedCreated LinkedModelPool::allocate(bool insert_head) {
    if (closed_)
        return {LinkedStatus::closed, {}};
    if (resetting_)
        return {LinkedStatus::busy, {}};
    if (!remaining_)
        return {LinkedStatus::full, {}};
    std::unique_ptr<Actor> actor;
    try {
        actor = std::make_unique<Actor>();
    } catch (const std::bad_alloc&) {
        return {LinkedStatus::no_memory, {}};
    }
    clear_authored_defaults(*actor);
    const auto created = world_.spawn_linked(std::move(actor));
    if (created.status != actors::EntityStatus::completed)
        return {created.status == actors::EntityStatus::no_memory ? LinkedStatus::no_memory
                                                                  : LinkedStatus::world_unavailable,
                {}};
    const auto index = std::uint8_t(--remaining_);
    auto& slot = slots_[index];
    slot = {created.id, {}, {}};
    if (!head_) {
        head_ = tail_ = index;
    } else if (insert_head) {
        slot.next = head_;
        slots_[*head_].previous = index;
        head_ = index;
    } else {
        slot.previous = tail_;
        slots_[*tail_].next = index;
        tail_ = index;
    }
    return {LinkedStatus::completed, created.id};
}
LinkedStatus LinkedModelPool::clear(bool seal) noexcept {
    if (closed_)
        return LinkedStatus::closed;
    if (updating_ || resetting_)
        return LinkedStatus::busy;
    resetting_ = true;
    if (seal)
        closed_ = true;
    auto old = std::move(slots_);
    slots_ = {};
    head_.reset();
    tail_.reset();
    remaining_ = capacity;
    for (const auto& slot : old)
        if (slot.id)
            (void)world_.retire_linked(slot.id);
    resetting_ = false;
    return LinkedStatus::completed;
}
LinkedStatus LinkedModelPool::reset() noexcept {
    return clear(false);
}
LinkedStatus LinkedModelPool::close() noexcept {
    return clear(true);
}
actors::EntityId LinkedModelPool::head() const noexcept {
    return head_ ? slots_[*head_].id : actors::EntityId{};
}
actors::EntityId LinkedModelPool::tail() const noexcept {
    return tail_ ? slots_[*tail_].id : actors::EntityId{};
}
std::optional<std::uint8_t>
LinkedModelPool::physical_slot(const actors::EntityId& id) const noexcept {
    if (!id)
        return {};
    for (unsigned i = 0; i < capacity; ++i)
        if (slots_[i].id == id)
            return std::uint8_t(i);
    return {};
}
std::shared_ptr<Actor> LinkedModelPool::resolve(const actors::EntityId& id) const {
    if (closed_ || !physical_slot(id))
        throw std::runtime_error("Native linked-model identity foreign or retired");
    auto actor = world_.resolve(id);
    if (!actor)
        throw std::runtime_error("Native linked-model Actor registration stale");
    return actor;
}
actors::EntityId LinkedModelPool::previous(const actors::EntityId& id) const {
    const auto index = physical_slot(id);
    if (!index)
        throw std::runtime_error("Native linked-model traversal identity unavailable");
    return slots_[*index].previous ? slots_[*slots_[*index].previous].id : actors::EntityId{};
}
void LinkedPoseRoot::select(actors::EntityId id) {
    if (id && !world_.resolve(id))
        throw std::runtime_error("Native linked pose root foreign or retired");
    selected_ = std::move(id);
}
bool LinkedPoseRoot::copy_joint17(Actor& dependent) {
    observed_ = selected_;
    if (!selected_)
        return false;
    const auto root = world_.resolve(selected_);
    if (!root)
        throw std::runtime_error("Native linked pose root registration stale");
    if (root->category != 2 || root->slot != 0x13)
        return false;
    if (!root->model || !root->model->retain() || root->model->nodes().size() <= 17)
        throw std::runtime_error("Required native root joint publication unavailable");
    const auto& m = root->model->nodes()[17].world;
    for (unsigned i = 0; i < 3; ++i)
        if (m[i][3] != 0)
            throw std::domain_error("Native dependent pose affine profile required");
    if (m[3][3] != 1)
        throw std::domain_error("Native dependent pose affine translation required");
    dependent.position = {m[3][0], m[3][1], m[3][2]};
    dependent.collision.basis = {{m[0][0], m[0][1], m[0][2]},
                                 {m[1][0], m[1][1], m[1][2]},
                                 {m[2][0], m[2][1], m[2][2]},
                                 {m[3][0], m[3][1], m[3][2]}};
    return true;
}
bool File1LinkedModelProfiles::skip_type1_correction(std::uint16_t variant) const {
    if (variant >= type1_flags.size())
        throw std::out_of_range("Native linked type1 definition variant unavailable");
    return type1_flags[variant] == 1;
}
const LinkedModelDefinition& File1LinkedModelProfiles::definition(std::uint8_t type,std::uint16_t variant,
    ModelDefinitionBank bank) const {
    const auto& definitions = bank == ModelDefinitionBank::alternate ? alternate_model_definitions : model_definitions;
    if (type>=definitions.size() || variant>=definitions[type].size())
        throw std::out_of_range("Native linked model definition unavailable");
    return definitions[type][variant];
}
LinkedModelReport LinkedModelPass::run() {
    if (&pool_.world_ != &world_ || &root_.world_ != &world_ || pool_.closed_)
        throw std::runtime_error("Native linked model pool owner unavailable");
    if (pool_.updating_ || pool_.resetting_)
        throw std::runtime_error("Native linked model pass reentry unavailable");
    pool_.updating_ = true;
    struct Reset {
        bool& flag;
        ~Reset() {
            flag = false;
        }
    } reset{pool_.updating_};
    LinkedModelReport result;
    for (auto id = pool_.tail(); id; id = pool_.previous(id)) {
        const auto actor = pool_.resolve(id);
        ++result.visited;
        if (!actor->visible)
            continue;
        if (!actor->model)
            throw std::runtime_error("Required linked canonical model unavailable");
        const auto model = actor->model;
        actor->collision.basis.translation = {actor->position.x, actor->position.y,
                                              actor->position.z};
        model->root_scale({actor->model_scale.x, actor->model_scale.y, actor->model_scale.z});
        if (actor->slot == 1) {
            if (!profiles_.skip_type1_correction(actor->linked_model_variant))
                correct_model_height(world_, *actor, scales_);
        } else if (actor->slot == 0x1b) {
            correct_model_height(world_, *actor, scales_);
        } else if (actor->slot == 0x38 && actor->motion_subtype == 0) {
            if (root_.copy_joint17(*actor))
                ++result.root_copies;
        }
        if (world_.resolve(id) != actor || actor->model != model)
            throw std::runtime_error("Linked actor/model replaced during model prelude");
        const auto kind = (actor->contact_flags & 0x12) || actor->model_pose_class == 2
                              ? ModelPoseKind::linked_actor
                              : ModelPoseKind::primary;
        const auto report = rebuild_model_after_prelude(world_, *actor, kind, scales_, floors_);
        ++result.updated;
        result.floor_queries += report.floor_queries;
    }
    return result;
}
} // namespace reo::native::gameplay_world
