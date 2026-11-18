#pragma once
#include "scene_matrix_programs.hpp"
#include "../gameplay_audio/owner.hpp"
#include "../gameplay_world/world.hpp"
namespace reo::native::gameplay_scenario {
// Complete6B60E0 ->1B9360 consumer. Borrows the actual World session and bank
// owner; it never stores a second scenario, sound map or model pose.
class SceneBankAudio final:public SceneMatrixSoundSink {
public:
    SceneBankAudio(gameplay_world::World&,gameplay_audio::Owner&,const gameplay_audio::SpatialContext&);
    bool admitted()const noexcept override;
    bool emit(transform_math::Vector,std::uint8_t,std::uint16_t)override;
    const std::optional<gameplay_audio::Result>& last_result()const noexcept{return last_;}
private:
    gameplay_world::World& world_;
    gameplay_audio::Owner& owner_;
    const gameplay_audio::SpatialContext& spatial_;
    std::optional<gameplay_audio::Result> last_;
};
// Scenario values42+ or resource IDs beyond the ten authored properties do not
// read null pointers, padding or adjacent tables in native code.
std::optional<std::uint8_t> scene_sound_offset(std::uint16_t scenario,std::uint8_t resource)noexcept;
}
