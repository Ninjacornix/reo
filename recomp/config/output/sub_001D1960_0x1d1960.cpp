#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D1960
// Address: 0x1d1960 - 0x1d1990
void sub_001D1960_0x1d1960(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D1960_0x1d1960");
#endif

    ctx->pc = 0x1d1960u;

    // 0x1d1960: 0x94830004  lhu         $v1, 0x4($a0)
    ctx->pc = 0x1d1960u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1d1964: 0x100482d  daddu       $t1, $t0, $zero
    ctx->pc = 0x1d1964u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1968: 0x94820000  lhu         $v0, 0x0($a0)
    ctx->pc = 0x1d1968u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1d196c: 0xc0402d  daddu       $t0, $a2, $zero
    ctx->pc = 0x1d196cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1970: 0xe0302d  daddu       $a2, $a3, $zero
    ctx->pc = 0x1d1970u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1974: 0x24870008  addiu       $a3, $a0, 0x8
    ctx->pc = 0x1d1974u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
    // 0x1d1978: 0xa0a20000  sb          $v0, 0x0($a1)
    ctx->pc = 0x1d1978u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1d197c: 0xa0a30001  sb          $v1, 0x1($a1)
    ctx->pc = 0x1d197cu;
    WRITE8(ADD32(GPR_U32(ctx, 5), 1), (uint8_t)GPR_U32(ctx, 3));
    // 0x1d1980: 0x8074540  j           func_1D1500
    ctx->pc = 0x1D1980u;
    ctx->pc = 0x1D1984u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1980u;
            // 0x1d1984: 0xa0a00002  sb          $zero, 0x2($a1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 5), 2), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D1500u;
    if (runtime->hasFunction(0x1D1500u)) {
        auto targetFn = runtime->lookupFunction(0x1D1500u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001D1500_0x1d1500(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1D1988u;
    // 0x1d1988: 0x0  nop
    ctx->pc = 0x1d1988u;
    // NOP
    // 0x1d198c: 0x0  nop
    ctx->pc = 0x1d198cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
