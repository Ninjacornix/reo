#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011F618
// Address: 0x11f618 - 0x11f63c
void sub_0011F618_0x11f618(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011F618_0x11f618");
#endif

    ctx->pc = 0x11f618u;

    // 0x11f618: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11f618u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11f61c: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x11f61cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x11f620: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x11f620u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x11f624: 0xac40b408  sw          $zero, -0x4BF8($v0)
    ctx->pc = 0x11f624u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294947848), GPR_U32(ctx, 0));
    // 0x11f628: 0xac60b40c  sw          $zero, -0x4BF4($v1)
    ctx->pc = 0x11f628u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294947852), GPR_U32(ctx, 0));
    // 0x11f62c: 0x24841d08  addiu       $a0, $a0, 0x1D08
    ctx->pc = 0x11f62cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 7432));
    // 0x11f630: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x11f630u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11f634: 0x8041f1a  j           func_107C68
    ctx->pc = 0x11F634u;
    ctx->pc = 0x11F638u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11F634u;
            // 0x11f638: 0x24060200  addiu       $a2, $zero, 0x200 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x11F63Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
