#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00163420
// Address: 0x163420 - 0x163440
void sub_00163420_0x163420(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00163420_0x163420");
#endif

    ctx->pc = 0x163420u;

    // 0x163420: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x163420u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x163424: 0x3e00008  jr          $ra
    ctx->pc = 0x163424u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x163428u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163424u;
            // 0x163428: 0x8c62ef50  lw          $v0, -0x10B0($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294963024)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x16342Cu;
    // 0x16342c: 0x0  nop
    ctx->pc = 0x16342cu;
    // NOP
    // 0x163430: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x163430u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x163434: 0x3e00008  jr          $ra
    ctx->pc = 0x163434u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x163438u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163434u;
            // 0x163438: 0xac44ef50  sw          $a0, -0x10B0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294963024), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x16343Cu;
    // 0x16343c: 0x0  nop
    ctx->pc = 0x16343cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
