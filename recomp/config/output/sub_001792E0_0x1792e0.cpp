#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001792E0
// Address: 0x1792e0 - 0x179308
void sub_001792E0_0x1792e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001792E0_0x1792e0");
#endif

    ctx->pc = 0x1792e0u;

    // 0x1792e0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1792e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1792e4: 0x2843ffff  slti        $v1, $v0, -0x1
    ctx->pc = 0x1792e4u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)4294967295) ? 1 : 0);
    // 0x1792e8: 0x28420002  slti        $v0, $v0, 0x2
    ctx->pc = 0x1792e8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1792ec: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1792ECu;
    {
        const bool branch_taken_0x1792ec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1792F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1792ECu;
            // 0x1792f0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1792ec) {
            ctx->pc = 0x179300u;
            goto label_179300;
        }
    }
    ctx->pc = 0x1792F4u;
    // 0x1792f4: 0x10600002  beqz        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1792F4u;
    {
        const bool branch_taken_0x1792f4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1792F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1792F4u;
            // 0x1792f8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1792f4) {
            ctx->pc = 0x179300u;
            goto label_179300;
        }
    }
    ctx->pc = 0x1792FCu;
    // 0x1792fc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1792fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_179300:
    // 0x179300: 0x3e00008  jr          $ra
    ctx->pc = 0x179300u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x179300u: goto label_179300;
            default: break;
        }
        return;
    }
    ctx->pc = 0x179308u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
