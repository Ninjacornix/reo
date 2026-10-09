#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017F908
// Address: 0x17f908 - 0x17f9c8
void sub_0017F908_0x17f908(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017F908_0x17f908");
#endif

    switch (ctx->pc) {
        case 0x17f940u: goto label_17f940;
        case 0x17f94cu: goto label_17f94c;
        case 0x17f95cu: goto label_17f95c;
        case 0x17f968u: goto label_17f968;
        case 0x17f978u: goto label_17f978;
        case 0x17f984u: goto label_17f984;
        case 0x17f9acu: goto label_17f9ac;
        default: break;
    }

    ctx->pc = 0x17f908u;

    // 0x17f908: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x17f908u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x17f90c: 0xe7b40050  swc1        $f20, 0x50($sp)
    ctx->pc = 0x17f90cu;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 80), bits); }
    // 0x17f910: 0x3c01bf80  lui         $at, 0xBF80
    ctx->pc = 0x17f910u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49024 << 16));
    // 0x17f914: 0x4481a000  mtc1        $at, $f20
    ctx->pc = 0x17f914u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[20], &bits, sizeof(bits)); }
    // 0x17f918: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x17f918u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x17f91c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x17f91cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f920: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x17f920u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x17f924: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x17f924u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x17f928: 0xe0902d  daddu       $s2, $a3, $zero
    ctx->pc = 0x17f928u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f92c: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x17f92cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f930: 0x4600a306  mov.s       $f12, $f20
    ctx->pc = 0x17f930u;
    ctx->f[12] = FPU_MOV_S(ctx->f[20]);
    // 0x17f934: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x17f934u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x17f938: 0xc05fc3c  jal         func_17F0F0
    ctx->pc = 0x17F938u;
    SET_GPR_U32(ctx, 31, 0x17F940u);
    ctx->pc = 0x17F93Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F938u;
            // 0x17f93c: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17F0F0u;
    if (runtime->hasFunction(0x17F0F0u)) {
        auto targetFn = runtime->lookupFunction(0x17F0F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F940u; }
        if (ctx->pc != 0x17F940u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017F0F0_0x17f0f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F940u; }
        if (ctx->pc != 0x17F940u) { return; }
    }
    ctx->pc = 0x17F940u;
label_17f940:
    // 0x17f940: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17f940u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f944: 0xc05fb26  jal         func_17EC98
    ctx->pc = 0x17F944u;
    SET_GPR_U32(ctx, 31, 0x17F94Cu);
    ctx->pc = 0x17F948u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F944u;
            // 0x17f948: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17EC98u;
    if (runtime->hasFunction(0x17EC98u)) {
        auto targetFn = runtime->lookupFunction(0x17EC98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F94Cu; }
        if (ctx->pc != 0x17F94Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017EC98_0x17ec98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F94Cu; }
        if (ctx->pc != 0x17F94Cu) { return; }
    }
    ctx->pc = 0x17F94Cu;
label_17f94c:
    // 0x17f94c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17f94cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f950: 0x4600a306  mov.s       $f12, $f20
    ctx->pc = 0x17f950u;
    ctx->f[12] = FPU_MOV_S(ctx->f[20]);
    // 0x17f954: 0xc05fc3c  jal         func_17F0F0
    ctx->pc = 0x17F954u;
    SET_GPR_U32(ctx, 31, 0x17F95Cu);
    ctx->pc = 0x17F958u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F954u;
            // 0x17f958: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17F0F0u;
    if (runtime->hasFunction(0x17F0F0u)) {
        auto targetFn = runtime->lookupFunction(0x17F0F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F95Cu; }
        if (ctx->pc != 0x17F95Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017F0F0_0x17f0f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F95Cu; }
        if (ctx->pc != 0x17F95Cu) { return; }
    }
    ctx->pc = 0x17F95Cu;
label_17f95c:
    // 0x17f95c: 0x26040010  addiu       $a0, $s0, 0x10
    ctx->pc = 0x17f95cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
    // 0x17f960: 0xc05fb26  jal         func_17EC98
    ctx->pc = 0x17F960u;
    SET_GPR_U32(ctx, 31, 0x17F968u);
    ctx->pc = 0x17F964u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F960u;
            // 0x17f964: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17EC98u;
    if (runtime->hasFunction(0x17EC98u)) {
        auto targetFn = runtime->lookupFunction(0x17EC98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F968u; }
        if (ctx->pc != 0x17F968u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017EC98_0x17ec98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F968u; }
        if (ctx->pc != 0x17F968u) { return; }
    }
    ctx->pc = 0x17F968u;
label_17f968:
    // 0x17f968: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x17f968u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f96c: 0x4600a306  mov.s       $f12, $f20
    ctx->pc = 0x17f96cu;
    ctx->f[12] = FPU_MOV_S(ctx->f[20]);
    // 0x17f970: 0xc05fc3c  jal         func_17F0F0
    ctx->pc = 0x17F970u;
    SET_GPR_U32(ctx, 31, 0x17F978u);
    ctx->pc = 0x17F974u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F970u;
            // 0x17f974: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17F0F0u;
    if (runtime->hasFunction(0x17F0F0u)) {
        auto targetFn = runtime->lookupFunction(0x17F0F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F978u; }
        if (ctx->pc != 0x17F978u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017F0F0_0x17f0f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F978u; }
        if (ctx->pc != 0x17F978u) { return; }
    }
    ctx->pc = 0x17F978u;
label_17f978:
    // 0x17f978: 0x26040020  addiu       $a0, $s0, 0x20
    ctx->pc = 0x17f978u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 32));
    // 0x17f97c: 0xc05fb26  jal         func_17EC98
    ctx->pc = 0x17F97Cu;
    SET_GPR_U32(ctx, 31, 0x17F984u);
    ctx->pc = 0x17F980u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F97Cu;
            // 0x17f980: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17EC98u;
    if (runtime->hasFunction(0x17EC98u)) {
        auto targetFn = runtime->lookupFunction(0x17EC98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F984u; }
        if (ctx->pc != 0x17F984u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017EC98_0x17ec98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F984u; }
        if (ctx->pc != 0x17F984u) { return; }
    }
    ctx->pc = 0x17F984u;
label_17f984:
    // 0x17f984: 0x44800000  mtc1        $zero, $f0
    ctx->pc = 0x17f984u;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x17f988: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17f988u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f98c: 0x3c013f80  lui         $at, 0x3F80
    ctx->pc = 0x17f98cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16256 << 16));
    // 0x17f990: 0x44810800  mtc1        $at, $f1
    ctx->pc = 0x17f990u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x17f994: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x17f994u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f998: 0xe6000030  swc1        $f0, 0x30($s0)
    ctx->pc = 0x17f998u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 48), bits); }
    // 0x17f99c: 0xe601003c  swc1        $f1, 0x3C($s0)
    ctx->pc = 0x17f99cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 60), bits); }
    // 0x17f9a0: 0xe6000038  swc1        $f0, 0x38($s0)
    ctx->pc = 0x17f9a0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 56), bits); }
    // 0x17f9a4: 0xc05fb46  jal         func_17ED18
    ctx->pc = 0x17F9A4u;
    SET_GPR_U32(ctx, 31, 0x17F9ACu);
    ctx->pc = 0x17F9A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F9A4u;
            // 0x17f9a8: 0xe6000034  swc1        $f0, 0x34($s0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 52), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x17ED18u;
    if (runtime->hasFunction(0x17ED18u)) {
        auto targetFn = runtime->lookupFunction(0x17ED18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F9ACu; }
        if (ctx->pc != 0x17F9ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017ED18_0x17ed18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F9ACu; }
        if (ctx->pc != 0x17F9ACu) { return; }
    }
    ctx->pc = 0x17F9ACu;
label_17f9ac:
    // 0x17f9ac: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x17f9acu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x17f9b0: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x17f9b0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x17f9b4: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x17f9b4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17f9b8: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x17f9b8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f9bc: 0xc7b40050  lwc1        $f20, 0x50($sp)
    ctx->pc = 0x17f9bcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 80)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x17f9c0: 0x3e00008  jr          $ra
    ctx->pc = 0x17F9C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17F9C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17F9C0u;
            // 0x17f9c4: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17F940u: goto label_17f940;
            case 0x17F94Cu: goto label_17f94c;
            case 0x17F95Cu: goto label_17f95c;
            case 0x17F968u: goto label_17f968;
            case 0x17F978u: goto label_17f978;
            case 0x17F984u: goto label_17f984;
            case 0x17F9ACu: goto label_17f9ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17F9C8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
