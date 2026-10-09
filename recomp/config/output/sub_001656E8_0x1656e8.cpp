#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001656E8
// Address: 0x1656e8 - 0x165710
void sub_001656E8_0x1656e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001656E8_0x1656e8");
#endif

    switch (ctx->pc) {
        case 0x1656f8u: goto label_1656f8;
        default: break;
    }

    ctx->pc = 0x1656e8u;

    // 0x1656e8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1656e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1656ec: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1656ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1656f0: 0xc04c7be  jal         func_131EF8
    ctx->pc = 0x1656F0u;
    SET_GPR_U32(ctx, 31, 0x1656F8u);
    ctx->pc = 0x131EF8u;
    if (runtime->hasFunction(0x131EF8u)) {
        auto targetFn = runtime->lookupFunction(0x131EF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1656F8u; }
        if (ctx->pc != 0x1656F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131EF8_0x131ef8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1656F8u; }
        if (ctx->pc != 0x1656F8u) { return; }
    }
    ctx->pc = 0x1656F8u;
label_1656f8:
    // 0x1656f8: 0x2c420002  sltiu       $v0, $v0, 0x2
    ctx->pc = 0x1656f8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x1656fc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1656fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x165700: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x165700u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x165704: 0x3e00008  jr          $ra
    ctx->pc = 0x165704u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x165708u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165704u;
            // 0x165708: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1656F8u: goto label_1656f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16570Cu;
    // 0x16570c: 0x0  nop
    ctx->pc = 0x16570cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
