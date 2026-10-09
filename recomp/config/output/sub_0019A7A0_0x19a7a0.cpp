#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019A7A0
// Address: 0x19a7a0 - 0x19a954
void sub_0019A7A0_0x19a7a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019A7A0_0x19a7a0");
#endif

    switch (ctx->pc) {
        case 0x19a7ccu: goto label_19a7cc;
        case 0x19a8a4u: goto label_19a8a4;
        case 0x19a8b4u: goto label_19a8b4;
        case 0x19a8bcu: goto label_19a8bc;
        case 0x19a8ccu: goto label_19a8cc;
        default: break;
    }

    ctx->pc = 0x19a7a0u;

    // 0x19a7a0: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x19a7a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x19a7a4: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x19a7a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x19a7a8: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x19a7a8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19a7ac: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x19a7acu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19a7b0: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x19a7b0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a7b4: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x19a7b4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19a7b8: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x19a7b8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a7bc: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x19a7bcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a7c0: 0x24040150  addiu       $a0, $zero, 0x150
    ctx->pc = 0x19a7c0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 336));
    // 0x19a7c4: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x19A7C4u;
    SET_GPR_U32(ctx, 31, 0x19A7CCu);
    ctx->pc = 0x19A7C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19A7C4u;
            // 0x19a7c8: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A7CCu; }
        if (ctx->pc != 0x19A7CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A7CCu; }
        if (ctx->pc != 0x19A7CCu) { return; }
    }
    ctx->pc = 0x19A7CCu;
label_19a7cc:
    // 0x19a7cc: 0x3c032000  lui         $v1, 0x2000
    ctx->pc = 0x19a7ccu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8192 << 16));
    // 0x19a7d0: 0x3c080029  lui         $t0, 0x29
    ctx->pc = 0x19a7d0u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)41 << 16));
    // 0x19a7d4: 0x34640014  ori         $a0, $v1, 0x14
    ctx->pc = 0x19a7d4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)20);
    // 0x19a7d8: 0x3c051300  lui         $a1, 0x1300
    ctx->pc = 0x19a7d8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4864 << 16));
    // 0x19a7dc: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x19a7dcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x19a7e0: 0x3c030100  lui         $v1, 0x100
    ctx->pc = 0x19a7e0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)256 << 16));
    // 0x19a7e4: 0xac500004  sw          $s0, 0x4($v0)
    ctx->pc = 0x19a7e4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x19a7e8: 0x34660404  ori         $a2, $v1, 0x404
    ctx->pc = 0x19a7e8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1028);
    // 0x19a7ec: 0xfc400008  sd          $zero, 0x8($v0)
    ctx->pc = 0x19a7ecu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19a7f0: 0x3c076c12  lui         $a3, 0x6C12
    ctx->pc = 0x19a7f0u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)27666 << 16));
    // 0x19a7f4: 0xac450010  sw          $a1, 0x10($v0)
    ctx->pc = 0x19a7f4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 5));
    // 0x19a7f8: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x19a7f8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x19a7fc: 0xac400014  sw          $zero, 0x14($v0)
    ctx->pc = 0x19a7fcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19a800: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a800u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a804: 0xac460018  sw          $a2, 0x18($v0)
    ctx->pc = 0x19a804u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 6));
    // 0x19a808: 0x24440040  addiu       $a0, $v0, 0x40
    ctx->pc = 0x19a808u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 64));
    // 0x19a80c: 0xac47001c  sw          $a3, 0x1C($v0)
    ctx->pc = 0x19a80cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 7));
    // 0x19a810: 0x34663700  ori         $a2, $v1, 0x3700
    ctx->pc = 0x19a810u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)14080);
    // 0x19a814: 0x34673f40  ori         $a3, $v1, 0x3F40
    ctx->pc = 0x19a814u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)16192);
    // 0x19a818: 0x27a50040  addiu       $a1, $sp, 0x40
    ctx->pc = 0x19a818u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x19a81c: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19a81cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a820: 0xc4214e50  lwc1        $f1, 0x4E50($at)
    ctx->pc = 0x19a820u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a824: 0x25084d40  addiu       $t0, $t0, 0x4D40
    ctx->pc = 0x19a824u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 19776));
    // 0x19a828: 0xc4600024  lwc1        $f0, 0x24($v1)
    ctx->pc = 0x19a828u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a82c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a82cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a830: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x19a830u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a834: 0xe4400020  swc1        $f0, 0x20($v0)
    ctx->pc = 0x19a834u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19a838: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19a838u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a83c: 0xc4214e54  lwc1        $f1, 0x4E54($at)
    ctx->pc = 0x19a83cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a840: 0xc4600024  lwc1        $f0, 0x24($v1)
    ctx->pc = 0x19a840u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a844: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a844u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a848: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x19a848u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a84c: 0xe4400024  swc1        $f0, 0x24($v0)
    ctx->pc = 0x19a84cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19a850: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19a850u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a854: 0xc4214e58  lwc1        $f1, 0x4E58($at)
    ctx->pc = 0x19a854u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a858: 0xc4600024  lwc1        $f0, 0x24($v1)
    ctx->pc = 0x19a858u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a85c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a85cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a860: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x19a860u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a864: 0xe4400028  swc1        $f0, 0x28($v0)
    ctx->pc = 0x19a864u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19a868: 0xc4204e5c  lwc1        $f0, 0x4E5C($at)
    ctx->pc = 0x19a868u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a86c: 0xe440002c  swc1        $f0, 0x2C($v0)
    ctx->pc = 0x19a86cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    // 0x19a870: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a870u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a874: 0xc4204e40  lwc1        $f0, 0x4E40($at)
    ctx->pc = 0x19a874u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20032)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a878: 0xe4400030  swc1        $f0, 0x30($v0)
    ctx->pc = 0x19a878u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 48), bits); }
    // 0x19a87c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a87cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a880: 0xc4204e44  lwc1        $f0, 0x4E44($at)
    ctx->pc = 0x19a880u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20036)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a884: 0xe4400034  swc1        $f0, 0x34($v0)
    ctx->pc = 0x19a884u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 52), bits); }
    // 0x19a888: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a888u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a88c: 0xc4204e48  lwc1        $f0, 0x4E48($at)
    ctx->pc = 0x19a88cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20040)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a890: 0xe4400038  swc1        $f0, 0x38($v0)
    ctx->pc = 0x19a890u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 56), bits); }
    // 0x19a894: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a894u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a898: 0xc4204e4c  lwc1        $f0, 0x4E4C($at)
    ctx->pc = 0x19a898u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20044)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a89c: 0xc066500  jal         func_199400
    ctx->pc = 0x19A89Cu;
    SET_GPR_U32(ctx, 31, 0x19A8A4u);
    ctx->pc = 0x19A8A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19A89Cu;
            // 0x19a8a0: 0xe440003c  swc1        $f0, 0x3C($v0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 60), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x199400u;
    if (runtime->hasFunction(0x199400u)) {
        auto targetFn = runtime->lookupFunction(0x199400u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A8A4u; }
        if (ctx->pc != 0x19A8A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199400_0x199400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A8A4u; }
        if (ctx->pc != 0x19A8A4u) { return; }
    }
    ctx->pc = 0x19A8A4u;
label_19a8a4:
    // 0x19a8a4: 0x3c060029  lui         $a2, 0x29
    ctx->pc = 0x19a8a4u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)41 << 16));
    // 0x19a8a8: 0x24440080  addiu       $a0, $v0, 0x80
    ctx->pc = 0x19a8a8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 128));
    // 0x19a8ac: 0xc0664e0  jal         func_199380
    ctx->pc = 0x19A8ACu;
    SET_GPR_U32(ctx, 31, 0x19A8B4u);
    ctx->pc = 0x19A8B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19A8ACu;
            // 0x19a8b0: 0x24c64d00  addiu       $a2, $a2, 0x4D00 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 19712));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199380u;
    if (runtime->hasFunction(0x199380u)) {
        auto targetFn = runtime->lookupFunction(0x199380u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A8B4u; }
        if (ctx->pc != 0x19A8B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199380_0x199380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A8B4u; }
        if (ctx->pc != 0x19A8B4u) { return; }
    }
    ctx->pc = 0x19A8B4u;
label_19a8b4:
    // 0x19a8b4: 0xc066734  jal         func_199CD0
    ctx->pc = 0x19A8B4u;
    SET_GPR_U32(ctx, 31, 0x19A8BCu);
    ctx->pc = 0x19A8B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19A8B4u;
            // 0x19a8b8: 0x244400c0  addiu       $a0, $v0, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 192));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199CD0u;
    if (runtime->hasFunction(0x199CD0u)) {
        auto targetFn = runtime->lookupFunction(0x199CD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A8BCu; }
        if (ctx->pc != 0x19A8BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199CD0_0x199cd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A8BCu; }
        if (ctx->pc != 0x19A8BCu) { return; }
    }
    ctx->pc = 0x19A8BCu;
label_19a8bc:
    // 0x19a8bc: 0x3c070029  lui         $a3, 0x29
    ctx->pc = 0x19a8bcu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)41 << 16));
    // 0x19a8c0: 0x24460100  addiu       $a2, $v0, 0x100
    ctx->pc = 0x19a8c0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 256));
    // 0x19a8c4: 0x24e74cc0  addiu       $a3, $a3, 0x4CC0
    ctx->pc = 0x19a8c4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 19648));
    // 0x19a8c8: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x19a8c8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
label_19a8cc:
    // 0x19a8cc: 0x8ce40000  lw          $a0, 0x0($a3)
    ctx->pc = 0x19a8ccu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x19a8d0: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x19a8d0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x19a8d4: 0x8ce30004  lw          $v1, 0x4($a3)
    ctx->pc = 0x19a8d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x19a8d8: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x19a8d8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x19a8dc: 0x24e70008  addiu       $a3, $a3, 0x8
    ctx->pc = 0x19a8dcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 8));
    // 0x19a8e0: 0xacc30004  sw          $v1, 0x4($a2)
    ctx->pc = 0x19a8e0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x19a8e4: 0x1ca0fff9  bgtz        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x19A8E4u;
    {
        const bool branch_taken_0x19a8e4 = (GPR_S64(ctx, 5) > 0);
        ctx->pc = 0x19A8E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19A8E4u;
            // 0x19a8e8: 0x24c60008  addiu       $a2, $a2, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19a8e4) {
            ctx->pc = 0x19A8CCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19a8cc;
        }
    }
    ctx->pc = 0x19A8ECu;
    // 0x19a8ec: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19a8ecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19a8f0: 0x3c033f80  lui         $v1, 0x3F80
    ctx->pc = 0x19a8f0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16256 << 16));
    // 0x19a8f4: 0xc421fe40  lwc1        $f1, -0x1C0($at)
    ctx->pc = 0x19a8f4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a8f8: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x19a8f8u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x19a8fc: 0x3c031500  lui         $v1, 0x1500
    ctx->pc = 0x19a8fcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)5376 << 16));
    // 0x19a900: 0x2231825  or          $v1, $s1, $v1
    ctx->pc = 0x19a900u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) | GPR_U64(ctx, 3));
    // 0x19a904: 0xe44100f0  swc1        $f1, 0xF0($v0)
    ctx->pc = 0x19a904u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 240), bits); }
    // 0x19a908: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19a908u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19a90c: 0xc422fe40  lwc1        $f2, -0x1C0($at)
    ctx->pc = 0x19a90cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19a910: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19a910u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19a914: 0xc421fe48  lwc1        $f1, -0x1B8($at)
    ctx->pc = 0x19a914u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966856)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a918: 0x46011041  sub.s       $f1, $f2, $f1
    ctx->pc = 0x19a918u;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x19a91c: 0x46010003  div.s       $f0, $f0, $f1
    ctx->pc = 0x19a91cu;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[0]) ^ std::bit_cast<uint32_t>(ctx->f[1])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[0] / ctx->f[1];
    // 0x19a920: 0xe44000f4  swc1        $f0, 0xF4($v0)
    ctx->pc = 0x19a920u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 244), bits); }
    // 0x19a924: 0xac4000f8  sw          $zero, 0xF8($v0)
    ctx->pc = 0x19a924u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 248), GPR_U32(ctx, 0));
    // 0x19a928: 0xac4000fc  sw          $zero, 0xFC($v0)
    ctx->pc = 0x19a928u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 252), GPR_U32(ctx, 0));
    // 0x19a92c: 0xac430140  sw          $v1, 0x140($v0)
    ctx->pc = 0x19a92cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 320), GPR_U32(ctx, 3));
    // 0x19a930: 0xac400144  sw          $zero, 0x144($v0)
    ctx->pc = 0x19a930u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 324), GPR_U32(ctx, 0));
    // 0x19a934: 0xac400148  sw          $zero, 0x148($v0)
    ctx->pc = 0x19a934u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 328), GPR_U32(ctx, 0));
    // 0x19a938: 0xac40014c  sw          $zero, 0x14C($v0)
    ctx->pc = 0x19a938u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 332), GPR_U32(ctx, 0));
    // 0x19a93c: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x19a93cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19a940: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x19a940u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19a944: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x19a944u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19a948: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19a948u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19a94c: 0x3e00008  jr          $ra
    ctx->pc = 0x19A94Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19A950u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19A94Cu;
            // 0x19a950: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19A7CCu: goto label_19a7cc;
            case 0x19A8A4u: goto label_19a8a4;
            case 0x19A8B4u: goto label_19a8b4;
            case 0x19A8BCu: goto label_19a8bc;
            case 0x19A8CCu: goto label_19a8cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19A954u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
