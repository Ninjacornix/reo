#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001790A8
// Address: 0x1790a8 - 0x1790ec
void sub_001790A8_0x1790a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001790A8_0x1790a8");
#endif

    ctx->pc = 0x1790a8u;

    // 0x1790a8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1790a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1790ac: 0x3c030027  lui         $v1, 0x27
    ctx->pc = 0x1790acu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)39 << 16));
    // 0x1790b0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1790b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1790b4: 0x24636144  addiu       $v1, $v1, 0x6144
    ctx->pc = 0x1790b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 24900));
    // 0x1790b8: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1790b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1790bc: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1790bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1790c0: 0x1c400007  bgtz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1790C0u;
    {
        const bool branch_taken_0x1790c0 = (GPR_S64(ctx, 2) > 0);
        ctx->pc = 0x1790C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1790C0u;
            // 0x1790c4: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1790c0) {
            ctx->pc = 0x1790E0u;
            goto label_1790e0;
        }
    }
    ctx->pc = 0x1790C8u;
    // 0x1790c8: 0x3c040027  lui         $a0, 0x27
    ctx->pc = 0x1790c8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)39 << 16));
    // 0x1790cc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1790ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1790d0: 0x24846138  addiu       $a0, $a0, 0x6138
    ctx->pc = 0x1790d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 24888));
    // 0x1790d4: 0x805e47a  j           func_1791E8
    ctx->pc = 0x1790D4u;
    ctx->pc = 0x1790D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1790D4u;
            // 0x1790d8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1791E8u;
    if (runtime->hasFunction(0x1791E8u)) {
        auto targetFn = runtime->lookupFunction(0x1791E8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001791E8_0x1791e8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1790DCu;
    // 0x1790dc: 0x0  nop
    ctx->pc = 0x1790dcu;
    // NOP
label_1790e0:
    // 0x1790e0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1790e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1790e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1790E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1790E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1790E4u;
            // 0x1790e8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1790E0u: goto label_1790e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1790ECu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
