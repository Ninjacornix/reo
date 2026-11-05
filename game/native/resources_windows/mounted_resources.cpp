#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0A00
#endif
#include "mounted_resources.hpp"
#include "import_manifest.hpp"
#include "../resources/virtual_file_view.hpp"
#include "runtime/assets/overlay.h"

#ifndef _WIN32
#error "MountedResources is a Windows resource adapter"
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>

#include <algorithm>
#include <cstring>
#include <map>
#include <stdexcept>
#include <utility>

namespace reo::native::resources::win32 {
namespace {
namespace fs = std::filesystem;
namespace a = reo::assets;
constexpr std::uint64_t sector_size = 2048;
constexpr std::size_t identity_limit = 32u * 1024u * 1024u;

struct Failure : std::runtime_error {
    MountStatus status;
    std::uint32_t error;
    Failure(MountStatus value, const std::string& reason, std::uint32_t system = 0)
        : std::runtime_error(reason), status(value), error(system) {}
};
void require(bool condition, MountStatus status, const char* message) {
    if (!condition)
        throw Failure(status, message);
}
[[noreturn]] void io_failure(const char* message) {
    throw Failure(MountStatus::source_failure, message, GetLastError());
}
struct Handle {
    HANDLE value{INVALID_HANDLE_VALUE};
    Handle() = default;
    explicit Handle(HANDLE handle) : value(handle) {}
    ~Handle() {
        if (value != INVALID_HANDLE_VALUE)
            CloseHandle(value);
    }
    Handle(const Handle&) = delete;
    Handle& operator=(const Handle&) = delete;
    Handle(Handle&& other) noexcept : value(std::exchange(other.value, INVALID_HANDLE_VALUE)) {}
    Handle& operator=(Handle&& other) noexcept {
        if (this != &other) {
            if (value != INVALID_HANDLE_VALUE)
                CloseHandle(value);
            value = std::exchange(other.value, INVALID_HANDLE_VALUE);
        }
        return *this;
    }
};
fs::path local_absolute(const fs::path& input) {
    const auto& spelling = input.native();
    if (spelling.size() >= 2 && (spelling[0] == L'\\' || spelling[0] == L'/') &&
        (spelling[1] == L'\\' || spelling[1] == L'/'))
        throw Failure(MountStatus::unsupported_layout, "UNC/device namespaces are unsupported");
    require(!input.empty() && input.is_absolute() && spelling.find(L'\0') == std::wstring::npos,
            MountStatus::invalid_path, "Mount paths must be absolute and nonempty");
    auto path = input.lexically_normal();
    while (path != path.root_path() && path.filename().empty())
        path = path.parent_path();
    const auto drive = path.root_name().wstring();
    require(drive.size() == 2 && drive[1] == L':' &&
                ((drive[0] >= L'A' && drive[0] <= L'Z') || (drive[0] >= L'a' && drive[0] <= L'z')),
            MountStatus::unsupported_layout,
            "Only local drive paths are admitted; UNC/device namespaces are unsupported");
    const auto type = GetDriveTypeW(path.root_path().c_str());
    require(type == DRIVE_FIXED || type == DRIVE_REMOVABLE, MountStatus::unsupported_layout,
            "Only local regular-file imports are admitted");
    require(path.native().size() <= 32760, MountStatus::invalid_path,
            "Mount path exceeds Windows bounds");
    return path;
}
std::wstring readable(const fs::path& path) {
    return L"\\\\?\\" + path.wstring();
}
FileIdentity identity(HANDLE handle, bool directory) {
    FILE_STANDARD_INFO standard{};
    FILE_ATTRIBUTE_TAG_INFO attributes{};
    FILE_ID_INFO id{};
    if (!GetFileInformationByHandleEx(handle, FileStandardInfo, &standard, sizeof(standard)) ||
        !GetFileInformationByHandleEx(handle, FileAttributeTagInfo, &attributes,
                                      sizeof(attributes)) ||
        !GetFileInformationByHandleEx(handle, FileIdInfo, &id, sizeof(id)))
        io_failure("Read retained file identity");
    require(GetFileType(handle) == FILE_TYPE_DISK && bool(standard.Directory) == directory &&
                standard.EndOfFile.QuadPart >= 0 &&
                !(attributes.FileAttributes & FILE_ATTRIBUTE_REPARSE_POINT),
            MountStatus::unsupported_layout,
            "Reparse points and nonregular mount entries are unsupported");
    const auto needed =
        GetFinalPathNameByHandleW(handle, nullptr, 0, FILE_NAME_NORMALIZED | VOLUME_NAME_DOS);
    if (!needed)
        io_failure("Resolve retained mount path");
    require(needed <= 32768, MountStatus::unsupported_layout,
            "Retained path exceeds Windows bounds");
    std::wstring final(needed + 1, L'\0');
    const auto copied =
        GetFinalPathNameByHandleW(handle, final.data(), static_cast<DWORD>(final.size()),
                                  FILE_NAME_NORMALIZED | VOLUME_NAME_DOS);
    if (!copied || copied >= final.size())
        io_failure("Resolve retained mount path");
    final.resize(copied);
    FileIdentity result;
    result.volume_serial = id.VolumeSerialNumber;
    result.length = static_cast<std::uint64_t>(standard.EndOfFile.QuadPart);
    std::copy(std::begin(id.FileId.Identifier), std::end(id.FileId.Identifier),
              result.file_id.begin());
    result.final_path = final;
    return result;
}
bool same_object(const FileIdentity& left, const FileIdentity& right) noexcept {
    return left.volume_serial == right.volume_serial && left.file_id == right.file_id &&
           left.length == right.length;
}
std::string utf8(const fs::path& path) {
    const auto value = path.generic_u8string();
    return {reinterpret_cast<const char*>(value.data()), value.size()};
}
std::string key_for(std::string name) {
    require(!name.empty(), MountStatus::unsupported_layout, "Empty facade key");
    for (auto& c : name) {
        require(static_cast<unsigned char>(c) >= 32 && static_cast<unsigned char>(c) < 127,
                MountStatus::unsupported_layout,
                "Non-ASCII imported names are outside the current PAK facade contract");
        if (c == '/')
            c = '\\';
        if (c >= 'a' && c <= 'z')
            c = static_cast<char>(c - 'a' + 'A');
    }
    return name;
}
bool path_equal(const fs::path& left, const fs::path& right) {
    const auto l = left.native(), r = right.native();
    return CompareStringOrdinal(l.data(), static_cast<int>(l.size()), r.data(),
                                static_cast<int>(r.size()), TRUE) == CSTR_EQUAL;
}
struct BytesIdentity {
    std::vector<std::uint8_t> bytes;
    void raw(std::span<const std::uint8_t> value) {
        require(value.size() <= identity_limit - bytes.size(), MountStatus::unsupported_layout,
                "Mount identity description exceeds 32 MiB");
        bytes.insert(bytes.end(), value.begin(), value.end());
    }
    void number(std::uint64_t value) {
        std::array<std::uint8_t, 8> encoded{};
        for (unsigned i = 0; i < 8; ++i)
            encoded[i] = static_cast<std::uint8_t>(value >> (8 * i));
        raw(encoded);
    }
    void text(std::string_view value) {
        number(value.size());
        raw({reinterpret_cast<const std::uint8_t*>(value.data()), value.size()});
    }
    void file(const FileIdentity& value) {
        number(value.volume_serial);
        raw(value.file_id);
        number(value.length);
        raw(value.sha256);
    }
    Digest finish() const {
        return reo_native_image_identity::sha256(bytes.data(),
                                                 static_cast<std::uint32_t>(bytes.size()));
    }
};
struct Blob {
    Handle handle;
    FileIdentity file;
    std::vector<std::uint8_t> bytes;
};
} // namespace

struct MountedResources::Impl {
    MountIdentity identity;
    std::vector<MountedRoute> routes;
    std::map<std::string, std::size_t, std::less<>> files;
    std::map<fs::path, Handle> directory_guards;
    std::vector<Blob> blobs;
    std::map<const a::PositionedSource*, FileIdentity> backend_identity;
    std::vector<std::shared_ptr<const PinnedFile>> pinned_files;
    struct Imported {
        ImportedFile row;
        fs::path path;
        std::shared_ptr<const PinnedFile> file;
    };
    std::map<std::string, Imported> imported;

    void guard_directory(const fs::path& path) {
        if (directory_guards.contains(path))
            return;
        require(directory_guards.size() < max_imported_files, MountStatus::unsupported_layout,
                "Too many retained source directories");
        Handle handle(CreateFileW(readable(path).c_str(), FILE_READ_ATTRIBUTES,
                                  FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, OPEN_EXISTING,
                                  FILE_FLAG_BACKUP_SEMANTICS | FILE_FLAG_OPEN_REPARSE_POINT,
                                  nullptr));
        if (handle.value == INVALID_HANDLE_VALUE)
            io_failure("Retain source directory");
        (void)::reo::native::resources::win32::identity(handle.value, true);
        directory_guards.emplace(path, std::move(handle));
    }
    void guard_parents(const fs::path& file) {
        const auto parent = file.parent_path();
        auto at = parent.root_path();
        guard_directory(at);
        for (const auto& part : parent.relative_path()) {
            at /= part;
            guard_directory(at);
        }
    }
    Handle regular_gate(const fs::path& path, bool reading = false) {
        guard_parents(path);
        Handle result(CreateFileW(readable(path).c_str(),
                                  reading ? GENERIC_READ : FILE_READ_ATTRIBUTES, FILE_SHARE_READ,
                                  nullptr, OPEN_EXISTING,
                                  FILE_FLAG_OPEN_REPARSE_POINT | FILE_FLAG_RANDOM_ACCESS, nullptr));
        if (result.value == INVALID_HANDLE_VALUE)
            io_failure("Open retained source gate");
        (void)::reo::native::resources::win32::identity(result.value, false);
        return result;
    }
    Blob read_blob(const fs::path& input, std::size_t limit) {
        const auto path = local_absolute(input);
        Blob result;
        result.handle = regular_gate(path, true);
        result.file = ::reo::native::resources::win32::identity(result.handle.value, false);
        require(result.file.length > 0 && result.file.length <= limit, MountStatus::manifest_error,
                "Manifest/plan is empty or exceeds its existing bound");
        result.bytes.resize(static_cast<std::size_t>(result.file.length));
        DWORD actual = 0;
        if (!ReadFile(result.handle.value, result.bytes.data(),
                      static_cast<DWORD>(result.bytes.size()), &actual, nullptr))
            io_failure("Read retained manifest/plan");
        require(actual == result.bytes.size(), MountStatus::source_failure,
                "Retained manifest/plan read was short");
        result.file.sha256 = reo_native_image_identity::sha256(result.bytes.data(), actual);
        return result;
    }
    std::map<std::string, fs::path> actual_files(const fs::path& root) {
        std::map<std::string, fs::path> actual;
        guard_directory(root);
        for (const auto& entry : fs::recursive_directory_iterator(root)) {
            const auto attributes = GetFileAttributesW(readable(entry.path()).c_str());
            if (attributes == INVALID_FILE_ATTRIBUTES)
                io_failure("Inspect imported tree");
            require(!(attributes & FILE_ATTRIBUTE_REPARSE_POINT), MountStatus::unsupported_layout,
                    "Imported tree contains a symlink/junction/reparse point");
            if (entry.is_directory()) {
                guard_directory(entry.path());
                continue;
            }
            require(entry.is_regular_file(), MountStatus::unsupported_layout,
                    "Imported tree contains a nonregular file");
            const auto key = key_for(utf8(entry.path().lexically_relative(root)));
            require(actual.emplace(key, entry.path()).second, MountStatus::file_set_mismatch,
                    "Imported tree contains a case-colliding facade key");
            require(actual.size() <= max_imported_files, MountStatus::unsupported_layout,
                    "Too many imported files");
        }
        return actual;
    }
    std::shared_ptr<const PinnedFile> pin(const fs::path& path, std::uint64_t length,
                                          const Digest& hash) {
        auto gate = regular_gate(path);
        const auto observed = ::reo::native::resources::win32::identity(gate.value, false);
        const auto pinned = PinnedFile::open_verified(path, length, hash);
        if (pinned.status != PinnedStatus::ok)
            throw Failure(pinned.status == PinnedStatus::no_memory ? MountStatus::no_memory
                                                                   : MountStatus::source_failure,
                          "Retained source failed length/hash/open verification: " + utf8(path),
                          pinned.system_error);
        require(same_object(observed, pinned.file->identity()), MountStatus::source_failure,
                "Retained source changed filesystem identity during admission");
        backend_identity.emplace(pinned.file.get(), pinned.file->identity());
        pinned_files.push_back(pinned.file);
        return pinned.file;
    }
    void add_route(std::string key, std::uint32_t lba, std::uint64_t capacity, bool overlay,
                   const a::VirtualFile& file) {
        auto frozen = VirtualFileView::create(file);
        require(frozen.status == Status::ok,
                frozen.status == Status::no_memory ? MountStatus::no_memory
                                                   : MountStatus::source_failure,
                "Could not freeze admitted virtual file");
        BytesIdentity layout;
        layout.text("reo mounted route segments v1");
        layout.number(file.size);
        layout.number(file.segments.size());
        for (const auto& segment : file.segments) {
            layout.number(segment.offset);
            layout.number(segment.size);
            layout.number(segment.sourceOffset);
            if (segment.source) {
                const auto found = backend_identity.find(segment.source->backend.get());
                require(found != backend_identity.end(), MountStatus::source_failure,
                        "Virtual route has an unretained source");
                layout.number(1);
                layout.file(found->second);
            } else {
                require(bool(segment.bytes), MountStatus::source_failure,
                        "Virtual route has no backing");
                layout.number(2);
                layout.number(segment.bytes->size());
                layout.raw(reo_native_image_identity::sha256(
                    segment.bytes->data(), static_cast<std::uint32_t>(segment.bytes->size())));
            }
        }
        files[key] = routes.size();
        routes.push_back({std::move(key), lba, file.size, capacity, overlay, layout.finish(),
                          std::move(frozen.view)});
    }
    void initialize(const fs::path& input, const std::optional<fs::path>& plan_path) {
        const auto root = local_absolute(input);
        require(root != root.root_path(), MountStatus::invalid_path,
                "Import data must be a directory below a volume root");
        guard_parents(root / "probe");
        auto manifest = read_blob(root.parent_path() / "import.json", max_manifest_bytes);
        ImportManifest parsed;
        try {
            parsed = parse_import_manifest(manifest.bytes);
        } catch (const ImportManifestError& error) {
            throw Failure(MountStatus::manifest_error, error.what());
        }
        identity.import_version = parsed.version;
        identity.manifest_sha256 = manifest.file.sha256;
        identity.sources.push_back({MountSourceKind::manifest, "import.json", manifest.file});
        blobs.push_back(std::move(manifest));
        auto actual = actual_files(root);
        require(actual.size() == parsed.files.size(), MountStatus::file_set_mismatch,
                "Actual imported regular-file set differs from the manifest");
        for (auto& row : parsed.files) {
            const auto key = key_for(row.name);
            const auto found = actual.find(key);
            require(found != actual.end(), MountStatus::file_set_mismatch,
                    "Manifest file is absent from imported tree");
            auto file = pin(found->second, row.length, row.sha256);
            identity.sources.push_back({MountSourceKind::imported, key, file->identity()});
            require(imported.emplace(key, Imported{std::move(row), found->second, std::move(file)})
                        .second,
                    MountStatus::file_set_mismatch, "Manifest keys collide in the facade");
        }
        // std::map order is exactly the facade's sorted uppercase/backslash
        // name order. Pinning never substitutes manifest row order for it.
        std::uint64_t next = 0x01000000;
        for (const auto& [key, source] : imported) {
            const auto bytes = source.file->size(), sectors = (bytes + 2047) / 2048;
            require(bytes < 0x100000000ull && next + sectors + 0x4000 < 0x10000000,
                    MountStatus::unsupported_layout,
                    "Imported PAK layout exceeds existing facade limits");
            auto wrapper = std::make_shared<a::Source>(source.path, source.file);
            add_route(key, static_cast<std::uint32_t>(next), (sectors + 0x4000) * sector_size,
                      false, a::original(wrapper, 0, bytes));
            next += sectors + 0x4000;
        }
        if (plan_path) {
            try {
                auto plan = read_blob(*plan_path, 16u * 1024u * 1024u);
                identity.overlay_plan_sha256 = plan.file.sha256;
                identity.sources.push_back(
                    {MountSourceKind::overlay_plan, "asset-overlay.bin", plan.file});
                a::Overlay overlay(
                    root, std::span<const std::uint8_t>(plan.bytes),
                    [&](const fs::path& requested, const a::Overlay::SourceExpectation& expected) {
                        const auto path = local_absolute(requested);
                        for (const auto& [key, item] : imported) {
                            (void)key;
                            if (!path_equal(path, item.path))
                                continue;
                            require(!expected.length || *expected.length == item.row.length,
                                    MountStatus::overlay_error,
                                    "Overlay source length contradicts imported identity");
                            require(!expected.sha256 || *expected.sha256 == item.row.sha256,
                                    MountStatus::overlay_error,
                                    "Overlay source hash contradicts imported identity");
                            return std::make_shared<a::Source>(path, item.file);
                        }
                        require(expected.length && expected.sha256, MountStatus::overlay_error,
                                "Overlay requested a source without admitted identity metadata");
                        require(*expected.length <= 256ull * 1024 * 1024,
                                MountStatus::overlay_error,
                                "Replacement exceeds the existing overlay hash input limit");
                        auto file = pin(path, *expected.length, *expected.sha256);
                        identity.sources.push_back(
                            {MountSourceKind::replacement, utf8(path), file->identity()});
                        return std::make_shared<a::Source>(path, std::move(file));
                    });
                for (const auto* name : {"NETBIO00.DAT", "NETBIO01.DAT", "NETBIO02.DAT"}) {
                    if (const auto* archive = overlay.find(name))
                        add_route(name, archive->lba,
                                  ((archive->file.size + 2047) / 2048) * sector_size, true,
                                  archive->file);
                }
                blobs.push_back(std::move(plan));
            } catch (const Failure&) {
                throw;
            } catch (const std::bad_alloc&) {
                throw;
            } catch (const std::exception& error) {
                throw Failure(MountStatus::overlay_error, error.what());
            }
        }
        const auto final_files = actual_files(root);
        require(actual == final_files, MountStatus::file_set_mismatch,
                "Imported namespace changed during admission");
        BytesIdentity description;
        description.text("reo retained imported PAK mount v1");
        description.number(identity.import_version);
        description.raw(identity.manifest_sha256);
        description.number(identity.overlay_plan_sha256.has_value());
        if (identity.overlay_plan_sha256)
            description.raw(*identity.overlay_plan_sha256);
        description.number(identity.sources.size());
        for (const auto& source : identity.sources) {
            description.number(static_cast<std::uint64_t>(source.kind));
            description.text(source.key);
            description.file(source.file);
        }
        description.number(routes.size());
        for (const auto& route : routes) {
            description.text(route.key);
            description.number(route.lba);
            description.number(route.bytes);
            description.number(route.sector_capacity_bytes);
            description.number(route.overlay);
            description.raw(route.layout_sha256);
        }
        identity.route_sha256 = description.finish();
    }
};

MountedResources::MountedResources(std::unique_ptr<Impl> impl) noexcept : impl_(std::move(impl)) {}
MountedResources::~MountedResources() = default;
const MountIdentity& MountedResources::identity() const noexcept {
    return impl_->identity;
}
std::span<const MountedRoute> MountedResources::routes() const noexcept {
    return impl_->routes;
}
std::optional<MountedRoute> MountedResources::find_file(std::string_view key) const {
    const auto found = impl_->files.find(key);
    if (found == impl_->files.end())
        return {};
    return impl_->routes[found->second];
}
SectorRoute MountedResources::resolve_sectors(std::uint32_t lba,
                                              std::uint32_t count) const noexcept {
    if (!count || count > 0x4000)
        return {RouteStatus::invalid_range, {}, {}, {}, {}, false};
    const auto at = std::upper_bound(
        impl_->routes.begin(), impl_->routes.end(), lba,
        [](std::uint32_t value, const MountedRoute& route) { return value < route.lba; });
    if (at == impl_->routes.begin())
        return {};
    const auto& route = *std::prev(at);
    const auto offset = std::uint64_t(lba - route.lba) * sector_size,
               total = std::uint64_t(count) * sector_size;
    if (offset >= route.sector_capacity_bytes)
        return {};
    if (total > route.sector_capacity_bytes - offset)
        return {RouteStatus::invalid_range, {}, {}, {}, {}, route.overlay};
    const auto prefix = offset < route.bytes ? std::min(total, route.bytes - offset) : 0;
    return {RouteStatus::ok, route.view, offset, prefix, total, route.overlay};
}
MountOpenResult MountedResources::open_file1_windows(const fs::path& root,
                                                     const std::optional<fs::path>& plan) noexcept {
    MountOpenResult result;
    try {
        auto impl = std::make_unique<Impl>();
        impl->initialize(root, plan);
        result.mount =
            std::shared_ptr<const MountedResources>(new MountedResources(std::move(impl)));
        result.status = MountStatus::ok;
    } catch (const std::bad_alloc&) {
        result.status = MountStatus::no_memory;
    } catch (const Failure& error) {
        result.status = error.status;
        result.system_error = error.error;
        try {
            result.detail = error.what();
        } catch (...) {
            result.status = MountStatus::no_memory;
        }
    } catch (const std::exception& error) {
        result.status = MountStatus::source_failure;
        try {
            result.detail = error.what();
        } catch (...) {
            result.status = MountStatus::no_memory;
        }
    } catch (...) {
        result.status = MountStatus::source_failure;
    }
    return result;
}
} // namespace reo::native::resources::win32
