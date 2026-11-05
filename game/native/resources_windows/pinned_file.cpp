#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0A00
#endif
#include "pinned_file.hpp"

#ifndef _WIN32
#error "PinnedFile is a Windows resource adapter"
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <bcrypt.h>

#include <algorithm>
#include <limits>
#include <mutex>
#include <new>
#include <stdexcept>
#include <system_error>
#include <utility>
#include <vector>

namespace reo::native::resources::win32 {
namespace {
struct FileHandle {
    HANDLE value{INVALID_HANDLE_VALUE};
    ~FileHandle() { if (value != INVALID_HANDLE_VALUE) CloseHandle(value); }
    FileHandle() = default;
    FileHandle(const FileHandle&) = delete;
    FileHandle& operator=(const FileHandle&) = delete;
};
struct HashHandles {
    BCRYPT_ALG_HANDLE algorithm{};
    BCRYPT_HASH_HANDLE hash{};
    ~HashHandles() {
        if (hash) BCryptDestroyHash(hash);
        if (algorithm) BCryptCloseAlgorithmProvider(algorithm, 0);
    }
};
std::filesystem::path readable(const std::filesystem::path& input) {
    auto value = input.wstring();
    if (value.rfind(L"\\\\?\\", 0) == 0) return input;
    value = std::filesystem::absolute(input).lexically_normal().wstring();
    std::replace(value.begin(), value.end(), L'/', L'\\');
    return value.rfind(L"\\\\", 0) == 0 ? L"\\\\?\\UNC\\" + value.substr(2) : L"\\\\?\\" + value;
}
std::filesystem::path final_path(HANDLE handle) {
    const DWORD required = GetFinalPathNameByHandleW(handle, nullptr, 0, FILE_NAME_NORMALIZED | VOLUME_NAME_DOS);
    if (!required) throw std::system_error(GetLastError(), std::system_category(), "Resolve retained resource identity");
    std::wstring value(required + 1, L'\0');
    const DWORD count = GetFinalPathNameByHandleW(handle, value.data(), static_cast<DWORD>(value.size()),
                                                 FILE_NAME_NORMALIZED | VOLUME_NAME_DOS);
    if (!count || count >= value.size())
        throw std::system_error(GetLastError(), std::system_category(), "Resolve retained resource path");
    value.resize(count);
    return value;
}
} // namespace

struct PinnedFile::Impl {
    FileHandle handle;
    FileIdentity identity;
    mutable std::mutex mutex;

    std::size_t read(std::uint64_t offset, std::size_t bytes, void* output) const {
        if (offset > identity.length || bytes > identity.length - offset || (bytes && !output))
            throw std::out_of_range("Pinned resource read outside admitted extent");
        if (!bytes) return 0;
        std::lock_guard lock(mutex);
        LARGE_INTEGER position;
        position.QuadPart = static_cast<LONGLONG>(offset);
        if (!SetFilePointerEx(handle.value, position, nullptr, FILE_BEGIN))
            throw std::system_error(GetLastError(), std::system_category(), "Pinned resource seek");
        std::size_t completed = 0;
        while (completed < bytes) {
            const auto chunk = static_cast<DWORD>(std::min<std::size_t>(bytes - completed, 4 * 1024 * 1024));
            DWORD actual = 0;
            if (!ReadFile(handle.value, static_cast<std::byte*>(output) + completed, chunk, &actual, nullptr))
                throw std::system_error(GetLastError(), std::system_category(), "Pinned resource read");
            completed += actual;
            if (actual != chunk) break;
        }
        return completed;
    }
};

PinnedFile::PinnedFile(std::unique_ptr<Impl> impl) noexcept : impl_(std::move(impl)) {}
PinnedFile::~PinnedFile() = default;
std::uint64_t PinnedFile::size() const noexcept { return impl_->identity.length; }
std::size_t PinnedFile::read(std::uint64_t offset, std::size_t bytes, void* output) const {
    return impl_->read(offset, bytes, output);
}
const FileIdentity& PinnedFile::identity() const noexcept { return impl_->identity; }

PinnedOpenResult PinnedFile::open_verified(const std::filesystem::path& path,
                                         std::uint64_t expected_length,
                                         const Digest& expected_sha256) noexcept {
    try {
        if (path.empty() || !path.is_absolute() || path.native().find(L'\0') != std::wstring::npos)
            return {PinnedStatus::invalid_path, {}, 0, {}};
        auto impl = std::make_unique<Impl>();
        impl->handle.value = CreateFileW(readable(path).c_str(), GENERIC_READ, FILE_SHARE_READ,
                                         nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_RANDOM_ACCESS, nullptr);
        if (impl->handle.value == INVALID_HANDLE_VALUE)
            return {PinnedStatus::io_error, {}, GetLastError(), {}};
        if (GetFileType(impl->handle.value) != FILE_TYPE_DISK)
            return {PinnedStatus::unsupported_file, {}, 0, {}};
        FILE_STANDARD_INFO standard{};
        FILE_ID_INFO file_id{};
        if (!GetFileInformationByHandleEx(impl->handle.value, FileStandardInfo, &standard, sizeof(standard)) ||
            !GetFileInformationByHandleEx(impl->handle.value, FileIdInfo, &file_id, sizeof(file_id)))
            return {PinnedStatus::io_error, {}, GetLastError(), {}};
        if (standard.Directory || standard.EndOfFile.QuadPart < 0)
            return {PinnedStatus::unsupported_file, {}, 0, {}};
        impl->identity.length = static_cast<std::uint64_t>(standard.EndOfFile.QuadPart);
        if (impl->identity.length != expected_length)
            return {PinnedStatus::length_mismatch, {}, 0, {}};
        impl->identity.volume_serial = file_id.VolumeSerialNumber;
        std::copy(std::begin(file_id.FileId.Identifier), std::end(file_id.FileId.Identifier), impl->identity.file_id.begin());
        impl->identity.final_path = final_path(impl->handle.value);

        HashHandles handles;
        NTSTATUS status = BCryptOpenAlgorithmProvider(&handles.algorithm, BCRYPT_SHA256_ALGORITHM, nullptr, 0);
        const auto hash_failure = [](NTSTATUS value) { return PinnedOpenResult{PinnedStatus::hash_error, {},
                                                                             static_cast<std::uint32_t>(value), {}}; };
        if (status < 0) return hash_failure(status);
        DWORD object_bytes = 0, result_bytes = 0, digest_bytes = 0;
        status = BCryptGetProperty(handles.algorithm, BCRYPT_OBJECT_LENGTH,
                                   reinterpret_cast<PUCHAR>(&object_bytes), sizeof(object_bytes), &result_bytes, 0);
        if (status < 0) return hash_failure(status);
        status = BCryptGetProperty(handles.algorithm, BCRYPT_HASH_LENGTH,
                                   reinterpret_cast<PUCHAR>(&digest_bytes), sizeof(digest_bytes), &result_bytes, 0);
        if (status < 0) return hash_failure(status);
        if (digest_bytes != 32 || object_bytes == 0 || object_bytes > 1024 * 1024)
            return {PinnedStatus::hash_error, {}, 0, {}};
        // The object buffer must outlive its BCrypt hash handle.
        std::vector<std::uint8_t> hash_object(object_bytes);
        struct HashLifetime {
            BCRYPT_HASH_HANDLE& handle;
            ~HashLifetime() { if (handle) { BCryptDestroyHash(handle); handle = nullptr; } }
        } hash_lifetime{handles.hash};
        status = BCryptCreateHash(handles.algorithm, &handles.hash, hash_object.data(), object_bytes, nullptr, 0, 0);
        if (status < 0) return hash_failure(status);
        std::vector<std::uint8_t> buffer(256 * 1024);
        std::uint64_t offset = 0;
        while (offset < expected_length) {
            const auto count = static_cast<std::size_t>(std::min<std::uint64_t>(buffer.size(), expected_length - offset));
            if (impl->read(offset, count, buffer.data()) != count)
                return {PinnedStatus::io_error, {}, ERROR_HANDLE_EOF, {}};
            status = BCryptHashData(handles.hash, buffer.data(), static_cast<ULONG>(count), 0);
            if (status < 0) return hash_failure(status);
            offset += count;
        }
        Digest observed{};
        status = BCryptFinishHash(handles.hash, observed.data(), static_cast<ULONG>(observed.size()), 0);
        if (status < 0) return hash_failure(status);
        if (observed != expected_sha256) return {PinnedStatus::hash_mismatch, {}, 0, observed};
        impl->identity.sha256 = observed;
        std::shared_ptr<const PinnedFile> file(new PinnedFile(std::move(impl)));
        return {PinnedStatus::ok, std::move(file), 0, observed};
    } catch (const std::bad_alloc&) {
        return {PinnedStatus::no_memory, {}, ERROR_NOT_ENOUGH_MEMORY, {}};
    } catch (const std::system_error& error) {
        return {PinnedStatus::io_error, {}, static_cast<std::uint32_t>(error.code().value()), {}};
    } catch (...) {
        return {PinnedStatus::io_error, {}, ERROR_INVALID_DATA, {}};
    }
}
} // namespace reo::native::resources::win32
