#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C7B80
// Address: 0x1c7b80 - 0x1c7bbc
void sub_001C7B80_0x1c7b80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C7B80_0x1c7b80");
#endif

    ctx->pc = 0x1c7b80u;

    // 0x1c7b80: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7b80u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c7b84: 0x8c2351b4  lw          $v1, 0x51B4($at)
    ctx->pc = 0x1c7b84u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 20916)));
    // 0x1c7b88: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1C7B88u;
    {
        const bool branch_taken_0x1c7b88 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C7B8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7B88u;
            // 0x1c7b8c: 0x3c010033  lui         $at, 0x33 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7b88) {
            ctx->pc = 0x1C7B9Cu;
            goto label_1c7b9c;
        }
    }
    ctx->pc = 0x1C7B90u;
    // 0x1c7b90: 0x8c2251b0  lw          $v0, 0x51B0($at)
    ctx->pc = 0x1c7b90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 20912)));
    // 0x1c7b94: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1C7B94u;
    {
        const bool branch_taken_0x1c7b94 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C7B98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7B94u;
            // 0x1c7b98: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7b94) {
            ctx->pc = 0x1C7BB4u;
            goto label_1c7bb4;
        }
    }
    ctx->pc = 0x1C7B9Cu;
label_1c7b9c:
    // 0x1c7b9c: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C7B9Cu;
    {
        const bool branch_taken_0x1c7b9c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C7BA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7B9Cu;
            // 0x1c7ba0: 0x3c010033  lui         $at, 0x33 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7b9c) {
            ctx->pc = 0x1C7BACu;
            goto label_1c7bac;
        }
    }
    ctx->pc = 0x1C7BA4u;
    // 0x1c7ba4: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1C7BA4u;
    {
        const bool branch_taken_0x1c7ba4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C7BA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7BA4u;
            // 0x1c7ba8: 0x2462037a  addiu       $v0, $v1, 0x37A (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 890));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c7ba4) {
            ctx->pc = 0x1C7BB4u;
            goto label_1c7bb4;
        }
    }
    ctx->pc = 0x1C7BACu;
label_1c7bac:
    // 0x1c7bac: 0x8c2251b0  lw          $v0, 0x51B0($at)
    ctx->pc = 0x1c7bacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 20912)));
    // 0x1c7bb0: 0x24420352  addiu       $v0, $v0, 0x352
    ctx->pc = 0x1c7bb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 850));
label_1c7bb4:
    // 0x1c7bb4: 0x3e00008  jr          $ra
    ctx->pc = 0x1C7BB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C7B9Cu: goto label_1c7b9c;
            case 0x1C7BACu: goto label_1c7bac;
            case 0x1C7BB4u: goto label_1c7bb4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C7BBCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
