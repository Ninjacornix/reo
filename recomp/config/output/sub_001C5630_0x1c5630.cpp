#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C5630
// Address: 0x1c5630 - 0x1c56a0
void sub_001C5630_0x1c5630(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C5630_0x1c5630");
#endif

    switch (ctx->pc) {
        case 0x1c5690u: goto label_1c5690;
        default: break;
    }

    ctx->pc = 0x1c5630u;

    // 0x1c5630: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1c5630u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1c5634: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1c5634u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1c5638: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1c5638u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1c563c: 0x8c840020  lw          $a0, 0x20($a0)
    ctx->pc = 0x1c563cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 32)));
    // 0x1c5640: 0x10830013  beq         $a0, $v1, . + 4 + (0x13 << 2)
    ctx->pc = 0x1C5640u;
    {
        const bool branch_taken_0x1c5640 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C5644u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5640u;
            // 0x1c5644: 0x24030003  addiu       $v1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5640) {
            ctx->pc = 0x1C5690u;
            goto label_1c5690;
        }
    }
    ctx->pc = 0x1C5648u;
    // 0x1c5648: 0x10830011  beq         $a0, $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x1C5648u;
    {
        const bool branch_taken_0x1c5648 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c5648) {
            ctx->pc = 0x1C5690u;
            goto label_1c5690;
        }
    }
    ctx->pc = 0x1C5650u;
    // 0x1c5650: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1c5650u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c5654: 0x1083000e  beq         $a0, $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x1C5654u;
    {
        const bool branch_taken_0x1c5654 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C5658u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5654u;
            // 0x1c5658: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5654) {
            ctx->pc = 0x1C5690u;
            goto label_1c5690;
        }
    }
    ctx->pc = 0x1C565Cu;
    // 0x1c565c: 0x10830005  beq         $a0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1C565Cu;
    {
        const bool branch_taken_0x1c565c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c565c) {
            ctx->pc = 0x1C5674u;
            goto label_1c5674;
        }
    }
    ctx->pc = 0x1C5664u;
    // 0x1c5664: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C5664u;
    {
        const bool branch_taken_0x1c5664 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c5664) {
            ctx->pc = 0x1C5674u;
            goto label_1c5674;
        }
    }
    ctx->pc = 0x1C566Cu;
    // 0x1c566c: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1C566Cu;
    {
        const bool branch_taken_0x1c566c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C5670u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C566Cu;
            // 0x1c5670: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c566c) {
            ctx->pc = 0x1C5694u;
            goto label_1c5694;
        }
    }
    ctx->pc = 0x1C5674u;
label_1c5674:
    // 0x1c5674: 0x3c040032  lui         $a0, 0x32
    ctx->pc = 0x1c5674u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)50 << 16));
    // 0x1c5678: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c5678u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c567c: 0x24848b60  addiu       $a0, $a0, -0x74A0
    ctx->pc = 0x1c567cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294937440));
    // 0x1c5680: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1c5680u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5684: 0x24067000  addiu       $a2, $zero, 0x7000
    ctx->pc = 0x1c5684u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 28672));
    // 0x1c5688: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1C5688u;
    SET_GPR_U32(ctx, 31, 0x1C5690u);
    ctx->pc = 0x1C568Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5688u;
            // 0x1c568c: 0xa0204488  sb          $zero, 0x4488($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 17544), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5690u; }
        if (ctx->pc != 0x1C5690u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5690u; }
        if (ctx->pc != 0x1C5690u) { return; }
    }
    ctx->pc = 0x1C5690u;
label_1c5690:
    // 0x1c5690: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1c5690u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1c5694:
    // 0x1c5694: 0x3e00008  jr          $ra
    ctx->pc = 0x1C5694u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C5698u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5694u;
            // 0x1c5698: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C5674u: goto label_1c5674;
            case 0x1C5690u: goto label_1c5690;
            case 0x1C5694u: goto label_1c5694;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C569Cu;
    // 0x1c569c: 0x0  nop
    ctx->pc = 0x1c569cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
