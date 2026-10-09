#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C80D0
// Address: 0x1c80d0 - 0x1c8110
void sub_001C80D0_0x1c80d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C80D0_0x1c80d0");
#endif

    ctx->pc = 0x1c80d0u;

    // 0x1c80d0: 0x3e00008  jr          $ra
    ctx->pc = 0x1C80D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C80D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C80D0u;
            // 0x1c80d4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1C80D8u;
    // 0x1c80d8: 0x0  nop
    ctx->pc = 0x1c80d8u;
    // NOP
    // 0x1c80dc: 0x0  nop
    ctx->pc = 0x1c80dcu;
    // NOP
    // 0x1c80e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1C80E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C80E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C80E0u;
            // 0x1c80e4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1C80E8u;
    // 0x1c80e8: 0x0  nop
    ctx->pc = 0x1c80e8u;
    // NOP
    // 0x1c80ec: 0x0  nop
    ctx->pc = 0x1c80ecu;
    // NOP
    // 0x1c80f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1C80F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C80F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C80F0u;
            // 0x1c80f4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1C80F8u;
    // 0x1c80f8: 0x0  nop
    ctx->pc = 0x1c80f8u;
    // NOP
    // 0x1c80fc: 0x0  nop
    ctx->pc = 0x1c80fcu;
    // NOP
    // 0x1c8100: 0x3e00008  jr          $ra
    ctx->pc = 0x1C8100u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C8104u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8100u;
            // 0x1c8104: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1C8108u;
    // 0x1c8108: 0x0  nop
    ctx->pc = 0x1c8108u;
    // NOP
    // 0x1c810c: 0x0  nop
    ctx->pc = 0x1c810cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
