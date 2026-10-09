#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00189BB8
// Address: 0x189bb8 - 0x189be0
void sub_00189BB8_0x189bb8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00189BB8_0x189bb8");
#endif

    ctx->pc = 0x189bb8u;

label_189bb8:
    // 0x189bb8: 0x78820000  lq          $v0, 0x0($a0)
    ctx->pc = 0x189bb8u;
    SET_GPR_VEC(ctx, 2, READ128(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x189bbc: 0x78830010  lq          $v1, 0x10($a0)
    ctx->pc = 0x189bbcu;
    SET_GPR_VEC(ctx, 3, READ128(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x189bc0: 0x7ca20000  sq          $v0, 0x0($a1)
    ctx->pc = 0x189bc0u;
    WRITE128(ADD32(GPR_U32(ctx, 5), 0), GPR_VEC(ctx, 2));
    // 0x189bc4: 0x7ca30010  sq          $v1, 0x10($a1)
    ctx->pc = 0x189bc4u;
    WRITE128(ADD32(GPR_U32(ctx, 5), 16), GPR_VEC(ctx, 3));
    // 0x189bc8: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x189bc8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x189bcc: 0x24840020  addiu       $a0, $a0, 0x20
    ctx->pc = 0x189bccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
    // 0x189bd0: 0x14c0fff9  bnez        $a2, . + 4 + (-0x7 << 2)
    ctx->pc = 0x189BD0u;
    {
        const bool branch_taken_0x189bd0 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x189BD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189BD0u;
            // 0x189bd4: 0x24a50020  addiu       $a1, $a1, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189bd0) {
            ctx->pc = 0x189BB8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_189bb8;
        }
    }
    ctx->pc = 0x189BD8u;
    // 0x189bd8: 0x3e00008  jr          $ra
    ctx->pc = 0x189BD8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x189BB8u: goto label_189bb8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x189BE0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
