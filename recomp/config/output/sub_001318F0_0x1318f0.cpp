#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001318F0
// Address: 0x1318f0 - 0x131918
void sub_001318F0_0x1318f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001318F0_0x1318f0");
#endif

    switch (ctx->pc) {
        case 0x13190cu: goto label_13190c;
        default: break;
    }

    ctx->pc = 0x1318f0u;

    // 0x1318f0: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x1318f0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x1318f4: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1318f4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1318f8: 0x8c42b794  lw          $v0, -0x486C($v0)
    ctx->pc = 0x1318f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294948756)));
    // 0x1318fc: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1318FCu;
    {
        const bool branch_taken_0x1318fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x131900u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1318FCu;
            // 0x131900: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1318fc) {
            ctx->pc = 0x13190Cu;
            goto label_13190c;
        }
    }
    ctx->pc = 0x131904u;
    // 0x131904: 0x40f809  jalr        $v0
    ctx->pc = 0x131904u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13190Cu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x13190Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13190Cu: goto label_13190c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13190Cu; }
            if (ctx->pc != 0x13190Cu) { return; }
        }
        }
    }
    ctx->pc = 0x13190Cu;
label_13190c:
    // 0x13190c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13190cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x131910: 0x3e00008  jr          $ra
    ctx->pc = 0x131910u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x131914u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131910u;
            // 0x131914: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13190Cu: goto label_13190c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x131918u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
