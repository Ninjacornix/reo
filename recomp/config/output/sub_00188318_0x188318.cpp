#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00188318
// Address: 0x188318 - 0x188344
void sub_00188318_0x188318(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00188318_0x188318");
#endif

    ctx->pc = 0x188318u;

    // 0x188318: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x188318u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x18831c: 0x410c0  sll         $v0, $a0, 3
    ctx->pc = 0x18831cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x188320: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x188320u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x188324: 0x441023  subu        $v0, $v0, $a0
    ctx->pc = 0x188324u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x188328: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x188328u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x18832c: 0x3c080029  lui         $t0, 0x29
    ctx->pc = 0x18832cu;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)41 << 16));
    // 0x188330: 0x1024021  addu        $t0, $t0, $v0
    ctx->pc = 0x188330u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
    // 0x188334: 0x8d08b8dc  lw          $t0, -0x4724($t0)
    ctx->pc = 0x188334u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 4294949084)));
    // 0x188338: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x188338u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x18833c: 0x806204e  j           func_188138
    ctx->pc = 0x18833Cu;
    ctx->pc = 0x188340u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18833Cu;
            // 0x188340: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x188138u;
    if (runtime->hasFunction(0x188138u)) {
        auto targetFn = runtime->lookupFunction(0x188138u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00188138_0x188138(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x188344u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
