#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C890
// Address: 0x12c890 - 0x12c8b0
void sub_0012C890_0x12c890(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C890_0x12c890");
#endif

    ctx->pc = 0x12c890u;

    // 0x12c890: 0x3e00008  jr          $ra
    ctx->pc = 0x12C890u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12C894u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12C890u;
            // 0x12c894: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12C898u;
    // 0x12c898: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c898u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c89c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c89cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c8a0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c8a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c8a4: 0x804fc40  j           func_13F100
    ctx->pc = 0x12C8A4u;
    ctx->pc = 0x12C8A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C8A4u;
            // 0x12c8a8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F100u;
    if (runtime->hasFunction(0x13F100u)) {
        auto targetFn = runtime->lookupFunction(0x13F100u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F100_0x13f100(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12C8ACu;
    // 0x12c8ac: 0x0  nop
    ctx->pc = 0x12c8acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
