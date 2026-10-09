#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CE800
// Address: 0x1ce800 - 0x1ce8b0
void sub_001CE800_0x1ce800(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CE800_0x1ce800");
#endif

    switch (ctx->pc) {
        case 0x1ce81cu: goto label_1ce81c;
        case 0x1ce854u: goto label_1ce854;
        case 0x1ce890u: goto label_1ce890;
        default: break;
    }

    ctx->pc = 0x1ce800u;

    // 0x1ce800: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1ce800u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1ce804: 0xc0382d  daddu       $a3, $a2, $zero
    ctx->pc = 0x1ce804u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ce808: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1ce808u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1ce80c: 0x80482d  daddu       $t1, $a0, $zero
    ctx->pc = 0x1ce80cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ce810: 0xa0402d  daddu       $t0, $a1, $zero
    ctx->pc = 0x1ce810u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ce814: 0xc0739e4  jal         func_1CE790
    ctx->pc = 0x1CE814u;
    SET_GPR_U32(ctx, 31, 0x1CE81Cu);
    ctx->pc = 0x1CE818u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CE814u;
            // 0x1ce818: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CE790u;
    if (runtime->hasFunction(0x1CE790u)) {
        auto targetFn = runtime->lookupFunction(0x1CE790u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CE81Cu; }
        if (ctx->pc != 0x1CE81Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CE790_0x1ce790(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CE81Cu; }
        if (ctx->pc != 0x1CE81Cu) { return; }
    }
    ctx->pc = 0x1CE81Cu;
label_1ce81c:
    // 0x1ce81c: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1CE81Cu;
    {
        const bool branch_taken_0x1ce81c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CE820u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CE81Cu;
            // 0x1ce820: 0xe0202d  daddu       $a0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ce81c) {
            ctx->pc = 0x1CE84Cu;
            goto label_1ce84c;
        }
    }
    ctx->pc = 0x1CE824u;
    // 0x1ce824: 0x9044000f  lbu         $a0, 0xF($v0)
    ctx->pc = 0x1ce824u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 15)));
    // 0x1ce828: 0xe01827  not         $v1, $a3
    ctx->pc = 0x1ce828u;
    SET_GPR_U64(ctx, 3, ~(GPR_U64(ctx, 7) | GPR_U64(ctx, 0)));
    // 0x1ce82c: 0x831824  and         $v1, $a0, $v1
    ctx->pc = 0x1ce82cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & GPR_U64(ctx, 3));
    // 0x1ce830: 0xe31825  or          $v1, $a3, $v1
    ctx->pc = 0x1ce830u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x1ce834: 0xa043000f  sb          $v1, 0xF($v0)
    ctx->pc = 0x1ce834u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 15), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ce838: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x1ce838u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ce83c: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1ce83cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1ce840: 0xa0430000  sb          $v1, 0x0($v0)
    ctx->pc = 0x1ce840u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ce844: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x1CE844u;
    {
        const bool branch_taken_0x1ce844 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CE848u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CE844u;
            // 0x1ce848: 0x9042000e  lbu         $v0, 0xE($v0) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ce844) {
            ctx->pc = 0x1CE894u;
            goto label_1ce894;
        }
    }
    ctx->pc = 0x1CE84Cu;
label_1ce84c:
    // 0x1ce84c: 0xc0739c0  jal         func_1CE700
    ctx->pc = 0x1CE84Cu;
    SET_GPR_U32(ctx, 31, 0x1CE854u);
    ctx->pc = 0x1CE700u;
    if (runtime->hasFunction(0x1CE700u)) {
        auto targetFn = runtime->lookupFunction(0x1CE700u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CE854u; }
        if (ctx->pc != 0x1CE854u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CE700_0x1ce700(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CE854u; }
        if (ctx->pc != 0x1CE854u) { return; }
    }
    ctx->pc = 0x1CE854u;
label_1ce854:
    // 0x1ce854: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1ce854u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ce858: 0x16000003  bnez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CE858u;
    {
        const bool branch_taken_0x1ce858 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x1ce858) {
            ctx->pc = 0x1CE868u;
            goto label_1ce868;
        }
    }
    ctx->pc = 0x1CE860u;
    // 0x1ce860: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1CE860u;
    {
        const bool branch_taken_0x1ce860 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CE864u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CE860u;
            // 0x1ce864: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ce860) {
            ctx->pc = 0x1CE894u;
            goto label_1ce894;
        }
    }
    ctx->pc = 0x1CE868u;
label_1ce868:
    // 0x1ce868: 0x3102ffff  andi        $v0, $t0, 0xFFFF
    ctx->pc = 0x1ce868u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 8) & (uint64_t)(uint16_t)65535);
    // 0x1ce86c: 0xa6080012  sh          $t0, 0x12($s0)
    ctx->pc = 0x1ce86cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 18), (uint16_t)GPR_U32(ctx, 8));
    // 0x1ce870: 0x30457fff  andi        $a1, $v0, 0x7FFF
    ctx->pc = 0x1ce870u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)32767);
    // 0x1ce874: 0x120202d  daddu       $a0, $t1, $zero
    ctx->pc = 0x1ce874u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ce878: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1ce878u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ce87c: 0x26060002  addiu       $a2, $s0, 0x2
    ctx->pc = 0x1ce87cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 2));
    // 0x1ce880: 0xa2020000  sb          $v0, 0x0($s0)
    ctx->pc = 0x1ce880u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ce884: 0xa207000f  sb          $a3, 0xF($s0)
    ctx->pc = 0x1ce884u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 15), (uint8_t)GPR_U32(ctx, 7));
    // 0x1ce888: 0xc073aac  jal         func_1CEAB0
    ctx->pc = 0x1CE888u;
    SET_GPR_U32(ctx, 31, 0x1CE890u);
    ctx->pc = 0x1CE88Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CE888u;
            // 0x1ce88c: 0xa2090010  sb          $t1, 0x10($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 16), (uint8_t)GPR_U32(ctx, 9));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CEAB0u;
    if (runtime->hasFunction(0x1CEAB0u)) {
        auto targetFn = runtime->lookupFunction(0x1CEAB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CE890u; }
        if (ctx->pc != 0x1CE890u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CEAB0_0x1ceab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CE890u; }
        if (ctx->pc != 0x1CE890u) { return; }
    }
    ctx->pc = 0x1CE890u;
label_1ce890:
    // 0x1ce890: 0x9202000e  lbu         $v0, 0xE($s0)
    ctx->pc = 0x1ce890u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
label_1ce894:
    // 0x1ce894: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1ce894u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ce898: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ce898u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ce89c: 0x3e00008  jr          $ra
    ctx->pc = 0x1CE89Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CE8A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CE89Cu;
            // 0x1ce8a0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CE81Cu: goto label_1ce81c;
            case 0x1CE84Cu: goto label_1ce84c;
            case 0x1CE854u: goto label_1ce854;
            case 0x1CE868u: goto label_1ce868;
            case 0x1CE890u: goto label_1ce890;
            case 0x1CE894u: goto label_1ce894;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CE8A4u;
    // 0x1ce8a4: 0x0  nop
    ctx->pc = 0x1ce8a4u;
    // NOP
    // 0x1ce8a8: 0x0  nop
    ctx->pc = 0x1ce8a8u;
    // NOP
    // 0x1ce8ac: 0x0  nop
    ctx->pc = 0x1ce8acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
