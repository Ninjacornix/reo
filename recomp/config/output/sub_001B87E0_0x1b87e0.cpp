#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B87E0
// Address: 0x1b87e0 - 0x1b8850
void sub_001B87E0_0x1b87e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B87E0_0x1b87e0");
#endif

    ctx->pc = 0x1b87e0u;

    // 0x1b87e0: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1b87e0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b87e4: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1b87e4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b87e8: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x1b87e8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b87ec: 0x806e4ec  j           func_1B93B0
    ctx->pc = 0x1B87ECu;
    ctx->pc = 0x1B87F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B87ECu;
            // 0x1b87f0: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93B0u;
    if (runtime->hasFunction(0x1B93B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93B0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001B93B0_0x1b93b0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1B87F4u;
    // 0x1b87f4: 0x0  nop
    ctx->pc = 0x1b87f4u;
    // NOP
    // 0x1b87f8: 0x0  nop
    ctx->pc = 0x1b87f8u;
    // NOP
    // 0x1b87fc: 0x0  nop
    ctx->pc = 0x1b87fcu;
    // NOP
    // 0x1b8800: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1b8800u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8804: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b8804u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8808: 0x806e4ec  j           func_1B93B0
    ctx->pc = 0x1B8808u;
    ctx->pc = 0x1B880Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8808u;
            // 0x1b880c: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93B0u;
    if (runtime->hasFunction(0x1B93B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93B0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001B93B0_0x1b93b0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1B8810u;
    // 0x1b8810: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1b8810u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8814: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1b8814u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b8818: 0x806e4ec  j           func_1B93B0
    ctx->pc = 0x1B8818u;
    ctx->pc = 0x1B881Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8818u;
            // 0x1b881c: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93B0u;
    if (runtime->hasFunction(0x1B93B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93B0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001B93B0_0x1b93b0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1B8820u;
    // 0x1b8820: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1b8820u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8824: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x1b8824u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b8828: 0x806e4ec  j           func_1B93B0
    ctx->pc = 0x1B8828u;
    ctx->pc = 0x1B882Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8828u;
            // 0x1b882c: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93B0u;
    if (runtime->hasFunction(0x1B93B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93B0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001B93B0_0x1b93b0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1B8830u;
    // 0x1b8830: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1b8830u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8834: 0x24050003  addiu       $a1, $zero, 0x3
    ctx->pc = 0x1b8834u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1b8838: 0x806e4ec  j           func_1B93B0
    ctx->pc = 0x1B8838u;
    ctx->pc = 0x1B883Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8838u;
            // 0x1b883c: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93B0u;
    if (runtime->hasFunction(0x1B93B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93B0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001B93B0_0x1b93b0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1B8840u;
    // 0x1b8840: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1b8840u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8844: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1b8844u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1b8848: 0x806e4ec  j           func_1B93B0
    ctx->pc = 0x1B8848u;
    ctx->pc = 0x1B884Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8848u;
            // 0x1b884c: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93B0u;
    if (runtime->hasFunction(0x1B93B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93B0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001B93B0_0x1b93b0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1B8850u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
