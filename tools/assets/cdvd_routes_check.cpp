#include "runtime/cdvd/cdvd.h"
#include "runtime/assets/overlay.h"
#include <iostream>

// Run against an owned import with REO_ASSET_OVERLAY set by the caller.
// Verifies all bytes of each changed payload through the shared host hook and
// sector provider. Never writes original or replacement files.
int main(int argc, char** argv) {
    try {
        reo::assets::require(argc == 2, "Usage: cdvd_routes_check imported-data-directory");
        reo::CDVD disc(std::filesystem::u8path(argv[1]));
        reo::assets::require(bool(reo::assets::active), "Set REO_ASSET_OVERLAY to the prepared binary plan");
        uint64_t bytes = 0; unsigned replacements = 0;
        for (const auto* name : {"NETBIO00.DAT", "NETBIO01.DAT", "NETBIO02.DAT"}) {
            const auto* archive = reo::assets::active->find(name);
            if (!archive) continue;
            uint32_t lba, size;
            reo::assets::require(disc.search_file(std::string("cdrom0:\\") + name + ";1", lba, size), "Virtual search failed");
            reo::assets::require(lba == archive->lba && size == archive->file.size && disc.file_size(name) == size,
                                 "Virtual lookup or stat returned original metadata");
            const auto host = disc.resolve_path(name);
            uint64_t hostSize = 0;
            reo::assets::require(reo::assets::hostSize(host, hostSize) && hostSize == size, "Host hook returned original metadata");
            for (const auto& segment : archive->file.segments) {
                if (!segment.source || !segment.source->traceReplacement) continue;
                ++replacements;
                reo::assets::require(segment.offset % 2048 == 0, "Replacement is not sector aligned");
                for (uint64_t at = 0; at < segment.size; at += 65536) {
                    const auto n = static_cast<size_t>(std::min<uint64_t>(65536, segment.size - at));
                    const auto sectors = static_cast<uint32_t>((n + 2047) / 2048);
                    std::vector<uint8_t> expected(n), hostBytes(n), sectorBytes(sectors * 2048);
                    segment.source->read(segment.sourceOffset + at, n, expected.data());
                    reo::assets::require(reo::assets::hostRead(host, segment.offset + at, hostBytes.data(), n), "Host range hook did not handle replacement");
                    reo::assets::require(disc.read_sectors(lba + static_cast<uint32_t>((segment.offset + at) / 2048), sectors, sectorBytes.data()), "Virtual sector read failed");
                    reo::assets::require(expected == hostBytes && std::equal(expected.begin(), expected.end(), sectorBytes.begin()),
                                         "Replacement bytes differ across disc access paths");
                    bytes += n;
                }
            }
        }
        std::cout << "PASS: " << replacements << " replacement payloads, " << bytes << " bytes through host and sector routes\n";
        return 0;
    } catch (const std::exception& e) { std::cerr << e.what() << '\n'; return 1; }
}
