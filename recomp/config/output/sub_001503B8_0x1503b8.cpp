#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001503B8
// Address: 0x1503b8 - 0x1503e0
void sub_001503B8_0x1503b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001503B8_0x1503b8");
#endif

    switch (ctx->pc) {
        case 0x1503d4u: goto label_1503d4;
        default: break;
    }

    ctx->pc = 0x1503b8u;

    // 0x1503b8: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1503b8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1503bc: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1503bcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1503c0: 0x8c42d830  lw          $v0, -0x27D0($v0)
    ctx->pc = 0x1503c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294957104)));
    // 0x1503c4: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1503C4u;
    {
        const bool branch_taken_0x1503c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1503C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1503C4u;
            // 0x1503c8: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1503c4) {
            ctx->pc = 0x1503D4u;
            goto label_1503d4;
        }
    }
    ctx->pc = 0x1503CCu;
    // 0x1503cc: 0x40f809  jalr        $v0
    ctx->pc = 0x1503CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1503D4u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1503D4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1503D4u: goto label_1503d4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1503D4u; }
            if (ctx->pc != 0x1503D4u) { return; }
        }
        }
    }
    ctx->pc = 0x1503D4u;
label_1503d4:
    // 0x1503d4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1503d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1503d8: 0x3e00008  jr          $ra
    ctx->pc = 0x1503D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1503DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1503D8u;
            // 0x1503dc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1503D4u: goto label_1503d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1503E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
