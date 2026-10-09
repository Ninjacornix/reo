#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DEF1C
// Address: 0x1def1c - 0x1deff0
void sub_001DEF1C_0x1def1c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DEF1C_0x1def1c");
#endif

    switch (ctx->pc) {
        case 0x1def3cu: goto label_1def3c;
        case 0x1def70u: goto label_1def70;
        case 0x1def9cu: goto label_1def9c;
        default: break;
    }

    ctx->pc = 0x1def1cu;

    // 0x1def1c: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1def1cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1def20: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1def20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1def24: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1def24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1def28: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1def28u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1def2c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1def2cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1def30: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1def30u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1def34: 0xc077950  jal         func_1DE540
    ctx->pc = 0x1DEF34u;
    SET_GPR_U32(ctx, 31, 0x1DEF3Cu);
    ctx->pc = 0x1DE540u;
    if (runtime->hasFunction(0x1DE540u)) {
        auto targetFn = runtime->lookupFunction(0x1DE540u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DEF3Cu; }
        if (ctx->pc != 0x1DEF3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DE540_0x1de540(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DEF3Cu; }
        if (ctx->pc != 0x1DEF3Cu) { return; }
    }
    ctx->pc = 0x1DEF3Cu;
label_1def3c:
    // 0x1def3c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1def3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1def40: 0x2442000c  addiu       $v0, $v0, 0xC
    ctx->pc = 0x1def40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 12));
    // 0x1def44: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1def44u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1def48: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1def48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1def4c: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1def4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1def50: 0x2842037d  slti        $v0, $v0, 0x37D
    ctx->pc = 0x1def50u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)893) ? 1 : 0);
    // 0x1def54: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DEF54u;
    {
        const bool branch_taken_0x1def54 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1def54) {
            ctx->pc = 0x1DEF64u;
            goto label_1def64;
        }
    }
    ctx->pc = 0x1DEF5Cu;
    // 0x1def5c: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x1DEF5Cu;
    {
        const bool branch_taken_0x1def5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1def5c) {
            ctx->pc = 0x1DEFD8u;
            goto label_1defd8;
        }
    }
    ctx->pc = 0x1DEF64u;
label_1def64:
    // 0x1def64: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1def64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1def68: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1def68u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1def6c: 0xafc00004  sw          $zero, 0x4($fp)
    ctx->pc = 0x1def6cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 0));
label_1def70:
    // 0x1def70: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1def70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1def74: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1def74u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1def78: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1def78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1def7c: 0x62102a  slt         $v0, $v1, $v0
    ctx->pc = 0x1def7cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1def80: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1DEF80u;
    {
        const bool branch_taken_0x1def80 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1def80) {
            ctx->pc = 0x1DEF90u;
            goto label_1def90;
        }
    }
    ctx->pc = 0x1DEF88u;
    // 0x1def88: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x1DEF88u;
    {
        const bool branch_taken_0x1def88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1def88) {
            ctx->pc = 0x1DEFD8u;
            goto label_1defd8;
        }
    }
    ctx->pc = 0x1DEF90u;
label_1def90:
    // 0x1def90: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1def90u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1def94: 0xc077b62  jal         func_1DED88
    ctx->pc = 0x1DEF94u;
    SET_GPR_U32(ctx, 31, 0x1DEF9Cu);
    ctx->pc = 0x1DED88u;
    if (runtime->hasFunction(0x1DED88u)) {
        auto targetFn = runtime->lookupFunction(0x1DED88u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DEF9Cu; }
        if (ctx->pc != 0x1DEF9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DED88_0x1ded88(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DEF9Cu; }
        if (ctx->pc != 0x1DEF9Cu) { return; }
    }
    ctx->pc = 0x1DEF9Cu;
label_1def9c:
    // 0x1def9c: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1def9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1defa0: 0x8c42001c  lw          $v0, 0x1C($v0)
    ctx->pc = 0x1defa0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 28)));
    // 0x1defa4: 0x24420023  addiu       $v0, $v0, 0x23
    ctx->pc = 0x1defa4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 35));
    // 0x1defa8: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x1defa8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x1defac: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1defacu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1defb0: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1defb0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1defb4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1defb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1defb8: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1defb8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1defbc: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1defbcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1defc0: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1defc0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1defc4: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1defc4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1defc8: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1defc8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1defcc: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1defccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1defd0: 0x1000ffe7  b           . + 4 + (-0x19 << 2)
    ctx->pc = 0x1DEFD0u;
    {
        const bool branch_taken_0x1defd0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1defd0) {
            ctx->pc = 0x1DEF70u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1def70;
        }
    }
    ctx->pc = 0x1DEFD8u;
label_1defd8:
    // 0x1defd8: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1defd8u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1defdc: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1defdcu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1defe0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1defe0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1defe4: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1defe4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1defe8: 0x3e00008  jr          $ra
    ctx->pc = 0x1DEFE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DEF3Cu: goto label_1def3c;
            case 0x1DEF64u: goto label_1def64;
            case 0x1DEF70u: goto label_1def70;
            case 0x1DEF90u: goto label_1def90;
            case 0x1DEF9Cu: goto label_1def9c;
            case 0x1DEFD8u: goto label_1defd8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DEFF0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
