#include "cutscene_actor_tracks.hpp"
#include "../gameplay_world/linked_models.hpp"
#include <cstring>
#include <stdexcept>
namespace reo::native::gameplay_scenario {
std::shared_ptr<const CutsceneActorStream> CutsceneActorStream::import(std::span<const std::byte> bytes){
    if(bytes.size()%36||bytes.size()/36>CutsceneActorTracks::maximum_records)
        throw std::invalid_argument("Native cutscene actor stream extent unavailable");
    const auto count=bytes.size()/36;
    // Authored empty streams contain one sentinel and remain idle during the
    // scene. A nonterminal event still requires its following inspection.
    if(count==1){std::uint16_t marker;std::memcpy(&marker,bytes.data()+2,2);
        if(marker!=65535)throw std::invalid_argument("Native cutscene actor stream continuation unavailable");}
    auto result=std::shared_ptr<CutsceneActorStream>(new CutsceneActorStream);
    result->records_.resize(count);
    if(!bytes.empty())std::memcpy(result->records_.data(),bytes.data(),bytes.size());
    if(count&&result->frame(count-1)!=65535)throw std::invalid_argument("Native cutscene actor stream lacks terminal record");
    return result;
}
std::span<const std::byte,36> CutsceneActorStream::record(std::size_t index)const{
    if(index>=records_.size())throw std::out_of_range("Native cutscene actor record outside stream");
    return records_[index];
}
std::uint16_t CutsceneActorStream::frame(std::size_t index)const{
    const auto bytes=record(index);std::uint16_t value;std::memcpy(&value,bytes.data()+2,2);return value;
}
CutsceneActorTracks::CutsceneActorTracks(gameplay_world::World& world):world_(world){
    if(world_.closed()||world_.cutscene_tracks_owner_)throw std::invalid_argument("Native cutscene tracks World unavailable or already bound");
    world_.cutscene_tracks_owner_=this;
}
CutsceneActorTracks::~CutsceneActorTracks(){if(running_)std::terminate();(void)close();}
CutsceneTrackStatus CutsceneActorTracks::close()noexcept{
    if(running_)return CutsceneTrackStatus::busy;
    closed_=true;
    if(world_.cutscene_tracks_owner_==this)world_.cutscene_tracks_owner_=nullptr;
    groups_.clear();return CutsceneTrackStatus::completed;
}
std::optional<std::size_t> CutsceneActorTracks::cursor(std::size_t group,std::size_t stream)const noexcept{
    if(closed_||group>=groups_.size()||stream>=7)return{};
    return groups_[group].positions[stream];
}
CutsceneTrackStatus CutsceneActorTracks::install(std::span<const CutsceneActorTrackGroup> groups){
    if(closed_||world_.closed())return CutsceneTrackStatus::closed;
    if(running_||world_.busy())return CutsceneTrackStatus::busy;
    if(groups.size()>capacity)return CutsceneTrackStatus::invalid_input;
    std::size_t count{};
    for(const auto& group:groups){
        if(group.kind>=0&&group.kind<=2&&group.actor){
            const auto actor=world_.resolve(group.actor);
            if(!actor||!actor->scripted)return CutsceneTrackStatus::unavailable;
        }
        for(const auto& stream:group.streams)if(stream){
            if(stream->size()>maximum_records-count)return CutsceneTrackStatus::invalid_input;
            count+=stream->size();
        }
    }
    std::vector<Group> prepared;
    try{
        prepared.reserve(groups.size());
        for(const auto& group:groups){
            Group value;value.binding=group;
            for(unsigned index=0;index<7;++index)if(group.streams[index]&&group.streams[index]->size())value.positions[index]=0;
            prepared.push_back(std::move(value));
        }
    }catch(const std::bad_alloc&){return CutsceneTrackStatus::no_memory;}
    groups_=std::move(prepared);failed_=false;return CutsceneTrackStatus::completed;
}
CutsceneTracksUpdated CutsceneActorTracks::tick(const std::uint32_t& frame,const std::uint8_t& scene,CutsceneSpeech* speech){
    if(closed_||world_.closed())return{CutsceneTrackStatus::closed};
    if(running_||world_.busy())return{CutsceneTrackStatus::busy};
    if(failed_)return{CutsceneTrackStatus::failed};
    auto& pool=world_.linked_models();
    if(pool.closed_)return{CutsceneTrackStatus::unavailable};
    running_=true;world_.updating_=true;pool.updating_=true;
    struct Reset{bool& running;bool& world;bool& pool;~Reset(){pool=false;world=false;running=false;}}reset{running_,world_.updating_,pool.updating_};
    CutsceneTracksUpdated result;std::array<gameplay_actors::EntityId,capacity> related;
    for(std::size_t index=0;index<groups_.size();++index)related[index]=groups_[index].binding.actor;
    try{
        for(auto& group:groups_)for(unsigned index=0;index<7;++index){
            auto& cursor=group.positions[index];if(!cursor)continue;++result.visited;
            const auto& stream=*group.binding.streams[index];
            auto due=stream.frame(*cursor),now=std::uint16_t(frame);
            if(world_.session().clock_mode){due>>=1;now>>=1;}
            if(due!=now)continue;
            ++result.matched;
            if(*cursor+1>=stream.size()){
                failed_=true;result.status=CutsceneTrackStatus::unavailable;return result;
            }
            if(group.binding.kind==0||group.binding.kind==1||group.binding.kind==2){
                const auto status=apply_cutscene_actor_command(world_,group.binding.actor,stream.record(*cursor),
                    std::span(related).first(groups_.size()),scene,speech);
                if(status!=CutsceneCommandStatus::completed){failed_=true;result.status=CutsceneTrackStatus::unavailable;return result;}
                ++result.commands;
            }else ++result.skipped;
            ++*cursor;
            if(stream.frame(*cursor)==65535){cursor.reset();++result.ended;}
        }
    }catch(...){failed_=true;throw;}
    return result;
}
}
