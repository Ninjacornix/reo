#pragma once
#include "native_frame_surface.h"
#include "mpeg2_stream.h"
#include "game/native/movie_lifecycle/prepared_graph.hpp"
#include "game/native/movie_timestamp/timecode.hpp"
#include <limits>
#include <bit>
namespace reo_gpu_movie {
namespace life=reo::native::movie_lifecycle;
// Actual serialized graphics owner only. Uses the existing bounded MPEG parser
// and hardware reference-surface protocol. Unsupported timestamp/profile input
// fails closed; no guessed timestamps, software decode or original fallback.
class NativeVideoGraph final:public life::VideoBackend {
    Mpeg2ElementaryStream elementary_;MpegProgramStream program_;
    std::shared_ptr<native_frames::Context> clock_;std::shared_ptr<native_frames::VideoFrames> frames_;
    std::shared_ptr<SameOwnerMovieBridge> bridge_;std::unique_ptr<NativeVideoFrames> pipeline_;
    NativeFrameSurface::Recorder record_;
    uint64_t generation_{};uint16_t previous_=0xffff,current_=0xffff;
    int64_t watermark_=std::numeric_limits<int64_t>::min();
    struct Pending {native_frames::FrameKey key;native_frames::Words time;int64_t pts;};
    std::vector<Pending> pending_;bool ended_{},closing_{},fault_{};
    struct Accounting {uint64_t begin,end;reo::native::movie_timestamp::Stamp stamp;};
    std::deque<Accounting> accounting_;
    reo::native::movie_timestamp::FlowState time_;
    uint64_t lastGop_{},decoded_{};uint32_t rate_{};
    void observePacket(uint8_t code,const PesTimestamp& time) {
        if(code!=0xe0 || !time.hasPts)return;
        if(accounting_.size()>=4096)throw std::runtime_error("Native movie timestamp accounting capacity");
        accounting_.push_back({time.elementaryBegin,time.elementaryEnd,{static_cast<uint32_t>(time.pts33>>2),static_cast<uint32_t>(time.elementaryBegin),static_cast<uint32_t>(time.elementaryEnd-time.elementaryBegin)}});
    }
    std::array<char,256> error_{};
    void failed(const char* reason)noexcept{fault_=true;std::snprintf(error_.data(),error_.size(),"%s",reason);}
    life::Status publish() {
        // Publish one earliest picture, including at EOF. A later ready GPU
        // surface must not bypass an earlier surface that is still producing.
        // Keep the published resource until the consumer and its fence retire.
        if(frames_->snapshot().resources || pending_.empty())return life::Status::completed;
        const auto item=std::min_element(pending_.begin(),pending_.end(),[](const auto& a,const auto& b){return a.pts<b.pts;});
        // Zero is the minimum admitted PTS. Other anchors wait until the next
        // anchor establishes the reorder watermark, or genuine parser EOF.
        if(item->pts!=0 && item->pts>=watermark_ && !(ended_ && !elementary_.hasPicture()))return life::Status::completed;
        const auto status=pipeline_->publishTime(item->key,item->time);
        if(status!=native_frames::FrameStatus::completed && status!=native_frames::FrameStatus::pending)return life::Status::provider_failure;
        pending_.erase(item);
        return life::Status::completed;
    }
public:
    NativeVideoGraph(std::shared_ptr<native_frames::Context> clock,uint64_t generation,
                     std::shared_ptr<SameOwnerMovieBridge> bridge,NativeFrameSurface::Recorder record)
        :program_(elementary_,0xe0,[this](uint8_t code,const PesTimestamp& time,std::span<const uint8_t>){observePacket(code,time);}),clock_(std::move(clock)),bridge_(std::move(bridge)),record_(std::move(record)),generation_(generation) {
        if(!clock_ || !bridge_ || !record_ || !generation_)throw std::invalid_argument("Native timed movie graph identity");
        frames_=native_frames::VideoFrames::create(clock_,3);pipeline_=std::make_unique<NativeVideoFrames>(bridge_,frames_);
        pending_.reserve(3);
    }
    ~NativeVideoGraph()override{drain();}
    const std::shared_ptr<native_frames::VideoFrames>& frames()const noexcept{return frames_;}
    const std::shared_ptr<native_frames::Context>& clock()const noexcept{return clock_;}
    const char* error()const noexcept{return error_.data();}
    uint64_t decodedPictures()const noexcept{return decoded_;}
    bool drained()const noexcept{return ended_ && !elementary_.hasPicture() && pending_.empty() && frames_->snapshot().resources==0;}
    life::Status feed(uint64_t offset,std::span<const std::byte> bytes)noexcept override {
        if(closing_)return life::Status::closed;
        if(fault_)return life::Status::provider_failure;
        if(elementary_.hasPicture())return life::Status::pending;
        try{program_.feed(offset,{reinterpret_cast<const uint8_t*>(bytes.data()),bytes.size()});return life::Status::completed;}
        catch(const std::exception& error){failed(error.what());return life::Status::provider_failure;}
        catch(...){failed("Unknown video parser failure");return life::Status::provider_failure;}
    }
    life::Status end()noexcept override {
        if(closing_)return life::Status::closed;
        if(fault_)return life::Status::provider_failure;
        if(ended_)return life::Status::completed;
        try{program_.end();ended_=true;return publish();}
        catch(const std::exception& error){failed(error.what());return life::Status::provider_failure;}
        catch(...){failed("Unknown video end failure");return life::Status::provider_failure;}
    }
    life::Status service()noexcept override {
        if(closing_)return life::Status::closed;
        if(fault_)return life::Status::provider_failure;
        try{
            const auto collected=frames_->poll();
            if(collected!=native_frames::FrameStatus::completed && collected!=native_frames::FrameStatus::pending)throw std::runtime_error("Native movie frame poll failed");
            if(publish()!=life::Status::completed)throw std::runtime_error("Native movie timed publication failed");
            // Let the frontend consume the published frame before decoding
            // ahead. Untimed/reorder-held slots have no published resources.
            if(frames_->snapshot().resources)return life::Status::pending;
            if(!elementary_.hasPicture())return life::Status::completed;
            const auto& picture=elementary_.picture();
            if(rate_ && rate_!=picture.rate)throw std::runtime_error("Movie rate change requires a new timing generation");
            namespace timestamps=reo::native::movie_timestamp;
            timestamps::FlowInput timing;timing.picture={picture.rate,picture.temporalReference,picture.kind,picture.drop,picture.hours,picture.minutes,picture.seconds,picture.frames,static_cast<uint32_t>(picture.gop)};timing.changed=picture.gop!=lastGop_;
            while(!accounting_.empty() && accounting_.front().end<=picture.begin)accounting_.pop_front();
            for(const auto& item:accounting_)if(item.begin<=picture.begin && picture.begin<item.end){timing.accounting=item.stamp;break;}
            auto candidate_time=time_;const auto publication=timestamps::publish(candidate_time,timing);
            if(!publication.admitted)throw std::runtime_error("Movie timestamp profile refused");
            auto submission=picture.submission();const bool anchor=picture.kind!=3;
            const uint16_t target=anchor?(current_==0?1:0):2;
            submission.picture.wDecodedPictureIndex=target;
            submission.picture.wForwardRefPictureIndex=picture.kind==1?0xffff:anchor?current_:previous_;
            submission.picture.wBackwardRefPictureIndex=picture.kind==3?current_:0xffff;
            if((picture.kind==2 && current_==0xffff) || (picture.kind==3 && (previous_==0xffff || current_==0xffff)))throw std::runtime_error("Native movie graph lacks genuine MPEG reference");
            MoviePictureIdentity identity;identity.generation=generation_;identity.picture=picture.ordinal;identity.compressedBegin=picture.begin;identity.compressedEnd=picture.end;
            // Existing bridge compatibility tags are opaque nonzero identities,
            // never guest pointers. They do not enter the native timing core.
            identity.sofdec=1;identity.work=1;identity.truePictureBoundaries=true;identity.truePlayerPts=true;
            identity.pts90k=int64_t(std::bit_cast<int32_t>(publication.value))*90000/publication.scale;
            if(submission.picture.wForwardRefPictureIndex!=0xffff)identity.forwardGeneration=bridge_->surfaceGeneration(submission.picture.wForwardRefPictureIndex);
            if(submission.picture.wBackwardRefPictureIndex!=0xffff)identity.backwardGeneration=bridge_->surfaceGeneration(submission.picture.wBackwardRefPictureIndex);
            const auto result=pipeline_->decode(identity,submission,0,0,std::nullopt,record_);
            if(result.status!=native_frames::FrameStatus::completed && result.status!=native_frames::FrameStatus::pending)throw std::runtime_error("Native movie graph decode failed");
            if(result.key==native_frames::FrameKey{})return life::Status::pending;
            pending_.push_back({result.key,{publication.value,publication.scale},identity.pts90k});
            time_=candidate_time;lastGop_=picture.gop;rate_=picture.rate;++decoded_;
            if(anchor){previous_=current_;current_=target;watermark_=identity.pts90k;}
            elementary_.pop();return publish();
        }catch(const std::exception& error){failed(error.what());return life::Status::provider_failure;}
        catch(...){failed("Unknown video service failure");return life::Status::provider_failure;}
    }
    void request_stop()noexcept override{if(closing_)return;closing_=true;(void)pipeline_->close();}
    life::Status poll_retired()noexcept override {
        if(!closing_)return life::Status::invalid_input;
        if(!pipeline_)return life::Status::completed;
        const auto result=pipeline_->close();
        if(result==native_frames::FrameStatus::pending || result==native_frames::FrameStatus::busy)return life::Status::pending;
        if(result!=native_frames::FrameStatus::completed)return life::Status::provider_failure;
        pending_.clear();bridge_->shutdown();return life::Status::completed;
    }
    void drain()noexcept override{request_stop();pending_.clear();pipeline_.reset();bridge_->shutdown();}
};
}
