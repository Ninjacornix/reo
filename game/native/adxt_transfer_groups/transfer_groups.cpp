#include "transfer_groups.hpp"
#include <stdexcept>
#include <utility>

namespace reo::native::adxt_transfer_groups {
DtxGroup::DtxGroup(std::shared_ptr<ChunkGuard> guard):guard_(std::move(guard)) {
    if(!guard_)throw std::invalid_argument("Owned chunk guard required");
}
bool DtxGroup::set(std::uint32_t slot,std::shared_ptr<group::ActiveWork> work)noexcept {
    if(slot>=dtx_slots)return false;
    slots_[slot]=std::move(work);return true;
}
void DtxGroup::service()noexcept {
    guard_->enter();
    for(std::uint32_t i=0;i<dtx_slots;++i){
        const auto work=slots_[i];
        if(work && work->active()==1)work->service();
    }
    guard_->leave();
}
DtrGroup::DtrGroup(std::shared_ptr<DtxGroup> dtx):dtx_(std::move(dtx)) {
    if(!dtx_)throw std::invalid_argument("Shared DTX group required");
}
bool DtrGroup::set(std::uint32_t slot,std::shared_ptr<group::ActiveWork> work)noexcept {
    if(slot>=dtr_slots)return false;
    slots_[slot]=std::move(work);return true;
}
void DtrGroup::service()noexcept {
    for(std::uint32_t i=0;i<dtr_slots;++i){
        const auto work=slots_[i];
        if(work && work->active()==1)work->service();
    }
    dtx_->service();
}
} // namespace reo::native::adxt_transfer_groups
