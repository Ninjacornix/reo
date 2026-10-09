#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001351D0
// Address: 0x1351d0 - 0x1351fc
void sub_001351D0_0x1351d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001351D0_0x1351d0");
#endif

    switch (ctx->pc) {
        case 0x1351f0u: goto label_1351f0;
        default: break;
    }

    ctx->pc = 0x1351d0u;

    // 0x1351d0: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x1351d0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x1351d4: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1351d4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1351d8: 0x8c43bb7c  lw          $v1, -0x4484($v0)
    ctx->pc = 0x1351d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294949756)));
    // 0x1351dc: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1351DCu;
    {
        const bool branch_taken_0x1351dc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1351E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1351DCu;
            // 0x1351e0: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1351dc) {
            ctx->pc = 0x1351F0u;
            goto label_1351f0;
        }
    }
    ctx->pc = 0x1351E4u;
    // 0x1351e4: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x1351e4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x1351e8: 0x60f809  jalr        $v1
    ctx->pc = 0x1351E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x1351F0u);
        ctx->pc = 0x1351ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1351E8u;
            // 0x1351ec: 0x8c44bb80  lw          $a0, -0x4480($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294949760)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1351F0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1351F0u: goto label_1351f0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1351F0u; }
            if (ctx->pc != 0x1351F0u) { return; }
        }
        }
    }
    ctx->pc = 0x1351F0u;
label_1351f0:
    // 0x1351f0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1351f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1351f4: 0x3e00008  jr          $ra
    ctx->pc = 0x1351F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1351F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1351F4u;
            // 0x1351f8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1351F0u: goto label_1351f0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1351FCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
