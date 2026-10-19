#include "gs_backend_route.h"
#include "runtime/ps2_gs_gpu.h"
#include "runtime/ps2_memory.h"
#include <algorithm>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <cstring>
#include <iostream>
#include <mutex>
#include <thread>
void ps2GsSnapshotDisplay();
void ps2GsRequestWorkerStop();
void ps2GsJoinWorker();
using namespace gs_backend_bridge;
#define CHECK(c)                                                                                   \
    do {                                                                                           \
        if (!(c))                                                                                  \
            throw std::logic_error("CHECK failed: " #c);                                           \
    } while (0)
struct Evidence {
    std::mutex mutex;
    std::condition_variable cv;
    bool gated = false, entered = false, released = false;
    std::vector<std::string> events;
    std::vector<uint8_t> vram;
    std::atomic<unsigned> closed{0};
};
struct Mock final : Backend {
    std::shared_ptr<Evidence> e;
    explicit Mock(std::shared_ptr<Evidence> value) : e(std::move(value)) {}
    bool init(const Init& value, std::string&) override {
        e->vram.assign(value.vram, value.vram + value.vramSize);
        return true;
    }
    void close() noexcept override {
        ++e->closed;
    }
    void reset() override {
        e->events.push_back("reset");
    }
    void rawGif(uint8_t path, const uint8_t* data, size_t n) override {
        CHECK(n == 16);
        std::unique_lock<std::mutex> lock(e->mutex);
        if (e->gated) {
            e->entered = true;
            e->cv.notify_all();
            e->cv.wait(lock, [&] { return e->released; });
        }
        e->events.push_back("gif" + std::to_string(path));
        e->vram[0] = data[0];
    }
    void directRegister(uint8_t reg, uint64_t value) override {
        e->events.push_back("reg");
        e->vram[1] = uint8_t(value);
        CHECK(reg == 1);
    }
    void privilegedWrite(uint32_t off, uint8_t width, uint64_t input) override {
        e->events.push_back("priv");
        CHECK(off == 0x1000 && width == 4 && input == 3);
    }
    Frame capture(const Capture& c) override {
        e->events.push_back("capture");
        CHECK(c.registers[7] == 42);
        Frame frame;
        frame.width = 1;
        frame.height = 1;
        frame.rgba = {e->vram[0], e->vram[1], 0, 255};
        return frame;
    }
    void exportVram(size_t off, uint8_t* dst, size_t n) override {
        e->events.push_back("export");
        std::memcpy(dst, e->vram.data() + off, n);
    }
    uint32_t readTransfer(uint8_t* dst, uint32_t n) override {
        e->events.push_back("read");
        std::fill(dst, dst + n, 7);
        return n;
    }
    bool clearContext(uint32_t, uint32_t, bool) override {
        e->events.push_back("clear");
        return true;
    }
    void flush() override {
        e->events.push_back("flush");
    }
};
int main() {
    _putenv_s("REO_GS_BACKEND", "parallel");
    _putenv_s("REO_GS_THREAD", "1");
    _putenv_s("REO_GS_BACKEND_ROUTE_TEST", "1");
    _putenv_s("REO_GS_PUBLICATION_LOG", "");
    _putenv_s("REO_GFX", "");
    auto e = std::make_shared<Evidence>();
    registerFactory([e] { return std::make_unique<Mock>(e); });
    std::vector<uint8_t> shadow(4u * 1024u * 1024u);
    GSRegisters registers{};
    registers.dispfb1 = 42;
    GS gs;
    gs.init(shadow.data(), uint32_t(shadow.size()), &registers);
    CHECK(active());
    uint8_t packet[16]{};
    packet[0] = 11;
    {
        PathScope scope(1);
        gs.processGIFPacket(packet, 16);
    }
    packet[0] = 99; // Queue has its own immutable copy.
    gs.writeRegister(1, 22);
    notifyPrivileged(0x1000, 4, 3);
    ps2GsSnapshotDisplay();
    uint8_t fifo[17]{};
    CHECK(gs.consumeLocalToHostBytes(fifo, 17) == 17 && fifo[16] == 7);
    CHECK(shadow[0] == 0 && shadow[1] == 0); // Software drawing did not run.
    std::vector<uint8_t> frame;
    uint32_t w = 0, h = 0;
    CHECK(gs.copyLatchedHostPresentationFrame(frame, w, h));
    CHECK(w == 1 && h == 1 && frame[0] == 11 && frame[1] == 22);
    exportCpuVram(shadow.data(), shadow.size());
    CHECK(shadow[0] == 11 && shadow[1] == 22);
    CHECK((e->events ==
           std::vector<std::string>{"gif1", "reg", "priv", "capture", "read", "export"}));
    // A canceled in-flight query must not leave a dangling guest/stack buffer.
    {
        std::lock_guard<std::mutex> lock(e->mutex);
        e->gated = true;
    }
    packet[0] = 33;
    {
        PathScope scope(2);
        gs.processGIFPacket(packet, 16);
    }
    {
        std::unique_lock<std::mutex> lock(e->mutex);
        CHECK(e->cv.wait_for(lock, std::chrono::seconds(3), [&] { return e->entered; }));
    }
    packet[0] = 44;
    {
        PathScope scope(3);
        gs.processGIFPacket(packet, 16);
    }
    std::atomic<bool> done{false};
    uint32_t canceled = 999;
    const uint64_t queuedBefore = debugControlQueuedCount();
    std::thread reader([&] {
        uint8_t bytes[3]{};
        canceled = gs.consumeLocalToHostBytes(bytes, 3);
        done = true;
    });
    const auto enqueueDeadline = std::chrono::steady_clock::now() + std::chrono::seconds(3);
    while (debugControlQueuedCount() == queuedBefore &&
           std::chrono::steady_clock::now() < enqueueDeadline)
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    const bool queryQueued = debugControlQueuedCount() == queuedBefore + 1u;
    const bool remainedPending = !done.load();
    ps2GsRequestWorkerStop();
    reader.join();
    CHECK(queryQueued && remainedPending && done && canceled == 0);
    {
        std::lock_guard<std::mutex> lock(e->mutex);
        e->released = true;
        e->cv.notify_all();
    }
    ps2GsJoinWorker();
    CHECK(e->closed == 1);
    CHECK(e->events.back() == "gif2");
    auto second = std::make_shared<Evidence>();
    registerFactory([second] { return std::make_unique<Mock>(second); });
    gs.init(shadow.data(), uint32_t(shadow.size()), &registers);
    CHECK(active());
    gs.reset();
    CHECK(second->events == std::vector<std::string>{"reset"});
    ps2GsJoinWorker();
    CHECK(second->closed == 1);
    // No registered native adapter: startup fallback remains usable software.
    registerFactory({});
    gs.init(shadow.data(), uint32_t(shadow.size()), &registers);
    CHECK(!active());
    ps2GsJoinWorker();
    std::cout << "actual_fifo_routing_checks=passed backend=mock native_gpu_acceleration=0\n";
}
