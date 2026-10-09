#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00122720
// Address: 0x122720 - 0x12276c
void sub_00122720_0x122720(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00122720_0x122720");
#endif

    switch (ctx->pc) {
        case 0x122750u: goto label_122750;
        default: break;
    }

    ctx->pc = 0x122720u;

    // 0x122720: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x122720u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x122724: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x122724u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x122728: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x122728u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12272c: 0x2450b410  addiu       $s0, $v0, -0x4BF0
    ctx->pc = 0x12272cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294947856));
    // 0x122730: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x122730u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x122734: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x122734u;
    {
        const bool branch_taken_0x122734 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x122738u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122734u;
            // 0x122738: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x122734) {
            ctx->pc = 0x122754u;
            goto label_122754;
        }
    }
    ctx->pc = 0x12273Cu;
    // 0x12273c: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x12273cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x122740: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x122740u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x122744: 0x2484b418  addiu       $a0, $a0, -0x4BE8
    ctx->pc = 0x122744u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294947864));
    // 0x122748: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x122748u;
    SET_GPR_U32(ctx, 31, 0x122750u);
    ctx->pc = 0x12274Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x122748u;
            // 0x12274c: 0x24060300  addiu       $a2, $zero, 0x300 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 768));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x122750u; }
        if (ctx->pc != 0x122750u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x122750u; }
        if (ctx->pc != 0x122750u) { return; }
    }
    ctx->pc = 0x122750u;
label_122750:
    // 0x122750: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x122750u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_122754:
    // 0x122754: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x122754u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x122758: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x122758u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12275c: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x12275cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x122760: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x122760u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x122764: 0x3e00008  jr          $ra
    ctx->pc = 0x122764u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x122768u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122764u;
            // 0x122768: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122750u: goto label_122750;
            case 0x122754u: goto label_122754;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12276Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
