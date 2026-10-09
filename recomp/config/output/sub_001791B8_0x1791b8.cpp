#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001791B8
// Address: 0x1791b8 - 0x179208
void sub_001791B8_0x1791b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001791B8_0x1791b8");
#endif

    switch (ctx->pc) {
        case 0x1791c8u: goto label_1791c8;
        default: break;
    }

    ctx->pc = 0x1791b8u;

    // 0x1791b8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1791b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1791bc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1791bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1791c0: 0xc05e482  jal         func_179208
    ctx->pc = 0x1791C0u;
    SET_GPR_U32(ctx, 31, 0x1791C8u);
    ctx->pc = 0x179208u;
    if (runtime->hasFunction(0x179208u)) {
        auto targetFn = runtime->lookupFunction(0x179208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1791C8u; }
        if (ctx->pc != 0x1791C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179208_0x179208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1791C8u; }
        if (ctx->pc != 0x1791C8u) { return; }
    }
    ctx->pc = 0x1791C8u;
label_1791c8:
    // 0x1791c8: 0x3c030027  lui         $v1, 0x27
    ctx->pc = 0x1791c8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)39 << 16));
    // 0x1791cc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1791ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1791d0: 0x24636138  addiu       $v1, $v1, 0x6138
    ctx->pc = 0x1791d0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 24888));
    // 0x1791d4: 0x8c620004  lw          $v0, 0x4($v1)
    ctx->pc = 0x1791d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x1791d8: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1791d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1791dc: 0xac620004  sw          $v0, 0x4($v1)
    ctx->pc = 0x1791dcu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
    // 0x1791e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1791E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1791E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1791E0u;
            // 0x1791e4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1791C8u: goto label_1791c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1791E8u;
    // 0x1791e8: 0xac800008  sw          $zero, 0x8($a0)
    ctx->pc = 0x1791e8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 0));
    // 0x1791ec: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x1791ecu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x1791f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1791F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1791F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1791F0u;
            // 0x1791f4: 0xac800004  sw          $zero, 0x4($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1791C8u: goto label_1791c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1791F8u;
    // 0x1791f8: 0xac860008  sw          $a2, 0x8($a0)
    ctx->pc = 0x1791f8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 6));
    // 0x1791fc: 0xac850000  sw          $a1, 0x0($a0)
    ctx->pc = 0x1791fcu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
    // 0x179200: 0x3e00008  jr          $ra
    ctx->pc = 0x179200u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x179204u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179200u;
            // 0x179204: 0xac800004  sw          $zero, 0x4($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1791C8u: goto label_1791c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x179208u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
