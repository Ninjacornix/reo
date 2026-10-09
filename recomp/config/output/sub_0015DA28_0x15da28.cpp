#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015DA28
// Address: 0x15da28 - 0x15daa8
void sub_0015DA28_0x15da28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015DA28_0x15da28");
#endif

    switch (ctx->pc) {
        case 0x15da40u: goto label_15da40;
        case 0x15da58u: goto label_15da58;
        default: break;
    }

    ctx->pc = 0x15da28u;

    // 0x15da28: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15da28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15da2c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15da2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15da30: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15da30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15da34: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x15da34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x15da38: 0xc057858  jal         func_15E160
    ctx->pc = 0x15DA38u;
    SET_GPR_U32(ctx, 31, 0x15DA40u);
    ctx->pc = 0x15DA3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15DA38u;
            // 0x15da3c: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15E160u;
    if (runtime->hasFunction(0x15E160u)) {
        auto targetFn = runtime->lookupFunction(0x15E160u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DA40u; }
        if (ctx->pc != 0x15DA40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E160_0x15e160(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DA40u; }
        if (ctx->pc != 0x15DA40u) { return; }
    }
    ctx->pc = 0x15DA40u;
label_15da40:
    // 0x15da40: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x15da40u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15da44: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x15da44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15da48: 0x16220011  bne         $s1, $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x15DA48u;
    {
        const bool branch_taken_0x15da48 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        ctx->pc = 0x15DA4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15DA48u;
            // 0x15da4c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15da48) {
            ctx->pc = 0x15DA90u;
            goto label_15da90;
        }
    }
    ctx->pc = 0x15DA50u;
    // 0x15da50: 0xc05882a  jal         func_1620A8
    ctx->pc = 0x15DA50u;
    SET_GPR_U32(ctx, 31, 0x15DA58u);
    ctx->pc = 0x1620A8u;
    if (runtime->hasFunction(0x1620A8u)) {
        auto targetFn = runtime->lookupFunction(0x1620A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DA58u; }
        if (ctx->pc != 0x15DA58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001620A8_0x1620a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15DA58u; }
        if (ctx->pc != 0x15DA58u) { return; }
    }
    ctx->pc = 0x15DA58u;
label_15da58:
    // 0x15da58: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x15da58u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15da5c: 0x14510006  bne         $v0, $s1, . + 4 + (0x6 << 2)
    ctx->pc = 0x15DA5Cu;
    {
        const bool branch_taken_0x15da5c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 17));
        ctx->pc = 0x15DA60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15DA5Cu;
            // 0x15da60: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15da5c) {
            ctx->pc = 0x15DA78u;
            goto label_15da78;
        }
    }
    ctx->pc = 0x15DA64u;
    // 0x15da64: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15da64u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15da68: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15da68u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15da6c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15da6cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15da70: 0x8058564  j           func_161590
    ctx->pc = 0x15DA70u;
    ctx->pc = 0x15DA74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15DA70u;
            // 0x15da74: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x161590u;
    if (runtime->hasFunction(0x161590u)) {
        auto targetFn = runtime->lookupFunction(0x161590u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00161590_0x161590(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15DA78u;
label_15da78:
    // 0x15da78: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15da78u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15da7c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15da7cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15da80: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x15da80u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15da84: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15da84u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15da88: 0x8058564  j           func_161590
    ctx->pc = 0x15DA88u;
    ctx->pc = 0x15DA8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15DA88u;
            // 0x15da8c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x161590u;
    if (runtime->hasFunction(0x161590u)) {
        auto targetFn = runtime->lookupFunction(0x161590u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00161590_0x161590(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15DA90u;
label_15da90:
    // 0x15da90: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15da90u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15da94: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15da94u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15da98: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15da98u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15da9c: 0x3e00008  jr          $ra
    ctx->pc = 0x15DA9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15DAA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15DA9Cu;
            // 0x15daa0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15DA40u: goto label_15da40;
            case 0x15DA58u: goto label_15da58;
            case 0x15DA78u: goto label_15da78;
            case 0x15DA90u: goto label_15da90;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15DAA4u;
    // 0x15daa4: 0x0  nop
    ctx->pc = 0x15daa4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
