#pragma once
#include "../adxt_service_group/service_group.hpp"
#include <array>
#include <cstdint>
#include <memory>

namespace reo::native::adxt_transfer_groups {
namespace group=adxt_service_group;
inline constexpr std::uint32_t dtr_slots=32,dtx_slots=8;
class ChunkGuard {
public:
    virtual ~ChunkGuard()=default;
    virtual void enter()noexcept=0;
    virtual void leave()noexcept=0;
};
class DtxGroup final:public group::Work {
public:
    explicit DtxGroup(std::shared_ptr<ChunkGuard>);
    [[nodiscard]] bool set(std::uint32_t,std::shared_ptr<group::ActiveWork>)noexcept;
    void service()noexcept override;
private:
    std::shared_ptr<ChunkGuard> guard_;
    std::array<std::shared_ptr<group::ActiveWork>,dtx_slots> slots_{};
};
class DtrGroup final:public group::Work {
public:
    explicit DtrGroup(std::shared_ptr<DtxGroup>);
    [[nodiscard]] bool set(std::uint32_t,std::shared_ptr<group::ActiveWork>)noexcept;
    void service()noexcept override;
private:
    std::shared_ptr<DtxGroup> dtx_;
    std::array<std::shared_ptr<group::ActiveWork>,dtr_slots> slots_{};
};
// Supply this same DtxGroup to DtrGroup and the outer audio group's DTX port.
// All methods/tables share the externally serialized audio control owner.
// Per-slot transfer protocols remain separate retained children.
} // namespace reo::native::adxt_transfer_groups
