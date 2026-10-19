// Actual copied Memory + GS FIFO front/reset regression, with a deterministic
// mock completion/capture gate. No device, game, or IRQ worker is launched.
#include "gs_backend_route.h"
#include "gs_priv_atomic.h"
#include "runtime/ps2_gs_gpu.h"
#include "runtime/ps2_memory.h"
#include "Kernel/Syscalls/Interrupt.h"
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <mutex>
#include <stdexcept>
#include <string>
#include <vector>

void ps2GsSnapshotDisplay();
void ps2GsRequestWorkerStop();
void ps2GsJoinWorker();
namespace gs_backend_bridge {
void publishPrivilegedReset(const Privileged&);
}
// Fixture-only inspection of the actual IRQ latch, whose external definition
// is in the pinned Interrupt.cpp. No IRQ consumer runs in this isolated test.
namespace ps2_syscalls::interrupt_state {
extern std::atomic<uint32_t> g_pending_intc_mask;
}
using namespace gs_backend_bridge;
static std::atomic<unsigned> assertions{0};
#define CHECK(c)                                                                                   \
    do {                                                                                           \
        ++assertions;                                                                              \
        if (!(c))                                                                                  \
            throw std::logic_error("CHECK failed at line " + std::to_string(__LINE__) + ": " #c);  \
    } while (0)
constexpr uint32_t csrAddress = PS2_GS_PRIV_REG_BASE + 0x1000u;
constexpr uint32_t imrAddress = PS2_GS_PRIV_REG_BASE + 0x1010u;
constexpr uint32_t displayAddress = PS2_GS_PRIV_REG_BASE + 0x70u;

struct Evidence {
    struct Gate {
        bool entered = false, released = false;
    };
    std::mutex mutex;
    std::condition_variable cv;
    std::map<std::string, Gate> gates;
    std::vector<std::string> calls;
    std::vector<uint8_t> vram;
    Init initial;
    std::atomic<unsigned> closed{0};
    std::atomic<unsigned> stalePeeks{0};
    void record(std::string text) {
        std::lock_guard<std::mutex> lock(mutex);
        calls.push_back(std::move(text));
    }
    void arm(const std::string& name) {
        std::lock_guard<std::mutex> lock(mutex);
        CHECK(gates.emplace(name, Gate{}).second);
    }
    void enter(const std::string& name) {
        std::unique_lock<std::mutex> lock(mutex);
        const auto it = gates.find(name);
        if (it == gates.end())
            return;
        it->second.entered = true;
        cv.notify_all();
        cv.wait(lock, [&] { return it->second.released; });
    }
    void wait(const std::string& name) {
        std::unique_lock<std::mutex> lock(mutex);
        CHECK(cv.wait_for(lock, std::chrono::seconds(5), [&] { return gates.at(name).entered; }));
    }
    void release(const std::string& name) {
        std::lock_guard<std::mutex> lock(mutex);
        gates.at(name).released = true;
        cv.notify_all();
    }
    void releaseAll() {
        std::lock_guard<std::mutex> lock(mutex);
        for (auto& [name, gate] : gates)
            gate.released = true;
        cv.notify_all();
    }
    size_t find(const std::string& name) {
        std::lock_guard<std::mutex> lock(mutex);
        for (size_t i = 0; i < calls.size(); ++i)
            if (calls[i] == name)
                return i;
        throw std::logic_error("Missing mock call: " + name);
    }
};
struct Mock final : Backend {
    std::shared_ptr<Evidence> e;
    explicit Mock(std::shared_ptr<Evidence> value) : e(std::move(value)) {}
    bool init(const Init& value, std::string&) override {
        e->initial = value;
        e->vram.assign(value.vram, value.vram + value.vramSize);
        return true;
    }
    void close() noexcept override {
        ++e->closed;
    }
    void reset() override {
        e->record("host-reset");
    }
    void rawGif(uint8_t, const uint8_t* data, size_t size) override {
        CHECK(size == 16 && (data[0] == 1 || data[0] == 2));
        const bool old = data[0] == 1;
        CHECK(peekEventFrontState().has_value());
        if (old) {
            e->record("old-event-enter");
            e->enter("old-events");
        }
        if (old) {
            CHECK(!peekEventFrontState());
            ++e->stalePeeks;
        }
        // Deliberately invoke even when stale: the runtime commit must reject
        // every event itself, independently of the concrete adapter's hook.
        e->initial.completedEvent(0x60, (uint64_t(0xffffffffu) << 32) | 0x11223344u);
        e->initial.completedEvent(0x61, 0);
        e->initial.completedEvent(0x62, (uint64_t(0xffffffffu) << 32) | 0x55667788u);
        e->record(old ? "old-event-return" : "new-events");
    }
    void directRegister(uint8_t, uint64_t) override {
        e->record("register");
    }
    void privilegedWrite(uint32_t offset, uint8_t width, uint64_t input) override {
        CHECK(peekEventFrontState().has_value());
        if (gsPrivCsrInput(offset, width, input) & (uint64_t(1) << 9)) {
            e->record("reset-epoch" + std::to_string(gsPrivCurrentEpoch()));
            Privileged stale;
            stale.fill(~uint64_t(0));
            publishPrivilegedReset(stale); // Native callback must be a no-op.
        } else if (offset == 0x70u) {
            e->record("display" + std::to_string(input));
        } else
            e->record("privileged");
    }
    Frame capture(const Capture& capture) override {
        CHECK(peekEventFrontState().has_value());
        const auto id = capture.registers[7];
        e->record("capture-enter" + std::to_string(id));
        e->enter("capture" + std::to_string(id));
        if (!peekEventFrontState())
            ++e->stalePeeks;
        e->record("capture-return" + std::to_string(id));
        Frame frame;
        frame.width = 1;
        frame.height = 1;
        frame.tick = capture.tick;
        frame.displayFbp = uint32_t(id);
        frame.sourceFbp = uint32_t(id);
        frame.rgba = {uint8_t(id), 0x31, 0x5a, 0xff};
        return frame;
    }
    void exportVram(size_t offset, uint8_t* dst, size_t size) override {
        std::memcpy(dst, e->vram.data() + offset, size);
    }
    uint32_t readTransfer(uint8_t* dst, uint32_t bytes) override {
        std::memset(dst, 0x7b, bytes);
        return bytes;
    }
    bool clearContext(uint32_t, uint32_t, bool) override {
        return true;
    }
    void flush() override {}
};
struct Cleanup {
    std::shared_ptr<Evidence> e;
    ~Cleanup() {
        e->releaseAll();
        ps2GsRequestWorkerStop();
        ps2GsJoinWorker();
    }
};
static void drain(GS& gs) {
    uint8_t byte = 0;
    CHECK(gs.consumeLocalToHostBytes(&byte, 1) == 1 && byte == 0x7b);
}
static void writeWidth(PS2Memory& memory, unsigned kind, uint32_t address, uint64_t input) {
    switch (kind) {
        case 0:
            memory.write8(address, uint8_t(input));
            break;
        case 1:
            memory.write16(address, uint16_t(input));
            break;
        case 2:
            memory.write32(address, uint32_t(input));
            break;
        case 3:
            memory.write64(address, input);
            break;
        case 4:
            CHECK(memory.writeIORegister(address, uint32_t(input)));
            break;
        default:
            throw std::logic_error("Invalid write-width fixture");
    }
}
static void seed(GSRegisters& gs, uint64_t csr, uint64_t imr) {
    std::lock_guard<std::mutex> lock(g_gsPrivFrontMutex);
    gsPrivStore(gs.csr, csr);
    gsPrivStore(gs.imr, imr);
}
static void checkReset(PS2Memory& memory) {
    std::lock_guard<std::mutex> lock(g_gsPrivFrontMutex);
    const auto words = gsPrivSnapshot(memory.gs());
    CHECK(words[15] == 0x551b4000ull && words[16] == 0x7f00ull);
    static_assert(sizeof(GSRegisters) == 19 * sizeof(uint64_t));
    for (unsigned i = 0; i < 19; ++i)
        if (i != 15 && i != 16)
            CHECK(words[i] == 0);
}
static void checkPicture(GS& gs, bool valid, unsigned id = 0) {
    std::vector<uint8_t> pixels;
    uint32_t width = 0, height = 0, display = 0;
    CHECK(gs.copyLatchedHostPresentationFrame(pixels, width, height, &display) == valid);
    if (valid)
        CHECK(width == 1 && height == 1 &&
              pixels == std::vector<uint8_t>({uint8_t(id), 0x31, 0x5a, 0xff}) && display == id);
    else
        CHECK(pixels.empty() && width == 0 && height == 0);
}
int main() try {
    _putenv_s("REO_GS_BACKEND", "parallel");
    _putenv_s("REO_GS_THREAD", "1");
    _putenv_s("REO_GS_BACKEND_ROUTE_TEST", "1");
    _putenv_s("REO_GFX", "");
    _putenv_s("REO_GS_PUBLICATION_PROBE", "0");
    _putenv_s("REO_GS_DISPATCH_PACE", "0");
    auto evidence = std::make_shared<Evidence>();
    PS2Memory memory;
    GS gs;
    Cleanup cleanup{evidence};
    CHECK(memory.initialize());
    registerFactory([evidence] { return std::make_unique<Mock>(evidence); });
    gs.init(memory.getGSVRAM(), 4u * 1024u * 1024u, &memory.gs());
    CHECK(active());
    CHECK(!peekEventFrontState());
    auto& irq = ps2_syscalls::interrupt_state::g_pending_intc_mask;
    irq.store(0);

    // Actual Memory write8/16/32/64/writeIORegister paths: all five W1C flags,
    // preserved read-only bits, and no RESET when bit19 is written.
    constexpr uint64_t seededCsr = 0x551b401full;
    for (unsigned kind = 0; kind < 5; ++kind) {
        seed(memory.gs(), seededCsr, 0x7f00);
        const auto epoch = gsPrivCurrentEpoch();
        const uint64_t written = (~uint64_t(0x1f) & ~(uint64_t(1) << 9)) | 0x15u;
        writeWidth(memory, kind, csrAddress, written);
        CHECK(memory.read64(csrAddress) == (seededCsr & ~uint64_t(0x15)));
        CHECK(gsPrivCurrentEpoch() == epoch);
        writeWidth(memory, kind, csrAddress, 0x0au);
        CHECK(memory.read64(csrAddress) == (seededCsr & ~uint64_t(0x1f)));
        drain(gs);
    }
    const auto readonlyEpoch = gsPrivCurrentEpoch();
    memory.write32(csrAddress, uint32_t(1) << 19);
    drain(gs);
    CHECK(gsPrivCurrentEpoch() == readonlyEpoch);
    CHECK(memory.read64(csrAddress) == (seededCsr & ~uint64_t(0x1f)));

    // Full19-word reset through every CPU path, including the byte lane that
    // carries RESET bit9. The queued reset callback tries to overwrite it.
    for (unsigned kind = 0; kind < 5; ++kind) {
        Privileged words;
        words.fill(0xdeadbeefcafef00dull);
        {
            std::lock_guard<std::mutex> lock(g_gsPrivFrontMutex);
            gsPrivPublish(memory.gs(), words);
        }
        const auto epoch = gsPrivCurrentEpoch();
        writeWidth(memory, kind, csrAddress + (kind == 0 ? 1 : 0), kind == 0 ? 2u : 0x200u);
        CHECK(gsPrivCurrentEpoch() == epoch + 1);
        checkReset(memory);
        drain(gs);
        checkReset(memory);
    }

    // IMR lane merging/reserved normalization and the actual pending IRQ latch.
    for (unsigned kind = 0; kind < 5; ++kind) {
        seed(memory.gs(), 0x551b4003, 0x7f00);
        irq.store(0);
        writeWidth(memory, kind, imrAddress + (kind == 0 ? 1 : 0), 0);
        CHECK(memory.read64(imrAddress) == 0x6000);
        CHECK((irq.load() & 1u) != 0);
        drain(gs);
        irq.store(0);
        writeWidth(memory, kind, imrAddress + (kind == 0 ? 1 : 0), 0);
        CHECK((irq.load() & 1u) == 0);
        drain(gs);
    }
    seed(memory.gs(), 0x551b4003, 0x7f00);
    irq.store(0);
    memory.write32(imrAddress + 4, 0xffffffffu);
    drain(gs);
    CHECK(memory.read64(imrAddress) == 0x7f00 && irq.load() == 0);
    seed(memory.gs(), 0x551b4002, 0x7f00);
    const auto fieldBefore = memory.read64(csrAddress);
    gsPrivFieldTick(memory.gs());
    CHECK(memory.read64(csrAddress) == ((fieldBefore ^ (uint64_t(1) << 13)) | 8u));
    CHECK((memory.read64(csrAddress) & 2u) != 0);

    // Gate a completed old-epoch packet, apply CPU RESET while it is in flight,
    // and enqueue newer display state/capture. Stale callbacks must not touch
    // IDs/status/IRQ; RESET must precede the new capture and preserve its state.
    evidence->arm("old-events");
    uint8_t packet[16]{};
    packet[0] = 1;
    gs.processGIFPacket(packet, 16);
    evidence->wait("old-events");
    irq.store(0);
    const auto eventEpoch = gsPrivCurrentEpoch();
    memory.write32(csrAddress, 0x200);
    checkReset(memory);
    CHECK(gsPrivCurrentEpoch() == eventEpoch + 1);
    memory.write64(displayAddress, 42);
    ps2GsSnapshotDisplay();
    evidence->release("old-events");
    drain(gs);
    CHECK(memory.read64(csrAddress) == 0x551b4000ull);
    CHECK(gsPrivLoad(memory.gs().siglblid) == 0 && irq.load() == 0);
    CHECK(memory.read64(displayAddress) == 42);
    checkPicture(gs, true, 42);
    CHECK(evidence->find("old-event-return") <
          evidence->find("reset-epoch" + std::to_string(eventEpoch + 1)));
    CHECK(evidence->find("reset-epoch" + std::to_string(eventEpoch + 1)) <
          evidence->find("display42"));
    CHECK(evidence->find("display42") < evidence->find("capture-enter42"));

    // Gate old capture43 and next-generation capture44 independently. Holding
    // capture44 proves there is no stale43 publication hidden by a later frame.
    evidence->arm("capture43");
    evidence->arm("capture44");
    memory.write64(displayAddress, 43);
    ps2GsSnapshotDisplay();
    evidence->wait("capture43");
    checkPicture(gs, true, 42);
    const auto captureEpoch = gsPrivCurrentEpoch();
    memory.write16(csrAddress, 0x200);
    checkReset(memory);
    checkPicture(gs, false);
    memory.write64(displayAddress, 44);
    ps2GsSnapshotDisplay();
    evidence->release("capture43");
    evidence->wait("capture44");
    checkPicture(gs, false);
    CHECK(memory.read64(displayAddress) == 44);
    CHECK(evidence->find("capture-return43") <
          evidence->find("reset-epoch" + std::to_string(captureEpoch + 1)));
    CHECK(evidence->find("reset-epoch" + std::to_string(captureEpoch + 1)) <
          evidence->find("display44"));
    CHECK(evidence->find("display44") < evidence->find("capture-enter44"));
    evidence->release("capture44");
    drain(gs);
    checkPicture(gs, true, 44);
    CHECK(evidence->stalePeeks == 2);

    // Fresh owner callbacks work, and unmasking their already pending flags
    // emits the IRQ once. This distinguishes suppression from disabling events.
    irq.store(0);
    packet[0] = 2;
    gs.processGIFPacket(packet, 16);
    drain(gs);
    CHECK(gsPrivLoad(memory.gs().siglblid) == 0x5566778811223344ull);
    CHECK((memory.read64(csrAddress) & 3u) == 3u && irq.load() == 0);
    memory.write64(imrAddress, 0);
    CHECK((irq.load() & 1u) != 0);
    drain(gs);
    CHECK(!peekEventFrontState());
    std::cout << "actual_fifo_frontend_checks=passed assertions=" << assertions
              << " stale_owner_peeks=2 backend=mock native_gpu_acceleration=0\n";
    return 0;
} catch (const std::exception& e) {
    std::cerr << "FAIL " << e.what() << '\n';
    return 1;
}
