#include "game/native/resources_windows/mounted_reader.hpp"
#include "game/native/resources_windows/facade_layout.hpp"
#include "runtime/assets/overlay.h"

#include <array>
#include <chrono>
#include <cstring>
#include <iostream>
#include <set>

namespace w = reo::native::resources::win32;
namespace r = reo::native::resources;
namespace fs = std::filesystem;
namespace {
struct Metrics {
    bool passed = false, facade_match = false, non_pak_rejected = false;
    unsigned checks = 0, files = 0, files_with_exact = 0, files_without_full_sector = 0;
    unsigned exact_reads = 0, partial_eof_checks = 0, read_ahead_checks = 0, failed_reads = 0;
    std::uint64_t imported_bytes = 0, compared_exact_bytes = 0, compared_partial_prefix_bytes = 0,
                  construction_us = 0;
    int factory_status = -1, resource_status = -1;
    std::uint32_t system_error = 0;
    std::string route_sha256, manifest_sha256, detail;
};
void check(Metrics& metrics, bool condition, const char* message) {
    ++metrics.checks;
    if (!condition)
        throw std::runtime_error(message);
}
std::string hex(const w::Digest& value) {
    constexpr char digits[] = "0123456789abcdef";
    std::string result(64, '0');
    for (std::size_t i = 0; i < value.size(); ++i) {
        result[i * 2] = digits[value[i] >> 4];
        result[i * 2 + 1] = digits[value[i] & 15];
    }
    return result;
}
bool sentinel(std::span<const std::byte> bytes) {
    return std::all_of(bytes.begin(), bytes.end(),
                       [](auto value) { return value == std::byte{0xA5}; });
}
void emit(const Metrics& value) {
    // Fixed keys, primitive values and bounded diagnostics; no payload bytes or
    // per-file asset content is serialized. Python owns the JSON receipt.
    std::cout << "PROBE passed=" << value.passed << '\n'
              << "PROBE factory_status=" << value.factory_status << '\n'
              << "PROBE resource_status=" << value.resource_status << '\n'
              << "PROBE system_error=" << value.system_error << '\n'
              << "PROBE facade_match=" << value.facade_match << '\n'
              << "PROBE non_pak_rejected=" << value.non_pak_rejected << '\n'
              << "PROBE checks=" << value.checks << '\n'
              << "PROBE files=" << value.files << '\n'
              << "PROBE imported_bytes=" << value.imported_bytes << '\n'
              << "PROBE files_with_exact=" << value.files_with_exact << '\n'
              << "PROBE files_without_full_sector=" << value.files_without_full_sector << '\n'
              << "PROBE exact_reads=" << value.exact_reads << '\n'
              << "PROBE compared_exact_bytes=" << value.compared_exact_bytes << '\n'
              << "PROBE partial_eof_checks=" << value.partial_eof_checks << '\n'
              << "PROBE compared_partial_prefix_bytes=" << value.compared_partial_prefix_bytes
              << '\n'
              << "PROBE read_ahead_checks=" << value.read_ahead_checks << '\n'
              << "PROBE failed_reads=" << value.failed_reads << '\n'
              << "PROBE construction_us=" << value.construction_us << '\n'
              << "PROBE route_sha256=" << value.route_sha256 << '\n'
              << "PROBE manifest_sha256=" << value.manifest_sha256 << '\n';
    auto reason = value.detail.substr(0, 512);
    for (auto& c : reason)
        if (c == '\r' || c == '\n' || static_cast<unsigned char>(c) < 32)
            c = ' ';
    std::cout << "PROBE detail=" << reason << '\n';
}
} // namespace

int main(int argc, char** argv) {
    Metrics metrics;
    try {
        check(metrics, argc == 4,
              "Pass explicit import data root, missing private ISO path, expected file count");
        const fs::path data(reinterpret_cast<const char8_t*>(argv[1]));
        const fs::path missing_iso(reinterpret_cast<const char8_t*>(argv[2]));
        const auto expected_files = std::stoul(argv[3]);
        check(metrics, data.is_absolute() && data.native().size() > 3 && data.filename() == "data",
              "Only an explicit extracted import data directory is admitted");
        check(metrics, missing_iso.is_absolute() && !fs::exists(missing_iso),
              "Private ISO sentinel must not exist");
        check(metrics, expected_files > 0 && expected_files <= 65536, "Expected count bound");
        _putenv_s("REO_GAME_PAK", "1");
        _putenv_s("REO_ASSET_OVERLAY", "");
        _putenv_s("REO_COOP_HOST", "");
        _wputenv_s(L"REO_ISO", missing_iso.c_str());
        reo::CDVD reference(data);
        check(metrics, reference.is_game_pak() && !reo::assets::active,
              "Reference is actual plain PAK mode");
        const auto begin = std::chrono::steady_clock::now();
        auto opened = w::MountedReader::open_file1_windows(data, {}, 8u * 1024u * 1024u);
        metrics.construction_us =
            static_cast<std::uint64_t>(std::chrono::duration_cast<std::chrono::microseconds>(
                                           std::chrono::steady_clock::now() - begin)
                                           .count());
        metrics.factory_status = static_cast<int>(opened.status);
        metrics.system_error = opened.system_error;
        if (opened.status != w::MountStatus::ok) {
            metrics.detail = opened.detail;
            emit(metrics);
            return 2;
        }
        auto reader = std::move(opened.reader);
        metrics.manifest_sha256 = hex(reader->identity().manifest_sha256);
        metrics.route_sha256 = hex(reader->identity().route_sha256);
        metrics.facade_match =
            w::matches_plain_pak_layout(reference, reader->mount(), bool(reo::assets::active));
        check(metrics, metrics.facade_match,
              "Actual facade mode/keys/LBAs/lengths/current source objects disagree");
        check(metrics, reader->mount().routes().size() == expected_files,
              "Actual imported route count differs from requested profile");
        check(metrics, !reader->identity().overlay_plan_sha256,
              "Probe unexpectedly admitted an overlay");
        for (const auto& route : reader->mount().routes()) {
            ++metrics.files;
            metrics.imported_bytes += route.bytes;
            check(metrics, !route.overlay, "Plain probe contains an overlay route");
            std::uint32_t legacy_lba = 0, legacy_size = 0;
            check(metrics,
                  reference.search_file(route.key, legacy_lba, legacy_size) &&
                      legacy_lba == route.lba && legacy_size == route.bytes,
                  "Actual file lookup differs from immutable route");
            const auto full = route.bytes / 2048;
            if (full)
                ++metrics.files_with_exact;
            else
                ++metrics.files_without_full_sector;
            std::set<std::pair<std::uint64_t, std::uint32_t>> ranges;
            if (full) {
                ranges.emplace(0, static_cast<std::uint32_t>(std::min<std::uint64_t>(4, full)));
                const auto middle = full / 2;
                ranges.emplace(
                    middle, static_cast<std::uint32_t>(std::min<std::uint64_t>(3, full - middle)));
                ranges.emplace(full - 1, 1);
            }
            for (const auto [sector, count] : ranges) {
                const auto size = static_cast<std::size_t>(count) * 2048;
                std::array<std::byte, 8192> native{}, legacy{};
                const auto result =
                    reader->read_sectors(route.lba + static_cast<std::uint32_t>(sector), count,
                                         std::span<std::byte>(native).first(size));
                metrics.resource_status = static_cast<int>(result.resource_status);
                if (result.disposition == w::ReaderDisposition::failed)
                    ++metrics.failed_reads;
                check(metrics,
                      result.disposition == w::ReaderDisposition::ok &&
                          result.resource_status == r::Status::ok && result.bytes == size,
                      "Wholly in-file native read failed");
                check(metrics,
                      reference.read_sectors(route.lba + static_cast<std::uint32_t>(sector), count,
                                             legacy.data()) &&
                          std::equal(native.begin(), native.begin() + size, legacy.begin()),
                      "Bounded exact payload differs from existing CDVD");
                ++metrics.exact_reads;
                metrics.compared_exact_bytes += size;
            }
            if (const auto remainder = route.bytes % 2048) {
                std::array<std::byte, 2048> native, legacy{}, expected{};
                native.fill(std::byte{0xA5});
                const auto offset = full * 2048;
                const auto result =
                    reader->read_sectors(route.lba + static_cast<std::uint32_t>(full), 1, native);
                check(metrics,
                      result.disposition == w::ReaderDisposition::not_covered && !result.bytes &&
                          sentinel(native),
                      "Partial final sector was admitted or changed output");
                const auto prefix = route.view->read(
                    offset,
                    std::span<std::byte>(expected).first(static_cast<std::size_t>(remainder)));
                check(metrics,
                      prefix == r::ReadResult{r::Status::ok, static_cast<std::size_t>(remainder)},
                      "Retained partial prefix failed");
                check(metrics,
                      reference.read_sectors(route.lba + static_cast<std::uint32_t>(full), 1,
                                             legacy.data()) &&
                          legacy == expected,
                      "Legacy partial EOF prefix/zero padding differs");
                ++metrics.partial_eof_checks;
                metrics.compared_partial_prefix_bytes += remainder;
            }
            const auto after = (route.bytes + 2047) / 2048;
            std::array<std::byte, 2048> native, legacy{};
            native.fill(std::byte{0xA5});
            const auto excluded =
                reader->read_sectors(route.lba + static_cast<std::uint32_t>(after), 1, native);
            check(metrics,
                  excluded.disposition == w::ReaderDisposition::not_covered && !excluded.bytes &&
                      sentinel(native),
                  "Read-ahead sector was admitted or changed output");
            check(metrics,
                  reference.read_sectors(route.lba + static_cast<std::uint32_t>(after), 1,
                                         legacy.data()) &&
                      std::all_of(legacy.begin(), legacy.end(),
                                  [](auto value) { return value == std::byte{0}; }),
                  "Existing read-ahead region is not zero filled");
            ++metrics.read_ahead_checks;
        }
        // Long extracted-directory root avoids CDVD's drive-root raw-volume
        // fallback. The only ISO pathname is the absent private sentinel.
        _putenv_s("REO_GAME_PAK", "0");
        reo::CDVD non_pak(data);
        metrics.non_pak_rejected =
            !non_pak.is_game_pak() && !non_pak.has_image() &&
            !w::matches_plain_pak_layout(non_pak, reader->mount(), bool(reo::assets::active));
        check(metrics, metrics.non_pak_rejected,
              "Actual non-PAK facade incorrectly passed admission");
        metrics.passed = true;
        emit(metrics);
        return 0;
    } catch (const std::exception& error) {
        metrics.detail = error.what();
        emit(metrics);
        return 1;
    }
}
