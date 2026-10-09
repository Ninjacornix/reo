#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013F310
// Address: 0x13f310 - 0x13f360
void sub_0013F310_0x13f310(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013F310_0x13f310");
#endif

    ctx->pc = 0x13f310u;

    // 0x13f310: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13f310u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13f314: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13f314u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13f318: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13f318u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13f31c: 0x24634798  addiu       $v1, $v1, 0x4798
    ctx->pc = 0x13f31cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 18328));
    // 0x13f320: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x13f320u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x13f324: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x13f324u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x13f328: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x13F328u;
    {
        const bool branch_taken_0x13f328 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13F32Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F328u;
            // 0x13f32c: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f328) {
            ctx->pc = 0x13F350u;
            goto label_13f350;
        }
    }
    ctx->pc = 0x13F330u;
    // 0x13f330: 0x3c040022  lui         $a0, 0x22
    ctx->pc = 0x13f330u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)34 << 16));
    // 0x13f334: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13f334u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13f338: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13f338u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f33c: 0x248447a0  addiu       $a0, $a0, 0x47A0
    ctx->pc = 0x13f33cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 18336));
    // 0x13f340: 0x24060480  addiu       $a2, $zero, 0x480
    ctx->pc = 0x13f340u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1152));
    // 0x13f344: 0x8041f1a  j           func_107C68
    ctx->pc = 0x13F344u;
    ctx->pc = 0x13F348u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F344u;
            // 0x13f348: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13F34Cu;
    // 0x13f34c: 0x0  nop
    ctx->pc = 0x13f34cu;
    // NOP
label_13f350:
    // 0x13f350: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13f350u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13f354: 0x3e00008  jr          $ra
    ctx->pc = 0x13F354u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F358u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F354u;
            // 0x13f358: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13F350u: goto label_13f350;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13F35Cu;
    // 0x13f35c: 0x0  nop
    ctx->pc = 0x13f35cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
