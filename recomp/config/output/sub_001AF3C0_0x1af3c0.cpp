#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AF3C0
// Address: 0x1af3c0 - 0x1af490
void sub_001AF3C0_0x1af3c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AF3C0_0x1af3c0");
#endif

    switch (ctx->pc) {
        case 0x1af3d4u: goto label_1af3d4;
        case 0x1af3e4u: goto label_1af3e4;
        case 0x1af3ecu: goto label_1af3ec;
        case 0x1af3f4u: goto label_1af3f4;
        case 0x1af3fcu: goto label_1af3fc;
        case 0x1af404u: goto label_1af404;
        case 0x1af40cu: goto label_1af40c;
        case 0x1af418u: goto label_1af418;
        case 0x1af428u: goto label_1af428;
        case 0x1af434u: goto label_1af434;
        case 0x1af444u: goto label_1af444;
        case 0x1af44cu: goto label_1af44c;
        case 0x1af454u: goto label_1af454;
        case 0x1af45cu: goto label_1af45c;
        case 0x1af464u: goto label_1af464;
        case 0x1af46cu: goto label_1af46c;
        case 0x1af474u: goto label_1af474;
        case 0x1af47cu: goto label_1af47c;
        case 0x1af484u: goto label_1af484;
        default: break;
    }

    ctx->pc = 0x1af3c0u;

    // 0x1af3c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1af3c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1af3c4: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1af3c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1af3c8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1af3c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1af3cc: 0xc06a5d4  jal         func_1A9750
    ctx->pc = 0x1AF3CCu;
    SET_GPR_U32(ctx, 31, 0x1AF3D4u);
    ctx->pc = 0x1AF3D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF3CCu;
            // 0x1af3d0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A9750u;
    if (runtime->hasFunction(0x1A9750u)) {
        auto targetFn = runtime->lookupFunction(0x1A9750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF3D4u; }
        if (ctx->pc != 0x1AF3D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A9750_0x1a9750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF3D4u; }
        if (ctx->pc != 0x1AF3D4u) { return; }
    }
    ctx->pc = 0x1AF3D4u;
label_1af3d4:
    // 0x1af3d4: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1AF3D4u;
    {
        const bool branch_taken_0x1af3d4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AF3D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF3D4u;
            // 0x1af3d8: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1af3d4) {
            ctx->pc = 0x1AF3ECu;
            goto label_1af3ec;
        }
    }
    ctx->pc = 0x1AF3DCu;
    // 0x1af3dc: 0xc17af1c  jal         func_5EBC70
    ctx->pc = 0x1AF3DCu;
    SET_GPR_U32(ctx, 31, 0x1AF3E4u);
    ctx->pc = 0x1AF3E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF3DCu;
            // 0x1af3e0: 0x2405ffff  addiu       $a1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x5EBC70u;
    {
        auto targetFn = runtime->lookupFunction(0x5EBC70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF3E4u; }
        if (ctx->pc != 0x1AF3E4u) { return; }
    }
    ctx->pc = 0x1AF3E4u;
label_1af3e4:
    // 0x1af3e4: 0xc073df8  jal         func_1CF7E0
    ctx->pc = 0x1AF3E4u;
    SET_GPR_U32(ctx, 31, 0x1AF3ECu);
    ctx->pc = 0x1CF7E0u;
    if (runtime->hasFunction(0x1CF7E0u)) {
        auto targetFn = runtime->lookupFunction(0x1CF7E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF3ECu; }
        if (ctx->pc != 0x1AF3ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CF7E0_0x1cf7e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF3ECu; }
        if (ctx->pc != 0x1AF3ECu) { return; }
    }
    ctx->pc = 0x1AF3ECu;
label_1af3ec:
    // 0x1af3ec: 0xc07326c  jal         func_1CC9B0
    ctx->pc = 0x1AF3ECu;
    SET_GPR_U32(ctx, 31, 0x1AF3F4u);
    ctx->pc = 0x1CC9B0u;
    if (runtime->hasFunction(0x1CC9B0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC9B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF3F4u; }
        if (ctx->pc != 0x1AF3F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC9B0_0x1cc9b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF3F4u; }
        if (ctx->pc != 0x1AF3F4u) { return; }
    }
    ctx->pc = 0x1AF3F4u;
label_1af3f4:
    // 0x1af3f4: 0xc06c63c  jal         func_1B18F0
    ctx->pc = 0x1AF3F4u;
    SET_GPR_U32(ctx, 31, 0x1AF3FCu);
    ctx->pc = 0x1B18F0u;
    if (runtime->hasFunction(0x1B18F0u)) {
        auto targetFn = runtime->lookupFunction(0x1B18F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF3FCu; }
        if (ctx->pc != 0x1AF3FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B18F0_0x1b18f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF3FCu; }
        if (ctx->pc != 0x1AF3FCu) { return; }
    }
    ctx->pc = 0x1AF3FCu;
label_1af3fc:
    // 0x1af3fc: 0xc06c838  jal         func_1B20E0
    ctx->pc = 0x1AF3FCu;
    SET_GPR_U32(ctx, 31, 0x1AF404u);
    ctx->pc = 0x1B20E0u;
    if (runtime->hasFunction(0x1B20E0u)) {
        auto targetFn = runtime->lookupFunction(0x1B20E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF404u; }
        if (ctx->pc != 0x1AF404u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B20E0_0x1b20e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF404u; }
        if (ctx->pc != 0x1AF404u) { return; }
    }
    ctx->pc = 0x1AF404u;
label_1af404:
    // 0x1af404: 0xc06c65c  jal         func_1B1970
    ctx->pc = 0x1AF404u;
    SET_GPR_U32(ctx, 31, 0x1AF40Cu);
    ctx->pc = 0x1B1970u;
    if (runtime->hasFunction(0x1B1970u)) {
        auto targetFn = runtime->lookupFunction(0x1B1970u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF40Cu; }
        if (ctx->pc != 0x1AF40Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1970_0x1b1970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF40Cu; }
        if (ctx->pc != 0x1AF40Cu) { return; }
    }
    ctx->pc = 0x1AF40Cu;
label_1af40c:
    // 0x1af40c: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1af40cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1af410: 0xc06a5d4  jal         func_1A9750
    ctx->pc = 0x1AF410u;
    SET_GPR_U32(ctx, 31, 0x1AF418u);
    ctx->pc = 0x1AF414u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF410u;
            // 0x1af414: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A9750u;
    if (runtime->hasFunction(0x1A9750u)) {
        auto targetFn = runtime->lookupFunction(0x1A9750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF418u; }
        if (ctx->pc != 0x1AF418u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A9750_0x1a9750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF418u; }
        if (ctx->pc != 0x1AF418u) { return; }
    }
    ctx->pc = 0x1AF418u;
label_1af418:
    // 0x1af418: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1AF418u;
    {
        const bool branch_taken_0x1af418 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AF41Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF418u;
            // 0x1af41c: 0x24040003  addiu       $a0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1af418) {
            ctx->pc = 0x1AF42Cu;
            goto label_1af42c;
        }
    }
    ctx->pc = 0x1AF420u;
    // 0x1af420: 0xc17ab74  jal         func_5EADD0
    ctx->pc = 0x1AF420u;
    SET_GPR_U32(ctx, 31, 0x1AF428u);
    ctx->pc = 0x5EADD0u;
    {
        auto targetFn = runtime->lookupFunction(0x5EADD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF428u; }
        if (ctx->pc != 0x1AF428u) { return; }
    }
    ctx->pc = 0x1AF428u;
label_1af428:
    // 0x1af428: 0x24040003  addiu       $a0, $zero, 0x3
    ctx->pc = 0x1af428u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
label_1af42c:
    // 0x1af42c: 0xc06a5d4  jal         func_1A9750
    ctx->pc = 0x1AF42Cu;
    SET_GPR_U32(ctx, 31, 0x1AF434u);
    ctx->pc = 0x1AF430u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF42Cu;
            // 0x1af430: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A9750u;
    if (runtime->hasFunction(0x1A9750u)) {
        auto targetFn = runtime->lookupFunction(0x1A9750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF434u; }
        if (ctx->pc != 0x1AF434u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A9750_0x1a9750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF434u; }
        if (ctx->pc != 0x1AF434u) { return; }
    }
    ctx->pc = 0x1AF434u;
label_1af434:
    // 0x1af434: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AF434u;
    {
        const bool branch_taken_0x1af434 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1af434) {
            ctx->pc = 0x1AF444u;
            goto label_1af444;
        }
    }
    ctx->pc = 0x1AF43Cu;
    // 0x1af43c: 0xc15d6a0  jal         func_575A80
    ctx->pc = 0x1AF43Cu;
    SET_GPR_U32(ctx, 31, 0x1AF444u);
    ctx->pc = 0x575A80u;
    {
        auto targetFn = runtime->lookupFunction(0x575A80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF444u; }
        if (ctx->pc != 0x1AF444u) { return; }
    }
    ctx->pc = 0x1AF444u;
label_1af444:
    // 0x1af444: 0xc06b3dc  jal         func_1ACF70
    ctx->pc = 0x1AF444u;
    SET_GPR_U32(ctx, 31, 0x1AF44Cu);
    ctx->pc = 0x1ACF70u;
    if (runtime->hasFunction(0x1ACF70u)) {
        auto targetFn = runtime->lookupFunction(0x1ACF70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF44Cu; }
        if (ctx->pc != 0x1AF44Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ACF70_0x1acf70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF44Cu; }
        if (ctx->pc != 0x1AF44Cu) { return; }
    }
    ctx->pc = 0x1AF44Cu;
label_1af44c:
    // 0x1af44c: 0xc06b878  jal         func_1AE1E0
    ctx->pc = 0x1AF44Cu;
    SET_GPR_U32(ctx, 31, 0x1AF454u);
    ctx->pc = 0x1AE1E0u;
    if (runtime->hasFunction(0x1AE1E0u)) {
        auto targetFn = runtime->lookupFunction(0x1AE1E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF454u; }
        if (ctx->pc != 0x1AF454u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AE1E0_0x1ae1e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF454u; }
        if (ctx->pc != 0x1AF454u) { return; }
    }
    ctx->pc = 0x1AF454u;
label_1af454:
    // 0x1af454: 0xc0dc678  jal         func_3719E0
    ctx->pc = 0x1AF454u;
    SET_GPR_U32(ctx, 31, 0x1AF45Cu);
    ctx->pc = 0x3719E0u;
    {
        auto targetFn = runtime->lookupFunction(0x3719E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF45Cu; }
        if (ctx->pc != 0x1AF45Cu) { return; }
    }
    ctx->pc = 0x1AF45Cu;
label_1af45c:
    // 0x1af45c: 0xc07326c  jal         func_1CC9B0
    ctx->pc = 0x1AF45Cu;
    SET_GPR_U32(ctx, 31, 0x1AF464u);
    ctx->pc = 0x1CC9B0u;
    if (runtime->hasFunction(0x1CC9B0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC9B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF464u; }
        if (ctx->pc != 0x1AF464u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC9B0_0x1cc9b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF464u; }
        if (ctx->pc != 0x1AF464u) { return; }
    }
    ctx->pc = 0x1AF464u;
label_1af464:
    // 0x1af464: 0xc06ee2c  jal         func_1BB8B0
    ctx->pc = 0x1AF464u;
    SET_GPR_U32(ctx, 31, 0x1AF46Cu);
    ctx->pc = 0x1BB8B0u;
    if (runtime->hasFunction(0x1BB8B0u)) {
        auto targetFn = runtime->lookupFunction(0x1BB8B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF46Cu; }
        if (ctx->pc != 0x1AF46Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BB8B0_0x1bb8b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF46Cu; }
        if (ctx->pc != 0x1AF46Cu) { return; }
    }
    ctx->pc = 0x1AF46Cu;
label_1af46c:
    // 0x1af46c: 0xc0ddee4  jal         func_377B90
    ctx->pc = 0x1AF46Cu;
    SET_GPR_U32(ctx, 31, 0x1AF474u);
    ctx->pc = 0x377B90u;
    {
        auto targetFn = runtime->lookupFunction(0x377B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF474u; }
        if (ctx->pc != 0x1AF474u) { return; }
    }
    ctx->pc = 0x1AF474u;
label_1af474:
    // 0x1af474: 0xc06cf70  jal         func_1B3DC0
    ctx->pc = 0x1AF474u;
    SET_GPR_U32(ctx, 31, 0x1AF47Cu);
    ctx->pc = 0x1B3DC0u;
    if (runtime->hasFunction(0x1B3DC0u)) {
        auto targetFn = runtime->lookupFunction(0x1B3DC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF47Cu; }
        if (ctx->pc != 0x1AF47Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B3DC0_0x1b3dc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF47Cu; }
        if (ctx->pc != 0x1AF47Cu) { return; }
    }
    ctx->pc = 0x1AF47Cu;
label_1af47c:
    // 0x1af47c: 0xc06f0ac  jal         func_1BC2B0
    ctx->pc = 0x1AF47Cu;
    SET_GPR_U32(ctx, 31, 0x1AF484u);
    ctx->pc = 0x1BC2B0u;
    if (runtime->hasFunction(0x1BC2B0u)) {
        auto targetFn = runtime->lookupFunction(0x1BC2B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF484u; }
        if (ctx->pc != 0x1AF484u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BC2B0_0x1bc2b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AF484u; }
        if (ctx->pc != 0x1AF484u) { return; }
    }
    ctx->pc = 0x1AF484u;
label_1af484:
    // 0x1af484: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1af484u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1af488: 0x3e00008  jr          $ra
    ctx->pc = 0x1AF488u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AF48Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF488u;
            // 0x1af48c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AF3D4u: goto label_1af3d4;
            case 0x1AF3E4u: goto label_1af3e4;
            case 0x1AF3ECu: goto label_1af3ec;
            case 0x1AF3F4u: goto label_1af3f4;
            case 0x1AF3FCu: goto label_1af3fc;
            case 0x1AF404u: goto label_1af404;
            case 0x1AF40Cu: goto label_1af40c;
            case 0x1AF418u: goto label_1af418;
            case 0x1AF428u: goto label_1af428;
            case 0x1AF42Cu: goto label_1af42c;
            case 0x1AF434u: goto label_1af434;
            case 0x1AF444u: goto label_1af444;
            case 0x1AF44Cu: goto label_1af44c;
            case 0x1AF454u: goto label_1af454;
            case 0x1AF45Cu: goto label_1af45c;
            case 0x1AF464u: goto label_1af464;
            case 0x1AF46Cu: goto label_1af46c;
            case 0x1AF474u: goto label_1af474;
            case 0x1AF47Cu: goto label_1af47c;
            case 0x1AF484u: goto label_1af484;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AF490u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
