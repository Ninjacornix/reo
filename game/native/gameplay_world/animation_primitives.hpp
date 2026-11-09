#pragma once
#include "animation_events.hpp"
#include "../animation/frame_events.hpp"
#include "../gameplay_collision/contact_packets.hpp"
#include "../gameplay_scenario/scene_resources.hpp"
namespace reo::native::gameplay_world {class WorldResourcePrograms;}
namespace reo::native::gameplay_world::animation_events {
// Concrete implementations must route through the canonical native audio
// owner. A recording implementation is useful only as a declared test seam.
class Audio {
  public:
    virtual ~Audio() = default;
    virtual void surface(Actor&, std::int8_t kind) = 0;
    virtual void actor(Actor&, std::uint32_t event, bool alternate) = 0;
    virtual void resource(Actor&, std::uint16_t event) = 0;
    virtual void node(Actor&, std::uint16_t kind) = 0;
    virtual void position(Actor&, std::uint32_t event) = 0;
};
// Native partial concrete event consumer. Crossing/RNG/notice/equipment and
// actual Catalog->Packets attachment are implemented here. Missing audio,
// visual/task/resource-program owners fail explicitly only on a reached path.
// Borrowed owners outlive this simulation-thread-only consumer and World.
class NativeConsumer final : public Consumer {
  public:
    NativeConsumer(World& world, const Metadata& metadata, Audio* audio = nullptr,
                   gameplay_collision::delivery::Packets* packets = nullptr,
                   const gameplay_collision::delivery::Catalog* catalog = nullptr,
                   gameplay_scenario::SceneResources* resources = nullptr,
                   WorldResourcePrograms* programs = nullptr)
        : world_(world), metadata_(metadata), audio_(audio), packets_(packets), catalog_(catalog),
          resources_(resources),programs_(programs) {}
    void apply(Actor&, const Event&, float step) override;

  private:
    World& world_;
    const Metadata& metadata_;
    Audio* audio_;
    gameplay_collision::delivery::Packets* packets_;
    const gameplay_collision::delivery::Catalog* catalog_;
    gameplay_scenario::SceneResources* resources_;
    WorldResourcePrograms* programs_;
    Audio& audio();
    bool crosses(Actor&, const Event&, float, unsigned channel);
    void attach(Actor&, std::uint8_t key);
    bool resource_present(const Actor&) const;
    void resource_program(Actor&, unsigned mode);
};
// Complete65E710, on the same canonical actor/equipment/session fields.
void notify_equipment_selection(Actor&, std::uint8_t selected_actor) noexcept;
} // namespace reo::native::gameplay_world::animation_events
