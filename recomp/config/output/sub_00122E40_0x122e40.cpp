#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00122E40
// Address: 0x122e40 - 0x122e70
void sub_00122E40_0x122e40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00122E40_0x122e40");
#endif

    switch (ctx->pc) {
        case 0x122e64u: goto label_122e64;
        default: break;
    }

    ctx->pc = 0x122e40u;

    // 0x122e40: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x122e40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x122e44: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x122e44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x122e48: 0x8c8200bc  lw          $v0, 0xBC($a0)
    ctx->pc = 0x122e48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 188)));
    // 0x122e4c: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x122E4Cu;
    {
        const bool branch_taken_0x122e4c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x122E50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122E4Cu;
            // 0x122e50: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x122e4c) {
            ctx->pc = 0x122E64u;
            goto label_122e64;
        }
    }
    ctx->pc = 0x122E54u;
    // 0x122e54: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x122e54u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x122e58: 0x8c43b718  lw          $v1, -0x48E8($v0)
    ctx->pc = 0x122e58u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294948632)));
    // 0x122e5c: 0x60f809  jalr        $v1
    ctx->pc = 0x122E5Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x122E64u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x122E64u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122E64u: goto label_122e64;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x122E64u; }
            if (ctx->pc != 0x122E64u) { return; }
        }
        }
    }
    ctx->pc = 0x122E64u;
label_122e64:
    // 0x122e64: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x122e64u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x122e68: 0x3e00008  jr          $ra
    ctx->pc = 0x122E68u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x122E6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122E68u;
            // 0x122e6c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122E64u: goto label_122e64;
            default: break;
        }
        return;
    }
    ctx->pc = 0x122E70u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
