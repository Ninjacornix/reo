#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D518
// Address: 0x17d518 - 0x17d540
void sub_0017D518_0x17d518(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D518_0x17d518");
#endif

    ctx->pc = 0x17d518u;

    // 0x17d518: 0x517c2  srl         $v0, $a1, 31
    ctx->pc = 0x17d518u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 5), 31));
    // 0x17d51c: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x17d51cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x17d520: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x17d520u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x17d524: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x17d524u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x17d528: 0x21843  sra         $v1, $v0, 1
    ctx->pc = 0x17d528u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 2), 1));
    // 0x17d52c: 0xac82000c  sw          $v0, 0xC($a0)
    ctx->pc = 0x17d52cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 2));
    // 0x17d530: 0xac83002c  sw          $v1, 0x2C($a0)
    ctx->pc = 0x17d530u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 44), GPR_U32(ctx, 3));
    // 0x17d534: 0x3e00008  jr          $ra
    ctx->pc = 0x17D534u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D538u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D534u;
            // 0x17d538: 0xac83001c  sw          $v1, 0x1C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17D53Cu;
    // 0x17d53c: 0x0  nop
    ctx->pc = 0x17d53cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
