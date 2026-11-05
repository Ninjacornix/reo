#include "game/native/resources/resource_session.hpp"
#include "game/native/resources/virtual_file_view.hpp"
#include "runtime/assets/virtual_afs.h"
#include "runtime/cdvd/cdvd.h"
#include "runtime/core/host_file.h"

#include <array>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <random>

namespace r = reo::native::resources;

void require(bool condition, const char* message) {
    if (!condition) throw std::runtime_error(message);
}

int main(int argc, char** argv) {
    try {
        require(argc == 2, "Pass a fresh synthetic output directory");
        const auto root = std::filesystem::absolute(std::filesystem::path(reinterpret_cast<const char8_t*>(argv[1])));
        require(!std::filesystem::exists(root), "Synthetic directory must not exist");
        std::filesystem::create_directories(root / "BOOT");
        // This process only: no inherited overlay, ISO, user files or game launch.
#ifdef _WIN32
        _putenv_s("REO_GAME_PAK", "1");
        _putenv_s("REO_ASSET_OVERLAY", "");
#else
        setenv("REO_GAME_PAK", "1", 1);
        unsetenv("REO_ASSET_OVERLAY");
#endif
        const auto path = root / "BOOT/TEST.BIN";
        std::vector<std::byte> expected(65539);
        for (std::size_t i = 0; i < expected.size(); ++i)
            expected[i] = std::byte((i * 37) ^ (i >> 8));
        {
            std::ofstream file(path, std::ios::binary);
            file.write(reinterpret_cast<const char*>(expected.data()), expected.size());
            require(bool(file), "Synthetic file write failed");
        }
        auto source = std::make_shared<reo::assets::Source>(path);
        const auto original = reo::assets::original(source, 0, source->size);
        const auto view = r::VirtualFileView::create(original);
        require(view.status == r::Status::ok, "Native view creation failed");
        r::ResourceSession session;
        const auto opened = session.open(view.view);
        require(opened.status == r::Status::ok, "Native session open failed");
        const auto host = std::unique_ptr<FILE, decltype(&std::fclose)>(reo::host_file::openRead(path), std::fclose);
        require(bool(host), "Host source open failed");
        std::mt19937 random(0x52454F31);
        for (unsigned i = 0; i < 256; ++i) {
            const std::size_t offset = i == 0 ? 0 : i == 1 ? expected.size() : random() % (expected.size() + 1);
            const auto length = std::min<std::size_t>(random() % 8193, expected.size() - offset);
            std::vector<std::byte> actual(length), reference(length), direct(length);
            const auto result = session.read_exact(opened.handle, offset, actual);
            require(result == r::ReadResult{r::Status::ok, length}, "Native exact read failed");
            source->read(offset, length, direct.data());
            require(reo::host_file::seek(host.get(), offset, SEEK_SET) == 0, "Host seek failed");
            require(length == 0 || std::fread(reference.data(), 1, length, host.get()) == length, "Host short read");
            require(actual == reference && actual == direct &&
                    std::equal(actual.begin(), actual.end(), expected.begin() + offset), "Byte route mismatch");
        }
        reo::CDVD disc(root);
        std::uint32_t lba = 0, size = 0;
        require(disc.has_image() && disc.search_file("cdrom0:\\boot\\test.bin;1", lba, size) &&
                size == expected.size(), "PAK source metadata mismatch");
        for (unsigned sector = 0; sector < 36; ++sector) {
            const auto offset = std::size_t(sector) * 2048;
            std::array<std::byte, 4096> sector_bytes;
            sector_bytes.fill(std::byte{0xA5});
            require(disc.read_sectors(lba + sector, 2, sector_bytes.data()), "PAK sector read failed");
            const auto prefix = offset < expected.size() ? std::min(sector_bytes.size(), expected.size() - offset) : 0;
            std::vector<std::byte> native(prefix);
            require(session.read_exact(opened.handle, std::min(offset, expected.size()), native) ==
                    r::ReadResult{r::Status::ok, prefix}, "Native sector prefix read failed");
            require(std::equal(native.begin(), native.end(), sector_bytes.begin()), "PAK prefix mismatch");
            require(std::all_of(sector_bytes.begin() + prefix, sector_bytes.end(),
                                [](auto b) { return b == std::byte{0}; }), "PAK EOF padding mismatch");
        }
        std::array<std::byte, 4> unchanged;
        unchanged.fill(std::byte{0xD2});
        require(session.read_exact(opened.handle, expected.size() - 1, unchanged) ==
                r::ReadResult{r::Status::invalid_range, 0}, "Native read silently padded beyond EOF");
        require(std::all_of(unchanged.begin(), unchanged.end(), [](auto b) { return b == std::byte{0xD2}; }),
                "Failed exact read changed output");
        session.shutdown_and_drain();
        std::cout << "PASS: 256 native/Source/host ranges, 36 PAK sector-prefix/padding cases; synthetic bytes only\n";
        return 0;
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
}
