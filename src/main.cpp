// REO native runtime scaffold.
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <filesystem>

#ifdef _WIN32
#include <windows.h>
#endif

#include "config.h"
#include "runtime/core/context.h"
#include "runtime/core/memory.h"
#include "runtime/core/syscall.h"
#include "runtime/gs/gs_renderer.h"
#include "runtime/spu2/spu2.h"
#include "runtime/vu/vu_interpreter.h"
#include "runtime/input/input.h"
#include "runtime/cdvd/cdvd.h"
#include "runtime/timer/timer.h"
#include "runtime/iop/iop_hle.h"
#include "network/snap_client/snap_protocol.h"
#include "network/dnas/dnas_bypass.h"

namespace fs = std::filesystem;

static void print_banner(const reo::GameInfo& info) {
    printf("\n");
    printf("  ██████╗ ███████╗ ██████╗ \n");
    printf("  ██╔══██╗██╔════╝██╔═══██╗\n");
    printf("  ██████╔╝█████╗  ██║   ██║\n");
    printf("  ██╔══██╗██╔══╝  ██║   ██║\n");
    printf("  ██║  ██║███████╗╚██████╔╝\n");
    printf("  ╚═╝  ╚═╝╚══════╝ ╚═════╝ \n");
    printf("\n");
    printf("  %s: Recompiled\n", info.display_name);
    printf("  v%s  [%s]\n", REO_VERSION_STRING, info.serial);
    printf("  Don't let the memory of Raccoon City die.\n");
    printf("\n");
}

int main(int argc, char* argv[]) {
    // Load configuration (includes game selection)
    reo::Config config;
    if (!config.load(argc, argv)) {
        return 1;
    }

    const auto& info = config.game_info();
    print_banner(info);

    // Verify game data exists
    fs::path game_data_path = config.game_data_path;
    if (!fs::exists(game_data_path)) {
        fprintf(stderr, "Game data not found at: %s\n", game_data_path.string().c_str());
        fprintf(stderr, "Run: reo-extract <path-to-ISO> %s\n", info.default_data_path);
        return 1;
    }

    // Verify ELF exists
    fs::path elf_path = game_data_path / info.elf_name;
    if (!fs::exists(elf_path)) {
        fprintf(stderr, "ELF not found: %s\n", elf_path.string().c_str());
        return 1;
    }

    printf("[BOOT] Game: %s (%s)\n", info.display_name, info.serial);
    printf("[BOOT] ELF:  %s (entry 0x%08X)\n", info.elf_name, info.entry_point);
    printf("[BOOT] Data: %s\n", game_data_path.string().c_str());
    printf("[BOOT] Initializing PS2 subsystems...\n");

    // Initialize the PS2 memory map (32MB main RAM + MMIO regions)
    reo::Memory memory;
    if (!memory.init()) {
        fprintf(stderr, "[BOOT] Failed to initialize memory subsystem.\n");
        return 1;
    }
    printf("[BOOT] Memory: 32MB main RAM mapped\n");

    // Initialize the EE CPU context (register file, PC, etc.)
    reo::EEContext cpu(memory);
    printf("[BOOT] EE CPU context ready (MIPS R5900 → x86-64)\n");

    // Initialize the Graphics Synthesizer replacement
    reo::GSRenderer gs;
    if (!gs.init(config.window_width, config.window_height, config.fullscreen)) {
        fprintf(stderr, "[BOOT] Failed to initialize GS renderer.\n");
        return 1;
    }
    printf("[BOOT] GS Renderer: %s (%dx%d)\n", gs.backend_name(), config.window_width,
           config.window_height);

    // Initialize SPU2 audio
    reo::SPU2 spu2;
    if (!spu2.init()) {
        fprintf(stderr, "[BOOT] Failed to initialize SPU2 audio.\n");
        return 1;
    }
    printf("[BOOT] SPU2: 48 voices, software mixer → WASAPI\n");

    // Initialize input system
    reo::Input input;
    if (!input.init()) {
        fprintf(stderr, "[BOOT] Failed to initialize input system.\n");
        return 1;
    }
    printf("[BOOT] Input: XInput + keyboard mapped\n");

    // Initialize CDVD (file system redirect)
    reo::CDVD cdvd(game_data_path);
    printf("[BOOT] CDVD: Redirected to %s\n", game_data_path.string().c_str());

    // Initialize IOP high-level emulation and wire subsystems
    reo::IopHLE iop(memory);
    iop.set_input(&input);
    iop.set_spu2(&spu2);
    iop.set_cdvd(&cdvd);
    printf("[BOOT] IOP: HLE ready (padman→Input, cdvd→CDVD, libsd→SPU2)\n");

    // Initialize timer system
    reo::Timer timer;
    timer.init();
    printf("[BOOT] Timer: High-resolution Windows timers\n");

    // Network (if online mode enabled)
    if (config.online_enabled) {
        printf("[BOOT] Network: Initializing online subsystem...\n");
        reo::DnasBypass::apply();
        printf("[BOOT] DNAS: Bypassed (connecting to community servers)\n");

        reo::SnapProtocol snap;
        if (snap.connect(config.server_address, config.server_port)) {
            printf("[BOOT] Connected to %s:%d\n", config.server_address.c_str(),
                   config.server_port);
        } else {
            printf("[BOOT] Network: Could not connect (offline mode)\n");
        }
    }

    // Initialize VU interpreters (for microprograms uploaded by the game)
    reo::VUInterpreter vu0(0, memory.vu0_code(), 4096, memory.vu0_data(), 4096);
    reo::VUInterpreter vu1(1, memory.vu1_code(), 16384, memory.vu1_data(), 16384);

    // Wire VU1 XGKICK → GS PATH1 (geometry submission pipeline)
    vu1.set_xgkick_callback(
        [](const void* data, uint32_t max_size, void* user) {
            auto* gs_ptr = (reo::GSRenderer*)user;
            gs_ptr->submit_path1(data, max_size);
        },
        &gs);
    printf("[BOOT] VU0/VU1: Interpreter mode ready (VU1→GS PATH1 wired)\n");

    // Initialize kernel thread/semaphore system
    reo::get_kernel().init();
    printf("[BOOT] EE Kernel: Thread scheduler + semaphores\n");

    printf("\n[BOOT] All subsystems initialized. Loading game...\n\n");

    // Load ELF into guest memory
    {
        FILE* f = fopen(elf_path.string().c_str(), "rb");
        if (!f) {
            fprintf(stderr, "[BOOT] Failed to open ELF: %s\n", elf_path.string().c_str());
            return 1;
        }

        fseek(f, 0, SEEK_END);
        long elf_size = ftell(f);
        fseek(f, 0, SEEK_SET);

        if (elf_size <= 0 || elf_size > (long)reo::EE_MAIN_RAM_SIZE) {
            fprintf(stderr, "[BOOT] Invalid ELF size: %ld\n", elf_size);
            fclose(f);
            return 1;
        }

        // Read ELF header to find load address
        uint8_t ehdr[64];
        fread(ehdr, 1, 64, f);

        // Verify ELF magic
        if (ehdr[0] != 0x7F || ehdr[1] != 'E' || ehdr[2] != 'L' || ehdr[3] != 'F') {
            fprintf(stderr, "[BOOT] Not a valid ELF file\n");
            fclose(f);
            return 1;
        }

        // Parse ELF32 program headers to load segments into guest memory
        uint32_t phoff = *(uint32_t*)(ehdr + 28);     // e_phoff
        uint16_t phnum = *(uint16_t*)(ehdr + 44);     // e_phnum
        uint16_t phentsize = *(uint16_t*)(ehdr + 42); // e_phentsize

        printf("[BOOT] ELF: %d program headers at offset 0x%X\n", phnum, phoff);

        for (int i = 0; i < phnum; i++) {
            uint8_t phdr[32];
            fseek(f, phoff + i * phentsize, SEEK_SET);
            fread(phdr, 1, 32, f);

            uint32_t p_type = *(uint32_t*)(phdr + 0);
            uint32_t p_offset = *(uint32_t*)(phdr + 4);
            uint32_t p_vaddr = *(uint32_t*)(phdr + 8);
            uint32_t p_filesz = *(uint32_t*)(phdr + 16);
            uint32_t p_memsz = *(uint32_t*)(phdr + 20);

            if (p_type != 1)
                continue; // PT_LOAD only

            uint8_t* dest = memory.get_pointer(p_vaddr);
            if (!dest) {
                printf("[BOOT] ELF: Segment at 0x%08X cannot be mapped\n", p_vaddr);
                continue;
            }

            // Clear BSS region
            if (p_memsz > p_filesz) {
                memset(dest + p_filesz, 0, p_memsz - p_filesz);
            }

            // Load file data
            fseek(f, p_offset, SEEK_SET);
            size_t read = fread(dest, 1, p_filesz, f);

            printf("[BOOT] ELF: LOAD 0x%08X - 0x%08X (%u bytes from file, %u in memory)\n", p_vaddr,
                   p_vaddr + p_memsz, p_filesz, p_memsz);
        }

        fclose(f);
    }

    // Set up EE CPU entry point
    cpu.pc = info.entry_point;
    cpu.gpr[29].set32(0x01FFFF00); // $sp — top of main RAM (with some margin)
    cpu.gpr[28].set32(0x00100000); // $gp — typical for PS2 executables

    printf("[BOOT] EE entry point: 0x%08X\n", cpu.pc);
    printf("[BOOT] Starting game execution...\n\n");

    // Main game loop
    bool running = true;
    uint32_t frame_count = 0;

    // Audio buffer (mixed per frame: 48kHz / 60fps = 800 samples/frame)
    constexpr int AUDIO_SAMPLES_PER_FRAME = 800;
    int16_t audio_buffer[AUDIO_SAMPLES_PER_FRAME * 2]; // stereo

    while (running) {
        timer.begin_frame();

        // 1. Poll input
        input.update();

        // Write pad state to the memory location the game reads from
        // (the IOP HLE padman handler will provide this via SIF RPC)
        const auto& pad = input.get_pad(0);

        // 2. Execute recompiled EE code
        // The recompiled code is linked separately in reo_recomp/reo_recomp_file2.
        // Here in the HAL runtime, we execute the entry point and dispatch
        // syscalls. The recompiled executable drives the game logic.
        //
        // For now, we signal one frame worth of execution:
        //   - Set vsync flag (so game's main loop processes one iteration)
        //   - Process any pending kernel thread scheduling

        // Signal vsync to the game
        auto& kern = reo::get_kernel();
        if (kern.vsync_flag_addr1) {
            memory.write32(kern.vsync_flag_addr1, frame_count);
        }
        if (kern.vsync_flag_addr2) {
            memory.write32(kern.vsync_flag_addr2, 1); // vsync occurred
        }

        // 3. Process VU microprograms
        // VU1 programs are submitted by the game and run asynchronously.
        // If VU1 was started (by the recompiled code writing to VIF1),
        // execute it now.
        if (vu1.is_running()) {
            vu1.run(65536);
        }

        // 4. GS rendering
        gs.begin_frame();
        // Geometry submission happens via VU1 XGKICK → PATH1,
        // or via GIF DMA → PATH3. The GS renderer accumulates draw
        // calls during the frame and renders them here.
        gs.end_frame();
        gs.present();

        // 5. Mix SPU2 audio
        spu2.process_keys();
        spu2.mix_samples(audio_buffer, AUDIO_SAMPLES_PER_FRAME);

        // 6. Handle network events
        // (handled by the snap protocol client if online)

        // 7. Frame timing / vsync
        timer.end_frame();
        timer.wait_for_vsync(60);

        frame_count++;

        // Print status periodically
        if (frame_count % 300 == 0) {
            printf("[MAIN] Frame %u | %.1f FPS | %.2f ms/frame\n", frame_count, timer.fps(),
                   timer.frame_time_ms());
        }

        // Check for exit condition (ESC key via GetAsyncKeyState)
#ifdef _WIN32
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            printf("[MAIN] ESC pressed — shutting down\n");
            running = false;
        }
#endif
    }

    printf("\n[MAIN] Exiting after %u frames\n", frame_count);

    // Cleanup
    spu2.shutdown();
    gs.shutdown();
    input.shutdown();

    return 0;
}
