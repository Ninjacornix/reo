#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D1C8
// Address: 0x17d1c8 - 0x17d208
void sub_0017D1C8_0x17d1c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D1C8_0x17d1c8");
#endif

    switch (ctx->pc) {
        case 0x17d1fcu: goto label_17d1fc;
        default: break;
    }

    ctx->pc = 0x17d1c8u;

    // 0x17d1c8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17d1c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17d1cc: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x17d1ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x17d1d0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17d1d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17d1d4: 0x2442f2a8  addiu       $v0, $v0, -0xD58
    ctx->pc = 0x17d1d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963880));
    // 0x17d1d8: 0xc0282d  daddu       $a1, $a2, $zero
    ctx->pc = 0x17d1d8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17d1dc: 0x8c430008  lw          $v1, 0x8($v0)
    ctx->pc = 0x17d1dcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x17d1e0: 0x8c460000  lw          $a2, 0x0($v0)
    ctx->pc = 0x17d1e0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x17d1e4: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x17d1e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x17d1e8: 0x8c440004  lw          $a0, 0x4($v0)
    ctx->pc = 0x17d1e8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x17d1ec: 0x10c00003  beqz        $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x17D1ECu;
    {
        const bool branch_taken_0x17d1ec = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x17D1F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D1ECu;
            // 0x17d1f0: 0xac430008  sw          $v1, 0x8($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17d1ec) {
            ctx->pc = 0x17D1FCu;
            goto label_17d1fc;
        }
    }
    ctx->pc = 0x17D1F4u;
    // 0x17d1f4: 0xc0f809  jalr        $a2
    ctx->pc = 0x17D1F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 6);
        SET_GPR_U32(ctx, 31, 0x17D1FCu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x17D1FCu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17D1FCu: goto label_17d1fc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x17D1FCu; }
            if (ctx->pc != 0x17D1FCu) { return; }
        }
        }
    }
    ctx->pc = 0x17D1FCu;
label_17d1fc:
    // 0x17d1fc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17d1fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17d200: 0x3e00008  jr          $ra
    ctx->pc = 0x17D200u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D204u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D200u;
            // 0x17d204: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17D1FCu: goto label_17d1fc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17D208u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
