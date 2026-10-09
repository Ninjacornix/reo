#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D24F0
// Address: 0x1d24f0 - 0x1d2520
void sub_001D24F0_0x1d24f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D24F0_0x1d24f0");
#endif

    switch (ctx->pc) {
        case 0x1d2514u: goto label_1d2514;
        default: break;
    }

    ctx->pc = 0x1d24f0u;

    // 0x1d24f0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d24f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d24f4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d24f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d24f8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d24f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d24fc: 0x802343d7  lb          $v1, 0x43D7($at)
    ctx->pc = 0x1d24fcu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d2500: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D2500u;
    {
        const bool branch_taken_0x1d2500 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D2504u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2500u;
            // 0x1d2504: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2500) {
            ctx->pc = 0x1D2514u;
            goto label_1d2514;
        }
    }
    ctx->pc = 0x1D2508u;
    // 0x1d2508: 0x942443da  lhu         $a0, 0x43DA($at)
    ctx->pc = 0x1d2508u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d250c: 0xc073784  jal         func_1CDE10
    ctx->pc = 0x1D250Cu;
    SET_GPR_U32(ctx, 31, 0x1D2514u);
    ctx->pc = 0x1D2510u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D250Cu;
            // 0x1d2510: 0x24052000  addiu       $a1, $zero, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CDE10u;
    if (runtime->hasFunction(0x1CDE10u)) {
        auto targetFn = runtime->lookupFunction(0x1CDE10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2514u; }
        if (ctx->pc != 0x1D2514u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CDE10_0x1cde10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2514u; }
        if (ctx->pc != 0x1D2514u) { return; }
    }
    ctx->pc = 0x1D2514u;
label_1d2514:
    // 0x1d2514: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d2514u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d2518: 0x3e00008  jr          $ra
    ctx->pc = 0x1D2518u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D251Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2518u;
            // 0x1d251c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D2514u: goto label_1d2514;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D2520u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
