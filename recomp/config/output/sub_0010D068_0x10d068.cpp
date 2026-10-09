#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010D068
// Address: 0x10d068 - 0x10d0b0
void sub_0010D068_0x10d068(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010D068_0x10d068");
#endif

    switch (ctx->pc) {
        case 0x10d098u: goto label_10d098;
        default: break;
    }

    ctx->pc = 0x10d068u;

    // 0x10d068: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x10d068u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x10d06c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x10d06cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x10d070: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x10d070u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d074: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x10d074u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x10d078: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x10d078u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x10d07c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x10D07Cu;
    {
        const bool branch_taken_0x10d07c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10D080u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D07Cu;
            // 0x10d080: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d07c) {
            ctx->pc = 0x10D090u;
            goto label_10d090;
        }
    }
    ctx->pc = 0x10D084u;
    // 0x10d084: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x10D084u;
    {
        const bool branch_taken_0x10d084 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D088u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D084u;
            // 0x10d088: 0xae000004  sw          $zero, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d084) {
            ctx->pc = 0x10D0A0u;
            goto label_10d0a0;
        }
    }
    ctx->pc = 0x10D08Cu;
    // 0x10d08c: 0x0  nop
    ctx->pc = 0x10d08cu;
    // NOP
label_10d090:
    // 0x10d090: 0xc0418d6  jal         func_106358
    ctx->pc = 0x10D090u;
    SET_GPR_U32(ctx, 31, 0x10D098u);
    ctx->pc = 0x106358u;
    if (runtime->hasFunction(0x106358u)) {
        auto targetFn = runtime->lookupFunction(0x106358u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D098u; }
        if (ctx->pc != 0x10D098u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00106358_0x106358(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D098u; }
        if (ctx->pc != 0x10D098u) { return; }
    }
    ctx->pc = 0x10D098u;
label_10d098:
    // 0x10d098: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x10d098u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x10d09c: 0xae000008  sw          $zero, 0x8($s0)
    ctx->pc = 0x10d09cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
label_10d0a0:
    // 0x10d0a0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x10d0a0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10d0a4: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x10d0a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x10d0a8: 0x3e00008  jr          $ra
    ctx->pc = 0x10D0A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10D0ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D0A8u;
            // 0x10d0ac: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10D090u: goto label_10d090;
            case 0x10D098u: goto label_10d098;
            case 0x10D0A0u: goto label_10d0a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10D0B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
