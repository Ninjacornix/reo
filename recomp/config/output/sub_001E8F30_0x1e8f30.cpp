#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E8F30
// Address: 0x1e8f30 - 0x1e930c
void sub_001E8F30_0x1e8f30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E8F30_0x1e8f30");
#endif

    switch (ctx->pc) {
        case 0x1e8f54u: goto label_1e8f54;
        case 0x1e8f6cu: goto label_1e8f6c;
        case 0x1e8f84u: goto label_1e8f84;
        case 0x1e8fb8u: goto label_1e8fb8;
        case 0x1e8fe8u: goto label_1e8fe8;
        case 0x1e9034u: goto label_1e9034;
        case 0x1e9068u: goto label_1e9068;
        case 0x1e9084u: goto label_1e9084;
        case 0x1e909cu: goto label_1e909c;
        case 0x1e90ccu: goto label_1e90cc;
        case 0x1e9184u: goto label_1e9184;
        case 0x1e9194u: goto label_1e9194;
        case 0x1e91acu: goto label_1e91ac;
        case 0x1e91e0u: goto label_1e91e0;
        case 0x1e9204u: goto label_1e9204;
        case 0x1e921cu: goto label_1e921c;
        case 0x1e9264u: goto label_1e9264;
        case 0x1e929cu: goto label_1e929c;
        case 0x1e92d8u: goto label_1e92d8;
        default: break;
    }

    ctx->pc = 0x1e8f30u;

    // 0x1e8f30: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e8f30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e8f34: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e8f34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e8f38: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e8f38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e8f3c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e8f3cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8f40: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e8f40u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e8f44: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e8f44u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e8f48: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e8f48u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e8f4c: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E8F4Cu;
    SET_GPR_U32(ctx, 31, 0x1E8F54u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8F54u; }
        if (ctx->pc != 0x1E8F54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8F54u; }
        if (ctx->pc != 0x1E8F54u) { return; }
    }
    ctx->pc = 0x1E8F54u;
label_1e8f54:
    // 0x1e8f54: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x1e8f54u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x1e8f58: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e8f58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e8f5c: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e8f5cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e8f60: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e8f60u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e8f64: 0xc07a216  jal         func_1E8858
    ctx->pc = 0x1E8F64u;
    SET_GPR_U32(ctx, 31, 0x1E8F6Cu);
    ctx->pc = 0x1E8858u;
    if (runtime->hasFunction(0x1E8858u)) {
        auto targetFn = runtime->lookupFunction(0x1E8858u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8F6Cu; }
        if (ctx->pc != 0x1E8F6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8858_0x1e8858(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8F6Cu; }
        if (ctx->pc != 0x1E8F6Cu) { return; }
    }
    ctx->pc = 0x1E8F6Cu;
label_1e8f6c:
    // 0x1e8f6c: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e8f6cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e8f70: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e8f70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e8f74: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E8F74u;
    {
        const bool branch_taken_0x1e8f74 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e8f74) {
            ctx->pc = 0x1E8F9Cu;
            goto label_1e8f9c;
        }
    }
    ctx->pc = 0x1E8F7Cu;
    // 0x1e8f7c: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E8F7Cu;
    SET_GPR_U32(ctx, 31, 0x1E8F84u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8F84u; }
        if (ctx->pc != 0x1E8F84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8F84u; }
        if (ctx->pc != 0x1E8F84u) { return; }
    }
    ctx->pc = 0x1E8F84u;
label_1e8f84:
    // 0x1e8f84: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e8f84u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8f88: 0x2402006c  addiu       $v0, $zero, 0x6C
    ctx->pc = 0x1e8f88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 108));
    // 0x1e8f8c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e8f8cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e8f90: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e8f90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e8f94: 0x1000006b  b           . + 4 + (0x6B << 2)
    ctx->pc = 0x1E8F94u;
    {
        const bool branch_taken_0x1e8f94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e8f94) {
            ctx->pc = 0x1E9144u;
            goto label_1e9144;
        }
    }
    ctx->pc = 0x1E8F9Cu;
label_1e8f9c:
    // 0x1e8f9c: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e8f9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e8fa0: 0x94430004  lhu         $v1, 0x4($v0)
    ctx->pc = 0x1e8fa0u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e8fa4: 0x3402ffff  ori         $v0, $zero, 0xFFFF
    ctx->pc = 0x1e8fa4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1e8fa8: 0x10620009  beq         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E8FA8u;
    {
        const bool branch_taken_0x1e8fa8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e8fa8) {
            ctx->pc = 0x1E8FD0u;
            goto label_1e8fd0;
        }
    }
    ctx->pc = 0x1E8FB0u;
    // 0x1e8fb0: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E8FB0u;
    SET_GPR_U32(ctx, 31, 0x1E8FB8u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8FB8u; }
        if (ctx->pc != 0x1E8FB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8FB8u; }
        if (ctx->pc != 0x1E8FB8u) { return; }
    }
    ctx->pc = 0x1E8FB8u;
label_1e8fb8:
    // 0x1e8fb8: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e8fb8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8fbc: 0x2402006b  addiu       $v0, $zero, 0x6B
    ctx->pc = 0x1e8fbcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 107));
    // 0x1e8fc0: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e8fc0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e8fc4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e8fc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e8fc8: 0x1000005e  b           . + 4 + (0x5E << 2)
    ctx->pc = 0x1E8FC8u;
    {
        const bool branch_taken_0x1e8fc8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e8fc8) {
            ctx->pc = 0x1E9144u;
            goto label_1e9144;
        }
    }
    ctx->pc = 0x1E8FD0u;
label_1e8fd0:
    // 0x1e8fd0: 0x8fc30008  lw          $v1, 0x8($fp)
    ctx->pc = 0x1e8fd0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e8fd4: 0x24020010  addiu       $v0, $zero, 0x10
    ctx->pc = 0x1e8fd4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1e8fd8: 0x10620009  beq         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E8FD8u;
    {
        const bool branch_taken_0x1e8fd8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e8fd8) {
            ctx->pc = 0x1E9000u;
            goto label_1e9000;
        }
    }
    ctx->pc = 0x1E8FE0u;
    // 0x1e8fe0: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E8FE0u;
    SET_GPR_U32(ctx, 31, 0x1E8FE8u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8FE8u; }
        if (ctx->pc != 0x1E8FE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E8FE8u; }
        if (ctx->pc != 0x1E8FE8u) { return; }
    }
    ctx->pc = 0x1E8FE8u;
label_1e8fe8:
    // 0x1e8fe8: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e8fe8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e8fec: 0x2402000e  addiu       $v0, $zero, 0xE
    ctx->pc = 0x1e8fecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1e8ff0: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e8ff0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e8ff4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e8ff4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e8ff8: 0x10000052  b           . + 4 + (0x52 << 2)
    ctx->pc = 0x1E8FF8u;
    {
        const bool branch_taken_0x1e8ff8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e8ff8) {
            ctx->pc = 0x1E9144u;
            goto label_1e9144;
        }
    }
    ctx->pc = 0x1E9000u;
label_1e9000:
    // 0x1e9000: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e9000u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e9004: 0x94420002  lhu         $v0, 0x2($v0)
    ctx->pc = 0x1e9004u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x1e9008: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e9008u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e900c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e900cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e9010: 0x8fc30018  lw          $v1, 0x18($fp)
    ctx->pc = 0x1e9010u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e9014: 0x1062003e  beq         $v1, $v0, . + 4 + (0x3E << 2)
    ctx->pc = 0x1E9014u;
    {
        const bool branch_taken_0x1e9014 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e9014) {
            ctx->pc = 0x1E9110u;
            goto label_1e9110;
        }
    }
    ctx->pc = 0x1E901Cu;
    // 0x1e901c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1e901cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1e9020: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e9020u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e9024: 0x10820009  beq         $a0, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E9024u;
    {
        const bool branch_taken_0x1e9024 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e9024) {
            ctx->pc = 0x1E904Cu;
            goto label_1e904c;
        }
    }
    ctx->pc = 0x1E902Cu;
    // 0x1e902c: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E902Cu;
    SET_GPR_U32(ctx, 31, 0x1E9034u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9034u; }
        if (ctx->pc != 0x1E9034u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9034u; }
        if (ctx->pc != 0x1E9034u) { return; }
    }
    ctx->pc = 0x1E9034u;
label_1e9034:
    // 0x1e9034: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e9034u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9038: 0x2402006c  addiu       $v0, $zero, 0x6C
    ctx->pc = 0x1e9038u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 108));
    // 0x1e903c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e903cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e9040: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e9040u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e9044: 0x1000003f  b           . + 4 + (0x3F << 2)
    ctx->pc = 0x1E9044u;
    {
        const bool branch_taken_0x1e9044 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e9044) {
            ctx->pc = 0x1E9144u;
            goto label_1e9144;
        }
    }
    ctx->pc = 0x1E904Cu;
label_1e904c:
    // 0x1e904c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e904cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e9050: 0x94420002  lhu         $v0, 0x2($v0)
    ctx->pc = 0x1e9050u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x1e9054: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1e9054u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9058: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1e9058u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e905c: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1e905cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9060: 0xc0760f4  jal         func_1D83D0
    ctx->pc = 0x1E9060u;
    SET_GPR_U32(ctx, 31, 0x1E9068u);
    ctx->pc = 0x1D83D0u;
    if (runtime->hasFunction(0x1D83D0u)) {
        auto targetFn = runtime->lookupFunction(0x1D83D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9068u; }
        if (ctx->pc != 0x1E9068u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D83D0_0x1d83d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9068u; }
        if (ctx->pc != 0x1E9068u) { return; }
    }
    ctx->pc = 0x1E9068u;
label_1e9068:
    // 0x1e9068: 0xa7c20014  sh          $v0, 0x14($fp)
    ctx->pc = 0x1e9068u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 20), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e906c: 0x87c20014  lh          $v0, 0x14($fp)
    ctx->pc = 0x1e906cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e9070: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x1e9070u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x1e9074: 0x24848068  addiu       $a0, $a0, -0x7F98
    ctx->pc = 0x1e9074u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294934632));
    // 0x1e9078: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e9078u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e907c: 0xc045a12  jal         func_116848
    ctx->pc = 0x1E907Cu;
    SET_GPR_U32(ctx, 31, 0x1E9084u);
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9084u; }
        if (ctx->pc != 0x1E9084u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9084u; }
        if (ctx->pc != 0x1E9084u) { return; }
    }
    ctx->pc = 0x1E9084u;
label_1e9084:
    // 0x1e9084: 0x87c30014  lh          $v1, 0x14($fp)
    ctx->pc = 0x1e9084u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e9088: 0x2402fffc  addiu       $v0, $zero, -0x4
    ctx->pc = 0x1e9088u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x1e908c: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E908Cu;
    {
        const bool branch_taken_0x1e908c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e908c) {
            ctx->pc = 0x1E90B4u;
            goto label_1e90b4;
        }
    }
    ctx->pc = 0x1E9094u;
    // 0x1e9094: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E9094u;
    SET_GPR_U32(ctx, 31, 0x1E909Cu);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E909Cu; }
        if (ctx->pc != 0x1E909Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E909Cu; }
        if (ctx->pc != 0x1E909Cu) { return; }
    }
    ctx->pc = 0x1E909Cu;
label_1e909c:
    // 0x1e909c: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e909cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e90a0: 0x2402007d  addiu       $v0, $zero, 0x7D
    ctx->pc = 0x1e90a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 125));
    // 0x1e90a4: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e90a4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e90a8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e90a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e90ac: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x1E90ACu;
    {
        const bool branch_taken_0x1e90ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e90ac) {
            ctx->pc = 0x1E9144u;
            goto label_1e9144;
        }
    }
    ctx->pc = 0x1E90B4u;
label_1e90b4:
    // 0x1e90b4: 0x87c30014  lh          $v1, 0x14($fp)
    ctx->pc = 0x1e90b4u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e90b8: 0x2402fffd  addiu       $v0, $zero, -0x3
    ctx->pc = 0x1e90b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
    // 0x1e90bc: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E90BCu;
    {
        const bool branch_taken_0x1e90bc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e90bc) {
            ctx->pc = 0x1E90E4u;
            goto label_1e90e4;
        }
    }
    ctx->pc = 0x1E90C4u;
    // 0x1e90c4: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E90C4u;
    SET_GPR_U32(ctx, 31, 0x1E90CCu);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E90CCu; }
        if (ctx->pc != 0x1E90CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E90CCu; }
        if (ctx->pc != 0x1E90CCu) { return; }
    }
    ctx->pc = 0x1E90CCu;
label_1e90cc:
    // 0x1e90cc: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e90ccu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e90d0: 0x3402ffff  ori         $v0, $zero, 0xFFFF
    ctx->pc = 0x1e90d0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1e90d4: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e90d4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e90d8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e90d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e90dc: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x1E90DCu;
    {
        const bool branch_taken_0x1e90dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e90dc) {
            ctx->pc = 0x1E9144u;
            goto label_1e9144;
        }
    }
    ctx->pc = 0x1E90E4u;
label_1e90e4:
    // 0x1e90e4: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1e90e4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e90e8: 0x97c20014  lhu         $v0, 0x14($fp)
    ctx->pc = 0x1e90e8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e90ec: 0xa4620000  sh          $v0, 0x0($v1)
    ctx->pc = 0x1e90ecu;
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e90f0: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1e90f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e90f4: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1e90f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1e90f8: 0xa4620002  sh          $v0, 0x2($v1)
    ctx->pc = 0x1e90f8u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e90fc: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1e90fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e9100: 0x2402007f  addiu       $v0, $zero, 0x7F
    ctx->pc = 0x1e9100u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x1e9104: 0xa4620004  sh          $v0, 0x4($v1)
    ctx->pc = 0x1e9104u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e9108: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1E9108u;
    {
        const bool branch_taken_0x1e9108 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e9108) {
            ctx->pc = 0x1E9140u;
            goto label_1e9140;
        }
    }
    ctx->pc = 0x1E9110u;
label_1e9110:
    // 0x1e9110: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1e9110u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e9114: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e9114u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e9118: 0x88440007  lwl         $a0, 0x7($v0)
    ctx->pc = 0x1e9118u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 7); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = (3u - offset) << 3; uint32_t keepMask = (shift == 0) ? 0u : ((1u << shift) - 1u); uint32_t merged = (GPR_U32(ctx, 4) & keepMask) | (mem << shift); SET_GPR_S32(ctx, 4, (int32_t)merged); }
    // 0x1e911c: 0x98440004  lwr         $a0, 0x4($v0)
    ctx->pc = 0x1e911cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 2), 4); uint32_t aligned_addr = addr & ~3u; uint32_t offset = addr & 3u; uint32_t mem = READ32(aligned_addr); uint32_t shift = offset << 3; uint32_t keepMask = (offset == 0) ? 0u : (0xFFFFFFFFu << ((4u - offset) << 3)); uint32_t merged32 = (GPR_U32(ctx, 4) & keepMask) | (mem >> shift); uint64_t merged64 = (GPR_U64(ctx, 4) & 0xFFFFFFFF00000000ull) | (uint64_t)merged32; if (offset == 0) merged64 = (uint64_t)(int64_t)(int32_t)merged32; SET_GPR_U64(ctx, 4, merged64); }
    // 0x1e9120: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1e9120u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9124: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1e9124u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1e9128: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x1e9128u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x1e912c: 0xac62001c  sw          $v0, 0x1C($v1)
    ctx->pc = 0x1e912cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 28), GPR_U32(ctx, 2));
    // 0x1e9130: 0x8fc3000c  lw          $v1, 0xC($fp)
    ctx->pc = 0x1e9130u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e9134: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e9134u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e9138: 0x94420002  lhu         $v0, 0x2($v0)
    ctx->pc = 0x1e9138u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x1e913c: 0xac620020  sw          $v0, 0x20($v1)
    ctx->pc = 0x1e913cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 32), GPR_U32(ctx, 2));
label_1e9140:
    // 0x1e9140: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e9140u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e9144:
    // 0x1e9144: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e9144u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9148: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e9148u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e914c: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e914cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e9150: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e9150u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e9154: 0x3e00008  jr          $ra
    ctx->pc = 0x1E9154u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E8F54u: goto label_1e8f54;
            case 0x1E8F6Cu: goto label_1e8f6c;
            case 0x1E8F84u: goto label_1e8f84;
            case 0x1E8F9Cu: goto label_1e8f9c;
            case 0x1E8FB8u: goto label_1e8fb8;
            case 0x1E8FD0u: goto label_1e8fd0;
            case 0x1E8FE8u: goto label_1e8fe8;
            case 0x1E9000u: goto label_1e9000;
            case 0x1E9034u: goto label_1e9034;
            case 0x1E904Cu: goto label_1e904c;
            case 0x1E9068u: goto label_1e9068;
            case 0x1E9084u: goto label_1e9084;
            case 0x1E909Cu: goto label_1e909c;
            case 0x1E90B4u: goto label_1e90b4;
            case 0x1E90CCu: goto label_1e90cc;
            case 0x1E90E4u: goto label_1e90e4;
            case 0x1E9110u: goto label_1e9110;
            case 0x1E9140u: goto label_1e9140;
            case 0x1E9144u: goto label_1e9144;
            case 0x1E9184u: goto label_1e9184;
            case 0x1E9194u: goto label_1e9194;
            case 0x1E91ACu: goto label_1e91ac;
            case 0x1E91C4u: goto label_1e91c4;
            case 0x1E91E0u: goto label_1e91e0;
            case 0x1E91F8u: goto label_1e91f8;
            case 0x1E9204u: goto label_1e9204;
            case 0x1E921Cu: goto label_1e921c;
            case 0x1E9234u: goto label_1e9234;
            case 0x1E9264u: goto label_1e9264;
            case 0x1E927Cu: goto label_1e927c;
            case 0x1E929Cu: goto label_1e929c;
            case 0x1E92C4u: goto label_1e92c4;
            case 0x1E92D8u: goto label_1e92d8;
            case 0x1E92F0u: goto label_1e92f0;
            case 0x1E92F4u: goto label_1e92f4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E915Cu;
    // 0x1e915c: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e915cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e9160: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e9160u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e9164: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e9164u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e9168: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e9168u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e916c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e916cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e9170: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e9170u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e9174: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e9174u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e9178: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1e9178u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1e917c: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E917Cu;
    SET_GPR_U32(ctx, 31, 0x1E9184u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9184u; }
        if (ctx->pc != 0x1E9184u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9184u; }
        if (ctx->pc != 0x1E9184u) { return; }
    }
    ctx->pc = 0x1E9184u;
label_1e9184:
    // 0x1e9184: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x1e9184u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x1e9188: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e9188u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e918c: 0xc07a216  jal         func_1E8858
    ctx->pc = 0x1E918Cu;
    SET_GPR_U32(ctx, 31, 0x1E9194u);
    ctx->pc = 0x1E8858u;
    if (runtime->hasFunction(0x1E8858u)) {
        auto targetFn = runtime->lookupFunction(0x1E8858u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9194u; }
        if (ctx->pc != 0x1E9194u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8858_0x1e8858(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9194u; }
        if (ctx->pc != 0x1E9194u) { return; }
    }
    ctx->pc = 0x1E9194u;
label_1e9194:
    // 0x1e9194: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e9194u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e9198: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e9198u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e919c: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E919Cu;
    {
        const bool branch_taken_0x1e919c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e919c) {
            ctx->pc = 0x1E91C4u;
            goto label_1e91c4;
        }
    }
    ctx->pc = 0x1E91A4u;
    // 0x1e91a4: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E91A4u;
    SET_GPR_U32(ctx, 31, 0x1E91ACu);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E91ACu; }
        if (ctx->pc != 0x1E91ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E91ACu; }
        if (ctx->pc != 0x1E91ACu) { return; }
    }
    ctx->pc = 0x1E91ACu;
label_1e91ac:
    // 0x1e91ac: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e91acu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e91b0: 0x2402000e  addiu       $v0, $zero, 0xE
    ctx->pc = 0x1e91b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1e91b4: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e91b4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e91b8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e91b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e91bc: 0x1000004d  b           . + 4 + (0x4D << 2)
    ctx->pc = 0x1E91BCu;
    {
        const bool branch_taken_0x1e91bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e91bc) {
            ctx->pc = 0x1E92F4u;
            goto label_1e92f4;
        }
    }
    ctx->pc = 0x1E91C4u;
label_1e91c4:
    // 0x1e91c4: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e91c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e91c8: 0x94430002  lhu         $v1, 0x2($v0)
    ctx->pc = 0x1e91c8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x1e91cc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e91ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e91d0: 0x10620009  beq         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E91D0u;
    {
        const bool branch_taken_0x1e91d0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e91d0) {
            ctx->pc = 0x1E91F8u;
            goto label_1e91f8;
        }
    }
    ctx->pc = 0x1E91D8u;
    // 0x1e91d8: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E91D8u;
    SET_GPR_U32(ctx, 31, 0x1E91E0u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E91E0u; }
        if (ctx->pc != 0x1E91E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E91E0u; }
        if (ctx->pc != 0x1E91E0u) { return; }
    }
    ctx->pc = 0x1E91E0u;
label_1e91e0:
    // 0x1e91e0: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e91e0u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e91e4: 0x2402006b  addiu       $v0, $zero, 0x6B
    ctx->pc = 0x1e91e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 107));
    // 0x1e91e8: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e91e8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e91ec: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e91ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e91f0: 0x10000040  b           . + 4 + (0x40 << 2)
    ctx->pc = 0x1E91F0u;
    {
        const bool branch_taken_0x1e91f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e91f0) {
            ctx->pc = 0x1E92F4u;
            goto label_1e92f4;
        }
    }
    ctx->pc = 0x1E91F8u;
label_1e91f8:
    // 0x1e91f8: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e91f8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e91fc: 0xc07aa87  jal         func_1EAA1C
    ctx->pc = 0x1E91FCu;
    SET_GPR_U32(ctx, 31, 0x1E9204u);
    ctx->pc = 0x1EAA1Cu;
    if (runtime->hasFunction(0x1EAA1Cu)) {
        auto targetFn = runtime->lookupFunction(0x1EAA1Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9204u; }
        if (ctx->pc != 0x1E9204u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001EAA1C_0x1eaa1c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9204u; }
        if (ctx->pc != 0x1E9204u) { return; }
    }
    ctx->pc = 0x1E9204u;
label_1e9204:
    // 0x1e9204: 0xa7c20014  sh          $v0, 0x14($fp)
    ctx->pc = 0x1e9204u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 20), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e9208: 0x87c20014  lh          $v0, 0x14($fp)
    ctx->pc = 0x1e9208u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e920c: 0x4410009  bgez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E920Cu;
    {
        const bool branch_taken_0x1e920c = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1e920c) {
            ctx->pc = 0x1E9234u;
            goto label_1e9234;
        }
    }
    ctx->pc = 0x1E9214u;
    // 0x1e9214: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E9214u;
    SET_GPR_U32(ctx, 31, 0x1E921Cu);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E921Cu; }
        if (ctx->pc != 0x1E921Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E921Cu; }
        if (ctx->pc != 0x1E921Cu) { return; }
    }
    ctx->pc = 0x1E921Cu;
label_1e921c:
    // 0x1e921c: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e921cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9220: 0x24020009  addiu       $v0, $zero, 0x9
    ctx->pc = 0x1e9220u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1e9224: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e9224u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e9228: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e9228u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e922c: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x1E922Cu;
    {
        const bool branch_taken_0x1e922c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e922c) {
            ctx->pc = 0x1E92F4u;
            goto label_1e92f4;
        }
    }
    ctx->pc = 0x1E9234u;
label_1e9234:
    // 0x1e9234: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e9234u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e9238: 0x94430004  lhu         $v1, 0x4($v0)
    ctx->pc = 0x1e9238u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e923c: 0x24020ff4  addiu       $v0, $zero, 0xFF4
    ctx->pc = 0x1e923cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4084));
    // 0x1e9240: 0x1062000e  beq         $v1, $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1E9240u;
    {
        const bool branch_taken_0x1e9240 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e9240) {
            ctx->pc = 0x1E927Cu;
            goto label_1e927c;
        }
    }
    ctx->pc = 0x1E9248u;
    // 0x1e9248: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e9248u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e924c: 0x94430004  lhu         $v1, 0x4($v0)
    ctx->pc = 0x1e924cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e9250: 0x2402007f  addiu       $v0, $zero, 0x7F
    ctx->pc = 0x1e9250u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x1e9254: 0x10620009  beq         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E9254u;
    {
        const bool branch_taken_0x1e9254 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e9254) {
            ctx->pc = 0x1E927Cu;
            goto label_1e927c;
        }
    }
    ctx->pc = 0x1E925Cu;
    // 0x1e925c: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E925Cu;
    SET_GPR_U32(ctx, 31, 0x1E9264u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9264u; }
        if (ctx->pc != 0x1E9264u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9264u; }
        if (ctx->pc != 0x1E9264u) { return; }
    }
    ctx->pc = 0x1E9264u;
label_1e9264:
    // 0x1e9264: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e9264u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9268: 0x24020009  addiu       $v0, $zero, 0x9
    ctx->pc = 0x1e9268u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1e926c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e926cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e9270: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e9270u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e9274: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x1E9274u;
    {
        const bool branch_taken_0x1e9274 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e9274) {
            ctx->pc = 0x1E92F4u;
            goto label_1e92f4;
        }
    }
    ctx->pc = 0x1E927Cu;
label_1e927c:
    // 0x1e927c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e927cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e9280: 0x84420000  lh          $v0, 0x0($v0)
    ctx->pc = 0x1e9280u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e9284: 0x87c30008  lh          $v1, 0x8($fp)
    ctx->pc = 0x1e9284u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e9288: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e9288u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e928c: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1e928cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e9290: 0x60302d  daddu       $a2, $v1, $zero
    ctx->pc = 0x1e9290u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9294: 0xc075fa4  jal         func_1D7E90
    ctx->pc = 0x1E9294u;
    SET_GPR_U32(ctx, 31, 0x1E929Cu);
    ctx->pc = 0x1D7E90u;
    if (runtime->hasFunction(0x1D7E90u)) {
        auto targetFn = runtime->lookupFunction(0x1D7E90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E929Cu; }
        if (ctx->pc != 0x1E929Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7E90_0x1d7e90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E929Cu; }
        if (ctx->pc != 0x1E929Cu) { return; }
    }
    ctx->pc = 0x1E929Cu;
label_1e929c:
    // 0x1e929c: 0xa7c20014  sh          $v0, 0x14($fp)
    ctx->pc = 0x1e929cu;
    WRITE16(ADD32(GPR_U32(ctx, 30), 20), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e92a0: 0x87c30014  lh          $v1, 0x14($fp)
    ctx->pc = 0x1e92a0u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e92a4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e92a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e92a8: 0x14620006  bne         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E92A8u;
    {
        const bool branch_taken_0x1e92a8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e92a8) {
            ctx->pc = 0x1E92C4u;
            goto label_1e92c4;
        }
    }
    ctx->pc = 0x1E92B0u;
    // 0x1e92b0: 0x8fc30010  lw          $v1, 0x10($fp)
    ctx->pc = 0x1e92b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e92b4: 0x24020ff2  addiu       $v0, $zero, 0xFF2
    ctx->pc = 0x1e92b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4082));
    // 0x1e92b8: 0xa4620004  sh          $v0, 0x4($v1)
    ctx->pc = 0x1e92b8u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e92bc: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1E92BCu;
    {
        const bool branch_taken_0x1e92bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e92bc) {
            ctx->pc = 0x1E92F0u;
            goto label_1e92f0;
        }
    }
    ctx->pc = 0x1E92C4u;
label_1e92c4:
    // 0x1e92c4: 0x87c20014  lh          $v0, 0x14($fp)
    ctx->pc = 0x1e92c4u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e92c8: 0x4410009  bgez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E92C8u;
    {
        const bool branch_taken_0x1e92c8 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1e92c8) {
            ctx->pc = 0x1E92F0u;
            goto label_1e92f0;
        }
    }
    ctx->pc = 0x1E92D0u;
    // 0x1e92d0: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E92D0u;
    SET_GPR_U32(ctx, 31, 0x1E92D8u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E92D8u; }
        if (ctx->pc != 0x1E92D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E92D8u; }
        if (ctx->pc != 0x1E92D8u) { return; }
    }
    ctx->pc = 0x1E92D8u;
label_1e92d8:
    // 0x1e92d8: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e92d8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e92dc: 0x2402000e  addiu       $v0, $zero, 0xE
    ctx->pc = 0x1e92dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1e92e0: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e92e0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e92e4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e92e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e92e8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1E92E8u;
    {
        const bool branch_taken_0x1e92e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e92e8) {
            ctx->pc = 0x1E92F4u;
            goto label_1e92f4;
        }
    }
    ctx->pc = 0x1E92F0u;
label_1e92f0:
    // 0x1e92f0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e92f0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e92f4:
    // 0x1e92f4: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e92f4u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e92f8: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e92f8u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e92fc: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e92fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e9300: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e9300u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e9304: 0x3e00008  jr          $ra
    ctx->pc = 0x1E9304u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E8F54u: goto label_1e8f54;
            case 0x1E8F6Cu: goto label_1e8f6c;
            case 0x1E8F84u: goto label_1e8f84;
            case 0x1E8F9Cu: goto label_1e8f9c;
            case 0x1E8FB8u: goto label_1e8fb8;
            case 0x1E8FD0u: goto label_1e8fd0;
            case 0x1E8FE8u: goto label_1e8fe8;
            case 0x1E9000u: goto label_1e9000;
            case 0x1E9034u: goto label_1e9034;
            case 0x1E904Cu: goto label_1e904c;
            case 0x1E9068u: goto label_1e9068;
            case 0x1E9084u: goto label_1e9084;
            case 0x1E909Cu: goto label_1e909c;
            case 0x1E90B4u: goto label_1e90b4;
            case 0x1E90CCu: goto label_1e90cc;
            case 0x1E90E4u: goto label_1e90e4;
            case 0x1E9110u: goto label_1e9110;
            case 0x1E9140u: goto label_1e9140;
            case 0x1E9144u: goto label_1e9144;
            case 0x1E9184u: goto label_1e9184;
            case 0x1E9194u: goto label_1e9194;
            case 0x1E91ACu: goto label_1e91ac;
            case 0x1E91C4u: goto label_1e91c4;
            case 0x1E91E0u: goto label_1e91e0;
            case 0x1E91F8u: goto label_1e91f8;
            case 0x1E9204u: goto label_1e9204;
            case 0x1E921Cu: goto label_1e921c;
            case 0x1E9234u: goto label_1e9234;
            case 0x1E9264u: goto label_1e9264;
            case 0x1E927Cu: goto label_1e927c;
            case 0x1E929Cu: goto label_1e929c;
            case 0x1E92C4u: goto label_1e92c4;
            case 0x1E92D8u: goto label_1e92d8;
            case 0x1E92F0u: goto label_1e92f0;
            case 0x1E92F4u: goto label_1e92f4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E930Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
