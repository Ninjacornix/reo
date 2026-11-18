#include "contact_packets.hpp"
#include <stdexcept>
namespace reo::native::gameplay_collision::delivery {
struct Packets::Node final : gameplay_actors::Entity {
    PacketState state;
    PacketId previous, next;
};
PacketState& Packets::Lease::state() const {
    if (!node_)
        throw std::logic_error("Native contact packet lease is absent");
    return node_->state;
}
PacketId Packets::Lease::previous() const noexcept {
    return node_ ? node_->previous : PacketId{};
}
PacketId Packets::Lease::next() const noexcept {
    return node_ ? node_->next : PacketId{};
}
Packets::Packets() : entities_({64}) {}
Packets::~Packets() {
    close();
}
CreatedPacket Packets::create(bool prepend) {
    if (closed_)
        return {PacketStatus::closed, {}};
    if (entities_.size() == 64)
        return {PacketStatus::full, {}};
    gameplay_actors::EntityCreated created;
    try {
        created = entities_.create(std::make_unique<Node>());
    } catch (const std::bad_alloc&) {
        return {PacketStatus::no_memory, {}};
    }
    if (created.status != gameplay_actors::EntityStatus::completed)
        return {created.status == gameplay_actors::EntityStatus::full ? PacketStatus::full
                                                                      : PacketStatus::no_memory,
                {}};
    PacketId id;
    id.entity_ = created.id;
    auto record = acquire(id);
    if (!tail_) {
        head_ = id;
        tail_ = id;
    } else if (prepend) {
        record.node_->next = head_;
        acquire(head_).node_->previous = id;
        head_ = id;
    } else {
        record.node_->previous = tail_;
        acquire(tail_).node_->next = id;
        tail_ = id;
    }
    return {PacketStatus::completed, id};
}
CreatedPacket Packets::attach(const Catalog& catalog, std::uint8_t bank, std::int32_t ordinal,
                              View owner) {
    if (closed_)
        return {PacketStatus::closed, {}};
    if (!owner.id)
        return {PacketStatus::missing_actor, {}};
    auto definition = catalog.find(bank, ordinal);
    if (!definition)
        return {PacketStatus::invalid, {}};
    auto result = create(true);
    if (result.status != PacketStatus::completed)
        return result;
    auto record = acquire(result.id);
    auto& state = record.state();
    state.delivery = {owner.id, owner.contact.related, definition->response,
                      bank,     definition->key,       0};
    state.enabled = 1;
    state.startup = definition->startup;
    state.lifetime = definition->lifetime;
    state.mask = definition->mask;
    state.attachment_flags = definition->attachment_flags;
    state.definition = std::move(definition);
    return result;
}
Packets::Lease Packets::acquire(const PacketId& id) const noexcept {
    Lease result;
    if (!closed_)
        result.node_ = std::static_pointer_cast<Node>(entities_.acquire(id.entity_));
    return result;
}
bool Packets::release(const PacketId& id) noexcept {
    auto record = acquire(id);
    if (!record)
        return false;
    record.state().enabled = 0;
    if (record.node_->previous)
        acquire(record.node_->previous).node_->next = record.node_->next;
    else
        head_ = record.node_->next;
    if (record.node_->next)
        acquire(record.node_->next).node_->previous = record.node_->previous;
    else
        tail_ = record.node_->previous;
    return entities_.retire(id.entity_) == gameplay_actors::EntityStatus::completed;
}
void Packets::close() noexcept {
    if (closed_)
        return;
    for (auto id = head_; id;) {
        auto record = acquire(id);
        record.state().enabled = 0;
        id = record.next();
    }
    closed_ = true;
    head_ = {};
    tail_ = {};
    entities_.shutdown();
}
} // namespace reo::native::gameplay_collision::delivery
