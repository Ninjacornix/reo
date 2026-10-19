// Source-only generic authority/ordering checks. Parent owns compilation/run.
#include "gs_backend_route.h"
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <thread>
using namespace gs_backend_bridge;
#define CHECK(condition)                                                                           \
    do {                                                                                           \
        if (!(condition))                                                                          \
            throw std::logic_error("CHECK failed: " #condition);                                   \
    } while (0)
struct Evidence {
    std::vector<std::string> log;
    int closes = 0;
    bool initOk = true, explode = false;
};
struct Mock final : Backend {
    std::shared_ptr<Evidence> evidence;
    explicit Mock(std::shared_ptr<Evidence> e) : evidence(std::move(e)) {}
    bool init(const Init& value, std::string& reason) override {
        CHECK(value.vramSize == 4u * 1024u * 1024u);
        evidence->log.push_back("init");
        reason = "injected initialization failure";
        return evidence->initOk;
    }
    void close() noexcept override {
        ++evidence->closes;
    }
    void reset() override {
        evidence->log.push_back("reset");
    }
    void rawGif(uint8_t p, const uint8_t*, size_t) override {
        if (evidence->explode)
            throw std::runtime_error("injected draw failure");
        evidence->log.push_back("gif" + std::to_string(p));
    }
    void directRegister(uint8_t, uint64_t) override {
        evidence->log.push_back("reg");
    }
    void privilegedWrite(uint32_t o, uint8_t width, uint64_t value) override {
        CHECK(o == 0x1000 && width == 4 && value == 3);
        evidence->log.push_back("csr-w1c-input");
    }
    Frame capture(const Capture& c) override {
        CHECK(c.registers[7] == 42);
        evidence->log.push_back("capture");
        Frame f;
        f.width = 2;
        f.height = 1;
        f.rgba.assign(8, 127);
        return f;
    }
    void exportVram(size_t, uint8_t* dst, size_t n) override {
        evidence->log.push_back("export");
        std::fill(dst, dst + n, 0xA5);
    }
    uint32_t readTransfer(uint8_t* dst, uint32_t n) override {
        evidence->log.push_back("read");
        std::fill(dst, dst + n, 9);
        return n;
    }
    bool clearContext(uint32_t, uint32_t, bool) override {
        evidence->log.push_back("clear");
        return true;
    }
    void flush() override {
        evidence->log.push_back("flush");
    }
};
int main() {
    std::vector<uint8_t> vram(4u * 1024u * 1024u), packet(16);
    Init init{vram.data(), vram.size(), {}};
    Route route;
    std::string reason;
    auto e = std::make_shared<Evidence>();
    Factory make = [e] { return std::make_unique<Mock>(e); };
    CHECK(!route.start(Choice::Software, init, make, reason));
    CHECK(e->log.empty());
    CHECK(!route.gif(3, packet.data(), packet.size()));
    CHECK(!route.start(Choice::Parallel, init, {}, reason));
    CHECK(route.state() == State::Software);
    e->initOk = false;
    CHECK(!route.start(Choice::Parallel, init, make, reason));
    CHECK(e->closes == 1);
    e->initOk = true;
    CHECK(route.start(Choice::Parallel, init, make, reason));
    e->log.clear();
    CHECK(currentPath() == 3);
    {
        PathScope p1(1);
        CHECK(currentPath() == 1);
        {
            PathScope p2(2);
            CHECK(currentPath() == 2);
        }
        CHECK(currentPath() == 1);
        std::thread isolated([] { CHECK(currentPath() == 3); });
        isolated.join();
    }
    CHECK(currentPath() == 3);
    CHECK(route.gif(1, packet.data(), 16));
    CHECK(route.gif(2, packet.data(), 16));
    CHECK(route.gif(3, packet.data(), 16));
    CHECK(route.reg(0x4C, 7));
    CHECK(route.privileged(0x1000, 4, 3));
    Capture capture;
    capture.registers[7] = 42;
    capture.tick = 53;
    Frame frame;
    CHECK(route.capture(capture, frame));
    CHECK(frame.tick == 53 && frame.rgba.size() == 8);
    uint8_t out[17]{};
    uint32_t count = 0;
    CHECK(route.readTransfer(out, 17, count));
    CHECK(count == 17 && out[16] == 9);
    CHECK(route.exportVram(0, out, 17));
    CHECK(out[16] == 0xA5);
    bool clear = false;
    CHECK(route.clear(0, 0, true, clear) && clear);
    CHECK(route.flush());
    CHECK(route.reset());
    CHECK((e->log == std::vector<std::string>{"gif1", "gif2", "gif3", "reg", "csr-w1c-input",
                                              "capture", "read", "export", "clear", "flush",
                                              "reset"}));
    e->explode = true;
    bool drawFailed = false;
    try {
        route.gif(1, packet.data(), 16);
    } catch (const std::runtime_error&) {
        drawFailed = true;
    }
    CHECK(drawFailed && route.state() == State::Failed);
    bool remainedFailed = false;
    try {
        route.reg(0, 0);
    } catch (const std::runtime_error&) {
        remainedFailed = true;
    }
    CHECK(remainedFailed);
    route.stop();
    CHECK(route.state() == State::Stopped && e->closes == 2);
    e->explode = false;
    CHECK(route.start(Choice::Parallel, init, make, reason));
    CHECK(route.reset());
    route.stop();
    CHECK(e->closes == 3);
    // Bounds are an execution error, preserving GPU authority rather than fallback.
    CHECK(route.start(Choice::Parallel, init, make, reason));
    bool boundsFailed = false;
    try {
        route.exportVram(vram.size() - 1, out, 2);
    } catch (const std::out_of_range&) {
        boundsFailed = true;
    }
    CHECK(boundsFailed && route.state() == State::Failed);
    route.stop();
    std::cout
        << "generic_authority_checks=passed native_gpu_integration=0 runtime_fifo_checks=not_run\n";
}
