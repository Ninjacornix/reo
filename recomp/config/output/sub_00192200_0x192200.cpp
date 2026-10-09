#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00192200
// Address: 0x192200 - 0x19221c
void sub_00192200_0x192200(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00192200_0x192200");
#endif

    switch (ctx->pc) {
        case 0x192210u: goto label_192210;
        default: break;
    }

    ctx->pc = 0x192200u;

    // 0x192200: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x192200u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x192204: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x192204u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x192208: 0xc0428bc  jal         func_10A2F0
    ctx->pc = 0x192208u;
    SET_GPR_U32(ctx, 31, 0x192210u);
    ctx->pc = 0x19220Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x192208u;
            // 0x19220c: 0x27a4001c  addiu       $a0, $sp, 0x1C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 28));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A2F0u;
    if (runtime->hasFunction(0x10A2F0u)) {
        auto targetFn = runtime->lookupFunction(0x10A2F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192210u; }
        if (ctx->pc != 0x192210u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A2F0_0x10a2f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192210u; }
        if (ctx->pc != 0x192210u) { return; }
    }
    ctx->pc = 0x192210u;
label_192210:
    // 0x192210: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x192210u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x192214: 0x3e00008  jr          $ra
    ctx->pc = 0x192214u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x192218u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192214u;
            // 0x192218: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x192210u: goto label_192210;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19221Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
