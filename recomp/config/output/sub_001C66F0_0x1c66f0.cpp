#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C66F0
// Address: 0x1c66f0 - 0x1c6714
void sub_001C66F0_0x1c66f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C66F0_0x1c66f0");
#endif

    ctx->pc = 0x1c66f0u;

    // 0x1c66f0: 0xac8501a8  sw          $a1, 0x1A8($a0)
    ctx->pc = 0x1c66f0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 424), GPR_U32(ctx, 5));
    // 0x1c66f4: 0x30e200ff  andi        $v0, $a3, 0xFF
    ctx->pc = 0x1c66f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)255);
    // 0x1c66f8: 0xac8501ac  sw          $a1, 0x1AC($a0)
    ctx->pc = 0x1c66f8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 428), GPR_U32(ctx, 5));
    // 0x1c66fc: 0xa48601b0  sh          $a2, 0x1B0($a0)
    ctx->pc = 0x1c66fcu;
    WRITE16(ADD32(GPR_U32(ctx, 4), 432), (uint16_t)GPR_U32(ctx, 6));
    // 0x1c6700: 0xa48201b4  sh          $v0, 0x1B4($a0)
    ctx->pc = 0x1c6700u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 436), (uint16_t)GPR_U32(ctx, 2));
    // 0x1c6704: 0x948601b0  lhu         $a2, 0x1B0($a0)
    ctx->pc = 0x1c6704u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 432)));
    // 0x1c6708: 0x8c8401a8  lw          $a0, 0x1A8($a0)
    ctx->pc = 0x1c6708u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 424)));
    // 0x1c670c: 0x8041f1a  j           func_107C68
    ctx->pc = 0x1C670Cu;
    ctx->pc = 0x1C6710u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C670Cu;
            // 0x1c6710: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C6714u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
