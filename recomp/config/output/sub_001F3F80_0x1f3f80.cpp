#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F3F80
// Address: 0x1f3f80 - 0x1f3fbc
void sub_001F3F80_0x1f3f80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F3F80_0x1f3f80");
#endif

    switch (ctx->pc) {
        case 0x1f3f88u: goto label_1f3f88;
        default: break;
    }

    ctx->pc = 0x1f3f80u;

    // 0x1f3f80: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1f3f80u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3f84: 0x861821  addu        $v1, $a0, $a2
    ctx->pc = 0x1f3f84u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
label_1f3f88:
    // 0x1f3f88: 0x24650e0d  addiu       $a1, $v1, 0xE0D
    ctx->pc = 0x1f3f88u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 3597));
    // 0x1f3f8c: 0x80630e0d  lb          $v1, 0xE0D($v1)
    ctx->pc = 0x1f3f8cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 3597)));
    // 0x1f3f90: 0x4600003  bltz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F3F90u;
    {
        const bool branch_taken_0x1f3f90 = (GPR_S64(ctx, 3) < 0);
        ctx->pc = 0x1F3F94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F3F90u;
            // 0x1f3f94: 0x28610003  slti        $at, $v1, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)3) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f3f90) {
            ctx->pc = 0x1F3FA0u;
            goto label_1f3fa0;
        }
    }
    ctx->pc = 0x1F3F98u;
    // 0x1f3f98: 0x14200002  bnez        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1F3F98u;
    {
        const bool branch_taken_0x1f3f98 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f3f98) {
            ctx->pc = 0x1F3FA4u;
            goto label_1f3fa4;
        }
    }
    ctx->pc = 0x1F3FA0u;
label_1f3fa0:
    // 0x1f3fa0: 0xa0a00000  sb          $zero, 0x0($a1)
    ctx->pc = 0x1f3fa0u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 0));
label_1f3fa4:
    // 0x1f3fa4: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1f3fa4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1f3fa8: 0x28c30010  slti        $v1, $a2, 0x10
    ctx->pc = 0x1f3fa8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1f3fac: 0x1460fff6  bnez        $v1, . + 4 + (-0xA << 2)
    ctx->pc = 0x1F3FACu;
    {
        const bool branch_taken_0x1f3fac = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F3FB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F3FACu;
            // 0x1f3fb0: 0x861821  addu        $v1, $a0, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f3fac) {
            ctx->pc = 0x1F3F88u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f3f88;
        }
    }
    ctx->pc = 0x1F3FB4u;
    // 0x1f3fb4: 0x3e00008  jr          $ra
    ctx->pc = 0x1F3FB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F3F88u: goto label_1f3f88;
            case 0x1F3FA0u: goto label_1f3fa0;
            case 0x1F3FA4u: goto label_1f3fa4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F3FBCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
