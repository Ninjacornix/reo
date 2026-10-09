#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001636B0
// Address: 0x1636b0 - 0x163700
void sub_001636B0_0x1636b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001636B0_0x1636b0");
#endif

    switch (ctx->pc) {
        case 0x1636d8u: goto label_1636d8;
        default: break;
    }

    ctx->pc = 0x1636b0u;

    // 0x1636b0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1636b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1636b4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1636b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1636b8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1636b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1636bc: 0x80505e4  j           func_141790
    ctx->pc = 0x1636BCu;
    ctx->pc = 0x1636C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1636BCu;
            // 0x1636c0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141790u;
    if (runtime->hasFunction(0x141790u)) {
        auto targetFn = runtime->lookupFunction(0x141790u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00141790_0x141790(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1636C4u;
    // 0x1636c4: 0x0  nop
    ctx->pc = 0x1636c4u;
    // NOP
    // 0x1636c8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1636c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1636cc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1636ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1636d0: 0xc0505cc  jal         func_141730
    ctx->pc = 0x1636D0u;
    SET_GPR_U32(ctx, 31, 0x1636D8u);
    ctx->pc = 0x141730u;
    if (runtime->hasFunction(0x141730u)) {
        auto targetFn = runtime->lookupFunction(0x141730u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1636D8u; }
        if (ctx->pc != 0x1636D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141730_0x141730(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1636D8u; }
        if (ctx->pc != 0x1636D8u) { return; }
    }
    ctx->pc = 0x1636D8u;
label_1636d8:
    // 0x1636d8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1636d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1636dc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1636dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1636e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1636E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1636E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1636E0u;
            // 0x1636e4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1636D8u: goto label_1636d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1636E8u;
    // 0x1636e8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1636e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1636ec: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1636ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1636f0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1636f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1636f4: 0x80505ea  j           func_1417A8
    ctx->pc = 0x1636F4u;
    ctx->pc = 0x1636F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1636F4u;
            // 0x1636f8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1417A8u;
    if (runtime->hasFunction(0x1417A8u)) {
        auto targetFn = runtime->lookupFunction(0x1417A8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001417A8_0x1417a8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1636FCu;
    // 0x1636fc: 0x0  nop
    ctx->pc = 0x1636fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
