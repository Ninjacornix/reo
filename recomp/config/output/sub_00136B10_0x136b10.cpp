#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00136B10
// Address: 0x136b10 - 0x136b74
void sub_00136B10_0x136b10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00136B10_0x136b10");
#endif

    switch (ctx->pc) {
        case 0x136b30u: goto label_136b30;
        case 0x136b50u: goto label_136b50;
        case 0x136b60u: goto label_136b60;
        default: break;
    }

    ctx->pc = 0x136b10u;

    // 0x136b10: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x136b10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x136b14: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x136b14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x136b18: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x136b18u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136b1c: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x136B1Cu;
    {
        const bool branch_taken_0x136b1c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x136B20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136B1Cu;
            // 0x136b20: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136b1c) {
            ctx->pc = 0x136B38u;
            goto label_136b38;
        }
    }
    ctx->pc = 0x136B24u;
    // 0x136b24: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136b24u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136b28: 0xc04d480  jal         func_135200
    ctx->pc = 0x136B28u;
    SET_GPR_U32(ctx, 31, 0x136B30u);
    ctx->pc = 0x136B2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136B28u;
            // 0x136b2c: 0x2484c100  addiu       $a0, $a0, -0x3F00 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951168));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136B30u; }
        if (ctx->pc != 0x136B30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136B30u; }
        if (ctx->pc != 0x136B30u) { return; }
    }
    ctx->pc = 0x136B30u;
label_136b30:
    // 0x136b30: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x136B30u;
    {
        const bool branch_taken_0x136b30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136B34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136B30u;
            // 0x136b34: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136b30) {
            ctx->pc = 0x136B64u;
            goto label_136b64;
        }
    }
    ctx->pc = 0x136B38u;
label_136b38:
    // 0x136b38: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x136b38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x136b3c: 0x8c420064  lw          $v0, 0x64($v0)
    ctx->pc = 0x136b3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 100)));
    // 0x136b40: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x136B40u;
    {
        const bool branch_taken_0x136b40 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x136b40) {
            ctx->pc = 0x136B44u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x136B40u;
            // 0x136b44: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x136B58u;
            goto label_136b58;
        }
    }
    ctx->pc = 0x136B48u;
    // 0x136b48: 0x40f809  jalr        $v0
    ctx->pc = 0x136B48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x136B50u);
        ctx->pc = 0x136B4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136B48u;
            // 0x136b4c: 0x8c840004  lw          $a0, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x136B50u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136B30u: goto label_136b30;
            case 0x136B38u: goto label_136b38;
            case 0x136B50u: goto label_136b50;
            case 0x136B58u: goto label_136b58;
            case 0x136B60u: goto label_136b60;
            case 0x136B64u: goto label_136b64;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136B50u; }
            if (ctx->pc != 0x136B50u) { return; }
        }
        }
    }
    ctx->pc = 0x136B50u;
label_136b50:
    // 0x136b50: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x136B50u;
    {
        const bool branch_taken_0x136b50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136B54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136B50u;
            // 0x136b54: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136b50) {
            ctx->pc = 0x136B60u;
            goto label_136b60;
        }
    }
    ctx->pc = 0x136B58u;
label_136b58:
    // 0x136b58: 0xc04d480  jal         func_135200
    ctx->pc = 0x136B58u;
    SET_GPR_U32(ctx, 31, 0x136B60u);
    ctx->pc = 0x136B5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136B58u;
            // 0x136b5c: 0x2484c120  addiu       $a0, $a0, -0x3EE0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951200));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136B60u; }
        if (ctx->pc != 0x136B60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136B60u; }
        if (ctx->pc != 0x136B60u) { return; }
    }
    ctx->pc = 0x136B60u;
label_136b60:
    // 0x136b60: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x136b60u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_136b64:
    // 0x136b64: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x136b64u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x136b68: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x136b68u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x136b6c: 0x3e00008  jr          $ra
    ctx->pc = 0x136B6Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136B70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136B6Cu;
            // 0x136b70: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136B30u: goto label_136b30;
            case 0x136B38u: goto label_136b38;
            case 0x136B50u: goto label_136b50;
            case 0x136B58u: goto label_136b58;
            case 0x136B60u: goto label_136b60;
            case 0x136B64u: goto label_136b64;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136B74u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
