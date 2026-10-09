#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A5BD0
// Address: 0x1a5bd0 - 0x1a5c10
void sub_001A5BD0_0x1a5bd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A5BD0_0x1a5bd0");
#endif

    switch (ctx->pc) {
        case 0x1a5bdcu: goto label_1a5bdc;
        default: break;
    }

    ctx->pc = 0x1a5bd0u;

    // 0x1a5bd0: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x1a5bd0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x1a5bd4: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1A5BD4u;
    {
        const bool branch_taken_0x1a5bd4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A5BD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5BD4u;
            // 0x1a5bd8: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a5bd4) {
            ctx->pc = 0x1A5BF4u;
            goto label_1a5bf4;
        }
    }
    ctx->pc = 0x1A5BDCu;
label_1a5bdc:
    // 0x1a5bdc: 0x71880  sll         $v1, $a3, 2
    ctx->pc = 0x1a5bdcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), 2));
    // 0x1a5be0: 0x63080  sll         $a2, $a2, 2
    ctx->pc = 0x1a5be0u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x1a5be4: 0xa31821  addu        $v1, $a1, $v1
    ctx->pc = 0x1a5be4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x1a5be8: 0xa63021  addu        $a2, $a1, $a2
    ctx->pc = 0x1a5be8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0x1a5bec: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x1a5becu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x1a5bf0: 0xac660000  sw          $a2, 0x0($v1)
    ctx->pc = 0x1a5bf0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 6));
label_1a5bf4:
    // 0x1a5bf4: 0xe4182a  slt         $v1, $a3, $a0
    ctx->pc = 0x1a5bf4u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x1a5bf8: 0x1460fff8  bnez        $v1, . + 4 + (-0x8 << 2)
    ctx->pc = 0x1A5BF8u;
    {
        const bool branch_taken_0x1a5bf8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A5BFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5BF8u;
            // 0x1a5bfc: 0x24e60001  addiu       $a2, $a3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a5bf8) {
            ctx->pc = 0x1A5BDCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a5bdc;
        }
    }
    ctx->pc = 0x1A5C00u;
    // 0x1a5c00: 0x71880  sll         $v1, $a3, 2
    ctx->pc = 0x1a5c00u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), 2));
    // 0x1a5c04: 0xa31821  addu        $v1, $a1, $v1
    ctx->pc = 0x1a5c04u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x1a5c08: 0x3e00008  jr          $ra
    ctx->pc = 0x1A5C08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A5C0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5C08u;
            // 0x1a5c0c: 0xac600000  sw          $zero, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A5BDCu: goto label_1a5bdc;
            case 0x1A5BF4u: goto label_1a5bf4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A5C10u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
