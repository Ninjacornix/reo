#include "pinned_file.hpp"
#include "game/native/resources/virtual_file_view.hpp"
#include "game/native/resources/resource_session.hpp"

#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <atomic>
#include <cstdlib>
#include <fstream>
#include <future>
#include <iostream>
#include <new>
#include <stdexcept>
#include <string>

namespace r = reo::native::resources;
namespace w = reo::native::resources::win32;
namespace {
std::atomic<bool> bounded_allocations{false};
}
#if defined(__GNUC__)
#define PIN_TEST_NOINLINE __attribute__((noinline))
#else
#define PIN_TEST_NOINLINE __declspec(noinline)
#endif
PIN_TEST_NOINLINE void* operator new(std::size_t bytes) {
    if (bounded_allocations.load() && bytes > 1024 * 1024) throw std::bad_alloc();
    if (auto* p = std::malloc(bytes ? bytes : 1)) return p;
    throw std::bad_alloc();
}
PIN_TEST_NOINLINE void operator delete(void* p) noexcept { std::free(p); }
PIN_TEST_NOINLINE void operator delete(void* p, std::size_t) noexcept { std::free(p); }
PIN_TEST_NOINLINE void* operator new[](std::size_t bytes) { return ::operator new(bytes); }
PIN_TEST_NOINLINE void operator delete[](void* p) noexcept { ::operator delete(p); }
PIN_TEST_NOINLINE void operator delete[](void* p, std::size_t) noexcept { ::operator delete(p); }

namespace {
unsigned checks{};
void check(bool value, const char* expression) {
    ++checks;
    if (!value) throw std::runtime_error(expression);
}
#define CHECK(...) check((__VA_ARGS__), #__VA_ARGS__)
w::Digest digest(const std::string& text) {
    CHECK(text.size() == 64);
    w::Digest value{};
    for (unsigned i = 0; i < value.size(); ++i)
        value[i] = static_cast<std::uint8_t>(std::stoul(text.substr(i * 2, 2), nullptr, 16));
    return value;
}
struct Fixture { std::filesystem::path path; std::uint64_t bytes{}; w::Digest hash{}; };
Fixture fixture(std::ifstream& input, const std::filesystem::path& root) {
    std::string name, hash;
    std::uint64_t bytes;
    CHECK(bool(input >> name >> bytes >> hash));
    return {root/std::filesystem::path(reinterpret_cast<const char8_t*>(name.c_str())), bytes, digest(hash)};
}
void identity_and_refusal(const Fixture& abc, const Fixture& empty) {
    CHECK(w::PinnedFile::open_verified("relative.bin", 3, abc.hash).status == w::PinnedStatus::invalid_path);
    CHECK(w::PinnedFile::open_verified(abc.path.parent_path()/"missing.bin", 3, abc.hash).status == w::PinnedStatus::io_error);
    CHECK(w::PinnedFile::open_verified(abc.path, 4, abc.hash).status == w::PinnedStatus::length_mismatch);
    auto wrong = abc.hash; wrong[0] ^= 1;
    const auto mismatch = w::PinnedFile::open_verified(abc.path, 3, wrong);
    CHECK(mismatch.status == w::PinnedStatus::hash_mismatch && !mismatch.file && mismatch.observed_sha256 == abc.hash);
    const auto opened = w::PinnedFile::open_verified(abc.path, 3, abc.hash);
    CHECK(opened.status == w::PinnedStatus::ok && opened.file->size() == 3);
    CHECK(opened.file->identity().length == 3 && opened.file->identity().sha256 == abc.hash);
    CHECK(!opened.file->identity().final_path.empty());
    std::array<char, 3> bytes{};
    CHECK(opened.file->read(0, bytes.size(), bytes.data()) == 3 && std::string(bytes.data(), 3) == "abc");
    CHECK(opened.file->read(3, 0, nullptr) == 0);
    bool rejected = false;
    try { (void)opened.file->read(2, 3, bytes.data()); } catch (const std::out_of_range&) { rejected = true; }
    CHECK(rejected);
    const auto zero = w::PinnedFile::open_verified(empty.path, 0, empty.hash);
    CHECK(zero.status == w::PinnedStatus::ok && zero.file->read(0, 0, nullptr) == 0);
}
void retained_lifetime_and_write_denial(const Fixture& abc) {
    auto opened = w::PinnedFile::open_verified(abc.path, abc.bytes, abc.hash);
    CHECK(opened.status == w::PinnedStatus::ok);
    std::weak_ptr<const w::PinnedFile> weak = opened.file;
    auto source = std::make_shared<reo::assets::Source>(abc.path.parent_path()/"diagnostic-label-only.bin", opened.file);
    const auto view_result = r::VirtualFileView::create(reo::assets::original(source, 0, 3));
    auto view = view_result.view;
    CHECK(view_result.status == r::Status::ok);
    r::ResourceSession session;
    const auto handle = session.open(view);
    CHECK(handle.status == r::Status::ok);
    opened.file.reset(); source.reset(); view.reset();
    // view_result retains the view until its scope ends; native handle lifetime
    // is separately checked with a nested owner below.
    CHECK(!weak.expired());
    const auto alias = abc.path.parent_path()/"hardlink.bin";
    HANDLE writer = CreateFileW(alias.c_str(), FILE_WRITE_DATA,
                                FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
                                nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    CHECK(writer == INVALID_HANDLE_VALUE && GetLastError() == ERROR_SHARING_VIOLATION);
    CHECK(!MoveFileExW(abc.path.c_str(), (abc.path.parent_path()/"renamed.bin").c_str(), 0));
    std::array<std::byte, 3> result{};
    CHECK(session.read_exact(handle.handle, 0, result) == r::ReadResult{r::Status::ok, 3});
    CHECK(result[0] == std::byte{'a'} && result[2] == std::byte{'c'});
    CHECK(session.close(handle.handle) == r::Status::ok);
}
void final_provider_release(const Fixture& abc) {
    std::weak_ptr<const w::PinnedFile> weak;
    r::ResourceSession session;
    r::Handle handle;
    {
        auto opened = w::PinnedFile::open_verified(abc.path, abc.bytes, abc.hash);
        CHECK(opened.status == w::PinnedStatus::ok);
        weak = opened.file;
        auto source = std::make_shared<reo::assets::Source>(abc.path.parent_path()/"not-a-file.bin", opened.file);
        auto view = r::VirtualFileView::create(reo::assets::original(source, 0, abc.bytes));
        CHECK(view.status == r::Status::ok);
        const auto result = session.open(view.view);
        CHECK(result.status == r::Status::ok);
        handle = result.handle;
    }
    CHECK(!weak.expired());
    CHECK(session.close(handle) == r::Status::ok && weak.expired());
    HANDLE writer = CreateFileW(abc.path.c_str(), FILE_WRITE_DATA, FILE_SHARE_READ,
                                nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    CHECK(writer != INVALID_HANDLE_VALUE);
    CloseHandle(writer);
}
void concurrent_positioned_reads(const Fixture& patterned) {
    const auto opened = w::PinnedFile::open_verified(patterned.path, patterned.bytes, patterned.hash);
    CHECK(opened.status == w::PinnedStatus::ok);
    std::array<std::future<bool>, 4> readers;
    for (unsigned worker = 0; worker < readers.size(); ++worker) {
        readers[worker] = std::async(std::launch::async, [&, worker] {
            std::array<std::uint8_t, 4096> data{};
            for (unsigned i = 0; i < 128; ++i) {
                const auto offset = (std::uint64_t(i) * 7919 + worker * 2137) % (patterned.bytes - data.size());
                if (opened.file->read(offset, data.size(), data.data()) != data.size()) return false;
                for (std::size_t j = 0; j < data.size(); ++j)
                    if (data[j] != std::uint8_t(((offset + j) * 37) ^ ((offset + j) >> 8))) return false;
            }
            return true;
        });
    }
    for (auto& reader : readers) CHECK(reader.get());
}
} // namespace

int main(int argc, char** argv) {
    try {
        CHECK(argc == 2);
        const auto root = std::filesystem::absolute(std::filesystem::path(reinterpret_cast<const char8_t*>(argv[1])));
        std::ifstream inputs(root/"hashes.txt");
        CHECK(bool(inputs));
        const auto abc = fixture(inputs, root), empty = fixture(inputs, root), patterned = fixture(inputs, root), large = fixture(inputs, root);
        const auto unicode = fixture(inputs, root);
        identity_and_refusal(abc, empty);
        retained_lifetime_and_write_denial(abc);
        final_provider_release(abc);
        concurrent_positioned_reads(patterned);
        const auto unicode_open = w::PinnedFile::open_verified(unicode.path, unicode.bytes, unicode.hash);
        CHECK(unicode_open.status == w::PinnedStatus::ok && unicode_open.file->size() == 3);
        // A >256 MiB source cannot require a whole-file C++ allocation.
        bounded_allocations.store(true);
        const auto large_open = w::PinnedFile::open_verified(large.path, large.bytes, large.hash);
        bounded_allocations.store(false);
        CHECK(large_open.status == w::PinnedStatus::ok && large_open.file->size() == large.bytes);
        std::cout << "Pinned Windows source: " << checks << " checks; SHA/read handle identity, lifetime, sharing, concurrent reads, >256MiB bounded hashing\n";
        return 0;
    } catch (const std::exception& error) {
        bounded_allocations.store(false);
        std::cerr << error.what() << '\n';
        return 1;
    }
}
