#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A9070
// Address: 0x1a9070 - 0x1a90b0
void sub_001A9070_0x1a9070(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A9070_0x1a9070");
#endif

    ctx->pc = 0x1a9070u;

    // 0x1a9070: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x1a9070u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x1a9074: 0x8c234178  lw          $v1, 0x4178($at)
    ctx->pc = 0x1a9074u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16760)));
    // 0x1a9078: 0x14600005  bnez        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1A9078u;
    {
        const bool branch_taken_0x1a9078 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a9078) {
            ctx->pc = 0x1A9090u;
            goto label_1a9090;
        }
    }
    ctx->pc = 0x1A9080u;
    // 0x1a9080: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1a9080u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a9084: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1a9084u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1a9088: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1A9088u;
    {
        const bool branch_taken_0x1a9088 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A908Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9088u;
            // 0x1a908c: 0xac23fa10  sw          $v1, -0x5F0($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294965776), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a9088) {
            ctx->pc = 0x1A909Cu;
            goto label_1a909c;
        }
    }
    ctx->pc = 0x1A9090u;
label_1a9090:
    // 0x1a9090: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1a9090u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1a9094: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x1a9094u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x1a9098: 0xac234178  sw          $v1, 0x4178($at)
    ctx->pc = 0x1a9098u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16760), GPR_U32(ctx, 3));
label_1a909c:
    // 0x1a909c: 0x3e00008  jr          $ra
    ctx->pc = 0x1A909Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A9090u: goto label_1a9090;
            case 0x1A909Cu: goto label_1a909c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A90A4u;
    // 0x1a90a4: 0x0  nop
    ctx->pc = 0x1a90a4u;
    // NOP
    // 0x1a90a8: 0x0  nop
    ctx->pc = 0x1a90a8u;
    // NOP
    // 0x1a90ac: 0x0  nop
    ctx->pc = 0x1a90acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
