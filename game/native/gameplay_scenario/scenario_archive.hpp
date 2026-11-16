#pragma once
#include "content.hpp"
#include <string>
#include <string_view>

namespace reo::assets { struct Source; }
namespace reo::native::gameplay_scenario::content {

struct RoomId {
    std::uint16_t scenario{}, room{}, variant{};
};

// File #1 scenario content read directly from a retained host NETBIO00 source.
class ScenarioArchive final {
public:
    explicit ScenarioArchive(std::shared_ptr<const reo::assets::Source> archive);
    bool bound_to(const reo::assets::Source& source)const noexcept{return archive_.get()==&source;}

    std::optional<ScriptBank> scenario_scripts(std::uint16_t scenario) const;
    std::optional<RdtDirectory> room(RoomId id) const;
    Bytes read_member(std::uint16_t scenario,std::string_view name) const;
    // Exact AFS table ordinal, including unnamed/empty positions. Room NBD
    // texture lists refer to these immutable table indices, not sorted names.
    Bytes read_member_ordinal(std::uint16_t scenario,std::uint32_t ordinal) const;
    // Resolve an authored scenario resource key through its owned _H.BIN
    // ordinal table. Basename keys are at most16 bytes; duplicate keys select the first
    // original entry. AFS display names do not participate in this lookup.
    Bytes read_resource(std::uint16_t scenario,std::string_view key) const;
    //1A9F20 reads whole AFS sectors and returns that storage extent. Preserve
    // actual archive padding; do not append invented zero bytes to the member.
    Bytes read_resource_sectors(std::uint16_t scenario,std::string_view key) const;

private:
    struct Member { std::string name; std::uint64_t offset{}; std::uint32_t size{},storage_bytes{}; };
    static_assert(sizeof(Member)==sizeof(std::string)+16);
    std::shared_ptr<const reo::assets::Source> archive_;
    std::array<std::vector<Member>,5> members_;
    std::array<std::vector<Member>,5> ordinal_members_;
    std::array<std::vector<Member>,5> resources_;
    Bytes read(const Member&) const;
    const Member* resource(std::uint16_t,std::string_view)const;
};
}
