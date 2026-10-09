#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00181DF0
// Address: 0x181df0 - 0x181e14
void sub_00181DF0_0x181df0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00181DF0_0x181df0");
#endif

    ctx->pc = 0x181df0u;

    // 0x181df0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x181df0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x181df4: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x181df4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181df8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x181df8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x181dfc: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x181dfcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181e00: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x181e00u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181e04: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x181e04u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181e08: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x181e08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x181e0c: 0x806074a  j           func_181D28
    ctx->pc = 0x181E0Cu;
    ctx->pc = 0x181E10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x181E0Cu;
            // 0x181e10: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x181D28u;
    if (runtime->hasFunction(0x181D28u)) {
        auto targetFn = runtime->lookupFunction(0x181D28u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00181D28_0x181d28(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x181E14u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
