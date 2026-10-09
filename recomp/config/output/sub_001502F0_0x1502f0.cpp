#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001502F0
// Address: 0x1502f0 - 0x150318
void sub_001502F0_0x1502f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001502F0_0x1502f0");
#endif

    switch (ctx->pc) {
        case 0x15030cu: goto label_15030c;
        default: break;
    }

    ctx->pc = 0x1502f0u;

    // 0x1502f0: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1502f0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1502f4: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1502f4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1502f8: 0x8c42d81c  lw          $v0, -0x27E4($v0)
    ctx->pc = 0x1502f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294957084)));
    // 0x1502fc: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1502FCu;
    {
        const bool branch_taken_0x1502fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x150300u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1502FCu;
            // 0x150300: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1502fc) {
            ctx->pc = 0x15030Cu;
            goto label_15030c;
        }
    }
    ctx->pc = 0x150304u;
    // 0x150304: 0x40f809  jalr        $v0
    ctx->pc = 0x150304u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x15030Cu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x15030Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15030Cu: goto label_15030c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15030Cu; }
            if (ctx->pc != 0x15030Cu) { return; }
        }
        }
    }
    ctx->pc = 0x15030Cu;
label_15030c:
    // 0x15030c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15030cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x150310: 0x3e00008  jr          $ra
    ctx->pc = 0x150310u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x150314u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150310u;
            // 0x150314: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15030Cu: goto label_15030c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x150318u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
