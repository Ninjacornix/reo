#pragma once

#include <algorithm>
#include <cstdint>
#include <memory>
#include <optional>
#include <stdexcept>
#include <utility>
#include <vector>

namespace reo::native::gameplay_scene {
struct RecordDomain final {};
template<class Value> class RecordPool;

// Shared by script controls and collision views. A recycled physical slot never
// grants access through the identity of its previous occupant.
class RecordId final {
public:
    RecordId() = default;
    explicit operator bool() const noexcept { return bool(domain_); }
    friend bool operator==(const RecordId&, const RecordId&) = default;
private:
    std::shared_ptr<const RecordDomain> domain_;
    std::uint64_t generation_{};
    std::uint32_t slot_{};
    template<class Value> friend class RecordPool;
};

enum class Placement { newest, oldest };

// Simulation-owner thread only. The original allocator has one 128-record pool;
// ordering is independent of its free-slot stack. A strong invocation lease
// preserves the old node and its reverse continuation across retirement. Reuse
// installs a NEW node, so a callback cannot redirect an old lease to a new actor.
template<class Value>
class RecordPool final {
public:
    struct Node {
        RecordId id;
        Value value;
        std::shared_ptr<Node> next; // original +28: toward older records
        std::weak_ptr<Node> previous; // original +2C: toward newer records
    };
    using Lease = std::shared_ptr<Node>;

    explicit RecordPool(std::uint32_t capacity = 128,
                        std::uint64_t maximum_generation = UINT64_MAX)
        : domain_(std::make_shared<RecordDomain>()), slots_(capacity),
          maximum_generation_(maximum_generation) {
        if (!capacity || capacity > 128 || !maximum_generation)
            throw std::invalid_argument("Invalid shared scene record capacity/generation");
        free_.reserve(capacity);
        for (std::uint32_t i = 0; i < capacity; ++i) free_.push_back(i);
    }
    ~RecordPool() { clear(); }
    RecordPool(const RecordPool&) = delete;
    RecordPool& operator=(const RecordPool&) = delete;

    std::optional<RecordId> create(Value value, Placement placement = Placement::newest) {
        if (free_.empty() || clearing_) return {};
        const auto slot = free_.back();
        auto& target = slots_[slot];
        RecordId id;
        id.domain_ = domain_; id.slot_ = slot; id.generation_ = target.generation + 1;
        // Allocation completes before modifying the free stack or linked order.
        auto node = std::make_shared<Node>(Node{id, std::move(value), {}, {}});
        free_.pop_back(); target.generation = id.generation_; target.node = node;
        if (!newest_) newest_ = oldest_ = node;
        else if (placement == Placement::newest) {
            node->next = newest_; newest_->previous = node; newest_ = node;
        } else {
            node->previous = oldest_; oldest_->next = node; oldest_ = node;
        }
        ++size_; touch();
        return id;
    }
    Lease acquire(const RecordId& id) const noexcept {
        if (id.domain_ != domain_ || id.slot_ >= slots_.size() || !id.generation_) return {};
        const auto& slot = slots_[id.slot_];
        return slot.generation == id.generation_ ? slot.node : Lease{};
    }
    bool retire(const RecordId& id) noexcept {
        auto node = acquire(id); if (!node) return false;
        auto newer = node->previous.lock();
        const auto older = node->next;
        if (newer) newer->next = older; else newest_ = older;
        if (older) older->previous = newer; else oldest_ = newer;
        auto& slot = slots_[id.slot_]; slot.node.reset();
        if (slot.generation < maximum_generation_) free_.push_back(id.slot_);
        --size_; touch();
        // Deliberately retain node->next for an invocation already using node.
        return true;
    }
    Lease first() const noexcept { return newest_; }
    std::vector<RecordId> ordered() const {
        std::vector<RecordId> result; result.reserve(size_);
        for (auto node = oldest_; node; node = node->previous.lock()) result.push_back(node->id);
        return result;
    }
    std::size_t size() const noexcept { return size_; }
    std::uint64_t revision() const noexcept { return revision_; }
    // Call before mutating any leased record. Collision snapshots are derived
    // caches and must be rebuilt after even a script-only activation change.
    void touch() noexcept { ++revision_; }
    void clear() noexcept {
        if (clearing_) return;
        clearing_ = true;
        while (newest_) (void)retire(newest_->id);
        clearing_ = false;
    }
private:
    struct Slot { Lease node; std::uint64_t generation{}; };
    std::shared_ptr<const RecordDomain> domain_;
    std::vector<Slot> slots_;
    std::vector<std::uint32_t> free_;
    Lease newest_, oldest_;
    std::uint64_t maximum_generation_, revision_{};
    std::size_t size_{};
    bool clearing_{};
};
} // namespace reo::native::gameplay_scene
