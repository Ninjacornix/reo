#pragma once
#include "gs_backend_route.h"
#include <thread>
class PS2Runtime;
class GS;
namespace gs_backend_bridge {
enum class SoundRamProfileStatusV1:std::uint8_t {ok,unavailable,busy,leased,foreign_runtime,unsupported,capacity,allocation_failed};
struct FactoryEntryV1;
// Pure concrete-backend metadata probe, attached to its actual factory. No
// provider/GPU/guest work, allocation, Route/factory reentry or logging.
Factory withSoundRamProfileProbeV1(Factory,SoundRamProfileProbeV1);
SoundRamProfileStatusV1 tryRegisterFactoryV1(Factory);
class FactorySnapshotV1 final {
public:FactorySnapshotV1()=default;
private:
    std::shared_ptr<const FactoryEntryV1> entry_;std::uint64_t generation_{};
    friend FactorySnapshotV1 registeredFactoryV1();friend Factory registeredFactory();friend class Route;
};
FactorySnapshotV1 registeredFactoryV1();
struct GlobalGsControlResultV1;
class GlobalGsControlV1 final {
public:
    GlobalGsControlV1()=default;
    GlobalGsControlV1(GlobalGsControlV1&&) noexcept;
    GlobalGsControlV1& operator=(GlobalGsControlV1&&) noexcept;
    ~GlobalGsControlV1();
    GlobalGsControlV1(const GlobalGsControlV1&)=delete;
    GlobalGsControlV1& operator=(const GlobalGsControlV1&)=delete;
    explicit operator bool()const noexcept{return active_;}
private:
    bool active_{},outer_{};std::thread::id thread_;std::uint64_t generation_{};
    void release() noexcept;
    std::uint64_t profilePermitV1()const noexcept;
    friend struct GlobalGsControlResultV1;
    friend GlobalGsControlResultV1 acquireGlobalGsControlV1() noexcept;
    friend SoundRamProfileResultV1 acquireSoundRamProfileBeforeRunV1(PS2Runtime&) noexcept;
};
struct GlobalGsControlResultV1 {SoundRamProfileStatusV1 status;GlobalGsControlV1 control;};
// Same-thread nested control lifetime. No mutex retained across initialization,
// worker join, factory/device calls. Blocks lease mint across ALL global effects.
GlobalGsControlResultV1 acquireGlobalGsControlV1() noexcept;
struct SoundRamProfileIdentityV1 {
    PS2Runtime* runtime{};const void* ee{};const void* iop{};const void* vram{};const GS* gs{};
};
class SoundRamSelectionLeaseV1 final {
public:
    SoundRamSelectionLeaseV1()=default;
    SoundRamSelectionLeaseV1(SoundRamSelectionLeaseV1&&) noexcept;
    SoundRamSelectionLeaseV1& operator=(SoundRamSelectionLeaseV1&&) noexcept;
    ~SoundRamSelectionLeaseV1();
    SoundRamSelectionLeaseV1(const SoundRamSelectionLeaseV1&)=delete;
    SoundRamSelectionLeaseV1& operator=(const SoundRamSelectionLeaseV1&)=delete;
    explicit operator bool()const noexcept{return route_!=nullptr;}
    bool matches(const PS2Runtime&,const void* ee,const void* iop)const noexcept;
    std::uint64_t incarnation()const noexcept{return incarnation_;}
    std::uint64_t factory_generation()const noexcept{return factory_generation_;}
    // CONTROL ONLY after audio outer drain + device fence, outside guest/RPC/
    // PCM/bank/provider/GS-owner locks. Does not stop a device or join a worker.
    void release() noexcept;
private:
    Route* route_{};SoundRamProfileIdentityV1 identity_{};
    std::uint64_t incarnation_{},factory_generation_{};std::size_t runtime_slot_{};
    friend class Route;
};
struct SoundRamProfileResultV1 {SoundRamProfileStatusV1 status{SoundRamProfileStatusV1::unavailable};SoundRamSelectionLeaseV1 lease;};
// Actual SDK gateway: real pre-run setup + actual GS owner control/FIFO. This
// proves selection/config exclusion only, NOT guest/CD/Pad/RAM read authority.
SoundRamProfileResultV1 acquireSoundRamProfileBeforeRunV1(PS2Runtime&) noexcept;
bool soundRamProfileHeldForRuntimeV1(const PS2Runtime*) noexcept;
bool soundRamSelectionHeldV1() noexcept;
} // namespace gs_backend_bridge
