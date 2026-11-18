#pragma once
#include "../gameplay_presentation/frontend_assets.hpp"
#include "../gameplay_world/world.hpp"
#include <string>
namespace reo::assets {struct Source;}
namespace reo::native::gameplay_application {
class SessionStartup;
class NativeSession;
enum class StartupTextureStatus {completed,busy,closed,unavailable,invalid_asset,no_memory};
struct StartupTextureBinding {
    std::uint32_t id{};
    std::string name;
    std::shared_ptr<const gameplay_presentation::Texture> texture;
    std::shared_ptr<const std::vector<std::byte>> encoded;
    std::uint16_t physical_slot{};
    std::int16_t references{1};
};
// Native identities replace341640's resource pointers. Construction establishes
// no loaded resource0: only the actual1D1FC0 frontend publication binds it.
class StartupTextureRegistry final {
public:
    StartupTextureRegistry(gameplay_world::World&,std::shared_ptr<const reo::assets::Source>)noexcept;
    bool bound_to(const gameplay_world::World&)const noexcept;
    bool busy()const noexcept{return running_;}
    std::shared_ptr<const gameplay_presentation::Texture> texture(std::uint32_t id)const noexcept;
    std::span<const StartupTextureBinding> bindings()const noexcept{return bindings_;}
    StartupTextureStatus load_game_etc()noexcept; //complete1D2550 ->1CDE10(0,2500)
    StartupTextureStatus release_cockpit_pair()noexcept; // 1CD080(2600,2)
    StartupTextureStatus load_scenario_common(NativeSession&)noexcept; // 1D2050
    StartupTextureStatus close()noexcept;
private:
    friend class SessionStartup;
    bool insert_binding(StartupTextureBinding);
    StartupTextureStatus bind_common(std::shared_ptr<const gameplay_presentation::CommonFrontendTextures>)noexcept;
    gameplay_world::World& world_;
    std::shared_ptr<const reo::assets::Source> source_;
    std::shared_ptr<const gameplay_presentation::CommonFrontendTextures> common_;
    std::vector<StartupTextureBinding> bindings_;
    bool running_{},closed_{};
};
}
