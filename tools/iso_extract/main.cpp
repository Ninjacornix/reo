/*
 * reo-extract — ISO extraction and ELF analysis tool
 *
 * Usage: reo-extract <path-to-Outbreak.iso> [output-dir]
 *
 * Extracts all files from the ISO, identifies the main ELF executable,
 * and prints basic analysis (entry point, section layout, symbol info).
 */

#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <filesystem>
#include "iso9660.h"

namespace fs = std::filesystem;

// Minimal ELF header parsing (PS2 ELF = 32-bit MIPS little-endian)
struct Elf32Header {
    uint8_t magic[4]; // 0x7F 'E' 'L' 'F'
    uint8_t ei_class; // 1 = 32-bit
    uint8_t ei_data;  // 1 = little-endian
    uint8_t ei_version;
    uint8_t ei_osabi;
    uint8_t padding[8];
    uint16_t type;    // 2 = ET_EXEC
    uint16_t machine; // 8 = MIPS, 0x61 = MIPS R5900
    uint32_t version;
    uint32_t entry; // Entry point address
    uint32_t phoff; // Program header table offset
    uint32_t shoff; // Section header table offset
    uint32_t flags;
    uint16_t ehsize;
    uint16_t phentsize;
    uint16_t phnum; // Number of program headers
    uint16_t shentsize;
    uint16_t shnum;    // Number of section headers
    uint16_t shstrndx; // Section name string table index
};

struct Elf32ProgramHeader {
    uint32_t type;
    uint32_t offset;
    uint32_t vaddr;
    uint32_t paddr;
    uint32_t filesz;
    uint32_t memsz;
    uint32_t flags;
    uint32_t align;
};

struct Elf32SectionHeader {
    uint32_t name; // Offset into section name string table
    uint32_t type;
    uint32_t flags;
    uint32_t addr;
    uint32_t offset;
    uint32_t size;
    uint32_t link;
    uint32_t info;
    uint32_t addralign;
    uint32_t entsize;
};

static void analyze_elf(const std::vector<uint8_t>& elf_data, const std::string& name) {
    if (elf_data.size() < sizeof(Elf32Header)) {
        fprintf(stderr, "[ELF] File too small\n");
        return;
    }

    const Elf32Header* hdr = (const Elf32Header*)elf_data.data();

    // Verify ELF magic
    if (hdr->magic[0] != 0x7F || hdr->magic[1] != 'E' || hdr->magic[2] != 'L' ||
        hdr->magic[3] != 'F') {
        fprintf(stderr, "[ELF] Invalid ELF magic\n");
        return;
    }

    printf("\n");
    printf("============================================\n");
    printf("  ELF Analysis: %s\n", name.c_str());
    printf("============================================\n");
    printf("  Class:        %s\n", hdr->ei_class == 1 ? "32-bit" : "64-bit");
    printf("  Endian:       %s\n", hdr->ei_data == 1 ? "Little" : "Big");
    printf("  Machine:      0x%04X (%s)\n", hdr->machine,
           hdr->machine == 8      ? "MIPS"
           : hdr->machine == 0x61 ? "MIPS R5900"
                                  : "unknown");
    printf("  Entry Point:  0x%08X\n", hdr->entry);
    printf("  PH offset:    0x%08X (%d entries)\n", hdr->phoff, hdr->phnum);
    printf("  SH offset:    0x%08X (%d entries)\n", hdr->shoff, hdr->shnum);
    printf("  Flags:        0x%08X\n", hdr->flags);
    printf("\n");

    // Program headers (segments)
    printf("  Program Headers (Segments):\n");
    printf("  %-8s %-10s %-10s %-10s %-10s %-6s\n", "Type", "VAddr", "FileSz", "MemSz", "Offset",
           "Flags");
    printf("  %-8s %-10s %-10s %-10s %-10s %-6s\n", "----", "-----", "------", "-----", "------",
           "-----");

    uint32_t code_size = 0;
    uint32_t data_size = 0;

    for (int i = 0; i < hdr->phnum; i++) {
        uint32_t ph_off = hdr->phoff + i * hdr->phentsize;
        if (ph_off + sizeof(Elf32ProgramHeader) > elf_data.size())
            break;

        const Elf32ProgramHeader* ph = (const Elf32ProgramHeader*)(elf_data.data() + ph_off);

        const char* type_str = "???";
        switch (ph->type) {
            case 0:
                type_str = "NULL";
                break;
            case 1:
                type_str = "LOAD";
                break;
            case 2:
                type_str = "DYNAMIC";
                break;
            case 3:
                type_str = "INTERP";
                break;
            case 4:
                type_str = "NOTE";
                break;
            case 0x70000000:
                type_str = "MIPS_REG";
                break;
        }

        char flags_str[4] = "---";
        if (ph->flags & 1)
            flags_str[2] = 'X'; // Execute
        if (ph->flags & 2)
            flags_str[1] = 'W'; // Write
        if (ph->flags & 4)
            flags_str[0] = 'R'; // Read

        printf("  %-8s 0x%08X 0x%08X 0x%08X 0x%08X %s\n", type_str, ph->vaddr, ph->filesz,
               ph->memsz, ph->offset, flags_str);

        if (ph->type == 1) { // PT_LOAD
            if (ph->flags & 1)
                code_size += ph->filesz; // Executable
            else
                data_size += ph->filesz;
        }
    }

    printf("\n");
    printf("  Code size: %u bytes (%.1f MB)\n", code_size, code_size / 1048576.0);
    printf("  Data size: %u bytes (%.1f MB)\n", data_size, data_size / 1048576.0);

    // Section headers (if present)
    if (hdr->shnum > 0 && hdr->shoff > 0 && hdr->shoff < elf_data.size()) {
        printf("\n  Section Headers:\n");
        printf("  %-4s %-20s %-10s %-10s %-10s %-6s\n", "#", "Name", "Addr", "Size", "Offset",
               "Type");

        // Get section name string table
        const char* strtab = nullptr;
        if (hdr->shstrndx < hdr->shnum) {
            uint32_t strtab_off = hdr->shoff + hdr->shstrndx * hdr->shentsize;
            if (strtab_off + sizeof(Elf32SectionHeader) <= elf_data.size()) {
                const Elf32SectionHeader* strtab_sh =
                    (const Elf32SectionHeader*)(elf_data.data() + strtab_off);
                if (strtab_sh->offset + strtab_sh->size <= elf_data.size()) {
                    strtab = (const char*)(elf_data.data() + strtab_sh->offset);
                }
            }
        }

        bool has_debug = false;
        bool has_mdebug = false;
        bool has_symtab = false;
        uint32_t symtab_entries = 0;

        for (int i = 0; i < hdr->shnum; i++) {
            uint32_t sh_off = hdr->shoff + i * hdr->shentsize;
            if (sh_off + sizeof(Elf32SectionHeader) > elf_data.size())
                break;

            const Elf32SectionHeader* sh = (const Elf32SectionHeader*)(elf_data.data() + sh_off);

            const char* name = (strtab && sh->name < 65536) ? strtab + sh->name : "";

            const char* type_str = "???";
            switch (sh->type) {
                case 0:
                    type_str = "NULL";
                    break;
                case 1:
                    type_str = "PROGBITS";
                    break;
                case 2:
                    type_str = "SYMTAB";
                    break;
                case 3:
                    type_str = "STRTAB";
                    break;
                case 4:
                    type_str = "RELA";
                    break;
                case 8:
                    type_str = "NOBITS";
                    break;
                case 9:
                    type_str = "REL";
                    break;
                case 0x70000005:
                    type_str = "MIPS_DEBUG";
                    break;
                case 0x70000006:
                    type_str = "MIPS_REGINFO";
                    break;
            }

            printf("  %-4d %-20s 0x%08X 0x%08X 0x%08X %s\n", i, name, sh->addr, sh->size,
                   sh->offset, type_str);

            // Check for useful sections
            if (strcmp(name, ".debug") == 0 || strncmp(name, ".debug_", 7) == 0) {
                has_debug = true;
            }
            if (strcmp(name, ".mdebug") == 0) {
                has_mdebug = true;
            }
            if (sh->type == 2) { // SHT_SYMTAB
                has_symtab = true;
                if (sh->entsize > 0) {
                    symtab_entries = sh->size / sh->entsize;
                }
            }
        }

        printf("\n");
        printf("  Debug info:    %s\n", has_debug ? "YES (DWARF)" : "No");
        printf("  MIPS debug:    %s\n", has_mdebug ? "YES (.mdebug/STABS)" : "No");
        printf("  Symbol table:  %s", has_symtab ? "YES" : "No");
        if (has_symtab)
            printf(" (%u entries)", symtab_entries);
        printf("\n");

        if (has_debug || has_mdebug) {
            printf("\n  *** DEBUG SYMBOLS FOUND! This will greatly aid recompilation. ***\n");
        }
    }

    printf("============================================\n\n");
}

static void print_directory(const reo::IsoDirectoryEntry& dir, int depth = 0) {
    for (auto& entry : dir.children) {
        for (int i = 0; i < depth; i++)
            printf("  ");

        if (entry.is_directory) {
            printf("[DIR] %s/\n", entry.name.c_str());
            print_directory(entry, depth + 1);
        } else {
            printf("      %s (%u bytes, LBA %u)\n", entry.name.c_str(), entry.size, entry.lba);
        }
    }
}

int main(int argc, char* argv[]) {
    printf("\n  reo-extract — RE Outbreak ISO Extractor & ELF Analyzer\n\n");

    if (argc < 2) {
        printf("Usage: reo-extract <path-to-iso> [output-dir]\n");
        printf("\n");
        printf("  Extracts game files from an RE Outbreak ISO and analyzes\n");
        printf("  the main ELF executable for static recompilation.\n");
        printf("\n");
        printf("  Default output directory: game_data/\n");
        return 1;
    }

    std::string iso_path = argv[1];
    std::string output_dir = (argc >= 3) ? argv[2] : "game_data";

    // Open ISO
    reo::Iso9660 iso;
    if (!iso.open(iso_path)) {
        fprintf(stderr, "Failed to open ISO: %s\n", iso_path.c_str());
        return 1;
    }

    // Print directory listing
    printf("\nISO Directory Listing:\n");
    printf("======================\n");
    print_directory(iso.root());
    printf("\n");

    // Find and read SYSTEM.CNF
    auto* system_cnf = iso.find("SYSTEM.CNF");
    if (system_cnf) {
        std::vector<uint8_t> cnf_data;
        iso.read_file(*system_cnf, cnf_data);
        cnf_data.push_back(0); // Null terminate

        printf("SYSTEM.CNF:\n");
        printf("  %s\n", (char*)cnf_data.data());

        // Parse BOOT2 line to find ELF path
        const char* boot2 = strstr((char*)cnf_data.data(), "BOOT2");
        if (boot2) {
            // Find the filename after '=' and any path prefix
            const char* eq = strchr(boot2, '=');
            if (eq) {
                eq++; // Skip '='
                while (*eq == ' ')
                    eq++; // Skip whitespace

                // Extract the filename (strip cdrom0:\ prefix)
                std::string elf_path = eq;
                // Trim newlines
                auto nl = elf_path.find_first_of("\r\n");
                if (nl != std::string::npos)
                    elf_path = elf_path.substr(0, nl);

                printf("  Boot ELF: %s\n\n", elf_path.c_str());

                // Strip cdrom prefix to get ISO path
                std::string iso_elf_path = elf_path;
                auto pos = iso_elf_path.find(":\\");
                if (pos != std::string::npos) {
                    iso_elf_path = iso_elf_path.substr(pos + 2);
                }
                // Strip version suffix (;1)
                auto semi = iso_elf_path.find(';');
                if (semi != std::string::npos) {
                    iso_elf_path = iso_elf_path.substr(0, semi);
                }
                // Replace backslash with forward slash
                for (auto& c : iso_elf_path) {
                    if (c == '\\')
                        c = '/';
                }
                // Try finding the ELF in the ISO
                auto* elf_entry = iso.find(iso_elf_path);
                if (!elf_entry) {
                    // Try with underscores replaced by dots
                    std::string alt = iso_elf_path;
                    for (auto& c : alt) {
                        if (c == '_')
                            c = '.';
                    }
                    elf_entry = iso.find(alt);
                }
                if (!elf_entry) {
                    // Try with dots replaced by underscores
                    std::string alt = iso_elf_path;
                    for (auto& c : alt) {
                        if (c == '.')
                            c = '_';
                    }
                    elf_entry = iso.find(alt);
                }

                if (elf_entry) {
                    std::vector<uint8_t> elf_data;
                    iso.read_file(*elf_entry, elf_data);
                    analyze_elf(elf_data, elf_entry->name);
                } else {
                    fprintf(stderr, "Could not find ELF: %s\n", iso_elf_path.c_str());
                }
            }
        }
    } else {
        printf("Warning: SYSTEM.CNF not found in ISO\n");
    }

    // Extract all files
    printf("Extracting all files to: %s\n", output_dir.c_str());
    iso.extract_all(output_dir);

    printf("\nExtraction complete!\n");
    printf("Next steps:\n");
    printf("  1. Run ps2xAnalyzer on the ELF to generate recompilation config\n");
    printf("  2. Run ps2xRecomp to generate C++ source from MIPS code\n");
    printf("  3. Build with the REO runtime to produce native executable\n");

    return 0;
}
