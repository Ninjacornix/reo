#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00124E40
// Address: 0x124e40 - 0x124e68
void sub_00124E40_0x124e40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00124E40_0x124e40");
#endif

    ctx->pc = 0x124e40u;

    // 0x124e40: 0xac86007c  sw          $a2, 0x7C($a0)
    ctx->pc = 0x124e40u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 124), GPR_U32(ctx, 6));
    // 0x124e44: 0x3e00008  jr          $ra
    ctx->pc = 0x124E44u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x124E48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124E44u;
            // 0x124e48: 0xac850078  sw          $a1, 0x78($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 120), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x124E4Cu;
    // 0x124e4c: 0x0  nop
    ctx->pc = 0x124e4cu;
    // NOP
    // 0x124e50: 0xac860084  sw          $a2, 0x84($a0)
    ctx->pc = 0x124e50u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 132), GPR_U32(ctx, 6));
    // 0x124e54: 0x3e00008  jr          $ra
    ctx->pc = 0x124E54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x124E58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124E54u;
            // 0x124e58: 0xac850080  sw          $a1, 0x80($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 128), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x124E5Cu;
    // 0x124e5c: 0x0  nop
    ctx->pc = 0x124e5cu;
    // NOP
    // 0x124e60: 0x3e00008  jr          $ra
    ctx->pc = 0x124E60u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x124E64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124E60u;
            // 0x124e64: 0x8c82003c  lw          $v0, 0x3C($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 60)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x124E68u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
