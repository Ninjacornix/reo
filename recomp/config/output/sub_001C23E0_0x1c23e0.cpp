#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C23E0
// Address: 0x1c23e0 - 0x1c2480
void sub_001C23E0_0x1c23e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C23E0_0x1c23e0");
#endif

    switch (ctx->pc) {
        case 0x1c2408u: goto label_1c2408;
        case 0x1c2450u: goto label_1c2450;
        default: break;
    }

    ctx->pc = 0x1c23e0u;

    // 0x1c23e0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1c23e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1c23e4: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1c23e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1c23e8: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1c23e8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1c23ec: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1c23ecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1c23f0: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1c23f0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c23f4: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c23f4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c23f8: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1c23f8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c23fc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c23fcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c2400: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1c2400u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c2404: 0x241003e8  addiu       $s0, $zero, 0x3E8
    ctx->pc = 0x1c2404u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1000));
label_1c2408:
    // 0x1c2408: 0x250001a  div         $zero, $s2, $s0
    ctx->pc = 0x1c2408u;
    { int32_t divisor = GPR_S32(ctx, 16);    int32_t dividend = GPR_S32(ctx, 18);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1c240c: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1c240cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1c2410: 0x2403000a  addiu       $v1, $zero, 0xA
    ctx->pc = 0x1c2410u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1c2414: 0x244259f0  addiu       $v0, $v0, 0x59F0
    ctx->pc = 0x1c2414u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 23024));
    // 0x1c2418: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1c2418u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c241c: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1c241cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c2420: 0x9010  mfhi        $s2
    ctx->pc = 0x1c2420u;
    SET_GPR_U64(ctx, 18, ctx->hi);
    // 0x1c2424: 0x203001a  div         $zero, $s0, $v1
    ctx->pc = 0x1c2424u;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 16);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1c2428: 0x0  nop
    ctx->pc = 0x1c2428u;
    // NOP
    // 0x1c242c: 0x0  nop
    ctx->pc = 0x1c242cu;
    // NOP
    // 0x1c2430: 0x8012  mflo        $s0
    ctx->pc = 0x1c2430u;
    SET_GPR_U64(ctx, 16, ctx->lo);
    // 0x1c2434: 0x250001a  div         $zero, $s2, $s0
    ctx->pc = 0x1c2434u;
    { int32_t divisor = GPR_S32(ctx, 16);    int32_t dividend = GPR_S32(ctx, 18);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1c2438: 0x0  nop
    ctx->pc = 0x1c2438u;
    // NOP
    // 0x1c243c: 0x0  nop
    ctx->pc = 0x1c243cu;
    // NOP
    // 0x1c2440: 0x1812  mflo        $v1
    ctx->pc = 0x1c2440u;
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x1c2444: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x1c2444u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1c2448: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x1C2448u;
    SET_GPR_U32(ctx, 31, 0x1C2450u);
    ctx->pc = 0x1C244Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2448u;
            // 0x1c244c: 0x432821  addu        $a1, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2450u; }
        if (ctx->pc != 0x1C2450u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C2450u; }
        if (ctx->pc != 0x1C2450u) { return; }
    }
    ctx->pc = 0x1C2450u;
label_1c2450:
    // 0x1c2450: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1c2450u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1c2454: 0x2a230003  slti        $v1, $s1, 0x3
    ctx->pc = 0x1c2454u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x1c2458: 0x1460ffeb  bnez        $v1, . + 4 + (-0x15 << 2)
    ctx->pc = 0x1C2458u;
    {
        const bool branch_taken_0x1c2458 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C245Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2458u;
            // 0x1c245c: 0x26730002  addiu       $s3, $s3, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c2458) {
            ctx->pc = 0x1C2408u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c2408;
        }
    }
    ctx->pc = 0x1C2460u;
    // 0x1c2460: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1c2460u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1c2464: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1c2464u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1c2468: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1c2468u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c246c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c246cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c2470: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c2470u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c2474: 0x3e00008  jr          $ra
    ctx->pc = 0x1C2474u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C2478u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C2474u;
            // 0x1c2478: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C2408u: goto label_1c2408;
            case 0x1C2450u: goto label_1c2450;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C247Cu;
    // 0x1c247c: 0x0  nop
    ctx->pc = 0x1c247cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
