#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00102488
// Address: 0x102488 - 0x102498
void sub_00102488_0x102488(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00102488_0x102488");
#endif

    ctx->pc = 0x102488u;

    // 0x102488: 0x4842e000  cfc2.ni     $v0, $vi28
    ctx->pc = 0x102488u;
    SET_GPR_U32(ctx, 2, ctx->vu0_itop);
    // 0x10248c: 0x212c2  srl         $v0, $v0, 11
    ctx->pc = 0x10248cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 11));
    // 0x102490: 0x3e00008  jr          $ra
    ctx->pc = 0x102490u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102494u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102490u;
            // 0x102494: 0x30420001  andi        $v0, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x102498u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
