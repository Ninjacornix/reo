#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00132DF0
// Address: 0x132df0 - 0x132e20
void sub_00132DF0_0x132df0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00132DF0_0x132df0");
#endif

    ctx->pc = 0x132df0u;

    // 0x132df0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x132df0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x132df4: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x132DF4u;
    {
        const bool branch_taken_0x132df4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x132DF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132DF4u;
            // 0x132df8: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132df4) {
            ctx->pc = 0x132E10u;
            goto label_132e10;
        }
    }
    ctx->pc = 0x132DFCu;
    // 0x132dfc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x132dfcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x132e00: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x132e00u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132e04: 0x2484b450  addiu       $a0, $a0, -0x4BB0
    ctx->pc = 0x132e04u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294947920));
    // 0x132e08: 0x804a034  j           func_1280D0
    ctx->pc = 0x132E08u;
    ctx->pc = 0x132E0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132E08u;
            // 0x132e0c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x132E10u;
label_132e10:
    // 0x132e10: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x132e10u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132e14: 0xa0850070  sb          $a1, 0x70($a0)
    ctx->pc = 0x132e14u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 112), (uint8_t)GPR_U32(ctx, 5));
    // 0x132e18: 0x3e00008  jr          $ra
    ctx->pc = 0x132E18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x132E1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132E18u;
            // 0x132e1c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x132E10u: goto label_132e10;
            default: break;
        }
        return;
    }
    ctx->pc = 0x132E20u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
