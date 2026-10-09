#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D258
// Address: 0x17d258 - 0x17d268
void sub_0017D258_0x17d258(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D258_0x17d258");
#endif

    ctx->pc = 0x17d258u;

    // 0x17d258: 0xac86000c  sw          $a2, 0xC($a0)
    ctx->pc = 0x17d258u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 6));
    // 0x17d25c: 0x3e00008  jr          $ra
    ctx->pc = 0x17D25Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D260u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D25Cu;
            // 0x17d260: 0xac850008  sw          $a1, 0x8($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17D264u;
    // 0x17d264: 0x0  nop
    ctx->pc = 0x17d264u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
