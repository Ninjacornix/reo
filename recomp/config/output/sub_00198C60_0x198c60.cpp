#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00198C60
// Address: 0x198c60 - 0x198c7c
void sub_00198C60_0x198c60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00198C60_0x198c60");
#endif

    ctx->pc = 0x198c60u;

    // 0x198c60: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x198c60u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x198c64: 0x2403fffe  addiu       $v1, $zero, -0x2
    ctx->pc = 0x198c64u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x198c68: 0xac24fd6c  sw          $a0, -0x294($at)
    ctx->pc = 0x198c68u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966636), GPR_U32(ctx, 4));
    // 0x198c6c: 0xa31824  and         $v1, $a1, $v1
    ctx->pc = 0x198c6cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) & GPR_U64(ctx, 3));
    // 0x198c70: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x198c70u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x198c74: 0x3e00008  jr          $ra
    ctx->pc = 0x198C74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x198C78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198C74u;
            // 0x198c78: 0xac23fd70  sw          $v1, -0x290($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966640), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x198C7Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
