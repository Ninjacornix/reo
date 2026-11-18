#pragma once
#include "motion_bank.hpp"
#include "model_blend.hpp"
namespace reo::native::gameplay_world {class PrimaryActorModels;}
namespace reo::native::animation {
struct RootMotionRef {
    float& x;
    float& y;
    float& z;
    Vector get() const noexcept {
        return {x, y, z};
    }
    void set(Vector value) const noexcept {
        x = value.x;
        y = value.y;
        z = value.z;
    }
};
struct MotionChannel {
    FrameRecord timing;
    std::uint16_t selector{};
    float blend_increment{}, blend_position{};
    std::uint16_t blend_remaining{};
    std::uint8_t skip_flags{}, mode{};
    std::uint32_t auxiliary{};
};
enum class ModelBank { primary, secondary };
enum class MotionBound { unchanged, cleared, prepared };
struct MotionClock {
    std::uint8_t mode{}, category{};
    float rate{1};
};
// Canonical Actor-owned animation component. It retains the exact primary
// Instance and its optional independently mutable, same-Skeleton pose bank.
class Playback final {
  public:
    explicit Playback(std::shared_ptr<Instance>, bool secondary_bank = true);
    Playback& operator=(const Playback&)=delete;
    // Simulation-owner snapshot for a distinct actor lifetime. Mutable model
    // banks/channels are independent; authored skeletons/clips/banks stay shared.
    // Includes detached playback state. Allocation failure leaves this intact.
    std::shared_ptr<Playback> clone_independent()const;
    const std::shared_ptr<Instance>& model() const noexcept {
        return primary_;
    }
    const std::shared_ptr<Instance>& secondary_model() const noexcept {
        return secondary_;
    }
    bool secondary_bank_enabled()const noexcept{return secondary_policy_;}
    Vector root_reference()const noexcept{return primary_?PoseBlend::root_reference(*primary_):detached_root_reference_;}
    // Simulation-owner operation for resident model reconstruction. The caller
    // supplies a fresh primary Instance; actor-owned channels, resources, root
    // history and progress survive. Corresponding secondary poses start fresh.
    // Allocation/validation finishes before either visible model is replaced.
    void replace_model(std::shared_ptr<Instance>);
    MotionChannel& channel(ModelBank, std::size_t);
    const MotionChannel& channel(ModelBank, std::size_t) const;
    MotionBound bind_plain(ModelBank, const MotionBank&, std::uint32_t key, std::uint16_t track,
                           float frame);
    int configure(const MotionBank&, std::int32_t key, std::uint16_t track, float frame,
                  float blend, MotionClock, RootMotionRef);
    // Whole-model scripted motion58C970/58CC80. These have distinct flag,
    // root-reference and transition behavior from per-track configuration.
    MotionBound configure_whole(const MotionBank&,std::int32_t key,float frame,
                               float blend,MotionClock,RootMotionRef);
    std::int8_t advance_whole(float step,std::uint8_t clock_mode,RootMotionRef);
    std::int8_t advance_plain(ModelBank, std::uint16_t track, float step, std::uint8_t clock_mode);
    std::int8_t advance_primary(std::uint16_t track, float step, std::uint8_t clock_mode,
                                RootMotionRef);
    std::uint8_t blend_transition(std::uint16_t track, RootMotionRef);
    void blend_banks(std::uint16_t track, float primary_weight, float secondary_weight);
    void activate(std::uint8_t count);
    void or_primary_flags82() noexcept;
    void or_packed_primary_flags(std::uint8_t) noexcept;
    void clear_primary(std::uint16_t track);
    //66C040 after its caller's type1 floor gate. Uses canonical secondary
    //channel364 and saved delta4FC, already owned by this Playback.
    void advance_locomotion_blend(float rate,std::uint8_t clock_mode);
    // The real573430 behavior/event prelude must run before these operations;
    // the World adapter owns that required synchronous provider boundary.
    std::int8_t advance_channels_after_prelude(std::uint8_t count, float step,
                                               std::uint8_t clock_mode, std::uint8_t category,
                                               bool selected, std::uint32_t buttons, RootMotionRef);
    std::int8_t advance_four_after_prelude(float step, float weight, std::uint8_t clock_mode,
                                           std::uint8_t category, bool selected,
                                           std::uint32_t buttons);
    std::uint8_t channel_count{5};
    bool resources_known{};
    std::array<std::shared_ptr<const MotionBank>, 3> resources;
    std::int16_t motion{};
    std::uint8_t source_kind{}, source_slot{}, progress_flags{}, progress_threshold{};
    Vector saved_delta() const noexcept {
        return saved_delta_;
    }
    Vector unblended_delta() const noexcept {
        return unblended_delta_;
    }

  private:
    Playback(const Playback&)=default;
    friend class gameplay_world::PrimaryActorModels;
    void replace_model_prepared(std::shared_ptr<Instance>,std::shared_ptr<Instance>);
    void retire_model()noexcept;
    void require_model()const;
    std::shared_ptr<Instance> primary_, secondary_;
    std::array<std::array<MotionChannel, 5>, 2> channels_{};
    Vector saved_delta_{}, unblended_delta_{};
    Vector detached_root_reference_{};
    bool secondary_policy_{};
    void progress(std::uint8_t category, bool selected, std::uint32_t buttons);
};
float transition_weight(float progress);
float motion_complement(float weight);
} // namespace reo::native::animation
