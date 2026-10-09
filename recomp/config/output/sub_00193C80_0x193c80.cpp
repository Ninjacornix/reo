#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00193C80
// Address: 0x193c80 - 0x193e20
void sub_00193C80_0x193c80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00193C80_0x193c80");
#endif

    switch (ctx->pc) {
        case 0x193cf8u: goto label_193cf8;
        case 0x193d10u: goto label_193d10;
        case 0x193d50u: goto label_193d50;
        case 0x193d70u: goto label_193d70;
        default: break;
    }

    ctx->pc = 0x193c80u;

    // 0x193c80: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x193c80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x193c84: 0xffbf0080  sd          $ra, 0x80($sp)
    ctx->pc = 0x193c84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 31));
    // 0x193c88: 0x7fb60070  sq          $s6, 0x70($sp)
    ctx->pc = 0x193c88u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 112), GPR_VEC(ctx, 22));
    // 0x193c8c: 0x7fb50060  sq          $s5, 0x60($sp)
    ctx->pc = 0x193c8cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 21));
    // 0x193c90: 0x7fb40050  sq          $s4, 0x50($sp)
    ctx->pc = 0x193c90u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 20));
    // 0x193c94: 0x7fb30040  sq          $s3, 0x40($sp)
    ctx->pc = 0x193c94u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 19));
    // 0x193c98: 0x7fb20030  sq          $s2, 0x30($sp)
    ctx->pc = 0x193c98u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 18));
    // 0x193c9c: 0x7fb10020  sq          $s1, 0x20($sp)
    ctx->pc = 0x193c9cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 17));
    // 0x193ca0: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x193ca0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193ca4: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x193ca4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x193ca8: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x193ca8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193cac: 0xe7b40000  swc1        $f20, 0x0($sp)
    ctx->pc = 0x193cacu;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x193cb0: 0xe0802d  daddu       $s0, $a3, $zero
    ctx->pc = 0x193cb0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193cb4: 0x1240004b  beqz        $s2, . + 4 + (0x4B << 2)
    ctx->pc = 0x193CB4u;
    {
        const bool branch_taken_0x193cb4 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x193CB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193CB4u;
            // 0x193cb8: 0x46006506  mov.s       $f20, $f12 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[12]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x193cb4) {
            ctx->pc = 0x193DE4u;
            goto label_193de4;
        }
    }
    ctx->pc = 0x193CBCu;
    // 0x193cbc: 0x96430000  lhu         $v1, 0x0($s2)
    ctx->pc = 0x193cbcu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x193cc0: 0x24022000  addiu       $v0, $zero, 0x2000
    ctx->pc = 0x193cc0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
    // 0x193cc4: 0x3063f000  andi        $v1, $v1, 0xF000
    ctx->pc = 0x193cc4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)61440);
    // 0x193cc8: 0x1062001c  beq         $v1, $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x193CC8u;
    {
        const bool branch_taken_0x193cc8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x193CCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193CC8u;
            // 0x193ccc: 0x3c010029  lui         $at, 0x29 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x193cc8) {
            ctx->pc = 0x193D3Cu;
            goto label_193d3c;
        }
    }
    ctx->pc = 0x193CD0u;
    // 0x193cd0: 0x24021000  addiu       $v0, $zero, 0x1000
    ctx->pc = 0x193cd0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x193cd4: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x193CD4u;
    {
        const bool branch_taken_0x193cd4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x193CD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193CD4u;
            // 0x193cd8: 0x3c010029  lui         $at, 0x29 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x193cd4) {
            ctx->pc = 0x193CE4u;
            goto label_193ce4;
        }
    }
    ctx->pc = 0x193CDCu;
    // 0x193cdc: 0x10000042  b           . + 4 + (0x42 << 2)
    ctx->pc = 0x193CDCu;
    {
        const bool branch_taken_0x193cdc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x193CE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193CDCu;
            // 0x193ce0: 0xdfbf0080  ld          $ra, 0x80($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 128)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x193cdc) {
            ctx->pc = 0x193DE8u;
            goto label_193de8;
        }
    }
    ctx->pc = 0x193CE4u;
label_193ce4:
    // 0x193ce4: 0x8e430004  lw          $v1, 0x4($s2)
    ctx->pc = 0x193ce4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x193ce8: 0x8c224168  lw          $v0, 0x4168($at)
    ctx->pc = 0x193ce8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16744)));
    // 0x193cec: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x193cecu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193cf0: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x193CF0u;
    {
        const bool branch_taken_0x193cf0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x193CF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193CF0u;
            // 0x193cf4: 0x629821  addu        $s3, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x193cf0) {
            ctx->pc = 0x193D24u;
            goto label_193d24;
        }
    }
    ctx->pc = 0x193CF8u;
label_193cf8:
    // 0x193cf8: 0x92750001  lbu         $s5, 0x1($s3)
    ctx->pc = 0x193cf8u;
    SET_GPR_U32(ctx, 21, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 1)));
    // 0x193cfc: 0x4600a306  mov.s       $f12, $f20
    ctx->pc = 0x193cfcu;
    ctx->f[12] = FPU_MOV_S(ctx->f[20]);
    // 0x193d00: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x193d00u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193d04: 0x151040  sll         $v0, $s5, 1
    ctx->pc = 0x193d04u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 21), 1));
    // 0x193d08: 0xc0638f0  jal         func_18E3C0
    ctx->pc = 0x193D08u;
    SET_GPR_U32(ctx, 31, 0x193D10u);
    ctx->pc = 0x193D0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193D08u;
            // 0x193d0c: 0x2022821  addu        $a1, $s0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18E3C0u;
    if (runtime->hasFunction(0x18E3C0u)) {
        auto targetFn = runtime->lookupFunction(0x18E3C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193D10u; }
        if (ctx->pc != 0x193D10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018E3C0_0x18e3c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193D10u; }
        if (ctx->pc != 0x193D10u) { return; }
    }
    ctx->pc = 0x193D10u;
label_193d10:
    // 0x193d10: 0x151080  sll         $v0, $s5, 2
    ctx->pc = 0x193d10u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 21), 2));
    // 0x193d14: 0x26940001  addiu       $s4, $s4, 0x1
    ctx->pc = 0x193d14u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
    // 0x193d18: 0x2221021  addu        $v0, $s1, $v0
    ctx->pc = 0x193d18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x193d1c: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x193d1cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x193d20: 0xe4400000  swc1        $f0, 0x0($v0)
    ctx->pc = 0x193d20u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 0), bits); }
label_193d24:
    // 0x193d24: 0x86420002  lh          $v0, 0x2($s2)
    ctx->pc = 0x193d24u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 18), 2)));
    // 0x193d28: 0x282102a  slt         $v0, $s4, $v0
    ctx->pc = 0x193d28u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 20) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x193d2c: 0x1440fff2  bnez        $v0, . + 4 + (-0xE << 2)
    ctx->pc = 0x193D2Cu;
    {
        const bool branch_taken_0x193d2c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x193d2c) {
            ctx->pc = 0x193CF8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_193cf8;
        }
    }
    ctx->pc = 0x193D34u;
    // 0x193d34: 0x1000002b  b           . + 4 + (0x2B << 2)
    ctx->pc = 0x193D34u;
    {
        const bool branch_taken_0x193d34 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x193d34) {
            ctx->pc = 0x193DE4u;
            goto label_193de4;
        }
    }
    ctx->pc = 0x193D3Cu;
label_193d3c:
    // 0x193d3c: 0x8e430004  lw          $v1, 0x4($s2)
    ctx->pc = 0x193d3cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x193d40: 0x8c224168  lw          $v0, 0x4168($at)
    ctx->pc = 0x193d40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16744)));
    // 0x193d44: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x193d44u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193d48: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x193D48u;
    {
        const bool branch_taken_0x193d48 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x193D4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193D48u;
            // 0x193d4c: 0x62a021  addu        $s4, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x193d48) {
            ctx->pc = 0x193DD4u;
            goto label_193dd4;
        }
    }
    ctx->pc = 0x193D50u;
label_193d50:
    // 0x193d50: 0x92960001  lbu         $s6, 0x1($s4)
    ctx->pc = 0x193d50u;
    SET_GPR_U32(ctx, 22, (uint8_t)READ8(ADD32(GPR_U32(ctx, 20), 1)));
    // 0x193d54: 0x4600a306  mov.s       $f12, $f20
    ctx->pc = 0x193d54u;
    ctx->f[12] = FPU_MOV_S(ctx->f[20]);
    // 0x193d58: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x193d58u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193d5c: 0x161880  sll         $v1, $s6, 2
    ctx->pc = 0x193d5cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 22), 2));
    // 0x193d60: 0x161040  sll         $v0, $s6, 1
    ctx->pc = 0x193d60u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 22), 1));
    // 0x193d64: 0x223a821  addu        $s5, $s1, $v1
    ctx->pc = 0x193d64u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x193d68: 0xc0638f0  jal         func_18E3C0
    ctx->pc = 0x193D68u;
    SET_GPR_U32(ctx, 31, 0x193D70u);
    ctx->pc = 0x193D6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193D68u;
            // 0x193d6c: 0x2022821  addu        $a1, $s0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18E3C0u;
    if (runtime->hasFunction(0x18E3C0u)) {
        auto targetFn = runtime->lookupFunction(0x18E3C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193D70u; }
        if (ctx->pc != 0x193D70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018E3C0_0x18e3c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193D70u; }
        if (ctx->pc != 0x193D70u) { return; }
    }
    ctx->pc = 0x193D70u;
label_193d70:
    // 0x193d70: 0x32c3ffff  andi        $v1, $s6, 0xFFFF
    ctx->pc = 0x193d70u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 22) & (uint64_t)(uint16_t)65535);
    // 0x193d74: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x193d74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x193d78: 0x10620009  beq         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x193D78u;
    {
        const bool branch_taken_0x193d78 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x193D7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193D78u;
            // 0x193d7c: 0xe6a00000  swc1        $f0, 0x0($s5) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 0), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x193d78) {
            ctx->pc = 0x193DA0u;
            goto label_193da0;
        }
    }
    ctx->pc = 0x193D80u;
    // 0x193d80: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x193d80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x193d84: 0x10620006  beq         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x193D84u;
    {
        const bool branch_taken_0x193d84 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x193d84) {
            ctx->pc = 0x193DA0u;
            goto label_193da0;
        }
    }
    ctx->pc = 0x193D8Cu;
    // 0x193d8c: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x193d8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x193d90: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x193D90u;
    {
        const bool branch_taken_0x193d90 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x193d90) {
            ctx->pc = 0x193DA0u;
            goto label_193da0;
        }
    }
    ctx->pc = 0x193D98u;
    // 0x193d98: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x193D98u;
    {
        const bool branch_taken_0x193d98 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x193D9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193D98u;
            // 0x193d9c: 0xc6a00000  lwc1        $f0, 0x0($s5) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 21), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
        ctx->in_delay_slot = false;
        if (branch_taken_0x193d98) {
            ctx->pc = 0x193DB8u;
            goto label_193db8;
        }
    }
    ctx->pc = 0x193DA0u;
label_193da0:
    // 0x193da0: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x193da0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x193da4: 0xc6a10000  lwc1        $f1, 0x0($s5)
    ctx->pc = 0x193da4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 21), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x193da8: 0xc4201c98  lwc1        $f0, 0x1C98($at)
    ctx->pc = 0x193da8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 7320)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x193dac: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x193dacu;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x193db0: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x193DB0u;
    {
        const bool branch_taken_0x193db0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x193DB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193DB0u;
            // 0x193db4: 0xe6a00000  swc1        $f0, 0x0($s5) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 0), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x193db0) {
            ctx->pc = 0x193DCCu;
            goto label_193dcc;
        }
    }
    ctx->pc = 0x193DB8u;
label_193db8:
    // 0x193db8: 0x3c024180  lui         $v0, 0x4180
    ctx->pc = 0x193db8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16768 << 16));
    // 0x193dbc: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x193dbcu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x193dc0: 0x0  nop
    ctx->pc = 0x193dc0u;
    // NOP
    // 0x193dc4: 0x46010003  div.s       $f0, $f0, $f1
    ctx->pc = 0x193dc4u;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[0]) ^ std::bit_cast<uint32_t>(ctx->f[1])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[0] / ctx->f[1];
    // 0x193dc8: 0xe6a00000  swc1        $f0, 0x0($s5)
    ctx->pc = 0x193dc8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 21), 0), bits); }
label_193dcc:
    // 0x193dcc: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x193dccu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x193dd0: 0x26940008  addiu       $s4, $s4, 0x8
    ctx->pc = 0x193dd0u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 8));
label_193dd4:
    // 0x193dd4: 0x86420002  lh          $v0, 0x2($s2)
    ctx->pc = 0x193dd4u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 18), 2)));
    // 0x193dd8: 0x262102a  slt         $v0, $s3, $v0
    ctx->pc = 0x193dd8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x193ddc: 0x1440ffdc  bnez        $v0, . + 4 + (-0x24 << 2)
    ctx->pc = 0x193DDCu;
    {
        const bool branch_taken_0x193ddc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x193ddc) {
            ctx->pc = 0x193D50u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_193d50;
        }
    }
    ctx->pc = 0x193DE4u;
label_193de4:
    // 0x193de4: 0xdfbf0080  ld          $ra, 0x80($sp)
    ctx->pc = 0x193de4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 128)));
label_193de8:
    // 0x193de8: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x193de8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x193dec: 0x7bb60070  lq          $s6, 0x70($sp)
    ctx->pc = 0x193decu;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x193df0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x193df0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x193df4: 0x7bb50060  lq          $s5, 0x60($sp)
    ctx->pc = 0x193df4u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x193df8: 0x7bb40050  lq          $s4, 0x50($sp)
    ctx->pc = 0x193df8u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x193dfc: 0x7bb30040  lq          $s3, 0x40($sp)
    ctx->pc = 0x193dfcu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x193e00: 0x7bb20030  lq          $s2, 0x30($sp)
    ctx->pc = 0x193e00u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x193e04: 0x7bb10020  lq          $s1, 0x20($sp)
    ctx->pc = 0x193e04u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x193e08: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x193e08u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x193e0c: 0x3e00008  jr          $ra
    ctx->pc = 0x193E0Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x193E10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193E0Cu;
            // 0x193e10: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x193CE4u: goto label_193ce4;
            case 0x193CF8u: goto label_193cf8;
            case 0x193D10u: goto label_193d10;
            case 0x193D24u: goto label_193d24;
            case 0x193D3Cu: goto label_193d3c;
            case 0x193D50u: goto label_193d50;
            case 0x193D70u: goto label_193d70;
            case 0x193DA0u: goto label_193da0;
            case 0x193DB8u: goto label_193db8;
            case 0x193DCCu: goto label_193dcc;
            case 0x193DD4u: goto label_193dd4;
            case 0x193DE4u: goto label_193de4;
            case 0x193DE8u: goto label_193de8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x193E14u;
    // 0x193e14: 0x0  nop
    ctx->pc = 0x193e14u;
    // NOP
    // 0x193e18: 0x0  nop
    ctx->pc = 0x193e18u;
    // NOP
    // 0x193e1c: 0x0  nop
    ctx->pc = 0x193e1cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
