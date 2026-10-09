#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00118CF8
// Address: 0x118cf8 - 0x118e78
void sub_00118CF8_0x118cf8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00118CF8_0x118cf8");
#endif

    switch (ctx->pc) {
        case 0x118d20u: goto label_118d20;
        case 0x118d2cu: goto label_118d2c;
        case 0x118d44u: goto label_118d44;
        case 0x118d68u: goto label_118d68;
        case 0x118da0u: goto label_118da0;
        case 0x118decu: goto label_118dec;
        case 0x118dfcu: goto label_118dfc;
        case 0x118e04u: goto label_118e04;
        case 0x118e1cu: goto label_118e1c;
        case 0x118e2cu: goto label_118e2c;
        case 0x118e3cu: goto label_118e3c;
        case 0x118e44u: goto label_118e44;
        default: break;
    }

    ctx->pc = 0x118cf8u;

    // 0x118cf8: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x118cf8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x118cfc: 0xffb40080  sd          $s4, 0x80($sp)
    ctx->pc = 0x118cfcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 20));
    // 0x118d00: 0xffb20060  sd          $s2, 0x60($sp)
    ctx->pc = 0x118d00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 18));
    // 0x118d04: 0x3c140026  lui         $s4, 0x26
    ctx->pc = 0x118d04u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)38 << 16));
    // 0x118d08: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x118d08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x118d0c: 0x2692ca40  addiu       $s2, $s4, -0x35C0
    ctx->pc = 0x118d0cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 20), 4294953536));
    // 0x118d10: 0xffbf0090  sd          $ra, 0x90($sp)
    ctx->pc = 0x118d10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 31));
    // 0x118d14: 0xffb30070  sd          $s3, 0x70($sp)
    ctx->pc = 0x118d14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 19));
    // 0x118d18: 0xc04607e  jal         func_1181F8
    ctx->pc = 0x118D18u;
    SET_GPR_U32(ctx, 31, 0x118D20u);
    ctx->pc = 0x118D1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118D18u;
            // 0x118d1c: 0xffb10050  sd          $s1, 0x50($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1181F8u;
    if (runtime->hasFunction(0x1181F8u)) {
        auto targetFn = runtime->lookupFunction(0x1181F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118D20u; }
        if (ctx->pc != 0x118D20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001181F8_0x1181f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118D20u; }
        if (ctx->pc != 0x118D20u) { return; }
    }
    ctx->pc = 0x118D20u;
label_118d20:
    // 0x118d20: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x118d20u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118d24: 0xc04619c  jal         func_118670
    ctx->pc = 0x118D24u;
    SET_GPR_U32(ctx, 31, 0x118D2Cu);
    ctx->pc = 0x118D28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118D24u;
            // 0x118d28: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118670u;
    if (runtime->hasFunction(0x118670u)) {
        auto targetFn = runtime->lookupFunction(0x118670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118D2Cu; }
        if (ctx->pc != 0x118D2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118670_0x118670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118D2Cu; }
        if (ctx->pc != 0x118D2Cu) { return; }
    }
    ctx->pc = 0x118D2Cu;
label_118d2c:
    // 0x118d2c: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x118d2cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x118d30: 0x8c629ddc  lw          $v0, -0x6224($v1)
    ctx->pc = 0x118d30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294942172)));
    // 0x118d34: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x118D34u;
    {
        const bool branch_taken_0x118d34 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x118d34) {
            ctx->pc = 0x118D4Cu;
            goto label_118d4c;
        }
    }
    ctx->pc = 0x118D3Cu;
    // 0x118d3c: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x118D3Cu;
    SET_GPR_U32(ctx, 31, 0x118D44u);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118D44u; }
        if (ctx->pc != 0x118D44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118D44u; }
        if (ctx->pc != 0x118D44u) { return; }
    }
    ctx->pc = 0x118D44u;
label_118d44:
    // 0x118d44: 0x10000043  b           . + 4 + (0x43 << 2)
    ctx->pc = 0x118D44u;
    {
        const bool branch_taken_0x118d44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x118D48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118D44u;
            // 0x118d48: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118d44) {
            ctx->pc = 0x118E54u;
            goto label_118e54;
        }
    }
    ctx->pc = 0x118D4Cu;
label_118d4c:
    // 0x118d4c: 0x12000004  beqz        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x118D4Cu;
    {
        const bool branch_taken_0x118d4c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x118d4c) {
            ctx->pc = 0x118D60u;
            goto label_118d60;
        }
    }
    ctx->pc = 0x118D54u;
    // 0x118d54: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x118d54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x118d58: 0x54400005  bnel        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x118D58u;
    {
        const bool branch_taken_0x118d58 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x118d58) {
            ctx->pc = 0x118D5Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x118D58u;
            // 0x118d5c: 0x8e030000  lw          $v1, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x118D70u;
            goto label_118d70;
        }
    }
    ctx->pc = 0x118D60u;
label_118d60:
    // 0x118d60: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x118D60u;
    SET_GPR_U32(ctx, 31, 0x118D68u);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118D68u; }
        if (ctx->pc != 0x118D68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118D68u; }
        if (ctx->pc != 0x118D68u) { return; }
    }
    ctx->pc = 0x118D68u;
label_118d68:
    // 0x118d68: 0x1000003a  b           . + 4 + (0x3A << 2)
    ctx->pc = 0x118D68u;
    {
        const bool branch_taken_0x118d68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x118D6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118D68u;
            // 0x118d6c: 0x2402fff7  addiu       $v0, $zero, -0x9 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967287));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118d68) {
            ctx->pc = 0x118E54u;
            goto label_118e54;
        }
    }
    ctx->pc = 0x118D70u;
label_118d70:
    // 0x118d70: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x118d70u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x118d74: 0x2442df40  addiu       $v0, $v0, -0x20C0
    ctx->pc = 0x118d74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294958912));
    // 0x118d78: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x118d78u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x118d7c: 0xae43000c  sw          $v1, 0xC($s2)
    ctx->pc = 0x118d7cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 12), GPR_U32(ctx, 3));
    // 0x118d80: 0x2021023  subu        $v0, $s0, $v0
    ctx->pc = 0x118d80u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x118d84: 0xafa40014  sw          $a0, 0x14($sp)
    ctx->pc = 0x118d84u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 4));
    // 0x118d88: 0x21103  sra         $v0, $v0, 4
    ctx->pc = 0x118d88u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 4));
    // 0x118d8c: 0xae420010  sw          $v0, 0x10($s2)
    ctx->pc = 0x118d8cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x118d90: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x118d90u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x118d94: 0xafa00018  sw          $zero, 0x18($sp)
    ctx->pc = 0x118d94u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
    // 0x118d98: 0xc045188  jal         func_114620
    ctx->pc = 0x118D98u;
    SET_GPR_U32(ctx, 31, 0x118DA0u);
    ctx->pc = 0x118D9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118D98u;
            // 0x118d9c: 0xafa00024  sw          $zero, 0x24($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118DA0u; }
        if (ctx->pc != 0x118DA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118DA0u; }
        if (ctx->pc != 0x118DA0u) { return; }
    }
    ctx->pc = 0x118DA0u;
label_118da0:
    // 0x118da0: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x118da0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118da4: 0x27a30030  addiu       $v1, $sp, 0x30
    ctx->pc = 0x118da4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x118da8: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x118da8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x118dac: 0xae91ca40  sw          $s1, -0x35C0($s4)
    ctx->pc = 0x118dacu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 4294953536), GPR_U32(ctx, 17));
    // 0x118db0: 0x2453d680  addiu       $s3, $v0, -0x2980
    ctx->pc = 0x118db0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 2), 4294956672));
    // 0x118db4: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x118db4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x118db8: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x118db8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x118dbc: 0xae430004  sw          $v1, 0x4($s2)
    ctx->pc = 0x118dbcu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 3));
    // 0x118dc0: 0xae420008  sw          $v0, 0x8($s2)
    ctx->pc = 0x118dc0u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 8), GPR_U32(ctx, 2));
    // 0x118dc4: 0x2484e140  addiu       $a0, $a0, -0x1EC0
    ctx->pc = 0x118dc4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294959424));
    // 0x118dc8: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x118dc8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118dcc: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x118dccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x118dd0: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x118dd0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x118dd4: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x118dd4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118dd8: 0x24080014  addiu       $t0, $zero, 0x14
    ctx->pc = 0x118dd8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x118ddc: 0x260482d  daddu       $t1, $s3, $zero
    ctx->pc = 0x118ddcu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118de0: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x118de0u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x118de4: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x118DE4u;
    SET_GPR_U32(ctx, 31, 0x118DECu);
    ctx->pc = 0x118DE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118DE4u;
            // 0x118de8: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118DECu; }
        if (ctx->pc != 0x118DECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118DECu; }
        if (ctx->pc != 0x118DECu) { return; }
    }
    ctx->pc = 0x118DECu;
label_118dec:
    // 0x118dec: 0x4430007  bgezl       $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x118DECu;
    {
        const bool branch_taken_0x118dec = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x118dec) {
            ctx->pc = 0x118DF0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x118DECu;
            // 0x118df0: 0xae000004  sw          $zero, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x118E0Cu;
            goto label_118e0c;
        }
    }
    ctx->pc = 0x118DF4u;
    // 0x118df4: 0xc04518c  jal         func_114630
    ctx->pc = 0x118DF4u;
    SET_GPR_U32(ctx, 31, 0x118DFCu);
    ctx->pc = 0x118DF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118DF4u;
            // 0x118df8: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118DFCu; }
        if (ctx->pc != 0x118DFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118DFCu; }
        if (ctx->pc != 0x118DFCu) { return; }
    }
    ctx->pc = 0x118DFCu;
label_118dfc:
    // 0x118dfc: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x118DFCu;
    SET_GPR_U32(ctx, 31, 0x118E04u);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118E04u; }
        if (ctx->pc != 0x118E04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118E04u; }
        if (ctx->pc != 0x118E04u) { return; }
    }
    ctx->pc = 0x118E04u;
label_118e04:
    // 0x118e04: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x118E04u;
    {
        const bool branch_taken_0x118e04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x118E08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118E04u;
            // 0x118e08: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118e04) {
            ctx->pc = 0x118E54u;
            goto label_118e54;
        }
    }
    ctx->pc = 0x118E0Cu;
label_118e0c:
    // 0x118e0c: 0x3c022000  lui         $v0, 0x2000
    ctx->pc = 0x118e0cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
    // 0x118e10: 0x2621025  or          $v0, $s3, $v0
    ctx->pc = 0x118e10u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) | GPR_U64(ctx, 2));
    // 0x118e14: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x118E14u;
    SET_GPR_U32(ctx, 31, 0x118E1Cu);
    ctx->pc = 0x118E18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118E14u;
            // 0x118e18: 0x8c500000  lw          $s0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118E1Cu; }
        if (ctx->pc != 0x118E1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118E1Cu; }
        if (ctx->pc != 0x118E1Cu) { return; }
    }
    ctx->pc = 0x118E1Cu;
label_118e1c:
    // 0x118e1c: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x118E1Cu;
    {
        const bool branch_taken_0x118e1c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x118e1c) {
            ctx->pc = 0x118E34u;
            goto label_118e34;
        }
    }
    ctx->pc = 0x118E24u;
    // 0x118e24: 0xc04518c  jal         func_114630
    ctx->pc = 0x118E24u;
    SET_GPR_U32(ctx, 31, 0x118E2Cu);
    ctx->pc = 0x118E28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118E24u;
            // 0x118e28: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118E2Cu; }
        if (ctx->pc != 0x118E2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118E2Cu; }
        if (ctx->pc != 0x118E2Cu) { return; }
    }
    ctx->pc = 0x118E2Cu;
label_118e2c:
    // 0x118e2c: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x118E2Cu;
    {
        const bool branch_taken_0x118e2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x118E30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118E2Cu;
            // 0x118e30: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118e2c) {
            ctx->pc = 0x118E54u;
            goto label_118e54;
        }
    }
    ctx->pc = 0x118E34u;
label_118e34:
    // 0x118e34: 0xc045198  jal         func_114660
    ctx->pc = 0x118E34u;
    SET_GPR_U32(ctx, 31, 0x118E3Cu);
    ctx->pc = 0x118E38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118E34u;
            // 0x118e38: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118E3Cu; }
        if (ctx->pc != 0x118E3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118E3Cu; }
        if (ctx->pc != 0x118E3Cu) { return; }
    }
    ctx->pc = 0x118E3Cu;
label_118e3c:
    // 0x118e3c: 0xc04518c  jal         func_114630
    ctx->pc = 0x118E3Cu;
    SET_GPR_U32(ctx, 31, 0x118E44u);
    ctx->pc = 0x118E40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118E3Cu;
            // 0x118e40: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118E44u; }
        if (ctx->pc != 0x118E44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118E44u; }
        if (ctx->pc != 0x118E44u) { return; }
    }
    ctx->pc = 0x118E44u;
label_118e44:
    // 0x118e44: 0x8fa20030  lw          $v0, 0x30($sp)
    ctx->pc = 0x118e44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x118e48: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x118e48u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x118e4c: 0x62182a  slt         $v1, $v1, $v0
    ctx->pc = 0x118e4cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x118e50: 0x3100b  movn        $v0, $zero, $v1
    ctx->pc = 0x118e50u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 0));
label_118e54:
    // 0x118e54: 0xdfbf0090  ld          $ra, 0x90($sp)
    ctx->pc = 0x118e54u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x118e58: 0xdfb40080  ld          $s4, 0x80($sp)
    ctx->pc = 0x118e58u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x118e5c: 0xdfb30070  ld          $s3, 0x70($sp)
    ctx->pc = 0x118e5cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x118e60: 0xdfb20060  ld          $s2, 0x60($sp)
    ctx->pc = 0x118e60u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x118e64: 0xdfb10050  ld          $s1, 0x50($sp)
    ctx->pc = 0x118e64u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x118e68: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x118e68u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x118e6c: 0x3e00008  jr          $ra
    ctx->pc = 0x118E6Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x118E70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118E6Cu;
            // 0x118e70: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x118D20u: goto label_118d20;
            case 0x118D2Cu: goto label_118d2c;
            case 0x118D44u: goto label_118d44;
            case 0x118D4Cu: goto label_118d4c;
            case 0x118D60u: goto label_118d60;
            case 0x118D68u: goto label_118d68;
            case 0x118D70u: goto label_118d70;
            case 0x118DA0u: goto label_118da0;
            case 0x118DECu: goto label_118dec;
            case 0x118DFCu: goto label_118dfc;
            case 0x118E04u: goto label_118e04;
            case 0x118E0Cu: goto label_118e0c;
            case 0x118E1Cu: goto label_118e1c;
            case 0x118E2Cu: goto label_118e2c;
            case 0x118E34u: goto label_118e34;
            case 0x118E3Cu: goto label_118e3c;
            case 0x118E44u: goto label_118e44;
            case 0x118E54u: goto label_118e54;
            default: break;
        }
        return;
    }
    ctx->pc = 0x118E74u;
    // 0x118e74: 0x0  nop
    ctx->pc = 0x118e74u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
