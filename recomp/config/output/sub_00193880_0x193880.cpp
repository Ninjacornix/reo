#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00193880
// Address: 0x193880 - 0x1938a0
void sub_00193880_0x193880(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00193880_0x193880");
#endif

    ctx->pc = 0x193880u;

    // 0x193880: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x193880u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x193884: 0x3c050029  lui         $a1, 0x29
    ctx->pc = 0x193884u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)41 << 16));
    // 0x193888: 0x44826000  mtc1        $v0, $f12
    ctx->pc = 0x193888u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[12], &bits, sizeof(bits)); }
    // 0x19388c: 0x24a54e00  addiu       $a1, $a1, 0x4E00
    ctx->pc = 0x19388cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 19968));
    // 0x193890: 0x46006346  mov.s       $f13, $f12
    ctx->pc = 0x193890u;
    ctx->f[13] = FPU_MOV_S(ctx->f[12]);
    // 0x193894: 0x8064e28  j           func_1938A0
    ctx->pc = 0x193894u;
    ctx->pc = 0x193898u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193894u;
            // 0x193898: 0x46006386  mov.s       $f14, $f12 (Delay Slot)
        ctx->f[14] = FPU_MOV_S(ctx->f[12]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1938A0u;
    if (runtime->hasFunction(0x1938A0u)) {
        auto targetFn = runtime->lookupFunction(0x1938A0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001938A0_0x1938a0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x19389Cu;
    // 0x19389c: 0x0  nop
    ctx->pc = 0x19389cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
