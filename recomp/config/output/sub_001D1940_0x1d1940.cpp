#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D1940
// Address: 0x1d1940 - 0x1d1960
void sub_001D1940_0x1d1940(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D1940_0x1d1940");
#endif

    ctx->pc = 0x1d1940u;

    // 0x1d1940: 0x94830004  lhu         $v1, 0x4($a0)
    ctx->pc = 0x1d1940u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1d1944: 0xe0402d  daddu       $t0, $a3, $zero
    ctx->pc = 0x1d1944u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1948: 0x94820000  lhu         $v0, 0x0($a0)
    ctx->pc = 0x1d1948u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1d194c: 0xc0382d  daddu       $a3, $a2, $zero
    ctx->pc = 0x1d194cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1950: 0x24860008  addiu       $a2, $a0, 0x8
    ctx->pc = 0x1d1950u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
    // 0x1d1954: 0xa0a20000  sb          $v0, 0x0($a1)
    ctx->pc = 0x1d1954u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1d1958: 0x80745b0  j           func_1D16C0
    ctx->pc = 0x1D1958u;
    ctx->pc = 0x1D195Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1958u;
            // 0x1d195c: 0xa0a30001  sb          $v1, 0x1($a1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 5), 1), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D16C0u;
    if (runtime->hasFunction(0x1D16C0u)) {
        auto targetFn = runtime->lookupFunction(0x1D16C0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001D16C0_0x1d16c0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1D1960u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
