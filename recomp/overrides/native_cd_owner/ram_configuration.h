#pragma once
#include <cstddef>
#include <cstdint>
#include <memory>

class PS2Runtime;
namespace reo_cd_async {
struct RamConfigurationState;
struct ConfigurationResult;
enum class RamWriteMode { unknown, synchronous, asynchronous };
enum class ConfigurationStatus { observed, phase_closed, invalid_identity, conflict, unavailable };

// A configuration seal only. The enclosing admitted audio/runtime owner must
// separately retain actual RAM and parent storage through all accepted calls.
// No guest pointer, read authority or writer reservation is supplied here.
class SyncRamWriteSeal final {
public:
    SyncRamWriteSeal() = default;
    SyncRamWriteSeal(SyncRamWriteSeal&&) noexcept;
    SyncRamWriteSeal& operator=(SyncRamWriteSeal&&) noexcept;
    ~SyncRamWriteSeal();
    SyncRamWriteSeal(const SyncRamWriteSeal&) = delete;
    SyncRamWriteSeal& operator=(const SyncRamWriteSeal&) = delete;
    explicit operator bool() const noexcept;
    [[nodiscard]] bool matches(const PS2Runtime&,const std::uint8_t*,std::size_t) const noexcept;
    [[nodiscard]] std::uint64_t generation() const noexcept;
private:
    explicit SyncRamWriteSeal(std::shared_ptr<RamConfigurationState>) noexcept;
    void release() noexcept;
    std::shared_ptr<RamConfigurationState> state_;
    friend class ConfigurationReceipt;
};

// Only the actual configure branch can issue one. A receipt is an observation,
// not a seal; a later unsealed reconfiguration makes it stale.
class ConfigurationReceipt final {
public:
    ConfigurationReceipt() = default;
    [[nodiscard]] SyncRamWriteSeal try_seal(PS2Runtime&,const std::uint8_t*,std::size_t) const noexcept;
    [[nodiscard]] std::uint64_t generation() const noexcept;
private:
    explicit ConfigurationReceipt(std::shared_ptr<RamConfigurationState>) noexcept;
    std::shared_ptr<RamConfigurationState> state_;
    friend ConfigurationResult configureWithReceipt(const char*,std::uint8_t*,std::size_t,PS2Runtime&) noexcept;
};
struct ConfigurationResult {
    ConfigurationStatus status{ConfigurationStatus::unavailable};
    RamWriteMode mode{RamWriteMode::unknown};
    ConfigurationReceipt receipt;
};

// Native-worker build only: this is the branch actually compiled behind
// REO_BUILD_NATIVE_RESOURCE_OWNER. The legacy detached-worker build has no
// equivalent qualification and must remain unsupported by a capture factory.
[[nodiscard]] ConfigurationResult configureWithReceipt(
    const char* serial,std::uint8_t* memory,std::size_t bytes,PS2Runtime&) noexcept;
} // namespace reo_cd_async
