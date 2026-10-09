#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018F7E0
// Address: 0x18f7e0 - 0x18f880
void sub_0018F7E0_0x18f7e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018F7E0_0x18f7e0");
#endif

    switch (ctx->pc) {
        case 0x18f7f8u: goto label_18f7f8;
        default: break;
    }

    ctx->pc = 0x18f7e0u;

    // 0x18f7e0: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x18f7e0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18f7e4: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x18f7e4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x18f7e8: 0x3c040029  lui         $a0, 0x29
    ctx->pc = 0x18f7e8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)41 << 16));
    // 0x18f7ec: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x18f7ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x18f7f0: 0xc064540  jal         func_191500
    ctx->pc = 0x18F7F0u;
    SET_GPR_U32(ctx, 31, 0x18F7F8u);
    ctx->pc = 0x18F7F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18F7F0u;
            // 0x18f7f4: 0x24844d00  addiu       $a0, $a0, 0x4D00 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19712));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191500u;
    if (runtime->hasFunction(0x191500u)) {
        auto targetFn = runtime->lookupFunction(0x191500u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18F7F8u; }
        if (ctx->pc != 0x18F7F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191500_0x191500(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18F7F8u; }
        if (ctx->pc != 0x18F7F8u) { return; }
    }
    ctx->pc = 0x18F7F8u;
label_18f7f8:
    // 0x18f7f8: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18f7f8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18f7fc: 0x3c033f00  lui         $v1, 0x3F00
    ctx->pc = 0x18f7fcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16128 << 16));
    // 0x18f800: 0xc42641d0  lwc1        $f6, 0x41D0($at)
    ctx->pc = 0x18f800u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[6] = f; }
    // 0x18f804: 0x44833800  mtc1        $v1, $f7
    ctx->pc = 0x18f804u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[7], &bits, sizeof(bits)); }
    // 0x18f808: 0x3c034000  lui         $v1, 0x4000
    ctx->pc = 0x18f808u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16384 << 16));
    // 0x18f80c: 0x44832000  mtc1        $v1, $f4
    ctx->pc = 0x18f80cu;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[4], &bits, sizeof(bits)); }
    // 0x18f810: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18f810u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18f814: 0xc42541b0  lwc1        $f5, 0x41B0($at)
    ctx->pc = 0x18f814u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16816)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[5] = f; }
    // 0x18f818: 0x46063982  mul.s       $f6, $f7, $f6
    ctx->pc = 0x18f818u;
    ctx->f[6] = FPU_MUL_S(ctx->f[7], ctx->f[6]);
    // 0x18f81c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18f81cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18f820: 0xc4234d00  lwc1        $f3, 0x4D00($at)
    ctx->pc = 0x18f820u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 19712)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x18f824: 0x46062943  div.s       $f5, $f5, $f6
    ctx->pc = 0x18f824u;
    if (ctx->f[6] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[5]) ^ std::bit_cast<uint32_t>(ctx->f[6])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[5] = std::bit_cast<float>(__maxf); } else ctx->f[5] = ctx->f[5] / ctx->f[6];
    // 0x18f828: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18f828u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18f82c: 0xc42241c8  lwc1        $f2, 0x41C8($at)
    ctx->pc = 0x18f82cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16840)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x18f830: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18f830u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18f834: 0xc42141a8  lwc1        $f1, 0x41A8($at)
    ctx->pc = 0x18f834u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16808)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x18f838: 0x46023882  mul.s       $f2, $f7, $f2
    ctx->pc = 0x18f838u;
    ctx->f[2] = FPU_MUL_S(ctx->f[7], ctx->f[2]);
    // 0x18f83c: 0x46020843  div.s       $f1, $f1, $f2
    ctx->pc = 0x18f83cu;
    if (ctx->f[2] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[2])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[1] = std::bit_cast<float>(__maxf); } else ctx->f[1] = ctx->f[1] / ctx->f[2];
    // 0x18f840: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18f840u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18f844: 0xc4204d14  lwc1        $f0, 0x4D14($at)
    ctx->pc = 0x18f844u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 19732)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18f848: 0x46032082  mul.s       $f2, $f4, $f3
    ctx->pc = 0x18f848u;
    ctx->f[2] = FPU_MUL_S(ctx->f[4], ctx->f[3]);
    // 0x18f84c: 0x46002002  mul.s       $f0, $f4, $f0
    ctx->pc = 0x18f84cu;
    ctx->f[0] = FPU_MUL_S(ctx->f[4], ctx->f[0]);
    // 0x18f850: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18f850u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18f854: 0x46051083  div.s       $f2, $f2, $f5
    ctx->pc = 0x18f854u;
    if (ctx->f[5] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[2]) ^ std::bit_cast<uint32_t>(ctx->f[5])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[2] = std::bit_cast<float>(__maxf); } else ctx->f[2] = ctx->f[2] / ctx->f[5];
    // 0x18f858: 0xe4224d00  swc1        $f2, 0x4D00($at)
    ctx->pc = 0x18f858u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 19712), bits); }
    // 0x18f85c: 0x46010003  div.s       $f0, $f0, $f1
    ctx->pc = 0x18f85cu;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[0]) ^ std::bit_cast<uint32_t>(ctx->f[1])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[0] / ctx->f[1];
    // 0x18f860: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18f860u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18f864: 0xe4204d14  swc1        $f0, 0x4D14($at)
    ctx->pc = 0x18f864u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 19732), bits); }
    // 0x18f868: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x18f868u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x18f86c: 0x3e00008  jr          $ra
    ctx->pc = 0x18F86Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18F870u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18F86Cu;
            // 0x18f870: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18F7F8u: goto label_18f7f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18F874u;
    // 0x18f874: 0x0  nop
    ctx->pc = 0x18f874u;
    // NOP
    // 0x18f878: 0x0  nop
    ctx->pc = 0x18f878u;
    // NOP
    // 0x18f87c: 0x0  nop
    ctx->pc = 0x18f87cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
