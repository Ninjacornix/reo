#include "runtime/ps2_memory.h"
#include "../../third_party/PS2Recomp/ps2xRuntime/src/lib/async_vif1.h"
#include "../../third_party/PS2Recomp/ps2xRuntime/src/lib/palette_dma_origin.h"
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <cstring>
#include <iostream>
#include <mutex>
#include <thread>
namespace {
unsigned checks = 0, failed = 0;
void check(bool value, const char* name) {
    ++checks;
    if (!value)
        ++failed;
    std::cout << (value ? "ok: " : "FAIL: ") << name << '\n';
}
void packet(PS2Memory& m) {
    // END+IRQ, MSCAL0, STROW, four words, two NOPs. The worker blocks in
    // MSCAL while the EE changes the ORIGINAL (already captured) STROW bytes.
    const uint32_t words[]{0xf0000002, 0, 0, 0, 0x14000000, 0x30000000, 11, 22, 33, 44, 0, 0};
    std::memcpy(m.getRDRAM() + 0x20000, words, sizeof(words));
}
void kick(PS2Memory& m) {
    m.writeIORegister(0x10009030, 0x20000);
    m.writeIORegister(0x10009000, 0x185);
}
} // namespace
int main() {
    try {
        {
            PS2Memory m;
            check(m.initialize(), "memory initialized");
            reo_async_vif::attach(m, nullptr);
            check(reo_async_vif::active(m), "opt-in worker active");
            packet(m);
            std::mutex mutex;
            std::condition_variable cv;
            bool entered = false, release = false;
            m.setVu1MscalCallback([&](uint32_t, uint32_t) {
                std::unique_lock<std::mutex> lock(mutex);
                entered = true;
                cv.notify_all();
                cv.wait_for(lock, std::chrono::seconds(5), [&] { return release; });
            });
            kick(m);
            {
                std::unique_lock<std::mutex> lock(mutex);
                check(cv.wait_for(lock, std::chrono::seconds(2), [&] { return entered; }),
                      "VU callback runs on independent worker");
            }
            check((m.readIORegister(0x10009000) & 0x100) != 0,
                  "CHCR poll cannot clear unfinished DMA STR");
            check((m.peekStoredIORegister(0x1000e010) & 2) == 0,
                  "no DMA completion before consumption");
            m.write32(0x30000, 0x12345678);
            check(m.read32(0x30000) == 0x12345678, "EE memory work overlaps VIF execution");
            alignas(16) uint32_t values[]{0x11223344, 2, 3, 4};
            m.write128(0x70003c10, _mm_loadu_si128(reinterpret_cast<const __m128i*>(values)));
            const auto scratch = m.read128(0x70003c10);
            check(_mm_cvtsi128_si32(scratch) == 0x11223344,
                  "scratchpad 70003C10 is not a VIF register barrier");
            m.write32(0x20018, 999); // First STROW word in original RAM, not owned snapshot.
            m.writeIORegister(0x10003c40, 0x0202);
            std::atomic<bool> readerEntered{false}, readerDone{false};
            std::thread reader([&] {
                readerEntered = true;
                m.readIORegister(0x10003c00);
                readerDone = true;
            });
            while (!readerEntered)
                std::this_thread::yield();
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
            check(!readerDone, "real VIF register read waits for preceding work");
            {
                std::lock_guard<std::mutex> lock(mutex);
                release = true;
                cv.notify_all();
            }
            reader.join();
            check(readerDone, "register barrier resumes after worker completion");
            check(m.vif1_regs.row[0] == 11 && m.vif1_regs.row[3] == 44,
                  "chain owns captured source bytes through completion");
            check(m.vif1_regs.cycle == 0x0202, "queued control write follows preceding VU work");
            check((m.readIORegister(0x10009000) & 0x100) == 0,
                  "STR clears after actual transfer consumption");
            check((m.readIORegister(0x10009000) & 0x80000000u) != 0,
                  "terminal tag IRQ identity preserved");
            check((m.peekStoredIORegister(0x1000e010) & 2) != 0,
                  "real DMA completion status published");
            {
                std::lock_guard<std::mutex> lock(mutex);
                release = false;
                entered = false;
            }
            packet(m);
            kick(m);
            {
                std::unique_lock<std::mutex> lock(mutex);
                cv.wait_for(lock, std::chrono::seconds(2), [&] { return entered; });
            }
            std::atomic<bool> subwordDone{false};
            std::thread subword([&] {
                m.write16(0x10003c40, 0x0303);
                subwordDone = true;
            });
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
            check(!subwordDone, "subword register merge waits before acquiring IO ownership");
            {
                std::lock_guard<std::mutex> lock(mutex);
                release = true;
                cv.notify_all();
            }
            subword.join();
            reo_async_vif::drain(m);
            check(m.vif1_regs.cycle == 0x0303,
                  "subword write observes prior ordered register updates");
            bool bounded = false;
            try {
                reo_async_vif::enqueue(m, [] {}, 16u * 1024u * 1024u + 1);
            } catch (const std::runtime_error&) {
                bounded = true;
            }
            check(bounded, "owned FIFO rejects an oversized immutable batch");
            const auto ee = std::this_thread::get_id();
            bool ranOnEe = false;
            m.setVu1MscalCallback(
                [&](uint32_t, uint32_t) { ranOnEe = std::this_thread::get_id() == ee; });
            reo_palette_origin::Callbacks callbacks;
            callbacks.allocation = [](const void*, uint32_t, uint32_t, bool) {
                return uint64_t(1);
            };
            callbacks.unpack = [](const void*, uint32_t, uint32_t, const uint8_t*, uint32_t,
                                  const reo_palette_origin::Spans&) {};
            reo_palette_origin::install(std::move(callbacks));
            packet(m);
            kick(m);
            check(ranOnEe, "source-origin callback path remains synchronous");
            reo_palette_origin::install({});
            reo_async_vif::shutdown(m);
            check(!reo_async_vif::active(m), "worker joined and detached before bank teardown");
        }
        {
            PS2Memory m;
            m.initialize();
            reo_async_vif::attach(m, nullptr);
            packet(m);
            m.setVu1MscalCallback(
                [](uint32_t, uint32_t) { throw std::runtime_error("intentional VIF failure"); });
            bool refused = false;
            try {
                kick(m);
                reo_async_vif::drain(m);
            } catch (const std::runtime_error& e) {
                refused = std::strstr(e.what(), "intentional") != nullptr;
            }
            check(refused, "worker exception reaches the observer");
            check((m.peekStoredIORegister(0x1000e010) & 2) == 0,
                  "failed work never publishes successful DMA completion");
            reo_async_vif::shutdown(m);
        }
        {
            PS2Memory m;
            m.initialize();
            reo_async_vif::attach(m, nullptr);
            packet(m);
            std::mutex mutex;
            std::condition_variable cv;
            bool entered = false, release = false;
            m.setVu1MscalCallback([&](uint32_t, uint32_t) {
                std::unique_lock<std::mutex> lock(mutex);
                entered = true;
                cv.notify_all();
                cv.wait_for(lock, std::chrono::seconds(5), [&] { return release; });
            });
            kick(m);
            {
                std::unique_lock<std::mutex> lock(mutex);
                cv.wait_for(lock, std::chrono::seconds(2), [&] { return entered; });
            }
            reo_async_vif::requestStop(m);
            {
                std::lock_guard<std::mutex> lock(mutex);
                release = true;
                cv.notify_all();
            }
            reo_async_vif::shutdown(m);
            check((m.peekStoredIORegister(0x1000e010) & 2) == 0,
                  "cancelled completion is not fabricated on shutdown");
        }
        {
            PS2Memory m;
            m.initialize();
            _putenv_s("REO_VIF1_GPU_RESIDENT", "1");
            bool refused = false;
            try {
                reo_async_vif::attach(m, nullptr);
            } catch (const std::runtime_error&) {
                refused = true;
            }
            _putenv_s("REO_VIF1_GPU_RESIDENT", "0");
            check(refused && !reo_async_vif::active(m),
                  "resident GPU bank and async CPU VU ownership cannot mix");
        }
    } catch (const std::exception& e) {
        check(false, e.what());
    }
    std::cout << checks - failed << '/' << checks << " checks passed\n";
    return failed ? 1 : 0;
}
