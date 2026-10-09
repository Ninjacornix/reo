#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AF710
// Address: 0x1af710 - 0x1af770
void sub_001AF710_0x1af710(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AF710_0x1af710");
#endif

    switch (ctx->pc) {
        case 0x1af720u: goto label_1af720;
        default: break;
    }

    ctx->pc = 0x1af710u;

    // 0x1af710: 0x3c03002c  lui         $v1, 0x2C
    ctx->pc = 0x1af710u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)44 << 16));
    // 0x1af714: 0x24050007  addiu       $a1, $zero, 0x7
    ctx->pc = 0x1af714u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1af718: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1AF718u;
    {
        const bool branch_taken_0x1af718 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AF71Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF718u;
            // 0x1af71c: 0x24638e88  addiu       $v1, $v1, -0x7178 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294938248));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1af718) {
            ctx->pc = 0x1AF734u;
            goto label_1af734;
        }
    }
    ctx->pc = 0x1AF720u;
label_1af720:
    // 0x1af720: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1af720u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1af724: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1AF724u;
    {
        const bool branch_taken_0x1af724 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1af724) {
            ctx->pc = 0x1AF740u;
            goto label_1af740;
        }
    }
    ctx->pc = 0x1AF72Cu;
    // 0x1af72c: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x1af72cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x1af730: 0x2463fff8  addiu       $v1, $v1, -0x8
    ctx->pc = 0x1af730u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967288));
label_1af734:
    // 0x1af734: 0x0  nop
    ctx->pc = 0x1af734u;
    // NOP
    // 0x1af738: 0x4a1fff9  bgez        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1AF738u;
    {
        const bool branch_taken_0x1af738 = (GPR_S64(ctx, 5) >= 0);
        if (branch_taken_0x1af738) {
            ctx->pc = 0x1AF720u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1af720;
        }
    }
    ctx->pc = 0x1AF740u;
label_1af740:
    // 0x1af740: 0x8c620004  lw          $v0, 0x4($v1)
    ctx->pc = 0x1af740u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x1af744: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1af744u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1af748: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x1af748u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1af74c: 0xac620004  sw          $v0, 0x4($v1)
    ctx->pc = 0x1af74cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
    // 0x1af750: 0x8c630004  lw          $v1, 0x4($v1)
    ctx->pc = 0x1af750u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x1af754: 0x8c228de0  lw          $v0, -0x7220($at)
    ctx->pc = 0x1af754u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294938080)));
    // 0x1af758: 0x43082a  slt         $at, $v0, $v1
    ctx->pc = 0x1af758u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1af75c: 0x10200002  beqz        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1AF75Cu;
    {
        const bool branch_taken_0x1af75c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AF760u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF75Cu;
            // 0x1af760: 0x3c01002c  lui         $at, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1af75c) {
            ctx->pc = 0x1AF768u;
            goto label_1af768;
        }
    }
    ctx->pc = 0x1AF764u;
    // 0x1af764: 0xac238de0  sw          $v1, -0x7220($at)
    ctx->pc = 0x1af764u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294938080), GPR_U32(ctx, 3));
label_1af768:
    // 0x1af768: 0x80636f8  j           func_18DBE0
    ctx->pc = 0x1AF768u;
    ctx->pc = 0x18DBE0u;
    if (runtime->hasFunction(0x18DBE0u)) {
        auto targetFn = runtime->lookupFunction(0x18DBE0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0018DBE0_0x18dbe0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1AF770u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
