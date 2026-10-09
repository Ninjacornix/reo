#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C2D00
// Address: 0x1c2d00 - 0x1c3150
void sub_001C2D00_0x1c2d00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C2D00_0x1c2d00");
#endif

    switch (ctx->pc) {
        case 0x1c2d58u: goto label_1c2d58;
        case 0x1c2d60u: goto label_1c2d60;
        case 0x1c2df0u: goto label_1c2df0;
        case 0x1c2ed0u: goto label_1c2ed0;
        case 0x1c2f00u: goto label_1c2f00;
        case 0x1c2f14u: goto label_1c2f14;
        case 0x1c3048u: goto label_1c3048;
        case 0x1c30ccu: goto label_1c30cc;
        case 0x1c3114u: goto label_1c3114;
        case 0x1c3128u: goto label_1c3128;
        case 0x1c3130u: goto label_1c3130;
        default: break;
    }

    ctx->pc = 0x1c2d00u;

    // 0x1c2d00: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c2d00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c2d04: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c2d04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c2d08: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c2d08u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c2d0c: 0x80820002  lb          $v0, 0x2($a0)
    ctx->pc = 0x1c2d0cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x1c2d10: 0x2c410006  sltiu       $at, $v0, 0x6
    ctx->pc = 0x1c2d10u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)6) ? 1 : 0);
    // 0x1c2d14: 0x10200101  beqz        $at, . + 4 + (0x101 << 2)
    ctx->pc = 0x1C2D14u;
    {
        const bool branch_taken_0x1c2d14 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2D18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2D14u;
            // 0x1c2d18: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2d14) {
            ctx->pc = 0x1C311Cu;
            goto label_1c311c;
        }
    }
    ctx->pc = 0x1C2D1Cu;
    // 0x1c2d1c: 0x3c030025  lui         $v1, 0x25
    ctx->pc = 0x1c2d1cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)37 << 16));
    // 0x1c2d20: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1c2d20u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1c2d24: 0x24632ce0  addiu       $v1, $v1, 0x2CE0
    ctx->pc = 0x1c2d24u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 11488));
    // 0x1c2d28: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c2d28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c2d2c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1c2d2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1c2d30: 0x400008  jr          $v0
    ctx->pc = 0x1C2D30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C2D38u: goto label_1c2d38;
            case 0x1C2D58u: goto label_1c2d58;
            case 0x1C2EC8u: goto label_1c2ec8;
            case 0x1C3030u: goto label_1c3030;
            case 0x1C30E4u: goto label_1c30e4;
            case 0x1C30FCu: goto label_1c30fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C2D38u;
label_1c2d38:
    // 0x1c2d38: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1c2d38u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c2d3c: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x1c2d3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1c2d40: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x1c2d40u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c2d44: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x1c2d44u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
    // 0x1c2d48: 0x8e040024  lw          $a0, 0x24($s0)
    ctx->pc = 0x1c2d48u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x1c2d4c: 0x8e0500e8  lw          $a1, 0xE8($s0)
    ctx->pc = 0x1c2d4cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 232)));
    // 0x1c2d50: 0xc0701c4  jal         func_1C0710
    ctx->pc = 0x1C2D50u;
    SET_GPR_U32(ctx, 31, 0x1C2D58u);
    ctx->pc = 0x1C2D54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2D50u;
            // 0x1c2d54: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C0710u;
    if (runtime->hasFunction(0x1C0710u)) {
        auto targetFn = runtime->lookupFunction(0x1C0710u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2D58u; }
        if (ctx->pc != 0x1C2D58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C0710_0x1c0710(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2D58u; }
        if (ctx->pc != 0x1C2D58u) { return; }
    }
    ctx->pc = 0x1C2D58u;
label_1c2d58:
    // 0x1c2d58: 0xc070498  jal         func_1C1260
    ctx->pc = 0x1C2D58u;
    SET_GPR_U32(ctx, 31, 0x1C2D60u);
    ctx->pc = 0x1C1260u;
    if (runtime->hasFunction(0x1C1260u)) {
        auto targetFn = runtime->lookupFunction(0x1C1260u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2D60u; }
        if (ctx->pc != 0x1C2D60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C1260_0x1c1260(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2D60u; }
        if (ctx->pc != 0x1C2D60u) { return; }
    }
    ctx->pc = 0x1C2D60u;
label_1c2d60:
    // 0x1c2d60: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1c2d60u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1c2d64: 0x104300ee  beq         $v0, $v1, . + 4 + (0xEE << 2)
    ctx->pc = 0x1C2D64u;
    {
        const bool branch_taken_0x1c2d64 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C2D68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2D64u;
            // 0x1c2d68: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2d64) {
            ctx->pc = 0x1C3120u;
            goto label_1c3120;
        }
    }
    ctx->pc = 0x1C2D6Cu;
    // 0x1c2d6c: 0x2403ff05  addiu       $v1, $zero, -0xFB
    ctx->pc = 0x1c2d6cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967045));
    // 0x1c2d70: 0x10430024  beq         $v0, $v1, . + 4 + (0x24 << 2)
    ctx->pc = 0x1C2D70u;
    {
        const bool branch_taken_0x1c2d70 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C2D74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2D70u;
            // 0x1c2d74: 0x24030036  addiu       $v1, $zero, 0x36 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 54));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2d70) {
            ctx->pc = 0x1C2E04u;
            goto label_1c2e04;
        }
    }
    ctx->pc = 0x1C2D78u;
    // 0x1c2d78: 0x1040001a  beqz        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x1C2D78u;
    {
        const bool branch_taken_0x1c2d78 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2D7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2D78u;
            // 0x1c2d7c: 0x2403ff00  addiu       $v1, $zero, -0x100 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2d78) {
            ctx->pc = 0x1C2DE4u;
            goto label_1c2de4;
        }
    }
    ctx->pc = 0x1C2D80u;
    // 0x1c2d80: 0x1043000e  beq         $v0, $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x1C2D80u;
    {
        const bool branch_taken_0x1c2d80 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c2d80) {
            ctx->pc = 0x1C2DBCu;
            goto label_1c2dbc;
        }
    }
    ctx->pc = 0x1C2D88u;
    // 0x1c2d88: 0x2403ff02  addiu       $v1, $zero, -0xFE
    ctx->pc = 0x1c2d88u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967042));
    // 0x1c2d8c: 0x10430005  beq         $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1C2D8Cu;
    {
        const bool branch_taken_0x1c2d8c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C2D90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2D8Cu;
            // 0x1c2d90: 0x2403ff03  addiu       $v1, $zero, -0xFD (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967043));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2d8c) {
            ctx->pc = 0x1C2DA4u;
            goto label_1c2da4;
        }
    }
    ctx->pc = 0x1C2D94u;
    // 0x1c2d94: 0x10430003  beq         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C2D94u;
    {
        const bool branch_taken_0x1c2d94 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c2d94) {
            ctx->pc = 0x1C2DA4u;
            goto label_1c2da4;
        }
    }
    ctx->pc = 0x1C2D9Cu;
    // 0x1c2d9c: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x1C2D9Cu;
    {
        const bool branch_taken_0x1c2d9c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2DA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2D9Cu;
            // 0x1c2da0: 0x24030003  addiu       $v1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2d9c) {
            ctx->pc = 0x1C2E28u;
            goto label_1c2e28;
        }
    }
    ctx->pc = 0x1C2DA4u;
label_1c2da4:
    // 0x1c2da4: 0xae00002c  sw          $zero, 0x2C($s0)
    ctx->pc = 0x1c2da4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 0));
    // 0x1c2da8: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1c2da8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1c2dac: 0xa2020002  sb          $v0, 0x2($s0)
    ctx->pc = 0x1c2dacu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c2db0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c2db0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c2db4: 0x100000d9  b           . + 4 + (0xD9 << 2)
    ctx->pc = 0x1C2DB4u;
    {
        const bool branch_taken_0x1c2db4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2DB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2DB4u;
            // 0x1c2db8: 0xae020010  sw          $v0, 0x10($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2db4) {
            ctx->pc = 0x1C311Cu;
            goto label_1c311c;
        }
    }
    ctx->pc = 0x1C2DBCu;
label_1c2dbc:
    // 0x1c2dbc: 0x24030036  addiu       $v1, $zero, 0x36
    ctx->pc = 0x1c2dbcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 54));
    // 0x1c2dc0: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1c2dc0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c2dc4: 0xae03002c  sw          $v1, 0x2C($s0)
    ctx->pc = 0x1c2dc4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 3));
    // 0x1c2dc8: 0xa2020002  sb          $v0, 0x2($s0)
    ctx->pc = 0x1c2dc8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c2dcc: 0x24030005  addiu       $v1, $zero, 0x5
    ctx->pc = 0x1c2dccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c2dd0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c2dd0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c2dd4: 0xae030010  sw          $v1, 0x10($s0)
    ctx->pc = 0x1c2dd4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 3));
    // 0x1c2dd8: 0xae020030  sw          $v0, 0x30($s0)
    ctx->pc = 0x1c2dd8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 2));
    // 0x1c2ddc: 0x100000cf  b           . + 4 + (0xCF << 2)
    ctx->pc = 0x1C2DDCu;
    {
        const bool branch_taken_0x1c2ddc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2DE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2DDCu;
            // 0x1c2de0: 0xae020038  sw          $v0, 0x38($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2ddc) {
            ctx->pc = 0x1C311Cu;
            goto label_1c311c;
        }
    }
    ctx->pc = 0x1C2DE4u;
label_1c2de4:
    // 0x1c2de4: 0x8e0500ec  lw          $a1, 0xEC($s0)
    ctx->pc = 0x1c2de4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 236)));
    // 0x1c2de8: 0xc070138  jal         func_1C04E0
    ctx->pc = 0x1C2DE8u;
    SET_GPR_U32(ctx, 31, 0x1C2DF0u);
    ctx->pc = 0x1C2DECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2DE8u;
            // 0x1c2dec: 0x8e040024  lw          $a0, 0x24($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C04E0u;
    if (runtime->hasFunction(0x1C04E0u)) {
        auto targetFn = runtime->lookupFunction(0x1C04E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2DF0u; }
        if (ctx->pc != 0x1C2DF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C04E0_0x1c04e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2DF0u; }
        if (ctx->pc != 0x1C2DF0u) { return; }
    }
    ctx->pc = 0x1C2DF0u;
label_1c2df0:
    // 0x1c2df0: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1c2df0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c2df4: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1c2df4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c2df8: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x1c2df8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c2dfc: 0x100000c7  b           . + 4 + (0xC7 << 2)
    ctx->pc = 0x1C2DFCu;
    {
        const bool branch_taken_0x1c2dfc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2E00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2DFCu;
            // 0x1c2e00: 0xae02002c  sw          $v0, 0x2C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2dfc) {
            ctx->pc = 0x1C311Cu;
            goto label_1c311c;
        }
    }
    ctx->pc = 0x1C2E04u;
label_1c2e04:
    // 0x1c2e04: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1c2e04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c2e08: 0xae03002c  sw          $v1, 0x2C($s0)
    ctx->pc = 0x1c2e08u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 3));
    // 0x1c2e0c: 0xa2020002  sb          $v0, 0x2($s0)
    ctx->pc = 0x1c2e0cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c2e10: 0x24030005  addiu       $v1, $zero, 0x5
    ctx->pc = 0x1c2e10u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c2e14: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c2e14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c2e18: 0xae030010  sw          $v1, 0x10($s0)
    ctx->pc = 0x1c2e18u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 3));
    // 0x1c2e1c: 0xae020030  sw          $v0, 0x30($s0)
    ctx->pc = 0x1c2e1cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 2));
    // 0x1c2e20: 0x100000be  b           . + 4 + (0xBE << 2)
    ctx->pc = 0x1C2E20u;
    {
        const bool branch_taken_0x1c2e20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2E24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2E20u;
            // 0x1c2e24: 0xae020038  sw          $v0, 0x38($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2e20) {
            ctx->pc = 0x1C311Cu;
            goto label_1c311c;
        }
    }
    ctx->pc = 0x1C2E28u;
label_1c2e28:
    // 0x1c2e28: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1c2e28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1c2e2c: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x1c2e2cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c2e30: 0xae020034  sw          $v0, 0x34($s0)
    ctx->pc = 0x1c2e30u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 2));
    // 0x1c2e34: 0x8e050034  lw          $a1, 0x34($s0)
    ctx->pc = 0x1c2e34u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 52)));
    // 0x1c2e38: 0x10a3001d  beq         $a1, $v1, . + 4 + (0x1D << 2)
    ctx->pc = 0x1C2E38u;
    {
        const bool branch_taken_0x1c2e38 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c2e38) {
            ctx->pc = 0x1C2EB0u;
            goto label_1c2eb0;
        }
    }
    ctx->pc = 0x1C2E40u;
    // 0x1c2e40: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1c2e40u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1c2e44: 0x10a30013  beq         $a1, $v1, . + 4 + (0x13 << 2)
    ctx->pc = 0x1C2E44u;
    {
        const bool branch_taken_0x1c2e44 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C2E48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2E44u;
            // 0x1c2e48: 0x2402001d  addiu       $v0, $zero, 0x1D (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 29));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2e44) {
            ctx->pc = 0x1C2E94u;
            goto label_1c2e94;
        }
    }
    ctx->pc = 0x1C2E4Cu;
    // 0x1c2e4c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1c2e4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c2e50: 0x10a2000b  beq         $a1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1C2E50u;
    {
        const bool branch_taken_0x1c2e50 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C2E54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2E50u;
            // 0x1c2e54: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2e50) {
            ctx->pc = 0x1C2E80u;
            goto label_1c2e80;
        }
    }
    ctx->pc = 0x1C2E58u;
    // 0x1c2e58: 0x10a40003  beq         $a1, $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C2E58u;
    {
        const bool branch_taken_0x1c2e58 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 4));
        ctx->pc = 0x1C2E5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2E58u;
            // 0x1c2e5c: 0x2403001c  addiu       $v1, $zero, 0x1C (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 28));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2e58) {
            ctx->pc = 0x1C2E68u;
            goto label_1c2e68;
        }
    }
    ctx->pc = 0x1C2E60u;
    // 0x1c2e60: 0x100000ae  b           . + 4 + (0xAE << 2)
    ctx->pc = 0x1C2E60u;
    {
        const bool branch_taken_0x1c2e60 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c2e60) {
            ctx->pc = 0x1C311Cu;
            goto label_1c311c;
        }
    }
    ctx->pc = 0x1C2E68u;
label_1c2e68:
    // 0x1c2e68: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1c2e68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c2e6c: 0xae03002c  sw          $v1, 0x2C($s0)
    ctx->pc = 0x1c2e6cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 3));
    // 0x1c2e70: 0xae020010  sw          $v0, 0x10($s0)
    ctx->pc = 0x1c2e70u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
    // 0x1c2e74: 0xae040030  sw          $a0, 0x30($s0)
    ctx->pc = 0x1c2e74u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 4));
    // 0x1c2e78: 0x100000a8  b           . + 4 + (0xA8 << 2)
    ctx->pc = 0x1C2E78u;
    {
        const bool branch_taken_0x1c2e78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2E7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2E78u;
            // 0x1c2e7c: 0xae040038  sw          $a0, 0x38($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2e78) {
            ctx->pc = 0x1C311Cu;
            goto label_1c311c;
        }
    }
    ctx->pc = 0x1C2E80u;
label_1c2e80:
    // 0x1c2e80: 0xae00002c  sw          $zero, 0x2C($s0)
    ctx->pc = 0x1c2e80u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 0));
    // 0x1c2e84: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c2e84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c2e88: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x1c2e88u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c2e8c: 0x100000a3  b           . + 4 + (0xA3 << 2)
    ctx->pc = 0x1C2E8Cu;
    {
        const bool branch_taken_0x1c2e8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2E90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2E8Cu;
            // 0x1c2e90: 0xae020010  sw          $v0, 0x10($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2e8c) {
            ctx->pc = 0x1C311Cu;
            goto label_1c311c;
        }
    }
    ctx->pc = 0x1C2E94u;
label_1c2e94:
    // 0x1c2e94: 0x24030005  addiu       $v1, $zero, 0x5
    ctx->pc = 0x1c2e94u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c2e98: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x1c2e98u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
    // 0x1c2e9c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c2e9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c2ea0: 0xae030010  sw          $v1, 0x10($s0)
    ctx->pc = 0x1c2ea0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 3));
    // 0x1c2ea4: 0xae020030  sw          $v0, 0x30($s0)
    ctx->pc = 0x1c2ea4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 2));
    // 0x1c2ea8: 0x1000009c  b           . + 4 + (0x9C << 2)
    ctx->pc = 0x1C2EA8u;
    {
        const bool branch_taken_0x1c2ea8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2EACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2EA8u;
            // 0x1c2eac: 0xae020038  sw          $v0, 0x38($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2ea8) {
            ctx->pc = 0x1C311Cu;
            goto label_1c311c;
        }
    }
    ctx->pc = 0x1C2EB0u;
label_1c2eb0:
    // 0x1c2eb0: 0xae00002c  sw          $zero, 0x2C($s0)
    ctx->pc = 0x1c2eb0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 0));
    // 0x1c2eb4: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1c2eb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1c2eb8: 0xa2020002  sb          $v0, 0x2($s0)
    ctx->pc = 0x1c2eb8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c2ebc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c2ebcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c2ec0: 0x10000096  b           . + 4 + (0x96 << 2)
    ctx->pc = 0x1C2EC0u;
    {
        const bool branch_taken_0x1c2ec0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2EC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2EC0u;
            // 0x1c2ec4: 0xae020010  sw          $v0, 0x10($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2ec0) {
            ctx->pc = 0x1C311Cu;
            goto label_1c311c;
        }
    }
    ctx->pc = 0x1C2EC8u;
label_1c2ec8:
    // 0x1c2ec8: 0xc070498  jal         func_1C1260
    ctx->pc = 0x1C2EC8u;
    SET_GPR_U32(ctx, 31, 0x1C2ED0u);
    ctx->pc = 0x1C1260u;
    if (runtime->hasFunction(0x1C1260u)) {
        auto targetFn = runtime->lookupFunction(0x1C1260u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2ED0u; }
        if (ctx->pc != 0x1C2ED0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C1260_0x1c1260(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2ED0u; }
        if (ctx->pc != 0x1C2ED0u) { return; }
    }
    ctx->pc = 0x1C2ED0u;
label_1c2ed0:
    // 0x1c2ed0: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1c2ed0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1c2ed4: 0x10430052  beq         $v0, $v1, . + 4 + (0x52 << 2)
    ctx->pc = 0x1C2ED4u;
    {
        const bool branch_taken_0x1c2ed4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c2ed4) {
            ctx->pc = 0x1C3020u;
            goto label_1c3020;
        }
    }
    ctx->pc = 0x1C2EDCu;
    // 0x1c2edc: 0x2403ff00  addiu       $v1, $zero, -0x100
    ctx->pc = 0x1c2edcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x1c2ee0: 0x1043001d  beq         $v0, $v1, . + 4 + (0x1D << 2)
    ctx->pc = 0x1C2EE0u;
    {
        const bool branch_taken_0x1c2ee0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C2EE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2EE0u;
            // 0x1c2ee4: 0x24030003  addiu       $v1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2ee0) {
            ctx->pc = 0x1C2F58u;
            goto label_1c2f58;
        }
    }
    ctx->pc = 0x1C2EE8u;
    // 0x1c2ee8: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C2EE8u;
    {
        const bool branch_taken_0x1c2ee8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2EECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2EE8u;
            // 0x1c2eec: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2ee8) {
            ctx->pc = 0x1C2EF8u;
            goto label_1c2ef8;
        }
    }
    ctx->pc = 0x1C2EF0u;
    // 0x1c2ef0: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x1C2EF0u;
    {
        const bool branch_taken_0x1c2ef0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2EF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2EF0u;
            // 0x1c2ef4: 0x24040003  addiu       $a0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2ef0) {
            ctx->pc = 0x1C2F7Cu;
            goto label_1c2f7c;
        }
    }
    ctx->pc = 0x1C2EF8u;
label_1c2ef8:
    // 0x1c2ef8: 0xc071570  jal         func_1C55C0
    ctx->pc = 0x1C2EF8u;
    SET_GPR_U32(ctx, 31, 0x1C2F00u);
    ctx->pc = 0x1C55C0u;
    if (runtime->hasFunction(0x1C55C0u)) {
        auto targetFn = runtime->lookupFunction(0x1C55C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2F00u; }
        if (ctx->pc != 0x1C2F00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C55C0_0x1c55c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2F00u; }
        if (ctx->pc != 0x1C2F00u) { return; }
    }
    ctx->pc = 0x1C2F00u;
label_1c2f00:
    // 0x1c2f00: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1C2F00u;
    {
        const bool branch_taken_0x1c2f00 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C2F04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2F00u;
            // 0x1c2f04: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2f00) {
            ctx->pc = 0x1C2F2Cu;
            goto label_1c2f2c;
        }
    }
    ctx->pc = 0x1C2F08u;
    // 0x1c2f08: 0x2402001a  addiu       $v0, $zero, 0x1A
    ctx->pc = 0x1c2f08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 26));
    // 0x1c2f0c: 0xc0704a4  jal         func_1C1290
    ctx->pc = 0x1C2F0Cu;
    SET_GPR_U32(ctx, 31, 0x1C2F14u);
    ctx->pc = 0x1C2F10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2F0Cu;
            // 0x1c2f10: 0xae02002c  sw          $v0, 0x2C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C1290u;
    if (runtime->hasFunction(0x1C1290u)) {
        auto targetFn = runtime->lookupFunction(0x1C1290u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2F14u; }
        if (ctx->pc != 0x1C2F14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C1290_0x1c1290(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2F14u; }
        if (ctx->pc != 0x1C2F14u) { return; }
    }
    ctx->pc = 0x1C2F14u;
label_1c2f14:
    // 0x1c2f14: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1c2f14u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1c2f18: 0x2402003c  addiu       $v0, $zero, 0x3C
    ctx->pc = 0x1c2f18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
    // 0x1c2f1c: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x1c2f1cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c2f20: 0xae000034  sw          $zero, 0x34($s0)
    ctx->pc = 0x1c2f20u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 0));
    // 0x1c2f24: 0x1000003e  b           . + 4 + (0x3E << 2)
    ctx->pc = 0x1C2F24u;
    {
        const bool branch_taken_0x1c2f24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2F28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2F24u;
            // 0x1c2f28: 0xae020010  sw          $v0, 0x10($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2f24) {
            ctx->pc = 0x1C3020u;
            goto label_1c3020;
        }
    }
    ctx->pc = 0x1C2F2Cu;
label_1c2f2c:
    // 0x1c2f2c: 0x24020039  addiu       $v0, $zero, 0x39
    ctx->pc = 0x1c2f2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 57));
    // 0x1c2f30: 0xa0204476  sb          $zero, 0x4476($at)
    ctx->pc = 0x1c2f30u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17526), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c2f34: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x1c2f34u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
    // 0x1c2f38: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1c2f38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c2f3c: 0xa2020002  sb          $v0, 0x2($s0)
    ctx->pc = 0x1c2f3cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c2f40: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1c2f40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c2f44: 0xae020010  sw          $v0, 0x10($s0)
    ctx->pc = 0x1c2f44u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
    // 0x1c2f48: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c2f48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c2f4c: 0xae020030  sw          $v0, 0x30($s0)
    ctx->pc = 0x1c2f4cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 2));
    // 0x1c2f50: 0x10000033  b           . + 4 + (0x33 << 2)
    ctx->pc = 0x1C2F50u;
    {
        const bool branch_taken_0x1c2f50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2F54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2F50u;
            // 0x1c2f54: 0xae020038  sw          $v0, 0x38($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2f50) {
            ctx->pc = 0x1C3020u;
            goto label_1c3020;
        }
    }
    ctx->pc = 0x1C2F58u;
label_1c2f58:
    // 0x1c2f58: 0x24020039  addiu       $v0, $zero, 0x39
    ctx->pc = 0x1c2f58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 57));
    // 0x1c2f5c: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x1c2f5cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c2f60: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x1c2f60u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
    // 0x1c2f64: 0x24030005  addiu       $v1, $zero, 0x5
    ctx->pc = 0x1c2f64u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c2f68: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c2f68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c2f6c: 0xae030010  sw          $v1, 0x10($s0)
    ctx->pc = 0x1c2f6cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 3));
    // 0x1c2f70: 0xae020030  sw          $v0, 0x30($s0)
    ctx->pc = 0x1c2f70u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 2));
    // 0x1c2f74: 0x1000002a  b           . + 4 + (0x2A << 2)
    ctx->pc = 0x1C2F74u;
    {
        const bool branch_taken_0x1c2f74 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2F78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2F74u;
            // 0x1c2f78: 0xae020038  sw          $v0, 0x38($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2f74) {
            ctx->pc = 0x1C3020u;
            goto label_1c3020;
        }
    }
    ctx->pc = 0x1C2F7Cu;
label_1c2f7c:
    // 0x1c2f7c: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1c2f7cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1c2f80: 0xa2040002  sb          $a0, 0x2($s0)
    ctx->pc = 0x1c2f80u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 4));
    // 0x1c2f84: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1c2f84u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1c2f88: 0xae020034  sw          $v0, 0x34($s0)
    ctx->pc = 0x1c2f88u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 2));
    // 0x1c2f8c: 0x8e050034  lw          $a1, 0x34($s0)
    ctx->pc = 0x1c2f8cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 52)));
    // 0x1c2f90: 0x10a3001c  beq         $a1, $v1, . + 4 + (0x1C << 2)
    ctx->pc = 0x1C2F90u;
    {
        const bool branch_taken_0x1c2f90 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        if (branch_taken_0x1c2f90) {
            ctx->pc = 0x1C3004u;
            goto label_1c3004;
        }
    }
    ctx->pc = 0x1C2F98u;
    // 0x1c2f98: 0x10a40013  beq         $a1, $a0, . + 4 + (0x13 << 2)
    ctx->pc = 0x1C2F98u;
    {
        const bool branch_taken_0x1c2f98 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 4));
        ctx->pc = 0x1C2F9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2F98u;
            // 0x1c2f9c: 0x24020039  addiu       $v0, $zero, 0x39 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 57));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2f98) {
            ctx->pc = 0x1C2FE8u;
            goto label_1c2fe8;
        }
    }
    ctx->pc = 0x1C2FA0u;
    // 0x1c2fa0: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1c2fa0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c2fa4: 0x10a2000b  beq         $a1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1C2FA4u;
    {
        const bool branch_taken_0x1c2fa4 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C2FA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2FA4u;
            // 0x1c2fa8: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2fa4) {
            ctx->pc = 0x1C2FD4u;
            goto label_1c2fd4;
        }
    }
    ctx->pc = 0x1C2FACu;
    // 0x1c2fac: 0x10a40003  beq         $a1, $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C2FACu;
    {
        const bool branch_taken_0x1c2fac = (GPR_U64(ctx, 5) == GPR_U64(ctx, 4));
        ctx->pc = 0x1C2FB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2FACu;
            // 0x1c2fb0: 0x2403001c  addiu       $v1, $zero, 0x1C (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 28));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2fac) {
            ctx->pc = 0x1C2FBCu;
            goto label_1c2fbc;
        }
    }
    ctx->pc = 0x1C2FB4u;
    // 0x1c2fb4: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x1C2FB4u;
    {
        const bool branch_taken_0x1c2fb4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c2fb4) {
            ctx->pc = 0x1C3020u;
            goto label_1c3020;
        }
    }
    ctx->pc = 0x1C2FBCu;
label_1c2fbc:
    // 0x1c2fbc: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1c2fbcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c2fc0: 0xae03002c  sw          $v1, 0x2C($s0)
    ctx->pc = 0x1c2fc0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 3));
    // 0x1c2fc4: 0xae020010  sw          $v0, 0x10($s0)
    ctx->pc = 0x1c2fc4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
    // 0x1c2fc8: 0xae040030  sw          $a0, 0x30($s0)
    ctx->pc = 0x1c2fc8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 4));
    // 0x1c2fcc: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1C2FCCu;
    {
        const bool branch_taken_0x1c2fcc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2FD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2FCCu;
            // 0x1c2fd0: 0xae040038  sw          $a0, 0x38($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2fcc) {
            ctx->pc = 0x1C3020u;
            goto label_1c3020;
        }
    }
    ctx->pc = 0x1C2FD4u;
label_1c2fd4:
    // 0x1c2fd4: 0xae00002c  sw          $zero, 0x2C($s0)
    ctx->pc = 0x1c2fd4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 0));
    // 0x1c2fd8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c2fd8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c2fdc: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x1c2fdcu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c2fe0: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1C2FE0u;
    {
        const bool branch_taken_0x1c2fe0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C2FE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2FE0u;
            // 0x1c2fe4: 0xae020010  sw          $v0, 0x10($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2fe0) {
            ctx->pc = 0x1C3020u;
            goto label_1c3020;
        }
    }
    ctx->pc = 0x1C2FE8u;
label_1c2fe8:
    // 0x1c2fe8: 0x24030005  addiu       $v1, $zero, 0x5
    ctx->pc = 0x1c2fe8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c2fec: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x1c2fecu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
    // 0x1c2ff0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c2ff0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c2ff4: 0xae030010  sw          $v1, 0x10($s0)
    ctx->pc = 0x1c2ff4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 3));
    // 0x1c2ff8: 0xae020030  sw          $v0, 0x30($s0)
    ctx->pc = 0x1c2ff8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 2));
    // 0x1c2ffc: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1C2FFCu;
    {
        const bool branch_taken_0x1c2ffc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C3000u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2FFCu;
            // 0x1c3000: 0xae020038  sw          $v0, 0x38($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2ffc) {
            ctx->pc = 0x1C3020u;
            goto label_1c3020;
        }
    }
    ctx->pc = 0x1C3004u;
label_1c3004:
    // 0x1c3004: 0x2402001d  addiu       $v0, $zero, 0x1D
    ctx->pc = 0x1c3004u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 29));
    // 0x1c3008: 0x24030005  addiu       $v1, $zero, 0x5
    ctx->pc = 0x1c3008u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c300c: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x1c300cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
    // 0x1c3010: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c3010u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c3014: 0xae030010  sw          $v1, 0x10($s0)
    ctx->pc = 0x1c3014u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 3));
    // 0x1c3018: 0xae020030  sw          $v0, 0x30($s0)
    ctx->pc = 0x1c3018u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 2));
    // 0x1c301c: 0xae020038  sw          $v0, 0x38($s0)
    ctx->pc = 0x1c301cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 2));
label_1c3020:
    // 0x1c3020: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x1c3020u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x1c3024: 0x8c224170  lw          $v0, 0x4170($at)
    ctx->pc = 0x1c3024u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16752)));
    // 0x1c3028: 0x1000003c  b           . + 4 + (0x3C << 2)
    ctx->pc = 0x1C3028u;
    {
        const bool branch_taken_0x1c3028 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C302Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3028u;
            // 0x1c302c: 0xae020014  sw          $v0, 0x14($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3028) {
            ctx->pc = 0x1C311Cu;
            goto label_1c311c;
        }
    }
    ctx->pc = 0x1C3030u;
label_1c3030:
    // 0x1c3030: 0x9603000a  lhu         $v1, 0xA($s0)
    ctx->pc = 0x1c3030u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 10)));
    // 0x1c3034: 0x30620010  andi        $v0, $v1, 0x10
    ctx->pc = 0x1c3034u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)16);
    // 0x1c3038: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1C3038u;
    {
        const bool branch_taken_0x1c3038 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c3038) {
            ctx->pc = 0x1C3078u;
            goto label_1c3078;
        }
    }
    ctx->pc = 0x1C3040u;
    // 0x1c3040: 0xc07165c  jal         func_1C5970
    ctx->pc = 0x1C3040u;
    SET_GPR_U32(ctx, 31, 0x1C3048u);
    ctx->pc = 0x1C5970u;
    if (runtime->hasFunction(0x1C5970u)) {
        auto targetFn = runtime->lookupFunction(0x1C5970u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3048u; }
        if (ctx->pc != 0x1C3048u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C5970_0x1c5970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3048u; }
        if (ctx->pc != 0x1C3048u) { return; }
    }
    ctx->pc = 0x1C3048u;
label_1c3048:
    // 0x1c3048: 0xae000030  sw          $zero, 0x30($s0)
    ctx->pc = 0x1c3048u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
    // 0x1c304c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1c304cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c3050: 0x8e020038  lw          $v0, 0x38($s0)
    ctx->pc = 0x1c3050u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x1c3054: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C3054u;
    {
        const bool branch_taken_0x1c3054 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1c3054) {
            ctx->pc = 0x1C3064u;
            goto label_1c3064;
        }
    }
    ctx->pc = 0x1C305Cu;
    // 0x1c305c: 0x1000002f  b           . + 4 + (0x2F << 2)
    ctx->pc = 0x1C305Cu;
    {
        const bool branch_taken_0x1c305c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C3060u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C305Cu;
            // 0x1c3060: 0xa2000002  sb          $zero, 0x2($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c305c) {
            ctx->pc = 0x1C311Cu;
            goto label_1c311c;
        }
    }
    ctx->pc = 0x1C3064u;
label_1c3064:
    // 0x1c3064: 0xae00002c  sw          $zero, 0x2C($s0)
    ctx->pc = 0x1c3064u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 0));
    // 0x1c3068: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1c3068u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1c306c: 0xa2020002  sb          $v0, 0x2($s0)
    ctx->pc = 0x1c306cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c3070: 0x1000002a  b           . + 4 + (0x2A << 2)
    ctx->pc = 0x1C3070u;
    {
        const bool branch_taken_0x1c3070 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C3074u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3070u;
            // 0x1c3074: 0xae030010  sw          $v1, 0x10($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3070) {
            ctx->pc = 0x1C311Cu;
            goto label_1c311c;
        }
    }
    ctx->pc = 0x1C3078u;
label_1c3078:
    // 0x1c3078: 0x8e020010  lw          $v0, 0x10($s0)
    ctx->pc = 0x1c3078u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1c307c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1C307Cu;
    {
        const bool branch_taken_0x1c307c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c307c) {
            ctx->pc = 0x1C3090u;
            goto label_1c3090;
        }
    }
    ctx->pc = 0x1C3084u;
    // 0x1c3084: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1c3084u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1c3088: 0x10000024  b           . + 4 + (0x24 << 2)
    ctx->pc = 0x1C3088u;
    {
        const bool branch_taken_0x1c3088 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C308Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3088u;
            // 0x1c308c: 0xae020010  sw          $v0, 0x10($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3088) {
            ctx->pc = 0x1C311Cu;
            goto label_1c311c;
        }
    }
    ctx->pc = 0x1C3090u;
label_1c3090:
    // 0x1c3090: 0x30620008  andi        $v0, $v1, 0x8
    ctx->pc = 0x1c3090u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)8);
    // 0x1c3094: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1C3094u;
    {
        const bool branch_taken_0x1c3094 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C3098u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3094u;
            // 0x1c3098: 0x30620004  andi        $v0, $v1, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)4);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3094) {
            ctx->pc = 0x1C30ACu;
            goto label_1c30ac;
        }
    }
    ctx->pc = 0x1C309Cu;
    // 0x1c309c: 0x8e020038  lw          $v0, 0x38($s0)
    ctx->pc = 0x1c309cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x1c30a0: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1C30A0u;
    {
        const bool branch_taken_0x1c30a0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c30a0) {
            ctx->pc = 0x1C30C4u;
            goto label_1c30c4;
        }
    }
    ctx->pc = 0x1C30A8u;
    // 0x1c30a8: 0x30620004  andi        $v0, $v1, 0x4
    ctx->pc = 0x1c30a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)4);
label_1c30ac:
    // 0x1c30ac: 0x1040001b  beqz        $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x1C30ACu;
    {
        const bool branch_taken_0x1c30ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c30ac) {
            ctx->pc = 0x1C311Cu;
            goto label_1c311c;
        }
    }
    ctx->pc = 0x1C30B4u;
    // 0x1c30b4: 0x8e030038  lw          $v1, 0x38($s0)
    ctx->pc = 0x1c30b4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x1c30b8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c30b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c30bc: 0x14620017  bne         $v1, $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x1C30BCu;
    {
        const bool branch_taken_0x1c30bc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1c30bc) {
            ctx->pc = 0x1C311Cu;
            goto label_1c311c;
        }
    }
    ctx->pc = 0x1C30C4u;
label_1c30c4:
    // 0x1c30c4: 0xc071660  jal         func_1C5980
    ctx->pc = 0x1C30C4u;
    SET_GPR_U32(ctx, 31, 0x1C30CCu);
    ctx->pc = 0x1C5980u;
    if (runtime->hasFunction(0x1C5980u)) {
        auto targetFn = runtime->lookupFunction(0x1C5980u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C30CCu; }
        if (ctx->pc != 0x1C30CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C5980_0x1c5980(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C30CCu; }
        if (ctx->pc != 0x1C30CCu) { return; }
    }
    ctx->pc = 0x1C30CCu;
label_1c30cc:
    // 0x1c30cc: 0x8e030038  lw          $v1, 0x38($s0)
    ctx->pc = 0x1c30ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x1c30d0: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1c30d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c30d4: 0x38630001  xori        $v1, $v1, 0x1
    ctx->pc = 0x1c30d4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)1);
    // 0x1c30d8: 0xae030038  sw          $v1, 0x38($s0)
    ctx->pc = 0x1c30d8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 3));
    // 0x1c30dc: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1C30DCu;
    {
        const bool branch_taken_0x1c30dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C30E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C30DCu;
            // 0x1c30e0: 0xae020010  sw          $v0, 0x10($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c30dc) {
            ctx->pc = 0x1C311Cu;
            goto label_1c311c;
        }
    }
    ctx->pc = 0x1C30E4u;
label_1c30e4:
    // 0x1c30e4: 0x8e020010  lw          $v0, 0x10($s0)
    ctx->pc = 0x1c30e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1c30e8: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1c30e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1c30ec: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1C30ECu;
    {
        const bool branch_taken_0x1c30ec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C30F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C30ECu;
            // 0x1c30f0: 0xae020010  sw          $v0, 0x10($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c30ec) {
            ctx->pc = 0x1C311Cu;
            goto label_1c311c;
        }
    }
    ctx->pc = 0x1C30F4u;
    // 0x1c30f4: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1C30F4u;
    {
        const bool branch_taken_0x1c30f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C30F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C30F4u;
            // 0x1c30f8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c30f4) {
            ctx->pc = 0x1C3134u;
            goto label_1c3134;
        }
    }
    ctx->pc = 0x1C30FCu;
label_1c30fc:
    // 0x1c30fc: 0x9602000a  lhu         $v0, 0xA($s0)
    ctx->pc = 0x1c30fcu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 10)));
    // 0x1c3100: 0x3042fff0  andi        $v0, $v0, 0xFFF0
    ctx->pc = 0x1c3100u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65520);
    // 0x1c3104: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1C3104u;
    {
        const bool branch_taken_0x1c3104 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c3104) {
            ctx->pc = 0x1C311Cu;
            goto label_1c311c;
        }
    }
    ctx->pc = 0x1C310Cu;
    // 0x1c310c: 0xc07165c  jal         func_1C5970
    ctx->pc = 0x1C310Cu;
    SET_GPR_U32(ctx, 31, 0x1C3114u);
    ctx->pc = 0x1C5970u;
    if (runtime->hasFunction(0x1C5970u)) {
        auto targetFn = runtime->lookupFunction(0x1C5970u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3114u; }
        if (ctx->pc != 0x1C3114u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C5970_0x1c5970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3114u; }
        if (ctx->pc != 0x1C3114u) { return; }
    }
    ctx->pc = 0x1C3114u;
label_1c3114:
    // 0x1c3114: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1C3114u;
    {
        const bool branch_taken_0x1c3114 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C3118u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3114u;
            // 0x1c3118: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c3114) {
            ctx->pc = 0x1C3134u;
            goto label_1c3134;
        }
    }
    ctx->pc = 0x1C311Cu;
label_1c311c:
    // 0x1c311c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1c311cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1c3120:
    // 0x1c3120: 0xc0713c4  jal         func_1C4F10
    ctx->pc = 0x1C3120u;
    SET_GPR_U32(ctx, 31, 0x1C3128u);
    ctx->pc = 0x1C4F10u;
    if (runtime->hasFunction(0x1C4F10u)) {
        auto targetFn = runtime->lookupFunction(0x1C4F10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3128u; }
        if (ctx->pc != 0x1C3128u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C4F10_0x1c4f10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3128u; }
        if (ctx->pc != 0x1C3128u) { return; }
    }
    ctx->pc = 0x1C3128u;
label_1c3128:
    // 0x1c3128: 0xc07146c  jal         func_1C51B0
    ctx->pc = 0x1C3128u;
    SET_GPR_U32(ctx, 31, 0x1C3130u);
    ctx->pc = 0x1C312Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C3128u;
            // 0x1c312c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C51B0u;
    if (runtime->hasFunction(0x1C51B0u)) {
        auto targetFn = runtime->lookupFunction(0x1C51B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3130u; }
        if (ctx->pc != 0x1C3130u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C51B0_0x1c51b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C3130u; }
        if (ctx->pc != 0x1C3130u) { return; }
    }
    ctx->pc = 0x1C3130u;
label_1c3130:
    // 0x1c3130: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c3130u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1c3134:
    // 0x1c3134: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c3134u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c3138: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c3138u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c313c: 0x3e00008  jr          $ra
    ctx->pc = 0x1C313Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C3140u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C313Cu;
            // 0x1c3140: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C2D38u: goto label_1c2d38;
            case 0x1C2D58u: goto label_1c2d58;
            case 0x1C2D60u: goto label_1c2d60;
            case 0x1C2DA4u: goto label_1c2da4;
            case 0x1C2DBCu: goto label_1c2dbc;
            case 0x1C2DE4u: goto label_1c2de4;
            case 0x1C2DF0u: goto label_1c2df0;
            case 0x1C2E04u: goto label_1c2e04;
            case 0x1C2E28u: goto label_1c2e28;
            case 0x1C2E68u: goto label_1c2e68;
            case 0x1C2E80u: goto label_1c2e80;
            case 0x1C2E94u: goto label_1c2e94;
            case 0x1C2EB0u: goto label_1c2eb0;
            case 0x1C2EC8u: goto label_1c2ec8;
            case 0x1C2ED0u: goto label_1c2ed0;
            case 0x1C2EF8u: goto label_1c2ef8;
            case 0x1C2F00u: goto label_1c2f00;
            case 0x1C2F14u: goto label_1c2f14;
            case 0x1C2F2Cu: goto label_1c2f2c;
            case 0x1C2F58u: goto label_1c2f58;
            case 0x1C2F7Cu: goto label_1c2f7c;
            case 0x1C2FBCu: goto label_1c2fbc;
            case 0x1C2FD4u: goto label_1c2fd4;
            case 0x1C2FE8u: goto label_1c2fe8;
            case 0x1C3004u: goto label_1c3004;
            case 0x1C3020u: goto label_1c3020;
            case 0x1C3030u: goto label_1c3030;
            case 0x1C3048u: goto label_1c3048;
            case 0x1C3064u: goto label_1c3064;
            case 0x1C3078u: goto label_1c3078;
            case 0x1C3090u: goto label_1c3090;
            case 0x1C30ACu: goto label_1c30ac;
            case 0x1C30C4u: goto label_1c30c4;
            case 0x1C30CCu: goto label_1c30cc;
            case 0x1C30E4u: goto label_1c30e4;
            case 0x1C30FCu: goto label_1c30fc;
            case 0x1C3114u: goto label_1c3114;
            case 0x1C311Cu: goto label_1c311c;
            case 0x1C3120u: goto label_1c3120;
            case 0x1C3128u: goto label_1c3128;
            case 0x1C3130u: goto label_1c3130;
            case 0x1C3134u: goto label_1c3134;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C3144u;
    // 0x1c3144: 0x0  nop
    ctx->pc = 0x1c3144u;
    // NOP
    // 0x1c3148: 0x0  nop
    ctx->pc = 0x1c3148u;
    // NOP
    // 0x1c314c: 0x0  nop
    ctx->pc = 0x1c314cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
