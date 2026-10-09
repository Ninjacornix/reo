#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00189B80
// Address: 0x189b80 - 0x189bb8
void sub_00189B80_0x189b80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00189B80_0x189b80");
#endif

    ctx->pc = 0x189b80u;

label_189b80:
    // 0x189b80: 0xdc820000  ld          $v0, 0x0($a0)
    ctx->pc = 0x189b80u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x189b84: 0xdc830008  ld          $v1, 0x8($a0)
    ctx->pc = 0x189b84u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x189b88: 0xdc880010  ld          $t0, 0x10($a0)
    ctx->pc = 0x189b88u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x189b8c: 0xdc890018  ld          $t1, 0x18($a0)
    ctx->pc = 0x189b8cu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x189b90: 0xfca20000  sd          $v0, 0x0($a1)
    ctx->pc = 0x189b90u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 0), GPR_U64(ctx, 2));
    // 0x189b94: 0xfca30008  sd          $v1, 0x8($a1)
    ctx->pc = 0x189b94u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 8), GPR_U64(ctx, 3));
    // 0x189b98: 0xfca80010  sd          $t0, 0x10($a1)
    ctx->pc = 0x189b98u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 16), GPR_U64(ctx, 8));
    // 0x189b9c: 0xfca90018  sd          $t1, 0x18($a1)
    ctx->pc = 0x189b9cu;
    WRITE64(ADD32(GPR_U32(ctx, 5), 24), GPR_U64(ctx, 9));
    // 0x189ba0: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x189ba0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x189ba4: 0x24840020  addiu       $a0, $a0, 0x20
    ctx->pc = 0x189ba4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
    // 0x189ba8: 0x14c0fff5  bnez        $a2, . + 4 + (-0xB << 2)
    ctx->pc = 0x189BA8u;
    {
        const bool branch_taken_0x189ba8 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x189BACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189BA8u;
            // 0x189bac: 0x24a50020  addiu       $a1, $a1, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189ba8) {
            ctx->pc = 0x189B80u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_189b80;
        }
    }
    ctx->pc = 0x189BB0u;
    // 0x189bb0: 0x3e00008  jr          $ra
    ctx->pc = 0x189BB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x189B80u: goto label_189b80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x189BB8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
