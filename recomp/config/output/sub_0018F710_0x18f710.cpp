#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018F710
// Address: 0x18f710 - 0x18f7e0
void sub_0018F710_0x18f710(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018F710_0x18f710");
#endif

    switch (ctx->pc) {
        case 0x18f754u: goto label_18f754;
        case 0x18f75cu: goto label_18f75c;
        default: break;
    }

    ctx->pc = 0x18f710u;

    // 0x18f710: 0x3c023f00  lui         $v0, 0x3F00
    ctx->pc = 0x18f710u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16128 << 16));
    // 0x18f714: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x18f714u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x18f718: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x18f718u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18f71c: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x18f71cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x18f720: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x18f720u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x18f724: 0x27a5003c  addiu       $a1, $sp, 0x3C
    ctx->pc = 0x18f724u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 60));
    // 0x18f728: 0x46007382  mul.s       $f14, $f14, $f0
    ctx->pc = 0x18f728u;
    ctx->f[14] = FPU_MUL_S(ctx->f[14], ctx->f[0]);
    // 0x18f72c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x18f72cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18f730: 0x27a40038  addiu       $a0, $sp, 0x38
    ctx->pc = 0x18f730u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
    // 0x18f734: 0xe7b60008  swc1        $f22, 0x8($sp)
    ctx->pc = 0x18f734u;
    { float f = ctx->f[22]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 8), bits); }
    // 0x18f738: 0xe7b50004  swc1        $f21, 0x4($sp)
    ctx->pc = 0x18f738u;
    { float f = ctx->f[21]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 4), bits); }
    // 0x18f73c: 0xe7b40000  swc1        $f20, 0x0($sp)
    ctx->pc = 0x18f73cu;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x18f740: 0x46006586  mov.s       $f22, $f12
    ctx->pc = 0x18f740u;
    ctx->f[22] = FPU_MOV_S(ctx->f[12]);
    // 0x18f744: 0x46006d06  mov.s       $f20, $f13
    ctx->pc = 0x18f744u;
    ctx->f[20] = FPU_MOV_S(ctx->f[13]);
    // 0x18f748: 0x46007d46  mov.s       $f21, $f15
    ctx->pc = 0x18f748u;
    ctx->f[21] = FPU_MOV_S(ctx->f[15]);
    // 0x18f74c: 0xc06486c  jal         func_1921B0
    ctx->pc = 0x18F74Cu;
    SET_GPR_U32(ctx, 31, 0x18F754u);
    ctx->pc = 0x18F750u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18F74Cu;
            // 0x18f750: 0x46007306  mov.s       $f12, $f14 (Delay Slot)
        ctx->f[12] = FPU_MOV_S(ctx->f[14]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1921B0u;
    if (runtime->hasFunction(0x1921B0u)) {
        auto targetFn = runtime->lookupFunction(0x1921B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18F754u; }
        if (ctx->pc != 0x18F754u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001921B0_0x1921b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18F754u; }
        if (ctx->pc != 0x18F754u) { return; }
    }
    ctx->pc = 0x18F754u;
label_18f754:
    // 0x18f754: 0xc063f7c  jal         func_18FDF0
    ctx->pc = 0x18F754u;
    SET_GPR_U32(ctx, 31, 0x18F75Cu);
    ctx->pc = 0x18F758u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18F754u;
            // 0x18f758: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18FDF0u;
    if (runtime->hasFunction(0x18FDF0u)) {
        auto targetFn = runtime->lookupFunction(0x18FDF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18F75Cu; }
        if (ctx->pc != 0x18F75Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018FDF0_0x18fdf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18F75Cu; }
        if (ctx->pc != 0x18F75Cu) { return; }
    }
    ctx->pc = 0x18F75Cu;
label_18f75c:
    // 0x18f75c: 0xc7a3003c  lwc1        $f3, 0x3C($sp)
    ctx->pc = 0x18f75cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 60)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x18f760: 0x3c034000  lui         $v1, 0x4000
    ctx->pc = 0x18f760u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16384 << 16));
    // 0x18f764: 0xc7a20038  lwc1        $f2, 0x38($sp)
    ctx->pc = 0x18f764u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 56)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x18f768: 0x3c04bf80  lui         $a0, 0xBF80
    ctx->pc = 0x18f768u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49024 << 16));
    // 0x18f76c: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x18f76cu;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x18f770: 0x4614b040  add.s       $f1, $f22, $f20
    ctx->pc = 0x18f770u;
    ctx->f[1] = FPU_ADD_S(ctx->f[22], ctx->f[20]);
    // 0x18f774: 0x46021883  div.s       $f2, $f3, $f2
    ctx->pc = 0x18f774u;
    if (ctx->f[2] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[3]) ^ std::bit_cast<uint32_t>(ctx->f[2])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[2] = std::bit_cast<float>(__maxf); } else ctx->f[2] = ctx->f[3] / ctx->f[2];
    // 0x18f778: 0x46151083  div.s       $f2, $f2, $f21
    ctx->pc = 0x18f778u;
    if (ctx->f[21] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[2]) ^ std::bit_cast<uint32_t>(ctx->f[21])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[2] = std::bit_cast<float>(__maxf); } else ctx->f[2] = ctx->f[2] / ctx->f[21];
    // 0x18f77c: 0xe6020000  swc1        $f2, 0x0($s0)
    ctx->pc = 0x18f77cu;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 0), bits); }
    // 0x18f780: 0x46160002  mul.s       $f0, $f0, $f22
    ctx->pc = 0x18f780u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[22]);
    // 0x18f784: 0x46140002  mul.s       $f0, $f0, $f20
    ctx->pc = 0x18f784u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[20]);
    // 0x18f788: 0xc7a3003c  lwc1        $f3, 0x3C($sp)
    ctx->pc = 0x18f788u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 60)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x18f78c: 0xc7a20038  lwc1        $f2, 0x38($sp)
    ctx->pc = 0x18f78cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 56)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x18f790: 0x4614b101  sub.s       $f4, $f22, $f20
    ctx->pc = 0x18f790u;
    ctx->f[4] = FPU_SUB_S(ctx->f[22], ctx->f[20]);
    // 0x18f794: 0x46000847  neg.s       $f1, $f1
    ctx->pc = 0x18f794u;
    ctx->f[1] = FPU_NEG_S(ctx->f[1]);
    // 0x18f798: 0x46021883  div.s       $f2, $f3, $f2
    ctx->pc = 0x18f798u;
    if (ctx->f[2] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[3]) ^ std::bit_cast<uint32_t>(ctx->f[2])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[2] = std::bit_cast<float>(__maxf); } else ctx->f[2] = ctx->f[3] / ctx->f[2];
    // 0x18f79c: 0x46000007  neg.s       $f0, $f0
    ctx->pc = 0x18f79cu;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x18f7a0: 0x46040843  div.s       $f1, $f1, $f4
    ctx->pc = 0x18f7a0u;
    if (ctx->f[4] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[4])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[1] = std::bit_cast<float>(__maxf); } else ctx->f[1] = ctx->f[1] / ctx->f[4];
    // 0x18f7a4: 0xe6020014  swc1        $f2, 0x14($s0)
    ctx->pc = 0x18f7a4u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 20), bits); }
    // 0x18f7a8: 0xe6010028  swc1        $f1, 0x28($s0)
    ctx->pc = 0x18f7a8u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 40), bits); }
    // 0x18f7ac: 0x46040003  div.s       $f0, $f0, $f4
    ctx->pc = 0x18f7acu;
    if (ctx->f[4] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[0]) ^ std::bit_cast<uint32_t>(ctx->f[4])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[0] / ctx->f[4];
    // 0x18f7b0: 0xae04002c  sw          $a0, 0x2C($s0)
    ctx->pc = 0x18f7b0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 4));
    // 0x18f7b4: 0xe6000038  swc1        $f0, 0x38($s0)
    ctx->pc = 0x18f7b4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 56), bits); }
    // 0x18f7b8: 0xae00003c  sw          $zero, 0x3C($s0)
    ctx->pc = 0x18f7b8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 0));
    // 0x18f7bc: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x18f7bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x18f7c0: 0xc7b60008  lwc1        $f22, 0x8($sp)
    ctx->pc = 0x18f7c0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[22] = f; }
    // 0x18f7c4: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x18f7c4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18f7c8: 0xc7b50004  lwc1        $f21, 0x4($sp)
    ctx->pc = 0x18f7c8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[21] = f; }
    // 0x18f7cc: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x18f7ccu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x18f7d0: 0x3e00008  jr          $ra
    ctx->pc = 0x18F7D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18F7D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18F7D0u;
            // 0x18f7d4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18F754u: goto label_18f754;
            case 0x18F75Cu: goto label_18f75c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18F7D8u;
    // 0x18f7d8: 0x0  nop
    ctx->pc = 0x18f7d8u;
    // NOP
    // 0x18f7dc: 0x0  nop
    ctx->pc = 0x18f7dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
