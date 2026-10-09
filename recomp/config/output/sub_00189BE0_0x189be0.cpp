#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00189BE0
// Address: 0x189be0 - 0x189c30
void sub_00189BE0_0x189be0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00189BE0_0x189be0");
#endif

    switch (ctx->pc) {
        case 0x189c18u: goto label_189c18;
        default: break;
    }

    ctx->pc = 0x189be0u;

label_189be0:
    // 0x189be0: 0x78820000  lq          $v0, 0x0($a0)
    ctx->pc = 0x189be0u;
    SET_GPR_VEC(ctx, 2, READ128(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x189be4: 0x78830010  lq          $v1, 0x10($a0)
    ctx->pc = 0x189be4u;
    SET_GPR_VEC(ctx, 3, READ128(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x189be8: 0x78880020  lq          $t0, 0x20($a0)
    ctx->pc = 0x189be8u;
    SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 4), 32)));
    // 0x189bec: 0x78890030  lq          $t1, 0x30($a0)
    ctx->pc = 0x189becu;
    SET_GPR_VEC(ctx, 9, READ128(ADD32(GPR_U32(ctx, 4), 48)));
    // 0x189bf0: 0x7ca20000  sq          $v0, 0x0($a1)
    ctx->pc = 0x189bf0u;
    WRITE128(ADD32(GPR_U32(ctx, 5), 0), GPR_VEC(ctx, 2));
    // 0x189bf4: 0x7ca30010  sq          $v1, 0x10($a1)
    ctx->pc = 0x189bf4u;
    WRITE128(ADD32(GPR_U32(ctx, 5), 16), GPR_VEC(ctx, 3));
    // 0x189bf8: 0x7ca80020  sq          $t0, 0x20($a1)
    ctx->pc = 0x189bf8u;
    WRITE128(ADD32(GPR_U32(ctx, 5), 32), GPR_VEC(ctx, 8));
    // 0x189bfc: 0x7ca90030  sq          $t1, 0x30($a1)
    ctx->pc = 0x189bfcu;
    WRITE128(ADD32(GPR_U32(ctx, 5), 48), GPR_VEC(ctx, 9));
    // 0x189c00: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x189c00u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x189c04: 0x24840040  addiu       $a0, $a0, 0x40
    ctx->pc = 0x189c04u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 64));
    // 0x189c08: 0x14c0fff5  bnez        $a2, . + 4 + (-0xB << 2)
    ctx->pc = 0x189C08u;
    {
        const bool branch_taken_0x189c08 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x189C0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189C08u;
            // 0x189c0c: 0x24a50040  addiu       $a1, $a1, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 64));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189c08) {
            ctx->pc = 0x189BE0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_189be0;
        }
    }
    ctx->pc = 0x189C10u;
    // 0x189c10: 0x3e00008  jr          $ra
    ctx->pc = 0x189C10u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x189BE0u: goto label_189be0;
            case 0x189C18u: goto label_189c18;
            default: break;
        }
        return;
    }
    ctx->pc = 0x189C18u;
label_189c18:
    // 0x189c18: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x189c18u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x189c1c: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x189c1cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x189c20: 0x14a0fffd  bnez        $a1, . + 4 + (-0x3 << 2)
    ctx->pc = 0x189C20u;
    {
        const bool branch_taken_0x189c20 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x189C24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189C20u;
            // 0x189c24: 0x24840004  addiu       $a0, $a0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189c20) {
            ctx->pc = 0x189C18u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_189c18;
        }
    }
    ctx->pc = 0x189C28u;
    // 0x189c28: 0x3e00008  jr          $ra
    ctx->pc = 0x189C28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x189BE0u: goto label_189be0;
            case 0x189C18u: goto label_189c18;
            default: break;
        }
        return;
    }
    ctx->pc = 0x189C30u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
