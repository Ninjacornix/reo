#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00193A00
// Address: 0x193a00 - 0x193af0
void sub_00193A00_0x193a00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00193A00_0x193a00");
#endif

    switch (ctx->pc) {
        case 0x193a4cu: goto label_193a4c;
        case 0x193a54u: goto label_193a54;
        case 0x193a68u: goto label_193a68;
        case 0x193a70u: goto label_193a70;
        case 0x193ab4u: goto label_193ab4;
        case 0x193ac0u: goto label_193ac0;
        default: break;
    }

    ctx->pc = 0x193a00u;

    // 0x193a00: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x193a00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x193a04: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x193a04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x193a08: 0x7fb10020  sq          $s1, 0x20($sp)
    ctx->pc = 0x193a08u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 17));
    // 0x193a0c: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x193a0cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x193a10: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x193a10u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193a14: 0xe7b60008  swc1        $f22, 0x8($sp)
    ctx->pc = 0x193a14u;
    { float f = ctx->f[22]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 8), bits); }
    // 0x193a18: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x193a18u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193a1c: 0xe7b50004  swc1        $f21, 0x4($sp)
    ctx->pc = 0x193a1cu;
    { float f = ctx->f[21]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 4), bits); }
    // 0x193a20: 0xe7b40000  swc1        $f20, 0x0($sp)
    ctx->pc = 0x193a20u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x193a24: 0xc4a20000  lwc1        $f2, 0x0($a1)
    ctx->pc = 0x193a24u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x193a28: 0xc4a10004  lwc1        $f1, 0x4($a1)
    ctx->pc = 0x193a28u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x193a2c: 0xc4a00008  lwc1        $f0, 0x8($a1)
    ctx->pc = 0x193a2cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x193a30: 0x46006586  mov.s       $f22, $f12
    ctx->pc = 0x193a30u;
    ctx->f[22] = FPU_MOV_S(ctx->f[12]);
    // 0x193a34: 0x46006d46  mov.s       $f21, $f13
    ctx->pc = 0x193a34u;
    ctx->f[21] = FPU_MOV_S(ctx->f[13]);
    // 0x193a38: 0x46007506  mov.s       $f20, $f14
    ctx->pc = 0x193a38u;
    ctx->f[20] = FPU_MOV_S(ctx->f[14]);
    // 0x193a3c: 0x46161302  mul.s       $f12, $f2, $f22
    ctx->pc = 0x193a3cu;
    ctx->f[12] = FPU_MUL_S(ctx->f[2], ctx->f[22]);
    // 0x193a40: 0x46150b42  mul.s       $f13, $f1, $f21
    ctx->pc = 0x193a40u;
    ctx->f[13] = FPU_MUL_S(ctx->f[1], ctx->f[21]);
    // 0x193a44: 0xc063f98  jal         func_18FE60
    ctx->pc = 0x193A44u;
    SET_GPR_U32(ctx, 31, 0x193A4Cu);
    ctx->pc = 0x193A48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193A44u;
            // 0x193a48: 0x46140382  mul.s       $f14, $f0, $f20 (Delay Slot)
        ctx->f[14] = FPU_MUL_S(ctx->f[0], ctx->f[20]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x18FE60u;
    if (runtime->hasFunction(0x18FE60u)) {
        auto targetFn = runtime->lookupFunction(0x18FE60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193A4Cu; }
        if (ctx->pc != 0x193A4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018FE60_0x18fe60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193A4Cu; }
        if (ctx->pc != 0x193A4Cu) { return; }
    }
    ctx->pc = 0x193A4Cu;
label_193a4c:
    // 0x193a4c: 0xc063f7c  jal         func_18FDF0
    ctx->pc = 0x193A4Cu;
    SET_GPR_U32(ctx, 31, 0x193A54u);
    ctx->pc = 0x193A50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193A4Cu;
            // 0x193a50: 0x27a40080  addiu       $a0, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18FDF0u;
    if (runtime->hasFunction(0x18FDF0u)) {
        auto targetFn = runtime->lookupFunction(0x18FDF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193A54u; }
        if (ctx->pc != 0x193A54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018FDF0_0x18fdf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193A54u; }
        if (ctx->pc != 0x193A54u) { return; }
    }
    ctx->pc = 0x193A54u;
label_193a54:
    // 0x193a54: 0xc60c000c  lwc1        $f12, 0xC($s0)
    ctx->pc = 0x193a54u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x193a58: 0xc60d0010  lwc1        $f13, 0x10($s0)
    ctx->pc = 0x193a58u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[13] = f; }
    // 0x193a5c: 0xc60e0014  lwc1        $f14, 0x14($s0)
    ctx->pc = 0x193a5cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 20)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[14] = f; }
    // 0x193a60: 0xc064284  jal         func_190A10
    ctx->pc = 0x193A60u;
    SET_GPR_U32(ctx, 31, 0x193A68u);
    ctx->pc = 0x193A64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193A60u;
            // 0x193a64: 0x27a40080  addiu       $a0, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x190A10u;
    if (runtime->hasFunction(0x190A10u)) {
        auto targetFn = runtime->lookupFunction(0x190A10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193A68u; }
        if (ctx->pc != 0x193A68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00190A10_0x190a10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193A68u; }
        if (ctx->pc != 0x193A68u) { return; }
    }
    ctx->pc = 0x193A68u;
label_193a68:
    // 0x193a68: 0xc063f7c  jal         func_18FDF0
    ctx->pc = 0x193A68u;
    SET_GPR_U32(ctx, 31, 0x193A70u);
    ctx->pc = 0x193A6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193A68u;
            // 0x193a6c: 0x27a40040  addiu       $a0, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18FDF0u;
    if (runtime->hasFunction(0x18FDF0u)) {
        auto targetFn = runtime->lookupFunction(0x18FDF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193A70u; }
        if (ctx->pc != 0x193A70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018FDF0_0x18fdf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193A70u; }
        if (ctx->pc != 0x193A70u) { return; }
    }
    ctx->pc = 0x193A70u;
label_193a70:
    // 0x193a70: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x193a70u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x193a74: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x193a74u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193a78: 0x44821000  mtc1        $v0, $f2
    ctx->pc = 0x193a78u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x193a7c: 0x27a50080  addiu       $a1, $sp, 0x80
    ctx->pc = 0x193a7cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
    // 0x193a80: 0x46161003  div.s       $f0, $f2, $f22
    ctx->pc = 0x193a80u;
    if (ctx->f[22] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[2]) ^ std::bit_cast<uint32_t>(ctx->f[22])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[2] / ctx->f[22];
    // 0x193a84: 0xe7a00040  swc1        $f0, 0x40($sp)
    ctx->pc = 0x193a84u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 64), bits); }
    // 0x193a88: 0x46151043  div.s       $f1, $f2, $f21
    ctx->pc = 0x193a88u;
    if (ctx->f[21] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[2]) ^ std::bit_cast<uint32_t>(ctx->f[21])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[1] = std::bit_cast<float>(__maxf); } else ctx->f[1] = ctx->f[2] / ctx->f[21];
    // 0x193a8c: 0x46141003  div.s       $f0, $f2, $f20
    ctx->pc = 0x193a8cu;
    if (ctx->f[20] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[2]) ^ std::bit_cast<uint32_t>(ctx->f[20])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[2] / ctx->f[20];
    // 0x193a90: 0xe7a10054  swc1        $f1, 0x54($sp)
    ctx->pc = 0x193a90u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 84), bits); }
    // 0x193a94: 0xe7a00068  swc1        $f0, 0x68($sp)
    ctx->pc = 0x193a94u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 104), bits); }
    // 0x193a98: 0xc6000018  lwc1        $f0, 0x18($s0)
    ctx->pc = 0x193a98u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 24)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x193a9c: 0xe7a00070  swc1        $f0, 0x70($sp)
    ctx->pc = 0x193a9cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 112), bits); }
    // 0x193aa0: 0xc600001c  lwc1        $f0, 0x1C($s0)
    ctx->pc = 0x193aa0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 28)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x193aa4: 0xe7a00074  swc1        $f0, 0x74($sp)
    ctx->pc = 0x193aa4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 116), bits); }
    // 0x193aa8: 0xc6000020  lwc1        $f0, 0x20($s0)
    ctx->pc = 0x193aa8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 32)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x193aac: 0xc0644c0  jal         func_191300
    ctx->pc = 0x193AACu;
    SET_GPR_U32(ctx, 31, 0x193AB4u);
    ctx->pc = 0x193AB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193AACu;
            // 0x193ab0: 0xe7a00078  swc1        $f0, 0x78($sp) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 120), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x191300u;
    if (runtime->hasFunction(0x191300u)) {
        auto targetFn = runtime->lookupFunction(0x191300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193AB4u; }
        if (ctx->pc != 0x193AB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191300_0x191300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193AB4u; }
        if (ctx->pc != 0x193AB4u) { return; }
    }
    ctx->pc = 0x193AB4u;
label_193ab4:
    // 0x193ab4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x193ab4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193ab8: 0xc0644c0  jal         func_191300
    ctx->pc = 0x193AB8u;
    SET_GPR_U32(ctx, 31, 0x193AC0u);
    ctx->pc = 0x193ABCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193AB8u;
            // 0x193abc: 0x27a50040  addiu       $a1, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191300u;
    if (runtime->hasFunction(0x191300u)) {
        auto targetFn = runtime->lookupFunction(0x191300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193AC0u; }
        if (ctx->pc != 0x193AC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191300_0x191300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193AC0u; }
        if (ctx->pc != 0x193AC0u) { return; }
    }
    ctx->pc = 0x193AC0u;
label_193ac0:
    // 0x193ac0: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x193ac0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x193ac4: 0xc7b60008  lwc1        $f22, 0x8($sp)
    ctx->pc = 0x193ac4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[22] = f; }
    // 0x193ac8: 0x7bb10020  lq          $s1, 0x20($sp)
    ctx->pc = 0x193ac8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x193acc: 0xc7b50004  lwc1        $f21, 0x4($sp)
    ctx->pc = 0x193accu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[21] = f; }
    // 0x193ad0: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x193ad0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x193ad4: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x193ad4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x193ad8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x193ad8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x193adc: 0x3e00008  jr          $ra
    ctx->pc = 0x193ADCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x193AE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193ADCu;
            // 0x193ae0: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x193A4Cu: goto label_193a4c;
            case 0x193A54u: goto label_193a54;
            case 0x193A68u: goto label_193a68;
            case 0x193A70u: goto label_193a70;
            case 0x193AB4u: goto label_193ab4;
            case 0x193AC0u: goto label_193ac0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x193AE4u;
    // 0x193ae4: 0x0  nop
    ctx->pc = 0x193ae4u;
    // NOP
    // 0x193ae8: 0x0  nop
    ctx->pc = 0x193ae8u;
    // NOP
    // 0x193aec: 0x0  nop
    ctx->pc = 0x193aecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
