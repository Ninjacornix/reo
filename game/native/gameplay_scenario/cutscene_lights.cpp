#include "cutscene_lights.hpp"
#include "cutscene_playback.hpp"
#include <cstring>
#include <stdexcept>
namespace reo::native::gameplay_scenario {
namespace {
template<class T>T field(std::span<const std::byte> bytes,std::size_t at){T value;std::memcpy(&value,bytes.data()+at,sizeof value);return value;}
CutsceneLightKey decode(std::span<const std::byte> bytes){
    CutsceneLightKey key;key.enabled=field<std::int8_t>(bytes,1);key.frame=field<std::uint16_t>(bytes,2);key.flags=field<std::uint16_t>(bytes,4);key.binding=field<std::int16_t>(bytes,6);
    key.point=field<transform_math::Vector>(bytes,8);key.control=field<transform_math::Vector>(bytes,20);key.radius=field<float>(bytes,32);key.extra=field<float>(bytes,44);
    key.first=field<std::array<std::uint8_t,3>>(bytes,36);key.second=field<std::array<std::uint8_t,3>>(bytes,40);return key;
}
struct Reset {bool& running;~Reset(){running=false;}};
}
std::shared_ptr<const PreparedLightTracks> PreparedLightTracks::import(std::span<const std::array<std::span<const std::byte>,2>> groups){
    if(groups.size()>32)throw std::invalid_argument("Native cinematic light group profile exceeded");
    auto result=std::shared_ptr<PreparedLightTracks>(new PreparedLightTracks);result->streams_.resize(groups.size());
    for(std::size_t group=0;group<groups.size();++group)for(unsigned stream=0;stream<2;++stream){
        const auto bytes=groups[group][stream];if(bytes.size()%48||bytes.size()/48>65535)throw std::invalid_argument("Native light stream extent unavailable");
        auto& keys=result->streams_[group][stream];keys.reserve(bytes.size()/48);
        for(std::size_t at=0;at<bytes.size();at+=48)keys.push_back(decode(bytes.subspan(at,48)));
        if(!keys.empty()&&keys.back().frame!=65535)throw std::invalid_argument("Native light stream terminal unavailable");
    }
    return result;
}
std::shared_ptr<const PreparedLightTracks> prepare_light_tracks(const CutsceneDescriptor& descriptor){
    std::vector<std::array<std::span<const std::byte>,2>> streams;
    if(descriptor.extension_groups())for(const auto& group:*descriptor.extension_groups())streams.push_back({descriptor.section(group[0]),descriptor.section(group[1])});
    return PreparedLightTracks::import(streams);
}
CutsceneLights::CutsceneLights(gameplay_world::World& world,CutscenePlaybackState& state,Lighting& lights,Fog& fog,
    gameplay_contact_world::RoomResources& rooms):world_(world),state_(state),lights_(lights),fog_(fog),rooms_(rooms){
    if(world.closed()||world.busy()||!lights.register_cutscene(this))throw std::invalid_argument("Native cinematic light owner unavailable or already registered");
}
CutsceneLights::~CutsceneLights(){if(running_)std::terminate();lights_.unregister_cutscene(this);}
bool CutsceneLights::bound_to(const gameplay_world::World& world,const CutscenePlaybackState& state)const noexcept{return &world_==&world&&&state_==&state&&lights_.owns_cutscene(this);}
CutsceneLightsStatus CutsceneLights::initialize()noexcept{
    if(running_||world_.busy())return CutsceneLightsStatus::busy;
    if(world_.closed())return CutsceneLightsStatus::closed;
    running_=true;Reset reset{running_};return initialize_impl();
}
CutsceneLightsStatus CutsceneLights::initialize_impl()noexcept{
    lights_.select(0);for(unsigned index=0;index<32;++index)(void)lights_.create(std::uint8_t(index));
    const auto selected=fog_.select(0);if(selected!=FogStatus::completed)return CutsceneLightsStatus::unavailable;
    physical_epoch_=lights_.reset_epoch();
    for(unsigned index=0;index<32;++index){const auto slot=lights_.allocate(nullptr,0,3);physical_[index]=slot?lights_.handle(*slot):std::nullopt;}
    mirror_=lights_.allocate_auxiliary(nullptr,0);return CutsceneLightsStatus::completed;
}
CutsceneLightsStatus CutsceneLights::install(std::shared_ptr<const PreparedLightTracks> tracks)noexcept{
    if(running_||world_.busy())return CutsceneLightsStatus::busy;
    if(world_.closed())return CutsceneLightsStatus::closed;
    if(!tracks)return CutsceneLightsStatus::unavailable;
    try{std::vector<std::array<std::optional<std::size_t>,2>> cursors(tracks->streams().size());
        for(std::size_t group=0;group<cursors.size();++group)for(unsigned stream=0;stream<2;++stream)if(!tracks->streams()[group][stream].empty())cursors[group][stream]=0;
        tracks_=std::move(tracks);cursors_=std::move(cursors);bindings_={};return CutsceneLightsStatus::completed;
    }catch(const std::bad_alloc&){return CutsceneLightsStatus::no_memory;}
}
CutsceneLightsStatus CutsceneLights::clear_bindings()noexcept{if(running_||world_.busy())return CutsceneLightsStatus::busy;
    if(world_.closed())return CutsceneLightsStatus::closed;
    bindings_={};return CutsceneLightsStatus::completed;}
std::optional<std::size_t> CutsceneLights::cursor(std::size_t group,std::size_t stream)const noexcept{return group<cursors_.size()&&stream<2?cursors_[group][stream]:std::nullopt;}
std::optional<NativeLight> CutsceneLights::light(std::size_t group)const noexcept{return group<physical_.size()&&physical_[group]?lights_.light(*physical_[group]):std::nullopt;}
std::optional<NativeLight> CutsceneLights::mirror()const noexcept{return mirror_?lights_.light(*mirror_):std::nullopt;}
const CutsceneLightKey* CutsceneLights::key(LightKeyLocation value)const noexcept{
    if(!tracks_||value.group>=tracks_->streams().size()||value.stream>=2)return nullptr;
    const auto& stream=tracks_->streams()[value.group][value.stream];return value.record<stream.size()?&stream[value.record]:nullptr;
}
std::optional<std::uint8_t> CutsceneLights::material(transform_math::Vector point){
    const auto room_number=world_.room;auto room=rooms_.retain(room_number);if(!room||room->room_number()!=room_number)return{};
    const auto identity=room->identity();if(!identity||!room->current(identity))return{};
    const auto result=room->geometry().floors.floor({point.x,point.y,point.z},255).material;
    if(world_.closed()||world_.room!=room_number||!room->current(identity))return{};
    return result;
}
CutsceneLightsStatus CutsceneLights::bind(LightKeyLocation location){
    const auto value=key(location);if(!value)return CutsceneLightsStatus::unavailable;
    bindings_[location.group][value->binding?1:0]=location;
    if(value->binding)return CutsceneLightsStatus::completed;
    const auto slot=physical_[location.group]?lights_.slot(*physical_[location.group]):std::nullopt;
    if(!slot)return CutsceneLightsStatus::unavailable;
    const auto tag=material(value->point);if(!tag)return CutsceneLightsStatus::unavailable;
    if(lights_.slot(*physical_[location.group])!=slot)return CutsceneLightsStatus::unavailable;
    initialize_cutscene_light(lights_.primary_[*slot],*value,*tag);return CutsceneLightsStatus::completed;
}
CutsceneLightsUpdated CutsceneLights::tick()noexcept{
    if(running_||world_.busy())return{CutsceneLightsStatus::busy};
    if(world_.closed())return{CutsceneLightsStatus::closed};
    if(!tracks_)return{CutsceneLightsStatus::unavailable};
    running_=true;Reset reset{running_};CutsceneLightsUpdated result;
    try{if(state_.light_groups<0)return result;if(std::size_t(state_.light_groups)>cursors_.size()){result.status=CutsceneLightsStatus::unavailable;return result;}
        for(std::size_t group=0;group<std::size_t(state_.light_groups);++group)for(unsigned stream=0;stream<2;++stream){
            auto& cursor=cursors_[group][stream];if(!cursor)continue;++result.visited;const auto& records=tracks_->streams()[group][stream];const auto frame=records[*cursor].frame,current=std::uint16_t(state_.frame);
            if(world_.session().clock_mode?(frame>>1)!=(current>>1):frame!=current)continue;
            result.status=bind({group,stream,*cursor});if(result.status!=CutsceneLightsStatus::completed)return result;++result.bound;
            const auto next=*cursor+1;if(next>=records.size()){result.status=CutsceneLightsStatus::unavailable;return result;}cursor=records[next].frame==65535?std::nullopt:std::optional(next);
        }
        return result;
    }catch(const std::bad_alloc&){result.status=CutsceneLightsStatus::no_memory;return result;}catch(...){result.status=CutsceneLightsStatus::unavailable;return result;}
}
CutsceneLightsUpdated CutsceneLights::sample(std::int8_t index)noexcept{
    if(running_||world_.busy())return{CutsceneLightsStatus::busy};
    if(world_.closed())return{CutsceneLightsStatus::closed};
    if(index<0||index>=32)return{CutsceneLightsStatus::unavailable};
    running_=true;Reset reset{running_};const auto group=std::size_t(index);CutsceneLightsUpdated result;
    const auto& first=bindings_[group][0];const auto& second=bindings_[group][1];if(!first||!second)return result;
    if(!physical_[group]||physical_epoch_!=lights_.reset_epoch())return result;
    const auto slot=lights_.slot(*physical_[group]);if(!slot){result.status=CutsceneLightsStatus::unavailable;return result;}
    const auto a=key(*first),b=key({first->group,first->stream,first->record+1}),end=key(*second);if(!a||!b||!end){result.status=CutsceneLightsStatus::unavailable;return result;}
    try{const CutsceneLightSegment segment{*a,*b};const auto frame=state_.frame;const auto point=cutscene_light_point(segment,frame);
        lights_.primary_[*slot].descriptor.position={point.x,point.y,point.z};lights_.primary_[*slot].tag=255;
        const auto tag=material(point);if(!tag||lights_.slot(*physical_[group])!=slot){result.status=CutsceneLightsStatus::unavailable;return result;}
        auto& light=lights_.primary_[*slot];const auto mirror=sample_cutscene_light(light,segment,end->enabled,frame,world_.session().clock_mode,*tag);++result.sampled;
        if(mirror){const auto target=mirror_?lights_.auxiliary_slot(*mirror_):std::nullopt;if(!target){light.descriptor.attenuation=mirror->attenuation;result.status=CutsceneLightsStatus::unavailable;return result;}lights_.auxiliary_[*target].tag=light.tag;lights_.auxiliary_[*target].descriptor=*mirror;}
        return result;
    }catch(const std::bad_alloc&){result.status=CutsceneLightsStatus::no_memory;return result;}catch(...){result.status=CutsceneLightsStatus::unavailable;return result;}
}
} // namespace reo::native::gameplay_scenario
