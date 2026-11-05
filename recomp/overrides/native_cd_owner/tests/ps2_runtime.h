#pragma once
#define PS2_RUNTIME_HAS_EXTERNAL_WORKERS 1
#include <array>
#include <atomic>
#include <cstdint>
#include <memory>
#include <mutex>
#include <unordered_map>
#include <vector>

constexpr std::uint32_t PS2_RAM_SIZE = 32u * 1024u * 1024u;
struct R5900Context {
    std::array<std::uint64_t, 32> gpr{};
    std::uint32_t pc{};
};
class PS2Runtime {
public:
    class ExternalWorker {
    public:
        virtual ~ExternalWorker() = default;
        virtual void requestStop() noexcept = 0;
        virtual bool join() noexcept = 0;
    };
    using Function = void (*)(std::uint8_t*, R5900Context*, PS2Runtime*);
    using RecompiledFunction = Function;
    struct Memory {
        std::vector<std::uint8_t> bytes = std::vector<std::uint8_t>(PS2_RAM_SIZE);
        std::uint8_t* getRDRAM() { return bytes.data(); }
    };
    class GuestExecutionScope {
    public:
        explicit GuestExecutionScope(PS2Runtime* runtime) : runtime_(runtime), lock_(runtime->guest_mutex) {
            ++runtime_->guest_depth;
        }
        ~GuestExecutionScope() { --runtime_->guest_depth; }
    private:
        PS2Runtime* runtime_;
        std::unique_lock<std::recursive_mutex> lock_;
    };
    ~PS2Runtime() { stopAndFinish(); }
    Memory& memory() { return memory_; }
    bool registerExternalWorker(std::shared_ptr<ExternalWorker> worker) {
        if (!registration_allowed || stopping.load()) return false;
        workers.push_back(std::move(worker));
        return true;
    }
    void requestStop() {
        stopping.store(true);
        for (auto& worker : workers) worker->requestStop();
    }
    bool isStopRequested() const { return stopping.load(); }
    void stopAndFinish() {
        requestStop();
        for (auto& worker : workers) if (!worker->join()) std::terminate();
        kernel_alive.store(false);
    }
    std::uint32_t reserveAsyncCallbackStack(std::uint32_t size, std::uint32_t alignment) {
        ++stack_reservations;
        return size == 0x4000 && alignment == 16 && stack_available ? 0x1FEFFF0u : 0;
    }
    bool hasFunction(std::uint32_t pc) const { return functions.contains(pc); }
    Function lookupFunction(std::uint32_t pc) const { return functions.at(pc); }
    std::unordered_map<std::uint32_t, Function> functions;
    std::atomic<bool> stopping{false}, kernel_alive{true};
    std::atomic<unsigned> guest_depth{0};
    bool registration_allowed{true}, stack_available{true};
    unsigned stack_reservations{};
private:
    Memory memory_;
    std::recursive_mutex guest_mutex;
    std::vector<std::shared_ptr<ExternalWorker>> workers;
};
