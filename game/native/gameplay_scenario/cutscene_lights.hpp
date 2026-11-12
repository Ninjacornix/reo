#pragma once
#include "cutscene_light_curves.hpp"
#include "fog.hpp"
#include "cutscene_descriptor.hpp"
#include "../gameplay_contact_world/contacts.hpp"
namespace reo::native::gameplay_scenario {
struct CutscenePlaybackState;
struct LightKeyLocation {std::size_t group{},stream{},record{};friend bool operator==(const LightKeyLocation&,const LightKeyLocation&)=default;};
class PreparedLightTracks final {
public:
    static std::shared_ptr<const PreparedLightTracks> import(std::span<const std::array<std::span<const std::byte>,2>>);
    const auto& streams()const noexcept{return streams_;}
private:std::vector<std::array<std::vector<CutsceneLightKey>,2>> streams_;
};
std::shared_ptr<const PreparedLightTracks> prepare_light_tracks(const CutsceneDescriptor&);
enum class CutsceneLightsStatus {completed,busy,closed,unavailable,no_memory};
struct CutsceneLightsUpdated {CutsceneLightsStatus status{CutsceneLightsStatus::completed};std::size_t visited{},bound{},sampled{};};
// Sole original747430/747420 binding owner over the actual Lighting pools.
// Curve reset6B38D0 does not release physical lights. Pool reset is still owned
// by Lighting; its generation/epoch invalidates these handles and all borrowers.
class CutsceneLights final {
public:
    CutsceneLights(gameplay_world::World&,CutscenePlaybackState&,Lighting&,Fog&,
                   gameplay_contact_world::RoomResources&);
    ~CutsceneLights();
    CutsceneLights(const CutsceneLights&)=delete;
    CutsceneLights& operator=(const CutsceneLights&)=delete;
    CutsceneLightsStatus initialize()noexcept; // complete6B3830
    CutsceneLightsStatus install(std::shared_ptr<const PreparedLightTracks>)noexcept;
    CutsceneLightsStatus clear_bindings()noexcept; // complete6B38D0
    CutsceneLightsUpdated tick()noexcept; // complete5EF640/6B3900
    CutsceneLightsUpdated sample(std::int8_t group)noexcept; // complete6B3BB0
    bool bound_to(const gameplay_world::World&,const CutscenePlaybackState&)const noexcept;
    bool busy()const noexcept{return running_;}
    std::optional<std::size_t> cursor(std::size_t group,std::size_t stream)const noexcept;
    const auto& bindings()const noexcept{return bindings_;}
    std::optional<NativeLight> light(std::size_t)const noexcept;
    std::optional<NativeLight> mirror()const noexcept;
private:
    friend class CutscenePlayback;
    gameplay_world::World& world_;CutscenePlaybackState& state_;Lighting& lights_;Fog& fog_;
    gameplay_contact_world::RoomResources& rooms_;
    std::array<std::optional<LightHandle>,32> physical_;
    std::optional<AuxiliaryLightHandle> mirror_;
    std::array<std::array<std::optional<LightKeyLocation>,2>,32> bindings_;
    std::shared_ptr<const PreparedLightTracks> tracks_;
    std::vector<std::array<std::optional<std::size_t>,2>> cursors_;
    std::uint64_t physical_epoch_{};
    bool running_{};
    const CutsceneLightKey* key(LightKeyLocation)const noexcept;
    std::optional<std::uint8_t> material(transform_math::Vector);
    CutsceneLightsStatus bind(LightKeyLocation);
};
} // namespace reo::native::gameplay_scenario
