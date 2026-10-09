#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00124F20
// Address: 0x124f20 - 0x124f34
void sub_00124F20_0x124f20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00124F20_0x124f20");
#endif

    ctx->pc = 0x124f20u;

    // 0x124f20: 0x10800002  beqz        $a0, . + 4 + (0x2 << 2)
    ctx->pc = 0x124F20u;
    {
        const bool branch_taken_0x124f20 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x124F24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124F20u;
            // 0x124f24: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124f20) {
            ctx->pc = 0x124F2Cu;
            goto label_124f2c;
        }
    }
    ctx->pc = 0x124F28u;
    // 0x124f28: 0x8c82002c  lw          $v0, 0x2C($a0)
    ctx->pc = 0x124f28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 44)));
label_124f2c:
    // 0x124f2c: 0x3e00008  jr          $ra
    ctx->pc = 0x124F2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x124F2Cu: goto label_124f2c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x124F34u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
