#include "game/native/resources/resource_session.hpp"
#include "game/native/resources/virtual_file_view.hpp"
#include "runtime/assets/overlay.h"

#include <array>
#include <atomic>
#include <fstream>
#include <functional>
#include <iostream>
#include <thread>

namespace a = reo::assets;
namespace r = reo::native::resources;
namespace fs = std::filesystem;

namespace {
std::atomic<unsigned> checks{0};
void check(bool value, const char* message) {
    ++checks;
    if (!value)
        throw std::runtime_error(message);
}
template <class F> void rejects(F&& operation, const char* message) {
    bool rejected = false;
    try {
        operation();
    } catch (const std::exception&) {
        rejected = true;
    }
    check(rejected, message);
}

struct MemorySource final : a::PositionedSource {
    enum class Failure { none, short_read, oversized_count, exception };
    const std::vector<uint8_t> bytes;
    mutable std::atomic<unsigned> reads{0};
    std::atomic<Failure> failure{Failure::none};
    std::function<void()> before_read, on_destroy;
    explicit MemorySource(std::vector<uint8_t> value) : bytes(std::move(value)) {}
    ~MemorySource() override {
        if (on_destroy)
            on_destroy();
    }
    uint64_t size() const noexcept override {
        return bytes.size();
    }
    size_t read(uint64_t offset, size_t count, void* out) const override {
        ++reads;
        if (before_read)
            before_read();
        a::require(offset <= bytes.size() && count <= bytes.size() - offset, "Fake source range");
        const auto mode = failure.load();
        const auto copied = mode == Failure::short_read ? count / 2 : count;
        if (copied)
            std::memcpy(out, bytes.data() + offset, copied);
        switch (mode) {
            case Failure::short_read:
                return copied;
            case Failure::oversized_count:
                return count + 1;
            case Failure::exception:
                throw std::runtime_error("Synthetic provider error");
            case Failure::none:
                return count;
        }
        return 0;
    }
};

void write(const fs::path& path, const std::vector<uint8_t>& bytes) {
    std::ofstream stream(path, std::ios::binary);
    stream.write(reinterpret_cast<const char*>(bytes.data()), bytes.size());
    check(bool(stream), "Synthetic fixture write");
}
std::vector<uint8_t> read(const fs::path& path) {
    std::ifstream stream(path, std::ios::binary | std::ios::ate);
    check(bool(stream), "Identity/fixture input open");
    const auto length = stream.tellg();
    check(length >= 0 && length <= 256 * 1024 * 1024, "Bounded identity/fixture input");
    std::vector<uint8_t> bytes(static_cast<size_t>(length));
    stream.seekg(0);
    stream.read(reinterpret_cast<char*>(bytes.data()), bytes.size());
    check(bool(stream), "Identity/fixture input read");
    return bytes;
}

void source_and_snapshot(const fs::path& root) {
    rejects([&] { a::Source invalid(root / "absent", {}); }, "Null provider rejected");
    const auto label = root / "replaced-label.bin";
    write(label, {1, 2, 3, 4, 5, 6, 7, 8, 9});
    auto backend = std::make_shared<MemorySource>(std::vector<uint8_t>{1, 2, 3, 4, 5, 6, 7, 8, 9});
    auto source = std::make_shared<a::Source>(label, backend);
    check(source->size == 9 && !source->stream.is_open(), "Adoption does not open pathname");
    std::weak_ptr<a::Source> weak_source = source;
    backend->before_read = [weak_source] {
        if (const auto current = weak_source.lock()) {
            check(current->lock.try_lock(), "Backend called outside legacy stream mutex");
            current->lock.unlock();
        }
    };
    source->transient = true;
    std::array<uint8_t, 2> direct{};
    source->read(1, direct.size(), direct.data());
    check(direct == std::array<uint8_t, 2>{2, 3}, "Adopted direct bytes");
    auto memory = std::make_shared<std::vector<uint8_t>>(std::initializer_list<uint8_t>{21, 22});
    a::VirtualFile file{12, {{2, 6, 1, source, {}}, {9, 2, 0, {}, memory}}};
    auto snapshot = r::VirtualFileView::create(file);
    check(snapshot.status == r::Status::ok, "Adopted snapshot admitted");
    r::ResourceSession session;
    const auto opened = session.open(std::move(snapshot.view));
    check(opened.status == r::Status::ok, "Snapshot session opened");
    std::atomic<bool> released{false};
    backend->on_destroy = [&] {
        // Shutdown releases providers outside the session's registry mutex.
        check(session.size(opened.handle).status == r::Status::session_closed,
              "Final provider destruction outside registry mutex");
        released = true;
    };
    std::weak_ptr<MemorySource> weak_backend = backend;
    source->path = root / "nonexistent-label";
    source->size = 0;
    source->transient = false;
    memory->assign(2, 99);
    file.segments.clear();
    file.size = 1;
    source.reset();
    memory.reset();
    backend.reset();
    fs::remove(label);
    write(label, std::vector<uint8_t>(9, 0xEE));
    check(!weak_backend.expired(), "View retains provider after caller release/path replacement");
    const std::array<std::byte, 12> expected{
        std::byte{0}, std::byte{0}, std::byte{2}, std::byte{3},  std::byte{4},  std::byte{5},
        std::byte{6}, std::byte{7}, std::byte{0}, std::byte{21}, std::byte{22}, std::byte{0}};
    std::atomic<bool> failed{false};
    std::array<std::thread, 6> readers;
    for (auto& reader : readers)
        reader = std::thread([&] {
            for (unsigned i = 0; i < 150; ++i) {
                std::array<std::byte, 12> actual{};
                if (session.read_exact(opened.handle, 0, actual) !=
                        r::ReadResult{r::Status::ok, 12} ||
                    actual != expected)
                    failed = true;
            }
        });
    for (auto& reader : readers)
        reader.join();
    check(!failed && session.size(opened.handle).bytes == 12,
          "Repeated/concurrent reads retain metadata, provider bytes, memory bytes and holes");
    session.shutdown_and_drain();
    check(released && weak_backend.expired(), "Final session release drops adopted backend");
}

void provider_failures(const fs::path& root) {
    auto backend = std::make_shared<MemorySource>(std::vector<uint8_t>{7, 8, 9, 10});
    auto source = std::make_shared<a::Source>(root / "never-created.bin", backend);
    auto snapshot = r::VirtualFileView::create(a::original(source, 0, source->size));
    check(snapshot.status == r::Status::ok, "Failure fixture view admitted");
    r::ResourceSession session;
    const auto opened = session.open(snapshot.view);
    for (const auto mode :
         {MemorySource::Failure::short_read, MemorySource::Failure::oversized_count,
          MemorySource::Failure::exception}) {
        backend->failure = mode;
        std::array<std::byte, 4> output;
        output.fill(std::byte{0xA5});
        rejects([&] { source->read(0, output.size(), output.data()); },
                "Bad direct provider completion rejected");
        const auto previous_output = output;
        const auto result = session.read_exact(opened.handle, 0, output);
        check(result == r::ReadResult{r::Status::source_failure, 0} && output == previous_output,
              "Session failure leaves its entry output unchanged after direct partial write");
        output.fill(std::byte{0xCC});
        check(session.read_exact(opened.handle, 0, output) ==
                      r::ReadResult{r::Status::source_failure, 0} &&
                  std::all_of(output.begin(), output.end(),
                              [](auto value) { return value == std::byte{0xCC}; }),
              "Session provider failure is transactional");
    }
    backend->failure = MemorySource::Failure::none;
    std::array<std::byte, 4> output{};
    check(session.read_exact(opened.handle, 0, output) == r::ReadResult{r::Status::ok, 4} &&
              output[0] == std::byte{7} && output[3] == std::byte{10},
          "Provider recovers without stream reopen");
    const auto previous = backend->reads.load();
    rejects([&] { source->read(4, 1, output.data()); }, "Range rejected before provider call");
    check(backend->reads == previous, "Rejected range bypasses provider");
}

void append32(std::vector<uint8_t>& bytes, uint32_t value) {
    for (unsigned shift = 0; shift < 32; shift += 8)
        bytes.push_back(uint8_t(value >> shift));
}
void append64(std::vector<uint8_t>& bytes, uint64_t value) {
    append32(bytes, uint32_t(value));
    append32(bytes, uint32_t(value >> 32));
}
void text(std::vector<uint8_t>& bytes, const std::string& value) {
    append32(bytes, static_cast<uint32_t>(value.size()));
    bytes.insert(bytes.end(), value.begin(), value.end());
}
a::Digest hash(const std::vector<uint8_t>& bytes) {
    return reo_native_image_identity::sha256(bytes.data(), static_cast<uint32_t>(bytes.size()));
}
void appendHash(std::vector<uint8_t>& bytes, const a::Digest& value) {
    bytes.insert(bytes.end(), value.begin(), value.end());
}
std::vector<uint8_t> archive() {
    // Synthetic AFS writer only. All archive parsing remains production table/build.
    std::vector<uint8_t> bytes(6240);
    std::memcpy(bytes.data(), "AFS\0", 4);
    a::put32(bytes.data() + 4, 2);
    a::put32(bytes.data() + 8, 2048);
    a::put32(bytes.data() + 12, 9);
    a::put32(bytes.data() + 16, 4096);
    a::put32(bytes.data() + 20, 11);
    a::put32(bytes.data() + 24, 6144);
    a::put32(bytes.data() + 28, 96);
    std::memcpy(bytes.data() + 2048, "original!", 9);
    std::memcpy(bytes.data() + 4096, "unchanged!!", 11);
    std::memcpy(bytes.data() + 6144, "one.bin", 7);
    a::put32(bytes.data() + 6144 + 44, 9);
    std::memcpy(bytes.data() + 6192, "two.bin", 7);
    a::put32(bytes.data() + 6192 + 44, 11);
    return bytes;
}

void overlay_injection(const fs::path& root) {
    const auto replacement_path = root / fs::path(std::u8string(u8"replacement-\u00e9-\u6728.bin"));
    const auto base_path = root / "NETBIO00.DAT";
    const auto elf_path = root / "SLUS_207.65";
    auto base = archive();
    std::vector<uint8_t> replacement(8193);
    for (size_t i = 0; i < replacement.size(); ++i)
        replacement[i] = uint8_t(i * 31);
    write(base_path, base);
    write(replacement_path, replacement);
    const auto elf = read(elf_path); // Owned ELF identity fixture; never executed.
    std::vector<uint8_t> plan{'R', 'E', 'O', 'P', 'A', 'K', '1', 0};
    append32(plan, 1);
    appendHash(plan, hash(elf));
    append32(plan, 1);
    text(plan, "NETBIO00.DAT/0");
    const auto replacement_u8 = replacement_path.u8string();
    text(plan,
         std::string(reinterpret_cast<const char*>(replacement_u8.data()), replacement_u8.size()));
    append64(plan, replacement.size());
    appendHash(plan, hash(std::vector<uint8_t>(base.begin() + 2048, base.begin() + 2057)));
    appendHash(plan, hash(replacement));
    const auto plan_path = root / "plan.bin";
    write(plan_path, plan);
    auto legacy = std::make_unique<a::Overlay>(root, plan_path);
    const auto* reference = legacy->find("cdrom0:\\netbio00.dat;1");
    check(reference && reference->lba == 0x20000000u, "Legacy synthetic overlay mounted");
    std::vector<uint8_t> expected(static_cast<size_t>(reference->file.size));
    reference->file.read(0, expected.size(), expected.data());
    const auto reference_lba = reference->lba;
    std::map<fs::path, std::shared_ptr<MemorySource>> providers;
    providers.emplace(elf_path, std::make_shared<MemorySource>(elf));
    providers.emplace(base_path, std::make_shared<MemorySource>(base));
    providers.emplace(replacement_path, std::make_shared<MemorySource>(replacement));
    std::vector<fs::path> resolved;
    const auto resolver = [&](const fs::path& path) {
        resolved.push_back(path);
        return std::make_shared<a::Source>(path, providers.at(path));
    };
    auto bad_plan = plan;
    bad_plan.back() ^= 1;
    write(root / "bad-plan.bin", bad_plan);
    rejects([&] { a::Overlay bad(root, root / "bad-plan.bin"); }, "Legacy wrong hash rejected");
    rejects([&] { a::Overlay bad(root, std::span<const uint8_t>(bad_plan), resolver); },
            "Injected wrong hash rejected");
    rejects([&] { a::Overlay bad(root, std::span<const uint8_t>(plan), a::Overlay::SourceResolver{}); },
            "Empty resolver rejected");
    rejects([&] { a::Overlay bad(root, std::span<const uint8_t>(plan), a::Overlay::VerifiedSourceResolver{}); },
            "Empty verified resolver rejected");
    rejects(
        [&] {
            a::Overlay bad(root, std::span<const uint8_t>(plan),
                           [](const fs::path&) { return std::shared_ptr<a::Source>{}; });
        },
        "Null resolver source rejected");
    std::vector<a::Overlay::SourceExpectation> expectations;
    {
        a::Overlay verified(root, std::span<const uint8_t>(plan),
            [&](const fs::path& path, const a::Overlay::SourceExpectation& expected_source) {
                expectations.push_back(expected_source);
                return resolver(path);
            });
        check(expectations.size() == 3 &&
                  !expectations[0].length && expectations[0].sha256 == hash(elf) &&
                  !expectations[1].length && !expectations[1].sha256 &&
                  expectations[2].length == replacement.size() &&
                  expectations[2].sha256 == hash(replacement),
              "Verified resolver receives parser ELF/base/replacement expectations");
        const auto* archive = verified.find("NETBIO00.DAT");
        std::vector<uint8_t> actual(expected.size());
        check(archive && archive->file.size == expected.size(), "Verified resolver keeps layout");
        archive->file.read(0, actual.size(), actual.data());
        check(actual == expected, "Verified resolver keeps archive bytes");
    }
    resolved.clear();
    auto retained = std::make_unique<a::Overlay>(
        root, std::span<const uint8_t>(plan), [&](const fs::path& path) {
            if (resolved.empty()) {
                std::fill(plan.begin(), plan.end(), 0);
                plan.resize(1); // Remaining fields would be invalid if borrowed.
            }
            return resolver(path);
        });
    check(resolved == std::vector<fs::path>{elf_path, base_path, replacement_path} &&
              plan.size() == 1,
          "Copied plan and injected ELF/base/replacement resolver used");
    const auto* mounted = retained->find("NETBIO00.DAT");
    check(mounted && mounted->lba == reference_lba && mounted->file.size == expected.size(),
          "Injected overlay retains legacy layout and LBA");
    for (uint32_t sector = 0; sector < (expected.size() + 2047) / 2048; ++sector) {
        std::array<uint8_t, 2048> left{}, right{};
        check(legacy->sector(reference_lba + sector, 1, left.data()) &&
                  retained->sector(reference_lba + sector, 1, right.data()) && left == right,
              "Injected/legacy sector bytes and EOF padding match");
    }
    auto snapshot = r::VirtualFileView::create(mounted->file);
    check(snapshot.status == r::Status::ok, "Injected overlay snapshots with retained backends");
    legacy.reset();
    retained.reset();
    providers.clear();
    fs::remove(base_path);
    fs::remove(replacement_path);
    fs::remove(plan_path);
    fs::remove(elf_path);
    write(base_path, std::vector<uint8_t>(base.size(), 0xEE));
    write(replacement_path, std::vector<uint8_t>(replacement.size(), 0xEE));
    r::ResourceSession session;
    const auto opened = session.open(std::move(snapshot.view));
    check(opened.status == r::Status::ok, "Retained overlay session opened");
    for (size_t at = 0; at < expected.size(); at += 777) {
        const auto count = std::min<size_t>(777, expected.size() - at);
        std::vector<std::byte> actual(count);
        check(session.read_exact(opened.handle, at, actual) ==
                      r::ReadResult{r::Status::ok, count} &&
                  std::memcmp(actual.data(), expected.data() + at, count) == 0,
              "Retained overlay bytes survive caller/path removal and replacement");
    }
    session.shutdown_and_drain();
}
} // namespace

int main(int argc, char** argv) {
    try {
        check(argc == 3,
              "Pass a fresh synthetic directory seeded only with the owned ELF identity fixture");
        const auto root = fs::absolute(fs::path(reinterpret_cast<const char8_t*>(argv[1])));
        const std::string token(argv[2]);
        check(token.size() == 32 &&
                  token.find_first_not_of("0123456789abcdef") == std::string::npos &&
                  root.filename() == "synthetic-" + token &&
                  root.parent_path().filename() == "retained-source-checks" &&
                  root.parent_path().parent_path().filename() == "build-native-sjuni",
              "Only the driver's uniquely named ignored fixture is admitted");
        check(fs::is_directory(root), "Synthetic directory exists");
        const auto marker = read(root / ".retained-source-fixture");
        check(std::string(marker.begin(), marker.end()) == token, "Private fixture marker matches");
        unsigned initial_files = 0;
        for (const auto& entry : fs::directory_iterator(root)) {
            check(entry.is_regular_file() &&
                      (entry.path().filename() == "SLUS_207.65" ||
                       entry.path().filename() == ".retained-source-fixture"),
                  "Fixture initially contains only its marker and copied ELF");
            ++initial_files;
        }
        check(initial_files == 2, "Fresh fixture file count");
        source_and_snapshot(root);
        provider_failures(root);
        overlay_injection(root);
        std::cout << "Retained source plumbing: " << checks.load() << " checks passed\n";
        return 0;
    } catch (const std::exception& error) {
        std::cerr << "FAIL: " << error.what() << '\n';
        return 1;
    }
}
