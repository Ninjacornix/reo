#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012CC00
// Address: 0x12cc00 - 0x12cc10
void sub_0012CC00_0x12cc00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012CC00_0x12cc00");
#endif

    ctx->pc = 0x12cc00u;

    // 0x12cc00: 0x52880  sll         $a1, $a1, 2
    ctx->pc = 0x12cc00u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x12cc04: 0x852021  addu        $a0, $a0, $a1
    ctx->pc = 0x12cc04u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x12cc08: 0x3e00008  jr          $ra
    ctx->pc = 0x12CC08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12CC0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12CC08u;
            // 0x12cc0c: 0xac86000c  sw          $a2, 0xC($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12CC10u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
