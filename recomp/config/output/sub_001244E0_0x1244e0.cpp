#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001244E0
// Address: 0x1244e0 - 0x124514
void sub_001244E0_0x1244e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001244E0_0x1244e0");
#endif

    switch (ctx->pc) {
        case 0x124504u: goto label_124504;
        default: break;
    }

    ctx->pc = 0x1244e0u;

    // 0x1244e0: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x1244e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x1244e4: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1244e4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1244e8: 0x8c43b940  lw          $v1, -0x46C0($v0)
    ctx->pc = 0x1244e8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294949184)));
    // 0x1244ec: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x1244ecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1244f0: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1244F0u;
    {
        const bool branch_taken_0x1244f0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1244F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1244F0u;
            // 0x1244f4: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1244f0) {
            ctx->pc = 0x124504u;
            goto label_124504;
        }
    }
    ctx->pc = 0x1244F8u;
    // 0x1244f8: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x1244f8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x1244fc: 0x60f809  jalr        $v1
    ctx->pc = 0x1244FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x124504u);
        ctx->pc = 0x124500u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1244FCu;
            // 0x124500: 0x8c44b944  lw          $a0, -0x46BC($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294949188)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x124504u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x124504u: goto label_124504;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x124504u; }
            if (ctx->pc != 0x124504u) { return; }
        }
        }
    }
    ctx->pc = 0x124504u;
label_124504:
    // 0x124504: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x124504u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x124508: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x124508u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12450c: 0x3e00008  jr          $ra
    ctx->pc = 0x12450Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x124510u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12450Cu;
            // 0x124510: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x124504u: goto label_124504;
            default: break;
        }
        return;
    }
    ctx->pc = 0x124514u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
