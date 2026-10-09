#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016FF20
// Address: 0x16ff20 - 0x16ffc0
void sub_0016FF20_0x16ff20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016FF20_0x16ff20");
#endif

    switch (ctx->pc) {
        case 0x16ff44u: goto label_16ff44;
        case 0x16ff68u: goto label_16ff68;
        case 0x16ff90u: goto label_16ff90;
        default: break;
    }

    ctx->pc = 0x16ff20u;

    // 0x16ff20: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x16ff20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x16ff24: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x16ff24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x16ff28: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x16ff28u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ff2c: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x16ff2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x16ff30: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x16ff30u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ff34: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x16ff34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x16ff38: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x16ff38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x16ff3c: 0xc05c164  jal         func_170590
    ctx->pc = 0x16FF3Cu;
    SET_GPR_U32(ctx, 31, 0x16FF44u);
    ctx->pc = 0x16FF40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16FF3Cu;
            // 0x16ff40: 0x26120cc0  addiu       $s2, $s0, 0xCC0 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), 3264));
        ctx->in_delay_slot = false;
    ctx->pc = 0x170590u;
    if (runtime->hasFunction(0x170590u)) {
        auto targetFn = runtime->lookupFunction(0x170590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16FF44u; }
        if (ctx->pc != 0x16FF44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00170590_0x170590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16FF44u; }
        if (ctx->pc != 0x16FF44u) { return; }
    }
    ctx->pc = 0x16FF44u;
label_16ff44:
    // 0x16ff44: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x16ff44u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x16ff48: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x16ff48u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ff4c: 0x14430004  bne         $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x16FF4Cu;
    {
        const bool branch_taken_0x16ff4c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x16FF50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16FF4Cu;
            // 0x16ff50: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16ff4c) {
            ctx->pc = 0x16FF60u;
            goto label_16ff60;
        }
    }
    ctx->pc = 0x16FF54u;
    // 0x16ff54: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x16ff54u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x16ff58: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x16FF58u;
    {
        const bool branch_taken_0x16ff58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16FF5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16FF58u;
            // 0x16ff5c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16ff58) {
            ctx->pc = 0x16FFA8u;
            goto label_16ffa8;
        }
    }
    ctx->pc = 0x16FF60u;
label_16ff60:
    // 0x16ff60: 0xc05c1d8  jal         func_170760
    ctx->pc = 0x16FF60u;
    SET_GPR_U32(ctx, 31, 0x16FF68u);
    ctx->pc = 0x170760u;
    if (runtime->hasFunction(0x170760u)) {
        auto targetFn = runtime->lookupFunction(0x170760u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16FF68u; }
        if (ctx->pc != 0x16FF68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00170760_0x170760(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16FF68u; }
        if (ctx->pc != 0x16FF68u) { return; }
    }
    ctx->pc = 0x16FF68u;
label_16ff68:
    // 0x16ff68: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16ff68u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ff6c: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x16ff6cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ff70: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x16ff70u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ff74: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x16FF74u;
    {
        const bool branch_taken_0x16ff74 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x16FF78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16FF74u;
            // 0x16ff78: 0x60282d  daddu       $a1, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16ff74) {
            ctx->pc = 0x16FF88u;
            goto label_16ff88;
        }
    }
    ctx->pc = 0x16FF7Cu;
    // 0x16ff7c: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x16FF7Cu;
    {
        const bool branch_taken_0x16ff7c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16FF80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16FF7Cu;
            // 0x16ff80: 0xae200000  sw          $zero, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16ff7c) {
            ctx->pc = 0x16FFA8u;
            goto label_16ffa8;
        }
    }
    ctx->pc = 0x16FF84u;
    // 0x16ff84: 0x0  nop
    ctx->pc = 0x16ff84u;
    // NOP
label_16ff88:
    // 0x16ff88: 0xc05bff0  jal         func_16FFC0
    ctx->pc = 0x16FF88u;
    SET_GPR_U32(ctx, 31, 0x16FF90u);
    ctx->pc = 0x16FFC0u;
    if (runtime->hasFunction(0x16FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x16FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16FF90u; }
        if (ctx->pc != 0x16FF90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016FFC0_0x16ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16FF90u; }
        if (ctx->pc != 0x16FF90u) { return; }
    }
    ctx->pc = 0x16FF90u;
label_16ff90:
    // 0x16ff90: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x16ff90u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ff94: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x16ff94u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x16ff98: 0x8c640014  lw          $a0, 0x14($v1)
    ctx->pc = 0x16ff98u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 20)));
    // 0x16ff9c: 0xae440238  sw          $a0, 0x238($s2)
    ctx->pc = 0x16ff9cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 568), GPR_U32(ctx, 4));
    // 0x16ffa0: 0x8c650018  lw          $a1, 0x18($v1)
    ctx->pc = 0x16ffa0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x16ffa4: 0xae45023c  sw          $a1, 0x23C($s2)
    ctx->pc = 0x16ffa4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 572), GPR_U32(ctx, 5));
label_16ffa8:
    // 0x16ffa8: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x16ffa8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16ffac: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x16ffacu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16ffb0: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x16ffb0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16ffb4: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x16ffb4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16ffb8: 0x3e00008  jr          $ra
    ctx->pc = 0x16FFB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16FFBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16FFB8u;
            // 0x16ffbc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16FF44u: goto label_16ff44;
            case 0x16FF60u: goto label_16ff60;
            case 0x16FF68u: goto label_16ff68;
            case 0x16FF88u: goto label_16ff88;
            case 0x16FF90u: goto label_16ff90;
            case 0x16FFA8u: goto label_16ffa8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16FFC0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
