#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016E668
// Address: 0x16e668 - 0x16e678
void sub_0016E668_0x16e668(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016E668_0x16e668");
#endif

    ctx->pc = 0x16e668u;

    // 0x16e668: 0x8c820de0  lw          $v0, 0xDE0($a0)
    ctx->pc = 0x16e668u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 3552)));
    // 0x16e66c: 0x21027  nor         $v0, $zero, $v0
    ctx->pc = 0x16e66cu;
    SET_GPR_U64(ctx, 2, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 2)));
    // 0x16e670: 0x3e00008  jr          $ra
    ctx->pc = 0x16E670u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16E674u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E670u;
            // 0x16e674: 0x217c2  srl         $v0, $v0, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x16E678u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
