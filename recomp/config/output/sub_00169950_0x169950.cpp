#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00169950
// Address: 0x169950 - 0x169980
void sub_00169950_0x169950(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00169950_0x169950");
#endif

    ctx->pc = 0x169950u;

    // 0x169950: 0x24850098  addiu       $a1, $a0, 0x98
    ctx->pc = 0x169950u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), 152));
    // 0x169954: 0x2484090c  addiu       $a0, $a0, 0x90C
    ctx->pc = 0x169954u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2316));
    // 0x169958: 0x8ca20004  lw          $v0, 0x4($a1)
    ctx->pc = 0x169958u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x16995c: 0xac820024  sw          $v0, 0x24($a0)
    ctx->pc = 0x16995cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 36), GPR_U32(ctx, 2));
    // 0x169960: 0x8ca30008  lw          $v1, 0x8($a1)
    ctx->pc = 0x169960u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x169964: 0xac830028  sw          $v1, 0x28($a0)
    ctx->pc = 0x169964u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 40), GPR_U32(ctx, 3));
    // 0x169968: 0x8ca2000c  lw          $v0, 0xC($a1)
    ctx->pc = 0x169968u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 12)));
    // 0x16996c: 0x3e00008  jr          $ra
    ctx->pc = 0x16996Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x169970u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16996Cu;
            // 0x169970: 0xac82002c  sw          $v0, 0x2C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 44), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x169974u;
    // 0x169974: 0x0  nop
    ctx->pc = 0x169974u;
    // NOP
    // 0x169978: 0x3e00008  jr          $ra
    ctx->pc = 0x169978u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16997Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x169978u;
            // 0x16997c: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x169980u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
