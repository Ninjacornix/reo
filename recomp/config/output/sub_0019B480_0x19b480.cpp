#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019B480
// Address: 0x19b480 - 0x19b6bc
void sub_0019B480_0x19b480(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019B480_0x19b480");
#endif

    switch (ctx->pc) {
        case 0x19b4b0u: goto label_19b4b0;
        case 0x19b5c4u: goto label_19b5c4;
        case 0x19b5d4u: goto label_19b5d4;
        case 0x19b674u: goto label_19b674;
        case 0x19b684u: goto label_19b684;
        default: break;
    }

    ctx->pc = 0x19b480u;

    // 0x19b480: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x19b480u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x19b484: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x19b484u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x19b488: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x19b488u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x19b48c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x19b48cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19b490: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x19b490u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19b494: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x19b494u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19b498: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x19b498u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19b49c: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x19b49cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19b4a0: 0x24040180  addiu       $a0, $zero, 0x180
    ctx->pc = 0x19b4a0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 384));
    // 0x19b4a4: 0x24050010  addiu       $a1, $zero, 0x10
    ctx->pc = 0x19b4a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x19b4a8: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x19B4A8u;
    SET_GPR_U32(ctx, 31, 0x19B4B0u);
    ctx->pc = 0x19B4ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19B4A8u;
            // 0x19b4ac: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B4B0u; }
        if (ctx->pc != 0x19B4B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B4B0u; }
        if (ctx->pc != 0x19B4B0u) { return; }
    }
    ctx->pc = 0x19B4B0u;
label_19b4b0:
    // 0x19b4b0: 0x3c032000  lui         $v1, 0x2000
    ctx->pc = 0x19b4b0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8192 << 16));
    // 0x19b4b4: 0x3c080029  lui         $t0, 0x29
    ctx->pc = 0x19b4b4u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)41 << 16));
    // 0x19b4b8: 0x34630017  ori         $v1, $v1, 0x17
    ctx->pc = 0x19b4b8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)23);
    // 0x19b4bc: 0x3c061300  lui         $a2, 0x1300
    ctx->pc = 0x19b4bcu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)4864 << 16));
    // 0x19b4c0: 0xac430000  sw          $v1, 0x0($v0)
    ctx->pc = 0x19b4c0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x19b4c4: 0x3c056c15  lui         $a1, 0x6C15
    ctx->pc = 0x19b4c4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)27669 << 16));
    // 0x19b4c8: 0xac510004  sw          $s1, 0x4($v0)
    ctx->pc = 0x19b4c8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 17));
    // 0x19b4cc: 0x3c030100  lui         $v1, 0x100
    ctx->pc = 0x19b4ccu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)256 << 16));
    // 0x19b4d0: 0xfc400008  sd          $zero, 0x8($v0)
    ctx->pc = 0x19b4d0u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19b4d4: 0x34640404  ori         $a0, $v1, 0x404
    ctx->pc = 0x19b4d4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1028);
    // 0x19b4d8: 0xac460010  sw          $a2, 0x10($v0)
    ctx->pc = 0x19b4d8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 6));
    // 0x19b4dc: 0x3c033f80  lui         $v1, 0x3F80
    ctx->pc = 0x19b4dcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16256 << 16));
    // 0x19b4e0: 0xac400014  sw          $zero, 0x14($v0)
    ctx->pc = 0x19b4e0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19b4e4: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x19b4e4u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x19b4e8: 0xac440018  sw          $a0, 0x18($v0)
    ctx->pc = 0x19b4e8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 4));
    // 0x19b4ec: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x19b4ecu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19b4f0: 0xac45001c  sw          $a1, 0x1C($v0)
    ctx->pc = 0x19b4f0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 5));
    // 0x19b4f4: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x19b4f4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x19b4f8: 0x8e69004c  lw          $t1, 0x4C($s3)
    ctx->pc = 0x19b4f8u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19b4fc: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b4fcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b500: 0xc4224e50  lwc1        $f2, 0x4E50($at)
    ctx->pc = 0x19b500u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b504: 0x34663700  ori         $a2, $v1, 0x3700
    ctx->pc = 0x19b504u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)14080);
    // 0x19b508: 0x34673f40  ori         $a3, $v1, 0x3F40
    ctx->pc = 0x19b508u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)16192);
    // 0x19b50c: 0x26040050  addiu       $a0, $s0, 0x50
    ctx->pc = 0x19b50cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 80));
    // 0x19b510: 0x27a50080  addiu       $a1, $sp, 0x80
    ctx->pc = 0x19b510u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
    // 0x19b514: 0x25084d40  addiu       $t0, $t0, 0x4D40
    ctx->pc = 0x19b514u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 19776));
    // 0x19b518: 0xc5210024  lwc1        $f1, 0x24($t1)
    ctx->pc = 0x19b518u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 9), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b51c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b51cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b520: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x19b520u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19b524: 0xe4410020  swc1        $f1, 0x20($v0)
    ctx->pc = 0x19b524u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19b528: 0x8e63004c  lw          $v1, 0x4C($s3)
    ctx->pc = 0x19b528u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19b52c: 0xc4224e54  lwc1        $f2, 0x4E54($at)
    ctx->pc = 0x19b52cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b530: 0xc4610024  lwc1        $f1, 0x24($v1)
    ctx->pc = 0x19b530u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b534: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b534u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b538: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x19b538u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19b53c: 0xe4410024  swc1        $f1, 0x24($v0)
    ctx->pc = 0x19b53cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19b540: 0x8e63004c  lw          $v1, 0x4C($s3)
    ctx->pc = 0x19b540u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19b544: 0xc4224e58  lwc1        $f2, 0x4E58($at)
    ctx->pc = 0x19b544u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b548: 0xc4610024  lwc1        $f1, 0x24($v1)
    ctx->pc = 0x19b548u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b54c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b54cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b550: 0x46011042  mul.s       $f1, $f2, $f1
    ctx->pc = 0x19b550u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19b554: 0xe4410028  swc1        $f1, 0x28($v0)
    ctx->pc = 0x19b554u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19b558: 0xc4214e5c  lwc1        $f1, 0x4E5C($at)
    ctx->pc = 0x19b558u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b55c: 0xe441002c  swc1        $f1, 0x2C($v0)
    ctx->pc = 0x19b55cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    // 0x19b560: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b560u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b564: 0xc4214e40  lwc1        $f1, 0x4E40($at)
    ctx->pc = 0x19b564u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20032)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b568: 0xe4410030  swc1        $f1, 0x30($v0)
    ctx->pc = 0x19b568u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 48), bits); }
    // 0x19b56c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b56cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b570: 0xc4214e44  lwc1        $f1, 0x4E44($at)
    ctx->pc = 0x19b570u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20036)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b574: 0xe4410034  swc1        $f1, 0x34($v0)
    ctx->pc = 0x19b574u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 52), bits); }
    // 0x19b578: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b578u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b57c: 0xc4214e48  lwc1        $f1, 0x4E48($at)
    ctx->pc = 0x19b57cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20040)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b580: 0xe4410038  swc1        $f1, 0x38($v0)
    ctx->pc = 0x19b580u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 56), bits); }
    // 0x19b584: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b584u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b588: 0xc4214e4c  lwc1        $f1, 0x4E4C($at)
    ctx->pc = 0x19b588u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20044)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b58c: 0xe441003c  swc1        $f1, 0x3C($v0)
    ctx->pc = 0x19b58cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 60), bits); }
    // 0x19b590: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19b590u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19b594: 0xc421fe40  lwc1        $f1, -0x1C0($at)
    ctx->pc = 0x19b594u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b598: 0xe4410040  swc1        $f1, 0x40($v0)
    ctx->pc = 0x19b598u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 64), bits); }
    // 0x19b59c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19b59cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19b5a0: 0xc422fe40  lwc1        $f2, -0x1C0($at)
    ctx->pc = 0x19b5a0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b5a4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19b5a4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19b5a8: 0xc421fe48  lwc1        $f1, -0x1B8($at)
    ctx->pc = 0x19b5a8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966856)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b5ac: 0x46011041  sub.s       $f1, $f2, $f1
    ctx->pc = 0x19b5acu;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x19b5b0: 0x46010003  div.s       $f0, $f0, $f1
    ctx->pc = 0x19b5b0u;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[0]) ^ std::bit_cast<uint32_t>(ctx->f[1])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[0] / ctx->f[1];
    // 0x19b5b4: 0xe4400044  swc1        $f0, 0x44($v0)
    ctx->pc = 0x19b5b4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 68), bits); }
    // 0x19b5b8: 0xac400048  sw          $zero, 0x48($v0)
    ctx->pc = 0x19b5b8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 72), GPR_U32(ctx, 0));
    // 0x19b5bc: 0xc066500  jal         func_199400
    ctx->pc = 0x19B5BCu;
    SET_GPR_U32(ctx, 31, 0x19B5C4u);
    ctx->pc = 0x19B5C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19B5BCu;
            // 0x19b5c0: 0xac40004c  sw          $zero, 0x4C($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 76), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199400u;
    if (runtime->hasFunction(0x199400u)) {
        auto targetFn = runtime->lookupFunction(0x199400u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B5C4u; }
        if (ctx->pc != 0x19B5C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199400_0x199400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B5C4u; }
        if (ctx->pc != 0x19B5C4u) { return; }
    }
    ctx->pc = 0x19B5C4u;
label_19b5c4:
    // 0x19b5c4: 0x3c060029  lui         $a2, 0x29
    ctx->pc = 0x19b5c4u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)41 << 16));
    // 0x19b5c8: 0x26040090  addiu       $a0, $s0, 0x90
    ctx->pc = 0x19b5c8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 144));
    // 0x19b5cc: 0xc0664e0  jal         func_199380
    ctx->pc = 0x19B5CCu;
    SET_GPR_U32(ctx, 31, 0x19B5D4u);
    ctx->pc = 0x19B5D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19B5CCu;
            // 0x19b5d0: 0x24c64d00  addiu       $a2, $a2, 0x4D00 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 19712));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199380u;
    if (runtime->hasFunction(0x199380u)) {
        auto targetFn = runtime->lookupFunction(0x199380u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B5D4u; }
        if (ctx->pc != 0x19B5D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199380_0x199380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B5D4u; }
        if (ctx->pc != 0x19B5D4u) { return; }
    }
    ctx->pc = 0x19B5D4u;
label_19b5d4:
    // 0x19b5d4: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b5d4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b5d8: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x19b5d8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x19b5dc: 0xc4214234  lwc1        $f1, 0x4234($at)
    ctx->pc = 0x19b5dcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16948)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b5e0: 0xafa2005c  sw          $v0, 0x5C($sp)
    ctx->pc = 0x19b5e0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 92), GPR_U32(ctx, 2));
    // 0x19b5e4: 0xafa2006c  sw          $v0, 0x6C($sp)
    ctx->pc = 0x19b5e4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 108), GPR_U32(ctx, 2));
    // 0x19b5e8: 0x260400d0  addiu       $a0, $s0, 0xD0
    ctx->pc = 0x19b5e8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 208));
    // 0x19b5ec: 0xafa2007c  sw          $v0, 0x7C($sp)
    ctx->pc = 0x19b5ecu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 124), GPR_U32(ctx, 2));
    // 0x19b5f0: 0x26050100  addiu       $a1, $s0, 0x100
    ctx->pc = 0x19b5f0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 256));
    // 0x19b5f4: 0x3c027000  lui         $v0, 0x7000
    ctx->pc = 0x19b5f4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28672 << 16));
    // 0x19b5f8: 0x27a70050  addiu       $a3, $sp, 0x50
    ctx->pc = 0x19b5f8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x19b5fc: 0x34463700  ori         $a2, $v0, 0x3700
    ctx->pc = 0x19b5fcu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)14080);
    // 0x19b600: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b600u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b604: 0xc4204238  lwc1        $f0, 0x4238($at)
    ctx->pc = 0x19b604u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16952)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19b608: 0x46000847  neg.s       $f1, $f1
    ctx->pc = 0x19b608u;
    ctx->f[1] = FPU_NEG_S(ctx->f[1]);
    // 0x19b60c: 0xe7a10050  swc1        $f1, 0x50($sp)
    ctx->pc = 0x19b60cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 80), bits); }
    // 0x19b610: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b610u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b614: 0xc424423c  lwc1        $f4, 0x423C($at)
    ctx->pc = 0x19b614u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16956)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x19b618: 0x46000147  neg.s       $f5, $f0
    ctx->pc = 0x19b618u;
    ctx->f[5] = FPU_NEG_S(ctx->f[0]);
    // 0x19b61c: 0xe7a50054  swc1        $f5, 0x54($sp)
    ctx->pc = 0x19b61cu;
    { float f = ctx->f[5]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 84), bits); }
    // 0x19b620: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b620u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b624: 0xc42342a8  lwc1        $f3, 0x42A8($at)
    ctx->pc = 0x19b624u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17064)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x19b628: 0x46002107  neg.s       $f4, $f4
    ctx->pc = 0x19b628u;
    ctx->f[4] = FPU_NEG_S(ctx->f[4]);
    // 0x19b62c: 0xe7a40058  swc1        $f4, 0x58($sp)
    ctx->pc = 0x19b62cu;
    { float f = ctx->f[4]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 88), bits); }
    // 0x19b630: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b630u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b634: 0xc42242ac  lwc1        $f2, 0x42AC($at)
    ctx->pc = 0x19b634u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17068)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b638: 0xe7a30060  swc1        $f3, 0x60($sp)
    ctx->pc = 0x19b638u;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 96), bits); }
    // 0x19b63c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b63cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b640: 0xc42142b0  lwc1        $f1, 0x42B0($at)
    ctx->pc = 0x19b640u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17072)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b644: 0xe7a20064  swc1        $f2, 0x64($sp)
    ctx->pc = 0x19b644u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 100), bits); }
    // 0x19b648: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b648u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b64c: 0xc4204310  lwc1        $f0, 0x4310($at)
    ctx->pc = 0x19b64cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17168)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19b650: 0xe7a10068  swc1        $f1, 0x68($sp)
    ctx->pc = 0x19b650u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 104), bits); }
    // 0x19b654: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b654u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b658: 0xc4214314  lwc1        $f1, 0x4314($at)
    ctx->pc = 0x19b658u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17172)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b65c: 0xe7a00070  swc1        $f0, 0x70($sp)
    ctx->pc = 0x19b65cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 112), bits); }
    // 0x19b660: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19b660u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19b664: 0xc4204318  lwc1        $f0, 0x4318($at)
    ctx->pc = 0x19b664u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17176)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19b668: 0xe7a10074  swc1        $f1, 0x74($sp)
    ctx->pc = 0x19b668u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 116), bits); }
    // 0x19b66c: 0xc0665d0  jal         func_199740
    ctx->pc = 0x19B66Cu;
    SET_GPR_U32(ctx, 31, 0x19B674u);
    ctx->pc = 0x19B670u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19B66Cu;
            // 0x19b670: 0xe7a00078  swc1        $f0, 0x78($sp) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 120), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x199740u;
    if (runtime->hasFunction(0x199740u)) {
        auto targetFn = runtime->lookupFunction(0x199740u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B674u; }
        if (ctx->pc != 0x19B674u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199740_0x199740(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B674u; }
        if (ctx->pc != 0x19B674u) { return; }
    }
    ctx->pc = 0x19B674u;
label_19b674:
    // 0x19b674: 0x8e62004c  lw          $v0, 0x4C($s3)
    ctx->pc = 0x19b674u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19b678: 0xc44c0024  lwc1        $f12, 0x24($v0)
    ctx->pc = 0x19b678u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x19b67c: 0xc0666a4  jal         func_199A90
    ctx->pc = 0x19B67Cu;
    SET_GPR_U32(ctx, 31, 0x19B684u);
    ctx->pc = 0x19B680u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19B67Cu;
            // 0x19b680: 0x26040110  addiu       $a0, $s0, 0x110 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 272));
        ctx->in_delay_slot = false;
    ctx->pc = 0x199A90u;
    if (runtime->hasFunction(0x199A90u)) {
        auto targetFn = runtime->lookupFunction(0x199A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B684u; }
        if (ctx->pc != 0x19B684u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00199A90_0x199a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B684u; }
        if (ctx->pc != 0x19B684u) { return; }
    }
    ctx->pc = 0x19B684u;
label_19b684:
    // 0x19b684: 0x3c031500  lui         $v1, 0x1500
    ctx->pc = 0x19b684u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)5376 << 16));
    // 0x19b688: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x19b688u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19b68c: 0x2431825  or          $v1, $s2, $v1
    ctx->pc = 0x19b68cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 18) | GPR_U64(ctx, 3));
    // 0x19b690: 0xae030170  sw          $v1, 0x170($s0)
    ctx->pc = 0x19b690u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 368), GPR_U32(ctx, 3));
    // 0x19b694: 0xae000174  sw          $zero, 0x174($s0)
    ctx->pc = 0x19b694u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 372), GPR_U32(ctx, 0));
    // 0x19b698: 0xae000178  sw          $zero, 0x178($s0)
    ctx->pc = 0x19b698u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 376), GPR_U32(ctx, 0));
    // 0x19b69c: 0xae00017c  sw          $zero, 0x17C($s0)
    ctx->pc = 0x19b69cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 380), GPR_U32(ctx, 0));
    // 0x19b6a0: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x19b6a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x19b6a4: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x19b6a4u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19b6a8: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x19b6a8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19b6ac: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x19b6acu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19b6b0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x19b6b0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19b6b4: 0x3e00008  jr          $ra
    ctx->pc = 0x19B6B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19B6B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19B6B4u;
            // 0x19b6b8: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19B4B0u: goto label_19b4b0;
            case 0x19B5C4u: goto label_19b5c4;
            case 0x19B5D4u: goto label_19b5d4;
            case 0x19B674u: goto label_19b674;
            case 0x19B684u: goto label_19b684;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19B6BCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
