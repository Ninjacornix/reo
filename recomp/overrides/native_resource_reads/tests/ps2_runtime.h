#pragma once
#define PS2_RUNTIME_HAS_EXTERNAL_WORKERS 1
#include <atomic>
#include <cstdint>
#include <memory>
#include <mutex>
#include <vector>
#include <utility>

constexpr std::uint32_t PS2_RAM_SIZE = 32u * 1024u * 1024u;
class PS2Runtime;
inline thread_local PS2Runtime* mock_guest_runtime = nullptr;
inline thread_local unsigned mock_guest_depth = 0;

class PS2Runtime {
public:
    class ExternalWorker {
    public:
        virtual ~ExternalWorker() = default;
        virtual void requestStop() noexcept = 0;
        virtual bool join() noexcept = 0;
    };
    struct Memory {
        std::vector<std::uint8_t> bytes = std::vector<std::uint8_t>(PS2_RAM_SIZE);
        std::uint8_t* getRDRAM() noexcept { return bytes.data(); }
    };
    class GuestExecutionScope {
        PS2Runtime* prior_ = mock_guest_runtime;
        unsigned prior_depth_ = mock_guest_depth;
    public:
        explicit GuestExecutionScope(PS2Runtime* runtime) {
            mock_guest_runtime = runtime;
            mock_guest_depth = prior_ == runtime ? prior_depth_ + 1 : 1;
        }
        ~GuestExecutionScope() { mock_guest_runtime = prior_; mock_guest_depth = prior_depth_; }
    };
    ~PS2Runtime() { requestStop(); if (!joinWorkers()) std::terminate(); }
    Memory& memory() noexcept { return memory_; }
    bool isStopRequested() const noexcept { return stopping.load(); }
    class PreRunSetupLease {
        PS2Runtime* owner_{};
        friend class PS2Runtime;
        explicit PreRunSetupLease(PS2Runtime* owner):owner_(owner){++owner_->setup_leases;}
    public:
        PreRunSetupLease()=default;
        PreRunSetupLease(const PreRunSetupLease&)=delete;
        PreRunSetupLease(PreRunSetupLease&& other)noexcept:owner_(std::exchange(other.owner_,nullptr)){}
        ~PreRunSetupLease(){if(owner_)--owner_->setup_leases;}
        explicit operator bool()const noexcept{return owner_!=nullptr;}
    };
    PreRunSetupLease acquirePreRunSetup()noexcept {
        ++setup_attempts;
        return setup_allowed && !stopping.load()?PreRunSetupLease(this):PreRunSetupLease();
    }
    bool registerExternalWorker(std::shared_ptr<ExternalWorker> worker) noexcept {
        if (!registration_allowed || stopping.load()) return false;
        try {
            workers_.push_back(std::move(worker));
            ++registrations;
            return true;
        } catch (...) { return false; }
    }
    void requestStop() noexcept {
        stopping.store(true);
        for (auto& worker : workers_) worker->requestStop();
    }
    bool joinWorkers() noexcept {
        for (auto& worker : workers_) if (!worker->join()) return false;
        return true;
    }
    bool registration_allowed = true;
    bool setup_allowed=true;
    unsigned setup_leases{},setup_attempts{};
    std::atomic<bool> stopping{false};
    unsigned registrations{};
private:
    Memory memory_;
    std::vector<std::shared_ptr<ExternalWorker>> workers_;
};

inline std::uint32_t ps2ActualGuestExecutionDepth(PS2Runtime* runtime) noexcept {
    return mock_guest_runtime == runtime ? mock_guest_depth : 0;
}
