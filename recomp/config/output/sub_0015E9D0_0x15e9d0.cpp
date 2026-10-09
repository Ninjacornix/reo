#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015E9D0
// Address: 0x15e9d0 - 0x15ea00
void sub_0015E9D0_0x15e9d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015E9D0_0x15e9d0");
#endif

    ctx->pc = 0x15e9d0u;

    // 0x15e9d0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15e9d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15e9d4: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x15e9d4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x15e9d8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15e9d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15e9dc: 0x2442de50  addiu       $v0, $v0, -0x21B0
    ctx->pc = 0x15e9dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294958672));
    // 0x15e9e0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x15e9e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x15e9e4: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x15E9E4u;
    {
        const bool branch_taken_0x15e9e4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x15E9E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E9E4u;
            // 0x15e9e8: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15e9e4) {
            ctx->pc = 0x15E9F8u;
            goto label_15e9f8;
        }
    }
    ctx->pc = 0x15E9ECu;
    // 0x15e9ec: 0x0  nop
    ctx->pc = 0x15e9ecu;
    // NOP
    // 0x15e9f0: 0x80579a8  j           func_15E6A0
    ctx->pc = 0x15E9F0u;
    ctx->pc = 0x15E9F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E9F0u;
            // 0x15e9f4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15E6A0u;
    if (runtime->hasFunction(0x15E6A0u)) {
        auto targetFn = runtime->lookupFunction(0x15E6A0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0015E6A0_0x15e6a0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15E9F8u;
label_15e9f8:
    // 0x15e9f8: 0x3e00008  jr          $ra
    ctx->pc = 0x15E9F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15E9FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E9F8u;
            // 0x15e9fc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15E9F8u: goto label_15e9f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15EA00u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
