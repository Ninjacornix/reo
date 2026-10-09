#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016A118
// Address: 0x16a118 - 0x16a138
void sub_0016A118_0x16a118(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016A118_0x16a118");
#endif

    switch (ctx->pc) {
        case 0x16a128u: goto label_16a128;
        default: break;
    }

    ctx->pc = 0x16a118u;

    // 0x16a118: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x16a118u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16a11c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16a11cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x16a120: 0xc056056  jal         func_158158
    ctx->pc = 0x16A120u;
    SET_GPR_U32(ctx, 31, 0x16A128u);
    ctx->pc = 0x158158u;
    if (runtime->hasFunction(0x158158u)) {
        auto targetFn = runtime->lookupFunction(0x158158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A128u; }
        if (ctx->pc != 0x16A128u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00158158_0x158158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A128u; }
        if (ctx->pc != 0x16A128u) { return; }
    }
    ctx->pc = 0x16A128u;
label_16a128:
    // 0x16a128: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16a128u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16a12c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x16a12cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a130: 0x3e00008  jr          $ra
    ctx->pc = 0x16A130u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16A134u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A130u;
            // 0x16a134: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16A128u: goto label_16a128;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16A138u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
