#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00176C78
// Address: 0x176c78 - 0x176d04
void sub_00176C78_0x176c78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00176C78_0x176c78");
#endif

    ctx->pc = 0x176c78u;

    // 0x176c78: 0x8ca8000c  lw          $t0, 0xC($a1)
    ctx->pc = 0x176c78u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 12)));
    // 0x176c7c: 0x240b000a  addiu       $t3, $zero, 0xA
    ctx->pc = 0x176c7cu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x176c80: 0x8cac0010  lw          $t4, 0x10($a1)
    ctx->pc = 0x176c80u;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x176c84: 0x3c090003  lui         $t1, 0x3
    ctx->pc = 0x176c84u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)3 << 16));
    // 0x176c88: 0x10b001a  div         $zero, $t0, $t3
    ctx->pc = 0x176c88u;
    { int32_t divisor = GPR_S32(ctx, 11);    int32_t dividend = GPR_S32(ctx, 8);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x176c8c: 0x8caa0008  lw          $t2, 0x8($a1)
    ctx->pc = 0x176c8cu;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x176c90: 0x35294b54  ori         $t1, $t1, 0x4B54
    ctx->pc = 0x176c90u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | (uint64_t)(uint16_t)19284);
    // 0x176c94: 0x810c0  sll         $v0, $t0, 3
    ctx->pc = 0x176c94u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x176c98: 0x481023  subu        $v0, $v0, $t0
    ctx->pc = 0x176c98u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x176c9c: 0xc1900  sll         $v1, $t4, 4
    ctx->pc = 0x176c9cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 12), 4));
    // 0x176ca0: 0x24200  sll         $t0, $v0, 8
    ctx->pc = 0x176ca0u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x176ca4: 0x6c1823  subu        $v1, $v1, $t4
    ctx->pc = 0x176ca4u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 12)));
    // 0x176ca8: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x176ca8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x176cac: 0x8ca80014  lw          $t0, 0x14($a1)
    ctx->pc = 0x176cacu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 20)));
    // 0x176cb0: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x176cb0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x176cb4: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x176cb4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x176cb8: 0x51600001  beql        $t3, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x176CB8u;
    {
        const bool branch_taken_0x176cb8 = (GPR_U64(ctx, 11) == GPR_U64(ctx, 0));
        if (branch_taken_0x176cb8) {
            ctx->pc = 0x176CBCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x176CB8u;
            // 0x176cbc: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x176CC0u;
            goto label_176cc0;
        }
    }
    ctx->pc = 0x176CC0u;
label_176cc0:
    // 0x176cc0: 0x6812  mflo        $t5
    ctx->pc = 0x176cc0u;
    SET_GPR_U64(ctx, 13, ctx->lo);
    // 0x176cc4: 0x1495018  mult        $t2, $t2, $t1
    ctx->pc = 0x176cc4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 10) * (int64_t)GPR_S32(ctx, 9); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 10, (int32_t)result); }
    // 0x176cc8: 0x6d1821  addu        $v1, $v1, $t5
    ctx->pc = 0x176cc8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 13)));
    // 0x176ccc: 0x8ca90018  lw          $t1, 0x18($a1)
    ctx->pc = 0x176cccu;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 24)));
    // 0x176cd0: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x176cd0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x176cd4: 0x1094021  addu        $t0, $t0, $t1
    ctx->pc = 0x176cd4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 9)));
    // 0x176cd8: 0x1425021  addu        $t2, $t2, $v0
    ctx->pc = 0x176cd8u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 2)));
    // 0x176cdc: 0x6a1821  addu        $v1, $v1, $t2
    ctx->pc = 0x176cdcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 10)));
    // 0x176ce0: 0x681821  addu        $v1, $v1, $t0
    ctx->pc = 0x176ce0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x176ce4: 0x31140  sll         $v0, $v1, 5
    ctx->pc = 0x176ce4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
    // 0x176ce8: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x176ce8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x176cec: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x176cecu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x176cf0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x176cf0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x176cf4: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x176cf4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x176cf8: 0xacc20000  sw          $v0, 0x0($a2)
    ctx->pc = 0x176cf8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x176cfc: 0x3e00008  jr          $ra
    ctx->pc = 0x176CFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x176D00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176CFCu;
            // 0x176d00: 0xace40000  sw          $a0, 0x0($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x176CC0u: goto label_176cc0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x176D04u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
