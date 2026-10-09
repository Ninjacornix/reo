#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016DB00
// Address: 0x16db00 - 0x16db20
void sub_0016DB00_0x16db00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016DB00_0x16db00");
#endif

    ctx->pc = 0x16db00u;

    // 0x16db00: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x16db00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16db04: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x16db04u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16db08: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16db08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x16db0c: 0x3c050157  lui         $a1, 0x157
    ctx->pc = 0x16db0cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)343 << 16));
    // 0x16db10: 0x34a552a0  ori         $a1, $a1, 0x52A0
    ctx->pc = 0x16db10u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)21152);
    // 0x16db14: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16db14u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16db18: 0x8056ea0  j           func_15BA80
    ctx->pc = 0x16DB18u;
    ctx->pc = 0x16DB1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16DB18u;
            // 0x16db1c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15BA80u;
    if (runtime->hasFunction(0x15BA80u)) {
        auto targetFn = runtime->lookupFunction(0x15BA80u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0015BA80_0x15ba80(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16DB20u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
