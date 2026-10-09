#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001644F0
// Address: 0x1644f0 - 0x164510
void sub_001644F0_0x1644f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001644F0_0x1644f0");
#endif

    switch (ctx->pc) {
        case 0x164500u: goto label_164500;
        default: break;
    }

    ctx->pc = 0x1644f0u;

    // 0x1644f0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1644f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1644f4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1644f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1644f8: 0xc04c196  jal         func_130658
    ctx->pc = 0x1644F8u;
    SET_GPR_U32(ctx, 31, 0x164500u);
    ctx->pc = 0x130658u;
    if (runtime->hasFunction(0x130658u)) {
        auto targetFn = runtime->lookupFunction(0x130658u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164500u; }
        if (ctx->pc != 0x164500u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130658_0x130658(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164500u; }
        if (ctx->pc != 0x164500u) { return; }
    }
    ctx->pc = 0x164500u;
label_164500:
    // 0x164500: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x164500u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x164504: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x164504u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164508: 0x3e00008  jr          $ra
    ctx->pc = 0x164508u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16450Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164508u;
            // 0x16450c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x164500u: goto label_164500;
            default: break;
        }
        return;
    }
    ctx->pc = 0x164510u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
