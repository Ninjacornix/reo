#pragma once
#include <cstdint>
#include <functional>
#include <memory>
#include <vector>
#define PS2_RUNTIME_HAS_EXTERNAL_WORKERS 1
inline std::uint32_t ps2RamBackingBytes = 32u * 1024u * 1024u;
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
    bool sealed{}, accept=true, stopped{};
    std::vector<std::shared_ptr<ExternalWorker>> workers;
    Memory& memory() { return memory_; }
    bool isStopRequested() const { return stopped; }
    bool registerExternalWorker(std::shared_ptr<ExternalWorker> worker) noexcept {
        if (!worker || sealed || !accept) return false;
        try { workers.push_back(std::move(worker)); return true; } catch (...) { return false; }
    }
    void stop() { sealed = true; stopped = true; for (auto& worker : workers) worker->requestStop(); }
    bool join() { for (auto& worker : workers) if (!worker->join()) return false; return true; }
private:
    Memory memory_;
};
