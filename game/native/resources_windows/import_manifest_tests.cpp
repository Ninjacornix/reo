#include "import_manifest.hpp"

#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <objbase.h>

#include <exception>
#include <iostream>
#include <string>
#include <string_view>
#include <thread>
#include <vector>

namespace manifest = reo::native::resources::win32;
namespace {
constexpr std::string_view elf = "06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46";
constexpr std::string_view hash = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
unsigned checks = 0;
void check(bool passed, std::string_view what) {
    ++checks;
    if (!passed) throw std::runtime_error(std::string(what));
}
manifest::ImportManifest parse(const std::string& json) {
    return manifest::parse_import_manifest({reinterpret_cast<const std::uint8_t*>(json.data()), json.size()});
}
std::string row(std::string_view name, std::string_view length = "1", std::string_view digest = hash) {
    return "{\"Name\":\"" + std::string(name) + "\",\"Length\":" + std::string(length) +
           ",\"Sha256\":\"" + std::string(digest) + "\"}";
}
std::string document(std::string_view extra = {}, std::string_view version = "1",
                     std::string_view game = "file1", std::string_view digest = elf) {
    return "{\"Version\":" + std::string(version) + ",\"Game\":\"" + std::string(game) +
        "\",\"Source\":\"C:\\\\ISO\\\\source.iso\",\"SourceLength\":100,"
        "\"SourceWriteTicks\":639031680000000001,\"ElfSha256\":\"" + std::string(digest) +
        "\",\"Files\":[" + row("SLUS_207.65", "1048576", elf) +
        (extra.empty() ? "" : "," + std::string(extra)) + "]}";
}
void rejected(std::string json, std::string_view what) {
    bool caught = false;
    try { (void)parse(json); }
    catch (const manifest::ImportManifestError& error) {
        caught = std::string_view(error.what()).starts_with("import manifest: ");
    }
    check(caught, what);
}
void replace_once(std::string& text, std::string_view from, std::string_view to) {
    const auto pos = text.find(from);
    check(pos != std::string::npos, "fixture replacement exists");
    text.replace(pos, from.size(), to);
}

void ordinary_cases() {
    const auto first = parse(document(row("BIN\\\\R000.BIN", "4294967295")));
    check(first.version == 1 && first.game == "file1", "V1 edition/version");
    check(first.files.size() == 2 && first.files[0].name == "SLUS_207.65", "V1 rows");
    check(first.files[1].name == "BIN/R000.BIN" && first.files[1].length == 4294967295ULL,
          "separator normalization and exact maximum file length");
    check(first.source && *first.source == "C:\\ISO\\source.iso", "source is provenance");
    check(first.elf_sha256[0] == 0x06 && first.elf_sha256[31] == 0x46, "typed ELF digest");
    const auto second = parse(document(row("BIN/\u4fdd\u5b58.BIN", "0"), "2"));
    check(second.version == 2 && second.files[1].length == 0, "V2 and zero-length non-ELF");
    const std::string unicode = "BIN/\xe4\xbf\x9d\xe5\xad\x98.BIN";
    check(second.files[1].name == unicode, "literal UTF-8 path preserved");
    auto escaped = document(row("BIN/\\u4fdd\\u5b58.BIN"));
    check(parse(escaped).files[1].name == unicode, "escaped Unicode decoded by OS JSON");
    check(parse(std::string("\xef\xbb\xbf") + document()).files.size() == 1, "UTF-8 BOM");
    auto no_source = document();
    const auto at = no_source.find("\"Source\":");
    no_source.erase(at, no_source.find(",\"SourceLength\"", at) - at + 1);
    check(!parse(no_source).source, "missing optional Source");
    // Uppercase the digest only, retaining case-sensitive field/game spellings.
    auto uppercase = document();
    auto upper_hash = std::string(elf);
    for (auto& c : upper_hash) if (c >= 'a' && c <= 'f') c = static_cast<char>(c - 'a' + 'A');
    replace_once(uppercase, elf, upper_hash);
    check(parse(uppercase).elf_sha256 == first.elf_sha256, "uppercase digest accepted");

    rejected("", "empty input");
    rejected("{", "truncated JSON");
    rejected("[]", "root type");
    rejected(document({}, "3"), "unsupported version");
    rejected(document({}, "0"), "zero version");
    rejected(document({}, "1", "file2"), "wrong edition");
    rejected(document({}, "1", "FILE1"), "edition is exact");
    rejected(document({}, "1", "file1", hash), "unsupported ELF");
    rejected(document(row("X.BIN", "1", "bad")), "short digest");
    rejected(document(row("X.BIN", "1", std::string(64, 'g'))), "nonhex digest");
    rejected(document(row("X.BIN", "1", std::string(65, 'a'))), "long digest");
    for (const std::string_view length : {"-1", "-0", "1.5", "1.0", "1.00000000000000001",
                                         "1e0", "1E0", "1e-2", "+1", "4294967296", "18446744073709551615",
                                         "true", "null", "\"1\"", "NaN", "Infinity", "01"})
        rejected(document(row("X.BIN", length)), "non-domain file Length");
    rejected(document({}, "1.00000000000000001"), "near-integral version");
    rejected(document({}, "1e0"), "exponential version");
    auto source_exponent = document();
    replace_once(source_exponent, "\"SourceLength\":100", "\"SourceLength\":1e2");
    rejected(source_exponent, "restricted numeric domain covers provenance too");
    auto string_number = document();
    replace_once(string_number, "source.iso", "1.5e+2.iso");
    check(parse(string_number).source->ends_with("1.5e+2.iso"), "numeric-looking source string skipped");
    auto missing = document();
    replace_once(missing, "\"Version\"", "\"WrongKey\"");
    rejected(missing, "required field");
    rejected(document("null"), "Files row type");
    auto array_type = document();
    replace_once(array_type, "\"Files\":[", "\"Files\":{");
    rejected(array_type, "array required");
    auto empty_array = document();
    replace_once(empty_array, row("SLUS_207.65", "1048576", elf), "");
    rejected(empty_array, "nonempty array");
    auto no_elf = document();
    replace_once(no_elf, "SLUS_207.65", "OTHER.BIN");
    rejected(no_elf, "ELF row required");
    auto elf_row = document();
    replace_once(elf_row, "1048576", "0");
    rejected(elf_row, "ELF row length");
    auto malformed_utf8 = document();
    malformed_utf8.insert(10, "\xc0\xaf");
    rejected(malformed_utf8, "invalid UTF-8");
    auto raw_nul = document();
    raw_nul += std::string("\0ignored", 8);
    rejected(raw_nul, "raw NUL cannot truncate JSON admission");
    rejected(document(row("BAD\\uD800.BIN")), "unpaired escaped surrogate");
    rejected(std::string(manifest::max_manifest_bytes + 1, ' '), "bounded input");
    rejected(std::string(33, '[') + "0" + std::string(33, ']'), "bounded nesting");
    rejected(document({}, "123456789012345678901"), "bounded integer token");

    for (const std::string_view name : {"", "../X", "X/../Y", "X/./Y", "/ABS", "C:/ABS", "C:REL",
                                      "\\\\ABS", "X//Y", "X/", "X.", "X ", "AUX", "con.txt", "CON .txt",
                                      "nul.dat", "COM1.bin", "LPT9", "COM0", "CONIN$", "CONOUT$", "CLOCK$",
                                      "COM\\u00b9.txt", "A:B", "A?B", "A*B", "A|B", "A<B", "A>B",
                                      "A\\u0000B", "A\\tB", "A\\u007fB", "A\\u202eB", "LONGNA~1.BIN"})
        rejected(document(row(name)), "unsafe Windows relative path");
    rejected(document(row(std::string(256, 'A'))), "bounded path component");
    rejected(document(row(std::string(1025, 'A'))), "bounded path name");
    rejected(document(row("BIN/X") + "," + row("bin/x")), "case-insensitive duplicate");
    rejected(document(row("BIN/\\u00e4") + "," + row("bin/\\u00c4")), "Unicode case-insensitive duplicate");
    rejected(document(row("BIN/X") + "," + row("BIN\\\\X")), "separator alias duplicate");
    rejected(document(row("slus_207.65")), "ELF alias duplicate");
    rejected(document(row("BIN") + "," + row("BIN/X")), "file/directory prefix conflict");
    rejected(document(row("BIN/X") + "," + row("BIN")), "reverse file/directory prefix conflict");

    // Count rejection precedes row traversal and needs no imported filesystem.
    std::string many;
    many.reserve(7200000);
    const auto repeated = row("X");
    for (std::size_t i = 0; i < manifest::max_imported_files; ++i) {
        if (i) many += ',';
        many += repeated;
    }
    rejected(document(many), "bounded file count");
}

void apartment_case(DWORD mode, APTTYPE expected) {
    std::exception_ptr error;
    std::thread worker([&] {
        try {
            const auto init = CoInitializeEx(nullptr, mode);
            check(SUCCEEDED(init), "existing apartment initialized");
            try {
                APTTYPE before{};
                APTTYPEQUALIFIER before_qualifier{};
                check(SUCCEEDED(CoGetApartmentType(&before, &before_qualifier)) &&
                      (before == expected || (expected == APTTYPE_STA && before == APTTYPE_MAINSTA)),
                      "fixture apartment has the requested mode");
                for (unsigned i = 0; i < 3; ++i) {
                    (void)parse(document());
                    rejected("{", "failed parse balances apartment");
                }
                APTTYPE actual{};
                APTTYPEQUALIFIER qualifier{};
                check(SUCCEEDED(CoGetApartmentType(&actual, &qualifier)) && actual == before &&
                      qualifier == before_qualifier,
                      "parser retains the existing apartment mode");
            } catch (...) { CoUninitialize(); throw; }
            CoUninitialize();
            APTTYPE actual{};
            APTTYPEQUALIFIER qualifier{};
            check(CoGetApartmentType(&actual, &qualifier) == CO_E_NOTINITIALIZED,
                  "successful and failed parses leave balanced COM counts");
        } catch (...) { error = std::current_exception(); }
    });
    worker.join();
    if (error) std::rethrow_exception(error);
}
} // namespace

int main() {
    try {
        ordinary_cases();
        APTTYPE type{};
        APTTYPEQUALIFIER qualifier{};
        check(CoGetApartmentType(&type, &qualifier) == CO_E_NOTINITIALIZED,
              "parser's own MTA initialization balanced");
        apartment_case(COINIT_APARTMENTTHREADED, APTTYPE_STA);
        apartment_case(COINIT_MULTITHREADED, APTTYPE_MTA);
        std::cout << "Windows.Data.Json manifest admission: " << checks << " checks passed\n";
        return 0;
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
}
