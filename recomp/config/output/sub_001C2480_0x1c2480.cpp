#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C2480
// Address: 0x1c2480 - 0x1c2600
void sub_001C2480_0x1c2480(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C2480_0x1c2480");
#endif

    switch (ctx->pc) {
        case 0x1c24bcu: goto label_1c24bc;
        case 0x1c24c4u: goto label_1c24c4;
        case 0x1c24d0u: goto label_1c24d0;
        case 0x1c24d8u: goto label_1c24d8;
        case 0x1c24e8u: goto label_1c24e8;
        case 0x1c24f8u: goto label_1c24f8;
        case 0x1c2510u: goto label_1c2510;
        case 0x1c2520u: goto label_1c2520;
        case 0x1c2540u: goto label_1c2540;
        case 0x1c254cu: goto label_1c254c;
        case 0x1c2568u: goto label_1c2568;
        case 0x1c2574u: goto label_1c2574;
        case 0x1c2584u: goto label_1c2584;
        case 0x1c259cu: goto label_1c259c;
        case 0x1c25b4u: goto label_1c25b4;
        case 0x1c25c8u: goto label_1c25c8;
        default: break;
    }

    ctx->pc = 0x1c2480u;

    // 0x1c2480: 0x27bdfeb0  addiu       $sp, $sp, -0x150
    ctx->pc = 0x1c2480u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966960));
    // 0x1c2484: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x1c2484u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x1c2488: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1c2488u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1c248c: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1c248cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1c2490: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1c2490u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1c2494: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1c2494u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1c2498: 0x3c130032  lui         $s3, 0x32
    ctx->pc = 0x1c2498u;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)50 << 16));
    // 0x1c249c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c249cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c24a0: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1c24a0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c24a4: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c24a4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c24a8: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1c24a8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c24ac: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x1c24acu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c24b0: 0x24040014  addiu       $a0, $zero, 0x14
    ctx->pc = 0x1c24b0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x1c24b4: 0xc06d574  jal         func_1B55D0
    ctx->pc = 0x1C24B4u;
    SET_GPR_U32(ctx, 31, 0x1C24BCu);
    ctx->pc = 0x1C24B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C24B4u;
            // 0x1c24b8: 0x267343c0  addiu       $s3, $s3, 0x43C0 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 17344));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B55D0u;
    if (runtime->hasFunction(0x1B55D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B55D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C24BCu; }
        if (ctx->pc != 0x1C24BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B55D0_0x1b55d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C24BCu; }
        if (ctx->pc != 0x1C24BCu) { return; }
    }
    ctx->pc = 0x1C24BCu;
label_1c24bc:
    // 0x1c24bc: 0xc06d590  jal         func_1B5640
    ctx->pc = 0x1C24BCu;
    SET_GPR_U32(ctx, 31, 0x1C24C4u);
    ctx->pc = 0x1C24C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C24BCu;
            // 0x1c24c0: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B5640u;
    if (runtime->hasFunction(0x1B5640u)) {
        auto targetFn = runtime->lookupFunction(0x1B5640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C24C4u; }
        if (ctx->pc != 0x1C24C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B5640_0x1b5640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C24C4u; }
        if (ctx->pc != 0x1C24C4u) { return; }
    }
    ctx->pc = 0x1C24C4u;
label_1c24c4:
    // 0x1c24c4: 0x3c028080  lui         $v0, 0x8080
    ctx->pc = 0x1c24c4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32896 << 16));
    // 0x1c24c8: 0xc06d594  jal         func_1B5650
    ctx->pc = 0x1C24C8u;
    SET_GPR_U32(ctx, 31, 0x1C24D0u);
    ctx->pc = 0x1C24CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C24C8u;
            // 0x1c24cc: 0x34448080  ori         $a0, $v0, 0x8080 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32896);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B5650u;
    if (runtime->hasFunction(0x1B5650u)) {
        auto targetFn = runtime->lookupFunction(0x1B5650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C24D0u; }
        if (ctx->pc != 0x1C24D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B5650_0x1b5650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C24D0u; }
        if (ctx->pc != 0x1C24D0u) { return; }
    }
    ctx->pc = 0x1C24D0u;
label_1c24d0:
    // 0x1c24d0: 0x1000003f  b           . + 4 + (0x3F << 2)
    ctx->pc = 0x1C24D0u;
    {
        const bool branch_taken_0x1c24d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C24D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C24D0u;
            // 0x1c24d4: 0x8e450000  lw          $a1, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c24d0) {
            ctx->pc = 0x1C25D0u;
            goto label_1c25d0;
        }
    }
    ctx->pc = 0x1C24D8u;
label_1c24d8:
    // 0x1c24d8: 0x27b400a0  addiu       $s4, $sp, 0xA0
    ctx->pc = 0x1c24d8u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
    // 0x1c24dc: 0xa3a000f0  sb          $zero, 0xF0($sp)
    ctx->pc = 0x1c24dcu;
    WRITE8(ADD32(GPR_U32(ctx, 29), 240), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c24e0: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1C24E0u;
    SET_GPR_U32(ctx, 31, 0x1C24E8u);
    ctx->pc = 0x1C24E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C24E0u;
            // 0x1c24e4: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C24E8u; }
        if (ctx->pc != 0x1C24E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C24E8u; }
        if (ctx->pc != 0x1C24E8u) { return; }
    }
    ctx->pc = 0x1C24E8u;
label_1c24e8:
    // 0x1c24e8: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1c24e8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1c24ec: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1c24ecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c24f0: 0xc042e02  jal         func_10B808
    ctx->pc = 0x1C24F0u;
    SET_GPR_U32(ctx, 31, 0x1C24F8u);
    ctx->pc = 0x1C24F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C24F0u;
            // 0x1c24f4: 0x24a52c78  addiu       $a1, $a1, 0x2C78 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 11384));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B808u;
    if (runtime->hasFunction(0x10B808u)) {
        auto targetFn = runtime->lookupFunction(0x10B808u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C24F8u; }
        if (ctx->pc != 0x1C24F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B808_0x10b808(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C24F8u; }
        if (ctx->pc != 0x1C24F8u) { return; }
    }
    ctx->pc = 0x1C24F8u;
label_1c24f8:
    // 0x1c24f8: 0x10400024  beqz        $v0, . + 4 + (0x24 << 2)
    ctx->pc = 0x1C24F8u;
    {
        const bool branch_taken_0x1c24f8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C24FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C24F8u;
            // 0x1c24fc: 0x40a82d  daddu       $s5, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c24f8) {
            ctx->pc = 0x1C258Cu;
            goto label_1c258c;
        }
    }
    ctx->pc = 0x1C2500u;
    // 0x1c2500: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x1c2500u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c2504: 0x27a400f0  addiu       $a0, $sp, 0xF0
    ctx->pc = 0x1c2504u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 240));
    // 0x1c2508: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x1C2508u;
    SET_GPR_U32(ctx, 31, 0x1C2510u);
    ctx->pc = 0x1C250Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2508u;
            // 0x1c250c: 0xa2a00000  sb          $zero, 0x0($s5) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2510u; }
        if (ctx->pc != 0x1C2510u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2510u; }
        if (ctx->pc != 0x1C2510u) { return; }
    }
    ctx->pc = 0x1C2510u;
label_1c2510:
    // 0x1c2510: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1c2510u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1c2514: 0x27a400f0  addiu       $a0, $sp, 0xF0
    ctx->pc = 0x1c2514u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 240));
    // 0x1c2518: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x1C2518u;
    SET_GPR_U32(ctx, 31, 0x1C2520u);
    ctx->pc = 0x1C251Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2518u;
            // 0x1c251c: 0x24a52c80  addiu       $a1, $a1, 0x2C80 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 11392));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2520u; }
        if (ctx->pc != 0x1C2520u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2520u; }
        if (ctx->pc != 0x1C2520u) { return; }
    }
    ctx->pc = 0x1C2520u;
label_1c2520:
    // 0x1c2520: 0x92620003  lbu         $v0, 0x3($s3)
    ctx->pc = 0x1c2520u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 3)));
    // 0x1c2524: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1C2524u;
    {
        const bool branch_taken_0x1c2524 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C2528u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2524u;
            // 0x1c2528: 0x26b40002  addiu       $s4, $s5, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 21), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2524) {
            ctx->pc = 0x1C2554u;
            goto label_1c2554;
        }
    }
    ctx->pc = 0x1C252Cu;
    // 0x1c252c: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1c252cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1c2530: 0x27a40070  addiu       $a0, $sp, 0x70
    ctx->pc = 0x1c2530u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
    // 0x1c2534: 0x24a52c88  addiu       $a1, $a1, 0x2C88
    ctx->pc = 0x1c2534u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 11400));
    // 0x1c2538: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1C2538u;
    SET_GPR_U32(ctx, 31, 0x1C2540u);
    ctx->pc = 0x1C253Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2538u;
            // 0x1c253c: 0x24060400  addiu       $a2, $zero, 0x400 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2540u; }
        if (ctx->pc != 0x1C2540u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2540u; }
        if (ctx->pc != 0x1C2540u) { return; }
    }
    ctx->pc = 0x1C2540u;
label_1c2540:
    // 0x1c2540: 0x27a40070  addiu       $a0, $sp, 0x70
    ctx->pc = 0x1c2540u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
    // 0x1c2544: 0xc06df00  jal         func_1B7C00
    ctx->pc = 0x1C2544u;
    SET_GPR_U32(ctx, 31, 0x1C254Cu);
    ctx->pc = 0x1C2548u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2544u;
            // 0x1c2548: 0x27a50140  addiu       $a1, $sp, 0x140 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 320));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B7C00u;
    if (runtime->hasFunction(0x1B7C00u)) {
        auto targetFn = runtime->lookupFunction(0x1B7C00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C254Cu; }
        if (ctx->pc != 0x1C254Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B7C00_0x1b7c00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C254Cu; }
        if (ctx->pc != 0x1C254Cu) { return; }
    }
    ctx->pc = 0x1C254Cu;
label_1c254c:
    // 0x1c254c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1C254Cu;
    {
        const bool branch_taken_0x1c254c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2550u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C254Cu;
            // 0x1c2550: 0x27a400f0  addiu       $a0, $sp, 0xF0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 240));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c254c) {
            ctx->pc = 0x1C256Cu;
            goto label_1c256c;
        }
    }
    ctx->pc = 0x1C2554u;
label_1c2554:
    // 0x1c2554: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1c2554u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1c2558: 0x27a40140  addiu       $a0, $sp, 0x140
    ctx->pc = 0x1c2558u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 320));
    // 0x1c255c: 0x24a52c88  addiu       $a1, $a1, 0x2C88
    ctx->pc = 0x1c255cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 11400));
    // 0x1c2560: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1C2560u;
    SET_GPR_U32(ctx, 31, 0x1C2568u);
    ctx->pc = 0x1C2564u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2560u;
            // 0x1c2564: 0x24060400  addiu       $a2, $zero, 0x400 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2568u; }
        if (ctx->pc != 0x1C2568u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2568u; }
        if (ctx->pc != 0x1C2568u) { return; }
    }
    ctx->pc = 0x1C2568u;
label_1c2568:
    // 0x1c2568: 0x27a400f0  addiu       $a0, $sp, 0xF0
    ctx->pc = 0x1c2568u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 240));
label_1c256c:
    // 0x1c256c: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x1C256Cu;
    SET_GPR_U32(ctx, 31, 0x1C2574u);
    ctx->pc = 0x1C2570u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C256Cu;
            // 0x1c2570: 0x27a50140  addiu       $a1, $sp, 0x140 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 320));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2574u; }
        if (ctx->pc != 0x1C2574u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2574u; }
        if (ctx->pc != 0x1C2574u) { return; }
    }
    ctx->pc = 0x1C2574u;
label_1c2574:
    // 0x1c2574: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1c2574u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1c2578: 0x27a400f0  addiu       $a0, $sp, 0xF0
    ctx->pc = 0x1c2578u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 240));
    // 0x1c257c: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x1C257Cu;
    SET_GPR_U32(ctx, 31, 0x1C2584u);
    ctx->pc = 0x1C2580u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C257Cu;
            // 0x1c2580: 0x24a52c90  addiu       $a1, $a1, 0x2C90 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 11408));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2584u; }
        if (ctx->pc != 0x1C2584u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2584u; }
        if (ctx->pc != 0x1C2584u) { return; }
    }
    ctx->pc = 0x1C2584u;
label_1c2584:
    // 0x1c2584: 0x1000ffd8  b           . + 4 + (-0x28 << 2)
    ctx->pc = 0x1C2584u;
    {
        const bool branch_taken_0x1c2584 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c2584) {
            ctx->pc = 0x1C24E8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c24e8;
        }
    }
    ctx->pc = 0x1C258Cu;
label_1c258c:
    // 0x1c258c: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1c258cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1c2590: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1c2590u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c2594: 0xc042e02  jal         func_10B808
    ctx->pc = 0x1C2594u;
    SET_GPR_U32(ctx, 31, 0x1C259Cu);
    ctx->pc = 0x1C2598u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2594u;
            // 0x1c2598: 0x24a52c98  addiu       $a1, $a1, 0x2C98 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 11416));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B808u;
    if (runtime->hasFunction(0x10B808u)) {
        auto targetFn = runtime->lookupFunction(0x10B808u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C259Cu; }
        if (ctx->pc != 0x1C259Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B808_0x10b808(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C259Cu; }
        if (ctx->pc != 0x1C259Cu) { return; }
    }
    ctx->pc = 0x1C259Cu;
label_1c259c:
    // 0x1c259c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C259Cu;
    {
        const bool branch_taken_0x1c259c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C25A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C259Cu;
            // 0x1c25a0: 0x280282d  daddu       $a1, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c259c) {
            ctx->pc = 0x1C25ACu;
            goto label_1c25ac;
        }
    }
    ctx->pc = 0x1C25A4u;
    // 0x1c25a4: 0x1000ffd0  b           . + 4 + (-0x30 << 2)
    ctx->pc = 0x1C25A4u;
    {
        const bool branch_taken_0x1c25a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C25A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C25A4u;
            // 0x1c25a8: 0xa0400000  sb          $zero, 0x0($v0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c25a4) {
            ctx->pc = 0x1C24E8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c24e8;
        }
    }
    ctx->pc = 0x1C25ACu;
label_1c25ac:
    // 0x1c25ac: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x1C25ACu;
    SET_GPR_U32(ctx, 31, 0x1C25B4u);
    ctx->pc = 0x1C25B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C25ACu;
            // 0x1c25b0: 0x27a400f0  addiu       $a0, $sp, 0xF0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 240));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C25B4u; }
        if (ctx->pc != 0x1C25B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C25B4u; }
        if (ctx->pc != 0x1C25B4u) { return; }
    }
    ctx->pc = 0x1C25B4u;
label_1c25b4:
    // 0x1c25b4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1c25b4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c25b8: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1c25b8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c25bc: 0x27a600f0  addiu       $a2, $sp, 0xF0
    ctx->pc = 0x1c25bcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 240));
    // 0x1c25c0: 0xc070800  jal         func_1C2000
    ctx->pc = 0x1C25C0u;
    SET_GPR_U32(ctx, 31, 0x1C25C8u);
    ctx->pc = 0x1C25C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C25C0u;
            // 0x1c25c4: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C2000u;
    if (runtime->hasFunction(0x1C2000u)) {
        auto targetFn = runtime->lookupFunction(0x1C2000u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C25C8u; }
        if (ctx->pc != 0x1C25C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C2000_0x1c2000(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C25C8u; }
        if (ctx->pc != 0x1C25C8u) { return; }
    }
    ctx->pc = 0x1C25C8u;
label_1c25c8:
    // 0x1c25c8: 0x26100014  addiu       $s0, $s0, 0x14
    ctx->pc = 0x1c25c8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 20));
    // 0x1c25cc: 0x8e450000  lw          $a1, 0x0($s2)
    ctx->pc = 0x1c25ccu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_1c25d0:
    // 0x1c25d0: 0x14a0ffc1  bnez        $a1, . + 4 + (-0x3F << 2)
    ctx->pc = 0x1C25D0u;
    {
        const bool branch_taken_0x1c25d0 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C25D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C25D0u;
            // 0x1c25d4: 0x26520004  addiu       $s2, $s2, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c25d0) {
            ctx->pc = 0x1C24D8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c24d8;
        }
    }
    ctx->pc = 0x1C25D8u;
    // 0x1c25d8: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x1c25d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1c25dc: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1c25dcu;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1c25e0: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1c25e0u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1c25e4: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1c25e4u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1c25e8: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1c25e8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c25ec: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c25ecu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c25f0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c25f0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c25f4: 0x3e00008  jr          $ra
    ctx->pc = 0x1C25F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C25F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C25F4u;
            // 0x1c25f8: 0x27bd0150  addiu       $sp, $sp, 0x150 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 336));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C24BCu: goto label_1c24bc;
            case 0x1C24C4u: goto label_1c24c4;
            case 0x1C24D0u: goto label_1c24d0;
            case 0x1C24D8u: goto label_1c24d8;
            case 0x1C24E8u: goto label_1c24e8;
            case 0x1C24F8u: goto label_1c24f8;
            case 0x1C2510u: goto label_1c2510;
            case 0x1C2520u: goto label_1c2520;
            case 0x1C2540u: goto label_1c2540;
            case 0x1C254Cu: goto label_1c254c;
            case 0x1C2554u: goto label_1c2554;
            case 0x1C2568u: goto label_1c2568;
            case 0x1C256Cu: goto label_1c256c;
            case 0x1C2574u: goto label_1c2574;
            case 0x1C2584u: goto label_1c2584;
            case 0x1C258Cu: goto label_1c258c;
            case 0x1C259Cu: goto label_1c259c;
            case 0x1C25ACu: goto label_1c25ac;
            case 0x1C25B4u: goto label_1c25b4;
            case 0x1C25C8u: goto label_1c25c8;
            case 0x1C25D0u: goto label_1c25d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C25FCu;
    // 0x1c25fc: 0x0  nop
    ctx->pc = 0x1c25fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
