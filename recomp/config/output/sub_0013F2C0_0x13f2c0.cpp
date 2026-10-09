#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013F2C0
// Address: 0x13f2c0 - 0x13f310
void sub_0013F2C0_0x13f2c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013F2C0_0x13f2c0");
#endif

    switch (ctx->pc) {
        case 0x13f2f0u: goto label_13f2f0;
        default: break;
    }

    ctx->pc = 0x13f2c0u;

    // 0x13f2c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13f2c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13f2c4: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13f2c4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13f2c8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13f2c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13f2cc: 0x24504798  addiu       $s0, $v0, 0x4798
    ctx->pc = 0x13f2ccu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 18328));
    // 0x13f2d0: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x13f2d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13f2d4: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x13F2D4u;
    {
        const bool branch_taken_0x13f2d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13F2D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F2D4u;
            // 0x13f2d8: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f2d4) {
            ctx->pc = 0x13F2F4u;
            goto label_13f2f4;
        }
    }
    ctx->pc = 0x13F2DCu;
    // 0x13f2dc: 0x3c040022  lui         $a0, 0x22
    ctx->pc = 0x13f2dcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)34 << 16));
    // 0x13f2e0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13f2e0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f2e4: 0x248447a0  addiu       $a0, $a0, 0x47A0
    ctx->pc = 0x13f2e4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 18336));
    // 0x13f2e8: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x13F2E8u;
    SET_GPR_U32(ctx, 31, 0x13F2F0u);
    ctx->pc = 0x13F2ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F2E8u;
            // 0x13f2ec: 0x24060480  addiu       $a2, $zero, 0x480 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1152));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F2F0u; }
        if (ctx->pc != 0x13F2F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F2F0u; }
        if (ctx->pc != 0x13F2F0u) { return; }
    }
    ctx->pc = 0x13F2F0u;
label_13f2f0:
    // 0x13f2f0: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x13f2f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_13f2f4:
    // 0x13f2f4: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x13f2f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x13f2f8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x13f2f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13f2fc: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x13f2fcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x13f300: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13f300u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13f304: 0x3e00008  jr          $ra
    ctx->pc = 0x13F304u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F308u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F304u;
            // 0x13f308: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13F2F0u: goto label_13f2f0;
            case 0x13F2F4u: goto label_13f2f4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13F30Cu;
    // 0x13f30c: 0x0  nop
    ctx->pc = 0x13f30cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
