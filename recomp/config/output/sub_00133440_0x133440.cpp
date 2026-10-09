#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00133440
// Address: 0x133440 - 0x133470
void sub_00133440_0x133440(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00133440_0x133440");
#endif

    ctx->pc = 0x133440u;

    // 0x133440: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x133440u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x133444: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x133444u;
    {
        const bool branch_taken_0x133444 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x133448u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x133444u;
            // 0x133448: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x133444) {
            ctx->pc = 0x133460u;
            goto label_133460;
        }
    }
    ctx->pc = 0x13344Cu;
    // 0x13344c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13344cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x133450: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x133450u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x133454: 0x2484b548  addiu       $a0, $a0, -0x4AB8
    ctx->pc = 0x133454u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948168));
    // 0x133458: 0x804a034  j           func_1280D0
    ctx->pc = 0x133458u;
    ctx->pc = 0x13345Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133458u;
            // 0x13345c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x133460u;
label_133460:
    // 0x133460: 0x8c840004  lw          $a0, 0x4($a0)
    ctx->pc = 0x133460u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x133464: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x133464u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x133468: 0x804b5be  j           func_12D6F8
    ctx->pc = 0x133468u;
    ctx->pc = 0x13346Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x133468u;
            // 0x13346c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D6F8u;
    if (runtime->hasFunction(0x12D6F8u)) {
        auto targetFn = runtime->lookupFunction(0x12D6F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0012D6F8_0x12d6f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x133470u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
