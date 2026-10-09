#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001318C8
// Address: 0x1318c8 - 0x1318f0
void sub_001318C8_0x1318c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001318C8_0x1318c8");
#endif

    switch (ctx->pc) {
        case 0x1318e4u: goto label_1318e4;
        default: break;
    }

    ctx->pc = 0x1318c8u;

    // 0x1318c8: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x1318c8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x1318cc: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1318ccu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1318d0: 0x8c42b790  lw          $v0, -0x4870($v0)
    ctx->pc = 0x1318d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294948752)));
    // 0x1318d4: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1318D4u;
    {
        const bool branch_taken_0x1318d4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1318D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1318D4u;
            // 0x1318d8: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1318d4) {
            ctx->pc = 0x1318E4u;
            goto label_1318e4;
        }
    }
    ctx->pc = 0x1318DCu;
    // 0x1318dc: 0x40f809  jalr        $v0
    ctx->pc = 0x1318DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1318E4u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1318E4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1318E4u: goto label_1318e4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1318E4u; }
            if (ctx->pc != 0x1318E4u) { return; }
        }
        }
    }
    ctx->pc = 0x1318E4u;
label_1318e4:
    // 0x1318e4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1318e4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1318e8: 0x3e00008  jr          $ra
    ctx->pc = 0x1318E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1318ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1318E8u;
            // 0x1318ec: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1318E4u: goto label_1318e4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1318F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
