#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017CF48
// Address: 0x17cf48 - 0x17cf5c
void sub_0017CF48_0x17cf48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017CF48_0x17cf48");
#endif

    ctx->pc = 0x17cf48u;

    // 0x17cf48: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x17cf48u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x17cf4c: 0x2442f2a8  addiu       $v0, $v0, -0xD58
    ctx->pc = 0x17cf4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963880));
    // 0x17cf50: 0xac450004  sw          $a1, 0x4($v0)
    ctx->pc = 0x17cf50u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 5));
    // 0x17cf54: 0x3e00008  jr          $ra
    ctx->pc = 0x17CF54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17CF58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17CF54u;
            // 0x17cf58: 0xac440000  sw          $a0, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17CF5Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
