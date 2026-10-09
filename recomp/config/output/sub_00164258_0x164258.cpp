#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00164258
// Address: 0x164258 - 0x164270
void sub_00164258_0x164258(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00164258_0x164258");
#endif

    ctx->pc = 0x164258u;

    // 0x164258: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x164258u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16425c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x16425cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164260: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x164260u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x164264: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x164264u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x164268: 0x805900e  j           func_164038
    ctx->pc = 0x164268u;
    ctx->pc = 0x16426Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164268u;
            // 0x16426c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x164038u;
    if (runtime->hasFunction(0x164038u)) {
        auto targetFn = runtime->lookupFunction(0x164038u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00164038_0x164038(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x164270u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
