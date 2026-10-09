#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00135DC8
// Address: 0x135dc8 - 0x135ef0
void sub_00135DC8_0x135dc8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00135DC8_0x135dc8");
#endif

    switch (ctx->pc) {
        case 0x135de4u: goto label_135de4;
        case 0x135e08u: goto label_135e08;
        case 0x135e1cu: goto label_135e1c;
        case 0x135e50u: goto label_135e50;
        case 0x135e70u: goto label_135e70;
        case 0x135e80u: goto label_135e80;
        case 0x135ed0u: goto label_135ed0;
        default: break;
    }

    ctx->pc = 0x135dc8u;

    // 0x135dc8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x135dc8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x135dcc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x135dccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x135dd0: 0x14800007  bnez        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x135DD0u;
    {
        const bool branch_taken_0x135dd0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x135DD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135DD0u;
            // 0x135dd4: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135dd0) {
            ctx->pc = 0x135DF0u;
            goto label_135df0;
        }
    }
    ctx->pc = 0x135DD8u;
    // 0x135dd8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x135dd8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x135ddc: 0xc04d480  jal         func_135200
    ctx->pc = 0x135DDCu;
    SET_GPR_U32(ctx, 31, 0x135DE4u);
    ctx->pc = 0x135DE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x135DDCu;
            // 0x135de0: 0x2484ba00  addiu       $a0, $a0, -0x4600 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949376));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135DE4u; }
        if (ctx->pc != 0x135DE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135DE4u; }
        if (ctx->pc != 0x135DE4u) { return; }
    }
    ctx->pc = 0x135DE4u;
label_135de4:
    // 0x135de4: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x135DE4u;
    {
        const bool branch_taken_0x135de4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x135DE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135DE4u;
            // 0x135de8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135de4) {
            ctx->pc = 0x135E20u;
            goto label_135e20;
        }
    }
    ctx->pc = 0x135DECu;
    // 0x135dec: 0x0  nop
    ctx->pc = 0x135decu;
    // NOP
label_135df0:
    // 0x135df0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x135df0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x135df4: 0x8c420020  lw          $v0, 0x20($v0)
    ctx->pc = 0x135df4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 32)));
    // 0x135df8: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x135DF8u;
    {
        const bool branch_taken_0x135df8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x135df8) {
            ctx->pc = 0x135DFCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x135DF8u;
            // 0x135dfc: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x135E10u;
            goto label_135e10;
        }
    }
    ctx->pc = 0x135E00u;
    // 0x135e00: 0x40f809  jalr        $v0
    ctx->pc = 0x135E00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x135E08u);
        ctx->pc = 0x135E04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135E00u;
            // 0x135e04: 0x8c840004  lw          $a0, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x135E08u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135DE4u: goto label_135de4;
            case 0x135DF0u: goto label_135df0;
            case 0x135E08u: goto label_135e08;
            case 0x135E10u: goto label_135e10;
            case 0x135E1Cu: goto label_135e1c;
            case 0x135E20u: goto label_135e20;
            case 0x135E50u: goto label_135e50;
            case 0x135E58u: goto label_135e58;
            case 0x135E70u: goto label_135e70;
            case 0x135E78u: goto label_135e78;
            case 0x135E80u: goto label_135e80;
            case 0x135E84u: goto label_135e84;
            case 0x135EB8u: goto label_135eb8;
            case 0x135ED0u: goto label_135ed0;
            case 0x135EE0u: goto label_135ee0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x135E08u; }
            if (ctx->pc != 0x135E08u) { return; }
        }
        }
    }
    ctx->pc = 0x135E08u;
label_135e08:
    // 0x135e08: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x135E08u;
    {
        const bool branch_taken_0x135e08 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x135E0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135E08u;
            // 0x135e0c: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135e08) {
            ctx->pc = 0x135E1Cu;
            goto label_135e1c;
        }
    }
    ctx->pc = 0x135E10u;
label_135e10:
    // 0x135e10: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x135e10u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x135e14: 0xc04d480  jal         func_135200
    ctx->pc = 0x135E14u;
    SET_GPR_U32(ctx, 31, 0x135E1Cu);
    ctx->pc = 0x135E18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x135E14u;
            // 0x135e18: 0x2484ba20  addiu       $a0, $a0, -0x45E0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949408));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135E1Cu; }
        if (ctx->pc != 0x135E1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135E1Cu; }
        if (ctx->pc != 0x135E1Cu) { return; }
    }
    ctx->pc = 0x135E1Cu;
label_135e1c:
    // 0x135e1c: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x135e1cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_135e20:
    // 0x135e20: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x135e20u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x135e24: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x135e24u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x135e28: 0x3e00008  jr          $ra
    ctx->pc = 0x135E28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x135E2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135E28u;
            // 0x135e2c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135DE4u: goto label_135de4;
            case 0x135DF0u: goto label_135df0;
            case 0x135E08u: goto label_135e08;
            case 0x135E10u: goto label_135e10;
            case 0x135E1Cu: goto label_135e1c;
            case 0x135E20u: goto label_135e20;
            case 0x135E50u: goto label_135e50;
            case 0x135E58u: goto label_135e58;
            case 0x135E70u: goto label_135e70;
            case 0x135E78u: goto label_135e78;
            case 0x135E80u: goto label_135e80;
            case 0x135E84u: goto label_135e84;
            case 0x135EB8u: goto label_135eb8;
            case 0x135ED0u: goto label_135ed0;
            case 0x135EE0u: goto label_135ee0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x135E30u;
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
            case 0x135DE4u: goto label_135de4;
            case 0x135DF0u: goto label_135df0;
            case 0x135E08u: goto label_135e08;
            case 0x135E10u: goto label_135e10;
            case 0x135E1Cu: goto label_135e1c;
            case 0x135E20u: goto label_135e20;
            case 0x135E50u: goto label_135e50;
            case 0x135E58u: goto label_135e58;
            case 0x135E70u: goto label_135e70;
            case 0x135E78u: goto label_135e78;
            case 0x135E80u: goto label_135e80;
            case 0x135E84u: goto label_135e84;
            case 0x135EB8u: goto label_135eb8;
            case 0x135ED0u: goto label_135ed0;
            case 0x135EE0u: goto label_135ee0;
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
            case 0x135DE4u: goto label_135de4;
            case 0x135DF0u: goto label_135df0;
            case 0x135E08u: goto label_135e08;
            case 0x135E10u: goto label_135e10;
            case 0x135E1Cu: goto label_135e1c;
            case 0x135E20u: goto label_135e20;
            case 0x135E50u: goto label_135e50;
            case 0x135E58u: goto label_135e58;
            case 0x135E70u: goto label_135e70;
            case 0x135E78u: goto label_135e78;
            case 0x135E80u: goto label_135e80;
            case 0x135E84u: goto label_135e84;
            case 0x135EB8u: goto label_135eb8;
            case 0x135ED0u: goto label_135ed0;
            case 0x135EE0u: goto label_135ee0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x135E94u;
    // 0x135e94: 0x0  nop
    ctx->pc = 0x135e94u;
    // NOP
    // 0x135e98: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x135e98u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x135e9c: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x135E9Cu;
    {
        const bool branch_taken_0x135e9c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x135EA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135E9Cu;
            // 0x135ea0: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135e9c) {
            ctx->pc = 0x135EB8u;
            goto label_135eb8;
        }
    }
    ctx->pc = 0x135EA4u;
    // 0x135ea4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x135ea4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x135ea8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x135ea8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x135eac: 0x2484ba70  addiu       $a0, $a0, -0x4590
    ctx->pc = 0x135eacu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949488));
    // 0x135eb0: 0x804d480  j           func_135200
    ctx->pc = 0x135EB0u;
    ctx->pc = 0x135EB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x135EB0u;
            // 0x135eb4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00135200_0x135200(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x135EB8u;
label_135eb8:
    // 0x135eb8: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x135eb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x135ebc: 0x8c420028  lw          $v0, 0x28($v0)
    ctx->pc = 0x135ebcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 40)));
    // 0x135ec0: 0x50400007  beql        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x135EC0u;
    {
        const bool branch_taken_0x135ec0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x135ec0) {
            ctx->pc = 0x135EC4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x135EC0u;
            // 0x135ec4: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x135EE0u;
            goto label_135ee0;
        }
    }
    ctx->pc = 0x135EC8u;
    // 0x135ec8: 0x40f809  jalr        $v0
    ctx->pc = 0x135EC8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x135ED0u);
        ctx->pc = 0x135ECCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135EC8u;
            // 0x135ecc: 0x8c840004  lw          $a0, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x135ED0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135DE4u: goto label_135de4;
            case 0x135DF0u: goto label_135df0;
            case 0x135E08u: goto label_135e08;
            case 0x135E10u: goto label_135e10;
            case 0x135E1Cu: goto label_135e1c;
            case 0x135E20u: goto label_135e20;
            case 0x135E50u: goto label_135e50;
            case 0x135E58u: goto label_135e58;
            case 0x135E70u: goto label_135e70;
            case 0x135E78u: goto label_135e78;
            case 0x135E80u: goto label_135e80;
            case 0x135E84u: goto label_135e84;
            case 0x135EB8u: goto label_135eb8;
            case 0x135ED0u: goto label_135ed0;
            case 0x135EE0u: goto label_135ee0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x135ED0u; }
            if (ctx->pc != 0x135ED0u) { return; }
        }
        }
    }
    ctx->pc = 0x135ED0u;
label_135ed0:
    // 0x135ed0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x135ed0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x135ed4: 0x3e00008  jr          $ra
    ctx->pc = 0x135ED4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x135ED8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135ED4u;
            // 0x135ed8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135DE4u: goto label_135de4;
            case 0x135DF0u: goto label_135df0;
            case 0x135E08u: goto label_135e08;
            case 0x135E10u: goto label_135e10;
            case 0x135E1Cu: goto label_135e1c;
            case 0x135E20u: goto label_135e20;
            case 0x135E50u: goto label_135e50;
            case 0x135E58u: goto label_135e58;
            case 0x135E70u: goto label_135e70;
            case 0x135E78u: goto label_135e78;
            case 0x135E80u: goto label_135e80;
            case 0x135E84u: goto label_135e84;
            case 0x135EB8u: goto label_135eb8;
            case 0x135ED0u: goto label_135ed0;
            case 0x135EE0u: goto label_135ee0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x135EDCu;
    // 0x135edc: 0x0  nop
    ctx->pc = 0x135edcu;
    // NOP
label_135ee0:
    // 0x135ee0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x135ee0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x135ee4: 0x2484ba90  addiu       $a0, $a0, -0x4570
    ctx->pc = 0x135ee4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949520));
    // 0x135ee8: 0x804d480  j           func_135200
    ctx->pc = 0x135EE8u;
    ctx->pc = 0x135EECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x135EE8u;
            // 0x135eec: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00135200_0x135200(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x135EF0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
