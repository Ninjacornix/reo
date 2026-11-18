#include "mounted_reader.hpp"
#include "../resources/resource_session.hpp"

#include <limits>
#include <map>
#include <new>
#include <stdexcept>
#include <utility>

namespace reo::native::resources::win32 {
namespace {
SessionConfig configuration(std::size_t count, std::size_t max_read) {
    if (!count || count > std::numeric_limits<std::uint32_t>::max())
        throw std::length_error("Mounted reader route count exceeds native handle domain");
    SessionConfig config;
    config.max_read_bytes = max_read;
    config.max_handles = static_cast<std::uint32_t>(count);
    return config;
}
struct OpenFailure : std::runtime_error {
    Status status;
    explicit OpenFailure(Status value)
        : std::runtime_error("Could not open immutable mounted route"), status(value) {}
};
} // namespace

struct MountedReader::Impl {
    // Destruction/drain precedes releasing the complete mount identity and pins.
    std::shared_ptr<const MountedResources> mount;
    ResourceSession session;
    std::map<const ByteView*, Handle, std::less<>> handles;
    const std::size_t max_read_bytes;

    Impl(std::shared_ptr<const MountedResources> value, std::size_t maximum)
        : mount(std::move(value)), session(configuration(mount->routes().size(), maximum)),
          max_read_bytes(maximum) {}
    ~Impl() {
        for (const auto& [view, handle] : handles) {
            (void)view;
            (void)session.close(handle);
        }
        // Also releases a handle admitted just before an allocation failure in
        // handles.emplace. Providers are released outside the registry mutex.
        session.shutdown_and_drain();
    }
    void open_routes() {
        for (const auto& route : mount->routes()) {
            if (handles.contains(route.view.get()))
                continue;
            const auto opened = session.open(route.view);
            if (opened.status != Status::ok)
                throw OpenFailure(opened.status);
            handles.emplace(route.view.get(), opened.handle);
        }
    }
};

MountedReader::MountedReader(std::unique_ptr<Impl> impl) noexcept : impl_(std::move(impl)) {}
MountedReader::~MountedReader() = default;
const MountIdentity& MountedReader::identity() const noexcept {
    return impl_->mount->identity();
}
const MountedResources& MountedReader::mount() const noexcept {
    return *impl_->mount;
}

MountedReadResult MountedReader::read_sectors(std::uint32_t lba, std::uint32_t count,
                                              std::span<std::byte> destination) noexcept {
    if (!count || count > 0x4000)
        return {ReaderDisposition::not_covered, Status::invalid_range, 0};
    const auto bytes = std::uint64_t(count) * 2048;
    if (bytes != destination.size())
        return {ReaderDisposition::not_covered, Status::invalid_range, 0};
    if (bytes > impl_->max_read_bytes)
        return {ReaderDisposition::not_covered, Status::read_limit, 0};
    const auto route = impl_->mount->resolve_sectors(lba, count);
    if (route.status != RouteStatus::ok || route.total_bytes != bytes ||
        route.prefix_bytes != bytes)
        return {ReaderDisposition::not_covered, Status::invalid_range, 0};
    const auto found = impl_->handles.find(route.view.get());
    if (found == impl_->handles.end())
        return {ReaderDisposition::failed, Status::invalid_handle, 0};
    const auto result = impl_->session.read_exact(found->second, route.offset, destination);
    if (result.status != Status::ok)
        return {ReaderDisposition::failed, result.status, 0};
    return {ReaderDisposition::ok, Status::ok, result.bytes};
}

MountedReaderOpenResult
MountedReader::open_file1_windows(const std::filesystem::path& root,
                                  const std::optional<std::filesystem::path>& plan,
                                  std::size_t maximum) noexcept {
    MountedReaderOpenResult result;
    try {
        if (!maximum) {
            result.status = MountStatus::unsupported_layout;
            result.detail = "Mounted reader maximum read must be positive";
            return result;
        }
        auto mounted = MountedResources::open_file1_windows(root, plan);
        if (mounted.status != MountStatus::ok) {
            result.status = mounted.status;
            result.system_error = mounted.system_error;
            result.detail = std::move(mounted.detail);
            return result;
        }
        auto impl = std::make_unique<Impl>(std::move(mounted.mount), maximum);
        impl->open_routes();
        result.reader = std::shared_ptr<MountedReader>(new MountedReader(std::move(impl)));
        result.status = MountStatus::ok;
    } catch (const std::bad_alloc&) {
        result.status = MountStatus::no_memory;
    } catch (const OpenFailure& error) {
        result.status = error.status == Status::no_memory ? MountStatus::no_memory
                                                          : MountStatus::source_failure;
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
