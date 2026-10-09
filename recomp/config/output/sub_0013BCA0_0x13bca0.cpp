#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013BCA0
// Address: 0x13bca0 - 0x13bcc0
void sub_0013BCA0_0x13bca0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013BCA0_0x13bca0");
#endif

    switch (ctx->pc) {
        case 0x13bcb0u: goto label_13bcb0;
        default: break;
    }

    ctx->pc = 0x13bca0u;

    // 0x13bca0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13bca0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13bca4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13bca4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13bca8: 0xc04ef0e  jal         func_13BC38
    ctx->pc = 0x13BCA8u;
    SET_GPR_U32(ctx, 31, 0x13BCB0u);
    ctx->pc = 0x13BC38u;
    if (runtime->hasFunction(0x13BC38u)) {
        auto targetFn = runtime->lookupFunction(0x13BC38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BCB0u; }
        if (ctx->pc != 0x13BCB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013BC38_0x13bc38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13BCB0u; }
        if (ctx->pc != 0x13BCB0u) { return; }
    }
    ctx->pc = 0x13BCB0u;
label_13bcb0:
    // 0x13bcb0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13bcb0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13bcb4: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x13bcb4u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x13bcb8: 0x3e00008  jr          $ra
    ctx->pc = 0x13BCB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13BCBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13BCB8u;
            // 0x13bcbc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13BCB0u: goto label_13bcb0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13BCC0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
