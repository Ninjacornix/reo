#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013ECF0
// Address: 0x13ecf0 - 0x13ed28
void sub_0013ECF0_0x13ecf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013ECF0_0x13ecf0");
#endif

    switch (ctx->pc) {
        case 0x13ed10u: goto label_13ed10;
        default: break;
    }

    ctx->pc = 0x13ecf0u;

    // 0x13ecf0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13ecf0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13ecf4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13ecf4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13ecf8: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x13ecf8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x13ecfc: 0x8c440008  lw          $a0, 0x8($v0)
    ctx->pc = 0x13ecfcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x13ed00: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x13ed00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x13ed04: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x13ed04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x13ed08: 0x40f809  jalr        $v0
    ctx->pc = 0x13ED08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13ED10u);
        ctx->pc = 0x13ED0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13ED08u;
            // 0x13ed0c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13ED10u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13ED10u: goto label_13ed10;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13ED10u; }
            if (ctx->pc != 0x13ED10u) { return; }
        }
        }
    }
    ctx->pc = 0x13ED10u;
label_13ed10:
    // 0x13ed10: 0x21fc2  srl         $v1, $v0, 31
    ctx->pc = 0x13ed10u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x13ed14: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13ed14u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13ed18: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x13ed18u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x13ed1c: 0x31043  sra         $v0, $v1, 1
    ctx->pc = 0x13ed1cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 1));
    // 0x13ed20: 0x3e00008  jr          $ra
    ctx->pc = 0x13ED20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13ED24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13ED20u;
            // 0x13ed24: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13ED10u: goto label_13ed10;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13ED28u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
