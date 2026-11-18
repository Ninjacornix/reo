#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0A00
#endif
#include "mounted_resources.hpp"
#include "import_manifest.hpp"
#include "facade_layout.hpp"
#include "../resources/resource_session.hpp"
#include "runtime/cdvd/cdvd.h"
#include "runtime/assets/overlay.h"
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <winioctl.h>

#include <atomic>
#include <fstream>
#include <iostream>
#include <map>
#include <thread>

namespace w = reo::native::resources::win32;
namespace r = reo::native::resources;
namespace fs = std::filesystem;
namespace {
unsigned checks = 0;
void check(bool condition, const char* message) {
    ++checks;
    if (!condition)
        throw std::runtime_error(message);
}
std::vector<std::uint8_t> read_file(const fs::path& path) {
    std::ifstream file(path, std::ios::binary | std::ios::ate);
    check(bool(file), "Fixture read open");
    const auto bytes = file.tellg();
    check(bytes >= 0 && bytes < 256 * 1024 * 1024, "Fixture size bound");
    std::vector<std::uint8_t> result(static_cast<std::size_t>(bytes));
    file.seekg(0);
    file.read(reinterpret_cast<char*>(result.data()), result.size());
    check(bool(file), "Fixture exact read");
    return result;
}
std::string key(std::string name) {
    for (auto& c : name) {
        if (c == '/')
            c = '\\';
        if (c >= 'a' && c <= 'z')
            c = static_cast<char>(c - 'a' + 'A');
    }
    return name;
}
void setup_reference(const std::optional<fs::path>& plan) {
    _putenv_s("REO_GAME_PAK", "1");
    _putenv_s("REO_ISO", "");
    _wputenv_s(L"REO_ASSET_OVERLAY", plan ? plan->c_str() : L"");
    _putenv_s("REO_COOP_HOST", "");
}
HANDLE write_handle(const fs::path& name) {
    return CreateFileW(name.c_str(), GENERIC_WRITE,
                       FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, nullptr,
                       OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
}
void junction(const fs::path& link, const fs::path& target) {
    // A private synthetic NTFS junction, created without launching another shell
    // or following it during cleanup. Both paths are inside this fresh fixture.
    check(fs::create_directory(link), "Create private junction directory");
    HANDLE handle = CreateFileW(link.c_str(), GENERIC_WRITE, 0, nullptr, OPEN_EXISTING,
                                FILE_FLAG_OPEN_REPARSE_POINT | FILE_FLAG_BACKUP_SEMANTICS, nullptr);
    check(handle != INVALID_HANDLE_VALUE, "Open private junction");
    const auto substitute = L"\\??\\" + target.wstring();
    const auto print = target.wstring();
    struct Header {
        DWORD tag;
        WORD length, reserved, sub_offset, sub_length, print_offset, print_length;
    };
    static_assert(sizeof(Header) == 16);
    const auto names_bytes = (substitute.size() + 1 + print.size() + 1) * sizeof(wchar_t);
    std::vector<std::uint8_t> buffer(sizeof(Header) + names_bytes);
    const Header header{IO_REPARSE_TAG_MOUNT_POINT,
                        static_cast<WORD>(8 + names_bytes),
                        0,
                        0,
                        static_cast<WORD>(substitute.size() * sizeof(wchar_t)),
                        static_cast<WORD>((substitute.size() + 1) * sizeof(wchar_t)),
                        static_cast<WORD>(print.size() * sizeof(wchar_t))};
    std::memcpy(buffer.data(), &header, sizeof(header));
    std::memcpy(buffer.data() + sizeof(header), substitute.c_str(),
                (substitute.size() + 1) * sizeof(wchar_t));
    std::memcpy(buffer.data() + sizeof(header) + (substitute.size() + 1) * sizeof(wchar_t),
                print.c_str(), (print.size() + 1) * sizeof(wchar_t));
    DWORD actual = 0;
    const bool ok =
        DeviceIoControl(handle, FSCTL_SET_REPARSE_POINT, buffer.data(),
                        static_cast<DWORD>(buffer.size()), nullptr, 0, &actual, nullptr) != FALSE;
    CloseHandle(handle);
    check(ok, "Set private NTFS junction");
}

void failure_case(const fs::path& root, const std::string& scenario) {
    const auto data = root / "data";
    std::optional<fs::path> plan;
    if (scenario.starts_with("overlay-"))
        plan = root / "asset-overlay.bin";
    bool linked = false;
    if (scenario == "junction") {
        fs::create_directories(root / "outside");
        junction(data / "LINK", root / "outside");
        linked = true;
    }
    if (scenario == "replacement-junction") {
        const auto cache = root / "cache";
        fs::rename(cache, root / "cache-original");
        junction(cache, root / "cache-original");
        linked = true;
        plan = root / "asset-overlay.bin";
    }
    const auto result = w::MountedResources::open_file1_windows(data, plan);
    check(result.status != w::MountStatus::ok && !result.mount,
          "Invalid mount exposes no partial owner");
    if (scenario == "junction" || scenario == "replacement-junction" || scenario == "unicode-name")
        check(result.status == w::MountStatus::unsupported_layout,
              "Unsupported path policy reports explicit status");
    if (scenario == "missing" || scenario == "unlisted" || scenario == "renamed")
        check(result.status == w::MountStatus::file_set_mismatch,
              "Actual file set mismatch reported");
    if (scenario == "manifest-elf" || scenario == "manifest-duplicate-case" ||
        scenario == "manifest-traversal" || scenario == "manifest-malformed")
        check(result.status == w::MountStatus::manifest_error,
              "Manifest policy reports manifest error");
    if (scenario == "overlay-oversize")
        check(result.status == w::MountStatus::overlay_error,
              "Existing replacement hash bound enforced before pinning");
    if (linked) {
        const auto link = scenario == "junction" ? data / "LINK" : root / "cache";
        check(RemoveDirectoryW(link.c_str()) != FALSE, "Remove only private junction itself");
    }
    // Every partially pinned source/blob/directory must have been released.
    HANDLE file = write_handle(data / "SLUS_207.65");
    check(file != INVALID_HANDLE_VALUE, "Failure releases partially admitted pinned files");
    CloseHandle(file);
    std::cout << "Rejected " << scenario << ": " << result.detail << '\n';
}

void accepted_case(const fs::path& root, bool with_overlay) {
    const auto data = root / "data";
    const std::optional<fs::path> plan =
        with_overlay ? std::optional<fs::path>{root / "asset-overlay.bin"} : std::nullopt;
    const auto raw_manifest = read_file(root / "import.json");
    const auto manifest = w::parse_import_manifest(raw_manifest);
    auto result = w::MountedResources::open_file1_windows(data, plan);
    if (result.status != w::MountStatus::ok)
        throw std::runtime_error("Admission failed: " + result.detail);
    auto mount = std::move(result.mount);
    check(mount->identity().import_version == manifest.version, "Import V1/V2 preserved");
    check(mount->identity().manifest_sha256 ==
              reo_native_image_identity::sha256(raw_manifest.data(),
                                                static_cast<std::uint32_t>(raw_manifest.size())),
          "Raw retained manifest identity includes exact bytes");
    check(mount->identity().overlay_plan_sha256.has_value() == with_overlay,
          "Optional plan identity recorded");
    check(mount->identity().route_sha256 != w::Digest{}, "Actual mount route identity computed");
    if (fs::exists(root / "outside-alpha.bin")) {
        HANDLE alias = write_handle(root / "outside-alpha.bin");
        check(alias == INVALID_HANDLE_VALUE,
              "Ordinary writes through an external hardlink alias are refused");
    }
    check(w::MountedResources::open_file1_windows(fs::path("relative/data")).status ==
              w::MountStatus::invalid_path,
          "Relative roots cannot silently adopt process CWD identity");
    check(w::MountedResources::open_file1_windows(fs::path(L"\\\\server\\share\\data")).status ==
              w::MountStatus::unsupported_layout,
          "UNC roots are explicitly unsupported before I/O");
    const auto second = w::MountedResources::open_file1_windows(data, plan);
    check(second.status == w::MountStatus::ok &&
              second.mount->identity().route_sha256 == mount->identity().route_sha256,
          "Same retained inputs produce the same route identity");
    // Keep repeated-admission ownership scoped so later last-view release checks
    // are not accidentally held open by the comparison mount.
    std::map<std::string, w::ImportedFile> sorted;
    for (const auto& row : manifest.files)
        sorted.emplace(key(row.name), row);
    std::uint64_t next = 0x01000000;
    std::size_t base_count = 0;
    for (const auto& route : mount->routes()) {
        if (route.overlay)
            continue;
        const auto expected = std::next(sorted.begin(), static_cast<std::ptrdiff_t>(base_count));
        check(route.key == expected->first && route.lba == next &&
                  route.bytes == expected->second.length,
              "PAK names sorted independently of manifest order and assigned exact existing LBAs");
        check(route.sector_capacity_bytes == ((route.bytes + 2047) / 2048 + 0x4000) * 2048,
              "Exact bounded PAK read-ahead extent");
        next += (route.bytes + 2047) / 2048 + 0x4000;
        ++base_count;
    }
    check(base_count == manifest.files.size(), "Every admitted import file has one original route");
    setup_reference(plan);
    auto reference = std::make_unique<reo::CDVD>(data);
    check(reference->is_game_pak() && reference->pak_routes().size() == base_count,
          "Actual facade exposes its frozen PAK mode and original route count");
    check(w::matches_plain_pak_layout(*reference, *mount, with_overlay) == !with_overlay,
          "First migration admits the actual plain PAK map and rejects overlays");
    check(!w::matches_plain_pak_layout(*reference, *mount, true),
          "Active mutable overlay cannot be admitted by a plain-Pak caller");
    if (!with_overlay) {
        const auto foreign = root / "foreign-data";
        fs::create_directory(foreign);
        for (const auto& entry : fs::recursive_directory_iterator(data)) {
            const auto target = foreign / entry.path().lexically_relative(data);
            if (entry.is_directory()) fs::create_directory(target);
            else fs::copy_file(entry.path(), target);
        }
        reo::CDVD different_objects(foreign);
        check(!w::matches_plain_pak_layout(different_objects, *mount, false),
              "Equal names/lengths/LBAs from different filesystem objects are refused");
        _putenv_s("REO_GAME_PAK", "0");
        {
            reo::CDVD unavailable_image(data);
            check(!unavailable_image.is_game_pak() &&
                      !w::matches_plain_pak_layout(unavailable_image, *mount, false),
                  "A saved PAK intention cannot admit an actual image-mode facade");
        }
        setup_reference({});
    }
    r::ResourceSession reads;
    for (const auto& [name, row] : sorted) {
        const auto route = mount->find_file(name);
        std::uint32_t lba = 0, bytes = 0;
        check(route && reference->search_file(name, lba, bytes) && route->lba == lba &&
                  route->bytes == bytes,
              "File lookup matches current facade including overlay precedence");
        (void)row;
    }
    check(!mount->find_file("alpha.bin"), "Lookup requires canonical facade key explicitly");
    for (const auto& route : mount->routes()) {
        const auto opened = reads.open(route.view);
        check(opened.status == r::Status::ok, "Route is a native ByteView");
        const auto rounded = (route.bytes + 2047) / 2048;
        const std::array<std::uint64_t, 6> offsets{0,
                                                   1,
                                                   rounded ? rounded - 1 : 0,
                                                   rounded,
                                                   route.sector_capacity_bytes / 2048 - 1,
                                                   route.sector_capacity_bytes / 2048};
        for (const auto at : offsets) {
            const auto resolved =
                mount->resolve_sectors(route.lba + static_cast<std::uint32_t>(at), 1);
            if (at * 2048 >= route.sector_capacity_bytes)
                continue; // May belong to next base route.
            check(resolved.status == w::RouteStatus::ok && resolved.view == route.view &&
                      resolved.offset == at * 2048 && resolved.total_bytes == 2048,
                  "Sector lookup retains exact route and offset");
            std::array<std::byte, 2048> actual{}, legacy{};
            if (resolved.prefix_bytes) {
                check(reads.read_exact(opened.handle, resolved.offset,
                                       std::span<std::byte>(actual).first(
                                           static_cast<std::size_t>(resolved.prefix_bytes))) ==
                          r::ReadResult{r::Status::ok,
                                        static_cast<std::size_t>(resolved.prefix_bytes)},
                      "Native exact prefix read");
            }
            check(reference->read_sectors(route.lba + static_cast<std::uint32_t>(at), 1,
                                          legacy.data()) &&
                      actual == legacy,
                  "Native prefix/zero-padding equals existing PAK/overlay sector reader");
        }
        const auto final =
            route.lba + static_cast<std::uint32_t>(route.sector_capacity_bytes / 2048 - 1);
        check(mount->resolve_sectors(final, 2).status == w::RouteStatus::invalid_range,
              "Cross-route read is rejected without I/O");
        check(reads.close(opened.handle) == r::Status::ok, "Route resource handle closed");
    }
    check(mount->resolve_sectors(0, 1).status == w::RouteStatus::not_found,
          "Unknown LBA has no invented route");
    check(mount->resolve_sectors(0x01000000, 0).status == w::RouteStatus::invalid_range &&
              mount->resolve_sectors(0x01000000, 0x4001).status == w::RouteStatus::invalid_range,
          "Original sector count bounds enforced");
    // Concurrent shared pinned reads; compare known fixture bytes, not another
    // native resource implementation.
    const auto alpha = mount->find_file("ALPHA.BIN");
    const auto expected = read_file(data / "alpha.bin");
    const auto opened = reads.open(alpha->view);
    std::atomic<bool> failed{false};
    std::array<std::thread, 4> threads;
    for (auto& thread : threads)
        thread = std::thread([&] {
            for (unsigned i = 0; i < 100; ++i) {
                std::array<std::byte, 127> bytes{};
                const auto at = (i * 29) % (expected.size() - bytes.size() + 1);
                if (reads.read_exact(opened.handle, at, bytes) !=
                        r::ReadResult{r::Status::ok, bytes.size()} ||
                    std::memcmp(bytes.data(), expected.data() + at, bytes.size()) != 0)
                    failed = true;
            }
        });
    for (auto& thread : threads)
        thread.join();
    check(!failed, "Concurrent retained routes read exact fixture bytes");
    check(reads.close(opened.handle) == r::Status::ok, "Concurrent route handle closed");
    reads.shutdown_and_drain();
    reference.reset();
    reo::assets::active.reset();
    std::array<std::byte, 4> after_reset{};
    check(alpha->view->read(0, after_reset) == r::ReadResult{r::Status::ok, 4} &&
              std::memcmp(after_reset.data(), expected.data(), 4) == 0,
          "Native view survives mutable legacy active overlay reset");
    // The lifecycle release proof is performed separately below because second
    // intentionally remains a retained independent owner until this scope ends.
}

void retained_view_case(const fs::path& root) {
    auto result = w::MountedResources::open_file1_windows(root / "data");
    check(result.status == w::MountStatus::ok, "Retention fixture admitted");
    auto route = result.mount->find_file("ALPHA.BIN");
    check(bool(route), "Retention route found");
    const auto expected = read_file(root / "data/alpha.bin");
    const auto digest = result.mount->identity().route_sha256;
    {
        std::ofstream file(root / "data/NEW.BIN", std::ios::binary);
        file << "new namespace entry";
        check(bool(file), "Add only a private unlisted fixture file");
    }
    check(!result.mount->find_file("NEW.BIN") && result.mount->identity().route_sha256 == digest,
          "Admitted route table/identity stays frozen after namespace additions");
    setup_reference({});
    {
        reo::CDVD changed_namespace(root / "data");
        check(!w::matches_plain_pak_layout(changed_namespace, *result.mount, false),
              "Actual facade with an extra captured route is refused");
    }
    const auto new_namespace = w::MountedResources::open_file1_windows(root / "data");
    check(new_namespace.status == w::MountStatus::file_set_mismatch && !new_namespace.mount,
          "Fresh mount rejects that same unlisted file");
    check(fs::remove(root / "data/NEW.BIN"), "Remove only newly authored private fixture file");
    result.mount.reset();
    HANDLE denied = write_handle(root / "data/alpha.bin");
    check(denied == INVALID_HANDLE_VALUE,
          "View alone retains read-only sharing lock after mount release");
    const auto error = GetLastError();
    check(error == ERROR_SHARING_VIOLATION || error == ERROR_ACCESS_DENIED,
          "Retained source refuses ordinary mutation");
    r::ResourceSession session;
    const auto opened = session.open(route->view);
    std::vector<std::byte> actual(expected.size());
    check(session.read_exact(opened.handle, 0, actual) ==
                  r::ReadResult{r::Status::ok, expected.size()} &&
              std::memcmp(actual.data(), expected.data(), expected.size()) == 0,
          "Retained view survives mount/caller release");
    route.reset();
    session.shutdown_and_drain();
    HANDLE released = write_handle(root / "data/alpha.bin");
    check(released != INVALID_HANDLE_VALUE, "Last view/drain releases pinned file handle");
    CloseHandle(released);
    // Change only this private fixture, preserving size. Original user assets
    // are never passed to this test executable.
    {
        std::fstream file(root / "data/alpha.bin", std::ios::binary | std::ios::in | std::ios::out);
        file.put('X');
        check(bool(file), "Private content edit");
    }
    const auto mismatch = w::MountedResources::open_file1_windows(root / "data");
    check(mismatch.status == w::MountStatus::source_failure && !mismatch.mount,
          "Changed bytes cannot reuse admitted identity");
    check(digest != w::Digest{}, "Identity is a value independent of released owner");
}
} // namespace

int main(int argc, char** argv) {
    try {
        check(argc == 4, "Pass private fixture root, token, and scenario");
        const auto root = fs::absolute(fs::path(reinterpret_cast<const char8_t*>(argv[1])));
        const std::string token(argv[2]), scenario(argv[3]);
        check(token.size() == 32 &&
                  token.find_first_not_of("0123456789abcdef") == std::string::npos &&
                  root.parent_path().filename() == "synthetic-" + token &&
                  root.parent_path().parent_path().filename() == "mounted-resources-checks",
              "Only driver's ignored private fixture tree is admitted");
        const auto marker = read_file(root.parent_path() / ".mounted-resources-fixture");
        check(std::string(marker.begin(), marker.end()) == token, "Private fixture marker matches");
        if (scenario == "pak-v1" || scenario == "pak-v2" || scenario == "pak-case" ||
            scenario == "pak-hardlink" || scenario == "overlay" || scenario == "overlay-empty")
            accepted_case(root, scenario == "overlay" || scenario == "overlay-empty");
        else if (scenario == "retention")
            retained_view_case(root);
        else
            failure_case(root, scenario);
        std::cout << scenario << ": " << checks << " mounted resource checks passed\n";
        return 0;
    } catch (const std::exception& error) {
        std::cerr << "FAIL: " << error.what() << '\n';
        return 1;
    }
}
