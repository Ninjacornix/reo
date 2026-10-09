#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00193240
// Address: 0x193240 - 0x193260
void sub_00193240_0x193240(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00193240_0x193240");
#endif

    ctx->pc = 0x193240u;

    // 0x193240: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x193240u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x193244: 0x44826000  mtc1        $v0, $f12
    ctx->pc = 0x193244u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[12], &bits, sizeof(bits)); }
    // 0x193248: 0x0  nop
    ctx->pc = 0x193248u;
    // NOP
    // 0x19324c: 0x46006346  mov.s       $f13, $f12
    ctx->pc = 0x19324cu;
    ctx->f[13] = FPU_MOV_S(ctx->f[12]);
    // 0x193250: 0x8064c98  j           func_193260
    ctx->pc = 0x193250u;
    ctx->pc = 0x193254u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193250u;
            // 0x193254: 0x46006386  mov.s       $f14, $f12 (Delay Slot)
        ctx->f[14] = FPU_MOV_S(ctx->f[12]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x193260u;
    if (runtime->hasFunction(0x193260u)) {
        auto targetFn = runtime->lookupFunction(0x193260u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00193260_0x193260(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x193258u;
    // 0x193258: 0x0  nop
    ctx->pc = 0x193258u;
    // NOP
    // 0x19325c: 0x0  nop
    ctx->pc = 0x19325cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
