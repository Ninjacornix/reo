#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019C0C0
// Address: 0x19c0c0 - 0x19c2a4
void sub_0019C0C0_0x19c0c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019C0C0_0x19c0c0");
#endif

    switch (ctx->pc) {
        case 0x19c0f0u: goto label_19c0f0;
        case 0x19c1ccu: goto label_19c1cc;
        case 0x19c1dcu: goto label_19c1dc;
        case 0x19c1ecu: goto label_19c1ec;
        case 0x19c214u: goto label_19c214;
        case 0x19c258u: goto label_19c258;
        case 0x19c26cu: goto label_19c26c;
        default: break;
    }

    ctx->pc = 0x19c0c0u;

    // 0x19c0c0: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x19c0c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x19c0c4: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x19c0c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x19c0c8: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x19c0c8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x19c0cc: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x19c0ccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19c0d0: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x19c0d0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19c0d4: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x19c0d4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19c0d8: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x19c0d8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19c0dc: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x19c0dcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19c0e0: 0x240401a0  addiu       $a0, $zero, 0x1A0
    ctx->pc = 0x19c0e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 416));
    // 0x19c0e4: 0x24050010  addiu       $a1, $zero, 0x10
    ctx->pc = 0x19c0e4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x19c0e8: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x19C0E8u;
    SET_GPR_U32(ctx, 31, 0x19C0F0u);
    ctx->pc = 0x19C0ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19C0E8u;
            // 0x19c0ec: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C0F0u; }
        if (ctx->pc != 0x19C0F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C0F0u; }
        if (ctx->pc != 0x19C0F0u) { return; }
    }
    ctx->pc = 0x19C0F0u;
label_19c0f0:
    // 0x19c0f0: 0x3c032000  lui         $v1, 0x2000
    ctx->pc = 0x19c0f0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8192 << 16));
    // 0x19c0f4: 0x3c080029  lui         $t0, 0x29
    ctx->pc = 0x19c0f4u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)41 << 16));
    // 0x19c0f8: 0x34630019  ori         $v1, $v1, 0x19
    ctx->pc = 0x19c0f8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)25);
    // 0x19c0fc: 0x3c041300  lui         $a0, 0x1300
    ctx->pc = 0x19c0fcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4864 << 16));
    // 0x19c100: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x19c100u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x19c104: 0x3c066c17  lui         $a2, 0x6C17
    ctx->pc = 0x19c104u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)27671 << 16));
    // 0x19c108: 0xac510004  sw          $s1, 0x4($v0)
    ctx->pc = 0x19c108u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 17));
    // 0x19c10c: 0x3c030100  lui         $v1, 0x100
    ctx->pc = 0x19c10cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)256 << 16));
    // 0x19c110: 0xfc400008  sd          $zero, 0x8($v0)
    ctx->pc = 0x19c110u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19c114: 0x34630404  ori         $v1, $v1, 0x404
    ctx->pc = 0x19c114u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1028);
    // 0x19c118: 0xac440010  sw          $a0, 0x10($v0)
    ctx->pc = 0x19c118u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 4));
    // 0x19c11c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x19c11cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19c120: 0xac400014  sw          $zero, 0x14($v0)
    ctx->pc = 0x19c120u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19c124: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c124u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c128: 0xac430018  sw          $v1, 0x18($v0)
    ctx->pc = 0x19c128u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 3));
    // 0x19c12c: 0x26040040  addiu       $a0, $s0, 0x40
    ctx->pc = 0x19c12cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 64));
    // 0x19c130: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x19c130u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x19c134: 0xac46001c  sw          $a2, 0x1C($v0)
    ctx->pc = 0x19c134u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 6));
    // 0x19c138: 0x34663700  ori         $a2, $v1, 0x3700
    ctx->pc = 0x19c138u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)14080);
    // 0x19c13c: 0x34673f40  ori         $a3, $v1, 0x3F40
    ctx->pc = 0x19c13cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)16192);
    // 0x19c140: 0x8e63004c  lw          $v1, 0x4C($s3)
    ctx->pc = 0x19c140u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19c144: 0xc4214e50  lwc1        $f1, 0x4E50($at)
    ctx->pc = 0x19c144u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c148: 0x27a50060  addiu       $a1, $sp, 0x60
    ctx->pc = 0x19c148u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x19c14c: 0x25084d40  addiu       $t0, $t0, 0x4D40
    ctx->pc = 0x19c14cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 19776));
    // 0x19c150: 0xc4600024  lwc1        $f0, 0x24($v1)
    ctx->pc = 0x19c150u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c154: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c154u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c158: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x19c158u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19c15c: 0xe4400020  swc1        $f0, 0x20($v0)
    ctx->pc = 0x19c15cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19c160: 0x8e63004c  lw          $v1, 0x4C($s3)
    ctx->pc = 0x19c160u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19c164: 0xc4214e54  lwc1        $f1, 0x4E54($at)
    ctx->pc = 0x19c164u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c168: 0xc4600024  lwc1        $f0, 0x24($v1)
    ctx->pc = 0x19c168u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c16c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c16cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c170: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x19c170u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19c174: 0xe4400024  swc1        $f0, 0x24($v0)
    ctx->pc = 0x19c174u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19c178: 0x8e63004c  lw          $v1, 0x4C($s3)
    ctx->pc = 0x19c178u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19c17c: 0xc4214e58  lwc1        $f1, 0x4E58($at)
    ctx->pc = 0x19c17cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c180: 0xc4600024  lwc1        $f0, 0x24($v1)
    ctx->pc = 0x19c180u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c184: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c184u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c188: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x19c188u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19c18c: 0xe4400028  swc1        $f0, 0x28($v0)
    ctx->pc = 0x19c18cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19c190: 0xc4204e5c  lwc1        $f0, 0x4E5C($at)
    ctx->pc = 0x19c190u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c194: 0xe440002c  swc1        $f0, 0x2C($v0)
    ctx->pc = 0x19c194u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    // 0x19c198: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c198u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c19c: 0xc4204e40  lwc1        $f0, 0x4E40($at)
    ctx->pc = 0x19c19cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20032)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c1a0: 0xe4400030  swc1        $f0, 0x30($v0)
    ctx->pc = 0x19c1a0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 48), bits); }
    // 0x19c1a4: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c1a4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c1a8: 0xc4204e44  lwc1        $f0, 0x4E44($at)
    ctx->pc = 0x19c1a8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20036)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c1ac: 0xe4400034  swc1        $f0, 0x34($v0)
    ctx->pc = 0x19c1acu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 52), bits); }
    // 0x19c1b0: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c1b0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c1b4: 0xc4204e48  lwc1        $f0, 0x4E48($at)
    ctx->pc = 0x19c1b4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20040)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c1b8: 0xe4400038  swc1        $f0, 0x38($v0)
    ctx->pc = 0x19c1b8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 56), bits); }
    // 0x19c1bc: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c1bcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c1c0: 0xc4204e4c  lwc1        $f0, 0x4E4C($at)
    ctx->pc = 0x19c1c0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20044)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c1c4: 0xc066500  jal         func_199400
    ctx->pc = 0x19C1C4u;
    SET_GPR_U32(ctx, 31, 0x19C1CCu);
    ctx->pc = 0x19C1C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19C1C4u;
            // 0x19c1c8: 0xe440003c  swc1        $f0, 0x3C($v0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 60), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x199400u;
    if (runtime->hasFunction(0x199400u)) {
        auto targetFn = runtime->lookupFunction(0x199400u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C1CCu; }
        if (ctx->pc != 0x19C1CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199400_0x199400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C1CCu; }
        if (ctx->pc != 0x19C1CCu) { return; }
    }
    ctx->pc = 0x19C1CCu;
label_19c1cc:
    // 0x19c1cc: 0x3c060029  lui         $a2, 0x29
    ctx->pc = 0x19c1ccu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)41 << 16));
    // 0x19c1d0: 0x26040080  addiu       $a0, $s0, 0x80
    ctx->pc = 0x19c1d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 128));
    // 0x19c1d4: 0xc0664e0  jal         func_199380
    ctx->pc = 0x19C1D4u;
    SET_GPR_U32(ctx, 31, 0x19C1DCu);
    ctx->pc = 0x19C1D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19C1D4u;
            // 0x19c1d8: 0x24c64d00  addiu       $a2, $a2, 0x4D00 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 19712));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199380u;
    if (runtime->hasFunction(0x199380u)) {
        auto targetFn = runtime->lookupFunction(0x199380u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C1DCu; }
        if (ctx->pc != 0x19C1DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199380_0x199380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C1DCu; }
        if (ctx->pc != 0x19C1DCu) { return; }
    }
    ctx->pc = 0x19C1DCu;
label_19c1dc:
    // 0x19c1dc: 0x3c060029  lui         $a2, 0x29
    ctx->pc = 0x19c1dcu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)41 << 16));
    // 0x19c1e0: 0x260500c0  addiu       $a1, $s0, 0xC0
    ctx->pc = 0x19c1e0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 192));
    // 0x19c1e4: 0x24c64cc0  addiu       $a2, $a2, 0x4CC0
    ctx->pc = 0x19c1e4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 19648));
    // 0x19c1e8: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x19c1e8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
label_19c1ec:
    // 0x19c1ec: 0x8cc30000  lw          $v1, 0x0($a2)
    ctx->pc = 0x19c1ecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x19c1f0: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x19c1f0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x19c1f4: 0x8cc20004  lw          $v0, 0x4($a2)
    ctx->pc = 0x19c1f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x19c1f8: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x19c1f8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x19c1fc: 0x24c60008  addiu       $a2, $a2, 0x8
    ctx->pc = 0x19c1fcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
    // 0x19c200: 0xaca20004  sw          $v0, 0x4($a1)
    ctx->pc = 0x19c200u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
    // 0x19c204: 0x1c80fff9  bgtz        $a0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x19C204u;
    {
        const bool branch_taken_0x19c204 = (GPR_S64(ctx, 4) > 0);
        ctx->pc = 0x19C208u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19C204u;
            // 0x19c208: 0x24a50008  addiu       $a1, $a1, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19c204) {
            ctx->pc = 0x19C1ECu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19c1ec;
        }
    }
    ctx->pc = 0x19C20Cu;
    // 0x19c20c: 0xc066734  jal         func_199CD0
    ctx->pc = 0x19C20Cu;
    SET_GPR_U32(ctx, 31, 0x19C214u);
    ctx->pc = 0x19C210u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19C20Cu;
            // 0x19c210: 0x26040100  addiu       $a0, $s0, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199CD0u;
    if (runtime->hasFunction(0x199CD0u)) {
        auto targetFn = runtime->lookupFunction(0x199CD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C214u; }
        if (ctx->pc != 0x19C214u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199CD0_0x199cd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C214u; }
        if (ctx->pc != 0x19C214u) { return; }
    }
    ctx->pc = 0x19C214u;
label_19c214:
    // 0x19c214: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c214u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c218: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x19c218u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x19c21c: 0xc4224240  lwc1        $f2, 0x4240($at)
    ctx->pc = 0x19c21cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16960)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19c220: 0xafa2005c  sw          $v0, 0x5C($sp)
    ctx->pc = 0x19c220u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 92), GPR_U32(ctx, 2));
    // 0x19c224: 0x3c027000  lui         $v0, 0x7000
    ctx->pc = 0x19c224u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28672 << 16));
    // 0x19c228: 0x26040130  addiu       $a0, $s0, 0x130
    ctx->pc = 0x19c228u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 304));
    // 0x19c22c: 0x26050160  addiu       $a1, $s0, 0x160
    ctx->pc = 0x19c22cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 352));
    // 0x19c230: 0x34463700  ori         $a2, $v0, 0x3700
    ctx->pc = 0x19c230u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)14080);
    // 0x19c234: 0x27a70050  addiu       $a3, $sp, 0x50
    ctx->pc = 0x19c234u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x19c238: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c238u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c23c: 0xc4214244  lwc1        $f1, 0x4244($at)
    ctx->pc = 0x19c23cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16964)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c240: 0xe7a20050  swc1        $f2, 0x50($sp)
    ctx->pc = 0x19c240u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 80), bits); }
    // 0x19c244: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19c244u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19c248: 0xc4204248  lwc1        $f0, 0x4248($at)
    ctx->pc = 0x19c248u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16968)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c24c: 0xe7a10054  swc1        $f1, 0x54($sp)
    ctx->pc = 0x19c24cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 84), bits); }
    // 0x19c250: 0xc0665a8  jal         func_1996A0
    ctx->pc = 0x19C250u;
    SET_GPR_U32(ctx, 31, 0x19C258u);
    ctx->pc = 0x19C254u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19C250u;
            // 0x19c254: 0xe7a00058  swc1        $f0, 0x58($sp) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 88), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1996A0u;
    if (runtime->hasFunction(0x1996A0u)) {
        auto targetFn = runtime->lookupFunction(0x1996A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C258u; }
        if (ctx->pc != 0x19C258u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001996A0_0x1996a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C258u; }
        if (ctx->pc != 0x19C258u) { return; }
    }
    ctx->pc = 0x19C258u;
label_19c258:
    // 0x19c258: 0x8e62004c  lw          $v0, 0x4C($s3)
    ctx->pc = 0x19c258u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19c25c: 0x26040170  addiu       $a0, $s0, 0x170
    ctx->pc = 0x19c25cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 368));
    // 0x19c260: 0xc44c0024  lwc1        $f12, 0x24($v0)
    ctx->pc = 0x19c260u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x19c264: 0xc066708  jal         func_199C20
    ctx->pc = 0x19C264u;
    SET_GPR_U32(ctx, 31, 0x19C26Cu);
    ctx->pc = 0x19C268u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19C264u;
            // 0x19c268: 0x26050180  addiu       $a1, $s0, 0x180 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 384));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199C20u;
    if (runtime->hasFunction(0x199C20u)) {
        auto targetFn = runtime->lookupFunction(0x199C20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C26Cu; }
        if (ctx->pc != 0x19C26Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199C20_0x199c20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C26Cu; }
        if (ctx->pc != 0x19C26Cu) { return; }
    }
    ctx->pc = 0x19C26Cu;
label_19c26c:
    // 0x19c26c: 0x3c031500  lui         $v1, 0x1500
    ctx->pc = 0x19c26cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)5376 << 16));
    // 0x19c270: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x19c270u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19c274: 0x2431825  or          $v1, $s2, $v1
    ctx->pc = 0x19c274u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 18) | GPR_U64(ctx, 3));
    // 0x19c278: 0xae030190  sw          $v1, 0x190($s0)
    ctx->pc = 0x19c278u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 400), GPR_U32(ctx, 3));
    // 0x19c27c: 0xae000194  sw          $zero, 0x194($s0)
    ctx->pc = 0x19c27cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 404), GPR_U32(ctx, 0));
    // 0x19c280: 0xae000198  sw          $zero, 0x198($s0)
    ctx->pc = 0x19c280u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 408), GPR_U32(ctx, 0));
    // 0x19c284: 0xae00019c  sw          $zero, 0x19C($s0)
    ctx->pc = 0x19c284u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 412), GPR_U32(ctx, 0));
    // 0x19c288: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x19c288u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x19c28c: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x19c28cu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19c290: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x19c290u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19c294: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x19c294u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19c298: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19c298u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19c29c: 0x3e00008  jr          $ra
    ctx->pc = 0x19C29Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19C2A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19C29Cu;
            // 0x19c2a0: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19C0F0u: goto label_19c0f0;
            case 0x19C1CCu: goto label_19c1cc;
            case 0x19C1DCu: goto label_19c1dc;
            case 0x19C1ECu: goto label_19c1ec;
            case 0x19C214u: goto label_19c214;
            case 0x19C258u: goto label_19c258;
            case 0x19C26Cu: goto label_19c26c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19C2A4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
