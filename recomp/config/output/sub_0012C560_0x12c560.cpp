#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C560
// Address: 0x12c560 - 0x12c594
void sub_0012C560_0x12c560(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C560_0x12c560");
#endif

    switch (ctx->pc) {
        case 0x12c584u: goto label_12c584;
        default: break;
    }

    ctx->pc = 0x12c560u;

    // 0x12c560: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c560u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c564: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c564u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c568: 0x8c82000c  lw          $v0, 0xC($a0)
    ctx->pc = 0x12c568u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x12c56c: 0x52080  sll         $a0, $a1, 2
    ctx->pc = 0x12c56cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x12c570: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12c570u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12c574: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x12c574u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x12c578: 0x8c430008  lw          $v1, 0x8($v0)
    ctx->pc = 0x12c578u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x12c57c: 0xc050374  jal         func_140DD0
    ctx->pc = 0x12C57Cu;
    SET_GPR_U32(ctx, 31, 0x12C584u);
    ctx->pc = 0x12C580u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C57Cu;
            // 0x12c580: 0x8c640004  lw          $a0, 0x4($v1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x140DD0u;
    if (runtime->hasFunction(0x140DD0u)) {
        auto targetFn = runtime->lookupFunction(0x140DD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C584u; }
        if (ctx->pc != 0x12C584u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00140DD0_0x140dd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C584u; }
        if (ctx->pc != 0x12C584u) { return; }
    }
    ctx->pc = 0x12C584u;
label_12c584:
    // 0x12c584: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c584u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c588: 0x21042  srl         $v0, $v0, 1
    ctx->pc = 0x12c588u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 1));
    // 0x12c58c: 0x3e00008  jr          $ra
    ctx->pc = 0x12C58Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12C590u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12C58Cu;
            // 0x12c590: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12C584u: goto label_12c584;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12C594u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
