#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00164540
// Address: 0x164540 - 0x164580
void sub_00164540_0x164540(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00164540_0x164540");
#endif

    ctx->pc = 0x164540u;

    // 0x164540: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x164540u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x164544: 0x10800004  beqz        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x164544u;
    {
        const bool branch_taken_0x164544 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x164548u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164544u;
            // 0x164548: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x164544) {
            ctx->pc = 0x164558u;
            goto label_164558;
        }
    }
    ctx->pc = 0x16454Cu;
    // 0x16454c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16454cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x164550: 0x804c386  j           func_130E18
    ctx->pc = 0x164550u;
    ctx->pc = 0x164554u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164550u;
            // 0x164554: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130E18u;
    if (runtime->hasFunction(0x130E18u)) {
        auto targetFn = runtime->lookupFunction(0x130E18u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00130E18_0x130e18(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x164558u;
label_164558:
    // 0x164558: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x164558u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16455c: 0x3e00008  jr          $ra
    ctx->pc = 0x16455Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x164560u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16455Cu;
            // 0x164560: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x164558u: goto label_164558;
            default: break;
        }
        return;
    }
    ctx->pc = 0x164564u;
    // 0x164564: 0x0  nop
    ctx->pc = 0x164564u;
    // NOP
    // 0x164568: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x164568u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16456c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16456cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x164570: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x164570u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x164574: 0x804c37e  j           func_130DF8
    ctx->pc = 0x164574u;
    ctx->pc = 0x164578u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164574u;
            // 0x164578: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130DF8u;
    if (runtime->hasFunction(0x130DF8u)) {
        auto targetFn = runtime->lookupFunction(0x130DF8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00130DF8_0x130df8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16457Cu;
    // 0x16457c: 0x0  nop
    ctx->pc = 0x16457cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
