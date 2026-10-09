#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001491A0
// Address: 0x1491a0 - 0x1491c4
void sub_001491A0_0x1491a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001491A0_0x1491a0");
#endif

    switch (ctx->pc) {
        case 0x1491b4u: goto label_1491b4;
        default: break;
    }

    ctx->pc = 0x1491a0u;

    // 0x1491a0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1491a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1491a4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1491a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1491a8: 0x8c840040  lw          $a0, 0x40($a0)
    ctx->pc = 0x1491a8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x1491ac: 0xc044f60  jal         func_113D80
    ctx->pc = 0x1491ACu;
    SET_GPR_U32(ctx, 31, 0x1491B4u);
    ctx->pc = 0x1491B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1491ACu;
            // 0x1491b0: 0x24840068  addiu       $a0, $a0, 0x68 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 104));
        ctx->in_delay_slot = false;
    ctx->pc = 0x113D80u;
    if (runtime->hasFunction(0x113D80u)) {
        auto targetFn = runtime->lookupFunction(0x113D80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1491B4u; }
        if (ctx->pc != 0x1491B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00113D80_0x113d80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1491B4u; }
        if (ctx->pc != 0x1491B4u) { return; }
    }
    ctx->pc = 0x1491B4u;
label_1491b4:
    // 0x1491b4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1491b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1491b8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1491b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1491bc: 0x3e00008  jr          $ra
    ctx->pc = 0x1491BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1491C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1491BCu;
            // 0x1491c0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1491B4u: goto label_1491b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1491C4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
