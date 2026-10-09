#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001719C8
// Address: 0x1719c8 - 0x1719ec
void sub_001719C8_0x1719c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001719C8_0x1719c8");
#endif

    switch (ctx->pc) {
        case 0x1719dcu: goto label_1719dc;
        default: break;
    }

    ctx->pc = 0x1719c8u;

    // 0x1719c8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1719c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1719cc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1719ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1719d0: 0x8cc41b30  lw          $a0, 0x1B30($a2)
    ctx->pc = 0x1719d0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 6960)));
    // 0x1719d4: 0xc05c458  jal         func_171160
    ctx->pc = 0x1719D4u;
    SET_GPR_U32(ctx, 31, 0x1719DCu);
    ctx->pc = 0x1719D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1719D4u;
            // 0x1719d8: 0x24840a48  addiu       $a0, $a0, 0xA48 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2632));
        ctx->in_delay_slot = false;
    ctx->pc = 0x171160u;
    if (runtime->hasFunction(0x171160u)) {
        auto targetFn = runtime->lookupFunction(0x171160u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1719DCu; }
        if (ctx->pc != 0x1719DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00171160_0x171160(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1719DCu; }
        if (ctx->pc != 0x1719DCu) { return; }
    }
    ctx->pc = 0x1719DCu;
label_1719dc:
    // 0x1719dc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1719dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1719e0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1719e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1719e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1719E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1719E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1719E4u;
            // 0x1719e8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1719DCu: goto label_1719dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1719ECu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
