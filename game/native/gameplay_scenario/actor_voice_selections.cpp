#include "actor_voice_selections.hpp"
#include "actor_voice_archive_assets.hpp"
#include "stream_instances.hpp"
#include <stdexcept>
#include <utility>
namespace reo::native::gameplay_scenario {
namespace {
struct Guard {std::atomic_flag& busy;bool acquired;explicit Guard(std::atomic_flag& value):busy(value),acquired(!busy.test_and_set(std::memory_order_acquire)){}~Guard(){if(acquired)busy.clear(std::memory_order_release);}};
}
ActorVoiceSelections::ActorVoiceSelections(std::shared_ptr<const StreamAssetCatalog> catalog):catalog_(std::move(catalog)){
    if(!catalog_||!catalog_->sealed())throw std::invalid_argument("Actor voice catalog unavailable");
}
StreamStatus ActorVoiceSelections::status()const noexcept{
    Guard lock(busy_);if(!lock.acquired)return StreamStatus::busy;return closed_?StreamStatus::closed:StreamStatus::completed;
}
StreamStatus ActorVoiceSelections::activate(std::uint8_t slot,std::uint8_t character)noexcept{
    if(slot>=entries_.size())return StreamStatus::completed; // 1BA440's original out-of-range no-op.
    Guard lock(busy_);if(!lock.acquired)return StreamStatus::busy;if(closed_)return StreamStatus::closed;
    std::shared_ptr<const afs_source_range::Archive> archive;
    if(character<ActorVoiceArchiveAssets::characters){archive=catalog_->actor_voice_archive(character);if(!archive)return StreamStatus::unbound;}
    entries_[slot]=Entry{archive?std::uint8_t(character+1):std::uint8_t(0),std::move(archive)};return StreamStatus::completed;
}
StreamStatus ActorVoiceSelections::clear()noexcept{
    Guard lock(busy_);if(!lock.acquired)return StreamStatus::busy;if(closed_)return StreamStatus::closed;
    for(auto& entry:entries_)entry=Entry{};return StreamStatus::completed;
}
StreamValue ActorVoiceSelections::marker(std::uint8_t slot)const noexcept{
    if(slot>=entries_.size())return{StreamStatus::unsupported_profile,0};
    Guard lock(busy_);if(!lock.acquired)return{StreamStatus::busy,0};if(closed_)return{StreamStatus::closed,0};
    return entries_[slot]?StreamValue{StreamStatus::completed,entries_[slot]->marker}:StreamValue{StreamStatus::unbound,0};
}
StreamSourceResult ActorVoiceSelections::source(std::uint8_t slot,std::int32_t member)const noexcept{
    if(slot>=entries_.size())return{StreamStatus::unsupported_profile,{}};
    Guard lock(busy_);if(!lock.acquired)return{StreamStatus::busy,{}};if(closed_)return{StreamStatus::closed,{}};
    const auto& selected=entries_[slot];if(!selected)return{};
    if(!selected->marker||!selected->archive||member<0)return{StreamStatus::missing_asset,{}};
    const auto entry=selected->archive->entry(std::uint32_t(member));if(!entry||!entry->logical_bytes)return{StreamStatus::missing_asset,{}};
    return{StreamStatus::completed,{ActorVoiceArchiveAssets::catalog_id(std::uint8_t(selected->marker-1)),member}};
}
StreamStatus ActorVoiceSelections::close()noexcept{
    Guard lock(busy_);if(!lock.acquired)return StreamStatus::busy;if(closed_)return StreamStatus::completed;
    closed_=true;for(auto& entry:entries_)entry.reset();return StreamStatus::completed;
}
}
