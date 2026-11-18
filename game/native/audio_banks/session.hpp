#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <memory>
#include <span>
#include <variant>
#include <vector>

namespace reo::native::audio_banks {
inline constexpr unsigned port_count=14, request_count=16, voice_capacity=48;
inline constexpr unsigned output_rate=48000, frames_per_tick=200;
enum class Status { ok, skipped, closed, invalid_input, invalid_asset, invalid_submission,
    stale_generation, capacity, no_memory, unsupported_gain, numeric_domain, counter_limit };
template<class T>struct Result {Status status{Status::invalid_input};T value{};};
struct OwnedBankBytes {std::vector<std::uint8_t> hd,bd,tq;};
struct Config {
    std::uint32_t max_submissions{16},max_render_frames{262144};
    std::uint64_t max_generation{std::numeric_limits<std::uint64_t>::max()};
    bool path_counters{};
};
struct State;
struct AssetData;
struct Identity;
class Session;
// Retain this move-only lease across future capture/read/decode/install. It
// keeps State alive. Release all own submissions before calling join().
class Submission final {
public:
    Submission()=default;
    Submission(Submission&&) noexcept;
    Submission& operator=(Submission&&) noexcept;
    ~Submission();
    Submission(const Submission&)=delete;
    Submission& operator=(const Submission&)=delete;
    explicit operator bool() const noexcept{return bool(state_);}
private:
    friend class Session;
    Submission(std::shared_ptr<State>,std::uint32_t,std::uint64_t) noexcept;
    void release() noexcept;
    std::shared_ptr<State> state_;
    std::uint32_t slot_{UINT32_MAX};
    std::uint64_t generation_{};
};
class PreparedBank final {
public:
    PreparedBank()=default;
    explicit operator bool() const noexcept{return bool(data_);}
    std::uint64_t fingerprint() const noexcept;
    unsigned sequence_count() const noexcept;
private:
    friend class Session;
    std::shared_ptr<const AssetData> data_;
    std::weak_ptr<const Identity> owner_;
    std::uint64_t epoch_{};
};
enum class LoadPolicy {force,if_unloaded};
struct StartRequest {std::uint8_t port{},index{},group{},volume{127},pan{64};std::uint16_t pitch{0x2000};std::uint8_t program_offset{};};
struct ChangeRequest {std::uint8_t port{},index{},group{},volume{255},pan{255};std::uint16_t pitch{65535};};
struct CancelRequest {std::uint8_t port{},index{},group{};};
struct StopAll {bool unload{};};
struct StopPort {unsigned port{};bool unload{};};
struct SetAllVolumes {std::uint16_t value{};};
struct SetPortVolume {unsigned port{};std::uint16_t value{};};
struct SetMuted {bool value{};};
struct SetMono {bool value{};};
enum class DiagnosticKind:std::uint8_t {velocity_curve,sample_decode,voice_capacity,tq_control,tq_opcode,reverb,global_control};
struct UnsupportedControl {DiagnosticKind kind{DiagnosticKind::global_control};std::uint32_t value{};};
using Command=std::variant<StartRequest,ChangeRequest,CancelRequest,StopAll,StopPort,
    SetAllVolumes,SetPortVolume,SetMuted,SetMono,UnsupportedControl>;
struct ApplyResult {Status status{Status::invalid_input};std::size_t applied{};};
class GainProvider {
public:
    virtual ~GainProvider()=default;
    // Exactly224 reads per nonnull positive mix, in port/slot order. Pure,
    // noexcept, no session/provider/guest reentry. Session holds its data lock.
    virtual float gain(unsigned port,unsigned sequence,std::uint64_t hd_fingerprint) noexcept=0;
};
struct SequenceInfo {std::uint32_t cursor{};std::uint16_t wait{};std::uint8_t program_offset{};bool active{},has_note{};};
struct RequestInfo {
    SequenceInfo sequence;
    std::uint8_t index{},group{},priority{},cancel_flags{},request_volume{},request_pan{};
    std::uint16_t request_pitch{},pitch{};
    unsigned program{},volume{},expression{},pan{};
    std::uint64_t age{};
};
struct PortInfo {bool loaded{};unsigned volume{},sequence_count{};std::uint64_t fingerprint{};std::array<RequestInfo,request_count> requests;};
struct VoiceInfo {
    unsigned port{},slot{};std::uint8_t note{},group{},velocity{};std::uint32_t bd_offset{};
    double position{},step{};int cached_bend{},envelope_phase{},envelope_value{};
    std::uint32_t envelope_countdown{};std::uint16_t adsr1{},adsr2{};bool active{};
};
struct DiagnosticEvent {DiagnosticKind kind{};std::uint32_t value{};};
struct Diagnostics {
    std::uint64_t unsupported{},loads{},active_voice_frames{},signal_voice_frames{},requests{};
    std::array<DiagnosticEvent,32> events{};std::size_t event_count{};
};
struct Snapshot {
    std::array<PortInfo,port_count> ports;
    std::array<VoiceInfo,voice_capacity> voices;
    std::size_t voice_count{},retired_clips{};
    std::uint64_t request_age{},frame_clock{};bool muted{},mono{};
    Diagnostics diagnostics;
};
// No guest memory, raw packets, file/device/runtime, worker or clock in this
// component. State/DSP is source-derived; session admission is a new contract.
class Session final {
public:
    explicit Session(Config={});
    ~Session();
    Session(const Session&)=delete;Session& operator=(const Session&)=delete;
    [[nodiscard]] Result<Submission> begin_submission() noexcept;
    [[nodiscard]] Result<PreparedBank> prepare(const Submission&,OwnedBankBytes) noexcept;
    [[nodiscard]] Status install(const Submission&,unsigned port,const PreparedBank&,LoadPolicy=LoadPolicy::force) noexcept;
    [[nodiscard]] ApplyResult apply(std::span<const Command>) noexcept;
    [[nodiscard]] ApplyResult apply(const Submission&,std::span<const Command>) noexcept;
    [[nodiscard]] Result<std::uint32_t> port_state(unsigned port,std::uint32_t& sequences) const noexcept;
    [[nodiscard]] Result<std::uint32_t> sequence_state(unsigned port,unsigned index,unsigned group) const noexcept;
    [[nodiscard]] Result<std::uint32_t> pending_loads() const noexcept;
    [[nodiscard]] Status mix_add(float* stereo,std::uint32_t frames,GainProvider&) noexcept;
    [[nodiscard]] Status reset() noexcept;
    void request_stop() noexcept;
    // Control only. Release own Submission objects first; returns false from a
    // current operation/gain callback instead of waiting on its own call lease.
    [[nodiscard]] bool join() noexcept;
    // Reclaim deferred last clip leases on producer/control side, outside locks.
    [[nodiscard]] Status drain_retired() noexcept;
    [[nodiscard]] Snapshot snapshot() const noexcept;
private:
    std::shared_ptr<State> state_;
};
} // namespace reo::native::audio_banks
