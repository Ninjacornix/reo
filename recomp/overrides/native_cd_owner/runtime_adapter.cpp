#include "runtime_adapter.h"
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include "ps2_syscalls.h"
#include "reo_hw_bridge.h"
#include "../../../game/native/tasks/serial_worker.hpp"
#include "../native_geometry/reo_vu_native_sha256.h"

#include <atomic>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <memory>
#include <mutex>
#include <utility>

#ifndef PS2_RUNTIME_HAS_EXTERNAL_WORKERS
#error "Native CD ownership requires the matching public external-worker runtime patch"
#endif
#if defined(REO_GAME_FILE2)
#error "Native CD ownership is admitted only for File #1"
#endif

namespace reo_cd_async {
bool enabled = false; // Bootstrap registration only; never changed by the worker.
namespace {
using reo::native::tasks::SerialWorker;
using reo::native::tasks::StopMode;
using reo::native::tasks::SubmitStatus;
constexpr std::uint32_t client = 0x208AD0, send = 0x207A00, callback = 0x1004D8;
constexpr std::uint32_t return_address = 0x101908;

std::uint32_t word(const std::uint8_t* memory, std::uint32_t address) noexcept {
    std::uint32_t value;
    std::memcpy(&value, memory + address, sizeof(value));
    return value;
}

struct Request {
    std::uint32_t lsn, count, destination, end_parameter, gp;
};

constexpr reo_native_image_identity::Digest digest(const char (&hex)[65]) {
    reo_native_image_identity::Digest result{};
    const auto nibble = [](char c) { return c <= '9' ? c - '0' : c - 'a' + 10; };
    for (unsigned i = 0; i < result.size(); ++i)
        result[i] = static_cast<std::uint8_t>((nibble(hex[2 * i]) << 4) | nibble(hex[2 * i + 1]));
    return result;
}

class Session final : public PS2Runtime::ExternalWorker {
public:
    Session(PS2Runtime& owner, std::uint8_t* bytes, std::uint32_t stack,
            PS2Runtime::RecompiledFunction completion)
        : runtime(owner), memory(bytes), worker(8), callback_function(completion), callback_stack(stack) {}

    void requestStop() noexcept override {
        stopping.store(true, std::memory_order_release);
        // Signal only. Queued tasks release captures on the worker and observe
        // stopping before I/O; requestStop never waits for a task/provider.
        worker.request_stop(StopMode::drain);
    }

    bool join() noexcept override {
        try {
            requestStop();
            return worker.join();
        } catch (...) {
            std::fprintf(stderr, "[NATIVE-CD-OWNER] worker join failed; runtime teardown must stop\n");
            return false;
        }
    }

    void perform(const Request& request) noexcept {
        if (stopping.load(std::memory_order_acquire) || runtime.isStopRequested()) return;
        try {
            auto* bridge = ReoHwBridge::instance();
            const bool ok = bridge && bridge->readCdSectors(request.lsn, request.count,
                                                          request.destination, memory);
            if (read_reports.fetch_add(1, std::memory_order_relaxed) < 40)
                std::fprintf(stderr, "[NATIVE-CD-OWNER] read lsn=%u n=%u dst=%08x result=%s\n",
                             request.lsn, request.count, request.destination, ok ? "ok" : "FAIL");
            // Preserve the existing false-read callback policy. Typed native
            // error -> original SRD/DVCI publication is a separate contract.
            PS2Runtime::GuestExecutionScope execution(&runtime);
            if (stopping.load(std::memory_order_acquire) || runtime.isStopRequested()) return;
            if (word(memory, request.end_parameter) != 0 || word(memory, request.end_parameter + 4) != 0) {
                std::fprintf(stderr, "[NATIVE-CD-OWNER] completion metadata changed; original busy state is unresolved\n");
                return; // Work was already published: never replay it through fallback.
            }
            R5900Context context{};
            SET_GPR_U32(&context, 28, request.gp);
            SET_GPR_U32(&context, 29, callback_stack);
            SET_GPR_U32(&context, 31, 0u);
            SET_GPR_U32(&context, 4, request.end_parameter);
            context.pc = callback;
            auto* callback_context = &context; // Real GPR macros require a pointer identifier.
            unsigned dispatches = 0;
            while (context.pc != 0 && !stopping.load(std::memory_order_acquire) &&
                   !runtime.isStopRequested() && dispatches < 256) {
                const auto pc = context.pc;
                auto function = callback_function;
                if (dispatches != 0) {
                    if (!runtime.hasFunction(pc)) {
                        std::fprintf(stderr, "[NATIVE-CD-OWNER] completion continuation unregistered at %08x\n", pc);
                        return;
                    }
                    function = runtime.lookupFunction(pc);
                }
                ++dispatches;
                function(memory, &context, &runtime);
                // Same unchanged-entry convention used by generated calls to
                // host overrides. Real original returns set PC to their RA.
                if (context.pc == pc) context.pc = GPR_U32(callback_context, 31);
            }
            if (context.pc == 0) {
                const auto count = completion_reports.fetch_add(1, std::memory_order_relaxed) + 1;
                if (count <= 4 || (count & (count - 1)) == 0)
                    std::fprintf(stderr, "[NATIVE-CD-OWNER] completion calls=%u dispatches=%u\n", count, dispatches);
            } else if (!stopping.load(std::memory_order_acquire) && !runtime.isStopRequested()) {
                std::fprintf(stderr, "[NATIVE-CD-OWNER] completion dispatch limit at %08x; original busy state is unresolved\n", context.pc);
            }
        } catch (const std::exception& error) {
            if (failure_reports.fetch_add(1, std::memory_order_relaxed) < 8)
                std::fprintf(stderr, "[NATIVE-CD-OWNER] completion stopped: %s\n", error.what());
        } catch (...) {
            if (failure_reports.fetch_add(1, std::memory_order_relaxed) < 8)
                std::fprintf(stderr, "[NATIVE-CD-OWNER] completion stopped: unknown exception\n");
        }
    }

    PS2Runtime& runtime;
    std::uint8_t* const memory;
    SerialWorker worker;
    std::atomic<bool> stopping{false};
    const PS2Runtime::RecompiledFunction callback_function;
private:
    const std::uint32_t callback_stack; // Reserved after final ELF load, before any request admission.
    std::atomic<unsigned> read_reports{0}, failure_reports{0}, completion_reports{0};
};

// The bundled libc++ lacks atomic<shared_ptr<T>> and newer libstdc++ deprecates
// its free-function predecessor. Hold this short registry lock only to retain
// or exchange ownership; no I/O, guest execution or final destruction under it.
std::shared_ptr<Session> active;
std::mutex active_mutex;
std::mutex configuration_mutex;

std::shared_ptr<Session> load_active() {
    std::lock_guard lock(active_mutex);
    return active;
}
void store_active(std::shared_ptr<Session> session) {
    { std::lock_guard lock(active_mutex); active.swap(session); }
}
std::shared_ptr<Session> take_active(PS2Runtime& runtime) {
    std::lock_guard lock(active_mutex);
    if (!active || &active->runtime != &runtime) return {};
    return std::exchange(active, {});
}

bool identity(const char* serial, const std::uint8_t* memory, std::size_t bytes) noexcept {
    return serial && !std::strcmp(serial, "SLUS-20765") && memory && bytes == PS2_RAM_SIZE &&
        word(memory, 0x1018E4) == 0xAFB30000u && word(memory, 0x1018EC) == 0x256B04D8u &&
        word(memory, 0x1018F8) == 0x24080018u && word(memory, 0x101900) == 0x0C045E7Au &&
        word(memory, callback) != 0 &&
        reo_native_image_identity::sha256(memory + 0x101788, 0x1E0) ==
            digest("c520c3c1af9405a9b73a60c397b7ed6196d34ad5d54559371b74aed5be6d1baa") &&
        reo_native_image_identity::sha256(memory + 0x1004D8, 0xB8) ==
            digest("6126b560a34e355058f3b6426a7ef310855bb5aef6cd5922a852bc9628b75e47") &&
        reo_native_image_identity::sha256(memory + 0x100298, 0xA0) ==
            digest("b1a65fc9ecc2500db7dc938d41b512ab3eb727b2a06748e71d8edee262455fcf");
}
} // namespace

void configure(const char* serial, std::uint8_t* memory, std::size_t bytes,
               PS2Runtime& runtime) noexcept {
    const char* opt = std::getenv("REO_NATIVE_CD_OWNER");
    const char* legacy = std::getenv("REO_CD_ASYNC");
    if (!opt || std::strcmp(opt, "1") || (legacy && !std::strcmp(legacy, "0"))) return;
    if (!identity(serial, memory, bytes) || runtime.memory().getRDRAM() != memory ||
        !runtime.hasFunction(callback)) return;
    try {
        std::lock_guard lock(configuration_mutex);
        if (const auto current = load_active()) {
            if (&current->runtime == &runtime && current->memory == memory &&
                !current->stopping.load(std::memory_order_acquire)) enabled = true;
            return;
        }
        const auto stack = runtime.reserveAsyncCallbackStack(0x4000u, 16u);
        if (!stack) {
            std::fprintf(stderr, "[NATIVE-CD-OWNER] callback stack unavailable; original HLE retained\n");
            return;
        }
        auto session = std::make_shared<Session>(runtime, memory, stack, runtime.lookupFunction(callback));
        if (!runtime.registerExternalWorker(session)) {
            session->requestStop();
            if (!session->join()) std::terminate();
            std::fprintf(stderr, "[NATIVE-CD-OWNER] runtime registration refused; original HLE retained\n");
            return;
        }
        store_active(std::move(session));
        enabled = true;
        std::fprintf(stderr, "[NATIVE-CD-OWNER] bounded session worker registered with runtime lifecycle\n");
    } catch (const std::exception& error) {
        std::fprintf(stderr, "[NATIVE-CD-OWNER] setup unavailable: %s; original HLE retained\n", error.what());
    } catch (...) {
        std::fprintf(stderr, "[NATIVE-CD-OWNER] setup unavailable; original HLE retained\n");
    }
}

void sifCallRpc(std::uint8_t* memory, R5900Context* context, PS2Runtime* runtime) {
    const auto session = load_active();
    if (session && runtime == &session->runtime && memory == session->memory &&
        runtime->memory().getRDRAM() == memory &&
        GPR_U32(context, 31) == return_address && GPR_U32(context, 4) == client &&
        GPR_U32(context, 5) == 1 && GPR_U32(context, 6) == 1 &&
        GPR_U32(context, 7) == send && GPR_U32(context, 8) == 0x18 &&
        GPR_U32(context, 9) == 0 && GPR_U32(context, 10) == 0 &&
        memory[send + 14] == 0 && word(memory, send + 16) == 0x208A00 &&
        word(memory, send + 20) == 0x208AC0 &&
        GPR_U32(context, 11) == callback && runtime->hasFunction(callback) &&
        runtime->lookupFunction(callback) == session->callback_function) {
        const auto stack = GPR_U32(context, 29);
        const Request request{word(memory, send), word(memory, send + 4), word(memory, send + 8),
                              0, GPR_U32(context, 28)};
        const auto bytes = std::uint64_t(request.count) * 2048;
        if (stack % 4 == 0 && stack <= PS2_RAM_SIZE - 4 && request.count > 0 &&
            request.count <= 0x4000 && request.destination > 0 &&
            request.destination < PS2_RAM_SIZE && bytes <= PS2_RAM_SIZE - request.destination &&
            (std::uint64_t(request.destination) + bytes <= 0x208A00 || request.destination >= 0x208A90) &&
            word(memory, 0x208A00) == 0 && word(memory, 0x208A04) == 0) {
            auto owned = request;
            owned.end_parameter = word(memory, stack);
            if (owned.end_parameter != 0x208A00) {
                ps2_syscalls::sceSifCallRpc(memory, context, runtime);
                return;
            }
            struct Publication { std::uint8_t* memory; std::uint32_t parameter; } publication{memory, owned.end_parameter};
            const auto publish = +[](void* opaque) noexcept {
                const auto& value = *static_cast<Publication*>(opaque);
                const auto put = [&](std::uint32_t address, std::uint32_t data) noexcept {
                    std::memcpy(value.memory + address, &data, sizeof(data));
                };
                put(client + 12, 1); put(client + 16, 1);
                put(client + 28, callback); put(client + 32, value.parameter);
            };
            try {
                const auto admitted = session->worker.submit([session, owned] { session->perform(owned); },
                                                              publish, &publication);
                if (admitted == SubmitStatus::accepted) {
                    SET_GPR_S32(context, 2, 0);
                    return;
                }
            } catch (...) {
                // Task allocation/queue lock failure precedes publication.
                std::fprintf(stderr, "[NATIVE-CD-OWNER] admission unavailable; original HLE retained\n");
            }
        }
    }
    ps2_syscalls::sceSifCallRpc(memory, context, runtime);
}

void finish(PS2Runtime& runtime) noexcept {
    auto session = take_active(runtime);
    if (!session) return;
    enabled = false;
    try { runtime.requestStop(); }
    catch (...) { std::fprintf(stderr, "[NATIVE-CD-OWNER] runtime stop raised during session cleanup\n"); }
    session->requestStop();
    if (!session->join()) std::terminate();
    std::fprintf(stderr, "[NATIVE-CD-OWNER] session joined before bootstrap export/destruction\n");
}
} // namespace reo_cd_async
