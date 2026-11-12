#include "cutscene_object_tracks.hpp"
#include "cutscene_descriptor.hpp"
#include <cstring>
#include <stdexcept>
namespace reo::native::gameplay_scenario {
namespace {
template<class T>T read(std::span<const std::byte> bytes,unsigned at){T value;std::memcpy(&value,bytes.data()+at,sizeof value);return value;}
}
std::vector<CutsceneObjectTrackGroup> CutsceneDescriptor::object_tracks(std::span<const CutsceneObjectBinding> bindings)const{
    if(bindings.size()!=objects_.size()||bindings.size()>CutsceneObjectTracks::capacity)throw std::invalid_argument("Native cutscene object binding cardinality unavailable");
    std::vector<CutsceneObjectTrackGroup> result;result.reserve(bindings.size());
    for(unsigned index=0;index<bindings.size();++index){
        CutsceneObjectTrackGroup group;group.object=bindings[index].object;group.attachment_scale=bindings[index].attachment_scale;
        for(unsigned stream=0;stream<7;++stream)group.streams[stream]=CutsceneActorStream::import(section(objects_[index][stream]));
        result.push_back(std::move(group));
    }
    return result;
}
CutsceneObjectTracks::CutsceneObjectTracks(gameplay_world::World& world):world_(world){
    if(world_.closed()||world_.cutscene_object_tracks_owner_)throw std::invalid_argument("Native cutscene object tracks World unavailable or already bound");
    world_.cutscene_object_tracks_owner_=this;
}
CutsceneObjectTracks::~CutsceneObjectTracks(){if(running_)std::terminate();(void)close();}
CutsceneTrackStatus CutsceneObjectTracks::close()noexcept{
    if(running_||(!world_.closed()&&world_.busy()))return CutsceneTrackStatus::busy;
    const bool previous=world_.updating_;running_=world_.updating_=true;
    struct Reset{bool& a;bool& b;bool previous;~Reset(){b=previous;a=false;}}reset{running_,world_.updating_,previous};
    closed_=true;if(world_.cutscene_object_tracks_owner_==this)world_.cutscene_object_tracks_owner_=nullptr;
    groups_.clear();actors_.clear();return CutsceneTrackStatus::completed;
}
std::optional<std::size_t> CutsceneObjectTracks::cursor(std::size_t group,std::size_t stream)const noexcept{
    if(closed_||group>=groups_.size()||stream>=7)return{};
    return groups_[group].positions[stream];
}
CutsceneTrackStatus CutsceneObjectTracks::install(std::span<const CutsceneObjectTrackGroup> groups,std::span<const gameplay_actors::EntityId> actors){
    if(closed_||world_.closed())return CutsceneTrackStatus::closed;
    if(running_||world_.busy())return CutsceneTrackStatus::busy;
    if(groups.size()>capacity||actors.size()>CutsceneActorTracks::capacity)return CutsceneTrackStatus::invalid_input;
    std::size_t count{};
    for(const auto& id:actors)if(id&&!world_.resolve(id))return CutsceneTrackStatus::unavailable;
    try{
        if(!groups.empty()){
            auto& pool=world_.cinematic_objects();
            for(unsigned index=0;index<groups.size();++index)if(!groups[index].object||groups[index].object!=pool.identity_at(index)||!pool.resolve(groups[index].object))return CutsceneTrackStatus::unavailable;
        }
        std::vector<Group> prepared;prepared.reserve(groups.size());
        for(const auto& group:groups){Group next;next.binding=group;
            for(unsigned stream=0;stream<7;++stream)if(group.streams[stream]){
                if(group.streams[stream]->size()>CutsceneActorTracks::maximum_records-count)return CutsceneTrackStatus::invalid_input;
                count+=group.streams[stream]->size();if(group.streams[stream]->size())next.positions[stream]=0;
            }
            prepared.push_back(std::move(next));
        }
        std::vector<gameplay_actors::EntityId> prepared_actors(actors.begin(),actors.end());
        running_=world_.updating_=true;
        struct Reset{bool& a;bool& b;~Reset(){b=false;a=false;}}reset{running_,world_.updating_};
        groups_=std::move(prepared);actors_=std::move(prepared_actors);failed_=false;return CutsceneTrackStatus::completed;
    }catch(const std::bad_alloc&){return CutsceneTrackStatus::no_memory;}
}
CutsceneTracksUpdated CutsceneObjectTracks::tick(const std::uint32_t& media_frame){
    if(closed_||world_.closed())return{CutsceneTrackStatus::closed};
    if(running_||world_.busy())return{CutsceneTrackStatus::busy};
    if(failed_)return{CutsceneTrackStatus::failed};
    if(groups_.empty())return{};
    auto& pool=world_.cinematic_objects();running_=world_.updating_=true;
    struct Reset{bool& a;bool& b;~Reset(){b=false;a=false;}}reset{running_,world_.updating_};
    CutsceneTracksUpdated result;
    const auto unavailable=[&]{failed_=true;result.status=CutsceneTrackStatus::unavailable;return result;};
    try{
        for(auto& group:groups_)for(unsigned stream_index=0;stream_index<7;++stream_index){
            auto& cursor=group.positions[stream_index];if(!cursor)continue;++result.visited;
            const auto& stream=*group.binding.streams[stream_index];auto due=stream.frame(*cursor),now=std::uint16_t(media_frame);
            if(world_.session().clock_mode){due>>=1;now>>=1;}
            if(due!=now)continue;
            ++result.matched;if(*cursor+1>=stream.size())return unavailable();
            const auto output=pool.resolve(group.binding.object);if(!output)return unavailable();
            const auto event=stream.record(*cursor);const auto kind=read<std::uint8_t>(event,1);
            if(kind==0){
                output->active=output->visible=true;std::array<std::byte,72> pair;
                std::memcpy(pair.data(),event.data(),36);const auto next=stream.record(*cursor+1);std::memcpy(pair.data()+36,next.data(),36);
                const auto pose=gameplay_world::CinematicObjectPose::read(pair);auto initial=pose;initial.end=65535;
                gameplay_world::evaluate_cinematic_object_pose(initial,0,output->position,output->angles);output->pose=pose;output->flags|=2;
            }else if(kind==1)output->visible=std::uint8_t(read<std::uint32_t>(event,4))!=0;
            else if(kind==2){output->flags|=1;output->motion=read<std::uint32_t>(event,4);}
            else if(kind==3){
                const auto encoded_node=read<std::uint32_t>(event,4);
                if(encoded_node){
                    std::shared_ptr<animation::Instance> model;animation::Vector scale;
                    const auto index=read<std::uint32_t>(event,32);
                    if(read<std::uint32_t>(event,8)){
                        if(index>=groups_.size()||!groups_[index].binding.attachment_scale)return unavailable();
                        const auto parent=pool.resolve(pool.identity_at(index));if(!parent||!parent->model)return unavailable();
                        model=parent->model;scale=*groups_[index].binding.attachment_scale;
                    }else{
                        if(index>=actors_.size())return unavailable();
                        const auto parent=world_.resolve(actors_[index]);if(!parent||!parent->model)return unavailable();
                        model=parent->model;scale={parent->model_scale.x,parent->model_scale.y,parent->model_scale.z};
                    }
                    gameplay_world::attach_cinematic_object(*output,*model,encoded_node-1,scale,gameplay_world::CinematicObjectAttachment::read(event));
                }
            }else ++result.skipped;
            ++result.commands;++*cursor;
            if(stream.frame(*cursor)==65535){cursor.reset();++result.ended;}
        }
    }catch(...){failed_=true;throw;}
    return result;
}
}
