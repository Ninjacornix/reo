#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001706E0
// Address: 0x1706e0 - 0x1706f8
void sub_001706E0_0x1706e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001706E0_0x1706e0");
#endif

    ctx->pc = 0x1706e0u;

    // 0x1706e0: 0x10800002  beqz        $a0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1706E0u;
    {
        const bool branch_taken_0x1706e0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1706E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1706E0u;
            // 0x1706e4: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1706e0) {
            ctx->pc = 0x1706ECu;
            goto label_1706ec;
        }
    }
    ctx->pc = 0x1706E8u;
    // 0x1706e8: 0xac820000  sw          $v0, 0x0($a0)
    ctx->pc = 0x1706e8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
label_1706ec:
    // 0x1706ec: 0x3e00008  jr          $ra
    ctx->pc = 0x1706ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1706ECu: goto label_1706ec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1706F4u;
    // 0x1706f4: 0x0  nop
    ctx->pc = 0x1706f4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
