#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B5670
// Address: 0x1b5670 - 0x1b56a0
void sub_001B5670_0x1b5670(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B5670_0x1b5670");
#endif

    ctx->pc = 0x1b5670u;

    // 0x1b5670: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B5670u;
    {
        const bool branch_taken_0x1b5670 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B5674u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5670u;
            // 0x1b5674: 0x3c03002c  lui         $v1, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)44 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5670) {
            ctx->pc = 0x1B568Cu;
            goto label_1b568c;
        }
    }
    ctx->pc = 0x1B5678u;
    // 0x1b5678: 0x3c03002c  lui         $v1, 0x2C
    ctx->pc = 0x1b5678u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)44 << 16));
    // 0x1b567c: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1b567cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1b5680: 0x2463aaf0  addiu       $v1, $v1, -0x5510
    ctx->pc = 0x1b5680u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294945520));
    // 0x1b5684: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1B5684u;
    {
        const bool branch_taken_0x1b5684 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B5688u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B5684u;
            // 0x1b5688: 0xac234768  sw          $v1, 0x4768($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 18280), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b5684) {
            ctx->pc = 0x1B5698u;
            goto label_1b5698;
        }
    }
    ctx->pc = 0x1B568Cu;
label_1b568c:
    // 0x1b568c: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1b568cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1b5690: 0x2463aa40  addiu       $v1, $v1, -0x55C0
    ctx->pc = 0x1b5690u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294945344));
    // 0x1b5694: 0xac234768  sw          $v1, 0x4768($at)
    ctx->pc = 0x1b5694u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 18280), GPR_U32(ctx, 3));
label_1b5698:
    // 0x1b5698: 0x3e00008  jr          $ra
    ctx->pc = 0x1B5698u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B568Cu: goto label_1b568c;
            case 0x1B5698u: goto label_1b5698;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B56A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
