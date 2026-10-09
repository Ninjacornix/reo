#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00136350
// Address: 0x136350 - 0x1363a8
void sub_00136350_0x136350(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00136350_0x136350");
#endif

    switch (ctx->pc) {
        case 0x136388u: goto label_136388;
        default: break;
    }

    ctx->pc = 0x136350u;

    // 0x136350: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x136350u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x136354: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x136354u;
    {
        const bool branch_taken_0x136354 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x136358u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136354u;
            // 0x136358: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136354) {
            ctx->pc = 0x136370u;
            goto label_136370;
        }
    }
    ctx->pc = 0x13635Cu;
    // 0x13635c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13635cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136360: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x136360u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x136364: 0x2484bce0  addiu       $a0, $a0, -0x4320
    ctx->pc = 0x136364u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950112));
    // 0x136368: 0x804d480  j           func_135200
    ctx->pc = 0x136368u;
    ctx->pc = 0x13636Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136368u;
            // 0x13636c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00135200_0x135200(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x136370u;
label_136370:
    // 0x136370: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x136370u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x136374: 0x8c420034  lw          $v0, 0x34($v0)
    ctx->pc = 0x136374u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 52)));
    // 0x136378: 0x50400007  beql        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x136378u;
    {
        const bool branch_taken_0x136378 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x136378) {
            ctx->pc = 0x13637Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x136378u;
            // 0x13637c: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x136398u;
            goto label_136398;
        }
    }
    ctx->pc = 0x136380u;
    // 0x136380: 0x40f809  jalr        $v0
    ctx->pc = 0x136380u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x136388u);
        ctx->pc = 0x136384u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136380u;
            // 0x136384: 0x8c840004  lw          $a0, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x136388u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136370u: goto label_136370;
            case 0x136388u: goto label_136388;
            case 0x136398u: goto label_136398;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136388u; }
            if (ctx->pc != 0x136388u) { return; }
        }
        }
    }
    ctx->pc = 0x136388u;
label_136388:
    // 0x136388: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x136388u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13638c: 0x3e00008  jr          $ra
    ctx->pc = 0x13638Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136390u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13638Cu;
            // 0x136390: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136370u: goto label_136370;
            case 0x136388u: goto label_136388;
            case 0x136398u: goto label_136398;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136394u;
    // 0x136394: 0x0  nop
    ctx->pc = 0x136394u;
    // NOP
label_136398:
    // 0x136398: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x136398u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13639c: 0x2484bd00  addiu       $a0, $a0, -0x4300
    ctx->pc = 0x13639cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950144));
    // 0x1363a0: 0x804d480  j           func_135200
    ctx->pc = 0x1363A0u;
    ctx->pc = 0x1363A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1363A0u;
            // 0x1363a4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00135200_0x135200(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1363A8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
