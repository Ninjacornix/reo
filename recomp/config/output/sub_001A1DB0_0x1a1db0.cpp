#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A1DB0
// Address: 0x1a1db0 - 0x1a1e00
void sub_001A1DB0_0x1a1db0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A1DB0_0x1a1db0");
#endif

    switch (ctx->pc) {
        case 0x1a1dc0u: goto label_1a1dc0;
        case 0x1a1dd0u: goto label_1a1dd0;
        default: break;
    }

    ctx->pc = 0x1a1db0u;

    // 0x1a1db0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a1db0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a1db4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a1db4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a1db8: 0xc068768  jal         func_1A1DA0
    ctx->pc = 0x1A1DB8u;
    SET_GPR_U32(ctx, 31, 0x1A1DC0u);
    ctx->pc = 0x1A1DA0u;
    if (runtime->hasFunction(0x1A1DA0u)) {
        auto targetFn = runtime->lookupFunction(0x1A1DA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A1DC0u; }
        if (ctx->pc != 0x1A1DC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A1DA0_0x1a1da0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A1DC0u; }
        if (ctx->pc != 0x1A1DC0u) { return; }
    }
    ctx->pc = 0x1A1DC0u;
label_1a1dc0:
    // 0x1a1dc0: 0x24440014  addiu       $a0, $v0, 0x14
    ctx->pc = 0x1a1dc0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 20));
    // 0x1a1dc4: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1a1dc4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a1dc8: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1A1DC8u;
    {
        const bool branch_taken_0x1a1dc8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A1DCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1DC8u;
            // 0x1a1dcc: 0x24420014  addiu       $v0, $v0, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a1dc8) {
            ctx->pc = 0x1A1DE0u;
            goto label_1a1de0;
        }
    }
    ctx->pc = 0x1A1DD0u;
label_1a1dd0:
    // 0x1a1dd0: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1a1dd0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1a1dd4: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1a1dd4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1a1dd8: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x1a1dd8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1a1ddc: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1a1ddcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_1a1de0:
    // 0x1a1de0: 0xc5182a  slt         $v1, $a2, $a1
    ctx->pc = 0x1a1de0u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x1a1de4: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1A1DE4u;
    {
        const bool branch_taken_0x1a1de4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a1de4) {
            ctx->pc = 0x1A1DD0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a1dd0;
        }
    }
    ctx->pc = 0x1A1DECu;
    // 0x1a1dec: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a1decu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a1df0: 0x3e00008  jr          $ra
    ctx->pc = 0x1A1DF0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A1DF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1DF0u;
            // 0x1a1df4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A1DC0u: goto label_1a1dc0;
            case 0x1A1DD0u: goto label_1a1dd0;
            case 0x1A1DE0u: goto label_1a1de0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A1DF8u;
    // 0x1a1df8: 0x0  nop
    ctx->pc = 0x1a1df8u;
    // NOP
    // 0x1a1dfc: 0x0  nop
    ctx->pc = 0x1a1dfcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
