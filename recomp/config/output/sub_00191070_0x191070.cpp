#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00191070
// Address: 0x191070 - 0x1911d0
void sub_00191070_0x191070(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00191070_0x191070");
#endif

    switch (ctx->pc) {
        case 0x1910ecu: goto label_1910ec;
        case 0x1910f4u: goto label_1910f4;
        case 0x191104u: goto label_191104;
        case 0x19110cu: goto label_19110c;
        case 0x19111cu: goto label_19111c;
        case 0x191184u: goto label_191184;
        case 0x191198u: goto label_191198;
        case 0x1911acu: goto label_1911ac;
        default: break;
    }

    ctx->pc = 0x191070u;

    // 0x191070: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x191070u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x191074: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x191074u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x191078: 0x27a20050  addiu       $v0, $sp, 0x50
    ctx->pc = 0x191078u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x19107c: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x19107cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x191080: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x191080u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x191084: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x191084u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x191088: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x191088u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19108c: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x19108cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x191090: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x191090u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x191094: 0x27b10064  addiu       $s1, $sp, 0x64
    ctx->pc = 0x191094u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 100));
    // 0x191098: 0xc4a10000  lwc1        $f1, 0x0($a1)
    ctx->pc = 0x191098u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19109c: 0x27b00068  addiu       $s0, $sp, 0x68
    ctx->pc = 0x19109cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 104));
    // 0x1910a0: 0xc4c00000  lwc1        $f0, 0x0($a2)
    ctx->pc = 0x1910a0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 6), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1910a4: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x1910a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1910a8: 0x46000801  sub.s       $f0, $f1, $f0
    ctx->pc = 0x1910a8u;
    ctx->f[0] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1910ac: 0xe7a00060  swc1        $f0, 0x60($sp)
    ctx->pc = 0x1910acu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 96), bits); }
    // 0x1910b0: 0xc4a10004  lwc1        $f1, 0x4($a1)
    ctx->pc = 0x1910b0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1910b4: 0xc4c00004  lwc1        $f0, 0x4($a2)
    ctx->pc = 0x1910b4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 6), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1910b8: 0x46000801  sub.s       $f0, $f1, $f0
    ctx->pc = 0x1910b8u;
    ctx->f[0] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1910bc: 0xe6200000  swc1        $f0, 0x0($s1)
    ctx->pc = 0x1910bcu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 0), bits); }
    // 0x1910c0: 0xc4a10008  lwc1        $f1, 0x8($a1)
    ctx->pc = 0x1910c0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1910c4: 0xc4c00008  lwc1        $f0, 0x8($a2)
    ctx->pc = 0x1910c4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 6), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1910c8: 0x46000801  sub.s       $f0, $f1, $f0
    ctx->pc = 0x1910c8u;
    ctx->f[0] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1910cc: 0xe6000000  swc1        $f0, 0x0($s0)
    ctx->pc = 0x1910ccu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 0), bits); }
    // 0x1910d0: 0xc4e20000  lwc1        $f2, 0x0($a3)
    ctx->pc = 0x1910d0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 7), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1910d4: 0xc4e10004  lwc1        $f1, 0x4($a3)
    ctx->pc = 0x1910d4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 7), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1910d8: 0xc4e00008  lwc1        $f0, 0x8($a3)
    ctx->pc = 0x1910d8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 7), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1910dc: 0xe4420000  swc1        $f2, 0x0($v0)
    ctx->pc = 0x1910dcu;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 0), bits); }
    // 0x1910e0: 0xe4410004  swc1        $f1, 0x4($v0)
    ctx->pc = 0x1910e0u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 4), bits); }
    // 0x1910e4: 0xc064760  jal         func_191D80
    ctx->pc = 0x1910E4u;
    SET_GPR_U32(ctx, 31, 0x1910ECu);
    ctx->pc = 0x1910E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1910E4u;
            // 0x1910e8: 0xe4400008  swc1        $f0, 0x8($v0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 8), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x191D80u;
    if (runtime->hasFunction(0x191D80u)) {
        auto targetFn = runtime->lookupFunction(0x191D80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1910ECu; }
        if (ctx->pc != 0x1910ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191D80_0x191d80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1910ECu; }
        if (ctx->pc != 0x1910ECu) { return; }
    }
    ctx->pc = 0x1910ECu;
label_1910ec:
    // 0x1910ec: 0xc064760  jal         func_191D80
    ctx->pc = 0x1910ECu;
    SET_GPR_U32(ctx, 31, 0x1910F4u);
    ctx->pc = 0x1910F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1910ECu;
            // 0x1910f0: 0x27a40050  addiu       $a0, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191D80u;
    if (runtime->hasFunction(0x191D80u)) {
        auto targetFn = runtime->lookupFunction(0x191D80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1910F4u; }
        if (ctx->pc != 0x1910F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191D80_0x191d80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1910F4u; }
        if (ctx->pc != 0x1910F4u) { return; }
    }
    ctx->pc = 0x1910F4u;
label_1910f4:
    // 0x1910f4: 0x27a40080  addiu       $a0, $sp, 0x80
    ctx->pc = 0x1910f4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
    // 0x1910f8: 0x27a50050  addiu       $a1, $sp, 0x50
    ctx->pc = 0x1910f8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1910fc: 0xc064794  jal         func_191E50
    ctx->pc = 0x1910FCu;
    SET_GPR_U32(ctx, 31, 0x191104u);
    ctx->pc = 0x191100u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1910FCu;
            // 0x191100: 0x27a60060  addiu       $a2, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191E50u;
    if (runtime->hasFunction(0x191E50u)) {
        auto targetFn = runtime->lookupFunction(0x191E50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x191104u; }
        if (ctx->pc != 0x191104u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191E50_0x191e50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x191104u; }
        if (ctx->pc != 0x191104u) { return; }
    }
    ctx->pc = 0x191104u;
label_191104:
    // 0x191104: 0xc064760  jal         func_191D80
    ctx->pc = 0x191104u;
    SET_GPR_U32(ctx, 31, 0x19110Cu);
    ctx->pc = 0x191108u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x191104u;
            // 0x191108: 0x27a40080  addiu       $a0, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191D80u;
    if (runtime->hasFunction(0x191D80u)) {
        auto targetFn = runtime->lookupFunction(0x191D80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19110Cu; }
        if (ctx->pc != 0x19110Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191D80_0x191d80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19110Cu; }
        if (ctx->pc != 0x19110Cu) { return; }
    }
    ctx->pc = 0x19110Cu;
label_19110c:
    // 0x19110c: 0x27a40070  addiu       $a0, $sp, 0x70
    ctx->pc = 0x19110cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
    // 0x191110: 0x27a50060  addiu       $a1, $sp, 0x60
    ctx->pc = 0x191110u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x191114: 0xc064794  jal         func_191E50
    ctx->pc = 0x191114u;
    SET_GPR_U32(ctx, 31, 0x19111Cu);
    ctx->pc = 0x191118u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x191114u;
            // 0x191118: 0x27a60080  addiu       $a2, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191E50u;
    if (runtime->hasFunction(0x191E50u)) {
        auto targetFn = runtime->lookupFunction(0x191E50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19111Cu; }
        if (ctx->pc != 0x19111Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191E50_0x191e50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19111Cu; }
        if (ctx->pc != 0x19111Cu) { return; }
    }
    ctx->pc = 0x19111Cu;
label_19111c:
    // 0x19111c: 0xae60000c  sw          $zero, 0xC($s3)
    ctx->pc = 0x19111cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 12), GPR_U32(ctx, 0));
    // 0x191120: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x191120u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x191124: 0xae60001c  sw          $zero, 0x1C($s3)
    ctx->pc = 0x191124u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 28), GPR_U32(ctx, 0));
    // 0x191128: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x191128u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19112c: 0xae60002c  sw          $zero, 0x2C($s3)
    ctx->pc = 0x19112cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 44), GPR_U32(ctx, 0));
    // 0x191130: 0x27a50080  addiu       $a1, $sp, 0x80
    ctx->pc = 0x191130u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
    // 0x191134: 0xae62003c  sw          $v0, 0x3C($s3)
    ctx->pc = 0x191134u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 60), GPR_U32(ctx, 2));
    // 0x191138: 0xc7a00080  lwc1        $f0, 0x80($sp)
    ctx->pc = 0x191138u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 128)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19113c: 0xe6600000  swc1        $f0, 0x0($s3)
    ctx->pc = 0x19113cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 19), 0), bits); }
    // 0x191140: 0xc7a00084  lwc1        $f0, 0x84($sp)
    ctx->pc = 0x191140u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 132)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191144: 0xe6600010  swc1        $f0, 0x10($s3)
    ctx->pc = 0x191144u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 19), 16), bits); }
    // 0x191148: 0xc7a00088  lwc1        $f0, 0x88($sp)
    ctx->pc = 0x191148u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 136)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19114c: 0xe6600020  swc1        $f0, 0x20($s3)
    ctx->pc = 0x19114cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 19), 32), bits); }
    // 0x191150: 0xc7a00070  lwc1        $f0, 0x70($sp)
    ctx->pc = 0x191150u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 112)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191154: 0xe6600004  swc1        $f0, 0x4($s3)
    ctx->pc = 0x191154u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 19), 4), bits); }
    // 0x191158: 0xc7a00074  lwc1        $f0, 0x74($sp)
    ctx->pc = 0x191158u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 116)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19115c: 0xe6600014  swc1        $f0, 0x14($s3)
    ctx->pc = 0x19115cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 19), 20), bits); }
    // 0x191160: 0xc7a00078  lwc1        $f0, 0x78($sp)
    ctx->pc = 0x191160u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 120)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191164: 0xe6600024  swc1        $f0, 0x24($s3)
    ctx->pc = 0x191164u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 19), 36), bits); }
    // 0x191168: 0xc7a00060  lwc1        $f0, 0x60($sp)
    ctx->pc = 0x191168u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 96)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19116c: 0xe6600008  swc1        $f0, 0x8($s3)
    ctx->pc = 0x19116cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 19), 8), bits); }
    // 0x191170: 0xc6200000  lwc1        $f0, 0x0($s1)
    ctx->pc = 0x191170u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x191174: 0xe6600018  swc1        $f0, 0x18($s3)
    ctx->pc = 0x191174u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 19), 24), bits); }
    // 0x191178: 0xc6000000  lwc1        $f0, 0x0($s0)
    ctx->pc = 0x191178u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19117c: 0xc06477c  jal         func_191DF0
    ctx->pc = 0x19117Cu;
    SET_GPR_U32(ctx, 31, 0x191184u);
    ctx->pc = 0x191180u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19117Cu;
            // 0x191180: 0xe6600028  swc1        $f0, 0x28($s3) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 19), 40), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x191DF0u;
    if (runtime->hasFunction(0x191DF0u)) {
        auto targetFn = runtime->lookupFunction(0x191DF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x191184u; }
        if (ctx->pc != 0x191184u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191DF0_0x191df0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x191184u; }
        if (ctx->pc != 0x191184u) { return; }
    }
    ctx->pc = 0x191184u;
label_191184:
    // 0x191184: 0x46000007  neg.s       $f0, $f0
    ctx->pc = 0x191184u;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x191188: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x191188u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19118c: 0xe6600030  swc1        $f0, 0x30($s3)
    ctx->pc = 0x19118cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 19), 48), bits); }
    // 0x191190: 0xc06477c  jal         func_191DF0
    ctx->pc = 0x191190u;
    SET_GPR_U32(ctx, 31, 0x191198u);
    ctx->pc = 0x191194u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x191190u;
            // 0x191194: 0x27a50070  addiu       $a1, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191DF0u;
    if (runtime->hasFunction(0x191DF0u)) {
        auto targetFn = runtime->lookupFunction(0x191DF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x191198u; }
        if (ctx->pc != 0x191198u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191DF0_0x191df0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x191198u; }
        if (ctx->pc != 0x191198u) { return; }
    }
    ctx->pc = 0x191198u;
label_191198:
    // 0x191198: 0x46000007  neg.s       $f0, $f0
    ctx->pc = 0x191198u;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x19119c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x19119cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1911a0: 0x27a50060  addiu       $a1, $sp, 0x60
    ctx->pc = 0x1911a0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1911a4: 0xc06477c  jal         func_191DF0
    ctx->pc = 0x1911A4u;
    SET_GPR_U32(ctx, 31, 0x1911ACu);
    ctx->pc = 0x1911A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1911A4u;
            // 0x1911a8: 0xe6600034  swc1        $f0, 0x34($s3) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 19), 52), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x191DF0u;
    if (runtime->hasFunction(0x191DF0u)) {
        auto targetFn = runtime->lookupFunction(0x191DF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1911ACu; }
        if (ctx->pc != 0x1911ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191DF0_0x191df0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1911ACu; }
        if (ctx->pc != 0x1911ACu) { return; }
    }
    ctx->pc = 0x1911ACu;
label_1911ac:
    // 0x1911ac: 0x46000007  neg.s       $f0, $f0
    ctx->pc = 0x1911acu;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x1911b0: 0xe6600038  swc1        $f0, 0x38($s3)
    ctx->pc = 0x1911b0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 19), 56), bits); }
    // 0x1911b4: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1911b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1911b8: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1911b8u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1911bc: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1911bcu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1911c0: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1911c0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1911c4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1911c4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1911c8: 0x3e00008  jr          $ra
    ctx->pc = 0x1911C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1911CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1911C8u;
            // 0x1911cc: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1910ECu: goto label_1910ec;
            case 0x1910F4u: goto label_1910f4;
            case 0x191104u: goto label_191104;
            case 0x19110Cu: goto label_19110c;
            case 0x19111Cu: goto label_19111c;
            case 0x191184u: goto label_191184;
            case 0x191198u: goto label_191198;
            case 0x1911ACu: goto label_1911ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1911D0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
