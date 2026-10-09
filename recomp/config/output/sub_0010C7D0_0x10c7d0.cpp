#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010C7D0
// Address: 0x10c7d0 - 0x10c7f8
void sub_0010C7D0_0x10c7d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010C7D0_0x10c7d0");
#endif

    switch (ctx->pc) {
        case 0x10c7e0u: goto label_10c7e0;
        case 0x10c7ecu: goto label_10c7ec;
        default: break;
    }

    ctx->pc = 0x10c7d0u;

    // 0x10c7d0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x10c7d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x10c7d4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x10c7d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x10c7d8: 0xc0431ea  jal         func_10C7A8
    ctx->pc = 0x10C7D8u;
    SET_GPR_U32(ctx, 31, 0x10C7E0u);
    ctx->pc = 0x10C7A8u;
    if (runtime->hasFunction(0x10C7A8u)) {
        auto targetFn = runtime->lookupFunction(0x10C7A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C7E0u; }
        if (ctx->pc != 0x10C7E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010C7A8_0x10c7a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C7E0u; }
        if (ctx->pc != 0x10C7E0u) { return; }
    }
    ctx->pc = 0x10C7E0u;
label_10c7e0:
    // 0x10c7e0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x10c7e0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c7e4: 0xc04491c  jal         func_112470
    ctx->pc = 0x10C7E4u;
    SET_GPR_U32(ctx, 31, 0x10C7ECu);
    ctx->pc = 0x112470u;
    if (runtime->hasFunction(0x112470u)) {
        auto targetFn = runtime->lookupFunction(0x112470u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C7ECu; }
        if (ctx->pc != 0x10C7ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112470_0x112470(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C7ECu; }
        if (ctx->pc != 0x10C7ECu) { return; }
    }
    ctx->pc = 0x10C7ECu;
label_10c7ec:
    // 0x10c7ec: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x10c7ecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10c7f0: 0x3e00008  jr          $ra
    ctx->pc = 0x10C7F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10C7F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C7F0u;
            // 0x10c7f4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10C7E0u: goto label_10c7e0;
            case 0x10C7ECu: goto label_10c7ec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10C7F8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
