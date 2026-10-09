#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00188B78
// Address: 0x188b78 - 0x188bc0
void sub_00188B78_0x188b78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00188B78_0x188b78");
#endif

    switch (ctx->pc) {
        case 0x188bb0u: goto label_188bb0;
        default: break;
    }

    ctx->pc = 0x188b78u;

    // 0x188b78: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x188b78u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x188b7c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x188b7cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x188b80: 0x8c62fd38  lw          $v0, -0x2C8($v1)
    ctx->pc = 0x188b80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294966584)));
    // 0x188b84: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x188B84u;
    {
        const bool branch_taken_0x188b84 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x188B88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x188B84u;
            // 0x188b88: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x188b84) {
            ctx->pc = 0x188B94u;
            goto label_188b94;
        }
    }
    ctx->pc = 0x188B8Cu;
    // 0x188b8c: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x188B8Cu;
    {
        const bool branch_taken_0x188b8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x188B90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x188B8Cu;
            // 0x188b90: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x188b8c) {
            ctx->pc = 0x188BB4u;
            goto label_188bb4;
        }
    }
    ctx->pc = 0x188B94u;
label_188b94:
    // 0x188b94: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x188b94u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x188b98: 0xac60fd38  sw          $zero, -0x2C8($v1)
    ctx->pc = 0x188b98u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294966584), GPR_U32(ctx, 0));
    // 0x188b9c: 0x8c444140  lw          $a0, 0x4140($v0)
    ctx->pc = 0x188b9cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16704)));
    // 0x188ba0: 0x4800004  bltz        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x188BA0u;
    {
        const bool branch_taken_0x188ba0 = (GPR_S64(ctx, 4) < 0);
        ctx->pc = 0x188BA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x188BA0u;
            // 0x188ba4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x188ba0) {
            ctx->pc = 0x188BB4u;
            goto label_188bb4;
        }
    }
    ctx->pc = 0x188BA8u;
    // 0x188ba8: 0xc04518c  jal         func_114630
    ctx->pc = 0x188BA8u;
    SET_GPR_U32(ctx, 31, 0x188BB0u);
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188BB0u; }
        if (ctx->pc != 0x188BB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188BB0u; }
        if (ctx->pc != 0x188BB0u) { return; }
    }
    ctx->pc = 0x188BB0u;
label_188bb0:
    // 0x188bb0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x188bb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_188bb4:
    // 0x188bb4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x188bb4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x188bb8: 0x3e00008  jr          $ra
    ctx->pc = 0x188BB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x188BBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x188BB8u;
            // 0x188bbc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x188B94u: goto label_188b94;
            case 0x188BB0u: goto label_188bb0;
            case 0x188BB4u: goto label_188bb4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x188BC0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
