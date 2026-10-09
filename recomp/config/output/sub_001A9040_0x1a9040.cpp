#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A9040
// Address: 0x1a9040 - 0x1a9070
void sub_001A9040_0x1a9040(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A9040_0x1a9040");
#endif

    switch (ctx->pc) {
        case 0x1a9060u: goto label_1a9060;
        default: break;
    }

    ctx->pc = 0x1a9040u;

    // 0x1a9040: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a9040u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a9044: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a9044u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a9048: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a9048u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a904c: 0x8c230ec0  lw          $v1, 0xEC0($at)
    ctx->pc = 0x1a904cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 3776)));
    // 0x1a9050: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A9050u;
    {
        const bool branch_taken_0x1a9050 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A9054u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9050u;
            // 0x1a9054: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9050) {
            ctx->pc = 0x1A9060u;
            goto label_1a9060;
        }
    }
    ctx->pc = 0x1A9058u;
    // 0x1a9058: 0xc04afb8  jal         func_12BEE0
    ctx->pc = 0x1A9058u;
    SET_GPR_U32(ctx, 31, 0x1A9060u);
    ctx->pc = 0x12BEE0u;
    if (runtime->hasFunction(0x12BEE0u)) {
        auto targetFn = runtime->lookupFunction(0x12BEE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9060u; }
        if (ctx->pc != 0x1A9060u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012BEE0_0x12bee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9060u; }
        if (ctx->pc != 0x1A9060u) { return; }
    }
    ctx->pc = 0x1A9060u;
label_1a9060:
    // 0x1a9060: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a9060u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a9064: 0x3e00008  jr          $ra
    ctx->pc = 0x1A9064u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A9068u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9064u;
            // 0x1a9068: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A9060u: goto label_1a9060;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A906Cu;
    // 0x1a906c: 0x0  nop
    ctx->pc = 0x1a906cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
