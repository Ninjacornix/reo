#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00165AF8
// Address: 0x165af8 - 0x165b08
void sub_00165AF8_0x165af8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00165AF8_0x165af8");
#endif

    ctx->pc = 0x165af8u;

    // 0x165af8: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x165af8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x165afc: 0x3e00008  jr          $ra
    ctx->pc = 0x165AFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x165B00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165AFCu;
            // 0x165b00: 0x8c62f188  lw          $v0, -0xE78($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294963592)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x165B04u;
    // 0x165b04: 0x0  nop
    ctx->pc = 0x165b04u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
