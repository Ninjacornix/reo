#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013ECA0
// Address: 0x13eca0 - 0x13ecb0
void sub_0013ECA0_0x13eca0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013ECA0_0x13eca0");
#endif

    ctx->pc = 0x13eca0u;

    // 0x13eca0: 0x3402bb80  ori         $v0, $zero, 0xBB80
    ctx->pc = 0x13eca0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)48000);
    // 0x13eca4: 0xaca00000  sw          $zero, 0x0($a1)
    ctx->pc = 0x13eca4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 0));
    // 0x13eca8: 0x3e00008  jr          $ra
    ctx->pc = 0x13ECA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13ECACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13ECA8u;
            // 0x13ecac: 0xacc20000  sw          $v0, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13ECB0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
