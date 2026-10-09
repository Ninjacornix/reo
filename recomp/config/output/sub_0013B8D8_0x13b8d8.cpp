#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013B8D8
// Address: 0x13b8d8 - 0x13b910
void sub_0013B8D8_0x13b8d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013B8D8_0x13b8d8");
#endif

    switch (ctx->pc) {
        case 0x13b8f4u: goto label_13b8f4;
        default: break;
    }

    ctx->pc = 0x13b8d8u;

    // 0x13b8d8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13b8d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13b8dc: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x13b8dcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b8e0: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x13B8E0u;
    {
        const bool branch_taken_0x13b8e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13B8E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B8E0u;
            // 0x13b8e4: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b8e0) {
            ctx->pc = 0x13B900u;
            goto label_13b900;
        }
    }
    ctx->pc = 0x13B8E8u;
    // 0x13b8e8: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x13b8e8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x13b8ec: 0xc04ebf2  jal         func_13AFC8
    ctx->pc = 0x13B8ECu;
    SET_GPR_U32(ctx, 31, 0x13B8F4u);
    ctx->pc = 0x13B8F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B8ECu;
            // 0x13b8f0: 0x24a5d0b0  addiu       $a1, $a1, -0x2F50 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294955184));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13AFC8u;
    if (runtime->hasFunction(0x13AFC8u)) {
        auto targetFn = runtime->lookupFunction(0x13AFC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B8F4u; }
        if (ctx->pc != 0x13B8F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013AFC8_0x13afc8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B8F4u; }
        if (ctx->pc != 0x13B8F4u) { return; }
    }
    ctx->pc = 0x13B8F4u;
label_13b8f4:
    // 0x13b8f4: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x13B8F4u;
    {
        const bool branch_taken_0x13b8f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13B8F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B8F4u;
            // 0x13b8f8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b8f4) {
            ctx->pc = 0x13B904u;
            goto label_13b904;
        }
    }
    ctx->pc = 0x13B8FCu;
    // 0x13b8fc: 0x0  nop
    ctx->pc = 0x13b8fcu;
    // NOP
label_13b900:
    // 0x13b900: 0x8c42001c  lw          $v0, 0x1C($v0)
    ctx->pc = 0x13b900u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
label_13b904:
    // 0x13b904: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13b904u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13b908: 0x3e00008  jr          $ra
    ctx->pc = 0x13B908u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13B90Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B908u;
            // 0x13b90c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13B8F4u: goto label_13b8f4;
            case 0x13B900u: goto label_13b900;
            case 0x13B904u: goto label_13b904;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13B910u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
