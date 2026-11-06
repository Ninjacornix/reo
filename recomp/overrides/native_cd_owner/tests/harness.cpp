#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include "ps2_syscalls.h"
#include "reo_hw_bridge.h"
#include "../runtime_adapter.h"

#include <chrono>
#include <condition_variable>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <future>
#include <iostream>
#include <new>
#include <stdexcept>
#include <string>
#include <thread>

using namespace std::chrono_literals;
namespace { std::atomic<bool> fail_allocation{false}; }
#if defined(__GNUC__)
#define TEST_NOINLINE __attribute__((noinline))
#else
#define TEST_NOINLINE __declspec(noinline)
#endif
TEST_NOINLINE void* operator new(std::size_t size) {
    if (fail_allocation.exchange(false)) throw std::bad_alloc();
    if (auto* memory = std::malloc(size ? size : 1)) return memory;
    throw std::bad_alloc();
}
TEST_NOINLINE void operator delete(void* memory) noexcept { std::free(memory); }
TEST_NOINLINE void operator delete(void* memory, std::size_t) noexcept { std::free(memory); }
TEST_NOINLINE void* operator new[](std::size_t size) { return ::operator new(size); }
TEST_NOINLINE void operator delete[](void* memory) noexcept { ::operator delete(memory); }
TEST_NOINLINE void operator delete[](void* memory, std::size_t) noexcept { ::operator delete(memory); }

namespace {
unsigned checks{};
void check(bool value, const char* expression) {
    ++checks;
    if (!value) throw std::runtime_error(expression);
}
#define CHECK(...) check(static_cast<bool>(__VA_ARGS__), #__VA_ARGS__)
constexpr std::uint32_t client = 0x208AD0, send = 0x207A00, callback_pc = 0x1004D8;
std::atomic<unsigned> callback_entries{0}, callback_completions{0};
std::atomic<bool> callback_invalid{false}, throw_callback{false};
std::atomic<bool> continue_callback{false};

struct Gate {
    std::mutex mutex;
    std::condition_variable changed;
    bool entered{}, released{};
    void block() {
        std::unique_lock lock(mutex);
        entered = true; changed.notify_all();
        if (!changed.wait_for(lock, 5s, [&] { return released; })) throw std::runtime_error("Test gate deadline");
    }
    void wait() {
        std::unique_lock lock(mutex);
        CHECK(changed.wait_for(lock, 2s, [&] { return entered; }));
    }
    void release() { std::lock_guard lock(mutex); released = true; changed.notify_all(); }
};
struct ReleaseOnExit { Gate& gate; ~ReleaseOnExit() { gate.release(); } };
Gate* callback_gate{};

template<class Predicate> void wait_for(Predicate predicate) {
    const auto deadline = std::chrono::steady_clock::now() + 2s;
    while (!predicate() && std::chrono::steady_clock::now() < deadline) std::this_thread::sleep_for(1ms);
    CHECK(predicate());
}
std::uint32_t word(std::uint8_t* ram, std::uint32_t address) {
    std::uint32_t value; std::memcpy(&value, ram + address, 4); return value;
}
void put(std::uint8_t* ram, std::uint32_t address, std::uint32_t value) { std::memcpy(ram + address, &value, 4); }
void opt(const char* name, const char* value) {
#ifdef _WIN32
    _putenv_s(name, value);
#else
    setenv(name, value, 1);
#endif
}
void completed(std::uint8_t*, R5900Context* context, PS2Runtime* runtime) {
    const bool raise = throw_callback.load();
    ++callback_entries;
    if (!runtime->kernel_alive.load() || runtime->guest_depth.load() == 0 ||
        GPR_U32(context, 4) != 0x208A00 || GPR_U32(context, 28) != 0x123456 ||
        GPR_U32(context, 29) != 0x1FEFFF0 || GPR_U32(context, 31) != 0 || context->pc != callback_pc)
        callback_invalid.store(true);
    if (callback_gate) callback_gate->block();
    if (!runtime->kernel_alive.load()) callback_invalid.store(true);
    if (raise) throw std::runtime_error("Mock callback failure");
    if (continue_callback.load()) {
        context->gpr[8] = 0xCC55;
        context->pc = 0x100298;
        return;
    }
    context->pc = 0;
    ++callback_completions;
}
void continued(std::uint8_t*, R5900Context* context, PS2Runtime* runtime) {
    if (context->gpr[8] != 0xCC55 || !runtime->kernel_alive || runtime->guest_depth == 0)
        callback_invalid.store(true);
    context->pc = 0;
    ++callback_completions;
}
void seed(PS2Runtime& runtime, const char* fixture) {
    std::ifstream file(fixture, std::ios::binary);
    CHECK(bool(file));
    for (unsigned i = 0; i < 3; ++i) {
        std::array<std::uint32_t, 2> item{};
        file.read(reinterpret_cast<char*>(item.data()), sizeof(item));
        CHECK(bool(file) && item[0] < PS2_RAM_SIZE && item[1] <= PS2_RAM_SIZE - item[0]);
        file.read(reinterpret_cast<char*>(runtime.memory().getRDRAM() + item[0]), item[1]);
        CHECK(bool(file));
    }
    runtime.functions.emplace(callback_pc, completed);
}
R5900Context request(PS2Runtime& runtime) {
    auto* ram = runtime.memory().getRDRAM();
    put(ram, send, 77); put(ram, send + 4, 1); put(ram, send + 8, 0x500000);
    put(ram, send + 12, 0); put(ram, send + 16, 0x208A00); put(ram, send + 20, 0x208AC0);
    put(ram, 0x208A00, 0); put(ram, 0x208A04, 0);
    put(ram, 0x1F10000, 0x208A00);
    R5900Context context{};
    context.gpr[4] = client; context.gpr[5] = 1; context.gpr[6] = 1;
    context.gpr[7] = send; context.gpr[8] = 0x18; context.gpr[11] = callback_pc;
    context.gpr[28] = 0x123456; context.gpr[29] = 0x1F10000; context.gpr[31] = 0x101908;
    context.gpr[2] = 0xAABB;
    return context;
}
void configure(PS2Runtime& runtime) {
    reo_cd_async::configure("SLUS-20765", runtime.memory().getRDRAM(), PS2_RAM_SIZE, runtime);
}
void call(PS2Runtime& runtime) {
    auto context = request(runtime);
    reo_cd_async::sifCallRpc(runtime.memory().getRDRAM(), &context, &runtime);
    CHECK(context.gpr[2] == 0);
}
void unchanged_fallback(PS2Runtime& runtime, R5900Context context) {
    auto* ram = runtime.memory().getRDRAM();
    const std::array<std::uint32_t, 4> offsets{12, 16, 28, 32};
    for (unsigned i = 0; i < offsets.size(); ++i) put(ram, client + offsets[i], 0xAA0000 + i);
    const auto previous = ps2_syscalls::fallback_calls.load();
    reo_cd_async::sifCallRpc(ram, &context, &runtime);
    CHECK(ps2_syscalls::fallback_calls.load() == previous + 1);
    for (unsigned i = 0; i < offsets.size(); ++i) CHECK(word(ram, client + offsets[i]) == 0xAA0000 + i);
}

void operations(const char* fixture) {
    PS2Runtime runtime; ReoHwBridge bridge;
    seed(runtime, fixture); configure(runtime); reo_cd_async::Lifetime lifetime(runtime);
    CHECK(reo_cd_async::enabled && runtime.stack_reservations == 1);
    configure(runtime); CHECK(runtime.stack_reservations == 1);
    bridge.on_read = [&](auto lsn, auto count, auto destination, auto* ram) {
        if (lsn != 77 || count != 1 || destination != 0x500000 ||
            word(ram, client + 12) != 1 || word(ram, client + 16) != 1 ||
            word(ram, client + 28) != callback_pc || word(ram, client + 32) != 0x208A00)
            callback_invalid.store(true);
        std::memset(ram + destination, 0x63, count * 2048);
        return false; // Existing false-read callback policy is deliberately retained.
    };
    call(runtime);
    wait_for([] { return callback_completions.load() == 1; });
    CHECK(bridge.reads == 1 && !callback_invalid);
    CHECK(runtime.memory().getRDRAM()[0x500000] == 0x63);
    CHECK(ps2_syscalls::fallback_calls == 0);
}

void refusals(const char* fixture) {
    PS2Runtime runtime; ReoHwBridge bridge; seed(runtime, fixture);
    auto* ram = runtime.memory().getRDRAM();
    opt("REO_NATIVE_CD_OWNER", "0"); configure(runtime); CHECK(!reo_cd_async::enabled);
    opt("REO_NATIVE_CD_OWNER", "1");
    reo_cd_async::configure("SLUS-20984", ram, PS2_RAM_SIZE, runtime); CHECK(!reo_cd_async::enabled);
    reo_cd_async::configure("SLUS-20765", ram, 16, runtime); CHECK(!reo_cd_async::enabled);
    const auto old = word(ram, 0x101900); put(ram, 0x101900, old ^ 1); configure(runtime); CHECK(!reo_cd_async::enabled);
    put(ram, 0x101900, old);
    ram[0x100500] ^= 1; configure(runtime); CHECK(!reo_cd_async::enabled); ram[0x100500] ^= 1;
    ram[0x1002B0] ^= 1; configure(runtime); CHECK(!reo_cd_async::enabled); ram[0x1002B0] ^= 1;
    configure(runtime); CHECK(reo_cd_async::enabled);
    reo_cd_async::Lifetime lifetime(runtime);
    for (unsigned which = 0; which < 19; ++which) {
        auto context = request(runtime);
        if (which == 0) context.gpr[31]++;
        if (which == 1) context.gpr[4]++;
        if (which == 2) context.gpr[29] = PS2_RAM_SIZE;
        if (which == 3) context.gpr[29]++;
        if (which == 4) put(ram, send + 4, 0);
        if (which == 5) put(ram, send + 8, PS2_RAM_SIZE - 1);
        if (which == 6) put(ram, send + 4, 0x4001);
        if (which == 7) context.gpr[9] = 1;
        if (which == 8) context.gpr[10] = 1;
        if (which == 9) put(ram, 0x1F10000, 0x208A04);
        if (which == 10) ram[send + 14] = 1;
        if (which == 11) ram[send + 14] = 2;
        if (which == 12) ram[send + 14] = 255;
        if (which == 13) put(ram, send + 16, 0x208A04);
        if (which == 14) put(ram, send + 20, 0x208AC4);
        if (which == 15) put(ram, 0x208A00, 1);
        if (which == 16) put(ram, 0x208A04, 1);
        if (which == 17) put(ram, send + 8, 0x208A00);
        if (which == 18) put(ram, send + 8, 0x2089FF);
        unchanged_fallback(runtime, context);
    }
    CHECK(bridge.reads == 0 && callback_entries == 0);
}

void shutdown_during_read(const char* fixture, bool full) {
    PS2Runtime runtime; ReoHwBridge bridge; Gate gate;
    seed(runtime, fixture); configure(runtime); reo_cd_async::Lifetime lifetime(runtime);
    ReleaseOnExit release{gate};
    bridge.on_read = [&](auto, auto, auto, auto*) { gate.block(); return true; };
    call(runtime); gate.wait();
    const unsigned queued = full ? 8 : 3;
    for (unsigned i = 0; i < queued; ++i) call(runtime);
    if (full) unchanged_fallback(runtime, request(runtime));
    auto stopping = std::async(std::launch::async, [&] { runtime.stopAndFinish(); });
    CHECK(stopping.wait_for(30ms) == std::future_status::timeout);
    CHECK(runtime.kernel_alive);
    gate.release(); stopping.get();
    CHECK(!runtime.kernel_alive && bridge.reads == 1 && callback_entries == 0);
}

void callback_overlap(const char* fixture) {
    PS2Runtime runtime; ReoHwBridge bridge; Gate gate;
    seed(runtime, fixture); configure(runtime); reo_cd_async::Lifetime lifetime(runtime);
    ReleaseOnExit release{gate};
    callback_gate = &gate;
    call(runtime); gate.wait();
    auto stopping = std::async(std::launch::async, [&] { runtime.stopAndFinish(); });
    CHECK(stopping.wait_for(30ms) == std::future_status::timeout);
    CHECK(runtime.kernel_alive && callback_entries == 1 && callback_completions == 0);
    gate.release(); stopping.get();
    CHECK(!runtime.kernel_alive && callback_completions == 1 && !callback_invalid);
    callback_gate = nullptr;
}

void allocation_failure(const char* fixture) {
    PS2Runtime runtime; ReoHwBridge bridge; seed(runtime, fixture); configure(runtime);
    reo_cd_async::Lifetime lifetime(runtime);
    auto context = request(runtime);
    const auto previous = ps2_syscalls::fallback_calls.load();
    auto* ram = runtime.memory().getRDRAM();
    put(ram, client + 12, 0xBAD);
    fail_allocation.store(true);
    reo_cd_async::sifCallRpc(ram, &context, &runtime);
    CHECK(!fail_allocation && ps2_syscalls::fallback_calls == previous + 1);
    CHECK(word(ram, client + 12) == 0xBAD && bridge.reads == 0);
}

void setup_refusal(const char* fixture, bool no_stack) {
    PS2Runtime runtime; ReoHwBridge bridge; seed(runtime, fixture);
    if (no_stack) runtime.stack_available = false;
    else runtime.registration_allowed = false;
    configure(runtime); reo_cd_async::Lifetime lifetime(runtime);
    CHECK(!reo_cd_async::enabled);
    unchanged_fallback(runtime, request(runtime));
    CHECK(bridge.reads == 0);
}

void callback_exception(const char* fixture) {
    PS2Runtime runtime; ReoHwBridge bridge; seed(runtime, fixture); configure(runtime);
    reo_cd_async::Lifetime lifetime(runtime);
    throw_callback.store(true); call(runtime);
    wait_for([] { return callback_entries.load() == 1; });
    throw_callback.store(false); call(runtime);
    wait_for([] { return callback_completions.load() >= 1; });
    CHECK(bridge.reads == 2 && ps2_syscalls::fallback_calls == 0);
}

void callback_continuation(const char* fixture) {
    PS2Runtime runtime; ReoHwBridge bridge; seed(runtime, fixture);
    runtime.functions.emplace(0x100298, continued);
    configure(runtime); reo_cd_async::Lifetime lifetime(runtime);
    continue_callback.store(true); call(runtime);
    wait_for([] { return callback_completions.load() == 1; });
    CHECK(callback_entries == 1 && bridge.reads == 1 && !callback_invalid);
}

void missing_callback(const char* fixture) {
    PS2Runtime runtime; ReoHwBridge bridge; seed(runtime, fixture);
    runtime.functions.erase(callback_pc);
    configure(runtime); reo_cd_async::Lifetime lifetime(runtime);
    CHECK(!reo_cd_async::enabled && runtime.stack_reservations == 0);
    unchanged_fallback(runtime, request(runtime));
    CHECK(bridge.reads == 0);
}

void changed_callback(const char* fixture) {
    PS2Runtime runtime; ReoHwBridge bridge; seed(runtime, fixture); configure(runtime);
    reo_cd_async::Lifetime lifetime(runtime);
    runtime.functions[callback_pc] = continued;
    unchanged_fallback(runtime, request(runtime));
    CHECK(bridge.reads == 0 && callback_entries == 0);
}

void read_exception(const char* fixture) {
    PS2Runtime runtime; ReoHwBridge bridge; seed(runtime, fixture); configure(runtime);
    reo_cd_async::Lifetime lifetime(runtime);
    std::atomic<unsigned> attempts{0};
    bridge.on_read = [&](auto, auto, auto, auto*) {
        if (attempts.fetch_add(1) == 0) throw std::runtime_error("Mock read failure");
        return true;
    };
    call(runtime); call(runtime);
    wait_for([] { return callback_completions.load() == 1; });
    CHECK(bridge.reads == 2 && callback_entries == 1 && ps2_syscalls::fallback_calls == 0);
    // Only survival of later work is proved; the first published request has
    // unresolved completion, and is never retried after its partial effects.
}
void changed_completion_metadata(const char* fixture) {
    PS2Runtime runtime; ReoHwBridge bridge; seed(runtime, fixture); configure(runtime);
    reo_cd_async::Lifetime lifetime(runtime);
    bridge.on_read = [&](auto, auto, auto, auto* ram) {
        put(ram, 0x208A00, 1);
        return true;
    };
    call(runtime);
    wait_for([&] { return runtime.scope_exits.load() == 1; });
    CHECK(bridge.reads == 1 && callback_entries == 0 && ps2_syscalls::fallback_calls == 0);
    // A metadata change after publication must not invoke the edge-copy body or
    // replay the read. The unresolved original busy state is diagnosed.
}
auto observed_config(PS2Runtime& runtime) {
    return reo_cd_async::configureWithReceipt("SLUS-20765",runtime.memory().getRDRAM(),PS2_RAM_SIZE,runtime);
}
void sync_configuration_seal(const char* fixture) {
    using namespace reo_cd_async;
    PS2Runtime runtime; ReoHwBridge bridge;seed(runtime,fixture);
    opt("REO_NATIVE_CD_OWNER","0");
    auto observed=observed_config(runtime);
    CHECK(observed.status==ConfigurationStatus::observed && observed.mode==RamWriteMode::synchronous);
    CHECK(observed.receipt.generation()!=0 && !enabled && runtime.stack_reservations==0);
    CHECK(runtime.setup_leases==0);
    auto* ram=runtime.memory().getRDRAM();
    auto seal=observed.receipt.try_seal(runtime,ram,PS2_RAM_SIZE);
    CHECK(seal && seal.matches(runtime,ram,PS2_RAM_SIZE) && seal.generation()==observed.receipt.generation());
    CHECK(runtime.setup_leases==0); // Persistent seal must not hold pre-run phase.
    CHECK(!seal.matches(runtime,ram+1,PS2_RAM_SIZE));
    CHECK(!observed.receipt.try_seal(runtime,ram,16));
    opt("REO_NATIVE_CD_OWNER","1");
    CHECK(observed_config(runtime).status==ConfigurationStatus::conflict);
    CHECK(!enabled && runtime.stack_reservations==0 && bridge.reads==0);
    opt("REO_NATIVE_CD_OWNER","0");
    CHECK(observed_config(runtime).status==ConfigurationStatus::conflict);
    SyncRamWriteSeal moved=std::move(seal);CHECK(!seal && moved);
    auto second=observed.receipt.try_seal(runtime,ram,PS2_RAM_SIZE);CHECK(second);
    moved=std::move(second);CHECK(moved && !second); // Releases replaced lease.
    moved={};
    auto next=observed_config(runtime);
    CHECK(next.status==ConfigurationStatus::observed && next.receipt.generation()>observed.receipt.generation());
    CHECK(!observed.receipt.try_seal(runtime,ram,PS2_RAM_SIZE));
    CHECK(next.receipt.try_seal(runtime,ram,PS2_RAM_SIZE));
    CHECK(runtime.setup_leases==0);
}
void configuration_phase_and_foreign(const char* fixture) {
    using namespace reo_cd_async;
    PS2Runtime runtime,foreign;ReoHwBridge bridge;seed(runtime,fixture);seed(foreign,fixture);
    opt("REO_NATIVE_CD_OWNER","0");
    ConfigurationReceipt empty;
    CHECK(!empty.try_seal(runtime,runtime.memory().getRDRAM(),PS2_RAM_SIZE));
    auto observed=observed_config(runtime);
    CHECK(!observed.receipt.try_seal(foreign,runtime.memory().getRDRAM(),PS2_RAM_SIZE));
    CHECK(!observed.receipt.try_seal(runtime,foreign.memory().getRDRAM(),PS2_RAM_SIZE));
    runtime.running=true;
    CHECK(!observed.receipt.try_seal(runtime,runtime.memory().getRDRAM(),PS2_RAM_SIZE));
    CHECK(observed_config(runtime).status==ConfigurationStatus::phase_closed);
    runtime.running=false;
    auto seal=observed.receipt.try_seal(runtime,runtime.memory().getRDRAM(),PS2_RAM_SIZE);CHECK(seal);
    CHECK(observed_config(foreign).status==ConfigurationStatus::conflict);
    runtime.requestStop();
    CHECK(seal.matches(runtime,runtime.memory().getRDRAM(),PS2_RAM_SIZE));
    CHECK(!observed.receipt.try_seal(runtime,runtime.memory().getRDRAM(),PS2_RAM_SIZE));
    CHECK(runtime.setup_leases==0 && bridge.reads==0);
}
void configuration_async_refusal(const char* fixture) {
    using namespace reo_cd_async;
    PS2Runtime runtime;ReoHwBridge bridge;seed(runtime,fixture);
    auto observed=observed_config(runtime);Lifetime lifetime(runtime);
    CHECK(observed.status==ConfigurationStatus::observed && observed.mode==RamWriteMode::asynchronous);
    CHECK(!observed.receipt.try_seal(runtime,runtime.memory().getRDRAM(),PS2_RAM_SIZE));
    opt("REO_NATIVE_CD_OWNER","0");opt("REO_CD_ASYNC","0");
    auto later=observed_config(runtime);
    CHECK(later.mode==RamWriteMode::asynchronous && enabled); // Never disable a working route to mint a seal.
    CHECK(!later.receipt.try_seal(runtime,runtime.memory().getRDRAM(),PS2_RAM_SIZE));
    CHECK(runtime.setup_leases==0 && bridge.reads==0);
}
void configuration_receipt_allocation_failure(const char* fixture) {
    using namespace reo_cd_async;
    PS2Runtime runtime;ReoHwBridge bridge;seed(runtime,fixture);opt("REO_NATIVE_CD_OWNER","0");
    auto observed=observed_config(runtime);auto* ram=runtime.memory().getRDRAM();
    CHECK(observed.receipt.try_seal(runtime,ram,PS2_RAM_SIZE));
    fail_allocation=true;
    auto failed=observed_config(runtime);
    CHECK(!fail_allocation && failed.status==ConfigurationStatus::unavailable);
    CHECK(!observed.receipt.try_seal(runtime,ram,PS2_RAM_SIZE));
    CHECK(!enabled && bridge.reads==0 && runtime.setup_leases==0);
    auto repaired=observed_config(runtime);
    CHECK(repaired.status==ConfigurationStatus::observed);
    CHECK(repaired.receipt.try_seal(runtime,ram,PS2_RAM_SIZE));
}
void configuration_failed_registration(const char* fixture) {
    using namespace reo_cd_async;
    PS2Runtime runtime;ReoHwBridge bridge;seed(runtime,fixture);opt("REO_NATIVE_CD_OWNER","0");
    auto old=observed_config(runtime);runtime.registration_allowed=false;opt("REO_NATIVE_CD_OWNER","1");
    auto attempted=observed_config(runtime);auto* ram=runtime.memory().getRDRAM();
    CHECK(attempted.status==ConfigurationStatus::observed && attempted.mode==RamWriteMode::synchronous);
    CHECK(!old.receipt.try_seal(runtime,ram,PS2_RAM_SIZE));
    CHECK(!attempted.receipt.try_seal(runtime,ram,PS2_RAM_SIZE));
    opt("REO_NATIVE_CD_OWNER","0");auto later=observed_config(runtime);
    CHECK(later.mode==RamWriteMode::synchronous && !later.receipt.try_seal(runtime,ram,PS2_RAM_SIZE));
    fail_allocation=true;auto failed=observed_config(runtime);
    CHECK(!fail_allocation && failed.status==ConfigurationStatus::unavailable);
    auto after_failure=observed_config(runtime);
    CHECK(after_failure.mode==RamWriteMode::synchronous && !after_failure.receipt.try_seal(runtime,ram,PS2_RAM_SIZE));
    CHECK(!enabled && bridge.reads==0 && runtime.setup_leases==0);
}
void configuration_disabled_override(const char* fixture) {
    using namespace reo_cd_async;
    PS2Runtime runtime;ReoHwBridge bridge;seed(runtime,fixture);opt("REO_CD_ASYNC","0");
    auto observed=observed_config(runtime);auto* ram=runtime.memory().getRDRAM();
    CHECK(observed.mode==RamWriteMode::synchronous && runtime.stack_reservations==0 && !enabled);
    auto seal=observed.receipt.try_seal(runtime,ram,PS2_RAM_SIZE);CHECK(seal);
    opt("REO_CD_ASYNC","1");
    CHECK(observed_config(runtime).status==ConfigurationStatus::conflict);
    CHECK(seal.matches(runtime,ram,PS2_RAM_SIZE) && !enabled && bridge.reads==0);
}
void configuration_seal_race(const char* fixture) {
    using namespace reo_cd_async;
    PS2Runtime runtime;ReoHwBridge bridge;seed(runtime,fixture);opt("REO_NATIVE_CD_OWNER","0");
    for(unsigned i=0;i<32;++i) {
        auto observed=observed_config(runtime);CHECK(observed.status==ConfigurationStatus::observed);
        std::promise<void> start;auto ready=start.get_future().share();
        auto sealing=std::async(std::launch::async,[&]{ready.wait();return observed.receipt.try_seal(runtime,runtime.memory().getRDRAM(),PS2_RAM_SIZE);});
        auto configuring=std::async(std::launch::async,[&]{ready.wait();return observed_config(runtime);});
        start.set_value();auto seal=sealing.get();auto configured=configuring.get();
        CHECK((seal && configured.status==ConfigurationStatus::conflict) ||
              (!seal && configured.status==ConfigurationStatus::observed));
        if(seal)CHECK(seal.generation()==observed.receipt.generation());
        else CHECK(configured.receipt.generation()>observed.receipt.generation());
    }
    CHECK(runtime.setup_leases==0 && !enabled && bridge.reads==0);
}
} // namespace

int main(int argc, char** argv) {
    try {
        CHECK(argc == 3);
        opt("REO_NATIVE_CD_OWNER", "1"); opt("REO_CD_ASYNC", "1");
        const std::string scenario = argv[2];
        if (scenario == "operations") operations(argv[1]);
        else if (scenario == "refusals") refusals(argv[1]);
        else if (scenario == "shutdown") shutdown_during_read(argv[1], false);
        else if (scenario == "queue-full") shutdown_during_read(argv[1], true);
        else if (scenario == "callback-overlap") callback_overlap(argv[1]);
        else if (scenario == "allocation-failure") allocation_failure(argv[1]);
        else if (scenario == "no-stack") setup_refusal(argv[1], true);
        else if (scenario == "late-registration") setup_refusal(argv[1], false);
        else if (scenario == "callback-exception") callback_exception(argv[1]);
        else if (scenario == "callback-continuation") callback_continuation(argv[1]);
        else if (scenario == "missing-callback") missing_callback(argv[1]);
        else if (scenario == "changed-callback") changed_callback(argv[1]);
        else if (scenario == "read-exception") read_exception(argv[1]);
        else if (scenario == "changed-completion-metadata") changed_completion_metadata(argv[1]);
        else if (scenario == "configuration-seal") sync_configuration_seal(argv[1]);
        else if (scenario == "configuration-phase") configuration_phase_and_foreign(argv[1]);
        else if (scenario == "configuration-async") configuration_async_refusal(argv[1]);
        else if (scenario == "configuration-allocation") configuration_receipt_allocation_failure(argv[1]);
        else if (scenario == "configuration-registration") configuration_failed_registration(argv[1]);
        else if (scenario == "configuration-disabled") configuration_disabled_override(argv[1]);
        else if (scenario == "configuration-race") configuration_seal_race(argv[1]);
        else throw std::runtime_error("Unknown scenario");
        std::cout << scenario << ": " << checks << " host-only checks passed\n";
        return 0;
    } catch (const std::exception& error) {
        std::cerr << "Native CD owner test failed: " << error.what() << '\n';
        return 1;
    }
}
