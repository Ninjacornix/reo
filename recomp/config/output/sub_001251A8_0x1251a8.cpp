#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001251A8
// Address: 0x1251a8 - 0x125230
void sub_001251A8_0x1251a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001251A8_0x1251a8");
#endif

    ctx->pc = 0x1251a8u;

    // 0x1251a8: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x1251a8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1251ac: 0x84e20098  lh          $v0, 0x98($a3)
    ctx->pc = 0x1251acu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 7), 152)));
    // 0x1251b0: 0x1440000d  bnez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1251B0u;
    {
        const bool branch_taken_0x1251b0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1251B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1251B0u;
            // 0x1251b4: 0xa0402d  daddu       $t0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1251b0) {
            ctx->pc = 0x1251E8u;
            goto label_1251e8;
        }
    }
    ctx->pc = 0x1251B8u;
    // 0x1251b8: 0x80e2000f  lb          $v0, 0xF($a3)
    ctx->pc = 0x1251b8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 15)));
    // 0x1251bc: 0xace80048  sw          $t0, 0x48($a3)
    ctx->pc = 0x1251bcu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 72), GPR_U32(ctx, 8));
    // 0x1251c0: 0xc2001a  div         $zero, $a2, $v0
    ctx->pc = 0x1251c0u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 6);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1251c4: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x1251C4u;
    {
        const bool branch_taken_0x1251c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1251c4) {
            ctx->pc = 0x1251C8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1251C4u;
            // 0x1251c8: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x1251CCu;
            goto label_1251cc;
        }
    }
    ctx->pc = 0x1251CCu;
label_1251cc:
    // 0x1251cc: 0xace00074  sw          $zero, 0x74($a3)
    ctx->pc = 0x1251ccu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 116), GPR_U32(ctx, 0));
    // 0x1251d0: 0xace00094  sw          $zero, 0x94($a3)
    ctx->pc = 0x1251d0u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 148), GPR_U32(ctx, 0));
    // 0x1251d4: 0xace00090  sw          $zero, 0x90($a3)
    ctx->pc = 0x1251d4u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 144), GPR_U32(ctx, 0));
    // 0x1251d8: 0x1812  mflo        $v1
    ctx->pc = 0x1251d8u;
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x1251dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1251DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1251E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1251DCu;
            // 0x1251e0: 0xace3004c  sw          $v1, 0x4C($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 76), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1251CCu: goto label_1251cc;
            case 0x1251E8u: goto label_1251e8;
            case 0x125214u: goto label_125214;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1251E4u;
    // 0x1251e4: 0x0  nop
    ctx->pc = 0x1251e4u;
    // NOP
label_1251e8:
    // 0x1251e8: 0x80e2000d  lb          $v0, 0xD($a3)
    ctx->pc = 0x1251e8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 13)));
    // 0x1251ec: 0x80e5000e  lb          $a1, 0xE($a3)
    ctx->pc = 0x1251ecu;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 14)));
    // 0x1251f0: 0x28430000  slti        $v1, $v0, 0x0
    ctx->pc = 0x1251f0u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x1251f4: 0x24440007  addiu       $a0, $v0, 0x7
    ctx->pc = 0x1251f4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 7));
    // 0x1251f8: 0x83100b  movn        $v0, $a0, $v1
    ctx->pc = 0x1251f8u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 4));
    // 0x1251fc: 0xace80048  sw          $t0, 0x48($a3)
    ctx->pc = 0x1251fcu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 72), GPR_U32(ctx, 8));
    // 0x125200: 0x210c3  sra         $v0, $v0, 3
    ctx->pc = 0x125200u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 3));
    // 0x125204: 0x451018  mult        $v0, $v0, $a1
    ctx->pc = 0x125204u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 5); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x125208: 0x70c2001a  div1        $zero, $a2, $v0
    ctx->pc = 0x125208u;
    { int32_t divisor = GPR_S32(ctx, 2); int32_t dividend = GPR_S32(ctx, 6); if (divisor != 0) {     if (divisor == -1 && dividend == INT32_MIN) {         ctx->lo1 = (uint64_t)(int64_t)INT32_MIN; ctx->hi1 = 0;     } else {         ctx->lo1 = (uint64_t)(int64_t)(dividend / divisor);         ctx->hi1 = (uint64_t)(int64_t)(dividend % divisor);     } } else {     ctx->lo1 = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi1 = (uint64_t)(int64_t)dividend; } }
    // 0x12520c: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x12520Cu;
    {
        const bool branch_taken_0x12520c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x12520c) {
            ctx->pc = 0x125210u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12520Cu;
            // 0x125210: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x125214u;
            goto label_125214;
        }
    }
    ctx->pc = 0x125214u;
label_125214:
    // 0x125214: 0xace00094  sw          $zero, 0x94($a3)
    ctx->pc = 0x125214u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 148), GPR_U32(ctx, 0));
    // 0x125218: 0xace00074  sw          $zero, 0x74($a3)
    ctx->pc = 0x125218u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 116), GPR_U32(ctx, 0));
    // 0x12521c: 0xace00090  sw          $zero, 0x90($a3)
    ctx->pc = 0x12521cu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 144), GPR_U32(ctx, 0));
    // 0x125220: 0x70001812  mflo1       $v1
    ctx->pc = 0x125220u;
    SET_GPR_U64(ctx, 3, ctx->lo1);
    // 0x125224: 0x3e00008  jr          $ra
    ctx->pc = 0x125224u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x125228u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125224u;
            // 0x125228: 0xace3004c  sw          $v1, 0x4C($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 76), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1251CCu: goto label_1251cc;
            case 0x1251E8u: goto label_1251e8;
            case 0x125214u: goto label_125214;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12522Cu;
    // 0x12522c: 0x0  nop
    ctx->pc = 0x12522cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
