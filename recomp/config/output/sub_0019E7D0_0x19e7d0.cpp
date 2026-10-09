#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019E7D0
// Address: 0x19e7d0 - 0x19e910
void sub_0019E7D0_0x19e7d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019E7D0_0x19e7d0");
#endif

    switch (ctx->pc) {
        case 0x19e844u: goto label_19e844;
        case 0x19e860u: goto label_19e860;
        case 0x19e874u: goto label_19e874;
        case 0x19e884u: goto label_19e884;
        case 0x19e8b4u: goto label_19e8b4;
        default: break;
    }

    ctx->pc = 0x19e7d0u;

    // 0x19e7d0: 0x27bddf30  addiu       $sp, $sp, -0x20D0
    ctx->pc = 0x19e7d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294958896));
    // 0x19e7d4: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x19e7d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x19e7d8: 0xffbf0090  sd          $ra, 0x90($sp)
    ctx->pc = 0x19e7d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 31));
    // 0x19e7dc: 0x419c3  sra         $v1, $a0, 7
    ctx->pc = 0x19e7dcu;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 4), 7));
    // 0x19e7e0: 0x7fbe0080  sq          $fp, 0x80($sp)
    ctx->pc = 0x19e7e0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 128), GPR_VEC(ctx, 30));
    // 0x19e7e4: 0x7fb70070  sq          $s7, 0x70($sp)
    ctx->pc = 0x19e7e4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 112), GPR_VEC(ctx, 23));
    // 0x19e7e8: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x19e7e8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x19e7ec: 0xe0b82d  daddu       $s7, $a3, $zero
    ctx->pc = 0x19e7ecu;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19e7f0: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x19e7f0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x19e7f4: 0xc0b02d  daddu       $s6, $a2, $zero
    ctx->pc = 0x19e7f4u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19e7f8: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x19e7f8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x19e7fc: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x19e7fcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x19e800: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x19e800u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19e804: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x19e804u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19e808: 0x4810003  bgez        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x19E808u;
    {
        const bool branch_taken_0x19e808 = (GPR_S64(ctx, 4) >= 0);
        ctx->pc = 0x19E80Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E808u;
            // 0x19e80c: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e808) {
            ctx->pc = 0x19E818u;
            goto label_19e818;
        }
    }
    ctx->pc = 0x19E810u;
    // 0x19e810: 0x2483007f  addiu       $v1, $a0, 0x7F
    ctx->pc = 0x19e810u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 127));
    // 0x19e814: 0x319c3  sra         $v1, $v1, 7
    ctx->pc = 0x19e814u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 7));
label_19e818:
    // 0x19e818: 0x24720001  addiu       $s2, $v1, 0x1
    ctx->pc = 0x19e818u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x19e81c: 0x24a4ffff  addiu       $a0, $a1, -0x1
    ctx->pc = 0x19e81cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x19e820: 0x4810003  bgez        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x19E820u;
    {
        const bool branch_taken_0x19e820 = (GPR_S64(ctx, 4) >= 0);
        ctx->pc = 0x19E824u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E820u;
            // 0x19e824: 0x41983  sra         $v1, $a0, 6 (Delay Slot)
        SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 4), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e820) {
            ctx->pc = 0x19E830u;
            goto label_19e830;
        }
    }
    ctx->pc = 0x19E828u;
    // 0x19e828: 0x2483003f  addiu       $v1, $a0, 0x3F
    ctx->pc = 0x19e828u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 63));
    // 0x19e82c: 0x31983  sra         $v1, $v1, 6
    ctx->pc = 0x19e82cu;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 6));
label_19e830:
    // 0x19e830: 0x247e0001  addiu       $fp, $v1, 0x1
    ctx->pc = 0x19e830u;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x19e834: 0xa82d  daddu       $s5, $zero, $zero
    ctx->pc = 0x19e834u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19e838: 0x1219c0  sll         $v1, $s2, 7
    ctx->pc = 0x19e838u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 18), 7));
    // 0x19e83c: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x19E83Cu;
    {
        const bool branch_taken_0x19e83c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19E840u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E83Cu;
            // 0x19e840: 0xafa300c0  sw          $v1, 0xC0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 192), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e83c) {
            ctx->pc = 0x19E8C8u;
            goto label_19e8c8;
        }
    }
    ctx->pc = 0x19E844u;
label_19e844:
    // 0x19e844: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x19e844u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19e848: 0x2432018  mult        $a0, $s2, $v1
    ctx->pc = 0x19e848u;
    { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x19e84c: 0x2c41821  addu        $v1, $s6, $a0
    ctx->pc = 0x19e84cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 4)));
    // 0x19e850: 0xafa300b0  sw          $v1, 0xB0($sp)
    ctx->pc = 0x19e850u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 176), GPR_U32(ctx, 3));
    // 0x19e854: 0x2e41821  addu        $v1, $s7, $a0
    ctx->pc = 0x19e854u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 4)));
    // 0x19e858: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x19E858u;
    {
        const bool branch_taken_0x19e858 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19E85Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E858u;
            // 0x19e85c: 0xafa300a0  sw          $v1, 0xA0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 160), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e858) {
            ctx->pc = 0x19E8B8u;
            goto label_19e8b8;
        }
    }
    ctx->pc = 0x19E860u;
label_19e860:
    // 0x19e860: 0x8fa200b0  lw          $v0, 0xB0($sp)
    ctx->pc = 0x19e860u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x19e864: 0x1419c0  sll         $v1, $s4, 7
    ctx->pc = 0x19e864u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 20), 7));
    // 0x19e868: 0x27b000d0  addiu       $s0, $sp, 0xD0
    ctx->pc = 0x19e868u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 208));
    // 0x19e86c: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x19e86cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19e870: 0x438821  addu        $s1, $v0, $v1
    ctx->pc = 0x19e870u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_19e874:
    // 0x19e874: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x19e874u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19e878: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x19e878u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19e87c: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x19E87Cu;
    SET_GPR_U32(ctx, 31, 0x19E884u);
    ctx->pc = 0x19E880u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19E87Cu;
            // 0x19e880: 0x24060080  addiu       $a2, $zero, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19E884u; }
        if (ctx->pc != 0x19E884u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19E884u; }
        if (ctx->pc != 0x19E884u) { return; }
    }
    ctx->pc = 0x19E884u;
label_19e884:
    // 0x19e884: 0x8fa200c0  lw          $v0, 0xC0($sp)
    ctx->pc = 0x19e884u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 192)));
    // 0x19e888: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x19e888u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x19e88c: 0x2228821  addu        $s1, $s1, $v0
    ctx->pc = 0x19e88cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x19e890: 0x2a620040  slti        $v0, $s3, 0x40
    ctx->pc = 0x19e890u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)(int32_t)64) ? 1 : 0);
    // 0x19e894: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x19E894u;
    {
        const bool branch_taken_0x19e894 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x19E898u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E894u;
            // 0x19e898: 0x26100080  addiu       $s0, $s0, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 128));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e894) {
            ctx->pc = 0x19E874u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19e874;
        }
    }
    ctx->pc = 0x19E89Cu;
    // 0x19e89c: 0x8fa200a0  lw          $v0, 0xA0($sp)
    ctx->pc = 0x19e89cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x19e8a0: 0x141a00  sll         $v1, $s4, 8
    ctx->pc = 0x19e8a0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 20), 8));
    // 0x19e8a4: 0x27a400d0  addiu       $a0, $sp, 0xD0
    ctx->pc = 0x19e8a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 208));
    // 0x19e8a8: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x19e8a8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19e8ac: 0xc067a44  jal         func_19E910
    ctx->pc = 0x19E8ACu;
    SET_GPR_U32(ctx, 31, 0x19E8B4u);
    ctx->pc = 0x19E8B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19E8ACu;
            // 0x19e8b0: 0x432821  addu        $a1, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x19E910u;
    if (runtime->hasFunction(0x19E910u)) {
        auto targetFn = runtime->lookupFunction(0x19E910u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19E8B4u; }
        if (ctx->pc != 0x19E8B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019E910_0x19e910(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19E8B4u; }
        if (ctx->pc != 0x19E8B4u) { return; }
    }
    ctx->pc = 0x19E8B4u;
label_19e8b4:
    // 0x19e8b4: 0x26940001  addiu       $s4, $s4, 0x1
    ctx->pc = 0x19e8b4u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
label_19e8b8:
    // 0x19e8b8: 0x292182a  slt         $v1, $s4, $s2
    ctx->pc = 0x19e8b8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 20) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x19e8bc: 0x1460ffe8  bnez        $v1, . + 4 + (-0x18 << 2)
    ctx->pc = 0x19E8BCu;
    {
        const bool branch_taken_0x19e8bc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x19e8bc) {
            ctx->pc = 0x19E860u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19e860;
        }
    }
    ctx->pc = 0x19E8C4u;
    // 0x19e8c4: 0x26b50001  addiu       $s5, $s5, 0x1
    ctx->pc = 0x19e8c4u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 1));
label_19e8c8:
    // 0x19e8c8: 0x2be182a  slt         $v1, $s5, $fp
    ctx->pc = 0x19e8c8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 21) < (int64_t)GPR_S64(ctx, 30)) ? 1 : 0);
    // 0x19e8cc: 0x1460ffdd  bnez        $v1, . + 4 + (-0x23 << 2)
    ctx->pc = 0x19E8CCu;
    {
        const bool branch_taken_0x19e8cc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x19E8D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E8CCu;
            // 0x19e8d0: 0x151b40  sll         $v1, $s5, 13 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 21), 13));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19e8cc) {
            ctx->pc = 0x19E844u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19e844;
        }
    }
    ctx->pc = 0x19E8D4u;
    // 0x19e8d4: 0xdfbf0090  ld          $ra, 0x90($sp)
    ctx->pc = 0x19e8d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x19e8d8: 0x7bbe0080  lq          $fp, 0x80($sp)
    ctx->pc = 0x19e8d8u;
    SET_GPR_VEC(ctx, 30, READ128(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x19e8dc: 0x7bb70070  lq          $s7, 0x70($sp)
    ctx->pc = 0x19e8dcu;
    SET_GPR_VEC(ctx, 23, READ128(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x19e8e0: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x19e8e0u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x19e8e4: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x19e8e4u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x19e8e8: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x19e8e8u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x19e8ec: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x19e8ecu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19e8f0: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x19e8f0u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19e8f4: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x19e8f4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19e8f8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19e8f8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19e8fc: 0x3e00008  jr          $ra
    ctx->pc = 0x19E8FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19E900u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19E8FCu;
            // 0x19e900: 0x27bd20d0  addiu       $sp, $sp, 0x20D0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 8400));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19E818u: goto label_19e818;
            case 0x19E830u: goto label_19e830;
            case 0x19E844u: goto label_19e844;
            case 0x19E860u: goto label_19e860;
            case 0x19E874u: goto label_19e874;
            case 0x19E884u: goto label_19e884;
            case 0x19E8B4u: goto label_19e8b4;
            case 0x19E8B8u: goto label_19e8b8;
            case 0x19E8C8u: goto label_19e8c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19E904u;
    // 0x19e904: 0x0  nop
    ctx->pc = 0x19e904u;
    // NOP
    // 0x19e908: 0x0  nop
    ctx->pc = 0x19e908u;
    // NOP
    // 0x19e90c: 0x0  nop
    ctx->pc = 0x19e90cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
