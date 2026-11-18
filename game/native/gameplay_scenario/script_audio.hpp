#pragma once
#include "../gameplay_audio/owner.hpp"
#include "../gameplay_world/world.hpp"
namespace reo::native::gameplay_scenario {
// Script73 ->1B8930. The actual World owns scenario identity, RNG and the
// remembered cue; this frontend only borrows the bank owner and camera context.
class ScriptAudio final {
public:
    ScriptAudio(gameplay_world::World&,gameplay_audio::Owner&,const gameplay_audio::SpatialContext&);
    bool bound_to(const gameplay_world::World&)const noexcept;
    bool ready(std::uint32_t event,std::uint32_t mode,std::uint32_t actor=0)const noexcept;
    bool command(std::uint32_t event,std::uint32_t mode,std::uint32_t actor=0,
                 std::array<std::int32_t,3> coordinates={})noexcept;
    bool play(std::uint32_t event,std::optional<gameplay_audio::Vector> position={})noexcept;
    const std::optional<gameplay_audio::Result>& last_result()const noexcept{return last_;}
private:
    gameplay_world::World& world_;
    gameplay_audio::Owner& owner_;
    const gameplay_audio::SpatialContext& spatial_;
    std::optional<gameplay_audio::Result> last_;
};
}
