#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012E968
// Address: 0x12e968 - 0x12ebf0
void sub_0012E968_0x12e968(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012E968_0x12e968");
#endif

    switch (ctx->pc) {
        case 0x12ea10u: goto label_12ea10;
        case 0x12ea18u: goto label_12ea18;
        case 0x12ea34u: goto label_12ea34;
        case 0x12ea44u: goto label_12ea44;
        case 0x12ea4cu: goto label_12ea4c;
        case 0x12eae4u: goto label_12eae4;
        case 0x12eaf0u: goto label_12eaf0;
        case 0x12eaf8u: goto label_12eaf8;
        default: break;
    }

    ctx->pc = 0x12e968u;

    // 0x12e968: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x12e968u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x12e96c: 0x24060008  addiu       $a2, $zero, 0x8
    ctx->pc = 0x12e96cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x12e970: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x12e970u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x12e974: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x12e974u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12e978: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x12e978u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x12e97c: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x12e97cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12e980: 0xffb60050  sd          $s6, 0x50($sp)
    ctx->pc = 0x12e980u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 22));
    // 0x12e984: 0x52080  sll         $a0, $a1, 2
    ctx->pc = 0x12e984u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x12e988: 0xffb70058  sd          $s7, 0x58($sp)
    ctx->pc = 0x12e988u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 23));
    // 0x12e98c: 0x51980  sll         $v1, $a1, 6
    ctx->pc = 0x12e98cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 6));
    // 0x12e990: 0xffbe0060  sd          $fp, 0x60($sp)
    ctx->pc = 0x12e990u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 30));
    // 0x12e994: 0x241effff  addiu       $fp, $zero, -0x1
    ctx->pc = 0x12e994u;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x12e998: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x12e998u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x12e99c: 0x52900  sll         $a1, $a1, 4
    ctx->pc = 0x12e99cu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 4));
    // 0x12e9a0: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x12e9a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x12e9a4: 0x2631821  addu        $v1, $s3, $v1
    ctx->pc = 0x12e9a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 3)));
    // 0x12e9a8: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x12e9a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x12e9ac: 0x2652821  addu        $a1, $s3, $a1
    ctx->pc = 0x12e9acu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 5)));
    // 0x12e9b0: 0xffb50048  sd          $s5, 0x48($sp)
    ctx->pc = 0x12e9b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 21));
    // 0x12e9b4: 0x24a502a8  addiu       $a1, $a1, 0x2A8
    ctx->pc = 0x12e9b4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 680));
    // 0x12e9b8: 0xffbf0068  sd          $ra, 0x68($sp)
    ctx->pc = 0x12e9b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 31));
    // 0x12e9bc: 0x932021  addu        $a0, $a0, $s3
    ctx->pc = 0x12e9bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 19)));
    // 0x12e9c0: 0x8e620054  lw          $v0, 0x54($s3)
    ctx->pc = 0x12e9c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 84)));
    // 0x12e9c4: 0xc2001a  div         $zero, $a2, $v0
    ctx->pc = 0x12e9c4u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 6);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x12e9c8: 0x24660210  addiu       $a2, $v1, 0x210
    ctx->pc = 0x12e9c8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), 528));
    // 0x12e9cc: 0x3812  mflo        $a3
    ctx->pc = 0x12e9ccu;
    SET_GPR_U64(ctx, 7, ctx->lo);
    // 0x12e9d0: 0xafa70014  sw          $a3, 0x14($sp)
    ctx->pc = 0x12e9d0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 7));
    // 0x12e9d4: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x12E9D4u;
    {
        const bool branch_taken_0x12e9d4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x12e9d4) {
            ctx->pc = 0x12E9D8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12E9D4u;
            // 0x12e9d8: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x12E9DCu;
            goto label_12e9dc;
        }
    }
    ctx->pc = 0x12E9DCu;
label_12e9dc:
    // 0x12e9dc: 0x8e620044  lw          $v0, 0x44($s3)
    ctx->pc = 0x12e9dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 68)));
    // 0x12e9e0: 0x24670110  addiu       $a3, $v1, 0x110
    ctx->pc = 0x12e9e0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 3), 272));
    // 0x12e9e4: 0xafa6000c  sw          $a2, 0xC($sp)
    ctx->pc = 0x12e9e4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 6));
    // 0x12e9e8: 0x24630190  addiu       $v1, $v1, 0x190
    ctx->pc = 0x12e9e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 400));
    // 0x12e9ec: 0xafa50010  sw          $a1, 0x10($sp)
    ctx->pc = 0x12e9ecu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 5));
    // 0x12e9f0: 0x8fb60014  lw          $s6, 0x14($sp)
    ctx->pc = 0x12e9f0u;
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x12e9f4: 0x8c970080  lw          $s7, 0x80($a0)
    ctx->pc = 0x12e9f4u;
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 128)));
    // 0x12e9f8: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x12e9f8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x12e9fc: 0xafa70004  sw          $a3, 0x4($sp)
    ctx->pc = 0x12e9fcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 7));
    // 0x12ea00: 0x1840006e  blez        $v0, . + 4 + (0x6E << 2)
    ctx->pc = 0x12EA00u;
    {
        const bool branch_taken_0x12ea00 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x12EA04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12EA00u;
            // 0x12ea04: 0xafa30008  sw          $v1, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ea00) {
            ctx->pc = 0x12EBBCu;
            goto label_12ebbc;
        }
    }
    ctx->pc = 0x12EA08u;
    // 0x12ea08: 0x24151249  addiu       $s5, $zero, 0x1249
    ctx->pc = 0x12ea08u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), 4681));
    // 0x12ea0c: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x12ea0cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
label_12ea10:
    // 0x12ea10: 0xc04b954  jal         func_12E550
    ctx->pc = 0x12EA10u;
    SET_GPR_U32(ctx, 31, 0x12EA18u);
    ctx->pc = 0x12EA14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12EA10u;
            // 0x12ea14: 0x2e0202d  daddu       $a0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12E550u;
    if (runtime->hasFunction(0x12E550u)) {
        auto targetFn = runtime->lookupFunction(0x12E550u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12EA18u; }
        if (ctx->pc != 0x12EA18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012E550_0x12e550(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12EA18u; }
        if (ctx->pc != 0x12EA18u) { return; }
    }
    ctx->pc = 0x12EA18u;
label_12ea18:
    // 0x12ea18: 0x148840  sll         $s1, $s4, 1
    ctx->pc = 0x12ea18u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 20), 1));
    // 0x12ea1c: 0x8fa40004  lw          $a0, 0x4($sp)
    ctx->pc = 0x12ea1cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x12ea20: 0x2241821  addu        $v1, $s1, $a0
    ctx->pc = 0x12ea20u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 4)));
    // 0x12ea24: 0x22400  sll         $a0, $v0, 16
    ctx->pc = 0x12ea24u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x12ea28: 0xa4620000  sh          $v0, 0x0($v1)
    ctx->pc = 0x12ea28u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x12ea2c: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x12EA2Cu;
    SET_GPR_U32(ctx, 31, 0x12EA34u);
    ctx->pc = 0x12EA30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12EA2Cu;
            // 0x12ea30: 0x42403  sra         $a0, $a0, 16 (Delay Slot)
        SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12EA34u; }
        if (ctx->pc != 0x12EA34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12EA34u; }
        if (ctx->pc != 0x12EA34u) { return; }
    }
    ctx->pc = 0x12EA34u;
label_12ea34:
    // 0x12ea34: 0xdef20080  ld          $s2, 0x80($s7)
    ctx->pc = 0x12ea34u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 23), 128)));
    // 0x12ea38: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x12ea38u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ea3c: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x12EA3Cu;
    SET_GPR_U32(ctx, 31, 0x12EA44u);
    ctx->pc = 0x12EA40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12EA3Cu;
            // 0x12ea40: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12EA44u; }
        if (ctx->pc != 0x12EA44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12EA44u; }
        if (ctx->pc != 0x12EA44u) { return; }
    }
    ctx->pc = 0x12EA44u;
label_12ea44:
    // 0x12ea44: 0xc0448e8  jal         func_1123A0
    ctx->pc = 0x12EA44u;
    SET_GPR_U32(ctx, 31, 0x12EA4Cu);
    ctx->pc = 0x12EA48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12EA44u;
            // 0x12ea48: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1123A0u;
    if (runtime->hasFunction(0x1123A0u)) {
        auto targetFn = runtime->lookupFunction(0x1123A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12EA4Cu; }
        if (ctx->pc != 0x12EA4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001123A0_0x1123a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12EA4Cu; }
        if (ctx->pc != 0x12EA4Cu) { return; }
    }
    ctx->pc = 0x12EA4Cu;
label_12ea4c:
    // 0x12ea4c: 0x24057fff  addiu       $a1, $zero, 0x7FFF
    ctx->pc = 0x12ea4cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 32767));
    // 0x12ea50: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x12ea50u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ea54: 0xa4102a  slt         $v0, $a1, $a0
    ctx->pc = 0x12ea54u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x12ea58: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x12EA58u;
    {
        const bool branch_taken_0x12ea58 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12EA5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12EA58u;
            // 0x12ea5c: 0x24037fff  addiu       $v1, $zero, 0x7FFF (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 32767));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ea58) {
            ctx->pc = 0x12EA78u;
            goto label_12ea78;
        }
    }
    ctx->pc = 0x12EA60u;
    // 0x12ea60: 0x80182d  daddu       $v1, $a0, $zero
    ctx->pc = 0x12ea60u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ea64: 0x28628000  slti        $v0, $v1, -0x8000
    ctx->pc = 0x12ea64u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)4294934528) ? 1 : 0);
    // 0x12ea68: 0x54400003  bnel        $v0, $zero, . + 4 + (0x3 << 2)
    ctx->pc = 0x12EA68u;
    {
        const bool branch_taken_0x12ea68 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x12ea68) {
            ctx->pc = 0x12EA6Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12EA68u;
            // 0x12ea6c: 0x24038000  addiu       $v1, $zero, -0x8000 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294934528));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12EA78u;
            goto label_12ea78;
        }
    }
    ctx->pc = 0x12EA70u;
    // 0x12ea70: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x12EA70u;
    {
        const bool branch_taken_0x12ea70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12EA74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12EA70u;
            // 0x12ea74: 0x8fa60008  lw          $a2, 0x8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ea70) {
            ctx->pc = 0x12EA7Cu;
            goto label_12ea7c;
        }
    }
    ctx->pc = 0x12EA78u;
label_12ea78:
    // 0x12ea78: 0x8fa60008  lw          $a2, 0x8($sp)
    ctx->pc = 0x12ea78u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
label_12ea7c:
    // 0x12ea7c: 0x60202d  daddu       $a0, $v1, $zero
    ctx->pc = 0x12ea7cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ea80: 0x41c00  sll         $v1, $a0, 16
    ctx->pc = 0x12ea80u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x12ea84: 0x2261021  addu        $v0, $s1, $a2
    ctx->pc = 0x12ea84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 6)));
    // 0x12ea88: 0x4610003  bgez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x12EA88u;
    {
        const bool branch_taken_0x12ea88 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x12EA8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12EA88u;
            // 0x12ea8c: 0xa4440000  sh          $a0, 0x0($v0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ea88) {
            ctx->pc = 0x12EA98u;
            goto label_12ea98;
        }
    }
    ctx->pc = 0x12EA90u;
    // 0x12ea90: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x12EA90u;
    {
        const bool branch_taken_0x12ea90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12EA94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12EA90u;
            // 0x12ea94: 0x2482f6dc  addiu       $v0, $a0, -0x924 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 4294964956));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ea90) {
            ctx->pc = 0x12EA9Cu;
            goto label_12ea9c;
        }
    }
    ctx->pc = 0x12EA98u;
label_12ea98:
    // 0x12ea98: 0x24820924  addiu       $v0, $a0, 0x924
    ctx->pc = 0x12ea98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 2340));
label_12ea9c:
    // 0x12ea9c: 0x52a00001  beql        $s5, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x12EA9Cu;
    {
        const bool branch_taken_0x12ea9c = (GPR_U64(ctx, 21) == GPR_U64(ctx, 0));
        if (branch_taken_0x12ea9c) {
            ctx->pc = 0x12EAA0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12EA9Cu;
            // 0x12eaa0: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x12EAA4u;
            goto label_12eaa4;
        }
    }
    ctx->pc = 0x12EAA4u;
label_12eaa4:
    // 0x12eaa4: 0x55001a  div         $zero, $v0, $s5
    ctx->pc = 0x12eaa4u;
    { int32_t divisor = GPR_S32(ctx, 21);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x12eaa8: 0x1012  mflo        $v0
    ctx->pc = 0x12eaa8u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x12eaac: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x12eaacu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12eab0: 0x28820007  slti        $v0, $a0, 0x7
    ctx->pc = 0x12eab0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)7) ? 1 : 0);
    // 0x12eab4: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x12EAB4u;
    {
        const bool branch_taken_0x12eab4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x12EAB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12EAB4u;
            // 0x12eab8: 0x24100007  addiu       $s0, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12eab4) {
            ctx->pc = 0x12EAD8u;
            goto label_12ead8;
        }
    }
    ctx->pc = 0x12EABCu;
    // 0x12eabc: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x12eabcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12eac0: 0x2a02fff8  slti        $v0, $s0, -0x8
    ctx->pc = 0x12eac0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)4294967288) ? 1 : 0);
    // 0x12eac4: 0x54400004  bnel        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x12EAC4u;
    {
        const bool branch_taken_0x12eac4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x12eac4) {
            ctx->pc = 0x12EAC8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12EAC4u;
            // 0x12eac8: 0x2410fff8  addiu       $s0, $zero, -0x8 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967288));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12EAD8u;
            goto label_12ead8;
        }
    }
    ctx->pc = 0x12EACCu;
    // 0x12eacc: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x12EACCu;
    {
        const bool branch_taken_0x12eacc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12EAD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12EACCu;
            // 0x12ead0: 0x86e4007c  lh          $a0, 0x7C($s7) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 23), 124)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12eacc) {
            ctx->pc = 0x12EADCu;
            goto label_12eadc;
        }
    }
    ctx->pc = 0x12EAD4u;
    // 0x12ead4: 0x0  nop
    ctx->pc = 0x12ead4u;
    // NOP
label_12ead8:
    // 0x12ead8: 0x86e4007c  lh          $a0, 0x7C($s7)
    ctx->pc = 0x12ead8u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 23), 124)));
label_12eadc:
    // 0x12eadc: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x12EADCu;
    SET_GPR_U32(ctx, 31, 0x12EAE4u);
    ctx->pc = 0x12EAE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12EADCu;
            // 0x12eae0: 0x2042018  mult        $a0, $s0, $a0 (Delay Slot)
        { int64_t result = (int64_t)GPR_S32(ctx, 16) * (int64_t)GPR_S32(ctx, 4); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12EAE4u; }
        if (ctx->pc != 0x12EAE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12EAE4u; }
        if (ctx->pc != 0x12EAE4u) { return; }
    }
    ctx->pc = 0x12EAE4u;
label_12eae4:
    // 0x12eae4: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x12eae4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12eae8: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x12EAE8u;
    SET_GPR_U32(ctx, 31, 0x12EAF0u);
    ctx->pc = 0x12EAECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12EAE8u;
            // 0x12eaec: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12EAF0u; }
        if (ctx->pc != 0x12EAF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12EAF0u; }
        if (ctx->pc != 0x12EAF0u) { return; }
    }
    ctx->pc = 0x12EAF0u;
label_12eaf0:
    // 0x12eaf0: 0xc0448e8  jal         func_1123A0
    ctx->pc = 0x12EAF0u;
    SET_GPR_U32(ctx, 31, 0x12EAF8u);
    ctx->pc = 0x12EAF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12EAF0u;
            // 0x12eaf4: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1123A0u;
    if (runtime->hasFunction(0x1123A0u)) {
        auto targetFn = runtime->lookupFunction(0x1123A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12EAF8u; }
        if (ctx->pc != 0x12EAF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001123A0_0x1123a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12EAF8u; }
        if (ctx->pc != 0x12EAF8u) { return; }
    }
    ctx->pc = 0x12EAF8u;
label_12eaf8:
    // 0x12eaf8: 0x24037fff  addiu       $v1, $zero, 0x7FFF
    ctx->pc = 0x12eaf8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 32767));
    // 0x12eafc: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x12eafcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12eb00: 0x64102a  slt         $v0, $v1, $a0
    ctx->pc = 0x12eb00u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x12eb04: 0x54400006  bnel        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x12EB04u;
    {
        const bool branch_taken_0x12eb04 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x12eb04) {
            ctx->pc = 0x12EB08u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12EB04u;
            // 0x12eb08: 0x24047fff  addiu       $a0, $zero, 0x7FFF (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 32767));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12EB20u;
            goto label_12eb20;
        }
    }
    ctx->pc = 0x12EB0Cu;
    // 0x12eb0c: 0x28828000  slti        $v0, $a0, -0x8000
    ctx->pc = 0x12eb0cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)4294934528) ? 1 : 0);
    // 0x12eb10: 0x54400003  bnel        $v0, $zero, . + 4 + (0x3 << 2)
    ctx->pc = 0x12EB10u;
    {
        const bool branch_taken_0x12eb10 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x12eb10) {
            ctx->pc = 0x12EB14u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12EB10u;
            // 0x12eb14: 0x24048000  addiu       $a0, $zero, -0x8000 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294934528));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12EB20u;
            goto label_12eb20;
        }
    }
    ctx->pc = 0x12EB18u;
    // 0x12eb18: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x12EB18u;
    {
        const bool branch_taken_0x12eb18 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12EB1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12EB18u;
            // 0x12eb1c: 0x296001a  div         $zero, $s4, $s6 (Delay Slot)
        { int32_t divisor = GPR_S32(ctx, 22);    int32_t dividend = GPR_S32(ctx, 20);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
        ctx->in_delay_slot = false;
        if (branch_taken_0x12eb18) {
            ctx->pc = 0x12EB24u;
            goto label_12eb24;
        }
    }
    ctx->pc = 0x12EB20u;
label_12eb20:
    // 0x12eb20: 0x296001a  div         $zero, $s4, $s6
    ctx->pc = 0x12eb20u;
    { int32_t divisor = GPR_S32(ctx, 22);    int32_t dividend = GPR_S32(ctx, 20);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
label_12eb24:
    // 0x12eb24: 0x8fa5000c  lw          $a1, 0xC($sp)
    ctx->pc = 0x12eb24u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x12eb28: 0x2251021  addu        $v0, $s1, $a1
    ctx->pc = 0x12eb28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 5)));
    // 0x12eb2c: 0xa4440000  sh          $a0, 0x0($v0)
    ctx->pc = 0x12eb2cu;
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 4));
    // 0x12eb30: 0x52c00001  beql        $s6, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x12EB30u;
    {
        const bool branch_taken_0x12eb30 = (GPR_U64(ctx, 22) == GPR_U64(ctx, 0));
        if (branch_taken_0x12eb30) {
            ctx->pc = 0x12EB34u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12EB30u;
            // 0x12eb34: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x12EB38u;
            goto label_12eb38;
        }
    }
    ctx->pc = 0x12EB38u;
label_12eb38:
    // 0x12eb38: 0x1810  mfhi        $v1
    ctx->pc = 0x12eb38u;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x12eb3c: 0x14600008  bnez        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x12EB3Cu;
    {
        const bool branch_taken_0x12eb3c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x12EB40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12EB3Cu;
            // 0x12eb40: 0x8fa30010  lw          $v1, 0x10($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12eb3c) {
            ctx->pc = 0x12EB60u;
            goto label_12eb60;
        }
    }
    ctx->pc = 0x12EB44u;
    // 0x12eb44: 0x8fa20010  lw          $v0, 0x10($sp)
    ctx->pc = 0x12eb44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12eb48: 0x27de0001  addiu       $fp, $fp, 0x1
    ctx->pc = 0x12eb48u;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 30), 1));
    // 0x12eb4c: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x12eb4cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12eb50: 0x5e3821  addu        $a3, $v0, $fp
    ctx->pc = 0x12eb50u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 30)));
    // 0x12eb54: 0xafa60000  sw          $a2, 0x0($sp)
    ctx->pc = 0x12eb54u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 6));
    // 0x12eb58: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x12EB58u;
    {
        const bool branch_taken_0x12eb58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12EB5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12EB58u;
            // 0x12eb5c: 0xa0e00000  sb          $zero, 0x0($a3) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 7), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12eb58) {
            ctx->pc = 0x12EB64u;
            goto label_12eb64;
        }
    }
    ctx->pc = 0x12EB60u;
label_12eb60:
    // 0x12eb60: 0x7e3821  addu        $a3, $v1, $fp
    ctx->pc = 0x12eb60u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 30)));
label_12eb64:
    // 0x12eb64: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x12eb64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12eb68: 0x24030008  addiu       $v1, $zero, 0x8
    ctx->pc = 0x12eb68u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x12eb6c: 0x8fa60014  lw          $a2, 0x14($sp)
    ctx->pc = 0x12eb6cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x12eb70: 0x26940001  addiu       $s4, $s4, 0x1
    ctx->pc = 0x12eb70u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
    // 0x12eb74: 0x8e650054  lw          $a1, 0x54($s3)
    ctx->pc = 0x12eb74u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 84)));
    // 0x12eb78: 0xc22023  subu        $a0, $a2, $v0
    ctx->pc = 0x12eb78u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x12eb7c: 0x90e60000  lbu         $a2, 0x0($a3)
    ctx->pc = 0x12eb7cu;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x12eb80: 0x651823  subu        $v1, $v1, $a1
    ctx->pc = 0x12eb80u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x12eb84: 0x852018  mult        $a0, $a0, $a1
    ctx->pc = 0x12eb84u;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 5); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x12eb88: 0x701004  sllv        $v0, $s0, $v1
    ctx->pc = 0x12eb88u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 3) & 0x1F));
    // 0x12eb8c: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x12eb8cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12eb90: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x12eb90u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x12eb94: 0x628007  srav        $s0, $v0, $v1
    ctx->pc = 0x12eb94u;
    SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 2), GPR_U32(ctx, 3) & 0x1F));
    // 0x12eb98: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x12eb98u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x12eb9c: 0x902004  sllv        $a0, $s0, $a0
    ctx->pc = 0x12eb9cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 16), GPR_U32(ctx, 4) & 0x1F));
    // 0x12eba0: 0xafa50000  sw          $a1, 0x0($sp)
    ctx->pc = 0x12eba0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 5));
    // 0x12eba4: 0xc43025  or          $a2, $a2, $a0
    ctx->pc = 0x12eba4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 4));
    // 0x12eba8: 0xa0e60000  sb          $a2, 0x0($a3)
    ctx->pc = 0x12eba8u;
    WRITE8(ADD32(GPR_U32(ctx, 7), 0), (uint8_t)GPR_U32(ctx, 6));
    // 0x12ebac: 0x8e620044  lw          $v0, 0x44($s3)
    ctx->pc = 0x12ebacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 68)));
    // 0x12ebb0: 0x282102a  slt         $v0, $s4, $v0
    ctx->pc = 0x12ebb0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 20) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x12ebb4: 0x1440ff96  bnez        $v0, . + 4 + (-0x6A << 2)
    ctx->pc = 0x12EBB4u;
    {
        const bool branch_taken_0x12ebb4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12EBB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12EBB4u;
            // 0x12ebb8: 0x280282d  daddu       $a1, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ebb4) {
            ctx->pc = 0x12EA10u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12ea10;
        }
    }
    ctx->pc = 0x12EBBCu;
label_12ebbc:
    // 0x12ebbc: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x12ebbcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12ebc0: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x12ebc0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x12ebc4: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x12ebc4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12ebc8: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x12ebc8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x12ebcc: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x12ebccu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x12ebd0: 0xdfb50048  ld          $s5, 0x48($sp)
    ctx->pc = 0x12ebd0u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x12ebd4: 0xdfb60050  ld          $s6, 0x50($sp)
    ctx->pc = 0x12ebd4u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x12ebd8: 0xdfb70058  ld          $s7, 0x58($sp)
    ctx->pc = 0x12ebd8u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x12ebdc: 0xdfbe0060  ld          $fp, 0x60($sp)
    ctx->pc = 0x12ebdcu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x12ebe0: 0xdfbf0068  ld          $ra, 0x68($sp)
    ctx->pc = 0x12ebe0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x12ebe4: 0x3e00008  jr          $ra
    ctx->pc = 0x12EBE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12EBE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12EBE4u;
            // 0x12ebe8: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12E9DCu: goto label_12e9dc;
            case 0x12EA10u: goto label_12ea10;
            case 0x12EA18u: goto label_12ea18;
            case 0x12EA34u: goto label_12ea34;
            case 0x12EA44u: goto label_12ea44;
            case 0x12EA4Cu: goto label_12ea4c;
            case 0x12EA78u: goto label_12ea78;
            case 0x12EA7Cu: goto label_12ea7c;
            case 0x12EA98u: goto label_12ea98;
            case 0x12EA9Cu: goto label_12ea9c;
            case 0x12EAA4u: goto label_12eaa4;
            case 0x12EAD8u: goto label_12ead8;
            case 0x12EADCu: goto label_12eadc;
            case 0x12EAE4u: goto label_12eae4;
            case 0x12EAF0u: goto label_12eaf0;
            case 0x12EAF8u: goto label_12eaf8;
            case 0x12EB20u: goto label_12eb20;
            case 0x12EB24u: goto label_12eb24;
            case 0x12EB38u: goto label_12eb38;
            case 0x12EB60u: goto label_12eb60;
            case 0x12EB64u: goto label_12eb64;
            case 0x12EBBCu: goto label_12ebbc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12EBECu;
    // 0x12ebec: 0x0  nop
    ctx->pc = 0x12ebecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
