#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001653C0
// Address: 0x1653c0 - 0x1653e8
void sub_001653C0_0x1653c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001653C0_0x1653c0");
#endif

    switch (ctx->pc) {
        case 0x1653d4u: goto label_1653d4;
        default: break;
    }

    ctx->pc = 0x1653c0u;

    // 0x1653c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1653c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1653c4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1653c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1653c8: 0x8c821b74  lw          $v0, 0x1B74($a0)
    ctx->pc = 0x1653c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 7028)));
    // 0x1653cc: 0xc04c7be  jal         func_131EF8
    ctx->pc = 0x1653CCu;
    SET_GPR_U32(ctx, 31, 0x1653D4u);
    ctx->pc = 0x1653D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1653CCu;
            // 0x1653d0: 0x8c440000  lw          $a0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x131EF8u;
    if (runtime->hasFunction(0x131EF8u)) {
        auto targetFn = runtime->lookupFunction(0x131EF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1653D4u; }
        if (ctx->pc != 0x1653D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131EF8_0x131ef8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1653D4u; }
        if (ctx->pc != 0x1653D4u) { return; }
    }
    ctx->pc = 0x1653D4u;
label_1653d4:
    // 0x1653d4: 0x38420003  xori        $v0, $v0, 0x3
    ctx->pc = 0x1653d4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)3);
    // 0x1653d8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1653d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1653dc: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x1653dcu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x1653e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1653E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1653E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1653E0u;
            // 0x1653e4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1653D4u: goto label_1653d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1653E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
