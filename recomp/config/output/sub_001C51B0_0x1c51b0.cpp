#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C51B0
// Address: 0x1c51b0 - 0x1c52b0
void sub_001C51B0_0x1c51b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C51B0_0x1c51b0");
#endif

    switch (ctx->pc) {
        case 0x1c51d4u: goto label_1c51d4;
        case 0x1c51e0u: goto label_1c51e0;
        case 0x1c5200u: goto label_1c5200;
        case 0x1c5210u: goto label_1c5210;
        case 0x1c5228u: goto label_1c5228;
        case 0x1c5238u: goto label_1c5238;
        case 0x1c5244u: goto label_1c5244;
        case 0x1c5250u: goto label_1c5250;
        case 0x1c5258u: goto label_1c5258;
        case 0x1c5274u: goto label_1c5274;
        case 0x1c5284u: goto label_1c5284;
        case 0x1c5290u: goto label_1c5290;
        default: break;
    }

    ctx->pc = 0x1c51b0u;

    // 0x1c51b0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1c51b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1c51b4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1c51b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1c51b8: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c51b8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c51bc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c51bcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c51c0: 0x8c830030  lw          $v1, 0x30($a0)
    ctx->pc = 0x1c51c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 48)));
    // 0x1c51c4: 0x10600032  beqz        $v1, . + 4 + (0x32 << 2)
    ctx->pc = 0x1C51C4u;
    {
        const bool branch_taken_0x1c51c4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C51C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C51C4u;
            // 0x1c51c8: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c51c4) {
            ctx->pc = 0x1C5290u;
            goto label_1c5290;
        }
    }
    ctx->pc = 0x1C51CCu;
    // 0x1c51cc: 0xc0707a8  jal         func_1C1EA0
    ctx->pc = 0x1C51CCu;
    SET_GPR_U32(ctx, 31, 0x1C51D4u);
    ctx->pc = 0x1C51D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C51CCu;
            // 0x1c51d0: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C1EA0u;
    if (runtime->hasFunction(0x1C1EA0u)) {
        auto targetFn = runtime->lookupFunction(0x1C1EA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C51D4u; }
        if (ctx->pc != 0x1C51D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C1EA0_0x1c1ea0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C51D4u; }
        if (ctx->pc != 0x1C51D4u) { return; }
    }
    ctx->pc = 0x1C51D4u;
label_1c51d4:
    // 0x1c51d4: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1c51d4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c51d8: 0xc06d574  jal         func_1B55D0
    ctx->pc = 0x1C51D8u;
    SET_GPR_U32(ctx, 31, 0x1C51E0u);
    ctx->pc = 0x1C51DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C51D8u;
            // 0x1c51dc: 0x24040014  addiu       $a0, $zero, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B55D0u;
    if (runtime->hasFunction(0x1B55D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B55D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C51E0u; }
        if (ctx->pc != 0x1C51E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B55D0_0x1b55d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C51E0u; }
        if (ctx->pc != 0x1C51E0u) { return; }
    }
    ctx->pc = 0x1C51E0u;
label_1c51e0:
    // 0x1c51e0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c51e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c51e4: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1c51e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c51e8: 0x902343c3  lbu         $v1, 0x43C3($at)
    ctx->pc = 0x1c51e8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17347)));
    // 0x1c51ec: 0x14620006  bne         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1C51ECu;
    {
        const bool branch_taken_0x1c51ec = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1C51F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C51ECu;
            // 0x1c51f0: 0x3c040025  lui         $a0, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c51ec) {
            ctx->pc = 0x1C5208u;
            goto label_1c5208;
        }
    }
    ctx->pc = 0x1C51F4u;
    // 0x1c51f4: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1c51f4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1c51f8: 0xc06d5a8  jal         func_1B56A0
    ctx->pc = 0x1C51F8u;
    SET_GPR_U32(ctx, 31, 0x1C5200u);
    ctx->pc = 0x1C51FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C51F8u;
            // 0x1c51fc: 0x24842d50  addiu       $a0, $a0, 0x2D50 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 11600));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B56A0u;
    if (runtime->hasFunction(0x1B56A0u)) {
        auto targetFn = runtime->lookupFunction(0x1B56A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5200u; }
        if (ctx->pc != 0x1C5200u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B56A0_0x1b56a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5200u; }
        if (ctx->pc != 0x1C5200u) { return; }
    }
    ctx->pc = 0x1C5200u;
label_1c5200:
    // 0x1c5200: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1C5200u;
    {
        const bool branch_taken_0x1c5200 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C5204u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5200u;
            // 0x1c5204: 0x8e220038  lw          $v0, 0x38($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 56)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5200) {
            ctx->pc = 0x1C5214u;
            goto label_1c5214;
        }
    }
    ctx->pc = 0x1C5208u;
label_1c5208:
    // 0x1c5208: 0xc06d5a8  jal         func_1B56A0
    ctx->pc = 0x1C5208u;
    SET_GPR_U32(ctx, 31, 0x1C5210u);
    ctx->pc = 0x1C520Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5208u;
            // 0x1c520c: 0x24842d58  addiu       $a0, $a0, 0x2D58 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 11608));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B56A0u;
    if (runtime->hasFunction(0x1B56A0u)) {
        auto targetFn = runtime->lookupFunction(0x1B56A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5210u; }
        if (ctx->pc != 0x1C5210u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B56A0_0x1b56a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5210u; }
        if (ctx->pc != 0x1C5210u) { return; }
    }
    ctx->pc = 0x1C5210u;
label_1c5210:
    // 0x1c5210: 0x8e220038  lw          $v0, 0x38($s1)
    ctx->pc = 0x1c5210u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 56)));
label_1c5214:
    // 0x1c5214: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1C5214u;
    {
        const bool branch_taken_0x1c5214 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C5218u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5214u;
            // 0x1c5218: 0x3c028080  lui         $v0, 0x8080 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32896 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5214) {
            ctx->pc = 0x1C5230u;
            goto label_1c5230;
        }
    }
    ctx->pc = 0x1C521Cu;
    // 0x1c521c: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1c521cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1c5220: 0xc06d594  jal         func_1B5650
    ctx->pc = 0x1C5220u;
    SET_GPR_U32(ctx, 31, 0x1C5228u);
    ctx->pc = 0x1C5224u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5220u;
            // 0x1c5224: 0x34440080  ori         $a0, $v0, 0x80 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)128);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B5650u;
    if (runtime->hasFunction(0x1B5650u)) {
        auto targetFn = runtime->lookupFunction(0x1B5650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5228u; }
        if (ctx->pc != 0x1C5228u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B5650_0x1b5650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5228u; }
        if (ctx->pc != 0x1C5228u) { return; }
    }
    ctx->pc = 0x1C5228u;
label_1c5228:
    // 0x1c5228: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1C5228u;
    {
        const bool branch_taken_0x1c5228 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C522Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5228u;
            // 0x1c522c: 0x8e040010  lw          $a0, 0x10($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5228) {
            ctx->pc = 0x1C523Cu;
            goto label_1c523c;
        }
    }
    ctx->pc = 0x1C5230u;
label_1c5230:
    // 0x1c5230: 0xc06d594  jal         func_1B5650
    ctx->pc = 0x1C5230u;
    SET_GPR_U32(ctx, 31, 0x1C5238u);
    ctx->pc = 0x1C5234u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5230u;
            // 0x1c5234: 0x34448080  ori         $a0, $v0, 0x8080 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32896);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B5650u;
    if (runtime->hasFunction(0x1B5650u)) {
        auto targetFn = runtime->lookupFunction(0x1B5650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5238u; }
        if (ctx->pc != 0x1C5238u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B5650_0x1b5650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5238u; }
        if (ctx->pc != 0x1C5238u) { return; }
    }
    ctx->pc = 0x1C5238u;
label_1c5238:
    // 0x1c5238: 0x8e040010  lw          $a0, 0x10($s0)
    ctx->pc = 0x1c5238u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
label_1c523c:
    // 0x1c523c: 0xc06d5a8  jal         func_1B56A0
    ctx->pc = 0x1C523Cu;
    SET_GPR_U32(ctx, 31, 0x1C5244u);
    ctx->pc = 0x1B56A0u;
    if (runtime->hasFunction(0x1B56A0u)) {
        auto targetFn = runtime->lookupFunction(0x1B56A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5244u; }
        if (ctx->pc != 0x1C5244u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B56A0_0x1b56a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5244u; }
        if (ctx->pc != 0x1C5244u) { return; }
    }
    ctx->pc = 0x1C5244u;
label_1c5244:
    // 0x1c5244: 0x3c028080  lui         $v0, 0x8080
    ctx->pc = 0x1c5244u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32896 << 16));
    // 0x1c5248: 0xc06d594  jal         func_1B5650
    ctx->pc = 0x1C5248u;
    SET_GPR_U32(ctx, 31, 0x1C5250u);
    ctx->pc = 0x1C524Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5248u;
            // 0x1c524c: 0x34448080  ori         $a0, $v0, 0x8080 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32896);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B5650u;
    if (runtime->hasFunction(0x1B5650u)) {
        auto targetFn = runtime->lookupFunction(0x1B5650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5250u; }
        if (ctx->pc != 0x1C5250u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B5650_0x1b5650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5250u; }
        if (ctx->pc != 0x1C5250u) { return; }
    }
    ctx->pc = 0x1C5250u;
label_1c5250:
    // 0x1c5250: 0xc06d5a8  jal         func_1B56A0
    ctx->pc = 0x1C5250u;
    SET_GPR_U32(ctx, 31, 0x1C5258u);
    ctx->pc = 0x1C5254u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5250u;
            // 0x1c5254: 0x8e040018  lw          $a0, 0x18($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B56A0u;
    if (runtime->hasFunction(0x1B56A0u)) {
        auto targetFn = runtime->lookupFunction(0x1B56A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5258u; }
        if (ctx->pc != 0x1C5258u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B56A0_0x1b56a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5258u; }
        if (ctx->pc != 0x1C5258u) { return; }
    }
    ctx->pc = 0x1C5258u;
label_1c5258:
    // 0x1c5258: 0x8e230038  lw          $v1, 0x38($s1)
    ctx->pc = 0x1c5258u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 56)));
    // 0x1c525c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c525cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c5260: 0x14620006  bne         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1C5260u;
    {
        const bool branch_taken_0x1c5260 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1C5264u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5260u;
            // 0x1c5264: 0x3c028080  lui         $v0, 0x8080 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32896 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5260) {
            ctx->pc = 0x1C527Cu;
            goto label_1c527c;
        }
    }
    ctx->pc = 0x1C5268u;
    // 0x1c5268: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1c5268u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1c526c: 0xc06d594  jal         func_1B5650
    ctx->pc = 0x1C526Cu;
    SET_GPR_U32(ctx, 31, 0x1C5274u);
    ctx->pc = 0x1C5270u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C526Cu;
            // 0x1c5270: 0x34440080  ori         $a0, $v0, 0x80 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)128);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B5650u;
    if (runtime->hasFunction(0x1B5650u)) {
        auto targetFn = runtime->lookupFunction(0x1B5650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5274u; }
        if (ctx->pc != 0x1C5274u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B5650_0x1b5650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5274u; }
        if (ctx->pc != 0x1C5274u) { return; }
    }
    ctx->pc = 0x1C5274u;
label_1c5274:
    // 0x1c5274: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1C5274u;
    {
        const bool branch_taken_0x1c5274 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C5278u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5274u;
            // 0x1c5278: 0x8e040014  lw          $a0, 0x14($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5274) {
            ctx->pc = 0x1C5288u;
            goto label_1c5288;
        }
    }
    ctx->pc = 0x1C527Cu;
label_1c527c:
    // 0x1c527c: 0xc06d594  jal         func_1B5650
    ctx->pc = 0x1C527Cu;
    SET_GPR_U32(ctx, 31, 0x1C5284u);
    ctx->pc = 0x1C5280u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C527Cu;
            // 0x1c5280: 0x34448080  ori         $a0, $v0, 0x8080 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32896);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B5650u;
    if (runtime->hasFunction(0x1B5650u)) {
        auto targetFn = runtime->lookupFunction(0x1B5650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5284u; }
        if (ctx->pc != 0x1C5284u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B5650_0x1b5650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5284u; }
        if (ctx->pc != 0x1C5284u) { return; }
    }
    ctx->pc = 0x1C5284u;
label_1c5284:
    // 0x1c5284: 0x8e040014  lw          $a0, 0x14($s0)
    ctx->pc = 0x1c5284u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
label_1c5288:
    // 0x1c5288: 0xc06d5a8  jal         func_1B56A0
    ctx->pc = 0x1C5288u;
    SET_GPR_U32(ctx, 31, 0x1C5290u);
    ctx->pc = 0x1B56A0u;
    if (runtime->hasFunction(0x1B56A0u)) {
        auto targetFn = runtime->lookupFunction(0x1B56A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5290u; }
        if (ctx->pc != 0x1C5290u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B56A0_0x1b56a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5290u; }
        if (ctx->pc != 0x1C5290u) { return; }
    }
    ctx->pc = 0x1C5290u;
label_1c5290:
    // 0x1c5290: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1c5290u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c5294: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c5294u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c5298: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c5298u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c529c: 0x3e00008  jr          $ra
    ctx->pc = 0x1C529Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C52A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C529Cu;
            // 0x1c52a0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C51D4u: goto label_1c51d4;
            case 0x1C51E0u: goto label_1c51e0;
            case 0x1C5200u: goto label_1c5200;
            case 0x1C5208u: goto label_1c5208;
            case 0x1C5210u: goto label_1c5210;
            case 0x1C5214u: goto label_1c5214;
            case 0x1C5228u: goto label_1c5228;
            case 0x1C5230u: goto label_1c5230;
            case 0x1C5238u: goto label_1c5238;
            case 0x1C523Cu: goto label_1c523c;
            case 0x1C5244u: goto label_1c5244;
            case 0x1C5250u: goto label_1c5250;
            case 0x1C5258u: goto label_1c5258;
            case 0x1C5274u: goto label_1c5274;
            case 0x1C527Cu: goto label_1c527c;
            case 0x1C5284u: goto label_1c5284;
            case 0x1C5288u: goto label_1c5288;
            case 0x1C5290u: goto label_1c5290;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C52A4u;
    // 0x1c52a4: 0x0  nop
    ctx->pc = 0x1c52a4u;
    // NOP
    // 0x1c52a8: 0x0  nop
    ctx->pc = 0x1c52a8u;
    // NOP
    // 0x1c52ac: 0x0  nop
    ctx->pc = 0x1c52acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
