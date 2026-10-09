#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00125370
// Address: 0x125370 - 0x125458
void sub_00125370_0x125370(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00125370_0x125370");
#endif

    ctx->pc = 0x125370u;

    // 0x125370: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x125370u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x125374: 0x24850048  addiu       $a1, $a0, 0x48
    ctx->pc = 0x125374u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), 72));
    // 0x125378: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x125378u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12537c: 0x8cae0008  lw          $t6, 0x8($a1)
    ctx->pc = 0x12537cu;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x125380: 0x8ca60004  lw          $a2, 0x4($a1)
    ctx->pc = 0x125380u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x125384: 0x51c00001  beql        $t6, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x125384u;
    {
        const bool branch_taken_0x125384 = (GPR_U64(ctx, 14) == GPR_U64(ctx, 0));
        if (branch_taken_0x125384) {
            ctx->pc = 0x125388u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x125384u;
            // 0x125388: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x12538Cu;
            goto label_12538c;
        }
    }
    ctx->pc = 0x12538Cu;
label_12538c:
    // 0x12538c: 0x8caf0018  lw          $t7, 0x18($a1)
    ctx->pc = 0x12538cu;
    SET_GPR_S32(ctx, 15, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 24)));
    // 0x125390: 0xce001a  div         $zero, $a2, $t6
    ctx->pc = 0x125390u;
    { int32_t divisor = GPR_S32(ctx, 14);    int32_t dividend = GPR_S32(ctx, 6);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x125394: 0x8ca80020  lw          $t0, 0x20($a1)
    ctx->pc = 0x125394u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 32)));
    // 0x125398: 0x8ca90010  lw          $t1, 0x10($a1)
    ctx->pc = 0x125398u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x12539c: 0x1e81023  subu        $v0, $t7, $t0
    ctx->pc = 0x12539cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 15), GPR_U32(ctx, 8)));
    // 0x1253a0: 0x8ca70028  lw          $a3, 0x28($a1)
    ctx->pc = 0x1253a0u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 40)));
    // 0x1253a4: 0x491021  addu        $v0, $v0, $t1
    ctx->pc = 0x1253a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 9)));
    // 0x1253a8: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1253a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1253ac: 0xe91821  addu        $v1, $a3, $t1
    ctx->pc = 0x1253acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x1253b0: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1253b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1253b4: 0x8cac0024  lw          $t4, 0x24($a1)
    ctx->pc = 0x1253b4u;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 36)));
    // 0x1253b8: 0xec382a  slt         $a3, $a3, $t4
    ctx->pc = 0x1253b8u;
    SET_GPR_U64(ctx, 7, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 12)) ? 1 : 0);
    // 0x1253bc: 0x3012  mflo        $a2
    ctx->pc = 0x1253bcu;
    SET_GPR_U64(ctx, 6, ctx->lo);
    // 0x1253c0: 0x49001a  div         $zero, $v0, $t1
    ctx->pc = 0x1253c0u;
    { int32_t divisor = GPR_S32(ctx, 9);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1253c4: 0xc0502d  daddu       $t2, $a2, $zero
    ctx->pc = 0x1253c4u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1253c8: 0x1012  mflo        $v0
    ctx->pc = 0x1253c8u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x1253cc: 0x69001a  div         $zero, $v1, $t1
    ctx->pc = 0x1253ccu;
    { int32_t divisor = GPR_S32(ctx, 9);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1253d0: 0x40582d  daddu       $t3, $v0, $zero
    ctx->pc = 0x1253d0u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1253d4: 0x6812  mflo        $t5
    ctx->pc = 0x1253d4u;
    SET_GPR_U64(ctx, 13, ctx->lo);
    // 0x1253d8: 0x2810  mfhi        $a1
    ctx->pc = 0x1253d8u;
    SET_GPR_U64(ctx, 5, ctx->hi);
    // 0x1253dc: 0x1691818  mult        $v1, $t3, $t1
    ctx->pc = 0x1253dcu;
    { int64_t result = (int64_t)GPR_S32(ctx, 11) * (int64_t)GPR_S32(ctx, 9); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1253e0: 0x1252823  subu        $a1, $t1, $a1
    ctx->pc = 0x1253e0u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 9), GPR_U32(ctx, 5)));
    // 0x1253e4: 0x1ab102a  slt         $v0, $t5, $t3
    ctx->pc = 0x1253e4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 13) < (int64_t)GPR_S64(ctx, 11)) ? 1 : 0);
    // 0x1253e8: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x1253e8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x1253ec: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1253ECu;
    {
        const bool branch_taken_0x1253ec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1253F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1253ECu;
            // 0x1253f0: 0x1034021  addu        $t0, $t0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1253ec) {
            ctx->pc = 0x125400u;
            goto label_125400;
        }
    }
    ctx->pc = 0x1253F4u;
    // 0x1253f4: 0x1051023  subu        $v0, $t0, $a1
    ctx->pc = 0x1253f4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 8), GPR_U32(ctx, 5)));
    // 0x1253f8: 0x4f102a  slt         $v0, $v0, $t7
    ctx->pc = 0x1253f8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 15)) ? 1 : 0);
    // 0x1253fc: 0x1625821  addu        $t3, $t3, $v0
    ctx->pc = 0x1253fcu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 2)));
label_125400:
    // 0x125400: 0xe51018  mult        $v0, $a3, $a1
    ctx->pc = 0x125400u;
    { int64_t result = (int64_t)GPR_S32(ctx, 7) * (int64_t)GPR_S32(ctx, 5); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x125404: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x125404u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x125408: 0x51200001  beql        $t1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x125408u;
    {
        const bool branch_taken_0x125408 = (GPR_U64(ctx, 9) == GPR_U64(ctx, 0));
        if (branch_taken_0x125408) {
            ctx->pc = 0x12540Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x125408u;
            // 0x12540c: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x125410u;
            goto label_125410;
        }
    }
    ctx->pc = 0x125410u;
label_125410:
    // 0x125410: 0x4c6021  addu        $t4, $v0, $t4
    ctx->pc = 0x125410u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 12)));
    // 0x125414: 0x189001a  div         $zero, $t4, $t1
    ctx->pc = 0x125414u;
    { int32_t divisor = GPR_S32(ctx, 9);    int32_t dividend = GPR_S32(ctx, 12);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x125418: 0x2812  mflo        $a1
    ctx->pc = 0x125418u;
    SET_GPR_U64(ctx, 5, ctx->lo);
    // 0x12541c: 0xaa102a  slt         $v0, $a1, $t2
    ctx->pc = 0x12541cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 10)) ? 1 : 0);
    // 0x125420: 0xa2500b  movn        $t2, $a1, $v0
    ctx->pc = 0x125420u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 10, GPR_VEC(ctx, 5));
    // 0x125424: 0x1aa182a  slt         $v1, $t5, $t2
    ctx->pc = 0x125424u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 13) < (int64_t)GPR_S64(ctx, 10)) ? 1 : 0);
    // 0x125428: 0x1a3500b  movn        $t2, $t5, $v1
    ctx->pc = 0x125428u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 10, GPR_VEC(ctx, 13));
    // 0x12542c: 0x16a102a  slt         $v0, $t3, $t2
    ctx->pc = 0x12542cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 11) < (int64_t)GPR_S64(ctx, 10)) ? 1 : 0);
    // 0x125430: 0x15c60005  bne         $t6, $a2, . + 4 + (0x5 << 2)
    ctx->pc = 0x125430u;
    {
        const bool branch_taken_0x125430 = (GPR_U64(ctx, 14) != GPR_U64(ctx, 6));
        ctx->pc = 0x125434u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125430u;
            // 0x125434: 0x162500b  movn        $t2, $t3, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 10, GPR_VEC(ctx, 11));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125430) {
            ctx->pc = 0x125448u;
            goto label_125448;
        }
    }
    ctx->pc = 0x125438u;
    // 0x125438: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x125438u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12543c: 0x140282d  daddu       $a1, $t2, $zero
    ctx->pc = 0x12543cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125440: 0x80494c6  j           func_125318
    ctx->pc = 0x125440u;
    ctx->pc = 0x125444u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x125440u;
            // 0x125444: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x125318u;
    if (runtime->hasFunction(0x125318u)) {
        auto targetFn = runtime->lookupFunction(0x125318u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00125318_0x125318(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x125448u;
label_125448:
    // 0x125448: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x125448u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12544c: 0x140282d  daddu       $a1, $t2, $zero
    ctx->pc = 0x12544cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125450: 0x80494b4  j           func_1252D0
    ctx->pc = 0x125450u;
    ctx->pc = 0x125454u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x125450u;
            // 0x125454: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1252D0u;
    if (runtime->hasFunction(0x1252D0u)) {
        auto targetFn = runtime->lookupFunction(0x1252D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001252D0_0x1252d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x125458u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
