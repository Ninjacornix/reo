#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D2FE0
// Address: 0x1d2fe0 - 0x1d3100
void sub_001D2FE0_0x1d2fe0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D2FE0_0x1d2fe0");
#endif

    switch (ctx->pc) {
        case 0x1d3014u: goto label_1d3014;
        case 0x1d3030u: goto label_1d3030;
        case 0x1d3044u: goto label_1d3044;
        case 0x1d304cu: goto label_1d304c;
        case 0x1d3058u: goto label_1d3058;
        case 0x1d3064u: goto label_1d3064;
        case 0x1d3070u: goto label_1d3070;
        case 0x1d3078u: goto label_1d3078;
        case 0x1d3094u: goto label_1d3094;
        case 0x1d30d0u: goto label_1d30d0;
        case 0x1d30d8u: goto label_1d30d8;
        default: break;
    }

    ctx->pc = 0x1d2fe0u;

    // 0x1d2fe0: 0x27bdff50  addiu       $sp, $sp, -0xB0
    ctx->pc = 0x1d2fe0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x1d2fe4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d2fe4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d2fe8: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1d2fe8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1d2fec: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1d2fecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1d2ff0: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d2ff0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d2ff4: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x1d2ff4u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d2ff8: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d2ff8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d2ffc: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x1d2ffcu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3000: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d3000u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d3004: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d3004u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d3008: 0x8c304428  lw          $s0, 0x4428($at)
    ctx->pc = 0x1d3008u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17448)));
    // 0x1d300c: 0xc068abc  jal         func_1A2AF0
    ctx->pc = 0x1D300Cu;
    SET_GPR_U32(ctx, 31, 0x1D3014u);
    ctx->pc = 0x1D3010u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D300Cu;
            // 0x1d3010: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A2AF0u;
    if (runtime->hasFunction(0x1A2AF0u)) {
        auto targetFn = runtime->lookupFunction(0x1A2AF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3014u; }
        if (ctx->pc != 0x1D3014u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A2AF0_0x1a2af0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3014u; }
        if (ctx->pc != 0x1D3014u) { return; }
    }
    ctx->pc = 0x1D3014u;
label_1d3014:
    // 0x1d3014: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d3014u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d3018: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x1d3018u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d301c: 0x8c23440c  lw          $v1, 0x440C($at)
    ctx->pc = 0x1d301cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d3020: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x1d3020u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x1d3024: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x1d3024u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1d3028: 0xc063f7c  jal         func_18FDF0
    ctx->pc = 0x1D3028u;
    SET_GPR_U32(ctx, 31, 0x1D3030u);
    ctx->pc = 0x1D302Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3028u;
            // 0x1d302c: 0x628821  addu        $s1, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18FDF0u;
    if (runtime->hasFunction(0x18FDF0u)) {
        auto targetFn = runtime->lookupFunction(0x18FDF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3030u; }
        if (ctx->pc != 0x1D3030u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018FDF0_0x18fdf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3030u; }
        if (ctx->pc != 0x1D3030u) { return; }
    }
    ctx->pc = 0x1D3030u;
label_1d3030:
    // 0x1d3030: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x1d3030u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3034: 0x27a400a0  addiu       $a0, $sp, 0xA0
    ctx->pc = 0x1d3034u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
    // 0x1d3038: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1d3038u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d303c: 0xc074d50  jal         func_1D3540
    ctx->pc = 0x1D303Cu;
    SET_GPR_U32(ctx, 31, 0x1D3044u);
    ctx->pc = 0x1D3040u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D303Cu;
            // 0x1d3040: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D3540u;
    if (runtime->hasFunction(0x1D3540u)) {
        auto targetFn = runtime->lookupFunction(0x1D3540u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3044u; }
        if (ctx->pc != 0x1D3044u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D3540_0x1d3540(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3044u; }
        if (ctx->pc != 0x1D3044u) { return; }
    }
    ctx->pc = 0x1D3044u;
label_1d3044:
    // 0x1d3044: 0xc064920  jal         func_192480
    ctx->pc = 0x1D3044u;
    SET_GPR_U32(ctx, 31, 0x1D304Cu);
    ctx->pc = 0x1D3048u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3044u;
            // 0x1d3048: 0x27a400a0  addiu       $a0, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
    ctx->pc = 0x192480u;
    if (runtime->hasFunction(0x192480u)) {
        auto targetFn = runtime->lookupFunction(0x192480u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D304Cu; }
        if (ctx->pc != 0x1D304Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00192480_0x192480(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D304Cu; }
        if (ctx->pc != 0x1D304Cu) { return; }
    }
    ctx->pc = 0x1D304Cu;
label_1d304c:
    // 0x1d304c: 0xae82080c  sw          $v0, 0x80C($s4)
    ctx->pc = 0x1d304cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 2060), GPR_U32(ctx, 2));
    // 0x1d3050: 0xc06c430  jal         func_1B10C0
    ctx->pc = 0x1D3050u;
    SET_GPR_U32(ctx, 31, 0x1D3058u);
    ctx->pc = 0x1D3054u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3050u;
            // 0x1d3054: 0x8e84080c  lw          $a0, 0x80C($s4) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 2060)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B10C0u;
    if (runtime->hasFunction(0x1B10C0u)) {
        auto targetFn = runtime->lookupFunction(0x1B10C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3058u; }
        if (ctx->pc != 0x1D3058u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B10C0_0x1b10c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3058u; }
        if (ctx->pc != 0x1D3058u) { return; }
    }
    ctx->pc = 0x1D3058u;
label_1d3058:
    // 0x1d3058: 0x8e85080c  lw          $a1, 0x80C($s4)
    ctx->pc = 0x1d3058u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 2060)));
    // 0x1d305c: 0xc064ce0  jal         func_193380
    ctx->pc = 0x1D305Cu;
    SET_GPR_U32(ctx, 31, 0x1D3064u);
    ctx->pc = 0x1D3060u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D305Cu;
            // 0x1d3060: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193380u;
    if (runtime->hasFunction(0x193380u)) {
        auto targetFn = runtime->lookupFunction(0x193380u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3064u; }
        if (ctx->pc != 0x1D3064u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193380_0x193380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3064u; }
        if (ctx->pc != 0x1D3064u) { return; }
    }
    ctx->pc = 0x1D3064u;
label_1d3064:
    // 0x1d3064: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1d3064u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3068: 0xc064c90  jal         func_193240
    ctx->pc = 0x1D3068u;
    SET_GPR_U32(ctx, 31, 0x1D3070u);
    ctx->pc = 0x1D306Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3068u;
            // 0x1d306c: 0x27a50060  addiu       $a1, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193240u;
    if (runtime->hasFunction(0x193240u)) {
        auto targetFn = runtime->lookupFunction(0x193240u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3070u; }
        if (ctx->pc != 0x1D3070u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193240_0x193240(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3070u; }
        if (ctx->pc != 0x1D3070u) { return; }
    }
    ctx->pc = 0x1D3070u;
label_1d3070:
    // 0x1d3070: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1D3070u;
    {
        const bool branch_taken_0x1d3070 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D3074u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3070u;
            // 0x1d3074: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d3070) {
            ctx->pc = 0x1D30BCu;
            goto label_1d30bc;
        }
    }
    ctx->pc = 0x1D3078u;
label_1d3078:
    // 0x1d3078: 0x8e220174  lw          $v0, 0x174($s1)
    ctx->pc = 0x1d3078u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 372)));
    // 0x1d307c: 0x440000d  bltz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1D307Cu;
    {
        const bool branch_taken_0x1d307c = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1d307c) {
            ctx->pc = 0x1D30B4u;
            goto label_1d30b4;
        }
    }
    ctx->pc = 0x1D3084u;
    // 0x1d3084: 0x21180  sll         $v0, $v0, 6
    ctx->pc = 0x1d3084u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 6));
    // 0x1d3088: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x1d3088u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1d308c: 0x2023021  addu        $a2, $s0, $v0
    ctx->pc = 0x1d308cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1d3090: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1d3090u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_1d3094:
    // 0x1d3094: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x1d3094u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1d3098: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x1d3098u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x1d309c: 0x8ca20004  lw          $v0, 0x4($a1)
    ctx->pc = 0x1d309cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x1d30a0: 0xacc30000  sw          $v1, 0x0($a2)
    ctx->pc = 0x1d30a0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 3));
    // 0x1d30a4: 0x24a50008  addiu       $a1, $a1, 0x8
    ctx->pc = 0x1d30a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8));
    // 0x1d30a8: 0xacc20004  sw          $v0, 0x4($a2)
    ctx->pc = 0x1d30a8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 2));
    // 0x1d30ac: 0x1c80fff9  bgtz        $a0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1D30ACu;
    {
        const bool branch_taken_0x1d30ac = (GPR_S64(ctx, 4) > 0);
        ctx->pc = 0x1D30B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D30ACu;
            // 0x1d30b0: 0x24c60008  addiu       $a2, $a2, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d30ac) {
            ctx->pc = 0x1D3094u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d3094;
        }
    }
    ctx->pc = 0x1D30B4u;
label_1d30b4:
    // 0x1d30b4: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x1d30b4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x1d30b8: 0x26310190  addiu       $s1, $s1, 0x190
    ctx->pc = 0x1d30b8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 400));
label_1d30bc:
    // 0x1d30bc: 0xf2102a  slt         $v0, $a3, $s2
    ctx->pc = 0x1d30bcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x1d30c0: 0x1440ffed  bnez        $v0, . + 4 + (-0x13 << 2)
    ctx->pc = 0x1D30C0u;
    {
        const bool branch_taken_0x1d30c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d30c0) {
            ctx->pc = 0x1D3078u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d3078;
        }
    }
    ctx->pc = 0x1D30C8u;
    // 0x1d30c8: 0xc064960  jal         func_192580
    ctx->pc = 0x1D30C8u;
    SET_GPR_U32(ctx, 31, 0x1D30D0u);
    ctx->pc = 0x1D30CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D30C8u;
            // 0x1d30cc: 0x8e84080c  lw          $a0, 0x80C($s4) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 2060)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x192580u;
    if (runtime->hasFunction(0x192580u)) {
        auto targetFn = runtime->lookupFunction(0x192580u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D30D0u; }
        if (ctx->pc != 0x1D30D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00192580_0x192580(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D30D0u; }
        if (ctx->pc != 0x1D30D0u) { return; }
    }
    ctx->pc = 0x1D30D0u;
label_1d30d0:
    // 0x1d30d0: 0xc06c444  jal         func_1B1110
    ctx->pc = 0x1D30D0u;
    SET_GPR_U32(ctx, 31, 0x1D30D8u);
    ctx->pc = 0x1D30D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D30D0u;
            // 0x1d30d4: 0x8e84080c  lw          $a0, 0x80C($s4) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 2060)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B1110u;
    if (runtime->hasFunction(0x1B1110u)) {
        auto targetFn = runtime->lookupFunction(0x1B1110u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D30D8u; }
        if (ctx->pc != 0x1D30D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1110_0x1b1110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D30D8u; }
        if (ctx->pc != 0x1D30D8u) { return; }
    }
    ctx->pc = 0x1D30D8u;
label_1d30d8:
    // 0x1d30d8: 0xae80080c  sw          $zero, 0x80C($s4)
    ctx->pc = 0x1d30d8u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 2060), GPR_U32(ctx, 0));
    // 0x1d30dc: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1d30dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1d30e0: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1d30e0u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d30e4: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d30e4u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d30e8: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d30e8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d30ec: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d30ecu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d30f0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d30f0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d30f4: 0x3e00008  jr          $ra
    ctx->pc = 0x1D30F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D30F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D30F4u;
            // 0x1d30f8: 0x27bd00b0  addiu       $sp, $sp, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D3014u: goto label_1d3014;
            case 0x1D3030u: goto label_1d3030;
            case 0x1D3044u: goto label_1d3044;
            case 0x1D304Cu: goto label_1d304c;
            case 0x1D3058u: goto label_1d3058;
            case 0x1D3064u: goto label_1d3064;
            case 0x1D3070u: goto label_1d3070;
            case 0x1D3078u: goto label_1d3078;
            case 0x1D3094u: goto label_1d3094;
            case 0x1D30B4u: goto label_1d30b4;
            case 0x1D30BCu: goto label_1d30bc;
            case 0x1D30D0u: goto label_1d30d0;
            case 0x1D30D8u: goto label_1d30d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D30FCu;
    // 0x1d30fc: 0x0  nop
    ctx->pc = 0x1d30fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
