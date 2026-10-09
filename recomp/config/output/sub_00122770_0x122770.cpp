#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00122770
// Address: 0x122770 - 0x1227bc
void sub_00122770_0x122770(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00122770_0x122770");
#endif

    ctx->pc = 0x122770u;

    // 0x122770: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x122770u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x122774: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x122774u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x122778: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x122778u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12277c: 0x2463b410  addiu       $v1, $v1, -0x4BF0
    ctx->pc = 0x12277cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294947856));
    // 0x122780: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x122780u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x122784: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x122784u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x122788: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x122788u;
    {
        const bool branch_taken_0x122788 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12278Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122788u;
            // 0x12278c: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x122788) {
            ctx->pc = 0x1227B0u;
            goto label_1227b0;
        }
    }
    ctx->pc = 0x122790u;
    // 0x122790: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x122790u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x122794: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x122794u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x122798: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x122798u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12279c: 0x2484b418  addiu       $a0, $a0, -0x4BE8
    ctx->pc = 0x12279cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294947864));
    // 0x1227a0: 0x24060300  addiu       $a2, $zero, 0x300
    ctx->pc = 0x1227a0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 768));
    // 0x1227a4: 0x8041f1a  j           func_107C68
    ctx->pc = 0x1227A4u;
    ctx->pc = 0x1227A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1227A4u;
            // 0x1227a8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1227ACu;
    // 0x1227ac: 0x0  nop
    ctx->pc = 0x1227acu;
    // NOP
label_1227b0:
    // 0x1227b0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1227b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1227b4: 0x3e00008  jr          $ra
    ctx->pc = 0x1227B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1227B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1227B4u;
            // 0x1227b8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1227B0u: goto label_1227b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1227BCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
