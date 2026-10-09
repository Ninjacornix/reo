#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C9D8
// Address: 0x12c9d8 - 0x12cb58
void sub_0012C9D8_0x12c9d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C9D8_0x12c9d8");
#endif

    switch (ctx->pc) {
        case 0x12ca20u: goto label_12ca20;
        case 0x12ca74u: goto label_12ca74;
        case 0x12ca80u: goto label_12ca80;
        case 0x12ca90u: goto label_12ca90;
        case 0x12cab4u: goto label_12cab4;
        case 0x12cad0u: goto label_12cad0;
        case 0x12cae8u: goto label_12cae8;
        case 0x12cb14u: goto label_12cb14;
        default: break;
    }

    ctx->pc = 0x12c9d8u;

    // 0x12c9d8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x12c9d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x12c9dc: 0x3c070021  lui         $a3, 0x21
    ctx->pc = 0x12c9dcu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)33 << 16));
    // 0x12c9e0: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x12c9e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x12c9e4: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x12c9e4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12c9e8: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x12c9e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x12c9ec: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x12c9ecu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12c9f0: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x12c9f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x12c9f4: 0x80a82d  daddu       $s5, $a0, $zero
    ctx->pc = 0x12c9f4u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12c9f8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12c9f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12c9fc: 0x24e37d88  addiu       $v1, $a3, 0x7D88
    ctx->pc = 0x12c9fcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), 32136));
    // 0x12ca00: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12ca00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12ca04: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12ca04u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ca08: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x12ca08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12ca0c: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x12ca0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x12ca10: 0x80620000  lb          $v0, 0x0($v1)
    ctx->pc = 0x12ca10u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12ca14: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x12CA14u;
    {
        const bool branch_taken_0x12ca14 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x12CA18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12CA14u;
            // 0x12ca18: 0x8e900000  lw          $s0, 0x0($s4) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ca14) {
            ctx->pc = 0x12CA44u;
            goto label_12ca44;
        }
    }
    ctx->pc = 0x12CA1Cu;
    // 0x12ca1c: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x12ca1cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
label_12ca20:
    // 0x12ca20: 0x28a20010  slti        $v0, $a1, 0x10
    ctx->pc = 0x12ca20u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x12ca24: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x12CA24u;
    {
        const bool branch_taken_0x12ca24 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x12CA28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12CA24u;
            // 0x12ca28: 0x2463009c  addiu       $v1, $v1, 0x9C (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 156));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ca24) {
            ctx->pc = 0x12CA44u;
            goto label_12ca44;
        }
    }
    ctx->pc = 0x12CA2Cu;
    // 0x12ca2c: 0x80620000  lb          $v0, 0x0($v1)
    ctx->pc = 0x12ca2cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12ca30: 0x0  nop
    ctx->pc = 0x12ca30u;
    // NOP
    // 0x12ca34: 0x0  nop
    ctx->pc = 0x12ca34u;
    // NOP
    // 0x12ca38: 0x0  nop
    ctx->pc = 0x12ca38u;
    // NOP
    // 0x12ca3c: 0x5440fff8  bnel        $v0, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x12CA3Cu;
    {
        const bool branch_taken_0x12ca3c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x12ca3c) {
            ctx->pc = 0x12CA40u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12CA3Cu;
            // 0x12ca40: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12CA20u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12ca20;
        }
    }
    ctx->pc = 0x12CA44u;
label_12ca44:
    // 0x12ca44: 0x24030010  addiu       $v1, $zero, 0x10
    ctx->pc = 0x12ca44u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x12ca48: 0x10a30039  beq         $a1, $v1, . + 4 + (0x39 << 2)
    ctx->pc = 0x12CA48u;
    {
        const bool branch_taken_0x12ca48 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        ctx->pc = 0x12CA4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12CA48u;
            // 0x12ca4c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ca48) {
            ctx->pc = 0x12CB30u;
            goto label_12cb30;
        }
    }
    ctx->pc = 0x12CA50u;
    // 0x12ca50: 0x51080  sll         $v0, $a1, 2
    ctx->pc = 0x12ca50u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x12ca54: 0x24e37d88  addiu       $v1, $a3, 0x7D88
    ctx->pc = 0x12ca54u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), 32136));
    // 0x12ca58: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x12ca58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x12ca5c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x12ca5cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ca60: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x12ca60u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x12ca64: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x12ca64u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x12ca68: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x12ca68u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x12ca6c: 0xc04ffee  jal         func_13FFB8
    ctx->pc = 0x12CA6Cu;
    SET_GPR_U32(ctx, 31, 0x12CA74u);
    ctx->pc = 0x12CA70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12CA6Cu;
            // 0x12ca70: 0x439021  addu        $s2, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13FFB8u;
    if (runtime->hasFunction(0x13FFB8u)) {
        auto targetFn = runtime->lookupFunction(0x13FFB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CA74u; }
        if (ctx->pc != 0x12CA74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013FFB8_0x13ffb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CA74u; }
        if (ctx->pc != 0x12CA74u) { return; }
    }
    ctx->pc = 0x12CA74u;
label_12ca74:
    // 0x12ca74: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x12ca74u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ca78: 0xc04fff0  jal         func_13FFC0
    ctx->pc = 0x12CA78u;
    SET_GPR_U32(ctx, 31, 0x12CA80u);
    ctx->pc = 0x12CA7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12CA78u;
            // 0x12ca7c: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13FFC0u;
    if (runtime->hasFunction(0x13FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x13FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CA80u; }
        if (ctx->pc != 0x12CA80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013FFC0_0x13ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CA80u; }
        if (ctx->pc != 0x12CA80u) { return; }
    }
    ctx->pc = 0x12CA80u;
label_12ca80:
    // 0x12ca80: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x12ca80u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ca84: 0x287c2  srl         $s0, $v0, 31
    ctx->pc = 0x12ca84u;
    SET_GPR_S32(ctx, 16, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x12ca88: 0xc04fff2  jal         func_13FFC8
    ctx->pc = 0x12CA88u;
    SET_GPR_U32(ctx, 31, 0x12CA90u);
    ctx->pc = 0x12CA8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12CA88u;
            // 0x12ca8c: 0x2028021  addu        $s0, $s0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13FFC8u;
    if (runtime->hasFunction(0x13FFC8u)) {
        auto targetFn = runtime->lookupFunction(0x13FFC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CA90u; }
        if (ctx->pc != 0x12CA90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013FFC8_0x13ffc8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CA90u; }
        if (ctx->pc != 0x12CA90u) { return; }
    }
    ctx->pc = 0x12CA90u;
label_12ca90:
    // 0x12ca90: 0x23fc2  srl         $a3, $v0, 31
    ctx->pc = 0x12ca90u;
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x12ca94: 0x108043  sra         $s0, $s0, 1
    ctx->pc = 0x12ca94u;
    SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 16), 1));
    // 0x12ca98: 0xe23821  addu        $a3, $a3, $v0
    ctx->pc = 0x12ca98u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x12ca9c: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x12ca9cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12caa0: 0x73843  sra         $a3, $a3, 1
    ctx->pc = 0x12caa0u;
    SET_GPR_S32(ctx, 7, SRA32(GPR_S32(ctx, 7), 1));
    // 0x12caa4: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x12caa4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12caa8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x12caa8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12caac: 0xc049218  jal         func_124860
    ctx->pc = 0x12CAACu;
    SET_GPR_U32(ctx, 31, 0x12CAB4u);
    ctx->pc = 0x12CAB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12CAACu;
            // 0x12cab0: 0xc73821  addu        $a3, $a2, $a3 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124860u;
    if (runtime->hasFunction(0x124860u)) {
        auto targetFn = runtime->lookupFunction(0x124860u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CAB4u; }
        if (ctx->pc != 0x12CAB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00124860_0x124860(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CAB4u; }
        if (ctx->pc != 0x12CAB4u) { return; }
    }
    ctx->pc = 0x12CAB4u;
label_12cab4:
    // 0x12cab4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x12cab4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12cab8: 0x1080001d  beqz        $a0, . + 4 + (0x1D << 2)
    ctx->pc = 0x12CAB8u;
    {
        const bool branch_taken_0x12cab8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x12CABCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12CAB8u;
            // 0x12cabc: 0xae440004  sw          $a0, 0x4($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12cab8) {
            ctx->pc = 0x12CB30u;
            goto label_12cb30;
        }
    }
    ctx->pc = 0x12CAC0u;
    // 0x12cac0: 0x3c050013  lui         $a1, 0x13
    ctx->pc = 0x12cac0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)19 << 16));
    // 0x12cac4: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x12cac4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12cac8: 0xc049390  jal         func_124E40
    ctx->pc = 0x12CAC8u;
    SET_GPR_U32(ctx, 31, 0x12CAD0u);
    ctx->pc = 0x12CACCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12CAC8u;
            // 0x12cacc: 0x24a5ceb8  addiu       $a1, $a1, -0x3148 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294954680));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124E40u;
    if (runtime->hasFunction(0x124E40u)) {
        auto targetFn = runtime->lookupFunction(0x124E40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CAD0u; }
        if (ctx->pc != 0x12CAD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00124E40_0x124e40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CAD0u; }
        if (ctx->pc != 0x12CAD0u) { return; }
    }
    ctx->pc = 0x12CAD0u;
label_12cad0:
    // 0x12cad0: 0xae550008  sw          $s5, 0x8($s2)
    ctx->pc = 0x12cad0u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 8), GPR_U32(ctx, 21));
    // 0x12cad4: 0xa2530002  sb          $s3, 0x2($s2)
    ctx->pc = 0x12cad4u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 2), (uint8_t)GPR_U32(ctx, 19));
    // 0x12cad8: 0x1a60000b  blez        $s3, . + 4 + (0xB << 2)
    ctx->pc = 0x12CAD8u;
    {
        const bool branch_taken_0x12cad8 = (GPR_S64(ctx, 19) <= 0);
        ctx->pc = 0x12CADCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12CAD8u;
            // 0x12cadc: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12cad8) {
            ctx->pc = 0x12CB08u;
            goto label_12cb08;
        }
    }
    ctx->pc = 0x12CAE0u;
    // 0x12cae0: 0x2647000c  addiu       $a3, $s2, 0xC
    ctx->pc = 0x12cae0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 18), 12));
    // 0x12cae4: 0x0  nop
    ctx->pc = 0x12cae4u;
    // NOP
label_12cae8:
    // 0x12cae8: 0x61080  sll         $v0, $a2, 2
    ctx->pc = 0x12cae8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x12caec: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x12caecu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x12caf0: 0x541821  addu        $v1, $v0, $s4
    ctx->pc = 0x12caf0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 20)));
    // 0x12caf4: 0xe21021  addu        $v0, $a3, $v0
    ctx->pc = 0x12caf4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x12caf8: 0x8c640000  lw          $a0, 0x0($v1)
    ctx->pc = 0x12caf8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12cafc: 0xd3282a  slt         $a1, $a2, $s3
    ctx->pc = 0x12cafcu;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 19)) ? 1 : 0);
    // 0x12cb00: 0x14a0fff9  bnez        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x12CB00u;
    {
        const bool branch_taken_0x12cb00 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x12CB04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12CB00u;
            // 0x12cb04: 0xac440000  sw          $a0, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12cb00) {
            ctx->pc = 0x12CAE8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12cae8;
        }
    }
    ctx->pc = 0x12CB08u;
label_12cb08:
    // 0x12cb08: 0xa2400001  sb          $zero, 0x1($s2)
    ctx->pc = 0x12cb08u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x12cb0c: 0xc04b268  jal         func_12C9A0
    ctx->pc = 0x12CB0Cu;
    SET_GPR_U32(ctx, 31, 0x12CB14u);
    ctx->pc = 0x12CB10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12CB0Cu;
            // 0x12cb10: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12C9A0u;
    if (runtime->hasFunction(0x12C9A0u)) {
        auto targetFn = runtime->lookupFunction(0x12C9A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CB14u; }
        if (ctx->pc != 0x12CB14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C9A0_0x12c9a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CB14u; }
        if (ctx->pc != 0x12CB14u) { return; }
    }
    ctx->pc = 0x12CB14u;
label_12cb14:
    // 0x12cb14: 0xae400048  sw          $zero, 0x48($s2)
    ctx->pc = 0x12cb14u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 72), GPR_U32(ctx, 0));
    // 0x12cb18: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x12cb18u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12cb1c: 0xae40004c  sw          $zero, 0x4C($s2)
    ctx->pc = 0x12cb1cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 76), GPR_U32(ctx, 0));
    // 0x12cb20: 0xae400050  sw          $zero, 0x50($s2)
    ctx->pc = 0x12cb20u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 80), GPR_U32(ctx, 0));
    // 0x12cb24: 0xae400054  sw          $zero, 0x54($s2)
    ctx->pc = 0x12cb24u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 84), GPR_U32(ctx, 0));
    // 0x12cb28: 0xa2420000  sb          $v0, 0x0($s2)
    ctx->pc = 0x12cb28u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x12cb2c: 0x240102d  daddu       $v0, $s2, $zero
    ctx->pc = 0x12cb2cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_12cb30:
    // 0x12cb30: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12cb30u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12cb34: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12cb34u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12cb38: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x12cb38u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12cb3c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x12cb3cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12cb40: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x12cb40u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12cb44: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x12cb44u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x12cb48: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x12cb48u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12cb4c: 0x3e00008  jr          $ra
    ctx->pc = 0x12CB4Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12CB50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12CB4Cu;
            // 0x12cb50: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12CA20u: goto label_12ca20;
            case 0x12CA44u: goto label_12ca44;
            case 0x12CA74u: goto label_12ca74;
            case 0x12CA80u: goto label_12ca80;
            case 0x12CA90u: goto label_12ca90;
            case 0x12CAB4u: goto label_12cab4;
            case 0x12CAD0u: goto label_12cad0;
            case 0x12CAE8u: goto label_12cae8;
            case 0x12CB08u: goto label_12cb08;
            case 0x12CB14u: goto label_12cb14;
            case 0x12CB30u: goto label_12cb30;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12CB54u;
    // 0x12cb54: 0x0  nop
    ctx->pc = 0x12cb54u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
