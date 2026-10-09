#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00162A98
// Address: 0x162a98 - 0x162ac4
void sub_00162A98_0x162a98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00162A98_0x162a98");
#endif

    ctx->pc = 0x162a98u;

    // 0x162a98: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x162a98u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x162a9c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x162a9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x162aa0: 0x8c82004c  lw          $v0, 0x4C($a0)
    ctx->pc = 0x162aa0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 76)));
    // 0x162aa4: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x162AA4u;
    {
        const bool branch_taken_0x162aa4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x162AA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162AA4u;
            // 0x162aa8: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x162aa4) {
            ctx->pc = 0x162AB8u;
            goto label_162ab8;
        }
    }
    ctx->pc = 0x162AACu;
    // 0x162aac: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x162aacu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162ab0: 0x804f4d6  j           func_13D358
    ctx->pc = 0x162AB0u;
    ctx->pc = 0x162AB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162AB0u;
            // 0x162ab4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D358u;
    if (runtime->hasFunction(0x13D358u)) {
        auto targetFn = runtime->lookupFunction(0x13D358u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013D358_0x13d358(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x162AB8u;
label_162ab8:
    // 0x162ab8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x162ab8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162abc: 0x3e00008  jr          $ra
    ctx->pc = 0x162ABCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x162AC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162ABCu;
            // 0x162ac0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x162AB8u: goto label_162ab8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x162AC4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
