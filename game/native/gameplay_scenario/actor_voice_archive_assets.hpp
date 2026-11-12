#pragma once
#include "../afs_source_range/afs_source_range.hpp"
#include <array>
#include <memory>
#include <string>
namespace reo::assets {struct Source;}
namespace reo::native::gameplay_scenario {
// Immutable File #1 actor voice indexes. These are retained nested views,
// not loaded-slot state or another mutable stream catalog.
class ActorVoiceArchiveAssets final {
public:
    explicit ActorVoiceArchiveAssets(std::shared_ptr<reo::assets::Source>);
    static constexpr std::size_t characters=8;
    static constexpr std::uint32_t catalog_id(std::uint8_t character)noexcept{return 401u+character;}
    const std::shared_ptr<const afs_source_range::Archive>& archive(std::size_t character)const{return archives_.at(character);}
    const std::string& identity(std::size_t character)const{return identities_.at(character);}
private:
    std::array<std::shared_ptr<const afs_source_range::Archive>,characters> archives_;
    std::array<std::string,characters> identities_;
};
}
