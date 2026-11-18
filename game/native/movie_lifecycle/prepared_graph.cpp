#include "prepared_graph.hpp"
#include <atomic>
#include <thread>
#include <stdexcept>
#include <algorithm>
namespace reo::native::movie_lifecycle {
namespace {struct Busy{bool& value;explicit Busy(bool& v):value(v){value=true;}~Busy(){value=false;}};}
struct PreparedGraph::Join {
    std::thread worker;std::atomic<bool> done{},success{};
    ~Join(){if(worker.joinable())worker.join();}
};
PreparedGraph::PreparedGraph(GraphConfig config,Recipe recipe,std::uint64_t generation):config_(std::move(config)),recipe_(std::move(recipe)) {
    if(!generation || !config_.video || !config_.read_bytes || config_.read_bytes>65536 || !recipe_.source || !recipe_.bytes || recipe_.offset>recipe_.source->size() || recipe_.bytes>recipe_.source->size()-recipe_.offset)throw std::invalid_argument("Prepared movie source/video profile");
    try{
        resource_io::Config input_config;input_config.max_requests=1;input_config.max_read_bytes=config_.read_bytes;input_config.byte_budget=2*config_.read_bytes;
        input_=std::make_shared<resource_io::AsyncReadOwner>(input_config);
        if(config_.audio){auto& a=*config_.audio;
            if(!a.session || !a.input || !a.tick)throw std::invalid_argument("Prepared native audio route");
            const auto opened=a.session->open(a.player,a.input,a.indices);
            if(opened.status!=adxt_control_session::Status::completed)throw std::runtime_error("Native movie audio construction refused");
            audio_key_=opened.key;config_.clock.audio=std::make_shared<timing::audio::SessionSource>(a.session,opened.key,a.tick);
        }
        config_.clock.facts.actual=1;config_.clock.facts.requested=1;
        clock_=timing::Context::create(config_.clock);video_=config_.video->create(clock_,generation);
        if(!video_)throw std::runtime_error("Native movie video construction refused");
        constructed_=true;
    }catch(...){request_stop();}
}
PreparedGraph::~PreparedGraph(){request_stop();drain();}
bool PreparedGraph::begin_join()noexcept {
    if(join_)return true;
    if(!input_)return true;
    try{
        auto state=std::make_unique<Join>();auto* result=state.get();auto input=input_;
        state->worker=std::thread([result,input]{result->success.store(input->join(),std::memory_order_release);result->done.store(true,std::memory_order_release);});join_=std::move(state);return true;
    }catch(...){return false;}
}
Status PreparedGraph::service()noexcept {
    if(busy_)return Status::busy;
    if(closing_)return Status::closed;
    Busy scope(busy_);
    if(config_.audio){std::uint32_t tick{};auto& a=*config_.audio;
        if(a.tick->read(tick)!=timing::audio::ProviderStatus::completed || a.session->service(tick)!=adxt_control_session::Status::completed)return Status::provider_failure;}
    const auto work=video_->service();if(work!=Status::completed && work!=Status::pending)return work;
    if(!bytes_.empty()){
        const auto fed=video_->feed(offset_,bytes_);if(fed!=Status::completed)return fed;
        offset_+=bytes_.size();bytes_.clear();
    }
    if(offset_==recipe_.bytes){if(ended_)return work;const auto result=video_->end();if(result==Status::completed)ended_=true;return result;}
    if(!reading_){const auto read=input_->submit(recipe_.source,recipe_.offset+offset_,static_cast<std::size_t>(std::min<std::uint64_t>(config_.read_bytes,recipe_.bytes-offset_)));
        if(read.status!=resource_io::SubmitStatus::accepted)return Status::provider_failure;
        ticket_=read.ticket;reading_=true;}
    auto read=input_->poll(ticket_);
    if(read.status==resource_io::PollStatus::pending)return Status::pending;
    if(read.status!=resource_io::PollStatus::ready || read.outcome.status!=resources::Status::ok)return Status::provider_failure;
    reading_=false;bytes_=std::move(read.outcome.bytes);return Status::pending;
}
void PreparedGraph::request_stop()noexcept {
    if(closing_)return;
    closing_=true;
    if(input_)input_->shutdown();
    if(video_)video_->request_stop();
    // Per-stream retirement preserves the shared audio device and other voices.
    if(audio_key_)audio_retired_=config_.audio->session->retire(*audio_key_).status==adxt_control_session::Status::completed;
    (void)begin_join();
}
Status PreparedGraph::poll_retired()noexcept {
    if(busy_)return Status::busy;
    if(!closing_)return Status::invalid_input;
    Busy scope(busy_);bool pending=false;
    if(!begin_join())return Status::provider_failure;
    if(join_){
        if(!join_->done.load(std::memory_order_acquire))pending=true;
        else{if(!join_->success.load(std::memory_order_acquire))return Status::provider_failure;if(join_->worker.joinable())join_->worker.join();input_.reset();}
    }
    if(video_){const auto result=video_->poll_retired();if(result!=Status::completed && result!=Status::pending)return result;pending|=result==Status::pending;}
    if(audio_key_ && !audio_retired_){const auto result=config_.audio->session->retire(*audio_key_);if(result.status!=adxt_control_session::Status::completed && result.status!=adxt_control_session::Status::pending)return Status::provider_failure;audio_retired_=result.status==adxt_control_session::Status::completed;pending|=!audio_retired_;}
    if(pending)return Status::pending;
    if(clock_ && !detached_){if(clock_->detach_queries()!=timing::Status::completed)return Status::provider_failure;detached_=true;}
    video_.reset();bytes_.clear();recipe_={};return Status::completed;
}
void PreparedGraph::drain()noexcept {
    request_stop();
    if(join_ && join_->worker.joinable())join_->worker.join();
    else if(input_)(void)input_->join();
    if(video_)video_->drain();
    if(audio_key_ && !audio_retired_){
        for(;;){const auto result=config_.audio->session->retire(*audio_key_);if(result.status==adxt_control_session::Status::completed){audio_retired_=true;break;}if(result.status!=adxt_control_session::Status::pending)break;std::this_thread::yield();}
    }
    if(clock_ && !detached_){detached_=clock_->detach_queries()==timing::Status::completed;}
}
Build PreparedFactory::construct(const Recipe& recipe,std::uint64_t generation)noexcept {
    try{
        auto graph=std::make_shared<PreparedGraph>(config_,recipe,generation);
        const auto status=graph->constructed()?Status::completed:Status::provider_failure;
        return{status,std::move(graph)};
    }catch(...){return{Status::provider_failure,{}};}
}
}
