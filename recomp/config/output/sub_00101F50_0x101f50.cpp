#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00101F50
// Address: 0x101f50 - 0x101f60
void sub_00101F50_0x101f50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00101F50_0x101f50");
#endif

    ctx->pc = 0x101f50u;

    // 0x101f50: 0x4842e000  cfc2.ni     $v0, $vi28
    ctx->pc = 0x101f50u;
    SET_GPR_U32(ctx, 2, ctx->vu0_itop);
    // 0x101f54: 0x210c2  srl         $v0, $v0, 3
    ctx->pc = 0x101f54u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 3));
    // 0x101f58: 0x3e00008  jr          $ra
    ctx->pc = 0x101F58u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x101F5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101F58u;
            // 0x101f5c: 0x30420001  andi        $v0, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x101F60u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
