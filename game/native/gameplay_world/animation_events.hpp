#pragma once
#include "animation.hpp"
namespace reo::native::gameplay_world::animation_events {
enum class EventKind {
    surface_pair_one,
    surface_pair_zero,
    actor_audio,
    alternate_audio,
    resource_audio,
    resource_callback,
    node_audio,
    position_audio,
    contact_action,
    model_action,
    resource_program,
    character_callback
};
struct Event {
    EventKind kind;
    std::int32_t frame{};
    std::uint32_t argument{}, auxiliary{}, profile{};
    friend bool operator==(const Event&, const Event&) = default;
};
// This is an immutable, native frame-event request, not a guest call address.
// A concrete consumer must provide the actual audio/contact/effect action; the
// scheduler never treats an absent consumer as successful work.
class Consumer {
  public:
    virtual ~Consumer() = default;
    virtual void apply(Actor&, const Event&, float step) = 0;
};
class Metadata {
  public:
    virtual ~Metadata() = default;
    virtual std::uint32_t action_flags(std::uint16_t) const = 0;
    virtual std::uint8_t contact_id(std::uint16_t) const = 0;
};
class File1Metadata final : public Metadata {
  public:
    std::uint32_t action_flags(std::uint16_t) const override;
    std::uint8_t contact_id(std::uint16_t) const override;
};
enum class Family {
    none,
    player_zero,
    player_one,
    civilian_two,
    civilian_three,
    civilian_four,
    civilian_five,
    civilian_six,
    civilian_seven,
    civilian_eight,
    civilian_nine,
    civilian_ten,
    extended_zero,
    extended_one,
    extended_two,
    extended_twelve,
    extended_sixteen,
    extended_eighteen,
    extended_twenty,
    extended_twenty_two,
    extended_twenty_six,
    extended_twenty_seven,
    extended_twenty_nine,
    extended_thirty_six,
    extended_forty_three,
    actor_zero,
    actor_one,
    actor_two,
    actor_four,
    actor_five,
    actor_six,
    actor_seven,
    actor_nine,
    actor_ten,
    actor_eighteen,
    actor_nineteen,
    actor_twenty,
    actor_twenty_two,
    actor_twenty_three,
    actor_twenty_six,
    actor_twenty_seven,
    actor_twenty_nine,
    actor_thirty,
    actor_thirty_six,
    actor_forty_one,
    actor_forty_three,
    actor_fifty_five,
    actor_fifty_nine
};
// Complete573430/5958B0/5959D0/5A8FD0 family selection. No-work branches are
// admitted explicitly; a selected family is not proof its consumers exist.
Family family(std::uint8_t category, bool visible, std::uint8_t actor_type,
              std::uint8_t source_kind, std::uint8_t source_slot) noexcept;
// Complete5965A0/59A820/59EBB0 and the eight character-bank schedules.
// Reads the same canonical Playback selectors, including fresh upper/tail reads
// after synchronous actions. Other real actor families explicitly refuse.
void run_player(Family, Actor&, const Metadata&, Consumer&, float step);
class Prelude final : public MotionPrelude {
  public:
    Prelude(World& world, const Metadata& metadata, Consumer& consumer)
        : world_(world), metadata_(metadata), consumer_(consumer) {}
    void run(World&, Actor&, float step) override;

  private:
    World& world_;
    const Metadata& metadata_;
    Consumer& consumer_;
};
} // namespace reo::native::gameplay_world::animation_events
