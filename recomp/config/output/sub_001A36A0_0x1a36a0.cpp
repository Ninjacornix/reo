#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A36A0
// Address: 0x1a36a0 - 0x1a36e0
void sub_001A36A0_0x1a36a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A36A0_0x1a36a0");
#endif

    switch (ctx->pc) {
        case 0x1a36b4u: goto label_1a36b4;
        default: break;
    }

    ctx->pc = 0x1a36a0u;

    // 0x1a36a0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a36a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a36a4: 0x24050005  addiu       $a1, $zero, 0x5
    ctx->pc = 0x1a36a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1a36a8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a36a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a36ac: 0xc068d7c  jal         func_1A35F0
    ctx->pc = 0x1A36ACu;
    SET_GPR_U32(ctx, 31, 0x1A36B4u);
    ctx->pc = 0x1A36B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A36ACu;
            // 0x1a36b0: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A35F0u;
    if (runtime->hasFunction(0x1A35F0u)) {
        auto targetFn = runtime->lookupFunction(0x1A35F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A36B4u; }
        if (ctx->pc != 0x1A36B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A35F0_0x1a35f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A36B4u; }
        if (ctx->pc != 0x1A36B4u) { return; }
    }
    ctx->pc = 0x1A36B4u;
label_1a36b4:
    // 0x1a36b4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A36B4u;
    {
        const bool branch_taken_0x1a36b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a36b4) {
            ctx->pc = 0x1A36C4u;
            goto label_1a36c4;
        }
    }
    ctx->pc = 0x1A36BCu;
    // 0x1a36bc: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1A36BCu;
    {
        const bool branch_taken_0x1a36bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A36C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A36BCu;
            // 0x1a36c0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a36bc) {
            ctx->pc = 0x1A36C8u;
            goto label_1a36c8;
        }
    }
    ctx->pc = 0x1A36C4u;
label_1a36c4:
    // 0x1a36c4: 0x8c420004  lw          $v0, 0x4($v0)
    ctx->pc = 0x1a36c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
label_1a36c8:
    // 0x1a36c8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a36c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a36cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1A36CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A36D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A36CCu;
            // 0x1a36d0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A36B4u: goto label_1a36b4;
            case 0x1A36C4u: goto label_1a36c4;
            case 0x1A36C8u: goto label_1a36c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A36D4u;
    // 0x1a36d4: 0x0  nop
    ctx->pc = 0x1a36d4u;
    // NOP
    // 0x1a36d8: 0x0  nop
    ctx->pc = 0x1a36d8u;
    // NOP
    // 0x1a36dc: 0x0  nop
    ctx->pc = 0x1a36dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
