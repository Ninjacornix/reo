#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D678
// Address: 0x17d678 - 0x17d684
void sub_0017D678_0x17d678(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D678_0x17d678");
#endif

    ctx->pc = 0x17d678u;

    // 0x17d678: 0x8c82005c  lw          $v0, 0x5C($a0)
    ctx->pc = 0x17d678u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 92)));
    // 0x17d67c: 0x3e00008  jr          $ra
    ctx->pc = 0x17D67Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D680u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D67Cu;
            // 0x17d680: 0x2102b  sltu        $v0, $zero, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17D684u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
