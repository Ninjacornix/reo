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

    std::optional<ScriptBank> scenario_scripts(std::uint16_t scenario) const;
    std::optional<RdtDirectory> room(RoomId id) const;
    Bytes read_member(std::uint16_t scenario,std::string_view name) const;

private:
    struct Member { std::string name; std::uint64_t offset{}; std::uint32_t size{}; };
    std::shared_ptr<const reo::assets::Source> archive_;
    std::array<std::vector<Member>,5> members_;
};
}
