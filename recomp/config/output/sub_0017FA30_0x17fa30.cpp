#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017FA30
// Address: 0x17fa30 - 0x17fb34
void sub_0017FA30_0x17fa30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017FA30_0x17fa30");
#endif

    switch (ctx->pc) {
        case 0x17fab8u: goto label_17fab8;
        case 0x17fae0u: goto label_17fae0;
        case 0x17fb08u: goto label_17fb08;
        default: break;
    }

    ctx->pc = 0x17fa30u;

    // 0x17fa30: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x17fa30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x17fa34: 0x46008807  neg.s       $f0, $f17
    ctx->pc = 0x17fa34u;
    ctx->f[0] = FPU_NEG_S(ctx->f[17]);
    // 0x17fa38: 0xe7b40060  swc1        $f20, 0x60($sp)
    ctx->pc = 0x17fa38u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 96), bits); }
    // 0x17fa3c: 0x46009507  neg.s       $f20, $f18
    ctx->pc = 0x17fa3cu;
    ctx->f[20] = FPU_NEG_S(ctx->f[18]);
    // 0x17fa40: 0xc7a100a0  lwc1        $f1, 0xA0($sp)
    ctx->pc = 0x17fa40u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 160)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x17fa44: 0xe7b50068  swc1        $f21, 0x68($sp)
    ctx->pc = 0x17fa44u;
    { float f = ctx->f[21]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 104), bits); }
    // 0x17fa48: 0x46120000  add.s       $f0, $f0, $f18
    ctx->pc = 0x17fa48u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[18]);
    // 0x17fa4c: 0x46130d42  mul.s       $f21, $f1, $f19
    ctx->pc = 0x17fa4cu;
    ctx->f[21] = FPU_MUL_S(ctx->f[1], ctx->f[19]);
    // 0x17fa50: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x17fa50u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x17fa54: 0x4613a502  mul.s       $f20, $f20, $f19
    ctx->pc = 0x17fa54u;
    ctx->f[20] = FPU_MUL_S(ctx->f[20], ctx->f[19]);
    // 0x17fa58: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x17fa58u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17fa5c: 0x46018c42  mul.s       $f17, $f17, $f1
    ctx->pc = 0x17fa5cu;
    ctx->f[17] = FPU_MUL_S(ctx->f[17], ctx->f[1]);
    // 0x17fa60: 0xe7ba0090  swc1        $f26, 0x90($sp)
    ctx->pc = 0x17fa60u;
    { float f = ctx->f[26]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 144), bits); }
    // 0x17fa64: 0x46009cc7  neg.s       $f19, $f19
    ctx->pc = 0x17fa64u;
    ctx->f[19] = FPU_NEG_S(ctx->f[19]);
    // 0x17fa68: 0xe7b90088  swc1        $f25, 0x88($sp)
    ctx->pc = 0x17fa68u;
    { float f = ctx->f[25]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 136), bits); }
    // 0x17fa6c: 0x4600ad42  mul.s       $f21, $f21, $f0
    ctx->pc = 0x17fa6cu;
    ctx->f[21] = FPU_MUL_S(ctx->f[21], ctx->f[0]);
    // 0x17fa70: 0xe7b80080  swc1        $f24, 0x80($sp)
    ctx->pc = 0x17fa70u;
    { float f = ctx->f[24]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 128), bits); }
    // 0x17fa74: 0x4611a500  add.s       $f20, $f20, $f17
    ctx->pc = 0x17fa74u;
    ctx->f[20] = FPU_ADD_S(ctx->f[20], ctx->f[17]);
    // 0x17fa78: 0xe7b70078  swc1        $f23, 0x78($sp)
    ctx->pc = 0x17fa78u;
    { float f = ctx->f[23]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 120), bits); }
    // 0x17fa7c: 0x46019cc0  add.s       $f19, $f19, $f1
    ctx->pc = 0x17fa7cu;
    ctx->f[19] = FPU_ADD_S(ctx->f[19], ctx->f[1]);
    // 0x17fa80: 0xe7b60070  swc1        $f22, 0x70($sp)
    ctx->pc = 0x17fa80u;
    { float f = ctx->f[22]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 112), bits); }
    // 0x17fa84: 0x46006586  mov.s       $f22, $f12
    ctx->pc = 0x17fa84u;
    ctx->f[22] = FPU_MOV_S(ctx->f[12]);
    // 0x17fa88: 0x46006e06  mov.s       $f24, $f13
    ctx->pc = 0x17fa88u;
    ctx->f[24] = FPU_MOV_S(ctx->f[13]);
    // 0x17fa8c: 0x460075c6  mov.s       $f23, $f14
    ctx->pc = 0x17fa8cu;
    ctx->f[23] = FPU_MOV_S(ctx->f[14]);
    // 0x17fa90: 0x46007e86  mov.s       $f26, $f15
    ctx->pc = 0x17fa90u;
    ctx->f[26] = FPU_MOV_S(ctx->f[15]);
    // 0x17fa94: 0x0  nop
    ctx->pc = 0x17fa94u;
    // NOP
    // 0x17fa98: 0x0  nop
    ctx->pc = 0x17fa98u;
    // NOP
    // 0x17fa9c: 0x4613ad43  div.s       $f21, $f21, $f19
    ctx->pc = 0x17fa9cu;
    if (ctx->f[19] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[21]) ^ std::bit_cast<uint32_t>(ctx->f[19])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[21] = std::bit_cast<float>(__maxf); } else ctx->f[21] = ctx->f[21] / ctx->f[19];
    // 0x17faa0: 0x0  nop
    ctx->pc = 0x17faa0u;
    // NOP
    // 0x17faa4: 0x0  nop
    ctx->pc = 0x17faa4u;
    // NOP
    // 0x17faa8: 0x4613a503  div.s       $f20, $f20, $f19
    ctx->pc = 0x17faa8u;
    if (ctx->f[19] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[20]) ^ std::bit_cast<uint32_t>(ctx->f[19])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[20] = std::bit_cast<float>(__maxf); } else ctx->f[20] = ctx->f[20] / ctx->f[19];
    // 0x17faac: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x17faacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x17fab0: 0xc05fcf4  jal         func_17F3D0
    ctx->pc = 0x17FAB0u;
    SET_GPR_U32(ctx, 31, 0x17FAB8u);
    ctx->pc = 0x17FAB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17FAB0u;
            // 0x17fab4: 0x46008646  mov.s       $f25, $f16 (Delay Slot)
        ctx->f[25] = FPU_MOV_S(ctx->f[16]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x17F3D0u;
    if (runtime->hasFunction(0x17F3D0u)) {
        auto targetFn = runtime->lookupFunction(0x17F3D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FAB8u; }
        if (ctx->pc != 0x17FAB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017F3D0_0x17f3d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FAB8u; }
        if (ctx->pc != 0x17FAB8u) { return; }
    }
    ctx->pc = 0x17FAB8u;
label_17fab8:
    // 0x17fab8: 0x3c013f80  lui         $at, 0x3F80
    ctx->pc = 0x17fab8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16256 << 16));
    // 0x17fabc: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x17fabcu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x17fac0: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x17fac0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17fac4: 0xe6160014  swc1        $f22, 0x14($s0)
    ctx->pc = 0x17fac4u;
    { float f = ctx->f[22]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 20), bits); }
    // 0x17fac8: 0xe6160000  swc1        $f22, 0x0($s0)
    ctx->pc = 0x17fac8u;
    { float f = ctx->f[22]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 0), bits); }
    // 0x17facc: 0xae000028  sw          $zero, 0x28($s0)
    ctx->pc = 0x17faccu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 0));
    // 0x17fad0: 0xae00003c  sw          $zero, 0x3C($s0)
    ctx->pc = 0x17fad0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 0));
    // 0x17fad4: 0xe600002c  swc1        $f0, 0x2C($s0)
    ctx->pc = 0x17fad4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 44), bits); }
    // 0x17fad8: 0xc05fcf4  jal         func_17F3D0
    ctx->pc = 0x17FAD8u;
    SET_GPR_U32(ctx, 31, 0x17FAE0u);
    ctx->pc = 0x17FADCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17FAD8u;
            // 0x17fadc: 0xe6000038  swc1        $f0, 0x38($s0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 56), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x17F3D0u;
    if (runtime->hasFunction(0x17F3D0u)) {
        auto targetFn = runtime->lookupFunction(0x17F3D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FAE0u; }
        if (ctx->pc != 0x17FAE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017F3D0_0x17f3d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FAE0u; }
        if (ctx->pc != 0x17FAE0u) { return; }
    }
    ctx->pc = 0x17FAE0u;
label_17fae0:
    // 0x17fae0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17fae0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17fae4: 0xe7b80000  swc1        $f24, 0x0($sp)
    ctx->pc = 0x17fae4u;
    { float f = ctx->f[24]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x17fae8: 0xe7b70014  swc1        $f23, 0x14($sp)
    ctx->pc = 0x17fae8u;
    { float f = ctx->f[23]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 20), bits); }
    // 0x17faec: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x17faecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17faf0: 0xe7b50028  swc1        $f21, 0x28($sp)
    ctx->pc = 0x17faf0u;
    { float f = ctx->f[21]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 40), bits); }
    // 0x17faf4: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x17faf4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17faf8: 0xe7ba0030  swc1        $f26, 0x30($sp)
    ctx->pc = 0x17faf8u;
    { float f = ctx->f[26]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 48), bits); }
    // 0x17fafc: 0xe7b90034  swc1        $f25, 0x34($sp)
    ctx->pc = 0x17fafcu;
    { float f = ctx->f[25]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 52), bits); }
    // 0x17fb00: 0xc05faca  jal         func_17EB28
    ctx->pc = 0x17FB00u;
    SET_GPR_U32(ctx, 31, 0x17FB08u);
    ctx->pc = 0x17FB04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17FB00u;
            // 0x17fb04: 0xe7b40038  swc1        $f20, 0x38($sp) (Delay Slot)
        { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 56), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x17EB28u;
    if (runtime->hasFunction(0x17EB28u)) {
        auto targetFn = runtime->lookupFunction(0x17EB28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FB08u; }
        if (ctx->pc != 0x17FB08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017EB28_0x17eb28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17FB08u; }
        if (ctx->pc != 0x17FB08u) { return; }
    }
    ctx->pc = 0x17FB08u;
label_17fb08:
    // 0x17fb08: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x17fb08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x17fb0c: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x17fb0cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x17fb10: 0xc7ba0090  lwc1        $f26, 0x90($sp)
    ctx->pc = 0x17fb10u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 144)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[26] = f; }
    // 0x17fb14: 0xc7b90088  lwc1        $f25, 0x88($sp)
    ctx->pc = 0x17fb14u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 136)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[25] = f; }
    // 0x17fb18: 0xc7b80080  lwc1        $f24, 0x80($sp)
    ctx->pc = 0x17fb18u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 128)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[24] = f; }
    // 0x17fb1c: 0xc7b70078  lwc1        $f23, 0x78($sp)
    ctx->pc = 0x17fb1cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 120)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[23] = f; }
    // 0x17fb20: 0xc7b60070  lwc1        $f22, 0x70($sp)
    ctx->pc = 0x17fb20u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 112)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[22] = f; }
    // 0x17fb24: 0xc7b50068  lwc1        $f21, 0x68($sp)
    ctx->pc = 0x17fb24u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 104)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[21] = f; }
    // 0x17fb28: 0xc7b40060  lwc1        $f20, 0x60($sp)
    ctx->pc = 0x17fb28u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 96)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x17fb2c: 0x3e00008  jr          $ra
    ctx->pc = 0x17FB2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17FB30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17FB2Cu;
            // 0x17fb30: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17FAB8u: goto label_17fab8;
            case 0x17FAE0u: goto label_17fae0;
            case 0x17FB08u: goto label_17fb08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17FB34u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
