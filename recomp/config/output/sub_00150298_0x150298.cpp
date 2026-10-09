#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00150298
// Address: 0x150298 - 0x1502c0
void sub_00150298_0x150298(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00150298_0x150298");
#endif

    switch (ctx->pc) {
        case 0x1502b4u: goto label_1502b4;
        default: break;
    }

    ctx->pc = 0x150298u;

    // 0x150298: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x150298u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x15029c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15029cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1502a0: 0x8c42d814  lw          $v0, -0x27EC($v0)
    ctx->pc = 0x1502a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294957076)));
    // 0x1502a4: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1502A4u;
    {
        const bool branch_taken_0x1502a4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1502A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1502A4u;
            // 0x1502a8: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1502a4) {
            ctx->pc = 0x1502B4u;
            goto label_1502b4;
        }
    }
    ctx->pc = 0x1502ACu;
    // 0x1502ac: 0x40f809  jalr        $v0
    ctx->pc = 0x1502ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1502B4u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1502B4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1502B4u: goto label_1502b4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1502B4u; }
            if (ctx->pc != 0x1502B4u) { return; }
        }
        }
    }
    ctx->pc = 0x1502B4u;
label_1502b4:
    // 0x1502b4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1502b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1502b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1502B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1502BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1502B8u;
            // 0x1502bc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1502B4u: goto label_1502b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1502C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
