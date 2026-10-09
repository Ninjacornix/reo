#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CED20
// Address: 0x1ced20 - 0x1cedf0
void sub_001CED20_0x1ced20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CED20_0x1ced20");
#endif

    switch (ctx->pc) {
        case 0x1ced3cu: goto label_1ced3c;
        case 0x1cedd8u: goto label_1cedd8;
        default: break;
    }

    ctx->pc = 0x1ced20u;

    // 0x1ced20: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1ced20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1ced24: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1ced24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1ced28: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1ced28u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1ced2c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1ced2cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ced30: 0x30a400ff  andi        $a0, $a1, 0xFF
    ctx->pc = 0x1ced30u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x1ced34: 0xc073ba4  jal         func_1CEE90
    ctx->pc = 0x1CED34u;
    SET_GPR_U32(ctx, 31, 0x1CED3Cu);
    ctx->pc = 0x1CED38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CED34u;
            // 0x1ced38: 0x30c5ffff  andi        $a1, $a2, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CEE90u;
    if (runtime->hasFunction(0x1CEE90u)) {
        auto targetFn = runtime->lookupFunction(0x1CEE90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CED3Cu; }
        if (ctx->pc != 0x1CED3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CEE90_0x1cee90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CED3Cu; }
        if (ctx->pc != 0x1CED3Cu) { return; }
    }
    ctx->pc = 0x1CED3Cu;
label_1ced3c:
    // 0x1ced3c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1ced3cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ced40: 0x10800025  beqz        $a0, . + 4 + (0x25 << 2)
    ctx->pc = 0x1CED40u;
    {
        const bool branch_taken_0x1ced40 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CED44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CED40u;
            // 0x1ced44: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ced40) {
            ctx->pc = 0x1CEDD8u;
            goto label_1cedd8;
        }
    }
    ctx->pc = 0x1CED48u;
    // 0x1ced48: 0x16030010  bne         $s0, $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1CED48u;
    {
        const bool branch_taken_0x1ced48 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 3));
        if (branch_taken_0x1ced48) {
            ctx->pc = 0x1CED8Cu;
            goto label_1ced8c;
        }
    }
    ctx->pc = 0x1CED50u;
    // 0x1ced50: 0x90850003  lbu         $a1, 0x3($a0)
    ctx->pc = 0x1ced50u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3)));
    // 0x1ced54: 0x30a30002  andi        $v1, $a1, 0x2
    ctx->pc = 0x1ced54u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)2);
    // 0x1ced58: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CED58u;
    {
        const bool branch_taken_0x1ced58 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CED5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CED58u;
            // 0x1ced5c: 0x30a30004  andi        $v1, $a1, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)4);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ced58) {
            ctx->pc = 0x1CED68u;
            goto label_1ced68;
        }
    }
    ctx->pc = 0x1CED60u;
    // 0x1ced60: 0x1060000a  beqz        $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x1CED60u;
    {
        const bool branch_taken_0x1ced60 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ced60) {
            ctx->pc = 0x1CED8Cu;
            goto label_1ced8c;
        }
    }
    ctx->pc = 0x1CED68u;
label_1ced68:
    // 0x1ced68: 0x90860000  lbu         $a2, 0x0($a0)
    ctx->pc = 0x1ced68u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ced6c: 0x2001827  not         $v1, $s0
    ctx->pc = 0x1ced6cu;
    SET_GPR_U64(ctx, 3, ~(GPR_U64(ctx, 16) | GPR_U64(ctx, 0)));
    // 0x1ced70: 0x306500ff  andi        $a1, $v1, 0xFF
    ctx->pc = 0x1ced70u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x1ced74: 0x24c3ffff  addiu       $v1, $a2, -0x1
    ctx->pc = 0x1ced74u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x1ced78: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x1ced78u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ced7c: 0x90830003  lbu         $v1, 0x3($a0)
    ctx->pc = 0x1ced7cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3)));
    // 0x1ced80: 0x651824  and         $v1, $v1, $a1
    ctx->pc = 0x1ced80u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 5));
    // 0x1ced84: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1CED84u;
    {
        const bool branch_taken_0x1ced84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CED88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CED84u;
            // 0x1ced88: 0xa0830003  sb          $v1, 0x3($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 3), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ced84) {
            ctx->pc = 0x1CEDD8u;
            goto label_1cedd8;
        }
    }
    ctx->pc = 0x1CED8Cu;
label_1ced8c:
    // 0x1ced8c: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1ced8cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1ced90: 0x1603000e  bne         $s0, $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x1CED90u;
    {
        const bool branch_taken_0x1ced90 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 3));
        if (branch_taken_0x1ced90) {
            ctx->pc = 0x1CEDCCu;
            goto label_1cedcc;
        }
    }
    ctx->pc = 0x1CED98u;
    // 0x1ced98: 0x90830003  lbu         $v1, 0x3($a0)
    ctx->pc = 0x1ced98u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3)));
    // 0x1ced9c: 0x30630002  andi        $v1, $v1, 0x2
    ctx->pc = 0x1ced9cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)2);
    // 0x1ceda0: 0x1060000a  beqz        $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x1CEDA0u;
    {
        const bool branch_taken_0x1ceda0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ceda0) {
            ctx->pc = 0x1CEDCCu;
            goto label_1cedcc;
        }
    }
    ctx->pc = 0x1CEDA8u;
    // 0x1ceda8: 0x90860000  lbu         $a2, 0x0($a0)
    ctx->pc = 0x1ceda8u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1cedac: 0x2001827  not         $v1, $s0
    ctx->pc = 0x1cedacu;
    SET_GPR_U64(ctx, 3, ~(GPR_U64(ctx, 16) | GPR_U64(ctx, 0)));
    // 0x1cedb0: 0x306500ff  andi        $a1, $v1, 0xFF
    ctx->pc = 0x1cedb0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x1cedb4: 0x24c3ffff  addiu       $v1, $a2, -0x1
    ctx->pc = 0x1cedb4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x1cedb8: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x1cedb8u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1cedbc: 0x90830003  lbu         $v1, 0x3($a0)
    ctx->pc = 0x1cedbcu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3)));
    // 0x1cedc0: 0x651824  and         $v1, $v1, $a1
    ctx->pc = 0x1cedc0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 5));
    // 0x1cedc4: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1CEDC4u;
    {
        const bool branch_taken_0x1cedc4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CEDC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEDC4u;
            // 0x1cedc8: 0xa0830003  sb          $v1, 0x3($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 3), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cedc4) {
            ctx->pc = 0x1CEDD8u;
            goto label_1cedd8;
        }
    }
    ctx->pc = 0x1CEDCCu;
label_1cedcc:
    // 0x1cedcc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1cedccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1cedd0: 0xc073b90  jal         func_1CEE40
    ctx->pc = 0x1CEDD0u;
    SET_GPR_U32(ctx, 31, 0x1CEDD8u);
    ctx->pc = 0x1CEDD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEDD0u;
            // 0x1cedd4: 0xa0820000  sb          $v0, 0x0($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CEE40u;
    if (runtime->hasFunction(0x1CEE40u)) {
        auto targetFn = runtime->lookupFunction(0x1CEE40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CEDD8u; }
        if (ctx->pc != 0x1CEDD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CEE40_0x1cee40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CEDD8u; }
        if (ctx->pc != 0x1CEDD8u) { return; }
    }
    ctx->pc = 0x1CEDD8u;
label_1cedd8:
    // 0x1cedd8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1cedd8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ceddc: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ceddcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cede0: 0x3e00008  jr          $ra
    ctx->pc = 0x1CEDE0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CEDE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CEDE0u;
            // 0x1cede4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CED3Cu: goto label_1ced3c;
            case 0x1CED68u: goto label_1ced68;
            case 0x1CED8Cu: goto label_1ced8c;
            case 0x1CEDCCu: goto label_1cedcc;
            case 0x1CEDD8u: goto label_1cedd8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CEDE8u;
    // 0x1cede8: 0x0  nop
    ctx->pc = 0x1cede8u;
    // NOP
    // 0x1cedec: 0x0  nop
    ctx->pc = 0x1cedecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
