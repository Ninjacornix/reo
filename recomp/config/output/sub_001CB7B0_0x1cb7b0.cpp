#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CB7B0
// Address: 0x1cb7b0 - 0x1cb800
void sub_001CB7B0_0x1cb7b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CB7B0_0x1cb7b0");
#endif

    switch (ctx->pc) {
        case 0x1cb7c4u: goto label_1cb7c4;
        default: break;
    }

    ctx->pc = 0x1cb7b0u;

    // 0x1cb7b0: 0x24c2ffff  addiu       $v0, $a2, -0x1
    ctx->pc = 0x1cb7b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x1cb7b4: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1cb7b4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cb7b8: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x1cb7b8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1cb7bc: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1CB7BCu;
    {
        const bool branch_taken_0x1cb7bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB7C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB7BCu;
            // 0x1cb7c0: 0x2403000a  addiu       $v1, $zero, 0xA (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb7bc) {
            ctx->pc = 0x1CB7E8u;
            goto label_1cb7e8;
        }
    }
    ctx->pc = 0x1CB7C4u;
label_1cb7c4:
    // 0x1cb7c4: 0xa3001a  div         $zero, $a1, $v1
    ctx->pc = 0x1cb7c4u;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 5);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1cb7c8: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x1cb7c8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x1cb7cc: 0x0  nop
    ctx->pc = 0x1cb7ccu;
    // NOP
    // 0x1cb7d0: 0x1010  mfhi        $v0
    ctx->pc = 0x1cb7d0u;
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x1cb7d4: 0xa3001a  div         $zero, $a1, $v1
    ctx->pc = 0x1cb7d4u;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 5);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1cb7d8: 0x24420030  addiu       $v0, $v0, 0x30
    ctx->pc = 0x1cb7d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 48));
    // 0x1cb7dc: 0xa0820000  sb          $v0, 0x0($a0)
    ctx->pc = 0x1cb7dcu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1cb7e0: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x1cb7e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x1cb7e4: 0x2812  mflo        $a1
    ctx->pc = 0x1cb7e4u;
    SET_GPR_U64(ctx, 5, ctx->lo);
label_1cb7e8:
    // 0x1cb7e8: 0xe6102a  slt         $v0, $a3, $a2
    ctx->pc = 0x1cb7e8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x1cb7ec: 0x1440fff5  bnez        $v0, . + 4 + (-0xB << 2)
    ctx->pc = 0x1CB7ECu;
    {
        const bool branch_taken_0x1cb7ec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CB7F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB7ECu;
            // 0x1cb7f0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb7ec) {
            ctx->pc = 0x1CB7C4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cb7c4;
        }
    }
    ctx->pc = 0x1CB7F4u;
    // 0x1cb7f4: 0x3e00008  jr          $ra
    ctx->pc = 0x1CB7F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CB7C4u: goto label_1cb7c4;
            case 0x1CB7E8u: goto label_1cb7e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CB7FCu;
    // 0x1cb7fc: 0x0  nop
    ctx->pc = 0x1cb7fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
