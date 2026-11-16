#include "session_audio.hpp"
#include "../adxt_output_session/session.hpp"
#include "../audio_mix_tail/mixer.hpp"
#include "../gameplay_world/world.hpp"
#include "../gameplay_bank_loading/aliases.hpp"
#include <stdexcept>
#include <thread>

namespace reo::native::gameplay_application {
SessionAudio::SessionAudio(gameplay_world::World& world,std::shared_ptr<audio_mix_tail::Mixer> mixer,
                           std::shared_ptr<adxt_output_session::Session> output,std::shared_ptr<const afs_source_range::Archive> archive)
    :world_(&world),mixer_(std::move(mixer)),output_(std::move(output)){
    if(!mixer_||!output_||!output_->bound_to(*mixer_)||mixer_->packets_||mixer_->stopping_.load(std::memory_order_acquire)||
       !mixer_->gameplay_owner_.expired()||!archive)
        throw std::invalid_argument("One matching direct native audio output and sound archive required");
    auto owner=std::make_shared<gameplay_audio::Owner>(mixer_->banks_,world.session().random);
    if(archive->count()!=422)throw std::invalid_argument("File1 named sound archive required");
    auto reads=std::make_unique<resource_io::AsyncReadOwner>(resource_io::Config{1,1024*1024,2*1024*1024});
    mixer_->gameplay_owner_=owner;owner_=std::move(owner);archive_=std::move(archive);reads_=std::move(reads);
}
SessionAudio::~SessionAudio(){if(!close())std::terminate();}
bool SessionAudio::bound_to(const gameplay_world::World& world)const noexcept{return !closed_&&world_==&world&&output_->bound_to(*mixer_);}
SessionAudioLoadResult SessionAudio::load_common()noexcept{
    return load_named("common.snd",0);
}
SessionAudioLoadResult SessionAudio::load_named(std::string_view name,unsigned port)noexcept{
    namespace banks=gameplay_bank_loading;
    using Status=SessionAudioLoadStatus;
    if(closed_||!output_->bound_to(*mixer_))return{Status::closed,{},{}};
    if(running_)return{Status::busy,{},{}};
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    const auto member=banks::sound_member(name);
    if(!member)return{Status::not_found,{},{}};
    const auto file=archive_->member(*member);
    if(file.status!=afs_source_range::Status::completed||!file.view)return{Status::source_failure,{},member};
    if(file.view->size()>1024*1024)return{Status::capacity,{},member};
    const auto submitted=reads_->submit(file.view,0,std::size_t(file.view->size()));
    if(submitted.status!=resource_io::SubmitStatus::accepted)return{Status::source_failure,{},member};
    for(;;){
        auto result=reads_->poll(submitted.ticket);
        if(result.status==resource_io::PollStatus::ready){
            if(result.outcome.status!=resources::Status::ok)return{Status::source_failure,{},member};
            const auto ticket=owner_->begin_bank(port);
            if(!ticket)return{Status::capacity,{},member};
            const auto bank=owner_->install(ticket,{reinterpret_cast<const std::uint8_t*>(result.outcome.bytes.data()),result.outcome.bytes.size()});
            if(bank.status!=gameplay_audio::Status::completed)(void)owner_->cancel(ticket);
            return{bank.status==gameplay_audio::Status::completed?Status::completed:Status::bank_failure,bank,member};
        }
        if(result.status!=resource_io::PollStatus::pending)return{Status::source_failure,{},member};
        std::this_thread::yield();
    }
}
bool SessionAudio::close()noexcept{
    if(closed_)return true;
    if(running_)return false;
    reads_->shutdown();if(!reads_->join())std::terminate();
    reads_.reset();archive_.reset();owner_.reset();closed_=true;return true;
}
}
