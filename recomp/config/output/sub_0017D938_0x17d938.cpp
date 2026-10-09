#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D938
// Address: 0x17d938 - 0x17d968
void sub_0017D938_0x17d938(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D938_0x17d938");
#endif

    ctx->pc = 0x17d938u;

    // 0x17d938: 0x24840008  addiu       $a0, $a0, 0x8
    ctx->pc = 0x17d938u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
    // 0x17d93c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x17d93cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17d940: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x17d940u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x17d944: 0x50430004  beql        $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x17D944u;
    {
        const bool branch_taken_0x17d944 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x17d944) {
            ctx->pc = 0x17D948u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17D944u;
            // 0x17d948: 0x8c820008  lw          $v0, 0x8($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17D958u;
            goto label_17d958;
        }
    }
    ctx->pc = 0x17D94Cu;
    // 0x17d94c: 0xaca00000  sw          $zero, 0x0($a1)
    ctx->pc = 0x17d94cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 0));
    // 0x17d950: 0x3e00008  jr          $ra
    ctx->pc = 0x17D950u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D954u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D950u;
            // 0x17d954: 0xacc00000  sw          $zero, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17D958u: goto label_17d958;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17D958u;
label_17d958:
    // 0x17d958: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x17d958u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x17d95c: 0xacc20000  sw          $v0, 0x0($a2)
    ctx->pc = 0x17d95cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x17d960: 0x3e00008  jr          $ra
    ctx->pc = 0x17D960u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D964u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D960u;
            // 0x17d964: 0xaca30000  sw          $v1, 0x0($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17D958u: goto label_17d958;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17D968u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
