#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00111828
// Address: 0x111828 - 0x111888
void sub_00111828_0x111828(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00111828_0x111828");
#endif

    ctx->pc = 0x111828u;

    // 0x111828: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x111828u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x11182c: 0x3c04007f  lui         $a0, 0x7F
    ctx->pc = 0x11182cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)127 << 16));
    // 0x111830: 0x3484ffff  ori         $a0, $a0, 0xFFFF
    ctx->pc = 0x111830u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)65535);
    // 0x111834: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x111834u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111838: 0x315c2  srl         $v0, $v1, 23
    ctx->pc = 0x111838u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 23));
    // 0x11183c: 0x32fc2  srl         $a1, $v1, 31
    ctx->pc = 0x11183cu;
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x111840: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x111840u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x111844: 0x641824  and         $v1, $v1, $a0
    ctx->pc = 0x111844u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x111848: 0xacc50004  sw          $a1, 0x4($a2)
    ctx->pc = 0x111848u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 5));
    // 0x11184c: 0x2445ff81  addiu       $a1, $v0, -0x7F
    ctx->pc = 0x11184cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967169));
    // 0x111850: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x111850u;
    {
        const bool branch_taken_0x111850 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x111854u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111850u;
            // 0x111854: 0x321c0  sll         $a0, $v1, 7 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x111850) {
            ctx->pc = 0x111868u;
            goto label_111868;
        }
    }
    ctx->pc = 0x111858u;
    // 0x111858: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x111858u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x11185c: 0x3e00008  jr          $ra
    ctx->pc = 0x11185Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x111860u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11185Cu;
            // 0x111860: 0xacc20000  sw          $v0, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x111868u: goto label_111868;
            default: break;
        }
        return;
    }
    ctx->pc = 0x111864u;
    // 0x111864: 0x0  nop
    ctx->pc = 0x111864u;
    // NOP
label_111868:
    // 0x111868: 0x3c024000  lui         $v0, 0x4000
    ctx->pc = 0x111868u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16384 << 16));
    // 0x11186c: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x11186cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x111870: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x111870u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x111874: 0xacc50008  sw          $a1, 0x8($a2)
    ctx->pc = 0x111874u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 5));
    // 0x111878: 0xacc30000  sw          $v1, 0x0($a2)
    ctx->pc = 0x111878u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 3));
    // 0x11187c: 0x3e00008  jr          $ra
    ctx->pc = 0x11187Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x111880u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11187Cu;
            // 0x111880: 0xacc2000c  sw          $v0, 0xC($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 12), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x111868u: goto label_111868;
            default: break;
        }
        return;
    }
    ctx->pc = 0x111884u;
    // 0x111884: 0x0  nop
    ctx->pc = 0x111884u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
