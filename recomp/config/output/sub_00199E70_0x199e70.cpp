#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00199E70
// Address: 0x199e70 - 0x19a040
void sub_00199E70_0x199e70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00199E70_0x199e70");
#endif

    switch (ctx->pc) {
        case 0x199e9cu: goto label_199e9c;
        case 0x199f44u: goto label_199f44;
        case 0x199f54u: goto label_199f54;
        case 0x199ff8u: goto label_199ff8;
        case 0x19a008u: goto label_19a008;
        case 0x19a010u: goto label_19a010;
        default: break;
    }

    ctx->pc = 0x199e70u;

    // 0x199e70: 0x27bdff50  addiu       $sp, $sp, -0xB0
    ctx->pc = 0x199e70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x199e74: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x199e74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x199e78: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x199e78u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x199e7c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x199e7cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x199e80: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x199e80u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x199e84: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x199e84u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x199e88: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x199e88u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x199e8c: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x199e8cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x199e90: 0x24040160  addiu       $a0, $zero, 0x160
    ctx->pc = 0x199e90u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 352));
    // 0x199e94: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x199E94u;
    SET_GPR_U32(ctx, 31, 0x199E9Cu);
    ctx->pc = 0x199E98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x199E94u;
            // 0x199e98: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x199E9Cu; }
        if (ctx->pc != 0x199E9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x199E9Cu; }
        if (ctx->pc != 0x199E9Cu) { return; }
    }
    ctx->pc = 0x199E9Cu;
label_199e9c:
    // 0x199e9c: 0x3c032000  lui         $v1, 0x2000
    ctx->pc = 0x199e9cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8192 << 16));
    // 0x199ea0: 0x3c080029  lui         $t0, 0x29
    ctx->pc = 0x199ea0u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)41 << 16));
    // 0x199ea4: 0x34640015  ori         $a0, $v1, 0x15
    ctx->pc = 0x199ea4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)21);
    // 0x199ea8: 0x3c051300  lui         $a1, 0x1300
    ctx->pc = 0x199ea8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4864 << 16));
    // 0x199eac: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x199eacu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x199eb0: 0x3c030100  lui         $v1, 0x100
    ctx->pc = 0x199eb0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)256 << 16));
    // 0x199eb4: 0xac500004  sw          $s0, 0x4($v0)
    ctx->pc = 0x199eb4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x199eb8: 0x34660404  ori         $a2, $v1, 0x404
    ctx->pc = 0x199eb8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1028);
    // 0x199ebc: 0xfc400008  sd          $zero, 0x8($v0)
    ctx->pc = 0x199ebcu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x199ec0: 0x3c076c13  lui         $a3, 0x6C13
    ctx->pc = 0x199ec0u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)27667 << 16));
    // 0x199ec4: 0xac450010  sw          $a1, 0x10($v0)
    ctx->pc = 0x199ec4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 5));
    // 0x199ec8: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x199ec8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x199ecc: 0xac400014  sw          $zero, 0x14($v0)
    ctx->pc = 0x199eccu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x199ed0: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x199ed0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x199ed4: 0xac460018  sw          $a2, 0x18($v0)
    ctx->pc = 0x199ed4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 6));
    // 0x199ed8: 0x24440030  addiu       $a0, $v0, 0x30
    ctx->pc = 0x199ed8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 48));
    // 0x199edc: 0xac47001c  sw          $a3, 0x1C($v0)
    ctx->pc = 0x199edcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 7));
    // 0x199ee0: 0x34663700  ori         $a2, $v1, 0x3700
    ctx->pc = 0x199ee0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)14080);
    // 0x199ee4: 0x34673f40  ori         $a3, $v1, 0x3F40
    ctx->pc = 0x199ee4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)16192);
    // 0x199ee8: 0x27a50070  addiu       $a1, $sp, 0x70
    ctx->pc = 0x199ee8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
    // 0x199eec: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x199eecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x199ef0: 0xc4214e50  lwc1        $f1, 0x4E50($at)
    ctx->pc = 0x199ef0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x199ef4: 0x25084d40  addiu       $t0, $t0, 0x4D40
    ctx->pc = 0x199ef4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 19776));
    // 0x199ef8: 0xc4600024  lwc1        $f0, 0x24($v1)
    ctx->pc = 0x199ef8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199efc: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x199efcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x199f00: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x199f00u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x199f04: 0xe4400020  swc1        $f0, 0x20($v0)
    ctx->pc = 0x199f04u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x199f08: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x199f08u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x199f0c: 0xc4214e54  lwc1        $f1, 0x4E54($at)
    ctx->pc = 0x199f0cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x199f10: 0xc4600024  lwc1        $f0, 0x24($v1)
    ctx->pc = 0x199f10u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199f14: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x199f14u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x199f18: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x199f18u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x199f1c: 0xe4400024  swc1        $f0, 0x24($v0)
    ctx->pc = 0x199f1cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x199f20: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x199f20u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x199f24: 0xc4214e58  lwc1        $f1, 0x4E58($at)
    ctx->pc = 0x199f24u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x199f28: 0xc4600024  lwc1        $f0, 0x24($v1)
    ctx->pc = 0x199f28u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199f2c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x199f2cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x199f30: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x199f30u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x199f34: 0xe4400028  swc1        $f0, 0x28($v0)
    ctx->pc = 0x199f34u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x199f38: 0xc4204e5c  lwc1        $f0, 0x4E5C($at)
    ctx->pc = 0x199f38u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199f3c: 0xc066500  jal         func_199400
    ctx->pc = 0x199F3Cu;
    SET_GPR_U32(ctx, 31, 0x199F44u);
    ctx->pc = 0x199F40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x199F3Cu;
            // 0x199f40: 0xe440002c  swc1        $f0, 0x2C($v0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x199400u;
    if (runtime->hasFunction(0x199400u)) {
        auto targetFn = runtime->lookupFunction(0x199400u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x199F44u; }
        if (ctx->pc != 0x199F44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199400_0x199400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x199F44u; }
        if (ctx->pc != 0x199F44u) { return; }
    }
    ctx->pc = 0x199F44u;
label_199f44:
    // 0x199f44: 0x3c060029  lui         $a2, 0x29
    ctx->pc = 0x199f44u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)41 << 16));
    // 0x199f48: 0x24440070  addiu       $a0, $v0, 0x70
    ctx->pc = 0x199f48u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 112));
    // 0x199f4c: 0xc0664e0  jal         func_199380
    ctx->pc = 0x199F4Cu;
    SET_GPR_U32(ctx, 31, 0x199F54u);
    ctx->pc = 0x199F50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x199F4Cu;
            // 0x199f50: 0x24c64d00  addiu       $a2, $a2, 0x4D00 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 19712));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199380u;
    if (runtime->hasFunction(0x199380u)) {
        auto targetFn = runtime->lookupFunction(0x199380u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x199F54u; }
        if (ctx->pc != 0x199F54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199380_0x199380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x199F54u; }
        if (ctx->pc != 0x199F54u) { return; }
    }
    ctx->pc = 0x199F54u;
label_199f54:
    // 0x199f54: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x199f54u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x199f58: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x199f58u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x199f5c: 0xc4204234  lwc1        $f0, 0x4234($at)
    ctx->pc = 0x199f5cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16948)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199f60: 0x244400b0  addiu       $a0, $v0, 0xB0
    ctx->pc = 0x199f60u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 176));
    // 0x199f64: 0x34653700  ori         $a1, $v1, 0x3700
    ctx->pc = 0x199f64u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)14080);
    // 0x199f68: 0x27a60040  addiu       $a2, $sp, 0x40
    ctx->pc = 0x199f68u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x199f6c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x199f6cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x199f70: 0xc4254238  lwc1        $f5, 0x4238($at)
    ctx->pc = 0x199f70u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16952)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[5] = f; }
    // 0x199f74: 0x46000187  neg.s       $f6, $f0
    ctx->pc = 0x199f74u;
    ctx->f[6] = FPU_NEG_S(ctx->f[0]);
    // 0x199f78: 0xe7a60040  swc1        $f6, 0x40($sp)
    ctx->pc = 0x199f78u;
    { float f = ctx->f[6]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 64), bits); }
    // 0x199f7c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x199f7cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x199f80: 0xc424423c  lwc1        $f4, 0x423C($at)
    ctx->pc = 0x199f80u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16956)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x199f84: 0x46002947  neg.s       $f5, $f5
    ctx->pc = 0x199f84u;
    ctx->f[5] = FPU_NEG_S(ctx->f[5]);
    // 0x199f88: 0xe7a50044  swc1        $f5, 0x44($sp)
    ctx->pc = 0x199f88u;
    { float f = ctx->f[5]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 68), bits); }
    // 0x199f8c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x199f8cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x199f90: 0xc423429c  lwc1        $f3, 0x429C($at)
    ctx->pc = 0x199f90u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x199f94: 0x46002107  neg.s       $f4, $f4
    ctx->pc = 0x199f94u;
    ctx->f[4] = FPU_NEG_S(ctx->f[4]);
    // 0x199f98: 0xe7a40048  swc1        $f4, 0x48($sp)
    ctx->pc = 0x199f98u;
    { float f = ctx->f[4]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 72), bits); }
    // 0x199f9c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x199f9cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x199fa0: 0xc42242a0  lwc1        $f2, 0x42A0($at)
    ctx->pc = 0x199fa0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x199fa4: 0x460018c7  neg.s       $f3, $f3
    ctx->pc = 0x199fa4u;
    ctx->f[3] = FPU_NEG_S(ctx->f[3]);
    // 0x199fa8: 0xe7a30050  swc1        $f3, 0x50($sp)
    ctx->pc = 0x199fa8u;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 80), bits); }
    // 0x199fac: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x199facu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x199fb0: 0xc42142a4  lwc1        $f1, 0x42A4($at)
    ctx->pc = 0x199fb0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x199fb4: 0x46001087  neg.s       $f2, $f2
    ctx->pc = 0x199fb4u;
    ctx->f[2] = FPU_NEG_S(ctx->f[2]);
    // 0x199fb8: 0xe7a20054  swc1        $f2, 0x54($sp)
    ctx->pc = 0x199fb8u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 84), bits); }
    // 0x199fbc: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x199fbcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x199fc0: 0xc4204304  lwc1        $f0, 0x4304($at)
    ctx->pc = 0x199fc0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17156)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199fc4: 0x46000847  neg.s       $f1, $f1
    ctx->pc = 0x199fc4u;
    ctx->f[1] = FPU_NEG_S(ctx->f[1]);
    // 0x199fc8: 0xe7a10058  swc1        $f1, 0x58($sp)
    ctx->pc = 0x199fc8u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 88), bits); }
    // 0x199fcc: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x199fccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x199fd0: 0xc4214308  lwc1        $f1, 0x4308($at)
    ctx->pc = 0x199fd0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17160)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x199fd4: 0x46000007  neg.s       $f0, $f0
    ctx->pc = 0x199fd4u;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x199fd8: 0xe7a00060  swc1        $f0, 0x60($sp)
    ctx->pc = 0x199fd8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 96), bits); }
    // 0x199fdc: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x199fdcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x199fe0: 0xc420430c  lwc1        $f0, 0x430C($at)
    ctx->pc = 0x199fe0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17164)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199fe4: 0x46000847  neg.s       $f1, $f1
    ctx->pc = 0x199fe4u;
    ctx->f[1] = FPU_NEG_S(ctx->f[1]);
    // 0x199fe8: 0xe7a10064  swc1        $f1, 0x64($sp)
    ctx->pc = 0x199fe8u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 100), bits); }
    // 0x199fec: 0x46000007  neg.s       $f0, $f0
    ctx->pc = 0x199fecu;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x199ff0: 0xc066570  jal         func_1995C0
    ctx->pc = 0x199FF0u;
    SET_GPR_U32(ctx, 31, 0x199FF8u);
    ctx->pc = 0x199FF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x199FF0u;
            // 0x199ff4: 0xe7a00068  swc1        $f0, 0x68($sp) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 104), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1995C0u;
    if (runtime->hasFunction(0x1995C0u)) {
        auto targetFn = runtime->lookupFunction(0x1995C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x199FF8u; }
        if (ctx->pc != 0x199FF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001995C0_0x1995c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x199FF8u; }
        if (ctx->pc != 0x199FF8u) { return; }
    }
    ctx->pc = 0x199FF8u;
label_199ff8:
    // 0x199ff8: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x199ff8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x199ffc: 0xc46c0024  lwc1        $f12, 0x24($v1)
    ctx->pc = 0x199ffcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x19a000: 0xc066648  jal         func_199920
    ctx->pc = 0x19A000u;
    SET_GPR_U32(ctx, 31, 0x19A008u);
    ctx->pc = 0x19A004u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19A000u;
            // 0x19a004: 0x244400e0  addiu       $a0, $v0, 0xE0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 224));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199920u;
    if (runtime->hasFunction(0x199920u)) {
        auto targetFn = runtime->lookupFunction(0x199920u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A008u; }
        if (ctx->pc != 0x19A008u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199920_0x199920(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A008u; }
        if (ctx->pc != 0x19A008u) { return; }
    }
    ctx->pc = 0x19A008u;
label_19a008:
    // 0x19a008: 0xc066734  jal         func_199CD0
    ctx->pc = 0x19A008u;
    SET_GPR_U32(ctx, 31, 0x19A010u);
    ctx->pc = 0x19A00Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19A008u;
            // 0x19a00c: 0x24440120  addiu       $a0, $v0, 0x120 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 288));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199CD0u;
    if (runtime->hasFunction(0x199CD0u)) {
        auto targetFn = runtime->lookupFunction(0x199CD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A010u; }
        if (ctx->pc != 0x19A010u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199CD0_0x199cd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A010u; }
        if (ctx->pc != 0x19A010u) { return; }
    }
    ctx->pc = 0x19A010u;
label_19a010:
    // 0x19a010: 0x3c031500  lui         $v1, 0x1500
    ctx->pc = 0x19a010u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)5376 << 16));
    // 0x19a014: 0x2231825  or          $v1, $s1, $v1
    ctx->pc = 0x19a014u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) | GPR_U64(ctx, 3));
    // 0x19a018: 0xac430150  sw          $v1, 0x150($v0)
    ctx->pc = 0x19a018u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 336), GPR_U32(ctx, 3));
    // 0x19a01c: 0xac400154  sw          $zero, 0x154($v0)
    ctx->pc = 0x19a01cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 340), GPR_U32(ctx, 0));
    // 0x19a020: 0xac400158  sw          $zero, 0x158($v0)
    ctx->pc = 0x19a020u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 344), GPR_U32(ctx, 0));
    // 0x19a024: 0xac40015c  sw          $zero, 0x15C($v0)
    ctx->pc = 0x19a024u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 348), GPR_U32(ctx, 0));
    // 0x19a028: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x19a028u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19a02c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x19a02cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19a030: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x19a030u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19a034: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19a034u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19a038: 0x3e00008  jr          $ra
    ctx->pc = 0x19A038u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19A03Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19A038u;
            // 0x19a03c: 0x27bd00b0  addiu       $sp, $sp, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x199E9Cu: goto label_199e9c;
            case 0x199F44u: goto label_199f44;
            case 0x199F54u: goto label_199f54;
            case 0x199FF8u: goto label_199ff8;
            case 0x19A008u: goto label_19a008;
            case 0x19A010u: goto label_19a010;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19A040u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
