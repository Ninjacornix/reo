#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019AAE0
// Address: 0x19aae0 - 0x19acec
void sub_0019AAE0_0x19aae0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019AAE0_0x19aae0");
#endif

    switch (ctx->pc) {
        case 0x19ab10u: goto label_19ab10;
        case 0x19abf4u: goto label_19abf4;
        case 0x19ac04u: goto label_19ac04;
        case 0x19aca4u: goto label_19aca4;
        case 0x19acb4u: goto label_19acb4;
        default: break;
    }

    ctx->pc = 0x19aae0u;

    // 0x19aae0: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x19aae0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x19aae4: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x19aae4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x19aae8: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x19aae8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x19aaec: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x19aaecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19aaf0: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x19aaf0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19aaf4: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x19aaf4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19aaf8: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x19aaf8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19aafc: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x19aafcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19ab00: 0x24040170  addiu       $a0, $zero, 0x170
    ctx->pc = 0x19ab00u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 368));
    // 0x19ab04: 0x24050010  addiu       $a1, $zero, 0x10
    ctx->pc = 0x19ab04u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x19ab08: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x19AB08u;
    SET_GPR_U32(ctx, 31, 0x19AB10u);
    ctx->pc = 0x19AB0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19AB08u;
            // 0x19ab0c: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19AB10u; }
        if (ctx->pc != 0x19AB10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19AB10u; }
        if (ctx->pc != 0x19AB10u) { return; }
    }
    ctx->pc = 0x19AB10u;
label_19ab10:
    // 0x19ab10: 0x3c032000  lui         $v1, 0x2000
    ctx->pc = 0x19ab10u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8192 << 16));
    // 0x19ab14: 0x3c080029  lui         $t0, 0x29
    ctx->pc = 0x19ab14u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)41 << 16));
    // 0x19ab18: 0x34630016  ori         $v1, $v1, 0x16
    ctx->pc = 0x19ab18u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)22);
    // 0x19ab1c: 0x3c061300  lui         $a2, 0x1300
    ctx->pc = 0x19ab1cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)4864 << 16));
    // 0x19ab20: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x19ab20u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x19ab24: 0x3c056c14  lui         $a1, 0x6C14
    ctx->pc = 0x19ab24u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)27668 << 16));
    // 0x19ab28: 0xac510004  sw          $s1, 0x4($v0)
    ctx->pc = 0x19ab28u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 17));
    // 0x19ab2c: 0x3c030100  lui         $v1, 0x100
    ctx->pc = 0x19ab2cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)256 << 16));
    // 0x19ab30: 0xfc400008  sd          $zero, 0x8($v0)
    ctx->pc = 0x19ab30u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19ab34: 0x34640404  ori         $a0, $v1, 0x404
    ctx->pc = 0x19ab34u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1028);
    // 0x19ab38: 0xac460010  sw          $a2, 0x10($v0)
    ctx->pc = 0x19ab38u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 6));
    // 0x19ab3c: 0x3c033f80  lui         $v1, 0x3F80
    ctx->pc = 0x19ab3cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16256 << 16));
    // 0x19ab40: 0xac400014  sw          $zero, 0x14($v0)
    ctx->pc = 0x19ab40u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19ab44: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x19ab44u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x19ab48: 0xac440018  sw          $a0, 0x18($v0)
    ctx->pc = 0x19ab48u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 4));
    // 0x19ab4c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x19ab4cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19ab50: 0xac45001c  sw          $a1, 0x1C($v0)
    ctx->pc = 0x19ab50u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 5));
    // 0x19ab54: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x19ab54u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x19ab58: 0x8e69004c  lw          $t1, 0x4C($s3)
    ctx->pc = 0x19ab58u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19ab5c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19ab5cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19ab60: 0xc4224e50  lwc1        $f2, 0x4E50($at)
    ctx->pc = 0x19ab60u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19ab64: 0x34663700  ori         $a2, $v1, 0x3700
    ctx->pc = 0x19ab64u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)14080);
    // 0x19ab68: 0x34673f40  ori         $a3, $v1, 0x3F40
    ctx->pc = 0x19ab68u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)16192);
    // 0x19ab6c: 0x26040040  addiu       $a0, $s0, 0x40
    ctx->pc = 0x19ab6cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 64));
    // 0x19ab70: 0x27a50080  addiu       $a1, $sp, 0x80
    ctx->pc = 0x19ab70u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
    // 0x19ab74: 0x25084d40  addiu       $t0, $t0, 0x4D40
    ctx->pc = 0x19ab74u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 19776));
    // 0x19ab78: 0xc5210024  lwc1        $f1, 0x24($t1)
    ctx->pc = 0x19ab78u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 9), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19ab7c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19ab7cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19ab80: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x19ab80u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19ab84: 0xe4410020  swc1        $f1, 0x20($v0)
    ctx->pc = 0x19ab84u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19ab88: 0x8e63004c  lw          $v1, 0x4C($s3)
    ctx->pc = 0x19ab88u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19ab8c: 0xc4224e54  lwc1        $f2, 0x4E54($at)
    ctx->pc = 0x19ab8cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19ab90: 0xc4610024  lwc1        $f1, 0x24($v1)
    ctx->pc = 0x19ab90u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19ab94: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19ab94u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19ab98: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x19ab98u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19ab9c: 0xe4410024  swc1        $f1, 0x24($v0)
    ctx->pc = 0x19ab9cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19aba0: 0x8e63004c  lw          $v1, 0x4C($s3)
    ctx->pc = 0x19aba0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19aba4: 0xc4224e58  lwc1        $f2, 0x4E58($at)
    ctx->pc = 0x19aba4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19aba8: 0xc4610024  lwc1        $f1, 0x24($v1)
    ctx->pc = 0x19aba8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19abac: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19abacu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19abb0: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x19abb0u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19abb4: 0xe4410028  swc1        $f1, 0x28($v0)
    ctx->pc = 0x19abb4u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19abb8: 0xc4214e5c  lwc1        $f1, 0x4E5C($at)
    ctx->pc = 0x19abb8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19abbc: 0xe441002c  swc1        $f1, 0x2C($v0)
    ctx->pc = 0x19abbcu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    // 0x19abc0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19abc0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19abc4: 0xc421fe40  lwc1        $f1, -0x1C0($at)
    ctx->pc = 0x19abc4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19abc8: 0xe4410030  swc1        $f1, 0x30($v0)
    ctx->pc = 0x19abc8u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 48), bits); }
    // 0x19abcc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19abccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19abd0: 0xc422fe40  lwc1        $f2, -0x1C0($at)
    ctx->pc = 0x19abd0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19abd4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19abd4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19abd8: 0xc421fe48  lwc1        $f1, -0x1B8($at)
    ctx->pc = 0x19abd8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966856)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19abdc: 0x46011041  sub.s       $f1, $f2, $f1
    ctx->pc = 0x19abdcu;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x19abe0: 0x46010003  div.s       $f0, $f0, $f1
    ctx->pc = 0x19abe0u;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[0]) ^ std::bit_cast<uint32_t>(ctx->f[1])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[0] / ctx->f[1];
    // 0x19abe4: 0xe4400034  swc1        $f0, 0x34($v0)
    ctx->pc = 0x19abe4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 52), bits); }
    // 0x19abe8: 0xac400038  sw          $zero, 0x38($v0)
    ctx->pc = 0x19abe8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 56), GPR_U32(ctx, 0));
    // 0x19abec: 0xc066500  jal         func_199400
    ctx->pc = 0x19ABECu;
    SET_GPR_U32(ctx, 31, 0x19ABF4u);
    ctx->pc = 0x19ABF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19ABECu;
            // 0x19abf0: 0xac40003c  sw          $zero, 0x3C($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 60), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199400u;
    if (runtime->hasFunction(0x199400u)) {
        auto targetFn = runtime->lookupFunction(0x199400u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19ABF4u; }
        if (ctx->pc != 0x19ABF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199400_0x199400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19ABF4u; }
        if (ctx->pc != 0x19ABF4u) { return; }
    }
    ctx->pc = 0x19ABF4u;
label_19abf4:
    // 0x19abf4: 0x3c060029  lui         $a2, 0x29
    ctx->pc = 0x19abf4u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)41 << 16));
    // 0x19abf8: 0x26040080  addiu       $a0, $s0, 0x80
    ctx->pc = 0x19abf8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 128));
    // 0x19abfc: 0xc0664e0  jal         func_199380
    ctx->pc = 0x19ABFCu;
    SET_GPR_U32(ctx, 31, 0x19AC04u);
    ctx->pc = 0x19AC00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19ABFCu;
            // 0x19ac00: 0x24c64d00  addiu       $a2, $a2, 0x4D00 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 19712));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199380u;
    if (runtime->hasFunction(0x199380u)) {
        auto targetFn = runtime->lookupFunction(0x199380u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19AC04u; }
        if (ctx->pc != 0x19AC04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199380_0x199380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19AC04u; }
        if (ctx->pc != 0x19AC04u) { return; }
    }
    ctx->pc = 0x19AC04u;
label_19ac04:
    // 0x19ac04: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19ac04u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19ac08: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x19ac08u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x19ac0c: 0xc4214234  lwc1        $f1, 0x4234($at)
    ctx->pc = 0x19ac0cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16948)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19ac10: 0xafa2005c  sw          $v0, 0x5C($sp)
    ctx->pc = 0x19ac10u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 92), GPR_U32(ctx, 2));
    // 0x19ac14: 0xafa2006c  sw          $v0, 0x6C($sp)
    ctx->pc = 0x19ac14u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 108), GPR_U32(ctx, 2));
    // 0x19ac18: 0x260400c0  addiu       $a0, $s0, 0xC0
    ctx->pc = 0x19ac18u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 192));
    // 0x19ac1c: 0xafa2007c  sw          $v0, 0x7C($sp)
    ctx->pc = 0x19ac1cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 124), GPR_U32(ctx, 2));
    // 0x19ac20: 0x260500f0  addiu       $a1, $s0, 0xF0
    ctx->pc = 0x19ac20u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 240));
    // 0x19ac24: 0x3c027000  lui         $v0, 0x7000
    ctx->pc = 0x19ac24u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28672 << 16));
    // 0x19ac28: 0x27a70050  addiu       $a3, $sp, 0x50
    ctx->pc = 0x19ac28u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x19ac2c: 0x34463700  ori         $a2, $v0, 0x3700
    ctx->pc = 0x19ac2cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)14080);
    // 0x19ac30: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19ac30u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19ac34: 0xc4204238  lwc1        $f0, 0x4238($at)
    ctx->pc = 0x19ac34u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16952)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19ac38: 0x46000847  neg.s       $f1, $f1
    ctx->pc = 0x19ac38u;
    ctx->f[1] = FPU_NEG_S(ctx->f[1]);
    // 0x19ac3c: 0xe7a10050  swc1        $f1, 0x50($sp)
    ctx->pc = 0x19ac3cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 80), bits); }
    // 0x19ac40: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19ac40u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19ac44: 0xc424423c  lwc1        $f4, 0x423C($at)
    ctx->pc = 0x19ac44u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16956)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x19ac48: 0x46000147  neg.s       $f5, $f0
    ctx->pc = 0x19ac48u;
    ctx->f[5] = FPU_NEG_S(ctx->f[0]);
    // 0x19ac4c: 0xe7a50054  swc1        $f5, 0x54($sp)
    ctx->pc = 0x19ac4cu;
    { float f = ctx->f[5]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 84), bits); }
    // 0x19ac50: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19ac50u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19ac54: 0xc42342a8  lwc1        $f3, 0x42A8($at)
    ctx->pc = 0x19ac54u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17064)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x19ac58: 0x46002107  neg.s       $f4, $f4
    ctx->pc = 0x19ac58u;
    ctx->f[4] = FPU_NEG_S(ctx->f[4]);
    // 0x19ac5c: 0xe7a40058  swc1        $f4, 0x58($sp)
    ctx->pc = 0x19ac5cu;
    { float f = ctx->f[4]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 88), bits); }
    // 0x19ac60: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19ac60u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19ac64: 0xc42242ac  lwc1        $f2, 0x42AC($at)
    ctx->pc = 0x19ac64u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17068)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19ac68: 0xe7a30060  swc1        $f3, 0x60($sp)
    ctx->pc = 0x19ac68u;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 96), bits); }
    // 0x19ac6c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19ac6cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19ac70: 0xc42142b0  lwc1        $f1, 0x42B0($at)
    ctx->pc = 0x19ac70u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17072)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19ac74: 0xe7a20064  swc1        $f2, 0x64($sp)
    ctx->pc = 0x19ac74u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 100), bits); }
    // 0x19ac78: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19ac78u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19ac7c: 0xc4204310  lwc1        $f0, 0x4310($at)
    ctx->pc = 0x19ac7cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17168)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19ac80: 0xe7a10068  swc1        $f1, 0x68($sp)
    ctx->pc = 0x19ac80u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 104), bits); }
    // 0x19ac84: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19ac84u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19ac88: 0xc4214314  lwc1        $f1, 0x4314($at)
    ctx->pc = 0x19ac88u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17172)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19ac8c: 0xe7a00070  swc1        $f0, 0x70($sp)
    ctx->pc = 0x19ac8cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 112), bits); }
    // 0x19ac90: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19ac90u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19ac94: 0xc4204318  lwc1        $f0, 0x4318($at)
    ctx->pc = 0x19ac94u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17176)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19ac98: 0xe7a10074  swc1        $f1, 0x74($sp)
    ctx->pc = 0x19ac98u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 116), bits); }
    // 0x19ac9c: 0xc0665d0  jal         func_199740
    ctx->pc = 0x19AC9Cu;
    SET_GPR_U32(ctx, 31, 0x19ACA4u);
    ctx->pc = 0x19ACA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19AC9Cu;
            // 0x19aca0: 0xe7a00078  swc1        $f0, 0x78($sp) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 120), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x199740u;
    if (runtime->hasFunction(0x199740u)) {
        auto targetFn = runtime->lookupFunction(0x199740u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19ACA4u; }
        if (ctx->pc != 0x19ACA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199740_0x199740(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19ACA4u; }
        if (ctx->pc != 0x19ACA4u) { return; }
    }
    ctx->pc = 0x19ACA4u;
label_19aca4:
    // 0x19aca4: 0x8e62004c  lw          $v0, 0x4C($s3)
    ctx->pc = 0x19aca4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19aca8: 0xc44c0024  lwc1        $f12, 0x24($v0)
    ctx->pc = 0x19aca8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x19acac: 0xc0666a4  jal         func_199A90
    ctx->pc = 0x19ACACu;
    SET_GPR_U32(ctx, 31, 0x19ACB4u);
    ctx->pc = 0x19ACB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19ACACu;
            // 0x19acb0: 0x26040100  addiu       $a0, $s0, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199A90u;
    if (runtime->hasFunction(0x199A90u)) {
        auto targetFn = runtime->lookupFunction(0x199A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19ACB4u; }
        if (ctx->pc != 0x19ACB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199A90_0x199a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19ACB4u; }
        if (ctx->pc != 0x19ACB4u) { return; }
    }
    ctx->pc = 0x19ACB4u;
label_19acb4:
    // 0x19acb4: 0x3c031500  lui         $v1, 0x1500
    ctx->pc = 0x19acb4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)5376 << 16));
    // 0x19acb8: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x19acb8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19acbc: 0x2431825  or          $v1, $s2, $v1
    ctx->pc = 0x19acbcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 18) | GPR_U64(ctx, 3));
    // 0x19acc0: 0xae030160  sw          $v1, 0x160($s0)
    ctx->pc = 0x19acc0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 352), GPR_U32(ctx, 3));
    // 0x19acc4: 0xae000164  sw          $zero, 0x164($s0)
    ctx->pc = 0x19acc4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 356), GPR_U32(ctx, 0));
    // 0x19acc8: 0xae000168  sw          $zero, 0x168($s0)
    ctx->pc = 0x19acc8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 360), GPR_U32(ctx, 0));
    // 0x19accc: 0xae00016c  sw          $zero, 0x16C($s0)
    ctx->pc = 0x19acccu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 364), GPR_U32(ctx, 0));
    // 0x19acd0: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x19acd0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x19acd4: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x19acd4u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19acd8: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x19acd8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19acdc: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x19acdcu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19ace0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19ace0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19ace4: 0x3e00008  jr          $ra
    ctx->pc = 0x19ACE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19ACE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19ACE4u;
            // 0x19ace8: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19AB10u: goto label_19ab10;
            case 0x19ABF4u: goto label_19abf4;
            case 0x19AC04u: goto label_19ac04;
            case 0x19ACA4u: goto label_19aca4;
            case 0x19ACB4u: goto label_19acb4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19ACECu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
