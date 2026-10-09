#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00163528
// Address: 0x163528 - 0x163558
void sub_00163528_0x163528(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00163528_0x163528");
#endif

    switch (ctx->pc) {
        case 0x163544u: goto label_163544;
        default: break;
    }

    ctx->pc = 0x163528u;

    // 0x163528: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x163528u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16352c: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x16352cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x163530: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x163530u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x163534: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x163534u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163538: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x163538u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x16353c: 0xc0506c4  jal         func_141B10
    ctx->pc = 0x16353Cu;
    SET_GPR_U32(ctx, 31, 0x163544u);
    ctx->pc = 0x163540u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16353Cu;
            // 0x163540: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141B10u;
    if (runtime->hasFunction(0x141B10u)) {
        auto targetFn = runtime->lookupFunction(0x141B10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163544u; }
        if (ctx->pc != 0x163544u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141B10_0x141b10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163544u; }
        if (ctx->pc != 0x163544u) { return; }
    }
    ctx->pc = 0x163544u;
label_163544:
    // 0x163544: 0x3c030027  lui         $v1, 0x27
    ctx->pc = 0x163544u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)39 << 16));
    // 0x163548: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x163548u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16354c: 0xac620744  sw          $v0, 0x744($v1)
    ctx->pc = 0x16354cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 1860), GPR_U32(ctx, 2));
    // 0x163550: 0x3e00008  jr          $ra
    ctx->pc = 0x163550u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x163554u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163550u;
            // 0x163554: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x163544u: goto label_163544;
            default: break;
        }
        return;
    }
    ctx->pc = 0x163558u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
