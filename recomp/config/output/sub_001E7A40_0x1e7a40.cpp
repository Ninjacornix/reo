#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E7A40
// Address: 0x1e7a40 - 0x1e7bb8
void sub_001E7A40_0x1e7a40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E7A40_0x1e7a40");
#endif

    switch (ctx->pc) {
        case 0x1e7a64u: goto label_1e7a64;
        case 0x1e7a70u: goto label_1e7a70;
        case 0x1e7a8cu: goto label_1e7a8c;
        case 0x1e7a94u: goto label_1e7a94;
        case 0x1e7aa4u: goto label_1e7aa4;
        case 0x1e7ac0u: goto label_1e7ac0;
        case 0x1e7ad0u: goto label_1e7ad0;
        case 0x1e7b00u: goto label_1e7b00;
        case 0x1e7b34u: goto label_1e7b34;
        default: break;
    }

    ctx->pc = 0x1e7a40u;

    // 0x1e7a40: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e7a40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e7a44: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e7a44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e7a48: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e7a48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e7a4c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e7a4cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7a50: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e7a50u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e7a54: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e7a54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e7a58: 0x8c42005c  lw          $v0, 0x5C($v0)
    ctx->pc = 0x1e7a58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 92)));
    // 0x1e7a5c: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1e7a5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1e7a60: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e7a60u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
label_1e7a64:
    // 0x1e7a64: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e7a64u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e7a68: 0xc07c441  jal         func_1F1104
    ctx->pc = 0x1E7A68u;
    SET_GPR_U32(ctx, 31, 0x1E7A70u);
    ctx->pc = 0x1F1104u;
    if (runtime->hasFunction(0x1F1104u)) {
        auto targetFn = runtime->lookupFunction(0x1F1104u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7A70u; }
        if (ctx->pc != 0x1E7A70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1104_0x1f1104(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7A70u; }
        if (ctx->pc != 0x1E7A70u) { return; }
    }
    ctx->pc = 0x1E7A70u;
label_1e7a70:
    // 0x1e7a70: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E7A70u;
    {
        const bool branch_taken_0x1e7a70 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e7a70) {
            ctx->pc = 0x1E7A80u;
            goto label_1e7a80;
        }
    }
    ctx->pc = 0x1E7A78u;
    // 0x1e7a78: 0x10000047  b           . + 4 + (0x47 << 2)
    ctx->pc = 0x1E7A78u;
    {
        const bool branch_taken_0x1e7a78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7a78) {
            ctx->pc = 0x1E7B98u;
            goto label_1e7b98;
        }
    }
    ctx->pc = 0x1E7A80u;
label_1e7a80:
    // 0x1e7a80: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e7a80u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e7a84: 0xc07c6e1  jal         func_1F1B84
    ctx->pc = 0x1E7A84u;
    SET_GPR_U32(ctx, 31, 0x1E7A8Cu);
    ctx->pc = 0x1F1B84u;
    if (runtime->hasFunction(0x1F1B84u)) {
        auto targetFn = runtime->lookupFunction(0x1F1B84u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7A8Cu; }
        if (ctx->pc != 0x1E7A8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1B84_0x1f1b84(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7A8Cu; }
        if (ctx->pc != 0x1E7A8Cu) { return; }
    }
    ctx->pc = 0x1E7A8Cu;
label_1e7a8c:
    // 0x1e7a8c: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e7a8cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e7a90: 0xafc00008  sw          $zero, 0x8($fp)
    ctx->pc = 0x1e7a90u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 0));
label_1e7a94:
    // 0x1e7a94: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e7a94u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e7a98: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e7a98u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e7a9c: 0xc07c5a2  jal         func_1F1688
    ctx->pc = 0x1E7A9Cu;
    SET_GPR_U32(ctx, 31, 0x1E7AA4u);
    ctx->pc = 0x1F1688u;
    if (runtime->hasFunction(0x1F1688u)) {
        auto targetFn = runtime->lookupFunction(0x1F1688u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7AA4u; }
        if (ctx->pc != 0x1E7AA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1688_0x1f1688(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7AA4u; }
        if (ctx->pc != 0x1E7AA4u) { return; }
    }
    ctx->pc = 0x1E7AA4u;
label_1e7aa4:
    // 0x1e7aa4: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E7AA4u;
    {
        const bool branch_taken_0x1e7aa4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7aa4) {
            ctx->pc = 0x1E7AB4u;
            goto label_1e7ab4;
        }
    }
    ctx->pc = 0x1E7AACu;
    // 0x1e7aac: 0x1000002c  b           . + 4 + (0x2C << 2)
    ctx->pc = 0x1E7AACu;
    {
        const bool branch_taken_0x1e7aac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7aac) {
            ctx->pc = 0x1E7B60u;
            goto label_1e7b60;
        }
    }
    ctx->pc = 0x1E7AB4u;
label_1e7ab4:
    // 0x1e7ab4: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e7ab4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e7ab8: 0xc07c6eb  jal         func_1F1BAC
    ctx->pc = 0x1E7AB8u;
    SET_GPR_U32(ctx, 31, 0x1E7AC0u);
    ctx->pc = 0x1F1BACu;
    if (runtime->hasFunction(0x1F1BACu)) {
        auto targetFn = runtime->lookupFunction(0x1F1BACu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7AC0u; }
        if (ctx->pc != 0x1E7AC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1BAC_0x1f1bac(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7AC0u; }
        if (ctx->pc != 0x1E7AC0u) { return; }
    }
    ctx->pc = 0x1E7AC0u;
label_1e7ac0:
    // 0x1e7ac0: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e7ac0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e7ac4: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e7ac4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e7ac8: 0xc07cd25  jal         func_1F3494
    ctx->pc = 0x1E7AC8u;
    SET_GPR_U32(ctx, 31, 0x1E7AD0u);
    ctx->pc = 0x1F3494u;
    if (runtime->hasFunction(0x1F3494u)) {
        auto targetFn = runtime->lookupFunction(0x1F3494u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7AD0u; }
        if (ctx->pc != 0x1E7AD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F3494_0x1f3494(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7AD0u; }
        if (ctx->pc != 0x1E7AD0u) { return; }
    }
    ctx->pc = 0x1E7AD0u;
label_1e7ad0:
    // 0x1e7ad0: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e7ad0u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7ad4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e7ad4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e7ad8: 0x8c42005c  lw          $v0, 0x5C($v0)
    ctx->pc = 0x1e7ad8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 92)));
    // 0x1e7adc: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e7adcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e7ae0: 0x1462001b  bne         $v1, $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x1E7AE0u;
    {
        const bool branch_taken_0x1e7ae0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e7ae0) {
            ctx->pc = 0x1E7B50u;
            goto label_1e7b50;
        }
    }
    ctx->pc = 0x1E7AE8u;
    // 0x1e7ae8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e7ae8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e7aec: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1e7aecu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1e7af0: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e7af0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e7af4: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e7af4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e7af8: 0xc07c4c3  jal         func_1F130C
    ctx->pc = 0x1E7AF8u;
    SET_GPR_U32(ctx, 31, 0x1E7B00u);
    ctx->pc = 0x1F130Cu;
    if (runtime->hasFunction(0x1F130Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F130Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7B00u; }
        if (ctx->pc != 0x1E7B00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F130C_0x1f130c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7B00u; }
        if (ctx->pc != 0x1E7B00u) { return; }
    }
    ctx->pc = 0x1E7B00u;
label_1e7b00:
    // 0x1e7b00: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1e7b00u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1e7b04: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e7b04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e7b08: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1E7B08u;
    {
        const bool branch_taken_0x1e7b08 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7b08) {
            ctx->pc = 0x1E7B1Cu;
            goto label_1e7b1c;
        }
    }
    ctx->pc = 0x1E7B10u;
    // 0x1e7b10: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e7b10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e7b14: 0x10000021  b           . + 4 + (0x21 << 2)
    ctx->pc = 0x1E7B14u;
    {
        const bool branch_taken_0x1e7b14 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7b14) {
            ctx->pc = 0x1E7B9Cu;
            goto label_1e7b9c;
        }
    }
    ctx->pc = 0x1E7B1Cu;
label_1e7b1c:
    // 0x1e7b1c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e7b1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e7b20: 0x24420068  addiu       $v0, $v0, 0x68
    ctx->pc = 0x1e7b20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 104));
    // 0x1e7b24: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e7b24u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7b28: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e7b28u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e7b2c: 0xc07c47a  jal         func_1F11E8
    ctx->pc = 0x1E7B2Cu;
    SET_GPR_U32(ctx, 31, 0x1E7B34u);
    ctx->pc = 0x1F11E8u;
    if (runtime->hasFunction(0x1F11E8u)) {
        auto targetFn = runtime->lookupFunction(0x1F11E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7B34u; }
        if (ctx->pc != 0x1E7B34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F11E8_0x1f11e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7B34u; }
        if (ctx->pc != 0x1E7B34u) { return; }
    }
    ctx->pc = 0x1E7B34u;
label_1e7b34:
    // 0x1e7b34: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1e7b34u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1e7b38: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e7b38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e7b3c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1E7B3Cu;
    {
        const bool branch_taken_0x1e7b3c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7b3c) {
            ctx->pc = 0x1E7B50u;
            goto label_1e7b50;
        }
    }
    ctx->pc = 0x1E7B44u;
    // 0x1e7b44: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e7b44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e7b48: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1E7B48u;
    {
        const bool branch_taken_0x1e7b48 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7b48) {
            ctx->pc = 0x1E7B9Cu;
            goto label_1e7b9c;
        }
    }
    ctx->pc = 0x1E7B50u;
label_1e7b50:
    // 0x1e7b50: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e7b50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e7b54: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e7b54u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e7b58: 0x1000ffce  b           . + 4 + (-0x32 << 2)
    ctx->pc = 0x1E7B58u;
    {
        const bool branch_taken_0x1e7b58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7b58) {
            ctx->pc = 0x1E7A94u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1e7a94;
        }
    }
    ctx->pc = 0x1E7B60u;
label_1e7b60:
    // 0x1e7b60: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e7b60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e7b64: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E7B64u;
    {
        const bool branch_taken_0x1e7b64 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e7b64) {
            ctx->pc = 0x1E7B74u;
            goto label_1e7b74;
        }
    }
    ctx->pc = 0x1E7B6Cu;
    // 0x1e7b6c: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1E7B6Cu;
    {
        const bool branch_taken_0x1e7b6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7b6c) {
            ctx->pc = 0x1E7B98u;
            goto label_1e7b98;
        }
    }
    ctx->pc = 0x1E7B74u;
label_1e7b74:
    // 0x1e7b74: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e7b74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e7b78: 0x8c43005c  lw          $v1, 0x5C($v0)
    ctx->pc = 0x1e7b78u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 92)));
    // 0x1e7b7c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e7b7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e7b80: 0x8c42005c  lw          $v0, 0x5C($v0)
    ctx->pc = 0x1e7b80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 92)));
    // 0x1e7b84: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e7b84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e7b88: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1e7b88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1e7b8c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e7b8cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e7b90: 0x1000ffb4  b           . + 4 + (-0x4C << 2)
    ctx->pc = 0x1E7B90u;
    {
        const bool branch_taken_0x1e7b90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7b90) {
            ctx->pc = 0x1E7A64u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1e7a64;
        }
    }
    ctx->pc = 0x1E7B98u;
label_1e7b98:
    // 0x1e7b98: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e7b98u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e7b9c:
    // 0x1e7b9c: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e7b9cu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7ba0: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e7ba0u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e7ba4: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e7ba4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e7ba8: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e7ba8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e7bac: 0x3e00008  jr          $ra
    ctx->pc = 0x1E7BACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E7A64u: goto label_1e7a64;
            case 0x1E7A70u: goto label_1e7a70;
            case 0x1E7A80u: goto label_1e7a80;
            case 0x1E7A8Cu: goto label_1e7a8c;
            case 0x1E7A94u: goto label_1e7a94;
            case 0x1E7AA4u: goto label_1e7aa4;
            case 0x1E7AB4u: goto label_1e7ab4;
            case 0x1E7AC0u: goto label_1e7ac0;
            case 0x1E7AD0u: goto label_1e7ad0;
            case 0x1E7B00u: goto label_1e7b00;
            case 0x1E7B1Cu: goto label_1e7b1c;
            case 0x1E7B34u: goto label_1e7b34;
            case 0x1E7B50u: goto label_1e7b50;
            case 0x1E7B60u: goto label_1e7b60;
            case 0x1E7B74u: goto label_1e7b74;
            case 0x1E7B98u: goto label_1e7b98;
            case 0x1E7B9Cu: goto label_1e7b9c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E7BB4u;
    // 0x1e7bb4: 0x0  nop
    ctx->pc = 0x1e7bb4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
