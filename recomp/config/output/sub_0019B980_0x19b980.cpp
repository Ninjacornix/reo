#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019B980
// Address: 0x19b980 - 0x19bbc4
void sub_0019B980_0x19b980(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019B980_0x19b980");
#endif

    switch (ctx->pc) {
        case 0x19b9b0u: goto label_19b9b0;
        case 0x19bac4u: goto label_19bac4;
        case 0x19bad4u: goto label_19bad4;
        case 0x19badcu: goto label_19badc;
        case 0x19bb7cu: goto label_19bb7c;
        case 0x19bb8cu: goto label_19bb8c;
        default: break;
    }

    ctx->pc = 0x19b980u;

    // 0x19b980: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x19b980u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x19b984: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x19b984u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x19b988: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x19b988u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x19b98c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x19b98cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19b990: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x19b990u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19b994: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x19b994u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19b998: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x19b998u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19b99c: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x19b99cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19b9a0: 0x240401b0  addiu       $a0, $zero, 0x1B0
    ctx->pc = 0x19b9a0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 432));
    // 0x19b9a4: 0x24050010  addiu       $a1, $zero, 0x10
    ctx->pc = 0x19b9a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x19b9a8: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x19B9A8u;
    SET_GPR_U32(ctx, 31, 0x19B9B0u);
    ctx->pc = 0x19B9ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19B9A8u;
            // 0x19b9ac: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B9B0u; }
        if (ctx->pc != 0x19B9B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B9B0u; }
        if (ctx->pc != 0x19B9B0u) { return; }
    }
    ctx->pc = 0x19B9B0u;
label_19b9b0:
    // 0x19b9b0: 0x3c032000  lui         $v1, 0x2000
    ctx->pc = 0x19b9b0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8192 << 16));
    // 0x19b9b4: 0x3c080029  lui         $t0, 0x29
    ctx->pc = 0x19b9b4u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)41 << 16));
    // 0x19b9b8: 0x3463001a  ori         $v1, $v1, 0x1A
    ctx->pc = 0x19b9b8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)26);
    // 0x19b9bc: 0x3c061300  lui         $a2, 0x1300
    ctx->pc = 0x19b9bcu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)4864 << 16));
    // 0x19b9c0: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x19b9c0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x19b9c4: 0x3c056c18  lui         $a1, 0x6C18
    ctx->pc = 0x19b9c4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)27672 << 16));
    // 0x19b9c8: 0xac510004  sw          $s1, 0x4($v0)
    ctx->pc = 0x19b9c8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 17));
    // 0x19b9cc: 0x3c030100  lui         $v1, 0x100
    ctx->pc = 0x19b9ccu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)256 << 16));
    // 0x19b9d0: 0xfc400008  sd          $zero, 0x8($v0)
    ctx->pc = 0x19b9d0u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19b9d4: 0x34640404  ori         $a0, $v1, 0x404
    ctx->pc = 0x19b9d4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1028);
    // 0x19b9d8: 0xac460010  sw          $a2, 0x10($v0)
    ctx->pc = 0x19b9d8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 6));
    // 0x19b9dc: 0x3c033f80  lui         $v1, 0x3F80
    ctx->pc = 0x19b9dcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16256 << 16));
    // 0x19b9e0: 0xac400014  sw          $zero, 0x14($v0)
    ctx->pc = 0x19b9e0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19b9e4: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x19b9e4u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x19b9e8: 0xac440018  sw          $a0, 0x18($v0)
    ctx->pc = 0x19b9e8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 4));
    // 0x19b9ec: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x19b9ecu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19b9f0: 0xac45001c  sw          $a1, 0x1C($v0)
    ctx->pc = 0x19b9f0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 5));
    // 0x19b9f4: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x19b9f4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x19b9f8: 0x8e69004c  lw          $t1, 0x4C($s3)
    ctx->pc = 0x19b9f8u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19b9fc: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b9fcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19ba00: 0xc4224e50  lwc1        $f2, 0x4E50($at)
    ctx->pc = 0x19ba00u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19ba04: 0x34663700  ori         $a2, $v1, 0x3700
    ctx->pc = 0x19ba04u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)14080);
    // 0x19ba08: 0x34673f40  ori         $a3, $v1, 0x3F40
    ctx->pc = 0x19ba08u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)16192);
    // 0x19ba0c: 0x26040050  addiu       $a0, $s0, 0x50
    ctx->pc = 0x19ba0cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 80));
    // 0x19ba10: 0x27a50080  addiu       $a1, $sp, 0x80
    ctx->pc = 0x19ba10u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
    // 0x19ba14: 0x25084d40  addiu       $t0, $t0, 0x4D40
    ctx->pc = 0x19ba14u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 19776));
    // 0x19ba18: 0xc5210024  lwc1        $f1, 0x24($t1)
    ctx->pc = 0x19ba18u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 9), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19ba1c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19ba1cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19ba20: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x19ba20u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19ba24: 0xe4410020  swc1        $f1, 0x20($v0)
    ctx->pc = 0x19ba24u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19ba28: 0x8e63004c  lw          $v1, 0x4C($s3)
    ctx->pc = 0x19ba28u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19ba2c: 0xc4224e54  lwc1        $f2, 0x4E54($at)
    ctx->pc = 0x19ba2cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19ba30: 0xc4610024  lwc1        $f1, 0x24($v1)
    ctx->pc = 0x19ba30u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19ba34: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19ba34u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19ba38: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x19ba38u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19ba3c: 0xe4410024  swc1        $f1, 0x24($v0)
    ctx->pc = 0x19ba3cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19ba40: 0x8e63004c  lw          $v1, 0x4C($s3)
    ctx->pc = 0x19ba40u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19ba44: 0xc4224e58  lwc1        $f2, 0x4E58($at)
    ctx->pc = 0x19ba44u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19ba48: 0xc4610024  lwc1        $f1, 0x24($v1)
    ctx->pc = 0x19ba48u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19ba4c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19ba4cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19ba50: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x19ba50u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19ba54: 0xe4410028  swc1        $f1, 0x28($v0)
    ctx->pc = 0x19ba54u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19ba58: 0xc4214e5c  lwc1        $f1, 0x4E5C($at)
    ctx->pc = 0x19ba58u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19ba5c: 0xe441002c  swc1        $f1, 0x2C($v0)
    ctx->pc = 0x19ba5cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    // 0x19ba60: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19ba60u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19ba64: 0xc4214e40  lwc1        $f1, 0x4E40($at)
    ctx->pc = 0x19ba64u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20032)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19ba68: 0xe4410030  swc1        $f1, 0x30($v0)
    ctx->pc = 0x19ba68u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 48), bits); }
    // 0x19ba6c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19ba6cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19ba70: 0xc4214e44  lwc1        $f1, 0x4E44($at)
    ctx->pc = 0x19ba70u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20036)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19ba74: 0xe4410034  swc1        $f1, 0x34($v0)
    ctx->pc = 0x19ba74u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 52), bits); }
    // 0x19ba78: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19ba78u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19ba7c: 0xc4214e48  lwc1        $f1, 0x4E48($at)
    ctx->pc = 0x19ba7cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20040)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19ba80: 0xe4410038  swc1        $f1, 0x38($v0)
    ctx->pc = 0x19ba80u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 56), bits); }
    // 0x19ba84: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19ba84u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19ba88: 0xc4214e4c  lwc1        $f1, 0x4E4C($at)
    ctx->pc = 0x19ba88u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20044)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19ba8c: 0xe441003c  swc1        $f1, 0x3C($v0)
    ctx->pc = 0x19ba8cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 60), bits); }
    // 0x19ba90: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19ba90u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19ba94: 0xc421fe40  lwc1        $f1, -0x1C0($at)
    ctx->pc = 0x19ba94u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19ba98: 0xe4410040  swc1        $f1, 0x40($v0)
    ctx->pc = 0x19ba98u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 64), bits); }
    // 0x19ba9c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19ba9cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19baa0: 0xc422fe40  lwc1        $f2, -0x1C0($at)
    ctx->pc = 0x19baa0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19baa4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19baa4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19baa8: 0xc421fe48  lwc1        $f1, -0x1B8($at)
    ctx->pc = 0x19baa8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966856)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19baac: 0x46011041  sub.s       $f1, $f2, $f1
    ctx->pc = 0x19baacu;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x19bab0: 0x46010003  div.s       $f0, $f0, $f1
    ctx->pc = 0x19bab0u;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[0]) ^ std::bit_cast<uint32_t>(ctx->f[1])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[0] / ctx->f[1];
    // 0x19bab4: 0xe4400044  swc1        $f0, 0x44($v0)
    ctx->pc = 0x19bab4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 68), bits); }
    // 0x19bab8: 0xac400048  sw          $zero, 0x48($v0)
    ctx->pc = 0x19bab8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 72), GPR_U32(ctx, 0));
    // 0x19babc: 0xc066500  jal         func_199400
    ctx->pc = 0x19BABCu;
    SET_GPR_U32(ctx, 31, 0x19BAC4u);
    ctx->pc = 0x19BAC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19BABCu;
            // 0x19bac0: 0xac40004c  sw          $zero, 0x4C($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 76), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199400u;
    if (runtime->hasFunction(0x199400u)) {
        auto targetFn = runtime->lookupFunction(0x199400u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BAC4u; }
        if (ctx->pc != 0x19BAC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199400_0x199400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BAC4u; }
        if (ctx->pc != 0x19BAC4u) { return; }
    }
    ctx->pc = 0x19BAC4u;
label_19bac4:
    // 0x19bac4: 0x3c060029  lui         $a2, 0x29
    ctx->pc = 0x19bac4u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)41 << 16));
    // 0x19bac8: 0x26040090  addiu       $a0, $s0, 0x90
    ctx->pc = 0x19bac8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 144));
    // 0x19bacc: 0xc0664e0  jal         func_199380
    ctx->pc = 0x19BACCu;
    SET_GPR_U32(ctx, 31, 0x19BAD4u);
    ctx->pc = 0x19BAD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19BACCu;
            // 0x19bad0: 0x24c64d00  addiu       $a2, $a2, 0x4D00 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 19712));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199380u;
    if (runtime->hasFunction(0x199380u)) {
        auto targetFn = runtime->lookupFunction(0x199380u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BAD4u; }
        if (ctx->pc != 0x19BAD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199380_0x199380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BAD4u; }
        if (ctx->pc != 0x19BAD4u) { return; }
    }
    ctx->pc = 0x19BAD4u;
label_19bad4:
    // 0x19bad4: 0xc066734  jal         func_199CD0
    ctx->pc = 0x19BAD4u;
    SET_GPR_U32(ctx, 31, 0x19BADCu);
    ctx->pc = 0x19BAD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19BAD4u;
            // 0x19bad8: 0x260400d0  addiu       $a0, $s0, 0xD0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 208));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199CD0u;
    if (runtime->hasFunction(0x199CD0u)) {
        auto targetFn = runtime->lookupFunction(0x199CD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BADCu; }
        if (ctx->pc != 0x19BADCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199CD0_0x199cd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BADCu; }
        if (ctx->pc != 0x19BADCu) { return; }
    }
    ctx->pc = 0x19BADCu;
label_19badc:
    // 0x19badc: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19badcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19bae0: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x19bae0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x19bae4: 0xc4214234  lwc1        $f1, 0x4234($at)
    ctx->pc = 0x19bae4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16948)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bae8: 0xafa2005c  sw          $v0, 0x5C($sp)
    ctx->pc = 0x19bae8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 92), GPR_U32(ctx, 2));
    // 0x19baec: 0xafa2006c  sw          $v0, 0x6C($sp)
    ctx->pc = 0x19baecu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 108), GPR_U32(ctx, 2));
    // 0x19baf0: 0x26040100  addiu       $a0, $s0, 0x100
    ctx->pc = 0x19baf0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 256));
    // 0x19baf4: 0xafa2007c  sw          $v0, 0x7C($sp)
    ctx->pc = 0x19baf4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 124), GPR_U32(ctx, 2));
    // 0x19baf8: 0x26050130  addiu       $a1, $s0, 0x130
    ctx->pc = 0x19baf8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 304));
    // 0x19bafc: 0x3c027000  lui         $v0, 0x7000
    ctx->pc = 0x19bafcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28672 << 16));
    // 0x19bb00: 0x27a70050  addiu       $a3, $sp, 0x50
    ctx->pc = 0x19bb00u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x19bb04: 0x34463700  ori         $a2, $v0, 0x3700
    ctx->pc = 0x19bb04u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)14080);
    // 0x19bb08: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19bb08u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19bb0c: 0xc4204238  lwc1        $f0, 0x4238($at)
    ctx->pc = 0x19bb0cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16952)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19bb10: 0x46000847  neg.s       $f1, $f1
    ctx->pc = 0x19bb10u;
    ctx->f[1] = FPU_NEG_S(ctx->f[1]);
    // 0x19bb14: 0xe7a10050  swc1        $f1, 0x50($sp)
    ctx->pc = 0x19bb14u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 80), bits); }
    // 0x19bb18: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19bb18u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19bb1c: 0xc424423c  lwc1        $f4, 0x423C($at)
    ctx->pc = 0x19bb1cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16956)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x19bb20: 0x46000147  neg.s       $f5, $f0
    ctx->pc = 0x19bb20u;
    ctx->f[5] = FPU_NEG_S(ctx->f[0]);
    // 0x19bb24: 0xe7a50054  swc1        $f5, 0x54($sp)
    ctx->pc = 0x19bb24u;
    { float f = ctx->f[5]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 84), bits); }
    // 0x19bb28: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19bb28u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19bb2c: 0xc42342a8  lwc1        $f3, 0x42A8($at)
    ctx->pc = 0x19bb2cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17064)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x19bb30: 0x46002107  neg.s       $f4, $f4
    ctx->pc = 0x19bb30u;
    ctx->f[4] = FPU_NEG_S(ctx->f[4]);
    // 0x19bb34: 0xe7a40058  swc1        $f4, 0x58($sp)
    ctx->pc = 0x19bb34u;
    { float f = ctx->f[4]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 88), bits); }
    // 0x19bb38: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19bb38u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19bb3c: 0xc42242ac  lwc1        $f2, 0x42AC($at)
    ctx->pc = 0x19bb3cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17068)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19bb40: 0xe7a30060  swc1        $f3, 0x60($sp)
    ctx->pc = 0x19bb40u;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 96), bits); }
    // 0x19bb44: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19bb44u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19bb48: 0xc42142b0  lwc1        $f1, 0x42B0($at)
    ctx->pc = 0x19bb48u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17072)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bb4c: 0xe7a20064  swc1        $f2, 0x64($sp)
    ctx->pc = 0x19bb4cu;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 100), bits); }
    // 0x19bb50: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19bb50u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19bb54: 0xc4204310  lwc1        $f0, 0x4310($at)
    ctx->pc = 0x19bb54u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17168)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19bb58: 0xe7a10068  swc1        $f1, 0x68($sp)
    ctx->pc = 0x19bb58u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 104), bits); }
    // 0x19bb5c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19bb5cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19bb60: 0xc4214314  lwc1        $f1, 0x4314($at)
    ctx->pc = 0x19bb60u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17172)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bb64: 0xe7a00070  swc1        $f0, 0x70($sp)
    ctx->pc = 0x19bb64u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 112), bits); }
    // 0x19bb68: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19bb68u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19bb6c: 0xc4204318  lwc1        $f0, 0x4318($at)
    ctx->pc = 0x19bb6cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17176)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19bb70: 0xe7a10074  swc1        $f1, 0x74($sp)
    ctx->pc = 0x19bb70u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 116), bits); }
    // 0x19bb74: 0xc0665d0  jal         func_199740
    ctx->pc = 0x19BB74u;
    SET_GPR_U32(ctx, 31, 0x19BB7Cu);
    ctx->pc = 0x19BB78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19BB74u;
            // 0x19bb78: 0xe7a00078  swc1        $f0, 0x78($sp) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 120), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x199740u;
    if (runtime->hasFunction(0x199740u)) {
        auto targetFn = runtime->lookupFunction(0x199740u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BB7Cu; }
        if (ctx->pc != 0x19BB7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199740_0x199740(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BB7Cu; }
        if (ctx->pc != 0x19BB7Cu) { return; }
    }
    ctx->pc = 0x19BB7Cu;
label_19bb7c:
    // 0x19bb7c: 0x8e62004c  lw          $v0, 0x4C($s3)
    ctx->pc = 0x19bb7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19bb80: 0xc44c0024  lwc1        $f12, 0x24($v0)
    ctx->pc = 0x19bb80u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x19bb84: 0xc0666a4  jal         func_199A90
    ctx->pc = 0x19BB84u;
    SET_GPR_U32(ctx, 31, 0x19BB8Cu);
    ctx->pc = 0x19BB88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19BB84u;
            // 0x19bb88: 0x26040140  addiu       $a0, $s0, 0x140 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 320));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199A90u;
    if (runtime->hasFunction(0x199A90u)) {
        auto targetFn = runtime->lookupFunction(0x199A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BB8Cu; }
        if (ctx->pc != 0x19BB8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199A90_0x199a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BB8Cu; }
        if (ctx->pc != 0x19BB8Cu) { return; }
    }
    ctx->pc = 0x19BB8Cu;
label_19bb8c:
    // 0x19bb8c: 0x3c031500  lui         $v1, 0x1500
    ctx->pc = 0x19bb8cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)5376 << 16));
    // 0x19bb90: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x19bb90u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19bb94: 0x2431825  or          $v1, $s2, $v1
    ctx->pc = 0x19bb94u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 18) | GPR_U64(ctx, 3));
    // 0x19bb98: 0xae0301a0  sw          $v1, 0x1A0($s0)
    ctx->pc = 0x19bb98u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 416), GPR_U32(ctx, 3));
    // 0x19bb9c: 0xae0001a4  sw          $zero, 0x1A4($s0)
    ctx->pc = 0x19bb9cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 420), GPR_U32(ctx, 0));
    // 0x19bba0: 0xae0001a8  sw          $zero, 0x1A8($s0)
    ctx->pc = 0x19bba0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 424), GPR_U32(ctx, 0));
    // 0x19bba4: 0xae0001ac  sw          $zero, 0x1AC($s0)
    ctx->pc = 0x19bba4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 428), GPR_U32(ctx, 0));
    // 0x19bba8: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x19bba8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x19bbac: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x19bbacu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19bbb0: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x19bbb0u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19bbb4: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x19bbb4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19bbb8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19bbb8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19bbbc: 0x3e00008  jr          $ra
    ctx->pc = 0x19BBBCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19BBC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19BBBCu;
            // 0x19bbc0: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19B9B0u: goto label_19b9b0;
            case 0x19BAC4u: goto label_19bac4;
            case 0x19BAD4u: goto label_19bad4;
            case 0x19BADCu: goto label_19badc;
            case 0x19BB7Cu: goto label_19bb7c;
            case 0x19BB8Cu: goto label_19bb8c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19BBC4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
