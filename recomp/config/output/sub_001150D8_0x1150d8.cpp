#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001150D8
// Address: 0x1150d8 - 0x1150ec
void sub_001150D8_0x1150d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001150D8_0x1150d8");
#endif

    ctx->pc = 0x1150d8u;

    // 0x1150d8: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x1150d8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x1150dc: 0x3442ffc0  ori         $v0, $v0, 0xFFC0
    ctx->pc = 0x1150dcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65472);
    // 0x1150e0: 0xa22824  and         $a1, $a1, $v0
    ctx->pc = 0x1150e0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & GPR_U64(ctx, 2));
    // 0x1150e4: 0x80453ec  j           func_114FB0
    ctx->pc = 0x1150E4u;
    ctx->pc = 0x1150E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1150E4u;
            // 0x1150e8: 0x822024  and         $a0, $a0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114FB0u;
    if (runtime->hasFunction(0x114FB0u)) {
        auto targetFn = runtime->lookupFunction(0x114FB0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00114FB0_0x114fb0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1150ECu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
