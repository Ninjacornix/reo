#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00122EC0
// Address: 0x122ec0 - 0x122eec
void sub_00122EC0_0x122ec0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00122EC0_0x122ec0");
#endif

    switch (ctx->pc) {
        case 0x122ee0u: goto label_122ee0;
        default: break;
    }

    ctx->pc = 0x122ec0u;

    // 0x122ec0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x122ec0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x122ec4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x122ec4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x122ec8: 0x8c8200bc  lw          $v0, 0xBC($a0)
    ctx->pc = 0x122ec8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 188)));
    // 0x122ecc: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x122ECCu;
    {
        const bool branch_taken_0x122ecc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x122ED0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122ECCu;
            // 0x122ed0: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x122ecc) {
            ctx->pc = 0x122EE0u;
            goto label_122ee0;
        }
    }
    ctx->pc = 0x122ED4u;
    // 0x122ed4: 0x8c43b720  lw          $v1, -0x48E0($v0)
    ctx->pc = 0x122ed4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294948640)));
    // 0x122ed8: 0x60f809  jalr        $v1
    ctx->pc = 0x122ED8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x122EE0u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x122EE0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122EE0u: goto label_122ee0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x122EE0u; }
            if (ctx->pc != 0x122EE0u) { return; }
        }
        }
    }
    ctx->pc = 0x122EE0u;
label_122ee0:
    // 0x122ee0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x122ee0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x122ee4: 0x3e00008  jr          $ra
    ctx->pc = 0x122EE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x122EE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122EE4u;
            // 0x122ee8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122EE0u: goto label_122ee0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x122EECu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
