#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019A4C0
// Address: 0x19a4c0 - 0x19a60c
void sub_0019A4C0_0x19a4c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019A4C0_0x19a4c0");
#endif

    switch (ctx->pc) {
        case 0x19a4ecu: goto label_19a4ec;
        case 0x19a5c4u: goto label_19a5c4;
        case 0x19a5d4u: goto label_19a5d4;
        case 0x19a5dcu: goto label_19a5dc;
        default: break;
    }

    ctx->pc = 0x19a4c0u;

    // 0x19a4c0: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x19a4c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x19a4c4: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x19a4c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x19a4c8: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x19a4c8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19a4cc: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x19a4ccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19a4d0: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x19a4d0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a4d4: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x19a4d4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19a4d8: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x19a4d8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a4dc: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x19a4dcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a4e0: 0x24040100  addiu       $a0, $zero, 0x100
    ctx->pc = 0x19a4e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x19a4e4: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x19A4E4u;
    SET_GPR_U32(ctx, 31, 0x19A4ECu);
    ctx->pc = 0x19A4E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19A4E4u;
            // 0x19a4e8: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A4ECu; }
        if (ctx->pc != 0x19A4ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A4ECu; }
        if (ctx->pc != 0x19A4ECu) { return; }
    }
    ctx->pc = 0x19A4ECu;
label_19a4ec:
    // 0x19a4ec: 0x3c032000  lui         $v1, 0x2000
    ctx->pc = 0x19a4ecu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8192 << 16));
    // 0x19a4f0: 0x3c080029  lui         $t0, 0x29
    ctx->pc = 0x19a4f0u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)41 << 16));
    // 0x19a4f4: 0x3464000f  ori         $a0, $v1, 0xF
    ctx->pc = 0x19a4f4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)15);
    // 0x19a4f8: 0x3c051300  lui         $a1, 0x1300
    ctx->pc = 0x19a4f8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4864 << 16));
    // 0x19a4fc: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x19a4fcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x19a500: 0x3c030100  lui         $v1, 0x100
    ctx->pc = 0x19a500u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)256 << 16));
    // 0x19a504: 0xac500004  sw          $s0, 0x4($v0)
    ctx->pc = 0x19a504u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x19a508: 0x34660404  ori         $a2, $v1, 0x404
    ctx->pc = 0x19a508u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1028);
    // 0x19a50c: 0xfc400008  sd          $zero, 0x8($v0)
    ctx->pc = 0x19a50cu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19a510: 0x3c076c0d  lui         $a3, 0x6C0D
    ctx->pc = 0x19a510u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)27661 << 16));
    // 0x19a514: 0xac450010  sw          $a1, 0x10($v0)
    ctx->pc = 0x19a514u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 5));
    // 0x19a518: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x19a518u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x19a51c: 0xac400014  sw          $zero, 0x14($v0)
    ctx->pc = 0x19a51cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19a520: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a520u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a524: 0xac460018  sw          $a2, 0x18($v0)
    ctx->pc = 0x19a524u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 6));
    // 0x19a528: 0x24440040  addiu       $a0, $v0, 0x40
    ctx->pc = 0x19a528u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 64));
    // 0x19a52c: 0xac47001c  sw          $a3, 0x1C($v0)
    ctx->pc = 0x19a52cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 7));
    // 0x19a530: 0x34663700  ori         $a2, $v1, 0x3700
    ctx->pc = 0x19a530u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)14080);
    // 0x19a534: 0x34673f40  ori         $a3, $v1, 0x3F40
    ctx->pc = 0x19a534u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)16192);
    // 0x19a538: 0x27a50040  addiu       $a1, $sp, 0x40
    ctx->pc = 0x19a538u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x19a53c: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19a53cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a540: 0xc4214e50  lwc1        $f1, 0x4E50($at)
    ctx->pc = 0x19a540u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a544: 0x25084d40  addiu       $t0, $t0, 0x4D40
    ctx->pc = 0x19a544u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 19776));
    // 0x19a548: 0xc4600024  lwc1        $f0, 0x24($v1)
    ctx->pc = 0x19a548u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a54c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a54cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a550: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x19a550u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a554: 0xe4400020  swc1        $f0, 0x20($v0)
    ctx->pc = 0x19a554u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19a558: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19a558u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a55c: 0xc4214e54  lwc1        $f1, 0x4E54($at)
    ctx->pc = 0x19a55cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a560: 0xc4600024  lwc1        $f0, 0x24($v1)
    ctx->pc = 0x19a560u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a564: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a564u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a568: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x19a568u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a56c: 0xe4400024  swc1        $f0, 0x24($v0)
    ctx->pc = 0x19a56cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19a570: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19a570u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a574: 0xc4214e58  lwc1        $f1, 0x4E58($at)
    ctx->pc = 0x19a574u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a578: 0xc4600024  lwc1        $f0, 0x24($v1)
    ctx->pc = 0x19a578u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a57c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a57cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a580: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x19a580u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a584: 0xe4400028  swc1        $f0, 0x28($v0)
    ctx->pc = 0x19a584u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19a588: 0xc4204e5c  lwc1        $f0, 0x4E5C($at)
    ctx->pc = 0x19a588u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a58c: 0xe440002c  swc1        $f0, 0x2C($v0)
    ctx->pc = 0x19a58cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    // 0x19a590: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a590u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a594: 0xc4204e40  lwc1        $f0, 0x4E40($at)
    ctx->pc = 0x19a594u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20032)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a598: 0xe4400030  swc1        $f0, 0x30($v0)
    ctx->pc = 0x19a598u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 48), bits); }
    // 0x19a59c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a59cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a5a0: 0xc4204e44  lwc1        $f0, 0x4E44($at)
    ctx->pc = 0x19a5a0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20036)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a5a4: 0xe4400034  swc1        $f0, 0x34($v0)
    ctx->pc = 0x19a5a4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 52), bits); }
    // 0x19a5a8: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a5a8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a5ac: 0xc4204e48  lwc1        $f0, 0x4E48($at)
    ctx->pc = 0x19a5acu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20040)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a5b0: 0xe4400038  swc1        $f0, 0x38($v0)
    ctx->pc = 0x19a5b0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 56), bits); }
    // 0x19a5b4: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a5b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a5b8: 0xc4204e4c  lwc1        $f0, 0x4E4C($at)
    ctx->pc = 0x19a5b8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20044)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a5bc: 0xc066500  jal         func_199400
    ctx->pc = 0x19A5BCu;
    SET_GPR_U32(ctx, 31, 0x19A5C4u);
    ctx->pc = 0x19A5C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19A5BCu;
            // 0x19a5c0: 0xe440003c  swc1        $f0, 0x3C($v0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 60), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x199400u;
    if (runtime->hasFunction(0x199400u)) {
        auto targetFn = runtime->lookupFunction(0x199400u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A5C4u; }
        if (ctx->pc != 0x19A5C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199400_0x199400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A5C4u; }
        if (ctx->pc != 0x19A5C4u) { return; }
    }
    ctx->pc = 0x19A5C4u;
label_19a5c4:
    // 0x19a5c4: 0x3c060029  lui         $a2, 0x29
    ctx->pc = 0x19a5c4u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)41 << 16));
    // 0x19a5c8: 0x24440080  addiu       $a0, $v0, 0x80
    ctx->pc = 0x19a5c8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 128));
    // 0x19a5cc: 0xc0664e0  jal         func_199380
    ctx->pc = 0x19A5CCu;
    SET_GPR_U32(ctx, 31, 0x19A5D4u);
    ctx->pc = 0x19A5D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19A5CCu;
            // 0x19a5d0: 0x24c64d00  addiu       $a2, $a2, 0x4D00 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 19712));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199380u;
    if (runtime->hasFunction(0x199380u)) {
        auto targetFn = runtime->lookupFunction(0x199380u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A5D4u; }
        if (ctx->pc != 0x19A5D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199380_0x199380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A5D4u; }
        if (ctx->pc != 0x19A5D4u) { return; }
    }
    ctx->pc = 0x19A5D4u;
label_19a5d4:
    // 0x19a5d4: 0xc066734  jal         func_199CD0
    ctx->pc = 0x19A5D4u;
    SET_GPR_U32(ctx, 31, 0x19A5DCu);
    ctx->pc = 0x19A5D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19A5D4u;
            // 0x19a5d8: 0x244400c0  addiu       $a0, $v0, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 192));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199CD0u;
    if (runtime->hasFunction(0x199CD0u)) {
        auto targetFn = runtime->lookupFunction(0x199CD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A5DCu; }
        if (ctx->pc != 0x19A5DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199CD0_0x199cd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A5DCu; }
        if (ctx->pc != 0x19A5DCu) { return; }
    }
    ctx->pc = 0x19A5DCu;
label_19a5dc:
    // 0x19a5dc: 0x3c031500  lui         $v1, 0x1500
    ctx->pc = 0x19a5dcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)5376 << 16));
    // 0x19a5e0: 0x2231825  or          $v1, $s1, $v1
    ctx->pc = 0x19a5e0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) | GPR_U64(ctx, 3));
    // 0x19a5e4: 0xac4300f0  sw          $v1, 0xF0($v0)
    ctx->pc = 0x19a5e4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 240), GPR_U32(ctx, 3));
    // 0x19a5e8: 0xac4000f4  sw          $zero, 0xF4($v0)
    ctx->pc = 0x19a5e8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 244), GPR_U32(ctx, 0));
    // 0x19a5ec: 0xac4000f8  sw          $zero, 0xF8($v0)
    ctx->pc = 0x19a5ecu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 248), GPR_U32(ctx, 0));
    // 0x19a5f0: 0xac4000fc  sw          $zero, 0xFC($v0)
    ctx->pc = 0x19a5f0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 252), GPR_U32(ctx, 0));
    // 0x19a5f4: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x19a5f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19a5f8: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x19a5f8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19a5fc: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x19a5fcu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19a600: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19a600u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19a604: 0x3e00008  jr          $ra
    ctx->pc = 0x19A604u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19A608u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19A604u;
            // 0x19a608: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19A4ECu: goto label_19a4ec;
            case 0x19A5C4u: goto label_19a5c4;
            case 0x19A5D4u: goto label_19a5d4;
            case 0x19A5DCu: goto label_19a5dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19A60Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
