#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D2CB0
// Address: 0x1d2cb0 - 0x1d2fe0
void sub_001D2CB0_0x1d2cb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D2CB0_0x1d2cb0");
#endif

    switch (ctx->pc) {
        case 0x1d2cf4u: goto label_1d2cf4;
        case 0x1d2d00u: goto label_1d2d00;
        case 0x1d2d10u: goto label_1d2d10;
        case 0x1d2d28u: goto label_1d2d28;
        case 0x1d2d90u: goto label_1d2d90;
        case 0x1d2d98u: goto label_1d2d98;
        case 0x1d2da8u: goto label_1d2da8;
        case 0x1d2db0u: goto label_1d2db0;
        case 0x1d2dbcu: goto label_1d2dbc;
        case 0x1d2dc8u: goto label_1d2dc8;
        case 0x1d2df8u: goto label_1d2df8;
        case 0x1d2e80u: goto label_1d2e80;
        case 0x1d2ec0u: goto label_1d2ec0;
        case 0x1d2ed8u: goto label_1d2ed8;
        case 0x1d2ef4u: goto label_1d2ef4;
        case 0x1d2f2cu: goto label_1d2f2c;
        case 0x1d2f80u: goto label_1d2f80;
        case 0x1d2f88u: goto label_1d2f88;
        default: break;
    }

    ctx->pc = 0x1d2cb0u;

    // 0x1d2cb0: 0x27bdfea0  addiu       $sp, $sp, -0x160
    ctx->pc = 0x1d2cb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966944));
    // 0x1d2cb4: 0xffbf0090  sd          $ra, 0x90($sp)
    ctx->pc = 0x1d2cb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 31));
    // 0x1d2cb8: 0x7fbe0080  sq          $fp, 0x80($sp)
    ctx->pc = 0x1d2cb8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 128), GPR_VEC(ctx, 30));
    // 0x1d2cbc: 0x7fb70070  sq          $s7, 0x70($sp)
    ctx->pc = 0x1d2cbcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 112), GPR_VEC(ctx, 23));
    // 0x1d2cc0: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x1d2cc0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x1d2cc4: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1d2cc4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1d2cc8: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1d2cc8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1d2ccc: 0x80a82d  daddu       $s5, $a0, $zero
    ctx->pc = 0x1d2cccu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d2cd0: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d2cd0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d2cd4: 0xa0a02d  daddu       $s4, $a1, $zero
    ctx->pc = 0x1d2cd4u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d2cd8: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d2cd8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d2cdc: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1d2cdcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d2ce0: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d2ce0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d2ce4: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d2ce4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d2ce8: 0xafa600c0  sw          $a2, 0xC0($sp)
    ctx->pc = 0x1d2ce8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 192), GPR_U32(ctx, 6));
    // 0x1d2cec: 0xc068abc  jal         func_1A2AF0
    ctx->pc = 0x1D2CECu;
    SET_GPR_U32(ctx, 31, 0x1D2CF4u);
    ctx->pc = 0x1D2CF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2CECu;
            // 0x1d2cf0: 0xafa700b0  sw          $a3, 0xB0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 176), GPR_U32(ctx, 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A2AF0u;
    if (runtime->hasFunction(0x1A2AF0u)) {
        auto targetFn = runtime->lookupFunction(0x1A2AF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2CF4u; }
        if (ctx->pc != 0x1D2CF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A2AF0_0x1a2af0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2CF4u; }
        if (ctx->pc != 0x1D2CF4u) { return; }
    }
    ctx->pc = 0x1D2CF4u;
label_1d2cf4:
    // 0x1d2cf4: 0xa6a20816  sh          $v0, 0x816($s5)
    ctx->pc = 0x1d2cf4u;
    WRITE16(ADD32(GPR_U32(ctx, 21), 2070), (uint16_t)GPR_U32(ctx, 2));
    // 0x1d2cf8: 0xc068acc  jal         func_1A2B30
    ctx->pc = 0x1D2CF8u;
    SET_GPR_U32(ctx, 31, 0x1D2D00u);
    ctx->pc = 0x1D2CFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2CF8u;
            // 0x1d2cfc: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A2B30u;
    if (runtime->hasFunction(0x1A2B30u)) {
        auto targetFn = runtime->lookupFunction(0x1A2B30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2D00u; }
        if (ctx->pc != 0x1D2D00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A2B30_0x1a2b30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2D00u; }
        if (ctx->pc != 0x1D2D00u) { return; }
    }
    ctx->pc = 0x1D2D00u;
label_1d2d00:
    // 0x1d2d00: 0x3c01004a  lui         $at, 0x4A
    ctx->pc = 0x1d2d00u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)74 << 16));
    // 0x1d2d04: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x1d2d04u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d2d08: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1D2D08u;
    {
        const bool branch_taken_0x1d2d08 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D2D0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2D08u;
            // 0x1d2d0c: 0xa022eef3  sb          $v0, -0x110D($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 4294962931), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2d08) {
            ctx->pc = 0x1D2D50u;
            goto label_1d2d50;
        }
    }
    ctx->pc = 0x1D2D10u;
label_1d2d10:
    // 0x1d2d10: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1d2d10u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d2d14: 0x111040  sll         $v0, $s1, 1
    ctx->pc = 0x1d2d14u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 1));
    // 0x1d2d18: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1d2d18u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d2d1c: 0x5d1021  addu        $v0, $v0, $sp
    ctx->pc = 0x1d2d1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 29)));
    // 0x1d2d20: 0xc068ad8  jal         func_1A2B60
    ctx->pc = 0x1D2D20u;
    SET_GPR_U32(ctx, 31, 0x1D2D28u);
    ctx->pc = 0x1D2D24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2D20u;
            // 0x1d2d24: 0x24500120  addiu       $s0, $v0, 0x120 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 288));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A2B60u;
    if (runtime->hasFunction(0x1A2B60u)) {
        auto targetFn = runtime->lookupFunction(0x1A2B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2D28u; }
        if (ctx->pc != 0x1D2D28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A2B60_0x1a2b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2D28u; }
        if (ctx->pc != 0x1D2D28u) { return; }
    }
    ctx->pc = 0x1D2D28u;
label_1d2d28:
    // 0x1d2d28: 0xa6020000  sh          $v0, 0x0($s0)
    ctx->pc = 0x1d2d28u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1d2d2c: 0x122040  sll         $a0, $s2, 1
    ctx->pc = 0x1d2d2cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x1d2d30: 0x96050000  lhu         $a1, 0x0($s0)
    ctx->pc = 0x1d2d30u;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1d2d34: 0x3c02004a  lui         $v0, 0x4A
    ctx->pc = 0x1d2d34u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)74 << 16));
    // 0x1d2d38: 0x2442eef0  addiu       $v0, $v0, -0x1110
    ctx->pc = 0x1d2d38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294962928));
    // 0x1d2d3c: 0x511821  addu        $v1, $v0, $s1
    ctx->pc = 0x1d2d3cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x1d2d40: 0x26620001  addiu       $v0, $s3, 0x1
    ctx->pc = 0x1d2d40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x1d2d44: 0x3053ffff  andi        $s3, $v0, 0xFFFF
    ctx->pc = 0x1d2d44u;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1d2d48: 0xa41023  subu        $v0, $a1, $a0
    ctx->pc = 0x1d2d48u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x1d2d4c: 0xa0622b20  sb          $v0, 0x2B20($v1)
    ctx->pc = 0x1d2d4cu;
    WRITE8(ADD32(GPR_U32(ctx, 3), 11040), (uint8_t)GPR_U32(ctx, 2));
label_1d2d50:
    // 0x1d2d50: 0x3c01004a  lui         $at, 0x4A
    ctx->pc = 0x1d2d50u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)74 << 16));
    // 0x1d2d54: 0x3272ffff  andi        $s2, $s3, 0xFFFF
    ctx->pc = 0x1d2d54u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)65535);
    // 0x1d2d58: 0x9022eef3  lbu         $v0, -0x110D($at)
    ctx->pc = 0x1d2d58u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294962931)));
    // 0x1d2d5c: 0x242102a  slt         $v0, $s2, $v0
    ctx->pc = 0x1d2d5cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1d2d60: 0x1440ffeb  bnez        $v0, . + 4 + (-0x15 << 2)
    ctx->pc = 0x1D2D60u;
    {
        const bool branch_taken_0x1d2d60 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D2D64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2D60u;
            // 0x1d2d64: 0x3271ffff  andi        $s1, $s3, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 17, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2d60) {
            ctx->pc = 0x1D2D10u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d2d10;
        }
    }
    ctx->pc = 0x1D2D68u;
    // 0x1d2d68: 0x96a50816  lhu         $a1, 0x816($s5)
    ctx->pc = 0x1d2d68u;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 21), 2070)));
    // 0x1d2d6c: 0x121040  sll         $v0, $s2, 1
    ctx->pc = 0x1d2d6cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x1d2d70: 0x5d1821  addu        $v1, $v0, $sp
    ctx->pc = 0x1d2d70u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 29)));
    // 0x1d2d74: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d2d74u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d2d78: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x1d2d78u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x1d2d7c: 0x27a400d0  addiu       $a0, $sp, 0xD0
    ctx->pc = 0x1d2d7cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 208));
    // 0x1d2d80: 0xa4650120  sh          $a1, 0x120($v1)
    ctx->pc = 0x1d2d80u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 288), (uint16_t)GPR_U32(ctx, 5));
    // 0x1d2d84: 0x8c23440c  lw          $v1, 0x440C($at)
    ctx->pc = 0x1d2d84u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d2d88: 0xc063f7c  jal         func_18FDF0
    ctx->pc = 0x1D2D88u;
    SET_GPR_U32(ctx, 31, 0x1D2D90u);
    ctx->pc = 0x1D2D8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2D88u;
            // 0x1d2d8c: 0x629821  addu        $s3, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18FDF0u;
    if (runtime->hasFunction(0x18FDF0u)) {
        auto targetFn = runtime->lookupFunction(0x18FDF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2D90u; }
        if (ctx->pc != 0x1D2D90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018FDF0_0x18fdf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2D90u; }
        if (ctx->pc != 0x1D2D90u) { return; }
    }
    ctx->pc = 0x1D2D90u;
label_1d2d90:
    // 0x1d2d90: 0x10000080  b           . + 4 + (0x80 << 2)
    ctx->pc = 0x1D2D90u;
    {
        const bool branch_taken_0x1d2d90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D2D94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2D90u;
            // 0x1d2d94: 0x902d  daddu       $s2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2d90) {
            ctx->pc = 0x1D2F94u;
            goto label_1d2f94;
        }
    }
    ctx->pc = 0x1D2D98u;
label_1d2d98:
    // 0x1d2d98: 0x27a40110  addiu       $a0, $sp, 0x110
    ctx->pc = 0x1d2d98u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 272));
    // 0x1d2d9c: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1d2d9cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d2da0: 0xc074d50  jal         func_1D3540
    ctx->pc = 0x1D2DA0u;
    SET_GPR_U32(ctx, 31, 0x1D2DA8u);
    ctx->pc = 0x1D2DA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2DA0u;
            // 0x1d2da4: 0x280302d  daddu       $a2, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D3540u;
    if (runtime->hasFunction(0x1D3540u)) {
        auto targetFn = runtime->lookupFunction(0x1D3540u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2DA8u; }
        if (ctx->pc != 0x1D2DA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D3540_0x1d3540(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2DA8u; }
        if (ctx->pc != 0x1D2DA8u) { return; }
    }
    ctx->pc = 0x1D2DA8u;
label_1d2da8:
    // 0x1d2da8: 0xc064920  jal         func_192480
    ctx->pc = 0x1D2DA8u;
    SET_GPR_U32(ctx, 31, 0x1D2DB0u);
    ctx->pc = 0x1D2DACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2DA8u;
            // 0x1d2dac: 0x27a40110  addiu       $a0, $sp, 0x110 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 272));
        ctx->in_delay_slot = false;
    ctx->pc = 0x192480u;
    if (runtime->hasFunction(0x192480u)) {
        auto targetFn = runtime->lookupFunction(0x192480u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2DB0u; }
        if (ctx->pc != 0x1D2DB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00192480_0x192480(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2DB0u; }
        if (ctx->pc != 0x1D2DB0u) { return; }
    }
    ctx->pc = 0x1D2DB0u;
label_1d2db0:
    // 0x1d2db0: 0xaea2080c  sw          $v0, 0x80C($s5)
    ctx->pc = 0x1d2db0u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 2060), GPR_U32(ctx, 2));
    // 0x1d2db4: 0xc06c430  jal         func_1B10C0
    ctx->pc = 0x1D2DB4u;
    SET_GPR_U32(ctx, 31, 0x1D2DBCu);
    ctx->pc = 0x1D2DB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2DB4u;
            // 0x1d2db8: 0x8ea4080c  lw          $a0, 0x80C($s5) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 2060)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B10C0u;
    if (runtime->hasFunction(0x1B10C0u)) {
        auto targetFn = runtime->lookupFunction(0x1B10C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2DBCu; }
        if (ctx->pc != 0x1D2DBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B10C0_0x1b10c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2DBCu; }
        if (ctx->pc != 0x1D2DBCu) { return; }
    }
    ctx->pc = 0x1D2DBCu;
label_1d2dbc:
    // 0x1d2dbc: 0x8ea5080c  lw          $a1, 0x80C($s5)
    ctx->pc = 0x1d2dbcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 2060)));
    // 0x1d2dc0: 0xc064ce0  jal         func_193380
    ctx->pc = 0x1D2DC0u;
    SET_GPR_U32(ctx, 31, 0x1D2DC8u);
    ctx->pc = 0x1D2DC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2DC0u;
            // 0x1d2dc4: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193380u;
    if (runtime->hasFunction(0x193380u)) {
        auto targetFn = runtime->lookupFunction(0x193380u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2DC8u; }
        if (ctx->pc != 0x1D2DC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193380_0x193380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2DC8u; }
        if (ctx->pc != 0x1D2DC8u) { return; }
    }
    ctx->pc = 0x1D2DC8u;
label_1d2dc8:
    // 0x1d2dc8: 0x101040  sll         $v0, $s0, 1
    ctx->pc = 0x1d2dc8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
    // 0x1d2dcc: 0x26640190  addiu       $a0, $s3, 0x190
    ctx->pc = 0x1d2dccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 400));
    // 0x1d2dd0: 0x5d1021  addu        $v0, $v0, $sp
    ctx->pc = 0x1d2dd0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 29)));
    // 0x1d2dd4: 0x3250ffff  andi        $s0, $s2, 0xFFFF
    ctx->pc = 0x1d2dd4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)65535);
    // 0x1d2dd8: 0x245e0122  addiu       $fp, $v0, 0x122
    ctx->pc = 0x1d2dd8u;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 2), 290));
    // 0x1d2ddc: 0x101040  sll         $v0, $s0, 1
    ctx->pc = 0x1d2ddcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
    // 0x1d2de0: 0x97c30000  lhu         $v1, 0x0($fp)
    ctx->pc = 0x1d2de0u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1d2de4: 0x5d1021  addu        $v0, $v0, $sp
    ctx->pc = 0x1d2de4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 29)));
    // 0x1d2de8: 0x94420120  lhu         $v0, 0x120($v0)
    ctx->pc = 0x1d2de8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 288)));
    // 0x1d2dec: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1d2decu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1d2df0: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x1D2DF0u;
    {
        const bool branch_taken_0x1d2df0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D2DF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2DF0u;
            // 0x1d2df4: 0x3045ffff  andi        $a1, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2df0) {
            ctx->pc = 0x1D2E64u;
            goto label_1d2e64;
        }
    }
    ctx->pc = 0x1D2DF8u;
label_1d2df8:
    // 0x1d2df8: 0x8c820174  lw          $v0, 0x174($a0)
    ctx->pc = 0x1d2df8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 372)));
    // 0x1d2dfc: 0x4410017  bgez        $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x1D2DFCu;
    {
        const bool branch_taken_0x1d2dfc = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1D2E00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2DFCu;
            // 0x1d2e00: 0x24a20001  addiu       $v0, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2dfc) {
            ctx->pc = 0x1D2E5Cu;
            goto label_1d2e5c;
        }
    }
    ctx->pc = 0x1D2E04u;
    // 0x1d2e04: 0xc48100dc  lwc1        $f1, 0xDC($a0)
    ctx->pc = 0x1d2e04u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 220)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1d2e08: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x1d2e08u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x1d2e0c: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1d2e0cu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1d2e10: 0x0  nop
    ctx->pc = 0x1d2e10u;
    // NOP
    // 0x1d2e14: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1d2e14u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1d2e18: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1D2E18u;
    {
        const bool branch_taken_0x1d2e18 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1d2e18) {
            ctx->pc = 0x1D2E30u;
            goto label_1d2e30;
        }
    }
    ctx->pc = 0x1D2E20u;
    // 0x1d2e20: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1d2e20u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1d2e24: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1d2e24u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1d2e28: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1D2E28u;
    {
        const bool branch_taken_0x1d2e28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d2e28) {
            ctx->pc = 0x1D2E48u;
            goto label_1d2e48;
        }
    }
    ctx->pc = 0x1D2E30u;
label_1d2e30:
    // 0x1d2e30: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1d2e30u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1d2e34: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1d2e34u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1d2e38: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1d2e38u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1d2e3c: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1d2e3cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1d2e40: 0x0  nop
    ctx->pc = 0x1d2e40u;
    // NOP
    // 0x1d2e44: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1d2e44u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
label_1d2e48:
    // 0x1d2e48: 0x3c02004a  lui         $v0, 0x4A
    ctx->pc = 0x1d2e48u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)74 << 16));
    // 0x1d2e4c: 0x2442eef0  addiu       $v0, $v0, -0x1110
    ctx->pc = 0x1d2e4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294962928));
    // 0x1d2e50: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1d2e50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1d2e54: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1D2E54u;
    {
        const bool branch_taken_0x1d2e54 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D2E58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2E54u;
            // 0x1d2e58: 0xa0432b38  sb          $v1, 0x2B38($v0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 2), 11064), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2e54) {
            ctx->pc = 0x1D2E74u;
            goto label_1d2e74;
        }
    }
    ctx->pc = 0x1D2E5Cu;
label_1d2e5c:
    // 0x1d2e5c: 0x24840190  addiu       $a0, $a0, 0x190
    ctx->pc = 0x1d2e5cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 400));
    // 0x1d2e60: 0x3045ffff  andi        $a1, $v0, 0xFFFF
    ctx->pc = 0x1d2e60u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
label_1d2e64:
    // 0x1d2e64: 0x30a2ffff  andi        $v0, $a1, 0xFFFF
    ctx->pc = 0x1d2e64u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
    // 0x1d2e68: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x1d2e68u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1d2e6c: 0x1440ffe2  bnez        $v0, . + 4 + (-0x1E << 2)
    ctx->pc = 0x1D2E6Cu;
    {
        const bool branch_taken_0x1d2e6c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d2e6c) {
            ctx->pc = 0x1D2DF8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d2df8;
        }
    }
    ctx->pc = 0x1D2E74u;
label_1d2e74:
    // 0x1d2e74: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1d2e74u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d2e78: 0xc064c90  jal         func_193240
    ctx->pc = 0x1D2E78u;
    SET_GPR_U32(ctx, 31, 0x1D2E80u);
    ctx->pc = 0x1D2E7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2E78u;
            // 0x1d2e7c: 0x27a500d0  addiu       $a1, $sp, 0xD0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 208));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193240u;
    if (runtime->hasFunction(0x193240u)) {
        auto targetFn = runtime->lookupFunction(0x193240u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2E80u; }
        if (ctx->pc != 0x1D2E80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193240_0x193240(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2E80u; }
        if (ctx->pc != 0x1D2E80u) { return; }
    }
    ctx->pc = 0x1D2E80u;
label_1d2e80:
    // 0x1d2e80: 0x101840  sll         $v1, $s0, 1
    ctx->pc = 0x1d2e80u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
    // 0x1d2e84: 0x3c05004a  lui         $a1, 0x4A
    ctx->pc = 0x1d2e84u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)74 << 16));
    // 0x1d2e88: 0x701021  addu        $v0, $v1, $s0
    ctx->pc = 0x1d2e88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1d2e8c: 0x24a5eef0  addiu       $a1, $a1, -0x1110
    ctx->pc = 0x1d2e8cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294962928));
    // 0x1d2e90: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1d2e90u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1d2e94: 0xb02021  addu        $a0, $a1, $s0
    ctx->pc = 0x1d2e94u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 16)));
    // 0x1d2e98: 0xa21021  addu        $v0, $a1, $v0
    ctx->pc = 0x1d2e98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1d2e9c: 0x7d1821  addu        $v1, $v1, $sp
    ctx->pc = 0x1d2e9cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 29)));
    // 0x1d2ea0: 0xa0800004  sb          $zero, 0x4($a0)
    ctx->pc = 0x1d2ea0u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 4), (uint8_t)GPR_U32(ctx, 0));
    // 0x1d2ea4: 0x24422b50  addiu       $v0, $v0, 0x2B50
    ctx->pc = 0x1d2ea4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 11088));
    // 0x1d2ea8: 0x24760120  addiu       $s6, $v1, 0x120
    ctx->pc = 0x1d2ea8u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 3), 288));
    // 0x1d2eac: 0xafa200a0  sw          $v0, 0xA0($sp)
    ctx->pc = 0x1d2eacu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 160), GPR_U32(ctx, 2));
    // 0x1d2eb0: 0x96d00000  lhu         $s0, 0x0($s6)
    ctx->pc = 0x1d2eb0u;
    SET_GPR_U32(ctx, 16, (uint16_t)READ16(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x1d2eb4: 0x260882d  daddu       $s1, $s3, $zero
    ctx->pc = 0x1d2eb4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d2eb8: 0x1000002a  b           . + 4 + (0x2A << 2)
    ctx->pc = 0x1D2EB8u;
    {
        const bool branch_taken_0x1d2eb8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D2EBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2EB8u;
            // 0x1d2ebc: 0x24970004  addiu       $s7, $a0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2eb8) {
            ctx->pc = 0x1D2F64u;
            goto label_1d2f64;
        }
    }
    ctx->pc = 0x1D2EC0u;
label_1d2ec0:
    // 0x1d2ec0: 0x96c20000  lhu         $v0, 0x0($s6)
    ctx->pc = 0x1d2ec0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x1d2ec4: 0x14620004  bne         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1D2EC4u;
    {
        const bool branch_taken_0x1d2ec4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1d2ec4) {
            ctx->pc = 0x1D2ED8u;
            goto label_1d2ed8;
        }
    }
    ctx->pc = 0x1D2ECCu;
    // 0x1d2ecc: 0x8fa400a0  lw          $a0, 0xA0($sp)
    ctx->pc = 0x1d2eccu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x1d2ed0: 0xc064038  jal         func_1900E0
    ctx->pc = 0x1D2ED0u;
    SET_GPR_U32(ctx, 31, 0x1D2ED8u);
    ctx->pc = 0x1D2ED4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2ED0u;
            // 0x1d2ed4: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1900E0u;
    if (runtime->hasFunction(0x1900E0u)) {
        auto targetFn = runtime->lookupFunction(0x1900E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2ED8u; }
        if (ctx->pc != 0x1D2ED8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001900E0_0x1900e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2ED8u; }
        if (ctx->pc != 0x1D2ED8u) { return; }
    }
    ctx->pc = 0x1D2ED8u;
label_1d2ed8:
    // 0x1d2ed8: 0x8e220174  lw          $v0, 0x174($s1)
    ctx->pc = 0x1d2ed8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 372)));
    // 0x1d2edc: 0x440001e  bltz        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x1D2EDCu;
    {
        const bool branch_taken_0x1d2edc = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1D2EE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2EDCu;
            // 0x1d2ee0: 0x21980  sll         $v1, $v0, 6 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2edc) {
            ctx->pc = 0x1D2F58u;
            goto label_1d2f58;
        }
    }
    ctx->pc = 0x1D2EE4u;
    // 0x1d2ee4: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x1d2ee4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1d2ee8: 0x8fa200c0  lw          $v0, 0xC0($sp)
    ctx->pc = 0x1d2ee8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 192)));
    // 0x1d2eec: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1d2eecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d2ef0: 0x433021  addu        $a2, $v0, $v1
    ctx->pc = 0x1d2ef0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_1d2ef4:
    // 0x1d2ef4: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x1d2ef4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1d2ef8: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x1d2ef8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x1d2efc: 0x8ca20004  lw          $v0, 0x4($a1)
    ctx->pc = 0x1d2efcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x1d2f00: 0xacc30000  sw          $v1, 0x0($a2)
    ctx->pc = 0x1d2f00u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 3));
    // 0x1d2f04: 0x24a50008  addiu       $a1, $a1, 0x8
    ctx->pc = 0x1d2f04u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8));
    // 0x1d2f08: 0xacc20004  sw          $v0, 0x4($a2)
    ctx->pc = 0x1d2f08u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 2));
    // 0x1d2f0c: 0x1c80fff9  bgtz        $a0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1D2F0Cu;
    {
        const bool branch_taken_0x1d2f0c = (GPR_S64(ctx, 4) > 0);
        ctx->pc = 0x1D2F10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2F0Cu;
            // 0x1d2f10: 0x24c60008  addiu       $a2, $a2, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2f0c) {
            ctx->pc = 0x1D2EF4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d2ef4;
        }
    }
    ctx->pc = 0x1D2F14u;
    // 0x1d2f14: 0x8e220174  lw          $v0, 0x174($s1)
    ctx->pc = 0x1d2f14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 372)));
    // 0x1d2f18: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x1d2f18u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1d2f1c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1d2f1cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d2f20: 0x21980  sll         $v1, $v0, 6
    ctx->pc = 0x1d2f20u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 6));
    // 0x1d2f24: 0x8fa200b0  lw          $v0, 0xB0($sp)
    ctx->pc = 0x1d2f24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x1d2f28: 0x433021  addu        $a2, $v0, $v1
    ctx->pc = 0x1d2f28u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_1d2f2c:
    // 0x1d2f2c: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x1d2f2cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1d2f30: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x1d2f30u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x1d2f34: 0x8ca20004  lw          $v0, 0x4($a1)
    ctx->pc = 0x1d2f34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x1d2f38: 0xacc30000  sw          $v1, 0x0($a2)
    ctx->pc = 0x1d2f38u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 3));
    // 0x1d2f3c: 0x24a50008  addiu       $a1, $a1, 0x8
    ctx->pc = 0x1d2f3cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8));
    // 0x1d2f40: 0xacc20004  sw          $v0, 0x4($a2)
    ctx->pc = 0x1d2f40u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 2));
    // 0x1d2f44: 0x1c80fff9  bgtz        $a0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1D2F44u;
    {
        const bool branch_taken_0x1d2f44 = (GPR_S64(ctx, 4) > 0);
        ctx->pc = 0x1D2F48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2F44u;
            // 0x1d2f48: 0x24c60008  addiu       $a2, $a2, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2f44) {
            ctx->pc = 0x1D2F2Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d2f2c;
        }
    }
    ctx->pc = 0x1D2F4Cu;
    // 0x1d2f4c: 0x92e20000  lbu         $v0, 0x0($s7)
    ctx->pc = 0x1d2f4cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 23), 0)));
    // 0x1d2f50: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1d2f50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1d2f54: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1d2f54u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
label_1d2f58:
    // 0x1d2f58: 0x26020001  addiu       $v0, $s0, 0x1
    ctx->pc = 0x1d2f58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1d2f5c: 0x26310190  addiu       $s1, $s1, 0x190
    ctx->pc = 0x1d2f5cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 400));
    // 0x1d2f60: 0x3050ffff  andi        $s0, $v0, 0xFFFF
    ctx->pc = 0x1d2f60u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
label_1d2f64:
    // 0x1d2f64: 0x97c20000  lhu         $v0, 0x0($fp)
    ctx->pc = 0x1d2f64u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1d2f68: 0x3203ffff  andi        $v1, $s0, 0xFFFF
    ctx->pc = 0x1d2f68u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)65535);
    // 0x1d2f6c: 0x62102a  slt         $v0, $v1, $v0
    ctx->pc = 0x1d2f6cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1d2f70: 0x1440ffd3  bnez        $v0, . + 4 + (-0x2D << 2)
    ctx->pc = 0x1D2F70u;
    {
        const bool branch_taken_0x1d2f70 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d2f70) {
            ctx->pc = 0x1D2EC0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d2ec0;
        }
    }
    ctx->pc = 0x1D2F78u;
    // 0x1d2f78: 0xc064960  jal         func_192580
    ctx->pc = 0x1D2F78u;
    SET_GPR_U32(ctx, 31, 0x1D2F80u);
    ctx->pc = 0x1D2F7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2F78u;
            // 0x1d2f7c: 0x8ea4080c  lw          $a0, 0x80C($s5) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 2060)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x192580u;
    if (runtime->hasFunction(0x192580u)) {
        auto targetFn = runtime->lookupFunction(0x192580u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2F80u; }
        if (ctx->pc != 0x1D2F80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00192580_0x192580(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2F80u; }
        if (ctx->pc != 0x1D2F80u) { return; }
    }
    ctx->pc = 0x1D2F80u;
label_1d2f80:
    // 0x1d2f80: 0xc06c444  jal         func_1B1110
    ctx->pc = 0x1D2F80u;
    SET_GPR_U32(ctx, 31, 0x1D2F88u);
    ctx->pc = 0x1D2F84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2F80u;
            // 0x1d2f84: 0x8ea4080c  lw          $a0, 0x80C($s5) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 2060)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B1110u;
    if (runtime->hasFunction(0x1B1110u)) {
        auto targetFn = runtime->lookupFunction(0x1B1110u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2F88u; }
        if (ctx->pc != 0x1D2F88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1110_0x1b1110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2F88u; }
        if (ctx->pc != 0x1D2F88u) { return; }
    }
    ctx->pc = 0x1D2F88u;
label_1d2f88:
    // 0x1d2f88: 0x26430001  addiu       $v1, $s2, 0x1
    ctx->pc = 0x1d2f88u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x1d2f8c: 0xaea0080c  sw          $zero, 0x80C($s5)
    ctx->pc = 0x1d2f8cu;
    WRITE32(ADD32(GPR_U32(ctx, 21), 2060), GPR_U32(ctx, 0));
    // 0x1d2f90: 0x3072ffff  andi        $s2, $v1, 0xFFFF
    ctx->pc = 0x1d2f90u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65535);
label_1d2f94:
    // 0x1d2f94: 0x3c01004a  lui         $at, 0x4A
    ctx->pc = 0x1d2f94u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)74 << 16));
    // 0x1d2f98: 0x3250ffff  andi        $s0, $s2, 0xFFFF
    ctx->pc = 0x1d2f98u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)65535);
    // 0x1d2f9c: 0x9023eef3  lbu         $v1, -0x110D($at)
    ctx->pc = 0x1d2f9cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294962931)));
    // 0x1d2fa0: 0x203182a  slt         $v1, $s0, $v1
    ctx->pc = 0x1d2fa0u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1d2fa4: 0x1460ff7c  bnez        $v1, . + 4 + (-0x84 << 2)
    ctx->pc = 0x1D2FA4u;
    {
        const bool branch_taken_0x1d2fa4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D2FA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2FA4u;
            // 0x1d2fa8: 0x3247ffff  andi        $a3, $s2, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2fa4) {
            ctx->pc = 0x1D2D98u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d2d98;
        }
    }
    ctx->pc = 0x1D2FACu;
    // 0x1d2fac: 0xdfbf0090  ld          $ra, 0x90($sp)
    ctx->pc = 0x1d2facu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x1d2fb0: 0x7bbe0080  lq          $fp, 0x80($sp)
    ctx->pc = 0x1d2fb0u;
    SET_GPR_VEC(ctx, 30, READ128(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x1d2fb4: 0x7bb70070  lq          $s7, 0x70($sp)
    ctx->pc = 0x1d2fb4u;
    SET_GPR_VEC(ctx, 23, READ128(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1d2fb8: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x1d2fb8u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1d2fbc: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1d2fbcu;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1d2fc0: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1d2fc0u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d2fc4: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d2fc4u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d2fc8: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d2fc8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d2fcc: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d2fccu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d2fd0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d2fd0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d2fd4: 0x3e00008  jr          $ra
    ctx->pc = 0x1D2FD4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D2FD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2FD4u;
            // 0x1d2fd8: 0x27bd0160  addiu       $sp, $sp, 0x160 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 352));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D2CF4u: goto label_1d2cf4;
            case 0x1D2D00u: goto label_1d2d00;
            case 0x1D2D10u: goto label_1d2d10;
            case 0x1D2D28u: goto label_1d2d28;
            case 0x1D2D50u: goto label_1d2d50;
            case 0x1D2D90u: goto label_1d2d90;
            case 0x1D2D98u: goto label_1d2d98;
            case 0x1D2DA8u: goto label_1d2da8;
            case 0x1D2DB0u: goto label_1d2db0;
            case 0x1D2DBCu: goto label_1d2dbc;
            case 0x1D2DC8u: goto label_1d2dc8;
            case 0x1D2DF8u: goto label_1d2df8;
            case 0x1D2E30u: goto label_1d2e30;
            case 0x1D2E48u: goto label_1d2e48;
            case 0x1D2E5Cu: goto label_1d2e5c;
            case 0x1D2E64u: goto label_1d2e64;
            case 0x1D2E74u: goto label_1d2e74;
            case 0x1D2E80u: goto label_1d2e80;
            case 0x1D2EC0u: goto label_1d2ec0;
            case 0x1D2ED8u: goto label_1d2ed8;
            case 0x1D2EF4u: goto label_1d2ef4;
            case 0x1D2F2Cu: goto label_1d2f2c;
            case 0x1D2F58u: goto label_1d2f58;
            case 0x1D2F64u: goto label_1d2f64;
            case 0x1D2F80u: goto label_1d2f80;
            case 0x1D2F88u: goto label_1d2f88;
            case 0x1D2F94u: goto label_1d2f94;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D2FDCu;
    // 0x1d2fdc: 0x0  nop
    ctx->pc = 0x1d2fdcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
