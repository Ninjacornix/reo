#pragma once
#include "inventory.hpp"
#include <span>
namespace reo::native::gameplay_world {
// Session-owned recovery lists are distinct from live actor inventory. Admit
// the four primary-player lists; signed/extended indices refuse when reached.
// Borrowed canonical inventory/resource/template owners outlive this facade.
class ResourceAuxiliaryLists final {
public:
    explicit ResourceAuxiliaryLists(WorldInventory&);
    bool append_ready(std::uint32_t actor,std::span<const std::uint8_t>,std::int32_t count)const noexcept;
    std::int8_t append(std::uint32_t actor,std::span<const std::uint8_t>,std::int32_t count); //5B5F10
    std::int8_t remove(std::uint32_t actor,std::uint32_t resource); //5B6180
    std::int8_t regroup(std::uint32_t actor); //5B6300
private:
    using Groups=std::array<std::array<std::uint8_t,8>,4>;
    World& world_;gameplay_scenario::SceneResources& resources_;
    const gameplay_scenario::ResourceTemplates& templates_;
    std::array<std::uint8_t,8>& list(std::uint32_t)const;
    gameplay_scenario::SceneDescriptor descriptor(std::uint8_t)const;
    unsigned group(const gameplay_scenario::SceneDescriptor&)const;
    static unsigned emit(std::array<std::uint8_t,8>&,const Groups&,const std::array<unsigned,4>&);
};
}
