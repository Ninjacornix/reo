#pragma once
#include "../../../game/native/audio_banks/v2/session.hpp"
#include <array>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <span>

namespace reo::native::bank_packets {
namespace banks=audio_banks::v2;
// Supplied by an independently qualified runtime owner. These values are NOT
// evidence that a caller actually verified an executable or retained its RAM.
struct MemoryIdentity {
    std::uint32_t schema{1};
    std::array<std::uint8_t,16> session{};
    std::array<std::uint8_t,32> executable_sha256{},native_build_sha256{};
    std::uint64_t runtime_incarnation{},ram_incarnation{},ram_bytes{};
    bool operator==(const MemoryIdentity&)const=default;
};
enum class Status {ok,rejected,closed,unsupported,invalid_input,invalid_asset,
    capacity,no_memory,stale_generation,foreign_runtime,capture_failed};
template<class T>struct Result {Status status{Status::invalid_input};T value{};};
enum class Part {hd,bd,tq};
// The outer aggregate SoundCall must retain the actual runtime/RAM owner before
// constructing a source or doing any guest read. Sources are synchronous caller
// capabilities: adapter calls never retain their pointers or borrowed spans.
// identity() must be allocation-free; reads must own their lifetime and perform
// a synchronized/coherent copy, with no source-global or device-lock inversion.
// An identity comparison alone does not freeze guest writers or make memcpy of
// concurrently written C++ storage safe. The concrete runtime provider must
// establish that property. Host test providers are not runtime qualification.
class CaptureSource {
public:
    virtual ~CaptureSource()=default;
    virtual MemoryIdentity identity()const noexcept=0;
    virtual bool packet_present()const noexcept=0;
    virtual std::size_t packet_bytes()const noexcept=0;
    virtual std::size_t ram_view_bytes()const noexcept=0;
    virtual bool ram_present()const noexcept=0;
    virtual bool copy_packet(std::span<std::uint8_t>)const noexcept=0;
    virtual bool copy_ram(std::size_t offset,std::span<std::uint8_t>)const noexcept=0;
    virtual banks::BankSizes direct_bank_sizes()const noexcept=0;
    virtual bool copy_bank(Part,std::span<std::uint8_t>)const noexcept=0;
};
struct Config {
    std::uint32_t max_calls{16},max_packet_bytes{65536};
    std::size_t control_byte_budget{2u*1024u*1024u};
    // All allocation providers (including the Session's asset provider) must
    // be concurrent, memory-only and nonreentrant into adapter/session APIs.
    // Control frees may run under packet-prefix transaction serialization.
    std::shared_ptr<banks::AllocationSource> control_allocation_source;
};
struct PacketResult {
    Status status{Status::invalid_input};
    bool parser_accepted{};
    std::size_t consumed{},commands_applied{};
};
struct State;
class PacketAdapter;
class Call final {
public:
    Call()=default;Call(Call&&)noexcept;Call& operator=(Call&&)noexcept;
    ~Call();Call(const Call&)=delete;Call& operator=(const Call&)=delete;
    explicit operator bool()const noexcept{return bool(state_);}
private:
    friend class PacketAdapter;
    Call(std::shared_ptr<State>,std::uint32_t,banks::Submission)noexcept;
    void release()noexcept;
    std::shared_ptr<State> state_;
    std::uint32_t slot_{UINT32_MAX};
    banks::Submission submission_;
};
// Only producer/control capture/admission lives here. Numerical bank algorithms,
// render, gain hooks and clip retirement remain in the separately owned Session.
// This adapter does not select a backend or acknowledge SIF/RPC requests.
class PacketAdapter final {
public:
    PacketAdapter(std::shared_ptr<banks::Session>,MemoryIdentity,Config={});
    [[nodiscard]] Result<Call> begin_call()noexcept;
    [[nodiscard]] PacketResult submit_packet(Call&,const CaptureSource&)noexcept;
    [[nodiscard]] Status submit_bank(Call&,unsigned port,const CaptureSource&)noexcept;
    [[nodiscard]] Result<std::uint32_t> pending_loads(Call&)noexcept;
    [[nodiscard]] Result<std::uint32_t> port_state(Call&,unsigned,std::uint32_t&)noexcept;
    [[nodiscard]] Result<std::uint32_t> sequence_state(Call&,unsigned,unsigned,unsigned)noexcept;
    [[nodiscard]] Status reset(Call&)noexcept;
    // Only under an already admitted aggregate render. Shares the original
    // packet-prefix serialization; does not reacquire producer admission.
    // GainProvider is pure/nonreentrant under transaction + Session data locks.
    [[nodiscard]] Status mix_add(float*,std::uint32_t,banks::GainProvider&)noexcept;
    // Signals producer admission only; it does not close the inner bank render
    // owner. The aggregate owner must stop it after accepted composite renders
    // finish. Accepted commits may finish after this signal; join is the fence.
    void request_stop()noexcept;
    // Release own Calls before joining. Caller must not invoke this from a
    // CaptureSource callback; the complete outer worker owns that obligation.
    void join()noexcept;
    [[nodiscard]] banks::BudgetSnapshot control_budget()const noexcept;
private:
    std::shared_ptr<State> state_;
};
} // namespace reo::native::bank_packets
