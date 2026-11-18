#pragma once
#include "same_owner_movie_bridge.h"
#include "game/native/movie_timing_context/video_frames.hpp"
#include <optional>
namespace reo_gpu_movie {
namespace native_frames=reo::native::movie_timing_context;
// Construct and use on the actual serialized GS owner. The retained bridge
// owns decoder surfaces, exported images and their actual D3D/Vulkan fences.
class NativeFrameSurface final:public native_frames::FrameSurface {
public:
    using Recorder=std::function<void(Vulkan::CommandBuffer&,const Vulkan::ImageView&,const MoviePictureIdentity&)>;
    NativeFrameSurface(std::shared_ptr<SameOwnerMovieBridge> bridge,MovieTextureTicket ticket,Recorder record)
        :bridge_(std::move(bridge)),ticket_(ticket),record_(std::move(record)) {
        if(!bridge_ || !record_ || !ticket.gpuSubmitted)throw std::invalid_argument("Retained native movie producer/consumer required");
        bridge_->leaseNativeFrame(ticket_);
    }
    ~NativeFrameSurface()override{drain();}
    NativeFrameSurface(const NativeFrameSurface&)=delete;
    NativeFrameSurface& operator=(const NativeFrameSurface&)=delete;
    native_frames::FrameStatus ready()noexcept override {
        if(retired_)return native_frames::FrameStatus::closed;
        try{return bridge_->ready(ticket_)?native_frames::FrameStatus::completed:native_frames::FrameStatus::pending;}
        catch(...){return native_frames::FrameStatus::provider_failure;}
    }
    native_frames::FrameStatus submit()noexcept override {
        const auto status=ready();if(status!=native_frames::FrameStatus::completed)return status;
        try{
            const auto fence=bridge_->consumePart(ticket_,false,record_,true);
            return fence?native_frames::FrameStatus::completed:native_frames::FrameStatus::provider_failure;
        }catch(...){return native_frames::FrameStatus::provider_failure;}
    }
    native_frames::FrameStatus retire()noexcept override {
        if(retired_)return native_frames::FrameStatus::completed;
        try{
            if(!bridge_->tryReleaseNativeFrame(ticket_))return native_frames::FrameStatus::pending;
            retired_=true;return native_frames::FrameStatus::completed;
        }catch(...){return native_frames::FrameStatus::provider_failure;}
    }
    void drain()noexcept override {
        if(retired_)return;
        try{bridge_->releaseOriginalFrame(ticket_,true);}
        catch(...){bridge_->shutdown();}
        retired_=true;
    }
    native_frames::FrameStatus bindTime(uint32_t reference,int64_t pts,bool absent)noexcept {
        if(retired_)return native_frames::FrameStatus::closed;
        try{return bridge_->bindNativePlayerTime(ticket_,reference,pts,absent)?native_frames::FrameStatus::completed:native_frames::FrameStatus::pending;}
        catch(...){return native_frames::FrameStatus::provider_failure;}
    }
private:
    std::shared_ptr<SameOwnerMovieBridge> bridge_;MovieTextureTicket ticket_;Recorder record_;bool retired_{};
};
// Decode submission and frame publication are joined: a successful enqueue is
// retained even while its producer fence is pending. No successful decode is
// inferred from a poll count, and no original/CPU fallback follows a side effect.
class NativeVideoFrames final {
public:
    struct PlayerTime {uint32_t reference{};int64_t pts{};bool absent{};};
    NativeVideoFrames(std::shared_ptr<SameOwnerMovieBridge> bridge,std::shared_ptr<native_frames::VideoFrames> frames)
        :bridge_(std::move(bridge)),frames_(std::move(frames)) {
        if(!bridge_ || !frames_)throw std::invalid_argument("Owned decoder and timed frame pool required");
    }
    ~NativeVideoFrames(){for(auto& item:pending_)(void)frames_->abandon(item.key);}
    NativeVideoFrames(const NativeVideoFrames&)=delete;
    NativeVideoFrames& operator=(const NativeVideoFrames&)=delete;
    native_frames::FrameResult decode(const MoviePictureIdentity& identity,const PictureSubmission& submission,
                                     uint32_t th0,uint32_t th1,std::optional<native_frames::Words> time,
                                     NativeFrameSurface::Recorder record,bool reference=false) {
        if(closing_)return{native_frames::FrameStatus::closed};
        if(!hasMovieProductionTime(identity) || !record)return{native_frames::FrameStatus::invalid_input};
        auto reserved=frames_->reserve();if(reserved.status!=native_frames::FrameStatus::completed)return reserved;
        MovieTextureTicket ticket{};
        try {
            if(!bridge_->enqueue(identity,submission,th0,th1,ticket)){
                (void)frames_->abandon(reserved.key);return{native_frames::FrameStatus::pending};
            }
            auto surface=std::make_shared<NativeFrameSurface>(bridge_,ticket,std::move(record));
            if(!time || !hasMovieConsumerTime(identity)){
                pending_.push_back({reserved.key,std::move(surface),reference,!hasMovieConsumerTime(identity)});
                reserved.status=native_frames::FrameStatus::pending;return reserved;
            }
            const auto status=frames_->publish(reserved.key,*time,surface,reference);
            if(status!=native_frames::FrameStatus::completed && status!=native_frames::FrameStatus::pending)
                (void)frames_->abandon(reserved.key);
            reserved.status=status;return reserved;
        }catch(...){
            (void)frames_->abandon(reserved.key);
            // STOP/error only. Existing scoped fences retain all prior reads.
            bridge_->shutdown();throw;
        }
    }
    native_frames::FrameStatus publishTime(const native_frames::FrameKey& key,native_frames::Words time,
                                          std::optional<PlayerTime> observation={})noexcept {
        if(closing_)return native_frames::FrameStatus::closed;
        auto found=std::find_if(pending_.begin(),pending_.end(),[&](const auto& item){return item.key==key;});
        if(found==pending_.end())return native_frames::FrameStatus::invalid_key;
        if(found->needsPlayerTime){
            if(!observation)return native_frames::FrameStatus::invalid_input;
            const auto bound=found->surface->bindTime(observation->reference,observation->pts,observation->absent);
            if(bound!=native_frames::FrameStatus::completed)return bound;
            found->needsPlayerTime=false;
        }
        const auto status=frames_->publish(key,time,found->surface,found->reference);
        if(status==native_frames::FrameStatus::completed || status==native_frames::FrameStatus::pending)pending_.erase(found);
        return status;
    }
    native_frames::FrameStatus close()noexcept {
        closing_=true;
        bool pending=false;
        bool fault=false;
        for(auto item=pending_.begin();item!=pending_.end();){
            const auto retired=item->surface->retire();
            if(retired==native_frames::FrameStatus::completed){
                const auto abandoned=frames_->abandon(item->key);
                if(abandoned==native_frames::FrameStatus::completed){item=pending_.erase(item);continue;}
                pending|=abandoned==native_frames::FrameStatus::busy;
                fault|=abandoned!=native_frames::FrameStatus::busy;
            }else{
                pending|=retired==native_frames::FrameStatus::pending;
                fault|=retired!=native_frames::FrameStatus::pending;
            }
            ++item;
        }
        const auto status=frames_->close();
        if(fault)return native_frames::FrameStatus::provider_failure;
        if(status!=native_frames::FrameStatus::completed)return status;
        return pending?native_frames::FrameStatus::pending:native_frames::FrameStatus::completed;
    }
    const std::shared_ptr<native_frames::VideoFrames>& frames()const noexcept{return frames_;}
private:
    struct Pending {native_frames::FrameKey key;std::shared_ptr<NativeFrameSurface> surface;bool reference{},needsPlayerTime{};};
    std::shared_ptr<SameOwnerMovieBridge> bridge_;std::shared_ptr<native_frames::VideoFrames> frames_;
    std::vector<Pending> pending_;bool closing_{};
};
}
