#pragma once
#include "contact_content.hpp"
namespace reo::native::gameplay_collision::delivery {
class Packets;
class PacketId {
  public:
    PacketId() = default;
    explicit operator bool() const noexcept {
        return bool(entity_);
    }
    friend bool operator==(const PacketId&, const PacketId&) = default;

  private:
    actors::EntityId entity_;
    friend class Packets;
};
struct PacketState {
    Packet delivery;
    std::shared_ptr<const Definition> definition;
    std::uint8_t enabled{}, startup{}, lifetime{}, contacts{}, cooldown{}, previous_valid{};
    std::uint8_t mask{}, attachment_flags{};
    Vec3 impact, previous;
};
enum class PacketStatus { completed, invalid, full, no_memory, closed, missing_actor };
struct CreatedPacket {
    PacketStatus status{PacketStatus::invalid};
    PacketId id;
};
// Native simulation-owner domain. No original slot address or physical free
// stack identity escapes. Per-call leases protect a retired record from reuse.
class Packets {
    struct Node;

  public:
    class Lease {
      public:
        Lease() = default;
        explicit operator bool() const noexcept {
            return bool(node_);
        }
        PacketState& state() const;
        PacketId previous() const noexcept;
        PacketId next() const noexcept;

      private:
        std::shared_ptr<Node> node_;
        friend class Packets;
    };
    Packets();
    ~Packets();
    Packets(const Packets&) = delete;
    Packets& operator=(const Packets&) = delete;
    CreatedPacket create(bool prepend);
    CreatedPacket attach(const Catalog&, std::uint8_t bank, std::int32_t ordinal, View owner);
    Lease acquire(const PacketId&) const noexcept;
    bool release(const PacketId&) noexcept;
    void close() noexcept;
    bool closed() const noexcept {
        return closed_;
    }
    std::size_t size() const noexcept {
        return entities_.size();
    }
    PacketId head() const noexcept {
        return head_;
    }
    PacketId tail() const noexcept {
        return tail_;
    }

  private:
    gameplay_actors::EntityStore entities_;
    PacketId head_, tail_;
    bool closed_{};
};
} // namespace reo::native::gameplay_collision::delivery
