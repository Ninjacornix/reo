#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BC5B0
// Address: 0x1bc5b0 - 0x1bc5c4
void sub_001BC5B0_0x1bc5b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BC5B0_0x1bc5b0");
#endif

    ctx->pc = 0x1bc5b0u;

    // 0x1bc5b0: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bc5b0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bc5b4: 0x902265c0  lbu         $v0, 0x65C0($at)
    ctx->pc = 0x1bc5b4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 26048)));
    // 0x1bc5b8: 0x38420001  xori        $v0, $v0, 0x1
    ctx->pc = 0x1bc5b8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
    // 0x1bc5bc: 0x3e00008  jr          $ra
    ctx->pc = 0x1BC5BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BC5C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BC5BCu;
            // 0x1bc5c0: 0x2c420001  sltiu       $v0, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1BC5C4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
