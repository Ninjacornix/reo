#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00132D90
// Address: 0x132d90 - 0x132dc0
void sub_00132D90_0x132d90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00132D90_0x132d90");
#endif

    ctx->pc = 0x132d90u;

    // 0x132d90: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x132d90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x132d94: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x132D94u;
    {
        const bool branch_taken_0x132d94 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x132D98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132D94u;
            // 0x132d98: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132d94) {
            ctx->pc = 0x132DB0u;
            goto label_132db0;
        }
    }
    ctx->pc = 0x132D9Cu;
    // 0x132d9c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x132d9cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x132da0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x132da0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132da4: 0x2484b3f0  addiu       $a0, $a0, -0x4C10
    ctx->pc = 0x132da4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294947824));
    // 0x132da8: 0x804a034  j           func_1280D0
    ctx->pc = 0x132DA8u;
    ctx->pc = 0x132DACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132DA8u;
            // 0x132dac: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x132DB0u;
label_132db0:
    // 0x132db0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x132db0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132db4: 0xa085006c  sb          $a1, 0x6C($a0)
    ctx->pc = 0x132db4u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 108), (uint8_t)GPR_U32(ctx, 5));
    // 0x132db8: 0x3e00008  jr          $ra
    ctx->pc = 0x132DB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x132DBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132DB8u;
            // 0x132dbc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x132DB0u: goto label_132db0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x132DC0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
