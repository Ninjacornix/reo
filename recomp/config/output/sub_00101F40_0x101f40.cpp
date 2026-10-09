#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00101F40
// Address: 0x101f40 - 0x101f50
void sub_00101F40_0x101f40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00101F40_0x101f40");
#endif

    ctx->pc = 0x101f40u;

    // 0x101f40: 0x4842e000  cfc2.ni     $v0, $vi28
    ctx->pc = 0x101f40u;
    SET_GPR_U32(ctx, 2, ctx->vu0_itop);
    // 0x101f44: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x101f44u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x101f48: 0x3e00008  jr          $ra
    ctx->pc = 0x101F48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x101F4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101F48u;
            // 0x101f4c: 0x30420001  andi        $v0, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x101F50u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
