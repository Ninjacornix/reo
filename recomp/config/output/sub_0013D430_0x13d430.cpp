#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013D430
// Address: 0x13d430 - 0x13d468
void sub_0013D430_0x13d430(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013D430_0x13d430");
#endif

    switch (ctx->pc) {
        case 0x13d458u: goto label_13d458;
        default: break;
    }

    ctx->pc = 0x13d430u;

    // 0x13d430: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13d430u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13d434: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13d434u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13d438: 0x8c46dfd8  lw          $a2, -0x2028($v0)
    ctx->pc = 0x13d438u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294959064)));
    // 0x13d43c: 0x10c00006  beqz        $a2, . + 4 + (0x6 << 2)
    ctx->pc = 0x13D43Cu;
    {
        const bool branch_taken_0x13d43c = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x13D440u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D43Cu;
            // 0x13d440: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d43c) {
            ctx->pc = 0x13D458u;
            goto label_13d458;
        }
    }
    ctx->pc = 0x13D444u;
    // 0x13d444: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13d444u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13d448: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13d448u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13d44c: 0x8c44dfdc  lw          $a0, -0x2024($v0)
    ctx->pc = 0x13d44cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294959068)));
    // 0x13d450: 0xc0f809  jalr        $a2
    ctx->pc = 0x13D450u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 6);
        SET_GPR_U32(ctx, 31, 0x13D458u);
        ctx->pc = 0x13D454u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D450u;
            // 0x13d454: 0x8c65dfe0  lw          $a1, -0x2020($v1) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294959072)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13D458u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13D458u: goto label_13d458;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13D458u; }
            if (ctx->pc != 0x13D458u) { return; }
        }
        }
    }
    ctx->pc = 0x13D458u;
label_13d458:
    // 0x13d458: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13d458u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13d45c: 0x3e00008  jr          $ra
    ctx->pc = 0x13D45Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13D460u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D45Cu;
            // 0x13d460: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13D458u: goto label_13d458;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13D464u;
    // 0x13d464: 0x0  nop
    ctx->pc = 0x13d464u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
