#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00166720
// Address: 0x166720 - 0x166880
void sub_00166720_0x166720(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00166720_0x166720");
#endif

    switch (ctx->pc) {
        case 0x16675cu: goto label_16675c;
        case 0x16678cu: goto label_16678c;
        case 0x1667a8u: goto label_1667a8;
        case 0x1667c4u: goto label_1667c4;
        case 0x1667e8u: goto label_1667e8;
        case 0x166804u: goto label_166804;
        case 0x166818u: goto label_166818;
        case 0x166830u: goto label_166830;
        case 0x166844u: goto label_166844;
        case 0x166858u: goto label_166858;
        default: break;
    }

    ctx->pc = 0x166720u;

    // 0x166720: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x166720u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x166724: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x166724u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x166728: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x166728u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16672c: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x16672cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x166730: 0x26110008  addiu       $s1, $s0, 0x8
    ctx->pc = 0x166730u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
    // 0x166734: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x166734u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x166738: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x166738u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16673c: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x16673cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x166740: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x166740u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166744: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x166744u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x166748: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x166748u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16674c: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x16674cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x166750: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x166750u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166754: 0xc059a20  jal         func_166880
    ctx->pc = 0x166754u;
    SET_GPR_U32(ctx, 31, 0x16675Cu);
    ctx->pc = 0x166758u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166754u;
            // 0x166758: 0x8e060004  lw          $a2, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166880u;
    if (runtime->hasFunction(0x166880u)) {
        auto targetFn = runtime->lookupFunction(0x166880u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16675Cu; }
        if (ctx->pc != 0x16675Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166880_0x166880(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16675Cu; }
        if (ctx->pc != 0x16675Cu) { return; }
    }
    ctx->pc = 0x16675Cu;
label_16675c:
    // 0x16675c: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x16675cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x166760: 0x8e020028  lw          $v0, 0x28($s0)
    ctx->pc = 0x166760u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x166764: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x166764u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166768: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x166768u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16676c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x16676cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166770: 0x62001a  div         $zero, $v1, $v0
    ctx->pc = 0x166770u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x166774: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x166774u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166778: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x166778u;
    {
        const bool branch_taken_0x166778 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x166778) {
            ctx->pc = 0x16677Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x166778u;
            // 0x16677c: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x166780u;
            goto label_166780;
        }
    }
    ctx->pc = 0x166780u;
label_166780:
    // 0x166780: 0x4010  mfhi        $t0
    ctx->pc = 0x166780u;
    SET_GPR_U64(ctx, 8, ctx->hi);
    // 0x166784: 0xc059a30  jal         func_1668C0
    ctx->pc = 0x166784u;
    SET_GPR_U32(ctx, 31, 0x16678Cu);
    ctx->pc = 0x1668C0u;
    if (runtime->hasFunction(0x1668C0u)) {
        auto targetFn = runtime->lookupFunction(0x1668C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16678Cu; }
        if (ctx->pc != 0x16678Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001668C0_0x1668c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16678Cu; }
        if (ctx->pc != 0x16678Cu) { return; }
    }
    ctx->pc = 0x16678Cu;
label_16678c:
    // 0x16678c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x16678cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166790: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x166790u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166794: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x166794u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166798: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x166798u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16679c: 0x24080800  addiu       $t0, $zero, 0x800
    ctx->pc = 0x16679cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
    // 0x1667a0: 0xc059a30  jal         func_1668C0
    ctx->pc = 0x1667A0u;
    SET_GPR_U32(ctx, 31, 0x1667A8u);
    ctx->pc = 0x1667A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1667A0u;
            // 0x1667a4: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1668C0u;
    if (runtime->hasFunction(0x1668C0u)) {
        auto targetFn = runtime->lookupFunction(0x1668C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1667A8u; }
        if (ctx->pc != 0x1667A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001668C0_0x1668c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1667A8u; }
        if (ctx->pc != 0x1667A8u) { return; }
    }
    ctx->pc = 0x1667A8u;
label_1667a8:
    // 0x1667a8: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x1667a8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1667ac: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1667acu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1667b0: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1667b0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1667b4: 0x24070002  addiu       $a3, $zero, 0x2
    ctx->pc = 0x1667b4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1667b8: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1667b8u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1667bc: 0xc059a30  jal         func_1668C0
    ctx->pc = 0x1667BCu;
    SET_GPR_U32(ctx, 31, 0x1667C4u);
    ctx->pc = 0x1667C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1667BCu;
            // 0x1667c0: 0x40a02d  daddu       $s4, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1668C0u;
    if (runtime->hasFunction(0x1668C0u)) {
        auto targetFn = runtime->lookupFunction(0x1668C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1667C4u; }
        if (ctx->pc != 0x1667C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001668C0_0x1668c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1667C4u; }
        if (ctx->pc != 0x1667C4u) { return; }
    }
    ctx->pc = 0x1667C4u;
label_1667c4:
    // 0x1667c4: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1667c4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1667c8: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1667C8u;
    {
        const bool branch_taken_0x1667c8 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x1667CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1667C8u;
            // 0x1667cc: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1667c8) {
            ctx->pc = 0x1667E0u;
            goto label_1667e0;
        }
    }
    ctx->pc = 0x1667D0u;
    // 0x1667d0: 0x16800003  bnez        $s4, . + 4 + (0x3 << 2)
    ctx->pc = 0x1667D0u;
    {
        const bool branch_taken_0x1667d0 = (GPR_U64(ctx, 20) != GPR_U64(ctx, 0));
        if (branch_taken_0x1667d0) {
            ctx->pc = 0x1667E0u;
            goto label_1667e0;
        }
    }
    ctx->pc = 0x1667D8u;
    // 0x1667d8: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1667D8u;
    {
        const bool branch_taken_0x1667d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1667DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1667D8u;
            // 0x1667dc: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1667d8) {
            ctx->pc = 0x1667F0u;
            goto label_1667f0;
        }
    }
    ctx->pc = 0x1667E0u;
label_1667e0:
    // 0x1667e0: 0xc05a704  jal         func_169C10
    ctx->pc = 0x1667E0u;
    SET_GPR_U32(ctx, 31, 0x1667E8u);
    ctx->pc = 0x1667E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1667E0u;
            // 0x1667e4: 0x34a5040a  ori         $a1, $a1, 0x40A (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1034);
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1667E8u; }
        if (ctx->pc != 0x1667E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1667E8u; }
        if (ctx->pc != 0x1667E8u) { return; }
    }
    ctx->pc = 0x1667E8u;
label_1667e8:
    // 0x1667e8: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x1667E8u;
    {
        const bool branch_taken_0x1667e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1667ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1667E8u;
            // 0x1667ec: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1667e8) {
            ctx->pc = 0x166860u;
            goto label_166860;
        }
    }
    ctx->pc = 0x1667F0u;
label_1667f0:
    // 0x1667f0: 0x24080003  addiu       $t0, $zero, 0x3
    ctx->pc = 0x1667f0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1667f4: 0x220382d  daddu       $a3, $s1, $zero
    ctx->pc = 0x1667f4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1667f8: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1667f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1667fc: 0xc059aa2  jal         func_166A88
    ctx->pc = 0x1667FCu;
    SET_GPR_U32(ctx, 31, 0x166804u);
    ctx->pc = 0x166800u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1667FCu;
            // 0x166800: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166A88u;
    if (runtime->hasFunction(0x166A88u)) {
        auto targetFn = runtime->lookupFunction(0x166A88u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166804u; }
        if (ctx->pc != 0x166804u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166A88_0x166a88(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166804u; }
        if (ctx->pc != 0x166804u) { return; }
    }
    ctx->pc = 0x166804u;
label_166804:
    // 0x166804: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x166804u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166808: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x166808u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16680c: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x16680cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166810: 0xc059ad0  jal         func_166B40
    ctx->pc = 0x166810u;
    SET_GPR_U32(ctx, 31, 0x166818u);
    ctx->pc = 0x166814u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166810u;
            // 0x166814: 0x24070004  addiu       $a3, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166B40u;
    if (runtime->hasFunction(0x166B40u)) {
        auto targetFn = runtime->lookupFunction(0x166B40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166818u; }
        if (ctx->pc != 0x166818u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166B40_0x166b40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166818u; }
        if (ctx->pc != 0x166818u) { return; }
    }
    ctx->pc = 0x166818u;
label_166818:
    // 0x166818: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x166818u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16681c: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x16681cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166820: 0x24080005  addiu       $t0, $zero, 0x5
    ctx->pc = 0x166820u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x166824: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x166824u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166828: 0xc059aa2  jal         func_166A88
    ctx->pc = 0x166828u;
    SET_GPR_U32(ctx, 31, 0x166830u);
    ctx->pc = 0x16682Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166828u;
            // 0x16682c: 0x220382d  daddu       $a3, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166A88u;
    if (runtime->hasFunction(0x166A88u)) {
        auto targetFn = runtime->lookupFunction(0x166A88u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166830u; }
        if (ctx->pc != 0x166830u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166A88_0x166a88(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166830u; }
        if (ctx->pc != 0x166830u) { return; }
    }
    ctx->pc = 0x166830u;
label_166830:
    // 0x166830: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x166830u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166834: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x166834u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166838: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x166838u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16683c: 0xc059ad0  jal         func_166B40
    ctx->pc = 0x16683Cu;
    SET_GPR_U32(ctx, 31, 0x166844u);
    ctx->pc = 0x166840u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16683Cu;
            // 0x166840: 0x24070006  addiu       $a3, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166B40u;
    if (runtime->hasFunction(0x166B40u)) {
        auto targetFn = runtime->lookupFunction(0x166B40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166844u; }
        if (ctx->pc != 0x166844u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166B40_0x166b40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166844u; }
        if (ctx->pc != 0x166844u) { return; }
    }
    ctx->pc = 0x166844u;
label_166844:
    // 0x166844: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x166844u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166848: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x166848u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16684c: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x16684cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166850: 0xc059b1a  jal         func_166C68
    ctx->pc = 0x166850u;
    SET_GPR_U32(ctx, 31, 0x166858u);
    ctx->pc = 0x166854u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166850u;
            // 0x166854: 0x24070007  addiu       $a3, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166C68u;
    if (runtime->hasFunction(0x166C68u)) {
        auto targetFn = runtime->lookupFunction(0x166C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166858u; }
        if (ctx->pc != 0x166858u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166C68_0x166c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166858u; }
        if (ctx->pc != 0x166858u) { return; }
    }
    ctx->pc = 0x166858u;
label_166858:
    // 0x166858: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x166858u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16685c: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x16685cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_166860:
    // 0x166860: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x166860u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x166864: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x166864u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x166868: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x166868u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x16686c: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x16686cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x166870: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x166870u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x166874: 0x3e00008  jr          $ra
    ctx->pc = 0x166874u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x166878u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166874u;
            // 0x166878: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16675Cu: goto label_16675c;
            case 0x166780u: goto label_166780;
            case 0x16678Cu: goto label_16678c;
            case 0x1667A8u: goto label_1667a8;
            case 0x1667C4u: goto label_1667c4;
            case 0x1667E0u: goto label_1667e0;
            case 0x1667E8u: goto label_1667e8;
            case 0x1667F0u: goto label_1667f0;
            case 0x166804u: goto label_166804;
            case 0x166818u: goto label_166818;
            case 0x166830u: goto label_166830;
            case 0x166844u: goto label_166844;
            case 0x166858u: goto label_166858;
            case 0x166860u: goto label_166860;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16687Cu;
    // 0x16687c: 0x0  nop
    ctx->pc = 0x16687cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
