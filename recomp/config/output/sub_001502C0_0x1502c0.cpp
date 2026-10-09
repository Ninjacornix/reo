#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001502C0
// Address: 0x1502c0 - 0x1502ec
void sub_001502C0_0x1502c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001502C0_0x1502c0");
#endif

    switch (ctx->pc) {
        case 0x1502e0u: goto label_1502e0;
        default: break;
    }

    ctx->pc = 0x1502c0u;

    // 0x1502c0: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x1502c0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x1502c4: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1502c4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1502c8: 0x8c63d818  lw          $v1, -0x27E8($v1)
    ctx->pc = 0x1502c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294957080)));
    // 0x1502cc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1502ccu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1502d0: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1502D0u;
    {
        const bool branch_taken_0x1502d0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1502D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1502D0u;
            // 0x1502d4: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1502d0) {
            ctx->pc = 0x1502E0u;
            goto label_1502e0;
        }
    }
    ctx->pc = 0x1502D8u;
    // 0x1502d8: 0x60f809  jalr        $v1
    ctx->pc = 0x1502D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x1502E0u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1502E0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1502E0u: goto label_1502e0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1502E0u; }
            if (ctx->pc != 0x1502E0u) { return; }
        }
        }
    }
    ctx->pc = 0x1502E0u;
label_1502e0:
    // 0x1502e0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1502e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1502e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1502E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1502E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1502E4u;
            // 0x1502e8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1502E0u: goto label_1502e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1502ECu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
