#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001504F8
// Address: 0x1504f8 - 0x150520
void sub_001504F8_0x1504f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001504F8_0x1504f8");
#endif

    switch (ctx->pc) {
        case 0x150514u: goto label_150514;
        default: break;
    }

    ctx->pc = 0x1504f8u;

    // 0x1504f8: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1504f8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1504fc: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1504fcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x150500: 0x8c42d850  lw          $v0, -0x27B0($v0)
    ctx->pc = 0x150500u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294957136)));
    // 0x150504: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x150504u;
    {
        const bool branch_taken_0x150504 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x150508u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150504u;
            // 0x150508: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150504) {
            ctx->pc = 0x150514u;
            goto label_150514;
        }
    }
    ctx->pc = 0x15050Cu;
    // 0x15050c: 0x40f809  jalr        $v0
    ctx->pc = 0x15050Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x150514u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x150514u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150514u: goto label_150514;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x150514u; }
            if (ctx->pc != 0x150514u) { return; }
        }
        }
    }
    ctx->pc = 0x150514u;
label_150514:
    // 0x150514: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x150514u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x150518: 0x3e00008  jr          $ra
    ctx->pc = 0x150518u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15051Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150518u;
            // 0x15051c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150514u: goto label_150514;
            default: break;
        }
        return;
    }
    ctx->pc = 0x150520u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
