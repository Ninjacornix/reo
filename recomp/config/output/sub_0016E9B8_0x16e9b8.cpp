#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016E9B8
// Address: 0x16e9b8 - 0x16eb30
void sub_0016E9B8_0x16e9b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016E9B8_0x16e9b8");
#endif

    switch (ctx->pc) {
        case 0x16ea30u: goto label_16ea30;
        case 0x16ea50u: goto label_16ea50;
        case 0x16ea68u: goto label_16ea68;
        case 0x16ea74u: goto label_16ea74;
        case 0x16eaa4u: goto label_16eaa4;
        case 0x16eac4u: goto label_16eac4;
        case 0x16eaf4u: goto label_16eaf4;
        default: break;
    }

    ctx->pc = 0x16e9b8u;

    // 0x16e9b8: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x16e9b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x16e9bc: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x16e9bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x16e9c0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x16e9c0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e9c4: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x16e9c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x16e9c8: 0x26110cc0  addiu       $s1, $s0, 0xCC0
    ctx->pc = 0x16e9c8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 3264));
    // 0x16e9cc: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x16e9ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x16e9d0: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x16e9d0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e9d4: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x16e9d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x16e9d8: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x16e9d8u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e9dc: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x16e9dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x16e9e0: 0x26030da4  addiu       $v1, $s0, 0xDA4
    ctx->pc = 0x16e9e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 3492));
    // 0x16e9e4: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x16e9e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x16e9e8: 0x26060d54  addiu       $a2, $s0, 0xD54
    ctx->pc = 0x16e9e8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 3412));
    // 0x16e9ec: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x16e9ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x16e9f0: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x16e9f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x16e9f4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x16E9F4u;
    {
        const bool branch_taken_0x16e9f4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16E9F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E9F4u;
            // 0x16e9f8: 0x8e151b30  lw          $s5, 0x1B30($s0) (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 6960)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e9f4) {
            ctx->pc = 0x16EA10u;
            goto label_16ea10;
        }
    }
    ctx->pc = 0x16E9FCu;
    // 0x16e9fc: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x16e9fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x16ea00: 0x8cc30020  lw          $v1, 0x20($a2)
    ctx->pc = 0x16ea00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 32)));
    // 0x16ea04: 0x8e240120  lw          $a0, 0x120($s1)
    ctx->pc = 0x16ea04u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 288)));
    // 0x16ea08: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x16ea08u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x16ea0c: 0x64a021  addu        $s4, $v1, $a0
    ctx->pc = 0x16ea0cu;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
label_16ea10:
    // 0x16ea10: 0x8e220018  lw          $v0, 0x18($s1)
    ctx->pc = 0x16ea10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x16ea14: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x16EA14u;
    {
        const bool branch_taken_0x16ea14 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16EA18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16EA14u;
            // 0x16ea18: 0x8cd30024  lw          $s3, 0x24($a2) (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 36)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16ea14) {
            ctx->pc = 0x16EA38u;
            goto label_16ea38;
        }
    }
    ctx->pc = 0x16EA1Cu;
    // 0x16ea1c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16ea1cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ea20: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x16ea20u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ea24: 0x280302d  daddu       $a2, $s4, $zero
    ctx->pc = 0x16ea24u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ea28: 0x40f809  jalr        $v0
    ctx->pc = 0x16EA28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x16EA30u);
        ctx->pc = 0x16EA2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16EA28u;
            // 0x16ea2c: 0x260382d  daddu       $a3, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x16EA30u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16EA10u: goto label_16ea10;
            case 0x16EA30u: goto label_16ea30;
            case 0x16EA38u: goto label_16ea38;
            case 0x16EA50u: goto label_16ea50;
            case 0x16EA54u: goto label_16ea54;
            case 0x16EA68u: goto label_16ea68;
            case 0x16EA6Cu: goto label_16ea6c;
            case 0x16EA74u: goto label_16ea74;
            case 0x16EA98u: goto label_16ea98;
            case 0x16EAA4u: goto label_16eaa4;
            case 0x16EAC4u: goto label_16eac4;
            case 0x16EADCu: goto label_16eadc;
            case 0x16EAF4u: goto label_16eaf4;
            case 0x16EB0Cu: goto label_16eb0c;
            case 0x16EB10u: goto label_16eb10;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x16EA30u; }
            if (ctx->pc != 0x16EA30u) { return; }
        }
        }
    }
    ctx->pc = 0x16EA30u;
label_16ea30:
    // 0x16ea30: 0x10000037  b           . + 4 + (0x37 << 2)
    ctx->pc = 0x16EA30u;
    {
        const bool branch_taken_0x16ea30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16EA34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16EA30u;
            // 0x16ea34: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16ea30) {
            ctx->pc = 0x16EB10u;
            goto label_16eb10;
        }
    }
    ctx->pc = 0x16EA38u;
label_16ea38:
    // 0x16ea38: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x16ea38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16ea3c: 0x56420005  bnel        $s2, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x16EA3Cu;
    {
        const bool branch_taken_0x16ea3c = (GPR_U64(ctx, 18) != GPR_U64(ctx, 2));
        if (branch_taken_0x16ea3c) {
            ctx->pc = 0x16EA40u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16EA3Cu;
            // 0x16ea40: 0x2642ffff  addiu       $v0, $s2, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16EA54u;
            goto label_16ea54;
        }
    }
    ctx->pc = 0x16EA44u;
    // 0x16ea44: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x16ea44u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ea48: 0xc05d72e  jal         func_175CB8
    ctx->pc = 0x16EA48u;
    SET_GPR_U32(ctx, 31, 0x16EA50u);
    ctx->pc = 0x16EA4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16EA48u;
            // 0x16ea4c: 0x280282d  daddu       $a1, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175CB8u;
    if (runtime->hasFunction(0x175CB8u)) {
        auto targetFn = runtime->lookupFunction(0x175CB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EA50u; }
        if (ctx->pc != 0x16EA50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175CB8_0x175cb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EA50u; }
        if (ctx->pc != 0x16EA50u) { return; }
    }
    ctx->pc = 0x16EA50u;
label_16ea50:
    // 0x16ea50: 0x2642ffff  addiu       $v0, $s2, -0x1
    ctx->pc = 0x16ea50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967295));
label_16ea54:
    // 0x16ea54: 0x2c420002  sltiu       $v0, $v0, 0x2
    ctx->pc = 0x16ea54u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x16ea58: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x16EA58u;
    {
        const bool branch_taken_0x16ea58 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16EA5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16EA58u;
            // 0x16ea5c: 0x280282d  daddu       $a1, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16ea58) {
            ctx->pc = 0x16EA6Cu;
            goto label_16ea6c;
        }
    }
    ctx->pc = 0x16EA60u;
    // 0x16ea60: 0xc05d756  jal         func_175D58
    ctx->pc = 0x16EA60u;
    SET_GPR_U32(ctx, 31, 0x16EA68u);
    ctx->pc = 0x16EA64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16EA60u;
            // 0x16ea64: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175D58u;
    if (runtime->hasFunction(0x175D58u)) {
        auto targetFn = runtime->lookupFunction(0x175D58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EA68u; }
        if (ctx->pc != 0x16EA68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175D58_0x175d58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EA68u; }
        if (ctx->pc != 0x16EA68u) { return; }
    }
    ctx->pc = 0x16EA68u;
label_16ea68:
    // 0x16ea68: 0x40a02d  daddu       $s4, $v0, $zero
    ctx->pc = 0x16ea68u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_16ea6c:
    // 0x16ea6c: 0xc05dd12  jal         func_177448
    ctx->pc = 0x16EA6Cu;
    SET_GPR_U32(ctx, 31, 0x16EA74u);
    ctx->pc = 0x16EA70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16EA6Cu;
            // 0x16ea70: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177448u;
    if (runtime->hasFunction(0x177448u)) {
        auto targetFn = runtime->lookupFunction(0x177448u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EA74u; }
        if (ctx->pc != 0x16EA74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177448_0x177448(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EA74u; }
        if (ctx->pc != 0x16EA74u) { return; }
    }
    ctx->pc = 0x16EA74u;
label_16ea74:
    // 0x16ea74: 0x284203e9  slti        $v0, $v0, 0x3E9
    ctx->pc = 0x16ea74u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)1001) ? 1 : 0);
    // 0x16ea78: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x16EA78u;
    {
        const bool branch_taken_0x16ea78 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16EA7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16EA78u;
            // 0x16ea7c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16ea78) {
            ctx->pc = 0x16EA98u;
            goto label_16ea98;
        }
    }
    ctx->pc = 0x16EA80u;
    // 0x16ea80: 0x8ea30084  lw          $v1, 0x84($s5)
    ctx->pc = 0x16ea80u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 132)));
    // 0x16ea84: 0x8e040a38  lw          $a0, 0xA38($s0)
    ctx->pc = 0x16ea84u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 2616)));
    // 0x16ea88: 0x64182a  slt         $v1, $v1, $a0
    ctx->pc = 0x16ea88u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x16ea8c: 0x1060001f  beqz        $v1, . + 4 + (0x1F << 2)
    ctx->pc = 0x16EA8Cu;
    {
        const bool branch_taken_0x16ea8c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x16EA90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16EA8Cu;
            // 0x16ea90: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16ea8c) {
            ctx->pc = 0x16EB0Cu;
            goto label_16eb0c;
        }
    }
    ctx->pc = 0x16EA94u;
    // 0x16ea94: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16ea94u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_16ea98:
    // 0x16ea98: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x16ea98u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ea9c: 0xc05d8d4  jal         func_176350
    ctx->pc = 0x16EA9Cu;
    SET_GPR_U32(ctx, 31, 0x16EAA4u);
    ctx->pc = 0x16EAA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16EA9Cu;
            // 0x16eaa0: 0x27a60004  addiu       $a2, $sp, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176350u;
    if (runtime->hasFunction(0x176350u)) {
        auto targetFn = runtime->lookupFunction(0x176350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EAA4u; }
        if (ctx->pc != 0x16EAA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00176350_0x176350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EAA4u; }
        if (ctx->pc != 0x16EAA4u) { return; }
    }
    ctx->pc = 0x16EAA4u;
label_16eaa4:
    // 0x16eaa4: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x16eaa4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16eaa8: 0x4600018  bltz        $v1, . + 4 + (0x18 << 2)
    ctx->pc = 0x16EAA8u;
    {
        const bool branch_taken_0x16eaa8 = (GPR_S64(ctx, 3) < 0);
        ctx->pc = 0x16EAACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16EAA8u;
            // 0x16eaac: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16eaa8) {
            ctx->pc = 0x16EB0Cu;
            goto label_16eb0c;
        }
    }
    ctx->pc = 0x16EAB0u;
    // 0x16eab0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16eab0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16eab4: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x16eab4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16eab8: 0x27a60008  addiu       $a2, $sp, 0x8
    ctx->pc = 0x16eab8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
    // 0x16eabc: 0xc05bacc  jal         func_16EB30
    ctx->pc = 0x16EABCu;
    SET_GPR_U32(ctx, 31, 0x16EAC4u);
    ctx->pc = 0x16EAC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16EABCu;
            // 0x16eac0: 0x27a7000c  addiu       $a3, $sp, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 12));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16EB30u;
    if (runtime->hasFunction(0x16EB30u)) {
        auto targetFn = runtime->lookupFunction(0x16EB30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EAC4u; }
        if (ctx->pc != 0x16EAC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016EB30_0x16eb30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EAC4u; }
        if (ctx->pc != 0x16EAC4u) { return; }
    }
    ctx->pc = 0x16EAC4u;
label_16eac4:
    // 0x16eac4: 0x260382d  daddu       $a3, $s3, $zero
    ctx->pc = 0x16eac4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16eac8: 0x8fa60008  lw          $a2, 0x8($sp)
    ctx->pc = 0x16eac8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16eacc: 0x8fa2000c  lw          $v0, 0xC($sp)
    ctx->pc = 0x16eaccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x16ead0: 0x2663018  mult        $a2, $s3, $a2
    ctx->pc = 0x16ead0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 19) * (int64_t)GPR_S32(ctx, 6); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 6, (int32_t)result); }
    // 0x16ead4: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x16EAD4u;
    {
        const bool branch_taken_0x16ead4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x16ead4) {
            ctx->pc = 0x16EAD8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16EAD4u;
            // 0x16ead8: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x16EADCu;
            goto label_16eadc;
        }
    }
    ctx->pc = 0x16EADCu;
label_16eadc:
    // 0x16eadc: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x16eadcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16eae0: 0x8fa50004  lw          $a1, 0x4($sp)
    ctx->pc = 0x16eae0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x16eae4: 0xc2001a  div         $zero, $a2, $v0
    ctx->pc = 0x16eae4u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 6);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x16eae8: 0x3012  mflo        $a2
    ctx->pc = 0x16eae8u;
    SET_GPR_U64(ctx, 6, ctx->lo);
    // 0x16eaec: 0xc05407a  jal         func_1501E8
    ctx->pc = 0x16EAECu;
    SET_GPR_U32(ctx, 31, 0x16EAF4u);
    ctx->pc = 0x16EAF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16EAECu;
            // 0x16eaf0: 0x2863023  subu        $a2, $s4, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 20), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1501E8u;
    if (runtime->hasFunction(0x1501E8u)) {
        auto targetFn = runtime->lookupFunction(0x1501E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EAF4u; }
        if (ctx->pc != 0x16EAF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001501E8_0x1501e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16EAF4u; }
        if (ctx->pc != 0x16EAF4u) { return; }
    }
    ctx->pc = 0x16EAF4u;
label_16eaf4:
    // 0x16eaf4: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x16EAF4u;
    {
        const bool branch_taken_0x16eaf4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16EAF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16EAF4u;
            // 0x16eaf8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16eaf4) {
            ctx->pc = 0x16EB0Cu;
            goto label_16eb0c;
        }
    }
    ctx->pc = 0x16EAFCu;
    // 0x16eafc: 0x8ea30084  lw          $v1, 0x84($s5)
    ctx->pc = 0x16eafcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 132)));
    // 0x16eb00: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x16eb00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16eb04: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x16eb04u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x16eb08: 0xaea30084  sw          $v1, 0x84($s5)
    ctx->pc = 0x16eb08u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 132), GPR_U32(ctx, 3));
label_16eb0c:
    // 0x16eb0c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x16eb0cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_16eb10:
    // 0x16eb10: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x16eb10u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16eb14: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x16eb14u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16eb18: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x16eb18u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16eb1c: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x16eb1cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16eb20: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x16eb20u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x16eb24: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x16eb24u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x16eb28: 0x3e00008  jr          $ra
    ctx->pc = 0x16EB28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16EB2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16EB28u;
            // 0x16eb2c: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16EA10u: goto label_16ea10;
            case 0x16EA30u: goto label_16ea30;
            case 0x16EA38u: goto label_16ea38;
            case 0x16EA50u: goto label_16ea50;
            case 0x16EA54u: goto label_16ea54;
            case 0x16EA68u: goto label_16ea68;
            case 0x16EA6Cu: goto label_16ea6c;
            case 0x16EA74u: goto label_16ea74;
            case 0x16EA98u: goto label_16ea98;
            case 0x16EAA4u: goto label_16eaa4;
            case 0x16EAC4u: goto label_16eac4;
            case 0x16EADCu: goto label_16eadc;
            case 0x16EAF4u: goto label_16eaf4;
            case 0x16EB0Cu: goto label_16eb0c;
            case 0x16EB10u: goto label_16eb10;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16EB30u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
