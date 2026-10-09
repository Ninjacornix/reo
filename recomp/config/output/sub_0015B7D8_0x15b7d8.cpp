#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015B7D8
// Address: 0x15b7d8 - 0x15b808
void sub_0015B7D8_0x15b7d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015B7D8_0x15b7d8");
#endif

    switch (ctx->pc) {
        case 0x15b7e8u: goto label_15b7e8;
        default: break;
    }

    ctx->pc = 0x15b7d8u;

    // 0x15b7d8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15b7d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15b7dc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15b7dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15b7e0: 0xc055600  jal         func_155800
    ctx->pc = 0x15B7E0u;
    SET_GPR_U32(ctx, 31, 0x15B7E8u);
    ctx->pc = 0x155800u;
    if (runtime->hasFunction(0x155800u)) {
        auto targetFn = runtime->lookupFunction(0x155800u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B7E8u; }
        if (ctx->pc != 0x15B7E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00155800_0x155800(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B7E8u; }
        if (ctx->pc != 0x15B7E8u) { return; }
    }
    ctx->pc = 0x15B7E8u;
label_15b7e8:
    // 0x15b7e8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15b7e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15b7ec: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x15b7ecu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x15b7f0: 0x24a54cd0  addiu       $a1, $a1, 0x4CD0
    ctx->pc = 0x15b7f0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 19664));
    // 0x15b7f4: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x15b7f4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x15b7f8: 0x24063840  addiu       $a2, $zero, 0x3840
    ctx->pc = 0x15b7f8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 14400));
    // 0x15b7fc: 0x805409c  j           func_150270
    ctx->pc = 0x15B7FCu;
    ctx->pc = 0x15B800u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15B7FCu;
            // 0x15b800: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x150270u;
    if (runtime->hasFunction(0x150270u)) {
        auto targetFn = runtime->lookupFunction(0x150270u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00150270_0x150270(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15B804u;
    // 0x15b804: 0x0  nop
    ctx->pc = 0x15b804u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
