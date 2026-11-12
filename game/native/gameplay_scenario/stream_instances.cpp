#include "stream_instances.hpp"
#include <bit>
#include <atomic>
#include <stdexcept>
#include <utility>

namespace reo::native::resources {
std::shared_ptr<const ByteView> retain_resident_view(std::shared_ptr<const ByteView>,std::string identity);
}
namespace reo::native::gameplay_scenario {
namespace {
std::uint64_t catalog_scope(){
    static std::atomic<std::uint64_t> next{1};auto value=next.load(std::memory_order_relaxed);
    for(;;){if(!value)throw std::length_error("Native stream catalog identity exhausted");
        const auto following=value==UINT64_MAX?0:value+1;
        if(next.compare_exchange_weak(value,following,std::memory_order_relaxed))return value;}
}
StreamStatus mapped(adxt_instances::Status status)noexcept{
    using S=adxt_instances::Status;
    switch(status){case S::completed:return StreamStatus::completed;case S::pending:return StreamStatus::pending;
    case S::closed:return StreamStatus::closed;case S::busy:return StreamStatus::busy;case S::invalid_key:return StreamStatus::unbound;
    case S::unsupported_profile:case S::invalid_input:case S::order_required:return StreamStatus::unsupported_profile;default:return StreamStatus::fault;}
}
StreamStatus admitted(adxt_control_owner::Admission a,StreamStatus result)noexcept{
    return a==adxt_control_owner::Admission::accepted?result:a==adxt_control_owner::Admission::busy?StreamStatus::busy:StreamStatus::closed;
}
template<class F>struct Operation final:adxt_control_owner::Operation {
    F action;explicit Operation(F f):action(std::move(f)){}
    void run(adxt_instances::Instances& value)noexcept override{action(value);}
};
}
StreamAssetCatalog::StreamAssetCatalog():scope_id_(catalog_scope()){}
bool StreamAssetCatalog::add(std::uint32_t id,std::shared_ptr<const afs_source_range::Archive> archive,std::string identity){
    if(sealed_||!archive||identity.empty()||identity.size()>512||archives_.size()>=64||archives_.contains(id))return false;
    return archives_.emplace(id,Entry{std::move(archive),std::move(identity)}).second;
}
StreamAsset StreamAssetCatalog::resolve(StreamRequest request)const noexcept{
    if(!sealed_)return{StreamStatus::unsupported_profile,{}};
    const auto found=archives_.find(request.archive);if(found==archives_.end()||request.member<0)return{};
    const auto member=found->second.archive->member(std::uint32_t(request.member));
    if(member.status!=afs_source_range::Status::completed||!member.view||!member.view->size())return{};
    try{
        const auto identity="native-stream-catalog:"+std::to_string(scope_id_)+":"+std::to_string(request.archive)+":"+
            found->second.identity+"@"+std::to_string(member.entry.start_sector)+":"+std::to_string(member.entry.logical_bytes);
        return{StreamStatus::completed,resources::retain_resident_view(member.view,identity)};
    }catch(...){return{StreamStatus::unsupported_profile,{}};}
}
StreamInstances::StreamInstances(std::shared_ptr<adxt_control_owner::Owner> owner,std::array<StreamInstanceConfig,3> config,
    std::shared_ptr<const StreamAssetCatalog> catalog,std::shared_ptr<audio_clip_loader::Loader> voice_loader):owner_(std::move(owner)),config_(std::move(config)),catalog_(std::move(catalog)),voice_loader_(std::move(voice_loader)){}
StreamInstancesOpen StreamInstances::create(std::shared_ptr<adxt_control_owner::Owner> owner,std::array<StreamInstanceConfig,3> config,
    std::shared_ptr<const StreamAssetCatalog> catalog,std::array<std::uint8_t,3> order,std::shared_ptr<audio_clip_loader::Loader> voice_loader)noexcept{
    if(!owner||!catalog||!catalog->sealed())return{StreamStatus::unsupported_profile,{}};
    std::array<bool,3> seen{};for(const auto index:order){if(index>=3||seen[index])return{StreamStatus::unsupported_profile,{}};seen[index]=true;}
    for(const auto& c:config)if(!c.construction.attenuation_table||c.construction.channels<1||c.construction.channels>2||
        c.player.sequence||c.player.lsc_input||c.player.initial_attenuation||
        (c.player.attenuation_table&&c.player.attenuation_table!=c.construction.attenuation_table))return{StreamStatus::unsupported_profile,{}};
    try{
        auto value=std::unique_ptr<StreamInstances>(new StreamInstances(std::move(owner),std::move(config),std::move(catalog),std::move(voice_loader)));
        auto result=StreamStatus::fault;Operation setup([&](auto& players){
            if(players.snapshot().instances){result=StreamStatus::unsupported_profile;return;}
            result=mapped(players.start_output());if(result!=StreamStatus::completed)return;
            for(std::size_t i=0;i<3;++i){const auto opened=players.create(value->config_[i].construction);result=mapped(opened.status);if(result!=StreamStatus::completed)return;value->keys_[i]=opened.key;value->constructed_[i]=true;}
            std::array<adxt_instances::Key,3> permutation;for(std::size_t i=0;i<3;++i)permutation[i]=value->keys_[order[i]];
            result=mapped(players.set_order(permutation));
        });const auto admission=value->owner_->run(setup);result=admitted(admission,result);
        if(result!=StreamStatus::completed)return{result,{}};
        return{result,std::move(value)};
    }catch(...){return{StreamStatus::fault,{}};}
}
StreamInstances::~StreamInstances(){(void)close();}
adxt_instances::Observation StreamInstances::inspect(std::uint8_t index)noexcept{
    adxt_instances::Observation observed;if(closed_||index>=3||!constructed_[index])return observed;
    Operation operation([&](auto& players){observed=players.inspect(keys_[index]);});
    if(owner_->run(operation)!=adxt_control_owner::Admission::accepted)observed.status=adxt_instances::Status::closed;
    return observed;
}
StreamValue StreamInstances::phase(std::uint8_t index)noexcept{
    if(index>=3)return{StreamStatus::invalid_channel,0};
    if(closed_)return{StreamStatus::closed,0};
    if(voice_queues_[index])return queued_phase(index,false);
    const auto observed=inspect(index);const auto status=mapped(observed.status);if(!stream_accepted(status))return{status,0};
    if(!started_[index])return{status,0};
    if(observed.replacement_pending)return{status,1};
    if(!observed.source)return{StreamStatus::fault,0};
    return{status,observed.source->configured?std::int32_t(observed.source->playback.phase):1};
}
StreamStatus StreamInstances::start(std::uint8_t index,StreamRequest request,std::uint32_t tick)noexcept{
    if(index>=3)return StreamStatus::invalid_channel;
    if(closed_)return StreamStatus::closed;
    // Metadata resolution/allocation and resident-view preparation are outside
    // canonical admission. Actual body I/O belongs to the existing source worker.
    const auto asset=catalog_->resolve(request);if(asset.status!=StreamStatus::completed)return asset.status;
    adxt_instances::Source source{config_[index].player,asset.view};source.player.initial_tick=tick;
    source.player.decoder.channels=config_[index].construction.channels;source.player.decoder.source_config.byte_length=std::int32_t(asset.view->size());
    auto retained_queue=voice_queues_[index];
    auto result=StreamStatus::fault;Operation operation([&](auto& players){if(voice_queues_[index]){result=retire_queue(index,players);if(!stream_accepted(result))return;}result=mapped(players.start(keys_[index],std::move(source)));});
    const auto admission=owner_->run(operation);result=admitted(admission,result);if(stream_accepted(result))started_[index]=true;return result;
}
StreamStatus StreamInstances::stop(std::uint8_t index)noexcept{
    if(index>=3)return StreamStatus::invalid_channel;
    if(closed_)return StreamStatus::closed;
    auto retained_queue=voice_queues_[index];
    auto result=StreamStatus::fault;Operation operation([&](auto& players){result=voice_queues_[index]?retire_queue(index,players):mapped(players.stop(keys_[index]));});
    const auto admission=owner_->run(operation);result=admitted(admission,result);if(stream_accepted(result))started_[index]=false;return result;
}
StreamStatus StreamInstances::pause(std::uint8_t index,bool value,std::uint32_t tick)noexcept{
    if(index>=3)return StreamStatus::invalid_channel;
    if(closed_)return StreamStatus::closed;
    auto result=StreamStatus::fault;Operation operation([&](auto& players){result=mapped(players.pause(keys_[index],value?1:0,tick));});const auto admission=owner_->run(operation);return admitted(admission,result);
}
StreamStatus StreamInstances::attenuation(std::uint8_t index,std::int32_t value)noexcept{
    if(index>=3)return StreamStatus::invalid_channel;
    if(closed_)return StreamStatus::closed;
    auto result=StreamStatus::fault;Operation operation([&](auto& players){result=mapped(players.attenuation(keys_[index],std::bit_cast<std::uint32_t>(value)));});const auto admission=owner_->run(operation);return admitted(admission,result);
}
StreamValue StreamInstances::instance_available(std::uint8_t index)noexcept{
    if(index>=3)return{StreamStatus::invalid_channel,0};
    if(closed_)return{StreamStatus::closed,0};
    if(!constructed_[index])return{StreamStatus::completed,0};
    auto result=StreamStatus::fault;Operation operation([&](auto& players){result=mapped(players.inspect(keys_[index]).status);});
    const auto admission=owner_->run(operation);result=admitted(admission,result);
    return{result,stream_accepted(result)?1:0};
}
StreamValue StreamInstances::start_ready(std::uint8_t index)noexcept{
    if(index>=3)return{StreamStatus::invalid_channel,0};
    if(closed_)return{StreamStatus::closed,0};
    if(!constructed_[index])return{StreamStatus::unbound,0};
    if(voice_queues_[index])return queued_phase(index,true);
    auto result=StreamStatus::fault;std::int32_t ready{};
    Operation operation([&](auto& players){const auto observed=players.inspect(keys_[index]);result=mapped(observed.status);
        if(stream_accepted(result)&&!observed.replacement_pending&&observed.source)ready=observed.source->playback.started?1:0;
    });const auto admission=owner_->run(operation);return{admitted(admission,result),ready};
}
StreamStatus StreamInstances::start_inhibit(std::uint8_t index,bool value)noexcept{
    if(index>=3)return StreamStatus::invalid_channel;
    if(closed_)return StreamStatus::closed;
    if(!constructed_[index])return StreamStatus::unbound;
    auto result=StreamStatus::fault;Operation operation([&](auto& players){result=mapped(players.set_start_inhibit(keys_[index],value));});
    const auto admission=owner_->run(operation);return admitted(admission,result);
}
StreamStatus StreamInstances::service(std::uint32_t tick)noexcept{
    if(closed_)return StreamStatus::closed;
    auto result=StreamStatus::fault;Operation operation([&](auto& players){const auto queued=service_queues(players,tick);const auto serviced=mapped(players.service(tick));result=!stream_accepted(queued)?queued:!stream_accepted(serviced)?serviced:queued==StreamStatus::pending||serviced==StreamStatus::pending?StreamStatus::pending:StreamStatus::completed;});const auto admission=owner_->run(operation);return admitted(admission,result);
}
StreamStatus StreamInstances::close()noexcept{
    if(closed_)return StreamStatus::completed;
    auto retained_queues=voice_queues_;
    auto result=StreamStatus::completed;Operation operation([&](auto& players){
        for(std::size_t i=0;i<3;++i)if(constructed_[i]){if(voice_queues_[i]){const auto status=retire_queue(std::uint8_t(i),players);if(!stream_accepted(status)){result=status;return;}}const auto status=mapped(players.destroy(keys_[i]));
            if(!stream_accepted(status)){result=status;return;}constructed_[i]=false;started_[i]=false;if(status==StreamStatus::pending)result=status;}
    });const auto admission=owner_->run(operation);result=admitted(admission,result);if(stream_accepted(result)||result==StreamStatus::closed)closed_=true;return result;
}
} // namespace reo::native::gameplay_scenario
