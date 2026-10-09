#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013D498
// Address: 0x13d498 - 0x13d4b8
void sub_0013D498_0x13d498(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013D498_0x13d498");
#endif

    switch (ctx->pc) {
        case 0x13d4a8u: goto label_13d4a8;
        default: break;
    }

    ctx->pc = 0x13d498u;

    // 0x13d498: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13d498u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13d49c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13d49cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13d4a0: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x13D4A0u;
    SET_GPR_U32(ctx, 31, 0x13D4A8u);
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D4A8u; }
        if (ctx->pc != 0x13D4A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D4A8u; }
        if (ctx->pc != 0x13D4A8u) { return; }
    }
    ctx->pc = 0x13D4A8u;
label_13d4a8:
    // 0x13d4a8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13d4a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13d4ac: 0x3e00008  jr          $ra
    ctx->pc = 0x13D4ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13D4B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D4ACu;
            // 0x13d4b0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13D4A8u: goto label_13d4a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13D4B4u;
    // 0x13d4b4: 0x0  nop
    ctx->pc = 0x13d4b4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
