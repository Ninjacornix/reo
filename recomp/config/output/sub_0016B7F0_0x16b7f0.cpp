#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016B7F0
// Address: 0x16b7f0 - 0x16b8b4
void sub_0016B7F0_0x16b7f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016B7F0_0x16b7f0");
#endif

    switch (ctx->pc) {
        case 0x16b818u: goto label_16b818;
        case 0x16b820u: goto label_16b820;
        case 0x16b860u: goto label_16b860;
        case 0x16b870u: goto label_16b870;
        default: break;
    }

    ctx->pc = 0x16b7f0u;

    // 0x16b7f0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x16b7f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16b7f4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16b7f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16b7f8: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x16b7f8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b7fc: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16b7fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x16b800: 0x26321d04  addiu       $s2, $s1, 0x1D04
    ctx->pc = 0x16b800u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 17), 7428));
    // 0x16b804: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16b804u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16b808: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x16b808u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b80c: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x16b80cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x16b810: 0xc05ae2e  jal         func_16B8B8
    ctx->pc = 0x16B810u;
    SET_GPR_U32(ctx, 31, 0x16B818u);
    ctx->pc = 0x16B814u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B810u;
            // 0x16b814: 0xae321aec  sw          $s2, 0x1AEC($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 6892), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16B8B8u;
    if (runtime->hasFunction(0x16B8B8u)) {
        auto targetFn = runtime->lookupFunction(0x16B8B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B818u; }
        if (ctx->pc != 0x16B818u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016B8B8_0x16b8b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B818u; }
        if (ctx->pc != 0x16B818u) { return; }
    }
    ctx->pc = 0x16B818u;
label_16b818:
    // 0x16b818: 0xc0560fc  jal         func_1583F0
    ctx->pc = 0x16B818u;
    SET_GPR_U32(ctx, 31, 0x16B820u);
    ctx->pc = 0x1583F0u;
    if (runtime->hasFunction(0x1583F0u)) {
        auto targetFn = runtime->lookupFunction(0x1583F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B820u; }
        if (ctx->pc != 0x16B820u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001583F0_0x1583f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B820u; }
        if (ctx->pc != 0x16B820u) { return; }
    }
    ctx->pc = 0x16B820u;
label_16b820:
    // 0x16b820: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x16b820u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b824: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16b824u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x16b828: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x16b828u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b82c: 0x34a50d08  ori         $a1, $a1, 0xD08
    ctx->pc = 0x16b82cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3336);
    // 0x16b830: 0x16000007  bnez        $s0, . + 4 + (0x7 << 2)
    ctx->pc = 0x16B830u;
    {
        const bool branch_taken_0x16b830 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x16B834u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B830u;
            // 0x16b834: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16b830) {
            ctx->pc = 0x16B850u;
            goto label_16b850;
        }
    }
    ctx->pc = 0x16B838u;
    // 0x16b838: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16b838u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16b83c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16b83cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16b840: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16b840u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16b844: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x16b844u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16b848: 0x805a704  j           func_169C10
    ctx->pc = 0x16B848u;
    ctx->pc = 0x16B84Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B848u;
            // 0x16b84c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16B850u;
label_16b850:
    // 0x16b850: 0x3c050017  lui         $a1, 0x17
    ctx->pc = 0x16b850u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)23 << 16));
    // 0x16b854: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16b854u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b858: 0xc0560a0  jal         func_158280
    ctx->pc = 0x16B858u;
    SET_GPR_U32(ctx, 31, 0x16B860u);
    ctx->pc = 0x16B85Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B858u;
            // 0x16b85c: 0x24a5b928  addiu       $a1, $a1, -0x46D8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294949160));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158280u;
    if (runtime->hasFunction(0x158280u)) {
        auto targetFn = runtime->lookupFunction(0x158280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B860u; }
        if (ctx->pc != 0x16B860u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00158280_0x158280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B860u; }
        if (ctx->pc != 0x16B860u) { return; }
    }
    ctx->pc = 0x16B860u;
label_16b860:
    // 0x16b860: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x16B860u;
    {
        const bool branch_taken_0x16b860 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16B864u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B860u;
            // 0x16b864: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16b860) {
            ctx->pc = 0x16B898u;
            goto label_16b898;
        }
    }
    ctx->pc = 0x16B868u;
    // 0x16b868: 0xc05ae64  jal         func_16B990
    ctx->pc = 0x16B868u;
    SET_GPR_U32(ctx, 31, 0x16B870u);
    ctx->pc = 0x16B990u;
    if (runtime->hasFunction(0x16B990u)) {
        auto targetFn = runtime->lookupFunction(0x16B990u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B870u; }
        if (ctx->pc != 0x16B870u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016B990_0x16b990(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B870u; }
        if (ctx->pc != 0x16B870u) { return; }
    }
    ctx->pc = 0x16B870u;
label_16b870:
    // 0x16b870: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x16b870u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b874: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16b874u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x16b878: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16b878u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16b87c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16b87cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16b880: 0x34a50d09  ori         $a1, $a1, 0xD09
    ctx->pc = 0x16b880u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3337);
    // 0x16b884: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16b884u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16b888: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x16b888u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16b88c: 0x805a704  j           func_169C10
    ctx->pc = 0x16B88Cu;
    ctx->pc = 0x16B890u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B88Cu;
            // 0x16b890: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16B894u;
    // 0x16b894: 0x0  nop
    ctx->pc = 0x16b894u;
    // NOP
label_16b898:
    // 0x16b898: 0xae500000  sw          $s0, 0x0($s2)
    ctx->pc = 0x16b898u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 16));
    // 0x16b89c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16b89cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16b8a0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16b8a0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16b8a4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16b8a4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16b8a8: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x16b8a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16b8ac: 0x3e00008  jr          $ra
    ctx->pc = 0x16B8ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16B8B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B8ACu;
            // 0x16b8b0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16B818u: goto label_16b818;
            case 0x16B820u: goto label_16b820;
            case 0x16B850u: goto label_16b850;
            case 0x16B860u: goto label_16b860;
            case 0x16B870u: goto label_16b870;
            case 0x16B898u: goto label_16b898;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16B8B4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
