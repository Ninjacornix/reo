#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019C2B0
// Address: 0x19c2b0 - 0x19c4b4
void sub_0019C2B0_0x19c2b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019C2B0_0x19c2b0");
#endif

    switch (ctx->pc) {
        case 0x19c2dcu: goto label_19c2dc;
        case 0x19c37cu: goto label_19c37c;
        case 0x19c394u: goto label_19c394;
        case 0x19c430u: goto label_19c430;
        case 0x19c440u: goto label_19c440;
        case 0x19c484u: goto label_19c484;
        default: break;
    }

    ctx->pc = 0x19c2b0u;

    // 0x19c2b0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x19c2b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x19c2b4: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x19c2b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x19c2b8: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x19c2b8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19c2bc: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x19c2bcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19c2c0: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x19c2c0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19c2c4: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x19c2c4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19c2c8: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x19c2c8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19c2cc: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x19c2ccu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19c2d0: 0x24040f70  addiu       $a0, $zero, 0xF70
    ctx->pc = 0x19c2d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3952));
    // 0x19c2d4: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x19C2D4u;
    SET_GPR_U32(ctx, 31, 0x19C2DCu);
    ctx->pc = 0x19C2D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19C2D4u;
            // 0x19c2d8: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C2DCu; }
        if (ctx->pc != 0x19C2DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C2DCu; }
        if (ctx->pc != 0x19C2DCu) { return; }
    }
    ctx->pc = 0x19C2DCu;
label_19c2dc:
    // 0x19c2dc: 0x3c032000  lui         $v1, 0x2000
    ctx->pc = 0x19c2dcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8192 << 16));
    // 0x19c2e0: 0x3c051300  lui         $a1, 0x1300
    ctx->pc = 0x19c2e0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4864 << 16));
    // 0x19c2e4: 0x346400f6  ori         $a0, $v1, 0xF6
    ctx->pc = 0x19c2e4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)246);
    // 0x19c2e8: 0x3c076cf4  lui         $a3, 0x6CF4
    ctx->pc = 0x19c2e8u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)27892 << 16));
    // 0x19c2ec: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x19c2ecu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x19c2f0: 0x3c030100  lui         $v1, 0x100
    ctx->pc = 0x19c2f0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)256 << 16));
    // 0x19c2f4: 0xac500004  sw          $s0, 0x4($v0)
    ctx->pc = 0x19c2f4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x19c2f8: 0x34660404  ori         $a2, $v1, 0x404
    ctx->pc = 0x19c2f8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1028);
    // 0x19c2fc: 0xfc400008  sd          $zero, 0x8($v0)
    ctx->pc = 0x19c2fcu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19c300: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x19c300u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x19c304: 0xac450010  sw          $a1, 0x10($v0)
    ctx->pc = 0x19c304u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 5));
    // 0x19c308: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c308u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c30c: 0xac400014  sw          $zero, 0x14($v0)
    ctx->pc = 0x19c30cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19c310: 0x34653f40  ori         $a1, $v1, 0x3F40
    ctx->pc = 0x19c310u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)16192);
    // 0x19c314: 0xac460018  sw          $a2, 0x18($v0)
    ctx->pc = 0x19c314u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 6));
    // 0x19c318: 0x24440030  addiu       $a0, $v0, 0x30
    ctx->pc = 0x19c318u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 48));
    // 0x19c31c: 0xac47001c  sw          $a3, 0x1C($v0)
    ctx->pc = 0x19c31cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 7));
    // 0x19c320: 0x3c060029  lui         $a2, 0x29
    ctx->pc = 0x19c320u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)41 << 16));
    // 0x19c324: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19c324u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19c328: 0xc4214e50  lwc1        $f1, 0x4E50($at)
    ctx->pc = 0x19c328u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c32c: 0x24c64d40  addiu       $a2, $a2, 0x4D40
    ctx->pc = 0x19c32cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 19776));
    // 0x19c330: 0xc4600024  lwc1        $f0, 0x24($v1)
    ctx->pc = 0x19c330u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c334: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c334u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c338: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x19c338u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19c33c: 0xe4400020  swc1        $f0, 0x20($v0)
    ctx->pc = 0x19c33cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19c340: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19c340u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19c344: 0xc4214e54  lwc1        $f1, 0x4E54($at)
    ctx->pc = 0x19c344u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c348: 0xc4600024  lwc1        $f0, 0x24($v1)
    ctx->pc = 0x19c348u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c34c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c34cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c350: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x19c350u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19c354: 0xe4400024  swc1        $f0, 0x24($v0)
    ctx->pc = 0x19c354u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19c358: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19c358u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19c35c: 0xc4214e58  lwc1        $f1, 0x4E58($at)
    ctx->pc = 0x19c35cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c360: 0xc4600024  lwc1        $f0, 0x24($v1)
    ctx->pc = 0x19c360u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c364: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c364u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c368: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x19c368u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19c36c: 0xe4400028  swc1        $f0, 0x28($v0)
    ctx->pc = 0x19c36cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19c370: 0xc4204e5c  lwc1        $f0, 0x4E5C($at)
    ctx->pc = 0x19c370u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c374: 0xc0664e0  jal         func_199380
    ctx->pc = 0x19C374u;
    SET_GPR_U32(ctx, 31, 0x19C37Cu);
    ctx->pc = 0x19C378u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19C374u;
            // 0x19c378: 0xe440002c  swc1        $f0, 0x2C($v0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x199380u;
    if (runtime->hasFunction(0x199380u)) {
        auto targetFn = runtime->lookupFunction(0x199380u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C37Cu; }
        if (ctx->pc != 0x19C37Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199380_0x199380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C37Cu; }
        if (ctx->pc != 0x19C37Cu) { return; }
    }
    ctx->pc = 0x19C37Cu;
label_19c37c:
    // 0x19c37c: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x19c37cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x19c380: 0x3c060029  lui         $a2, 0x29
    ctx->pc = 0x19c380u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)41 << 16));
    // 0x19c384: 0x24440070  addiu       $a0, $v0, 0x70
    ctx->pc = 0x19c384u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 112));
    // 0x19c388: 0x34653f40  ori         $a1, $v1, 0x3F40
    ctx->pc = 0x19c388u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)16192);
    // 0x19c38c: 0xc0664e0  jal         func_199380
    ctx->pc = 0x19C38Cu;
    SET_GPR_U32(ctx, 31, 0x19C394u);
    ctx->pc = 0x19C390u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19C38Cu;
            // 0x19c390: 0x24c64d00  addiu       $a2, $a2, 0x4D00 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 19712));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199380u;
    if (runtime->hasFunction(0x199380u)) {
        auto targetFn = runtime->lookupFunction(0x199380u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C394u; }
        if (ctx->pc != 0x19C394u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199380_0x199380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C394u; }
        if (ctx->pc != 0x19C394u) { return; }
    }
    ctx->pc = 0x19C394u;
label_19c394:
    // 0x19c394: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c394u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c398: 0xc4204234  lwc1        $f0, 0x4234($at)
    ctx->pc = 0x19c398u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16948)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c39c: 0x46000007  neg.s       $f0, $f0
    ctx->pc = 0x19c39cu;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x19c3a0: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c3a0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c3a4: 0xe44000b0  swc1        $f0, 0xB0($v0)
    ctx->pc = 0x19c3a4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 176), bits); }
    // 0x19c3a8: 0xc4204238  lwc1        $f0, 0x4238($at)
    ctx->pc = 0x19c3a8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16952)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c3ac: 0x46000007  neg.s       $f0, $f0
    ctx->pc = 0x19c3acu;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x19c3b0: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c3b0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c3b4: 0xe44000b4  swc1        $f0, 0xB4($v0)
    ctx->pc = 0x19c3b4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 180), bits); }
    // 0x19c3b8: 0xc420423c  lwc1        $f0, 0x423C($at)
    ctx->pc = 0x19c3b8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16956)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c3bc: 0x46000007  neg.s       $f0, $f0
    ctx->pc = 0x19c3bcu;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x19c3c0: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c3c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c3c4: 0xe44000b8  swc1        $f0, 0xB8($v0)
    ctx->pc = 0x19c3c4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 184), bits); }
    // 0x19c3c8: 0xc420429c  lwc1        $f0, 0x429C($at)
    ctx->pc = 0x19c3c8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c3cc: 0x46000007  neg.s       $f0, $f0
    ctx->pc = 0x19c3ccu;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x19c3d0: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c3d0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c3d4: 0xe44000c0  swc1        $f0, 0xC0($v0)
    ctx->pc = 0x19c3d4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 192), bits); }
    // 0x19c3d8: 0xc42042a0  lwc1        $f0, 0x42A0($at)
    ctx->pc = 0x19c3d8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c3dc: 0x46000007  neg.s       $f0, $f0
    ctx->pc = 0x19c3dcu;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x19c3e0: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c3e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c3e4: 0xe44000c4  swc1        $f0, 0xC4($v0)
    ctx->pc = 0x19c3e4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 196), bits); }
    // 0x19c3e8: 0xc42042a4  lwc1        $f0, 0x42A4($at)
    ctx->pc = 0x19c3e8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c3ec: 0x46000007  neg.s       $f0, $f0
    ctx->pc = 0x19c3ecu;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x19c3f0: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c3f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c3f4: 0xe44000c8  swc1        $f0, 0xC8($v0)
    ctx->pc = 0x19c3f4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 200), bits); }
    // 0x19c3f8: 0xc4204304  lwc1        $f0, 0x4304($at)
    ctx->pc = 0x19c3f8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17156)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c3fc: 0x46000007  neg.s       $f0, $f0
    ctx->pc = 0x19c3fcu;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x19c400: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c400u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c404: 0xe44000d0  swc1        $f0, 0xD0($v0)
    ctx->pc = 0x19c404u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 208), bits); }
    // 0x19c408: 0xc4204308  lwc1        $f0, 0x4308($at)
    ctx->pc = 0x19c408u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17160)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c40c: 0x46000007  neg.s       $f0, $f0
    ctx->pc = 0x19c40cu;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x19c410: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c410u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c414: 0xe44000d4  swc1        $f0, 0xD4($v0)
    ctx->pc = 0x19c414u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 212), bits); }
    // 0x19c418: 0xc420430c  lwc1        $f0, 0x430C($at)
    ctx->pc = 0x19c418u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17164)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c41c: 0x46000007  neg.s       $f0, $f0
    ctx->pc = 0x19c41cu;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x19c420: 0xe44000d8  swc1        $f0, 0xD8($v0)
    ctx->pc = 0x19c420u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 216), bits); }
    // 0x19c424: 0x8e450054  lw          $a1, 0x54($s2)
    ctx->pc = 0x19c424u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 84)));
    // 0x19c428: 0xc066740  jal         func_199D00
    ctx->pc = 0x19C428u;
    SET_GPR_U32(ctx, 31, 0x19C430u);
    ctx->pc = 0x19C42Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19C428u;
            // 0x19c42c: 0x24440160  addiu       $a0, $v0, 0x160 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 352));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199D00u;
    if (runtime->hasFunction(0x199D00u)) {
        auto targetFn = runtime->lookupFunction(0x199D00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C430u; }
        if (ctx->pc != 0x19C430u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199D00_0x199d00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C430u; }
        if (ctx->pc != 0x19C430u) { return; }
    }
    ctx->pc = 0x19C430u;
label_19c430:
    // 0x19c430: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19c430u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19c434: 0xc46c0024  lwc1        $f12, 0x24($v1)
    ctx->pc = 0x19c434u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x19c438: 0xc066648  jal         func_199920
    ctx->pc = 0x19C438u;
    SET_GPR_U32(ctx, 31, 0x19C440u);
    ctx->pc = 0x19C43Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19C438u;
            // 0x19c43c: 0x244400e0  addiu       $a0, $v0, 0xE0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 224));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199920u;
    if (runtime->hasFunction(0x199920u)) {
        auto targetFn = runtime->lookupFunction(0x199920u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C440u; }
        if (ctx->pc != 0x19C440u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199920_0x199920(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C440u; }
        if (ctx->pc != 0x19C440u) { return; }
    }
    ctx->pc = 0x19C440u;
label_19c440:
    // 0x19c440: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19c440u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19c444: 0x3c033f80  lui         $v1, 0x3F80
    ctx->pc = 0x19c444u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16256 << 16));
    // 0x19c448: 0xc421fe40  lwc1        $f1, -0x1C0($at)
    ctx->pc = 0x19c448u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c44c: 0x24440130  addiu       $a0, $v0, 0x130
    ctx->pc = 0x19c44cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 304));
    // 0x19c450: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x19c450u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x19c454: 0x0  nop
    ctx->pc = 0x19c454u;
    // NOP
    // 0x19c458: 0xe4410120  swc1        $f1, 0x120($v0)
    ctx->pc = 0x19c458u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 288), bits); }
    // 0x19c45c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19c45cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19c460: 0xc422fe40  lwc1        $f2, -0x1C0($at)
    ctx->pc = 0x19c460u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19c464: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19c464u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19c468: 0xc421fe48  lwc1        $f1, -0x1B8($at)
    ctx->pc = 0x19c468u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966856)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c46c: 0x46011041  sub.s       $f1, $f2, $f1
    ctx->pc = 0x19c46cu;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x19c470: 0x46010003  div.s       $f0, $f0, $f1
    ctx->pc = 0x19c470u;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[0]) ^ std::bit_cast<uint32_t>(ctx->f[1])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[0] / ctx->f[1];
    // 0x19c474: 0xe4400124  swc1        $f0, 0x124($v0)
    ctx->pc = 0x19c474u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 292), bits); }
    // 0x19c478: 0xac400128  sw          $zero, 0x128($v0)
    ctx->pc = 0x19c478u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 296), GPR_U32(ctx, 0));
    // 0x19c47c: 0xc066734  jal         func_199CD0
    ctx->pc = 0x19C47Cu;
    SET_GPR_U32(ctx, 31, 0x19C484u);
    ctx->pc = 0x19C480u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19C47Cu;
            // 0x19c480: 0xac40012c  sw          $zero, 0x12C($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 300), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199CD0u;
    if (runtime->hasFunction(0x199CD0u)) {
        auto targetFn = runtime->lookupFunction(0x199CD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C484u; }
        if (ctx->pc != 0x19C484u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199CD0_0x199cd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C484u; }
        if (ctx->pc != 0x19C484u) { return; }
    }
    ctx->pc = 0x19C484u;
label_19c484:
    // 0x19c484: 0x3c031500  lui         $v1, 0x1500
    ctx->pc = 0x19c484u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)5376 << 16));
    // 0x19c488: 0x2231825  or          $v1, $s1, $v1
    ctx->pc = 0x19c488u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) | GPR_U64(ctx, 3));
    // 0x19c48c: 0xac430f60  sw          $v1, 0xF60($v0)
    ctx->pc = 0x19c48cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3936), GPR_U32(ctx, 3));
    // 0x19c490: 0xac400f64  sw          $zero, 0xF64($v0)
    ctx->pc = 0x19c490u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3940), GPR_U32(ctx, 0));
    // 0x19c494: 0xac400f68  sw          $zero, 0xF68($v0)
    ctx->pc = 0x19c494u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3944), GPR_U32(ctx, 0));
    // 0x19c498: 0xac400f6c  sw          $zero, 0xF6C($v0)
    ctx->pc = 0x19c498u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3948), GPR_U32(ctx, 0));
    // 0x19c49c: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x19c49cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19c4a0: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x19c4a0u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19c4a4: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x19c4a4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19c4a8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19c4a8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19c4ac: 0x3e00008  jr          $ra
    ctx->pc = 0x19C4ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19C4B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19C4ACu;
            // 0x19c4b0: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19C2DCu: goto label_19c2dc;
            case 0x19C37Cu: goto label_19c37c;
            case 0x19C394u: goto label_19c394;
            case 0x19C430u: goto label_19c430;
            case 0x19C440u: goto label_19c440;
            case 0x19C484u: goto label_19c484;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19C4B4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
