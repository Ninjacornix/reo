#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A51B0
// Address: 0x1a51b0 - 0x1a5220
void sub_001A51B0_0x1a51b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A51B0_0x1a51b0");
#endif

    switch (ctx->pc) {
        case 0x1a51c4u: goto label_1a51c4;
        default: break;
    }

    ctx->pc = 0x1a51b0u;

    // 0x1a51b0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1a51b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1a51b4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1a51b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1a51b8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1a51b8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1a51bc: 0xc069460  jal         func_1A5180
    ctx->pc = 0x1A51BCu;
    SET_GPR_U32(ctx, 31, 0x1A51C4u);
    ctx->pc = 0x1A51C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A51BCu;
            // 0x1a51c0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A5180u;
    if (runtime->hasFunction(0x1A5180u)) {
        auto targetFn = runtime->lookupFunction(0x1A5180u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A51C4u; }
        if (ctx->pc != 0x1A51C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A5180_0x1a5180(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A51C4u; }
        if (ctx->pc != 0x1A51C4u) { return; }
    }
    ctx->pc = 0x1A51C4u;
label_1a51c4:
    // 0x1a51c4: 0x44800800  mtc1        $zero, $f1
    ctx->pc = 0x1a51c4u;
    { uint32_t bits = GPR_U32(ctx, 0); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1a51c8: 0x0  nop
    ctx->pc = 0x1a51c8u;
    // NOP
    // 0x1a51cc: 0x46000832  c.eq.s      $f1, $f0
    ctx->pc = 0x1a51ccu;
    ctx->fcr31 = (FPU_C_EQ_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1a51d0: 0x45000005  bc1f        . + 4 + (0x5 << 2)
    ctx->pc = 0x1A51D0u;
    {
        const bool branch_taken_0x1a51d0 = (!(ctx->fcr31 & 0x800000));
        if (branch_taken_0x1a51d0) {
            ctx->pc = 0x1A51E8u;
            goto label_1a51e8;
        }
    }
    ctx->pc = 0x1A51D8u;
    // 0x1a51d8: 0xe6010008  swc1        $f1, 0x8($s0)
    ctx->pc = 0x1a51d8u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 8), bits); }
    // 0x1a51dc: 0xe6010004  swc1        $f1, 0x4($s0)
    ctx->pc = 0x1a51dcu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 4), bits); }
    // 0x1a51e0: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1A51E0u;
    {
        const bool branch_taken_0x1a51e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A51E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A51E0u;
            // 0x1a51e4: 0xe6010000  swc1        $f1, 0x0($s0) (Delay Slot)
        { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 0), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a51e0) {
            ctx->pc = 0x1A5210u;
            goto label_1a5210;
        }
    }
    ctx->pc = 0x1A51E8u;
label_1a51e8:
    // 0x1a51e8: 0xc6010000  lwc1        $f1, 0x0($s0)
    ctx->pc = 0x1a51e8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1a51ec: 0x0  nop
    ctx->pc = 0x1a51ecu;
    // NOP
    // 0x1a51f0: 0x46000843  div.s       $f1, $f1, $f0
    ctx->pc = 0x1a51f0u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[1] = std::bit_cast<float>(__maxf); } else ctx->f[1] = ctx->f[1] / ctx->f[0];
    // 0x1a51f4: 0xe6010000  swc1        $f1, 0x0($s0)
    ctx->pc = 0x1a51f4u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 0), bits); }
    // 0x1a51f8: 0xc6010004  lwc1        $f1, 0x4($s0)
    ctx->pc = 0x1a51f8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1a51fc: 0x46000843  div.s       $f1, $f1, $f0
    ctx->pc = 0x1a51fcu;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[1] = std::bit_cast<float>(__maxf); } else ctx->f[1] = ctx->f[1] / ctx->f[0];
    // 0x1a5200: 0xe6010004  swc1        $f1, 0x4($s0)
    ctx->pc = 0x1a5200u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 4), bits); }
    // 0x1a5204: 0xc6010008  lwc1        $f1, 0x8($s0)
    ctx->pc = 0x1a5204u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 16), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1a5208: 0x46000803  div.s       $f0, $f1, $f0
    ctx->pc = 0x1a5208u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[1] / ctx->f[0];
    // 0x1a520c: 0xe6000008  swc1        $f0, 0x8($s0)
    ctx->pc = 0x1a520cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 8), bits); }
label_1a5210:
    // 0x1a5210: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1a5210u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a5214: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a5214u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a5218: 0x3e00008  jr          $ra
    ctx->pc = 0x1A5218u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A521Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5218u;
            // 0x1a521c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A51C4u: goto label_1a51c4;
            case 0x1A51E8u: goto label_1a51e8;
            case 0x1A5210u: goto label_1a5210;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A5220u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
