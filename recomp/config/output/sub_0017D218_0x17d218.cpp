#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D218
// Address: 0x17d218 - 0x17d248
void sub_0017D218_0x17d218(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D218_0x17d218");
#endif

    ctx->pc = 0x17d218u;

    // 0x17d218: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x17d218u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x17d21c: 0x3e00008  jr          $ra
    ctx->pc = 0x17D21Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D220u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D21Cu;
            // 0x17d220: 0x8c62f2b4  lw          $v0, -0xD4C($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294963892)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17D224u;
    // 0x17d224: 0x0  nop
    ctx->pc = 0x17d224u;
    // NOP
    // 0x17d228: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x17d228u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x17d22c: 0x3e00008  jr          $ra
    ctx->pc = 0x17D22Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D230u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D22Cu;
            // 0x17d230: 0xac44f29c  sw          $a0, -0xD64($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294963868), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17D234u;
    // 0x17d234: 0x0  nop
    ctx->pc = 0x17d234u;
    // NOP
    // 0x17d238: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x17d238u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x17d23c: 0x3e00008  jr          $ra
    ctx->pc = 0x17D23Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D240u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D23Cu;
            // 0x17d240: 0x8c62f29c  lw          $v0, -0xD64($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294963868)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17D244u;
    // 0x17d244: 0x0  nop
    ctx->pc = 0x17d244u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
