#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012E570
// Address: 0x12e570 - 0x12e588
void sub_0012E570_0x12e570(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012E570_0x12e570");
#endif

    ctx->pc = 0x12e570u;

    // 0x12e570: 0xa42821  addu        $a1, $a1, $a0
    ctx->pc = 0x12e570u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x12e574: 0x10800002  beqz        $a0, . + 4 + (0x2 << 2)
    ctx->pc = 0x12E574u;
    {
        const bool branch_taken_0x12e574 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x12E578u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E574u;
            // 0x12e578: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12e574) {
            ctx->pc = 0x12E580u;
            goto label_12e580;
        }
    }
    ctx->pc = 0x12E57Cu;
    // 0x12e57c: 0x80a20058  lb          $v0, 0x58($a1)
    ctx->pc = 0x12e57cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 88)));
label_12e580:
    // 0x12e580: 0x3e00008  jr          $ra
    ctx->pc = 0x12E580u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12E580u: goto label_12e580;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12E588u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
