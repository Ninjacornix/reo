#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B8780
// Address: 0x1b8780 - 0x1b87c0
void sub_001B8780_0x1b8780(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B8780_0x1b8780");
#endif

    ctx->pc = 0x1b8780u;

    // 0x1b8780: 0x44841000  mtc1        $a0, $f2
    ctx->pc = 0x1b8780u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x1b8784: 0x3c0240e0  lui         $v0, 0x40E0
    ctx->pc = 0x1b8784u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16608 << 16));
    // 0x1b8788: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x1b8788u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1b878c: 0x468010a0  cvt.s.w     $f2, $f2
    ctx->pc = 0x1b878cu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[2], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x1b8790: 0x3c0242fe  lui         $v0, 0x42FE
    ctx->pc = 0x1b8790u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17150 << 16));
    // 0x1b8794: 0x46011043  div.s       $f1, $f2, $f1
    ctx->pc = 0x1b8794u;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[2]) ^ std::bit_cast<uint32_t>(ctx->f[1])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[1] = std::bit_cast<float>(__maxf); } else ctx->f[1] = ctx->f[2] / ctx->f[1];
    // 0x1b8798: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1b8798u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1b879c: 0x0  nop
    ctx->pc = 0x1b879cu;
    // NOP
    // 0x1b87a0: 0x46010002  mul.s       $f0, $f0, $f1
    ctx->pc = 0x1b87a0u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[1]);
    // 0x1b87a4: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1b87a4u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1b87a8: 0x44050000  mfc1        $a1, $f0
    ctx->pc = 0x1b87a8u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 5, bits); }
    // 0x1b87ac: 0x0  nop
    ctx->pc = 0x1b87acu;
    // NOP
    // 0x1b87b0: 0x806b830  j           func_1AE0C0
    ctx->pc = 0x1B87B0u;
    ctx->pc = 0x1B87B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B87B0u;
            // 0x1b87b4: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AE0C0u;
    if (runtime->hasFunction(0x1AE0C0u)) {
        auto targetFn = runtime->lookupFunction(0x1AE0C0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001AE0C0_0x1ae0c0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1B87B8u;
    // 0x1b87b8: 0x0  nop
    ctx->pc = 0x1b87b8u;
    // NOP
    // 0x1b87bc: 0x0  nop
    ctx->pc = 0x1b87bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
