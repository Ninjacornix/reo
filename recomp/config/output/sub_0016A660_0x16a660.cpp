#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016A660
// Address: 0x16a660 - 0x16a7c0
void sub_0016A660_0x16a660(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016A660_0x16a660");
#endif

    switch (ctx->pc) {
        case 0x16a6b8u: goto label_16a6b8;
        case 0x16a6ccu: goto label_16a6cc;
        case 0x16a6f8u: goto label_16a6f8;
        case 0x16a750u: goto label_16a750;
        case 0x16a774u: goto label_16a774;
        default: break;
    }

    ctx->pc = 0x16a660u;

    // 0x16a660: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x16a660u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x16a664: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x16a664u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x16a668: 0x100982d  daddu       $s3, $t0, $zero
    ctx->pc = 0x16a668u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a66c: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x16a66cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x16a670: 0xe0a02d  daddu       $s4, $a3, $zero
    ctx->pc = 0x16a670u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a674: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x16a674u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x16a678: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x16a678u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a67c: 0xffb50048  sd          $s5, 0x48($sp)
    ctx->pc = 0x16a67cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 21));
    // 0x16a680: 0xc0a82d  daddu       $s5, $a2, $zero
    ctx->pc = 0x16a680u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a684: 0xffb60050  sd          $s6, 0x50($sp)
    ctx->pc = 0x16a684u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 22));
    // 0x16a688: 0xb02d  daddu       $s6, $zero, $zero
    ctx->pc = 0x16a688u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a68c: 0xffb70058  sd          $s7, 0x58($sp)
    ctx->pc = 0x16a68cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 23));
    // 0x16a690: 0xa0b82d  daddu       $s7, $a1, $zero
    ctx->pc = 0x16a690u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a694: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x16a694u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x16a698: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x16a698u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a69c: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x16a69cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x16a6a0: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x16a6a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x16a6a4: 0xae800000  sw          $zero, 0x0($s4)
    ctx->pc = 0x16a6a4u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 0));
    // 0x16a6a8: 0xae600000  sw          $zero, 0x0($s3)
    ctx->pc = 0x16a6a8u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 0));
    // 0x16a6ac: 0x8e511aec  lw          $s1, 0x1AEC($s2)
    ctx->pc = 0x16a6acu;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 6892)));
    // 0x16a6b0: 0xc055fe2  jal         func_157F88
    ctx->pc = 0x16A6B0u;
    SET_GPR_U32(ctx, 31, 0x16A6B8u);
    ctx->pc = 0x16A6B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A6B0u;
            // 0x16a6b4: 0x8e240000  lw          $a0, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x157F88u;
    if (runtime->hasFunction(0x157F88u)) {
        auto targetFn = runtime->lookupFunction(0x157F88u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A6B8u; }
        if (ctx->pc != 0x16A6B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00157F88_0x157f88(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A6B8u; }
        if (ctx->pc != 0x16A6B8u) { return; }
    }
    ctx->pc = 0x16A6B8u;
label_16a6b8:
    // 0x16a6b8: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x16A6B8u;
    {
        const bool branch_taken_0x16a6b8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16A6BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A6B8u;
            // 0x16a6bc: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a6b8) {
            ctx->pc = 0x16A6D0u;
            goto label_16a6d0;
        }
    }
    ctx->pc = 0x16A6C0u;
    // 0x16a6c0: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16a6c0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x16a6c4: 0xc05a704  jal         func_169C10
    ctx->pc = 0x16A6C4u;
    SET_GPR_U32(ctx, 31, 0x16A6CCu);
    ctx->pc = 0x16A6C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A6C4u;
            // 0x16a6c8: 0x34a50d06  ori         $a1, $a1, 0xD06 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3334);
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A6CCu; }
        if (ctx->pc != 0x16A6CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A6CCu; }
        if (ctx->pc != 0x16A6CCu) { return; }
    }
    ctx->pc = 0x16A6CCu;
label_16a6cc:
    // 0x16a6cc: 0x40b02d  daddu       $s6, $v0, $zero
    ctx->pc = 0x16a6ccu;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_16a6d0:
    // 0x16a6d0: 0x8fb0001c  lw          $s0, 0x1C($sp)
    ctx->pc = 0x16a6d0u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x16a6d4: 0x8fa70000  lw          $a3, 0x0($sp)
    ctx->pc = 0x16a6d4u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16a6d8: 0x8fa60004  lw          $a2, 0x4($sp)
    ctx->pc = 0x16a6d8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x16a6dc: 0x8fa50008  lw          $a1, 0x8($sp)
    ctx->pc = 0x16a6dcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16a6e0: 0x6010007  bgez        $s0, . + 4 + (0x7 << 2)
    ctx->pc = 0x16A6E0u;
    {
        const bool branch_taken_0x16a6e0 = (GPR_S64(ctx, 16) >= 0);
        ctx->pc = 0x16A6E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A6E0u;
            // 0x16a6e4: 0x8fa80014  lw          $t0, 0x14($sp) (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a6e0) {
            ctx->pc = 0x16A700u;
            goto label_16a700;
        }
    }
    ctx->pc = 0x16A6E8u;
    // 0x16a6e8: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16a6e8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x16a6ec: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x16a6ecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a6f0: 0xc05a704  jal         func_169C10
    ctx->pc = 0x16A6F0u;
    SET_GPR_U32(ctx, 31, 0x16A6F8u);
    ctx->pc = 0x16A6F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A6F0u;
            // 0x16a6f4: 0x34a50d0e  ori         $a1, $a1, 0xD0E (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3342);
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A6F8u; }
        if (ctx->pc != 0x16A6F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A6F8u; }
        if (ctx->pc != 0x16A6F8u) { return; }
    }
    ctx->pc = 0x16A6F8u;
label_16a6f8:
    // 0x16a6f8: 0x10000027  b           . + 4 + (0x27 << 2)
    ctx->pc = 0x16A6F8u;
    {
        const bool branch_taken_0x16a6f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16A6FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A6F8u;
            // 0x16a6fc: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a6f8) {
            ctx->pc = 0x16A798u;
            goto label_16a798;
        }
    }
    ctx->pc = 0x16A700u;
label_16a700:
    // 0x16a700: 0x16000007  bnez        $s0, . + 4 + (0x7 << 2)
    ctx->pc = 0x16A700u;
    {
        const bool branch_taken_0x16a700 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x16A704u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A700u;
            // 0x16a704: 0x2b0182a  slt         $v1, $s5, $s0 (Delay Slot)
        SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 21) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a700) {
            ctx->pc = 0x16A720u;
            goto label_16a720;
        }
    }
    ctx->pc = 0x16A708u;
    // 0x16a708: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x16a708u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16a70c: 0xae800000  sw          $zero, 0x0($s4)
    ctx->pc = 0x16a70cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 0));
    // 0x16a710: 0xae620000  sw          $v0, 0x0($s3)
    ctx->pc = 0x16a710u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x16a714: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x16A714u;
    {
        const bool branch_taken_0x16a714 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16A718u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A714u;
            // 0x16a718: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a714) {
            ctx->pc = 0x16A794u;
            goto label_16a794;
        }
    }
    ctx->pc = 0x16A71Cu;
    // 0x16a71c: 0x0  nop
    ctx->pc = 0x16a71cu;
    // NOP
label_16a720:
    // 0x16a720: 0x1460001c  bnez        $v1, . + 4 + (0x1C << 2)
    ctx->pc = 0x16A720u;
    {
        const bool branch_taken_0x16a720 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x16A724u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A720u;
            // 0x16a724: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a720) {
            ctx->pc = 0x16A794u;
            goto label_16a794;
        }
    }
    ctx->pc = 0x16A728u;
    // 0x16a728: 0x71080  sll         $v0, $a3, 2
    ctx->pc = 0x16a728u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 2));
    // 0x16a72c: 0x511021  addu        $v0, $v0, $s1
    ctx->pc = 0x16a72cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x16a730: 0x8c44fd44  lw          $a0, -0x2BC($v0)
    ctx->pc = 0x16a730u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294966596)));
    // 0x16a734: 0x50800008  beql        $a0, $zero, . + 4 + (0x8 << 2)
    ctx->pc = 0x16A734u;
    {
        const bool branch_taken_0x16a734 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x16a734) {
            ctx->pc = 0x16A738u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16A734u;
            // 0x16a738: 0x61880  sll         $v1, $a2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16A758u;
            goto label_16a758;
        }
    }
    ctx->pc = 0x16A73Cu;
    // 0x16a73c: 0x8e260148  lw          $a2, 0x148($s1)
    ctx->pc = 0x16a73cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 328)));
    // 0x16a740: 0x2e0402d  daddu       $t0, $s7, $zero
    ctx->pc = 0x16a740u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a744: 0x8e250144  lw          $a1, 0x144($s1)
    ctx->pc = 0x16a744u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 324)));
    // 0x16a748: 0xc05a9f0  jal         func_16A7C0
    ctx->pc = 0x16A748u;
    SET_GPR_U32(ctx, 31, 0x16A750u);
    ctx->pc = 0x16A74Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A748u;
            // 0x16a74c: 0x200482d  daddu       $t1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16A7C0u;
    if (runtime->hasFunction(0x16A7C0u)) {
        auto targetFn = runtime->lookupFunction(0x16A7C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A750u; }
        if (ctx->pc != 0x16A750u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016A7C0_0x16a7c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A750u; }
        if (ctx->pc != 0x16A750u) { return; }
    }
    ctx->pc = 0x16A750u;
label_16a750:
    // 0x16a750: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x16A750u;
    {
        const bool branch_taken_0x16a750 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16A754u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A750u;
            // 0x16a754: 0xae620000  sw          $v0, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a750) {
            ctx->pc = 0x16A778u;
            goto label_16a778;
        }
    }
    ctx->pc = 0x16A758u;
label_16a758:
    // 0x16a758: 0x2e0302d  daddu       $a2, $s7, $zero
    ctx->pc = 0x16a758u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a75c: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x16a75cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x16a760: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x16a760u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x16a764: 0x8c420850  lw          $v0, 0x850($v0)
    ctx->pc = 0x16a764u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 2128)));
    // 0x16a768: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x16a768u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a76c: 0x40f809  jalr        $v0
    ctx->pc = 0x16A76Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x16A774u);
        ctx->pc = 0x16A770u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A76Cu;
            // 0x16a770: 0x200382d  daddu       $a3, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x16A774u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16A6B8u: goto label_16a6b8;
            case 0x16A6CCu: goto label_16a6cc;
            case 0x16A6D0u: goto label_16a6d0;
            case 0x16A6F8u: goto label_16a6f8;
            case 0x16A700u: goto label_16a700;
            case 0x16A720u: goto label_16a720;
            case 0x16A750u: goto label_16a750;
            case 0x16A758u: goto label_16a758;
            case 0x16A774u: goto label_16a774;
            case 0x16A778u: goto label_16a778;
            case 0x16A790u: goto label_16a790;
            case 0x16A794u: goto label_16a794;
            case 0x16A798u: goto label_16a798;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x16A774u; }
            if (ctx->pc != 0x16A774u) { return; }
        }
        }
    }
    ctx->pc = 0x16A774u;
label_16a774:
    // 0x16a774: 0xae620000  sw          $v0, 0x0($s3)
    ctx->pc = 0x16a774u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
label_16a778:
    // 0x16a778: 0x8e680000  lw          $t0, 0x0($s3)
    ctx->pc = 0x16a778u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x16a77c: 0x11000004  beqz        $t0, . + 4 + (0x4 << 2)
    ctx->pc = 0x16A77Cu;
    {
        const bool branch_taken_0x16a77c = (GPR_U64(ctx, 8) == GPR_U64(ctx, 0));
        ctx->pc = 0x16A780u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A77Cu;
            // 0x16a780: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a77c) {
            ctx->pc = 0x16A790u;
            goto label_16a790;
        }
    }
    ctx->pc = 0x16A784u;
    // 0x16a784: 0x55020002  bnel        $t0, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x16A784u;
    {
        const bool branch_taken_0x16a784 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 2));
        if (branch_taken_0x16a784) {
            ctx->pc = 0x16A788u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16A784u;
            // 0x16a788: 0x100b02d  daddu       $s6, $t0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16A790u;
            goto label_16a790;
        }
    }
    ctx->pc = 0x16A78Cu;
    // 0x16a78c: 0xae900000  sw          $s0, 0x0($s4)
    ctx->pc = 0x16a78cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 16));
label_16a790:
    // 0x16a790: 0x2c0102d  daddu       $v0, $s6, $zero
    ctx->pc = 0x16a790u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
label_16a794:
    // 0x16a794: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x16a794u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_16a798:
    // 0x16a798: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x16a798u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16a79c: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x16a79cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16a7a0: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x16a7a0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x16a7a4: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x16a7a4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x16a7a8: 0xdfb50048  ld          $s5, 0x48($sp)
    ctx->pc = 0x16a7a8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x16a7ac: 0xdfb60050  ld          $s6, 0x50($sp)
    ctx->pc = 0x16a7acu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x16a7b0: 0xdfb70058  ld          $s7, 0x58($sp)
    ctx->pc = 0x16a7b0u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x16a7b4: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x16a7b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x16a7b8: 0x3e00008  jr          $ra
    ctx->pc = 0x16A7B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16A7BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A7B8u;
            // 0x16a7bc: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16A6B8u: goto label_16a6b8;
            case 0x16A6CCu: goto label_16a6cc;
            case 0x16A6D0u: goto label_16a6d0;
            case 0x16A6F8u: goto label_16a6f8;
            case 0x16A700u: goto label_16a700;
            case 0x16A720u: goto label_16a720;
            case 0x16A750u: goto label_16a750;
            case 0x16A758u: goto label_16a758;
            case 0x16A774u: goto label_16a774;
            case 0x16A778u: goto label_16a778;
            case 0x16A790u: goto label_16a790;
            case 0x16A794u: goto label_16a794;
            case 0x16A798u: goto label_16a798;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16A7C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
