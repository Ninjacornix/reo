#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00139D00
// Address: 0x139d00 - 0x139ea4
void sub_00139D00_0x139d00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00139D00_0x139d00");
#endif

    switch (ctx->pc) {
        case 0x139d60u: goto label_139d60;
        case 0x139d90u: goto label_139d90;
        case 0x139df0u: goto label_139df0;
        case 0x139e10u: goto label_139e10;
        case 0x139e20u: goto label_139e20;
        case 0x139e40u: goto label_139e40;
        case 0x139e48u: goto label_139e48;
        case 0x139e50u: goto label_139e50;
        case 0x139e58u: goto label_139e58;
        case 0x139e60u: goto label_139e60;
        default: break;
    }

    ctx->pc = 0x139d00u;

    // 0x139d00: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x139d00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x139d04: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x139d04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x139d08: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x139d08u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x139d0c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x139d0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x139d10: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x139d10u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x139d14: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x139d14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x139d18: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x139d18u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x139d1c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x139d1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x139d20: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x139D20u;
    {
        const bool branch_taken_0x139d20 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x139D24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139D20u;
            // 0x139d24: 0xffbf0020  sd          $ra, 0x20($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139d20) {
            ctx->pc = 0x139D38u;
            goto label_139d38;
        }
    }
    ctx->pc = 0x139D28u;
    // 0x139d28: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x139d28u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x139d2c: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x139D2Cu;
    {
        const bool branch_taken_0x139d2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x139D30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139D2Cu;
            // 0x139d30: 0x24a5cbe8  addiu       $a1, $a1, -0x3418 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294953960));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139d2c) {
            ctx->pc = 0x139D58u;
            goto label_139d58;
        }
    }
    ctx->pc = 0x139D34u;
    // 0x139d34: 0x0  nop
    ctx->pc = 0x139d34u;
    // NOP
label_139d38:
    // 0x139d38: 0x6410003  bgez        $s2, . + 4 + (0x3 << 2)
    ctx->pc = 0x139D38u;
    {
        const bool branch_taken_0x139d38 = (GPR_S64(ctx, 18) >= 0);
        ctx->pc = 0x139D3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139D38u;
            // 0x139d3c: 0x3c050024  lui         $a1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139d38) {
            ctx->pc = 0x139D48u;
            goto label_139d48;
        }
    }
    ctx->pc = 0x139D40u;
    // 0x139d40: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x139D40u;
    {
        const bool branch_taken_0x139d40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x139D44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139D40u;
            // 0x139d44: 0x24a5cc00  addiu       $a1, $a1, -0x3400 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294953984));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139d40) {
            ctx->pc = 0x139D58u;
            goto label_139d58;
        }
    }
    ctx->pc = 0x139D48u;
label_139d48:
    // 0x139d48: 0x56200007  bnel        $s1, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x139D48u;
    {
        const bool branch_taken_0x139d48 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        if (branch_taken_0x139d48) {
            ctx->pc = 0x139D4Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x139D48u;
            // 0x139d4c: 0x82030002  lb          $v1, 0x2($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x139D68u;
            goto label_139d68;
        }
    }
    ctx->pc = 0x139D50u;
    // 0x139d50: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x139d50u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x139d54: 0x24a5cc20  addiu       $a1, $a1, -0x33E0
    ctx->pc = 0x139d54u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294954016));
label_139d58:
    // 0x139d58: 0xc04e57e  jal         func_1395F8
    ctx->pc = 0x139D58u;
    SET_GPR_U32(ctx, 31, 0x139D60u);
    ctx->pc = 0x1395F8u;
    if (runtime->hasFunction(0x1395F8u)) {
        auto targetFn = runtime->lookupFunction(0x1395F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139D60u; }
        if (ctx->pc != 0x139D60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001395F8_0x1395f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139D60u; }
        if (ctx->pc != 0x139D60u) { return; }
    }
    ctx->pc = 0x139D60u;
label_139d60:
    // 0x139d60: 0x10000049  b           . + 4 + (0x49 << 2)
    ctx->pc = 0x139D60u;
    {
        const bool branch_taken_0x139d60 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x139D64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139D60u;
            // 0x139d64: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139d60) {
            ctx->pc = 0x139E88u;
            goto label_139e88;
        }
    }
    ctx->pc = 0x139D68u;
label_139d68:
    // 0x139d68: 0x24130002  addiu       $s3, $zero, 0x2
    ctx->pc = 0x139d68u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x139d6c: 0x10730046  beq         $v1, $s3, . + 4 + (0x46 << 2)
    ctx->pc = 0x139D6Cu;
    {
        const bool branch_taken_0x139d6c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 19));
        ctx->pc = 0x139D70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139D6Cu;
            // 0x139d70: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139d6c) {
            ctx->pc = 0x139E88u;
            goto label_139e88;
        }
    }
    ctx->pc = 0x139D74u;
    // 0x139d74: 0x16400004  bnez        $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x139D74u;
    {
        const bool branch_taken_0x139d74 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        ctx->pc = 0x139D78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139D74u;
            // 0x139d78: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139d74) {
            ctx->pc = 0x139D88u;
            goto label_139d88;
        }
    }
    ctx->pc = 0x139D7Cu;
    // 0x139d7c: 0x10000042  b           . + 4 + (0x42 << 2)
    ctx->pc = 0x139D7Cu;
    {
        const bool branch_taken_0x139d7c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x139D80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139D7Cu;
            // 0x139d80: 0xa2030002  sb          $v1, 0x2($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139d7c) {
            ctx->pc = 0x139E88u;
            goto label_139e88;
        }
    }
    ctx->pc = 0x139D84u;
    // 0x139d84: 0x0  nop
    ctx->pc = 0x139d84u;
    // NOP
label_139d88:
    // 0x139d88: 0xc04dcd0  jal         func_137340
    ctx->pc = 0x139D88u;
    SET_GPR_U32(ctx, 31, 0x139D90u);
    ctx->pc = 0x137340u;
    if (runtime->hasFunction(0x137340u)) {
        auto targetFn = runtime->lookupFunction(0x137340u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139D90u; }
        if (ctx->pc != 0x139D90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00137340_0x137340(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139D90u; }
        if (ctx->pc != 0x139D90u) { return; }
    }
    ctx->pc = 0x139D90u;
label_139d90:
    // 0x139d90: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x139d90u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x139d94: 0x1060003c  beqz        $v1, . + 4 + (0x3C << 2)
    ctx->pc = 0x139D94u;
    {
        const bool branch_taken_0x139d94 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x139D98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139D94u;
            // 0x139d98: 0xae03001c  sw          $v1, 0x1C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139d94) {
            ctx->pc = 0x139E88u;
            goto label_139e88;
        }
    }
    ctx->pc = 0x139D9Cu;
    // 0x139d9c: 0x3c060022  lui         $a2, 0x22
    ctx->pc = 0x139d9cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)34 << 16));
    // 0x139da0: 0x8e02000c  lw          $v0, 0xC($s0)
    ctx->pc = 0x139da0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x139da4: 0x24c6d8e0  addiu       $a2, $a2, -0x2720
    ctx->pc = 0x139da4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294957280));
    // 0x139da8: 0x8e030008  lw          $v1, 0x8($s0)
    ctx->pc = 0x139da8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x139dac: 0x90c50000  lbu         $a1, 0x0($a2)
    ctx->pc = 0x139dacu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x139db0: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x139db0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x139db4: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x139db4u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x139db8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x139db8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x139dbc: 0xa2050044  sb          $a1, 0x44($s0)
    ctx->pc = 0x139dbcu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 68), (uint8_t)GPR_U32(ctx, 5));
    // 0x139dc0: 0x243102a  slt         $v0, $s2, $v1
    ctx->pc = 0x139dc0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x139dc4: 0x62380a  movz        $a3, $v1, $v0
    ctx->pc = 0x139dc4u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 7, GPR_VEC(ctx, 3));
    // 0x139dc8: 0x90c80001  lbu         $t0, 0x1($a2)
    ctx->pc = 0x139dc8u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 1)));
    // 0x139dcc: 0x72ac0  sll         $a1, $a3, 11
    ctx->pc = 0x139dccu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 7), 11));
    // 0x139dd0: 0x2252821  addu        $a1, $s1, $a1
    ctx->pc = 0x139dd0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 5)));
    // 0x139dd4: 0xa2080045  sb          $t0, 0x45($s0)
    ctx->pc = 0x139dd4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 69), (uint8_t)GPR_U32(ctx, 8));
    // 0x139dd8: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x139dd8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x139ddc: 0x90c20002  lbu         $v0, 0x2($a2)
    ctx->pc = 0x139ddcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 2)));
    // 0x139de0: 0xae070010  sw          $a3, 0x10($s0)
    ctx->pc = 0x139de0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 7));
    // 0x139de4: 0xa2020046  sb          $v0, 0x46($s0)
    ctx->pc = 0x139de4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 70), (uint8_t)GPR_U32(ctx, 2));
    // 0x139de8: 0xc045416  jal         func_115058
    ctx->pc = 0x139DE8u;
    SET_GPR_U32(ctx, 31, 0x139DF0u);
    ctx->pc = 0x139DECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x139DE8u;
            // 0x139dec: 0xae110018  sw          $s1, 0x18($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x115058u;
    if (runtime->hasFunction(0x115058u)) {
        auto targetFn = runtime->lookupFunction(0x115058u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139DF0u; }
        if (ctx->pc != 0x139DF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00115058_0x115058(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139DF0u; }
        if (ctx->pc != 0x139DF0u) { return; }
    }
    ctx->pc = 0x139DF0u;
label_139df0:
    // 0x139df0: 0x8e020020  lw          $v0, 0x20($s0)
    ctx->pc = 0x139df0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x139df4: 0x8e05000c  lw          $a1, 0xC($s0)
    ctx->pc = 0x139df4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x139df8: 0x26080044  addiu       $t0, $s0, 0x44
    ctx->pc = 0x139df8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 16), 68));
    // 0x139dfc: 0x8e04001c  lw          $a0, 0x1C($s0)
    ctx->pc = 0x139dfcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x139e00: 0x8e060010  lw          $a2, 0x10($s0)
    ctx->pc = 0x139e00u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x139e04: 0x452821  addu        $a1, $v0, $a1
    ctx->pc = 0x139e04u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x139e08: 0xc04dd1a  jal         func_137468
    ctx->pc = 0x139E08u;
    SET_GPR_U32(ctx, 31, 0x139E10u);
    ctx->pc = 0x139E0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x139E08u;
            // 0x139e0c: 0x8e070018  lw          $a3, 0x18($s0) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x137468u;
    if (runtime->hasFunction(0x137468u)) {
        auto targetFn = runtime->lookupFunction(0x137468u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139E10u; }
        if (ctx->pc != 0x139E10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00137468_0x137468(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139E10u; }
        if (ctx->pc != 0x139E10u) { return; }
    }
    ctx->pc = 0x139E10u;
label_139e10:
    // 0x139e10: 0x54400005  bnel        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x139E10u;
    {
        const bool branch_taken_0x139e10 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x139e10) {
            ctx->pc = 0x139E14u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x139E10u;
            // 0x139e14: 0x3c020022  lui         $v0, 0x22 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x139E28u;
            goto label_139e28;
        }
    }
    ctx->pc = 0x139E18u;
    // 0x139e18: 0xc04dcf2  jal         func_1373C8
    ctx->pc = 0x139E18u;
    SET_GPR_U32(ctx, 31, 0x139E20u);
    ctx->pc = 0x139E1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x139E18u;
            // 0x139e1c: 0x8e04001c  lw          $a0, 0x1C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1373C8u;
    if (runtime->hasFunction(0x1373C8u)) {
        auto targetFn = runtime->lookupFunction(0x1373C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139E20u; }
        if (ctx->pc != 0x139E20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001373C8_0x1373c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139E20u; }
        if (ctx->pc != 0x139E20u) { return; }
    }
    ctx->pc = 0x139E20u;
label_139e20:
    // 0x139e20: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x139E20u;
    {
        const bool branch_taken_0x139e20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x139E24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139E20u;
            // 0x139e24: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139e20) {
            ctx->pc = 0x139E88u;
            goto label_139e88;
        }
    }
    ctx->pc = 0x139E28u;
label_139e28:
    // 0x139e28: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x139e28u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x139e2c: 0x8c51d8e4  lw          $s1, -0x271C($v0)
    ctx->pc = 0x139e2cu;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294957284)));
    // 0x139e30: 0x56230013  bnel        $s1, $v1, . + 4 + (0x13 << 2)
    ctx->pc = 0x139E30u;
    {
        const bool branch_taken_0x139e30 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 3));
        if (branch_taken_0x139e30) {
            ctx->pc = 0x139E34u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x139E30u;
            // 0x139e34: 0xa2130002  sb          $s3, 0x2($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 19));
        ctx->in_delay_slot = false;
            ctx->pc = 0x139E80u;
            goto label_139e80;
        }
    }
    ctx->pc = 0x139E38u;
    // 0x139e38: 0xc04035e  jal         func_100D78
    ctx->pc = 0x139E38u;
    SET_GPR_U32(ctx, 31, 0x139E40u);
    ctx->pc = 0x139E3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x139E38u;
            // 0x139e3c: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100D78u;
    if (runtime->hasFunction(0x100D78u)) {
        auto targetFn = runtime->lookupFunction(0x100D78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139E40u; }
        if (ctx->pc != 0x139E40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00100D78_0x100d78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139E40u; }
        if (ctx->pc != 0x139E40u) { return; }
    }
    ctx->pc = 0x139E40u;
label_139e40:
    // 0x139e40: 0xc04dfa4  jal         func_137E90
    ctx->pc = 0x139E40u;
    SET_GPR_U32(ctx, 31, 0x139E48u);
    ctx->pc = 0x137E90u;
    if (runtime->hasFunction(0x137E90u)) {
        auto targetFn = runtime->lookupFunction(0x137E90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139E48u; }
        if (ctx->pc != 0x139E48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00137E90_0x137e90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139E48u; }
        if (ctx->pc != 0x139E48u) { return; }
    }
    ctx->pc = 0x139E48u;
label_139e48:
    // 0x139e48: 0xc04df60  jal         func_137D80
    ctx->pc = 0x139E48u;
    SET_GPR_U32(ctx, 31, 0x139E50u);
    ctx->pc = 0x137D80u;
    if (runtime->hasFunction(0x137D80u)) {
        auto targetFn = runtime->lookupFunction(0x137D80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139E50u; }
        if (ctx->pc != 0x139E50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00137D80_0x137d80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139E50u; }
        if (ctx->pc != 0x139E50u) { return; }
    }
    ctx->pc = 0x139E50u;
label_139e50:
    // 0x139e50: 0xc04ddce  jal         func_137738
    ctx->pc = 0x139E50u;
    SET_GPR_U32(ctx, 31, 0x139E58u);
    ctx->pc = 0x139E54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x139E50u;
            // 0x139e54: 0x8e04001c  lw          $a0, 0x1C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x137738u;
    if (runtime->hasFunction(0x137738u)) {
        auto targetFn = runtime->lookupFunction(0x137738u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139E58u; }
        if (ctx->pc != 0x139E58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00137738_0x137738(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139E58u; }
        if (ctx->pc != 0x139E58u) { return; }
    }
    ctx->pc = 0x139E58u;
label_139e58:
    // 0x139e58: 0xc04dcf2  jal         func_1373C8
    ctx->pc = 0x139E58u;
    SET_GPR_U32(ctx, 31, 0x139E60u);
    ctx->pc = 0x139E5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x139E58u;
            // 0x139e5c: 0x8e04001c  lw          $a0, 0x1C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1373C8u;
    if (runtime->hasFunction(0x1373C8u)) {
        auto targetFn = runtime->lookupFunction(0x1373C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139E60u; }
        if (ctx->pc != 0x139E60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001373C8_0x1373c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139E60u; }
        if (ctx->pc != 0x139E60u) { return; }
    }
    ctx->pc = 0x139E60u;
label_139e60:
    // 0x139e60: 0xae00001c  sw          $zero, 0x1C($s0)
    ctx->pc = 0x139e60u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 0));
    // 0x139e64: 0x8e02000c  lw          $v0, 0xC($s0)
    ctx->pc = 0x139e64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x139e68: 0x8e030010  lw          $v1, 0x10($s0)
    ctx->pc = 0x139e68u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x139e6c: 0xae120014  sw          $s2, 0x14($s0)
    ctx->pc = 0x139e6cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 18));
    // 0x139e70: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x139e70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x139e74: 0xa2110002  sb          $s1, 0x2($s0)
    ctx->pc = 0x139e74u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 17));
    // 0x139e78: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x139E78u;
    {
        const bool branch_taken_0x139e78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x139E7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139E78u;
            // 0x139e7c: 0xae02000c  sw          $v0, 0xC($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139e78) {
            ctx->pc = 0x139E84u;
            goto label_139e84;
        }
    }
    ctx->pc = 0x139E80u;
label_139e80:
    // 0x139e80: 0x8e030010  lw          $v1, 0x10($s0)
    ctx->pc = 0x139e80u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
label_139e84:
    // 0x139e84: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x139e84u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
label_139e88:
    // 0x139e88: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x139e88u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x139e8c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x139e8cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x139e90: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x139e90u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x139e94: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x139e94u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x139e98: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x139e98u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x139e9c: 0x3e00008  jr          $ra
    ctx->pc = 0x139E9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x139EA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139E9Cu;
            // 0x139ea0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x139D38u: goto label_139d38;
            case 0x139D48u: goto label_139d48;
            case 0x139D58u: goto label_139d58;
            case 0x139D60u: goto label_139d60;
            case 0x139D68u: goto label_139d68;
            case 0x139D88u: goto label_139d88;
            case 0x139D90u: goto label_139d90;
            case 0x139DF0u: goto label_139df0;
            case 0x139E10u: goto label_139e10;
            case 0x139E20u: goto label_139e20;
            case 0x139E28u: goto label_139e28;
            case 0x139E40u: goto label_139e40;
            case 0x139E48u: goto label_139e48;
            case 0x139E50u: goto label_139e50;
            case 0x139E58u: goto label_139e58;
            case 0x139E60u: goto label_139e60;
            case 0x139E80u: goto label_139e80;
            case 0x139E84u: goto label_139e84;
            case 0x139E88u: goto label_139e88;
            default: break;
        }
        return;
    }
    ctx->pc = 0x139EA4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
