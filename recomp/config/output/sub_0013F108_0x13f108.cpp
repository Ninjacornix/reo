#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013F108
// Address: 0x13f108 - 0x13f12c
void sub_0013F108_0x13f108(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013F108_0x13f108");
#endif

    switch (ctx->pc) {
        case 0x13f11cu: goto label_13f11c;
        default: break;
    }

    ctx->pc = 0x13f108u;

    // 0x13f108: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13f108u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13f10c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13f10cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13f110: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13f110u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13f114: 0xc045a12  jal         func_116848
    ctx->pc = 0x13F114u;
    SET_GPR_U32(ctx, 31, 0x13F11Cu);
    ctx->pc = 0x13F118u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F114u;
            // 0x13f118: 0x2484d938  addiu       $a0, $a0, -0x26C8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957368));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F11Cu; }
        if (ctx->pc != 0x13F11Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F11Cu; }
        if (ctx->pc != 0x13F11Cu) { return; }
    }
    ctx->pc = 0x13F11Cu;
label_13f11c:
    // 0x13f11c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x13f11cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f120: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13f120u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13f124: 0x3e00008  jr          $ra
    ctx->pc = 0x13F124u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F128u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F124u;
            // 0x13f128: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13F11Cu: goto label_13f11c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13F12Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
