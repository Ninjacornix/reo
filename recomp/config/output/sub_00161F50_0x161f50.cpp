#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00161F50
// Address: 0x161f50 - 0x161ff0
void sub_00161F50_0x161f50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00161F50_0x161f50");
#endif

    switch (ctx->pc) {
        case 0x161f70u: goto label_161f70;
        case 0x161f84u: goto label_161f84;
        case 0x161fa8u: goto label_161fa8;
        case 0x161fb8u: goto label_161fb8;
        case 0x161fccu: goto label_161fcc;
        case 0x161fd8u: goto label_161fd8;
        default: break;
    }

    ctx->pc = 0x161f50u;

    // 0x161f50: 0x27bdff50  addiu       $sp, $sp, -0xB0
    ctx->pc = 0x161f50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x161f54: 0xffb10098  sd          $s1, 0x98($sp)
    ctx->pc = 0x161f54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 17));
    // 0x161f58: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x161f58u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161f5c: 0xffb200a0  sd          $s2, 0xA0($sp)
    ctx->pc = 0x161f5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 18));
    // 0x161f60: 0xffb00090  sd          $s0, 0x90($sp)
    ctx->pc = 0x161f60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 16));
    // 0x161f64: 0xffbf00a8  sd          $ra, 0xA8($sp)
    ctx->pc = 0x161f64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 168), GPR_U64(ctx, 31));
    // 0x161f68: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x161F68u;
    SET_GPR_U32(ctx, 31, 0x161F70u);
    ctx->pc = 0x161F6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161F68u;
            // 0x161f6c: 0xa0902d  daddu       $s2, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161F70u; }
        if (ctx->pc != 0x161F70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161F70u; }
        if (ctx->pc != 0x161F70u) { return; }
    }
    ctx->pc = 0x161F70u;
label_161f70:
    // 0x161f70: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x161f70u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x161f74: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x161F74u;
    {
        const bool branch_taken_0x161f74 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x161F78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161F74u;
            // 0x161f78: 0x2484ff08  addiu       $a0, $a0, -0xF8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967048));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161f74) {
            ctx->pc = 0x161F90u;
            goto label_161f90;
        }
    }
    ctx->pc = 0x161F7Cu;
    // 0x161f7c: 0xc058dd4  jal         func_163750
    ctx->pc = 0x161F7Cu;
    SET_GPR_U32(ctx, 31, 0x161F84u);
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161F84u; }
        if (ctx->pc != 0x161F84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161F84u; }
        if (ctx->pc != 0x161F84u) { return; }
    }
    ctx->pc = 0x161F84u;
label_161f84:
    // 0x161f84: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x161F84u;
    {
        const bool branch_taken_0x161f84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x161F88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161F84u;
            // 0x161f88: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161f84) {
            ctx->pc = 0x161FDCu;
            goto label_161fdc;
        }
    }
    ctx->pc = 0x161F8Cu;
    // 0x161f8c: 0x0  nop
    ctx->pc = 0x161f8cu;
    // NOP
label_161f90:
    // 0x161f90: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x161f90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x161f94: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x161F94u;
    {
        const bool branch_taken_0x161f94 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x161f94) {
            ctx->pc = 0x161FB0u;
            goto label_161fb0;
        }
    }
    ctx->pc = 0x161F9Cu;
    // 0x161f9c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x161f9cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x161fa0: 0xc058dd4  jal         func_163750
    ctx->pc = 0x161FA0u;
    SET_GPR_U32(ctx, 31, 0x161FA8u);
    ctx->pc = 0x161FA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161FA0u;
            // 0x161fa4: 0x2484ff38  addiu       $a0, $a0, -0xC8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967096));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161FA8u; }
        if (ctx->pc != 0x161FA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161FA8u; }
        if (ctx->pc != 0x161FA8u) { return; }
    }
    ctx->pc = 0x161FA8u;
label_161fa8:
    // 0x161fa8: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x161FA8u;
    {
        const bool branch_taken_0x161fa8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x161FACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161FA8u;
            // 0x161fac: 0xdfb00090  ld          $s0, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161fa8) {
            ctx->pc = 0x161FDCu;
            goto label_161fdc;
        }
    }
    ctx->pc = 0x161FB0u;
label_161fb0:
    // 0x161fb0: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x161FB0u;
    SET_GPR_U32(ctx, 31, 0x161FB8u);
    ctx->pc = 0x161FB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161FB0u;
            // 0x161fb4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161FB8u; }
        if (ctx->pc != 0x161FB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161FB8u; }
        if (ctx->pc != 0x161FB8u) { return; }
    }
    ctx->pc = 0x161FB8u;
label_161fb8:
    // 0x161fb8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x161fb8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161fbc: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x161fbcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161fc0: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x161fc0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161fc4: 0xc0582ee  jal         func_160BB8
    ctx->pc = 0x161FC4u;
    SET_GPR_U32(ctx, 31, 0x161FCCu);
    ctx->pc = 0x161FC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161FC4u;
            // 0x161fc8: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x160BB8u;
    if (runtime->hasFunction(0x160BB8u)) {
        auto targetFn = runtime->lookupFunction(0x160BB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161FCCu; }
        if (ctx->pc != 0x161FCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160BB8_0x160bb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161FCCu; }
        if (ctx->pc != 0x161FCCu) { return; }
    }
    ctx->pc = 0x161FCCu;
label_161fcc:
    // 0x161fcc: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x161fccu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161fd0: 0xc05f250  jal         func_17C940
    ctx->pc = 0x161FD0u;
    SET_GPR_U32(ctx, 31, 0x161FD8u);
    ctx->pc = 0x161FD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161FD0u;
            // 0x161fd4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C940u;
    if (runtime->hasFunction(0x17C940u)) {
        auto targetFn = runtime->lookupFunction(0x17C940u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161FD8u; }
        if (ctx->pc != 0x161FD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017C940_0x17c940(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161FD8u; }
        if (ctx->pc != 0x161FD8u) { return; }
    }
    ctx->pc = 0x161FD8u;
label_161fd8:
    // 0x161fd8: 0xdfb00090  ld          $s0, 0x90($sp)
    ctx->pc = 0x161fd8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 144)));
label_161fdc:
    // 0x161fdc: 0xdfb10098  ld          $s1, 0x98($sp)
    ctx->pc = 0x161fdcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 152)));
    // 0x161fe0: 0xdfb200a0  ld          $s2, 0xA0($sp)
    ctx->pc = 0x161fe0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x161fe4: 0xdfbf00a8  ld          $ra, 0xA8($sp)
    ctx->pc = 0x161fe4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x161fe8: 0x3e00008  jr          $ra
    ctx->pc = 0x161FE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x161FECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161FE8u;
            // 0x161fec: 0x27bd00b0  addiu       $sp, $sp, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x161F70u: goto label_161f70;
            case 0x161F84u: goto label_161f84;
            case 0x161F90u: goto label_161f90;
            case 0x161FA8u: goto label_161fa8;
            case 0x161FB0u: goto label_161fb0;
            case 0x161FB8u: goto label_161fb8;
            case 0x161FCCu: goto label_161fcc;
            case 0x161FD8u: goto label_161fd8;
            case 0x161FDCu: goto label_161fdc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x161FF0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
