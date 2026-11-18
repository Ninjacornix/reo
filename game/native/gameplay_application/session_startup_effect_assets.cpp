#include "session_startup.hpp"
#include "session_resources.hpp"
#include "session_audio.hpp"
#include "../gameplay_presentation/graphics_state.hpp"
#include "../gameplay_weapon_resources/weapon_resources.hpp"
#include "runtime/assets/virtual_afs.h"
#include <algorithm>
#include <bit>
#include <cstdio>

namespace reo::native::gameplay_application {
namespace {
class StartupSourceView final:public resources::ByteView {
public:
    explicit StartupSourceView(std::shared_ptr<const reo::assets::Source> source):source_(std::move(source)){}
    std::uint64_t size()const noexcept override{return source_->size;}
    resources::ReadResult read(std::uint64_t offset,std::span<std::byte> target)const override{
        if(offset>source_->size||target.size()>source_->size-offset)return{resources::Status::invalid_range,0};
        source_->read(offset,target.size(),target.data());return{resources::Status::ok,target.size()};
    }
private:std::shared_ptr<const reo::assets::Source> source_;
};
std::shared_ptr<const gameplay_weapon_resources::Catalogue> weapon_catalogue(std::shared_ptr<const reo::assets::Source> source){
    if(!source)throw std::invalid_argument("Actual startup weapon asset source unavailable");
    const auto root=reo::assets::table(*source,0,source->size);
    const auto matches=[](const auto& entry){auto name=entry.name;for(auto& c:name)if(c>='A'&&c<='Z')c+='a'-'A';return name=="romdata_usa.afs";};
    const auto entry=std::find_if(root.entries.begin(),root.entries.end(),matches);
    if(entry==root.entries.end()||std::find_if(entry+1,root.entries.end(),matches)!=root.entries.end())throw std::invalid_argument("Actual startup ROM archive unavailable");
    const auto opened=afs_source_range::Archive::open(std::make_shared<StartupSourceView>(std::move(source)),entry->offset,entry->size,1342);
    if(opened.status!=afs_source_range::Status::completed)throw std::invalid_argument("Actual startup weapon ROM view unavailable");
    return gameplay_weapon_resources::Catalogue::prepare_file1_rom(opened.archive);
}
}
bool SessionStartup::bind_graphics(gameplay_presentation::GraphicsState* graphics)noexcept{
    if(!open())return !graphics;
    if(running_||session_.world().busy()||session_.update().busy())return false;
    if(graphics_&&graphics&&graphics_!=graphics)return false;
    graphics_=graphics;return true;
}
bool SessionStartup::bind_audio(SessionAudio* audio)noexcept{
    if(!open())return !audio;
    if(running_||session_.world().busy()||session_.update().busy())return false;
    if(audio&&!audio->bound_to(session_.world()))return false;
    if(audio_&&audio&&audio_!=audio)return false;
    audio_=audio;return true;
}
gameplay_world::PrimaryStartupStatus SessionStartup::load_scenario_effects()noexcept{
    using Status=gameplay_world::PrimaryStartupStatus;
    auto& world=session_.world();auto* resources=session_.resources();
    if(!open())return Status::closed;
    if(!running_||!world.busy()||!resources||!resources->bound_to(session_)||!graphics_||
       !world.scenario||!world.session().asset_loading_mode||!*world.session().asset_loading_mode||
       !graphics_->frontend_draw_controls())
        return Status::unavailable;
    auto& visuals=resources->visuals();
    //1D1034 releases resource2000 before selector writes or new file reads.
    // Existing work retains its immutable native lease; future constructors
    // cannot silently keep using the retired publication after a failed load.
    if(!visuals.replace_bank({}))return Status::busy;
    effect_bank_.reset();effect_geometry_.reset();effect_model_bytes_.reset();
    graphics_->select_format(2);graphics_->select_model_color(0);
    graphics_->select_option_12(0);if(!graphics_->select_model_draw_controls(false))return Status::unavailable;
    try{
        char model_name[24],data_name[32];
        // Source1D1030 uses full scenario halfword;1CE110's selector maps the
        // packed scenario key to its actual retained archive member.
        const auto scenario=*world.scenario;
        const int model_count=std::snprintf(model_name,sizeof model_name,"ef%02u.nbd",unsigned(scenario));
        const int data_count=std::snprintf(data_name,sizeof data_name,"efdata%02u.bin",unsigned(scenario));
        if(model_count<0||std::size_t(model_count)>=sizeof model_name||data_count<0||std::size_t(data_count)>=sizeof data_name)return Status::unavailable;
        const auto model=session_.archive().read_resource(scenario,model_name);
        if(!model)return Status::unavailable;
        effect_geometry_=gameplay_effects::Geometry::import_nbd(*model);
        effect_model_bytes_=model;
        //1D1144 publishes the new model/header before resetting the runtime
        // lookup views and attempting efdata. A missing warm efdata leaves
        // the previous immutable bytes, matching the source's conditional copy.
        const auto data=session_.archive().read_resource(scenario,data_name);
        if(data)effect_data_bytes_=data;
        if(!effect_data_bytes_)return Status::unavailable;
        const auto bank=gameplay_effects::EffectBank::import(*effect_model_bytes_,*effect_data_bytes_);
        if(!visuals.replace_bank(bank))return Status::busy;
        effect_bank_=bank;return Status::completed;
    }catch(const std::bad_alloc&){return Status::no_memory;}
    catch(...){return Status::unavailable;}
}
gameplay_world::PrimaryStartupStatus SessionStartup::load_scenario_objects()noexcept{
    using Status=gameplay_world::PrimaryStartupStatus;
    auto& world=session_.world();auto* resources=session_.resources();
    if(!open())return Status::closed;
    if(!running_||!world.busy()||!resources||!resources->bound_to(session_)||!graphics_||
       !world.scenario||!world.session().asset_loading_mode||!*world.session().asset_loading_mode||
       !graphics_->frontend_draw_controls())return Status::unavailable;
    auto& factory=resources->factory();
    //1D0B84 releases the old2A00 bank before changing import selectors. The
    // already published effect bank is independent and remains current.
    if(!factory.replace_static_assets({}))return Status::busy;
    object_models_.reset();
    graphics_->select_format(2);graphics_->select_model_color(0x800);
    graphics_->select_option_12(0x8000);if(!graphics_->select_model_draw_controls(true))return Status::unavailable;
    try{
        //1D0B70 receives a byte scenario argument; its formatting and packed
        // archive selector both observe that low byte, unlike1D1030's halfword.
        const auto scenario=std::uint8_t(*world.scenario);
        char name[24];const int count=std::snprintf(name,sizeof name,"objS%02u.nbd",unsigned(scenario));
        if(count<0||std::size_t(count)>=sizeof name)return Status::unavailable;
        const auto bytes=session_.archive().read_resource(scenario,name);if(!bytes)return Status::unavailable;
        const auto models=gameplay_world::ResourceStaticAssets::import_nbd(*bytes);
        if(!factory.replace_static_assets(models))return Status::busy;
        object_models_=models;return Status::completed;
    }catch(const std::bad_alloc&){return Status::no_memory;}
    catch(...){return Status::unavailable;}
}
gameplay_world::PrimaryStartupStatus SessionStartup::load_actor_resources(gameplay_world::PrimaryStartupWork work,
    const gameplay_world::actors::EntityId& id)noexcept{
    using Status=gameplay_world::PrimaryStartupStatus;using Work=gameplay_world::PrimaryStartupWork;
    auto& world=session_.world();
    if(!open())return Status::closed;
    if(!running_||!world.busy())return Status::unavailable;
    const auto actor=world.resolve(id);
    if(!actor||actor->slot>=gameplay_world::World::primary_capacity||world.primary(actor->slot)!=actor)return Status::unavailable;
    try{
        char name[32];unsigned port{};int count{};
        if(work==Work::actor_equipment){
            //1D3A88 exits before requiring descriptors, WMD or audio whenFF.
            if(actor->selected_resource==255)return Status::completed;
            const auto* resources=session_.resources();if(!resources||!resources->bound_to(session_))return Status::unavailable;
            auto& descriptors=session_.resources()->descriptors();const auto selected=descriptors.slot(actor->selected_resource);
            const auto descriptor=selected?descriptors.get(*selected):std::nullopt;if(!descriptor)return Status::unavailable;
            // Complete5B4CE0's inactive andFF-template branches return signed-1.
            if(!descriptor->active||descriptor->template_index==255)return Status::completed;
            const auto& templates=resources->templates().state().templates;
            if(descriptor->template_index>=templates.size())return Status::unavailable;
            const auto kind=std::bit_cast<std::int8_t>(std::to_integer<std::uint8_t>(templates[descriptor->template_index].encoded[14]));
            if(kind==-1)return Status::completed;
            //6B4AE0 publishes a cleared per-slot WMD before its optional read.
            // The same actor.weapon_programs is consumed by WorldResourcePrograms
            // and ResourceFrames; no private startup playback copy is created.
            actor->weapon_programs=animation::WeaponProgramBank::import({});
            if(actor->selected_resource){
                if(!weapon_programs_)weapon_programs_=weapon_catalogue(source_);
                const auto bank=weapon_programs_->find(kind);if(!bank)return Status::unavailable;
                actor->weapon_programs=bank;
            }
            count=std::snprintf(name,sizeof name,"weapon%02d.snd",int(kind));port=unsigned(actor->slot)+8;
        }else if(work==Work::actor_secondary_resources){
            count=std::snprintf(name,sizeof name,"pl%02u_voi.snd",unsigned(actor->character));port=unsigned(actor->slot)+4;
        }else return Status::unavailable;
        if(count<0||std::size_t(count)>=sizeof name||!audio_||!audio_->bound_to(world))return Status::unavailable;
        const auto loaded=audio_->load_named(std::string_view(name,std::size_t(count)),port);
        switch(loaded.status){
        case SessionAudioLoadStatus::completed:return Status::completed;
        case SessionAudioLoadStatus::not_found:return Status::completed; // authoritative1AB310<0 gate, no port mutation
        case SessionAudioLoadStatus::busy:return Status::busy;
        case SessionAudioLoadStatus::closed:return Status::closed;
        default:return Status::unavailable;
        }
    }catch(const std::bad_alloc&){return Status::no_memory;}
    catch(...){return Status::unavailable;}
}
}
