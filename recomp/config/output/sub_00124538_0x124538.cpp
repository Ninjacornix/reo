#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00124538
// Address: 0x124538 - 0x124558
void sub_00124538_0x124538(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00124538_0x124538");
#endif

    ctx->pc = 0x124538u;

    // 0x124538: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x124538u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x12453c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x12453cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124540: 0x2484b93c  addiu       $a0, $a0, -0x46C4
    ctx->pc = 0x124540u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949180));
    // 0x124544: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x124544u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x124548: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x124548u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x12454c: 0x3e00008  jr          $ra
    ctx->pc = 0x12454Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x124550u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12454Cu;
            // 0x124550: 0xac830000  sw          $v1, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x124554u;
    // 0x124554: 0x0  nop
    ctx->pc = 0x124554u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
