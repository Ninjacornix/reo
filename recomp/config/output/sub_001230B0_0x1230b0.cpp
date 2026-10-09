#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001230B0
// Address: 0x1230b0 - 0x1230e0
void sub_001230B0_0x1230b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001230B0_0x1230b0");
#endif

    switch (ctx->pc) {
        case 0x1230d4u: goto label_1230d4;
        default: break;
    }

    ctx->pc = 0x1230b0u;

    // 0x1230b0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1230b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1230b4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1230b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1230b8: 0x8c8200b0  lw          $v0, 0xB0($a0)
    ctx->pc = 0x1230b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 176)));
    // 0x1230bc: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1230BCu;
    {
        const bool branch_taken_0x1230bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1230C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1230BCu;
            // 0x1230c0: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1230bc) {
            ctx->pc = 0x1230D4u;
            goto label_1230d4;
        }
    }
    ctx->pc = 0x1230C4u;
    // 0x1230c4: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x1230c4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x1230c8: 0x8c43b730  lw          $v1, -0x48D0($v0)
    ctx->pc = 0x1230c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294948656)));
    // 0x1230cc: 0x60f809  jalr        $v1
    ctx->pc = 0x1230CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x1230D4u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1230D4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1230D4u: goto label_1230d4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1230D4u; }
            if (ctx->pc != 0x1230D4u) { return; }
        }
        }
    }
    ctx->pc = 0x1230D4u;
label_1230d4:
    // 0x1230d4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1230d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1230d8: 0x3e00008  jr          $ra
    ctx->pc = 0x1230D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1230DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1230D8u;
            // 0x1230dc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1230D4u: goto label_1230d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1230E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
