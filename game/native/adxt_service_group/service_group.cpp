#include "service_group.hpp"
#include <stdexcept>
#include <utility>

namespace reo::native::adxt_service_group {
Group::Group(std::shared_ptr<adxt_estimated_clock::Shared> clock,std::shared_ptr<Guards> guards,
             std::shared_ptr<Work> dtr,std::shared_ptr<Work> dtx)
    :clock_(std::move(clock)),guards_(std::move(guards)),dtr_(std::move(dtr)),dtx_(std::move(dtx)) {
    if(!clock_ || !guards_ || !dtr_ || !dtx_)throw std::invalid_argument("Owned audio group boundaries required");
}
bool Group::set_decoder(std::uint32_t slot,std::shared_ptr<ActiveWork> work)noexcept {
    if(slot>=slots)return false;
    decoders_[slot]=std::move(work);return true;
}
bool Group::set_stream(std::uint32_t slot,std::shared_ptr<Stream> stream)noexcept {
    if(slot>=slots)return false;
    streams_[slot]=std::move(stream);return true;
}
bool Group::set_rna(std::uint32_t slot,std::shared_ptr<ActiveWork> work)noexcept {
    if(slot>=slots)return false;
    rna_[slot]=std::move(work);return true;
}
Status Group::service()noexcept {
    guards_->enter(Domain::cri);
    if(clock_->service_busy){guards_->leave(Domain::cri);return Status::busy;}
    clock_->service_busy=1;
    guards_->leave(Domain::cri);
    guards_->enter(Domain::cri);
    for(std::uint32_t i=0;i<slots;++i){
        const auto decoder=decoders_[i];
        if(decoder && decoder->active()==1)decoder->service();
    }
    clock_->service_busy=2;
    for(std::uint32_t i=0;i<slots;++i){
        const auto stream=streams_[i];
        if(!stream || stream->active()!=1)continue;
        const auto phase=stream->phase();
        switch(phase){
        case 1:stream->service_phase(Phase::ready);break;
        case 2:stream->service_phase(Phase::buffering);break;
        case 3:stream->service_phase(Phase::playing);break;
        case 4:stream->service_phase(Phase::draining);break;
        default:break; // Original phase5 body is a no-op.
        }
        stream->propagate_input_end();
        stream->propagate_error();
    }
    clock_->service_busy=3;
    guards_->enter(Domain::rna);
    for(std::uint32_t i=0;i<slots;++i){
        const auto rna=rna_[i];
        if(rna && rna->active()==1)rna->service();
    }
    guards_->leave(Domain::rna);
    dtr_->service();
    dtx_->service();
    clock_->service_busy=0;
    guards_->leave(Domain::cri);
    return Status::completed;
}
} // namespace reo::native::adxt_service_group
