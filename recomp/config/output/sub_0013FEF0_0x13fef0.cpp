#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013FEF0
// Address: 0x13fef0 - 0x13ffb8
void sub_0013FEF0_0x13fef0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013FEF0_0x13fef0");
#endif

    switch (ctx->pc) {
        case 0x13ff1cu: goto label_13ff1c;
        case 0x13ff8cu: goto label_13ff8c;
        case 0x13ff94u: goto label_13ff94;
        default: break;
    }

    ctx->pc = 0x13fef0u;

    // 0x13fef0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x13fef0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x13fef4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13fef4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13fef8: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x13fef8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13fefc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13fefcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13ff00: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x13ff00u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ff04: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13ff04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13ff08: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x13ff08u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ff0c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x13ff0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x13ff10: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x13ff10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x13ff14: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x13FF14u;
    SET_GPR_U32(ctx, 31, 0x13FF1Cu);
    ctx->pc = 0x13FF18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13FF14u;
            // 0x13ff18: 0xe0982d  daddu       $s3, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13FF1Cu; }
        if (ctx->pc != 0x13FF1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13FF1Cu; }
        if (ctx->pc != 0x13FF1Cu) { return; }
    }
    ctx->pc = 0x13FF1Cu;
label_13ff1c:
    // 0x13ff1c: 0x16000008  bnez        $s0, . + 4 + (0x8 << 2)
    ctx->pc = 0x13FF1Cu;
    {
        const bool branch_taken_0x13ff1c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x13FF20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FF1Cu;
            // 0x13ff20: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ff1c) {
            ctx->pc = 0x13FF40u;
            goto label_13ff40;
        }
    }
    ctx->pc = 0x13FF24u;
    // 0x13ff24: 0x8e220014  lw          $v0, 0x14($s1)
    ctx->pc = 0x13ff24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x13ff28: 0x8e230020  lw          $v1, 0x20($s1)
    ctx->pc = 0x13ff28u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x13ff2c: 0x8e250024  lw          $a1, 0x24($s1)
    ctx->pc = 0x13ff2cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x13ff30: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x13ff30u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x13ff34: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x13FF34u;
    {
        const bool branch_taken_0x13ff34 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13FF38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FF34u;
            // 0x13ff38: 0x8e240010  lw          $a0, 0x10($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ff34) {
            ctx->pc = 0x13FF5Cu;
            goto label_13ff5c;
        }
    }
    ctx->pc = 0x13FF3Cu;
    // 0x13ff3c: 0x0  nop
    ctx->pc = 0x13ff3cu;
    // NOP
label_13ff40:
    // 0x13ff40: 0x5602000d  bnel        $s0, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x13FF40u;
    {
        const bool branch_taken_0x13ff40 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        if (branch_taken_0x13ff40) {
            ctx->pc = 0x13FF44u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13FF40u;
            // 0x13ff44: 0x8e220038  lw          $v0, 0x38($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 56)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13FF78u;
            goto label_13ff78;
        }
    }
    ctx->pc = 0x13FF48u;
    // 0x13ff48: 0x8e220018  lw          $v0, 0x18($s1)
    ctx->pc = 0x13ff48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x13ff4c: 0x8e230020  lw          $v1, 0x20($s1)
    ctx->pc = 0x13ff4cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x13ff50: 0x8e250024  lw          $a1, 0x24($s1)
    ctx->pc = 0x13ff50u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x13ff54: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x13ff54u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x13ff58: 0x8e24000c  lw          $a0, 0xC($s1)
    ctx->pc = 0x13ff58u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
label_13ff5c:
    // 0x13ff5c: 0x658021  addu        $s0, $v1, $a1
    ctx->pc = 0x13ff5cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x13ff60: 0x90102a  slt         $v0, $a0, $s0
    ctx->pc = 0x13ff60u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x13ff64: 0x82800b  movn        $s0, $a0, $v0
    ctx->pc = 0x13ff64u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 4));
    // 0x13ff68: 0x212182a  slt         $v1, $s0, $s2
    ctx->pc = 0x13ff68u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x13ff6c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x13FF6Cu;
    {
        const bool branch_taken_0x13ff6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13FF70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FF6Cu;
            // 0x13ff70: 0x243800a  movz        $s0, $s2, $v1 (Delay Slot)
        if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ff6c) {
            ctx->pc = 0x13FF8Cu;
            goto label_13ff8c;
        }
    }
    ctx->pc = 0x13FF74u;
    // 0x13ff74: 0x0  nop
    ctx->pc = 0x13ff74u;
    // NOP
label_13ff78:
    // 0x13ff78: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x13FF78u;
    {
        const bool branch_taken_0x13ff78 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13FF7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FF78u;
            // 0x13ff7c: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ff78) {
            ctx->pc = 0x13FF8Cu;
            goto label_13ff8c;
        }
    }
    ctx->pc = 0x13FF80u;
    // 0x13ff80: 0x8e24003c  lw          $a0, 0x3C($s1)
    ctx->pc = 0x13ff80u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 60)));
    // 0x13ff84: 0x40f809  jalr        $v0
    ctx->pc = 0x13FF84u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13FF8Cu);
        ctx->pc = 0x13FF88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FF84u;
            // 0x13ff88: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13FF8Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13FF1Cu: goto label_13ff1c;
            case 0x13FF40u: goto label_13ff40;
            case 0x13FF5Cu: goto label_13ff5c;
            case 0x13FF78u: goto label_13ff78;
            case 0x13FF8Cu: goto label_13ff8c;
            case 0x13FF94u: goto label_13ff94;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13FF8Cu; }
            if (ctx->pc != 0x13FF8Cu) { return; }
        }
        }
    }
    ctx->pc = 0x13FF8Cu;
label_13ff8c:
    // 0x13ff8c: 0xc04fc9c  jal         func_13F270
    ctx->pc = 0x13FF8Cu;
    SET_GPR_U32(ctx, 31, 0x13FF94u);
    ctx->pc = 0x13FF90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13FF8Cu;
            // 0x13ff90: 0xae700000  sw          $s0, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13FF94u; }
        if (ctx->pc != 0x13FF94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F270_0x13f270(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13FF94u; }
        if (ctx->pc != 0x13FF94u) { return; }
    }
    ctx->pc = 0x13FF94u;
label_13ff94:
    // 0x13ff94: 0x2121026  xor         $v0, $s0, $s2
    ctx->pc = 0x13ff94u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) ^ GPR_U64(ctx, 18));
    // 0x13ff98: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13ff98u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13ff9c: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x13ff9cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x13ffa0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13ffa0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13ffa4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13ffa4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13ffa8: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x13ffa8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13ffac: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x13ffacu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13ffb0: 0x3e00008  jr          $ra
    ctx->pc = 0x13FFB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13FFB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13FFB0u;
            // 0x13ffb4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13FF1Cu: goto label_13ff1c;
            case 0x13FF40u: goto label_13ff40;
            case 0x13FF5Cu: goto label_13ff5c;
            case 0x13FF78u: goto label_13ff78;
            case 0x13FF8Cu: goto label_13ff8c;
            case 0x13FF94u: goto label_13ff94;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13FFB8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
