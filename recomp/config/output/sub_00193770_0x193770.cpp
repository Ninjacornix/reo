#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00193770
// Address: 0x193770 - 0x193790
void sub_00193770_0x193770(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00193770_0x193770");
#endif

    ctx->pc = 0x193770u;

    // 0x193770: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x193770u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x193774: 0x3c050029  lui         $a1, 0x29
    ctx->pc = 0x193774u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)41 << 16));
    // 0x193778: 0x44826000  mtc1        $v0, $f12
    ctx->pc = 0x193778u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[12], &bits, sizeof(bits)); }
    // 0x19377c: 0x24a54e00  addiu       $a1, $a1, 0x4E00
    ctx->pc = 0x19377cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 19968));
    // 0x193780: 0x46006346  mov.s       $f13, $f12
    ctx->pc = 0x193780u;
    ctx->f[13] = FPU_MOV_S(ctx->f[12]);
    // 0x193784: 0x8064de4  j           func_193790
    ctx->pc = 0x193784u;
    ctx->pc = 0x193788u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193784u;
            // 0x193788: 0x46006386  mov.s       $f14, $f12 (Delay Slot)
        ctx->f[14] = FPU_MOV_S(ctx->f[12]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x193790u;
    if (runtime->hasFunction(0x193790u)) {
        auto targetFn = runtime->lookupFunction(0x193790u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00193790_0x193790(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x19378Cu;
    // 0x19378c: 0x0  nop
    ctx->pc = 0x19378cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
