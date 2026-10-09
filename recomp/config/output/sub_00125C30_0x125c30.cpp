#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00125C30
// Address: 0x125c30 - 0x126410
void sub_00125C30_0x125c30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00125C30_0x125c30");
#endif

    switch (ctx->pc) {
        case 0x125c88u: goto label_125c88;
        case 0x125ca0u: goto label_125ca0;
        case 0x125ce0u: goto label_125ce0;
        case 0x125cf8u: goto label_125cf8;
        case 0x125e60u: goto label_125e60;
        case 0x125eccu: goto label_125ecc;
        case 0x125f60u: goto label_125f60;
        case 0x125f94u: goto label_125f94;
        case 0x125fb4u: goto label_125fb4;
        case 0x126010u: goto label_126010;
        case 0x126050u: goto label_126050;
        case 0x1260b4u: goto label_1260b4;
        case 0x1260d8u: goto label_1260d8;
        case 0x12610cu: goto label_12610c;
        case 0x12612cu: goto label_12612c;
        case 0x126190u: goto label_126190;
        case 0x1261e8u: goto label_1261e8;
        case 0x12624cu: goto label_12624c;
        case 0x126270u: goto label_126270;
        case 0x1262a4u: goto label_1262a4;
        case 0x1262c4u: goto label_1262c4;
        case 0x126320u: goto label_126320;
        case 0x126380u: goto label_126380;
        case 0x1263ecu: goto label_1263ec;
        default: break;
    }

    ctx->pc = 0x125c30u;

label_125c30:
    // 0x125c30: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x125c30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x125c34: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x125c34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x125c38: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x125c38u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125c3c: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x125c3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x125c40: 0x3c110021  lui         $s1, 0x21
    ctx->pc = 0x125c40u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)33 << 16));
    // 0x125c44: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x125c44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x125c48: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x125c48u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125c4c: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x125c4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x125c50: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x125c50u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125c54: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x125c54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x125c58: 0x100a02d  daddu       $s4, $t0, $zero
    ctx->pc = 0x125c58u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125c5c: 0xffb60040  sd          $s6, 0x40($sp)
    ctx->pc = 0x125c5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
    // 0x125c60: 0x140b02d  daddu       $s6, $t2, $zero
    ctx->pc = 0x125c60u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125c64: 0xffb70048  sd          $s7, 0x48($sp)
    ctx->pc = 0x125c64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 23));
    // 0x125c68: 0x120b82d  daddu       $s7, $t1, $zero
    ctx->pc = 0x125c68u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125c6c: 0xffbe0050  sd          $fp, 0x50($sp)
    ctx->pc = 0x125c6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 30));
    // 0x125c70: 0xc0f02d  daddu       $fp, $a2, $zero
    ctx->pc = 0x125c70u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125c74: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x125c74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x125c78: 0xffbf0058  sd          $ra, 0x58($sp)
    ctx->pc = 0x125c78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x125c7c: 0xafa70000  sw          $a3, 0x0($sp)
    ctx->pc = 0x125c7cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 7));
    // 0x125c80: 0xafab0004  sw          $t3, 0x4($sp)
    ctx->pc = 0x125c80u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 11));
    // 0x125c84: 0x0  nop
    ctx->pc = 0x125c84u;
    // NOP
label_125c88:
    // 0x125c88: 0x212102a  slt         $v0, $s0, $s2
    ctx->pc = 0x125c88u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x125c8c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x125C8Cu;
    {
        const bool branch_taken_0x125c8c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x125C90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125C8Cu;
            // 0x125c90: 0x8e25c798  lw          $a1, -0x3868($s1) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4294952856)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125c8c) {
            ctx->pc = 0x125CA8u;
            goto label_125ca8;
        }
    }
    ctx->pc = 0x125C94u;
    // 0x125c94: 0x2702021  addu        $a0, $s3, $s0
    ctx->pc = 0x125c94u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 16)));
    // 0x125c98: 0xc041e86  jal         func_107A18
    ctx->pc = 0x125C98u;
    SET_GPR_U32(ctx, 31, 0x125CA0u);
    ctx->pc = 0x125C9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x125C98u;
            // 0x125c9c: 0x24060004  addiu       $a2, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107A18u;
    if (runtime->hasFunction(0x107A18u)) {
        auto targetFn = runtime->lookupFunction(0x107A18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125CA0u; }
        if (ctx->pc != 0x125CA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107A18_0x107a18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125CA0u; }
        if (ctx->pc != 0x125CA0u) { return; }
    }
    ctx->pc = 0x125CA0u;
label_125ca0:
    // 0x125ca0: 0x5440fff9  bnel        $v0, $zero, . + 4 + (-0x7 << 2)
    ctx->pc = 0x125CA0u;
    {
        const bool branch_taken_0x125ca0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x125ca0) {
            ctx->pc = 0x125CA4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x125CA0u;
            // 0x125ca4: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x125C88u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_125c88;
        }
    }
    ctx->pc = 0x125CA8u;
label_125ca8:
    // 0x125ca8: 0x12120061  beq         $s0, $s2, . + 4 + (0x61 << 2)
    ctx->pc = 0x125CA8u;
    {
        const bool branch_taken_0x125ca8 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 18));
        ctx->pc = 0x125CACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125CA8u;
            // 0x125cac: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125ca8) {
            ctx->pc = 0x125E30u;
            goto label_125e30;
        }
    }
    ctx->pc = 0x125CB0u;
    // 0x125cb0: 0x32030003  andi        $v1, $s0, 0x3
    ctx->pc = 0x125cb0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)3);
    // 0x125cb4: 0x5460005f  bnel        $v1, $zero, . + 4 + (0x5F << 2)
    ctx->pc = 0x125CB4u;
    {
        const bool branch_taken_0x125cb4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x125cb4) {
            ctx->pc = 0x125CB8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x125CB4u;
            // 0x125cb8: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x125E34u;
            goto label_125e34;
        }
    }
    ctx->pc = 0x125CBCu;
    // 0x125cbc: 0x2702021  addu        $a0, $s3, $s0
    ctx->pc = 0x125cbcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 16)));
    // 0x125cc0: 0x24910008  addiu       $s1, $a0, 0x8
    ctx->pc = 0x125cc0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
    // 0x125cc4: 0x86230000  lh          $v1, 0x0($s1)
    ctx->pc = 0x125cc4u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x125cc8: 0x28630002  slti        $v1, $v1, 0x2
    ctx->pc = 0x125cc8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x125ccc: 0x50600059  beql        $v1, $zero, . + 4 + (0x59 << 2)
    ctx->pc = 0x125CCCu;
    {
        const bool branch_taken_0x125ccc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x125ccc) {
            ctx->pc = 0x125CD0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x125CCCu;
            // 0x125cd0: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x125E34u;
            goto label_125e34;
        }
    }
    ctx->pc = 0x125CD4u;
    // 0x125cd4: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x125cd4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125cd8: 0x3c150021  lui         $s5, 0x21
    ctx->pc = 0x125cd8u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)33 << 16));
    // 0x125cdc: 0x0  nop
    ctx->pc = 0x125cdcu;
    // NOP
label_125ce0:
    // 0x125ce0: 0x212102a  slt         $v0, $s0, $s2
    ctx->pc = 0x125ce0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x125ce4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x125CE4u;
    {
        const bool branch_taken_0x125ce4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x125CE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125CE4u;
            // 0x125ce8: 0x8ea5c79c  lw          $a1, -0x3864($s5) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 4294952860)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125ce4) {
            ctx->pc = 0x125D00u;
            goto label_125d00;
        }
    }
    ctx->pc = 0x125CECu;
    // 0x125cec: 0x2702021  addu        $a0, $s3, $s0
    ctx->pc = 0x125cecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 16)));
    // 0x125cf0: 0xc041e86  jal         func_107A18
    ctx->pc = 0x125CF0u;
    SET_GPR_U32(ctx, 31, 0x125CF8u);
    ctx->pc = 0x125CF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x125CF0u;
            // 0x125cf4: 0x24060004  addiu       $a2, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107A18u;
    if (runtime->hasFunction(0x107A18u)) {
        auto targetFn = runtime->lookupFunction(0x107A18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125CF8u; }
        if (ctx->pc != 0x125CF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107A18_0x107a18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125CF8u; }
        if (ctx->pc != 0x125CF8u) { return; }
    }
    ctx->pc = 0x125CF8u;
label_125cf8:
    // 0x125cf8: 0x5440fff9  bnel        $v0, $zero, . + 4 + (-0x7 << 2)
    ctx->pc = 0x125CF8u;
    {
        const bool branch_taken_0x125cf8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x125cf8) {
            ctx->pc = 0x125CFCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x125CF8u;
            // 0x125cfc: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x125CE0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_125ce0;
        }
    }
    ctx->pc = 0x125D00u;
label_125d00:
    // 0x125d00: 0x1212004b  beq         $s0, $s2, . + 4 + (0x4B << 2)
    ctx->pc = 0x125D00u;
    {
        const bool branch_taken_0x125d00 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 18));
        ctx->pc = 0x125D04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125D00u;
            // 0x125d04: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125d00) {
            ctx->pc = 0x125E30u;
            goto label_125e30;
        }
    }
    ctx->pc = 0x125D08u;
    // 0x125d08: 0x26020008  addiu       $v0, $s0, 0x8
    ctx->pc = 0x125d08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
    // 0x125d0c: 0x2701821  addu        $v1, $s3, $s0
    ctx->pc = 0x125d0cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 16)));
    // 0x125d10: 0xa7c20000  sh          $v0, 0x0($fp)
    ctx->pc = 0x125d10u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x125d14: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x125d14u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x125d18: 0x8c660004  lw          $a2, 0x4($v1)
    ctx->pc = 0x125d18u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x125d1c: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x125d1cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x125d20: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x125d20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x125d24: 0x24080010  addiu       $t0, $zero, 0x10
    ctx->pc = 0x125d24u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x125d28: 0xa0440000  sb          $a0, 0x0($v0)
    ctx->pc = 0x125d28u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x125d2c: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x125d2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x125d30: 0x8fa40004  lw          $a0, 0x4($sp)
    ctx->pc = 0x125d30u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x125d34: 0x92230002  lbu         $v1, 0x2($s1)
    ctx->pc = 0x125d34u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x125d38: 0xac820000  sw          $v0, 0x0($a0)
    ctx->pc = 0x125d38u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x125d3c: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x125d3cu;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x125d40: 0x9222000e  lbu         $v0, 0xE($s1)
    ctx->pc = 0x125d40u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 14)));
    // 0x125d44: 0xa2820000  sb          $v0, 0x0($s4)
    ctx->pc = 0x125d44u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x125d48: 0x9223000c  lbu         $v1, 0xC($s1)
    ctx->pc = 0x125d48u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x125d4c: 0x31600  sll         $v0, $v1, 24
    ctx->pc = 0x125d4cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x125d50: 0xa2e30000  sb          $v1, 0x0($s7)
    ctx->pc = 0x125d50u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x125d54: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x125d54u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x125d58: 0xc2001a  div         $zero, $a2, $v0
    ctx->pc = 0x125d58u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 6);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x125d5c: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x125D5Cu;
    {
        const bool branch_taken_0x125d5c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x125d5c) {
            ctx->pc = 0x125D60u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x125D5Cu;
            // 0x125d60: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x125D64u;
            goto label_125d64;
        }
    }
    ctx->pc = 0x125D64u;
label_125d64:
    // 0x125d64: 0x8fa20060  lw          $v0, 0x60($sp)
    ctx->pc = 0x125d64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x125d68: 0x1812  mflo        $v1
    ctx->pc = 0x125d68u;
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x125d6c: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x125d6cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x125d70: 0x8fa40068  lw          $a0, 0x68($sp)
    ctx->pc = 0x125d70u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x125d74: 0xac870000  sw          $a3, 0x0($a0)
    ctx->pc = 0x125d74u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 7));
    // 0x125d78: 0x82850000  lb          $a1, 0x0($s4)
    ctx->pc = 0x125d78u;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x125d7c: 0x14a80004  bne         $a1, $t0, . + 4 + (0x4 << 2)
    ctx->pc = 0x125D7Cu;
    {
        const bool branch_taken_0x125d7c = (GPR_U64(ctx, 5) != GPR_U64(ctx, 8));
        ctx->pc = 0x125D80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125D7Cu;
            // 0x125d80: 0x92830000  lbu         $v1, 0x0($s4) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 20), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125d7c) {
            ctx->pc = 0x125D90u;
            goto label_125d90;
        }
    }
    ctx->pc = 0x125D84u;
    // 0x125d84: 0x8fa20070  lw          $v0, 0x70($sp)
    ctx->pc = 0x125d84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x125d88: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x125D88u;
    {
        const bool branch_taken_0x125d88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x125D8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125D88u;
            // 0x125d8c: 0xa4400000  sh          $zero, 0x0($v0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125d88) {
            ctx->pc = 0x125DF8u;
            goto label_125df8;
        }
    }
    ctx->pc = 0x125D90u;
label_125d90:
    // 0x125d90: 0x24020008  addiu       $v0, $zero, 0x8
    ctx->pc = 0x125d90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x125d94: 0x14a20004  bne         $a1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x125D94u;
    {
        const bool branch_taken_0x125d94 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        ctx->pc = 0x125D98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125D94u;
            // 0x125d98: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125d94) {
            ctx->pc = 0x125DA8u;
            goto label_125da8;
        }
    }
    ctx->pc = 0x125D9Cu;
    // 0x125d9c: 0x8fa40070  lw          $a0, 0x70($sp)
    ctx->pc = 0x125d9cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x125da0: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x125DA0u;
    {
        const bool branch_taken_0x125da0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x125DA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125DA0u;
            // 0x125da4: 0xa4870000  sh          $a3, 0x0($a0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125da0) {
            ctx->pc = 0x125DF8u;
            goto label_125df8;
        }
    }
    ctx->pc = 0x125DA8u;
label_125da8:
    // 0x125da8: 0x14a20014  bne         $a1, $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x125DA8u;
    {
        const bool branch_taken_0x125da8 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        ctx->pc = 0x125DACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125DA8u;
            // 0x125dac: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125da8) {
            ctx->pc = 0x125DFCu;
            goto label_125dfc;
        }
    }
    ctx->pc = 0x125DB0u;
    // 0x125db0: 0x82c20000  lb          $v0, 0x0($s6)
    ctx->pc = 0x125db0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x125db4: 0x61fc2  srl         $v1, $a2, 31
    ctx->pc = 0x125db4u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 6), 31));
    // 0x125db8: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x125db8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x125dbc: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x125dbcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x125dc0: 0x31843  sra         $v1, $v1, 1
    ctx->pc = 0x125dc0u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 1));
    // 0x125dc4: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x125dc4u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x125dc8: 0x8fa20068  lw          $v0, 0x68($sp)
    ctx->pc = 0x125dc8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x125dcc: 0xac450000  sw          $a1, 0x0($v0)
    ctx->pc = 0x125dccu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 5));
    // 0x125dd0: 0x82c20000  lb          $v0, 0x0($s6)
    ctx->pc = 0x125dd0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x125dd4: 0x62001a  div         $zero, $v1, $v0
    ctx->pc = 0x125dd4u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x125dd8: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x125DD8u;
    {
        const bool branch_taken_0x125dd8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x125dd8) {
            ctx->pc = 0x125DDCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x125DD8u;
            // 0x125ddc: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x125DE0u;
            goto label_125de0;
        }
    }
    ctx->pc = 0x125DE0u;
label_125de0:
    // 0x125de0: 0x8fa20060  lw          $v0, 0x60($sp)
    ctx->pc = 0x125de0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x125de4: 0x1812  mflo        $v1
    ctx->pc = 0x125de4u;
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x125de8: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x125de8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x125dec: 0xa2880000  sb          $t0, 0x0($s4)
    ctx->pc = 0x125decu;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 8));
    // 0x125df0: 0x8fa20070  lw          $v0, 0x70($sp)
    ctx->pc = 0x125df0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x125df4: 0xa4440000  sh          $a0, 0x0($v0)
    ctx->pc = 0x125df4u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 4));
label_125df8:
    // 0x125df8: 0x92830000  lbu         $v1, 0x0($s4)
    ctx->pc = 0x125df8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 20), 0)));
label_125dfc:
    // 0x125dfc: 0x1060000c  beqz        $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x125DFCu;
    {
        const bool branch_taken_0x125dfc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x125E00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125DFCu;
            // 0x125e00: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125dfc) {
            ctx->pc = 0x125E30u;
            goto label_125e30;
        }
    }
    ctx->pc = 0x125E04u;
    // 0x125e04: 0x82e30000  lb          $v1, 0x0($s7)
    ctx->pc = 0x125e04u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 23), 0)));
    // 0x125e08: 0x1060000a  beqz        $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x125E08u;
    {
        const bool branch_taken_0x125e08 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x125E0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125E08u;
            // 0x125e0c: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125e08) {
            ctx->pc = 0x125E34u;
            goto label_125e34;
        }
    }
    ctx->pc = 0x125E10u;
    // 0x125e10: 0x92c30000  lbu         $v1, 0x0($s6)
    ctx->pc = 0x125e10u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x125e14: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x125e14u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x125e18: 0x2c630002  sltiu       $v1, $v1, 0x2
    ctx->pc = 0x125e18u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x125e1c: 0x10600006  beqz        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x125E1Cu;
    {
        const bool branch_taken_0x125e1c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x125E20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125E1Cu;
            // 0x125e20: 0xdfb10018  ld          $s1, 0x18($sp) (Delay Slot)
        SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125e1c) {
            ctx->pc = 0x125E38u;
            goto label_125e38;
        }
    }
    ctx->pc = 0x125E24u;
    // 0x125e24: 0x8fa40004  lw          $a0, 0x4($sp)
    ctx->pc = 0x125e24u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x125e28: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x125e28u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x125e2c: 0x3100b  movn        $v0, $zero, $v1
    ctx->pc = 0x125e2cu;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 0));
label_125e30:
    // 0x125e30: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x125e30u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_125e34:
    // 0x125e34: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x125e34u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
label_125e38:
    // 0x125e38: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x125e38u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x125e3c: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x125e3cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x125e40: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x125e40u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x125e44: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x125e44u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x125e48: 0xdfb60040  ld          $s6, 0x40($sp)
    ctx->pc = 0x125e48u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x125e4c: 0xdfb70048  ld          $s7, 0x48($sp)
    ctx->pc = 0x125e4cu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x125e50: 0xdfbe0050  ld          $fp, 0x50($sp)
    ctx->pc = 0x125e50u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x125e54: 0xdfbf0058  ld          $ra, 0x58($sp)
    ctx->pc = 0x125e54u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x125e58: 0x3e00008  jr          $ra
    ctx->pc = 0x125E58u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x125E5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125E58u;
            // 0x125e5c: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x125C30u: goto label_125c30;
            case 0x125C88u: goto label_125c88;
            case 0x125CA0u: goto label_125ca0;
            case 0x125CA8u: goto label_125ca8;
            case 0x125CE0u: goto label_125ce0;
            case 0x125CF8u: goto label_125cf8;
            case 0x125D00u: goto label_125d00;
            case 0x125D64u: goto label_125d64;
            case 0x125D90u: goto label_125d90;
            case 0x125DA8u: goto label_125da8;
            case 0x125DE0u: goto label_125de0;
            case 0x125DF8u: goto label_125df8;
            case 0x125DFCu: goto label_125dfc;
            case 0x125E30u: goto label_125e30;
            case 0x125E34u: goto label_125e34;
            case 0x125E38u: goto label_125e38;
            case 0x125E60u: goto label_125e60;
            case 0x125ECCu: goto label_125ecc;
            case 0x125EE0u: goto label_125ee0;
            case 0x125F3Cu: goto label_125f3c;
            case 0x125F60u: goto label_125f60;
            case 0x125F94u: goto label_125f94;
            case 0x125FB4u: goto label_125fb4;
            case 0x126010u: goto label_126010;
            case 0x126048u: goto label_126048;
            case 0x126050u: goto label_126050;
            case 0x126074u: goto label_126074;
            case 0x126094u: goto label_126094;
            case 0x1260B4u: goto label_1260b4;
            case 0x1260C0u: goto label_1260c0;
            case 0x1260D8u: goto label_1260d8;
            case 0x12610Cu: goto label_12610c;
            case 0x12612Cu: goto label_12612c;
            case 0x126190u: goto label_126190;
            case 0x1261D8u: goto label_1261d8;
            case 0x1261E8u: goto label_1261e8;
            case 0x126210u: goto label_126210;
            case 0x12622Cu: goto label_12622c;
            case 0x12624Cu: goto label_12624c;
            case 0x126258u: goto label_126258;
            case 0x126270u: goto label_126270;
            case 0x1262A4u: goto label_1262a4;
            case 0x1262C4u: goto label_1262c4;
            case 0x126320u: goto label_126320;
            case 0x126370u: goto label_126370;
            case 0x126380u: goto label_126380;
            case 0x1263ACu: goto label_1263ac;
            case 0x1263CCu: goto label_1263cc;
            case 0x1263ECu: goto label_1263ec;
            case 0x1263F8u: goto label_1263f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x125E60u;
label_125e60:
    // 0x125e60: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x125e60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x125e64: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x125e64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x125e68: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x125e68u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125e6c: 0xffb40050  sd          $s4, 0x50($sp)
    ctx->pc = 0x125e6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 20));
    // 0x125e70: 0x24140001  addiu       $s4, $zero, 0x1
    ctx->pc = 0x125e70u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x125e74: 0xffb10038  sd          $s1, 0x38($sp)
    ctx->pc = 0x125e74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x125e78: 0x2611000e  addiu       $s1, $s0, 0xE
    ctx->pc = 0x125e78u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 14));
    // 0x125e7c: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x125e7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x125e80: 0x26120010  addiu       $s2, $s0, 0x10
    ctx->pc = 0x125e80u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
    // 0x125e84: 0xffb30048  sd          $s3, 0x48($sp)
    ctx->pc = 0x125e84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 19));
    // 0x125e88: 0x2613000f  addiu       $s3, $s0, 0xF
    ctx->pc = 0x125e88u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 16), 15));
    // 0x125e8c: 0xffbf0058  sd          $ra, 0x58($sp)
    ctx->pc = 0x125e8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x125e90: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x125e90u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125e94: 0xa6140002  sh          $s4, 0x2($s0)
    ctx->pc = 0x125e94u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 20));
    // 0x125e98: 0x26020018  addiu       $v0, $s0, 0x18
    ctx->pc = 0x125e98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 24));
    // 0x125e9c: 0xc0282d  daddu       $a1, $a2, $zero
    ctx->pc = 0x125e9cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125ea0: 0x27a60020  addiu       $a2, $sp, 0x20
    ctx->pc = 0x125ea0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x125ea4: 0x2603009a  addiu       $v1, $s0, 0x9A
    ctx->pc = 0x125ea4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 154));
    // 0x125ea8: 0x2607000c  addiu       $a3, $s0, 0xC
    ctx->pc = 0x125ea8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 12));
    // 0x125eac: 0x2608000d  addiu       $t0, $s0, 0xD
    ctx->pc = 0x125eacu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 16), 13));
    // 0x125eb0: 0x260482d  daddu       $t1, $s3, $zero
    ctx->pc = 0x125eb0u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125eb4: 0x220502d  daddu       $t2, $s1, $zero
    ctx->pc = 0x125eb4u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125eb8: 0x260b0014  addiu       $t3, $s0, 0x14
    ctx->pc = 0x125eb8u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 16), 20));
    // 0x125ebc: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x125ebcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x125ec0: 0xafa30010  sw          $v1, 0x10($sp)
    ctx->pc = 0x125ec0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 3));
    // 0x125ec4: 0xc04970c  jal         func_125C30
    ctx->pc = 0x125EC4u;
    SET_GPR_U32(ctx, 31, 0x125ECCu);
    ctx->pc = 0x125EC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x125EC4u;
            // 0x125ec8: 0xafb20008  sw          $s2, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
    ctx->pc = 0x125C30u;
    goto label_125c30;
    ctx->pc = 0x125ECCu;
label_125ecc:
    // 0x125ecc: 0x4430004  bgezl       $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x125ECCu;
    {
        const bool branch_taken_0x125ecc = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x125ecc) {
            ctx->pc = 0x125ED0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x125ECCu;
            // 0x125ed0: 0xae000034  sw          $zero, 0x34($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x125EE0u;
            goto label_125ee0;
        }
    }
    ctx->pc = 0x125ED4u;
    // 0x125ed4: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x125ED4u;
    {
        const bool branch_taken_0x125ed4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x125ED8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125ED4u;
            // 0x125ed8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125ed4) {
            ctx->pc = 0x125F3Cu;
            goto label_125f3c;
        }
    }
    ctx->pc = 0x125EDCu;
    // 0x125edc: 0x0  nop
    ctx->pc = 0x125edcu;
    // NOP
label_125ee0:
    // 0x125ee0: 0xae000030  sw          $zero, 0x30($s0)
    ctx->pc = 0x125ee0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
    // 0x125ee4: 0xae00002c  sw          $zero, 0x2C($s0)
    ctx->pc = 0x125ee4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 0));
    // 0x125ee8: 0xae000028  sw          $zero, 0x28($s0)
    ctx->pc = 0x125ee8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 0));
    // 0x125eec: 0xae000020  sw          $zero, 0x20($s0)
    ctx->pc = 0x125eecu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 0));
    // 0x125ef0: 0xa600001c  sh          $zero, 0x1C($s0)
    ctx->pc = 0x125ef0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 28), (uint16_t)GPR_U32(ctx, 0));
    // 0x125ef4: 0xa6000026  sh          $zero, 0x26($s0)
    ctx->pc = 0x125ef4u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 38), (uint16_t)GPR_U32(ctx, 0));
    // 0x125ef8: 0xa6000024  sh          $zero, 0x24($s0)
    ctx->pc = 0x125ef8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 36), (uint16_t)GPR_U32(ctx, 0));
    // 0x125efc: 0x8e05003c  lw          $a1, 0x3C($s0)
    ctx->pc = 0x125efcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
    // 0x125f00: 0x82230000  lb          $v1, 0x0($s1)
    ctx->pc = 0x125f00u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x125f04: 0x8e060040  lw          $a2, 0x40($s0)
    ctx->pc = 0x125f04u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
    // 0x125f08: 0xae030050  sw          $v1, 0x50($s0)
    ctx->pc = 0x125f08u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 80), GPR_U32(ctx, 3));
    // 0x125f0c: 0x8e070044  lw          $a3, 0x44($s0)
    ctx->pc = 0x125f0cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x125f10: 0x82640000  lb          $a0, 0x0($s3)
    ctx->pc = 0x125f10u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x125f14: 0x87a20020  lh          $v0, 0x20($sp)
    ctx->pc = 0x125f14u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x125f18: 0xae040054  sw          $a0, 0x54($s0)
    ctx->pc = 0x125f18u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 84), GPR_U32(ctx, 4));
    // 0x125f1c: 0xa6140098  sh          $s4, 0x98($s0)
    ctx->pc = 0x125f1cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 152), (uint16_t)GPR_U32(ctx, 20));
    // 0x125f20: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x125f20u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x125f24: 0xae05005c  sw          $a1, 0x5C($s0)
    ctx->pc = 0x125f24u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 92), GPR_U32(ctx, 5));
    // 0x125f28: 0xae060060  sw          $a2, 0x60($s0)
    ctx->pc = 0x125f28u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 96), GPR_U32(ctx, 6));
    // 0x125f2c: 0xae030058  sw          $v1, 0x58($s0)
    ctx->pc = 0x125f2cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 88), GPR_U32(ctx, 3));
    // 0x125f30: 0xae070064  sw          $a3, 0x64($s0)
    ctx->pc = 0x125f30u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 100), GPR_U32(ctx, 7));
    // 0x125f34: 0xae00008c  sw          $zero, 0x8C($s0)
    ctx->pc = 0x125f34u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 140), GPR_U32(ctx, 0));
    // 0x125f38: 0xae000088  sw          $zero, 0x88($s0)
    ctx->pc = 0x125f38u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 136), GPR_U32(ctx, 0));
label_125f3c:
    // 0x125f3c: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x125f3cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x125f40: 0xdfb10038  ld          $s1, 0x38($sp)
    ctx->pc = 0x125f40u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x125f44: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x125f44u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x125f48: 0xdfb30048  ld          $s3, 0x48($sp)
    ctx->pc = 0x125f48u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x125f4c: 0xdfb40050  ld          $s4, 0x50($sp)
    ctx->pc = 0x125f4cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x125f50: 0xdfbf0058  ld          $ra, 0x58($sp)
    ctx->pc = 0x125f50u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x125f54: 0x3e00008  jr          $ra
    ctx->pc = 0x125F54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x125F58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125F54u;
            // 0x125f58: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x125C30u: goto label_125c30;
            case 0x125C88u: goto label_125c88;
            case 0x125CA0u: goto label_125ca0;
            case 0x125CA8u: goto label_125ca8;
            case 0x125CE0u: goto label_125ce0;
            case 0x125CF8u: goto label_125cf8;
            case 0x125D00u: goto label_125d00;
            case 0x125D64u: goto label_125d64;
            case 0x125D90u: goto label_125d90;
            case 0x125DA8u: goto label_125da8;
            case 0x125DE0u: goto label_125de0;
            case 0x125DF8u: goto label_125df8;
            case 0x125DFCu: goto label_125dfc;
            case 0x125E30u: goto label_125e30;
            case 0x125E34u: goto label_125e34;
            case 0x125E38u: goto label_125e38;
            case 0x125E60u: goto label_125e60;
            case 0x125ECCu: goto label_125ecc;
            case 0x125EE0u: goto label_125ee0;
            case 0x125F3Cu: goto label_125f3c;
            case 0x125F60u: goto label_125f60;
            case 0x125F94u: goto label_125f94;
            case 0x125FB4u: goto label_125fb4;
            case 0x126010u: goto label_126010;
            case 0x126048u: goto label_126048;
            case 0x126050u: goto label_126050;
            case 0x126074u: goto label_126074;
            case 0x126094u: goto label_126094;
            case 0x1260B4u: goto label_1260b4;
            case 0x1260C0u: goto label_1260c0;
            case 0x1260D8u: goto label_1260d8;
            case 0x12610Cu: goto label_12610c;
            case 0x12612Cu: goto label_12612c;
            case 0x126190u: goto label_126190;
            case 0x1261D8u: goto label_1261d8;
            case 0x1261E8u: goto label_1261e8;
            case 0x126210u: goto label_126210;
            case 0x12622Cu: goto label_12622c;
            case 0x12624Cu: goto label_12624c;
            case 0x126258u: goto label_126258;
            case 0x126270u: goto label_126270;
            case 0x1262A4u: goto label_1262a4;
            case 0x1262C4u: goto label_1262c4;
            case 0x126320u: goto label_126320;
            case 0x126370u: goto label_126370;
            case 0x126380u: goto label_126380;
            case 0x1263ACu: goto label_1263ac;
            case 0x1263CCu: goto label_1263cc;
            case 0x1263ECu: goto label_1263ec;
            case 0x1263F8u: goto label_1263f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x125F5Cu;
    // 0x125f5c: 0x0  nop
    ctx->pc = 0x125f5cu;
    // NOP
label_125f60:
    // 0x125f60: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x125f60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x125f64: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x125f64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x125f68: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x125f68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x125f6c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x125f6cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125f70: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x125f70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x125f74: 0x26110048  addiu       $s1, $s0, 0x48
    ctx->pc = 0x125f74u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 72));
    // 0x125f78: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x125f78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x125f7c: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x125f7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x125f80: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x125f80u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x125f84: 0x14620043  bne         $v1, $v0, . + 4 + (0x43 << 2)
    ctx->pc = 0x125F84u;
    {
        const bool branch_taken_0x125f84 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x125F88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125F84u;
            // 0x125f88: 0x8e320000  lw          $s2, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125f84) {
            ctx->pc = 0x126094u;
            goto label_126094;
        }
    }
    ctx->pc = 0x125F8Cu;
    // 0x125f8c: 0xc04d3e6  jal         func_134F98
    ctx->pc = 0x125F8Cu;
    SET_GPR_U32(ctx, 31, 0x125F94u);
    ctx->pc = 0x125F90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x125F8Cu;
            // 0x125f90: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134F98u;
    if (runtime->hasFunction(0x134F98u)) {
        auto targetFn = runtime->lookupFunction(0x134F98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125F94u; }
        if (ctx->pc != 0x125F94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134F98_0x134f98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125F94u; }
        if (ctx->pc != 0x125F94u) { return; }
    }
    ctx->pc = 0x125F94u;
label_125f94:
    // 0x125f94: 0x5440003f  bnel        $v0, $zero, . + 4 + (0x3F << 2)
    ctx->pc = 0x125F94u;
    {
        const bool branch_taken_0x125f94 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x125f94) {
            ctx->pc = 0x125F98u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x125F94u;
            // 0x125f98: 0x8e030004  lw          $v1, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x126094u;
            goto label_126094;
        }
    }
    ctx->pc = 0x125F9Cu;
    // 0x125f9c: 0x8e04007c  lw          $a0, 0x7C($s0)
    ctx->pc = 0x125f9cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 124)));
    // 0x125fa0: 0x26050068  addiu       $a1, $s0, 0x68
    ctx->pc = 0x125fa0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 104));
    // 0x125fa4: 0x8e020078  lw          $v0, 0x78($s0)
    ctx->pc = 0x125fa4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 120)));
    // 0x125fa8: 0x2606006c  addiu       $a2, $s0, 0x6C
    ctx->pc = 0x125fa8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 108));
    // 0x125fac: 0x40f809  jalr        $v0
    ctx->pc = 0x125FACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x125FB4u);
        ctx->pc = 0x125FB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125FACu;
            // 0x125fb0: 0x26070070  addiu       $a3, $s0, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 112));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x125FB4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x125C30u: goto label_125c30;
            case 0x125C88u: goto label_125c88;
            case 0x125CA0u: goto label_125ca0;
            case 0x125CA8u: goto label_125ca8;
            case 0x125CE0u: goto label_125ce0;
            case 0x125CF8u: goto label_125cf8;
            case 0x125D00u: goto label_125d00;
            case 0x125D64u: goto label_125d64;
            case 0x125D90u: goto label_125d90;
            case 0x125DA8u: goto label_125da8;
            case 0x125DE0u: goto label_125de0;
            case 0x125DF8u: goto label_125df8;
            case 0x125DFCu: goto label_125dfc;
            case 0x125E30u: goto label_125e30;
            case 0x125E34u: goto label_125e34;
            case 0x125E38u: goto label_125e38;
            case 0x125E60u: goto label_125e60;
            case 0x125ECCu: goto label_125ecc;
            case 0x125EE0u: goto label_125ee0;
            case 0x125F3Cu: goto label_125f3c;
            case 0x125F60u: goto label_125f60;
            case 0x125F94u: goto label_125f94;
            case 0x125FB4u: goto label_125fb4;
            case 0x126010u: goto label_126010;
            case 0x126048u: goto label_126048;
            case 0x126050u: goto label_126050;
            case 0x126074u: goto label_126074;
            case 0x126094u: goto label_126094;
            case 0x1260B4u: goto label_1260b4;
            case 0x1260C0u: goto label_1260c0;
            case 0x1260D8u: goto label_1260d8;
            case 0x12610Cu: goto label_12610c;
            case 0x12612Cu: goto label_12612c;
            case 0x126190u: goto label_126190;
            case 0x1261D8u: goto label_1261d8;
            case 0x1261E8u: goto label_1261e8;
            case 0x126210u: goto label_126210;
            case 0x12622Cu: goto label_12622c;
            case 0x12624Cu: goto label_12624c;
            case 0x126258u: goto label_126258;
            case 0x126270u: goto label_126270;
            case 0x1262A4u: goto label_1262a4;
            case 0x1262C4u: goto label_1262c4;
            case 0x126320u: goto label_126320;
            case 0x126370u: goto label_126370;
            case 0x126380u: goto label_126380;
            case 0x1263ACu: goto label_1263ac;
            case 0x1263CCu: goto label_1263cc;
            case 0x1263ECu: goto label_1263ec;
            case 0x1263F8u: goto label_1263f8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x125FB4u; }
            if (ctx->pc != 0x125FB4u) { return; }
        }
        }
    }
    ctx->pc = 0x125FB4u;
label_125fb4:
    // 0x125fb4: 0x8e240018  lw          $a0, 0x18($s1)
    ctx->pc = 0x125fb4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x125fb8: 0x8e270020  lw          $a3, 0x20($s1)
    ctx->pc = 0x125fb8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x125fbc: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x125fbcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x125fc0: 0x8e230024  lw          $v1, 0x24($s1)
    ctx->pc = 0x125fc0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x125fc4: 0x874823  subu        $t1, $a0, $a3
    ctx->pc = 0x125fc4u;
    SET_GPR_S32(ctx, 9, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x125fc8: 0x8204000e  lb          $a0, 0xE($s0)
    ctx->pc = 0x125fc8u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
    // 0x125fcc: 0x69102a  slt         $v0, $v1, $t1
    ctx->pc = 0x125fccu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x125fd0: 0x8e250004  lw          $a1, 0x4($s1)
    ctx->pc = 0x125fd0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x125fd4: 0x62480b  movn        $t1, $v1, $v0
    ctx->pc = 0x125fd4u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 9, GPR_VEC(ctx, 3));
    // 0x125fd8: 0x71840  sll         $v1, $a3, 1
    ctx->pc = 0x125fd8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x125fdc: 0x8e2b0014  lw          $t3, 0x14($s1)
    ctx->pc = 0x125fdcu;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x125fe0: 0xa9102a  slt         $v0, $a1, $t1
    ctx->pc = 0x125fe0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x125fe4: 0xa2480b  movn        $t1, $a1, $v0
    ctx->pc = 0x125fe4u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 9, GPR_VEC(ctx, 5));
    // 0x125fe8: 0x1635021  addu        $t2, $t3, $v1
    ctx->pc = 0x125fe8u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 3)));
    // 0x125fec: 0x14860016  bne         $a0, $a2, . + 4 + (0x16 << 2)
    ctx->pc = 0x125FECu;
    {
        const bool branch_taken_0x125fec = (GPR_U64(ctx, 4) != GPR_U64(ctx, 6));
        ctx->pc = 0x125FF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125FECu;
            // 0x125ff0: 0x9203000e  lbu         $v1, 0xE($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125fec) {
            ctx->pc = 0x126048u;
            goto label_126048;
        }
    }
    ctx->pc = 0x125FF4u;
    // 0x125ff4: 0x8e22001c  lw          $v0, 0x1C($s1)
    ctx->pc = 0x125ff4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x125ff8: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x125ff8u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125ffc: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x125ffcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x126000: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x126000u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x126004: 0x1920001b  blez        $t1, . + 4 + (0x1B << 2)
    ctx->pc = 0x126004u;
    {
        const bool branch_taken_0x126004 = (GPR_S64(ctx, 9) <= 0);
        ctx->pc = 0x126008u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126004u;
            // 0x126008: 0x1625821  addu        $t3, $t3, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126004) {
            ctx->pc = 0x126074u;
            goto label_126074;
        }
    }
    ctx->pc = 0x12600Cu;
    // 0x12600c: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x12600cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_126010:
    // 0x126010: 0x81840  sll         $v1, $t0, 1
    ctx->pc = 0x126010u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x126014: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x126014u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x126018: 0x94e50000  lhu         $a1, 0x0($a3)
    ctx->pc = 0x126018u;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x12601c: 0x6a2021  addu        $a0, $v1, $t2
    ctx->pc = 0x12601cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 10)));
    // 0x126020: 0x109302a  slt         $a2, $t0, $t1
    ctx->pc = 0x126020u;
    SET_GPR_U64(ctx, 6, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x126024: 0x6b1821  addu        $v1, $v1, $t3
    ctx->pc = 0x126024u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 11)));
    // 0x126028: 0xa4850000  sh          $a1, 0x0($a0)
    ctx->pc = 0x126028u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 5));
    // 0x12602c: 0x94e20002  lhu         $v0, 0x2($a3)
    ctx->pc = 0x12602cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 2)));
    // 0x126030: 0x24e70004  addiu       $a3, $a3, 0x4
    ctx->pc = 0x126030u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4));
    // 0x126034: 0x14c0fff6  bnez        $a2, . + 4 + (-0xA << 2)
    ctx->pc = 0x126034u;
    {
        const bool branch_taken_0x126034 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x126038u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126034u;
            // 0x126038: 0xa4620000  sh          $v0, 0x0($v1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126034) {
            ctx->pc = 0x126010u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_126010;
        }
    }
    ctx->pc = 0x12603Cu;
    // 0x12603c: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x12603Cu;
    {
        const bool branch_taken_0x12603c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x126040u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12603Cu;
            // 0x126040: 0x9203000e  lbu         $v1, 0xE($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12603c) {
            ctx->pc = 0x126074u;
            goto label_126074;
        }
    }
    ctx->pc = 0x126044u;
    // 0x126044: 0x0  nop
    ctx->pc = 0x126044u;
    // NOP
label_126048:
    // 0x126048: 0x1920000a  blez        $t1, . + 4 + (0xA << 2)
    ctx->pc = 0x126048u;
    {
        const bool branch_taken_0x126048 = (GPR_S64(ctx, 9) <= 0);
        ctx->pc = 0x12604Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126048u;
            // 0x12604c: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126048) {
            ctx->pc = 0x126074u;
            goto label_126074;
        }
    }
    ctx->pc = 0x126050u;
label_126050:
    // 0x126050: 0x81040  sll         $v0, $t0, 1
    ctx->pc = 0x126050u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x126054: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x126054u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x126058: 0x521821  addu        $v1, $v0, $s2
    ctx->pc = 0x126058u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x12605c: 0x4a1021  addu        $v0, $v0, $t2
    ctx->pc = 0x12605cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 10)));
    // 0x126060: 0x94640000  lhu         $a0, 0x0($v1)
    ctx->pc = 0x126060u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x126064: 0x109282a  slt         $a1, $t0, $t1
    ctx->pc = 0x126064u;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x126068: 0x14a0fff9  bnez        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x126068u;
    {
        const bool branch_taken_0x126068 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x12606Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126068u;
            // 0x12606c: 0xa4440000  sh          $a0, 0x0($v0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126068) {
            ctx->pc = 0x126050u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_126050;
        }
    }
    ctx->pc = 0x126070u;
    // 0x126070: 0x9203000e  lbu         $v1, 0xE($s0)
    ctx->pc = 0x126070u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
label_126074:
    // 0x126074: 0x31600  sll         $v0, $v1, 24
    ctx->pc = 0x126074u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x126078: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x126078u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12607c: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x12607cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x126080: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x126080u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
    // 0x126084: 0x1221018  mult        $v0, $t1, $v0
    ctx->pc = 0x126084u;
    { int64_t result = (int64_t)GPR_S32(ctx, 9) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x126088: 0xae090090  sw          $t1, 0x90($s0)
    ctx->pc = 0x126088u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 9));
    // 0x12608c: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x12608cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x126090: 0xae020094  sw          $v0, 0x94($s0)
    ctx->pc = 0x126090u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 148), GPR_U32(ctx, 2));
label_126094:
    // 0x126094: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x126094u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x126098: 0x54620009  bnel        $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x126098u;
    {
        const bool branch_taken_0x126098 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x126098) {
            ctx->pc = 0x12609Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x126098u;
            // 0x12609c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1260C0u;
            goto label_1260c0;
        }
    }
    ctx->pc = 0x1260A0u;
    // 0x1260a0: 0x8e030080  lw          $v1, 0x80($s0)
    ctx->pc = 0x1260a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 128)));
    // 0x1260a4: 0x8e040084  lw          $a0, 0x84($s0)
    ctx->pc = 0x1260a4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 132)));
    // 0x1260a8: 0x8e050094  lw          $a1, 0x94($s0)
    ctx->pc = 0x1260a8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 148)));
    // 0x1260ac: 0x60f809  jalr        $v1
    ctx->pc = 0x1260ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x1260B4u);
        ctx->pc = 0x1260B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1260ACu;
            // 0x1260b0: 0x8e060090  lw          $a2, 0x90($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 144)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1260B4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x125C30u: goto label_125c30;
            case 0x125C88u: goto label_125c88;
            case 0x125CA0u: goto label_125ca0;
            case 0x125CA8u: goto label_125ca8;
            case 0x125CE0u: goto label_125ce0;
            case 0x125CF8u: goto label_125cf8;
            case 0x125D00u: goto label_125d00;
            case 0x125D64u: goto label_125d64;
            case 0x125D90u: goto label_125d90;
            case 0x125DA8u: goto label_125da8;
            case 0x125DE0u: goto label_125de0;
            case 0x125DF8u: goto label_125df8;
            case 0x125DFCu: goto label_125dfc;
            case 0x125E30u: goto label_125e30;
            case 0x125E34u: goto label_125e34;
            case 0x125E38u: goto label_125e38;
            case 0x125E60u: goto label_125e60;
            case 0x125ECCu: goto label_125ecc;
            case 0x125EE0u: goto label_125ee0;
            case 0x125F3Cu: goto label_125f3c;
            case 0x125F60u: goto label_125f60;
            case 0x125F94u: goto label_125f94;
            case 0x125FB4u: goto label_125fb4;
            case 0x126010u: goto label_126010;
            case 0x126048u: goto label_126048;
            case 0x126050u: goto label_126050;
            case 0x126074u: goto label_126074;
            case 0x126094u: goto label_126094;
            case 0x1260B4u: goto label_1260b4;
            case 0x1260C0u: goto label_1260c0;
            case 0x1260D8u: goto label_1260d8;
            case 0x12610Cu: goto label_12610c;
            case 0x12612Cu: goto label_12612c;
            case 0x126190u: goto label_126190;
            case 0x1261D8u: goto label_1261d8;
            case 0x1261E8u: goto label_1261e8;
            case 0x126210u: goto label_126210;
            case 0x12622Cu: goto label_12622c;
            case 0x12624Cu: goto label_12624c;
            case 0x126258u: goto label_126258;
            case 0x126270u: goto label_126270;
            case 0x1262A4u: goto label_1262a4;
            case 0x1262C4u: goto label_1262c4;
            case 0x126320u: goto label_126320;
            case 0x126370u: goto label_126370;
            case 0x126380u: goto label_126380;
            case 0x1263ACu: goto label_1263ac;
            case 0x1263CCu: goto label_1263cc;
            case 0x1263ECu: goto label_1263ec;
            case 0x1263F8u: goto label_1263f8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1260B4u; }
            if (ctx->pc != 0x1260B4u) { return; }
        }
        }
    }
    ctx->pc = 0x1260B4u;
label_1260b4:
    // 0x1260b4: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1260b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1260b8: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x1260b8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x1260bc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1260bcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1260c0:
    // 0x1260c0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1260c0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1260c4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1260c4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1260c8: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1260c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1260cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1260CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1260D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1260CCu;
            // 0x1260d0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x125C30u: goto label_125c30;
            case 0x125C88u: goto label_125c88;
            case 0x125CA0u: goto label_125ca0;
            case 0x125CA8u: goto label_125ca8;
            case 0x125CE0u: goto label_125ce0;
            case 0x125CF8u: goto label_125cf8;
            case 0x125D00u: goto label_125d00;
            case 0x125D64u: goto label_125d64;
            case 0x125D90u: goto label_125d90;
            case 0x125DA8u: goto label_125da8;
            case 0x125DE0u: goto label_125de0;
            case 0x125DF8u: goto label_125df8;
            case 0x125DFCu: goto label_125dfc;
            case 0x125E30u: goto label_125e30;
            case 0x125E34u: goto label_125e34;
            case 0x125E38u: goto label_125e38;
            case 0x125E60u: goto label_125e60;
            case 0x125ECCu: goto label_125ecc;
            case 0x125EE0u: goto label_125ee0;
            case 0x125F3Cu: goto label_125f3c;
            case 0x125F60u: goto label_125f60;
            case 0x125F94u: goto label_125f94;
            case 0x125FB4u: goto label_125fb4;
            case 0x126010u: goto label_126010;
            case 0x126048u: goto label_126048;
            case 0x126050u: goto label_126050;
            case 0x126074u: goto label_126074;
            case 0x126094u: goto label_126094;
            case 0x1260B4u: goto label_1260b4;
            case 0x1260C0u: goto label_1260c0;
            case 0x1260D8u: goto label_1260d8;
            case 0x12610Cu: goto label_12610c;
            case 0x12612Cu: goto label_12612c;
            case 0x126190u: goto label_126190;
            case 0x1261D8u: goto label_1261d8;
            case 0x1261E8u: goto label_1261e8;
            case 0x126210u: goto label_126210;
            case 0x12622Cu: goto label_12622c;
            case 0x12624Cu: goto label_12624c;
            case 0x126258u: goto label_126258;
            case 0x126270u: goto label_126270;
            case 0x1262A4u: goto label_1262a4;
            case 0x1262C4u: goto label_1262c4;
            case 0x126320u: goto label_126320;
            case 0x126370u: goto label_126370;
            case 0x126380u: goto label_126380;
            case 0x1263ACu: goto label_1263ac;
            case 0x1263CCu: goto label_1263cc;
            case 0x1263ECu: goto label_1263ec;
            case 0x1263F8u: goto label_1263f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1260D4u;
    // 0x1260d4: 0x0  nop
    ctx->pc = 0x1260d4u;
    // NOP
label_1260d8:
    // 0x1260d8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1260d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1260dc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1260dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1260e0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1260e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1260e4: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1260e4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1260e8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1260e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1260ec: 0x26110048  addiu       $s1, $s0, 0x48
    ctx->pc = 0x1260ecu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 72));
    // 0x1260f0: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1260f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1260f4: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1260f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1260f8: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x1260f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1260fc: 0x1462004b  bne         $v1, $v0, . + 4 + (0x4B << 2)
    ctx->pc = 0x1260FCu;
    {
        const bool branch_taken_0x1260fc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x126100u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1260FCu;
            // 0x126100: 0x8e320000  lw          $s2, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1260fc) {
            ctx->pc = 0x12622Cu;
            goto label_12622c;
        }
    }
    ctx->pc = 0x126104u;
    // 0x126104: 0xc04d3e6  jal         func_134F98
    ctx->pc = 0x126104u;
    SET_GPR_U32(ctx, 31, 0x12610Cu);
    ctx->pc = 0x126108u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x126104u;
            // 0x126108: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134F98u;
    if (runtime->hasFunction(0x134F98u)) {
        auto targetFn = runtime->lookupFunction(0x134F98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12610Cu; }
        if (ctx->pc != 0x12610Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134F98_0x134f98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12610Cu; }
        if (ctx->pc != 0x12610Cu) { return; }
    }
    ctx->pc = 0x12610Cu;
label_12610c:
    // 0x12610c: 0x54400047  bnel        $v0, $zero, . + 4 + (0x47 << 2)
    ctx->pc = 0x12610Cu;
    {
        const bool branch_taken_0x12610c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x12610c) {
            ctx->pc = 0x126110u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12610Cu;
            // 0x126110: 0x8e030004  lw          $v1, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12622Cu;
            goto label_12622c;
        }
    }
    ctx->pc = 0x126114u;
    // 0x126114: 0x8e04007c  lw          $a0, 0x7C($s0)
    ctx->pc = 0x126114u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 124)));
    // 0x126118: 0x26050068  addiu       $a1, $s0, 0x68
    ctx->pc = 0x126118u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 104));
    // 0x12611c: 0x8e020078  lw          $v0, 0x78($s0)
    ctx->pc = 0x12611cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 120)));
    // 0x126120: 0x2606006c  addiu       $a2, $s0, 0x6C
    ctx->pc = 0x126120u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 108));
    // 0x126124: 0x40f809  jalr        $v0
    ctx->pc = 0x126124u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12612Cu);
        ctx->pc = 0x126128u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126124u;
            // 0x126128: 0x26070070  addiu       $a3, $s0, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 112));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12612Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x125C30u: goto label_125c30;
            case 0x125C88u: goto label_125c88;
            case 0x125CA0u: goto label_125ca0;
            case 0x125CA8u: goto label_125ca8;
            case 0x125CE0u: goto label_125ce0;
            case 0x125CF8u: goto label_125cf8;
            case 0x125D00u: goto label_125d00;
            case 0x125D64u: goto label_125d64;
            case 0x125D90u: goto label_125d90;
            case 0x125DA8u: goto label_125da8;
            case 0x125DE0u: goto label_125de0;
            case 0x125DF8u: goto label_125df8;
            case 0x125DFCu: goto label_125dfc;
            case 0x125E30u: goto label_125e30;
            case 0x125E34u: goto label_125e34;
            case 0x125E38u: goto label_125e38;
            case 0x125E60u: goto label_125e60;
            case 0x125ECCu: goto label_125ecc;
            case 0x125EE0u: goto label_125ee0;
            case 0x125F3Cu: goto label_125f3c;
            case 0x125F60u: goto label_125f60;
            case 0x125F94u: goto label_125f94;
            case 0x125FB4u: goto label_125fb4;
            case 0x126010u: goto label_126010;
            case 0x126048u: goto label_126048;
            case 0x126050u: goto label_126050;
            case 0x126074u: goto label_126074;
            case 0x126094u: goto label_126094;
            case 0x1260B4u: goto label_1260b4;
            case 0x1260C0u: goto label_1260c0;
            case 0x1260D8u: goto label_1260d8;
            case 0x12610Cu: goto label_12610c;
            case 0x12612Cu: goto label_12612c;
            case 0x126190u: goto label_126190;
            case 0x1261D8u: goto label_1261d8;
            case 0x1261E8u: goto label_1261e8;
            case 0x126210u: goto label_126210;
            case 0x12622Cu: goto label_12622c;
            case 0x12624Cu: goto label_12624c;
            case 0x126258u: goto label_126258;
            case 0x126270u: goto label_126270;
            case 0x1262A4u: goto label_1262a4;
            case 0x1262C4u: goto label_1262c4;
            case 0x126320u: goto label_126320;
            case 0x126370u: goto label_126370;
            case 0x126380u: goto label_126380;
            case 0x1263ACu: goto label_1263ac;
            case 0x1263CCu: goto label_1263cc;
            case 0x1263ECu: goto label_1263ec;
            case 0x1263F8u: goto label_1263f8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12612Cu; }
            if (ctx->pc != 0x12612Cu) { return; }
        }
        }
    }
    ctx->pc = 0x12612Cu;
label_12612c:
    // 0x12612c: 0x8e240018  lw          $a0, 0x18($s1)
    ctx->pc = 0x12612cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x126130: 0x8e270020  lw          $a3, 0x20($s1)
    ctx->pc = 0x126130u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x126134: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x126134u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x126138: 0x8e230024  lw          $v1, 0x24($s1)
    ctx->pc = 0x126138u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x12613c: 0x874823  subu        $t1, $a0, $a3
    ctx->pc = 0x12613cu;
    SET_GPR_S32(ctx, 9, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x126140: 0x8204000e  lb          $a0, 0xE($s0)
    ctx->pc = 0x126140u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
    // 0x126144: 0x69102a  slt         $v0, $v1, $t1
    ctx->pc = 0x126144u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x126148: 0x8e250004  lw          $a1, 0x4($s1)
    ctx->pc = 0x126148u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x12614c: 0x62480b  movn        $t1, $v1, $v0
    ctx->pc = 0x12614cu;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 9, GPR_VEC(ctx, 3));
    // 0x126150: 0x71840  sll         $v1, $a3, 1
    ctx->pc = 0x126150u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x126154: 0x8e2a0014  lw          $t2, 0x14($s1)
    ctx->pc = 0x126154u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x126158: 0xa9102a  slt         $v0, $a1, $t1
    ctx->pc = 0x126158u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x12615c: 0xa2480b  movn        $t1, $a1, $v0
    ctx->pc = 0x12615cu;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 9, GPR_VEC(ctx, 5));
    // 0x126160: 0x1435821  addu        $t3, $t2, $v1
    ctx->pc = 0x126160u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 3)));
    // 0x126164: 0x1486001c  bne         $a0, $a2, . + 4 + (0x1C << 2)
    ctx->pc = 0x126164u;
    {
        const bool branch_taken_0x126164 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 6));
        ctx->pc = 0x126168u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126164u;
            // 0x126168: 0x9203000e  lbu         $v1, 0xE($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126164) {
            ctx->pc = 0x1261D8u;
            goto label_1261d8;
        }
    }
    ctx->pc = 0x12616Cu;
    // 0x12616c: 0x8e22001c  lw          $v0, 0x1C($s1)
    ctx->pc = 0x12616cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x126170: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x126170u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x126174: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x126174u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x126178: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x126178u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x12617c: 0x19200024  blez        $t1, . + 4 + (0x24 << 2)
    ctx->pc = 0x12617Cu;
    {
        const bool branch_taken_0x12617c = (GPR_S64(ctx, 9) <= 0);
        ctx->pc = 0x126180u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12617Cu;
            // 0x126180: 0x1426021  addu        $t4, $t2, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12617c) {
            ctx->pc = 0x126210u;
            goto label_126210;
        }
    }
    ctx->pc = 0x126184u;
    // 0x126184: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x126184u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x126188: 0x340aff80  ori         $t2, $zero, 0xFF80
    ctx->pc = 0x126188u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65408);
    // 0x12618c: 0x0  nop
    ctx->pc = 0x12618cu;
    // NOP
label_126190:
    // 0x126190: 0x90e30000  lbu         $v1, 0x0($a3)
    ctx->pc = 0x126190u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x126194: 0x82040  sll         $a0, $t0, 1
    ctx->pc = 0x126194u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x126198: 0x8b2821  addu        $a1, $a0, $t3
    ctx->pc = 0x126198u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 11)));
    // 0x12619c: 0x8c2021  addu        $a0, $a0, $t4
    ctx->pc = 0x12619cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 12)));
    // 0x1261a0: 0x6a1821  addu        $v1, $v1, $t2
    ctx->pc = 0x1261a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 10)));
    // 0x1261a4: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1261a4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1261a8: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x1261a8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x1261ac: 0x109302a  slt         $a2, $t0, $t1
    ctx->pc = 0x1261acu;
    SET_GPR_U64(ctx, 6, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x1261b0: 0xa4a30000  sh          $v1, 0x0($a1)
    ctx->pc = 0x1261b0u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1261b4: 0x90e20001  lbu         $v0, 0x1($a3)
    ctx->pc = 0x1261b4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 1)));
    // 0x1261b8: 0x24e70002  addiu       $a3, $a3, 0x2
    ctx->pc = 0x1261b8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 2));
    // 0x1261bc: 0x4a1021  addu        $v0, $v0, $t2
    ctx->pc = 0x1261bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 10)));
    // 0x1261c0: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1261c0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1261c4: 0x14c0fff2  bnez        $a2, . + 4 + (-0xE << 2)
    ctx->pc = 0x1261C4u;
    {
        const bool branch_taken_0x1261c4 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x1261C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1261C4u;
            // 0x1261c8: 0xa4820000  sh          $v0, 0x0($a0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1261c4) {
            ctx->pc = 0x126190u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_126190;
        }
    }
    ctx->pc = 0x1261CCu;
    // 0x1261cc: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1261CCu;
    {
        const bool branch_taken_0x1261cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1261D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1261CCu;
            // 0x1261d0: 0x9203000e  lbu         $v1, 0xE($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1261cc) {
            ctx->pc = 0x126210u;
            goto label_126210;
        }
    }
    ctx->pc = 0x1261D4u;
    // 0x1261d4: 0x0  nop
    ctx->pc = 0x1261d4u;
    // NOP
label_1261d8:
    // 0x1261d8: 0x1920000d  blez        $t1, . + 4 + (0xD << 2)
    ctx->pc = 0x1261D8u;
    {
        const bool branch_taken_0x1261d8 = (GPR_S64(ctx, 9) <= 0);
        ctx->pc = 0x1261DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1261D8u;
            // 0x1261dc: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1261d8) {
            ctx->pc = 0x126210u;
            goto label_126210;
        }
    }
    ctx->pc = 0x1261E0u;
    // 0x1261e0: 0x160282d  daddu       $a1, $t3, $zero
    ctx->pc = 0x1261e0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1261e4: 0x3406ff80  ori         $a2, $zero, 0xFF80
    ctx->pc = 0x1261e4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65408);
label_1261e8:
    // 0x1261e8: 0x2481021  addu        $v0, $s2, $t0
    ctx->pc = 0x1261e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 8)));
    // 0x1261ec: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1261ecu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1261f0: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x1261f0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1261f4: 0x109202a  slt         $a0, $t0, $t1
    ctx->pc = 0x1261f4u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x1261f8: 0x661821  addu        $v1, $v1, $a2
    ctx->pc = 0x1261f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x1261fc: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x1261fcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x126200: 0xa4a30000  sh          $v1, 0x0($a1)
    ctx->pc = 0x126200u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x126204: 0x1480fff8  bnez        $a0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x126204u;
    {
        const bool branch_taken_0x126204 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x126208u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126204u;
            // 0x126208: 0x24a50002  addiu       $a1, $a1, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126204) {
            ctx->pc = 0x1261E8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1261e8;
        }
    }
    ctx->pc = 0x12620Cu;
    // 0x12620c: 0x9203000e  lbu         $v1, 0xE($s0)
    ctx->pc = 0x12620cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
label_126210:
    // 0x126210: 0x31600  sll         $v0, $v1, 24
    ctx->pc = 0x126210u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x126214: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x126214u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x126218: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x126218u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x12621c: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x12621cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
    // 0x126220: 0x1221018  mult        $v0, $t1, $v0
    ctx->pc = 0x126220u;
    { int64_t result = (int64_t)GPR_S32(ctx, 9) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x126224: 0xae090090  sw          $t1, 0x90($s0)
    ctx->pc = 0x126224u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 9));
    // 0x126228: 0xae020094  sw          $v0, 0x94($s0)
    ctx->pc = 0x126228u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 148), GPR_U32(ctx, 2));
label_12622c:
    // 0x12622c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x12622cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x126230: 0x54620009  bnel        $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x126230u;
    {
        const bool branch_taken_0x126230 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x126230) {
            ctx->pc = 0x126234u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x126230u;
            // 0x126234: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x126258u;
            goto label_126258;
        }
    }
    ctx->pc = 0x126238u;
    // 0x126238: 0x8e030080  lw          $v1, 0x80($s0)
    ctx->pc = 0x126238u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 128)));
    // 0x12623c: 0x8e040084  lw          $a0, 0x84($s0)
    ctx->pc = 0x12623cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 132)));
    // 0x126240: 0x8e050094  lw          $a1, 0x94($s0)
    ctx->pc = 0x126240u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 148)));
    // 0x126244: 0x60f809  jalr        $v1
    ctx->pc = 0x126244u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x12624Cu);
        ctx->pc = 0x126248u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126244u;
            // 0x126248: 0x8e060090  lw          $a2, 0x90($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 144)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12624Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x125C30u: goto label_125c30;
            case 0x125C88u: goto label_125c88;
            case 0x125CA0u: goto label_125ca0;
            case 0x125CA8u: goto label_125ca8;
            case 0x125CE0u: goto label_125ce0;
            case 0x125CF8u: goto label_125cf8;
            case 0x125D00u: goto label_125d00;
            case 0x125D64u: goto label_125d64;
            case 0x125D90u: goto label_125d90;
            case 0x125DA8u: goto label_125da8;
            case 0x125DE0u: goto label_125de0;
            case 0x125DF8u: goto label_125df8;
            case 0x125DFCu: goto label_125dfc;
            case 0x125E30u: goto label_125e30;
            case 0x125E34u: goto label_125e34;
            case 0x125E38u: goto label_125e38;
            case 0x125E60u: goto label_125e60;
            case 0x125ECCu: goto label_125ecc;
            case 0x125EE0u: goto label_125ee0;
            case 0x125F3Cu: goto label_125f3c;
            case 0x125F60u: goto label_125f60;
            case 0x125F94u: goto label_125f94;
            case 0x125FB4u: goto label_125fb4;
            case 0x126010u: goto label_126010;
            case 0x126048u: goto label_126048;
            case 0x126050u: goto label_126050;
            case 0x126074u: goto label_126074;
            case 0x126094u: goto label_126094;
            case 0x1260B4u: goto label_1260b4;
            case 0x1260C0u: goto label_1260c0;
            case 0x1260D8u: goto label_1260d8;
            case 0x12610Cu: goto label_12610c;
            case 0x12612Cu: goto label_12612c;
            case 0x126190u: goto label_126190;
            case 0x1261D8u: goto label_1261d8;
            case 0x1261E8u: goto label_1261e8;
            case 0x126210u: goto label_126210;
            case 0x12622Cu: goto label_12622c;
            case 0x12624Cu: goto label_12624c;
            case 0x126258u: goto label_126258;
            case 0x126270u: goto label_126270;
            case 0x1262A4u: goto label_1262a4;
            case 0x1262C4u: goto label_1262c4;
            case 0x126320u: goto label_126320;
            case 0x126370u: goto label_126370;
            case 0x126380u: goto label_126380;
            case 0x1263ACu: goto label_1263ac;
            case 0x1263CCu: goto label_1263cc;
            case 0x1263ECu: goto label_1263ec;
            case 0x1263F8u: goto label_1263f8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12624Cu; }
            if (ctx->pc != 0x12624Cu) { return; }
        }
        }
    }
    ctx->pc = 0x12624Cu;
label_12624c:
    // 0x12624c: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x12624cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x126250: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x126250u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x126254: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x126254u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_126258:
    // 0x126258: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x126258u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12625c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x12625cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x126260: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x126260u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x126264: 0x3e00008  jr          $ra
    ctx->pc = 0x126264u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x126268u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126264u;
            // 0x126268: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x125C30u: goto label_125c30;
            case 0x125C88u: goto label_125c88;
            case 0x125CA0u: goto label_125ca0;
            case 0x125CA8u: goto label_125ca8;
            case 0x125CE0u: goto label_125ce0;
            case 0x125CF8u: goto label_125cf8;
            case 0x125D00u: goto label_125d00;
            case 0x125D64u: goto label_125d64;
            case 0x125D90u: goto label_125d90;
            case 0x125DA8u: goto label_125da8;
            case 0x125DE0u: goto label_125de0;
            case 0x125DF8u: goto label_125df8;
            case 0x125DFCu: goto label_125dfc;
            case 0x125E30u: goto label_125e30;
            case 0x125E34u: goto label_125e34;
            case 0x125E38u: goto label_125e38;
            case 0x125E60u: goto label_125e60;
            case 0x125ECCu: goto label_125ecc;
            case 0x125EE0u: goto label_125ee0;
            case 0x125F3Cu: goto label_125f3c;
            case 0x125F60u: goto label_125f60;
            case 0x125F94u: goto label_125f94;
            case 0x125FB4u: goto label_125fb4;
            case 0x126010u: goto label_126010;
            case 0x126048u: goto label_126048;
            case 0x126050u: goto label_126050;
            case 0x126074u: goto label_126074;
            case 0x126094u: goto label_126094;
            case 0x1260B4u: goto label_1260b4;
            case 0x1260C0u: goto label_1260c0;
            case 0x1260D8u: goto label_1260d8;
            case 0x12610Cu: goto label_12610c;
            case 0x12612Cu: goto label_12612c;
            case 0x126190u: goto label_126190;
            case 0x1261D8u: goto label_1261d8;
            case 0x1261E8u: goto label_1261e8;
            case 0x126210u: goto label_126210;
            case 0x12622Cu: goto label_12622c;
            case 0x12624Cu: goto label_12624c;
            case 0x126258u: goto label_126258;
            case 0x126270u: goto label_126270;
            case 0x1262A4u: goto label_1262a4;
            case 0x1262C4u: goto label_1262c4;
            case 0x126320u: goto label_126320;
            case 0x126370u: goto label_126370;
            case 0x126380u: goto label_126380;
            case 0x1263ACu: goto label_1263ac;
            case 0x1263CCu: goto label_1263cc;
            case 0x1263ECu: goto label_1263ec;
            case 0x1263F8u: goto label_1263f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12626Cu;
    // 0x12626c: 0x0  nop
    ctx->pc = 0x12626cu;
    // NOP
label_126270:
    // 0x126270: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x126270u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x126274: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x126274u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x126278: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x126278u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12627c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x12627cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x126280: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x126280u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x126284: 0x26110048  addiu       $s1, $s0, 0x48
    ctx->pc = 0x126284u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 72));
    // 0x126288: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x126288u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12628c: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x12628cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x126290: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x126290u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x126294: 0x1462004d  bne         $v1, $v0, . + 4 + (0x4D << 2)
    ctx->pc = 0x126294u;
    {
        const bool branch_taken_0x126294 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x126298u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126294u;
            // 0x126298: 0x8e320000  lw          $s2, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126294) {
            ctx->pc = 0x1263CCu;
            goto label_1263cc;
        }
    }
    ctx->pc = 0x12629Cu;
    // 0x12629c: 0xc04d3e6  jal         func_134F98
    ctx->pc = 0x12629Cu;
    SET_GPR_U32(ctx, 31, 0x1262A4u);
    ctx->pc = 0x1262A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12629Cu;
            // 0x1262a0: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134F98u;
    if (runtime->hasFunction(0x134F98u)) {
        auto targetFn = runtime->lookupFunction(0x134F98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1262A4u; }
        if (ctx->pc != 0x1262A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134F98_0x134f98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1262A4u; }
        if (ctx->pc != 0x1262A4u) { return; }
    }
    ctx->pc = 0x1262A4u;
label_1262a4:
    // 0x1262a4: 0x54400049  bnel        $v0, $zero, . + 4 + (0x49 << 2)
    ctx->pc = 0x1262A4u;
    {
        const bool branch_taken_0x1262a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1262a4) {
            ctx->pc = 0x1262A8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1262A4u;
            // 0x1262a8: 0x8e030004  lw          $v1, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1263CCu;
            goto label_1263cc;
        }
    }
    ctx->pc = 0x1262ACu;
    // 0x1262ac: 0x8e04007c  lw          $a0, 0x7C($s0)
    ctx->pc = 0x1262acu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 124)));
    // 0x1262b0: 0x26050068  addiu       $a1, $s0, 0x68
    ctx->pc = 0x1262b0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 104));
    // 0x1262b4: 0x8e020078  lw          $v0, 0x78($s0)
    ctx->pc = 0x1262b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 120)));
    // 0x1262b8: 0x2606006c  addiu       $a2, $s0, 0x6C
    ctx->pc = 0x1262b8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 108));
    // 0x1262bc: 0x40f809  jalr        $v0
    ctx->pc = 0x1262BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1262C4u);
        ctx->pc = 0x1262C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1262BCu;
            // 0x1262c0: 0x26070070  addiu       $a3, $s0, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 112));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1262C4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x125C30u: goto label_125c30;
            case 0x125C88u: goto label_125c88;
            case 0x125CA0u: goto label_125ca0;
            case 0x125CA8u: goto label_125ca8;
            case 0x125CE0u: goto label_125ce0;
            case 0x125CF8u: goto label_125cf8;
            case 0x125D00u: goto label_125d00;
            case 0x125D64u: goto label_125d64;
            case 0x125D90u: goto label_125d90;
            case 0x125DA8u: goto label_125da8;
            case 0x125DE0u: goto label_125de0;
            case 0x125DF8u: goto label_125df8;
            case 0x125DFCu: goto label_125dfc;
            case 0x125E30u: goto label_125e30;
            case 0x125E34u: goto label_125e34;
            case 0x125E38u: goto label_125e38;
            case 0x125E60u: goto label_125e60;
            case 0x125ECCu: goto label_125ecc;
            case 0x125EE0u: goto label_125ee0;
            case 0x125F3Cu: goto label_125f3c;
            case 0x125F60u: goto label_125f60;
            case 0x125F94u: goto label_125f94;
            case 0x125FB4u: goto label_125fb4;
            case 0x126010u: goto label_126010;
            case 0x126048u: goto label_126048;
            case 0x126050u: goto label_126050;
            case 0x126074u: goto label_126074;
            case 0x126094u: goto label_126094;
            case 0x1260B4u: goto label_1260b4;
            case 0x1260C0u: goto label_1260c0;
            case 0x1260D8u: goto label_1260d8;
            case 0x12610Cu: goto label_12610c;
            case 0x12612Cu: goto label_12612c;
            case 0x126190u: goto label_126190;
            case 0x1261D8u: goto label_1261d8;
            case 0x1261E8u: goto label_1261e8;
            case 0x126210u: goto label_126210;
            case 0x12622Cu: goto label_12622c;
            case 0x12624Cu: goto label_12624c;
            case 0x126258u: goto label_126258;
            case 0x126270u: goto label_126270;
            case 0x1262A4u: goto label_1262a4;
            case 0x1262C4u: goto label_1262c4;
            case 0x126320u: goto label_126320;
            case 0x126370u: goto label_126370;
            case 0x126380u: goto label_126380;
            case 0x1263ACu: goto label_1263ac;
            case 0x1263CCu: goto label_1263cc;
            case 0x1263ECu: goto label_1263ec;
            case 0x1263F8u: goto label_1263f8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1262C4u; }
            if (ctx->pc != 0x1262C4u) { return; }
        }
        }
    }
    ctx->pc = 0x1262C4u;
label_1262c4:
    // 0x1262c4: 0x8e240018  lw          $a0, 0x18($s1)
    ctx->pc = 0x1262c4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x1262c8: 0x8e270020  lw          $a3, 0x20($s1)
    ctx->pc = 0x1262c8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x1262cc: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1262ccu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1262d0: 0x8e230024  lw          $v1, 0x24($s1)
    ctx->pc = 0x1262d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x1262d4: 0x874823  subu        $t1, $a0, $a3
    ctx->pc = 0x1262d4u;
    SET_GPR_S32(ctx, 9, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x1262d8: 0x8204000e  lb          $a0, 0xE($s0)
    ctx->pc = 0x1262d8u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
    // 0x1262dc: 0x69102a  slt         $v0, $v1, $t1
    ctx->pc = 0x1262dcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x1262e0: 0x8e250004  lw          $a1, 0x4($s1)
    ctx->pc = 0x1262e0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1262e4: 0x62480b  movn        $t1, $v1, $v0
    ctx->pc = 0x1262e4u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 9, GPR_VEC(ctx, 3));
    // 0x1262e8: 0x71840  sll         $v1, $a3, 1
    ctx->pc = 0x1262e8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x1262ec: 0x8e2b0014  lw          $t3, 0x14($s1)
    ctx->pc = 0x1262ecu;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x1262f0: 0xa9102a  slt         $v0, $a1, $t1
    ctx->pc = 0x1262f0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x1262f4: 0xa2480b  movn        $t1, $a1, $v0
    ctx->pc = 0x1262f4u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 9, GPR_VEC(ctx, 5));
    // 0x1262f8: 0x1635021  addu        $t2, $t3, $v1
    ctx->pc = 0x1262f8u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 3)));
    // 0x1262fc: 0x1486001c  bne         $a0, $a2, . + 4 + (0x1C << 2)
    ctx->pc = 0x1262FCu;
    {
        const bool branch_taken_0x1262fc = (GPR_U64(ctx, 4) != GPR_U64(ctx, 6));
        ctx->pc = 0x126300u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1262FCu;
            // 0x126300: 0x9203000e  lbu         $v1, 0xE($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1262fc) {
            ctx->pc = 0x126370u;
            goto label_126370;
        }
    }
    ctx->pc = 0x126304u;
    // 0x126304: 0x8e22001c  lw          $v0, 0x1C($s1)
    ctx->pc = 0x126304u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x126308: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x126308u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12630c: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x12630cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x126310: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x126310u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x126314: 0x19200025  blez        $t1, . + 4 + (0x25 << 2)
    ctx->pc = 0x126314u;
    {
        const bool branch_taken_0x126314 = (GPR_S64(ctx, 9) <= 0);
        ctx->pc = 0x126318u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126314u;
            // 0x126318: 0x1625821  addu        $t3, $t3, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126314) {
            ctx->pc = 0x1263ACu;
            goto label_1263ac;
        }
    }
    ctx->pc = 0x12631Cu;
    // 0x12631c: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x12631cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_126320:
    // 0x126320: 0x90e20002  lbu         $v0, 0x2($a3)
    ctx->pc = 0x126320u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 2)));
    // 0x126324: 0x82040  sll         $a0, $t0, 1
    ctx->pc = 0x126324u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x126328: 0x90e30000  lbu         $v1, 0x0($a3)
    ctx->pc = 0x126328u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x12632c: 0x8a2821  addu        $a1, $a0, $t2
    ctx->pc = 0x12632cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 10)));
    // 0x126330: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x126330u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x126334: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x126334u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x126338: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x126338u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x12633c: 0x8b2021  addu        $a0, $a0, $t3
    ctx->pc = 0x12633cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 11)));
    // 0x126340: 0xa4a30000  sh          $v1, 0x0($a1)
    ctx->pc = 0x126340u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x126344: 0x109302a  slt         $a2, $t0, $t1
    ctx->pc = 0x126344u;
    SET_GPR_U64(ctx, 6, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x126348: 0x90e20003  lbu         $v0, 0x3($a3)
    ctx->pc = 0x126348u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 3)));
    // 0x12634c: 0x90e30001  lbu         $v1, 0x1($a3)
    ctx->pc = 0x12634cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 1)));
    // 0x126350: 0x24e70004  addiu       $a3, $a3, 0x4
    ctx->pc = 0x126350u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4));
    // 0x126354: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x126354u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x126358: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x126358u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x12635c: 0x14c0fff0  bnez        $a2, . + 4 + (-0x10 << 2)
    ctx->pc = 0x12635Cu;
    {
        const bool branch_taken_0x12635c = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x126360u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12635Cu;
            // 0x126360: 0xa4830000  sh          $v1, 0x0($a0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12635c) {
            ctx->pc = 0x126320u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_126320;
        }
    }
    ctx->pc = 0x126364u;
    // 0x126364: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x126364u;
    {
        const bool branch_taken_0x126364 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x126368u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126364u;
            // 0x126368: 0x9203000e  lbu         $v1, 0xE($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126364) {
            ctx->pc = 0x1263ACu;
            goto label_1263ac;
        }
    }
    ctx->pc = 0x12636Cu;
    // 0x12636c: 0x0  nop
    ctx->pc = 0x12636cu;
    // NOP
label_126370:
    // 0x126370: 0x1920000e  blez        $t1, . + 4 + (0xE << 2)
    ctx->pc = 0x126370u;
    {
        const bool branch_taken_0x126370 = (GPR_S64(ctx, 9) <= 0);
        ctx->pc = 0x126374u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126370u;
            // 0x126374: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126370) {
            ctx->pc = 0x1263ACu;
            goto label_1263ac;
        }
    }
    ctx->pc = 0x126378u;
    // 0x126378: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x126378u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12637c: 0x140302d  daddu       $a2, $t2, $zero
    ctx->pc = 0x12637cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
label_126380:
    // 0x126380: 0x90a20001  lbu         $v0, 0x1($a1)
    ctx->pc = 0x126380u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 1)));
    // 0x126384: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x126384u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x126388: 0x90a30000  lbu         $v1, 0x0($a1)
    ctx->pc = 0x126388u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x12638c: 0x24a50002  addiu       $a1, $a1, 0x2
    ctx->pc = 0x12638cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 2));
    // 0x126390: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x126390u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x126394: 0x109202a  slt         $a0, $t0, $t1
    ctx->pc = 0x126394u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x126398: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x126398u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x12639c: 0xa4c30000  sh          $v1, 0x0($a2)
    ctx->pc = 0x12639cu;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1263a0: 0x1480fff7  bnez        $a0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x1263A0u;
    {
        const bool branch_taken_0x1263a0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1263A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1263A0u;
            // 0x1263a4: 0x24c60002  addiu       $a2, $a2, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1263a0) {
            ctx->pc = 0x126380u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_126380;
        }
    }
    ctx->pc = 0x1263A8u;
    // 0x1263a8: 0x9203000e  lbu         $v1, 0xE($s0)
    ctx->pc = 0x1263a8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
label_1263ac:
    // 0x1263ac: 0x31600  sll         $v0, $v1, 24
    ctx->pc = 0x1263acu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x1263b0: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1263b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1263b4: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x1263b4u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x1263b8: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x1263b8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
    // 0x1263bc: 0x1221018  mult        $v0, $t1, $v0
    ctx->pc = 0x1263bcu;
    { int64_t result = (int64_t)GPR_S32(ctx, 9) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x1263c0: 0xae090090  sw          $t1, 0x90($s0)
    ctx->pc = 0x1263c0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 9));
    // 0x1263c4: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1263c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1263c8: 0xae020094  sw          $v0, 0x94($s0)
    ctx->pc = 0x1263c8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 148), GPR_U32(ctx, 2));
label_1263cc:
    // 0x1263cc: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1263ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1263d0: 0x54620009  bnel        $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1263D0u;
    {
        const bool branch_taken_0x1263d0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1263d0) {
            ctx->pc = 0x1263D4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1263D0u;
            // 0x1263d4: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1263F8u;
            goto label_1263f8;
        }
    }
    ctx->pc = 0x1263D8u;
    // 0x1263d8: 0x8e030080  lw          $v1, 0x80($s0)
    ctx->pc = 0x1263d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 128)));
    // 0x1263dc: 0x8e040084  lw          $a0, 0x84($s0)
    ctx->pc = 0x1263dcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 132)));
    // 0x1263e0: 0x8e050094  lw          $a1, 0x94($s0)
    ctx->pc = 0x1263e0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 148)));
    // 0x1263e4: 0x60f809  jalr        $v1
    ctx->pc = 0x1263E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x1263ECu);
        ctx->pc = 0x1263E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1263E4u;
            // 0x1263e8: 0x8e060090  lw          $a2, 0x90($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 144)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1263ECu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x125C30u: goto label_125c30;
            case 0x125C88u: goto label_125c88;
            case 0x125CA0u: goto label_125ca0;
            case 0x125CA8u: goto label_125ca8;
            case 0x125CE0u: goto label_125ce0;
            case 0x125CF8u: goto label_125cf8;
            case 0x125D00u: goto label_125d00;
            case 0x125D64u: goto label_125d64;
            case 0x125D90u: goto label_125d90;
            case 0x125DA8u: goto label_125da8;
            case 0x125DE0u: goto label_125de0;
            case 0x125DF8u: goto label_125df8;
            case 0x125DFCu: goto label_125dfc;
            case 0x125E30u: goto label_125e30;
            case 0x125E34u: goto label_125e34;
            case 0x125E38u: goto label_125e38;
            case 0x125E60u: goto label_125e60;
            case 0x125ECCu: goto label_125ecc;
            case 0x125EE0u: goto label_125ee0;
            case 0x125F3Cu: goto label_125f3c;
            case 0x125F60u: goto label_125f60;
            case 0x125F94u: goto label_125f94;
            case 0x125FB4u: goto label_125fb4;
            case 0x126010u: goto label_126010;
            case 0x126048u: goto label_126048;
            case 0x126050u: goto label_126050;
            case 0x126074u: goto label_126074;
            case 0x126094u: goto label_126094;
            case 0x1260B4u: goto label_1260b4;
            case 0x1260C0u: goto label_1260c0;
            case 0x1260D8u: goto label_1260d8;
            case 0x12610Cu: goto label_12610c;
            case 0x12612Cu: goto label_12612c;
            case 0x126190u: goto label_126190;
            case 0x1261D8u: goto label_1261d8;
            case 0x1261E8u: goto label_1261e8;
            case 0x126210u: goto label_126210;
            case 0x12622Cu: goto label_12622c;
            case 0x12624Cu: goto label_12624c;
            case 0x126258u: goto label_126258;
            case 0x126270u: goto label_126270;
            case 0x1262A4u: goto label_1262a4;
            case 0x1262C4u: goto label_1262c4;
            case 0x126320u: goto label_126320;
            case 0x126370u: goto label_126370;
            case 0x126380u: goto label_126380;
            case 0x1263ACu: goto label_1263ac;
            case 0x1263CCu: goto label_1263cc;
            case 0x1263ECu: goto label_1263ec;
            case 0x1263F8u: goto label_1263f8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1263ECu; }
            if (ctx->pc != 0x1263ECu) { return; }
        }
        }
    }
    ctx->pc = 0x1263ECu;
label_1263ec:
    // 0x1263ec: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1263ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1263f0: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x1263f0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x1263f4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1263f4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1263f8:
    // 0x1263f8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1263f8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1263fc: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1263fcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x126400: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x126400u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x126404: 0x3e00008  jr          $ra
    ctx->pc = 0x126404u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x126408u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126404u;
            // 0x126408: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x125C30u: goto label_125c30;
            case 0x125C88u: goto label_125c88;
            case 0x125CA0u: goto label_125ca0;
            case 0x125CA8u: goto label_125ca8;
            case 0x125CE0u: goto label_125ce0;
            case 0x125CF8u: goto label_125cf8;
            case 0x125D00u: goto label_125d00;
            case 0x125D64u: goto label_125d64;
            case 0x125D90u: goto label_125d90;
            case 0x125DA8u: goto label_125da8;
            case 0x125DE0u: goto label_125de0;
            case 0x125DF8u: goto label_125df8;
            case 0x125DFCu: goto label_125dfc;
            case 0x125E30u: goto label_125e30;
            case 0x125E34u: goto label_125e34;
            case 0x125E38u: goto label_125e38;
            case 0x125E60u: goto label_125e60;
            case 0x125ECCu: goto label_125ecc;
            case 0x125EE0u: goto label_125ee0;
            case 0x125F3Cu: goto label_125f3c;
            case 0x125F60u: goto label_125f60;
            case 0x125F94u: goto label_125f94;
            case 0x125FB4u: goto label_125fb4;
            case 0x126010u: goto label_126010;
            case 0x126048u: goto label_126048;
            case 0x126050u: goto label_126050;
            case 0x126074u: goto label_126074;
            case 0x126094u: goto label_126094;
            case 0x1260B4u: goto label_1260b4;
            case 0x1260C0u: goto label_1260c0;
            case 0x1260D8u: goto label_1260d8;
            case 0x12610Cu: goto label_12610c;
            case 0x12612Cu: goto label_12612c;
            case 0x126190u: goto label_126190;
            case 0x1261D8u: goto label_1261d8;
            case 0x1261E8u: goto label_1261e8;
            case 0x126210u: goto label_126210;
            case 0x12622Cu: goto label_12622c;
            case 0x12624Cu: goto label_12624c;
            case 0x126258u: goto label_126258;
            case 0x126270u: goto label_126270;
            case 0x1262A4u: goto label_1262a4;
            case 0x1262C4u: goto label_1262c4;
            case 0x126320u: goto label_126320;
            case 0x126370u: goto label_126370;
            case 0x126380u: goto label_126380;
            case 0x1263ACu: goto label_1263ac;
            case 0x1263CCu: goto label_1263cc;
            case 0x1263ECu: goto label_1263ec;
            case 0x1263F8u: goto label_1263f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12640Cu;
    // 0x12640c: 0x0  nop
    ctx->pc = 0x12640cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
