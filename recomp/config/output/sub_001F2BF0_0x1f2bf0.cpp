#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F2BF0
// Address: 0x1f2bf0 - 0x1f2e64
void sub_001F2BF0_0x1f2bf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F2BF0_0x1f2bf0");
#endif

    switch (ctx->pc) {
        case 0x1f2c14u: goto label_1f2c14;
        case 0x1f2c38u: goto label_1f2c38;
        case 0x1f2c60u: goto label_1f2c60;
        case 0x1f2c8cu: goto label_1f2c8c;
        case 0x1f2cb8u: goto label_1f2cb8;
        case 0x1f2cf8u: goto label_1f2cf8;
        case 0x1f2d18u: goto label_1f2d18;
        case 0x1f2d4cu: goto label_1f2d4c;
        case 0x1f2d8cu: goto label_1f2d8c;
        case 0x1f2dacu: goto label_1f2dac;
        case 0x1f2de0u: goto label_1f2de0;
        case 0x1f2e20u: goto label_1f2e20;
        case 0x1f2e48u: goto label_1f2e48;
        default: break;
    }

    ctx->pc = 0x1f2bf0u;

    // 0x1f2bf0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f2bf0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f2bf4: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1f2bf4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1f2bf8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1f2bf8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1f2bfc: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f2bfcu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2c00: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f2c00u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f2c04: 0xafc00004  sw          $zero, 0x4($fp)
    ctx->pc = 0x1f2c04u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 0));
    // 0x1f2c08: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f2c08u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2c0c: 0xc07c441  jal         func_1F1104
    ctx->pc = 0x1F2C0Cu;
    SET_GPR_U32(ctx, 31, 0x1F2C14u);
    ctx->pc = 0x1F1104u;
    if (runtime->hasFunction(0x1F1104u)) {
        auto targetFn = runtime->lookupFunction(0x1F1104u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2C14u; }
        if (ctx->pc != 0x1F2C14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1104_0x1f1104(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2C14u; }
        if (ctx->pc != 0x1F2C14u) { return; }
    }
    ctx->pc = 0x1F2C14u;
label_1f2c14:
    // 0x1f2c14: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1f2c14u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2c18: 0x9463005c  lhu         $v1, 0x5C($v1)
    ctx->pc = 0x1f2c18u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 92)));
    // 0x1f2c1c: 0x14430017  bne         $v0, $v1, . + 4 + (0x17 << 2)
    ctx->pc = 0x1F2C1Cu;
    {
        const bool branch_taken_0x1f2c1c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1f2c1c) {
            ctx->pc = 0x1F2C7Cu;
            goto label_1f2c7c;
        }
    }
    ctx->pc = 0x1F2C24u;
    // 0x1f2c24: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f2c24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2c28: 0x24420014  addiu       $v0, $v0, 0x14
    ctx->pc = 0x1f2c28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 20));
    // 0x1f2c2c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f2c2cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2c30: 0xc07c441  jal         func_1F1104
    ctx->pc = 0x1F2C30u;
    SET_GPR_U32(ctx, 31, 0x1F2C38u);
    ctx->pc = 0x1F1104u;
    if (runtime->hasFunction(0x1F1104u)) {
        auto targetFn = runtime->lookupFunction(0x1F1104u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2C38u; }
        if (ctx->pc != 0x1F2C38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1104_0x1f1104(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2C38u; }
        if (ctx->pc != 0x1F2C38u) { return; }
    }
    ctx->pc = 0x1F2C38u;
label_1f2c38:
    // 0x1f2c38: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1f2c38u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2c3c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f2c3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2c40: 0x94420062  lhu         $v0, 0x62($v0)
    ctx->pc = 0x1f2c40u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 98)));
    // 0x1f2c44: 0x1462000d  bne         $v1, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1F2C44u;
    {
        const bool branch_taken_0x1f2c44 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1f2c44) {
            ctx->pc = 0x1F2C7Cu;
            goto label_1f2c7c;
        }
    }
    ctx->pc = 0x1F2C4Cu;
    // 0x1f2c4c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f2c4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2c50: 0x24420028  addiu       $v0, $v0, 0x28
    ctx->pc = 0x1f2c50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 40));
    // 0x1f2c54: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f2c54u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2c58: 0xc07c441  jal         func_1F1104
    ctx->pc = 0x1F2C58u;
    SET_GPR_U32(ctx, 31, 0x1F2C60u);
    ctx->pc = 0x1F1104u;
    if (runtime->hasFunction(0x1F1104u)) {
        auto targetFn = runtime->lookupFunction(0x1F1104u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2C60u; }
        if (ctx->pc != 0x1F2C60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1104_0x1f1104(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2C60u; }
        if (ctx->pc != 0x1F2C60u) { return; }
    }
    ctx->pc = 0x1F2C60u;
label_1f2c60:
    // 0x1f2c60: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1f2c60u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2c64: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f2c64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2c68: 0x94420068  lhu         $v0, 0x68($v0)
    ctx->pc = 0x1f2c68u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 104)));
    // 0x1f2c6c: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F2C6Cu;
    {
        const bool branch_taken_0x1f2c6c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1f2c6c) {
            ctx->pc = 0x1F2C7Cu;
            goto label_1f2c7c;
        }
    }
    ctx->pc = 0x1F2C74u;
    // 0x1f2c74: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1F2C74u;
    {
        const bool branch_taken_0x1f2c74 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f2c74) {
            ctx->pc = 0x1F2C88u;
            goto label_1f2c88;
        }
    }
    ctx->pc = 0x1F2C7Cu;
label_1f2c7c:
    // 0x1f2c7c: 0x2402e0c1  addiu       $v0, $zero, -0x1F3F
    ctx->pc = 0x1f2c7cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294959297));
    // 0x1f2c80: 0x10000072  b           . + 4 + (0x72 << 2)
    ctx->pc = 0x1F2C80u;
    {
        const bool branch_taken_0x1f2c80 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f2c80) {
            ctx->pc = 0x1F2E4Cu;
            goto label_1f2e4c;
        }
    }
    ctx->pc = 0x1F2C88u;
label_1f2c88:
    // 0x1f2c88: 0xafc00004  sw          $zero, 0x4($fp)
    ctx->pc = 0x1f2c88u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 0));
label_1f2c8c:
    // 0x1f2c8c: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1f2c8cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f2c90: 0x2402e4aa  addiu       $v0, $zero, -0x1B56
    ctx->pc = 0x1f2c90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294960298));
    // 0x1f2c94: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F2C94u;
    {
        const bool branch_taken_0x1f2c94 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1f2c94) {
            ctx->pc = 0x1F2CA4u;
            goto label_1f2ca4;
        }
    }
    ctx->pc = 0x1F2C9Cu;
    // 0x1f2c9c: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x1F2C9Cu;
    {
        const bool branch_taken_0x1f2c9c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f2c9c) {
            ctx->pc = 0x1F2D14u;
            goto label_1f2d14;
        }
    }
    ctx->pc = 0x1F2CA4u;
label_1f2ca4:
    // 0x1f2ca4: 0x27c20008  addiu       $v0, $fp, 0x8
    ctx->pc = 0x1f2ca4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 8));
    // 0x1f2ca8: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f2ca8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2cac: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1f2cacu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2cb0: 0xc07c499  jal         func_1F1264
    ctx->pc = 0x1F2CB0u;
    SET_GPR_U32(ctx, 31, 0x1F2CB8u);
    ctx->pc = 0x1F1264u;
    if (runtime->hasFunction(0x1F1264u)) {
        auto targetFn = runtime->lookupFunction(0x1F1264u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2CB8u; }
        if (ctx->pc != 0x1F2CB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1264_0x1f1264(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2CB8u; }
        if (ctx->pc != 0x1F2CB8u) { return; }
    }
    ctx->pc = 0x1F2CB8u;
label_1f2cb8:
    // 0x1f2cb8: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1f2cb8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1f2cbc: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1f2cbcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f2cc0: 0x2402e4aa  addiu       $v0, $zero, -0x1B56
    ctx->pc = 0x1f2cc0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294960298));
    // 0x1f2cc4: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F2CC4u;
    {
        const bool branch_taken_0x1f2cc4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1f2cc4) {
            ctx->pc = 0x1F2CD4u;
            goto label_1f2cd4;
        }
    }
    ctx->pc = 0x1F2CCCu;
    // 0x1f2ccc: 0x1000ffef  b           . + 4 + (-0x11 << 2)
    ctx->pc = 0x1F2CCCu;
    {
        const bool branch_taken_0x1f2ccc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f2ccc) {
            ctx->pc = 0x1F2C8Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f2c8c;
        }
    }
    ctx->pc = 0x1F2CD4u;
label_1f2cd4:
    // 0x1f2cd4: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f2cd4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f2cd8: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F2CD8u;
    {
        const bool branch_taken_0x1f2cd8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f2cd8) {
            ctx->pc = 0x1F2CECu;
            goto label_1f2cec;
        }
    }
    ctx->pc = 0x1F2CE0u;
    // 0x1f2ce0: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f2ce0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f2ce4: 0x10000059  b           . + 4 + (0x59 << 2)
    ctx->pc = 0x1F2CE4u;
    {
        const bool branch_taken_0x1f2ce4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f2ce4) {
            ctx->pc = 0x1F2E4Cu;
            goto label_1f2e4c;
        }
    }
    ctx->pc = 0x1F2CECu;
label_1f2cec:
    // 0x1f2cec: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1f2cecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f2cf0: 0xc07cf95  jal         func_1F3E54
    ctx->pc = 0x1F2CF0u;
    SET_GPR_U32(ctx, 31, 0x1F2CF8u);
    ctx->pc = 0x1F3E54u;
    if (runtime->hasFunction(0x1F3E54u)) {
        auto targetFn = runtime->lookupFunction(0x1F3E54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2CF8u; }
        if (ctx->pc != 0x1F2CF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F3E54_0x1f3e54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2CF8u; }
        if (ctx->pc != 0x1F2CF8u) { return; }
    }
    ctx->pc = 0x1F2CF8u;
label_1f2cf8:
    // 0x1f2cf8: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1f2cf8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1f2cfc: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f2cfcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f2d00: 0x1040ffe2  beqz        $v0, . + 4 + (-0x1E << 2)
    ctx->pc = 0x1F2D00u;
    {
        const bool branch_taken_0x1f2d00 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f2d00) {
            ctx->pc = 0x1F2C8Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f2c8c;
        }
    }
    ctx->pc = 0x1F2D08u;
    // 0x1f2d08: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f2d08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f2d0c: 0x1000004f  b           . + 4 + (0x4F << 2)
    ctx->pc = 0x1F2D0Cu;
    {
        const bool branch_taken_0x1f2d0c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f2d0c) {
            ctx->pc = 0x1F2E4Cu;
            goto label_1f2e4c;
        }
    }
    ctx->pc = 0x1F2D14u;
label_1f2d14:
    // 0x1f2d14: 0xafc00004  sw          $zero, 0x4($fp)
    ctx->pc = 0x1f2d14u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 0));
label_1f2d18:
    // 0x1f2d18: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1f2d18u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f2d1c: 0x2402e4aa  addiu       $v0, $zero, -0x1B56
    ctx->pc = 0x1f2d1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294960298));
    // 0x1f2d20: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F2D20u;
    {
        const bool branch_taken_0x1f2d20 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1f2d20) {
            ctx->pc = 0x1F2D30u;
            goto label_1f2d30;
        }
    }
    ctx->pc = 0x1F2D28u;
    // 0x1f2d28: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x1F2D28u;
    {
        const bool branch_taken_0x1f2d28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f2d28) {
            ctx->pc = 0x1F2DA8u;
            goto label_1f2da8;
        }
    }
    ctx->pc = 0x1F2D30u;
label_1f2d30:
    // 0x1f2d30: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f2d30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2d34: 0x24420014  addiu       $v0, $v0, 0x14
    ctx->pc = 0x1f2d34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 20));
    // 0x1f2d38: 0x27c30008  addiu       $v1, $fp, 0x8
    ctx->pc = 0x1f2d38u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 8));
    // 0x1f2d3c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f2d3cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2d40: 0x60282d  daddu       $a1, $v1, $zero
    ctx->pc = 0x1f2d40u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2d44: 0xc07c499  jal         func_1F1264
    ctx->pc = 0x1F2D44u;
    SET_GPR_U32(ctx, 31, 0x1F2D4Cu);
    ctx->pc = 0x1F1264u;
    if (runtime->hasFunction(0x1F1264u)) {
        auto targetFn = runtime->lookupFunction(0x1F1264u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2D4Cu; }
        if (ctx->pc != 0x1F2D4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1264_0x1f1264(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2D4Cu; }
        if (ctx->pc != 0x1F2D4Cu) { return; }
    }
    ctx->pc = 0x1F2D4Cu;
label_1f2d4c:
    // 0x1f2d4c: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1f2d4cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1f2d50: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1f2d50u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f2d54: 0x2402e4aa  addiu       $v0, $zero, -0x1B56
    ctx->pc = 0x1f2d54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294960298));
    // 0x1f2d58: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F2D58u;
    {
        const bool branch_taken_0x1f2d58 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1f2d58) {
            ctx->pc = 0x1F2D68u;
            goto label_1f2d68;
        }
    }
    ctx->pc = 0x1F2D60u;
    // 0x1f2d60: 0x1000ffed  b           . + 4 + (-0x13 << 2)
    ctx->pc = 0x1F2D60u;
    {
        const bool branch_taken_0x1f2d60 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f2d60) {
            ctx->pc = 0x1F2D18u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f2d18;
        }
    }
    ctx->pc = 0x1F2D68u;
label_1f2d68:
    // 0x1f2d68: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f2d68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f2d6c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F2D6Cu;
    {
        const bool branch_taken_0x1f2d6c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f2d6c) {
            ctx->pc = 0x1F2D80u;
            goto label_1f2d80;
        }
    }
    ctx->pc = 0x1F2D74u;
    // 0x1f2d74: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f2d74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f2d78: 0x10000034  b           . + 4 + (0x34 << 2)
    ctx->pc = 0x1F2D78u;
    {
        const bool branch_taken_0x1f2d78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f2d78) {
            ctx->pc = 0x1F2E4Cu;
            goto label_1f2e4c;
        }
    }
    ctx->pc = 0x1F2D80u;
label_1f2d80:
    // 0x1f2d80: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1f2d80u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f2d84: 0xc07cf95  jal         func_1F3E54
    ctx->pc = 0x1F2D84u;
    SET_GPR_U32(ctx, 31, 0x1F2D8Cu);
    ctx->pc = 0x1F3E54u;
    if (runtime->hasFunction(0x1F3E54u)) {
        auto targetFn = runtime->lookupFunction(0x1F3E54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2D8Cu; }
        if (ctx->pc != 0x1F2D8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F3E54_0x1f3e54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2D8Cu; }
        if (ctx->pc != 0x1F2D8Cu) { return; }
    }
    ctx->pc = 0x1F2D8Cu;
label_1f2d8c:
    // 0x1f2d8c: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1f2d8cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1f2d90: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f2d90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f2d94: 0x1040ffe0  beqz        $v0, . + 4 + (-0x20 << 2)
    ctx->pc = 0x1F2D94u;
    {
        const bool branch_taken_0x1f2d94 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f2d94) {
            ctx->pc = 0x1F2D18u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f2d18;
        }
    }
    ctx->pc = 0x1F2D9Cu;
    // 0x1f2d9c: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f2d9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f2da0: 0x1000002a  b           . + 4 + (0x2A << 2)
    ctx->pc = 0x1F2DA0u;
    {
        const bool branch_taken_0x1f2da0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f2da0) {
            ctx->pc = 0x1F2E4Cu;
            goto label_1f2e4c;
        }
    }
    ctx->pc = 0x1F2DA8u;
label_1f2da8:
    // 0x1f2da8: 0xafc00004  sw          $zero, 0x4($fp)
    ctx->pc = 0x1f2da8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 0));
label_1f2dac:
    // 0x1f2dac: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1f2dacu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f2db0: 0x2402e4aa  addiu       $v0, $zero, -0x1B56
    ctx->pc = 0x1f2db0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294960298));
    // 0x1f2db4: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F2DB4u;
    {
        const bool branch_taken_0x1f2db4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1f2db4) {
            ctx->pc = 0x1F2DC4u;
            goto label_1f2dc4;
        }
    }
    ctx->pc = 0x1F2DBCu;
    // 0x1f2dbc: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x1F2DBCu;
    {
        const bool branch_taken_0x1f2dbc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f2dbc) {
            ctx->pc = 0x1F2E3Cu;
            goto label_1f2e3c;
        }
    }
    ctx->pc = 0x1F2DC4u;
label_1f2dc4:
    // 0x1f2dc4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f2dc4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2dc8: 0x24420028  addiu       $v0, $v0, 0x28
    ctx->pc = 0x1f2dc8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 40));
    // 0x1f2dcc: 0x27c30008  addiu       $v1, $fp, 0x8
    ctx->pc = 0x1f2dccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 8));
    // 0x1f2dd0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f2dd0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2dd4: 0x60282d  daddu       $a1, $v1, $zero
    ctx->pc = 0x1f2dd4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2dd8: 0xc07c499  jal         func_1F1264
    ctx->pc = 0x1F2DD8u;
    SET_GPR_U32(ctx, 31, 0x1F2DE0u);
    ctx->pc = 0x1F1264u;
    if (runtime->hasFunction(0x1F1264u)) {
        auto targetFn = runtime->lookupFunction(0x1F1264u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2DE0u; }
        if (ctx->pc != 0x1F2DE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1264_0x1f1264(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2DE0u; }
        if (ctx->pc != 0x1F2DE0u) { return; }
    }
    ctx->pc = 0x1F2DE0u;
label_1f2de0:
    // 0x1f2de0: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1f2de0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1f2de4: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1f2de4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f2de8: 0x2402e4aa  addiu       $v0, $zero, -0x1B56
    ctx->pc = 0x1f2de8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294960298));
    // 0x1f2dec: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F2DECu;
    {
        const bool branch_taken_0x1f2dec = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1f2dec) {
            ctx->pc = 0x1F2DFCu;
            goto label_1f2dfc;
        }
    }
    ctx->pc = 0x1F2DF4u;
    // 0x1f2df4: 0x1000ffed  b           . + 4 + (-0x13 << 2)
    ctx->pc = 0x1F2DF4u;
    {
        const bool branch_taken_0x1f2df4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f2df4) {
            ctx->pc = 0x1F2DACu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f2dac;
        }
    }
    ctx->pc = 0x1F2DFCu;
label_1f2dfc:
    // 0x1f2dfc: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f2dfcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f2e00: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F2E00u;
    {
        const bool branch_taken_0x1f2e00 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f2e00) {
            ctx->pc = 0x1F2E14u;
            goto label_1f2e14;
        }
    }
    ctx->pc = 0x1F2E08u;
    // 0x1f2e08: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f2e08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f2e0c: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1F2E0Cu;
    {
        const bool branch_taken_0x1f2e0c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f2e0c) {
            ctx->pc = 0x1F2E4Cu;
            goto label_1f2e4c;
        }
    }
    ctx->pc = 0x1F2E14u;
label_1f2e14:
    // 0x1f2e14: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1f2e14u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f2e18: 0xc07cf95  jal         func_1F3E54
    ctx->pc = 0x1F2E18u;
    SET_GPR_U32(ctx, 31, 0x1F2E20u);
    ctx->pc = 0x1F3E54u;
    if (runtime->hasFunction(0x1F3E54u)) {
        auto targetFn = runtime->lookupFunction(0x1F3E54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2E20u; }
        if (ctx->pc != 0x1F2E20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F3E54_0x1f3e54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2E20u; }
        if (ctx->pc != 0x1F2E20u) { return; }
    }
    ctx->pc = 0x1F2E20u;
label_1f2e20:
    // 0x1f2e20: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1f2e20u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1f2e24: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f2e24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f2e28: 0x1040ffe0  beqz        $v0, . + 4 + (-0x20 << 2)
    ctx->pc = 0x1F2E28u;
    {
        const bool branch_taken_0x1f2e28 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f2e28) {
            ctx->pc = 0x1F2DACu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f2dac;
        }
    }
    ctx->pc = 0x1F2E30u;
    // 0x1f2e30: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f2e30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f2e34: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1F2E34u;
    {
        const bool branch_taken_0x1f2e34 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f2e34) {
            ctx->pc = 0x1F2E4Cu;
            goto label_1f2e4c;
        }
    }
    ctx->pc = 0x1F2E3Cu;
label_1f2e3c:
    // 0x1f2e3c: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f2e3cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2e40: 0xc079f90  jal         func_1E7E40
    ctx->pc = 0x1F2E40u;
    SET_GPR_U32(ctx, 31, 0x1F2E48u);
    ctx->pc = 0x1E7E40u;
    if (runtime->hasFunction(0x1E7E40u)) {
        auto targetFn = runtime->lookupFunction(0x1E7E40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2E48u; }
        if (ctx->pc != 0x1F2E48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E7E40_0x1e7e40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2E48u; }
        if (ctx->pc != 0x1F2E48u) { return; }
    }
    ctx->pc = 0x1F2E48u;
label_1f2e48:
    // 0x1f2e48: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f2e48u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1f2e4c:
    // 0x1f2e4c: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f2e4cu;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2e50: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1f2e50u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f2e54: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1f2e54u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1f2e58: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1f2e58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1f2e5c: 0x3e00008  jr          $ra
    ctx->pc = 0x1F2E5Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F2C14u: goto label_1f2c14;
            case 0x1F2C38u: goto label_1f2c38;
            case 0x1F2C60u: goto label_1f2c60;
            case 0x1F2C7Cu: goto label_1f2c7c;
            case 0x1F2C88u: goto label_1f2c88;
            case 0x1F2C8Cu: goto label_1f2c8c;
            case 0x1F2CA4u: goto label_1f2ca4;
            case 0x1F2CB8u: goto label_1f2cb8;
            case 0x1F2CD4u: goto label_1f2cd4;
            case 0x1F2CECu: goto label_1f2cec;
            case 0x1F2CF8u: goto label_1f2cf8;
            case 0x1F2D14u: goto label_1f2d14;
            case 0x1F2D18u: goto label_1f2d18;
            case 0x1F2D30u: goto label_1f2d30;
            case 0x1F2D4Cu: goto label_1f2d4c;
            case 0x1F2D68u: goto label_1f2d68;
            case 0x1F2D80u: goto label_1f2d80;
            case 0x1F2D8Cu: goto label_1f2d8c;
            case 0x1F2DA8u: goto label_1f2da8;
            case 0x1F2DACu: goto label_1f2dac;
            case 0x1F2DC4u: goto label_1f2dc4;
            case 0x1F2DE0u: goto label_1f2de0;
            case 0x1F2DFCu: goto label_1f2dfc;
            case 0x1F2E14u: goto label_1f2e14;
            case 0x1F2E20u: goto label_1f2e20;
            case 0x1F2E3Cu: goto label_1f2e3c;
            case 0x1F2E48u: goto label_1f2e48;
            case 0x1F2E4Cu: goto label_1f2e4c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F2E64u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
