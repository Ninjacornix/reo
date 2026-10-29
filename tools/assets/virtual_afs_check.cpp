#include "runtime/assets/overlay.h"
#include <iostream>
#include <sstream>

// Standalone developer probe. No game data or runtime dependencies.
int main(int argc, char** argv) {
    try {
        if (argc == 4 && std::string(argv[1]) == "--map-plan") {
            reo::assets::Overlay overlay(std::filesystem::u8path(argv[2]), std::filesystem::u8path(argv[3]));
            for (const auto* name : {"NETBIO00.DAT", "NETBIO01.DAT", "NETBIO02.DAT"})
                if (const auto* archive = overlay.find(name)) for (const auto& segment : archive->file.segments)
                    if (segment.source) std::cout << name << '|' << archive->lba << '|' << segment.offset << '|' << segment.size << '|'
                        << segment.sourceOffset << '|' << segment.source->path.filename().string() << '|' << segment.source->traceReplacement << '\n';
            return 0;
        }
        if (argc == 4 && std::string(argv[1]) == "--validate-plan") {
            reo::assets::Overlay overlay(std::filesystem::u8path(argv[2]), std::filesystem::u8path(argv[3]));
            return 0;
        }
        if (argc < 3) throw std::runtime_error("Usage: virtual_afs_check original.afs output.afs [index/path=replacement ...]");
        auto source = std::make_shared<reo::assets::Source>(std::filesystem::u8path(argv[1]));
        reo::assets::Replacements changes;
        for (int i = 3; i < argc; ++i) {
            const std::string arg(argv[i]); const auto equals = arg.find('=');
            if (equals == std::string::npos) throw std::runtime_error("Missing replacement filename");
            reo::assets::IndexPath indices; std::stringstream parts(arg.substr(0, equals)); std::string part;
            while (std::getline(parts, part, '/')) indices.push_back(static_cast<uint32_t>(std::stoul(part)));
            reo::assets::require(changes.emplace(indices, std::make_shared<reo::assets::Source>(std::filesystem::u8path(arg.substr(equals + 1)))).second,
                                 "Duplicate replacement");
        }
        const auto file = reo::assets::build(source, 0, source->size, changes);
        std::ofstream output(std::filesystem::u8path(argv[2]), std::ios::binary);
        std::vector<uint8_t> buffer(777); // Deliberately cross alignment/segment boundaries.
        for (uint64_t offset = 0; offset < file.size; offset += buffer.size()) {
            const auto count = static_cast<size_t>(std::min<uint64_t>(buffer.size(), file.size - offset));
            file.read(offset, count, buffer.data()); output.write(reinterpret_cast<const char*>(buffer.data()), count);
        }
        reo::assets::require(bool(output), "Output write failed");
        uint8_t byte; bool boundsChecked = false;
        try { file.read(file.size, 1, &byte); } catch (...) { boundsChecked = true; }
        reo::assets::require(boundsChecked, "Out-of-bounds read accepted");
        std::cout << file.size << " bytes; " << file.segments.size() << " segments\n";
        return 0;
    } catch (const std::exception& e) { std::cerr << e.what() << '\n'; return 1; }
}
