#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00163410
// Address: 0x163410 - 0x163420
void sub_00163410_0x163410(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00163410_0x163410");
#endif

    ctx->pc = 0x163410u;

    // 0x163410: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x163410u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x163414: 0x3e00008  jr          $ra
    ctx->pc = 0x163414u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x163418u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163414u;
            // 0x163418: 0x2442ef50  addiu       $v0, $v0, -0x10B0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963024));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x16341Cu;
    // 0x16341c: 0x0  nop
    ctx->pc = 0x16341cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
