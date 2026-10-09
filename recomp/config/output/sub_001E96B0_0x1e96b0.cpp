#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E96B0
// Address: 0x1e96b0 - 0x1e986c
void sub_001E96B0_0x1e96b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E96B0_0x1e96b0");
#endif

    switch (ctx->pc) {
        case 0x1e96e0u: goto label_1e96e0;
        case 0x1e96f0u: goto label_1e96f0;
        case 0x1e9708u: goto label_1e9708;
        case 0x1e973cu: goto label_1e973c;
        case 0x1e9770u: goto label_1e9770;
        case 0x1e97a4u: goto label_1e97a4;
        case 0x1e97d8u: goto label_1e97d8;
        case 0x1e9804u: goto label_1e9804;
        case 0x1e9814u: goto label_1e9814;
        case 0x1e9824u: goto label_1e9824;
        case 0x1e9840u: goto label_1e9840;
        case 0x1e9850u: goto label_1e9850;
        default: break;
    }

    ctx->pc = 0x1e96b0u;

    // 0x1e96b0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1e96b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1e96b4: 0xffbe0040  sd          $fp, 0x40($sp)
    ctx->pc = 0x1e96b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 30));
    // 0x1e96b8: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x1e96b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x1e96bc: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e96bcu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e96c0: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e96c0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e96c4: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e96c4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e96c8: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e96c8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e96cc: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1e96ccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1e96d0: 0xafc80010  sw          $t0, 0x10($fp)
    ctx->pc = 0x1e96d0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 8));
    // 0x1e96d4: 0xafc90014  sw          $t1, 0x14($fp)
    ctx->pc = 0x1e96d4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 9));
    // 0x1e96d8: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E96D8u;
    SET_GPR_U32(ctx, 31, 0x1E96E0u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E96E0u; }
        if (ctx->pc != 0x1E96E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E96E0u; }
        if (ctx->pc != 0x1E96E0u) { return; }
    }
    ctx->pc = 0x1E96E0u;
label_1e96e0:
    // 0x1e96e0: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x1e96e0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x1e96e4: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e96e4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e96e8: 0xc07a216  jal         func_1E8858
    ctx->pc = 0x1E96E8u;
    SET_GPR_U32(ctx, 31, 0x1E96F0u);
    ctx->pc = 0x1E8858u;
    if (runtime->hasFunction(0x1E8858u)) {
        auto targetFn = runtime->lookupFunction(0x1E8858u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E96F0u; }
        if (ctx->pc != 0x1E96F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8858_0x1e8858(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E96F0u; }
        if (ctx->pc != 0x1E96F0u) { return; }
    }
    ctx->pc = 0x1E96F0u;
label_1e96f0:
    // 0x1e96f0: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1e96f0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1e96f4: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1e96f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e96f8: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E96F8u;
    {
        const bool branch_taken_0x1e96f8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e96f8) {
            ctx->pc = 0x1E9720u;
            goto label_1e9720;
        }
    }
    ctx->pc = 0x1E9700u;
    // 0x1e9700: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E9700u;
    SET_GPR_U32(ctx, 31, 0x1E9708u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9708u; }
        if (ctx->pc != 0x1E9708u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9708u; }
        if (ctx->pc != 0x1E9708u) { return; }
    }
    ctx->pc = 0x1E9708u;
label_1e9708:
    // 0x1e9708: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e9708u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e970c: 0x2402006c  addiu       $v0, $zero, 0x6C
    ctx->pc = 0x1e970cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 108));
    // 0x1e9710: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e9710u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e9714: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e9714u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e9718: 0x1000004e  b           . + 4 + (0x4E << 2)
    ctx->pc = 0x1E9718u;
    {
        const bool branch_taken_0x1e9718 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e9718) {
            ctx->pc = 0x1E9854u;
            goto label_1e9854;
        }
    }
    ctx->pc = 0x1E9720u;
label_1e9720:
    // 0x1e9720: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1e9720u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e9724: 0x94430004  lhu         $v1, 0x4($v0)
    ctx->pc = 0x1e9724u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e9728: 0x3402ffff  ori         $v0, $zero, 0xFFFF
    ctx->pc = 0x1e9728u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1e972c: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E972Cu;
    {
        const bool branch_taken_0x1e972c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e972c) {
            ctx->pc = 0x1E9754u;
            goto label_1e9754;
        }
    }
    ctx->pc = 0x1E9734u;
    // 0x1e9734: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E9734u;
    SET_GPR_U32(ctx, 31, 0x1E973Cu);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E973Cu; }
        if (ctx->pc != 0x1E973Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E973Cu; }
        if (ctx->pc != 0x1E973Cu) { return; }
    }
    ctx->pc = 0x1E973Cu;
label_1e973c:
    // 0x1e973c: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e973cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9740: 0x2402000e  addiu       $v0, $zero, 0xE
    ctx->pc = 0x1e9740u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1e9744: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e9744u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e9748: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e9748u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e974c: 0x10000041  b           . + 4 + (0x41 << 2)
    ctx->pc = 0x1E974Cu;
    {
        const bool branch_taken_0x1e974c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e974c) {
            ctx->pc = 0x1E9854u;
            goto label_1e9854;
        }
    }
    ctx->pc = 0x1E9754u;
label_1e9754:
    // 0x1e9754: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1e9754u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e9758: 0x94430002  lhu         $v1, 0x2($v0)
    ctx->pc = 0x1e9758u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x1e975c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1e975cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1e9760: 0x10620009  beq         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E9760u;
    {
        const bool branch_taken_0x1e9760 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e9760) {
            ctx->pc = 0x1E9788u;
            goto label_1e9788;
        }
    }
    ctx->pc = 0x1E9768u;
    // 0x1e9768: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E9768u;
    SET_GPR_U32(ctx, 31, 0x1E9770u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9770u; }
        if (ctx->pc != 0x1E9770u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9770u; }
        if (ctx->pc != 0x1E9770u) { return; }
    }
    ctx->pc = 0x1E9770u;
label_1e9770:
    // 0x1e9770: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e9770u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9774: 0x2402006b  addiu       $v0, $zero, 0x6B
    ctx->pc = 0x1e9774u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 107));
    // 0x1e9778: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e9778u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e977c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e977cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e9780: 0x10000034  b           . + 4 + (0x34 << 2)
    ctx->pc = 0x1E9780u;
    {
        const bool branch_taken_0x1e9780 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e9780) {
            ctx->pc = 0x1E9854u;
            goto label_1e9854;
        }
    }
    ctx->pc = 0x1E9788u;
label_1e9788:
    // 0x1e9788: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1e9788u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e978c: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1e978cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1e9790: 0x27c30038  addiu       $v1, $fp, 0x38
    ctx->pc = 0x1e9790u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 56));
    // 0x1e9794: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e9794u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9798: 0x60282d  daddu       $a1, $v1, $zero
    ctx->pc = 0x1e9798u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e979c: 0xc07c499  jal         func_1F1264
    ctx->pc = 0x1E979Cu;
    SET_GPR_U32(ctx, 31, 0x1E97A4u);
    ctx->pc = 0x1F1264u;
    if (runtime->hasFunction(0x1F1264u)) {
        auto targetFn = runtime->lookupFunction(0x1F1264u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E97A4u; }
        if (ctx->pc != 0x1E97A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1264_0x1f1264(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E97A4u; }
        if (ctx->pc != 0x1E97A4u) { return; }
    }
    ctx->pc = 0x1E97A4u;
label_1e97a4:
    // 0x1e97a4: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1e97a4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
    // 0x1e97a8: 0x8fc30034  lw          $v1, 0x34($fp)
    ctx->pc = 0x1e97a8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1e97ac: 0x2402e4aa  addiu       $v0, $zero, -0x1B56
    ctx->pc = 0x1e97acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294960298));
    // 0x1e97b0: 0x14620004  bne         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1E97B0u;
    {
        const bool branch_taken_0x1e97b0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e97b0) {
            ctx->pc = 0x1E97C4u;
            goto label_1e97c4;
        }
    }
    ctx->pc = 0x1E97B8u;
    // 0x1e97b8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e97b8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e97bc: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x1E97BCu;
    {
        const bool branch_taken_0x1e97bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e97bc) {
            ctx->pc = 0x1E9854u;
            goto label_1e9854;
        }
    }
    ctx->pc = 0x1E97C4u;
label_1e97c4:
    // 0x1e97c4: 0x8fc20034  lw          $v0, 0x34($fp)
    ctx->pc = 0x1e97c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1e97c8: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E97C8u;
    {
        const bool branch_taken_0x1e97c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e97c8) {
            ctx->pc = 0x1E97F0u;
            goto label_1e97f0;
        }
    }
    ctx->pc = 0x1E97D0u;
    // 0x1e97d0: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E97D0u;
    SET_GPR_U32(ctx, 31, 0x1E97D8u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E97D8u; }
        if (ctx->pc != 0x1E97D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E97D8u; }
        if (ctx->pc != 0x1E97D8u) { return; }
    }
    ctx->pc = 0x1E97D8u;
label_1e97d8:
    // 0x1e97d8: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e97d8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e97dc: 0x8fc20034  lw          $v0, 0x34($fp)
    ctx->pc = 0x1e97dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
    // 0x1e97e0: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e97e0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e97e4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e97e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e97e8: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x1E97E8u;
    {
        const bool branch_taken_0x1e97e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e97e8) {
            ctx->pc = 0x1E9854u;
            goto label_1e9854;
        }
    }
    ctx->pc = 0x1E97F0u;
label_1e97f0:
    // 0x1e97f0: 0x8fc40038  lw          $a0, 0x38($fp)
    ctx->pc = 0x1e97f0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1e97f4: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1e97f4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e97f8: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1e97f8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e97fc: 0xc07cd84  jal         func_1F3610
    ctx->pc = 0x1E97FCu;
    SET_GPR_U32(ctx, 31, 0x1E9804u);
    ctx->pc = 0x1F3610u;
    if (runtime->hasFunction(0x1F3610u)) {
        auto targetFn = runtime->lookupFunction(0x1F3610u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9804u; }
        if (ctx->pc != 0x1E9804u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F3610_0x1f3610(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9804u; }
        if (ctx->pc != 0x1E9804u) { return; }
    }
    ctx->pc = 0x1E9804u;
label_1e9804:
    // 0x1e9804: 0xafc20034  sw          $v0, 0x34($fp)
    ctx->pc = 0x1e9804u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 52), GPR_U32(ctx, 2));
    // 0x1e9808: 0x8fc40038  lw          $a0, 0x38($fp)
    ctx->pc = 0x1e9808u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1e980c: 0xc07cc89  jal         func_1F3224
    ctx->pc = 0x1E980Cu;
    SET_GPR_U32(ctx, 31, 0x1E9814u);
    ctx->pc = 0x1F3224u;
    if (runtime->hasFunction(0x1F3224u)) {
        auto targetFn = runtime->lookupFunction(0x1F3224u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9814u; }
        if (ctx->pc != 0x1E9814u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F3224_0x1f3224(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9814u; }
        if (ctx->pc != 0x1E9814u) { return; }
    }
    ctx->pc = 0x1E9814u;
label_1e9814:
    // 0x1e9814: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1e9814u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1e9818: 0x8fc40038  lw          $a0, 0x38($fp)
    ctx->pc = 0x1e9818u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1e981c: 0xc07cccb  jal         func_1F332C
    ctx->pc = 0x1E981Cu;
    SET_GPR_U32(ctx, 31, 0x1E9824u);
    ctx->pc = 0x1F332Cu;
    if (runtime->hasFunction(0x1F332Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F332Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9824u; }
        if (ctx->pc != 0x1E9824u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F332C_0x1f332c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9824u; }
        if (ctx->pc != 0x1E9824u) { return; }
    }
    ctx->pc = 0x1E9824u;
label_1e9824:
    // 0x1e9824: 0xa7c20022  sh          $v0, 0x22($fp)
    ctx->pc = 0x1e9824u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 34), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e9828: 0x27c20020  addiu       $v0, $fp, 0x20
    ctx->pc = 0x1e9828u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 32));
    // 0x1e982c: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e982cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e9830: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e9830u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9834: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x1e9834u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1e9838: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1E9838u;
    SET_GPR_U32(ctx, 31, 0x1E9840u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9840u; }
        if (ctx->pc != 0x1E9840u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9840u; }
        if (ctx->pc != 0x1E9840u) { return; }
    }
    ctx->pc = 0x1E9840u;
label_1e9840:
    // 0x1e9840: 0x8f84802c  lw          $a0, -0x7FD4($gp)
    ctx->pc = 0x1e9840u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 28), 4294934572)));
    // 0x1e9844: 0x8fc50038  lw          $a1, 0x38($fp)
    ctx->pc = 0x1e9844u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 56)));
    // 0x1e9848: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E9848u;
    SET_GPR_U32(ctx, 31, 0x1E9850u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9850u; }
        if (ctx->pc != 0x1E9850u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9850u; }
        if (ctx->pc != 0x1E9850u) { return; }
    }
    ctx->pc = 0x1E9850u;
label_1e9850:
    // 0x1e9850: 0x8fc20034  lw          $v0, 0x34($fp)
    ctx->pc = 0x1e9850u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 52)));
label_1e9854:
    // 0x1e9854: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e9854u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9858: 0xdfbe0040  ld          $fp, 0x40($sp)
    ctx->pc = 0x1e9858u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1e985c: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x1e985cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1e9860: 0x27bd0050  addiu       $sp, $sp, 0x50
    ctx->pc = 0x1e9860u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1e9864: 0x3e00008  jr          $ra
    ctx->pc = 0x1E9864u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E96E0u: goto label_1e96e0;
            case 0x1E96F0u: goto label_1e96f0;
            case 0x1E9708u: goto label_1e9708;
            case 0x1E9720u: goto label_1e9720;
            case 0x1E973Cu: goto label_1e973c;
            case 0x1E9754u: goto label_1e9754;
            case 0x1E9770u: goto label_1e9770;
            case 0x1E9788u: goto label_1e9788;
            case 0x1E97A4u: goto label_1e97a4;
            case 0x1E97C4u: goto label_1e97c4;
            case 0x1E97D8u: goto label_1e97d8;
            case 0x1E97F0u: goto label_1e97f0;
            case 0x1E9804u: goto label_1e9804;
            case 0x1E9814u: goto label_1e9814;
            case 0x1E9824u: goto label_1e9824;
            case 0x1E9840u: goto label_1e9840;
            case 0x1E9850u: goto label_1e9850;
            case 0x1E9854u: goto label_1e9854;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E986Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
