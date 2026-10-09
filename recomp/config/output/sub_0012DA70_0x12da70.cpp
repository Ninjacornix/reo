#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012DA70
// Address: 0x12da70 - 0x12da88
void sub_0012DA70_0x12da70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012DA70_0x12da70");
#endif

    ctx->pc = 0x12da70u;

    // 0x12da70: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x12da70u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x12da74: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x12da74u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x12da78: 0xac44874c  sw          $a0, -0x78B4($v0)
    ctx->pc = 0x12da78u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294936396), GPR_U32(ctx, 4));
    // 0x12da7c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x12da7cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12da80: 0x3e00008  jr          $ra
    ctx->pc = 0x12DA80u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12DA84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12DA80u;
            // 0x12da84: 0xac658750  sw          $a1, -0x78B0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 4294936400), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12DA88u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
