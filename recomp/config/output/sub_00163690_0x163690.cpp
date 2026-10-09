#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00163690
// Address: 0x163690 - 0x1636b0
void sub_00163690_0x163690(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00163690_0x163690");
#endif

    switch (ctx->pc) {
        case 0x1636a0u: goto label_1636a0;
        default: break;
    }

    ctx->pc = 0x163690u;

    // 0x163690: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x163690u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x163694: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x163694u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x163698: 0xc0505c6  jal         func_141718
    ctx->pc = 0x163698u;
    SET_GPR_U32(ctx, 31, 0x1636A0u);
    ctx->pc = 0x141718u;
    if (runtime->hasFunction(0x141718u)) {
        auto targetFn = runtime->lookupFunction(0x141718u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1636A0u; }
        if (ctx->pc != 0x1636A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141718_0x141718(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1636A0u; }
        if (ctx->pc != 0x1636A0u) { return; }
    }
    ctx->pc = 0x1636A0u;
label_1636a0:
    // 0x1636a0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1636a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1636a4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1636a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1636a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1636A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1636ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1636A8u;
            // 0x1636ac: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1636A0u: goto label_1636a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1636B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
