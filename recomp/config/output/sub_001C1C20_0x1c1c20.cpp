#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C1C20
// Address: 0x1c1c20 - 0x1c1c70
void sub_001C1C20_0x1c1c20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C1C20_0x1c1c20");
#endif

    switch (ctx->pc) {
        case 0x1c1c38u: goto label_1c1c38;
        case 0x1c1c40u: goto label_1c1c40;
        default: break;
    }

    ctx->pc = 0x1c1c20u;

    // 0x1c1c20: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1c1c20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1c1c24: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1c1c24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1c1c28: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x1c1c28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x1c1c2c: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1c1c2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1c1c30: 0xc0705ca  jal         func_1C1728
    ctx->pc = 0x1C1C30u;
    SET_GPR_U32(ctx, 31, 0x1C1C38u);
    ctx->pc = 0x1C1C34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1C30u;
            // 0x1c1c34: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C1728u;
    if (runtime->hasFunction(0x1C1728u)) {
        auto targetFn = runtime->lookupFunction(0x1C1728u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1C38u; }
        if (ctx->pc != 0x1C1C38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C1728_0x1c1728(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1C38u; }
        if (ctx->pc != 0x1C1C38u) { return; }
    }
    ctx->pc = 0x1C1C38u;
label_1c1c38:
    // 0x1c1c38: 0xc0705f8  jal         func_1C17E0
    ctx->pc = 0x1C1C38u;
    SET_GPR_U32(ctx, 31, 0x1C1C40u);
    ctx->pc = 0x1C1C3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1C38u;
            // 0x1c1c3c: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C17E0u;
    if (runtime->hasFunction(0x1C17E0u)) {
        auto targetFn = runtime->lookupFunction(0x1C17E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1C40u; }
        if (ctx->pc != 0x1C1C40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C17E0_0x1c17e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1C40u; }
        if (ctx->pc != 0x1C1C40u) { return; }
    }
    ctx->pc = 0x1C1C40u;
label_1c1c40:
    // 0x1c1c40: 0x2403003c  addiu       $v1, $zero, 0x3C
    ctx->pc = 0x1c1c40u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
    // 0x1c1c44: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1c1c44u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c1c48: 0x431018  mult        $v0, $v0, $v1
    ctx->pc = 0x1c1c48u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x1c1c4c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1c1c4cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c1c50: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1c1c50u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c1c54: 0x2442fde4  addiu       $v0, $v0, -0x21C
    ctx->pc = 0x1c1c54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294966756));
    // 0x1c1c58: 0x2222821  addu        $a1, $s1, $v0
    ctx->pc = 0x1c1c58u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x1c1c5c: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x1c1c5cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c1c60: 0x80706e2  j           func_1C1B88
    ctx->pc = 0x1C1C60u;
    ctx->pc = 0x1C1C64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1C60u;
            // 0x1c1c64: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C1B88u;
    if (runtime->hasFunction(0x1C1B88u)) {
        auto targetFn = runtime->lookupFunction(0x1C1B88u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001C1B88_0x1c1b88(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C1C68u;
    // 0x1c1c68: 0x0  nop
    ctx->pc = 0x1c1c68u;
    // NOP
    // 0x1c1c6c: 0x0  nop
    ctx->pc = 0x1c1c6cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
