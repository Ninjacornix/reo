#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015B910
// Address: 0x15b910 - 0x15ba80
void sub_0015B910_0x15b910(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015B910_0x15b910");
#endif

    switch (ctx->pc) {
        case 0x15b938u: goto label_15b938;
        case 0x15b944u: goto label_15b944;
        case 0x15b958u: goto label_15b958;
        case 0x15b968u: goto label_15b968;
        default: break;
    }

    ctx->pc = 0x15b910u;

    // 0x15b910: 0x27bdff50  addiu       $sp, $sp, -0xB0
    ctx->pc = 0x15b910u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x15b914: 0xffb00080  sd          $s0, 0x80($sp)
    ctx->pc = 0x15b914u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 16));
    // 0x15b918: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x15b918u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15b91c: 0xffb10088  sd          $s1, 0x88($sp)
    ctx->pc = 0x15b91cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 136), GPR_U64(ctx, 17));
    // 0x15b920: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x15b920u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15b924: 0xffb20090  sd          $s2, 0x90($sp)
    ctx->pc = 0x15b924u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 18));
    // 0x15b928: 0xffb30098  sd          $s3, 0x98($sp)
    ctx->pc = 0x15b928u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 19));
    // 0x15b92c: 0xffbf00a0  sd          $ra, 0xA0($sp)
    ctx->pc = 0x15b92cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 31));
    // 0x15b930: 0xc05412a  jal         func_1504A8
    ctx->pc = 0x15B930u;
    SET_GPR_U32(ctx, 31, 0x15B938u);
    ctx->pc = 0x15B934u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15B930u;
            // 0x15b934: 0x8e040380  lw          $a0, 0x380($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 896)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1504A8u;
    if (runtime->hasFunction(0x1504A8u)) {
        auto targetFn = runtime->lookupFunction(0x1504A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B938u; }
        if (ctx->pc != 0x15B938u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001504A8_0x1504a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B938u; }
        if (ctx->pc != 0x15B938u) { return; }
    }
    ctx->pc = 0x15B938u;
label_15b938:
    // 0x15b938: 0x8e040380  lw          $a0, 0x380($s0)
    ctx->pc = 0x15b938u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 896)));
    // 0x15b93c: 0xc054134  jal         func_1504D0
    ctx->pc = 0x15B93Cu;
    SET_GPR_U32(ctx, 31, 0x15B944u);
    ctx->pc = 0x15B940u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15B93Cu;
            // 0x15b940: 0x27a50060  addiu       $a1, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1504D0u;
    if (runtime->hasFunction(0x1504D0u)) {
        auto targetFn = runtime->lookupFunction(0x1504D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B944u; }
        if (ctx->pc != 0x15B944u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001504D0_0x1504d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B944u; }
        if (ctx->pc != 0x15B944u) { return; }
    }
    ctx->pc = 0x15B944u;
label_15b944:
    // 0x15b944: 0x8e040380  lw          $a0, 0x380($s0)
    ctx->pc = 0x15b944u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 896)));
    // 0x15b948: 0x27a50064  addiu       $a1, $sp, 0x64
    ctx->pc = 0x15b948u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 100));
    // 0x15b94c: 0x27a60068  addiu       $a2, $sp, 0x68
    ctx->pc = 0x15b94cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 104));
    // 0x15b950: 0xc05413e  jal         func_1504F8
    ctx->pc = 0x15B950u;
    SET_GPR_U32(ctx, 31, 0x15B958u);
    ctx->pc = 0x15B954u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15B950u;
            // 0x15b954: 0x27a7006c  addiu       $a3, $sp, 0x6C (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 108));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1504F8u;
    if (runtime->hasFunction(0x1504F8u)) {
        auto targetFn = runtime->lookupFunction(0x1504F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B958u; }
        if (ctx->pc != 0x15B958u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001504F8_0x1504f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B958u; }
        if (ctx->pc != 0x15B958u) { return; }
    }
    ctx->pc = 0x15B958u;
label_15b958:
    // 0x15b958: 0x8e040380  lw          $a0, 0x380($s0)
    ctx->pc = 0x15b958u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 896)));
    // 0x15b95c: 0x27a50070  addiu       $a1, $sp, 0x70
    ctx->pc = 0x15b95cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
    // 0x15b960: 0xc054148  jal         func_150520
    ctx->pc = 0x15B960u;
    SET_GPR_U32(ctx, 31, 0x15B968u);
    ctx->pc = 0x15B964u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15B960u;
            // 0x15b964: 0x27a60074  addiu       $a2, $sp, 0x74 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 116));
        ctx->in_delay_slot = false;
    ctx->pc = 0x150520u;
    if (runtime->hasFunction(0x150520u)) {
        auto targetFn = runtime->lookupFunction(0x150520u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B968u; }
        if (ctx->pc != 0x15B968u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00150520_0x150520(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15B968u; }
        if (ctx->pc != 0x15B968u) { return; }
    }
    ctx->pc = 0x15B968u;
label_15b968:
    // 0x15b968: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x15b968u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15b96c: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x15b96cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x15b970: 0x8fa40008  lw          $a0, 0x8($sp)
    ctx->pc = 0x15b970u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15b974: 0x8fa5000c  lw          $a1, 0xC($sp)
    ctx->pc = 0x15b974u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x15b978: 0x8fa70014  lw          $a3, 0x14($sp)
    ctx->pc = 0x15b978u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x15b97c: 0x8fa9001c  lw          $t1, 0x1C($sp)
    ctx->pc = 0x15b97cu;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x15b980: 0x8faa0020  lw          $t2, 0x20($sp)
    ctx->pc = 0x15b980u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x15b984: 0x8fb30040  lw          $s3, 0x40($sp)
    ctx->pc = 0x15b984u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x15b988: 0x8fab0024  lw          $t3, 0x24($sp)
    ctx->pc = 0x15b988u;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x15b98c: 0x8fac0028  lw          $t4, 0x28($sp)
    ctx->pc = 0x15b98cu;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x15b990: 0x8fad002c  lw          $t5, 0x2C($sp)
    ctx->pc = 0x15b990u;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x15b994: 0x8fae0030  lw          $t6, 0x30($sp)
    ctx->pc = 0x15b994u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x15b998: 0x8faf0034  lw          $t7, 0x34($sp)
    ctx->pc = 0x15b998u;
    SET_GPR_S32(ctx, 15, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
    // 0x15b99c: 0x8fa60010  lw          $a2, 0x10($sp)
    ctx->pc = 0x15b99cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15b9a0: 0x8fa80018  lw          $t0, 0x18($sp)
    ctx->pc = 0x15b9a0u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15b9a4: 0x8fb10038  lw          $s1, 0x38($sp)
    ctx->pc = 0x15b9a4u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x15b9a8: 0x8fb2003c  lw          $s2, 0x3C($sp)
    ctx->pc = 0x15b9a8u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x15b9ac: 0xae0201d0  sw          $v0, 0x1D0($s0)
    ctx->pc = 0x15b9acu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 464), GPR_U32(ctx, 2));
    // 0x15b9b0: 0xae0301d4  sw          $v1, 0x1D4($s0)
    ctx->pc = 0x15b9b0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 468), GPR_U32(ctx, 3));
    // 0x15b9b4: 0xae0401d8  sw          $a0, 0x1D8($s0)
    ctx->pc = 0x15b9b4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 472), GPR_U32(ctx, 4));
    // 0x15b9b8: 0xae0501dc  sw          $a1, 0x1DC($s0)
    ctx->pc = 0x15b9b8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 476), GPR_U32(ctx, 5));
    // 0x15b9bc: 0xae0601e0  sw          $a2, 0x1E0($s0)
    ctx->pc = 0x15b9bcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 480), GPR_U32(ctx, 6));
    // 0x15b9c0: 0xae0701e4  sw          $a3, 0x1E4($s0)
    ctx->pc = 0x15b9c0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 484), GPR_U32(ctx, 7));
    // 0x15b9c4: 0xae0801e8  sw          $t0, 0x1E8($s0)
    ctx->pc = 0x15b9c4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 488), GPR_U32(ctx, 8));
    // 0x15b9c8: 0xae0901ec  sw          $t1, 0x1EC($s0)
    ctx->pc = 0x15b9c8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 492), GPR_U32(ctx, 9));
    // 0x15b9cc: 0xae0a01f0  sw          $t2, 0x1F0($s0)
    ctx->pc = 0x15b9ccu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 496), GPR_U32(ctx, 10));
    // 0x15b9d0: 0xae0b01f4  sw          $t3, 0x1F4($s0)
    ctx->pc = 0x15b9d0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 500), GPR_U32(ctx, 11));
    // 0x15b9d4: 0xae0c01f8  sw          $t4, 0x1F8($s0)
    ctx->pc = 0x15b9d4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 504), GPR_U32(ctx, 12));
    // 0x15b9d8: 0xae0d01fc  sw          $t5, 0x1FC($s0)
    ctx->pc = 0x15b9d8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 508), GPR_U32(ctx, 13));
    // 0x15b9dc: 0xae0e0200  sw          $t6, 0x200($s0)
    ctx->pc = 0x15b9dcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 512), GPR_U32(ctx, 14));
    // 0x15b9e0: 0xae0f0204  sw          $t7, 0x204($s0)
    ctx->pc = 0x15b9e0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 516), GPR_U32(ctx, 15));
    // 0x15b9e4: 0xae110208  sw          $s1, 0x208($s0)
    ctx->pc = 0x15b9e4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 520), GPR_U32(ctx, 17));
    // 0x15b9e8: 0xae12020c  sw          $s2, 0x20C($s0)
    ctx->pc = 0x15b9e8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 524), GPR_U32(ctx, 18));
    // 0x15b9ec: 0xae130210  sw          $s3, 0x210($s0)
    ctx->pc = 0x15b9ecu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 528), GPR_U32(ctx, 19));
    // 0x15b9f0: 0x8fa30064  lw          $v1, 0x64($sp)
    ctx->pc = 0x15b9f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 100)));
    // 0x15b9f4: 0x8fa50060  lw          $a1, 0x60($sp)
    ctx->pc = 0x15b9f4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x15b9f8: 0x246407ff  addiu       $a0, $v1, 0x7FF
    ctx->pc = 0x15b9f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 2047));
    // 0x15b9fc: 0x28620000  slti        $v0, $v1, 0x0
    ctx->pc = 0x15b9fcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x15ba00: 0x8fa80068  lw          $t0, 0x68($sp)
    ctx->pc = 0x15ba00u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x15ba04: 0x82180b  movn        $v1, $a0, $v0
    ctx->pc = 0x15ba04u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 4));
    // 0x15ba08: 0x8fa90070  lw          $t1, 0x70($sp)
    ctx->pc = 0x15ba08u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x15ba0c: 0x31ac3  sra         $v1, $v1, 11
    ctx->pc = 0x15ba0cu;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 11));
    // 0x15ba10: 0x8fa20074  lw          $v0, 0x74($sp)
    ctx->pc = 0x15ba10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 116)));
    // 0x15ba14: 0x8faa0044  lw          $t2, 0x44($sp)
    ctx->pc = 0x15ba14u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 68)));
    // 0x15ba18: 0x8fa60048  lw          $a2, 0x48($sp)
    ctx->pc = 0x15ba18u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x15ba1c: 0x8fa7004c  lw          $a3, 0x4C($sp)
    ctx->pc = 0x15ba1cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
    // 0x15ba20: 0x8fa40050  lw          $a0, 0x50($sp)
    ctx->pc = 0x15ba20u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x15ba24: 0xae0a0214  sw          $t2, 0x214($s0)
    ctx->pc = 0x15ba24u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 532), GPR_U32(ctx, 10));
    // 0x15ba28: 0xae02028c  sw          $v0, 0x28C($s0)
    ctx->pc = 0x15ba28u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 652), GPR_U32(ctx, 2));
    // 0x15ba2c: 0xae060218  sw          $a2, 0x218($s0)
    ctx->pc = 0x15ba2cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 536), GPR_U32(ctx, 6));
    // 0x15ba30: 0xae07021c  sw          $a3, 0x21C($s0)
    ctx->pc = 0x15ba30u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 540), GPR_U32(ctx, 7));
    // 0x15ba34: 0xae040220  sw          $a0, 0x220($s0)
    ctx->pc = 0x15ba34u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 544), GPR_U32(ctx, 4));
    // 0x15ba38: 0xae05027c  sw          $a1, 0x27C($s0)
    ctx->pc = 0x15ba38u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 636), GPR_U32(ctx, 5));
    // 0x15ba3c: 0xae030280  sw          $v1, 0x280($s0)
    ctx->pc = 0x15ba3cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 640), GPR_U32(ctx, 3));
    // 0x15ba40: 0xae080290  sw          $t0, 0x290($s0)
    ctx->pc = 0x15ba40u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 656), GPR_U32(ctx, 8));
    // 0x15ba44: 0xae090288  sw          $t1, 0x288($s0)
    ctx->pc = 0x15ba44u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 648), GPR_U32(ctx, 9));
    // 0x15ba48: 0xdfb10088  ld          $s1, 0x88($sp)
    ctx->pc = 0x15ba48u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 136)));
    // 0x15ba4c: 0xdfb00080  ld          $s0, 0x80($sp)
    ctx->pc = 0x15ba4cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x15ba50: 0xdfb20090  ld          $s2, 0x90($sp)
    ctx->pc = 0x15ba50u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x15ba54: 0xdfb30098  ld          $s3, 0x98($sp)
    ctx->pc = 0x15ba54u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 152)));
    // 0x15ba58: 0xdfbf00a0  ld          $ra, 0xA0($sp)
    ctx->pc = 0x15ba58u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x15ba5c: 0x3e00008  jr          $ra
    ctx->pc = 0x15BA5Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15BA60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15BA5Cu;
            // 0x15ba60: 0x27bd00b0  addiu       $sp, $sp, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15B938u: goto label_15b938;
            case 0x15B944u: goto label_15b944;
            case 0x15B958u: goto label_15b958;
            case 0x15B968u: goto label_15b968;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15BA64u;
    // 0x15ba64: 0x0  nop
    ctx->pc = 0x15ba64u;
    // NOP
    // 0x15ba68: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15ba68u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15ba6c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15ba6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15ba70: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15ba70u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15ba74: 0x8056ea0  j           func_15BA80
    ctx->pc = 0x15BA74u;
    ctx->pc = 0x15BA78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15BA74u;
            // 0x15ba78: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15BA80u;
    if (runtime->hasFunction(0x15BA80u)) {
        auto targetFn = runtime->lookupFunction(0x15BA80u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0015BA80_0x15ba80(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15BA7Cu;
    // 0x15ba7c: 0x0  nop
    ctx->pc = 0x15ba7cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
