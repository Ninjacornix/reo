#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00176B78
// Address: 0x176b78 - 0x176bf8
void sub_00176B78_0x176b78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00176B78_0x176b78");
#endif

    ctx->pc = 0x176b78u;

    // 0x176b78: 0x8caa000c  lw          $t2, 0xC($a1)
    ctx->pc = 0x176b78u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 12)));
    // 0x176b7c: 0x240b000a  addiu       $t3, $zero, 0xA
    ctx->pc = 0x176b7cu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x176b80: 0x8cac0010  lw          $t4, 0x10($a1)
    ctx->pc = 0x176b80u;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x176b84: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x176b84u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x176b88: 0x14b001a  div         $zero, $t2, $t3
    ctx->pc = 0x176b88u;
    { int32_t divisor = GPR_S32(ctx, 11);    int32_t dividend = GPR_S32(ctx, 10);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x176b8c: 0x8ca90008  lw          $t1, 0x8($a1)
    ctx->pc = 0x176b8cu;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x176b90: 0x34425114  ori         $v0, $v0, 0x5114
    ctx->pc = 0x176b90u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)20756);
    // 0x176b94: 0x2408059e  addiu       $t0, $zero, 0x59E
    ctx->pc = 0x176b94u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1438));
    // 0x176b98: 0xc1840  sll         $v1, $t4, 1
    ctx->pc = 0x176b98u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 12), 1));
    // 0x176b9c: 0x51600001  beql        $t3, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x176B9Cu;
    {
        const bool branch_taken_0x176b9c = (GPR_U64(ctx, 11) == GPR_U64(ctx, 0));
        if (branch_taken_0x176b9c) {
            ctx->pc = 0x176BA0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x176B9Cu;
            // 0x176ba0: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x176BA4u;
            goto label_176ba4;
        }
    }
    ctx->pc = 0x176BA4u;
label_176ba4:
    // 0x176ba4: 0x6c1821  addu        $v1, $v1, $t4
    ctx->pc = 0x176ba4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 12)));
    // 0x176ba8: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x176ba8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x176bac: 0x6812  mflo        $t5
    ctx->pc = 0x176bacu;
    SET_GPR_U64(ctx, 13, ctx->lo);
    // 0x176bb0: 0x1224818  mult        $t1, $t1, $v0
    ctx->pc = 0x176bb0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 9) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 9, (int32_t)result); }
    // 0x176bb4: 0x1485018  mult        $t2, $t2, $t0
    ctx->pc = 0x176bb4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 10) * (int64_t)GPR_S32(ctx, 8); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 10, (int32_t)result); }
    // 0x176bb8: 0x8ca80014  lw          $t0, 0x14($a1)
    ctx->pc = 0x176bb8u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 20)));
    // 0x176bbc: 0x8ca20018  lw          $v0, 0x18($a1)
    ctx->pc = 0x176bbcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 24)));
    // 0x176bc0: 0x6d1821  addu        $v1, $v1, $t5
    ctx->pc = 0x176bc0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 13)));
    // 0x176bc4: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x176bc4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x176bc8: 0x1024021  addu        $t0, $t0, $v0
    ctx->pc = 0x176bc8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
    // 0x176bcc: 0x12a4821  addu        $t1, $t1, $t2
    ctx->pc = 0x176bccu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 10)));
    // 0x176bd0: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x176bd0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x176bd4: 0x681821  addu        $v1, $v1, $t0
    ctx->pc = 0x176bd4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x176bd8: 0x31140  sll         $v0, $v1, 5
    ctx->pc = 0x176bd8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
    // 0x176bdc: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x176bdcu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x176be0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x176be0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x176be4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x176be4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x176be8: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x176be8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x176bec: 0xacc20000  sw          $v0, 0x0($a2)
    ctx->pc = 0x176becu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x176bf0: 0x3e00008  jr          $ra
    ctx->pc = 0x176BF0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x176BF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176BF0u;
            // 0x176bf4: 0xace40000  sw          $a0, 0x0($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x176BA4u: goto label_176ba4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x176BF8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
