#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A5050
// Address: 0x1a5050 - 0x1a517c
void sub_001A5050_0x1a5050(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A5050_0x1a5050");
#endif

    switch (ctx->pc) {
        case 0x1a50b0u: goto label_1a50b0;
        case 0x1a50b8u: goto label_1a50b8;
        case 0x1a50e8u: goto label_1a50e8;
        case 0x1a50f0u: goto label_1a50f0;
        case 0x1a5100u: goto label_1a5100;
        default: break;
    }

    ctx->pc = 0x1a5050u;

    // 0x1a5050: 0x27bdff50  addiu       $sp, $sp, -0xB0
    ctx->pc = 0x1a5050u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x1a5054: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1a5054u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1a5058: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1a5058u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1a505c: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1a505cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1a5060: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x1a5060u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a5064: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1a5064u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1a5068: 0x27b30074  addiu       $s3, $sp, 0x74
    ctx->pc = 0x1a5068u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 116));
    // 0x1a506c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1a506cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1a5070: 0x27b20078  addiu       $s2, $sp, 0x78
    ctx->pc = 0x1a5070u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 29), 120));
    // 0x1a5074: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1a5074u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1a5078: 0x27a40070  addiu       $a0, $sp, 0x70
    ctx->pc = 0x1a5078u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
    // 0x1a507c: 0xc4a00000  lwc1        $f0, 0x0($a1)
    ctx->pc = 0x1a507cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a5080: 0xe7a00070  swc1        $f0, 0x70($sp)
    ctx->pc = 0x1a5080u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 112), bits); }
    // 0x1a5084: 0xc4a00004  lwc1        $f0, 0x4($a1)
    ctx->pc = 0x1a5084u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a5088: 0xe6600000  swc1        $f0, 0x0($s3)
    ctx->pc = 0x1a5088u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 19), 0), bits); }
    // 0x1a508c: 0xc4a00008  lwc1        $f0, 0x8($a1)
    ctx->pc = 0x1a508cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a5090: 0xe6400000  swc1        $f0, 0x0($s2)
    ctx->pc = 0x1a5090u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 18), 0), bits); }
    // 0x1a5094: 0xc4c00000  lwc1        $f0, 0x0($a2)
    ctx->pc = 0x1a5094u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 6), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a5098: 0xe7a00060  swc1        $f0, 0x60($sp)
    ctx->pc = 0x1a5098u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 96), bits); }
    // 0x1a509c: 0xc4c00004  lwc1        $f0, 0x4($a2)
    ctx->pc = 0x1a509cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 6), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a50a0: 0xe7a00064  swc1        $f0, 0x64($sp)
    ctx->pc = 0x1a50a0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 100), bits); }
    // 0x1a50a4: 0xc4c00008  lwc1        $f0, 0x8($a2)
    ctx->pc = 0x1a50a4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 6), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a50a8: 0xc06946c  jal         func_1A51B0
    ctx->pc = 0x1A50A8u;
    SET_GPR_U32(ctx, 31, 0x1A50B0u);
    ctx->pc = 0x1A50ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A50A8u;
            // 0x1a50ac: 0xe7a00068  swc1        $f0, 0x68($sp) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 104), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A51B0u;
    if (runtime->hasFunction(0x1A51B0u)) {
        auto targetFn = runtime->lookupFunction(0x1A51B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A50B0u; }
        if (ctx->pc != 0x1A50B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A51B0_0x1a51b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A50B0u; }
        if (ctx->pc != 0x1A50B0u) { return; }
    }
    ctx->pc = 0x1A50B0u;
label_1a50b0:
    // 0x1a50b0: 0xc06946c  jal         func_1A51B0
    ctx->pc = 0x1A50B0u;
    SET_GPR_U32(ctx, 31, 0x1A50B8u);
    ctx->pc = 0x1A50B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A50B0u;
            // 0x1a50b4: 0x27a40060  addiu       $a0, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A51B0u;
    if (runtime->hasFunction(0x1A51B0u)) {
        auto targetFn = runtime->lookupFunction(0x1A51B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A50B8u; }
        if (ctx->pc != 0x1A50B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A51B0_0x1a51b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A50B8u; }
        if (ctx->pc != 0x1A50B8u) { return; }
    }
    ctx->pc = 0x1A50B8u;
label_1a50b8:
    // 0x1a50b8: 0xc7a00070  lwc1        $f0, 0x70($sp)
    ctx->pc = 0x1a50b8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 112)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a50bc: 0x27b100a4  addiu       $s1, $sp, 0xA4
    ctx->pc = 0x1a50bcu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 164));
    // 0x1a50c0: 0x27b000a8  addiu       $s0, $sp, 0xA8
    ctx->pc = 0x1a50c0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 168));
    // 0x1a50c4: 0x27a40080  addiu       $a0, $sp, 0x80
    ctx->pc = 0x1a50c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
    // 0x1a50c8: 0x27a500a0  addiu       $a1, $sp, 0xA0
    ctx->pc = 0x1a50c8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
    // 0x1a50cc: 0x27a60060  addiu       $a2, $sp, 0x60
    ctx->pc = 0x1a50ccu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x1a50d0: 0xe7a000a0  swc1        $f0, 0xA0($sp)
    ctx->pc = 0x1a50d0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 160), bits); }
    // 0x1a50d4: 0xc6600000  lwc1        $f0, 0x0($s3)
    ctx->pc = 0x1a50d4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 19), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a50d8: 0xe6200000  swc1        $f0, 0x0($s1)
    ctx->pc = 0x1a50d8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 0), bits); }
    // 0x1a50dc: 0xc6400000  lwc1        $f0, 0x0($s2)
    ctx->pc = 0x1a50dcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a50e0: 0xc069488  jal         func_1A5220
    ctx->pc = 0x1A50E0u;
    SET_GPR_U32(ctx, 31, 0x1A50E8u);
    ctx->pc = 0x1A50E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A50E0u;
            // 0x1a50e4: 0xe6000000  swc1        $f0, 0x0($s0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 0), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A5220u;
    if (runtime->hasFunction(0x1A5220u)) {
        auto targetFn = runtime->lookupFunction(0x1A5220u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A50E8u; }
        if (ctx->pc != 0x1A50E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A5220_0x1a5220(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A50E8u; }
        if (ctx->pc != 0x1A50E8u) { return; }
    }
    ctx->pc = 0x1A50E8u;
label_1a50e8:
    // 0x1a50e8: 0xc06946c  jal         func_1A51B0
    ctx->pc = 0x1A50E8u;
    SET_GPR_U32(ctx, 31, 0x1A50F0u);
    ctx->pc = 0x1A50ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A50E8u;
            // 0x1a50ec: 0x27a40080  addiu       $a0, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A51B0u;
    if (runtime->hasFunction(0x1A51B0u)) {
        auto targetFn = runtime->lookupFunction(0x1A51B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A50F0u; }
        if (ctx->pc != 0x1A50F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A51B0_0x1a51b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A50F0u; }
        if (ctx->pc != 0x1A50F0u) { return; }
    }
    ctx->pc = 0x1A50F0u;
label_1a50f0:
    // 0x1a50f0: 0x27a40090  addiu       $a0, $sp, 0x90
    ctx->pc = 0x1a50f0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
    // 0x1a50f4: 0x27a50080  addiu       $a1, $sp, 0x80
    ctx->pc = 0x1a50f4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
    // 0x1a50f8: 0xc069488  jal         func_1A5220
    ctx->pc = 0x1A50F8u;
    SET_GPR_U32(ctx, 31, 0x1A5100u);
    ctx->pc = 0x1A50FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A50F8u;
            // 0x1a50fc: 0x27a600a0  addiu       $a2, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A5220u;
    if (runtime->hasFunction(0x1A5220u)) {
        auto targetFn = runtime->lookupFunction(0x1A5220u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5100u; }
        if (ctx->pc != 0x1A5100u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A5220_0x1a5220(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A5100u; }
        if (ctx->pc != 0x1A5100u) { return; }
    }
    ctx->pc = 0x1A5100u;
label_1a5100:
    // 0x1a5100: 0xae80000c  sw          $zero, 0xC($s4)
    ctx->pc = 0x1a5100u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 12), GPR_U32(ctx, 0));
    // 0x1a5104: 0x3c033f80  lui         $v1, 0x3F80
    ctx->pc = 0x1a5104u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16256 << 16));
    // 0x1a5108: 0xae80001c  sw          $zero, 0x1C($s4)
    ctx->pc = 0x1a5108u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 28), GPR_U32(ctx, 0));
    // 0x1a510c: 0xae80002c  sw          $zero, 0x2C($s4)
    ctx->pc = 0x1a510cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 44), GPR_U32(ctx, 0));
    // 0x1a5110: 0xae83003c  sw          $v1, 0x3C($s4)
    ctx->pc = 0x1a5110u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 60), GPR_U32(ctx, 3));
    // 0x1a5114: 0xc7a000a0  lwc1        $f0, 0xA0($sp)
    ctx->pc = 0x1a5114u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 160)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a5118: 0xe6800000  swc1        $f0, 0x0($s4)
    ctx->pc = 0x1a5118u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 20), 0), bits); }
    // 0x1a511c: 0xc6200000  lwc1        $f0, 0x0($s1)
    ctx->pc = 0x1a511cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a5120: 0xe6800004  swc1        $f0, 0x4($s4)
    ctx->pc = 0x1a5120u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 20), 4), bits); }
    // 0x1a5124: 0xc6000000  lwc1        $f0, 0x0($s0)
    ctx->pc = 0x1a5124u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a5128: 0xe6800008  swc1        $f0, 0x8($s4)
    ctx->pc = 0x1a5128u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 20), 8), bits); }
    // 0x1a512c: 0xc7a00090  lwc1        $f0, 0x90($sp)
    ctx->pc = 0x1a512cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 144)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a5130: 0xe6800010  swc1        $f0, 0x10($s4)
    ctx->pc = 0x1a5130u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 20), 16), bits); }
    // 0x1a5134: 0xc7a00094  lwc1        $f0, 0x94($sp)
    ctx->pc = 0x1a5134u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 148)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a5138: 0xe6800014  swc1        $f0, 0x14($s4)
    ctx->pc = 0x1a5138u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 20), 20), bits); }
    // 0x1a513c: 0xc7a00098  lwc1        $f0, 0x98($sp)
    ctx->pc = 0x1a513cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 152)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a5140: 0xe6800018  swc1        $f0, 0x18($s4)
    ctx->pc = 0x1a5140u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 20), 24), bits); }
    // 0x1a5144: 0xc7a00080  lwc1        $f0, 0x80($sp)
    ctx->pc = 0x1a5144u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 128)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a5148: 0xe6800020  swc1        $f0, 0x20($s4)
    ctx->pc = 0x1a5148u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 20), 32), bits); }
    // 0x1a514c: 0xc7a00084  lwc1        $f0, 0x84($sp)
    ctx->pc = 0x1a514cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 132)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a5150: 0xe6800024  swc1        $f0, 0x24($s4)
    ctx->pc = 0x1a5150u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 20), 36), bits); }
    // 0x1a5154: 0xc7a00088  lwc1        $f0, 0x88($sp)
    ctx->pc = 0x1a5154u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 136)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1a5158: 0xe6800028  swc1        $f0, 0x28($s4)
    ctx->pc = 0x1a5158u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 20), 40), bits); }
    // 0x1a515c: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1a515cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1a5160: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1a5160u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1a5164: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1a5164u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1a5168: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1a5168u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1a516c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1a516cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a5170: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a5170u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a5174: 0x3e00008  jr          $ra
    ctx->pc = 0x1A5174u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A5178u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5174u;
            // 0x1a5178: 0x27bd00b0  addiu       $sp, $sp, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A50B0u: goto label_1a50b0;
            case 0x1A50B8u: goto label_1a50b8;
            case 0x1A50E8u: goto label_1a50e8;
            case 0x1A50F0u: goto label_1a50f0;
            case 0x1A5100u: goto label_1a5100;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A517Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
