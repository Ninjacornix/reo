#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C9050
// Address: 0x1c9050 - 0x1c9080
void sub_001C9050_0x1c9050(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C9050_0x1c9050");
#endif

    switch (ctx->pc) {
        case 0x1c905cu: goto label_1c905c;
        default: break;
    }

    ctx->pc = 0x1c9050u;

    // 0x1c9050: 0x2402005c  addiu       $v0, $zero, 0x5C
    ctx->pc = 0x1c9050u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 92));
    // 0x1c9054: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1C9054u;
    {
        const bool branch_taken_0x1c9054 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9058u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9054u;
            // 0x1c9058: 0x2403002f  addiu       $v1, $zero, 0x2F (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 47));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9054) {
            ctx->pc = 0x1C906Cu;
            goto label_1c906c;
        }
    }
    ctx->pc = 0x1C905Cu;
label_1c905c:
    // 0x1c905c: 0x14a30002  bne         $a1, $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1C905Cu;
    {
        const bool branch_taken_0x1c905c = (GPR_U64(ctx, 5) != GPR_U64(ctx, 3));
        if (branch_taken_0x1c905c) {
            ctx->pc = 0x1C9068u;
            goto label_1c9068;
        }
    }
    ctx->pc = 0x1C9064u;
    // 0x1c9064: 0xa0820000  sb          $v0, 0x0($a0)
    ctx->pc = 0x1c9064u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 2));
label_1c9068:
    // 0x1c9068: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1c9068u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
label_1c906c:
    // 0x1c906c: 0x80850000  lb          $a1, 0x0($a0)
    ctx->pc = 0x1c906cu;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1c9070: 0x14a0fffa  bnez        $a1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1C9070u;
    {
        const bool branch_taken_0x1c9070 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c9070) {
            ctx->pc = 0x1C905Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c905c;
        }
    }
    ctx->pc = 0x1C9078u;
    // 0x1c9078: 0x3e00008  jr          $ra
    ctx->pc = 0x1C9078u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C907Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9078u;
            // 0x1c907c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C905Cu: goto label_1c905c;
            case 0x1C9068u: goto label_1c9068;
            case 0x1C906Cu: goto label_1c906c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C9080u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
