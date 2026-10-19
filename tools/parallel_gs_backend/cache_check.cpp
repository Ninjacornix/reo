#include "pipeline_cache_store.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <thread>
using namespace reo_parallel_backend::cache_store;
static unsigned checks = 0;
#define CHECK(c)                                                                                   \
    do {                                                                                           \
        ++checks;                                                                                  \
        if (!(c))                                                                                  \
            throw std::runtime_error(std::string("CHECK failed: ") + #c + " line " +               \
                                     std::to_string(__LINE__));                                    \
    } while (0)
static Identity identity() {
    Identity id;
    id.vendor = 0x1002;
    id.device = 0x67DF;
    id.driver = 123;
    for (unsigned i = 0; i < 16; ++i)
        id.uuid[i] = uint8_t(i + 1);
    return id;
}
static std::vector<uint8_t> legacy(const Identity& id, uint8_t suffix) {
    std::vector<uint8_t> p(24 + 32 + 4);
    std::memcpy(p.data(), id.uuid.data(), 16);
    put32(p.data() + 24, 32);
    put32(p.data() + 28, 1);
    put32(p.data() + 32, id.vendor);
    put32(p.data() + 36, id.device);
    std::memcpy(p.data() + 40, id.uuid.data(), 16);
    p.back() = suffix;
    return p;
}
static std::vector<uint8_t> binary() {
    std::vector<uint8_t> p(56 + 16 + 8 + 8 + 16 + 32 + 8);
    constexpr char magic[16] = "GraniteBinary1";
    std::memcpy(p.data(), magic, 16);
    put32(p.data() + 16, 4);
    put32(p.data() + 52, 1); // One pipeline.
    put64(p.data() + 56, 123);
    put64(p.data() + 64, 1);
    put64(p.data() + 72, 456);
    put64(p.data() + 80, 1); // One blob.
    put64(p.data() + 88, 456);
    put32(p.data() + 96, 7);
    put32(p.data() + 100, 4); // Padded7-byte blob.
    return p;
}
int main(int argc, char** argv) try {
    if (argc != 2)
        throw std::runtime_error("Usage: pipeline_cache_store_check NEW_OUTPUT_DIRECTORY");
    const auto directory = std::filesystem::absolute(argv[1]);
    if (std::filesystem::exists(directory))
        throw std::runtime_error("Output exists");
    std::filesystem::create_directories(directory);
    const auto id = identity();
    const auto p = legacy(id, 1), q = legacy(id, 2);
    const auto envelope = encode(p, id);
    CHECK(!envelope.empty());
    CHECK(decode(envelope, id) == p);
    for (size_t length = 0; length < HeaderBytes; ++length) {
        auto truncated = envelope;
        truncated.resize(length);
        CHECK(decode(truncated, id).empty());
    }
    for (size_t field :
         std::initializer_list<size_t>{0, 16, 20, 24, 28, 32, 36, 40, 56, 64, 72, HeaderBytes}) {
        auto damaged = envelope;
        damaged[field] ^= 1;
        CHECK(decode(damaged, id).empty());
    }
    auto changed = id;
    changed.driver++;
    CHECK(decode(envelope, changed).empty());
    changed = id;
    changed.uuid[0]++;
    CHECK(decode(envelope, changed).empty());
    changed = id;
    changed.flags++;
    CHECK(decode(envelope, changed).empty());
    auto oversized = envelope;
    put64(oversized.data() + 64, MaxPayload + 1);
    CHECK(decode(oversized, id).empty());
    auto badVulkan = p;
    put32(badVulkan.data() + 24, 31);
    CHECK(encode(badVulkan, id).empty());
    badVulkan = p;
    put32(badVulkan.data() + 28, 2);
    CHECK(encode(badVulkan, id).empty());
    auto binaryId = id;
    binaryId.format = 1;
    const auto bp = binary();
    CHECK(binaryStructure(bp.data(), bp.size()));
    const auto be = encode(bp, binaryId);
    CHECK(decode(be, binaryId) == bp);
    CHECK(decode(be, id).empty());
    for (size_t offset : std::initializer_list<size_t>{16, 52, 64, 80, 96, 100}) {
        auto malformed = bp;
        put32(malformed.data() + offset, 0xFFFFFFFF);
        CHECK(encode(malformed, binaryId).empty());
    }
    auto truncated = bp;
    truncated.pop_back();
    CHECK(encode(truncated, binaryId).empty());
    const auto path = directory / L"driver.cache";
    CHECK(load(path, id).empty());
    CHECK(save(path, p, id));
    CHECK(load(path, id) == p);
    CHECK(save(path, q, id));
    CHECK(load(path, id) == q);
    CHECK(load(path, changed).empty());
    // Win32 sharing locks reject replacement; POSIX readers retain the old inode.
#if defined(_WIN32)
    const HANDLE locked = CreateFileW(path.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr,
                                      OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    CHECK(locked != INVALID_HANDLE_VALUE);
    const bool replaced = save(path, p, id);
    CloseHandle(locked);
    CHECK(!replaced);
    CHECK(load(path, id) == q);
#else
    const int locked = ::open(path.c_str(), O_RDONLY | O_CLOEXEC);
    CHECK(locked >= 0);
    CHECK(save(path, p, id));
    CHECK(load(path, id) == p);
    std::vector<uint8_t> prior(encode(q, id).size());
    CHECK(::read(locked, prior.data(), prior.size()) == ssize_t(prior.size()));
    CHECK(decode(prior, id) == q);
    CHECK(::close(locked) == 0);
#endif
    for (const auto& entry : std::filesystem::directory_iterator(directory))
        CHECK(entry.path().filename().wstring().find(L".tmp.") == std::wstring::npos);
    bool first = false, second = false;
    std::thread one([&] { first = save(path, p, id); });
    std::thread two([&] { second = save(path, q, id); });
    one.join();
    two.join();
    CHECK(first || second);
    const auto final = load(path, id);
    CHECK(final == p || final == q);
    // Size cap checked from file metadata before any large payload allocation.
    const auto huge = directory / L"oversized.cache";
#if defined(_WIN32)
    const HANDLE file = CreateFileW(huge.c_str(), GENERIC_WRITE, 0, nullptr, CREATE_NEW,
                                    FILE_ATTRIBUTE_NORMAL, nullptr);
    CHECK(file != INVALID_HANDLE_VALUE);
    LARGE_INTEGER end{};
    end.QuadPart = MaxPayload + HeaderBytes + 1;
    const bool sized = SetFilePointerEx(file, end, nullptr, FILE_BEGIN) && SetEndOfFile(file);
    CloseHandle(file);
    CHECK(sized);
#else
    const int file = ::open(huge.c_str(), O_WRONLY | O_CREAT | O_EXCL | O_CLOEXEC, 0600);
    CHECK(file >= 0);
    CHECK(::ftruncate(file, off_t(MaxPayload + HeaderBytes + 1)) == 0);
    CHECK(::close(file) == 0);
    const auto symlink = directory / "symlink.cache";
    std::filesystem::create_symlink(path, symlink);
    CHECK(load(symlink, id).empty());
#endif
    CHECK(load(huge, id).empty());
    const auto stable1 = defaultPath(id), stable2 = defaultPath(id);
    CHECK(stable1 == stable2);
    std::ofstream report(directory / L"result.json");
    report << "{\"checks\":" << checks << ",\"failures\":0,\"gpu\":false,\"native\":false}\n";
    CHECK(bool(report));
    std::cout << "PASS cache_io_codec checks=" << checks << " gpu=0 native=0\n";
    return 0;
} catch (const std::exception& e) {
    std::cerr << "FAIL " << e.what() << " checks=" << checks << '\n';
    return 1;
}
