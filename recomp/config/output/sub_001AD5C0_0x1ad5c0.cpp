#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AD5C0
// Address: 0x1ad5c0 - 0x1ad610
void sub_001AD5C0_0x1ad5c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AD5C0_0x1ad5c0");
#endif

    switch (ctx->pc) {
        case 0x1ad5dcu: goto label_1ad5dc;
        default: break;
    }

    ctx->pc = 0x1ad5c0u;

    // 0x1ad5c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1ad5c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1ad5c4: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1ad5c4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1ad5c8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1ad5c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1ad5cc: 0x24843840  addiu       $a0, $a0, 0x3840
    ctx->pc = 0x1ad5ccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 14400));
    // 0x1ad5d0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1ad5d0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ad5d4: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1AD5D4u;
    SET_GPR_U32(ctx, 31, 0x1AD5DCu);
    ctx->pc = 0x1AD5D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD5D4u;
            // 0x1ad5d8: 0x24060108  addiu       $a2, $zero, 0x108 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 264));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD5DCu; }
        if (ctx->pc != 0x1AD5DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AD5DCu; }
        if (ctx->pc != 0x1AD5DCu) { return; }
    }
    ctx->pc = 0x1AD5DCu;
label_1ad5dc:
    // 0x1ad5dc: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1ad5dcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1ad5e0: 0x8c24440c  lw          $a0, 0x440C($at)
    ctx->pc = 0x1ad5e0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1ad5e4: 0x10800004  beqz        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1AD5E4u;
    {
        const bool branch_taken_0x1ad5e4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AD5E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD5E4u;
            // 0x1ad5e8: 0x3c030008  lui         $v1, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ad5e4) {
            ctx->pc = 0x1AD5F8u;
            goto label_1ad5f8;
        }
    }
    ctx->pc = 0x1AD5ECu;
    // 0x1ad5ec: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1ad5ecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1ad5f0: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x1ad5f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1ad5f4: 0xac233848  sw          $v1, 0x3848($at)
    ctx->pc = 0x1ad5f4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 14408), GPR_U32(ctx, 3));
label_1ad5f8:
    // 0x1ad5f8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1ad5f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ad5fc: 0x3e00008  jr          $ra
    ctx->pc = 0x1AD5FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AD600u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AD5FCu;
            // 0x1ad600: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AD5DCu: goto label_1ad5dc;
            case 0x1AD5F8u: goto label_1ad5f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AD604u;
    // 0x1ad604: 0x0  nop
    ctx->pc = 0x1ad604u;
    // NOP
    // 0x1ad608: 0x0  nop
    ctx->pc = 0x1ad608u;
    // NOP
    // 0x1ad60c: 0x0  nop
    ctx->pc = 0x1ad60cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
