#pragma once
#include "stream_channels.hpp"
#include "../afs_source_range/afs_source_range.hpp"
#include <array>
#include <atomic>
#include <memory>
#include <optional>
namespace reo::native::gameplay_scenario {
class StreamAssetCatalog;
// Canonical five 1BA440 archive selections, independent of decoder creation.
// The exact sealed catalog is retained; later stream instances borrow this same
// object, never a per-frame copy of the markers or archive identities.
class ActorVoiceSelections final {
public:
    explicit ActorVoiceSelections(std::shared_ptr<const StreamAssetCatalog>);
    bool bound_to(const StreamAssetCatalog& catalog)const noexcept{return catalog_.get()==&catalog;}
    StreamStatus activate(std::uint8_t slot,std::uint8_t character)noexcept;
    StreamStatus clear()noexcept;
    StreamValue marker(std::uint8_t slot)const noexcept;
    StreamSourceResult source(std::uint8_t slot,std::int32_t member)const noexcept;
    StreamStatus close()noexcept;
private:
    struct Entry {std::uint8_t marker{};std::shared_ptr<const afs_source_range::Archive> archive;};
    std::shared_ptr<const StreamAssetCatalog> catalog_;
    mutable std::atomic_flag busy_{};
    std::array<std::optional<Entry>,5> entries_;
    bool closed_{};
};
}
