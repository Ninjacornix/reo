#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DCC2C
// Address: 0x1dcc2c - 0x1dcd10
void sub_001DCC2C_0x1dcc2c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DCC2C_0x1dcc2c");
#endif

    switch (ctx->pc) {
        case 0x1dcc40u: goto label_1dcc40;
        case 0x1dcc54u: goto label_1dcc54;
        case 0x1dcc80u: goto label_1dcc80;
        case 0x1dccc4u: goto label_1dccc4;
        case 0x1dccd8u: goto label_1dccd8;
        default: break;
    }

    ctx->pc = 0x1dcc2cu;

    // 0x1dcc2c: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1dcc2cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1dcc30: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1dcc30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1dcc34: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1dcc34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1dcc38: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1dcc38u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dcc3c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1dcc3cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
label_1dcc40:
    // 0x1dcc40: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dcc40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dcc44: 0x24420068  addiu       $v0, $v0, 0x68
    ctx->pc = 0x1dcc44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 104));
    // 0x1dcc48: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1dcc48u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dcc4c: 0xc07c441  jal         func_1F1104
    ctx->pc = 0x1DCC4Cu;
    SET_GPR_U32(ctx, 31, 0x1DCC54u);
    ctx->pc = 0x1F1104u;
    if (runtime->hasFunction(0x1F1104u)) {
        auto targetFn = runtime->lookupFunction(0x1F1104u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCC54u; }
        if (ctx->pc != 0x1DCC54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1104_0x1f1104(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCC54u; }
        if (ctx->pc != 0x1DCC54u) { return; }
    }
    ctx->pc = 0x1DCC54u;
label_1dcc54:
    // 0x1dcc54: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DCC54u;
    {
        const bool branch_taken_0x1dcc54 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1dcc54) {
            ctx->pc = 0x1DCC64u;
            goto label_1dcc64;
        }
    }
    ctx->pc = 0x1DCC5Cu;
    // 0x1dcc5c: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x1DCC5Cu;
    {
        const bool branch_taken_0x1dcc5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dcc5c) {
            ctx->pc = 0x1DCCF4u;
            goto label_1dccf4;
        }
    }
    ctx->pc = 0x1DCC64u;
label_1dcc64:
    // 0x1dcc64: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dcc64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dcc68: 0x24420068  addiu       $v0, $v0, 0x68
    ctx->pc = 0x1dcc68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 104));
    // 0x1dcc6c: 0x27c30008  addiu       $v1, $fp, 0x8
    ctx->pc = 0x1dcc6cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 8));
    // 0x1dcc70: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1dcc70u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dcc74: 0x60282d  daddu       $a1, $v1, $zero
    ctx->pc = 0x1dcc74u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dcc78: 0xc07c499  jal         func_1F1264
    ctx->pc = 0x1DCC78u;
    SET_GPR_U32(ctx, 31, 0x1DCC80u);
    ctx->pc = 0x1F1264u;
    if (runtime->hasFunction(0x1F1264u)) {
        auto targetFn = runtime->lookupFunction(0x1F1264u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCC80u; }
        if (ctx->pc != 0x1DCC80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1264_0x1f1264(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCC80u; }
        if (ctx->pc != 0x1DCC80u) { return; }
    }
    ctx->pc = 0x1DCC80u;
label_1dcc80:
    // 0x1dcc80: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1dcc80u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1dcc84: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1dcc84u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dcc88: 0x2402e4aa  addiu       $v0, $zero, -0x1B56
    ctx->pc = 0x1dcc88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294960298));
    // 0x1dcc8c: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DCC8Cu;
    {
        const bool branch_taken_0x1dcc8c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1dcc8c) {
            ctx->pc = 0x1DCC9Cu;
            goto label_1dcc9c;
        }
    }
    ctx->pc = 0x1DCC94u;
    // 0x1dcc94: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1DCC94u;
    {
        const bool branch_taken_0x1dcc94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dcc94) {
            ctx->pc = 0x1DCCF4u;
            goto label_1dccf4;
        }
    }
    ctx->pc = 0x1DCC9Cu;
label_1dcc9c:
    // 0x1dcc9c: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1dcc9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dcca0: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1DCCA0u;
    {
        const bool branch_taken_0x1dcca0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dcca0) {
            ctx->pc = 0x1DCCB4u;
            goto label_1dccb4;
        }
    }
    ctx->pc = 0x1DCCA8u;
    // 0x1dcca8: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1dcca8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dccac: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1DCCACu;
    {
        const bool branch_taken_0x1dccac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dccac) {
            ctx->pc = 0x1DCCF8u;
            goto label_1dccf8;
        }
    }
    ctx->pc = 0x1DCCB4u;
label_1dccb4:
    // 0x1dccb4: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1dccb4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dccb8: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1dccb8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dccbc: 0xc077f6a  jal         func_1DFDA8
    ctx->pc = 0x1DCCBCu;
    SET_GPR_U32(ctx, 31, 0x1DCCC4u);
    ctx->pc = 0x1DFDA8u;
    if (runtime->hasFunction(0x1DFDA8u)) {
        auto targetFn = runtime->lookupFunction(0x1DFDA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCCC4u; }
        if (ctx->pc != 0x1DCCC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DFDA8_0x1dfda8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCCC4u; }
        if (ctx->pc != 0x1DCCC4u) { return; }
    }
    ctx->pc = 0x1DCCC4u;
label_1dccc4:
    // 0x1dccc4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1dccc4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dccc8: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1dccc8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1dcccc: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1dccccu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dccd0: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1DCCD0u;
    SET_GPR_U32(ctx, 31, 0x1DCCD8u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCCD8u; }
        if (ctx->pc != 0x1DCCD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DCCD8u; }
        if (ctx->pc != 0x1DCCD8u) { return; }
    }
    ctx->pc = 0x1DCCD8u;
label_1dccd8:
    // 0x1dccd8: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1dccd8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1dccdc: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1dccdcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dcce0: 0x1040ffd7  beqz        $v0, . + 4 + (-0x29 << 2)
    ctx->pc = 0x1DCCE0u;
    {
        const bool branch_taken_0x1dcce0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dcce0) {
            ctx->pc = 0x1DCC40u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1dcc40;
        }
    }
    ctx->pc = 0x1DCCE8u;
    // 0x1dcce8: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1dcce8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dccec: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1DCCECu;
    {
        const bool branch_taken_0x1dccec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1dccec) {
            ctx->pc = 0x1DCCF8u;
            goto label_1dccf8;
        }
    }
    ctx->pc = 0x1DCCF4u;
label_1dccf4:
    // 0x1dccf4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1dccf4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1dccf8:
    // 0x1dccf8: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1dccf8u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dccfc: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1dccfcu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1dcd00: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1dcd00u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1dcd04: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1dcd04u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1dcd08: 0x3e00008  jr          $ra
    ctx->pc = 0x1DCD08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DCC40u: goto label_1dcc40;
            case 0x1DCC54u: goto label_1dcc54;
            case 0x1DCC64u: goto label_1dcc64;
            case 0x1DCC80u: goto label_1dcc80;
            case 0x1DCC9Cu: goto label_1dcc9c;
            case 0x1DCCB4u: goto label_1dccb4;
            case 0x1DCCC4u: goto label_1dccc4;
            case 0x1DCCD8u: goto label_1dccd8;
            case 0x1DCCF4u: goto label_1dccf4;
            case 0x1DCCF8u: goto label_1dccf8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DCD10u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
