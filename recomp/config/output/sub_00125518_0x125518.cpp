#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00125518
// Address: 0x125518 - 0x125768
void sub_00125518_0x125518(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00125518_0x125518");
#endif

    switch (ctx->pc) {
        case 0x125590u: goto label_125590;
        case 0x1256c4u: goto label_1256c4;
        case 0x1256e0u: goto label_1256e0;
        case 0x1256e8u: goto label_1256e8;
        case 0x125710u: goto label_125710;
        case 0x125718u: goto label_125718;
        case 0x125730u: goto label_125730;
        case 0x125738u: goto label_125738;
        case 0x12574cu: goto label_12574c;
        default: break;
    }

    ctx->pc = 0x125518u;

label_125518:
    // 0x125518: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x125518u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x12551c: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x12551cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x125520: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x125520u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x125524: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x125524u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x125528: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x125528u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12552c: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x12552cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x125530: 0xffb60040  sd          $s6, 0x40($sp)
    ctx->pc = 0x125530u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
    // 0x125534: 0x26960048  addiu       $s6, $s4, 0x48
    ctx->pc = 0x125534u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 20), 72));
    // 0x125538: 0xffbe0050  sd          $fp, 0x50($sp)
    ctx->pc = 0x125538u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 30));
    // 0x12553c: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x12553cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x125540: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x125540u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x125544: 0xffb70048  sd          $s7, 0x48($sp)
    ctx->pc = 0x125544u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 23));
    // 0x125548: 0xffbf0058  sd          $ra, 0x58($sp)
    ctx->pc = 0x125548u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x12554c: 0x8ed10010  lw          $s1, 0x10($s6)
    ctx->pc = 0x12554cu;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 16)));
    // 0x125550: 0x8ed20028  lw          $s2, 0x28($s6)
    ctx->pc = 0x125550u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 40)));
    // 0x125554: 0x52200001  beql        $s1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x125554u;
    {
        const bool branch_taken_0x125554 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        if (branch_taken_0x125554) {
            ctx->pc = 0x125558u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x125554u;
            // 0x125558: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x12555Cu;
            goto label_12555c;
        }
    }
    ctx->pc = 0x12555Cu;
label_12555c:
    // 0x12555c: 0x2519021  addu        $s2, $s2, $s1
    ctx->pc = 0x12555cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 17)));
    // 0x125560: 0x8e820044  lw          $v0, 0x44($s4)
    ctx->pc = 0x125560u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 68)));
    // 0x125564: 0x2652ffff  addiu       $s2, $s2, -0x1
    ctx->pc = 0x125564u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967295));
    // 0x125568: 0x8e970040  lw          $s7, 0x40($s4)
    ctx->pc = 0x125568u;
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 64)));
    // 0x12556c: 0x251001a  div         $zero, $s2, $s1
    ctx->pc = 0x12556cu;
    { int32_t divisor = GPR_S32(ctx, 17);    int32_t dividend = GPR_S32(ctx, 18);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x125570: 0x8e840008  lw          $a0, 0x8($s4)
    ctx->pc = 0x125570u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 8)));
    // 0x125574: 0x8ede0014  lw          $fp, 0x14($s6)
    ctx->pc = 0x125574u;
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 20)));
    // 0x125578: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x125578u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x12557c: 0x8ed3000c  lw          $s3, 0xC($s6)
    ctx->pc = 0x12557cu;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 12)));
    // 0x125580: 0x8010  mfhi        $s0
    ctx->pc = 0x125580u;
    SET_GPR_U64(ctx, 16, ctx->hi);
    // 0x125584: 0x9012  mflo        $s2
    ctx->pc = 0x125584u;
    SET_GPR_U64(ctx, 18, ctx->lo);
    // 0x125588: 0xc04d418  jal         func_135060
    ctx->pc = 0x125588u;
    SET_GPR_U32(ctx, 31, 0x125590u);
    ctx->pc = 0x12558Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x125588u;
            // 0x12558c: 0x8ed50020  lw          $s5, 0x20($s6) (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 32)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135060u;
    if (runtime->hasFunction(0x135060u)) {
        auto targetFn = runtime->lookupFunction(0x135060u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125590u; }
        if (ctx->pc != 0x125590u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135060_0x135060(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125590u; }
        if (ctx->pc != 0x125590u) { return; }
    }
    ctx->pc = 0x125590u;
label_125590:
    // 0x125590: 0x8ec30008  lw          $v1, 0x8($s6)
    ctx->pc = 0x125590u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 22), 8)));
    // 0x125594: 0x2308023  subu        $s0, $s1, $s0
    ctx->pc = 0x125594u;
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
    // 0x125598: 0x518818  mult        $s1, $v0, $s1
    ctx->pc = 0x125598u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 17); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 17, (int32_t)result); }
    // 0x12559c: 0x2439018  mult        $s2, $s2, $v1
    ctx->pc = 0x12559cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 18, (int32_t)result); }
    // 0x1255a0: 0x2610ffff  addiu       $s0, $s0, -0x1
    ctx->pc = 0x1255a0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
    // 0x1255a4: 0x70539818  mult1       $s3, $v0, $s3
    ctx->pc = 0x1255a4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 19); ctx->lo1 = (uint64_t)(int64_t)(int32_t)result; ctx->hi1 = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 19, (int32_t)result); }
    // 0x1255a8: 0x50600001  beql        $v1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x1255A8u;
    {
        const bool branch_taken_0x1255a8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1255a8) {
            ctx->pc = 0x1255ACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1255A8u;
            // 0x1255ac: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x1255B0u;
            goto label_1255b0;
        }
    }
    ctx->pc = 0x1255B0u;
label_1255b0:
    // 0x1255b0: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1255b0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1255b4: 0x223001a  div         $zero, $s1, $v1
    ctx->pc = 0x1255b4u;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 17);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1255b8: 0x52102a  slt         $v0, $v0, $s2
    ctx->pc = 0x1255b8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x1255bc: 0xae930094  sw          $s3, 0x94($s4)
    ctx->pc = 0x1255bcu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 148), GPR_U32(ctx, 19));
    // 0x1255c0: 0x8812  mflo        $s1
    ctx->pc = 0x1255c0u;
    SET_GPR_U64(ctx, 17, ctx->lo);
    // 0x1255c4: 0x2308023  subu        $s0, $s1, $s0
    ctx->pc = 0x1255c4u;
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
    // 0x1255c8: 0x222800b  movn        $s0, $s1, $v0
    ctx->pc = 0x1255c8u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 17));
    // 0x1255cc: 0x2b0a821  addu        $s5, $s5, $s0
    ctx->pc = 0x1255ccu;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 16)));
    // 0x1255d0: 0xae900090  sw          $s0, 0x90($s4)
    ctx->pc = 0x1255d0u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 144), GPR_U32(ctx, 16));
    // 0x1255d4: 0x2b7102a  slt         $v0, $s5, $s7
    ctx->pc = 0x1255d4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 21) < (int64_t)GPR_S64(ctx, 23)) ? 1 : 0);
    // 0x1255d8: 0x14400023  bnez        $v0, . + 4 + (0x23 << 2)
    ctx->pc = 0x1255D8u;
    {
        const bool branch_taken_0x1255d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1255DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1255D8u;
            // 0x1255dc: 0x2b7a823  subu        $s5, $s5, $s7 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)SUB32(GPR_U32(ctx, 21), GPR_U32(ctx, 23)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1255d8) {
            ctx->pc = 0x125668u;
            goto label_125668;
        }
    }
    ctx->pc = 0x1255E0u;
    // 0x1255e0: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1255e0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1255e4: 0x14440010  bne         $v0, $a0, . + 4 + (0x10 << 2)
    ctx->pc = 0x1255E4u;
    {
        const bool branch_taken_0x1255e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        ctx->pc = 0x1255E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1255E4u;
            // 0x1255e8: 0x3c0202d  daddu       $a0, $fp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1255e4) {
            ctx->pc = 0x125628u;
            goto label_125628;
        }
    }
    ctx->pc = 0x1255ECu;
    // 0x1255ec: 0xdfbe0050  ld          $fp, 0x50($sp)
    ctx->pc = 0x1255ecu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1255f0: 0x2e0282d  daddu       $a1, $s7, $zero
    ctx->pc = 0x1255f0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1255f4: 0xdfb70048  ld          $s7, 0x48($sp)
    ctx->pc = 0x1255f4u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1255f8: 0x2a0382d  daddu       $a3, $s5, $zero
    ctx->pc = 0x1255f8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1255fc: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x1255fcu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x125600: 0x8fa60000  lw          $a2, 0x0($sp)
    ctx->pc = 0x125600u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x125604: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x125604u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x125608: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x125608u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12560c: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x12560cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x125610: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x125610u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x125614: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x125614u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x125618: 0xdfb60040  ld          $s6, 0x40($sp)
    ctx->pc = 0x125618u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x12561c: 0xdfbf0058  ld          $ra, 0x58($sp)
    ctx->pc = 0x12561cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x125620: 0x8049522  j           func_125488
    ctx->pc = 0x125620u;
    ctx->pc = 0x125624u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x125620u;
            // 0x125624: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
    ctx->pc = 0x125488u;
    if (runtime->hasFunction(0x125488u)) {
        auto targetFn = runtime->lookupFunction(0x125488u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00125488_0x125488(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x125628u;
label_125628:
    // 0x125628: 0xdfbe0050  ld          $fp, 0x50($sp)
    ctx->pc = 0x125628u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x12562c: 0x2e0282d  daddu       $a1, $s7, $zero
    ctx->pc = 0x12562cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125630: 0xdfb70048  ld          $s7, 0x48($sp)
    ctx->pc = 0x125630u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x125634: 0x2a0382d  daddu       $a3, $s5, $zero
    ctx->pc = 0x125634u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125638: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x125638u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x12563c: 0x8fa60000  lw          $a2, 0x0($sp)
    ctx->pc = 0x12563cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x125640: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x125640u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x125644: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x125644u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x125648: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x125648u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12564c: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x12564cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x125650: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x125650u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x125654: 0xdfb60040  ld          $s6, 0x40($sp)
    ctx->pc = 0x125654u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x125658: 0xdfbf0058  ld          $ra, 0x58($sp)
    ctx->pc = 0x125658u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x12565c: 0x804953e  j           func_1254F8
    ctx->pc = 0x12565Cu;
    ctx->pc = 0x125660u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12565Cu;
            // 0x125660: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1254F8u;
    if (runtime->hasFunction(0x1254F8u)) {
        auto targetFn = runtime->lookupFunction(0x1254F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001254F8_0x1254f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x125664u;
    // 0x125664: 0x0  nop
    ctx->pc = 0x125664u;
    // NOP
label_125668:
    // 0x125668: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x125668u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12566c: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x12566cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x125670: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x125670u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x125674: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x125674u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x125678: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x125678u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12567c: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x12567cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x125680: 0xdfb60040  ld          $s6, 0x40($sp)
    ctx->pc = 0x125680u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x125684: 0xdfb70048  ld          $s7, 0x48($sp)
    ctx->pc = 0x125684u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x125688: 0xdfbe0050  ld          $fp, 0x50($sp)
    ctx->pc = 0x125688u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x12568c: 0xdfbf0058  ld          $ra, 0x58($sp)
    ctx->pc = 0x12568cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x125690: 0x3e00008  jr          $ra
    ctx->pc = 0x125690u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x125694u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125690u;
            // 0x125694: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x125518u: goto label_125518;
            case 0x12555Cu: goto label_12555c;
            case 0x125590u: goto label_125590;
            case 0x1255B0u: goto label_1255b0;
            case 0x125628u: goto label_125628;
            case 0x125668u: goto label_125668;
            case 0x1256C4u: goto label_1256c4;
            case 0x1256E0u: goto label_1256e0;
            case 0x1256E8u: goto label_1256e8;
            case 0x1256F8u: goto label_1256f8;
            case 0x125700u: goto label_125700;
            case 0x125710u: goto label_125710;
            case 0x125718u: goto label_125718;
            case 0x125730u: goto label_125730;
            case 0x125738u: goto label_125738;
            case 0x12574Cu: goto label_12574c;
            case 0x125750u: goto label_125750;
            case 0x125754u: goto label_125754;
            default: break;
        }
        return;
    }
    ctx->pc = 0x125698u;
    // 0x125698: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x125698u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x12569c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x12569cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1256a0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1256a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1256a4: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1256a4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1256a8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1256a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1256ac: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1256acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1256b0: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x1256b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1256b4: 0x54620012  bnel        $v1, $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x1256B4u;
    {
        const bool branch_taken_0x1256b4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1256b4) {
            ctx->pc = 0x1256B8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1256B4u;
            // 0x1256b8: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x125700u;
            goto label_125700;
        }
    }
    ctx->pc = 0x1256BCu;
    // 0x1256bc: 0xc04d3e6  jal         func_134F98
    ctx->pc = 0x1256BCu;
    SET_GPR_U32(ctx, 31, 0x1256C4u);
    ctx->pc = 0x1256C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1256BCu;
            // 0x1256c0: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134F98u;
    if (runtime->hasFunction(0x134F98u)) {
        auto targetFn = runtime->lookupFunction(0x134F98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1256C4u; }
        if (ctx->pc != 0x1256C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134F98_0x134f98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1256C4u; }
        if (ctx->pc != 0x1256C4u) { return; }
    }
    ctx->pc = 0x1256C4u;
label_1256c4:
    // 0x1256c4: 0x26050068  addiu       $a1, $s0, 0x68
    ctx->pc = 0x1256c4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 104));
    // 0x1256c8: 0x2606006c  addiu       $a2, $s0, 0x6C
    ctx->pc = 0x1256c8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 108));
    // 0x1256cc: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1256CCu;
    {
        const bool branch_taken_0x1256cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1256D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1256CCu;
            // 0x1256d0: 0x26070070  addiu       $a3, $s0, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 112));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1256cc) {
            ctx->pc = 0x1256F8u;
            goto label_1256f8;
        }
    }
    ctx->pc = 0x1256D4u;
    // 0x1256d4: 0x8e020078  lw          $v0, 0x78($s0)
    ctx->pc = 0x1256d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 120)));
    // 0x1256d8: 0x40f809  jalr        $v0
    ctx->pc = 0x1256D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1256E0u);
        ctx->pc = 0x1256DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1256D8u;
            // 0x1256dc: 0x8e04007c  lw          $a0, 0x7C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 124)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1256E0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x125518u: goto label_125518;
            case 0x12555Cu: goto label_12555c;
            case 0x125590u: goto label_125590;
            case 0x1255B0u: goto label_1255b0;
            case 0x125628u: goto label_125628;
            case 0x125668u: goto label_125668;
            case 0x1256C4u: goto label_1256c4;
            case 0x1256E0u: goto label_1256e0;
            case 0x1256E8u: goto label_1256e8;
            case 0x1256F8u: goto label_1256f8;
            case 0x125700u: goto label_125700;
            case 0x125710u: goto label_125710;
            case 0x125718u: goto label_125718;
            case 0x125730u: goto label_125730;
            case 0x125738u: goto label_125738;
            case 0x12574Cu: goto label_12574c;
            case 0x125750u: goto label_125750;
            case 0x125754u: goto label_125754;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1256E0u; }
            if (ctx->pc != 0x1256E0u) { return; }
        }
        }
    }
    ctx->pc = 0x1256E0u;
label_1256e0:
    // 0x1256e0: 0xc0494dc  jal         func_125370
    ctx->pc = 0x1256E0u;
    SET_GPR_U32(ctx, 31, 0x1256E8u);
    ctx->pc = 0x1256E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1256E0u;
            // 0x1256e4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x125370u;
    if (runtime->hasFunction(0x125370u)) {
        auto targetFn = runtime->lookupFunction(0x125370u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1256E8u; }
        if (ctx->pc != 0x1256E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00125370_0x125370(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1256E8u; }
        if (ctx->pc != 0x1256E8u) { return; }
    }
    ctx->pc = 0x1256E8u;
label_1256e8:
    // 0x1256e8: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1256e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1256ec: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x1256ecu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x1256f0: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1256F0u;
    {
        const bool branch_taken_0x1256f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1256F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1256F0u;
            // 0x1256f4: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1256f0) {
            ctx->pc = 0x125700u;
            goto label_125700;
        }
    }
    ctx->pc = 0x1256F8u;
label_1256f8:
    // 0x1256f8: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x1256f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1256fc: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1256fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
label_125700:
    // 0x125700: 0x54620014  bnel        $v1, $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x125700u;
    {
        const bool branch_taken_0x125700 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x125700) {
            ctx->pc = 0x125704u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x125700u;
            // 0x125704: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x125754u;
            goto label_125754;
        }
    }
    ctx->pc = 0x125708u;
    // 0x125708: 0xc04d41e  jal         func_135078
    ctx->pc = 0x125708u;
    SET_GPR_U32(ctx, 31, 0x125710u);
    ctx->pc = 0x12570Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x125708u;
            // 0x12570c: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135078u;
    if (runtime->hasFunction(0x135078u)) {
        auto targetFn = runtime->lookupFunction(0x135078u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125710u; }
        if (ctx->pc != 0x125710u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135078_0x135078(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125710u; }
        if (ctx->pc != 0x125710u) { return; }
    }
    ctx->pc = 0x125710u;
label_125710:
    // 0x125710: 0xc04d3e6  jal         func_134F98
    ctx->pc = 0x125710u;
    SET_GPR_U32(ctx, 31, 0x125718u);
    ctx->pc = 0x125714u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x125710u;
            // 0x125714: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134F98u;
    if (runtime->hasFunction(0x134F98u)) {
        auto targetFn = runtime->lookupFunction(0x134F98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125718u; }
        if (ctx->pc != 0x125718u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134F98_0x134f98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125718u; }
        if (ctx->pc != 0x125718u) { return; }
    }
    ctx->pc = 0x125718u;
label_125718:
    // 0x125718: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x125718u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12571c: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x12571cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x125720: 0x1622000b  bne         $s1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x125720u;
    {
        const bool branch_taken_0x125720 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        ctx->pc = 0x125724u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125720u;
            // 0x125724: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125720) {
            ctx->pc = 0x125750u;
            goto label_125750;
        }
    }
    ctx->pc = 0x125728u;
    // 0x125728: 0xc049546  jal         func_125518
    ctx->pc = 0x125728u;
    SET_GPR_U32(ctx, 31, 0x125730u);
    ctx->pc = 0x125518u;
    goto label_125518;
    ctx->pc = 0x125730u;
label_125730:
    // 0x125730: 0xc04d412  jal         func_135048
    ctx->pc = 0x125730u;
    SET_GPR_U32(ctx, 31, 0x125738u);
    ctx->pc = 0x125734u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x125730u;
            // 0x125734: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135048u;
    if (runtime->hasFunction(0x135048u)) {
        auto targetFn = runtime->lookupFunction(0x135048u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125738u; }
        if (ctx->pc != 0x125738u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135048_0x135048(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125738u; }
        if (ctx->pc != 0x125738u) { return; }
    }
    ctx->pc = 0x125738u;
label_125738:
    // 0x125738: 0x8e020080  lw          $v0, 0x80($s0)
    ctx->pc = 0x125738u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 128)));
    // 0x12573c: 0x8e040084  lw          $a0, 0x84($s0)
    ctx->pc = 0x12573cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 132)));
    // 0x125740: 0x8e050094  lw          $a1, 0x94($s0)
    ctx->pc = 0x125740u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 148)));
    // 0x125744: 0x40f809  jalr        $v0
    ctx->pc = 0x125744u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12574Cu);
        ctx->pc = 0x125748u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125744u;
            // 0x125748: 0x8e060090  lw          $a2, 0x90($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 144)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12574Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x125518u: goto label_125518;
            case 0x12555Cu: goto label_12555c;
            case 0x125590u: goto label_125590;
            case 0x1255B0u: goto label_1255b0;
            case 0x125628u: goto label_125628;
            case 0x125668u: goto label_125668;
            case 0x1256C4u: goto label_1256c4;
            case 0x1256E0u: goto label_1256e0;
            case 0x1256E8u: goto label_1256e8;
            case 0x1256F8u: goto label_1256f8;
            case 0x125700u: goto label_125700;
            case 0x125710u: goto label_125710;
            case 0x125718u: goto label_125718;
            case 0x125730u: goto label_125730;
            case 0x125738u: goto label_125738;
            case 0x12574Cu: goto label_12574c;
            case 0x125750u: goto label_125750;
            case 0x125754u: goto label_125754;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12574Cu; }
            if (ctx->pc != 0x12574Cu) { return; }
        }
        }
    }
    ctx->pc = 0x12574Cu;
label_12574c:
    // 0x12574c: 0xae110004  sw          $s1, 0x4($s0)
    ctx->pc = 0x12574cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 17));
label_125750:
    // 0x125750: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x125750u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_125754:
    // 0x125754: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x125754u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x125758: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x125758u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12575c: 0x3e00008  jr          $ra
    ctx->pc = 0x12575Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x125760u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12575Cu;
            // 0x125760: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x125518u: goto label_125518;
            case 0x12555Cu: goto label_12555c;
            case 0x125590u: goto label_125590;
            case 0x1255B0u: goto label_1255b0;
            case 0x125628u: goto label_125628;
            case 0x125668u: goto label_125668;
            case 0x1256C4u: goto label_1256c4;
            case 0x1256E0u: goto label_1256e0;
            case 0x1256E8u: goto label_1256e8;
            case 0x1256F8u: goto label_1256f8;
            case 0x125700u: goto label_125700;
            case 0x125710u: goto label_125710;
            case 0x125718u: goto label_125718;
            case 0x125730u: goto label_125730;
            case 0x125738u: goto label_125738;
            case 0x12574Cu: goto label_12574c;
            case 0x125750u: goto label_125750;
            case 0x125754u: goto label_125754;
            default: break;
        }
        return;
    }
    ctx->pc = 0x125764u;
    // 0x125764: 0x0  nop
    ctx->pc = 0x125764u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
