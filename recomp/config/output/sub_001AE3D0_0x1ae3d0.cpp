#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AE3D0
// Address: 0x1ae3d0 - 0x1ae3f0
void sub_001AE3D0_0x1ae3d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AE3D0_0x1ae3d0");
#endif

    switch (ctx->pc) {
        case 0x1ae3e0u: goto label_1ae3e0;
        default: break;
    }

    ctx->pc = 0x1ae3d0u;

    // 0x1ae3d0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1ae3d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1ae3d4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1ae3d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1ae3d8: 0xc04cd0a  jal         func_133428
    ctx->pc = 0x1AE3D8u;
    SET_GPR_U32(ctx, 31, 0x1AE3E0u);
    ctx->pc = 0x133428u;
    if (runtime->hasFunction(0x133428u)) {
        auto targetFn = runtime->lookupFunction(0x133428u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE3E0u; }
        if (ctx->pc != 0x1AE3E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00133428_0x133428(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE3E0u; }
        if (ctx->pc != 0x1AE3E0u) { return; }
    }
    ctx->pc = 0x1AE3E0u;
label_1ae3e0:
    // 0x1ae3e0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1ae3e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ae3e4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ae3e4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ae3e8: 0x3e00008  jr          $ra
    ctx->pc = 0x1AE3E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AE3ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE3E8u;
            // 0x1ae3ec: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AE3E0u: goto label_1ae3e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AE3F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
