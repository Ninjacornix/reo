#pragma once
#include "../audio_banks/v2/session.hpp"
#include "../../../recomp/overrides/native_banks/v3/packet_adapter.h"
#include <atomic>
#include <optional>

namespace reo::native::adxt_output_session { struct State; class Session; }
namespace reo::native::audio_mix_tail {
namespace banks=audio_banks::v2;
namespace packets=bank_packets::v3;
struct PacketProfile {packets::MemoryIdentity identity;packets::Config config;};
class MasterGain {
public:
    virtual ~MasterGain()=default;
    // Pure/noexcept, bounded and nonreentrant. No guest work, I/O or joins.
    virtual float gain() noexcept=0;
};
enum class Status { completed,closed,bank_failure,invalid_master_gain };
struct Snapshot {
    banks::Snapshot banks;
    std::uint64_t render_calls{},completed_frames{},bank_failures{},master_failures{};
    Status last_status{Status::completed};
    bool bound{},stopping{},joined{};
};
// The bank Session remains private: only its bound output may advance audio.
// Control callers release ALL bank Submission leases before output join.
class Mixer final {
public:
    Mixer(banks::Config,std::shared_ptr<banks::GainProvider>,std::shared_ptr<MasterGain>,std::optional<PacketProfile> = {});
    Mixer(const Mixer&)=delete;Mixer& operator=(const Mixer&)=delete;
    [[nodiscard]] banks::Result<banks::Submission> begin_submission() noexcept;
    [[nodiscard]] banks::Result<banks::CapturedBank> capture(const banks::Submission&,banks::BankSizes) noexcept;
    [[nodiscard]] banks::Result<banks::PreparedBank> prepare(const banks::Submission&,banks::CapturedBank) noexcept;
    [[nodiscard]] banks::Status install(const banks::Submission&,unsigned,const banks::PreparedBank&,banks::LoadPolicy=banks::LoadPolicy::force) noexcept;
    [[nodiscard]] banks::ApplyResult apply(std::span<const banks::Command>) noexcept;
    [[nodiscard]] banks::Status reset() noexcept;
    [[nodiscard]] banks::Status drain_retired() noexcept;
    [[nodiscard]] std::shared_ptr<const banks::Budget> budget_observer() const noexcept;
    [[nodiscard]] Snapshot snapshot() const noexcept;
    // Optional original-qualified grouped capture path. Direct bank controls
    // refuse in this profile, preserving the adapter's prefix transaction lock.
    [[nodiscard]] packets::Result<packets::Call> begin_call() noexcept;
    [[nodiscard]] packets::PacketResult submit_packet(packets::Call&,const packets::CaptureSource&) noexcept;
    [[nodiscard]] packets::Status submit_bank(packets::Call&,unsigned,const packets::CaptureSource&) noexcept;
    [[nodiscard]] packets::Status reset(packets::Call&) noexcept;
private:
    friend struct adxt_output_session::State;
    friend class adxt_output_session::Session;
    [[nodiscard]] bool bind() noexcept;
    [[nodiscard]] Status render(float*,std::uint32_t) noexcept;
    void request_stop() noexcept;
    [[nodiscard]] bool join() noexcept;
    std::shared_ptr<banks::Session> banks_;
    std::unique_ptr<packets::PacketAdapter> packets_;
    std::shared_ptr<banks::GainProvider> bank_gains_;
    std::shared_ptr<MasterGain> master_;
    std::atomic<bool> bound_{},stopping_{},joined_{};
    std::atomic<std::uint64_t> render_calls_{},frames_{},bank_failures_{},master_failures_{};
    std::atomic<Status> last_status_{Status::completed};
};
}
