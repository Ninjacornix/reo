#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00122FF0
// Address: 0x122ff0 - 0x123020
void sub_00122FF0_0x122ff0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00122FF0_0x122ff0");
#endif

    switch (ctx->pc) {
        case 0x123014u: goto label_123014;
        default: break;
    }

    ctx->pc = 0x122ff0u;

    // 0x122ff0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x122ff0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x122ff4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x122ff4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x122ff8: 0x8c8200b0  lw          $v0, 0xB0($a0)
    ctx->pc = 0x122ff8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 176)));
    // 0x122ffc: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x122FFCu;
    {
        const bool branch_taken_0x122ffc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x123000u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122FFCu;
            // 0x123000: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x122ffc) {
            ctx->pc = 0x123014u;
            goto label_123014;
        }
    }
    ctx->pc = 0x123004u;
    // 0x123004: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x123004u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x123008: 0x8c43b728  lw          $v1, -0x48D8($v0)
    ctx->pc = 0x123008u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294948648)));
    // 0x12300c: 0x60f809  jalr        $v1
    ctx->pc = 0x12300Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x123014u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x123014u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123014u: goto label_123014;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x123014u; }
            if (ctx->pc != 0x123014u) { return; }
        }
        }
    }
    ctx->pc = 0x123014u;
label_123014:
    // 0x123014: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x123014u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x123018: 0x3e00008  jr          $ra
    ctx->pc = 0x123018u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12301Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123018u;
            // 0x12301c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123014u: goto label_123014;
            default: break;
        }
        return;
    }
    ctx->pc = 0x123020u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
