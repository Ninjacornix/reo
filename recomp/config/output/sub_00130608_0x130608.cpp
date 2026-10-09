#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00130608
// Address: 0x130608 - 0x130620
void sub_00130608_0x130608(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00130608_0x130608");
#endif

    ctx->pc = 0x130608u;

    // 0x130608: 0x8c830008  lw          $v1, 0x8($a0)
    ctx->pc = 0x130608u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x13060c: 0x10600002  beqz        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x13060Cu;
    {
        const bool branch_taken_0x13060c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x130610u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13060Cu;
            // 0x130610: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13060c) {
            ctx->pc = 0x130618u;
            goto label_130618;
        }
    }
    ctx->pc = 0x130614u;
    // 0x130614: 0x8c820054  lw          $v0, 0x54($a0)
    ctx->pc = 0x130614u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 84)));
label_130618:
    // 0x130618: 0x3e00008  jr          $ra
    ctx->pc = 0x130618u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130618u: goto label_130618;
            default: break;
        }
        return;
    }
    ctx->pc = 0x130620u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
