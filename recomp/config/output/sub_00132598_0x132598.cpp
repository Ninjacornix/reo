#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00132598
// Address: 0x132598 - 0x1325e4
void sub_00132598_0x132598(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00132598_0x132598");
#endif

    switch (ctx->pc) {
        case 0x1325b0u: goto label_1325b0;
        default: break;
    }

    ctx->pc = 0x132598u;

    // 0x132598: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x132598u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13259c: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x13259Cu;
    {
        const bool branch_taken_0x13259c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1325A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13259Cu;
            // 0x1325a0: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13259c) {
            ctx->pc = 0x1325B8u;
            goto label_1325b8;
        }
    }
    ctx->pc = 0x1325A4u;
    // 0x1325a4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1325a4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1325a8: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x1325A8u;
    SET_GPR_U32(ctx, 31, 0x1325B0u);
    ctx->pc = 0x1325ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1325A8u;
            // 0x1325ac: 0x2484b028  addiu       $a0, $a0, -0x4FD8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294946856));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1325B0u; }
        if (ctx->pc != 0x1325B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1325B0u; }
        if (ctx->pc != 0x1325B0u) { return; }
    }
    ctx->pc = 0x1325B0u;
label_1325b0:
    // 0x1325b0: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1325B0u;
    {
        const bool branch_taken_0x1325b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1325B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1325B0u;
            // 0x1325b4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1325b0) {
            ctx->pc = 0x1325D8u;
            goto label_1325d8;
        }
    }
    ctx->pc = 0x1325B8u;
label_1325b8:
    // 0x1325b8: 0x80820001  lb          $v0, 0x1($a0)
    ctx->pc = 0x1325b8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x1325bc: 0x28420002  slti        $v0, $v0, 0x2
    ctx->pc = 0x1325bcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1325c0: 0x54400005  bnel        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x1325C0u;
    {
        const bool branch_taken_0x1325c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1325c0) {
            ctx->pc = 0x1325C4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1325C0u;
            // 0x1325c4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1325D8u;
            goto label_1325d8;
        }
    }
    ctx->pc = 0x1325C8u;
    // 0x1325c8: 0x8c840004  lw          $a0, 0x4($a0)
    ctx->pc = 0x1325c8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1325cc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1325ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1325d0: 0x804b684  j           func_12DA10
    ctx->pc = 0x1325D0u;
    ctx->pc = 0x1325D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1325D0u;
            // 0x1325d4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12DA10u;
    {
        auto targetFn = runtime->lookupFunction(0x12DA10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        return;
    }
    ctx->pc = 0x1325D8u;
label_1325d8:
    // 0x1325d8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1325d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1325dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1325DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1325E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1325DCu;
            // 0x1325e0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1325B0u: goto label_1325b0;
            case 0x1325B8u: goto label_1325b8;
            case 0x1325D8u: goto label_1325d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1325E4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
