#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00135E30
// Address: 0x135e30 - 0x135e94
void sub_00135E30_0x135e30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00135E30_0x135e30");
#endif

    switch (ctx->pc) {
        case 0x135e50u: goto label_135e50;
        case 0x135e70u: goto label_135e70;
        case 0x135e80u: goto label_135e80;
        default: break;
    }

    ctx->pc = 0x135e30u;

    // 0x135e30: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x135e30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x135e34: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x135e34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x135e38: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x135e38u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x135e3c: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x135E3Cu;
    {
        const bool branch_taken_0x135e3c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x135E40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135E3Cu;
            // 0x135e40: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135e3c) {
            ctx->pc = 0x135E58u;
            goto label_135e58;
        }
    }
    ctx->pc = 0x135E44u;
    // 0x135e44: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x135e44u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x135e48: 0xc04d480  jal         func_135200
    ctx->pc = 0x135E48u;
    SET_GPR_U32(ctx, 31, 0x135E50u);
    ctx->pc = 0x135E4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x135E48u;
            // 0x135e4c: 0x2484ba38  addiu       $a0, $a0, -0x45C8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949432));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135E50u; }
        if (ctx->pc != 0x135E50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135E50u; }
        if (ctx->pc != 0x135E50u) { return; }
    }
    ctx->pc = 0x135E50u;
label_135e50:
    // 0x135e50: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x135E50u;
    {
        const bool branch_taken_0x135e50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x135E54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135E50u;
            // 0x135e54: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135e50) {
            ctx->pc = 0x135E84u;
            goto label_135e84;
        }
    }
    ctx->pc = 0x135E58u;
label_135e58:
    // 0x135e58: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x135e58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x135e5c: 0x8c420024  lw          $v0, 0x24($v0)
    ctx->pc = 0x135e5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 36)));
    // 0x135e60: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x135E60u;
    {
        const bool branch_taken_0x135e60 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x135e60) {
            ctx->pc = 0x135E64u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x135E60u;
            // 0x135e64: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x135E78u;
            goto label_135e78;
        }
    }
    ctx->pc = 0x135E68u;
    // 0x135e68: 0x40f809  jalr        $v0
    ctx->pc = 0x135E68u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x135E70u);
        ctx->pc = 0x135E6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135E68u;
            // 0x135e6c: 0x8c840004  lw          $a0, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x135E70u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135E50u: goto label_135e50;
            case 0x135E58u: goto label_135e58;
            case 0x135E70u: goto label_135e70;
            case 0x135E78u: goto label_135e78;
            case 0x135E80u: goto label_135e80;
            case 0x135E84u: goto label_135e84;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x135E70u; }
            if (ctx->pc != 0x135E70u) { return; }
        }
        }
    }
    ctx->pc = 0x135E70u;
label_135e70:
    // 0x135e70: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x135E70u;
    {
        const bool branch_taken_0x135e70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x135E74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135E70u;
            // 0x135e74: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135e70) {
            ctx->pc = 0x135E80u;
            goto label_135e80;
        }
    }
    ctx->pc = 0x135E78u;
label_135e78:
    // 0x135e78: 0xc04d480  jal         func_135200
    ctx->pc = 0x135E78u;
    SET_GPR_U32(ctx, 31, 0x135E80u);
    ctx->pc = 0x135E7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x135E78u;
            // 0x135e7c: 0x2484ba58  addiu       $a0, $a0, -0x45A8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949464));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135E80u; }
        if (ctx->pc != 0x135E80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135E80u; }
        if (ctx->pc != 0x135E80u) { return; }
    }
    ctx->pc = 0x135E80u;
label_135e80:
    // 0x135e80: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x135e80u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_135e84:
    // 0x135e84: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x135e84u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x135e88: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x135e88u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x135e8c: 0x3e00008  jr          $ra
    ctx->pc = 0x135E8Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x135E90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135E8Cu;
            // 0x135e90: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135E50u: goto label_135e50;
            case 0x135E58u: goto label_135e58;
            case 0x135E70u: goto label_135e70;
            case 0x135E78u: goto label_135e78;
            case 0x135E80u: goto label_135e80;
            case 0x135E84u: goto label_135e84;
            default: break;
        }
        return;
    }
    ctx->pc = 0x135E94u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
