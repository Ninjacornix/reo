#include "weapon_resources.hpp"
#include "../resources/resource_session.hpp"
#include <bit>
#include <cstdio>
#include <stdexcept>
namespace reo::native::gameplay_weapon_resources {
std::shared_ptr<const Catalogue> Catalogue::prepare_file1_rom(std::shared_ptr<const afs_source_range::Archive> rom){
    if(!rom||rom->count()!=1342)throw std::invalid_argument("Native weapon resources require the admitted File1 ROM archive");
    constexpr std::array<std::int8_t,16> selectors{0,1,2,4,5,7,8,9,12,18,22,23,24,25,26,51};
    auto result=std::shared_ptr<Catalogue>(new Catalogue);result->cleared_=animation::WeaponProgramBank::import({});resources::ResourceSession reads({2048,1,UINT64_MAX});
    for(unsigned i=0;i<selectors.size();++i){
        const auto member=rom->member(1260+i);
        if(member.status!=afs_source_range::Status::completed||!member.view||!member.entry.logical_bytes||member.entry.logical_bytes>2048)throw std::invalid_argument("Native weapon archive member unavailable");
        const auto opened=reads.open(member.view);if(opened.status!=resources::Status::ok)throw std::runtime_error("Native weapon source open failed");
        std::vector<std::byte> bytes(member.entry.logical_bytes);const auto read=reads.read_exact(opened.handle,0,bytes);const auto closed=reads.close(opened.handle);
        if(read.status!=resources::Status::ok||read.bytes!=bytes.size()||closed!=resources::Status::ok)throw std::runtime_error("Native weapon source read failed");
        result->banks_[unsigned(selectors[i])]=animation::WeaponProgramBank::import(bytes);
    }
    return result;
}
std::shared_ptr<const animation::WeaponProgramBank> Catalogue::find(std::int8_t selector)const noexcept{
    return selector<0?nullptr:banks_[unsigned(selector)];
}
Owner::Owner(gameplay_world::World& world,gameplay_scenario::SceneResources& resources,
    const gameplay_scenario::ResourceTemplates& templates,std::shared_ptr<const Catalogue> catalogue,
    std::shared_ptr<gameplay_audio::Owner> audio,gameplay_bank_loading::Loader& loader)
    :world_(world),resources_(resources),templates_(templates),catalogue_(std::move(catalogue)),audio_(std::move(audio)),loader_(loader){
    if(world_.closed()||!catalogue_||!audio_||!audio_->bound_to(world_.session().random)||!loader_.bound_to(*audio_))throw std::invalid_argument("Native weapon resource owners missing or foreign");
}
bool Owner::bound_to(const gameplay_world::World& world,const gameplay_scenario::SceneResources& resources,
    const gameplay_scenario::ResourceTemplates& templates)const noexcept{return (&world_==&world)&&(&resources_==&resources)&&(&templates_==&templates);}
Refreshed Owner::refresh(const gameplay_actors::EntityId& id)noexcept{
    if(world_.closed())return{Status::closed,false,{}};
    const auto actor=world_.resolve(id);if(!actor)return{Status::foreign_or_stale,false,{}};
    if(actor->selected_resource==255)return{Status::completed,false,{}};
    bool changed{};
    try{
        const auto resource=resources_.slot(actor->selected_resource);const auto descriptor=resource?resources_.get(*resource):std::nullopt;
        if(!descriptor)return{};
        if(!descriptor->active||descriptor->template_index==255)return{Status::completed,false,{}};
        if(descriptor->template_index>=templates_.state().templates.size())return{};
        const auto selector=std::bit_cast<std::int8_t>(std::to_integer<std::uint8_t>(templates_.state().templates[descriptor->template_index].encoded[14]));
        if(selector==-1)return{Status::completed,false,{}};
        if(actor->slot>=4||world_.primary(actor->slot)!=actor)return{};
        actor->weapon_programs=catalogue_->cleared();changed=true;
        if(actor->selected_resource){const auto bank=catalogue_->find(selector);if(!bank)return{Status::unavailable,true,{}};actor->weapon_programs=bank;}
        if(world_.session().sound_loading_mode==2)return{Status::completed,true,{}};
        std::array<char,32> name{};const auto length=std::snprintf(name.data(),name.size(),"weapon%02d",int(selector));if(length<0||unsigned(length)>=name.size())return{Status::unavailable,true,{}};
        return{Status::completed,true,loader_.enqueue(std::string_view(name.data(),std::size_t(length)),unsigned(actor->slot)+8)};
    }catch(const std::exception&){return{Status::unavailable,changed,{}};}
}
}
