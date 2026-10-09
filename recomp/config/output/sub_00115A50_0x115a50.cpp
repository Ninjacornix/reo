#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00115A50
// Address: 0x115a50 - 0x115be4
void sub_00115A50_0x115a50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00115A50_0x115a50");
#endif

    switch (ctx->pc) {
        case 0x115abcu: goto label_115abc;
        case 0x115ad4u: goto label_115ad4;
        case 0x115aecu: goto label_115aec;
        case 0x115b20u: goto label_115b20;
        case 0x115b40u: goto label_115b40;
        case 0x115b70u: goto label_115b70;
        case 0x115b88u: goto label_115b88;
        case 0x115bc8u: goto label_115bc8;
        default: break;
    }

    ctx->pc = 0x115a50u;

    // 0x115a50: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x115a50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x115a54: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x115a54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x115a58: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x115a58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x115a5c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x115a5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x115a60: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x115a60u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115a64: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x115a64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x115a68: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x115a68u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115a6c: 0x1082003b  beq         $a0, $v0, . + 4 + (0x3B << 2)
    ctx->pc = 0x115A6Cu;
    {
        const bool branch_taken_0x115a6c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x115A70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115A6Cu;
            // 0x115a70: 0xffb20020  sd          $s2, 0x20($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115a6c) {
            ctx->pc = 0x115B5Cu;
            goto label_115b5c;
        }
    }
    ctx->pc = 0x115A74u;
    // 0x115a74: 0x28820004  slti        $v0, $a0, 0x4
    ctx->pc = 0x115a74u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x115a78: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x115A78u;
    {
        const bool branch_taken_0x115a78 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x115A7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115A78u;
            // 0x115a7c: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115a78) {
            ctx->pc = 0x115A90u;
            goto label_115a90;
        }
    }
    ctx->pc = 0x115A80u;
    // 0x115a80: 0x1082004a  beq         $a0, $v0, . + 4 + (0x4A << 2)
    ctx->pc = 0x115A80u;
    {
        const bool branch_taken_0x115a80 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x115A84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115A80u;
            // 0x115a84: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115a80) {
            ctx->pc = 0x115BACu;
            goto label_115bac;
        }
    }
    ctx->pc = 0x115A88u;
    // 0x115a88: 0x10000052  b           . + 4 + (0x52 << 2)
    ctx->pc = 0x115A88u;
    {
        const bool branch_taken_0x115a88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x115A8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115A88u;
            // 0x115a8c: 0xdfb20020  ld          $s2, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115a88) {
            ctx->pc = 0x115BD4u;
            goto label_115bd4;
        }
    }
    ctx->pc = 0x115A90u;
label_115a90:
    // 0x115a90: 0x1880004f  blez        $a0, . + 4 + (0x4F << 2)
    ctx->pc = 0x115A90u;
    {
        const bool branch_taken_0x115a90 = (GPR_S64(ctx, 4) <= 0);
        ctx->pc = 0x115A94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115A90u;
            // 0x115a94: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115a90) {
            ctx->pc = 0x115BD0u;
            goto label_115bd0;
        }
    }
    ctx->pc = 0x115A98u;
    // 0x115a98: 0x52000019  beql        $s0, $zero, . + 4 + (0x19 << 2)
    ctx->pc = 0x115A98u;
    {
        const bool branch_taken_0x115a98 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x115a98) {
            ctx->pc = 0x115A9Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x115A98u;
            // 0x115a9c: 0x8e320014  lw          $s2, 0x14($s1) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x115B00u;
            goto label_115b00;
        }
    }
    ctx->pc = 0x115AA0u;
    // 0x115aa0: 0x8e220008  lw          $v0, 0x8($s1)
    ctx->pc = 0x115aa0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x115aa4: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x115aa4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x115aa8: 0x2c420141  sltiu       $v0, $v0, 0x141
    ctx->pc = 0x115aa8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)321) ? 1 : 0);
    // 0x115aac: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x115AACu;
    {
        const bool branch_taken_0x115aac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x115AB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115AACu;
            // 0x115ab0: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115aac) {
            ctx->pc = 0x115ABCu;
            goto label_115abc;
        }
    }
    ctx->pc = 0x115AB4u;
    // 0x115ab4: 0xc045a04  jal         func_116810
    ctx->pc = 0x115AB4u;
    SET_GPR_U32(ctx, 31, 0x115ABCu);
    ctx->pc = 0x115AB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115AB4u;
            // 0x115ab8: 0x24848950  addiu       $a0, $a0, -0x76B0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294936912));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116810u;
    if (runtime->hasFunction(0x116810u)) {
        auto targetFn = runtime->lookupFunction(0x116810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115ABCu; }
        if (ctx->pc != 0x115ABCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116810_0x116810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115ABCu; }
        if (ctx->pc != 0x115ABCu) { return; }
    }
    ctx->pc = 0x115ABCu;
label_115abc:
    // 0x115abc: 0x8e220008  lw          $v0, 0x8($s1)
    ctx->pc = 0x115abcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x115ac0: 0x3206ffff  andi        $a2, $s0, 0xFFFF
    ctx->pc = 0x115ac0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)65535);
    // 0x115ac4: 0x8e250014  lw          $a1, 0x14($s1)
    ctx->pc = 0x115ac4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x115ac8: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x115ac8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x115acc: 0xc045624  jal         func_115890
    ctx->pc = 0x115ACCu;
    SET_GPR_U32(ctx, 31, 0x115AD4u);
    ctx->pc = 0x115AD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115ACCu;
            // 0x115ad0: 0xa22821  addu        $a1, $a1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x115890u;
    if (runtime->hasFunction(0x115890u)) {
        auto targetFn = runtime->lookupFunction(0x115890u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115AD4u; }
        if (ctx->pc != 0x115AD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00115890_0x115890(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115AD4u; }
        if (ctx->pc != 0x115AD4u) { return; }
    }
    ctx->pc = 0x115AD4u;
label_115ad4:
    // 0x115ad4: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x115ad4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115ad8: 0x6010004  bgez        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x115AD8u;
    {
        const bool branch_taken_0x115ad8 = (GPR_S64(ctx, 16) >= 0);
        if (branch_taken_0x115ad8) {
            ctx->pc = 0x115AECu;
            goto label_115aec;
        }
    }
    ctx->pc = 0x115AE0u;
    // 0x115ae0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x115ae0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x115ae4: 0xc045a04  jal         func_116810
    ctx->pc = 0x115AE4u;
    SET_GPR_U32(ctx, 31, 0x115AECu);
    ctx->pc = 0x115AE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115AE4u;
            // 0x115ae8: 0x24848978  addiu       $a0, $a0, -0x7688 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294936952));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116810u;
    if (runtime->hasFunction(0x116810u)) {
        auto targetFn = runtime->lookupFunction(0x116810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115AECu; }
        if (ctx->pc != 0x115AECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116810_0x116810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115AECu; }
        if (ctx->pc != 0x115AECu) { return; }
    }
    ctx->pc = 0x115AECu;
label_115aec:
    // 0x115aec: 0x8e220008  lw          $v0, 0x8($s1)
    ctx->pc = 0x115aecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x115af0: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x115af0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x115af4: 0xae220008  sw          $v0, 0x8($s1)
    ctx->pc = 0x115af4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 2));
    // 0x115af8: 0x10000035  b           . + 4 + (0x35 << 2)
    ctx->pc = 0x115AF8u;
    {
        const bool branch_taken_0x115af8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x115AFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115AF8u;
            // 0x115afc: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115af8) {
            ctx->pc = 0x115BD0u;
            goto label_115bd0;
        }
    }
    ctx->pc = 0x115B00u;
label_115b00:
    // 0x115b00: 0x2410000c  addiu       $s0, $zero, 0xC
    ctx->pc = 0x115b00u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x115b04: 0x96420000  lhu         $v0, 0x0($s2)
    ctx->pc = 0x115b04u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x115b08: 0x202102a  slt         $v0, $s0, $v0
    ctx->pc = 0x115b08u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x115b0c: 0x10400010  beqz        $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x115B0Cu;
    {
        const bool branch_taken_0x115b0c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x115B10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115B0Cu;
            // 0x115b10: 0x240182d  daddu       $v1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115b0c) {
            ctx->pc = 0x115B50u;
            goto label_115b50;
        }
    }
    ctx->pc = 0x115B14u;
    // 0x115b14: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x115B14u;
    {
        const bool branch_taken_0x115b14 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x115B18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115B14u;
            // 0x115b18: 0x8e240018  lw          $a0, 0x18($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115b14) {
            ctx->pc = 0x115B24u;
            goto label_115b24;
        }
    }
    ctx->pc = 0x115B1Cu;
    // 0x115b1c: 0x0  nop
    ctx->pc = 0x115b1cu;
    // NOP
label_115b20:
    // 0x115b20: 0x8e240018  lw          $a0, 0x18($s1)
    ctx->pc = 0x115b20u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
label_115b24:
    // 0x115b24: 0x701021  addu        $v0, $v1, $s0
    ctx->pc = 0x115b24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x115b28: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x115b28u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x115b2c: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x115b2cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x115b30: 0x8c82000c  lw          $v0, 0xC($a0)
    ctx->pc = 0x115b30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x115b34: 0xa0430000  sb          $v1, 0x0($v0)
    ctx->pc = 0x115b34u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x115b38: 0xc045674  jal         func_1159D0
    ctx->pc = 0x115B38u;
    SET_GPR_U32(ctx, 31, 0x115B40u);
    ctx->pc = 0x115B3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115B38u;
            // 0x115b3c: 0x8e240018  lw          $a0, 0x18($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1159D0u;
    if (runtime->hasFunction(0x1159D0u)) {
        auto targetFn = runtime->lookupFunction(0x1159D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115B40u; }
        if (ctx->pc != 0x115B40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001159D0_0x1159d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115B40u; }
        if (ctx->pc != 0x115B40u) { return; }
    }
    ctx->pc = 0x115B40u;
label_115b40:
    // 0x115b40: 0x96420000  lhu         $v0, 0x0($s2)
    ctx->pc = 0x115b40u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x115b44: 0x202102a  slt         $v0, $s0, $v0
    ctx->pc = 0x115b44u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x115b48: 0x5440fff5  bnel        $v0, $zero, . + 4 + (-0xB << 2)
    ctx->pc = 0x115B48u;
    {
        const bool branch_taken_0x115b48 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x115b48) {
            ctx->pc = 0x115B4Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x115B48u;
            // 0x115b4c: 0x8e230014  lw          $v1, 0x14($s1) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x115B20u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_115b20;
        }
    }
    ctx->pc = 0x115B50u;
label_115b50:
    // 0x115b50: 0xae200008  sw          $zero, 0x8($s1)
    ctx->pc = 0x115b50u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 0));
    // 0x115b54: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x115B54u;
    {
        const bool branch_taken_0x115b54 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x115B58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115B54u;
            // 0x115b58: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115b54) {
            ctx->pc = 0x115BD0u;
            goto label_115bd0;
        }
    }
    ctx->pc = 0x115B5Cu;
label_115b5c:
    // 0x115b5c: 0x8e260004  lw          $a2, 0x4($s1)
    ctx->pc = 0x115b5cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x115b60: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x115b60u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x115b64: 0x8e250010  lw          $a1, 0x10($s1)
    ctx->pc = 0x115b64u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x115b68: 0xc045632  jal         func_1158C8
    ctx->pc = 0x115B68u;
    SET_GPR_U32(ctx, 31, 0x115B70u);
    ctx->pc = 0x115B6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115B68u;
            // 0x115b6c: 0x30c6ffff  andi        $a2, $a2, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1158C8u;
    if (runtime->hasFunction(0x1158C8u)) {
        auto targetFn = runtime->lookupFunction(0x1158C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115B70u; }
        if (ctx->pc != 0x115B70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001158C8_0x1158c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115B70u; }
        if (ctx->pc != 0x115B70u) { return; }
    }
    ctx->pc = 0x115B70u;
label_115b70:
    // 0x115b70: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x115b70u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115b74: 0x4a30006  bgezl       $a1, . + 4 + (0x6 << 2)
    ctx->pc = 0x115B74u;
    {
        const bool branch_taken_0x115b74 = (GPR_S64(ctx, 5) >= 0);
        if (branch_taken_0x115b74) {
            ctx->pc = 0x115B78u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x115B74u;
            // 0x115b78: 0x8e220010  lw          $v0, 0x10($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x115B90u;
            goto label_115b90;
        }
    }
    ctx->pc = 0x115B7Cu;
    // 0x115b7c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x115b7cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x115b80: 0xc045a04  jal         func_116810
    ctx->pc = 0x115B80u;
    SET_GPR_U32(ctx, 31, 0x115B88u);
    ctx->pc = 0x115B84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115B80u;
            // 0x115b84: 0x24848990  addiu       $a0, $a0, -0x7670 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294936976));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116810u;
    if (runtime->hasFunction(0x116810u)) {
        auto targetFn = runtime->lookupFunction(0x116810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115B88u; }
        if (ctx->pc != 0x115B88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116810_0x116810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115B88u; }
        if (ctx->pc != 0x115B88u) { return; }
    }
    ctx->pc = 0x115B88u;
label_115b88:
    // 0x115b88: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x115B88u;
    {
        const bool branch_taken_0x115b88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x115b88) {
            ctx->pc = 0x115BC8u;
            goto label_115bc8;
        }
    }
    ctx->pc = 0x115B90u;
label_115b90:
    // 0x115b90: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x115b90u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x115b94: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x115b94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x115b98: 0x651823  subu        $v1, $v1, $a1
    ctx->pc = 0x115b98u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x115b9c: 0xae220010  sw          $v0, 0x10($s1)
    ctx->pc = 0x115b9cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 2));
    // 0x115ba0: 0xae230004  sw          $v1, 0x4($s1)
    ctx->pc = 0x115ba0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 3));
    // 0x115ba4: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x115BA4u;
    {
        const bool branch_taken_0x115ba4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x115BA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115BA4u;
            // 0x115ba8: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x115ba4) {
            ctx->pc = 0x115BD0u;
            goto label_115bd0;
        }
    }
    ctx->pc = 0x115BACu;
label_115bac:
    // 0x115bac: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x115bacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x115bb0: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x115BB0u;
    {
        const bool branch_taken_0x115bb0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x115bb0) {
            ctx->pc = 0x115BC8u;
            goto label_115bc8;
        }
    }
    ctx->pc = 0x115BB8u;
    // 0x115bb8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x115bb8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x115bbc: 0x8e250004  lw          $a1, 0x4($s1)
    ctx->pc = 0x115bbcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x115bc0: 0xc045a04  jal         func_116810
    ctx->pc = 0x115BC0u;
    SET_GPR_U32(ctx, 31, 0x115BC8u);
    ctx->pc = 0x115BC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115BC0u;
            // 0x115bc4: 0x248489a8  addiu       $a0, $a0, -0x7658 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294937000));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116810u;
    if (runtime->hasFunction(0x116810u)) {
        auto targetFn = runtime->lookupFunction(0x116810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115BC8u; }
        if (ctx->pc != 0x115BC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116810_0x116810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115BC8u; }
        if (ctx->pc != 0x115BC8u) { return; }
    }
    ctx->pc = 0x115BC8u;
label_115bc8:
    // 0x115bc8: 0xae20000c  sw          $zero, 0xC($s1)
    ctx->pc = 0x115bc8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 0));
    // 0x115bcc: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x115bccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_115bd0:
    // 0x115bd0: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x115bd0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_115bd4:
    // 0x115bd4: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x115bd4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x115bd8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x115bd8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x115bdc: 0x3e00008  jr          $ra
    ctx->pc = 0x115BDCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x115BE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115BDCu;
            // 0x115be0: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x115A90u: goto label_115a90;
            case 0x115ABCu: goto label_115abc;
            case 0x115AD4u: goto label_115ad4;
            case 0x115AECu: goto label_115aec;
            case 0x115B00u: goto label_115b00;
            case 0x115B20u: goto label_115b20;
            case 0x115B24u: goto label_115b24;
            case 0x115B40u: goto label_115b40;
            case 0x115B50u: goto label_115b50;
            case 0x115B5Cu: goto label_115b5c;
            case 0x115B70u: goto label_115b70;
            case 0x115B88u: goto label_115b88;
            case 0x115B90u: goto label_115b90;
            case 0x115BACu: goto label_115bac;
            case 0x115BC8u: goto label_115bc8;
            case 0x115BD0u: goto label_115bd0;
            case 0x115BD4u: goto label_115bd4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x115BE4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
