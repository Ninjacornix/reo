#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013ED28
// Address: 0x13ed28 - 0x13f1a0
void sub_0013ED28_0x13ed28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013ED28_0x13ed28");
#endif

    switch (ctx->pc) {
        case 0x13ed78u: goto label_13ed78;
        case 0x13ed80u: goto label_13ed80;
        case 0x13eda0u: goto label_13eda0;
        case 0x13edf0u: goto label_13edf0;
        case 0x13ee10u: goto label_13ee10;
        case 0x13ee2cu: goto label_13ee2c;
        case 0x13ee50u: goto label_13ee50;
        case 0x13ee68u: goto label_13ee68;
        case 0x13eea4u: goto label_13eea4;
        case 0x13eeb4u: goto label_13eeb4;
        case 0x13ef08u: goto label_13ef08;
        case 0x13ef10u: goto label_13ef10;
        case 0x13ef24u: goto label_13ef24;
        case 0x13ef38u: goto label_13ef38;
        case 0x13ef40u: goto label_13ef40;
        case 0x13ef78u: goto label_13ef78;
        case 0x13efb4u: goto label_13efb4;
        case 0x13efb8u: goto label_13efb8;
        case 0x13f008u: goto label_13f008;
        case 0x13f0ccu: goto label_13f0cc;
        case 0x13f0e0u: goto label_13f0e0;
        case 0x13f0e8u: goto label_13f0e8;
        case 0x13f0f0u: goto label_13f0f0;
        case 0x13f100u: goto label_13f100;
        case 0x13f11cu: goto label_13f11c;
        case 0x13f16cu: goto label_13f16c;
        default: break;
    }

    ctx->pc = 0x13ed28u;

label_13ed28:
    // 0x13ed28: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x13ed28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x13ed2c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x13ed2cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13ed30: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x13ed30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x13ed34: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x13ed34u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ed38: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x13ed38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x13ed3c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x13ed3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x13ed40: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x13ed40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x13ed44: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x13ed44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x13ed48: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x13ed48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x13ed4c: 0x82220050  lb          $v0, 0x50($s1)
    ctx->pc = 0x13ed4cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 80)));
    // 0x13ed50: 0x1443005d  bne         $v0, $v1, . + 4 + (0x5D << 2)
    ctx->pc = 0x13ED50u;
    {
        const bool branch_taken_0x13ed50 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x13ED54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13ED50u;
            // 0x13ed54: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ed50) {
            ctx->pc = 0x13EEC8u;
            goto label_13eec8;
        }
    }
    ctx->pc = 0x13ED58u;
    // 0x13ed58: 0x82220026  lb          $v0, 0x26($s1)
    ctx->pc = 0x13ed58u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 38)));
    // 0x13ed5c: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x13ed5cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ed60: 0x92230026  lbu         $v1, 0x26($s1)
    ctx->pc = 0x13ed60u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 38)));
    // 0x13ed64: 0x18400018  blez        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x13ED64u;
    {
        const bool branch_taken_0x13ed64 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x13ED68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13ED64u;
            // 0x13ed68: 0x982d  daddu       $s3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ed64) {
            ctx->pc = 0x13EDC8u;
            goto label_13edc8;
        }
    }
    ctx->pc = 0x13ED6Cu;
    // 0x13ed6c: 0x24140001  addiu       $s4, $zero, 0x1
    ctx->pc = 0x13ed6cu;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13ed70: 0x26300008  addiu       $s0, $s1, 0x8
    ctx->pc = 0x13ed70u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 8));
    // 0x13ed74: 0x0  nop
    ctx->pc = 0x13ed74u;
    // NOP
label_13ed78:
    // 0x13ed78: 0xc04e274  jal         func_1389D0
    ctx->pc = 0x13ED78u;
    SET_GPR_U32(ctx, 31, 0x13ED80u);
    ctx->pc = 0x13ED7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13ED78u;
            // 0x13ed7c: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1389D0u;
    if (runtime->hasFunction(0x1389D0u)) {
        auto targetFn = runtime->lookupFunction(0x1389D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13ED80u; }
        if (ctx->pc != 0x13ED80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001389D0_0x1389d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13ED80u; }
        if (ctx->pc != 0x13ED80u) { return; }
    }
    ctx->pc = 0x13ED80u;
label_13ed80:
    // 0x13ed80: 0x1054000b  beq         $v0, $s4, . + 4 + (0xB << 2)
    ctx->pc = 0x13ED80u;
    {
        const bool branch_taken_0x13ed80 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 20));
        ctx->pc = 0x13ED84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13ED80u;
            // 0x13ed84: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ed80) {
            ctx->pc = 0x13EDB0u;
            goto label_13edb0;
        }
    }
    ctx->pc = 0x13ED88u;
    // 0x13ed88: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x13ed88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13ed8c: 0x8c440008  lw          $a0, 0x8($v0)
    ctx->pc = 0x13ed8cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x13ed90: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x13ed90u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x13ed94: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x13ed94u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x13ed98: 0x40f809  jalr        $v0
    ctx->pc = 0x13ED98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13EDA0u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x13EDA0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13ED28u: goto label_13ed28;
            case 0x13ED78u: goto label_13ed78;
            case 0x13ED80u: goto label_13ed80;
            case 0x13EDA0u: goto label_13eda0;
            case 0x13EDB0u: goto label_13edb0;
            case 0x13EDC8u: goto label_13edc8;
            case 0x13EDF0u: goto label_13edf0;
            case 0x13EE10u: goto label_13ee10;
            case 0x13EE2Cu: goto label_13ee2c;
            case 0x13EE50u: goto label_13ee50;
            case 0x13EE68u: goto label_13ee68;
            case 0x13EE88u: goto label_13ee88;
            case 0x13EEA4u: goto label_13eea4;
            case 0x13EEB4u: goto label_13eeb4;
            case 0x13EEC8u: goto label_13eec8;
            case 0x13EF08u: goto label_13ef08;
            case 0x13EF10u: goto label_13ef10;
            case 0x13EF24u: goto label_13ef24;
            case 0x13EF28u: goto label_13ef28;
            case 0x13EF38u: goto label_13ef38;
            case 0x13EF40u: goto label_13ef40;
            case 0x13EF78u: goto label_13ef78;
            case 0x13EF9Cu: goto label_13ef9c;
            case 0x13EFB4u: goto label_13efb4;
            case 0x13EFB8u: goto label_13efb8;
            case 0x13EFD8u: goto label_13efd8;
            case 0x13EFECu: goto label_13efec;
            case 0x13F008u: goto label_13f008;
            case 0x13F028u: goto label_13f028;
            case 0x13F02Cu: goto label_13f02c;
            case 0x13F0A8u: goto label_13f0a8;
            case 0x13F0CCu: goto label_13f0cc;
            case 0x13F0E0u: goto label_13f0e0;
            case 0x13F0E8u: goto label_13f0e8;
            case 0x13F0F0u: goto label_13f0f0;
            case 0x13F100u: goto label_13f100;
            case 0x13F11Cu: goto label_13f11c;
            case 0x13F16Cu: goto label_13f16c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13EDA0u; }
            if (ctx->pc != 0x13EDA0u) { return; }
        }
        }
    }
    ctx->pc = 0x13EDA0u;
label_13eda0:
    // 0x13eda0: 0x8e23005c  lw          $v1, 0x5C($s1)
    ctx->pc = 0x13eda0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 92)));
    // 0x13eda4: 0x26440001  addiu       $a0, $s2, 0x1
    ctx->pc = 0x13eda4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x13eda8: 0x431026  xor         $v0, $v0, $v1
    ctx->pc = 0x13eda8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ GPR_U64(ctx, 3));
    // 0x13edac: 0x82900a  movz        $s2, $a0, $v0
    ctx->pc = 0x13edacu;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 18, GPR_VEC(ctx, 4));
label_13edb0:
    // 0x13edb0: 0x82220026  lb          $v0, 0x26($s1)
    ctx->pc = 0x13edb0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 38)));
    // 0x13edb4: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x13edb4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x13edb8: 0x26100004  addiu       $s0, $s0, 0x4
    ctx->pc = 0x13edb8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x13edbc: 0x262102a  slt         $v0, $s3, $v0
    ctx->pc = 0x13edbcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x13edc0: 0x1440ffed  bnez        $v0, . + 4 + (-0x13 << 2)
    ctx->pc = 0x13EDC0u;
    {
        const bool branch_taken_0x13edc0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13EDC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EDC0u;
            // 0x13edc4: 0x92230026  lbu         $v1, 0x26($s1) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 38)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13edc0) {
            ctx->pc = 0x13ED78u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13ed78;
        }
    }
    ctx->pc = 0x13EDC8u;
label_13edc8:
    // 0x13edc8: 0x31600  sll         $v0, $v1, 24
    ctx->pc = 0x13edc8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x13edcc: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x13edccu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x13edd0: 0x1642003d  bne         $s2, $v0, . + 4 + (0x3D << 2)
    ctx->pc = 0x13EDD0u;
    {
        const bool branch_taken_0x13edd0 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 2));
        ctx->pc = 0x13EDD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EDD0u;
            // 0x13edd4: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13edd0) {
            ctx->pc = 0x13EEC8u;
            goto label_13eec8;
        }
    }
    ctx->pc = 0x13EDD8u;
    // 0x13edd8: 0x1a40003b  blez        $s2, . + 4 + (0x3B << 2)
    ctx->pc = 0x13EDD8u;
    {
        const bool branch_taken_0x13edd8 = (GPR_S64(ctx, 18) <= 0);
        ctx->pc = 0x13EDDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EDD8u;
            // 0x13eddc: 0x982d  daddu       $s3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13edd8) {
            ctx->pc = 0x13EEC8u;
            goto label_13eec8;
        }
    }
    ctx->pc = 0x13EDE0u;
    // 0x13ede0: 0x26320010  addiu       $s2, $s1, 0x10
    ctx->pc = 0x13ede0u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 17), 16));
    // 0x13ede4: 0x26300008  addiu       $s0, $s1, 0x8
    ctx->pc = 0x13ede4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 8));
    // 0x13ede8: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x13ede8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13edec: 0x0  nop
    ctx->pc = 0x13edecu;
    // NOP
label_13edf0:
    // 0x13edf0: 0x3c067fff  lui         $a2, 0x7FFF
    ctx->pc = 0x13edf0u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)32767 << 16));
    // 0x13edf4: 0x3a0382d  daddu       $a3, $sp, $zero
    ctx->pc = 0x13edf4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13edf8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13edf8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13edfc: 0x8c440008  lw          $a0, 0x8($v0)
    ctx->pc = 0x13edfcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x13ee00: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x13ee00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x13ee04: 0x8c620018  lw          $v0, 0x18($v1)
    ctx->pc = 0x13ee04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x13ee08: 0x40f809  jalr        $v0
    ctx->pc = 0x13EE08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13EE10u);
        ctx->pc = 0x13EE0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EE08u;
            // 0x13ee0c: 0x34c6ffff  ori         $a2, $a2, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13EE10u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13ED28u: goto label_13ed28;
            case 0x13ED78u: goto label_13ed78;
            case 0x13ED80u: goto label_13ed80;
            case 0x13EDA0u: goto label_13eda0;
            case 0x13EDB0u: goto label_13edb0;
            case 0x13EDC8u: goto label_13edc8;
            case 0x13EDF0u: goto label_13edf0;
            case 0x13EE10u: goto label_13ee10;
            case 0x13EE2Cu: goto label_13ee2c;
            case 0x13EE50u: goto label_13ee50;
            case 0x13EE68u: goto label_13ee68;
            case 0x13EE88u: goto label_13ee88;
            case 0x13EEA4u: goto label_13eea4;
            case 0x13EEB4u: goto label_13eeb4;
            case 0x13EEC8u: goto label_13eec8;
            case 0x13EF08u: goto label_13ef08;
            case 0x13EF10u: goto label_13ef10;
            case 0x13EF24u: goto label_13ef24;
            case 0x13EF28u: goto label_13ef28;
            case 0x13EF38u: goto label_13ef38;
            case 0x13EF40u: goto label_13ef40;
            case 0x13EF78u: goto label_13ef78;
            case 0x13EF9Cu: goto label_13ef9c;
            case 0x13EFB4u: goto label_13efb4;
            case 0x13EFB8u: goto label_13efb8;
            case 0x13EFD8u: goto label_13efd8;
            case 0x13EFECu: goto label_13efec;
            case 0x13F008u: goto label_13f008;
            case 0x13F028u: goto label_13f028;
            case 0x13F02Cu: goto label_13f02c;
            case 0x13F0A8u: goto label_13f0a8;
            case 0x13F0CCu: goto label_13f0cc;
            case 0x13F0E0u: goto label_13f0e0;
            case 0x13F0E8u: goto label_13f0e8;
            case 0x13F0F0u: goto label_13f0f0;
            case 0x13F100u: goto label_13f100;
            case 0x13F11Cu: goto label_13f11c;
            case 0x13F16Cu: goto label_13f16c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13EE10u; }
            if (ctx->pc != 0x13EE10u) { return; }
        }
        }
    }
    ctx->pc = 0x13EE10u;
label_13ee10:
    // 0x13ee10: 0x8e070000  lw          $a3, 0x0($s0)
    ctx->pc = 0x13ee10u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13ee14: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x13ee14u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ee18: 0x8ce40008  lw          $a0, 0x8($a3)
    ctx->pc = 0x13ee18u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 8)));
    // 0x13ee1c: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x13ee1cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x13ee20: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x13ee20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x13ee24: 0x40f809  jalr        $v0
    ctx->pc = 0x13EE24u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13EE2Cu);
        ctx->pc = 0x13EE28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EE24u;
            // 0x13ee28: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13EE2Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13ED28u: goto label_13ed28;
            case 0x13ED78u: goto label_13ed78;
            case 0x13ED80u: goto label_13ed80;
            case 0x13EDA0u: goto label_13eda0;
            case 0x13EDB0u: goto label_13edb0;
            case 0x13EDC8u: goto label_13edc8;
            case 0x13EDF0u: goto label_13edf0;
            case 0x13EE10u: goto label_13ee10;
            case 0x13EE2Cu: goto label_13ee2c;
            case 0x13EE50u: goto label_13ee50;
            case 0x13EE68u: goto label_13ee68;
            case 0x13EE88u: goto label_13ee88;
            case 0x13EEA4u: goto label_13eea4;
            case 0x13EEB4u: goto label_13eeb4;
            case 0x13EEC8u: goto label_13eec8;
            case 0x13EF08u: goto label_13ef08;
            case 0x13EF10u: goto label_13ef10;
            case 0x13EF24u: goto label_13ef24;
            case 0x13EF28u: goto label_13ef28;
            case 0x13EF38u: goto label_13ef38;
            case 0x13EF40u: goto label_13ef40;
            case 0x13EF78u: goto label_13ef78;
            case 0x13EF9Cu: goto label_13ef9c;
            case 0x13EFB4u: goto label_13efb4;
            case 0x13EFB8u: goto label_13efb8;
            case 0x13EFD8u: goto label_13efd8;
            case 0x13EFECu: goto label_13efec;
            case 0x13F008u: goto label_13f008;
            case 0x13F028u: goto label_13f028;
            case 0x13F02Cu: goto label_13f02c;
            case 0x13F0A8u: goto label_13f0a8;
            case 0x13F0CCu: goto label_13f0cc;
            case 0x13F0E0u: goto label_13f0e0;
            case 0x13F0E8u: goto label_13f0e8;
            case 0x13F0F0u: goto label_13f0f0;
            case 0x13F100u: goto label_13f100;
            case 0x13F11Cu: goto label_13f11c;
            case 0x13F16Cu: goto label_13f16c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13EE2Cu; }
            if (ctx->pc != 0x13EE2Cu) { return; }
        }
        }
    }
    ctx->pc = 0x13EE2Cu;
label_13ee2c:
    // 0x13ee2c: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x13ee2cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13ee30: 0x3c067fff  lui         $a2, 0x7FFF
    ctx->pc = 0x13ee30u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)32767 << 16));
    // 0x13ee34: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13ee34u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ee38: 0x8c640008  lw          $a0, 0x8($v1)
    ctx->pc = 0x13ee38u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x13ee3c: 0x34c6ffff  ori         $a2, $a2, 0xFFFF
    ctx->pc = 0x13ee3cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)65535);
    // 0x13ee40: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x13ee40u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x13ee44: 0x8c620018  lw          $v0, 0x18($v1)
    ctx->pc = 0x13ee44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x13ee48: 0x40f809  jalr        $v0
    ctx->pc = 0x13EE48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13EE50u);
        ctx->pc = 0x13EE4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EE48u;
            // 0x13ee4c: 0x3a0382d  daddu       $a3, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13EE50u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13ED28u: goto label_13ed28;
            case 0x13ED78u: goto label_13ed78;
            case 0x13ED80u: goto label_13ed80;
            case 0x13EDA0u: goto label_13eda0;
            case 0x13EDB0u: goto label_13edb0;
            case 0x13EDC8u: goto label_13edc8;
            case 0x13EDF0u: goto label_13edf0;
            case 0x13EE10u: goto label_13ee10;
            case 0x13EE2Cu: goto label_13ee2c;
            case 0x13EE50u: goto label_13ee50;
            case 0x13EE68u: goto label_13ee68;
            case 0x13EE88u: goto label_13ee88;
            case 0x13EEA4u: goto label_13eea4;
            case 0x13EEB4u: goto label_13eeb4;
            case 0x13EEC8u: goto label_13eec8;
            case 0x13EF08u: goto label_13ef08;
            case 0x13EF10u: goto label_13ef10;
            case 0x13EF24u: goto label_13ef24;
            case 0x13EF28u: goto label_13ef28;
            case 0x13EF38u: goto label_13ef38;
            case 0x13EF40u: goto label_13ef40;
            case 0x13EF78u: goto label_13ef78;
            case 0x13EF9Cu: goto label_13ef9c;
            case 0x13EFB4u: goto label_13efb4;
            case 0x13EFB8u: goto label_13efb8;
            case 0x13EFD8u: goto label_13efd8;
            case 0x13EFECu: goto label_13efec;
            case 0x13F008u: goto label_13f008;
            case 0x13F028u: goto label_13f028;
            case 0x13F02Cu: goto label_13f02c;
            case 0x13F0A8u: goto label_13f0a8;
            case 0x13F0CCu: goto label_13f0cc;
            case 0x13F0E0u: goto label_13f0e0;
            case 0x13F0E8u: goto label_13f0e8;
            case 0x13F0F0u: goto label_13f0f0;
            case 0x13F100u: goto label_13f100;
            case 0x13F11Cu: goto label_13f11c;
            case 0x13F16Cu: goto label_13f16c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13EE50u; }
            if (ctx->pc != 0x13EE50u) { return; }
        }
        }
    }
    ctx->pc = 0x13EE50u;
label_13ee50:
    // 0x13ee50: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13ee50u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ee54: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x13ee54u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x13ee58: 0x8e22005c  lw          $v0, 0x5C($s1)
    ctx->pc = 0x13ee58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 92)));
    // 0x13ee5c: 0x1062000a  beq         $v1, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x13EE5Cu;
    {
        const bool branch_taken_0x13ee5c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x13EE60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EE5Cu;
            // 0x13ee60: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ee5c) {
            ctx->pc = 0x13EE88u;
            goto label_13ee88;
        }
    }
    ctx->pc = 0x13EE64u;
    // 0x13ee64: 0x0  nop
    ctx->pc = 0x13ee64u;
    // NOP
label_13ee68:
    // 0x13ee68: 0x0  nop
    ctx->pc = 0x13ee68u;
    // NOP
    // 0x13ee6c: 0x0  nop
    ctx->pc = 0x13ee6cu;
    // NOP
    // 0x13ee70: 0x0  nop
    ctx->pc = 0x13ee70u;
    // NOP
    // 0x13ee74: 0x0  nop
    ctx->pc = 0x13ee74u;
    // NOP
    // 0x13ee78: 0x0  nop
    ctx->pc = 0x13ee78u;
    // NOP
    // 0x13ee7c: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x13EE7Cu;
    {
        const bool branch_taken_0x13ee7c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x13ee7c) {
            ctx->pc = 0x13EE68u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13ee68;
        }
    }
    ctx->pc = 0x13EE84u;
    // 0x13ee84: 0x0  nop
    ctx->pc = 0x13ee84u;
    // NOP
label_13ee88:
    // 0x13ee88: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x13ee88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13ee8c: 0x26100004  addiu       $s0, $s0, 0x4
    ctx->pc = 0x13ee8cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x13ee90: 0x8c440008  lw          $a0, 0x8($v0)
    ctx->pc = 0x13ee90u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x13ee94: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x13ee94u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x13ee98: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x13ee98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x13ee9c: 0x40f809  jalr        $v0
    ctx->pc = 0x13EE9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13EEA4u);
        ctx->pc = 0x13EEA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EE9Cu;
            // 0x13eea0: 0x26730001  addiu       $s3, $s3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13EEA4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13ED28u: goto label_13ed28;
            case 0x13ED78u: goto label_13ed78;
            case 0x13ED80u: goto label_13ed80;
            case 0x13EDA0u: goto label_13eda0;
            case 0x13EDB0u: goto label_13edb0;
            case 0x13EDC8u: goto label_13edc8;
            case 0x13EDF0u: goto label_13edf0;
            case 0x13EE10u: goto label_13ee10;
            case 0x13EE2Cu: goto label_13ee2c;
            case 0x13EE50u: goto label_13ee50;
            case 0x13EE68u: goto label_13ee68;
            case 0x13EE88u: goto label_13ee88;
            case 0x13EEA4u: goto label_13eea4;
            case 0x13EEB4u: goto label_13eeb4;
            case 0x13EEC8u: goto label_13eec8;
            case 0x13EF08u: goto label_13ef08;
            case 0x13EF10u: goto label_13ef10;
            case 0x13EF24u: goto label_13ef24;
            case 0x13EF28u: goto label_13ef28;
            case 0x13EF38u: goto label_13ef38;
            case 0x13EF40u: goto label_13ef40;
            case 0x13EF78u: goto label_13ef78;
            case 0x13EF9Cu: goto label_13ef9c;
            case 0x13EFB4u: goto label_13efb4;
            case 0x13EFB8u: goto label_13efb8;
            case 0x13EFD8u: goto label_13efd8;
            case 0x13EFECu: goto label_13efec;
            case 0x13F008u: goto label_13f008;
            case 0x13F028u: goto label_13f028;
            case 0x13F02Cu: goto label_13f02c;
            case 0x13F0A8u: goto label_13f0a8;
            case 0x13F0CCu: goto label_13f0cc;
            case 0x13F0E0u: goto label_13f0e0;
            case 0x13F0E8u: goto label_13f0e8;
            case 0x13F0F0u: goto label_13f0f0;
            case 0x13F100u: goto label_13f100;
            case 0x13F11Cu: goto label_13f11c;
            case 0x13F16Cu: goto label_13f16c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13EEA4u; }
            if (ctx->pc != 0x13EEA4u) { return; }
        }
        }
    }
    ctx->pc = 0x13EEA4u;
label_13eea4:
    // 0x13eea4: 0xa2200053  sb          $zero, 0x53($s1)
    ctx->pc = 0x13eea4u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 83), (uint8_t)GPR_U32(ctx, 0));
    // 0x13eea8: 0x8e440000  lw          $a0, 0x0($s2)
    ctx->pc = 0x13eea8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x13eeac: 0xc04e2f4  jal         func_138BD0
    ctx->pc = 0x13EEACu;
    SET_GPR_U32(ctx, 31, 0x13EEB4u);
    ctx->pc = 0x13EEB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13EEACu;
            // 0x13eeb0: 0x26520004  addiu       $s2, $s2, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138BD0u;
    if (runtime->hasFunction(0x138BD0u)) {
        auto targetFn = runtime->lookupFunction(0x138BD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EEB4u; }
        if (ctx->pc != 0x13EEB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138BD0_0x138bd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EEB4u; }
        if (ctx->pc != 0x13EEB4u) { return; }
    }
    ctx->pc = 0x13EEB4u;
label_13eeb4:
    // 0x13eeb4: 0x82220026  lb          $v0, 0x26($s1)
    ctx->pc = 0x13eeb4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 38)));
    // 0x13eeb8: 0x262102a  slt         $v0, $s3, $v0
    ctx->pc = 0x13eeb8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x13eebc: 0x5440ffcc  bnel        $v0, $zero, . + 4 + (-0x34 << 2)
    ctx->pc = 0x13EEBCu;
    {
        const bool branch_taken_0x13eebc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x13eebc) {
            ctx->pc = 0x13EEC0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13EEBCu;
            // 0x13eec0: 0x8e020000  lw          $v0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13EDF0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13edf0;
        }
    }
    ctx->pc = 0x13EEC4u;
    // 0x13eec4: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x13eec4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_13eec8:
    // 0x13eec8: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x13eec8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13eecc: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x13eeccu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13eed0: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x13eed0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x13eed4: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x13eed4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x13eed8: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x13eed8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x13eedc: 0x3e00008  jr          $ra
    ctx->pc = 0x13EEDCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13EEE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EEDCu;
            // 0x13eee0: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13ED28u: goto label_13ed28;
            case 0x13ED78u: goto label_13ed78;
            case 0x13ED80u: goto label_13ed80;
            case 0x13EDA0u: goto label_13eda0;
            case 0x13EDB0u: goto label_13edb0;
            case 0x13EDC8u: goto label_13edc8;
            case 0x13EDF0u: goto label_13edf0;
            case 0x13EE10u: goto label_13ee10;
            case 0x13EE2Cu: goto label_13ee2c;
            case 0x13EE50u: goto label_13ee50;
            case 0x13EE68u: goto label_13ee68;
            case 0x13EE88u: goto label_13ee88;
            case 0x13EEA4u: goto label_13eea4;
            case 0x13EEB4u: goto label_13eeb4;
            case 0x13EEC8u: goto label_13eec8;
            case 0x13EF08u: goto label_13ef08;
            case 0x13EF10u: goto label_13ef10;
            case 0x13EF24u: goto label_13ef24;
            case 0x13EF28u: goto label_13ef28;
            case 0x13EF38u: goto label_13ef38;
            case 0x13EF40u: goto label_13ef40;
            case 0x13EF78u: goto label_13ef78;
            case 0x13EF9Cu: goto label_13ef9c;
            case 0x13EFB4u: goto label_13efb4;
            case 0x13EFB8u: goto label_13efb8;
            case 0x13EFD8u: goto label_13efd8;
            case 0x13EFECu: goto label_13efec;
            case 0x13F008u: goto label_13f008;
            case 0x13F028u: goto label_13f028;
            case 0x13F02Cu: goto label_13f02c;
            case 0x13F0A8u: goto label_13f0a8;
            case 0x13F0CCu: goto label_13f0cc;
            case 0x13F0E0u: goto label_13f0e0;
            case 0x13F0E8u: goto label_13f0e8;
            case 0x13F0F0u: goto label_13f0f0;
            case 0x13F100u: goto label_13f100;
            case 0x13F11Cu: goto label_13f11c;
            case 0x13F16Cu: goto label_13f16c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13EEE4u;
    // 0x13eee4: 0x0  nop
    ctx->pc = 0x13eee4u;
    // NOP
    // 0x13eee8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x13eee8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13eeec: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13eeecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13eef0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13eef0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13eef4: 0x2411000f  addiu       $s1, $zero, 0xF
    ctx->pc = 0x13eef4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x13eef8: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13eef8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13eefc: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x13eefcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x13ef00: 0xc04fc86  jal         func_13F218
    ctx->pc = 0x13EF00u;
    SET_GPR_U32(ctx, 31, 0x13EF08u);
    ctx->pc = 0x13EF04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13EF00u;
            // 0x13ef04: 0x24120001  addiu       $s2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F218u;
    if (runtime->hasFunction(0x13F218u)) {
        auto targetFn = runtime->lookupFunction(0x13F218u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EF08u; }
        if (ctx->pc != 0x13EF08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F218_0x13f218(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EF08u; }
        if (ctx->pc != 0x13EF08u) { return; }
    }
    ctx->pc = 0x13EF08u;
label_13ef08:
    // 0x13ef08: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13ef08u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13ef0c: 0x24503880  addiu       $s0, $v0, 0x3880
    ctx->pc = 0x13ef0cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 14464));
label_13ef10:
    // 0x13ef10: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x13ef10u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13ef14: 0x54520004  bnel        $v0, $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x13EF14u;
    {
        const bool branch_taken_0x13ef14 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 18));
        if (branch_taken_0x13ef14) {
            ctx->pc = 0x13EF18u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13EF14u;
            // 0x13ef18: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13EF28u;
            goto label_13ef28;
        }
    }
    ctx->pc = 0x13EF1Cu;
    // 0x13ef1c: 0xc04fb4a  jal         func_13ED28
    ctx->pc = 0x13EF1Cu;
    SET_GPR_U32(ctx, 31, 0x13EF24u);
    ctx->pc = 0x13EF20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13EF1Cu;
            // 0x13ef20: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13ED28u;
    goto label_13ed28;
    ctx->pc = 0x13EF24u;
label_13ef24:
    // 0x13ef24: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x13ef24u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_13ef28:
    // 0x13ef28: 0x621fff9  bgez        $s1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x13EF28u;
    {
        const bool branch_taken_0x13ef28 = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x13EF2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EF28u;
            // 0x13ef2c: 0x26100060  addiu       $s0, $s0, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 96));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ef28) {
            ctx->pc = 0x13EF10u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13ef10;
        }
    }
    ctx->pc = 0x13EF30u;
    // 0x13ef30: 0xc04fc8c  jal         func_13F230
    ctx->pc = 0x13EF30u;
    SET_GPR_U32(ctx, 31, 0x13EF38u);
    ctx->pc = 0x13F230u;
    if (runtime->hasFunction(0x13F230u)) {
        auto targetFn = runtime->lookupFunction(0x13F230u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EF38u; }
        if (ctx->pc != 0x13EF38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F230_0x13f230(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EF38u; }
        if (ctx->pc != 0x13EF38u) { return; }
    }
    ctx->pc = 0x13EF38u;
label_13ef38:
    // 0x13ef38: 0xc04e276  jal         func_1389D8
    ctx->pc = 0x13EF38u;
    SET_GPR_U32(ctx, 31, 0x13EF40u);
    ctx->pc = 0x1389D8u;
    if (runtime->hasFunction(0x1389D8u)) {
        auto targetFn = runtime->lookupFunction(0x1389D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EF40u; }
        if (ctx->pc != 0x13EF40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001389D8_0x1389d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EF40u; }
        if (ctx->pc != 0x13EF40u) { return; }
    }
    ctx->pc = 0x13EF40u;
label_13ef40:
    // 0x13ef40: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13ef40u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13ef44: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13ef44u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13ef48: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13ef48u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13ef4c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x13ef4cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13ef50: 0x805049a  j           func_141268
    ctx->pc = 0x13EF50u;
    ctx->pc = 0x13EF54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13EF50u;
            // 0x13ef54: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141268u;
    if (runtime->hasFunction(0x141268u)) {
        auto targetFn = runtime->lookupFunction(0x141268u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00141268_0x141268(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13EF58u;
    // 0x13ef58: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13ef58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13ef5c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13ef5cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13ef60: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13ef60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13ef64: 0x2484d898  addiu       $a0, $a0, -0x2768
    ctx->pc = 0x13ef64u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957208));
    // 0x13ef68: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13ef68u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13ef6c: 0x8045a12  j           func_116848
    ctx->pc = 0x13EF6Cu;
    ctx->pc = 0x13EF70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13EF6Cu;
            // 0x13ef70: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00116848_0x116848(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13EF74u;
    // 0x13ef74: 0x0  nop
    ctx->pc = 0x13ef74u;
    // NOP
label_13ef78:
    // 0x13ef78: 0x3e00008  jr          $ra
    ctx->pc = 0x13EF78u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13EF7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EF78u;
            // 0x13ef7c: 0xa0850026  sb          $a1, 0x26($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 38), (uint8_t)GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13ED28u: goto label_13ed28;
            case 0x13ED78u: goto label_13ed78;
            case 0x13ED80u: goto label_13ed80;
            case 0x13EDA0u: goto label_13eda0;
            case 0x13EDB0u: goto label_13edb0;
            case 0x13EDC8u: goto label_13edc8;
            case 0x13EDF0u: goto label_13edf0;
            case 0x13EE10u: goto label_13ee10;
            case 0x13EE2Cu: goto label_13ee2c;
            case 0x13EE50u: goto label_13ee50;
            case 0x13EE68u: goto label_13ee68;
            case 0x13EE88u: goto label_13ee88;
            case 0x13EEA4u: goto label_13eea4;
            case 0x13EEB4u: goto label_13eeb4;
            case 0x13EEC8u: goto label_13eec8;
            case 0x13EF08u: goto label_13ef08;
            case 0x13EF10u: goto label_13ef10;
            case 0x13EF24u: goto label_13ef24;
            case 0x13EF28u: goto label_13ef28;
            case 0x13EF38u: goto label_13ef38;
            case 0x13EF40u: goto label_13ef40;
            case 0x13EF78u: goto label_13ef78;
            case 0x13EF9Cu: goto label_13ef9c;
            case 0x13EFB4u: goto label_13efb4;
            case 0x13EFB8u: goto label_13efb8;
            case 0x13EFD8u: goto label_13efd8;
            case 0x13EFECu: goto label_13efec;
            case 0x13F008u: goto label_13f008;
            case 0x13F028u: goto label_13f028;
            case 0x13F02Cu: goto label_13f02c;
            case 0x13F0A8u: goto label_13f0a8;
            case 0x13F0CCu: goto label_13f0cc;
            case 0x13F0E0u: goto label_13f0e0;
            case 0x13F0E8u: goto label_13f0e8;
            case 0x13F0F0u: goto label_13f0f0;
            case 0x13F100u: goto label_13f100;
            case 0x13F11Cu: goto label_13f11c;
            case 0x13F16Cu: goto label_13f16c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13EF80u;
    // 0x13ef80: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x13ef80u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ef84: 0x3402bb80  ori         $v0, $zero, 0xBB80
    ctx->pc = 0x13ef84u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)48000);
    // 0x13ef88: 0x46001a  div         $zero, $v0, $a2
    ctx->pc = 0x13ef88u;
    { int32_t divisor = GPR_S32(ctx, 6);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x13ef8c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13ef8cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13ef90: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13ef90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13ef94: 0x50c00001  beql        $a2, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x13EF94u;
    {
        const bool branch_taken_0x13ef94 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x13ef94) {
            ctx->pc = 0x13EF98u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13EF94u;
            // 0x13ef98: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x13EF9Cu;
            goto label_13ef9c;
        }
    }
    ctx->pc = 0x13EF9Cu;
label_13ef9c:
    // 0x13ef9c: 0x1810  mfhi        $v1
    ctx->pc = 0x13ef9cu;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x13efa0: 0x5060000d  beql        $v1, $zero, . + 4 + (0xD << 2)
    ctx->pc = 0x13EFA0u;
    {
        const bool branch_taken_0x13efa0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x13efa0) {
            ctx->pc = 0x13EFA4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13EFA0u;
            // 0x13efa4: 0x3402bb80  ori         $v0, $zero, 0xBB80 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)48000);
        ctx->in_delay_slot = false;
            ctx->pc = 0x13EFD8u;
            goto label_13efd8;
        }
    }
    ctx->pc = 0x13EFA8u;
    // 0x13efa8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13efa8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13efac: 0xc045a12  jal         func_116848
    ctx->pc = 0x13EFACu;
    SET_GPR_U32(ctx, 31, 0x13EFB4u);
    ctx->pc = 0x13EFB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13EFACu;
            // 0x13efb0: 0x2484d8c0  addiu       $a0, $a0, -0x2740 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957248));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EFB4u; }
        if (ctx->pc != 0x13EFB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EFB4u; }
        if (ctx->pc != 0x13EFB4u) { return; }
    }
    ctx->pc = 0x13EFB4u;
label_13efb4:
    // 0x13efb4: 0x0  nop
    ctx->pc = 0x13efb4u;
    // NOP
label_13efb8:
    // 0x13efb8: 0x0  nop
    ctx->pc = 0x13efb8u;
    // NOP
    // 0x13efbc: 0x0  nop
    ctx->pc = 0x13efbcu;
    // NOP
    // 0x13efc0: 0x0  nop
    ctx->pc = 0x13efc0u;
    // NOP
    // 0x13efc4: 0x0  nop
    ctx->pc = 0x13efc4u;
    // NOP
    // 0x13efc8: 0x0  nop
    ctx->pc = 0x13efc8u;
    // NOP
    // 0x13efcc: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x13EFCCu;
    {
        const bool branch_taken_0x13efcc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x13efcc) {
            ctx->pc = 0x13EFB8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13efb8;
        }
    }
    ctx->pc = 0x13EFD4u;
    // 0x13efd4: 0x0  nop
    ctx->pc = 0x13efd4u;
    // NOP
label_13efd8:
    // 0x13efd8: 0x10c20014  beq         $a2, $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x13EFD8u;
    {
        const bool branch_taken_0x13efd8 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 2));
        ctx->pc = 0x13EFDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EFD8u;
            // 0x13efdc: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13efd8) {
            ctx->pc = 0x13F02Cu;
            goto label_13f02c;
        }
    }
    ctx->pc = 0x13EFE0u;
    // 0x13efe0: 0x46001a  div         $zero, $v0, $a2
    ctx->pc = 0x13efe0u;
    { int32_t divisor = GPR_S32(ctx, 6);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x13efe4: 0x50c00001  beql        $a2, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x13EFE4u;
    {
        const bool branch_taken_0x13efe4 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x13efe4) {
            ctx->pc = 0x13EFE8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13EFE4u;
            // 0x13efe8: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x13EFECu;
            goto label_13efec;
        }
    }
    ctx->pc = 0x13EFECu;
label_13efec:
    // 0x13efec: 0x1012  mflo        $v0
    ctx->pc = 0x13efecu;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x13eff0: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x13eff0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x13eff4: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x13EFF4u;
    {
        const bool branch_taken_0x13eff4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13EFF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EFF4u;
            // 0x13eff8: 0xc0282d  daddu       $a1, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13eff4) {
            ctx->pc = 0x13F028u;
            goto label_13f028;
        }
    }
    ctx->pc = 0x13EFFCu;
    // 0x13effc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13effcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13f000: 0xc045a12  jal         func_116848
    ctx->pc = 0x13F000u;
    SET_GPR_U32(ctx, 31, 0x13F008u);
    ctx->pc = 0x13F004u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F000u;
            // 0x13f004: 0x2484d8c0  addiu       $a0, $a0, -0x2740 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957248));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F008u; }
        if (ctx->pc != 0x13F008u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F008u; }
        if (ctx->pc != 0x13F008u) { return; }
    }
    ctx->pc = 0x13F008u;
label_13f008:
    // 0x13f008: 0x0  nop
    ctx->pc = 0x13f008u;
    // NOP
    // 0x13f00c: 0x0  nop
    ctx->pc = 0x13f00cu;
    // NOP
    // 0x13f010: 0x0  nop
    ctx->pc = 0x13f010u;
    // NOP
    // 0x13f014: 0x0  nop
    ctx->pc = 0x13f014u;
    // NOP
    // 0x13f018: 0x0  nop
    ctx->pc = 0x13f018u;
    // NOP
    // 0x13f01c: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x13F01Cu;
    {
        const bool branch_taken_0x13f01c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x13f01c) {
            ctx->pc = 0x13F008u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13f008;
        }
    }
    ctx->pc = 0x13F024u;
    // 0x13f024: 0x0  nop
    ctx->pc = 0x13f024u;
    // NOP
label_13f028:
    // 0x13f028: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13f028u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_13f02c:
    // 0x13f02c: 0xac860028  sw          $a2, 0x28($a0)
    ctx->pc = 0x13f02cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 40), GPR_U32(ctx, 6));
    // 0x13f030: 0x3e00008  jr          $ra
    ctx->pc = 0x13F030u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F034u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F030u;
            // 0x13f034: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13ED28u: goto label_13ed28;
            case 0x13ED78u: goto label_13ed78;
            case 0x13ED80u: goto label_13ed80;
            case 0x13EDA0u: goto label_13eda0;
            case 0x13EDB0u: goto label_13edb0;
            case 0x13EDC8u: goto label_13edc8;
            case 0x13EDF0u: goto label_13edf0;
            case 0x13EE10u: goto label_13ee10;
            case 0x13EE2Cu: goto label_13ee2c;
            case 0x13EE50u: goto label_13ee50;
            case 0x13EE68u: goto label_13ee68;
            case 0x13EE88u: goto label_13ee88;
            case 0x13EEA4u: goto label_13eea4;
            case 0x13EEB4u: goto label_13eeb4;
            case 0x13EEC8u: goto label_13eec8;
            case 0x13EF08u: goto label_13ef08;
            case 0x13EF10u: goto label_13ef10;
            case 0x13EF24u: goto label_13ef24;
            case 0x13EF28u: goto label_13ef28;
            case 0x13EF38u: goto label_13ef38;
            case 0x13EF40u: goto label_13ef40;
            case 0x13EF78u: goto label_13ef78;
            case 0x13EF9Cu: goto label_13ef9c;
            case 0x13EFB4u: goto label_13efb4;
            case 0x13EFB8u: goto label_13efb8;
            case 0x13EFD8u: goto label_13efd8;
            case 0x13EFECu: goto label_13efec;
            case 0x13F008u: goto label_13f008;
            case 0x13F028u: goto label_13f028;
            case 0x13F02Cu: goto label_13f02c;
            case 0x13F0A8u: goto label_13f0a8;
            case 0x13F0CCu: goto label_13f0cc;
            case 0x13F0E0u: goto label_13f0e0;
            case 0x13F0E8u: goto label_13f0e8;
            case 0x13F0F0u: goto label_13f0f0;
            case 0x13F100u: goto label_13f100;
            case 0x13F11Cu: goto label_13f11c;
            case 0x13F16Cu: goto label_13f16c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13F038u;
    // 0x13f038: 0x5102a  slt         $v0, $zero, $a1
    ctx->pc = 0x13f038u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x13f03c: 0x2406fc19  addiu       $a2, $zero, -0x3E7
    ctx->pc = 0x13f03cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966297));
    // 0x13f040: 0x2280b  movn        $a1, $zero, $v0
    ctx->pc = 0x13f040u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 0));
    // 0x13f044: 0x28a3fc19  slti        $v1, $a1, -0x3E7
    ctx->pc = 0x13f044u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)4294966297) ? 1 : 0);
    // 0x13f048: 0xc3280b  movn        $a1, $a2, $v1
    ctx->pc = 0x13f048u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 6));
    // 0x13f04c: 0x3e00008  jr          $ra
    ctx->pc = 0x13F04Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F050u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F04Cu;
            // 0x13f050: 0xac850030  sw          $a1, 0x30($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 48), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13ED28u: goto label_13ed28;
            case 0x13ED78u: goto label_13ed78;
            case 0x13ED80u: goto label_13ed80;
            case 0x13EDA0u: goto label_13eda0;
            case 0x13EDB0u: goto label_13edb0;
            case 0x13EDC8u: goto label_13edc8;
            case 0x13EDF0u: goto label_13edf0;
            case 0x13EE10u: goto label_13ee10;
            case 0x13EE2Cu: goto label_13ee2c;
            case 0x13EE50u: goto label_13ee50;
            case 0x13EE68u: goto label_13ee68;
            case 0x13EE88u: goto label_13ee88;
            case 0x13EEA4u: goto label_13eea4;
            case 0x13EEB4u: goto label_13eeb4;
            case 0x13EEC8u: goto label_13eec8;
            case 0x13EF08u: goto label_13ef08;
            case 0x13EF10u: goto label_13ef10;
            case 0x13EF24u: goto label_13ef24;
            case 0x13EF28u: goto label_13ef28;
            case 0x13EF38u: goto label_13ef38;
            case 0x13EF40u: goto label_13ef40;
            case 0x13EF78u: goto label_13ef78;
            case 0x13EF9Cu: goto label_13ef9c;
            case 0x13EFB4u: goto label_13efb4;
            case 0x13EFB8u: goto label_13efb8;
            case 0x13EFD8u: goto label_13efd8;
            case 0x13EFECu: goto label_13efec;
            case 0x13F008u: goto label_13f008;
            case 0x13F028u: goto label_13f028;
            case 0x13F02Cu: goto label_13f02c;
            case 0x13F0A8u: goto label_13f0a8;
            case 0x13F0CCu: goto label_13f0cc;
            case 0x13F0E0u: goto label_13f0e0;
            case 0x13F0E8u: goto label_13f0e8;
            case 0x13F0F0u: goto label_13f0f0;
            case 0x13F100u: goto label_13f100;
            case 0x13F11Cu: goto label_13f11c;
            case 0x13F16Cu: goto label_13f16c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13F054u;
    // 0x13f054: 0x0  nop
    ctx->pc = 0x13f054u;
    // NOP
    // 0x13f058: 0x28c3fff1  slti        $v1, $a2, -0xF
    ctx->pc = 0x13f058u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)4294967281) ? 1 : 0);
    // 0x13f05c: 0x2402fff1  addiu       $v0, $zero, -0xF
    ctx->pc = 0x13f05cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967281));
    // 0x13f060: 0xc3100a  movz        $v0, $a2, $v1
    ctx->pc = 0x13f060u;
    if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 6));
    // 0x13f064: 0x2406000f  addiu       $a2, $zero, 0xF
    ctx->pc = 0x13f064u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x13f068: 0x52880  sll         $a1, $a1, 2
    ctx->pc = 0x13f068u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x13f06c: 0x28430010  slti        $v1, $v0, 0x10
    ctx->pc = 0x13f06cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x13f070: 0xa42821  addu        $a1, $a1, $a0
    ctx->pc = 0x13f070u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x13f074: 0xc3100a  movz        $v0, $a2, $v1
    ctx->pc = 0x13f074u;
    if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 6));
    // 0x13f078: 0x3e00008  jr          $ra
    ctx->pc = 0x13F078u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F07Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F078u;
            // 0x13f07c: 0xaca20038  sw          $v0, 0x38($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 56), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13ED28u: goto label_13ed28;
            case 0x13ED78u: goto label_13ed78;
            case 0x13ED80u: goto label_13ed80;
            case 0x13EDA0u: goto label_13eda0;
            case 0x13EDB0u: goto label_13edb0;
            case 0x13EDC8u: goto label_13edc8;
            case 0x13EDF0u: goto label_13edf0;
            case 0x13EE10u: goto label_13ee10;
            case 0x13EE2Cu: goto label_13ee2c;
            case 0x13EE50u: goto label_13ee50;
            case 0x13EE68u: goto label_13ee68;
            case 0x13EE88u: goto label_13ee88;
            case 0x13EEA4u: goto label_13eea4;
            case 0x13EEB4u: goto label_13eeb4;
            case 0x13EEC8u: goto label_13eec8;
            case 0x13EF08u: goto label_13ef08;
            case 0x13EF10u: goto label_13ef10;
            case 0x13EF24u: goto label_13ef24;
            case 0x13EF28u: goto label_13ef28;
            case 0x13EF38u: goto label_13ef38;
            case 0x13EF40u: goto label_13ef40;
            case 0x13EF78u: goto label_13ef78;
            case 0x13EF9Cu: goto label_13ef9c;
            case 0x13EFB4u: goto label_13efb4;
            case 0x13EFB8u: goto label_13efb8;
            case 0x13EFD8u: goto label_13efd8;
            case 0x13EFECu: goto label_13efec;
            case 0x13F008u: goto label_13f008;
            case 0x13F028u: goto label_13f028;
            case 0x13F02Cu: goto label_13f02c;
            case 0x13F0A8u: goto label_13f0a8;
            case 0x13F0CCu: goto label_13f0cc;
            case 0x13F0E0u: goto label_13f0e0;
            case 0x13F0E8u: goto label_13f0e8;
            case 0x13F0F0u: goto label_13f0f0;
            case 0x13F100u: goto label_13f100;
            case 0x13F11Cu: goto label_13f11c;
            case 0x13F16Cu: goto label_13f16c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13F080u;
    // 0x13f080: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13f080u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13f084: 0x24020010  addiu       $v0, $zero, 0x10
    ctx->pc = 0x13f084u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x13f088: 0x10a20007  beq         $a1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x13F088u;
    {
        const bool branch_taken_0x13f088 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 2));
        ctx->pc = 0x13F08Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F088u;
            // 0x13f08c: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f088) {
            ctx->pc = 0x13F0A8u;
            goto label_13f0a8;
        }
    }
    ctx->pc = 0x13F090u;
    // 0x13f090: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13f090u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13f094: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13f094u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13f098: 0x2484d8e0  addiu       $a0, $a0, -0x2720
    ctx->pc = 0x13f098u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957280));
    // 0x13f09c: 0x8045a12  j           func_116848
    ctx->pc = 0x13F09Cu;
    ctx->pc = 0x13F0A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F09Cu;
            // 0x13f0a0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00116848_0x116848(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13F0A4u;
    // 0x13f0a4: 0x0  nop
    ctx->pc = 0x13f0a4u;
    // NOP
label_13f0a8:
    // 0x13f0a8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13f0a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13f0ac: 0x3e00008  jr          $ra
    ctx->pc = 0x13F0ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F0B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F0ACu;
            // 0x13f0b0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13ED28u: goto label_13ed28;
            case 0x13ED78u: goto label_13ed78;
            case 0x13ED80u: goto label_13ed80;
            case 0x13EDA0u: goto label_13eda0;
            case 0x13EDB0u: goto label_13edb0;
            case 0x13EDC8u: goto label_13edc8;
            case 0x13EDF0u: goto label_13edf0;
            case 0x13EE10u: goto label_13ee10;
            case 0x13EE2Cu: goto label_13ee2c;
            case 0x13EE50u: goto label_13ee50;
            case 0x13EE68u: goto label_13ee68;
            case 0x13EE88u: goto label_13ee88;
            case 0x13EEA4u: goto label_13eea4;
            case 0x13EEB4u: goto label_13eeb4;
            case 0x13EEC8u: goto label_13eec8;
            case 0x13EF08u: goto label_13ef08;
            case 0x13EF10u: goto label_13ef10;
            case 0x13EF24u: goto label_13ef24;
            case 0x13EF28u: goto label_13ef28;
            case 0x13EF38u: goto label_13ef38;
            case 0x13EF40u: goto label_13ef40;
            case 0x13EF78u: goto label_13ef78;
            case 0x13EF9Cu: goto label_13ef9c;
            case 0x13EFB4u: goto label_13efb4;
            case 0x13EFB8u: goto label_13efb8;
            case 0x13EFD8u: goto label_13efd8;
            case 0x13EFECu: goto label_13efec;
            case 0x13F008u: goto label_13f008;
            case 0x13F028u: goto label_13f028;
            case 0x13F02Cu: goto label_13f02c;
            case 0x13F0A8u: goto label_13f0a8;
            case 0x13F0CCu: goto label_13f0cc;
            case 0x13F0E0u: goto label_13f0e0;
            case 0x13F0E8u: goto label_13f0e8;
            case 0x13F0F0u: goto label_13f0f0;
            case 0x13F100u: goto label_13f100;
            case 0x13F11Cu: goto label_13f11c;
            case 0x13F16Cu: goto label_13f16c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13F0B4u;
    // 0x13f0b4: 0x0  nop
    ctx->pc = 0x13f0b4u;
    // NOP
    // 0x13f0b8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13f0b8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13f0bc: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13f0bcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13f0c0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13f0c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13f0c4: 0xc045a12  jal         func_116848
    ctx->pc = 0x13F0C4u;
    SET_GPR_U32(ctx, 31, 0x13F0CCu);
    ctx->pc = 0x13F0C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F0C4u;
            // 0x13f0c8: 0x2484d910  addiu       $a0, $a0, -0x26F0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957328));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F0CCu; }
        if (ctx->pc != 0x13F0CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F0CCu; }
        if (ctx->pc != 0x13F0CCu) { return; }
    }
    ctx->pc = 0x13F0CCu;
label_13f0cc:
    // 0x13f0cc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x13f0ccu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f0d0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13f0d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13f0d4: 0x3e00008  jr          $ra
    ctx->pc = 0x13F0D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F0D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F0D4u;
            // 0x13f0d8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13ED28u: goto label_13ed28;
            case 0x13ED78u: goto label_13ed78;
            case 0x13ED80u: goto label_13ed80;
            case 0x13EDA0u: goto label_13eda0;
            case 0x13EDB0u: goto label_13edb0;
            case 0x13EDC8u: goto label_13edc8;
            case 0x13EDF0u: goto label_13edf0;
            case 0x13EE10u: goto label_13ee10;
            case 0x13EE2Cu: goto label_13ee2c;
            case 0x13EE50u: goto label_13ee50;
            case 0x13EE68u: goto label_13ee68;
            case 0x13EE88u: goto label_13ee88;
            case 0x13EEA4u: goto label_13eea4;
            case 0x13EEB4u: goto label_13eeb4;
            case 0x13EEC8u: goto label_13eec8;
            case 0x13EF08u: goto label_13ef08;
            case 0x13EF10u: goto label_13ef10;
            case 0x13EF24u: goto label_13ef24;
            case 0x13EF28u: goto label_13ef28;
            case 0x13EF38u: goto label_13ef38;
            case 0x13EF40u: goto label_13ef40;
            case 0x13EF78u: goto label_13ef78;
            case 0x13EF9Cu: goto label_13ef9c;
            case 0x13EFB4u: goto label_13efb4;
            case 0x13EFB8u: goto label_13efb8;
            case 0x13EFD8u: goto label_13efd8;
            case 0x13EFECu: goto label_13efec;
            case 0x13F008u: goto label_13f008;
            case 0x13F028u: goto label_13f028;
            case 0x13F02Cu: goto label_13f02c;
            case 0x13F0A8u: goto label_13f0a8;
            case 0x13F0CCu: goto label_13f0cc;
            case 0x13F0E0u: goto label_13f0e0;
            case 0x13F0E8u: goto label_13f0e8;
            case 0x13F0F0u: goto label_13f0f0;
            case 0x13F100u: goto label_13f100;
            case 0x13F11Cu: goto label_13f11c;
            case 0x13F16Cu: goto label_13f16c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13F0DCu;
    // 0x13f0dc: 0x0  nop
    ctx->pc = 0x13f0dcu;
    // NOP
label_13f0e0:
    // 0x13f0e0: 0x3e00008  jr          $ra
    ctx->pc = 0x13F0E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F0E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F0E0u;
            // 0x13f0e4: 0x8c820028  lw          $v0, 0x28($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 40)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13ED28u: goto label_13ed28;
            case 0x13ED78u: goto label_13ed78;
            case 0x13ED80u: goto label_13ed80;
            case 0x13EDA0u: goto label_13eda0;
            case 0x13EDB0u: goto label_13edb0;
            case 0x13EDC8u: goto label_13edc8;
            case 0x13EDF0u: goto label_13edf0;
            case 0x13EE10u: goto label_13ee10;
            case 0x13EE2Cu: goto label_13ee2c;
            case 0x13EE50u: goto label_13ee50;
            case 0x13EE68u: goto label_13ee68;
            case 0x13EE88u: goto label_13ee88;
            case 0x13EEA4u: goto label_13eea4;
            case 0x13EEB4u: goto label_13eeb4;
            case 0x13EEC8u: goto label_13eec8;
            case 0x13EF08u: goto label_13ef08;
            case 0x13EF10u: goto label_13ef10;
            case 0x13EF24u: goto label_13ef24;
            case 0x13EF28u: goto label_13ef28;
            case 0x13EF38u: goto label_13ef38;
            case 0x13EF40u: goto label_13ef40;
            case 0x13EF78u: goto label_13ef78;
            case 0x13EF9Cu: goto label_13ef9c;
            case 0x13EFB4u: goto label_13efb4;
            case 0x13EFB8u: goto label_13efb8;
            case 0x13EFD8u: goto label_13efd8;
            case 0x13EFECu: goto label_13efec;
            case 0x13F008u: goto label_13f008;
            case 0x13F028u: goto label_13f028;
            case 0x13F02Cu: goto label_13f02c;
            case 0x13F0A8u: goto label_13f0a8;
            case 0x13F0CCu: goto label_13f0cc;
            case 0x13F0E0u: goto label_13f0e0;
            case 0x13F0E8u: goto label_13f0e8;
            case 0x13F0F0u: goto label_13f0f0;
            case 0x13F100u: goto label_13f100;
            case 0x13F11Cu: goto label_13f11c;
            case 0x13F16Cu: goto label_13f16c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13F0E8u;
label_13f0e8:
    // 0x13f0e8: 0x3e00008  jr          $ra
    ctx->pc = 0x13F0E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F0ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F0E8u;
            // 0x13f0ec: 0x8c820030  lw          $v0, 0x30($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 48)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13ED28u: goto label_13ed28;
            case 0x13ED78u: goto label_13ed78;
            case 0x13ED80u: goto label_13ed80;
            case 0x13EDA0u: goto label_13eda0;
            case 0x13EDB0u: goto label_13edb0;
            case 0x13EDC8u: goto label_13edc8;
            case 0x13EDF0u: goto label_13edf0;
            case 0x13EE10u: goto label_13ee10;
            case 0x13EE2Cu: goto label_13ee2c;
            case 0x13EE50u: goto label_13ee50;
            case 0x13EE68u: goto label_13ee68;
            case 0x13EE88u: goto label_13ee88;
            case 0x13EEA4u: goto label_13eea4;
            case 0x13EEB4u: goto label_13eeb4;
            case 0x13EEC8u: goto label_13eec8;
            case 0x13EF08u: goto label_13ef08;
            case 0x13EF10u: goto label_13ef10;
            case 0x13EF24u: goto label_13ef24;
            case 0x13EF28u: goto label_13ef28;
            case 0x13EF38u: goto label_13ef38;
            case 0x13EF40u: goto label_13ef40;
            case 0x13EF78u: goto label_13ef78;
            case 0x13EF9Cu: goto label_13ef9c;
            case 0x13EFB4u: goto label_13efb4;
            case 0x13EFB8u: goto label_13efb8;
            case 0x13EFD8u: goto label_13efd8;
            case 0x13EFECu: goto label_13efec;
            case 0x13F008u: goto label_13f008;
            case 0x13F028u: goto label_13f028;
            case 0x13F02Cu: goto label_13f02c;
            case 0x13F0A8u: goto label_13f0a8;
            case 0x13F0CCu: goto label_13f0cc;
            case 0x13F0E0u: goto label_13f0e0;
            case 0x13F0E8u: goto label_13f0e8;
            case 0x13F0F0u: goto label_13f0f0;
            case 0x13F100u: goto label_13f100;
            case 0x13F11Cu: goto label_13f11c;
            case 0x13F16Cu: goto label_13f16c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13F0F0u;
label_13f0f0:
    // 0x13f0f0: 0x52880  sll         $a1, $a1, 2
    ctx->pc = 0x13f0f0u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x13f0f4: 0xa42821  addu        $a1, $a1, $a0
    ctx->pc = 0x13f0f4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x13f0f8: 0x3e00008  jr          $ra
    ctx->pc = 0x13F0F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F0FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F0F8u;
            // 0x13f0fc: 0x8ca20038  lw          $v0, 0x38($a1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 56)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13ED28u: goto label_13ed28;
            case 0x13ED78u: goto label_13ed78;
            case 0x13ED80u: goto label_13ed80;
            case 0x13EDA0u: goto label_13eda0;
            case 0x13EDB0u: goto label_13edb0;
            case 0x13EDC8u: goto label_13edc8;
            case 0x13EDF0u: goto label_13edf0;
            case 0x13EE10u: goto label_13ee10;
            case 0x13EE2Cu: goto label_13ee2c;
            case 0x13EE50u: goto label_13ee50;
            case 0x13EE68u: goto label_13ee68;
            case 0x13EE88u: goto label_13ee88;
            case 0x13EEA4u: goto label_13eea4;
            case 0x13EEB4u: goto label_13eeb4;
            case 0x13EEC8u: goto label_13eec8;
            case 0x13EF08u: goto label_13ef08;
            case 0x13EF10u: goto label_13ef10;
            case 0x13EF24u: goto label_13ef24;
            case 0x13EF28u: goto label_13ef28;
            case 0x13EF38u: goto label_13ef38;
            case 0x13EF40u: goto label_13ef40;
            case 0x13EF78u: goto label_13ef78;
            case 0x13EF9Cu: goto label_13ef9c;
            case 0x13EFB4u: goto label_13efb4;
            case 0x13EFB8u: goto label_13efb8;
            case 0x13EFD8u: goto label_13efd8;
            case 0x13EFECu: goto label_13efec;
            case 0x13F008u: goto label_13f008;
            case 0x13F028u: goto label_13f028;
            case 0x13F02Cu: goto label_13f02c;
            case 0x13F0A8u: goto label_13f0a8;
            case 0x13F0CCu: goto label_13f0cc;
            case 0x13F0E0u: goto label_13f0e0;
            case 0x13F0E8u: goto label_13f0e8;
            case 0x13F0F0u: goto label_13f0f0;
            case 0x13F100u: goto label_13f100;
            case 0x13F11Cu: goto label_13f11c;
            case 0x13F16Cu: goto label_13f16c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13F100u;
label_13f100:
    // 0x13f100: 0x3e00008  jr          $ra
    ctx->pc = 0x13F100u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F104u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F100u;
            // 0x13f104: 0x24020010  addiu       $v0, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13ED28u: goto label_13ed28;
            case 0x13ED78u: goto label_13ed78;
            case 0x13ED80u: goto label_13ed80;
            case 0x13EDA0u: goto label_13eda0;
            case 0x13EDB0u: goto label_13edb0;
            case 0x13EDC8u: goto label_13edc8;
            case 0x13EDF0u: goto label_13edf0;
            case 0x13EE10u: goto label_13ee10;
            case 0x13EE2Cu: goto label_13ee2c;
            case 0x13EE50u: goto label_13ee50;
            case 0x13EE68u: goto label_13ee68;
            case 0x13EE88u: goto label_13ee88;
            case 0x13EEA4u: goto label_13eea4;
            case 0x13EEB4u: goto label_13eeb4;
            case 0x13EEC8u: goto label_13eec8;
            case 0x13EF08u: goto label_13ef08;
            case 0x13EF10u: goto label_13ef10;
            case 0x13EF24u: goto label_13ef24;
            case 0x13EF28u: goto label_13ef28;
            case 0x13EF38u: goto label_13ef38;
            case 0x13EF40u: goto label_13ef40;
            case 0x13EF78u: goto label_13ef78;
            case 0x13EF9Cu: goto label_13ef9c;
            case 0x13EFB4u: goto label_13efb4;
            case 0x13EFB8u: goto label_13efb8;
            case 0x13EFD8u: goto label_13efd8;
            case 0x13EFECu: goto label_13efec;
            case 0x13F008u: goto label_13f008;
            case 0x13F028u: goto label_13f028;
            case 0x13F02Cu: goto label_13f02c;
            case 0x13F0A8u: goto label_13f0a8;
            case 0x13F0CCu: goto label_13f0cc;
            case 0x13F0E0u: goto label_13f0e0;
            case 0x13F0E8u: goto label_13f0e8;
            case 0x13F0F0u: goto label_13f0f0;
            case 0x13F100u: goto label_13f100;
            case 0x13F11Cu: goto label_13f11c;
            case 0x13F16Cu: goto label_13f16c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13F108u;
    // 0x13f108: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13f108u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13f10c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13f10cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13f110: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13f110u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13f114: 0xc045a12  jal         func_116848
    ctx->pc = 0x13F114u;
    SET_GPR_U32(ctx, 31, 0x13F11Cu);
    ctx->pc = 0x13F118u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F114u;
            // 0x13f118: 0x2484d938  addiu       $a0, $a0, -0x26C8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957368));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F11Cu; }
        if (ctx->pc != 0x13F11Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F11Cu; }
        if (ctx->pc != 0x13F11Cu) { return; }
    }
    ctx->pc = 0x13F11Cu;
label_13f11c:
    // 0x13f11c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x13f11cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f120: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13f120u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13f124: 0x3e00008  jr          $ra
    ctx->pc = 0x13F124u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F128u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F124u;
            // 0x13f128: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13ED28u: goto label_13ed28;
            case 0x13ED78u: goto label_13ed78;
            case 0x13ED80u: goto label_13ed80;
            case 0x13EDA0u: goto label_13eda0;
            case 0x13EDB0u: goto label_13edb0;
            case 0x13EDC8u: goto label_13edc8;
            case 0x13EDF0u: goto label_13edf0;
            case 0x13EE10u: goto label_13ee10;
            case 0x13EE2Cu: goto label_13ee2c;
            case 0x13EE50u: goto label_13ee50;
            case 0x13EE68u: goto label_13ee68;
            case 0x13EE88u: goto label_13ee88;
            case 0x13EEA4u: goto label_13eea4;
            case 0x13EEB4u: goto label_13eeb4;
            case 0x13EEC8u: goto label_13eec8;
            case 0x13EF08u: goto label_13ef08;
            case 0x13EF10u: goto label_13ef10;
            case 0x13EF24u: goto label_13ef24;
            case 0x13EF28u: goto label_13ef28;
            case 0x13EF38u: goto label_13ef38;
            case 0x13EF40u: goto label_13ef40;
            case 0x13EF78u: goto label_13ef78;
            case 0x13EF9Cu: goto label_13ef9c;
            case 0x13EFB4u: goto label_13efb4;
            case 0x13EFB8u: goto label_13efb8;
            case 0x13EFD8u: goto label_13efd8;
            case 0x13EFECu: goto label_13efec;
            case 0x13F008u: goto label_13f008;
            case 0x13F028u: goto label_13f028;
            case 0x13F02Cu: goto label_13f02c;
            case 0x13F0A8u: goto label_13f0a8;
            case 0x13F0CCu: goto label_13f0cc;
            case 0x13F0E0u: goto label_13f0e0;
            case 0x13F0E8u: goto label_13f0e8;
            case 0x13F0F0u: goto label_13f0f0;
            case 0x13F100u: goto label_13f100;
            case 0x13F11Cu: goto label_13f11c;
            case 0x13F16Cu: goto label_13f16c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13F12Cu;
    // 0x13f12c: 0x0  nop
    ctx->pc = 0x13f12cu;
    // NOP
    // 0x13f130: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13f130u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13f134: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13f134u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13f138: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13f138u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13f13c: 0x2484d960  addiu       $a0, $a0, -0x26A0
    ctx->pc = 0x13f13cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957408));
    // 0x13f140: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13f140u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13f144: 0x8045a12  j           func_116848
    ctx->pc = 0x13F144u;
    ctx->pc = 0x13F148u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F144u;
            // 0x13f148: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00116848_0x116848(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13F14Cu;
    // 0x13f14c: 0x0  nop
    ctx->pc = 0x13f14cu;
    // NOP
    // 0x13f150: 0x3e00008  jr          $ra
    ctx->pc = 0x13F150u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13ED28u: goto label_13ed28;
            case 0x13ED78u: goto label_13ed78;
            case 0x13ED80u: goto label_13ed80;
            case 0x13EDA0u: goto label_13eda0;
            case 0x13EDB0u: goto label_13edb0;
            case 0x13EDC8u: goto label_13edc8;
            case 0x13EDF0u: goto label_13edf0;
            case 0x13EE10u: goto label_13ee10;
            case 0x13EE2Cu: goto label_13ee2c;
            case 0x13EE50u: goto label_13ee50;
            case 0x13EE68u: goto label_13ee68;
            case 0x13EE88u: goto label_13ee88;
            case 0x13EEA4u: goto label_13eea4;
            case 0x13EEB4u: goto label_13eeb4;
            case 0x13EEC8u: goto label_13eec8;
            case 0x13EF08u: goto label_13ef08;
            case 0x13EF10u: goto label_13ef10;
            case 0x13EF24u: goto label_13ef24;
            case 0x13EF28u: goto label_13ef28;
            case 0x13EF38u: goto label_13ef38;
            case 0x13EF40u: goto label_13ef40;
            case 0x13EF78u: goto label_13ef78;
            case 0x13EF9Cu: goto label_13ef9c;
            case 0x13EFB4u: goto label_13efb4;
            case 0x13EFB8u: goto label_13efb8;
            case 0x13EFD8u: goto label_13efd8;
            case 0x13EFECu: goto label_13efec;
            case 0x13F008u: goto label_13f008;
            case 0x13F028u: goto label_13f028;
            case 0x13F02Cu: goto label_13f02c;
            case 0x13F0A8u: goto label_13f0a8;
            case 0x13F0CCu: goto label_13f0cc;
            case 0x13F0E0u: goto label_13f0e0;
            case 0x13F0E8u: goto label_13f0e8;
            case 0x13F0F0u: goto label_13f0f0;
            case 0x13F100u: goto label_13f100;
            case 0x13F11Cu: goto label_13f11c;
            case 0x13F16Cu: goto label_13f16c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13F158u;
    // 0x13f158: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13f158u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13f15c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13f15cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13f160: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13f160u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13f164: 0xc045a12  jal         func_116848
    ctx->pc = 0x13F164u;
    SET_GPR_U32(ctx, 31, 0x13F16Cu);
    ctx->pc = 0x13F168u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F164u;
            // 0x13f168: 0x2484d988  addiu       $a0, $a0, -0x2678 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957448));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F16Cu; }
        if (ctx->pc != 0x13F16Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F16Cu; }
        if (ctx->pc != 0x13F16Cu) { return; }
    }
    ctx->pc = 0x13F16Cu;
label_13f16c:
    // 0x13f16c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x13f16cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f170: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13f170u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13f174: 0x3e00008  jr          $ra
    ctx->pc = 0x13F174u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F178u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F174u;
            // 0x13f178: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13ED28u: goto label_13ed28;
            case 0x13ED78u: goto label_13ed78;
            case 0x13ED80u: goto label_13ed80;
            case 0x13EDA0u: goto label_13eda0;
            case 0x13EDB0u: goto label_13edb0;
            case 0x13EDC8u: goto label_13edc8;
            case 0x13EDF0u: goto label_13edf0;
            case 0x13EE10u: goto label_13ee10;
            case 0x13EE2Cu: goto label_13ee2c;
            case 0x13EE50u: goto label_13ee50;
            case 0x13EE68u: goto label_13ee68;
            case 0x13EE88u: goto label_13ee88;
            case 0x13EEA4u: goto label_13eea4;
            case 0x13EEB4u: goto label_13eeb4;
            case 0x13EEC8u: goto label_13eec8;
            case 0x13EF08u: goto label_13ef08;
            case 0x13EF10u: goto label_13ef10;
            case 0x13EF24u: goto label_13ef24;
            case 0x13EF28u: goto label_13ef28;
            case 0x13EF38u: goto label_13ef38;
            case 0x13EF40u: goto label_13ef40;
            case 0x13EF78u: goto label_13ef78;
            case 0x13EF9Cu: goto label_13ef9c;
            case 0x13EFB4u: goto label_13efb4;
            case 0x13EFB8u: goto label_13efb8;
            case 0x13EFD8u: goto label_13efd8;
            case 0x13EFECu: goto label_13efec;
            case 0x13F008u: goto label_13f008;
            case 0x13F028u: goto label_13f028;
            case 0x13F02Cu: goto label_13f02c;
            case 0x13F0A8u: goto label_13f0a8;
            case 0x13F0CCu: goto label_13f0cc;
            case 0x13F0E0u: goto label_13f0e0;
            case 0x13F0E8u: goto label_13f0e8;
            case 0x13F0F0u: goto label_13f0f0;
            case 0x13F100u: goto label_13f100;
            case 0x13F11Cu: goto label_13f11c;
            case 0x13F16Cu: goto label_13f16c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13F17Cu;
    // 0x13f17c: 0x0  nop
    ctx->pc = 0x13f17cu;
    // NOP
    // 0x13f180: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13f180u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13f184: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13f184u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13f188: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13f188u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13f18c: 0x2484d9b0  addiu       $a0, $a0, -0x2650
    ctx->pc = 0x13f18cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957488));
    // 0x13f190: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13f190u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13f194: 0x8045a12  j           func_116848
    ctx->pc = 0x13F194u;
    ctx->pc = 0x13F198u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F194u;
            // 0x13f198: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00116848_0x116848(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13F19Cu;
    // 0x13f19c: 0x0  nop
    ctx->pc = 0x13f19cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
