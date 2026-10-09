#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F7580
// Address: 0x1f7580 - 0x1f7590
void sub_001F7580_0x1f7580(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F7580_0x1f7580");
#endif

    ctx->pc = 0x1f7580u;

    // 0x1f7580: 0x600000cf  daddi       $zero, $zero, 0xCF
    ctx->pc = 0x1f7580u;
    { int64_t src = (int64_t)GPR_S64(ctx, 0); int64_t imm = (int64_t)(int32_t)207; int64_t res = src + imm; if (((src ^ imm) >= 0) && ((src ^ res) < 0))     runtime->SignalException(ctx, EXCEPTION_INTEGER_OVERFLOW); else SET_GPR_S64(ctx, 0, res); }
    // 0x1f7584: 0x0  nop
    ctx->pc = 0x1f7584u;
    // NOP
    // 0x1f7588: 0x0  nop
    ctx->pc = 0x1f7588u;
    // NOP
    // 0x1f758c: 0x4a000000  vaddx       $vf0, $vf0, $vf0x
    ctx->pc = 0x1f758cu;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], _mm_shuffle_ps(ctx->vu0_vf[0], ctx->vu0_vf[0], _MM_SHUFFLE(0,0,0,0))); __m128i mask = _mm_set_epi32(0, 0, 0, 0); ctx->vu0_vf[0] = _mm_blendv_ps(ctx->vu0_vf[0], res, _mm_castsi128_ps(mask)); }
    ctx->pc = GPR_U32(ctx, 31); return;
}
