#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00169068
// Address: 0x169068 - 0x169098
void sub_00169068_0x169068(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00169068_0x169068");
#endif

    ctx->pc = 0x169068u;

    // 0x169068: 0x90820000  lbu         $v0, 0x0($a0)
    ctx->pc = 0x169068u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x16906c: 0x90830001  lbu         $v1, 0x1($a0)
    ctx->pc = 0x16906cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x169070: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x169070u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x169074: 0x90850002  lbu         $a1, 0x2($a0)
    ctx->pc = 0x169074u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x169078: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x169078u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x16907c: 0x90860003  lbu         $a2, 0x3($a0)
    ctx->pc = 0x16907cu;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3)));
    // 0x169080: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x169080u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x169084: 0x451025  or          $v0, $v0, $a1
    ctx->pc = 0x169084u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 5));
    // 0x169088: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x169088u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x16908c: 0x3e00008  jr          $ra
    ctx->pc = 0x16908Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x169090u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16908Cu;
            // 0x169090: 0x461025  or          $v0, $v0, $a2 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 6));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x169094u;
    // 0x169094: 0x0  nop
    ctx->pc = 0x169094u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
