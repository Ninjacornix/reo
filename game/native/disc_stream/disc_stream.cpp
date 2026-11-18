#include "disc_stream.hpp"

#include <bit>
#include <stdexcept>

namespace reo::native::disc_stream {
namespace {
std::int32_t word(std::uint32_t value) noexcept { return std::bit_cast<std::int32_t>(value); }
std::int32_t add(std::int32_t a, std::int32_t b) noexcept {
    return word(static_cast<std::uint32_t>(a) + static_cast<std::uint32_t>(b));
}
std::int32_t subtract(std::int32_t a, std::int32_t b) noexcept {
    return word(static_cast<std::uint32_t>(a) - static_cast<std::uint32_t>(b));
}
std::uint32_t byte_count(std::int32_t sectors) noexcept {
    return static_cast<std::uint32_t>(sectors) << 11;
}
} // namespace

std::int32_t seek(FileState* file, std::int32_t offset, std::int32_t origin, Hooks& hooks) {
    if (!file) { hooks.diagnostic(Diagnostic::null_file); return 0; }
    if (origin == 0) file->cursor = offset;
    else if (origin == 1) file->cursor = add(file->cursor, offset);
    else if (origin == 2) file->cursor = add(file->sectors, offset);
    file->completed = 0;
    auto selected = file->cursor < file->sectors ? file->cursor : file->sectors;
    if (selected < 0) selected = 0;
    file->cursor = selected;
    return selected;
}

std::int32_t tell(const FileState* file, Hooks& hooks) {
    if (!file) { hooks.diagnostic(Diagnostic::null_file); return 0; }
    return file->cursor;
}

std::int32_t status(const FileState* file, Hooks& hooks) {
    if (!file) { hooks.diagnostic(Diagnostic::null_file); return 0; }
    return static_cast<std::int32_t>(file->status);
}

std::int32_t transferred(const FileState* file, Hooks& hooks) {
    if (!file) { hooks.diagnostic(Diagnostic::null_file); return 0; }
    return file->status == FileStatus::ready ? word(byte_count(file->completed)) : 0;
}

std::int32_t request(FileState* file, std::int32_t sectors, BufferId destination,
                     const Settings& settings, Hooks& hooks) {
    if (!file) { hooks.diagnostic(Diagnostic::null_file); return 0; }
    if (sectors < 0) { hooks.diagnostic(Diagnostic::negative_request); return 0; }
    if (!destination) { hooks.diagnostic(Diagnostic::null_buffer); return 0; }
    if (file->status == FileStatus::pending) return 0;
    if (sectors == 0) { file->status = FileStatus::ready; return 0; }

    file->request = hooks.create_request();
    if (!file->request) return 0;
    const auto remaining = subtract(file->sectors, file->cursor);
    const auto accepted = sectors < remaining ? sectors : remaining;
    for (unsigned i = 0; i < settings.read_mode.size(); ++i)
        file->read_mode[i] = settings.read_mode[i];
    file->accepted = accepted;
    file->buffer = destination;
    hooks.cache_range(destination, byte_count(accepted));
    const auto start = file->base_sector + static_cast<std::uint32_t>(file->cursor);
    if (!hooks.prepare_disc(file->request, start, accepted, destination, file->read_mode)) {
        hooks.destroy(file->request);
        return 0; // Retain the stored request ID and other residual fields.
    }
    if (settings.sync_mode == 1) {
        hooks.cd_sync();
        hooks.server_gate();
        hooks.server_service();
        hooks.wait(file->request);
        hooks.destroy(file->request);
        file->request = {};
        file->completed = sectors;
        file->status = FileStatus::ready;
        file->cursor = add(file->cursor, file->accepted);
    } else {
        file->status = FileStatus::pending;
    }
    return file->accepted;
}

void update(FileState& file, Hooks& hooks) {
    if (!file.request) return;
    hooks.enter();
    const auto current = hooks.request_status(file.request);
    bool terminal = true;
    switch (current) {
    case RequestStatus::stopped:
        file.status = FileStatus::idle;
        break;
    case RequestStatus::complete:
        file.completed = file.accepted;
        file.cursor = add(file.cursor, file.accepted);
        file.status = FileStatus::ready;
        break;
    case RequestStatus::error:
        file.status = FileStatus::error;
        break;
    case RequestStatus::queued: case RequestStatus::active:
    case RequestStatus::stage4: case RequestStatus::stage5: case RequestStatus::stage6:
    case RequestStatus::stage7: case RequestStatus::stage8:
        terminal = false;
        break;
    default:
        throw std::logic_error("RequestStatus outside the admitted hook domain");
    }
    if (terminal) {
        hooks.destroy(file.request);
        file.request = {};
    }
    hooks.leave();
}

} // namespace reo::native::disc_stream
