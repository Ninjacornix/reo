#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013EAC0
// Address: 0x13eac0 - 0x13eb88
void sub_0013EAC0_0x13eac0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013EAC0_0x13eac0");
#endif

    switch (ctx->pc) {
        case 0x13eaf0u: goto label_13eaf0;
        case 0x13eb00u: goto label_13eb00;
        case 0x13eb34u: goto label_13eb34;
        case 0x13eb48u: goto label_13eb48;
        case 0x13eb58u: goto label_13eb58;
        default: break;
    }

    ctx->pc = 0x13eac0u;

    // 0x13eac0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x13eac0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x13eac4: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x13eac4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x13eac8: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x13eac8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13eacc: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x13eaccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x13ead0: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x13ead0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x13ead4: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x13ead4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x13ead8: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x13ead8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13eadc: 0x1860000d  blez        $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x13EADCu;
    {
        const bool branch_taken_0x13eadc = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x13EAE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EADCu;
            // 0x13eae0: 0x902d  daddu       $s2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13eadc) {
            ctx->pc = 0x13EB14u;
            goto label_13eb14;
        }
    }
    ctx->pc = 0x13EAE4u;
    // 0x13eae4: 0x26300010  addiu       $s0, $s1, 0x10
    ctx->pc = 0x13eae4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 16));
    // 0x13eae8: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x13eae8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13eaec: 0x0  nop
    ctx->pc = 0x13eaecu;
    // NOP
label_13eaf0:
    // 0x13eaf0: 0x10800004  beqz        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x13EAF0u;
    {
        const bool branch_taken_0x13eaf0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x13EAF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EAF0u;
            // 0x13eaf4: 0x26100004  addiu       $s0, $s0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13eaf0) {
            ctx->pc = 0x13EB04u;
            goto label_13eb04;
        }
    }
    ctx->pc = 0x13EAF8u;
    // 0x13eaf8: 0xc04e2ea  jal         func_138BA8
    ctx->pc = 0x13EAF8u;
    SET_GPR_U32(ctx, 31, 0x13EB00u);
    ctx->pc = 0x138BA8u;
    if (runtime->hasFunction(0x138BA8u)) {
        auto targetFn = runtime->lookupFunction(0x138BA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EB00u; }
        if (ctx->pc != 0x13EB00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138BA8_0x138ba8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EB00u; }
        if (ctx->pc != 0x13EB00u) { return; }
    }
    ctx->pc = 0x13EB00u;
label_13eb00:
    // 0x13eb00: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x13eb00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
label_13eb04:
    // 0x13eb04: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x13eb04u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x13eb08: 0x243102a  slt         $v0, $s2, $v1
    ctx->pc = 0x13eb08u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x13eb0c: 0x5440fff8  bnel        $v0, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x13EB0Cu;
    {
        const bool branch_taken_0x13eb0c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x13eb0c) {
            ctx->pc = 0x13EB10u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13EB0Cu;
            // 0x13eb10: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13EAF0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13eaf0;
        }
    }
    ctx->pc = 0x13EB14u;
label_13eb14:
    // 0x13eb14: 0x8e220020  lw          $v0, 0x20($s1)
    ctx->pc = 0x13eb14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x13eb18: 0x24040009  addiu       $a0, $zero, 0x9
    ctx->pc = 0x13eb18u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x13eb1c: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x13eb1cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13eb20: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x13eb20u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13eb24: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x13eb24u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13eb28: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x13eb28u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13eb2c: 0xc04e518  jal         func_139460
    ctx->pc = 0x13EB2Cu;
    SET_GPR_U32(ctx, 31, 0x13EB34u);
    ctx->pc = 0x13EB30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13EB2Cu;
            // 0x13eb30: 0xafa20000  sw          $v0, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139460u;
    if (runtime->hasFunction(0x139460u)) {
        auto targetFn = runtime->lookupFunction(0x139460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EB34u; }
        if (ctx->pc != 0x13EB34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139460_0x139460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EB34u; }
        if (ctx->pc != 0x13EB34u) { return; }
    }
    ctx->pc = 0x13EB34u;
label_13eb34:
    // 0x13eb34: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x13eb34u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13eb38: 0x1860000c  blez        $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x13EB38u;
    {
        const bool branch_taken_0x13eb38 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x13EB3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EB38u;
            // 0x13eb3c: 0x902d  daddu       $s2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13eb38) {
            ctx->pc = 0x13EB6Cu;
            goto label_13eb6c;
        }
    }
    ctx->pc = 0x13EB40u;
    // 0x13eb40: 0x26300008  addiu       $s0, $s1, 0x8
    ctx->pc = 0x13eb40u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 8));
    // 0x13eb44: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x13eb44u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_13eb48:
    // 0x13eb48: 0x10800004  beqz        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x13EB48u;
    {
        const bool branch_taken_0x13eb48 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x13EB4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EB48u;
            // 0x13eb4c: 0x26100004  addiu       $s0, $s0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13eb48) {
            ctx->pc = 0x13EB5Cu;
            goto label_13eb5c;
        }
    }
    ctx->pc = 0x13EB50u;
    // 0x13eb50: 0xc04f7e6  jal         func_13DF98
    ctx->pc = 0x13EB50u;
    SET_GPR_U32(ctx, 31, 0x13EB58u);
    ctx->pc = 0x13DF98u;
    if (runtime->hasFunction(0x13DF98u)) {
        auto targetFn = runtime->lookupFunction(0x13DF98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EB58u; }
        if (ctx->pc != 0x13EB58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013DF98_0x13df98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EB58u; }
        if (ctx->pc != 0x13EB58u) { return; }
    }
    ctx->pc = 0x13EB58u;
label_13eb58:
    // 0x13eb58: 0x8e230004  lw          $v1, 0x4($s1)
    ctx->pc = 0x13eb58u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
label_13eb5c:
    // 0x13eb5c: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x13eb5cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x13eb60: 0x243102a  slt         $v0, $s2, $v1
    ctx->pc = 0x13eb60u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x13eb64: 0x5440fff8  bnel        $v0, $zero, . + 4 + (-0x8 << 2)
    ctx->pc = 0x13EB64u;
    {
        const bool branch_taken_0x13eb64 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x13eb64) {
            ctx->pc = 0x13EB68u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13EB64u;
            // 0x13eb68: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13EB48u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13eb48;
        }
    }
    ctx->pc = 0x13EB6Cu;
label_13eb6c:
    // 0x13eb6c: 0xa2200000  sb          $zero, 0x0($s1)
    ctx->pc = 0x13eb6cu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x13eb70: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x13eb70u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13eb74: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x13eb74u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13eb78: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x13eb78u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13eb7c: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x13eb7cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x13eb80: 0x3e00008  jr          $ra
    ctx->pc = 0x13EB80u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13EB84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EB80u;
            // 0x13eb84: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13EAF0u: goto label_13eaf0;
            case 0x13EB00u: goto label_13eb00;
            case 0x13EB04u: goto label_13eb04;
            case 0x13EB14u: goto label_13eb14;
            case 0x13EB34u: goto label_13eb34;
            case 0x13EB48u: goto label_13eb48;
            case 0x13EB58u: goto label_13eb58;
            case 0x13EB5Cu: goto label_13eb5c;
            case 0x13EB6Cu: goto label_13eb6c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13EB88u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
