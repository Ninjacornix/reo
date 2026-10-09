#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E99D8
// Address: 0x1e99d8 - 0x1e9dc8
void sub_001E99D8_0x1e99d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E99D8_0x1e99d8");
#endif

    switch (ctx->pc) {
        case 0x1e9a24u: goto label_1e9a24;
        case 0x1e9af4u: goto label_1e9af4;
        case 0x1e9b24u: goto label_1e9b24;
        case 0x1e9bbcu: goto label_1e9bbc;
        case 0x1e9d1cu: goto label_1e9d1c;
        default: break;
    }

    ctx->pc = 0x1e99d8u;

    // 0x1e99d8: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1e99d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1e99dc: 0xffbe0040  sd          $fp, 0x40($sp)
    ctx->pc = 0x1e99dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 30));
    // 0x1e99e0: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x1e99e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x1e99e4: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e99e4u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e99e8: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e99e8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e99ec: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e99ecu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e99f0: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e99f0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e99f4: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1e99f4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1e99f8: 0xafc80010  sw          $t0, 0x10($fp)
    ctx->pc = 0x1e99f8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 8));
    // 0x1e99fc: 0xafc00020  sw          $zero, 0x20($fp)
    ctx->pc = 0x1e99fcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 0));
    // 0x1e9a00: 0xafc00024  sw          $zero, 0x24($fp)
    ctx->pc = 0x1e9a00u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 0));
    // 0x1e9a04: 0xafc0001c  sw          $zero, 0x1C($fp)
    ctx->pc = 0x1e9a04u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 0));
    // 0x1e9a08: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e9a08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e9a0c: 0x28420041  slti        $v0, $v0, 0x41
    ctx->pc = 0x1e9a0cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)65) ? 1 : 0);
    // 0x1e9a10: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E9A10u;
    {
        const bool branch_taken_0x1e9a10 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e9a10) {
            ctx->pc = 0x1E9A20u;
            goto label_1e9a20;
        }
    }
    ctx->pc = 0x1E9A18u;
    // 0x1e9a18: 0x24020040  addiu       $v0, $zero, 0x40
    ctx->pc = 0x1e9a18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x1e9a1c: 0xafc20000  sw          $v0, 0x0($fp)
    ctx->pc = 0x1e9a1cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 2));
label_1e9a20:
    // 0x1e9a20: 0xafc00014  sw          $zero, 0x14($fp)
    ctx->pc = 0x1e9a20u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
label_1e9a24:
    // 0x1e9a24: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e9a24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e9a28: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e9a28u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e9a2c: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x1e9a2cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1e9a30: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E9A30u;
    {
        const bool branch_taken_0x1e9a30 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e9a30) {
            ctx->pc = 0x1E9A40u;
            goto label_1e9a40;
        }
    }
    ctx->pc = 0x1E9A38u;
    // 0x1e9a38: 0x100000dc  b           . + 4 + (0xDC << 2)
    ctx->pc = 0x1E9A38u;
    {
        const bool branch_taken_0x1e9a38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e9a38) {
            ctx->pc = 0x1E9DACu;
            goto label_1e9dac;
        }
    }
    ctx->pc = 0x1E9A40u;
label_1e9a40:
    // 0x1e9a40: 0xafc00024  sw          $zero, 0x24($fp)
    ctx->pc = 0x1e9a40u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 0));
    // 0x1e9a44: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e9a44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e9a48: 0x10400082  beqz        $v0, . + 4 + (0x82 << 2)
    ctx->pc = 0x1E9A48u;
    {
        const bool branch_taken_0x1e9a48 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e9a48) {
            ctx->pc = 0x1E9C54u;
            goto label_1e9c54;
        }
    }
    ctx->pc = 0x1E9A50u;
    // 0x1e9a50: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e9a50u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e9a54: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e9a54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e9a58: 0x21182  srl         $v0, $v0, 6
    ctx->pc = 0x1e9a58u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 6));
    // 0x1e9a5c: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1e9a5cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1e9a60: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1e9a60u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e9a64: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e9a64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e9a68: 0x3043003f  andi        $v1, $v0, 0x3F
    ctx->pc = 0x1e9a68u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)63);
    // 0x1e9a6c: 0xdc820000  ld          $v0, 0x0($a0)
    ctx->pc = 0x1e9a6cu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1e9a70: 0x621817  dsrav       $v1, $v0, $v1
    ctx->pc = 0x1e9a70u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 2) >> (GPR_U32(ctx, 3) & 0x3F));
    // 0x1e9a74: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e9a74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e9a78: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e9a78u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e9a7c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1e9a7cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1e9a80: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x1e9a80u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x1e9a84: 0x10400073  beqz        $v0, . + 4 + (0x73 << 2)
    ctx->pc = 0x1E9A84u;
    {
        const bool branch_taken_0x1e9a84 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e9a84) {
            ctx->pc = 0x1E9C54u;
            goto label_1e9c54;
        }
    }
    ctx->pc = 0x1E9A8Cu;
    // 0x1e9a8c: 0x8fc30014  lw          $v1, 0x14($fp)
    ctx->pc = 0x1e9a8cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e9a90: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e9a90u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9a94: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1e9a94u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1e9a98: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e9a98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e9a9c: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e9a9cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e9aa0: 0x8f828028  lw          $v0, -0x7FD8($gp)
    ctx->pc = 0x1e9aa0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 28), 4294934568)));
    // 0x1e9aa4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e9aa4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e9aa8: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e9aa8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e9aac: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e9aacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e9ab0: 0x94420002  lhu         $v0, 0x2($v0)
    ctx->pc = 0x1e9ab0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x1e9ab4: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1e9ab4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1e9ab8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e9ab8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e9abc: 0x8fc3002c  lw          $v1, 0x2C($fp)
    ctx->pc = 0x1e9abcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1e9ac0: 0x10620038  beq         $v1, $v0, . + 4 + (0x38 << 2)
    ctx->pc = 0x1E9AC0u;
    {
        const bool branch_taken_0x1e9ac0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e9ac0) {
            ctx->pc = 0x1E9BA4u;
            goto label_1e9ba4;
        }
    }
    ctx->pc = 0x1E9AC8u;
    // 0x1e9ac8: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1e9ac8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1e9acc: 0x8fc3002c  lw          $v1, 0x2C($fp)
    ctx->pc = 0x1e9accu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1e9ad0: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E9AD0u;
    {
        const bool branch_taken_0x1e9ad0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e9ad0) {
            ctx->pc = 0x1E9AE0u;
            goto label_1e9ae0;
        }
    }
    ctx->pc = 0x1E9AD8u;
    // 0x1e9ad8: 0x1000005e  b           . + 4 + (0x5E << 2)
    ctx->pc = 0x1E9AD8u;
    {
        const bool branch_taken_0x1e9ad8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e9ad8) {
            ctx->pc = 0x1E9C54u;
            goto label_1e9c54;
        }
    }
    ctx->pc = 0x1E9AE0u;
label_1e9ae0:
    // 0x1e9ae0: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1e9ae0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1e9ae4: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1E9AE4u;
    {
        const bool branch_taken_0x1e9ae4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e9ae4) {
            ctx->pc = 0x1E9AFCu;
            goto label_1e9afc;
        }
    }
    ctx->pc = 0x1E9AECu;
    // 0x1e9aec: 0xc07a61b  jal         func_1E986C
    ctx->pc = 0x1E9AECu;
    SET_GPR_U32(ctx, 31, 0x1E9AF4u);
    ctx->pc = 0x1E986Cu;
    if (runtime->hasFunction(0x1E986Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E986Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9AF4u; }
        if (ctx->pc != 0x1E9AF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E986C_0x1e986c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9AF4u; }
        if (ctx->pc != 0x1E9AF4u) { return; }
    }
    ctx->pc = 0x1E9AF4u;
label_1e9af4:
    // 0x1e9af4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e9af4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e9af8: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1e9af8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
label_1e9afc:
    // 0x1e9afc: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e9afcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e9b00: 0x94430004  lhu         $v1, 0x4($v0)
    ctx->pc = 0x1e9b00u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e9b04: 0x2402007f  addiu       $v0, $zero, 0x7F
    ctx->pc = 0x1e9b04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x1e9b08: 0x14620021  bne         $v1, $v0, . + 4 + (0x21 << 2)
    ctx->pc = 0x1E9B08u;
    {
        const bool branch_taken_0x1e9b08 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e9b08) {
            ctx->pc = 0x1E9B90u;
            goto label_1e9b90;
        }
    }
    ctx->pc = 0x1E9B10u;
    // 0x1e9b10: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e9b10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e9b14: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1e9b14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1e9b18: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e9b18u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9b1c: 0xc07c441  jal         func_1F1104
    ctx->pc = 0x1E9B1Cu;
    SET_GPR_U32(ctx, 31, 0x1E9B24u);
    ctx->pc = 0x1F1104u;
    if (runtime->hasFunction(0x1F1104u)) {
        auto targetFn = runtime->lookupFunction(0x1F1104u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9B24u; }
        if (ctx->pc != 0x1E9B24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1104_0x1f1104(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9B24u; }
        if (ctx->pc != 0x1E9B24u) { return; }
    }
    ctx->pc = 0x1E9B24u;
label_1e9b24:
    // 0x1e9b24: 0x14400015  bnez        $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x1E9B24u;
    {
        const bool branch_taken_0x1e9b24 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e9b24) {
            ctx->pc = 0x1E9B7Cu;
            goto label_1e9b7c;
        }
    }
    ctx->pc = 0x1E9B2Cu;
    // 0x1e9b2c: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e9b2cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e9b30: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e9b30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e9b34: 0x22182  srl         $a0, $v0, 6
    ctx->pc = 0x1e9b34u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 2), 6));
    // 0x1e9b38: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1e9b38u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9b3c: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1e9b3cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1e9b40: 0x622821  addu        $a1, $v1, $v0
    ctx->pc = 0x1e9b40u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e9b44: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e9b44u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e9b48: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1e9b48u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9b4c: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1e9b4cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1e9b50: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1e9b50u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e9b54: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e9b54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e9b58: 0x3043003f  andi        $v1, $v0, 0x3F
    ctx->pc = 0x1e9b58u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)63);
    // 0x1e9b5c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e9b5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e9b60: 0x621014  dsllv       $v0, $v0, $v1
    ctx->pc = 0x1e9b60u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (GPR_U32(ctx, 3) & 0x3F));
    // 0x1e9b64: 0x21827  nor         $v1, $zero, $v0
    ctx->pc = 0x1e9b64u;
    SET_GPR_U64(ctx, 3, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 2)));
    // 0x1e9b68: 0xdc820000  ld          $v0, 0x0($a0)
    ctx->pc = 0x1e9b68u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1e9b6c: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x1e9b6cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x1e9b70: 0xfca20000  sd          $v0, 0x0($a1)
    ctx->pc = 0x1e9b70u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 0), GPR_U64(ctx, 2));
    // 0x1e9b74: 0x10000037  b           . + 4 + (0x37 << 2)
    ctx->pc = 0x1E9B74u;
    {
        const bool branch_taken_0x1e9b74 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e9b74) {
            ctx->pc = 0x1E9C54u;
            goto label_1e9c54;
        }
    }
    ctx->pc = 0x1E9B7Cu;
label_1e9b7c:
    // 0x1e9b7c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e9b7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e9b80: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1e9b80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1e9b84: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e9b84u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e9b88: 0x10000032  b           . + 4 + (0x32 << 2)
    ctx->pc = 0x1E9B88u;
    {
        const bool branch_taken_0x1e9b88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e9b88) {
            ctx->pc = 0x1E9C54u;
            goto label_1e9c54;
        }
    }
    ctx->pc = 0x1E9B90u;
label_1e9b90:
    // 0x1e9b90: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e9b90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e9b94: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1e9b94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1e9b98: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e9b98u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e9b9c: 0x1000002d  b           . + 4 + (0x2D << 2)
    ctx->pc = 0x1E9B9Cu;
    {
        const bool branch_taken_0x1e9b9c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e9b9c) {
            ctx->pc = 0x1E9C54u;
            goto label_1e9c54;
        }
    }
    ctx->pc = 0x1E9BA4u;
label_1e9ba4:
    // 0x1e9ba4: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1e9ba4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e9ba8: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1E9BA8u;
    {
        const bool branch_taken_0x1e9ba8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e9ba8) {
            ctx->pc = 0x1E9BC8u;
            goto label_1e9bc8;
        }
    }
    ctx->pc = 0x1E9BB0u;
    // 0x1e9bb0: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e9bb0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e9bb4: 0xc07aa87  jal         func_1EAA1C
    ctx->pc = 0x1E9BB4u;
    SET_GPR_U32(ctx, 31, 0x1E9BBCu);
    ctx->pc = 0x1EAA1Cu;
    if (runtime->hasFunction(0x1EAA1Cu)) {
        auto targetFn = runtime->lookupFunction(0x1EAA1Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9BBCu; }
        if (ctx->pc != 0x1E9BBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001EAA1C_0x1eaa1c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9BBCu; }
        if (ctx->pc != 0x1E9BBCu) { return; }
    }
    ctx->pc = 0x1E9BBCu;
label_1e9bbc:
    // 0x1e9bbc: 0xa7c20028  sh          $v0, 0x28($fp)
    ctx->pc = 0x1e9bbcu;
    WRITE16(ADD32(GPR_U32(ctx, 30), 40), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e9bc0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e9bc0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e9bc4: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1e9bc4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
label_1e9bc8:
    // 0x1e9bc8: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e9bc8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e9bcc: 0x94430004  lhu         $v1, 0x4($v0)
    ctx->pc = 0x1e9bccu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e9bd0: 0x24020ff4  addiu       $v0, $zero, 0xFF4
    ctx->pc = 0x1e9bd0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4084));
    // 0x1e9bd4: 0x10620008  beq         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1E9BD4u;
    {
        const bool branch_taken_0x1e9bd4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e9bd4) {
            ctx->pc = 0x1E9BF8u;
            goto label_1e9bf8;
        }
    }
    ctx->pc = 0x1E9BDCu;
    // 0x1e9bdc: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e9bdcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e9be0: 0x94430004  lhu         $v1, 0x4($v0)
    ctx->pc = 0x1e9be0u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e9be4: 0x24020ff6  addiu       $v0, $zero, 0xFF6
    ctx->pc = 0x1e9be4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4086));
    // 0x1e9be8: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E9BE8u;
    {
        const bool branch_taken_0x1e9be8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e9be8) {
            ctx->pc = 0x1E9BF8u;
            goto label_1e9bf8;
        }
    }
    ctx->pc = 0x1E9BF0u;
    // 0x1e9bf0: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1E9BF0u;
    {
        const bool branch_taken_0x1e9bf0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e9bf0) {
            ctx->pc = 0x1E9C0Cu;
            goto label_1e9c0c;
        }
    }
    ctx->pc = 0x1E9BF8u;
label_1e9bf8:
    // 0x1e9bf8: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e9bf8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e9bfc: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1e9bfcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1e9c00: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e9c00u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e9c04: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x1E9C04u;
    {
        const bool branch_taken_0x1e9c04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e9c04) {
            ctx->pc = 0x1E9C54u;
            goto label_1e9c54;
        }
    }
    ctx->pc = 0x1E9C0Cu;
label_1e9c0c:
    // 0x1e9c0c: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e9c0cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e9c10: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e9c10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e9c14: 0x22182  srl         $a0, $v0, 6
    ctx->pc = 0x1e9c14u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 2), 6));
    // 0x1e9c18: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1e9c18u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9c1c: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1e9c1cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1e9c20: 0x622821  addu        $a1, $v1, $v0
    ctx->pc = 0x1e9c20u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e9c24: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e9c24u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e9c28: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1e9c28u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9c2c: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1e9c2cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1e9c30: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1e9c30u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e9c34: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e9c34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e9c38: 0x3043003f  andi        $v1, $v0, 0x3F
    ctx->pc = 0x1e9c38u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)63);
    // 0x1e9c3c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e9c3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e9c40: 0x621014  dsllv       $v0, $v0, $v1
    ctx->pc = 0x1e9c40u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (GPR_U32(ctx, 3) & 0x3F));
    // 0x1e9c44: 0x21827  nor         $v1, $zero, $v0
    ctx->pc = 0x1e9c44u;
    SET_GPR_U64(ctx, 3, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 2)));
    // 0x1e9c48: 0xdc820000  ld          $v0, 0x0($a0)
    ctx->pc = 0x1e9c48u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1e9c4c: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x1e9c4cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x1e9c50: 0xfca20000  sd          $v0, 0x0($a1)
    ctx->pc = 0x1e9c50u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 0), GPR_U64(ctx, 2));
label_1e9c54:
    // 0x1e9c54: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e9c54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e9c58: 0x1040004f  beqz        $v0, . + 4 + (0x4F << 2)
    ctx->pc = 0x1E9C58u;
    {
        const bool branch_taken_0x1e9c58 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e9c58) {
            ctx->pc = 0x1E9D98u;
            goto label_1e9d98;
        }
    }
    ctx->pc = 0x1E9C60u;
    // 0x1e9c60: 0x8fc30008  lw          $v1, 0x8($fp)
    ctx->pc = 0x1e9c60u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e9c64: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e9c64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e9c68: 0x21182  srl         $v0, $v0, 6
    ctx->pc = 0x1e9c68u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 6));
    // 0x1e9c6c: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1e9c6cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1e9c70: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1e9c70u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e9c74: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e9c74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e9c78: 0x3043003f  andi        $v1, $v0, 0x3F
    ctx->pc = 0x1e9c78u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)63);
    // 0x1e9c7c: 0xdc820000  ld          $v0, 0x0($a0)
    ctx->pc = 0x1e9c7cu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1e9c80: 0x621817  dsrav       $v1, $v0, $v1
    ctx->pc = 0x1e9c80u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 2) >> (GPR_U32(ctx, 3) & 0x3F));
    // 0x1e9c84: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e9c84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e9c88: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e9c88u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e9c8c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1e9c8cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1e9c90: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x1e9c90u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x1e9c94: 0x10400040  beqz        $v0, . + 4 + (0x40 << 2)
    ctx->pc = 0x1E9C94u;
    {
        const bool branch_taken_0x1e9c94 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e9c94) {
            ctx->pc = 0x1E9D98u;
            goto label_1e9d98;
        }
    }
    ctx->pc = 0x1E9C9Cu;
    // 0x1e9c9c: 0x8fc30014  lw          $v1, 0x14($fp)
    ctx->pc = 0x1e9c9cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e9ca0: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1e9ca0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9ca4: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1e9ca4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1e9ca8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e9ca8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e9cac: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e9cacu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e9cb0: 0x8f828028  lw          $v0, -0x7FD8($gp)
    ctx->pc = 0x1e9cb0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 28), 4294934568)));
    // 0x1e9cb4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e9cb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e9cb8: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e9cb8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e9cbc: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e9cbcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e9cc0: 0x94420002  lhu         $v0, 0x2($v0)
    ctx->pc = 0x1e9cc0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x1e9cc4: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1e9cc4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1e9cc8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e9cc8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e9ccc: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1e9cccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e9cd0: 0x1062000c  beq         $v1, $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1E9CD0u;
    {
        const bool branch_taken_0x1e9cd0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e9cd0) {
            ctx->pc = 0x1E9D04u;
            goto label_1e9d04;
        }
    }
    ctx->pc = 0x1E9CD8u;
    // 0x1e9cd8: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1e9cd8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1e9cdc: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1e9cdcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1e9ce0: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E9CE0u;
    {
        const bool branch_taken_0x1e9ce0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e9ce0) {
            ctx->pc = 0x1E9CF0u;
            goto label_1e9cf0;
        }
    }
    ctx->pc = 0x1E9CE8u;
    // 0x1e9ce8: 0x1000002b  b           . + 4 + (0x2B << 2)
    ctx->pc = 0x1E9CE8u;
    {
        const bool branch_taken_0x1e9ce8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e9ce8) {
            ctx->pc = 0x1E9D98u;
            goto label_1e9d98;
        }
    }
    ctx->pc = 0x1E9CF0u;
label_1e9cf0:
    // 0x1e9cf0: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e9cf0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e9cf4: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1e9cf4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1e9cf8: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e9cf8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e9cfc: 0x10000026  b           . + 4 + (0x26 << 2)
    ctx->pc = 0x1E9CFCu;
    {
        const bool branch_taken_0x1e9cfc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e9cfc) {
            ctx->pc = 0x1E9D98u;
            goto label_1e9d98;
        }
    }
    ctx->pc = 0x1E9D04u;
label_1e9d04:
    // 0x1e9d04: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1e9d04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1e9d08: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1E9D08u;
    {
        const bool branch_taken_0x1e9d08 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e9d08) {
            ctx->pc = 0x1E9D28u;
            goto label_1e9d28;
        }
    }
    ctx->pc = 0x1E9D10u;
    // 0x1e9d10: 0x8fc40018  lw          $a0, 0x18($fp)
    ctx->pc = 0x1e9d10u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e9d14: 0xc07aa87  jal         func_1EAA1C
    ctx->pc = 0x1E9D14u;
    SET_GPR_U32(ctx, 31, 0x1E9D1Cu);
    ctx->pc = 0x1EAA1Cu;
    if (runtime->hasFunction(0x1EAA1Cu)) {
        auto targetFn = runtime->lookupFunction(0x1EAA1Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9D1Cu; }
        if (ctx->pc != 0x1E9D1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001EAA1C_0x1eaa1c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9D1Cu; }
        if (ctx->pc != 0x1E9D1Cu) { return; }
    }
    ctx->pc = 0x1E9D1Cu;
label_1e9d1c:
    // 0x1e9d1c: 0xa7c20028  sh          $v0, 0x28($fp)
    ctx->pc = 0x1e9d1cu;
    WRITE16(ADD32(GPR_U32(ctx, 30), 40), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e9d20: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e9d20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e9d24: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1e9d24u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
label_1e9d28:
    // 0x1e9d28: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e9d28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e9d2c: 0x94430004  lhu         $v1, 0x4($v0)
    ctx->pc = 0x1e9d2cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e9d30: 0x2402007f  addiu       $v0, $zero, 0x7F
    ctx->pc = 0x1e9d30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x1e9d34: 0x14620006  bne         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E9D34u;
    {
        const bool branch_taken_0x1e9d34 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e9d34) {
            ctx->pc = 0x1E9D50u;
            goto label_1e9d50;
        }
    }
    ctx->pc = 0x1E9D3Cu;
    // 0x1e9d3c: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e9d3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e9d40: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1e9d40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1e9d44: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1e9d44u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1e9d48: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x1E9D48u;
    {
        const bool branch_taken_0x1e9d48 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e9d48) {
            ctx->pc = 0x1E9D98u;
            goto label_1e9d98;
        }
    }
    ctx->pc = 0x1E9D50u;
label_1e9d50:
    // 0x1e9d50: 0x8fc30008  lw          $v1, 0x8($fp)
    ctx->pc = 0x1e9d50u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e9d54: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e9d54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e9d58: 0x22182  srl         $a0, $v0, 6
    ctx->pc = 0x1e9d58u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 2), 6));
    // 0x1e9d5c: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1e9d5cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9d60: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1e9d60u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1e9d64: 0x622821  addu        $a1, $v1, $v0
    ctx->pc = 0x1e9d64u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e9d68: 0x8fc30008  lw          $v1, 0x8($fp)
    ctx->pc = 0x1e9d68u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e9d6c: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1e9d6cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9d70: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1e9d70u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1e9d74: 0x622021  addu        $a0, $v1, $v0
    ctx->pc = 0x1e9d74u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1e9d78: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e9d78u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e9d7c: 0x3043003f  andi        $v1, $v0, 0x3F
    ctx->pc = 0x1e9d7cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)63);
    // 0x1e9d80: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e9d80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e9d84: 0x621014  dsllv       $v0, $v0, $v1
    ctx->pc = 0x1e9d84u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (GPR_U32(ctx, 3) & 0x3F));
    // 0x1e9d88: 0x21827  nor         $v1, $zero, $v0
    ctx->pc = 0x1e9d88u;
    SET_GPR_U64(ctx, 3, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 2)));
    // 0x1e9d8c: 0xdc820000  ld          $v0, 0x0($a0)
    ctx->pc = 0x1e9d8cu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1e9d90: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x1e9d90u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x1e9d94: 0xfca20000  sd          $v0, 0x0($a1)
    ctx->pc = 0x1e9d94u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 0), GPR_U64(ctx, 2));
label_1e9d98:
    // 0x1e9d98: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e9d98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e9d9c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1e9d9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1e9da0: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e9da0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e9da4: 0x1000ff1f  b           . + 4 + (-0xE1 << 2)
    ctx->pc = 0x1E9DA4u;
    {
        const bool branch_taken_0x1e9da4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e9da4) {
            ctx->pc = 0x1E9A24u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1e9a24;
        }
    }
    ctx->pc = 0x1E9DACu;
label_1e9dac:
    // 0x1e9dac: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1e9dacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1e9db0: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e9db0u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9db4: 0xdfbe0040  ld          $fp, 0x40($sp)
    ctx->pc = 0x1e9db4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1e9db8: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x1e9db8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1e9dbc: 0x27bd0050  addiu       $sp, $sp, 0x50
    ctx->pc = 0x1e9dbcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1e9dc0: 0x3e00008  jr          $ra
    ctx->pc = 0x1E9DC0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E9A20u: goto label_1e9a20;
            case 0x1E9A24u: goto label_1e9a24;
            case 0x1E9A40u: goto label_1e9a40;
            case 0x1E9AE0u: goto label_1e9ae0;
            case 0x1E9AF4u: goto label_1e9af4;
            case 0x1E9AFCu: goto label_1e9afc;
            case 0x1E9B24u: goto label_1e9b24;
            case 0x1E9B7Cu: goto label_1e9b7c;
            case 0x1E9B90u: goto label_1e9b90;
            case 0x1E9BA4u: goto label_1e9ba4;
            case 0x1E9BBCu: goto label_1e9bbc;
            case 0x1E9BC8u: goto label_1e9bc8;
            case 0x1E9BF8u: goto label_1e9bf8;
            case 0x1E9C0Cu: goto label_1e9c0c;
            case 0x1E9C54u: goto label_1e9c54;
            case 0x1E9CF0u: goto label_1e9cf0;
            case 0x1E9D04u: goto label_1e9d04;
            case 0x1E9D1Cu: goto label_1e9d1c;
            case 0x1E9D28u: goto label_1e9d28;
            case 0x1E9D50u: goto label_1e9d50;
            case 0x1E9D98u: goto label_1e9d98;
            case 0x1E9DACu: goto label_1e9dac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E9DC8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
