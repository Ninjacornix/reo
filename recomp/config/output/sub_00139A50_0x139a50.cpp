#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00139A50
// Address: 0x139a50 - 0x139bd4
void sub_00139A50_0x139a50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00139A50_0x139a50");
#endif

    switch (ctx->pc) {
        case 0x139aa0u: goto label_139aa0;
        case 0x139ac0u: goto label_139ac0;
        case 0x139ad4u: goto label_139ad4;
        case 0x139af4u: goto label_139af4;
        case 0x139b14u: goto label_139b14;
        case 0x139b1cu: goto label_139b1c;
        case 0x139b24u: goto label_139b24;
        case 0x139b2cu: goto label_139b2c;
        case 0x139b38u: goto label_139b38;
        case 0x139b50u: goto label_139b50;
        case 0x139b58u: goto label_139b58;
        default: break;
    }

    ctx->pc = 0x139a50u;

    // 0x139a50: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x139a50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x139a54: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x139a54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x139a58: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x139a58u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x139a5c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x139a5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x139a60: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x139a60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x139a64: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x139a64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x139a68: 0x16200005  bnez        $s1, . + 4 + (0x5 << 2)
    ctx->pc = 0x139A68u;
    {
        const bool branch_taken_0x139a68 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x139A6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139A68u;
            // 0x139a6c: 0xffbf0020  sd          $ra, 0x20($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139a68) {
            ctx->pc = 0x139A80u;
            goto label_139a80;
        }
    }
    ctx->pc = 0x139A70u;
    // 0x139a70: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x139a70u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x139a74: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x139A74u;
    {
        const bool branch_taken_0x139a74 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x139A78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139A74u;
            // 0x139a78: 0x24a5cb10  addiu       $a1, $a1, -0x34F0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294953744));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139a74) {
            ctx->pc = 0x139AB8u;
            goto label_139ab8;
        }
    }
    ctx->pc = 0x139A7Cu;
    // 0x139a7c: 0x0  nop
    ctx->pc = 0x139a7cu;
    // NOP
label_139a80:
    // 0x139a80: 0x10c00005  beqz        $a2, . + 4 + (0x5 << 2)
    ctx->pc = 0x139A80u;
    {
        const bool branch_taken_0x139a80 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x139A84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139A80u;
            // 0x139a84: 0x3c050024  lui         $a1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139a80) {
            ctx->pc = 0x139A98u;
            goto label_139a98;
        }
    }
    ctx->pc = 0x139A88u;
    // 0x139a88: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x139a88u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x139a8c: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x139A8Cu;
    {
        const bool branch_taken_0x139a8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x139A90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139A8Cu;
            // 0x139a90: 0x24a5cb38  addiu       $a1, $a1, -0x34C8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294953784));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139a8c) {
            ctx->pc = 0x139AB8u;
            goto label_139ab8;
        }
    }
    ctx->pc = 0x139A94u;
    // 0x139a94: 0x0  nop
    ctx->pc = 0x139a94u;
    // NOP
label_139a98:
    // 0x139a98: 0xc04e67e  jal         func_1399F8
    ctx->pc = 0x139A98u;
    SET_GPR_U32(ctx, 31, 0x139AA0u);
    ctx->pc = 0x1399F8u;
    if (runtime->hasFunction(0x1399F8u)) {
        auto targetFn = runtime->lookupFunction(0x1399F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139AA0u; }
        if (ctx->pc != 0x139AA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001399F8_0x1399f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139AA0u; }
        if (ctx->pc != 0x139AA0u) { return; }
    }
    ctx->pc = 0x139AA0u;
label_139aa0:
    // 0x139aa0: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x139aa0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x139aa4: 0x16000008  bnez        $s0, . + 4 + (0x8 << 2)
    ctx->pc = 0x139AA4u;
    {
        const bool branch_taken_0x139aa4 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x139AA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139AA4u;
            // 0x139aa8: 0x26120020  addiu       $s2, $s0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139aa4) {
            ctx->pc = 0x139AC8u;
            goto label_139ac8;
        }
    }
    ctx->pc = 0x139AACu;
    // 0x139aac: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x139aacu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x139ab0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x139ab0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x139ab4: 0x24a5cb60  addiu       $a1, $a1, -0x34A0
    ctx->pc = 0x139ab4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294953824));
label_139ab8:
    // 0x139ab8: 0xc04e57e  jal         func_1395F8
    ctx->pc = 0x139AB8u;
    SET_GPR_U32(ctx, 31, 0x139AC0u);
    ctx->pc = 0x1395F8u;
    if (runtime->hasFunction(0x1395F8u)) {
        auto targetFn = runtime->lookupFunction(0x1395F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139AC0u; }
        if (ctx->pc != 0x139AC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001395F8_0x1395f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139AC0u; }
        if (ctx->pc != 0x139AC0u) { return; }
    }
    ctx->pc = 0x139AC0u;
label_139ac0:
    // 0x139ac0: 0x1000003d  b           . + 4 + (0x3D << 2)
    ctx->pc = 0x139AC0u;
    {
        const bool branch_taken_0x139ac0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x139AC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139AC0u;
            // 0x139ac4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139ac0) {
            ctx->pc = 0x139BB8u;
            goto label_139bb8;
        }
    }
    ctx->pc = 0x139AC8u;
label_139ac8:
    // 0x139ac8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x139ac8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x139acc: 0xc04ea80  jal         func_13AA00
    ctx->pc = 0x139ACCu;
    SET_GPR_U32(ctx, 31, 0x139AD4u);
    ctx->pc = 0x139AD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x139ACCu;
            // 0x139ad0: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13AA00u;
    if (runtime->hasFunction(0x13AA00u)) {
        auto targetFn = runtime->lookupFunction(0x13AA00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139AD4u; }
        if (ctx->pc != 0x139AD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013AA00_0x13aa00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139AD4u; }
        if (ctx->pc != 0x139AD4u) { return; }
    }
    ctx->pc = 0x139AD4u;
label_139ad4:
    // 0x139ad4: 0x8e050024  lw          $a1, 0x24($s0)
    ctx->pc = 0x139ad4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x139ad8: 0x14a00023  bnez        $a1, . + 4 + (0x23 << 2)
    ctx->pc = 0x139AD8u;
    {
        const bool branch_taken_0x139ad8 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x139ADCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139AD8u;
            // 0x139adc: 0x40982d  daddu       $s3, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139ad8) {
            ctx->pc = 0x139B68u;
            goto label_139b68;
        }
    }
    ctx->pc = 0x139AE0u;
    // 0x139ae0: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x139ae0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x139ae4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x139ae4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x139ae8: 0x2451d7a0  addiu       $s1, $v0, -0x2860
    ctx->pc = 0x139ae8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294956960));
    // 0x139aec: 0xc04e892  jal         func_13A248
    ctx->pc = 0x139AECu;
    SET_GPR_U32(ctx, 31, 0x139AF4u);
    ctx->pc = 0x139AF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x139AECu;
            // 0x139af0: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13A248u;
    if (runtime->hasFunction(0x13A248u)) {
        auto targetFn = runtime->lookupFunction(0x13A248u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139AF4u; }
        if (ctx->pc != 0x139AF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013A248_0x13a248(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139AF4u; }
        if (ctx->pc != 0x139AF4u) { return; }
    }
    ctx->pc = 0x139AF4u;
label_139af4:
    // 0x139af4: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x139af4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x139af8: 0x8c44d8e8  lw          $a0, -0x2718($v0)
    ctx->pc = 0x139af8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294957288)));
    // 0x139afc: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x139afcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x139b00: 0x10830004  beq         $a0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x139B00u;
    {
        const bool branch_taken_0x139b00 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x139B04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139B00u;
            // 0x139b04: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139b00) {
            ctx->pc = 0x139B14u;
            goto label_139b14;
        }
    }
    ctx->pc = 0x139B08u;
    // 0x139b08: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x139b08u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x139b0c: 0xc045a12  jal         func_116848
    ctx->pc = 0x139B0Cu;
    SET_GPR_U32(ctx, 31, 0x139B14u);
    ctx->pc = 0x139B10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x139B0Cu;
            // 0x139b10: 0x2484cb90  addiu       $a0, $a0, -0x3470 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294953872));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139B14u; }
        if (ctx->pc != 0x139B14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139B14u; }
        if (ctx->pc != 0x139B14u) { return; }
    }
    ctx->pc = 0x139B14u;
label_139b14:
    // 0x139b14: 0xc04e082  jal         func_138208
    ctx->pc = 0x139B14u;
    SET_GPR_U32(ctx, 31, 0x139B1Cu);
    ctx->pc = 0x139B18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x139B14u;
            // 0x139b18: 0x34048300  ori         $a0, $zero, 0x8300 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33536);
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139B1Cu; }
        if (ctx->pc != 0x139B1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139B1Cu; }
        if (ctx->pc != 0x139B1Cu) { return; }
    }
    ctx->pc = 0x139B1Cu;
label_139b1c:
    // 0x139b1c: 0xc04035e  jal         func_100D78
    ctx->pc = 0x139B1Cu;
    SET_GPR_U32(ctx, 31, 0x139B24u);
    ctx->pc = 0x139B20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x139B1Cu;
            // 0x139b20: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100D78u;
    if (runtime->hasFunction(0x100D78u)) {
        auto targetFn = runtime->lookupFunction(0x100D78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139B24u; }
        if (ctx->pc != 0x139B24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00100D78_0x100d78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139B24u; }
        if (ctx->pc != 0x139B24u) { return; }
    }
    ctx->pc = 0x139B24u;
label_139b24:
    // 0x139b24: 0xc04e082  jal         func_138208
    ctx->pc = 0x139B24u;
    SET_GPR_U32(ctx, 31, 0x139B2Cu);
    ctx->pc = 0x139B28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x139B24u;
            // 0x139b28: 0x34048301  ori         $a0, $zero, 0x8301 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33537);
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139B2Cu; }
        if (ctx->pc != 0x139B2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139B2Cu; }
        if (ctx->pc != 0x139B2Cu) { return; }
    }
    ctx->pc = 0x139B2Cu;
label_139b2c:
    // 0x139b2c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x139b2cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x139b30: 0xc04e58a  jal         func_139628
    ctx->pc = 0x139B30u;
    SET_GPR_U32(ctx, 31, 0x139B38u);
    ctx->pc = 0x139B34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x139B30u;
            // 0x139b34: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139628u;
    if (runtime->hasFunction(0x139628u)) {
        auto targetFn = runtime->lookupFunction(0x139628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139B38u; }
        if (ctx->pc != 0x139B38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139628_0x139628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139B38u; }
        if (ctx->pc != 0x139B38u) { return; }
    }
    ctx->pc = 0x139B38u;
label_139b38:
    // 0x139b38: 0x54400009  bnel        $v0, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x139B38u;
    {
        const bool branch_taken_0x139b38 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x139b38) {
            ctx->pc = 0x139B3Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x139B38u;
            // 0x139b3c: 0xa2000001  sb          $zero, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x139B60u;
            goto label_139b60;
        }
    }
    ctx->pc = 0x139B40u;
    // 0x139b40: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x139b40u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x139b44: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x139b44u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x139b48: 0xc04e57e  jal         func_1395F8
    ctx->pc = 0x139B48u;
    SET_GPR_U32(ctx, 31, 0x139B50u);
    ctx->pc = 0x139B4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x139B48u;
            // 0x139b4c: 0x24a5cbb8  addiu       $a1, $a1, -0x3448 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294953912));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1395F8u;
    if (runtime->hasFunction(0x1395F8u)) {
        auto targetFn = runtime->lookupFunction(0x1395F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139B50u; }
        if (ctx->pc != 0x139B50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001395F8_0x1395f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139B50u; }
        if (ctx->pc != 0x139B50u) { return; }
    }
    ctx->pc = 0x139B50u;
label_139b50:
    // 0x139b50: 0xc04e68c  jal         func_139A30
    ctx->pc = 0x139B50u;
    SET_GPR_U32(ctx, 31, 0x139B58u);
    ctx->pc = 0x139B54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x139B50u;
            // 0x139b54: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139A30u;
    if (runtime->hasFunction(0x139A30u)) {
        auto targetFn = runtime->lookupFunction(0x139A30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139B58u; }
        if (ctx->pc != 0x139B58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139A30_0x139a30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139B58u; }
        if (ctx->pc != 0x139B58u) { return; }
    }
    ctx->pc = 0x139B58u;
label_139b58:
    // 0x139b58: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x139B58u;
    {
        const bool branch_taken_0x139b58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x139B5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139B58u;
            // 0x139b5c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139b58) {
            ctx->pc = 0x139BB8u;
            goto label_139bb8;
        }
    }
    ctx->pc = 0x139B60u;
label_139b60:
    // 0x139b60: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x139B60u;
    {
        const bool branch_taken_0x139b60 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x139B64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139B60u;
            // 0x139b64: 0x8e050024  lw          $a1, 0x24($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139b60) {
            ctx->pc = 0x139B70u;
            goto label_139b70;
        }
    }
    ctx->pc = 0x139B68u;
label_139b68:
    // 0x139b68: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x139b68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x139b6c: 0xa2020001  sb          $v0, 0x1($s0)
    ctx->pc = 0x139b6cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
label_139b70:
    // 0x139b70: 0x24a207ff  addiu       $v0, $a1, 0x7FF
    ctx->pc = 0x139b70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 2047));
    // 0x139b74: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x139b74u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x139b78: 0x212c2  srl         $v0, $v0, 11
    ctx->pc = 0x139b78u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 11));
    // 0x139b7c: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x139b7cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x139b80: 0xae020008  sw          $v0, 0x8($s0)
    ctx->pc = 0x139b80u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
    // 0x139b84: 0xa2030000  sb          $v1, 0x0($s0)
    ctx->pc = 0x139b84u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x139b88: 0xae050004  sw          $a1, 0x4($s0)
    ctx->pc = 0x139b88u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 5));
    // 0x139b8c: 0xae00000c  sw          $zero, 0xC($s0)
    ctx->pc = 0x139b8cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 0));
    // 0x139b90: 0xae000018  sw          $zero, 0x18($s0)
    ctx->pc = 0x139b90u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 0));
    // 0x139b94: 0xae000010  sw          $zero, 0x10($s0)
    ctx->pc = 0x139b94u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 0));
    // 0x139b98: 0xae000014  sw          $zero, 0x14($s0)
    ctx->pc = 0x139b98u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
    // 0x139b9c: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x139b9cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x139ba0: 0x16640004  bne         $s3, $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x139BA0u;
    {
        const bool branch_taken_0x139ba0 = (GPR_U64(ctx, 19) != GPR_U64(ctx, 4));
        ctx->pc = 0x139BA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139BA0u;
            // 0x139ba4: 0xae00001c  sw          $zero, 0x1C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139ba0) {
            ctx->pc = 0x139BB4u;
            goto label_139bb4;
        }
    }
    ctx->pc = 0x139BA8u;
    // 0x139ba8: 0x3c027fff  lui         $v0, 0x7FFF
    ctx->pc = 0x139ba8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
    // 0x139bac: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x139bacu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x139bb0: 0xae020008  sw          $v0, 0x8($s0)
    ctx->pc = 0x139bb0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
label_139bb4:
    // 0x139bb4: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x139bb4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_139bb8:
    // 0x139bb8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x139bb8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x139bbc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x139bbcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x139bc0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x139bc0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x139bc4: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x139bc4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x139bc8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x139bc8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x139bcc: 0x3e00008  jr          $ra
    ctx->pc = 0x139BCCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x139BD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139BCCu;
            // 0x139bd0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x139A80u: goto label_139a80;
            case 0x139A98u: goto label_139a98;
            case 0x139AA0u: goto label_139aa0;
            case 0x139AB8u: goto label_139ab8;
            case 0x139AC0u: goto label_139ac0;
            case 0x139AC8u: goto label_139ac8;
            case 0x139AD4u: goto label_139ad4;
            case 0x139AF4u: goto label_139af4;
            case 0x139B14u: goto label_139b14;
            case 0x139B1Cu: goto label_139b1c;
            case 0x139B24u: goto label_139b24;
            case 0x139B2Cu: goto label_139b2c;
            case 0x139B38u: goto label_139b38;
            case 0x139B50u: goto label_139b50;
            case 0x139B58u: goto label_139b58;
            case 0x139B60u: goto label_139b60;
            case 0x139B68u: goto label_139b68;
            case 0x139B70u: goto label_139b70;
            case 0x139BB4u: goto label_139bb4;
            case 0x139BB8u: goto label_139bb8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x139BD4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
