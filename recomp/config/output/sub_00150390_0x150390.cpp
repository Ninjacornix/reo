#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00150390
// Address: 0x150390 - 0x1503b8
void sub_00150390_0x150390(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00150390_0x150390");
#endif

    switch (ctx->pc) {
        case 0x1503acu: goto label_1503ac;
        default: break;
    }

    ctx->pc = 0x150390u;

    // 0x150390: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x150390u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x150394: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x150394u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x150398: 0x8c42d82c  lw          $v0, -0x27D4($v0)
    ctx->pc = 0x150398u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294957100)));
    // 0x15039c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x15039Cu;
    {
        const bool branch_taken_0x15039c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1503A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15039Cu;
            // 0x1503a0: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15039c) {
            ctx->pc = 0x1503ACu;
            goto label_1503ac;
        }
    }
    ctx->pc = 0x1503A4u;
    // 0x1503a4: 0x40f809  jalr        $v0
    ctx->pc = 0x1503A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1503ACu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1503ACu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1503ACu: goto label_1503ac;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1503ACu; }
            if (ctx->pc != 0x1503ACu) { return; }
        }
        }
    }
    ctx->pc = 0x1503ACu;
label_1503ac:
    // 0x1503ac: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1503acu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1503b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1503B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1503B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1503B0u;
            // 0x1503b4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1503ACu: goto label_1503ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1503B8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
