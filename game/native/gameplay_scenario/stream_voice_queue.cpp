#include "stream_instances.hpp"
#include "../audio_cue_queue/queue.hpp"
#include <vector>
namespace reo::native::gameplay_scenario {
class StreamVoiceQueue final {
public:
    StreamVoiceQueue(audio_cue_queue::Config config,std::shared_ptr<audio_clip_loader::Loader> loader):queue(config,std::move(loader)){}
    audio_cue_queue::Queue queue;
};
namespace {
StreamStatus mapped(audio_cue_queue::Status value)noexcept{
    using S=audio_cue_queue::Status;
    switch(value){case S::completed:return StreamStatus::completed;case S::pending:return StreamStatus::pending;case S::closed:return StreamStatus::closed;case S::invalid_owner:return StreamStatus::unbound;case S::unsupported_profile:case S::capacity:case S::invalid_input:return StreamStatus::unsupported_profile;default:return StreamStatus::fault;}
}
StreamStatus mapped(adxt_instances::Status value)noexcept{
    using S=adxt_instances::Status;
    switch(value){case S::completed:return StreamStatus::completed;case S::pending:return StreamStatus::pending;case S::closed:return StreamStatus::closed;case S::busy:return StreamStatus::busy;case S::invalid_key:return StreamStatus::unbound;default:return StreamStatus::fault;}
}
StreamStatus admitted(adxt_control_owner::Admission value,StreamStatus status)noexcept{return value==adxt_control_owner::Admission::accepted?status:value==adxt_control_owner::Admission::busy?StreamStatus::busy:StreamStatus::closed;}
template<class F>struct Operation final:adxt_control_owner::Operation {F action;explicit Operation(F f):action(std::move(f)){}void run(adxt_instances::Instances& players)noexcept override{action(players);}};
}
StreamStatus StreamInstances::prepare_cues(std::uint8_t index,std::span<const StreamCue> cues,std::uint32_t tick)noexcept{
    if(index>=3)return StreamStatus::invalid_channel;
    if(closed_)return StreamStatus::closed;
    if(!constructed_[index]||!voice_loader_)return StreamStatus::unbound;
    if(cues.size()>17)return StreamStatus::unsupported_profile;
    try{
        std::vector<StreamAsset> assets;assets.reserve(cues.size());
        for(const auto& cue:cues){if(cue.identity.empty()||cue.identity.size()>384||cue.identity.find('\0')!=cue.identity.npos)return StreamStatus::unsupported_profile;auto asset=catalog_->resolve(cue.source);if(asset.status!=StreamStatus::completed)return asset.status;assets.push_back(std::move(asset));}
        auto next=std::make_shared<StreamVoiceQueue>(audio_cue_queue::Config{config_[index].construction.channels,65536},voice_loader_);
        auto retained=voice_queues_[index];auto result=StreamStatus::fault;
        Operation operation([&](auto& players){
            result=voice_queues_[index]?retire_queue(index,players):mapped(players.stop(keys_[index]));if(!stream_accepted(result))return;
            result=mapped(next->queue.bind(players,keys_[index]));if(!stream_accepted(result))return;
            voice_queues_[index]=next;
            for(std::size_t i=0;i<cues.size();++i){result=mapped(next->queue.enqueue(players,cues[i].identity,assets[i].view).status);if(!stream_accepted(result))return;}
            result=mapped(next->queue.start(players,tick));
        });const auto admission=owner_->run(operation);result=admitted(admission,result);if(stream_accepted(result))started_[index]=true;return result;
    }catch(...){return StreamStatus::fault;}
}
StreamStatus StreamInstances::retire_queue(std::uint8_t index,adxt_instances::Instances& players)noexcept{
    if(!voice_queues_[index])return StreamStatus::completed;
    const auto result=mapped(voice_queues_[index]->queue.close(players));if(stream_accepted(result))voice_queues_[index].reset();return result;
}
StreamStatus StreamInstances::service_queues(adxt_instances::Instances& players,std::uint32_t tick)noexcept{
    auto result=StreamStatus::completed;
    for(const auto& queue:voice_queues_)if(queue){const auto status=mapped(queue->queue.service(players,tick));if(!stream_accepted(status))return status;if(status==StreamStatus::pending)result=status;}
    return result;
}
StreamValue StreamInstances::queued_phase(std::uint8_t index,bool ready)noexcept{
    auto result=StreamStatus::fault;std::int32_t value{};
    Operation operation([&](auto& players){
        if(!voice_queues_[index]){result=StreamStatus::unbound;return;}
        const auto report=voice_queues_[index]->queue.snapshot();if(report.failed){result=mapped(report.failure);return;}
        const auto observed=players.inspect(keys_[index]);result=mapped(observed.status);if(!stream_accepted(result))return;
        if(!report.source_submitted||observed.replacement_pending){value=ready?0:1;return;}
        if(!observed.source){result=StreamStatus::fault;return;}
        value=ready?(observed.source->playback.started?1:0):observed.source->configured?std::int32_t(observed.source->playback.phase):1;
    });const auto admission=owner_->run(operation);return{admitted(admission,result),value};
}
StreamQueueObservation StreamInstances::inspect_queue(std::uint8_t index)noexcept{
    if(index>=3)return{StreamStatus::invalid_channel};
    if(closed_)return{StreamStatus::closed};
    StreamQueueObservation result;
    Operation operation([&](auto&){if(!voice_queues_[index])return;const auto report=voice_queues_[index]->queue.snapshot();result={report.failed?mapped(report.failure):StreamStatus::completed,report.preparing,report.queued,report.registered_assets,report.accepted,report.submitted_sources,report.source_submitted,report.decoder_ended,report.failed};});
    const auto admission=owner_->run(operation);result.status=admitted(admission,result.status);return result;
}
}
