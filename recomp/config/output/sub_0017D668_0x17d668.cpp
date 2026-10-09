#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D668
// Address: 0x17d668 - 0x17d678
void sub_0017D668_0x17d668(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D668_0x17d668");
#endif

    ctx->pc = 0x17d668u;

    // 0x17d668: 0x2484005c  addiu       $a0, $a0, 0x5C
    ctx->pc = 0x17d668u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 92));
    // 0x17d66c: 0xac860004  sw          $a2, 0x4($a0)
    ctx->pc = 0x17d66cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 6));
    // 0x17d670: 0x3e00008  jr          $ra
    ctx->pc = 0x17D670u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D674u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D670u;
            // 0x17d674: 0xac850000  sw          $a1, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17D678u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
