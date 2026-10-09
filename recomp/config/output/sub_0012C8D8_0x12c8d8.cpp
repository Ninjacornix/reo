#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C8D8
// Address: 0x12c8d8 - 0x12c8f8
void sub_0012C8D8_0x12c8d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C8D8_0x12c8d8");
#endif

    switch (ctx->pc) {
        case 0x12c8e8u: goto label_12c8e8;
        case 0x12c8f0u: goto label_12c8f0;
        default: break;
    }

    ctx->pc = 0x12c8d8u;

    // 0x12c8d8: 0x3e00008  jr          $ra
    ctx->pc = 0x12C8D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12C8E8u: goto label_12c8e8;
            case 0x12C8F0u: goto label_12c8f0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12C8E0u;
    // 0x12c8e0: 0x3e00008  jr          $ra
    ctx->pc = 0x12C8E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12C8E8u: goto label_12c8e8;
            case 0x12C8F0u: goto label_12c8f0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12C8E8u;
label_12c8e8:
    // 0x12c8e8: 0x3e00008  jr          $ra
    ctx->pc = 0x12C8E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12C8E8u: goto label_12c8e8;
            case 0x12C8F0u: goto label_12c8f0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12C8F0u;
label_12c8f0:
    // 0x12c8f0: 0x3e00008  jr          $ra
    ctx->pc = 0x12C8F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12C8F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12C8F0u;
            // 0x12c8f4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12C8E8u: goto label_12c8e8;
            case 0x12C8F0u: goto label_12c8f0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12C8F8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
