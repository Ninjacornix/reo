#include "ps2_runtime.h"
#include "reo_hw_bridge.h"
#include "game/native/resources_windows/mounted_reader.hpp"
#include "../runtime_adapter.h"

#include <array>
#include <chrono>
#include <condition_variable>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <future>
#include <iostream>
#include <mutex>
#include <stdexcept>
#include <string>

using namespace std::chrono_literals;
namespace native = reo::native::resources::win32;
namespace api = reo_native_resource_reads;
namespace {
unsigned checks{};
void check(bool value, const char* expression) {
    ++checks;
    if (!value) throw std::runtime_error(expression);
}
#define CHECK(...) check((__VA_ARGS__), #__VA_ARGS__)
constexpr std::uint32_t packet = 0x207A00, destination = 0x500000;
void put(std::uint8_t* ram, std::uint32_t at, std::uint32_t value) { std::memcpy(ram + at, &value, 4); }
void opt(const char* name, const char* value) { _putenv_s(name, value); }
void seed(PS2Runtime& runtime, const char* fixture) {
    std::ifstream file(fixture, std::ios::binary);
    CHECK(bool(file));
    for (unsigned i = 0; i < 3; ++i) {
        std::array<std::uint32_t, 2> header{};
        file.read(reinterpret_cast<char*>(header.data()), sizeof(header));
        CHECK(bool(file) && header[0] < PS2_RAM_SIZE && header[1] <= PS2_RAM_SIZE - header[0]);
        file.read(reinterpret_cast<char*>(runtime.memory().getRDRAM() + header[0]), header[1]);
        CHECK(bool(file));
    }
}
void request(PS2Runtime& runtime, std::uint32_t output = destination, std::uint32_t count = 1) {
    auto* ram = runtime.memory().getRDRAM();
    put(ram, packet, 77); put(ram, packet + 4, count); put(ram, packet + 8, output);
    ram[packet + 14] = 0;
    put(ram, packet + 16, 0x208A00); put(ram, packet + 20, 0x208AC0);
    put(ram, 0x208A00, 0); put(ram, 0x208A04, 0);
}
void configure(PS2Runtime& runtime) {
    api::configure("SLUS-20765", runtime.memory().getRDRAM(), PS2_RAM_SIZE, runtime,
                   std::filesystem::path(L"synthetic-\u6e2c\u8a66"));
}
bool read(PS2Runtime& runtime, bool& ok) {
    return api::tryRead(runtime.memory().getRDRAM(), &runtime, packet, 0x18, 0, 0, ok);
}
void untouched_refusal(PS2Runtime& runtime, std::uint32_t send = packet, std::uint32_t send_size = 0x18,
                        std::uint32_t receive = 0, std::uint32_t receive_size = 0) {
    auto* ram = runtime.memory().getRDRAM();
    const auto before = native::mock::reads.load();
    ram[destination] = 0x47;
    bool ok = true;
    CHECK(!api::tryRead(ram, &runtime, send, send_size, receive, receive_size, ok));
    CHECK(ok && ram[destination] == 0x47 && native::mock::reads == before);
}
struct Gate {
    std::mutex mutex;
    std::condition_variable cv;
    bool entered{}, released{};
    void block() {
        std::unique_lock lock(mutex);
        entered = true; cv.notify_all();
        if (!cv.wait_for(lock, 5s, [&] { return released; })) throw std::runtime_error("mock read timeout");
    }
    void wait() { std::unique_lock lock(mutex); CHECK(cv.wait_for(lock, 2s, [&] { return entered; })); }
    void release() { std::lock_guard lock(mutex); released = true; cv.notify_all(); }
};
struct ReleaseOnExit { Gate& gate; ~ReleaseOnExit() { gate.release(); } };

void operations(const char* fixture) {
    std::weak_ptr<native::MountedReader> lifetime;
    {
        PS2Runtime runtime; ReoHwBridge bridge;
        seed(runtime, fixture); request(runtime); configure(runtime);
        CHECK(runtime.registrations == 1 && native::mock::opens == 1);
        configure(runtime); CHECK(runtime.registrations == 1 && native::mock::opens == 1);
        CHECK(native::mock::captured_limit == 8u * 1024u * 1024u);
        CHECK(native::mock::captured_root == std::filesystem::path(L"synthetic-\u6e2c\u8a66"));
        CHECK(!native::mock::captured_overlay);
        PS2Runtime::GuestExecutionScope guest(&runtime);
        bool ok = false;
        CHECK(read(runtime, ok) && ok);
        CHECK(native::mock::reads == 1 && native::mock::io_calls == 1);
        CHECK(runtime.memory().getRDRAM()[destination] == 0x63);
        lifetime = native::mock::last_reader;
        runtime.requestStop();
        CHECK(runtime.joinWorkers() && !lifetime.expired());
        untouched_refusal(runtime);
    }
    CHECK(lifetime.expired() && native::mock::deaths == 1);
}

void refusals(const char* fixture) {
    PS2Runtime runtime; ReoHwBridge bridge;
    seed(runtime, fixture); request(runtime); configure(runtime);
    // No guest execution is a refusal, never an implicit scope acquisition.
    untouched_refusal(runtime);
    PS2Runtime::GuestExecutionScope guest(&runtime);
    untouched_refusal(runtime, packet + 4); untouched_refusal(runtime, packet, 0x14);
    untouched_refusal(runtime, packet, 0x18, 1, 0); untouched_refusal(runtime, packet, 0x18, 0, 4);
    auto* ram = runtime.memory().getRDRAM();
    for (const std::uint8_t mode : {std::uint8_t{1}, std::uint8_t{2}, std::uint8_t{255}}) {
        request(runtime); ram[packet + 14] = mode; untouched_refusal(runtime);
    }
    for (const auto at : {packet + 16, packet + 20, 0x208A00u, 0x208A04u}) {
        request(runtime); put(ram, at, 1); untouched_refusal(runtime);
    }
    for (const auto count : {0u, 0x4001u, 4097u}) {
        request(runtime, destination, count); untouched_refusal(runtime);
    }
    request(runtime); put(ram, packet, 0xFFFFFFFF); put(ram, packet + 4, 2); untouched_refusal(runtime);
    for (const auto output : {0u, destination + 1, PS2_RAM_SIZE, PS2_RAM_SIZE - 64,
                              0x207A00u, 0x208AC0u, 0x208A00u, 0x100280u, 0x1004C0u,
                              0x101780u, 0x21BB80u, 0x21CC40u, 0x21D8C0u}) {
        request(runtime, output); untouched_refusal(runtime);
    }
    request(runtime);
    bool ok = true;
    CHECK(!api::tryRead(nullptr, &runtime, packet, 0x18, 0, 0, ok) && ok);
    CHECK(!api::tryRead(ram, nullptr, packet, 0x18, 0, 0, ok) && ok);
    PS2Runtime other;
    CHECK(!api::tryRead(ram, &other, packet, 0x18, 0, 0, ok) && ok);
    CHECK(native::mock::reads == 0 && native::mock::io_calls == 0);
}

void reader_results(const char* fixture) {
    PS2Runtime runtime; ReoHwBridge bridge;
    seed(runtime, fixture); request(runtime); configure(runtime);
    PS2Runtime::GuestExecutionScope guest(&runtime);
    auto* ram = runtime.memory().getRDRAM();
    native::mock::action = [](auto, auto, auto) {
        return native::MountedReadResult{native::ReaderDisposition::not_covered,
                                         reo::native::resources::Status::invalid_range, 0};
    };
    bool ok = true;
    ram[destination] = 0x47;
    CHECK(!read(runtime, ok) && ok && ram[destination] == 0x47 && native::mock::io_calls == 0);
    native::mock::action = [](auto, auto, auto) {
        ++native::mock::io_calls;
        return native::MountedReadResult{native::ReaderDisposition::failed,
                                         reo::native::resources::Status::source_failure, 0};
    };
    CHECK(read(runtime, ok) && !ok && ram[destination] == 0x47 && native::mock::io_calls == 1);
    native::mock::action = [](auto, auto, auto output) {
        ++native::mock::io_calls;
        output[0] = std::byte{0x99};
        return native::MountedReadResult{native::ReaderDisposition::ok,
                                         reo::native::resources::Status::ok, output.size() - 1};
    };
    ok = true;
    CHECK(read(runtime, ok) && !ok && ram[destination] == 0x99 && native::mock::io_calls == 2);
    // A broken reader contract cannot lead to duplicate legacy I/O.
    native::mock::action = [](auto, auto, auto output) {
        ++native::mock::io_calls;
        return native::MountedReadResult{native::ReaderDisposition::ok,
                                         reo::native::resources::Status::source_failure, output.size()};
    };
    ok = true;
    CHECK(read(runtime, ok) && !ok && native::mock::io_calls == 3);
}

void shutdown(const char* fixture, bool self_join) {
    Gate gate;
    PS2Runtime runtime; ReoHwBridge bridge;
    seed(runtime, fixture); request(runtime); configure(runtime);
    ReleaseOnExit release{gate};
    std::atomic<bool> self_refused{}, nested_refused{};
    native::mock::action = [&](auto, auto, auto output) {
        ++native::mock::io_calls;
        if (self_join) {
            bool nested_ok = true;
            nested_refused = !read(runtime, nested_ok) && nested_ok;
            runtime.requestStop();
            self_refused = !runtime.joinWorkers();
        } else gate.block();
        std::fill(output.begin(), output.end(), std::byte{0x23});
        return native::MountedReadResult{native::ReaderDisposition::ok,
                                         reo::native::resources::Status::ok, output.size()};
    };
    auto reading = std::async(std::launch::async, [&] {
        PS2Runtime::GuestExecutionScope guest(&runtime);
        bool ok = false;
        return read(runtime, ok) && ok;
    });
    if (!self_join) {
        gate.wait();
        runtime.requestStop();
        auto joining = std::async(std::launch::async, [&] { return runtime.joinWorkers(); });
        CHECK(joining.wait_for(30ms) == std::future_status::timeout);
        CHECK(!native::mock::last_reader.expired());
        gate.release();
        CHECK(reading.get() && joining.get());
    } else {
        CHECK(reading.get() && self_refused && nested_refused);
        CHECK(runtime.joinWorkers());
    }
    CHECK(native::mock::io_calls == 1);
}

void setup_refusal(const char* fixture, const std::string& scenario) {
    PS2Runtime runtime; ReoHwBridge bridge;
    seed(runtime, fixture); request(runtime);
    auto* ram = runtime.memory().getRDRAM();
    if (scenario == "flag-off") opt("REO_NATIVE_RESOURCE_READS", "0");
    if (scenario == "pak-off") opt("REO_GAME_PAK", "0");
    if (scenario == "async-on") opt("REO_CD_ASYNC", "1");
    if (scenario == "async-unset") _putenv_s("REO_CD_ASYNC", "");
    if (scenario == "mount-failure") native::mock::factory_failure = true;
    if (scenario == "null-mount") native::mock::null_factory = true;
    if (scenario == "layout-mismatch") bridge.matches = false;
    if (scenario == "missing-bridge") ReoHwBridge::current = nullptr;
    if (scenario == "registration-refused") runtime.registration_allowed = false;
    if (scenario == "stopped") runtime.requestStop();
    if (scenario == "identity") ram[0x100500] ^= 1;
    if (scenario == "wrong-edition") api::configure("SLUS-20984", ram, PS2_RAM_SIZE, runtime, L"synthetic");
    else configure(runtime);
    CHECK(runtime.registrations == 0);
    PS2Runtime::GuestExecutionScope guest(&runtime);
    untouched_refusal(runtime);
    CHECK(native::mock::reads == 0 && native::mock::io_calls == 0);
}
} // namespace

int main(int argc, char** argv) {
    try {
        CHECK(argc == 3);
        opt("REO_NATIVE_RESOURCE_READS", "1"); opt("REO_GAME_PAK", "1"); opt("REO_CD_ASYNC", "0");
        _wputenv_s(L"REO_ASSET_OVERLAY", L"");
        const std::string scenario = argv[2];
        if (scenario == "operations") operations(argv[1]);
        else if (scenario == "refusals") refusals(argv[1]);
        else if (scenario == "reader-results") reader_results(argv[1]);
        else if (scenario == "shutdown") shutdown(argv[1], false);
        else if (scenario == "self-join") shutdown(argv[1], true);
        else if (scenario == "overlay") {
            _wputenv_s(L"REO_ASSET_OVERLAY", L"synthetic-\u6e2c\u8a66.plan");
            PS2Runtime runtime; ReoHwBridge bridge; seed(runtime, argv[1]); request(runtime); configure(runtime);
            CHECK(runtime.registrations == 1 && native::mock::captured_overlay == std::filesystem::path(L"synthetic-\u6e2c\u8a66.plan"));
        } else if (scenario == "disabled") {
            PS2Runtime runtime; ReoHwBridge bridge; seed(runtime, argv[1]); request(runtime); configure(runtime);
            CHECK(runtime.registrations == 0 && native::mock::opens == 0);
            PS2Runtime::GuestExecutionScope guest(&runtime); untouched_refusal(runtime);
        } else setup_refusal(argv[1], scenario);
        std::cout << scenario << ": " << checks << " host-only checks passed\n";
        return 0;
    } catch (const std::exception& error) {
        std::cerr << "Native payload adapter check failed: " << error.what() << '\n';
        return 1;
    }
}
