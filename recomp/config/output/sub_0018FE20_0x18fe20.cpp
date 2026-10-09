#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018FE20
// Address: 0x18fe20 - 0x18fe60
void sub_0018FE20_0x18fe20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018FE20_0x18fe20");
#endif

    ctx->pc = 0x18fe20u;

    // 0x18fe20: 0x3c030029  lui         $v1, 0x29
    ctx->pc = 0x18fe20u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)41 << 16));
    // 0x18fe24: 0x24634e00  addiu       $v1, $v1, 0x4E00
    ctx->pc = 0x18fe24u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 19968));
    // 0x18fe28: 0xd8640000  lqc2        $vf4, 0x0($v1)
    ctx->pc = 0x18fe28u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x18fe2c: 0xd8650010  lqc2        $vf5, 0x10($v1)
    ctx->pc = 0x18fe2cu;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x18fe30: 0xd8660020  lqc2        $vf6, 0x20($v1)
    ctx->pc = 0x18fe30u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x18fe34: 0xd8880000  lqc2        $vf8, 0x0($a0)
    ctx->pc = 0x18fe34u;
    ctx->vu0_vf[8] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x18fe38: 0xd8890010  lqc2        $vf9, 0x10($a0)
    ctx->pc = 0x18fe38u;
    ctx->vu0_vf[9] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x18fe3c: 0xd88a0020  lqc2        $vf10, 0x20($a0)
    ctx->pc = 0x18fe3cu;
    ctx->vu0_vf[10] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 4), 32)));
    // 0x18fe40: 0x4bc40228  vadd.xyz    $vf8, $vf0, $vf4
    ctx->pc = 0x18fe40u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[4]); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[8] = PS2_VBLEND(ctx->vu0_vf[8], res, _mm_castsi128_ps(mask)); }
    // 0x18fe44: 0x4bc50268  vadd.xyz    $vf9, $vf0, $vf5
    ctx->pc = 0x18fe44u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[5]); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[9] = PS2_VBLEND(ctx->vu0_vf[9], res, _mm_castsi128_ps(mask)); }
    // 0x18fe48: 0x4bc602a8  vadd.xyz    $vf10, $vf0, $vf6
    ctx->pc = 0x18fe48u;
    { __m128 res = PS2_VADD(ctx->vu0_vf[0], ctx->vu0_vf[6]); __m128i mask = _mm_set_epi32(0, -1, -1, -1); ctx->vu0_vf[10] = PS2_VBLEND(ctx->vu0_vf[10], res, _mm_castsi128_ps(mask)); }
    // 0x18fe4c: 0xf8880000  sqc2        $vf8, 0x0($a0)
    ctx->pc = 0x18fe4cu;
    WRITE128(ADD32(GPR_U32(ctx, 4), 0), _mm_castps_si128(ctx->vu0_vf[8]));
    // 0x18fe50: 0xf8890010  sqc2        $vf9, 0x10($a0)
    ctx->pc = 0x18fe50u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 16), _mm_castps_si128(ctx->vu0_vf[9]));
    // 0x18fe54: 0x3e00008  jr          $ra
    ctx->pc = 0x18FE54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18FE58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18FE54u;
            // 0x18fe58: 0xf88a0020  sqc2        $vf10, 0x20($a0) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 4), 32), _mm_castps_si128(ctx->vu0_vf[10]));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x18FE5Cu;
    // 0x18fe5c: 0x0  nop
    ctx->pc = 0x18fe5cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
