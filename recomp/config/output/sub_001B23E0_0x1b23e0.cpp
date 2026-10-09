#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B23E0
// Address: 0x1b23e0 - 0x1b2580
void sub_001B23E0_0x1b23e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B23E0_0x1b23e0");
#endif

    switch (ctx->pc) {
        case 0x1b240cu: goto label_1b240c;
        case 0x1b2468u: goto label_1b2468;
        case 0x1b24a4u: goto label_1b24a4;
        case 0x1b255cu: goto label_1b255c;
        default: break;
    }

    ctx->pc = 0x1b23e0u;

    // 0x1b23e0: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x1b23e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x1b23e4: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1b23e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1b23e8: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1b23e8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1b23ec: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1b23ecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1b23f0: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x1b23f0u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b23f4: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b23f4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b23f8: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x1b23f8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b23fc: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b23fcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b2400: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x1b2400u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b2404: 0xc06c9e4  jal         func_1B2790
    ctx->pc = 0x1B2404u;
    SET_GPR_U32(ctx, 31, 0x1B240Cu);
    ctx->pc = 0x1B2408u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2404u;
            // 0x1b2408: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2790u;
    if (runtime->hasFunction(0x1B2790u)) {
        auto targetFn = runtime->lookupFunction(0x1B2790u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B240Cu; }
        if (ctx->pc != 0x1B240Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2790_0x1b2790(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B240Cu; }
        if (ctx->pc != 0x1B240Cu) { return; }
    }
    ctx->pc = 0x1B240Cu;
label_1b240c:
    // 0x1b240c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B240Cu;
    {
        const bool branch_taken_0x1b240c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B2410u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B240Cu;
            // 0x1b2410: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b240c) {
            ctx->pc = 0x1B241Cu;
            goto label_1b241c;
        }
    }
    ctx->pc = 0x1B2414u;
    // 0x1b2414: 0x10000052  b           . + 4 + (0x52 << 2)
    ctx->pc = 0x1B2414u;
    {
        const bool branch_taken_0x1b2414 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B2418u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2414u;
            // 0x1b2418: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2414) {
            ctx->pc = 0x1B2560u;
            goto label_1b2560;
        }
    }
    ctx->pc = 0x1B241Cu;
label_1b241c:
    // 0x1b241c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b241cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b2420: 0x27a40080  addiu       $a0, $sp, 0x80
    ctx->pc = 0x1b2420u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
    // 0x1b2424: 0xc4224138  lwc1        $f2, 0x4138($at)
    ctx->pc = 0x1b2424u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16696)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1b2428: 0x27a50070  addiu       $a1, $sp, 0x70
    ctx->pc = 0x1b2428u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
    // 0x1b242c: 0x27b10068  addiu       $s1, $sp, 0x68
    ctx->pc = 0x1b242cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 104));
    // 0x1b2430: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b2430u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b2434: 0xc421413c  lwc1        $f1, 0x413C($at)
    ctx->pc = 0x1b2434u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16700)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1b2438: 0xe7a20080  swc1        $f2, 0x80($sp)
    ctx->pc = 0x1b2438u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 128), bits); }
    // 0x1b243c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b243cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b2440: 0xc4204140  lwc1        $f0, 0x4140($at)
    ctx->pc = 0x1b2440u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16704)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1b2444: 0xe7a10084  swc1        $f1, 0x84($sp)
    ctx->pc = 0x1b2444u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 132), bits); }
    // 0x1b2448: 0xe7a00088  swc1        $f0, 0x88($sp)
    ctx->pc = 0x1b2448u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 136), bits); }
    // 0x1b244c: 0xc6400000  lwc1        $f0, 0x0($s2)
    ctx->pc = 0x1b244cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1b2450: 0xe7a00070  swc1        $f0, 0x70($sp)
    ctx->pc = 0x1b2450u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 112), bits); }
    // 0x1b2454: 0xc6400004  lwc1        $f0, 0x4($s2)
    ctx->pc = 0x1b2454u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1b2458: 0xe7a00074  swc1        $f0, 0x74($sp)
    ctx->pc = 0x1b2458u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 116), bits); }
    // 0x1b245c: 0xc6400008  lwc1        $f0, 0x8($s2)
    ctx->pc = 0x1b245cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1b2460: 0xc064744  jal         func_191D10
    ctx->pc = 0x1B2460u;
    SET_GPR_U32(ctx, 31, 0x1B2468u);
    ctx->pc = 0x1B2464u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2460u;
            // 0x1b2464: 0xe7a00078  swc1        $f0, 0x78($sp) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 120), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x191D10u;
    if (runtime->hasFunction(0x191D10u)) {
        auto targetFn = runtime->lookupFunction(0x191D10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2468u; }
        if (ctx->pc != 0x1B2468u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191D10_0x191d10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2468u; }
        if (ctx->pc != 0x1B2468u) { return; }
    }
    ctx->pc = 0x1B2468u;
label_1b2468:
    // 0x1b2468: 0x44800800  mtc1        $zero, $f1
    ctx->pc = 0x1b2468u;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1b246c: 0x0  nop
    ctx->pc = 0x1b246cu;
    // NOP
    // 0x1b2470: 0x46010034  c.lt.s      $f0, $f1
    ctx->pc = 0x1b2470u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1b2474: 0x45000002  bc1f        . + 4 + (0x2 << 2)
    ctx->pc = 0x1B2474u;
    {
        const bool branch_taken_0x1b2474 = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x1B2478u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2474u;
            // 0x1b2478: 0xe6200000  swc1        $f0, 0x0($s1) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 0), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2474) {
            ctx->pc = 0x1B2480u;
            goto label_1b2480;
        }
    }
    ctx->pc = 0x1B247Cu;
    // 0x1b247c: 0xe6210000  swc1        $f1, 0x0($s1)
    ctx->pc = 0x1b247cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 0), bits); }
label_1b2480:
    // 0x1b2480: 0x3402c350  ori         $v0, $zero, 0xC350
    ctx->pc = 0x1b2480u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)50000);
    // 0x1b2484: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1b2484u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1b2488: 0xc6210000  lwc1        $f1, 0x0($s1)
    ctx->pc = 0x1b2488u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1b248c: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x1b248cu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x1b2490: 0x46000836  c.le.s      $f1, $f0
    ctx->pc = 0x1b2490u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1b2494: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1B2494u;
    {
        const bool branch_taken_0x1b2494 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1b2494) {
            ctx->pc = 0x1B24ACu;
            goto label_1b24ac;
        }
    }
    ctx->pc = 0x1B249Cu;
    // 0x1b249c: 0xc06ca04  jal         func_1B2810
    ctx->pc = 0x1B249Cu;
    SET_GPR_U32(ctx, 31, 0x1B24A4u);
    ctx->pc = 0x1B2810u;
    if (runtime->hasFunction(0x1B2810u)) {
        auto targetFn = runtime->lookupFunction(0x1B2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B24A4u; }
        if (ctx->pc != 0x1B24A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2810_0x1b2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B24A4u; }
        if (ctx->pc != 0x1B24A4u) { return; }
    }
    ctx->pc = 0x1B24A4u;
label_1b24a4:
    // 0x1b24a4: 0x1000002e  b           . + 4 + (0x2E << 2)
    ctx->pc = 0x1B24A4u;
    {
        const bool branch_taken_0x1b24a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B24A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B24A4u;
            // 0x1b24a8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b24a4) {
            ctx->pc = 0x1B2560u;
            goto label_1b2560;
        }
    }
    ctx->pc = 0x1B24ACu;
label_1b24ac:
    // 0x1b24ac: 0x0  nop
    ctx->pc = 0x1b24acu;
    // NOP
    // 0x1b24b0: 0x0  nop
    ctx->pc = 0x1b24b0u;
    // NOP
    // 0x1b24b4: 0x46000883  div.s       $f2, $f1, $f0
    ctx->pc = 0x1b24b4u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[2] = std::bit_cast<float>(__maxf); } else ctx->f[2] = ctx->f[1] / ctx->f[0];
    // 0x1b24b8: 0xae14001c  sw          $s4, 0x1C($s0)
    ctx->pc = 0x1b24b8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 20));
    // 0x1b24bc: 0xae130018  sw          $s3, 0x18($s0)
    ctx->pc = 0x1b24bcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 19));
    // 0x1b24c0: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x1b24c0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1b24c4: 0x3c034300  lui         $v1, 0x4300
    ctx->pc = 0x1b24c4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)17152 << 16));
    // 0x1b24c8: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x1b24c8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x1b24cc: 0xc4840000  lwc1        $f4, 0x0($a0)
    ctx->pc = 0x1b24ccu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x1b24d0: 0xc4830004  lwc1        $f3, 0x4($a0)
    ctx->pc = 0x1b24d0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x1b24d4: 0xc4810008  lwc1        $f1, 0x8($a0)
    ctx->pc = 0x1b24d4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1b24d8: 0xc480000c  lwc1        $f0, 0xC($a0)
    ctx->pc = 0x1b24d8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1b24dc: 0xe6040008  swc1        $f4, 0x8($s0)
    ctx->pc = 0x1b24dcu;
    { float f = ctx->f[4]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 8), bits); }
    // 0x1b24e0: 0xe603000c  swc1        $f3, 0xC($s0)
    ctx->pc = 0x1b24e0u;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 12), bits); }
    // 0x1b24e4: 0xe6010010  swc1        $f1, 0x10($s0)
    ctx->pc = 0x1b24e4u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 16), bits); }
    // 0x1b24e8: 0x44830800  mtc1        $v1, $f1
    ctx->pc = 0x1b24e8u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1b24ec: 0x0  nop
    ctx->pc = 0x1b24ecu;
    // NOP
    // 0x1b24f0: 0xe6000014  swc1        $f0, 0x14($s0)
    ctx->pc = 0x1b24f0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 20), bits); }
    // 0x1b24f4: 0x46020842  mul.s       $f1, $f1, $f2
    ctx->pc = 0x1b24f4u;
    ctx->f[1] = FPU_MUL_S(ctx->f[1], ctx->f[2]);
    // 0x1b24f8: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1b24f8u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1b24fc: 0x0  nop
    ctx->pc = 0x1b24fcu;
    // NOP
    // 0x1b2500: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1b2500u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1b2504: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1B2504u;
    {
        const bool branch_taken_0x1b2504 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1b2504) {
            ctx->pc = 0x1B251Cu;
            goto label_1b251c;
        }
    }
    ctx->pc = 0x1B250Cu;
    // 0x1b250c: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1b250cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1b2510: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1b2510u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1b2514: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1B2514u;
    {
        const bool branch_taken_0x1b2514 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B2518u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2514u;
            // 0x1b2518: 0xae030004  sw          $v1, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2514) {
            ctx->pc = 0x1B2538u;
            goto label_1b2538;
        }
    }
    ctx->pc = 0x1B251Cu;
label_1b251c:
    // 0x1b251c: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1b251cu;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1b2520: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1b2520u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1b2524: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1b2524u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1b2528: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x1b2528u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1b252c: 0x0  nop
    ctx->pc = 0x1b252cu;
    // NOP
    // 0x1b2530: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1b2530u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1b2534: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x1b2534u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
label_1b2538:
    // 0x1b2538: 0x3c020032  lui         $v0, 0x32
    ctx->pc = 0x1b2538u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)50 << 16));
    // 0x1b253c: 0x8e050004  lw          $a1, 0x4($s0)
    ctx->pc = 0x1b253cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1b2540: 0x2403007f  addiu       $v1, $zero, 0x7F
    ctx->pc = 0x1b2540u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x1b2544: 0x244288e0  addiu       $v0, $v0, -0x7720
    ctx->pc = 0x1b2544u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294936800));
    // 0x1b2548: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1b2548u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b254c: 0x651823  subu        $v1, $v1, $a1
    ctx->pc = 0x1b254cu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1b2550: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1b2550u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1b2554: 0xc06ca14  jal         func_1B2850
    ctx->pc = 0x1B2554u;
    SET_GPR_U32(ctx, 31, 0x1B255Cu);
    ctx->pc = 0x1B2558u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2554u;
            // 0x1b2558: 0x432821  addu        $a1, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2850u;
    if (runtime->hasFunction(0x1B2850u)) {
        auto targetFn = runtime->lookupFunction(0x1B2850u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B255Cu; }
        if (ctx->pc != 0x1B255Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2850_0x1b2850(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B255Cu; }
        if (ctx->pc != 0x1B255Cu) { return; }
    }
    ctx->pc = 0x1B255Cu;
label_1b255c:
    // 0x1b255c: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x1b255cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
label_1b2560:
    // 0x1b2560: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1b2560u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1b2564: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1b2564u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1b2568: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1b2568u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b256c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b256cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b2570: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b2570u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b2574: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b2574u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b2578: 0x3e00008  jr          $ra
    ctx->pc = 0x1B2578u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B257Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2578u;
            // 0x1b257c: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B240Cu: goto label_1b240c;
            case 0x1B241Cu: goto label_1b241c;
            case 0x1B2468u: goto label_1b2468;
            case 0x1B2480u: goto label_1b2480;
            case 0x1B24A4u: goto label_1b24a4;
            case 0x1B24ACu: goto label_1b24ac;
            case 0x1B251Cu: goto label_1b251c;
            case 0x1B2538u: goto label_1b2538;
            case 0x1B255Cu: goto label_1b255c;
            case 0x1B2560u: goto label_1b2560;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B2580u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
