#pragma once
#include <cstdint>
#include <atomic>
#include <condition_variable>
#include <functional>
#include <memory>
#include <mutex>
#include <stdexcept>
#include <utility>
#include <vector>
#define PS2_RUNTIME_HAS_EXTERNAL_WORKERS 1
inline std::uint32_t ps2RamBackingBytes = 32u * 1024u * 1024u;
#include "exact_layout.inc"
// Fake registration/RAM surroundings for actual dispatch + authored binding.
// No real guest execution, runtime worker thread or device is created here.
class PS2Runtime {
public:
    struct Memory {
        std::vector<std::uint8_t> bytes = std::vector<std::uint8_t>(32u * 1024u * 1024u);
        std::uint8_t* getRDRAM() { return bytes.data(); }
    };
    class GuestExecutionScope { public: explicit GuestExecutionScope(PS2Runtime*) {} };
    class ExternalWorker {public:virtual ~ExternalWorker()=default;virtual void requestStop() noexcept=0;virtual bool join() noexcept=0;};
    using ExternalWorkerList = std::vector<std::shared_ptr<ExternalWorker>>;
    std::mutex m_externalWorkersMutex;
    std::shared_ptr<ExternalWorkerList> m_externalWorkers = std::make_shared<ExternalWorkerList>();
    bool m_externalWorkersSealed = false;
    std::condition_variable m_preRunSetupChanged;
    std::size_t m_preRunSetupCount = 0;
    std::atomic<bool> m_stopRequested{false};
#include "exact_lease.inc"
    PreRunSetupLease acquirePreRunSetup() noexcept;
    void releasePreRunSetup() noexcept;
    bool externalWorkerResetAllowed();
    void beginExternalWorkerRun();
    bool accept = true;
    ExternalWorkerList& workers = *m_externalWorkers;
    Memory& memory() { return memory_; }
    bool isStopRequested() const { return m_stopRequested.load(std::memory_order_acquire); }
    bool registerExternalWorker(std::shared_ptr<ExternalWorker> worker) noexcept {
        if (!worker || !accept) return false;
        try {
            std::lock_guard lock(m_externalWorkersMutex);
            if (m_externalWorkersSealed || m_stopRequested) return false;
            workers.push_back(std::move(worker)); return true;
        } catch (...) { return false; }
    }
    void stop() {
        std::shared_ptr<ExternalWorkerList> snapshot;
        {
            std::lock_guard lock(m_externalWorkersMutex);
            if (m_stopRequested.exchange(true)) return;
            m_externalWorkersSealed = true;
            snapshot = m_externalWorkers;
        }
        for (auto& worker : *snapshot) worker->requestStop();
    }
    bool join() { for (auto& worker : workers) if (!worker->join()) return false; return true; }
private:
    Memory memory_;
};
