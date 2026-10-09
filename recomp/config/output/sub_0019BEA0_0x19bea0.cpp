#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019BEA0
// Address: 0x19bea0 - 0x19c0bc
void sub_0019BEA0_0x19bea0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019BEA0_0x19bea0");
#endif

    switch (ctx->pc) {
        case 0x19bed0u: goto label_19bed0;
        case 0x19bfe4u: goto label_19bfe4;
        case 0x19bff4u: goto label_19bff4;
        case 0x19c004u: goto label_19c004;
        case 0x19c02cu: goto label_19c02c;
        case 0x19c070u: goto label_19c070;
        case 0x19c084u: goto label_19c084;
        default: break;
    }

    ctx->pc = 0x19bea0u;

    // 0x19bea0: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x19bea0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x19bea4: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x19bea4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x19bea8: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x19bea8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x19beac: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x19beacu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19beb0: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x19beb0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19beb4: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x19beb4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19beb8: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x19beb8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19bebc: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x19bebcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19bec0: 0x240401b0  addiu       $a0, $zero, 0x1B0
    ctx->pc = 0x19bec0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 432));
    // 0x19bec4: 0x24050010  addiu       $a1, $zero, 0x10
    ctx->pc = 0x19bec4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x19bec8: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x19BEC8u;
    SET_GPR_U32(ctx, 31, 0x19BED0u);
    ctx->pc = 0x19BECCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19BEC8u;
            // 0x19becc: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BED0u; }
        if (ctx->pc != 0x19BED0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BED0u; }
        if (ctx->pc != 0x19BED0u) { return; }
    }
    ctx->pc = 0x19BED0u;
label_19bed0:
    // 0x19bed0: 0x3c032000  lui         $v1, 0x2000
    ctx->pc = 0x19bed0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8192 << 16));
    // 0x19bed4: 0x3c080029  lui         $t0, 0x29
    ctx->pc = 0x19bed4u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)41 << 16));
    // 0x19bed8: 0x3463001a  ori         $v1, $v1, 0x1A
    ctx->pc = 0x19bed8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)26);
    // 0x19bedc: 0x3c061300  lui         $a2, 0x1300
    ctx->pc = 0x19bedcu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)4864 << 16));
    // 0x19bee0: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x19bee0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x19bee4: 0x3c056c18  lui         $a1, 0x6C18
    ctx->pc = 0x19bee4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)27672 << 16));
    // 0x19bee8: 0xac510004  sw          $s1, 0x4($v0)
    ctx->pc = 0x19bee8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 17));
    // 0x19beec: 0x3c030100  lui         $v1, 0x100
    ctx->pc = 0x19beecu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)256 << 16));
    // 0x19bef0: 0xfc400008  sd          $zero, 0x8($v0)
    ctx->pc = 0x19bef0u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19bef4: 0x34640404  ori         $a0, $v1, 0x404
    ctx->pc = 0x19bef4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1028);
    // 0x19bef8: 0xac460010  sw          $a2, 0x10($v0)
    ctx->pc = 0x19bef8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 6));
    // 0x19befc: 0x3c033f80  lui         $v1, 0x3F80
    ctx->pc = 0x19befcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16256 << 16));
    // 0x19bf00: 0xac400014  sw          $zero, 0x14($v0)
    ctx->pc = 0x19bf00u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19bf04: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x19bf04u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x19bf08: 0xac440018  sw          $a0, 0x18($v0)
    ctx->pc = 0x19bf08u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 4));
    // 0x19bf0c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x19bf0cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19bf10: 0xac45001c  sw          $a1, 0x1C($v0)
    ctx->pc = 0x19bf10u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 5));
    // 0x19bf14: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x19bf14u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x19bf18: 0x8e69004c  lw          $t1, 0x4C($s3)
    ctx->pc = 0x19bf18u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19bf1c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19bf1cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19bf20: 0xc4224e50  lwc1        $f2, 0x4E50($at)
    ctx->pc = 0x19bf20u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19bf24: 0x34663700  ori         $a2, $v1, 0x3700
    ctx->pc = 0x19bf24u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)14080);
    // 0x19bf28: 0x34673f40  ori         $a3, $v1, 0x3F40
    ctx->pc = 0x19bf28u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)16192);
    // 0x19bf2c: 0x26040050  addiu       $a0, $s0, 0x50
    ctx->pc = 0x19bf2cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 80));
    // 0x19bf30: 0x27a50060  addiu       $a1, $sp, 0x60
    ctx->pc = 0x19bf30u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x19bf34: 0x25084d40  addiu       $t0, $t0, 0x4D40
    ctx->pc = 0x19bf34u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 19776));
    // 0x19bf38: 0xc5210024  lwc1        $f1, 0x24($t1)
    ctx->pc = 0x19bf38u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 9), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bf3c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19bf3cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19bf40: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x19bf40u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19bf44: 0xe4410020  swc1        $f1, 0x20($v0)
    ctx->pc = 0x19bf44u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19bf48: 0x8e63004c  lw          $v1, 0x4C($s3)
    ctx->pc = 0x19bf48u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19bf4c: 0xc4224e54  lwc1        $f2, 0x4E54($at)
    ctx->pc = 0x19bf4cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19bf50: 0xc4610024  lwc1        $f1, 0x24($v1)
    ctx->pc = 0x19bf50u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bf54: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19bf54u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19bf58: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x19bf58u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19bf5c: 0xe4410024  swc1        $f1, 0x24($v0)
    ctx->pc = 0x19bf5cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19bf60: 0x8e63004c  lw          $v1, 0x4C($s3)
    ctx->pc = 0x19bf60u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19bf64: 0xc4224e58  lwc1        $f2, 0x4E58($at)
    ctx->pc = 0x19bf64u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19bf68: 0xc4610024  lwc1        $f1, 0x24($v1)
    ctx->pc = 0x19bf68u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bf6c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19bf6cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19bf70: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x19bf70u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19bf74: 0xe4410028  swc1        $f1, 0x28($v0)
    ctx->pc = 0x19bf74u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19bf78: 0xc4214e5c  lwc1        $f1, 0x4E5C($at)
    ctx->pc = 0x19bf78u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bf7c: 0xe441002c  swc1        $f1, 0x2C($v0)
    ctx->pc = 0x19bf7cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    // 0x19bf80: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19bf80u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19bf84: 0xc4214e40  lwc1        $f1, 0x4E40($at)
    ctx->pc = 0x19bf84u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20032)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bf88: 0xe4410030  swc1        $f1, 0x30($v0)
    ctx->pc = 0x19bf88u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 48), bits); }
    // 0x19bf8c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19bf8cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19bf90: 0xc4214e44  lwc1        $f1, 0x4E44($at)
    ctx->pc = 0x19bf90u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20036)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bf94: 0xe4410034  swc1        $f1, 0x34($v0)
    ctx->pc = 0x19bf94u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 52), bits); }
    // 0x19bf98: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19bf98u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19bf9c: 0xc4214e48  lwc1        $f1, 0x4E48($at)
    ctx->pc = 0x19bf9cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20040)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bfa0: 0xe4410038  swc1        $f1, 0x38($v0)
    ctx->pc = 0x19bfa0u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 56), bits); }
    // 0x19bfa4: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19bfa4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19bfa8: 0xc4214e4c  lwc1        $f1, 0x4E4C($at)
    ctx->pc = 0x19bfa8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20044)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bfac: 0xe441003c  swc1        $f1, 0x3C($v0)
    ctx->pc = 0x19bfacu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 60), bits); }
    // 0x19bfb0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19bfb0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19bfb4: 0xc421fe40  lwc1        $f1, -0x1C0($at)
    ctx->pc = 0x19bfb4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bfb8: 0xe4410040  swc1        $f1, 0x40($v0)
    ctx->pc = 0x19bfb8u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 64), bits); }
    // 0x19bfbc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19bfbcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19bfc0: 0xc422fe40  lwc1        $f2, -0x1C0($at)
    ctx->pc = 0x19bfc0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19bfc4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19bfc4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19bfc8: 0xc421fe48  lwc1        $f1, -0x1B8($at)
    ctx->pc = 0x19bfc8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966856)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bfcc: 0x46011041  sub.s       $f1, $f2, $f1
    ctx->pc = 0x19bfccu;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x19bfd0: 0x46010003  div.s       $f0, $f0, $f1
    ctx->pc = 0x19bfd0u;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[0]) ^ std::bit_cast<uint32_t>(ctx->f[1])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[0] / ctx->f[1];
    // 0x19bfd4: 0xe4400044  swc1        $f0, 0x44($v0)
    ctx->pc = 0x19bfd4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 68), bits); }
    // 0x19bfd8: 0xac400048  sw          $zero, 0x48($v0)
    ctx->pc = 0x19bfd8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 72), GPR_U32(ctx, 0));
    // 0x19bfdc: 0xc066500  jal         func_199400
    ctx->pc = 0x19BFDCu;
    SET_GPR_U32(ctx, 31, 0x19BFE4u);
    ctx->pc = 0x19BFE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19BFDCu;
            // 0x19bfe0: 0xac40004c  sw          $zero, 0x4C($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 76), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199400u;
    if (runtime->hasFunction(0x199400u)) {
        auto targetFn = runtime->lookupFunction(0x199400u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BFE4u; }
        if (ctx->pc != 0x19BFE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199400_0x199400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BFE4u; }
        if (ctx->pc != 0x19BFE4u) { return; }
    }
    ctx->pc = 0x19BFE4u;
label_19bfe4:
    // 0x19bfe4: 0x3c060029  lui         $a2, 0x29
    ctx->pc = 0x19bfe4u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)41 << 16));
    // 0x19bfe8: 0x26040090  addiu       $a0, $s0, 0x90
    ctx->pc = 0x19bfe8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 144));
    // 0x19bfec: 0xc0664e0  jal         func_199380
    ctx->pc = 0x19BFECu;
    SET_GPR_U32(ctx, 31, 0x19BFF4u);
    ctx->pc = 0x19BFF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19BFECu;
            // 0x19bff0: 0x24c64d00  addiu       $a2, $a2, 0x4D00 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 19712));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199380u;
    if (runtime->hasFunction(0x199380u)) {
        auto targetFn = runtime->lookupFunction(0x199380u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BFF4u; }
        if (ctx->pc != 0x19BFF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199380_0x199380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BFF4u; }
        if (ctx->pc != 0x19BFF4u) { return; }
    }
    ctx->pc = 0x19BFF4u;
label_19bff4:
    // 0x19bff4: 0x3c060029  lui         $a2, 0x29
    ctx->pc = 0x19bff4u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)41 << 16));
    // 0x19bff8: 0x260500d0  addiu       $a1, $s0, 0xD0
    ctx->pc = 0x19bff8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 208));
    // 0x19bffc: 0x24c64cc0  addiu       $a2, $a2, 0x4CC0
    ctx->pc = 0x19bffcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 19648));
    // 0x19c000: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x19c000u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
label_19c004:
    // 0x19c004: 0x8cc30000  lw          $v1, 0x0($a2)
    ctx->pc = 0x19c004u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x19c008: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x19c008u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x19c00c: 0x8cc20004  lw          $v0, 0x4($a2)
    ctx->pc = 0x19c00cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x19c010: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x19c010u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x19c014: 0x24c60008  addiu       $a2, $a2, 0x8
    ctx->pc = 0x19c014u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
    // 0x19c018: 0xaca20004  sw          $v0, 0x4($a1)
    ctx->pc = 0x19c018u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
    // 0x19c01c: 0x1c80fff9  bgtz        $a0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x19C01Cu;
    {
        const bool branch_taken_0x19c01c = (GPR_S64(ctx, 4) > 0);
        ctx->pc = 0x19C020u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19C01Cu;
            // 0x19c020: 0x24a50008  addiu       $a1, $a1, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19c01c) {
            ctx->pc = 0x19C004u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19c004;
        }
    }
    ctx->pc = 0x19C024u;
    // 0x19c024: 0xc066734  jal         func_199CD0
    ctx->pc = 0x19C024u;
    SET_GPR_U32(ctx, 31, 0x19C02Cu);
    ctx->pc = 0x19C028u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19C024u;
            // 0x19c028: 0x26040110  addiu       $a0, $s0, 0x110 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 272));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199CD0u;
    if (runtime->hasFunction(0x199CD0u)) {
        auto targetFn = runtime->lookupFunction(0x199CD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C02Cu; }
        if (ctx->pc != 0x19C02Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199CD0_0x199cd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C02Cu; }
        if (ctx->pc != 0x19C02Cu) { return; }
    }
    ctx->pc = 0x19C02Cu;
label_19c02c:
    // 0x19c02c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c02cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c030: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x19c030u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x19c034: 0xc4224240  lwc1        $f2, 0x4240($at)
    ctx->pc = 0x19c034u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16960)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19c038: 0xafa2005c  sw          $v0, 0x5C($sp)
    ctx->pc = 0x19c038u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 92), GPR_U32(ctx, 2));
    // 0x19c03c: 0x3c027000  lui         $v0, 0x7000
    ctx->pc = 0x19c03cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28672 << 16));
    // 0x19c040: 0x26040140  addiu       $a0, $s0, 0x140
    ctx->pc = 0x19c040u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 320));
    // 0x19c044: 0x26050170  addiu       $a1, $s0, 0x170
    ctx->pc = 0x19c044u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 368));
    // 0x19c048: 0x34463700  ori         $a2, $v0, 0x3700
    ctx->pc = 0x19c048u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)14080);
    // 0x19c04c: 0x27a70050  addiu       $a3, $sp, 0x50
    ctx->pc = 0x19c04cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x19c050: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c050u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c054: 0xc4214244  lwc1        $f1, 0x4244($at)
    ctx->pc = 0x19c054u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16964)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c058: 0xe7a20050  swc1        $f2, 0x50($sp)
    ctx->pc = 0x19c058u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 80), bits); }
    // 0x19c05c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c05cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c060: 0xc4204248  lwc1        $f0, 0x4248($at)
    ctx->pc = 0x19c060u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16968)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c064: 0xe7a10054  swc1        $f1, 0x54($sp)
    ctx->pc = 0x19c064u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 84), bits); }
    // 0x19c068: 0xc0665a8  jal         func_1996A0
    ctx->pc = 0x19C068u;
    SET_GPR_U32(ctx, 31, 0x19C070u);
    ctx->pc = 0x19C06Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19C068u;
            // 0x19c06c: 0xe7a00058  swc1        $f0, 0x58($sp) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 88), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1996A0u;
    if (runtime->hasFunction(0x1996A0u)) {
        auto targetFn = runtime->lookupFunction(0x1996A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C070u; }
        if (ctx->pc != 0x19C070u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001996A0_0x1996a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C070u; }
        if (ctx->pc != 0x19C070u) { return; }
    }
    ctx->pc = 0x19C070u;
label_19c070:
    // 0x19c070: 0x8e62004c  lw          $v0, 0x4C($s3)
    ctx->pc = 0x19c070u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19c074: 0x26040180  addiu       $a0, $s0, 0x180
    ctx->pc = 0x19c074u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 384));
    // 0x19c078: 0xc44c0024  lwc1        $f12, 0x24($v0)
    ctx->pc = 0x19c078u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x19c07c: 0xc066708  jal         func_199C20
    ctx->pc = 0x19C07Cu;
    SET_GPR_U32(ctx, 31, 0x19C084u);
    ctx->pc = 0x19C080u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19C07Cu;
            // 0x19c080: 0x26050190  addiu       $a1, $s0, 0x190 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 400));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199C20u;
    if (runtime->hasFunction(0x199C20u)) {
        auto targetFn = runtime->lookupFunction(0x199C20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C084u; }
        if (ctx->pc != 0x19C084u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199C20_0x199c20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C084u; }
        if (ctx->pc != 0x19C084u) { return; }
    }
    ctx->pc = 0x19C084u;
label_19c084:
    // 0x19c084: 0x3c031500  lui         $v1, 0x1500
    ctx->pc = 0x19c084u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)5376 << 16));
    // 0x19c088: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x19c088u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19c08c: 0x2431825  or          $v1, $s2, $v1
    ctx->pc = 0x19c08cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 18) | GPR_U64(ctx, 3));
    // 0x19c090: 0xae0301a0  sw          $v1, 0x1A0($s0)
    ctx->pc = 0x19c090u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 416), GPR_U32(ctx, 3));
    // 0x19c094: 0xae0001a4  sw          $zero, 0x1A4($s0)
    ctx->pc = 0x19c094u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 420), GPR_U32(ctx, 0));
    // 0x19c098: 0xae0001a8  sw          $zero, 0x1A8($s0)
    ctx->pc = 0x19c098u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 424), GPR_U32(ctx, 0));
    // 0x19c09c: 0xae0001ac  sw          $zero, 0x1AC($s0)
    ctx->pc = 0x19c09cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 428), GPR_U32(ctx, 0));
    // 0x19c0a0: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x19c0a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x19c0a4: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x19c0a4u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19c0a8: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x19c0a8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19c0ac: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x19c0acu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19c0b0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19c0b0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19c0b4: 0x3e00008  jr          $ra
    ctx->pc = 0x19C0B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19C0B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19C0B4u;
            // 0x19c0b8: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19BED0u: goto label_19bed0;
            case 0x19BFE4u: goto label_19bfe4;
            case 0x19BFF4u: goto label_19bff4;
            case 0x19C004u: goto label_19c004;
            case 0x19C02Cu: goto label_19c02c;
            case 0x19C070u: goto label_19c070;
            case 0x19C084u: goto label_19c084;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19C0BCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
