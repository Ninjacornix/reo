#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017B888
// Address: 0x17b888 - 0x17b960
void sub_0017B888_0x17b888(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017B888_0x17b888");
#endif

    switch (ctx->pc) {
        case 0x17b8d4u: goto label_17b8d4;
        case 0x17b92cu: goto label_17b92c;
        case 0x17b944u: goto label_17b944;
        default: break;
    }

    ctx->pc = 0x17b888u;

    // 0x17b888: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x17b888u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x17b88c: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x17b88cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x17b890: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x17b890u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b894: 0xffb10038  sd          $s1, 0x38($sp)
    ctx->pc = 0x17b894u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x17b898: 0x26110004  addiu       $s1, $s0, 0x4
    ctx->pc = 0x17b898u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x17b89c: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x17b89cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x17b8a0: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x17b8a0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b8a4: 0xffb30048  sd          $s3, 0x48($sp)
    ctx->pc = 0x17b8a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 19));
    // 0x17b8a8: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x17b8a8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b8ac: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x17b8acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x17b8b0: 0xafa60010  sw          $a2, 0x10($sp)
    ctx->pc = 0x17b8b0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 6));
    // 0x17b8b4: 0x8e050044  lw          $a1, 0x44($s0)
    ctx->pc = 0x17b8b4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x17b8b8: 0x8e020048  lw          $v0, 0x48($s0)
    ctx->pc = 0x17b8b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x17b8bc: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x17b8bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x17b8c0: 0xafa50014  sw          $a1, 0x14($sp)
    ctx->pc = 0x17b8c0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 5));
    // 0x17b8c4: 0xafa30000  sw          $v1, 0x0($sp)
    ctx->pc = 0x17b8c4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
    // 0x17b8c8: 0xafa50004  sw          $a1, 0x4($sp)
    ctx->pc = 0x17b8c8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 5));
    // 0x17b8cc: 0xc05eb6a  jal         func_17ADA8
    ctx->pc = 0x17B8CCu;
    SET_GPR_U32(ctx, 31, 0x17B8D4u);
    ctx->pc = 0x17B8D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B8CCu;
            // 0x17b8d0: 0xafa20008  sw          $v0, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17ADA8u;
    if (runtime->hasFunction(0x17ADA8u)) {
        auto targetFn = runtime->lookupFunction(0x17ADA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B8D4u; }
        if (ctx->pc != 0x17B8D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017ADA8_0x17ada8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B8D4u; }
        if (ctx->pc != 0x17B8D4u) { return; }
    }
    ctx->pc = 0x17B8D4u;
label_17b8d4:
    // 0x17b8d4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x17b8d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17b8d8: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x17b8d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b8dc: 0x27a50010  addiu       $a1, $sp, 0x10
    ctx->pc = 0x17b8dcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x17b8e0: 0x14430007  bne         $v0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x17B8E0u;
    {
        const bool branch_taken_0x17b8e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x17B8E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B8E0u;
            // 0x17b8e4: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b8e0) {
            ctx->pc = 0x17B900u;
            goto label_17b900;
        }
    }
    ctx->pc = 0x17B8E8u;
    // 0x17b8e8: 0x8e020048  lw          $v0, 0x48($s0)
    ctx->pc = 0x17b8e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x17b8ec: 0x21fc2  srl         $v1, $v0, 31
    ctx->pc = 0x17b8ecu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x17b8f0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x17b8f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x17b8f4: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x17B8F4u;
    {
        const bool branch_taken_0x17b8f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17B8F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B8F4u;
            // 0x17b8f8: 0x21043  sra         $v0, $v0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b8f4) {
            ctx->pc = 0x17B904u;
            goto label_17b904;
        }
    }
    ctx->pc = 0x17B8FCu;
    // 0x17b8fc: 0x0  nop
    ctx->pc = 0x17b8fcu;
    // NOP
label_17b900:
    // 0x17b900: 0x8e020048  lw          $v0, 0x48($s0)
    ctx->pc = 0x17b900u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
label_17b904:
    // 0x17b904: 0xafa20018  sw          $v0, 0x18($sp)
    ctx->pc = 0x17b904u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x17b908: 0x8e420008  lw          $v0, 0x8($s2)
    ctx->pc = 0x17b908u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x17b90c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x17B90Cu;
    {
        const bool branch_taken_0x17b90c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x17b90c) {
            ctx->pc = 0x17B91Cu;
            goto label_17b91c;
        }
    }
    ctx->pc = 0x17B914u;
    // 0x17b914: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x17b914u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x17b918: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x17b918u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
label_17b91c:
    // 0x17b91c: 0x16660006  bne         $s3, $a2, . + 4 + (0x6 << 2)
    ctx->pc = 0x17B91Cu;
    {
        const bool branch_taken_0x17b91c = (GPR_U64(ctx, 19) != GPR_U64(ctx, 6));
        ctx->pc = 0x17B920u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B91Cu;
            // 0x17b920: 0xafa2001c  sw          $v0, 0x1C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b91c) {
            ctx->pc = 0x17B938u;
            goto label_17b938;
        }
    }
    ctx->pc = 0x17B924u;
    // 0x17b924: 0xc053db4  jal         func_14F6D0
    ctx->pc = 0x17B924u;
    SET_GPR_U32(ctx, 31, 0x17B92Cu);
    ctx->pc = 0x17B928u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B924u;
            // 0x17b928: 0x8e46003c  lw          $a2, 0x3C($s2) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 60)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x14F6D0u;
    if (runtime->hasFunction(0x14F6D0u)) {
        auto targetFn = runtime->lookupFunction(0x14F6D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B92Cu; }
        if (ctx->pc != 0x17B92Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0014F6D0_0x14f6d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B92Cu; }
        if (ctx->pc != 0x17B92Cu) { return; }
    }
    ctx->pc = 0x17B92Cu;
label_17b92c:
    // 0x17b92c: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x17B92Cu;
    {
        const bool branch_taken_0x17b92c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17B930u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B92Cu;
            // 0x17b930: 0xdfb00030  ld          $s0, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17b92c) {
            ctx->pc = 0x17B948u;
            goto label_17b948;
        }
    }
    ctx->pc = 0x17B934u;
    // 0x17b934: 0x0  nop
    ctx->pc = 0x17b934u;
    // NOP
label_17b938:
    // 0x17b938: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x17b938u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17b93c: 0xc053dac  jal         func_14F6B0
    ctx->pc = 0x17B93Cu;
    SET_GPR_U32(ctx, 31, 0x17B944u);
    ctx->pc = 0x17B940u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17B93Cu;
            // 0x17b940: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x14F6B0u;
    if (runtime->hasFunction(0x14F6B0u)) {
        auto targetFn = runtime->lookupFunction(0x14F6B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B944u; }
        if (ctx->pc != 0x17B944u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0014F6B0_0x14f6b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17B944u; }
        if (ctx->pc != 0x17B944u) { return; }
    }
    ctx->pc = 0x17B944u;
label_17b944:
    // 0x17b944: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x17b944u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_17b948:
    // 0x17b948: 0xdfb10038  ld          $s1, 0x38($sp)
    ctx->pc = 0x17b948u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x17b94c: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x17b94cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x17b950: 0xdfb30048  ld          $s3, 0x48($sp)
    ctx->pc = 0x17b950u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x17b954: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x17b954u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x17b958: 0x3e00008  jr          $ra
    ctx->pc = 0x17B958u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17B95Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17B958u;
            // 0x17b95c: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17B8D4u: goto label_17b8d4;
            case 0x17B900u: goto label_17b900;
            case 0x17B904u: goto label_17b904;
            case 0x17B91Cu: goto label_17b91c;
            case 0x17B92Cu: goto label_17b92c;
            case 0x17B938u: goto label_17b938;
            case 0x17B944u: goto label_17b944;
            case 0x17B948u: goto label_17b948;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17B960u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
