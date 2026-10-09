#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016DF80
// Address: 0x16df80 - 0x16e038
void sub_0016DF80_0x16df80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016DF80_0x16df80");
#endif

    ctx->pc = 0x16df80u;

    // 0x16df80: 0x8c880018  lw          $t0, 0x18($a0)
    ctx->pc = 0x16df80u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x16df84: 0x52880  sll         $a1, $a1, 2
    ctx->pc = 0x16df84u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x16df88: 0x8c820014  lw          $v0, 0x14($a0)
    ctx->pc = 0x16df88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x16df8c: 0x2409003c  addiu       $t1, $zero, 0x3C
    ctx->pc = 0x16df8cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
    // 0x16df90: 0x3c030024  lui         $v1, 0x24
    ctx->pc = 0x16df90u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
    // 0x16df94: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x16df94u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x16df98: 0x8c630898  lw          $v1, 0x898($v1)
    ctx->pc = 0x16df98u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 2200)));
    // 0x16df9c: 0x240d003c  addiu       $t5, $zero, 0x3C
    ctx->pc = 0x16df9cu;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
    // 0x16dfa0: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x16dfa0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x16dfa4: 0x8c88000c  lw          $t0, 0xC($a0)
    ctx->pc = 0x16dfa4u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x16dfa8: 0x244b0001  addiu       $t3, $v0, 0x1
    ctx->pc = 0x16dfa8u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x16dfac: 0x2402003c  addiu       $v0, $zero, 0x3C
    ctx->pc = 0x16dfacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
    // 0x16dfb0: 0x163001a  div         $zero, $t3, $v1
    ctx->pc = 0x16dfb0u;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 11);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x16dfb4: 0x8c850010  lw          $a1, 0x10($a0)
    ctx->pc = 0x16dfb4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x16dfb8: 0x8c8e0008  lw          $t6, 0x8($a0)
    ctx->pc = 0x16dfb8u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x16dfbc: 0x240c003c  addiu       $t4, $zero, 0x3C
    ctx->pc = 0x16dfbcu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
    // 0x16dfc0: 0x50600001  beql        $v1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x16DFC0u;
    {
        const bool branch_taken_0x16dfc0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x16dfc0) {
            ctx->pc = 0x16DFC4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16DFC0u;
            // 0x16dfc4: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x16DFC8u;
            goto label_16dfc8;
        }
    }
    ctx->pc = 0x16DFC8u;
label_16dfc8:
    // 0x16dfc8: 0x5012  mflo        $t2
    ctx->pc = 0x16dfc8u;
    SET_GPR_U64(ctx, 10, ctx->lo);
    // 0x16dfcc: 0x5810  mfhi        $t3
    ctx->pc = 0x16dfccu;
    SET_GPR_U64(ctx, 11, ctx->hi);
    // 0x16dfd0: 0xaa2821  addu        $a1, $a1, $t2
    ctx->pc = 0x16dfd0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 10)));
    // 0x16dfd4: 0xa9001a  div         $zero, $a1, $t1
    ctx->pc = 0x16dfd4u;
    { int32_t divisor = GPR_S32(ctx, 9);    int32_t dividend = GPR_S32(ctx, 5);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x16dfd8: 0x2812  mflo        $a1
    ctx->pc = 0x16dfd8u;
    SET_GPR_U64(ctx, 5, ctx->lo);
    // 0x16dfdc: 0x5010  mfhi        $t2
    ctx->pc = 0x16dfdcu;
    SET_GPR_U64(ctx, 10, ctx->hi);
    // 0x16dfe0: 0x1054021  addu        $t0, $t0, $a1
    ctx->pc = 0x16dfe0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 5)));
    // 0x16dfe4: 0x109001a  div         $zero, $t0, $t1
    ctx->pc = 0x16dfe4u;
    { int32_t divisor = GPR_S32(ctx, 9);    int32_t dividend = GPR_S32(ctx, 8);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x16dfe8: 0x4012  mflo        $t0
    ctx->pc = 0x16dfe8u;
    SET_GPR_U64(ctx, 8, ctx->lo);
    // 0x16dfec: 0x2010  mfhi        $a0
    ctx->pc = 0x16dfecu;
    SET_GPR_U64(ctx, 4, ctx->hi);
    // 0x16dff0: 0x10c0000c  beqz        $a2, . + 4 + (0xC << 2)
    ctx->pc = 0x16DFF0u;
    {
        const bool branch_taken_0x16dff0 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x16DFF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16DFF0u;
            // 0x16dff4: 0x1c87021  addu        $t6, $t6, $t0 (Delay Slot)
        SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), GPR_U32(ctx, 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16dff0) {
            ctx->pc = 0x16E024u;
            goto label_16e024;
        }
    }
    ctx->pc = 0x16DFF8u;
    // 0x16dff8: 0x5540000b  bnel        $t2, $zero, . + 4 + (0xB << 2)
    ctx->pc = 0x16DFF8u;
    {
        const bool branch_taken_0x16dff8 = (GPR_U64(ctx, 10) != GPR_U64(ctx, 0));
        if (branch_taken_0x16dff8) {
            ctx->pc = 0x16DFFCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16DFF8u;
            // 0x16dffc: 0xaceb0014  sw          $t3, 0x14($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 20), GPR_U32(ctx, 11));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16E028u;
            goto label_16e028;
        }
    }
    ctx->pc = 0x16E000u;
    // 0x16e000: 0x2402000a  addiu       $v0, $zero, 0xA
    ctx->pc = 0x16e000u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x16e004: 0x82001a  div         $zero, $a0, $v0
    ctx->pc = 0x16e004u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 4);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x16e008: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x16E008u;
    {
        const bool branch_taken_0x16e008 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x16e008) {
            ctx->pc = 0x16E00Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16E008u;
            // 0x16e00c: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x16E010u;
            goto label_16e010;
        }
    }
    ctx->pc = 0x16E010u;
label_16e010:
    // 0x16e010: 0x1810  mfhi        $v1
    ctx->pc = 0x16e010u;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x16e014: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x16E014u;
    {
        const bool branch_taken_0x16e014 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x16E018u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E014u;
            // 0x16e018: 0x2d630002  sltiu       $v1, $t3, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 11) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e014) {
            ctx->pc = 0x16E024u;
            goto label_16e024;
        }
    }
    ctx->pc = 0x16E01Cu;
    // 0x16e01c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x16e01cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x16e020: 0x43580b  movn        $t3, $v0, $v1
    ctx->pc = 0x16e020u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 11, GPR_VEC(ctx, 2));
label_16e024:
    // 0x16e024: 0xaceb0014  sw          $t3, 0x14($a3)
    ctx->pc = 0x16e024u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 20), GPR_U32(ctx, 11));
label_16e028:
    // 0x16e028: 0xacee0008  sw          $t6, 0x8($a3)
    ctx->pc = 0x16e028u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 8), GPR_U32(ctx, 14));
    // 0x16e02c: 0xace4000c  sw          $a0, 0xC($a3)
    ctx->pc = 0x16e02cu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 12), GPR_U32(ctx, 4));
    // 0x16e030: 0x3e00008  jr          $ra
    ctx->pc = 0x16E030u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16E034u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E030u;
            // 0x16e034: 0xacea0010  sw          $t2, 0x10($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 16), GPR_U32(ctx, 10));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16DFC8u: goto label_16dfc8;
            case 0x16E010u: goto label_16e010;
            case 0x16E024u: goto label_16e024;
            case 0x16E028u: goto label_16e028;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16E038u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
