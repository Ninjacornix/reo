#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019A370
// Address: 0x19a370 - 0x19a4b4
void sub_0019A370_0x19a370(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019A370_0x19a370");
#endif

    switch (ctx->pc) {
        case 0x19a39cu: goto label_19a39c;
        case 0x19a474u: goto label_19a474;
        case 0x19a484u: goto label_19a484;
        default: break;
    }

    ctx->pc = 0x19a370u;

    // 0x19a370: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x19a370u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x19a374: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x19a374u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x19a378: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x19a378u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19a37c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x19a37cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19a380: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x19a380u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a384: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x19a384u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19a388: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x19a388u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a38c: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x19a38cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a390: 0x240400d0  addiu       $a0, $zero, 0xD0
    ctx->pc = 0x19a390u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 208));
    // 0x19a394: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x19A394u;
    SET_GPR_U32(ctx, 31, 0x19A39Cu);
    ctx->pc = 0x19A398u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19A394u;
            // 0x19a398: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A39Cu; }
        if (ctx->pc != 0x19A39Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A39Cu; }
        if (ctx->pc != 0x19A39Cu) { return; }
    }
    ctx->pc = 0x19A39Cu;
label_19a39c:
    // 0x19a39c: 0x3c032000  lui         $v1, 0x2000
    ctx->pc = 0x19a39cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8192 << 16));
    // 0x19a3a0: 0x3c080029  lui         $t0, 0x29
    ctx->pc = 0x19a3a0u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)41 << 16));
    // 0x19a3a4: 0x3464000c  ori         $a0, $v1, 0xC
    ctx->pc = 0x19a3a4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)12);
    // 0x19a3a8: 0x3c051300  lui         $a1, 0x1300
    ctx->pc = 0x19a3a8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4864 << 16));
    // 0x19a3ac: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x19a3acu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x19a3b0: 0x3c030100  lui         $v1, 0x100
    ctx->pc = 0x19a3b0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)256 << 16));
    // 0x19a3b4: 0xac500004  sw          $s0, 0x4($v0)
    ctx->pc = 0x19a3b4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x19a3b8: 0x34660404  ori         $a2, $v1, 0x404
    ctx->pc = 0x19a3b8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1028);
    // 0x19a3bc: 0xfc400008  sd          $zero, 0x8($v0)
    ctx->pc = 0x19a3bcu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19a3c0: 0x3c076c0a  lui         $a3, 0x6C0A
    ctx->pc = 0x19a3c0u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)27658 << 16));
    // 0x19a3c4: 0xac450010  sw          $a1, 0x10($v0)
    ctx->pc = 0x19a3c4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 5));
    // 0x19a3c8: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x19a3c8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x19a3cc: 0xac400014  sw          $zero, 0x14($v0)
    ctx->pc = 0x19a3ccu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19a3d0: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a3d0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a3d4: 0xac460018  sw          $a2, 0x18($v0)
    ctx->pc = 0x19a3d4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 6));
    // 0x19a3d8: 0x24440040  addiu       $a0, $v0, 0x40
    ctx->pc = 0x19a3d8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 64));
    // 0x19a3dc: 0xac47001c  sw          $a3, 0x1C($v0)
    ctx->pc = 0x19a3dcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 7));
    // 0x19a3e0: 0x34663700  ori         $a2, $v1, 0x3700
    ctx->pc = 0x19a3e0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)14080);
    // 0x19a3e4: 0x34673f40  ori         $a3, $v1, 0x3F40
    ctx->pc = 0x19a3e4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)16192);
    // 0x19a3e8: 0x27a50040  addiu       $a1, $sp, 0x40
    ctx->pc = 0x19a3e8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x19a3ec: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19a3ecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a3f0: 0xc4214e50  lwc1        $f1, 0x4E50($at)
    ctx->pc = 0x19a3f0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a3f4: 0x25084d40  addiu       $t0, $t0, 0x4D40
    ctx->pc = 0x19a3f4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 19776));
    // 0x19a3f8: 0xc4600024  lwc1        $f0, 0x24($v1)
    ctx->pc = 0x19a3f8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a3fc: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a3fcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a400: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x19a400u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a404: 0xe4400020  swc1        $f0, 0x20($v0)
    ctx->pc = 0x19a404u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19a408: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19a408u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a40c: 0xc4214e54  lwc1        $f1, 0x4E54($at)
    ctx->pc = 0x19a40cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a410: 0xc4600024  lwc1        $f0, 0x24($v1)
    ctx->pc = 0x19a410u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a414: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a414u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a418: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x19a418u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a41c: 0xe4400024  swc1        $f0, 0x24($v0)
    ctx->pc = 0x19a41cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19a420: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19a420u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a424: 0xc4214e58  lwc1        $f1, 0x4E58($at)
    ctx->pc = 0x19a424u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a428: 0xc4600024  lwc1        $f0, 0x24($v1)
    ctx->pc = 0x19a428u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a42c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a42cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a430: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x19a430u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a434: 0xe4400028  swc1        $f0, 0x28($v0)
    ctx->pc = 0x19a434u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19a438: 0xc4204e5c  lwc1        $f0, 0x4E5C($at)
    ctx->pc = 0x19a438u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a43c: 0xe440002c  swc1        $f0, 0x2C($v0)
    ctx->pc = 0x19a43cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    // 0x19a440: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a440u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a444: 0xc4204e40  lwc1        $f0, 0x4E40($at)
    ctx->pc = 0x19a444u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20032)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a448: 0xe4400030  swc1        $f0, 0x30($v0)
    ctx->pc = 0x19a448u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 48), bits); }
    // 0x19a44c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a44cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a450: 0xc4204e44  lwc1        $f0, 0x4E44($at)
    ctx->pc = 0x19a450u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20036)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a454: 0xe4400034  swc1        $f0, 0x34($v0)
    ctx->pc = 0x19a454u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 52), bits); }
    // 0x19a458: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a458u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a45c: 0xc4204e48  lwc1        $f0, 0x4E48($at)
    ctx->pc = 0x19a45cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20040)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a460: 0xe4400038  swc1        $f0, 0x38($v0)
    ctx->pc = 0x19a460u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 56), bits); }
    // 0x19a464: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a464u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a468: 0xc4204e4c  lwc1        $f0, 0x4E4C($at)
    ctx->pc = 0x19a468u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20044)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a46c: 0xc066500  jal         func_199400
    ctx->pc = 0x19A46Cu;
    SET_GPR_U32(ctx, 31, 0x19A474u);
    ctx->pc = 0x19A470u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19A46Cu;
            // 0x19a470: 0xe440003c  swc1        $f0, 0x3C($v0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 60), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x199400u;
    if (runtime->hasFunction(0x199400u)) {
        auto targetFn = runtime->lookupFunction(0x199400u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A474u; }
        if (ctx->pc != 0x19A474u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199400_0x199400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A474u; }
        if (ctx->pc != 0x19A474u) { return; }
    }
    ctx->pc = 0x19A474u;
label_19a474:
    // 0x19a474: 0x3c060029  lui         $a2, 0x29
    ctx->pc = 0x19a474u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)41 << 16));
    // 0x19a478: 0x24440080  addiu       $a0, $v0, 0x80
    ctx->pc = 0x19a478u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 128));
    // 0x19a47c: 0xc0664e0  jal         func_199380
    ctx->pc = 0x19A47Cu;
    SET_GPR_U32(ctx, 31, 0x19A484u);
    ctx->pc = 0x19A480u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19A47Cu;
            // 0x19a480: 0x24c64d00  addiu       $a2, $a2, 0x4D00 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 19712));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199380u;
    if (runtime->hasFunction(0x199380u)) {
        auto targetFn = runtime->lookupFunction(0x199380u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A484u; }
        if (ctx->pc != 0x19A484u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199380_0x199380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A484u; }
        if (ctx->pc != 0x19A484u) { return; }
    }
    ctx->pc = 0x19A484u;
label_19a484:
    // 0x19a484: 0x3c031500  lui         $v1, 0x1500
    ctx->pc = 0x19a484u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)5376 << 16));
    // 0x19a488: 0x2231825  or          $v1, $s1, $v1
    ctx->pc = 0x19a488u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) | GPR_U64(ctx, 3));
    // 0x19a48c: 0xac4300c0  sw          $v1, 0xC0($v0)
    ctx->pc = 0x19a48cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 192), GPR_U32(ctx, 3));
    // 0x19a490: 0xac4000c4  sw          $zero, 0xC4($v0)
    ctx->pc = 0x19a490u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 196), GPR_U32(ctx, 0));
    // 0x19a494: 0xac4000c8  sw          $zero, 0xC8($v0)
    ctx->pc = 0x19a494u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 200), GPR_U32(ctx, 0));
    // 0x19a498: 0xac4000cc  sw          $zero, 0xCC($v0)
    ctx->pc = 0x19a498u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 204), GPR_U32(ctx, 0));
    // 0x19a49c: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x19a49cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19a4a0: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x19a4a0u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19a4a4: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x19a4a4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19a4a8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19a4a8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19a4ac: 0x3e00008  jr          $ra
    ctx->pc = 0x19A4ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19A4B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19A4ACu;
            // 0x19a4b0: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19A39Cu: goto label_19a39c;
            case 0x19A474u: goto label_19a474;
            case 0x19A484u: goto label_19a484;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19A4B4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
