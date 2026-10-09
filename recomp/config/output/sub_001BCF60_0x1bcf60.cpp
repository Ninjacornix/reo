#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BCF60
// Address: 0x1bcf60 - 0x1bd040
void sub_001BCF60_0x1bcf60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BCF60_0x1bcf60");
#endif

    switch (ctx->pc) {
        case 0x1bcf88u: goto label_1bcf88;
        case 0x1bcfa4u: goto label_1bcfa4;
        case 0x1bcfc0u: goto label_1bcfc0;
        case 0x1bcfdcu: goto label_1bcfdc;
        case 0x1bcff8u: goto label_1bcff8;
        case 0x1bd008u: goto label_1bd008;
        case 0x1bd028u: goto label_1bd028;
        case 0x1bd034u: goto label_1bd034;
        default: break;
    }

    ctx->pc = 0x1bcf60u;

    // 0x1bcf60: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1bcf60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1bcf64: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1bcf64u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1bcf68: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1bcf68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1bcf6c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bcf6cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bcf70: 0xac2044e0  sw          $zero, 0x44E0($at)
    ctx->pc = 0x1bcf70u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17632), GPR_U32(ctx, 0));
    // 0x1bcf74: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1bcf74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1bcf78: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1bcf78u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1bcf7c: 0x24840370  addiu       $a0, $a0, 0x370
    ctx->pc = 0x1bcf7cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 880));
    // 0x1bcf80: 0xc0470f8  jal         func_11C3E0
    ctx->pc = 0x1BCF80u;
    SET_GPR_U32(ctx, 31, 0x1BCF88u);
    ctx->pc = 0x1BCF84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCF80u;
            // 0x1bcf84: 0xac225008  sw          $v0, 0x5008($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 20488), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11C3E0u;
    if (runtime->hasFunction(0x11C3E0u)) {
        auto targetFn = runtime->lookupFunction(0x11C3E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCF88u; }
        if (ctx->pc != 0x1BCF88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011C3E0_0x11c3e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCF88u; }
        if (ctx->pc != 0x1BCF88u) { return; }
    }
    ctx->pc = 0x1BCF88u;
label_1bcf88:
    // 0x1bcf88: 0x4410008  bgez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1BCF88u;
    {
        const bool branch_taken_0x1bcf88 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1bcf88) {
            ctx->pc = 0x1BCFACu;
            goto label_1bcfac;
        }
    }
    ctx->pc = 0x1BCF90u;
    // 0x1bcf90: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1bcf90u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1bcf94: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1bcf94u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bcf98: 0x24840380  addiu       $a0, $a0, 0x380
    ctx->pc = 0x1bcf98u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 896));
    // 0x1bcf9c: 0xc06f410  jal         func_1BD040
    ctx->pc = 0x1BCF9Cu;
    SET_GPR_U32(ctx, 31, 0x1BCFA4u);
    ctx->pc = 0x1BCFA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCF9Cu;
            // 0x1bcfa0: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BD040u;
    if (runtime->hasFunction(0x1BD040u)) {
        auto targetFn = runtime->lookupFunction(0x1BD040u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCFA4u; }
        if (ctx->pc != 0x1BCFA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BD040_0x1bd040(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCFA4u; }
        if (ctx->pc != 0x1BCFA4u) { return; }
    }
    ctx->pc = 0x1BCFA4u;
label_1bcfa4:
    // 0x1bcfa4: 0x4400023  bltz        $v0, . + 4 + (0x23 << 2)
    ctx->pc = 0x1BCFA4u;
    {
        const bool branch_taken_0x1bcfa4 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1bcfa4) {
            ctx->pc = 0x1BD034u;
            goto label_1bd034;
        }
    }
    ctx->pc = 0x1BCFACu;
label_1bcfac:
    // 0x1bcfac: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1bcfacu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1bcfb0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1bcfb0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bcfb4: 0x248403a0  addiu       $a0, $a0, 0x3A0
    ctx->pc = 0x1bcfb4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 928));
    // 0x1bcfb8: 0xc06f410  jal         func_1BD040
    ctx->pc = 0x1BCFB8u;
    SET_GPR_U32(ctx, 31, 0x1BCFC0u);
    ctx->pc = 0x1BCFBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCFB8u;
            // 0x1bcfbc: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BD040u;
    if (runtime->hasFunction(0x1BD040u)) {
        auto targetFn = runtime->lookupFunction(0x1BD040u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCFC0u; }
        if (ctx->pc != 0x1BCFC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BD040_0x1bd040(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCFC0u; }
        if (ctx->pc != 0x1BCFC0u) { return; }
    }
    ctx->pc = 0x1BCFC0u;
label_1bcfc0:
    // 0x1bcfc0: 0x440001c  bltz        $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x1BCFC0u;
    {
        const bool branch_taken_0x1bcfc0 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1BCFC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCFC0u;
            // 0x1bcfc4: 0x3c040025  lui         $a0, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bcfc0) {
            ctx->pc = 0x1BD034u;
            goto label_1bd034;
        }
    }
    ctx->pc = 0x1BCFC8u;
    // 0x1bcfc8: 0x3c060023  lui         $a2, 0x23
    ctx->pc = 0x1bcfc8u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)35 << 16));
    // 0x1bcfcc: 0x248403c0  addiu       $a0, $a0, 0x3C0
    ctx->pc = 0x1bcfccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 960));
    // 0x1bcfd0: 0x2405000a  addiu       $a1, $zero, 0xA
    ctx->pc = 0x1bcfd0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1bcfd4: 0xc06f410  jal         func_1BD040
    ctx->pc = 0x1BCFD4u;
    SET_GPR_U32(ctx, 31, 0x1BCFDCu);
    ctx->pc = 0x1BCFD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCFD4u;
            // 0x1bcfd8: 0x24c64f08  addiu       $a2, $a2, 0x4F08 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 20232));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BD040u;
    if (runtime->hasFunction(0x1BD040u)) {
        auto targetFn = runtime->lookupFunction(0x1BD040u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCFDCu; }
        if (ctx->pc != 0x1BCFDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BD040_0x1bd040(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCFDCu; }
        if (ctx->pc != 0x1BCFDCu) { return; }
    }
    ctx->pc = 0x1BCFDCu;
label_1bcfdc:
    // 0x1bcfdc: 0x4400015  bltz        $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x1BCFDCu;
    {
        const bool branch_taken_0x1bcfdc = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1BCFE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCFDCu;
            // 0x1bcfe0: 0x3c040025  lui         $a0, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bcfdc) {
            ctx->pc = 0x1BD034u;
            goto label_1bd034;
        }
    }
    ctx->pc = 0x1BCFE4u;
    // 0x1bcfe4: 0x3c060023  lui         $a2, 0x23
    ctx->pc = 0x1bcfe4u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)35 << 16));
    // 0x1bcfe8: 0x248403e0  addiu       $a0, $a0, 0x3E0
    ctx->pc = 0x1bcfe8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 992));
    // 0x1bcfec: 0x24050010  addiu       $a1, $zero, 0x10
    ctx->pc = 0x1bcfecu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1bcff0: 0xc06f410  jal         func_1BD040
    ctx->pc = 0x1BCFF0u;
    SET_GPR_U32(ctx, 31, 0x1BCFF8u);
    ctx->pc = 0x1BCFF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BCFF0u;
            // 0x1bcff4: 0x24c64f20  addiu       $a2, $a2, 0x4F20 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 20256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BD040u;
    if (runtime->hasFunction(0x1BD040u)) {
        auto targetFn = runtime->lookupFunction(0x1BD040u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCFF8u; }
        if (ctx->pc != 0x1BCFF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BD040_0x1bd040(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCFF8u; }
        if (ctx->pc != 0x1BCFF8u) { return; }
    }
    ctx->pc = 0x1BCFF8u;
label_1bcff8:
    // 0x1bcff8: 0x440000e  bltz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1BCFF8u;
    {
        const bool branch_taken_0x1bcff8 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1bcff8) {
            ctx->pc = 0x1BD034u;
            goto label_1bd034;
        }
    }
    ctx->pc = 0x1BD000u;
    // 0x1bd000: 0xc06f42c  jal         func_1BD0B0
    ctx->pc = 0x1BD000u;
    SET_GPR_U32(ctx, 31, 0x1BD008u);
    ctx->pc = 0x1BD0B0u;
    if (runtime->hasFunction(0x1BD0B0u)) {
        auto targetFn = runtime->lookupFunction(0x1BD0B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD008u; }
        if (ctx->pc != 0x1BD008u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BD0B0_0x1bd0b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD008u; }
        if (ctx->pc != 0x1BD008u) { return; }
    }
    ctx->pc = 0x1BD008u;
label_1bd008:
    // 0x1bd008: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1bd008u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1bd00c: 0x24054807  addiu       $a1, $zero, 0x4807
    ctx->pc = 0x1bd00cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 18439));
    // 0x1bd010: 0x24840400  addiu       $a0, $a0, 0x400
    ctx->pc = 0x1bd010u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1024));
    // 0x1bd014: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1bd014u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd018: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1bd018u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd01c: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1bd01cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd020: 0xc046c92  jal         func_11B248
    ctx->pc = 0x1BD020u;
    SET_GPR_U32(ctx, 31, 0x1BD028u);
    ctx->pc = 0x1BD024u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD020u;
            // 0x1bd024: 0x482d  daddu       $t1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11B248u;
    if (runtime->hasFunction(0x11B248u)) {
        auto targetFn = runtime->lookupFunction(0x11B248u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD028u; }
        if (ctx->pc != 0x1BD028u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011B248_0x11b248(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD028u; }
        if (ctx->pc != 0x1BD028u) { return; }
    }
    ctx->pc = 0x1BD028u;
label_1bd028:
    // 0x1bd028: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1bd028u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1bd02c: 0xc06f4bc  jal         func_1BD2F0
    ctx->pc = 0x1BD02Cu;
    SET_GPR_U32(ctx, 31, 0x1BD034u);
    ctx->pc = 0x1BD030u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD02Cu;
            // 0x1bd030: 0xac225008  sw          $v0, 0x5008($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 20488), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BD2F0u;
    if (runtime->hasFunction(0x1BD2F0u)) {
        auto targetFn = runtime->lookupFunction(0x1BD2F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD034u; }
        if (ctx->pc != 0x1BD034u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BD2F0_0x1bd2f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD034u; }
        if (ctx->pc != 0x1BD034u) { return; }
    }
    ctx->pc = 0x1BD034u;
label_1bd034:
    // 0x1bd034: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1bd034u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bd038: 0x3e00008  jr          $ra
    ctx->pc = 0x1BD038u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BD03Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD038u;
            // 0x1bd03c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BCF88u: goto label_1bcf88;
            case 0x1BCFA4u: goto label_1bcfa4;
            case 0x1BCFACu: goto label_1bcfac;
            case 0x1BCFC0u: goto label_1bcfc0;
            case 0x1BCFDCu: goto label_1bcfdc;
            case 0x1BCFF8u: goto label_1bcff8;
            case 0x1BD008u: goto label_1bd008;
            case 0x1BD028u: goto label_1bd028;
            case 0x1BD034u: goto label_1bd034;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BD040u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
