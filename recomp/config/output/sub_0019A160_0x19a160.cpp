#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019A160
// Address: 0x19a160 - 0x19a368
void sub_0019A160_0x19a160(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019A160_0x19a160");
#endif

    switch (ctx->pc) {
        case 0x19a18cu: goto label_19a18c;
        case 0x19a234u: goto label_19a234;
        case 0x19a244u: goto label_19a244;
        case 0x19a2e8u: goto label_19a2e8;
        case 0x19a2f8u: goto label_19a2f8;
        case 0x19a300u: goto label_19a300;
        default: break;
    }

    ctx->pc = 0x19a160u;

    // 0x19a160: 0x27bdff50  addiu       $sp, $sp, -0xB0
    ctx->pc = 0x19a160u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x19a164: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x19a164u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x19a168: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x19a168u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19a16c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x19a16cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19a170: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x19a170u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a174: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x19a174u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19a178: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x19a178u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a17c: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x19a17cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a180: 0x24040170  addiu       $a0, $zero, 0x170
    ctx->pc = 0x19a180u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 368));
    // 0x19a184: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x19A184u;
    SET_GPR_U32(ctx, 31, 0x19A18Cu);
    ctx->pc = 0x19A188u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19A184u;
            // 0x19a188: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A18Cu; }
        if (ctx->pc != 0x19A18Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A18Cu; }
        if (ctx->pc != 0x19A18Cu) { return; }
    }
    ctx->pc = 0x19A18Cu;
label_19a18c:
    // 0x19a18c: 0x3c032000  lui         $v1, 0x2000
    ctx->pc = 0x19a18cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8192 << 16));
    // 0x19a190: 0x3c080029  lui         $t0, 0x29
    ctx->pc = 0x19a190u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)41 << 16));
    // 0x19a194: 0x34640016  ori         $a0, $v1, 0x16
    ctx->pc = 0x19a194u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)22);
    // 0x19a198: 0x3c051300  lui         $a1, 0x1300
    ctx->pc = 0x19a198u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4864 << 16));
    // 0x19a19c: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x19a19cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x19a1a0: 0x3c030100  lui         $v1, 0x100
    ctx->pc = 0x19a1a0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)256 << 16));
    // 0x19a1a4: 0xac500004  sw          $s0, 0x4($v0)
    ctx->pc = 0x19a1a4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x19a1a8: 0x34660404  ori         $a2, $v1, 0x404
    ctx->pc = 0x19a1a8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1028);
    // 0x19a1ac: 0xfc400008  sd          $zero, 0x8($v0)
    ctx->pc = 0x19a1acu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19a1b0: 0x3c076c14  lui         $a3, 0x6C14
    ctx->pc = 0x19a1b0u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)27668 << 16));
    // 0x19a1b4: 0xac450010  sw          $a1, 0x10($v0)
    ctx->pc = 0x19a1b4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 5));
    // 0x19a1b8: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x19a1b8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x19a1bc: 0xac400014  sw          $zero, 0x14($v0)
    ctx->pc = 0x19a1bcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19a1c0: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a1c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a1c4: 0xac460018  sw          $a2, 0x18($v0)
    ctx->pc = 0x19a1c4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 6));
    // 0x19a1c8: 0x24440030  addiu       $a0, $v0, 0x30
    ctx->pc = 0x19a1c8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 48));
    // 0x19a1cc: 0xac47001c  sw          $a3, 0x1C($v0)
    ctx->pc = 0x19a1ccu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 7));
    // 0x19a1d0: 0x34663700  ori         $a2, $v1, 0x3700
    ctx->pc = 0x19a1d0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)14080);
    // 0x19a1d4: 0x34673f40  ori         $a3, $v1, 0x3F40
    ctx->pc = 0x19a1d4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)16192);
    // 0x19a1d8: 0x27a50070  addiu       $a1, $sp, 0x70
    ctx->pc = 0x19a1d8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
    // 0x19a1dc: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19a1dcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a1e0: 0xc4214e50  lwc1        $f1, 0x4E50($at)
    ctx->pc = 0x19a1e0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a1e4: 0x25084d40  addiu       $t0, $t0, 0x4D40
    ctx->pc = 0x19a1e4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 19776));
    // 0x19a1e8: 0xc4600024  lwc1        $f0, 0x24($v1)
    ctx->pc = 0x19a1e8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a1ec: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a1ecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a1f0: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x19a1f0u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a1f4: 0xe4400020  swc1        $f0, 0x20($v0)
    ctx->pc = 0x19a1f4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19a1f8: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19a1f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a1fc: 0xc4214e54  lwc1        $f1, 0x4E54($at)
    ctx->pc = 0x19a1fcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a200: 0xc4600024  lwc1        $f0, 0x24($v1)
    ctx->pc = 0x19a200u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a204: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a204u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a208: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x19a208u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a20c: 0xe4400024  swc1        $f0, 0x24($v0)
    ctx->pc = 0x19a20cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19a210: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19a210u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a214: 0xc4214e58  lwc1        $f1, 0x4E58($at)
    ctx->pc = 0x19a214u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a218: 0xc4600024  lwc1        $f0, 0x24($v1)
    ctx->pc = 0x19a218u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a21c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a21cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a220: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x19a220u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a224: 0xe4400028  swc1        $f0, 0x28($v0)
    ctx->pc = 0x19a224u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19a228: 0xc4204e5c  lwc1        $f0, 0x4E5C($at)
    ctx->pc = 0x19a228u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a22c: 0xc066500  jal         func_199400
    ctx->pc = 0x19A22Cu;
    SET_GPR_U32(ctx, 31, 0x19A234u);
    ctx->pc = 0x19A230u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19A22Cu;
            // 0x19a230: 0xe440002c  swc1        $f0, 0x2C($v0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x199400u;
    if (runtime->hasFunction(0x199400u)) {
        auto targetFn = runtime->lookupFunction(0x199400u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A234u; }
        if (ctx->pc != 0x19A234u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199400_0x199400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A234u; }
        if (ctx->pc != 0x19A234u) { return; }
    }
    ctx->pc = 0x19A234u;
label_19a234:
    // 0x19a234: 0x3c060029  lui         $a2, 0x29
    ctx->pc = 0x19a234u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)41 << 16));
    // 0x19a238: 0x24440070  addiu       $a0, $v0, 0x70
    ctx->pc = 0x19a238u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 112));
    // 0x19a23c: 0xc0664e0  jal         func_199380
    ctx->pc = 0x19A23Cu;
    SET_GPR_U32(ctx, 31, 0x19A244u);
    ctx->pc = 0x19A240u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19A23Cu;
            // 0x19a240: 0x24c64d00  addiu       $a2, $a2, 0x4D00 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 19712));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199380u;
    if (runtime->hasFunction(0x199380u)) {
        auto targetFn = runtime->lookupFunction(0x199380u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A244u; }
        if (ctx->pc != 0x19A244u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199380_0x199380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A244u; }
        if (ctx->pc != 0x19A244u) { return; }
    }
    ctx->pc = 0x19A244u;
label_19a244:
    // 0x19a244: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a244u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a248: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x19a248u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x19a24c: 0xc4204234  lwc1        $f0, 0x4234($at)
    ctx->pc = 0x19a24cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16948)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a250: 0x244400b0  addiu       $a0, $v0, 0xB0
    ctx->pc = 0x19a250u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 176));
    // 0x19a254: 0x34653700  ori         $a1, $v1, 0x3700
    ctx->pc = 0x19a254u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)14080);
    // 0x19a258: 0x27a60040  addiu       $a2, $sp, 0x40
    ctx->pc = 0x19a258u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x19a25c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a25cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a260: 0xc4254238  lwc1        $f5, 0x4238($at)
    ctx->pc = 0x19a260u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16952)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[5] = f; }
    // 0x19a264: 0x46000187  neg.s       $f6, $f0
    ctx->pc = 0x19a264u;
    ctx->f[6] = FPU_NEG_S(ctx->f[0]);
    // 0x19a268: 0xe7a60040  swc1        $f6, 0x40($sp)
    ctx->pc = 0x19a268u;
    { float f = ctx->f[6]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 64), bits); }
    // 0x19a26c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a26cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a270: 0xc424423c  lwc1        $f4, 0x423C($at)
    ctx->pc = 0x19a270u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16956)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x19a274: 0x46002947  neg.s       $f5, $f5
    ctx->pc = 0x19a274u;
    ctx->f[5] = FPU_NEG_S(ctx->f[5]);
    // 0x19a278: 0xe7a50044  swc1        $f5, 0x44($sp)
    ctx->pc = 0x19a278u;
    { float f = ctx->f[5]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 68), bits); }
    // 0x19a27c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a27cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a280: 0xc423429c  lwc1        $f3, 0x429C($at)
    ctx->pc = 0x19a280u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x19a284: 0x46002107  neg.s       $f4, $f4
    ctx->pc = 0x19a284u;
    ctx->f[4] = FPU_NEG_S(ctx->f[4]);
    // 0x19a288: 0xe7a40048  swc1        $f4, 0x48($sp)
    ctx->pc = 0x19a288u;
    { float f = ctx->f[4]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 72), bits); }
    // 0x19a28c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a28cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a290: 0xc42242a0  lwc1        $f2, 0x42A0($at)
    ctx->pc = 0x19a290u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19a294: 0x460018c7  neg.s       $f3, $f3
    ctx->pc = 0x19a294u;
    ctx->f[3] = FPU_NEG_S(ctx->f[3]);
    // 0x19a298: 0xe7a30050  swc1        $f3, 0x50($sp)
    ctx->pc = 0x19a298u;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 80), bits); }
    // 0x19a29c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a29cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a2a0: 0xc42142a4  lwc1        $f1, 0x42A4($at)
    ctx->pc = 0x19a2a0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a2a4: 0x46001087  neg.s       $f2, $f2
    ctx->pc = 0x19a2a4u;
    ctx->f[2] = FPU_NEG_S(ctx->f[2]);
    // 0x19a2a8: 0xe7a20054  swc1        $f2, 0x54($sp)
    ctx->pc = 0x19a2a8u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 84), bits); }
    // 0x19a2ac: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a2acu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a2b0: 0xc4204304  lwc1        $f0, 0x4304($at)
    ctx->pc = 0x19a2b0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17156)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a2b4: 0x46000847  neg.s       $f1, $f1
    ctx->pc = 0x19a2b4u;
    ctx->f[1] = FPU_NEG_S(ctx->f[1]);
    // 0x19a2b8: 0xe7a10058  swc1        $f1, 0x58($sp)
    ctx->pc = 0x19a2b8u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 88), bits); }
    // 0x19a2bc: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a2bcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a2c0: 0xc4214308  lwc1        $f1, 0x4308($at)
    ctx->pc = 0x19a2c0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17160)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a2c4: 0x46000007  neg.s       $f0, $f0
    ctx->pc = 0x19a2c4u;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x19a2c8: 0xe7a00060  swc1        $f0, 0x60($sp)
    ctx->pc = 0x19a2c8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 96), bits); }
    // 0x19a2cc: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19a2ccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19a2d0: 0xc420430c  lwc1        $f0, 0x430C($at)
    ctx->pc = 0x19a2d0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17164)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a2d4: 0x46000847  neg.s       $f1, $f1
    ctx->pc = 0x19a2d4u;
    ctx->f[1] = FPU_NEG_S(ctx->f[1]);
    // 0x19a2d8: 0xe7a10064  swc1        $f1, 0x64($sp)
    ctx->pc = 0x19a2d8u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 100), bits); }
    // 0x19a2dc: 0x46000007  neg.s       $f0, $f0
    ctx->pc = 0x19a2dcu;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x19a2e0: 0xc066570  jal         func_1995C0
    ctx->pc = 0x19A2E0u;
    SET_GPR_U32(ctx, 31, 0x19A2E8u);
    ctx->pc = 0x19A2E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19A2E0u;
            // 0x19a2e4: 0xe7a00068  swc1        $f0, 0x68($sp) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 104), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1995C0u;
    if (runtime->hasFunction(0x1995C0u)) {
        auto targetFn = runtime->lookupFunction(0x1995C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A2E8u; }
        if (ctx->pc != 0x19A2E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001995C0_0x1995c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A2E8u; }
        if (ctx->pc != 0x19A2E8u) { return; }
    }
    ctx->pc = 0x19A2E8u;
label_19a2e8:
    // 0x19a2e8: 0x8e43004c  lw          $v1, 0x4C($s2)
    ctx->pc = 0x19a2e8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a2ec: 0xc46c0024  lwc1        $f12, 0x24($v1)
    ctx->pc = 0x19a2ecu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x19a2f0: 0xc066648  jal         func_199920
    ctx->pc = 0x19A2F0u;
    SET_GPR_U32(ctx, 31, 0x19A2F8u);
    ctx->pc = 0x19A2F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19A2F0u;
            // 0x19a2f4: 0x244400e0  addiu       $a0, $v0, 0xE0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 224));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199920u;
    if (runtime->hasFunction(0x199920u)) {
        auto targetFn = runtime->lookupFunction(0x199920u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A2F8u; }
        if (ctx->pc != 0x19A2F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199920_0x199920(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A2F8u; }
        if (ctx->pc != 0x19A2F8u) { return; }
    }
    ctx->pc = 0x19A2F8u;
label_19a2f8:
    // 0x19a2f8: 0xc066734  jal         func_199CD0
    ctx->pc = 0x19A2F8u;
    SET_GPR_U32(ctx, 31, 0x19A300u);
    ctx->pc = 0x19A2FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19A2F8u;
            // 0x19a2fc: 0x24440120  addiu       $a0, $v0, 0x120 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 288));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199CD0u;
    if (runtime->hasFunction(0x199CD0u)) {
        auto targetFn = runtime->lookupFunction(0x199CD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A300u; }
        if (ctx->pc != 0x19A300u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199CD0_0x199cd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A300u; }
        if (ctx->pc != 0x19A300u) { return; }
    }
    ctx->pc = 0x19A300u;
label_19a300:
    // 0x19a300: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19a300u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19a304: 0x3c033f80  lui         $v1, 0x3F80
    ctx->pc = 0x19a304u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16256 << 16));
    // 0x19a308: 0xc421fe40  lwc1        $f1, -0x1C0($at)
    ctx->pc = 0x19a308u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a30c: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x19a30cu;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x19a310: 0x3c031500  lui         $v1, 0x1500
    ctx->pc = 0x19a310u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)5376 << 16));
    // 0x19a314: 0x2231825  or          $v1, $s1, $v1
    ctx->pc = 0x19a314u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) | GPR_U64(ctx, 3));
    // 0x19a318: 0xe4410150  swc1        $f1, 0x150($v0)
    ctx->pc = 0x19a318u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 336), bits); }
    // 0x19a31c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19a31cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19a320: 0xc422fe40  lwc1        $f2, -0x1C0($at)
    ctx->pc = 0x19a320u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19a324: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19a324u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19a328: 0xc421fe48  lwc1        $f1, -0x1B8($at)
    ctx->pc = 0x19a328u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966856)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a32c: 0x46011041  sub.s       $f1, $f2, $f1
    ctx->pc = 0x19a32cu;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x19a330: 0x46010003  div.s       $f0, $f0, $f1
    ctx->pc = 0x19a330u;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[0]) ^ std::bit_cast<uint32_t>(ctx->f[1])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[0] / ctx->f[1];
    // 0x19a334: 0xe4400154  swc1        $f0, 0x154($v0)
    ctx->pc = 0x19a334u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 340), bits); }
    // 0x19a338: 0xac400158  sw          $zero, 0x158($v0)
    ctx->pc = 0x19a338u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 344), GPR_U32(ctx, 0));
    // 0x19a33c: 0xac40015c  sw          $zero, 0x15C($v0)
    ctx->pc = 0x19a33cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 348), GPR_U32(ctx, 0));
    // 0x19a340: 0xac430160  sw          $v1, 0x160($v0)
    ctx->pc = 0x19a340u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 352), GPR_U32(ctx, 3));
    // 0x19a344: 0xac400164  sw          $zero, 0x164($v0)
    ctx->pc = 0x19a344u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 356), GPR_U32(ctx, 0));
    // 0x19a348: 0xac400168  sw          $zero, 0x168($v0)
    ctx->pc = 0x19a348u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 360), GPR_U32(ctx, 0));
    // 0x19a34c: 0xac40016c  sw          $zero, 0x16C($v0)
    ctx->pc = 0x19a34cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 364), GPR_U32(ctx, 0));
    // 0x19a350: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x19a350u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19a354: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x19a354u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19a358: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x19a358u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19a35c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19a35cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19a360: 0x3e00008  jr          $ra
    ctx->pc = 0x19A360u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19A364u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19A360u;
            // 0x19a364: 0x27bd00b0  addiu       $sp, $sp, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19A18Cu: goto label_19a18c;
            case 0x19A234u: goto label_19a234;
            case 0x19A244u: goto label_19a244;
            case 0x19A2E8u: goto label_19a2e8;
            case 0x19A2F8u: goto label_19a2f8;
            case 0x19A300u: goto label_19a300;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19A368u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
