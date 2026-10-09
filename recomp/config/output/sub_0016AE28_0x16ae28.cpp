#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016AE28
// Address: 0x16ae28 - 0x16aea0
void sub_0016AE28_0x16ae28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016AE28_0x16ae28");
#endif

    switch (ctx->pc) {
        case 0x16ae54u: goto label_16ae54;
        case 0x16ae64u: goto label_16ae64;
        case 0x16ae7cu: goto label_16ae7c;
        default: break;
    }

    ctx->pc = 0x16ae28u;

    // 0x16ae28: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x16ae28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x16ae2c: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x16ae2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x16ae30: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x16ae30u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ae34: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x16ae34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x16ae38: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x16ae38u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ae3c: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x16ae3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x16ae40: 0x3a0382d  daddu       $a3, $sp, $zero
    ctx->pc = 0x16ae40u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ae44: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x16ae44u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x16ae48: 0x8c620018  lw          $v0, 0x18($v1)
    ctx->pc = 0x16ae48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x16ae4c: 0x40f809  jalr        $v0
    ctx->pc = 0x16AE4Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x16AE54u);
        ctx->pc = 0x16AE50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16AE4Cu;
            // 0x16ae50: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x16AE54u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16AE54u: goto label_16ae54;
            case 0x16AE64u: goto label_16ae64;
            case 0x16AE7Cu: goto label_16ae7c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x16AE54u; }
            if (ctx->pc != 0x16AE54u) { return; }
        }
        }
    }
    ctx->pc = 0x16AE54u;
label_16ae54:
    // 0x16ae54: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x16ae54u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ae58: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x16ae58u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16ae5c: 0xc055798  jal         func_155E60
    ctx->pc = 0x16AE5Cu;
    SET_GPR_U32(ctx, 31, 0x16AE64u);
    ctx->pc = 0x16AE60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16AE5Cu;
            // 0x16ae60: 0x8fa60004  lw          $a2, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155E60u;
    if (runtime->hasFunction(0x155E60u)) {
        auto targetFn = runtime->lookupFunction(0x155E60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AE64u; }
        if (ctx->pc != 0x16AE64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00155E60_0x155e60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AE64u; }
        if (ctx->pc != 0x16AE64u) { return; }
    }
    ctx->pc = 0x16AE64u;
label_16ae64:
    // 0x16ae64: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x16ae64u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x16ae68: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16ae68u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ae6c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x16ae6cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16ae70: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x16ae70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x16ae74: 0x40f809  jalr        $v0
    ctx->pc = 0x16AE74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x16AE7Cu);
        ctx->pc = 0x16AE78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16AE74u;
            // 0x16ae78: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x16AE7Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16AE54u: goto label_16ae54;
            case 0x16AE64u: goto label_16ae64;
            case 0x16AE7Cu: goto label_16ae7c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x16AE7Cu; }
            if (ctx->pc != 0x16AE7Cu) { return; }
        }
        }
    }
    ctx->pc = 0x16AE7Cu;
label_16ae7c:
    // 0x16ae7c: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x16ae7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x16ae80: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x16ae80u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16ae84: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x16ae84u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16ae88: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x16ae88u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16ae8c: 0x3e00008  jr          $ra
    ctx->pc = 0x16AE8Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16AE90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16AE8Cu;
            // 0x16ae90: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16AE54u: goto label_16ae54;
            case 0x16AE64u: goto label_16ae64;
            case 0x16AE7Cu: goto label_16ae7c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16AE94u;
    // 0x16ae94: 0x0  nop
    ctx->pc = 0x16ae94u;
    // NOP
    // 0x16ae98: 0x3e00008  jr          $ra
    ctx->pc = 0x16AE98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16AE9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16AE98u;
            // 0x16ae9c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16AE54u: goto label_16ae54;
            case 0x16AE64u: goto label_16ae64;
            case 0x16AE7Cu: goto label_16ae7c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16AEA0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
