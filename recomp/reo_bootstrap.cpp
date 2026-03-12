/*
 * REO Bootstrap — Main entry point for running recompiled RE Outbreak
 *
 * Supports both games:
 *   - RE Outbreak File #1 (SLUS-20765): 3,209 recompiled functions
 *   - RE Outbreak File #2 (SLUS-20984): 3,525 recompiled functions
 *
 * Build: compile all generated .cpp files + this bootstrap against
 *        PS2Recomp's runtime library.
 *
 * Usage:
 *   reo_recomp --game file1   (or --game file2)
 *   reo_recomp --elf <path> --data <path>   (manual override)
 */

#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "game_overrides.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

// Function registration — defined in each game's generated register_functions.cpp
// The active build target (file1 or file2) provides the implementation.
extern void registerAllFunctions(PS2Runtime& runtime);

// Overlay function registration — runtime-loaded code dumped from PCSX2
extern void registerOverlayFunctions(PS2Runtime& runtime);

struct GameDef {
    const char* name;
    const char* elf_name;
    const char* serial;
    const char* default_data;
    uint32_t entry_point;
};

static const GameDef s_games[] = {
    { "Resident Evil Outbreak",          "SLUS_207.65", "SLUS-20765", "game_data",       0x00100008 },
    { "Resident Evil Outbreak: File #2", "SLUS_209.84", "SLUS-20984", "game_data_file2", 0x00100008 },
};

static void print_banner(const GameDef& g) {
    printf("\n");
    printf("  ██████╗ ███████╗ ██████╗ \n");
    printf("  ██╔══██╗██╔════╝██╔═══██╗\n");
    printf("  ██████╔╝█████╗  ██║   ██║\n");
    printf("  ██╔══██╗██╔══╝  ██║   ██║\n");
    printf("  ██║  ██║███████╗╚██████╔╝\n");
    printf("  ╚═╝  ╚═╝╚══════╝ ╚═════╝ \n");
    printf("\n");
    printf("  %s: Recompiled\n", g.name);
    printf("  [%s]  Static recompilation — no emulator\n", g.serial);
    printf("  Don't let the memory of Raccoon City die.\n");
    printf("\n");
}

int main(int argc, char* argv[]) {
    // Defaults — selected game determines paths
    int game_idx = -1;  // -1 = auto-detect from build target
    std::string elf_path;
    std::string game_data;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--game") == 0 && i + 1 < argc) {
            const char* g = argv[++i];
            if (strcmp(g, "file1") == 0 || strcmp(g, "outbreak") == 0 || strcmp(g, "1") == 0)
                game_idx = 0;
            else if (strcmp(g, "file2") == 0 || strcmp(g, "2") == 0)
                game_idx = 1;
            else {
                fprintf(stderr, "[REO] Unknown game: %s (use 'file1' or 'file2')\n", g);
                return 1;
            }
        } else if (strcmp(argv[i], "--elf") == 0 && i + 1 < argc) {
            elf_path = argv[++i];
        } else if (strcmp(argv[i], "--data") == 0 && i + 1 < argc) {
            game_data = argv[++i];
        } else if (strcmp(argv[i], "--help") == 0) {
            printf("Usage: reo_recomp [--game file1|file2] [--elf <path>] [--data <path>]\n");
            printf("  --game   Which game to run: file1 or file2 (auto-detected if not set)\n");
            printf("  --elf    Path to game ELF (default: auto from game selection)\n");
            printf("  --data   Path to extracted game data (default: auto from game selection)\n");
            return 0;
        }
    }

    // Auto-detect game from build target (compile-time define)
#if defined(REO_GAME_FILE2)
    if (game_idx < 0) game_idx = 1;
#else
    if (game_idx < 0) game_idx = 0;
#endif

    const GameDef& g = s_games[game_idx];
    print_banner(g);

    // Resolve paths
    if (game_data.empty()) game_data = g.default_data;
    if (elf_path.empty())  elf_path = std::string(game_data) + "/" + g.elf_name;

    if (!fs::exists(elf_path)) {
        fprintf(stderr, "[REO] ELF not found: %s\n", elf_path.c_str());
        fprintf(stderr, "[REO] Run: reo-extract <ISO> %s\n", g.default_data);
        return 1;
    }

    printf("[BOOT] ELF: %s\n", elf_path.c_str());
    printf("[BOOT] Game data: %s\n", game_data.c_str());

    // Initialize the PS2Recomp runtime
    printf("[BOOT] Initializing PS2 runtime...\n");
    PS2Runtime runtime;

    if (!runtime.initialize(g.name)) {
        fprintf(stderr, "[BOOT] Failed to initialize runtime\n");
        return 1;
    }

    // Configure I/O paths
    PS2Runtime::IoPaths paths;
    paths.elfPath = elf_path;
    paths.elfDirectory = fs::path(elf_path).parent_path();
    paths.hostRoot = game_data;
    paths.cdRoot = game_data;
    paths.mcRoot = "saves";
    PS2Runtime::setIoPaths(paths);

    fs::create_directories("saves");

    // Load the ELF into guest memory
    printf("[BOOT] Loading ELF into guest memory...\n");
    if (!runtime.loadELF(elf_path)) {
        fprintf(stderr, "[BOOT] Failed to load ELF: %s\n", elf_path.c_str());
        return 1;
    }

    // Register all recompiled functions
    printf("[BOOT] Registering recompiled functions...\n");
    registerAllFunctions(runtime);
    printf("[BOOT] Registering overlay functions (runtime-loaded code)...\n");
    registerOverlayFunctions(runtime);
    printf("[BOOT] All functions registered.\n");

    // Re-apply game overrides AFTER function registration.
    // loadELF() applies them first, but registerAllFunctions() overwrites
    // our custom handlers with the generated stubs. This second pass ensures
    // our overrides take precedence over generated code.
    printf("[BOOT] Applying game overrides (post-registration)...\n");
    ps2_game_overrides::applyMatching(runtime, elf_path, g.entry_point);

    // Begin execution
    printf("[BOOT] Starting execution at entry point 0x%08X...\n", g.entry_point);
    printf("[BOOT] ========================================\n\n");

    runtime.run();

    printf("\n[BOOT] ========================================\n");
    printf("[BOOT] Execution ended.\n");

    return 0;
}
