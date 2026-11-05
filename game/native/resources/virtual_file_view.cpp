#include "virtual_file_view.hpp"

#include "runtime/assets/virtual_afs.h"

#include <limits>
#include <map>
#include <new>

namespace reo::native::resources {
namespace {
std::filesystem::path source_constructor_path(const std::filesystem::path& path) {
#ifdef _WIN32
    // Source stores the extended readablePath result, but its constructor calls
    // readablePath again. MinGW filesystem::absolute is not idempotent on that
    // extended form; normalize only this wrapper prefix before reusing Source.
    const auto value = path.wstring();
    if (value.rfind(L"\\\\?\\UNC\\", 0) == 0) return L"\\\\" + value.substr(8);
    if (value.rfind(L"\\\\?\\", 0) == 0) return value.substr(4);
#endif
    return path;
}
} // namespace

struct VirtualFileView::Impl {
    reo::assets::VirtualFile file;
};

VirtualFileView::VirtualFileView(std::unique_ptr<Impl> impl) noexcept : impl_(std::move(impl)) {}
VirtualFileView::~VirtualFileView() = default;

ViewResult VirtualFileView::create(const reo::assets::VirtualFile& file) noexcept {
    try {
        auto frozen = std::make_unique<Impl>();
        frozen->file.size = file.size;
        frozen->file.segments.reserve(file.segments.size());
        std::map<const reo::assets::Source*, std::shared_ptr<reo::assets::Source>> sources;
        std::map<const std::vector<std::uint8_t>*, std::shared_ptr<std::vector<std::uint8_t>>> buffers;
        std::uint64_t previous_end = 0;
        for (const auto& segment : file.segments) {
            if (bool(segment.source) == bool(segment.bytes) || segment.offset < previous_end ||
                segment.offset > file.size || segment.size > file.size - segment.offset)
                return {Status::invalid_view, {}};
            previous_end = segment.offset + segment.size;
            auto copy = segment;
            if (segment.source) {
                // Source's seek uses streamoff. Admit only representable source
                // offsets, independent of the virtual file's sparse total size.
                if (segment.sourceOffset > std::uint64_t(std::numeric_limits<std::streamoff>::max()) ||
                    segment.size > std::uint64_t(std::numeric_limits<std::streamoff>::max()) - segment.sourceOffset)
                    return {Status::invalid_view, {}};
                auto& source = sources[segment.source.get()];
                if (!source) {
                    source = std::make_shared<reo::assets::Source>(source_constructor_path(segment.source->path));
                    if (source->size != segment.source->size) return {Status::source_failure, {}};
                    source->transient = segment.source->transient;
                    if (source->transient) source->stream.close();
                }
                if (segment.sourceOffset > source->size || segment.size > source->size - segment.sourceOffset)
                    return {Status::invalid_view, {}};
                copy.source = source;
            } else {
                // Existing VirtualFile uses memory bytes from index zero and
                // ignores sourceOffset on that branch. Require zero explicitly.
                if (segment.sourceOffset != 0 || segment.size > segment.bytes->size())
                    return {Status::invalid_view, {}};
                auto& bytes = buffers[segment.bytes.get()];
                if (!bytes) bytes = std::make_shared<std::vector<std::uint8_t>>(*segment.bytes);
                copy.bytes = bytes;
            }
            frozen->file.segments.push_back(std::move(copy));
        }
        return {Status::ok, std::shared_ptr<const ByteView>(new VirtualFileView(std::move(frozen)))};
    } catch (const std::bad_alloc&) {
        return {Status::no_memory, {}};
    } catch (...) {
        return {Status::source_failure, {}};
    }
}

std::uint64_t VirtualFileView::size() const noexcept { return impl_->file.size; }

ReadResult VirtualFileView::read(std::uint64_t offset, std::span<std::byte> destination) const {
    if (offset > size() || destination.size() > size() - offset) return {Status::invalid_range, 0};
    try {
        impl_->file.read(offset, destination.size(), destination.data());
        return {Status::ok, destination.size()};
    } catch (const std::bad_alloc&) {
        return {Status::no_memory, 0};
    } catch (...) {
        return {Status::source_failure, 0};
    }
}

} // namespace reo::native::resources
