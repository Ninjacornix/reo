#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D168
// Address: 0x17d168 - 0x17d178
void sub_0017D168_0x17d168(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D168_0x17d168");
#endif

    ctx->pc = 0x17d168u;

    // 0x17d168: 0x2882181f  slti        $v0, $a0, 0x181F
    ctx->pc = 0x17d168u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)6175) ? 1 : 0);
    // 0x17d16c: 0x3e00008  jr          $ra
    ctx->pc = 0x17D16Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D170u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D16Cu;
            // 0x17d170: 0x38420001  xori        $v0, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17D174u;
    // 0x17d174: 0x0  nop
    ctx->pc = 0x17d174u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
