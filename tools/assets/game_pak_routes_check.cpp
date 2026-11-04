#include "runtime/cdvd/cdvd.h"
#include <algorithm>
#include <fstream>
#include <iostream>

// Self-contained PAK-mode sector contract. Uses only synthetic files.
int main(int argc, char** argv) {
    try {
        if (argc != 2) throw std::runtime_error("Pass a new synthetic test directory");
        const auto root = std::filesystem::u8path(argv[1]);
        if (std::filesystem::exists(root)) throw std::runtime_error("Choose a new directory");
        std::filesystem::create_directories(root / "BOOT");
        std::vector<unsigned char> expected(65539);
        for (size_t i = 0; i < expected.size(); ++i) expected[i] = static_cast<unsigned char>((i * 37) ^ (i >> 8));
        { std::ofstream f(root / "BOOT" / "TEST.BIN", std::ios::binary); f.write(reinterpret_cast<const char*>(expected.data()), expected.size()); }
        reo::CDVD disc(root);
        if (!disc.has_image()) throw std::runtime_error("PAK sector provider unavailable");
        uint32_t lba = 0, size = 0;
        if (!disc.search_file("cdrom0:\\boot\\test.bin;1", lba, size) || size != expected.size() || lba < 0x01000000)
            throw std::runtime_error("File search metadata differs");
        std::vector<unsigned char> actual((expected.size() + 2047) & ~size_t(2047), 0xff);
        if (!disc.read_sectors(lba, static_cast<uint32_t>(actual.size() / 2048), actual.data()) ||
            !std::equal(expected.begin(), expected.end(), actual.begin()) ||
            !std::all_of(actual.begin() + expected.size(), actual.end(), [](auto v) { return v == 0; }))
            throw std::runtime_error("Sector bytes or last-sector padding differ");
        std::vector<unsigned char> ahead(2 * 2048, 0xff);
        if (!disc.read_sectors(lba + 32, 2, ahead.data()) || ahead[0] != expected[65536] ||
            !std::all_of(ahead.begin() + 3, ahead.end(), [](auto v) { return v == 0; }))
            throw std::runtime_error("Read-ahead past EOF differs");
        if (disc.read_sectors(lba - 1, 1, actual.data()) || disc.read_sectors(lba, 0x4001, actual.data()) ||
            disc.read_sectors(lba, 1, nullptr) || disc.search_file("MISSING.BIN", lba, size))
            throw std::runtime_error("Out-of-range read accepted");
        std::cout << "PASS: ISO-independent search, 65539 bytes, sector padding and bounds\n";
        return 0;
    } catch (const std::exception& e) { std::cerr << e.what() << '\n'; return 1; }
}
