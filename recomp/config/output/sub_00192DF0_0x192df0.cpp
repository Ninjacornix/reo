#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00192DF0
// Address: 0x192df0 - 0x193000
void sub_00192DF0_0x192df0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00192DF0_0x192df0");
#endif

    switch (ctx->pc) {
        case 0x192e34u: goto label_192e34;
        case 0x192e98u: goto label_192e98;
        case 0x192eb0u: goto label_192eb0;
        case 0x192ef0u: goto label_192ef0;
        case 0x192f10u: goto label_192f10;
        case 0x192f98u: goto label_192f98;
        case 0x192facu: goto label_192fac;
        default: break;
    }

    ctx->pc = 0x192df0u;

    // 0x192df0: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x192df0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x192df4: 0xffbf0090  sd          $ra, 0x90($sp)
    ctx->pc = 0x192df4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 31));
    // 0x192df8: 0x7fb70080  sq          $s7, 0x80($sp)
    ctx->pc = 0x192df8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 128), GPR_VEC(ctx, 23));
    // 0x192dfc: 0x7fb60070  sq          $s6, 0x70($sp)
    ctx->pc = 0x192dfcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 112), GPR_VEC(ctx, 22));
    // 0x192e00: 0x100b82d  daddu       $s7, $t0, $zero
    ctx->pc = 0x192e00u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192e04: 0x7fb50060  sq          $s5, 0x60($sp)
    ctx->pc = 0x192e04u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 21));
    // 0x192e08: 0x80b02d  daddu       $s6, $a0, $zero
    ctx->pc = 0x192e08u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192e0c: 0x7fb40050  sq          $s4, 0x50($sp)
    ctx->pc = 0x192e0cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 20));
    // 0x192e10: 0xc0a82d  daddu       $s5, $a2, $zero
    ctx->pc = 0x192e10u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192e14: 0x7fb30040  sq          $s3, 0x40($sp)
    ctx->pc = 0x192e14u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 19));
    // 0x192e18: 0xe0a02d  daddu       $s4, $a3, $zero
    ctx->pc = 0x192e18u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192e1c: 0x7fb20030  sq          $s2, 0x30($sp)
    ctx->pc = 0x192e1cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 18));
    // 0x192e20: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x192e20u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192e24: 0x7fb10020  sq          $s1, 0x20($sp)
    ctx->pc = 0x192e24u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 17));
    // 0x192e28: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x192e28u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x192e2c: 0xe7b40000  swc1        $f20, 0x0($sp)
    ctx->pc = 0x192e2cu;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x192e30: 0x46006506  mov.s       $f20, $f12
    ctx->pc = 0x192e30u;
    ctx->f[20] = FPU_MOV_S(ctx->f[12]);
label_192e34:
    // 0x192e34: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x192e34u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x192e38: 0xa31021  addu        $v0, $a1, $v1
    ctx->pc = 0x192e38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x192e3c: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x192e3cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x192e40: 0xc4400000  lwc1        $f0, 0x0($v0)
    ctx->pc = 0x192e40u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x192e44: 0x2a31821  addu        $v1, $s5, $v1
    ctx->pc = 0x192e44u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 3)));
    // 0x192e48: 0x2882000a  slti        $v0, $a0, 0xA
    ctx->pc = 0x192e48u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)10) ? 1 : 0);
    // 0x192e4c: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x192E4Cu;
    {
        const bool branch_taken_0x192e4c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x192E50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192E4Cu;
            // 0x192e50: 0xe4600000  swc1        $f0, 0x0($v1) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 0), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x192e4c) {
            ctx->pc = 0x192E34u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192e34;
        }
    }
    ctx->pc = 0x192E54u;
    // 0x192e54: 0x12c0004b  beqz        $s6, . + 4 + (0x4B << 2)
    ctx->pc = 0x192E54u;
    {
        const bool branch_taken_0x192e54 = (GPR_U64(ctx, 22) == GPR_U64(ctx, 0));
        if (branch_taken_0x192e54) {
            ctx->pc = 0x192F84u;
            goto label_192f84;
        }
    }
    ctx->pc = 0x192E5Cu;
    // 0x192e5c: 0x96c30000  lhu         $v1, 0x0($s6)
    ctx->pc = 0x192e5cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x192e60: 0x24022000  addiu       $v0, $zero, 0x2000
    ctx->pc = 0x192e60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
    // 0x192e64: 0x3063f000  andi        $v1, $v1, 0xF000
    ctx->pc = 0x192e64u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)61440);
    // 0x192e68: 0x1062001c  beq         $v1, $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x192E68u;
    {
        const bool branch_taken_0x192e68 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x192E6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192E68u;
            // 0x192e6c: 0x3c010029  lui         $at, 0x29 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x192e68) {
            ctx->pc = 0x192EDCu;
            goto label_192edc;
        }
    }
    ctx->pc = 0x192E70u;
    // 0x192e70: 0x24021000  addiu       $v0, $zero, 0x1000
    ctx->pc = 0x192e70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x192e74: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x192E74u;
    {
        const bool branch_taken_0x192e74 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x192E78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192E74u;
            // 0x192e78: 0x3c010029  lui         $at, 0x29 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x192e74) {
            ctx->pc = 0x192E84u;
            goto label_192e84;
        }
    }
    ctx->pc = 0x192E7Cu;
    // 0x192e7c: 0x10000042  b           . + 4 + (0x42 << 2)
    ctx->pc = 0x192E7Cu;
    {
        const bool branch_taken_0x192e7c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x192E80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192E7Cu;
            // 0x192e80: 0xc6ac0000  lwc1        $f12, 0x0($s5) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 21), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
        ctx->in_delay_slot = false;
        if (branch_taken_0x192e7c) {
            ctx->pc = 0x192F88u;
            goto label_192f88;
        }
    }
    ctx->pc = 0x192E84u;
label_192e84:
    // 0x192e84: 0x8ec30004  lw          $v1, 0x4($s6)
    ctx->pc = 0x192e84u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 4)));
    // 0x192e88: 0x8c224168  lw          $v0, 0x4168($at)
    ctx->pc = 0x192e88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16744)));
    // 0x192e8c: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x192e8cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192e90: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x192E90u;
    {
        const bool branch_taken_0x192e90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x192E94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192E90u;
            // 0x192e94: 0x629021  addu        $s2, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x192e90) {
            ctx->pc = 0x192EC4u;
            goto label_192ec4;
        }
    }
    ctx->pc = 0x192E98u;
label_192e98:
    // 0x192e98: 0x92510001  lbu         $s1, 0x1($s2)
    ctx->pc = 0x192e98u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 1)));
    // 0x192e9c: 0x4600a306  mov.s       $f12, $f20
    ctx->pc = 0x192e9cu;
    ctx->f[12] = FPU_MOV_S(ctx->f[20]);
    // 0x192ea0: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x192ea0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192ea4: 0x111040  sll         $v0, $s1, 1
    ctx->pc = 0x192ea4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 1));
    // 0x192ea8: 0xc0638f0  jal         func_18E3C0
    ctx->pc = 0x192EA8u;
    SET_GPR_U32(ctx, 31, 0x192EB0u);
    ctx->pc = 0x192EACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x192EA8u;
            // 0x192eac: 0x2e22821  addu        $a1, $s7, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18E3C0u;
    if (runtime->hasFunction(0x18E3C0u)) {
        auto targetFn = runtime->lookupFunction(0x18E3C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192EB0u; }
        if (ctx->pc != 0x192EB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018E3C0_0x18e3c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192EB0u; }
        if (ctx->pc != 0x192EB0u) { return; }
    }
    ctx->pc = 0x192EB0u;
label_192eb0:
    // 0x192eb0: 0x111080  sll         $v0, $s1, 2
    ctx->pc = 0x192eb0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
    // 0x192eb4: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x192eb4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x192eb8: 0x2a21021  addu        $v0, $s5, $v0
    ctx->pc = 0x192eb8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 2)));
    // 0x192ebc: 0x26520008  addiu       $s2, $s2, 0x8
    ctx->pc = 0x192ebcu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 8));
    // 0x192ec0: 0xe4400000  swc1        $f0, 0x0($v0)
    ctx->pc = 0x192ec0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 0), bits); }
label_192ec4:
    // 0x192ec4: 0x86c20002  lh          $v0, 0x2($s6)
    ctx->pc = 0x192ec4u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 22), 2)));
    // 0x192ec8: 0x202102a  slt         $v0, $s0, $v0
    ctx->pc = 0x192ec8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x192ecc: 0x1440fff2  bnez        $v0, . + 4 + (-0xE << 2)
    ctx->pc = 0x192ECCu;
    {
        const bool branch_taken_0x192ecc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x192ecc) {
            ctx->pc = 0x192E98u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192e98;
        }
    }
    ctx->pc = 0x192ED4u;
    // 0x192ed4: 0x1000002b  b           . + 4 + (0x2B << 2)
    ctx->pc = 0x192ED4u;
    {
        const bool branch_taken_0x192ed4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x192ed4) {
            ctx->pc = 0x192F84u;
            goto label_192f84;
        }
    }
    ctx->pc = 0x192EDCu;
label_192edc:
    // 0x192edc: 0x8ec30004  lw          $v1, 0x4($s6)
    ctx->pc = 0x192edcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 4)));
    // 0x192ee0: 0x8c224168  lw          $v0, 0x4168($at)
    ctx->pc = 0x192ee0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16744)));
    // 0x192ee4: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x192ee4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192ee8: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x192EE8u;
    {
        const bool branch_taken_0x192ee8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x192EECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192EE8u;
            // 0x192eec: 0x628021  addu        $s0, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x192ee8) {
            ctx->pc = 0x192F74u;
            goto label_192f74;
        }
    }
    ctx->pc = 0x192EF0u;
label_192ef0:
    // 0x192ef0: 0x92130001  lbu         $s3, 0x1($s0)
    ctx->pc = 0x192ef0u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x192ef4: 0x4600a306  mov.s       $f12, $f20
    ctx->pc = 0x192ef4u;
    ctx->f[12] = FPU_MOV_S(ctx->f[20]);
    // 0x192ef8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x192ef8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192efc: 0x131880  sll         $v1, $s3, 2
    ctx->pc = 0x192efcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 19), 2));
    // 0x192f00: 0x131040  sll         $v0, $s3, 1
    ctx->pc = 0x192f00u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 19), 1));
    // 0x192f04: 0x2a39021  addu        $s2, $s5, $v1
    ctx->pc = 0x192f04u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 3)));
    // 0x192f08: 0xc0638f0  jal         func_18E3C0
    ctx->pc = 0x192F08u;
    SET_GPR_U32(ctx, 31, 0x192F10u);
    ctx->pc = 0x192F0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x192F08u;
            // 0x192f0c: 0x2e22821  addu        $a1, $s7, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18E3C0u;
    if (runtime->hasFunction(0x18E3C0u)) {
        auto targetFn = runtime->lookupFunction(0x18E3C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192F10u; }
        if (ctx->pc != 0x192F10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018E3C0_0x18e3c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192F10u; }
        if (ctx->pc != 0x192F10u) { return; }
    }
    ctx->pc = 0x192F10u;
label_192f10:
    // 0x192f10: 0x3263ffff  andi        $v1, $s3, 0xFFFF
    ctx->pc = 0x192f10u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)65535);
    // 0x192f14: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x192f14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x192f18: 0x10620009  beq         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x192F18u;
    {
        const bool branch_taken_0x192f18 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x192F1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192F18u;
            // 0x192f1c: 0xe6400000  swc1        $f0, 0x0($s2) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 18), 0), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x192f18) {
            ctx->pc = 0x192F40u;
            goto label_192f40;
        }
    }
    ctx->pc = 0x192F20u;
    // 0x192f20: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x192f20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x192f24: 0x10620006  beq         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x192F24u;
    {
        const bool branch_taken_0x192f24 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x192f24) {
            ctx->pc = 0x192F40u;
            goto label_192f40;
        }
    }
    ctx->pc = 0x192F2Cu;
    // 0x192f2c: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x192f2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x192f30: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x192F30u;
    {
        const bool branch_taken_0x192f30 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x192f30) {
            ctx->pc = 0x192F40u;
            goto label_192f40;
        }
    }
    ctx->pc = 0x192F38u;
    // 0x192f38: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x192F38u;
    {
        const bool branch_taken_0x192f38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x192F3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192F38u;
            // 0x192f3c: 0xc6400000  lwc1        $f0, 0x0($s2) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
        ctx->in_delay_slot = false;
        if (branch_taken_0x192f38) {
            ctx->pc = 0x192F58u;
            goto label_192f58;
        }
    }
    ctx->pc = 0x192F40u;
label_192f40:
    // 0x192f40: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x192f40u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x192f44: 0xc6410000  lwc1        $f1, 0x0($s2)
    ctx->pc = 0x192f44u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x192f48: 0xc4201c98  lwc1        $f0, 0x1C98($at)
    ctx->pc = 0x192f48u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 7320)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x192f4c: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x192f4cu;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x192f50: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x192F50u;
    {
        const bool branch_taken_0x192f50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x192F54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192F50u;
            // 0x192f54: 0xe6400000  swc1        $f0, 0x0($s2) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 18), 0), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x192f50) {
            ctx->pc = 0x192F6Cu;
            goto label_192f6c;
        }
    }
    ctx->pc = 0x192F58u;
label_192f58:
    // 0x192f58: 0x3c024180  lui         $v0, 0x4180
    ctx->pc = 0x192f58u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16768 << 16));
    // 0x192f5c: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x192f5cu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x192f60: 0x0  nop
    ctx->pc = 0x192f60u;
    // NOP
    // 0x192f64: 0x46010003  div.s       $f0, $f0, $f1
    ctx->pc = 0x192f64u;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[0]) ^ std::bit_cast<uint32_t>(ctx->f[1])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[0] / ctx->f[1];
    // 0x192f68: 0xe6400000  swc1        $f0, 0x0($s2)
    ctx->pc = 0x192f68u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 18), 0), bits); }
label_192f6c:
    // 0x192f6c: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x192f6cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x192f70: 0x26100008  addiu       $s0, $s0, 0x8
    ctx->pc = 0x192f70u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
label_192f74:
    // 0x192f74: 0x86c20002  lh          $v0, 0x2($s6)
    ctx->pc = 0x192f74u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 22), 2)));
    // 0x192f78: 0x222102a  slt         $v0, $s1, $v0
    ctx->pc = 0x192f78u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x192f7c: 0x1440ffdc  bnez        $v0, . + 4 + (-0x24 << 2)
    ctx->pc = 0x192F7Cu;
    {
        const bool branch_taken_0x192f7c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x192f7c) {
            ctx->pc = 0x192EF0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_192ef0;
        }
    }
    ctx->pc = 0x192F84u;
label_192f84:
    // 0x192f84: 0xc6ac0000  lwc1        $f12, 0x0($s5)
    ctx->pc = 0x192f84u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 21), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
label_192f88:
    // 0x192f88: 0xc6ad0004  lwc1        $f13, 0x4($s5)
    ctx->pc = 0x192f88u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 21), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[13] = f; }
    // 0x192f8c: 0xc6ae0008  lwc1        $f14, 0x8($s5)
    ctx->pc = 0x192f8cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 21), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[14] = f; }
    // 0x192f90: 0xc063f98  jal         func_18FE60
    ctx->pc = 0x192F90u;
    SET_GPR_U32(ctx, 31, 0x192F98u);
    ctx->pc = 0x192F94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x192F90u;
            // 0x192f94: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18FE60u;
    if (runtime->hasFunction(0x18FE60u)) {
        auto targetFn = runtime->lookupFunction(0x18FE60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192F98u; }
        if (ctx->pc != 0x192F98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018FE60_0x18fe60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192F98u; }
        if (ctx->pc != 0x192F98u) { return; }
    }
    ctx->pc = 0x192F98u;
label_192f98:
    // 0x192f98: 0xc6ac000c  lwc1        $f12, 0xC($s5)
    ctx->pc = 0x192f98u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 21), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x192f9c: 0xc6ad0010  lwc1        $f13, 0x10($s5)
    ctx->pc = 0x192f9cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 21), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[13] = f; }
    // 0x192fa0: 0xc6ae0014  lwc1        $f14, 0x14($s5)
    ctx->pc = 0x192fa0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 21), 20)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[14] = f; }
    // 0x192fa4: 0xc064284  jal         func_190A10
    ctx->pc = 0x192FA4u;
    SET_GPR_U32(ctx, 31, 0x192FACu);
    ctx->pc = 0x192FA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x192FA4u;
            // 0x192fa8: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x190A10u;
    if (runtime->hasFunction(0x190A10u)) {
        auto targetFn = runtime->lookupFunction(0x190A10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192FACu; }
        if (ctx->pc != 0x192FACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00190A10_0x190a10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192FACu; }
        if (ctx->pc != 0x192FACu) { return; }
    }
    ctx->pc = 0x192FACu;
label_192fac:
    // 0x192fac: 0xc6a00018  lwc1        $f0, 0x18($s5)
    ctx->pc = 0x192facu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 21), 24)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x192fb0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x192fb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x192fb4: 0xe6800030  swc1        $f0, 0x30($s4)
    ctx->pc = 0x192fb4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 20), 48), bits); }
    // 0x192fb8: 0xc6a0001c  lwc1        $f0, 0x1C($s5)
    ctx->pc = 0x192fb8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 21), 28)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x192fbc: 0xe6800034  swc1        $f0, 0x34($s4)
    ctx->pc = 0x192fbcu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 20), 52), bits); }
    // 0x192fc0: 0xc6a00020  lwc1        $f0, 0x20($s5)
    ctx->pc = 0x192fc0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 21), 32)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x192fc4: 0xe6800038  swc1        $f0, 0x38($s4)
    ctx->pc = 0x192fc4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 20), 56), bits); }
    // 0x192fc8: 0xdfbf0090  ld          $ra, 0x90($sp)
    ctx->pc = 0x192fc8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x192fcc: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x192fccu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x192fd0: 0x7bb70080  lq          $s7, 0x80($sp)
    ctx->pc = 0x192fd0u;
    SET_GPR_VEC(ctx, 23, READ128(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x192fd4: 0x7bb60070  lq          $s6, 0x70($sp)
    ctx->pc = 0x192fd4u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x192fd8: 0x7bb50060  lq          $s5, 0x60($sp)
    ctx->pc = 0x192fd8u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x192fdc: 0x7bb40050  lq          $s4, 0x50($sp)
    ctx->pc = 0x192fdcu;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x192fe0: 0x7bb30040  lq          $s3, 0x40($sp)
    ctx->pc = 0x192fe0u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x192fe4: 0x7bb20030  lq          $s2, 0x30($sp)
    ctx->pc = 0x192fe4u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x192fe8: 0x7bb10020  lq          $s1, 0x20($sp)
    ctx->pc = 0x192fe8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x192fec: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x192fecu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x192ff0: 0x3e00008  jr          $ra
    ctx->pc = 0x192FF0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x192FF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192FF0u;
            // 0x192ff4: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x192E34u: goto label_192e34;
            case 0x192E84u: goto label_192e84;
            case 0x192E98u: goto label_192e98;
            case 0x192EB0u: goto label_192eb0;
            case 0x192EC4u: goto label_192ec4;
            case 0x192EDCu: goto label_192edc;
            case 0x192EF0u: goto label_192ef0;
            case 0x192F10u: goto label_192f10;
            case 0x192F40u: goto label_192f40;
            case 0x192F58u: goto label_192f58;
            case 0x192F6Cu: goto label_192f6c;
            case 0x192F74u: goto label_192f74;
            case 0x192F84u: goto label_192f84;
            case 0x192F88u: goto label_192f88;
            case 0x192F98u: goto label_192f98;
            case 0x192FACu: goto label_192fac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x192FF8u;
    // 0x192ff8: 0x0  nop
    ctx->pc = 0x192ff8u;
    // NOP
    // 0x192ffc: 0x0  nop
    ctx->pc = 0x192ffcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
