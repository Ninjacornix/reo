#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D6070
// Address: 0x1d6070 - 0x1d6090
void sub_001D6070_0x1d6070(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D6070_0x1d6070");
#endif

    ctx->pc = 0x1d6070u;

    // 0x1d6070: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1d6070u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1d6074: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1d6074u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1d6078: 0x90432981  lbu         $v1, 0x2981($v0)
    ctx->pc = 0x1d6078u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 10625)));
    // 0x1d607c: 0x90a42941  lbu         $a0, 0x2941($a1)
    ctx->pc = 0x1d607cu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 10561)));
    // 0x1d6080: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d6080u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d6084: 0x641826  xor         $v1, $v1, $a0
    ctx->pc = 0x1d6084u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 4));
    // 0x1d6088: 0x3e00008  jr          $ra
    ctx->pc = 0x1D6088u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D608Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6088u;
            // 0x1d608c: 0x3100a  movz        $v0, $zero, $v1 (Delay Slot)
        if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1D6090u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
