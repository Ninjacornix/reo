#pragma once
#include "../gameplay_world/world.hpp"
#include <span>
namespace reo::native::gameplay_scenario {
struct CutsceneSpeechRequest {
    gameplay_actors::EntityId actor;
    std::uint16_t scenario{},facial{};
    std::uint8_t scene{};
    std::int16_t voice{};
    std::int8_t character{};
};
class CutsceneSpeech {
public:
    virtual ~CutsceneSpeech()=default;
    virtual bool queue_voice(const CutsceneSpeechRequest&)=0;
    virtual bool animate_face(const CutsceneSpeechRequest&)=0;
};
enum class CutsceneCommandStatus {completed,closed,malformed,unavailable};
// One original36-byte authored event. Scene stream selection/cadence belongs
// to its caller; this consumer does not advance clocks or guess actor bindings.
CutsceneCommandStatus apply_cutscene_actor_command(gameplay_world::World&,
    const gameplay_actors::EntityId&,std::span<const std::byte>,
    std::span<const gameplay_actors::EntityId> related={},const std::uint8_t& scene=0,CutsceneSpeech* = nullptr);
}
