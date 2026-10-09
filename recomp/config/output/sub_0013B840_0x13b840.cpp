#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013B840
// Address: 0x13b840 - 0x13b8d4
void sub_0013B840_0x13b840(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013B840_0x13b840");
#endif

    switch (ctx->pc) {
        case 0x13b85cu: goto label_13b85c;
        default: break;
    }

    ctx->pc = 0x13b840u;

    // 0x13b840: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13b840u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13b844: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x13b844u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b848: 0x14e00007  bnez        $a3, . + 4 + (0x7 << 2)
    ctx->pc = 0x13B848u;
    {
        const bool branch_taken_0x13b848 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        ctx->pc = 0x13B84Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B848u;
            // 0x13b84c: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b848) {
            ctx->pc = 0x13B868u;
            goto label_13b868;
        }
    }
    ctx->pc = 0x13B850u;
    // 0x13b850: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x13b850u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x13b854: 0xc04ebf2  jal         func_13AFC8
    ctx->pc = 0x13B854u;
    SET_GPR_U32(ctx, 31, 0x13B85Cu);
    ctx->pc = 0x13B858u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B854u;
            // 0x13b858: 0x24a5d0b0  addiu       $a1, $a1, -0x2F50 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294955184));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13AFC8u;
    if (runtime->hasFunction(0x13AFC8u)) {
        auto targetFn = runtime->lookupFunction(0x13AFC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B85Cu; }
        if (ctx->pc != 0x13B85Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013AFC8_0x13afc8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B85Cu; }
        if (ctx->pc != 0x13B85Cu) { return; }
    }
    ctx->pc = 0x13B85Cu;
label_13b85c:
    // 0x13b85c: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x13B85Cu;
    {
        const bool branch_taken_0x13b85c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13B860u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B85Cu;
            // 0x13b860: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b85c) {
            ctx->pc = 0x13B8C8u;
            goto label_13b8c8;
        }
    }
    ctx->pc = 0x13B864u;
    // 0x13b864: 0x0  nop
    ctx->pc = 0x13b864u;
    // NOP
label_13b868:
    // 0x13b868: 0x14c00003  bnez        $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x13B868u;
    {
        const bool branch_taken_0x13b868 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x13B86Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B868u;
            // 0x13b86c: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b868) {
            ctx->pc = 0x13B878u;
            goto label_13b878;
        }
    }
    ctx->pc = 0x13B870u;
    // 0x13b870: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x13B870u;
    {
        const bool branch_taken_0x13b870 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13B874u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B870u;
            // 0x13b874: 0xace5001c  sw          $a1, 0x1C($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 28), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b870) {
            ctx->pc = 0x13B8A8u;
            goto label_13b8a8;
        }
    }
    ctx->pc = 0x13B878u;
label_13b878:
    // 0x13b878: 0x14c20005  bne         $a2, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x13B878u;
    {
        const bool branch_taken_0x13b878 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 2));
        ctx->pc = 0x13B87Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B878u;
            // 0x13b87c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b878) {
            ctx->pc = 0x13B890u;
            goto label_13b890;
        }
    }
    ctx->pc = 0x13B880u;
    // 0x13b880: 0x8ce40010  lw          $a0, 0x10($a3)
    ctx->pc = 0x13b880u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 16)));
    // 0x13b884: 0x851021  addu        $v0, $a0, $a1
    ctx->pc = 0x13b884u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x13b888: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x13B888u;
    {
        const bool branch_taken_0x13b888 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13B88Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B888u;
            // 0x13b88c: 0xace2001c  sw          $v0, 0x1C($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 28), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b888) {
            ctx->pc = 0x13B8ACu;
            goto label_13b8ac;
        }
    }
    ctx->pc = 0x13B890u;
label_13b890:
    // 0x13b890: 0x14c20006  bne         $a2, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x13B890u;
    {
        const bool branch_taken_0x13b890 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 2));
        ctx->pc = 0x13B894u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B890u;
            // 0x13b894: 0x8ce40010  lw          $a0, 0x10($a3) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b890) {
            ctx->pc = 0x13B8ACu;
            goto label_13b8ac;
        }
    }
    ctx->pc = 0x13B898u;
    // 0x13b898: 0x8ce2001c  lw          $v0, 0x1C($a3)
    ctx->pc = 0x13b898u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 28)));
    // 0x13b89c: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x13b89cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x13b8a0: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x13B8A0u;
    {
        const bool branch_taken_0x13b8a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13B8A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B8A0u;
            // 0x13b8a4: 0xace2001c  sw          $v0, 0x1C($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 28), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b8a0) {
            ctx->pc = 0x13B8ACu;
            goto label_13b8ac;
        }
    }
    ctx->pc = 0x13B8A8u;
label_13b8a8:
    // 0x13b8a8: 0x8ce40010  lw          $a0, 0x10($a3)
    ctx->pc = 0x13b8a8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 16)));
label_13b8ac:
    // 0x13b8ac: 0x8ce2001c  lw          $v0, 0x1C($a3)
    ctx->pc = 0x13b8acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 28)));
    // 0x13b8b0: 0xace00028  sw          $zero, 0x28($a3)
    ctx->pc = 0x13b8b0u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 40), GPR_U32(ctx, 0));
    // 0x13b8b4: 0x44182a  slt         $v1, $v0, $a0
    ctx->pc = 0x13b8b4u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x13b8b8: 0x83100a  movz        $v0, $a0, $v1
    ctx->pc = 0x13b8b8u;
    if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 4));
    // 0x13b8bc: 0x28440000  slti        $a0, $v0, 0x0
    ctx->pc = 0x13b8bcu;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x13b8c0: 0x4100b  movn        $v0, $zero, $a0
    ctx->pc = 0x13b8c0u;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 0));
    // 0x13b8c4: 0xace2001c  sw          $v0, 0x1C($a3)
    ctx->pc = 0x13b8c4u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 28), GPR_U32(ctx, 2));
label_13b8c8:
    // 0x13b8c8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13b8c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13b8cc: 0x3e00008  jr          $ra
    ctx->pc = 0x13B8CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13B8D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B8CCu;
            // 0x13b8d0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13B85Cu: goto label_13b85c;
            case 0x13B868u: goto label_13b868;
            case 0x13B878u: goto label_13b878;
            case 0x13B890u: goto label_13b890;
            case 0x13B8A8u: goto label_13b8a8;
            case 0x13B8ACu: goto label_13b8ac;
            case 0x13B8C8u: goto label_13b8c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13B8D4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
