#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00163430
// Address: 0x163430 - 0x16343c
void sub_00163430_0x163430(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00163430_0x163430");
#endif

    ctx->pc = 0x163430u;

    // 0x163430: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x163430u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x163434: 0x3e00008  jr          $ra
    ctx->pc = 0x163434u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x163438u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163434u;
            // 0x163438: 0xac44ef50  sw          $a0, -0x10B0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294963024), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x16343Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
