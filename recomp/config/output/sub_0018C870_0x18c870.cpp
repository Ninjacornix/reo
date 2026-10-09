#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018C870
// Address: 0x18c870 - 0x18c8b0
void sub_0018C870_0x18c870(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018C870_0x18c870");
#endif

    ctx->pc = 0x18c870u;

    // 0x18c870: 0x3c020007  lui         $v0, 0x7
    ctx->pc = 0x18c870u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)7 << 16));
    // 0x18c874: 0x82001b  divu        $zero, $a0, $v0
    ctx->pc = 0x18c874u;
    { uint32_t divisor = GPR_U32(ctx, 2); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 4) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 4) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,4); } }
    // 0x18c878: 0x0  nop
    ctx->pc = 0x18c878u;
    // NOP
    // 0x18c87c: 0x0  nop
    ctx->pc = 0x18c87cu;
    // NOP
    // 0x18c880: 0x1812  mflo        $v1
    ctx->pc = 0x18c880u;
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x18c884: 0x82001b  divu        $zero, $a0, $v0
    ctx->pc = 0x18c884u;
    { uint32_t divisor = GPR_U32(ctx, 2); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 4) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 4) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,4); } }
    // 0x18c888: 0x0  nop
    ctx->pc = 0x18c888u;
    // NOP
    // 0x18c88c: 0x0  nop
    ctx->pc = 0x18c88cu;
    // NOP
    // 0x18c890: 0x1010  mfhi        $v0
    ctx->pc = 0x18c890u;
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x18c894: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x18C894u;
    {
        const bool branch_taken_0x18c894 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x18C898u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18C894u;
            // 0x18c898: 0x311c0  sll         $v0, $v1, 7 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18c894) {
            ctx->pc = 0x18C8A4u;
            goto label_18c8a4;
        }
    }
    ctx->pc = 0x18C89Cu;
    // 0x18c89c: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x18c89cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x18c8a0: 0x311c0  sll         $v0, $v1, 7
    ctx->pc = 0x18c8a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 7));
label_18c8a4:
    // 0x18c8a4: 0x3e00008  jr          $ra
    ctx->pc = 0x18C8A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18C8A4u: goto label_18c8a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18C8ACu;
    // 0x18c8ac: 0x0  nop
    ctx->pc = 0x18c8acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
