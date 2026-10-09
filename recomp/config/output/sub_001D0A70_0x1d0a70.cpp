#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D0A70
// Address: 0x1d0a70 - 0x1d0b6c
void sub_001D0A70_0x1d0a70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D0A70_0x1d0a70");
#endif

    switch (ctx->pc) {
        case 0x1d0abcu: goto label_1d0abc;
        case 0x1d0ad8u: goto label_1d0ad8;
        case 0x1d0aecu: goto label_1d0aec;
        case 0x1d0b20u: goto label_1d0b20;
        case 0x1d0b34u: goto label_1d0b34;
        default: break;
    }

    ctx->pc = 0x1d0a70u;

    // 0x1d0a70: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1d0a70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1d0a74: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0a74u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0a78: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1d0a78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1d0a7c: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d0a7cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d0a80: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d0a80u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d0a84: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1d0a84u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0a88: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d0a88u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d0a8c: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1d0a8cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0a90: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d0a90u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d0a94: 0x802243d7  lb          $v0, 0x43D7($at)
    ctx->pc = 0x1d0a94u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d0a98: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1D0A98u;
    {
        const bool branch_taken_0x1d0a98 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D0A9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0A98u;
            // 0x1d0a9c: 0xc0882d  daddu       $s1, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0a98) {
            ctx->pc = 0x1D0AC4u;
            goto label_1d0ac4;
        }
    }
    ctx->pc = 0x1D0AA0u;
    // 0x1d0aa0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0aa0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0aa4: 0x902443da  lbu         $a0, 0x43DA($at)
    ctx->pc = 0x1d0aa4u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d0aa8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0aa8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0aac: 0x902543dc  lbu         $a1, 0x43DC($at)
    ctx->pc = 0x1d0aacu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17372)));
    // 0x1d0ab0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d0ab0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d0ab4: 0xc06a930  jal         func_1AA4C0
    ctx->pc = 0x1D0AB4u;
    SET_GPR_U32(ctx, 31, 0x1D0ABCu);
    ctx->pc = 0x1D0AB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0AB4u;
            // 0x1d0ab8: 0x902643de  lbu         $a2, 0x43DE($at) (Delay Slot)
        SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17374)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AA4C0u;
    if (runtime->hasFunction(0x1AA4C0u)) {
        auto targetFn = runtime->lookupFunction(0x1AA4C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0ABCu; }
        if (ctx->pc != 0x1D0ABCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AA4C0_0x1aa4c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0ABCu; }
        if (ctx->pc != 0x1D0ABCu) { return; }
    }
    ctx->pc = 0x1D0ABCu;
label_1d0abc:
    // 0x1d0abc: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x1D0ABCu;
    {
        const bool branch_taken_0x1d0abc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D0AC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0ABCu;
            // 0x1d0ac0: 0xdfbf0040  ld          $ra, 0x40($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0abc) {
            ctx->pc = 0x1D0B54u;
            goto label_1d0b54;
        }
    }
    ctx->pc = 0x1D0AC4u;
label_1d0ac4:
    // 0x1d0ac4: 0x3c010057  lui         $at, 0x57
    ctx->pc = 0x1d0ac4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)87 << 16));
    // 0x1d0ac8: 0x902297b8  lbu         $v0, -0x6848($at)
    ctx->pc = 0x1d0ac8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294940600)));
    // 0x1d0acc: 0x211c0  sll         $v0, $v0, 7
    ctx->pc = 0x1d0accu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 7));
    // 0x1d0ad0: 0xc073470  jal         func_1CD1C0
    ctx->pc = 0x1D0AD0u;
    SET_GPR_U32(ctx, 31, 0x1D0AD8u);
    ctx->pc = 0x1D0AD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0AD0u;
            // 0x1d0ad4: 0x24441800  addiu       $a0, $v0, 0x1800 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 6144));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD1C0u;
    if (runtime->hasFunction(0x1CD1C0u)) {
        auto targetFn = runtime->lookupFunction(0x1CD1C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0AD8u; }
        if (ctx->pc != 0x1D0AD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD1C0_0x1cd1c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0AD8u; }
        if (ctx->pc != 0x1D0AD8u) { return; }
    }
    ctx->pc = 0x1D0AD8u;
label_1d0ad8:
    // 0x1d0ad8: 0x3c10004a  lui         $s0, 0x4A
    ctx->pc = 0x1d0ad8u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)74 << 16));
    // 0x1d0adc: 0x24040080  addiu       $a0, $zero, 0x80
    ctx->pc = 0x1d0adcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x1d0ae0: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x1d0ae0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1d0ae4: 0xc06ca9c  jal         func_1B2A70
    ctx->pc = 0x1D0AE4u;
    SET_GPR_U32(ctx, 31, 0x1D0AECu);
    ctx->pc = 0x1D0AE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0AE4u;
            // 0x1d0ae8: 0x2610ef50  addiu       $s0, $s0, -0x10B0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294963024));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2A70u;
    if (runtime->hasFunction(0x1B2A70u)) {
        auto targetFn = runtime->lookupFunction(0x1B2A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0AECu; }
        if (ctx->pc != 0x1D0AECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2A70_0x1b2a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0AECu; }
        if (ctx->pc != 0x1D0AECu) { return; }
    }
    ctx->pc = 0x1D0AECu;
label_1d0aec:
    // 0x1d0aec: 0x326400ff  andi        $a0, $s3, 0xFF
    ctx->pc = 0x1d0aecu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)255);
    // 0x1d0af0: 0x324300ff  andi        $v1, $s2, 0xFF
    ctx->pc = 0x1d0af0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)255);
    // 0x1d0af4: 0x42400  sll         $a0, $a0, 16
    ctx->pc = 0x1d0af4u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x1d0af8: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x1d0af8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x1d0afc: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x1d0afcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1d0b00: 0xae020808  sw          $v0, 0x808($s0)
    ctx->pc = 0x1d0b00u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 2056), GPR_U32(ctx, 2));
    // 0x1d0b04: 0x322300ff  andi        $v1, $s1, 0xFF
    ctx->pc = 0x1d0b04u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)255);
    // 0x1d0b08: 0x2405ffff  addiu       $a1, $zero, -0x1
    ctx->pc = 0x1d0b08u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d0b0c: 0x642025  or          $a0, $v1, $a0
    ctx->pc = 0x1d0b0cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1d0b10: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1d0b10u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0b14: 0x24070002  addiu       $a3, $zero, 0x2
    ctx->pc = 0x1d0b14u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d0b18: 0xc073844  jal         func_1CE110
    ctx->pc = 0x1D0B18u;
    SET_GPR_U32(ctx, 31, 0x1D0B20u);
    ctx->pc = 0x1D0B1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0B18u;
            // 0x1d0b1c: 0xae000818  sw          $zero, 0x818($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 2072), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CE110u;
    if (runtime->hasFunction(0x1CE110u)) {
        auto targetFn = runtime->lookupFunction(0x1CE110u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0B20u; }
        if (ctx->pc != 0x1D0B20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CE110_0x1ce110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D0B20u; }
        if (ctx->pc != 0x1D0B20u) { return; }
    }
    ctx->pc = 0x1D0B20u;
label_1d0b20:
    // 0x1d0b20: 0x3c04004a  lui         $a0, 0x4A
    ctx->pc = 0x1d0b20u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)74 << 16));
    // 0x1d0b24: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1d0b24u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d0b28: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1d0b28u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d0b2c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1D0B2Cu;
    {
        const bool branch_taken_0x1d0b2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D0B30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0B2Cu;
            // 0x1d0b30: 0x2484eef0  addiu       $a0, $a0, -0x1110 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294962928));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d0b2c) {
            ctx->pc = 0x1D0B40u;
            goto label_1d0b40;
        }
    }
    ctx->pc = 0x1D0B34u;
label_1d0b34:
    // 0x1d0b34: 0x861821  addu        $v1, $a0, $a2
    ctx->pc = 0x1d0b34u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
    // 0x1d0b38: 0xa06508a0  sb          $a1, 0x8A0($v1)
    ctx->pc = 0x1d0b38u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 2208), (uint8_t)GPR_U32(ctx, 5));
    // 0x1d0b3c: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1d0b3cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
label_1d0b40:
    // 0x1d0b40: 0x96030812  lhu         $v1, 0x812($s0)
    ctx->pc = 0x1d0b40u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 2066)));
    // 0x1d0b44: 0xc3182a  slt         $v1, $a2, $v1
    ctx->pc = 0x1d0b44u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1d0b48: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1D0B48u;
    {
        const bool branch_taken_0x1d0b48 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d0b48) {
            ctx->pc = 0x1D0B34u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d0b34;
        }
    }
    ctx->pc = 0x1D0B50u;
    // 0x1d0b50: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1d0b50u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
label_1d0b54:
    // 0x1d0b54: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d0b54u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d0b58: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d0b58u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d0b5c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d0b5cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d0b60: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d0b60u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d0b64: 0x3e00008  jr          $ra
    ctx->pc = 0x1D0B64u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D0B68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D0B64u;
            // 0x1d0b68: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D0ABCu: goto label_1d0abc;
            case 0x1D0AC4u: goto label_1d0ac4;
            case 0x1D0AD8u: goto label_1d0ad8;
            case 0x1D0AECu: goto label_1d0aec;
            case 0x1D0B20u: goto label_1d0b20;
            case 0x1D0B34u: goto label_1d0b34;
            case 0x1D0B40u: goto label_1d0b40;
            case 0x1D0B54u: goto label_1d0b54;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D0B6Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
