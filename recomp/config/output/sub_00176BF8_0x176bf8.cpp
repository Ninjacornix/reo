#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00176BF8
// Address: 0x176bf8 - 0x176c74
void sub_00176BF8_0x176bf8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00176BF8_0x176bf8");
#endif

    ctx->pc = 0x176bf8u;

    // 0x176bf8: 0x8ca9000c  lw          $t1, 0xC($a1)
    ctx->pc = 0x176bf8u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 12)));
    // 0x176bfc: 0x240c000a  addiu       $t4, $zero, 0xA
    ctx->pc = 0x176bfcu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x176c00: 0x8caa0008  lw          $t2, 0x8($a1)
    ctx->pc = 0x176c00u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x176c04: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x176c04u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x176c08: 0x12c001a  div         $zero, $t1, $t4
    ctx->pc = 0x176c08u;
    { int32_t divisor = GPR_S32(ctx, 12);    int32_t dividend = GPR_S32(ctx, 9);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x176c0c: 0x8cab0010  lw          $t3, 0x10($a1)
    ctx->pc = 0x176c0cu;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x176c10: 0x3442a574  ori         $v0, $v0, 0xA574
    ctx->pc = 0x176c10u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)42356);
    // 0x176c14: 0x24080706  addiu       $t0, $zero, 0x706
    ctx->pc = 0x176c14u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1798));
    // 0x176c18: 0x71284818  mult1       $t1, $t1, $t0
    ctx->pc = 0x176c18u;
    { int64_t result = (int64_t)GPR_S32(ctx, 9) * (int64_t)GPR_S32(ctx, 8); ctx->lo1 = (uint64_t)(int64_t)(int32_t)result; ctx->hi1 = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 9, (int32_t)result); }
    // 0x176c1c: 0x8ca80014  lw          $t0, 0x14($a1)
    ctx->pc = 0x176c1cu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 20)));
    // 0x176c20: 0xb1900  sll         $v1, $t3, 4
    ctx->pc = 0x176c20u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 11), 4));
    // 0x176c24: 0x51800001  beql        $t4, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x176C24u;
    {
        const bool branch_taken_0x176c24 = (GPR_U64(ctx, 12) == GPR_U64(ctx, 0));
        if (branch_taken_0x176c24) {
            ctx->pc = 0x176C28u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x176C24u;
            // 0x176c28: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x176C2Cu;
            goto label_176c2c;
        }
    }
    ctx->pc = 0x176C2Cu;
label_176c2c:
    // 0x176c2c: 0x6b1823  subu        $v1, $v1, $t3
    ctx->pc = 0x176c2cu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 11)));
    // 0x176c30: 0x6812  mflo        $t5
    ctx->pc = 0x176c30u;
    SET_GPR_U64(ctx, 13, ctx->lo);
    // 0x176c34: 0x1425018  mult        $t2, $t2, $v0
    ctx->pc = 0x176c34u;
    { int64_t result = (int64_t)GPR_S32(ctx, 10) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 10, (int32_t)result); }
    // 0x176c38: 0x6d1821  addu        $v1, $v1, $t5
    ctx->pc = 0x176c38u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 13)));
    // 0x176c3c: 0x8ca20018  lw          $v0, 0x18($a1)
    ctx->pc = 0x176c3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 24)));
    // 0x176c40: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x176c40u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x176c44: 0x1024021  addu        $t0, $t0, $v0
    ctx->pc = 0x176c44u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
    // 0x176c48: 0x1495021  addu        $t2, $t2, $t1
    ctx->pc = 0x176c48u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 9)));
    // 0x176c4c: 0x6a1821  addu        $v1, $v1, $t2
    ctx->pc = 0x176c4cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 10)));
    // 0x176c50: 0x681821  addu        $v1, $v1, $t0
    ctx->pc = 0x176c50u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x176c54: 0x31140  sll         $v0, $v1, 5
    ctx->pc = 0x176c54u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
    // 0x176c58: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x176c58u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x176c5c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x176c5cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x176c60: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x176c60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x176c64: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x176c64u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x176c68: 0xacc20000  sw          $v0, 0x0($a2)
    ctx->pc = 0x176c68u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x176c6c: 0x3e00008  jr          $ra
    ctx->pc = 0x176C6Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x176C70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176C6Cu;
            // 0x176c70: 0xace40000  sw          $a0, 0x0($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x176C2Cu: goto label_176c2c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x176C74u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
