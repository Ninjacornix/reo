#include "cutscene_lights.hpp"
#include "cutscene_playback.hpp"
#include "scenario_archive.hpp"
#include <cstdio>
#include <new>
namespace reo::native::gameplay_scenario {
CutsceneRoomLightingLoaded CutsceneLights::load_room(const content::ScenarioArchive& archive)noexcept{
    if(running_||world_.busy())return{CutsceneLightsStatus::busy};
    if(world_.closed())return{CutsceneLightsStatus::closed};
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    CutsceneRoomLightingLoaded result;
    try{
        const auto& session=world_.session();
        if(!session.asset_loading_mode||!session.scenario||!session.room_variant)return result;
        if(*session.asset_loading_mode&&*session.scenario!=1&&*session.scenario!=2&&
           *session.scenario!=28&&*session.scenario!=35&&*session.scenario!=41&&*session.scenario!=65535)
            return result;
        // Mode0 selects the default1342-key catalogue. Its actual compiled
        // names contain no room LIG/FOG key, so both positive-read gates fail.
        // The unconditional6B3830 initialization below still executes.
        if(*session.asset_loading_mode){
            std::array<char,128> name{};
            std::snprintf(name.data(),name.size(),"r%03u%02u%02u.lig",
                unsigned(*session.scenario),unsigned(world_.room),unsigned(*session.room_variant));
            if(const auto bytes=archive.read_resource_sectors(*session.scenario,name.data())){
                result.lighting_read=true;result.lighting_import=lights_.import_lig(*bytes);
                // Version4's complete6B1DC0 also invalidates the shared fog
                // selection. Apply that cross-owner effect before FOG import.
                if(*result.lighting_import==LightingImport::completed)fog_.reset_selection();
            }
            std::snprintf(name.data(),name.size(),"r%03u%02u%02u.fog",
                unsigned(*session.scenario),unsigned(world_.room),unsigned(*session.room_variant));
            if(const auto bytes=archive.read_resource_sectors(*session.scenario,name.data())){
                result.fog_read=true;result.fog_import=fog_.import_fog(*bytes);
                if(*result.fog_import!=FogStatus::completed&&*result.fog_import!=FogStatus::unsupported_version)
                    return result;
            }
        }
        result.status=initialize_impl();result.initialized=result.status==CutsceneLightsStatus::completed;
        return result;
    }catch(const std::bad_alloc&){result.status=CutsceneLightsStatus::no_memory;return result;}
    catch(...){return result;}
}
} // namespace reo::native::gameplay_scenario
