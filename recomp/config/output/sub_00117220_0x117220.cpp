#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00117220
// Address: 0x117220 - 0x117248
void sub_00117220_0x117220(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00117220_0x117220");
#endif

    switch (ctx->pc) {
        case 0x117230u: goto label_117230;
        default: break;
    }

    ctx->pc = 0x117220u;

    // 0x117220: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x117220u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x117224: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x117224u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x117228: 0xc045ae8  jal         func_116BA0
    ctx->pc = 0x117228u;
    SET_GPR_U32(ctx, 31, 0x117230u);
    ctx->pc = 0x116BA0u;
    if (runtime->hasFunction(0x116BA0u)) {
        auto targetFn = runtime->lookupFunction(0x116BA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117230u; }
        if (ctx->pc != 0x117230u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116BA0_0x116ba0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117230u; }
        if (ctx->pc != 0x117230u) { return; }
    }
    ctx->pc = 0x117230u;
label_117230:
    // 0x117230: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x117230u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x117234: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x117234u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x117238: 0xac409d50  sw          $zero, -0x62B0($v0)
    ctx->pc = 0x117238u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294942032), GPR_U32(ctx, 0));
    // 0x11723c: 0x3e00008  jr          $ra
    ctx->pc = 0x11723Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x117240u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11723Cu;
            // 0x117240: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x117230u: goto label_117230;
            default: break;
        }
        return;
    }
    ctx->pc = 0x117244u;
    // 0x117244: 0x0  nop
    ctx->pc = 0x117244u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
