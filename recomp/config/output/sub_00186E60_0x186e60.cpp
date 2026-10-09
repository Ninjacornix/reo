#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00186E60
// Address: 0x186e60 - 0x186ea8
void sub_00186E60_0x186e60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00186E60_0x186e60");
#endif

    ctx->pc = 0x186e60u;

    // 0x186e60: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x186e60u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x186e64: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x186e64u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x186e68: 0x21840  sll         $v1, $v0, 1
    ctx->pc = 0x186e68u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x186e6c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x186e6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x186e70: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x186e70u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x186e74: 0x31940  sll         $v1, $v1, 5
    ctx->pc = 0x186e74u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
    // 0x186e78: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x186e78u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x186e7c: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x186e7cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x186e80: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x186e80u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x186e84: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x186e84u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x186e88: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x186e88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x186e8c: 0x9442fa42  lhu         $v0, -0x5BE($v0)
    ctx->pc = 0x186e8cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 4294965826)));
    // 0x186e90: 0x470018  mult        $zero, $v0, $a3
    ctx->pc = 0x186e90u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 7); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x186e94: 0x3812  mflo        $a3
    ctx->pc = 0x186e94u;
    SET_GPR_U64(ctx, 7, ctx->lo);
    // 0x186e98: 0xc20018  mult        $zero, $a2, $v0
    ctx->pc = 0x186e98u;
    { int64_t result = (int64_t)GPR_S32(ctx, 6) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x186e9c: 0x3012  mflo        $a2
    ctx->pc = 0x186e9cu;
    SET_GPR_U64(ctx, 6, ctx->lo);
    // 0x186ea0: 0x80620c6  j           func_188318
    ctx->pc = 0x186EA0u;
    ctx->pc = 0x186EA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x186EA0u;
            // 0x186ea4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x188318u;
    if (runtime->hasFunction(0x188318u)) {
        auto targetFn = runtime->lookupFunction(0x188318u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00188318_0x188318(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x186EA8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
