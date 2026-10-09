#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001172F0
// Address: 0x1172f0 - 0x117310
void sub_001172F0_0x1172f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001172F0_0x1172f0");
#endif

    ctx->pc = 0x1172f0u;

    // 0x1172f0: 0x8c830010  lw          $v1, 0x10($a0)
    ctx->pc = 0x1172f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x1172f4: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x1172f4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x1172f8: 0x3442fffe  ori         $v0, $v0, 0xFFFE
    ctx->pc = 0x1172f8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65534);
    // 0x1172fc: 0xac800018  sw          $zero, 0x18($a0)
    ctx->pc = 0x1172fcu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 0));
    // 0x117300: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x117300u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x117304: 0x3e00008  jr          $ra
    ctx->pc = 0x117304u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x117308u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117304u;
            // 0x117308: 0xac830010  sw          $v1, 0x10($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x11730Cu;
    // 0x11730c: 0x0  nop
    ctx->pc = 0x11730cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
