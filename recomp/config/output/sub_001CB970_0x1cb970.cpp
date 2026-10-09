#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CB970
// Address: 0x1cb970 - 0x1cb9a0
void sub_001CB970_0x1cb970(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CB970_0x1cb970");
#endif

    switch (ctx->pc) {
        case 0x1cb994u: goto label_1cb994;
        default: break;
    }

    ctx->pc = 0x1cb970u;

    // 0x1cb970: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1cb970u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1cb974: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cb974u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cb978: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1cb978u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1cb97c: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1cb97cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1cb980: 0x8c246008  lw          $a0, 0x6008($at)
    ctx->pc = 0x1cb980u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24584)));
    // 0x1cb984: 0x10830003  beq         $a0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CB984u;
    {
        const bool branch_taken_0x1cb984 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1cb984) {
            ctx->pc = 0x1CB994u;
            goto label_1cb994;
        }
    }
    ctx->pc = 0x1CB98Cu;
    // 0x1cb98c: 0xc045194  jal         func_114650
    ctx->pc = 0x1CB98Cu;
    SET_GPR_U32(ctx, 31, 0x1CB994u);
    ctx->pc = 0x114650u;
    if (runtime->hasFunction(0x114650u)) {
        auto targetFn = runtime->lookupFunction(0x114650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB994u; }
        if (ctx->pc != 0x1CB994u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114650_0x114650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB994u; }
        if (ctx->pc != 0x1CB994u) { return; }
    }
    ctx->pc = 0x1CB994u;
label_1cb994:
    // 0x1cb994: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1cb994u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cb998: 0x3e00008  jr          $ra
    ctx->pc = 0x1CB998u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CB99Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB998u;
            // 0x1cb99c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CB994u: goto label_1cb994;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CB9A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
