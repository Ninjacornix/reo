#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C5990
// Address: 0x1c5990 - 0x1c59d0
void sub_001C5990_0x1c5990(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C5990_0x1c5990");
#endif

    ctx->pc = 0x1c5990u;

    // 0x1c5990: 0x30a200ff  andi        $v0, $a1, 0xFF
    ctx->pc = 0x1c5990u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x1c5994: 0x30420080  andi        $v0, $v0, 0x80
    ctx->pc = 0x1c5994u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)128);
    // 0x1c5998: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1C5998u;
    {
        const bool branch_taken_0x1c5998 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C599Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5998u;
            // 0x1c599c: 0x24820008  addiu       $v0, $a0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5998) {
            ctx->pc = 0x1C59A4u;
            goto label_1c59a4;
        }
    }
    ctx->pc = 0x1C59A0u;
    // 0x1c59a0: 0x24820018  addiu       $v0, $a0, 0x18
    ctx->pc = 0x1c59a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 24));
label_1c59a4:
    // 0x1c59a4: 0x90430008  lbu         $v1, 0x8($v0)
    ctx->pc = 0x1c59a4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1c59a8: 0x90420009  lbu         $v0, 0x9($v0)
    ctx->pc = 0x1c59a8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 9)));
    // 0x1c59ac: 0x62082a  slt         $at, $v1, $v0
    ctx->pc = 0x1c59acu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1c59b0: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C59B0u;
    {
        const bool branch_taken_0x1c59b0 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c59b0) {
            ctx->pc = 0x1C59C0u;
            goto label_1c59c0;
        }
    }
    ctx->pc = 0x1C59B8u;
    // 0x1c59b8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1C59B8u;
    {
        const bool branch_taken_0x1c59b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C59BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C59B8u;
            // 0x1c59bc: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c59b8) {
            ctx->pc = 0x1C59C4u;
            goto label_1c59c4;
        }
    }
    ctx->pc = 0x1C59C0u;
label_1c59c0:
    // 0x1c59c0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1c59c0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1c59c4:
    // 0x1c59c4: 0x3e00008  jr          $ra
    ctx->pc = 0x1C59C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C59A4u: goto label_1c59a4;
            case 0x1C59C0u: goto label_1c59c0;
            case 0x1C59C4u: goto label_1c59c4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C59CCu;
    // 0x1c59cc: 0x0  nop
    ctx->pc = 0x1c59ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
