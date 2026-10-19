/*
 * reo-elfinfo — Standalone ELF analyzer for PS2 executables
 *
 * Reads a PS2 ELF binary and prints detailed information about:
 * - Entry point, segment layout
 * - Section headers (looking for debug symbols, .mdebug, etc.)
 * - Symbol table dump (if present)
 * - Function boundary detection heuristics
 * - Memory map analysis
 *
 * Usage: reo-elfinfo <path-to-elf>
 */

#include <cstdio>
#include <cstring>
#include <cstdint>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

struct Elf32Header {
    uint8_t magic[4];
    uint8_t ei_class;
    uint8_t ei_data;
    uint8_t ei_version;
    uint8_t ei_osabi;
    uint8_t padding[8];
    uint16_t type;
    uint16_t machine;
    uint32_t version;
    uint32_t entry;
    uint32_t phoff;
    uint32_t shoff;
    uint32_t flags;
    uint16_t ehsize;
    uint16_t phentsize;
    uint16_t phnum;
    uint16_t shentsize;
    uint16_t shnum;
    uint16_t shstrndx;
};

struct Elf32Symbol {
    uint32_t name;
    uint32_t value;
    uint32_t size;
    uint8_t info;
    uint8_t other;
    uint16_t shndx;
};

struct Elf32SectionHeader {
    uint32_t name;
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

static int count_functions_heuristic(const uint8_t* code, uint32_t size) {
    // MIPS function prologue heuristic:
    // Look for "addiu $sp, $sp, -N" (stack frame allocation)
    // Encoding: 0x27BDxxxx where xxxx is negative offset
    int count = 0;
    for (uint32_t i = 0; i + 4 <= size; i += 4) {
        uint32_t inst = *(uint32_t*)(code + i);
        if ((inst & 0xFFFF0000) == 0x27BD0000) {
            int16_t offset = (int16_t)(inst & 0xFFFF);
            if (offset < 0) { // Stack allocation (negative = growing down)
                count++;
            }
        }
    }
    return count;
}

int main(int argc, char* argv[]) {
    printf("\n  reo-elfinfo — PS2 ELF Analyzer\n\n");

    if (argc < 2) {
        printf("Usage: reo-elfinfo <path-to-elf>\n");
        return 1;
    }

    std::ifstream file(argv[1], std::ios::binary | std::ios::ate);
    if (!file) {
        fprintf(stderr, "Failed to open: %s\n", argv[1]);
        return 1;
    }

    auto fsize = file.tellg();
    file.seekg(0);
    std::vector<uint8_t> data((size_t)fsize);
    file.read((char*)data.data(), fsize);

    if (data.size() < sizeof(Elf32Header)) {
        fprintf(stderr, "File too small for ELF header\n");
        return 1;
    }

    const Elf32Header* hdr = (const Elf32Header*)data.data();

    if (hdr->magic[0] != 0x7F || hdr->magic[1] != 'E' || hdr->magic[2] != 'L' ||
        hdr->magic[3] != 'F') {
        fprintf(stderr, "Not a valid ELF file\n");
        return 1;
    }

    printf("File:        %s\n", argv[1]);
    printf("Size:        %llu bytes (%.1f MB)\n", (unsigned long long)fsize,
           (double)fsize / 1048576.0);
    printf("Machine:     0x%04X\n", hdr->machine);
    printf("Entry:       0x%08X\n", hdr->entry);
    printf("Segments:    %d\n", hdr->phnum);
    printf("Sections:    %d\n", hdr->shnum);
    printf("\n");

    // Count functions via heuristic (across all executable segments)
    printf("Scanning for function prologues...\n");

    // Find executable LOAD segments
    for (int i = 0; i < hdr->phnum; i++) {
        uint32_t ph_off = hdr->phoff + i * hdr->phentsize;
        if (ph_off + 32 > data.size())
            break;

        uint32_t type = *(uint32_t*)(data.data() + ph_off);
        uint32_t offset = *(uint32_t*)(data.data() + ph_off + 4);
        uint32_t vaddr = *(uint32_t*)(data.data() + ph_off + 8);
        uint32_t filesz = *(uint32_t*)(data.data() + ph_off + 16);
        uint32_t flags = *(uint32_t*)(data.data() + ph_off + 24);

        if (type == 1 && (flags & 1)) { // PT_LOAD + PF_X
            if (offset + filesz <= data.size()) {
                int funcs = count_functions_heuristic(data.data() + offset, filesz);
                printf("  Segment at 0x%08X: ~%d functions (%.1f MB code)\n", vaddr, funcs,
                       filesz / 1048576.0);
            }
        }
    }

    // Check for symbol table
    if (hdr->shnum > 0 && hdr->shoff > 0) {
        // Get string table
        const char* strtab = nullptr;
        if (hdr->shstrndx < hdr->shnum) {
            uint32_t strtab_off = hdr->shoff + hdr->shstrndx * hdr->shentsize;
            if (strtab_off + sizeof(Elf32SectionHeader) <= data.size()) {
                const Elf32SectionHeader* stsh =
                    (const Elf32SectionHeader*)(data.data() + strtab_off);
                if (stsh->offset + stsh->size <= data.size()) {
                    strtab = (const char*)(data.data() + stsh->offset);
                }
            }
        }

        for (int i = 0; i < hdr->shnum; i++) {
            uint32_t sh_off = hdr->shoff + i * hdr->shentsize;
            if (sh_off + sizeof(Elf32SectionHeader) > data.size())
                break;

            const Elf32SectionHeader* sh = (const Elf32SectionHeader*)(data.data() + sh_off);

            if (sh->type == 2) { // SHT_SYMTAB
                printf("\nSymbol table found! (%u bytes)\n", sh->size);

                // Get symbol string table (linked section)
                const char* sym_strtab = nullptr;
                if (sh->link < hdr->shnum) {
                    uint32_t link_off = hdr->shoff + sh->link * hdr->shentsize;
                    if (link_off + sizeof(Elf32SectionHeader) <= data.size()) {
                        const Elf32SectionHeader* link_sh =
                            (const Elf32SectionHeader*)(data.data() + link_off);
                        if (link_sh->offset + link_sh->size <= data.size()) {
                            sym_strtab = (const char*)(data.data() + link_sh->offset);
                        }
                    }
                }

                if (sym_strtab && sh->entsize == sizeof(Elf32Symbol)) {
                    uint32_t num_syms = sh->size / sh->entsize;
                    int func_count = 0;

                    printf("  %u symbols total\n", num_syms);

                    // Count and list function symbols
                    for (uint32_t j = 0; j < num_syms; j++) {
                        uint32_t sym_off = sh->offset + j * sizeof(Elf32Symbol);
                        if (sym_off + sizeof(Elf32Symbol) > data.size())
                            break;

                        const Elf32Symbol* sym = (const Elf32Symbol*)(data.data() + sym_off);

                        uint8_t type = sym->info & 0x0F;
                        if (type == 2) { // STT_FUNC
                            func_count++;
                            if (func_count <= 20) { // Print first 20
                                printf("    FUNC 0x%08X size=%u %s\n", sym->value, sym->size,
                                       sym_strtab + sym->name);
                            }
                        }
                    }

                    if (func_count > 20) {
                        printf("    ... and %d more functions\n", func_count - 20);
                    }
                    printf("  Total functions with symbols: %d\n", func_count);
                }
            }
        }
    }

    printf("\nAnalysis complete.\n");
    return 0;
}
