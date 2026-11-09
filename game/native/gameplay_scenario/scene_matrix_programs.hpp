#pragma once
#include "../gameplay_collision/room_damage.hpp"
#include "flags.hpp"
#include "scene_controls.hpp"
#include "scene_matrix_tables.hpp"
#include "scene_model_bindings.hpp"
namespace reo::native::gameplay_scenario {
struct SceneMatrixChannel {
    gameplay_collision::delivery::RouteChannel contact;
    std::uint8_t interaction{}, progress{}, playback{}, model_slot{}, program{},
        cursor{}, curve{}, transform{};
    std::int16_t time{}, segment{}, sound_cursor{};
    std::uint8_t source_type{};
    ModelMatrix matrix{};
};
enum class SceneMatrixSelection {
    room_variant,
    first,
    normal,
    expiry,
    terminal
};
enum class SceneMatrixStatus {
    completed,
    invalid_channel,
    unavailable_control,
    unavailable_flags,
    unadmitted_profile,
    binding_refused,
    unsupported_numeric,
    unavailable_sound,
    sound_refused,
    closed
};
class SceneMatrixSoundSink {
  public:
    virtual ~SceneMatrixSoundSink() = default;
    virtual bool admitted() const noexcept = 0;
    // Selected6B60E0 request: current matrix translation, model sound resource,
    // and low event halfword. The actual room/audio owner resolves the cue.
    virtual bool emit(transform_math::Vector, std::uint8_t sound_resource,
                      std::uint16_t event) = 0;
};
struct SceneMatrixPlaybackResult {
    SceneMatrixStatus status{SceneMatrixStatus::completed};
    std::size_t quanta{}, sounds{};
};
struct SceneMatrixResult {
    SceneMatrixStatus status{SceneMatrixStatus::completed};
    bool matched{}, changed{};
};
// Original reset/service owns16 channels. The32-bit render-admission mask is a
// separate consumer. Typed contact gate/active fields are owned exactly once.
// All borrowed scene owners and room reference outlive this owner.
// ModelBindings retains matrix leases; canonical scene teardown closes bindings
// separately.
class SceneMatrixPrograms final
    : public gameplay_collision::delivery::RouteChannels {
  public:
    using State = std::array<SceneMatrixChannel, 16>;
    SceneMatrixPrograms(SceneControls &, SceneModels &, SceneModelBindings &,
                        FlagState &, const std::uint16_t &current_room,
                        const State &initial = {});
    std::optional<gameplay_collision::delivery::ChannelView>
    channel(std::uint8_t) override;
    std::optional<SceneMatrixChannel> inspect(std::size_t) const noexcept;
    SceneMatrixResult select(std::uint32_t authored,
                             SceneMatrixSelection) noexcept;
    SceneMatrixStatus evaluate_first(std::size_t) noexcept;
    SceneMatrixPlaybackResult advance(std::size_t, bool double_quantum,
                                      SceneMatrixSoundSink *) noexcept;
    SceneMatrixStatus source_type(std::size_t,std::uint8_t) noexcept;
    bool bound_to(const SceneControls& controls,const SceneModels& models)const noexcept{return !closed_ && &controls_==&controls && &models_==&models;}
    void close() noexcept { closed_ = true; }

  private:
    SceneControls &controls_;
    SceneModels &models_;
    SceneModelBindings &bindings_;
    FlagState &flags_;
    const std::uint16_t &room_;
    std::array<std::shared_ptr<SceneMatrixChannel>, 16> channels_;
    std::array<std::shared_ptr<ModelMatrix>, 16> matrices_;
    const SceneMatrixTables &tables_;
    bool closed_{};
    static ModelMatrix evaluate_value(const ModelMatrix &, std::uint8_t,
                                      float);
};
} // namespace reo::native::gameplay_scenario
