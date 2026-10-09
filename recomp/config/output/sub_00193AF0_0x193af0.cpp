#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00193AF0
// Address: 0x193af0 - 0x193bd0
void sub_00193AF0_0x193af0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00193AF0_0x193af0");
#endif

    switch (ctx->pc) {
        case 0x193b30u: goto label_193b30;
        case 0x193b38u: goto label_193b38;
        case 0x193b4cu: goto label_193b4c;
        case 0x193b54u: goto label_193b54;
        case 0x193b98u: goto label_193b98;
        case 0x193ba4u: goto label_193ba4;
        default: break;
    }

    ctx->pc = 0x193af0u;

    // 0x193af0: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x193af0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x193af4: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x193af4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x193af8: 0x7fb10020  sq          $s1, 0x20($sp)
    ctx->pc = 0x193af8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 17));
    // 0x193afc: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x193afcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x193b00: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x193b00u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193b04: 0xe7b60008  swc1        $f22, 0x8($sp)
    ctx->pc = 0x193b04u;
    { float f = ctx->f[22]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 8), bits); }
    // 0x193b08: 0xe7b50004  swc1        $f21, 0x4($sp)
    ctx->pc = 0x193b08u;
    { float f = ctx->f[21]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 4), bits); }
    // 0x193b0c: 0xe7b40000  swc1        $f20, 0x0($sp)
    ctx->pc = 0x193b0cu;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x193b10: 0x46006586  mov.s       $f22, $f12
    ctx->pc = 0x193b10u;
    ctx->f[22] = FPU_MOV_S(ctx->f[12]);
    // 0x193b14: 0x46006d46  mov.s       $f21, $f13
    ctx->pc = 0x193b14u;
    ctx->f[21] = FPU_MOV_S(ctx->f[13]);
    // 0x193b18: 0x46007506  mov.s       $f20, $f14
    ctx->pc = 0x193b18u;
    ctx->f[20] = FPU_MOV_S(ctx->f[14]);
    // 0x193b1c: 0xc4ac0000  lwc1        $f12, 0x0($a1)
    ctx->pc = 0x193b1cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x193b20: 0xc4ad0004  lwc1        $f13, 0x4($a1)
    ctx->pc = 0x193b20u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[13] = f; }
    // 0x193b24: 0xc4ae0008  lwc1        $f14, 0x8($a1)
    ctx->pc = 0x193b24u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[14] = f; }
    // 0x193b28: 0xc063f98  jal         func_18FE60
    ctx->pc = 0x193B28u;
    SET_GPR_U32(ctx, 31, 0x193B30u);
    ctx->pc = 0x193B2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193B28u;
            // 0x193b2c: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18FE60u;
    if (runtime->hasFunction(0x18FE60u)) {
        auto targetFn = runtime->lookupFunction(0x18FE60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193B30u; }
        if (ctx->pc != 0x193B30u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018FE60_0x18fe60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193B30u; }
        if (ctx->pc != 0x193B30u) { return; }
    }
    ctx->pc = 0x193B30u;
label_193b30:
    // 0x193b30: 0xc063f7c  jal         func_18FDF0
    ctx->pc = 0x193B30u;
    SET_GPR_U32(ctx, 31, 0x193B38u);
    ctx->pc = 0x193B34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193B30u;
            // 0x193b34: 0x27a40080  addiu       $a0, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18FDF0u;
    if (runtime->hasFunction(0x18FDF0u)) {
        auto targetFn = runtime->lookupFunction(0x18FDF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193B38u; }
        if (ctx->pc != 0x193B38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018FDF0_0x18fdf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193B38u; }
        if (ctx->pc != 0x193B38u) { return; }
    }
    ctx->pc = 0x193B38u;
label_193b38:
    // 0x193b38: 0xc60c000c  lwc1        $f12, 0xC($s0)
    ctx->pc = 0x193b38u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x193b3c: 0xc60d0010  lwc1        $f13, 0x10($s0)
    ctx->pc = 0x193b3cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[13] = f; }
    // 0x193b40: 0xc60e0014  lwc1        $f14, 0x14($s0)
    ctx->pc = 0x193b40u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 20)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[14] = f; }
    // 0x193b44: 0xc064284  jal         func_190A10
    ctx->pc = 0x193B44u;
    SET_GPR_U32(ctx, 31, 0x193B4Cu);
    ctx->pc = 0x193B48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193B44u;
            // 0x193b48: 0x27a40080  addiu       $a0, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x190A10u;
    if (runtime->hasFunction(0x190A10u)) {
        auto targetFn = runtime->lookupFunction(0x190A10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193B4Cu; }
        if (ctx->pc != 0x193B4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00190A10_0x190a10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193B4Cu; }
        if (ctx->pc != 0x193B4Cu) { return; }
    }
    ctx->pc = 0x193B4Cu;
label_193b4c:
    // 0x193b4c: 0xc063f7c  jal         func_18FDF0
    ctx->pc = 0x193B4Cu;
    SET_GPR_U32(ctx, 31, 0x193B54u);
    ctx->pc = 0x193B50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193B4Cu;
            // 0x193b50: 0x27a40040  addiu       $a0, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18FDF0u;
    if (runtime->hasFunction(0x18FDF0u)) {
        auto targetFn = runtime->lookupFunction(0x18FDF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193B54u; }
        if (ctx->pc != 0x193B54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018FDF0_0x18fdf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193B54u; }
        if (ctx->pc != 0x193B54u) { return; }
    }
    ctx->pc = 0x193B54u;
label_193b54:
    // 0x193b54: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x193b54u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x193b58: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x193b58u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193b5c: 0x44821000  mtc1        $v0, $f2
    ctx->pc = 0x193b5cu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x193b60: 0x27a50080  addiu       $a1, $sp, 0x80
    ctx->pc = 0x193b60u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
    // 0x193b64: 0x46161003  div.s       $f0, $f2, $f22
    ctx->pc = 0x193b64u;
    if (ctx->f[22] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[2]) ^ std::bit_cast<uint32_t>(ctx->f[22])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[2] / ctx->f[22];
    // 0x193b68: 0xe7a00040  swc1        $f0, 0x40($sp)
    ctx->pc = 0x193b68u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 64), bits); }
    // 0x193b6c: 0x46151043  div.s       $f1, $f2, $f21
    ctx->pc = 0x193b6cu;
    if (ctx->f[21] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[2]) ^ std::bit_cast<uint32_t>(ctx->f[21])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[1] = std::bit_cast<float>(__maxf); } else ctx->f[1] = ctx->f[2] / ctx->f[21];
    // 0x193b70: 0x46141003  div.s       $f0, $f2, $f20
    ctx->pc = 0x193b70u;
    if (ctx->f[20] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[2]) ^ std::bit_cast<uint32_t>(ctx->f[20])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[2] / ctx->f[20];
    // 0x193b74: 0xe7a10054  swc1        $f1, 0x54($sp)
    ctx->pc = 0x193b74u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 84), bits); }
    // 0x193b78: 0xe7a00068  swc1        $f0, 0x68($sp)
    ctx->pc = 0x193b78u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 104), bits); }
    // 0x193b7c: 0xc6000018  lwc1        $f0, 0x18($s0)
    ctx->pc = 0x193b7cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 24)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x193b80: 0xe7a00070  swc1        $f0, 0x70($sp)
    ctx->pc = 0x193b80u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 112), bits); }
    // 0x193b84: 0xc600001c  lwc1        $f0, 0x1C($s0)
    ctx->pc = 0x193b84u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 28)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x193b88: 0xe7a00074  swc1        $f0, 0x74($sp)
    ctx->pc = 0x193b88u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 116), bits); }
    // 0x193b8c: 0xc6000020  lwc1        $f0, 0x20($s0)
    ctx->pc = 0x193b8cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 32)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x193b90: 0xc0644c0  jal         func_191300
    ctx->pc = 0x193B90u;
    SET_GPR_U32(ctx, 31, 0x193B98u);
    ctx->pc = 0x193B94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193B90u;
            // 0x193b94: 0xe7a00078  swc1        $f0, 0x78($sp) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 120), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x191300u;
    if (runtime->hasFunction(0x191300u)) {
        auto targetFn = runtime->lookupFunction(0x191300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193B98u; }
        if (ctx->pc != 0x193B98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191300_0x191300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193B98u; }
        if (ctx->pc != 0x193B98u) { return; }
    }
    ctx->pc = 0x193B98u;
label_193b98:
    // 0x193b98: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x193b98u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193b9c: 0xc0644c0  jal         func_191300
    ctx->pc = 0x193B9Cu;
    SET_GPR_U32(ctx, 31, 0x193BA4u);
    ctx->pc = 0x193BA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193B9Cu;
            // 0x193ba0: 0x27a50040  addiu       $a1, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191300u;
    if (runtime->hasFunction(0x191300u)) {
        auto targetFn = runtime->lookupFunction(0x191300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193BA4u; }
        if (ctx->pc != 0x193BA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191300_0x191300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193BA4u; }
        if (ctx->pc != 0x193BA4u) { return; }
    }
    ctx->pc = 0x193BA4u;
label_193ba4:
    // 0x193ba4: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x193ba4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x193ba8: 0xc7b60008  lwc1        $f22, 0x8($sp)
    ctx->pc = 0x193ba8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[22] = f; }
    // 0x193bac: 0x7bb10020  lq          $s1, 0x20($sp)
    ctx->pc = 0x193bacu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x193bb0: 0xc7b50004  lwc1        $f21, 0x4($sp)
    ctx->pc = 0x193bb0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[21] = f; }
    // 0x193bb4: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x193bb4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x193bb8: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x193bb8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x193bbc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x193bbcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x193bc0: 0x3e00008  jr          $ra
    ctx->pc = 0x193BC0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x193BC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193BC0u;
            // 0x193bc4: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x193B30u: goto label_193b30;
            case 0x193B38u: goto label_193b38;
            case 0x193B4Cu: goto label_193b4c;
            case 0x193B54u: goto label_193b54;
            case 0x193B98u: goto label_193b98;
            case 0x193BA4u: goto label_193ba4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x193BC8u;
    // 0x193bc8: 0x0  nop
    ctx->pc = 0x193bc8u;
    // NOP
    // 0x193bcc: 0x0  nop
    ctx->pc = 0x193bccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
