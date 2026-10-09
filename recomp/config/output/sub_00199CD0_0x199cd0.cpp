#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00199CD0
// Address: 0x199cd0 - 0x199d00
void sub_00199CD0_0x199cd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00199CD0_0x199cd0");
#endif

    ctx->pc = 0x199cd0u;

    // 0x199cd0: 0x3c037000  lui         $v1, 0x7000
    ctx->pc = 0x199cd0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28672 << 16));
    // 0x199cd4: 0x34633fc0  ori         $v1, $v1, 0x3FC0
    ctx->pc = 0x199cd4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)16320);
    // 0x199cd8: 0xd8640000  lqc2        $vf4, 0x0($v1)
    ctx->pc = 0x199cd8u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x199cdc: 0xd8650010  lqc2        $vf5, 0x10($v1)
    ctx->pc = 0x199cdcu;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x199ce0: 0xd8660030  lqc2        $vf6, 0x30($v1)
    ctx->pc = 0x199ce0u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 48)));
    // 0x199ce4: 0xf8840000  sqc2        $vf4, 0x0($a0)
    ctx->pc = 0x199ce4u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x199ce8: 0xf8850010  sqc2        $vf5, 0x10($a0)
    ctx->pc = 0x199ce8u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 16), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x199cec: 0xf8860020  sqc2        $vf6, 0x20($a0)
    ctx->pc = 0x199cecu;
    WRITE128(ADD32(GPR_U32(ctx, 4), 32), _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x199cf0: 0x3e00008  jr          $ra
    ctx->pc = 0x199CF0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x199CF8u;
    // 0x199cf8: 0x0  nop
    ctx->pc = 0x199cf8u;
    // NOP
    // 0x199cfc: 0x0  nop
    ctx->pc = 0x199cfcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
