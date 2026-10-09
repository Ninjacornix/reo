#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00169EF8
// Address: 0x169ef8 - 0x169f00
void sub_00169EF8_0x169ef8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00169EF8_0x169ef8");
#endif

    ctx->pc = 0x169ef8u;

    // 0x169ef8: 0x3e00008  jr          $ra
    ctx->pc = 0x169EF8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x169EFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x169EF8u;
            // 0x169efc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x169F00u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
