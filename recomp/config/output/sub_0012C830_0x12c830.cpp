#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C830
// Address: 0x12c830 - 0x12c890
void sub_0012C830_0x12c830(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C830_0x12c830");
#endif

    ctx->pc = 0x12c830u;

    // 0x12c830: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c830u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c834: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c834u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c838: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c838u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c83c: 0x804fc20  j           func_13F080
    ctx->pc = 0x12C83Cu;
    ctx->pc = 0x12C840u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C83Cu;
            // 0x12c840: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F080u;
    if (runtime->hasFunction(0x13F080u)) {
        auto targetFn = runtime->lookupFunction(0x13F080u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F080_0x13f080(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12C844u;
    // 0x12c844: 0x0  nop
    ctx->pc = 0x12c844u;
    // NOP
    // 0x12c848: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c848u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c84c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c84cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c850: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c850u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c854: 0x804fc38  j           func_13F0E0
    ctx->pc = 0x12C854u;
    ctx->pc = 0x12C858u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C854u;
            // 0x12c858: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F0E0u;
    if (runtime->hasFunction(0x13F0E0u)) {
        auto targetFn = runtime->lookupFunction(0x13F0E0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F0E0_0x13f0e0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12C85Cu;
    // 0x12c85c: 0x0  nop
    ctx->pc = 0x12c85cu;
    // NOP
    // 0x12c860: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c860u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c864: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c864u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c868: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c868u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c86c: 0x804fc3a  j           func_13F0E8
    ctx->pc = 0x12C86Cu;
    ctx->pc = 0x12C870u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C86Cu;
            // 0x12c870: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F0E8u;
    if (runtime->hasFunction(0x13F0E8u)) {
        auto targetFn = runtime->lookupFunction(0x13F0E8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F0E8_0x13f0e8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12C874u;
    // 0x12c874: 0x0  nop
    ctx->pc = 0x12c874u;
    // NOP
    // 0x12c878: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c878u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c87c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c87cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c880: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c880u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c884: 0x804fc3c  j           func_13F0F0
    ctx->pc = 0x12C884u;
    ctx->pc = 0x12C888u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C884u;
            // 0x12c888: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F0F0u;
    if (runtime->hasFunction(0x13F0F0u)) {
        auto targetFn = runtime->lookupFunction(0x13F0F0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F0F0_0x13f0f0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12C88Cu;
    // 0x12c88c: 0x0  nop
    ctx->pc = 0x12c88cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
