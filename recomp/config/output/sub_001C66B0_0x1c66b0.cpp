#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C66B0
// Address: 0x1c66b0 - 0x1c66e4
void sub_001C66B0_0x1c66b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C66B0_0x1c66b0");
#endif

    ctx->pc = 0x1c66b0u;

    // 0x1c66b0: 0x948501b0  lhu         $a1, 0x1B0($a0)
    ctx->pc = 0x1c66b0u;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 432)));
    // 0x1c66b4: 0x8c8301a8  lw          $v1, 0x1A8($a0)
    ctx->pc = 0x1c66b4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 424)));
    // 0x1c66b8: 0x8c8201ac  lw          $v0, 0x1AC($a0)
    ctx->pc = 0x1c66b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 428)));
    // 0x1c66bc: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x1c66bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1c66c0: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x1c66c0u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1c66c4: 0x31080  sll         $v0, $v1, 2
    ctx->pc = 0x1c66c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1c66c8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c66c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c66cc: 0x45001a  div         $zero, $v0, $a1
    ctx->pc = 0x1c66ccu;
    { int32_t divisor = GPR_S32(ctx, 5);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1c66d0: 0x0  nop
    ctx->pc = 0x1c66d0u;
    // NOP
    // 0x1c66d4: 0x0  nop
    ctx->pc = 0x1c66d4u;
    // NOP
    // 0x1c66d8: 0x1012  mflo        $v0
    ctx->pc = 0x1c66d8u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x1c66dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1C66DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C66E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C66DCu;
            // 0x1c66e0: 0x304200ff  andi        $v0, $v0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1C66E4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
