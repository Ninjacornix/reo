#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F4830
// Address: 0x1f4830 - 0x1f4890
void sub_001F4830_0x1f4830(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F4830_0x1f4830");
#endif

    switch (ctx->pc) {
        case 0x1f4858u: goto label_1f4858;
        default: break;
    }

    ctx->pc = 0x1f4830u;

    // 0x1f4830: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1f4830u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1f4834: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1f4834u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1f4838: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1f4838u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1f483c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f483cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f4840: 0x94830034  lhu         $v1, 0x34($a0)
    ctx->pc = 0x1f4840u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 52)));
    // 0x1f4844: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1f4844u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4848: 0x8c820028  lw          $v0, 0x28($a0)
    ctx->pc = 0x1f4848u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 40)));
    // 0x1f484c: 0x432821  addu        $a1, $v0, $v1
    ctx->pc = 0x1f484cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1f4850: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F4850u;
    SET_GPR_U32(ctx, 31, 0x1F4858u);
    ctx->pc = 0x1F4854u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4850u;
            // 0x1f4854: 0x27a4002e  addiu       $a0, $sp, 0x2E (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 46));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4858u; }
        if (ctx->pc != 0x1F4858u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4858u; }
        if (ctx->pc != 0x1F4858u) { return; }
    }
    ctx->pc = 0x1F4858u;
label_1f4858:
    // 0x1f4858: 0x96040034  lhu         $a0, 0x34($s0)
    ctx->pc = 0x1f4858u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 52)));
    // 0x1f485c: 0x97a2002e  lhu         $v0, 0x2E($sp)
    ctx->pc = 0x1f485cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 46)));
    // 0x1f4860: 0x24840002  addiu       $a0, $a0, 0x2
    ctx->pc = 0x1f4860u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2));
    // 0x1f4864: 0xa6040034  sh          $a0, 0x34($s0)
    ctx->pc = 0x1f4864u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 52), (uint16_t)GPR_U32(ctx, 4));
    // 0x1f4868: 0x21a00  sll         $v1, $v0, 8
    ctx->pc = 0x1f4868u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1f486c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1f486cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f4870: 0x21203  sra         $v0, $v0, 8
    ctx->pc = 0x1f4870u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 8));
    // 0x1f4874: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f4874u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f4878: 0x3063ff00  andi        $v1, $v1, 0xFF00
    ctx->pc = 0x1f4878u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65280);
    // 0x1f487c: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1f487cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1f4880: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x1f4880u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1f4884: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1f4884u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1f4888: 0x3e00008  jr          $ra
    ctx->pc = 0x1F4888u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F488Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4888u;
            // 0x1f488c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F4858u: goto label_1f4858;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F4890u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
