#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001618C0
// Address: 0x1618c0 - 0x1618e8
void sub_001618C0_0x1618c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001618C0_0x1618c0");
#endif

    ctx->pc = 0x1618c0u;

    // 0x1618c0: 0x8c830020  lw          $v1, 0x20($a0)
    ctx->pc = 0x1618c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 32)));
    // 0x1618c4: 0x10600005  beqz        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1618C4u;
    {
        const bool branch_taken_0x1618c4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1618C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1618C4u;
            // 0x1618c8: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1618c4) {
            ctx->pc = 0x1618DCu;
            goto label_1618dc;
        }
    }
    ctx->pc = 0x1618CCu;
    // 0x1618cc: 0x24020101  addiu       $v0, $zero, 0x101
    ctx->pc = 0x1618ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 257));
    // 0x1618d0: 0x14620002  bne         $v1, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1618D0u;
    {
        const bool branch_taken_0x1618d0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1618D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1618D0u;
            // 0x1618d4: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1618d0) {
            ctx->pc = 0x1618DCu;
            goto label_1618dc;
        }
    }
    ctx->pc = 0x1618D8u;
    // 0x1618d8: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1618d8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1618dc:
    // 0x1618dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1618DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1618E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1618DCu;
            // 0x1618e0: 0x80102d  daddu       $v0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1618DCu: goto label_1618dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1618E4u;
    // 0x1618e4: 0x0  nop
    ctx->pc = 0x1618e4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
