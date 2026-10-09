#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00189AE0
// Address: 0x189ae0 - 0x189b08
void sub_00189AE0_0x189ae0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00189AE0_0x189ae0");
#endif

    ctx->pc = 0x189ae0u;

label_189ae0:
    // 0x189ae0: 0xdc820000  ld          $v0, 0x0($a0)
    ctx->pc = 0x189ae0u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x189ae4: 0xdc830008  ld          $v1, 0x8($a0)
    ctx->pc = 0x189ae4u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x189ae8: 0xfca20000  sd          $v0, 0x0($a1)
    ctx->pc = 0x189ae8u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 0), GPR_U64(ctx, 2));
    // 0x189aec: 0xfca30008  sd          $v1, 0x8($a1)
    ctx->pc = 0x189aecu;
    WRITE64(ADD32(GPR_U32(ctx, 5), 8), GPR_U64(ctx, 3));
    // 0x189af0: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x189af0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x189af4: 0x24840010  addiu       $a0, $a0, 0x10
    ctx->pc = 0x189af4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16));
    // 0x189af8: 0x14c0fff9  bnez        $a2, . + 4 + (-0x7 << 2)
    ctx->pc = 0x189AF8u;
    {
        const bool branch_taken_0x189af8 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x189AFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189AF8u;
            // 0x189afc: 0x24a50010  addiu       $a1, $a1, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189af8) {
            ctx->pc = 0x189AE0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_189ae0;
        }
    }
    ctx->pc = 0x189B00u;
    // 0x189b00: 0x3e00008  jr          $ra
    ctx->pc = 0x189B00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x189AE0u: goto label_189ae0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x189B08u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
