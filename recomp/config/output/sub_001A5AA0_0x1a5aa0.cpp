#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A5AA0
// Address: 0x1a5aa0 - 0x1a5b10
void sub_001A5AA0_0x1a5aa0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A5AA0_0x1a5aa0");
#endif

    switch (ctx->pc) {
        case 0x1a5b00u: goto label_1a5b00;
        default: break;
    }

    ctx->pc = 0x1a5aa0u;

    // 0x1a5aa0: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x1a5aa0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1a5aa4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1a5aa4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a5aa8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a5aa8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a5aac: 0x28620008  slti        $v0, $v1, 0x8
    ctx->pc = 0x1a5aacu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x1a5ab0: 0xafa40018  sw          $a0, 0x18($sp)
    ctx->pc = 0x1a5ab0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 4));
    // 0x1a5ab4: 0xffa50028  sd          $a1, 0x28($sp)
    ctx->pc = 0x1a5ab4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 5));
    // 0x1a5ab8: 0xffa60030  sd          $a2, 0x30($sp)
    ctx->pc = 0x1a5ab8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 6));
    // 0x1a5abc: 0xffa70038  sd          $a3, 0x38($sp)
    ctx->pc = 0x1a5abcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 7));
    // 0x1a5ac0: 0xffa80040  sd          $t0, 0x40($sp)
    ctx->pc = 0x1a5ac0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 8));
    // 0x1a5ac4: 0xffa90048  sd          $t1, 0x48($sp)
    ctx->pc = 0x1a5ac4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 9));
    // 0x1a5ac8: 0xffaa0050  sd          $t2, 0x50($sp)
    ctx->pc = 0x1a5ac8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 10));
    // 0x1a5acc: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A5ACCu;
    {
        const bool branch_taken_0x1a5acc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A5AD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5ACCu;
            // 0x1a5ad0: 0xffab0058  sd          $t3, 0x58($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 11));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a5acc) {
            ctx->pc = 0x1A5ADCu;
            goto label_1a5adc;
        }
    }
    ctx->pc = 0x1A5AD4u;
    // 0x1a5ad4: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1A5AD4u;
    {
        const bool branch_taken_0x1a5ad4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A5AD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5AD4u;
            // 0x1a5ad8: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a5ad4) {
            ctx->pc = 0x1A5AE8u;
            goto label_1a5ae8;
        }
    }
    ctx->pc = 0x1A5ADCu;
label_1a5adc:
    // 0x1a5adc: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x1a5adcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1a5ae0: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x1a5ae0u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a5ae4: 0x218c0  sll         $v1, $v0, 3
    ctx->pc = 0x1a5ae4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
label_1a5ae8:
    // 0x1a5ae8: 0x8fa50018  lw          $a1, 0x18($sp)
    ctx->pc = 0x1a5ae8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1a5aec: 0x27a20060  addiu       $v0, $sp, 0x60
    ctx->pc = 0x1a5aecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1a5af0: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a5af0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a5af4: 0x433023  subu        $a2, $v0, $v1
    ctx->pc = 0x1a5af4u;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a5af8: 0xc043e20  jal         func_10F880
    ctx->pc = 0x1A5AF8u;
    SET_GPR_U32(ctx, 31, 0x1A5B00u);
    ctx->pc = 0x1A5AFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5AF8u;
            // 0x1a5afc: 0x24840000  addiu       $a0, $a0, 0x0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10F880u;
    if (runtime->hasFunction(0x10F880u)) {
        auto targetFn = runtime->lookupFunction(0x10F880u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5B00u; }
        if (ctx->pc != 0x1A5B00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010F880_0x10f880(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5B00u; }
        if (ctx->pc != 0x1A5B00u) { return; }
    }
    ctx->pc = 0x1A5B00u;
label_1a5b00:
    // 0x1a5b00: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a5b00u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a5b04: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1a5b04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a5b08: 0x3e00008  jr          $ra
    ctx->pc = 0x1A5B08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A5B0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5B08u;
            // 0x1a5b0c: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A5ADCu: goto label_1a5adc;
            case 0x1A5AE8u: goto label_1a5ae8;
            case 0x1A5B00u: goto label_1a5b00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A5B10u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
