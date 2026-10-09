#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00105D40
// Address: 0x105d40 - 0x1061f0
void sub_00105D40_0x105d40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00105D40_0x105d40");
#endif

    switch (ctx->pc) {
        case 0x105da4u: goto label_105da4;
        case 0x105dc4u: goto label_105dc4;
        case 0x105e10u: goto label_105e10;
        case 0x105e34u: goto label_105e34;
        case 0x105ee0u: goto label_105ee0;
        case 0x105f1cu: goto label_105f1c;
        case 0x105f70u: goto label_105f70;
        case 0x105fa4u: goto label_105fa4;
        case 0x106094u: goto label_106094;
        case 0x1060c8u: goto label_1060c8;
        case 0x1060f4u: goto label_1060f4;
        case 0x10611cu: goto label_10611c;
        case 0x106158u: goto label_106158;
        case 0x106170u: goto label_106170;
        case 0x1061a0u: goto label_1061a0;
        default: break;
    }

    ctx->pc = 0x105d40u;

    // 0x105d40: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x105d40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x105d44: 0xffb00070  sd          $s0, 0x70($sp)
    ctx->pc = 0x105d44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 16));
    // 0x105d48: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x105d48u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105d4c: 0xffb40090  sd          $s4, 0x90($sp)
    ctx->pc = 0x105d4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 20));
    // 0x105d50: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x105d50u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105d54: 0xffb600a0  sd          $s6, 0xA0($sp)
    ctx->pc = 0x105d54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 22));
    // 0x105d58: 0xffb10078  sd          $s1, 0x78($sp)
    ctx->pc = 0x105d58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 120), GPR_U64(ctx, 17));
    // 0x105d5c: 0xffb20080  sd          $s2, 0x80($sp)
    ctx->pc = 0x105d5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 18));
    // 0x105d60: 0xffb30088  sd          $s3, 0x88($sp)
    ctx->pc = 0x105d60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 136), GPR_U64(ctx, 19));
    // 0x105d64: 0xffb50098  sd          $s5, 0x98($sp)
    ctx->pc = 0x105d64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 21));
    // 0x105d68: 0xffb700a8  sd          $s7, 0xA8($sp)
    ctx->pc = 0x105d68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 168), GPR_U64(ctx, 23));
    // 0x105d6c: 0xffbf00b0  sd          $ra, 0xB0($sp)
    ctx->pc = 0x105d6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 31));
    // 0x105d70: 0x8e110054  lw          $s1, 0x54($s0)
    ctx->pc = 0x105d70u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
    // 0x105d74: 0x16200006  bnez        $s1, . + 4 + (0x6 << 2)
    ctx->pc = 0x105D74u;
    {
        const bool branch_taken_0x105d74 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x105D78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105D74u;
            // 0x105d78: 0xa0b02d  daddu       $s6, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105d74) {
            ctx->pc = 0x105D90u;
            goto label_105d90;
        }
    }
    ctx->pc = 0x105D7Cu;
    // 0x105d7c: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x105d7cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x105d80: 0x8c4397f0  lw          $v1, -0x6810($v0)
    ctx->pc = 0x105d80u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294940656)));
    // 0x105d84: 0xae030054  sw          $v1, 0x54($s0)
    ctx->pc = 0x105d84u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 84), GPR_U32(ctx, 3));
    // 0x105d88: 0x60882d  daddu       $s1, $v1, $zero
    ctx->pc = 0x105d88u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105d8c: 0x0  nop
    ctx->pc = 0x105d8cu;
    // NOP
label_105d90:
    // 0x105d90: 0x8e220038  lw          $v0, 0x38($s1)
    ctx->pc = 0x105d90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 56)));
    // 0x105d94: 0x54400005  bnel        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x105D94u;
    {
        const bool branch_taken_0x105d94 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x105d94) {
            ctx->pc = 0x105D98u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x105D94u;
            // 0x105d98: 0x8e02000c  lw          $v0, 0xC($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x105DACu;
            goto label_105dac;
        }
    }
    ctx->pc = 0x105D9Cu;
    // 0x105d9c: 0xc041544  jal         func_105510
    ctx->pc = 0x105D9Cu;
    SET_GPR_U32(ctx, 31, 0x105DA4u);
    ctx->pc = 0x105DA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x105D9Cu;
            // 0x105da0: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x105510u;
    if (runtime->hasFunction(0x105510u)) {
        auto targetFn = runtime->lookupFunction(0x105510u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105DA4u; }
        if (ctx->pc != 0x105DA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00105510_0x105510(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105DA4u; }
        if (ctx->pc != 0x105DA4u) { return; }
    }
    ctx->pc = 0x105DA4u;
label_105da4:
    // 0x105da4: 0x8e110054  lw          $s1, 0x54($s0)
    ctx->pc = 0x105da4u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
    // 0x105da8: 0x8e02000c  lw          $v0, 0xC($s0)
    ctx->pc = 0x105da8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
label_105dac:
    // 0x105dac: 0x24030108  addiu       $v1, $zero, 0x108
    ctx->pc = 0x105dacu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 264));
    // 0x105db0: 0x30420108  andi        $v0, $v0, 0x108
    ctx->pc = 0x105db0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)264);
    // 0x105db4: 0x54430004  bnel        $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x105DB4u;
    {
        const bool branch_taken_0x105db4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x105db4) {
            ctx->pc = 0x105DB8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x105DB4u;
            // 0x105db8: 0x8e150028  lw          $s5, 0x28($s0) (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x105DC8u;
            goto label_105dc8;
        }
    }
    ctx->pc = 0x105DBCu;
    // 0x105dbc: 0xc04142c  jal         func_1050B0
    ctx->pc = 0x105DBCu;
    SET_GPR_U32(ctx, 31, 0x105DC4u);
    ctx->pc = 0x105DC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x105DBCu;
            // 0x105dc0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1050B0u;
    if (runtime->hasFunction(0x1050B0u)) {
        auto targetFn = runtime->lookupFunction(0x1050B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105DC4u; }
        if (ctx->pc != 0x105DC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001050B0_0x1050b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105DC4u; }
        if (ctx->pc != 0x105DC4u) { return; }
    }
    ctx->pc = 0x105DC4u;
label_105dc4:
    // 0x105dc4: 0x8e150028  lw          $s5, 0x28($s0)
    ctx->pc = 0x105dc4u;
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
label_105dc8:
    // 0x105dc8: 0x56a00003  bnel        $s5, $zero, . + 4 + (0x3 << 2)
    ctx->pc = 0x105DC8u;
    {
        const bool branch_taken_0x105dc8 = (GPR_U64(ctx, 21) != GPR_U64(ctx, 0));
        if (branch_taken_0x105dc8) {
            ctx->pc = 0x105DCCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x105DC8u;
            // 0x105dcc: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x105DD8u;
            goto label_105dd8;
        }
    }
    ctx->pc = 0x105DD0u;
    // 0x105dd0: 0x1000003b  b           . + 4 + (0x3B << 2)
    ctx->pc = 0x105DD0u;
    {
        const bool branch_taken_0x105dd0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x105DD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105DD0u;
            // 0x105dd4: 0x2403001d  addiu       $v1, $zero, 0x1D (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 29));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105dd0) {
            ctx->pc = 0x105EC0u;
            goto label_105ec0;
        }
    }
    ctx->pc = 0x105DD8u;
label_105dd8:
    // 0x105dd8: 0x1282000b  beq         $s4, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x105DD8u;
    {
        const bool branch_taken_0x105dd8 = (GPR_U64(ctx, 20) == GPR_U64(ctx, 2));
        ctx->pc = 0x105DDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105DD8u;
            // 0x105ddc: 0x2a820002  slti        $v0, $s4, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 20) < (int64_t)(int32_t)2) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x105dd8) {
            ctx->pc = 0x105E08u;
            goto label_105e08;
        }
    }
    ctx->pc = 0x105DE0u;
    // 0x105de0: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x105DE0u;
    {
        const bool branch_taken_0x105de0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x105DE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105DE0u;
            // 0x105de4: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105de0) {
            ctx->pc = 0x105DF8u;
            goto label_105df8;
        }
    }
    ctx->pc = 0x105DE8u;
    // 0x105de8: 0x12800031  beqz        $s4, . + 4 + (0x31 << 2)
    ctx->pc = 0x105DE8u;
    {
        const bool branch_taken_0x105de8 = (GPR_U64(ctx, 20) == GPR_U64(ctx, 0));
        ctx->pc = 0x105DECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105DE8u;
            // 0x105dec: 0x24030016  addiu       $v1, $zero, 0x16 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 22));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105de8) {
            ctx->pc = 0x105EB0u;
            goto label_105eb0;
        }
    }
    ctx->pc = 0x105DF0u;
    // 0x105df0: 0x10000034  b           . + 4 + (0x34 << 2)
    ctx->pc = 0x105DF0u;
    {
        const bool branch_taken_0x105df0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x105DF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105DF0u;
            // 0x105df4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105df0) {
            ctx->pc = 0x105EC4u;
            goto label_105ec4;
        }
    }
    ctx->pc = 0x105DF8u;
label_105df8:
    // 0x105df8: 0x1282002d  beq         $s4, $v0, . + 4 + (0x2D << 2)
    ctx->pc = 0x105DF8u;
    {
        const bool branch_taken_0x105df8 = (GPR_U64(ctx, 20) == GPR_U64(ctx, 2));
        ctx->pc = 0x105DFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105DF8u;
            // 0x105dfc: 0x24030016  addiu       $v1, $zero, 0x16 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 22));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105df8) {
            ctx->pc = 0x105EB0u;
            goto label_105eb0;
        }
    }
    ctx->pc = 0x105E00u;
    // 0x105e00: 0x10000030  b           . + 4 + (0x30 << 2)
    ctx->pc = 0x105E00u;
    {
        const bool branch_taken_0x105e00 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x105E04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105E00u;
            // 0x105e04: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105e00) {
            ctx->pc = 0x105EC4u;
            goto label_105ec4;
        }
    }
    ctx->pc = 0x105E08u;
label_105e08:
    // 0x105e08: 0xc04142c  jal         func_1050B0
    ctx->pc = 0x105E08u;
    SET_GPR_U32(ctx, 31, 0x105E10u);
    ctx->pc = 0x105E0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x105E08u;
            // 0x105e0c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1050B0u;
    if (runtime->hasFunction(0x1050B0u)) {
        auto targetFn = runtime->lookupFunction(0x1050B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105E10u; }
        if (ctx->pc != 0x105E10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001050B0_0x1050b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105E10u; }
        if (ctx->pc != 0x105E10u) { return; }
    }
    ctx->pc = 0x105E10u;
label_105e10:
    // 0x105e10: 0x9606000c  lhu         $a2, 0xC($s0)
    ctx->pc = 0x105e10u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x105e14: 0x30c21000  andi        $v0, $a2, 0x1000
    ctx->pc = 0x105e14u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)4096);
    // 0x105e18: 0x50400003  beql        $v0, $zero, . + 4 + (0x3 << 2)
    ctx->pc = 0x105E18u;
    {
        const bool branch_taken_0x105e18 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x105e18) {
            ctx->pc = 0x105E1Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x105E18u;
            // 0x105e1c: 0x8e04001c  lw          $a0, 0x1C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x105E28u;
            goto label_105e28;
        }
    }
    ctx->pc = 0x105E20u;
    // 0x105e20: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x105E20u;
    {
        const bool branch_taken_0x105e20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x105E24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105E20u;
            // 0x105e24: 0x8e120050  lw          $s2, 0x50($s0) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 80)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105e20) {
            ctx->pc = 0x105E48u;
            goto label_105e48;
        }
    }
    ctx->pc = 0x105E28u;
label_105e28:
    // 0x105e28: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x105e28u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105e2c: 0x2a0f809  jalr        $s5
    ctx->pc = 0x105E2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 21);
        SET_GPR_U32(ctx, 31, 0x105E34u);
        ctx->pc = 0x105E30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105E2Cu;
            // 0x105e30: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x105E34u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x105D90u: goto label_105d90;
            case 0x105DA4u: goto label_105da4;
            case 0x105DACu: goto label_105dac;
            case 0x105DC4u: goto label_105dc4;
            case 0x105DC8u: goto label_105dc8;
            case 0x105DD8u: goto label_105dd8;
            case 0x105DF8u: goto label_105df8;
            case 0x105E08u: goto label_105e08;
            case 0x105E10u: goto label_105e10;
            case 0x105E28u: goto label_105e28;
            case 0x105E34u: goto label_105e34;
            case 0x105E48u: goto label_105e48;
            case 0x105E78u: goto label_105e78;
            case 0x105E98u: goto label_105e98;
            case 0x105E9Cu: goto label_105e9c;
            case 0x105EB0u: goto label_105eb0;
            case 0x105EC0u: goto label_105ec0;
            case 0x105EC4u: goto label_105ec4;
            case 0x105ED0u: goto label_105ed0;
            case 0x105EE0u: goto label_105ee0;
            case 0x105EE4u: goto label_105ee4;
            case 0x105F1Cu: goto label_105f1c;
            case 0x105F3Cu: goto label_105f3c;
            case 0x105F40u: goto label_105f40;
            case 0x105F48u: goto label_105f48;
            case 0x105F58u: goto label_105f58;
            case 0x105F70u: goto label_105f70;
            case 0x105F7Cu: goto label_105f7c;
            case 0x105F98u: goto label_105f98;
            case 0x105FA4u: goto label_105fa4;
            case 0x105FB8u: goto label_105fb8;
            case 0x105FD8u: goto label_105fd8;
            case 0x105FDCu: goto label_105fdc;
            case 0x106010u: goto label_106010;
            case 0x106014u: goto label_106014;
            case 0x106030u: goto label_106030;
            case 0x106094u: goto label_106094;
            case 0x10609Cu: goto label_10609c;
            case 0x1060B0u: goto label_1060b0;
            case 0x1060C8u: goto label_1060c8;
            case 0x1060F4u: goto label_1060f4;
            case 0x1060F8u: goto label_1060f8;
            case 0x10611Cu: goto label_10611c;
            case 0x106144u: goto label_106144;
            case 0x106150u: goto label_106150;
            case 0x106158u: goto label_106158;
            case 0x106170u: goto label_106170;
            case 0x106188u: goto label_106188;
            case 0x1061A0u: goto label_1061a0;
            case 0x1061A4u: goto label_1061a4;
            case 0x1061C0u: goto label_1061c0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x105E34u; }
            if (ctx->pc != 0x105E34u) { return; }
        }
        }
    }
    ctx->pc = 0x105E34u;
label_105e34:
    // 0x105e34: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x105e34u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x105e38: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x105e38u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105e3c: 0x124300e0  beq         $s2, $v1, . + 4 + (0xE0 << 2)
    ctx->pc = 0x105E3Cu;
    {
        const bool branch_taken_0x105e3c = (GPR_U64(ctx, 18) == GPR_U64(ctx, 3));
        ctx->pc = 0x105E40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105E3Cu;
            // 0x105e40: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105e3c) {
            ctx->pc = 0x1061C0u;
            goto label_1061c0;
        }
    }
    ctx->pc = 0x105E44u;
    // 0x105e44: 0x9606000c  lhu         $a2, 0xC($s0)
    ctx->pc = 0x105e44u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
label_105e48:
    // 0x105e48: 0x30c20004  andi        $v0, $a2, 0x4
    ctx->pc = 0x105e48u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)4);
    // 0x105e4c: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x105E4Cu;
    {
        const bool branch_taken_0x105e4c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x105E50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105E4Cu;
            // 0x105e50: 0x30c20008  andi        $v0, $a2, 0x8 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)8);
        ctx->in_delay_slot = false;
        if (branch_taken_0x105e4c) {
            ctx->pc = 0x105E78u;
            goto label_105e78;
        }
    }
    ctx->pc = 0x105E54u;
    // 0x105e54: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x105e54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x105e58: 0x8e050030  lw          $a1, 0x30($s0)
    ctx->pc = 0x105e58u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x105e5c: 0x10a0000e  beqz        $a1, . + 4 + (0xE << 2)
    ctx->pc = 0x105E5Cu;
    {
        const bool branch_taken_0x105e5c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x105E60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105E5Cu;
            // 0x105e60: 0x242902f  dsubu       $s2, $s2, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) - GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105e5c) {
            ctx->pc = 0x105E98u;
            goto label_105e98;
        }
    }
    ctx->pc = 0x105E64u;
    // 0x105e64: 0x8e02003c  lw          $v0, 0x3C($s0)
    ctx->pc = 0x105e64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
    // 0x105e68: 0x8e070010  lw          $a3, 0x10($s0)
    ctx->pc = 0x105e68u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x105e6c: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x105E6Cu;
    {
        const bool branch_taken_0x105e6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x105E70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105E6Cu;
            // 0x105e70: 0x242902f  dsubu       $s2, $s2, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) - GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105e6c) {
            ctx->pc = 0x105E9Cu;
            goto label_105e9c;
        }
    }
    ctx->pc = 0x105E74u;
    // 0x105e74: 0x0  nop
    ctx->pc = 0x105e74u;
    // NOP
label_105e78:
    // 0x105e78: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x105E78u;
    {
        const bool branch_taken_0x105e78 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x105E7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105E78u;
            // 0x105e7c: 0x8e070010  lw          $a3, 0x10($s0) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105e78) {
            ctx->pc = 0x105E9Cu;
            goto label_105e9c;
        }
    }
    ctx->pc = 0x105E80u;
    // 0x105e80: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x105e80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x105e84: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x105E84u;
    {
        const bool branch_taken_0x105e84 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x105e84) {
            ctx->pc = 0x105E9Cu;
            goto label_105e9c;
        }
    }
    ctx->pc = 0x105E8Cu;
    // 0x105e8c: 0x471023  subu        $v0, $v0, $a3
    ctx->pc = 0x105e8cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x105e90: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x105E90u;
    {
        const bool branch_taken_0x105e90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x105E94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105E90u;
            // 0x105e94: 0x242902d  daddu       $s2, $s2, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105e90) {
            ctx->pc = 0x105E9Cu;
            goto label_105e9c;
        }
    }
    ctx->pc = 0x105E98u;
label_105e98:
    // 0x105e98: 0x8e070010  lw          $a3, 0x10($s0)
    ctx->pc = 0x105e98u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
label_105e9c:
    // 0x105e9c: 0x2d2b02d  daddu       $s6, $s6, $s2
    ctx->pc = 0x105e9cu;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 18));
    // 0x105ea0: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x105ea0u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105ea4: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x105EA4u;
    {
        const bool branch_taken_0x105ea4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x105EA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105EA4u;
            // 0x105ea8: 0x24170001  addiu       $s7, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105ea4) {
            ctx->pc = 0x105ED0u;
            goto label_105ed0;
        }
    }
    ctx->pc = 0x105EACu;
    // 0x105eac: 0x0  nop
    ctx->pc = 0x105eacu;
    // NOP
label_105eb0:
    // 0x105eb0: 0xb82d  daddu       $s7, $zero, $zero
    ctx->pc = 0x105eb0u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105eb4: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x105EB4u;
    {
        const bool branch_taken_0x105eb4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x105EB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105EB4u;
            // 0x105eb8: 0x8e070010  lw          $a3, 0x10($s0) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105eb4) {
            ctx->pc = 0x105ED0u;
            goto label_105ed0;
        }
    }
    ctx->pc = 0x105EBCu;
    // 0x105ebc: 0x0  nop
    ctx->pc = 0x105ebcu;
    // NOP
label_105ec0:
    // 0x105ec0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x105ec0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_105ec4:
    // 0x105ec4: 0x100000be  b           . + 4 + (0xBE << 2)
    ctx->pc = 0x105EC4u;
    {
        const bool branch_taken_0x105ec4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x105EC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105EC4u;
            // 0x105ec8: 0xae230000  sw          $v1, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105ec4) {
            ctx->pc = 0x1061C0u;
            goto label_1061c0;
        }
    }
    ctx->pc = 0x105ECCu;
    // 0x105ecc: 0x0  nop
    ctx->pc = 0x105eccu;
    // NOP
label_105ed0:
    // 0x105ed0: 0x54e00004  bnel        $a3, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x105ED0u;
    {
        const bool branch_taken_0x105ed0 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        if (branch_taken_0x105ed0) {
            ctx->pc = 0x105ED4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x105ED0u;
            // 0x105ed4: 0x9606000c  lhu         $a2, 0xC($s0) (Delay Slot)
        SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x105EE4u;
            goto label_105ee4;
        }
    }
    ctx->pc = 0x105ED8u;
    // 0x105ed8: 0xc041ad6  jal         func_106B58
    ctx->pc = 0x105ED8u;
    SET_GPR_U32(ctx, 31, 0x105EE0u);
    ctx->pc = 0x105EDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x105ED8u;
            // 0x105edc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x106B58u;
    if (runtime->hasFunction(0x106B58u)) {
        auto targetFn = runtime->lookupFunction(0x106B58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105EE0u; }
        if (ctx->pc != 0x105EE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00106B58_0x106b58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105EE0u; }
        if (ctx->pc != 0x105EE0u) { return; }
    }
    ctx->pc = 0x105EE0u;
label_105ee0:
    // 0x105ee0: 0x9606000c  lhu         $a2, 0xC($s0)
    ctx->pc = 0x105ee0u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
label_105ee4:
    // 0x105ee4: 0x30c2081a  andi        $v0, $a2, 0x81A
    ctx->pc = 0x105ee4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)2074);
    // 0x105ee8: 0x14400099  bnez        $v0, . + 4 + (0x99 << 2)
    ctx->pc = 0x105EE8u;
    {
        const bool branch_taken_0x105ee8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x105EECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105EE8u;
            // 0x105eec: 0x30c20400  andi        $v0, $a2, 0x400 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)1024);
        ctx->in_delay_slot = false;
        if (branch_taken_0x105ee8) {
            ctx->pc = 0x106150u;
            goto label_106150;
        }
    }
    ctx->pc = 0x105EF0u;
    // 0x105ef0: 0x14400019  bnez        $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x105EF0u;
    {
        const bool branch_taken_0x105ef0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x105EF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105EF0u;
            // 0x105ef4: 0x3c020011  lui         $v0, 0x11 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105ef0) {
            ctx->pc = 0x105F58u;
            goto label_105f58;
        }
    }
    ctx->pc = 0x105EF8u;
    // 0x105ef8: 0x2442aa58  addiu       $v0, $v0, -0x55A8
    ctx->pc = 0x105ef8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294945368));
    // 0x105efc: 0x56a20010  bnel        $s5, $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x105EFCu;
    {
        const bool branch_taken_0x105efc = (GPR_U64(ctx, 21) != GPR_U64(ctx, 2));
        if (branch_taken_0x105efc) {
            ctx->pc = 0x105F00u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x105EFCu;
            // 0x105f00: 0x34c20800  ori         $v0, $a2, 0x800 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)2048);
        ctx->in_delay_slot = false;
            ctx->pc = 0x105F40u;
            goto label_105f40;
        }
    }
    ctx->pc = 0x105F04u;
    // 0x105f04: 0x8605000e  lh          $a1, 0xE($s0)
    ctx->pc = 0x105f04u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 14)));
    // 0x105f08: 0x4a2000d  bltzl       $a1, . + 4 + (0xD << 2)
    ctx->pc = 0x105F08u;
    {
        const bool branch_taken_0x105f08 = (GPR_S64(ctx, 5) < 0);
        if (branch_taken_0x105f08) {
            ctx->pc = 0x105F0Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x105F08u;
            // 0x105f0c: 0x34c20800  ori         $v0, $a2, 0x800 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)2048);
        ctx->in_delay_slot = false;
            ctx->pc = 0x105F40u;
            goto label_105f40;
        }
    }
    ctx->pc = 0x105F10u;
    // 0x105f10: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x105f10u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105f14: 0xc04187c  jal         func_1061F0
    ctx->pc = 0x105F14u;
    SET_GPR_U32(ctx, 31, 0x105F1Cu);
    ctx->pc = 0x105F18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x105F14u;
            // 0x105f18: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1061F0u;
    if (runtime->hasFunction(0x1061F0u)) {
        auto targetFn = runtime->lookupFunction(0x1061F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105F1Cu; }
        if (ctx->pc != 0x105F1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001061F0_0x1061f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105F1Cu; }
        if (ctx->pc != 0x105F1Cu) { return; }
    }
    ctx->pc = 0x105F1Cu;
label_105f1c:
    // 0x105f1c: 0x54400007  bnel        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x105F1Cu;
    {
        const bool branch_taken_0x105f1c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x105f1c) {
            ctx->pc = 0x105F20u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x105F1Cu;
            // 0x105f20: 0x9606000c  lhu         $a2, 0xC($s0) (Delay Slot)
        SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x105F3Cu;
            goto label_105f3c;
        }
    }
    ctx->pc = 0x105F24u;
    // 0x105f24: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x105f24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x105f28: 0x34038000  ori         $v1, $zero, 0x8000
    ctx->pc = 0x105f28u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x105f2c: 0x3042f000  andi        $v0, $v0, 0xF000
    ctx->pc = 0x105f2cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)61440);
    // 0x105f30: 0x50430005  beql        $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x105F30u;
    {
        const bool branch_taken_0x105f30 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x105f30) {
            ctx->pc = 0x105F34u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x105F30u;
            // 0x105f34: 0x9602000c  lhu         $v0, 0xC($s0) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x105F48u;
            goto label_105f48;
        }
    }
    ctx->pc = 0x105F38u;
    // 0x105f38: 0x9606000c  lhu         $a2, 0xC($s0)
    ctx->pc = 0x105f38u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
label_105f3c:
    // 0x105f3c: 0x34c20800  ori         $v0, $a2, 0x800
    ctx->pc = 0x105f3cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)2048);
label_105f40:
    // 0x105f40: 0x10000083  b           . + 4 + (0x83 << 2)
    ctx->pc = 0x105F40u;
    {
        const bool branch_taken_0x105f40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x105F44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105F40u;
            // 0x105f44: 0xa602000c  sh          $v0, 0xC($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105f40) {
            ctx->pc = 0x106150u;
            goto label_106150;
        }
    }
    ctx->pc = 0x105F48u;
label_105f48:
    // 0x105f48: 0x24030400  addiu       $v1, $zero, 0x400
    ctx->pc = 0x105f48u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
    // 0x105f4c: 0xae03004c  sw          $v1, 0x4C($s0)
    ctx->pc = 0x105f4cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 76), GPR_U32(ctx, 3));
    // 0x105f50: 0x34420400  ori         $v0, $v0, 0x400
    ctx->pc = 0x105f50u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1024);
    // 0x105f54: 0xa602000c  sh          $v0, 0xC($s0)
    ctx->pc = 0x105f54u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 2));
label_105f58:
    // 0x105f58: 0x12800008  beqz        $s4, . + 4 + (0x8 << 2)
    ctx->pc = 0x105F58u;
    {
        const bool branch_taken_0x105f58 = (GPR_U64(ctx, 20) == GPR_U64(ctx, 0));
        ctx->pc = 0x105F5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105F58u;
            // 0x105f5c: 0x2c0982d  daddu       $s3, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105f58) {
            ctx->pc = 0x105F7Cu;
            goto label_105f7c;
        }
    }
    ctx->pc = 0x105F60u;
    // 0x105f60: 0x8605000e  lh          $a1, 0xE($s0)
    ctx->pc = 0x105f60u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 14)));
    // 0x105f64: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x105f64u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105f68: 0xc04187c  jal         func_1061F0
    ctx->pc = 0x105F68u;
    SET_GPR_U32(ctx, 31, 0x105F70u);
    ctx->pc = 0x105F6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x105F68u;
            // 0x105f6c: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1061F0u;
    if (runtime->hasFunction(0x1061F0u)) {
        auto targetFn = runtime->lookupFunction(0x1061F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105F70u; }
        if (ctx->pc != 0x105F70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001061F0_0x1061f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105F70u; }
        if (ctx->pc != 0x105F70u) { return; }
    }
    ctx->pc = 0x105F70u;
label_105f70:
    // 0x105f70: 0x14400077  bnez        $v0, . + 4 + (0x77 << 2)
    ctx->pc = 0x105F70u;
    {
        const bool branch_taken_0x105f70 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x105F74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105F70u;
            // 0x105f74: 0xdfa20010  ld          $v0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105f70) {
            ctx->pc = 0x106150u;
            goto label_106150;
        }
    }
    ctx->pc = 0x105F78u;
    // 0x105f78: 0x56982d  daddu       $s3, $v0, $s6
    ctx->pc = 0x105f78u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 22));
label_105f7c:
    // 0x105f7c: 0x16e00016  bnez        $s7, . + 4 + (0x16 << 2)
    ctx->pc = 0x105F7Cu;
    {
        const bool branch_taken_0x105f7c = (GPR_U64(ctx, 23) != GPR_U64(ctx, 0));
        ctx->pc = 0x105F80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105F7Cu;
            // 0x105f80: 0x9606000c  lhu         $a2, 0xC($s0) (Delay Slot)
        SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105f7c) {
            ctx->pc = 0x105FD8u;
            goto label_105fd8;
        }
    }
    ctx->pc = 0x105F84u;
    // 0x105f84: 0x30c21000  andi        $v0, $a2, 0x1000
    ctx->pc = 0x105f84u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)4096);
    // 0x105f88: 0x50400003  beql        $v0, $zero, . + 4 + (0x3 << 2)
    ctx->pc = 0x105F88u;
    {
        const bool branch_taken_0x105f88 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x105f88) {
            ctx->pc = 0x105F8Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x105F88u;
            // 0x105f8c: 0x8e04001c  lw          $a0, 0x1C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x105F98u;
            goto label_105f98;
        }
    }
    ctx->pc = 0x105F90u;
    // 0x105f90: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x105F90u;
    {
        const bool branch_taken_0x105f90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x105F94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105F90u;
            // 0x105f94: 0x8e120050  lw          $s2, 0x50($s0) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 80)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105f90) {
            ctx->pc = 0x105FB8u;
            goto label_105fb8;
        }
    }
    ctx->pc = 0x105F98u;
label_105f98:
    // 0x105f98: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x105f98u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105f9c: 0x2a0f809  jalr        $s5
    ctx->pc = 0x105F9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 21);
        SET_GPR_U32(ctx, 31, 0x105FA4u);
        ctx->pc = 0x105FA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105F9Cu;
            // 0x105fa0: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x105FA4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x105D90u: goto label_105d90;
            case 0x105DA4u: goto label_105da4;
            case 0x105DACu: goto label_105dac;
            case 0x105DC4u: goto label_105dc4;
            case 0x105DC8u: goto label_105dc8;
            case 0x105DD8u: goto label_105dd8;
            case 0x105DF8u: goto label_105df8;
            case 0x105E08u: goto label_105e08;
            case 0x105E10u: goto label_105e10;
            case 0x105E28u: goto label_105e28;
            case 0x105E34u: goto label_105e34;
            case 0x105E48u: goto label_105e48;
            case 0x105E78u: goto label_105e78;
            case 0x105E98u: goto label_105e98;
            case 0x105E9Cu: goto label_105e9c;
            case 0x105EB0u: goto label_105eb0;
            case 0x105EC0u: goto label_105ec0;
            case 0x105EC4u: goto label_105ec4;
            case 0x105ED0u: goto label_105ed0;
            case 0x105EE0u: goto label_105ee0;
            case 0x105EE4u: goto label_105ee4;
            case 0x105F1Cu: goto label_105f1c;
            case 0x105F3Cu: goto label_105f3c;
            case 0x105F40u: goto label_105f40;
            case 0x105F48u: goto label_105f48;
            case 0x105F58u: goto label_105f58;
            case 0x105F70u: goto label_105f70;
            case 0x105F7Cu: goto label_105f7c;
            case 0x105F98u: goto label_105f98;
            case 0x105FA4u: goto label_105fa4;
            case 0x105FB8u: goto label_105fb8;
            case 0x105FD8u: goto label_105fd8;
            case 0x105FDCu: goto label_105fdc;
            case 0x106010u: goto label_106010;
            case 0x106014u: goto label_106014;
            case 0x106030u: goto label_106030;
            case 0x106094u: goto label_106094;
            case 0x10609Cu: goto label_10609c;
            case 0x1060B0u: goto label_1060b0;
            case 0x1060C8u: goto label_1060c8;
            case 0x1060F4u: goto label_1060f4;
            case 0x1060F8u: goto label_1060f8;
            case 0x10611Cu: goto label_10611c;
            case 0x106144u: goto label_106144;
            case 0x106150u: goto label_106150;
            case 0x106158u: goto label_106158;
            case 0x106170u: goto label_106170;
            case 0x106188u: goto label_106188;
            case 0x1061A0u: goto label_1061a0;
            case 0x1061A4u: goto label_1061a4;
            case 0x1061C0u: goto label_1061c0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x105FA4u; }
            if (ctx->pc != 0x105FA4u) { return; }
        }
        }
    }
    ctx->pc = 0x105FA4u;
label_105fa4:
    // 0x105fa4: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x105fa4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105fa8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x105fa8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x105fac: 0x12420068  beq         $s2, $v0, . + 4 + (0x68 << 2)
    ctx->pc = 0x105FACu;
    {
        const bool branch_taken_0x105fac = (GPR_U64(ctx, 18) == GPR_U64(ctx, 2));
        if (branch_taken_0x105fac) {
            ctx->pc = 0x106150u;
            goto label_106150;
        }
    }
    ctx->pc = 0x105FB4u;
    // 0x105fb4: 0x9606000c  lhu         $a2, 0xC($s0)
    ctx->pc = 0x105fb4u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
label_105fb8:
    // 0x105fb8: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x105fb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x105fbc: 0x8e050030  lw          $a1, 0x30($s0)
    ctx->pc = 0x105fbcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x105fc0: 0x10a00013  beqz        $a1, . + 4 + (0x13 << 2)
    ctx->pc = 0x105FC0u;
    {
        const bool branch_taken_0x105fc0 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x105FC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105FC0u;
            // 0x105fc4: 0x242902f  dsubu       $s2, $s2, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) - GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105fc0) {
            ctx->pc = 0x106010u;
            goto label_106010;
        }
    }
    ctx->pc = 0x105FC8u;
    // 0x105fc8: 0x8e02003c  lw          $v0, 0x3C($s0)
    ctx->pc = 0x105fc8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
    // 0x105fcc: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x105FCCu;
    {
        const bool branch_taken_0x105fcc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x105FD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x105FCCu;
            // 0x105fd0: 0x242902f  dsubu       $s2, $s2, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) - GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x105fcc) {
            ctx->pc = 0x105FDCu;
            goto label_105fdc;
        }
    }
    ctx->pc = 0x105FD4u;
    // 0x105fd4: 0x0  nop
    ctx->pc = 0x105fd4u;
    // NOP
label_105fd8:
    // 0x105fd8: 0x8e050030  lw          $a1, 0x30($s0)
    ctx->pc = 0x105fd8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
label_105fdc:
    // 0x105fdc: 0x50a0000d  beql        $a1, $zero, . + 4 + (0xD << 2)
    ctx->pc = 0x105FDCu;
    {
        const bool branch_taken_0x105fdc = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x105fdc) {
            ctx->pc = 0x105FE0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x105FDCu;
            // 0x105fe0: 0x8e020000  lw          $v0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x106014u;
            goto label_106014;
        }
    }
    ctx->pc = 0x105FE4u;
    // 0x105fe4: 0x8e020038  lw          $v0, 0x38($s0)
    ctx->pc = 0x105fe4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x105fe8: 0x8e070010  lw          $a3, 0x10($s0)
    ctx->pc = 0x105fe8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x105fec: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x105fecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x105ff0: 0x478823  subu        $s1, $v0, $a3
    ctx->pc = 0x105ff0u;
    SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x105ff4: 0x8e04003c  lw          $a0, 0x3C($s0)
    ctx->pc = 0x105ff4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
    // 0x105ff8: 0x11103c  dsll32      $v0, $s1, 0
    ctx->pc = 0x105ff8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) << (32 + 0));
    // 0x105ffc: 0x243902d  daddu       $s2, $s2, $v1
    ctx->pc = 0x105ffcu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 3));
    // 0x106000: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x106000u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x106004: 0x2248821  addu        $s1, $s1, $a0
    ctx->pc = 0x106004u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 4)));
    // 0x106008: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x106008u;
    {
        const bool branch_taken_0x106008 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10600Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106008u;
            // 0x10600c: 0x242902f  dsubu       $s2, $s2, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) - GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106008) {
            ctx->pc = 0x106030u;
            goto label_106030;
        }
    }
    ctx->pc = 0x106010u;
label_106010:
    // 0x106010: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x106010u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_106014:
    // 0x106014: 0x8e070010  lw          $a3, 0x10($s0)
    ctx->pc = 0x106014u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x106018: 0x8e040004  lw          $a0, 0x4($s0)
    ctx->pc = 0x106018u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x10601c: 0x478823  subu        $s1, $v0, $a3
    ctx->pc = 0x10601cu;
    SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x106020: 0x11183c  dsll32      $v1, $s1, 0
    ctx->pc = 0x106020u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) << (32 + 0));
    // 0x106024: 0x2248821  addu        $s1, $s1, $a0
    ctx->pc = 0x106024u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 4)));
    // 0x106028: 0x3183e  dsrl32      $v1, $v1, 0
    ctx->pc = 0x106028u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x10602c: 0x243902f  dsubu       $s2, $s2, $v1
    ctx->pc = 0x10602cu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) - GPR_U64(ctx, 3));
label_106030:
    // 0x106030: 0x30c22000  andi        $v0, $a2, 0x2000
    ctx->pc = 0x106030u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)8192);
    // 0x106034: 0x5440001e  bnel        $v0, $zero, . + 4 + (0x1E << 2)
    ctx->pc = 0x106034u;
    {
        const bool branch_taken_0x106034 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x106034) {
            ctx->pc = 0x106038u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x106034u;
            // 0x106038: 0x8e02004c  lw          $v0, 0x4C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 76)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1060B0u;
            goto label_1060b0;
        }
    }
    ctx->pc = 0x10603Cu;
    // 0x10603c: 0x272102a  slt         $v0, $s3, $s2
    ctx->pc = 0x10603cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x106040: 0x5440001b  bnel        $v0, $zero, . + 4 + (0x1B << 2)
    ctx->pc = 0x106040u;
    {
        const bool branch_taken_0x106040 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x106040) {
            ctx->pc = 0x106044u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x106040u;
            // 0x106044: 0x8e02004c  lw          $v0, 0x4C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 76)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1060B0u;
            goto label_1060b0;
        }
    }
    ctx->pc = 0x106048u;
    // 0x106048: 0x11103c  dsll32      $v0, $s1, 0
    ctx->pc = 0x106048u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) << (32 + 0));
    // 0x10604c: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x10604cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x106050: 0x242102d  daddu       $v0, $s2, $v0
    ctx->pc = 0x106050u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 2));
    // 0x106054: 0x262102a  slt         $v0, $s3, $v0
    ctx->pc = 0x106054u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x106058: 0x50400015  beql        $v0, $zero, . + 4 + (0x15 << 2)
    ctx->pc = 0x106058u;
    {
        const bool branch_taken_0x106058 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x106058) {
            ctx->pc = 0x10605Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x106058u;
            // 0x10605c: 0x8e02004c  lw          $v0, 0x4C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 76)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1060B0u;
            goto label_1060b0;
        }
    }
    ctx->pc = 0x106060u;
    // 0x106060: 0x272102f  dsubu       $v0, $s3, $s2
    ctx->pc = 0x106060u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) - GPR_U64(ctx, 18));
    // 0x106064: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x106064u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x106068: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x106068u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x10606c: 0x2221823  subu        $v1, $s1, $v0
    ctx->pc = 0x10606cu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x106070: 0xe21021  addu        $v0, $a3, $v0
    ctx->pc = 0x106070u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x106074: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x106074u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x106078: 0x10a00008  beqz        $a1, . + 4 + (0x8 << 2)
    ctx->pc = 0x106078u;
    {
        const bool branch_taken_0x106078 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x10607Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106078u;
            // 0x10607c: 0xae030004  sw          $v1, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106078) {
            ctx->pc = 0x10609Cu;
            goto label_10609c;
        }
    }
    ctx->pc = 0x106080u;
    // 0x106080: 0x26020040  addiu       $v0, $s0, 0x40
    ctx->pc = 0x106080u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 64));
    // 0x106084: 0x50a20005  beql        $a1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x106084u;
    {
        const bool branch_taken_0x106084 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        if (branch_taken_0x106084) {
            ctx->pc = 0x106088u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x106084u;
            // 0x106088: 0xae000030  sw          $zero, 0x30($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10609Cu;
            goto label_10609c;
        }
    }
    ctx->pc = 0x10608Cu;
    // 0x10608c: 0xc041636  jal         func_1058D8
    ctx->pc = 0x10608Cu;
    SET_GPR_U32(ctx, 31, 0x106094u);
    ctx->pc = 0x106090u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10608Cu;
            // 0x106090: 0x8e040054  lw          $a0, 0x54($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1058D8u;
    if (runtime->hasFunction(0x1058D8u)) {
        auto targetFn = runtime->lookupFunction(0x1058D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106094u; }
        if (ctx->pc != 0x106094u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001058D8_0x1058d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106094u; }
        if (ctx->pc != 0x106094u) { return; }
    }
    ctx->pc = 0x106094u;
label_106094:
    // 0x106094: 0x9606000c  lhu         $a2, 0xC($s0)
    ctx->pc = 0x106094u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x106098: 0xae000030  sw          $zero, 0x30($s0)
    ctx->pc = 0x106098u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
label_10609c:
    // 0x10609c: 0x30c3ffdf  andi        $v1, $a2, 0xFFDF
    ctx->pc = 0x10609cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)65503);
    // 0x1060a0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1060a0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1060a4: 0x10000046  b           . + 4 + (0x46 << 2)
    ctx->pc = 0x1060A4u;
    {
        const bool branch_taken_0x1060a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1060A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1060A4u;
            // 0x1060a8: 0xa603000c  sh          $v1, 0xC($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1060a4) {
            ctx->pc = 0x1061C0u;
            goto label_1061c0;
        }
    }
    ctx->pc = 0x1060ACu;
    // 0x1060ac: 0x0  nop
    ctx->pc = 0x1060acu;
    // NOP
label_1060b0:
    // 0x1060b0: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1060b0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1060b4: 0x8e04001c  lw          $a0, 0x1C($s0)
    ctx->pc = 0x1060b4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1060b8: 0x21023  negu        $v0, $v0
    ctx->pc = 0x1060b8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 2)));
    // 0x1060bc: 0x539024  and         $s2, $v0, $s3
    ctx->pc = 0x1060bcu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 2) & GPR_U64(ctx, 19));
    // 0x1060c0: 0x2a0f809  jalr        $s5
    ctx->pc = 0x1060C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 21);
        SET_GPR_U32(ctx, 31, 0x1060C8u);
        ctx->pc = 0x1060C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1060C0u;
            // 0x1060c4: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1060C8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x105D90u: goto label_105d90;
            case 0x105DA4u: goto label_105da4;
            case 0x105DACu: goto label_105dac;
            case 0x105DC4u: goto label_105dc4;
            case 0x105DC8u: goto label_105dc8;
            case 0x105DD8u: goto label_105dd8;
            case 0x105DF8u: goto label_105df8;
            case 0x105E08u: goto label_105e08;
            case 0x105E10u: goto label_105e10;
            case 0x105E28u: goto label_105e28;
            case 0x105E34u: goto label_105e34;
            case 0x105E48u: goto label_105e48;
            case 0x105E78u: goto label_105e78;
            case 0x105E98u: goto label_105e98;
            case 0x105E9Cu: goto label_105e9c;
            case 0x105EB0u: goto label_105eb0;
            case 0x105EC0u: goto label_105ec0;
            case 0x105EC4u: goto label_105ec4;
            case 0x105ED0u: goto label_105ed0;
            case 0x105EE0u: goto label_105ee0;
            case 0x105EE4u: goto label_105ee4;
            case 0x105F1Cu: goto label_105f1c;
            case 0x105F3Cu: goto label_105f3c;
            case 0x105F40u: goto label_105f40;
            case 0x105F48u: goto label_105f48;
            case 0x105F58u: goto label_105f58;
            case 0x105F70u: goto label_105f70;
            case 0x105F7Cu: goto label_105f7c;
            case 0x105F98u: goto label_105f98;
            case 0x105FA4u: goto label_105fa4;
            case 0x105FB8u: goto label_105fb8;
            case 0x105FD8u: goto label_105fd8;
            case 0x105FDCu: goto label_105fdc;
            case 0x106010u: goto label_106010;
            case 0x106014u: goto label_106014;
            case 0x106030u: goto label_106030;
            case 0x106094u: goto label_106094;
            case 0x10609Cu: goto label_10609c;
            case 0x1060B0u: goto label_1060b0;
            case 0x1060C8u: goto label_1060c8;
            case 0x1060F4u: goto label_1060f4;
            case 0x1060F8u: goto label_1060f8;
            case 0x10611Cu: goto label_10611c;
            case 0x106144u: goto label_106144;
            case 0x106150u: goto label_106150;
            case 0x106158u: goto label_106158;
            case 0x106170u: goto label_106170;
            case 0x106188u: goto label_106188;
            case 0x1061A0u: goto label_1061a0;
            case 0x1061A4u: goto label_1061a4;
            case 0x1061C0u: goto label_1061c0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1060C8u; }
            if (ctx->pc != 0x1060C8u) { return; }
        }
        }
    }
    ctx->pc = 0x1060C8u;
label_1060c8:
    // 0x1060c8: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1060c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1060cc: 0x10430020  beq         $v0, $v1, . + 4 + (0x20 << 2)
    ctx->pc = 0x1060CCu;
    {
        const bool branch_taken_0x1060cc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1060cc) {
            ctx->pc = 0x106150u;
            goto label_106150;
        }
    }
    ctx->pc = 0x1060D4u;
    // 0x1060d4: 0x8e050030  lw          $a1, 0x30($s0)
    ctx->pc = 0x1060d4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x1060d8: 0x10a00007  beqz        $a1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1060D8u;
    {
        const bool branch_taken_0x1060d8 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x1060DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1060D8u;
            // 0x1060dc: 0xae000004  sw          $zero, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1060d8) {
            ctx->pc = 0x1060F8u;
            goto label_1060f8;
        }
    }
    ctx->pc = 0x1060E0u;
    // 0x1060e0: 0x26020040  addiu       $v0, $s0, 0x40
    ctx->pc = 0x1060e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 64));
    // 0x1060e4: 0x50a20004  beql        $a1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1060E4u;
    {
        const bool branch_taken_0x1060e4 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        if (branch_taken_0x1060e4) {
            ctx->pc = 0x1060E8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1060E4u;
            // 0x1060e8: 0xae000030  sw          $zero, 0x30($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1060F8u;
            goto label_1060f8;
        }
    }
    ctx->pc = 0x1060ECu;
    // 0x1060ec: 0xc041636  jal         func_1058D8
    ctx->pc = 0x1060ECu;
    SET_GPR_U32(ctx, 31, 0x1060F4u);
    ctx->pc = 0x1060F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1060ECu;
            // 0x1060f0: 0x8e040054  lw          $a0, 0x54($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1058D8u;
    if (runtime->hasFunction(0x1058D8u)) {
        auto targetFn = runtime->lookupFunction(0x1058D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1060F4u; }
        if (ctx->pc != 0x1060F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001058D8_0x1058d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1060F4u; }
        if (ctx->pc != 0x1060F4u) { return; }
    }
    ctx->pc = 0x1060F4u;
label_1060f4:
    // 0x1060f4: 0xae000030  sw          $zero, 0x30($s0)
    ctx->pc = 0x1060f4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
label_1060f8:
    // 0x1060f8: 0x9602000c  lhu         $v0, 0xC($s0)
    ctx->pc = 0x1060f8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1060fc: 0x272182f  dsubu       $v1, $s3, $s2
    ctx->pc = 0x1060fcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 19) - GPR_U64(ctx, 18));
    // 0x106100: 0x3883c  dsll32      $s1, $v1, 0
    ctx->pc = 0x106100u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 3) << (32 + 0));
    // 0x106104: 0x11883f  dsra32      $s1, $s1, 0
    ctx->pc = 0x106104u;
    SET_GPR_S64(ctx, 17, GPR_S64(ctx, 17) >> (32 + 0));
    // 0x106108: 0x3042ffdf  andi        $v0, $v0, 0xFFDF
    ctx->pc = 0x106108u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65503);
    // 0x10610c: 0x1220000d  beqz        $s1, . + 4 + (0xD << 2)
    ctx->pc = 0x10610Cu;
    {
        const bool branch_taken_0x10610c = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x106110u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10610Cu;
            // 0x106110: 0xa602000c  sh          $v0, 0xC($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10610c) {
            ctx->pc = 0x106144u;
            goto label_106144;
        }
    }
    ctx->pc = 0x106114u;
    // 0x106114: 0xc042814  jal         func_10A050
    ctx->pc = 0x106114u;
    SET_GPR_U32(ctx, 31, 0x10611Cu);
    ctx->pc = 0x106118u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106114u;
            // 0x106118: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A050u;
    if (runtime->hasFunction(0x10A050u)) {
        auto targetFn = runtime->lookupFunction(0x10A050u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10611Cu; }
        if (ctx->pc != 0x10611Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A050_0x10a050(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10611Cu; }
        if (ctx->pc != 0x10611Cu) { return; }
    }
    ctx->pc = 0x10611Cu;
label_10611c:
    // 0x10611c: 0x1440000c  bnez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x10611Cu;
    {
        const bool branch_taken_0x10611c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10611c) {
            ctx->pc = 0x106150u;
            goto label_106150;
        }
    }
    ctx->pc = 0x106124u;
    // 0x106124: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x106124u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x106128: 0x71102b  sltu        $v0, $v1, $s1
    ctx->pc = 0x106128u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 17)) ? 1 : 0);
    // 0x10612c: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x10612Cu;
    {
        const bool branch_taken_0x10612c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x106130u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10612Cu;
            // 0x106130: 0x711823  subu        $v1, $v1, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10612c) {
            ctx->pc = 0x106150u;
            goto label_106150;
        }
    }
    ctx->pc = 0x106134u;
    // 0x106134: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x106134u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x106138: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x106138u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
    // 0x10613c: 0x511021  addu        $v0, $v0, $s1
    ctx->pc = 0x10613cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x106140: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x106140u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
label_106144:
    // 0x106144: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x106144u;
    {
        const bool branch_taken_0x106144 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x106148u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106144u;
            // 0x106148: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106144) {
            ctx->pc = 0x1061C0u;
            goto label_1061c0;
        }
    }
    ctx->pc = 0x10614Cu;
    // 0x10614c: 0x0  nop
    ctx->pc = 0x10614cu;
    // NOP
label_106150:
    // 0x106150: 0xc04142c  jal         func_1050B0
    ctx->pc = 0x106150u;
    SET_GPR_U32(ctx, 31, 0x106158u);
    ctx->pc = 0x106154u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106150u;
            // 0x106154: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1050B0u;
    if (runtime->hasFunction(0x1050B0u)) {
        auto targetFn = runtime->lookupFunction(0x1050B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106158u; }
        if (ctx->pc != 0x106158u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001050B0_0x1050b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106158u; }
        if (ctx->pc != 0x106158u) { return; }
    }
    ctx->pc = 0x106158u;
label_106158:
    // 0x106158: 0x54400019  bnel        $v0, $zero, . + 4 + (0x19 << 2)
    ctx->pc = 0x106158u;
    {
        const bool branch_taken_0x106158 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x106158) {
            ctx->pc = 0x10615Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x106158u;
            // 0x10615c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1061C0u;
            goto label_1061c0;
        }
    }
    ctx->pc = 0x106160u;
    // 0x106160: 0x8e04001c  lw          $a0, 0x1C($s0)
    ctx->pc = 0x106160u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x106164: 0x2c0282d  daddu       $a1, $s6, $zero
    ctx->pc = 0x106164u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106168: 0x2a0f809  jalr        $s5
    ctx->pc = 0x106168u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 21);
        SET_GPR_U32(ctx, 31, 0x106170u);
        ctx->pc = 0x10616Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106168u;
            // 0x10616c: 0x280302d  daddu       $a2, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x106170u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x105D90u: goto label_105d90;
            case 0x105DA4u: goto label_105da4;
            case 0x105DACu: goto label_105dac;
            case 0x105DC4u: goto label_105dc4;
            case 0x105DC8u: goto label_105dc8;
            case 0x105DD8u: goto label_105dd8;
            case 0x105DF8u: goto label_105df8;
            case 0x105E08u: goto label_105e08;
            case 0x105E10u: goto label_105e10;
            case 0x105E28u: goto label_105e28;
            case 0x105E34u: goto label_105e34;
            case 0x105E48u: goto label_105e48;
            case 0x105E78u: goto label_105e78;
            case 0x105E98u: goto label_105e98;
            case 0x105E9Cu: goto label_105e9c;
            case 0x105EB0u: goto label_105eb0;
            case 0x105EC0u: goto label_105ec0;
            case 0x105EC4u: goto label_105ec4;
            case 0x105ED0u: goto label_105ed0;
            case 0x105EE0u: goto label_105ee0;
            case 0x105EE4u: goto label_105ee4;
            case 0x105F1Cu: goto label_105f1c;
            case 0x105F3Cu: goto label_105f3c;
            case 0x105F40u: goto label_105f40;
            case 0x105F48u: goto label_105f48;
            case 0x105F58u: goto label_105f58;
            case 0x105F70u: goto label_105f70;
            case 0x105F7Cu: goto label_105f7c;
            case 0x105F98u: goto label_105f98;
            case 0x105FA4u: goto label_105fa4;
            case 0x105FB8u: goto label_105fb8;
            case 0x105FD8u: goto label_105fd8;
            case 0x105FDCu: goto label_105fdc;
            case 0x106010u: goto label_106010;
            case 0x106014u: goto label_106014;
            case 0x106030u: goto label_106030;
            case 0x106094u: goto label_106094;
            case 0x10609Cu: goto label_10609c;
            case 0x1060B0u: goto label_1060b0;
            case 0x1060C8u: goto label_1060c8;
            case 0x1060F4u: goto label_1060f4;
            case 0x1060F8u: goto label_1060f8;
            case 0x10611Cu: goto label_10611c;
            case 0x106144u: goto label_106144;
            case 0x106150u: goto label_106150;
            case 0x106158u: goto label_106158;
            case 0x106170u: goto label_106170;
            case 0x106188u: goto label_106188;
            case 0x1061A0u: goto label_1061a0;
            case 0x1061A4u: goto label_1061a4;
            case 0x1061C0u: goto label_1061c0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x106170u; }
            if (ctx->pc != 0x106170u) { return; }
        }
        }
    }
    ctx->pc = 0x106170u;
label_106170:
    // 0x106170: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x106170u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x106174: 0x54430004  bnel        $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x106174u;
    {
        const bool branch_taken_0x106174 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x106174) {
            ctx->pc = 0x106178u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x106174u;
            // 0x106178: 0x8e050030  lw          $a1, 0x30($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x106188u;
            goto label_106188;
        }
    }
    ctx->pc = 0x10617Cu;
    // 0x10617c: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x10617Cu;
    {
        const bool branch_taken_0x10617c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x106180u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10617Cu;
            // 0x106180: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10617c) {
            ctx->pc = 0x1061C0u;
            goto label_1061c0;
        }
    }
    ctx->pc = 0x106184u;
    // 0x106184: 0x0  nop
    ctx->pc = 0x106184u;
    // NOP
label_106188:
    // 0x106188: 0x10a00006  beqz        $a1, . + 4 + (0x6 << 2)
    ctx->pc = 0x106188u;
    {
        const bool branch_taken_0x106188 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x10618Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106188u;
            // 0x10618c: 0x26020040  addiu       $v0, $s0, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 64));
        ctx->in_delay_slot = false;
        if (branch_taken_0x106188) {
            ctx->pc = 0x1061A4u;
            goto label_1061a4;
        }
    }
    ctx->pc = 0x106190u;
    // 0x106190: 0x50a20004  beql        $a1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x106190u;
    {
        const bool branch_taken_0x106190 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        if (branch_taken_0x106190) {
            ctx->pc = 0x106194u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x106190u;
            // 0x106194: 0xae000030  sw          $zero, 0x30($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1061A4u;
            goto label_1061a4;
        }
    }
    ctx->pc = 0x106198u;
    // 0x106198: 0xc041636  jal         func_1058D8
    ctx->pc = 0x106198u;
    SET_GPR_U32(ctx, 31, 0x1061A0u);
    ctx->pc = 0x10619Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106198u;
            // 0x10619c: 0x8e040054  lw          $a0, 0x54($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1058D8u;
    if (runtime->hasFunction(0x1058D8u)) {
        auto targetFn = runtime->lookupFunction(0x1058D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1061A0u; }
        if (ctx->pc != 0x1061A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001058D8_0x1058d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1061A0u; }
        if (ctx->pc != 0x1061A0u) { return; }
    }
    ctx->pc = 0x1061A0u;
label_1061a0:
    // 0x1061a0: 0xae000030  sw          $zero, 0x30($s0)
    ctx->pc = 0x1061a0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
label_1061a4:
    // 0x1061a4: 0x9603000c  lhu         $v1, 0xC($s0)
    ctx->pc = 0x1061a4u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1061a8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1061a8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1061ac: 0x8e040010  lw          $a0, 0x10($s0)
    ctx->pc = 0x1061acu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1061b0: 0x3063ffdf  andi        $v1, $v1, 0xFFDF
    ctx->pc = 0x1061b0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65503);
    // 0x1061b4: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x1061b4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x1061b8: 0xa603000c  sh          $v1, 0xC($s0)
    ctx->pc = 0x1061b8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 3));
    // 0x1061bc: 0xae040000  sw          $a0, 0x0($s0)
    ctx->pc = 0x1061bcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 4));
label_1061c0:
    // 0x1061c0: 0xdfb00070  ld          $s0, 0x70($sp)
    ctx->pc = 0x1061c0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1061c4: 0xdfb10078  ld          $s1, 0x78($sp)
    ctx->pc = 0x1061c4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 120)));
    // 0x1061c8: 0xdfb20080  ld          $s2, 0x80($sp)
    ctx->pc = 0x1061c8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x1061cc: 0xdfb30088  ld          $s3, 0x88($sp)
    ctx->pc = 0x1061ccu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 136)));
    // 0x1061d0: 0xdfb40090  ld          $s4, 0x90($sp)
    ctx->pc = 0x1061d0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x1061d4: 0xdfb50098  ld          $s5, 0x98($sp)
    ctx->pc = 0x1061d4u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 152)));
    // 0x1061d8: 0xdfb600a0  ld          $s6, 0xA0($sp)
    ctx->pc = 0x1061d8u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x1061dc: 0xdfb700a8  ld          $s7, 0xA8($sp)
    ctx->pc = 0x1061dcu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x1061e0: 0xdfbf00b0  ld          $ra, 0xB0($sp)
    ctx->pc = 0x1061e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x1061e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1061E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1061E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1061E4u;
            // 0x1061e8: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x105D90u: goto label_105d90;
            case 0x105DA4u: goto label_105da4;
            case 0x105DACu: goto label_105dac;
            case 0x105DC4u: goto label_105dc4;
            case 0x105DC8u: goto label_105dc8;
            case 0x105DD8u: goto label_105dd8;
            case 0x105DF8u: goto label_105df8;
            case 0x105E08u: goto label_105e08;
            case 0x105E10u: goto label_105e10;
            case 0x105E28u: goto label_105e28;
            case 0x105E34u: goto label_105e34;
            case 0x105E48u: goto label_105e48;
            case 0x105E78u: goto label_105e78;
            case 0x105E98u: goto label_105e98;
            case 0x105E9Cu: goto label_105e9c;
            case 0x105EB0u: goto label_105eb0;
            case 0x105EC0u: goto label_105ec0;
            case 0x105EC4u: goto label_105ec4;
            case 0x105ED0u: goto label_105ed0;
            case 0x105EE0u: goto label_105ee0;
            case 0x105EE4u: goto label_105ee4;
            case 0x105F1Cu: goto label_105f1c;
            case 0x105F3Cu: goto label_105f3c;
            case 0x105F40u: goto label_105f40;
            case 0x105F48u: goto label_105f48;
            case 0x105F58u: goto label_105f58;
            case 0x105F70u: goto label_105f70;
            case 0x105F7Cu: goto label_105f7c;
            case 0x105F98u: goto label_105f98;
            case 0x105FA4u: goto label_105fa4;
            case 0x105FB8u: goto label_105fb8;
            case 0x105FD8u: goto label_105fd8;
            case 0x105FDCu: goto label_105fdc;
            case 0x106010u: goto label_106010;
            case 0x106014u: goto label_106014;
            case 0x106030u: goto label_106030;
            case 0x106094u: goto label_106094;
            case 0x10609Cu: goto label_10609c;
            case 0x1060B0u: goto label_1060b0;
            case 0x1060C8u: goto label_1060c8;
            case 0x1060F4u: goto label_1060f4;
            case 0x1060F8u: goto label_1060f8;
            case 0x10611Cu: goto label_10611c;
            case 0x106144u: goto label_106144;
            case 0x106150u: goto label_106150;
            case 0x106158u: goto label_106158;
            case 0x106170u: goto label_106170;
            case 0x106188u: goto label_106188;
            case 0x1061A0u: goto label_1061a0;
            case 0x1061A4u: goto label_1061a4;
            case 0x1061C0u: goto label_1061c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1061ECu;
    // 0x1061ec: 0x0  nop
    ctx->pc = 0x1061ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
