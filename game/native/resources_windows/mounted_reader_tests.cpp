#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0A00
#endif
#include "mounted_reader.hpp"

#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <array>
#include <algorithm>
#include <atomic>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <latch>
#include <new>
#include <thread>
#include <utility>

// Test executable only: replace its ReadFile import pointer. Production library
// sources are unchanged. Real reads still use the OS function obtained directly
// from kernel32; faults/short completions affect only explicitly armed calls.
namespace injection {
using ReadFileFunction = BOOL(WINAPI*)(HANDLE, LPVOID, DWORD, LPDWORD, LPOVERLAPPED);
enum class Mode { none, short_read, error_after_prefix, block };
std::atomic<Mode> mode{Mode::none};
std::atomic<unsigned> calls{0};
std::latch* entered = nullptr;
std::latch* release = nullptr;
thread_local bool fail_allocation = false;
ReadFileFunction real_read() noexcept {
    static const auto actual = [] {
        const auto address = GetProcAddress(GetModuleHandleW(L"kernel32.dll"), "ReadFile");
        ReadFileFunction result{};
        static_assert(sizeof(result) == sizeof(address));
        std::memcpy(&result, &address, sizeof(result));
        if (!result)
            std::abort();
        return result;
    }();
    return actual;
}
BOOL WINAPI read(HANDLE file, LPVOID output, DWORD count, LPDWORD actual,
                 LPOVERLAPPED overlap) noexcept {
    ++calls;
    const auto fault = mode.exchange(Mode::none);
    if (fault == Mode::block) {
        entered->count_down();
        release->wait();
    }
    if (fault == Mode::short_read || fault == Mode::error_after_prefix) {
        const auto success = real_read()(file, output, count / 2, actual, overlap);
        if (fault == Mode::error_after_prefix) {
            SetLastError(ERROR_READ_FAULT);
            return FALSE;
        }
        return success;
    }
    return real_read()(file, output, count, actual, overlap);
}
} // namespace injection
extern "C" {
injection::ReadFileFunction __imp_ReadFile = injection::read;
}

#if defined(__GNUC__)
#define TEST_NOINLINE __attribute__((noinline))
#else
#define TEST_NOINLINE __declspec(noinline)
#endif
TEST_NOINLINE void* operator new(std::size_t size) {
    if (std::exchange(injection::fail_allocation, false))
        throw std::bad_alloc();
    if (auto* value = std::malloc(size ? size : 1))
        return value;
    throw std::bad_alloc();
}
TEST_NOINLINE void operator delete(void* value) noexcept {
    std::free(value);
}
TEST_NOINLINE void operator delete(void* value, std::size_t) noexcept {
    std::free(value);
}
TEST_NOINLINE void* operator new[](std::size_t size) {
    return ::operator new(size);
}
TEST_NOINLINE void operator delete[](void* value) noexcept {
    ::operator delete(value);
}
TEST_NOINLINE void operator delete[](void* value, std::size_t) noexcept {
    ::operator delete(value);
}

namespace w = reo::native::resources::win32;
namespace r = reo::native::resources;
namespace fs = std::filesystem;
namespace {
unsigned checks = 0;
void check(bool value, const char* message) {
    ++checks;
    if (!value)
        throw std::runtime_error(message);
}
std::vector<std::uint8_t> read_file(const fs::path& path) {
    std::ifstream file(path, std::ios::binary | std::ios::ate);
    check(bool(file), "Fixture input open");
    const auto size = file.tellg();
    check(size >= 0 && size < 256 * 1024 * 1024, "Fixture size bound");
    std::vector<std::uint8_t> result(static_cast<std::size_t>(size));
    file.seekg(0);
    file.read(reinterpret_cast<char*>(result.data()), result.size());
    check(bool(file), "Fixture exact input read");
    return result;
}
std::shared_ptr<w::MountedReader> reader(const fs::path& root, bool overlay = false,
                                         std::size_t maximum = 8 * 1024 * 1024) {
    const std::optional<fs::path> plan =
        overlay ? std::optional<fs::path>{root / "asset-overlay.bin"} : std::nullopt;
    auto opened = w::MountedReader::open_file1_windows(root / "data", plan, maximum);
    if (opened.status != w::MountStatus::ok)
        throw std::runtime_error("Reader admission failed: " + opened.detail);
    check(bool(opened.reader), "Successful factory returns reader");
    return std::move(opened.reader);
}
std::uint32_t lba(const w::MountedReader& value, std::string_view key) {
    const auto route = value.mount().find_file(key);
    check(bool(route), "Expected immutable route exists");
    return route->lba;
}
template <std::size_t N> void unchanged(const std::array<std::byte, N>& bytes) {
    check(std::all_of(bytes.begin(), bytes.end(),
                      [](auto value) { return value == std::byte{0xA5}; }),
          "Rejected/failed output remains byte-for-byte unchanged");
}
void coverage(const fs::path& root) {
    auto value = reader(root);
    const auto aligned = lba(*value, "ALIGNED.BIN"), alpha = lba(*value, "ALPHA.BIN");
    const auto expected = read_file(root / "data/aligned.bin");
    std::array<std::byte, 8192> exact{};
    auto result = value->read_sectors(aligned, 4, exact);
    check(result.disposition == w::ReaderDisposition::ok &&
              result.resource_status == r::Status::ok && result.bytes == exact.size() &&
              std::memcmp(exact.data(), expected.data(), exact.size()) == 0,
          "Whole aligned file read is exact");
    std::array<std::byte, 2048> block{};
    result = value->read_sectors(aligned + 3, 1, block);
    check(result.disposition == w::ReaderDisposition::ok && result.bytes == block.size() &&
              std::memcmp(block.data(), expected.data() + 6144, block.size()) == 0,
          "Read ending exactly at EOF admitted");
    const std::array<std::pair<std::uint32_t, std::uint32_t>, 6> misses{{{0, 1},
                                                                         {aligned, 0},
                                                                         {aligned, 0x4001},
                                                                         {aligned + 4, 1},
                                                                         {alpha + 2, 1},
                                                                         {aligned + 0x4000, 1}}};
    for (const auto [sector, count] : misses) {
        block.fill(std::byte{0xA5});
        injection::calls = 0;
        result = value->read_sectors(sector, count, block);
        check(result.disposition == w::ReaderDisposition::not_covered && result.bytes == 0 &&
                  injection::calls == 0,
              "Unknown/count/EOF/read-ahead/output mismatch rejects before source I/O");
        unchanged(block);
    }
    std::array<std::byte, 4096> mismatched;
    mismatched.fill(std::byte{0xA5});
    injection::calls = 0;
    result = value->read_sectors(aligned, 1, mismatched);
    check(result.disposition == w::ReaderDisposition::not_covered && injection::calls == 0,
          "Larger destination rejected before I/O");
    unchanged(mismatched);
    auto limited = reader(root, false, 2048);
    mismatched.fill(std::byte{0xA5});
    injection::calls = 0;
    result = limited->read_sectors(aligned, 2, mismatched);
    check(result.disposition == w::ReaderDisposition::not_covered &&
              result.resource_status == r::Status::read_limit && injection::calls == 0,
          "Configured read limit excludes before I/O");
    unchanged(mismatched);
    check(limited->read_sectors(aligned, 1, block).disposition == w::ReaderDisposition::ok,
          "Exact configured limit remains covered");
    const auto identity = value->identity().route_sha256;
    check(identity == value->mount().identity().route_sha256 && identity != w::Digest{},
          "Reader exposes actual retained route identity");
}

void failures(const fs::path& root) {
    auto value = reader(root);
    const auto sector = lba(*value, "ALIGNED.BIN");
    const auto expected = read_file(root / "data/aligned.bin");
    std::array<std::byte, 4096> output;
    for (const auto mode : {injection::Mode::short_read, injection::Mode::error_after_prefix}) {
        output.fill(std::byte{0xA5});
        injection::calls = 0;
        injection::mode = mode;
        const auto result = value->read_sectors(sector, 2, output);
        check(result.disposition == w::ReaderDisposition::failed &&
                  result.resource_status == r::Status::source_failure && result.bytes == 0 &&
                  injection::calls == 1,
              "Admitted partial/failed source read is failed, never fallback/retry");
        unchanged(output);
        check(value->read_sectors(sector, 2, output).disposition == w::ReaderDisposition::ok &&
                  std::memcmp(output.data(), expected.data(), output.size()) == 0,
              "Later exact read recovers on same retained source");
    }
    output.fill(std::byte{0xA5});
    injection::calls = 0;
    injection::fail_allocation = true;
    const auto result = value->read_sectors(sector, 2, output);
    check(!injection::fail_allocation && result.disposition == w::ReaderDisposition::failed &&
              result.resource_status == r::Status::no_memory && result.bytes == 0 &&
              injection::calls == 0,
          "Admitted staging allocation failure is failed before provider I/O");
    unchanged(output);
    check(value->read_sectors(sector, 2, output).disposition == w::ReaderDisposition::ok,
          "Allocation failure does not poison reader");
}

void overlay(const fs::path& root) {
    auto value = reader(root, true);
    const auto virtual_lba = lba(*value, "NETBIO00.DAT");
    const auto selected = value->mount().find_file("NETBIO00.DAT");
    check(selected->overlay && virtual_lba == 0x20000000, "Overlay uses actual virtual LBA route");
    const auto payload =
        read_file(root / fs::path(std::u8string(u8"cache/replacement-\u00e9-\u6728-0.bin")));
    std::array<std::byte, 2048> output{};
    check(value->read_sectors(virtual_lba + 1, 1, output).disposition == w::ReaderDisposition::ok &&
              std::memcmp(output.data(), payload.data(), output.size()) == 0,
          "Exact replacement payload bytes read through native view");
    const auto* original = static_cast<const w::MountedRoute*>(nullptr);
    for (const auto& route : value->mount().routes())
        if (route.key == "NETBIO00.DAT" && !route.overlay)
            original = &route;
    check(original != nullptr, "Original base route remains retained alongside overlay");
    const auto base = read_file(root / "data/NETBIO00.DAT");
    check(value->read_sectors(original->lba + 1, 1, output).disposition ==
                  w::ReaderDisposition::ok &&
              std::memcmp(output.data(), base.data() + 2048, output.size()) == 0,
          "Original PAK LBA still returns original bytes");
    const auto final_sector = virtual_lba + static_cast<std::uint32_t>(selected->bytes / 2048);
    output.fill(std::byte{0xA5});
    injection::calls = 0;
    const auto result = value->read_sectors(final_sector, 1, output);
    check(result.disposition == w::ReaderDisposition::not_covered && injection::calls == 0,
          "Partial overlay EOF excluded before I/O");
    unchanged(output);
}

void concurrent(const fs::path& root) {
    auto value = reader(root);
    const auto sector = lba(*value, "ALIGNED.BIN");
    const auto expected = read_file(root / "data/aligned.bin");
    std::atomic<bool> failed{false};
    std::array<std::thread, 5> threads;
    for (auto& thread : threads)
        thread = std::thread([held = value, &failed, &expected, sector] {
            for (unsigned i = 0; i < 100; ++i) {
                std::array<std::byte, 2048> output{};
                const auto at = i % 4;
                const auto result = held->read_sectors(sector + at, 1, output);
                if (result.disposition != w::ReaderDisposition::ok ||
                    result.bytes != output.size() ||
                    std::memcmp(output.data(), expected.data() + at * 2048, output.size()) != 0)
                    failed = true;
            }
        });
    for (auto& thread : threads)
        thread.join();
    check(!failed, "Concurrent synchronous reads use independent caller destinations and exact "
                   "retained bytes");
}

HANDLE write_handle(const fs::path& name) {
    return CreateFileW(name.c_str(), GENERIC_WRITE,
                       FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, nullptr,
                       OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
}
void lifetime(const fs::path& root) {
    auto value = reader(root);
    const auto sector = lba(*value, "ALIGNED.BIN");
    const auto expected = read_file(root / "data/aligned.bin");
    std::weak_ptr<w::MountedReader> weak = value;
    std::latch entered(1), release(1);
    injection::entered = &entered;
    injection::release = &release;
    injection::mode = injection::Mode::block;
    std::array<std::byte, 2048> output{};
    w::MountedReadResult result;
    std::thread active([held = value, &output, &result, sector]() mutable {
        result = held->read_sectors(sector, 1, output);
        held.reset();
    });
    entered.wait();
    value.reset();
    check(!weak.expired(), "Calling owner is retained while synchronous source read is blocked");
    HANDLE denied = write_handle(root / "data/aligned.bin");
    check(denied == INVALID_HANDLE_VALUE, "Active read retains exact source sharing exclusion");
    release.count_down();
    active.join();
    injection::entered = nullptr;
    injection::release = nullptr;
    check(result.disposition == w::ReaderDisposition::ok &&
              std::memcmp(output.data(), expected.data(), output.size()) == 0,
          "Blocked read completes before releasing its provider owner");
    check(weak.expired(), "Final reader owner closes/drains before releasing mount");
    HANDLE writable = write_handle(root / "data/aligned.bin");
    check(writable != INVALID_HANDLE_VALUE,
          "Reader destruction releases all route handles and pinned files");
    CloseHandle(writable);
}

void construction(const fs::path& root) {
    const auto data = root / "data";
    injection::calls = 0;
    const auto zero = w::MountedReader::open_file1_windows(root / "does-not-exist", {}, 0);
    check(zero.status == w::MountStatus::unsupported_layout && !zero.reader &&
              injection::calls == 0,
          "Zero read budget rejects before mount I/O");
    injection::fail_allocation = true;
    const auto memory = w::MountedReader::open_file1_windows(data);
    check(!injection::fail_allocation && memory.status == w::MountStatus::no_memory &&
              !memory.reader,
          "Construction allocation failure exposes no partial reader");
    const auto invalid = w::MountedReader::open_file1_windows(root / "bad-data");
    check(invalid.status != w::MountStatus::ok && !invalid.reader,
          "Invalid mount exposes no partial reader");
    HANDLE writable = write_handle(root / "data/aligned.bin");
    check(writable != INVALID_HANDLE_VALUE, "Failed construction retained no data provider");
    CloseHandle(writable);
}
} // namespace

int main(int argc, char** argv) {
    try {
        check(argc == 4, "Pass private fixture root, token and scenario");
        const auto root = fs::absolute(fs::path(reinterpret_cast<const char8_t*>(argv[1])));
        const std::string token(argv[2]), scenario(argv[3]);
        check(token.size() == 32 &&
                  token.find_first_not_of("0123456789abcdef") == std::string::npos &&
                  root.parent_path().filename() == "synthetic-" + token &&
                  root.parent_path().parent_path().filename() == "mounted-reader-checks",
              "Only fresh private test tree admitted");
        const auto marker = read_file(root.parent_path() / ".mounted-reader-fixture");
        check(std::string(marker.begin(), marker.end()) == token, "Fixture marker matches");
        if (scenario == "coverage")
            coverage(root);
        else if (scenario == "failures")
            failures(root);
        else if (scenario == "overlay")
            overlay(root);
        else if (scenario == "concurrent")
            concurrent(root);
        else if (scenario == "lifetime")
            lifetime(root);
        else if (scenario == "construction")
            construction(root);
        else
            throw std::runtime_error("Unknown synthetic scenario");
        std::cout << scenario << ": " << checks << " mounted reader checks passed\n";
        return 0;
    } catch (const std::exception& error) {
        std::cerr << "FAIL: " << error.what() << '\n';
        return 1;
    }
}
