#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018FDF0
// Address: 0x18fdf0 - 0x18fe20
void sub_0018FDF0_0x18fdf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018FDF0_0x18fdf0");
#endif

    ctx->pc = 0x18fdf0u;

    // 0x18fdf0: 0x3c030029  lui         $v1, 0x29
    ctx->pc = 0x18fdf0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)41 << 16));
    // 0x18fdf4: 0x24634e00  addiu       $v1, $v1, 0x4E00
    ctx->pc = 0x18fdf4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 19968));
    // 0x18fdf8: 0xd8640000  lqc2        $vf4, 0x0($v1)
    ctx->pc = 0x18fdf8u;
    ctx->vu0_vf[4] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x18fdfc: 0xd8650010  lqc2        $vf5, 0x10($v1)
    ctx->pc = 0x18fdfcu;
    ctx->vu0_vf[5] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x18fe00: 0xd8660020  lqc2        $vf6, 0x20($v1)
    ctx->pc = 0x18fe00u;
    ctx->vu0_vf[6] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x18fe04: 0xd8670030  lqc2        $vf7, 0x30($v1)
    ctx->pc = 0x18fe04u;
    ctx->vu0_vf[7] = _mm_castsi128_ps(READ128(ADD32(GPR_U32(ctx, 3), 48)));
    // 0x18fe08: 0xf8840000  sqc2        $vf4, 0x0($a0)
    ctx->pc = 0x18fe08u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 0), _mm_castps_si128(ctx->vu0_vf[4]));
    // 0x18fe0c: 0xf8850010  sqc2        $vf5, 0x10($a0)
    ctx->pc = 0x18fe0cu;
    WRITE128(ADD32(GPR_U32(ctx, 4), 16), _mm_castps_si128(ctx->vu0_vf[5]));
    // 0x18fe10: 0xf8860020  sqc2        $vf6, 0x20($a0)
    ctx->pc = 0x18fe10u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 32), _mm_castps_si128(ctx->vu0_vf[6]));
    // 0x18fe14: 0x3e00008  jr          $ra
    ctx->pc = 0x18FE14u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18FE18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18FE14u;
            // 0x18fe18: 0xf8870030  sqc2        $vf7, 0x30($a0) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 4), 48), _mm_castps_si128(ctx->vu0_vf[7]));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x18FE1Cu;
    // 0x18fe1c: 0x0  nop
    ctx->pc = 0x18fe1cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
