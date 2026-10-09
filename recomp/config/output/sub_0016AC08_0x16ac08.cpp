#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016AC08
// Address: 0x16ac08 - 0x16aca4
void sub_0016AC08_0x16ac08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016AC08_0x16ac08");
#endif

    switch (ctx->pc) {
        case 0x16ac38u: goto label_16ac38;
        case 0x16ac54u: goto label_16ac54;
        case 0x16ac74u: goto label_16ac74;
        case 0x16ac88u: goto label_16ac88;
        default: break;
    }

    ctx->pc = 0x16ac08u;

    // 0x16ac08: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x16ac08u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x16ac0c: 0x3a0402d  daddu       $t0, $sp, $zero
    ctx->pc = 0x16ac0cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ac10: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x16ac10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x16ac14: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x16ac14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x16ac18: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x16ac18u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ac1c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x16ac1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x16ac20: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x16ac20u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ac24: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x16ac24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x16ac28: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x16ac28u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ac2c: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x16ac2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x16ac30: 0xc05a3e2  jal         func_168F88
    ctx->pc = 0x16AC30u;
    SET_GPR_U32(ctx, 31, 0x16AC38u);
    ctx->pc = 0x16AC34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16AC30u;
            // 0x16ac34: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x168F88u;
    if (runtime->hasFunction(0x168F88u)) {
        auto targetFn = runtime->lookupFunction(0x168F88u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AC38u; }
        if (ctx->pc != 0x16AC38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00168F88_0x168f88(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AC38u; }
        if (ctx->pc != 0x16AC38u) { return; }
    }
    ctx->pc = 0x16AC38u;
label_16ac38:
    // 0x16ac38: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x16ac38u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ac3c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x16ac3cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ac40: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x16ac40u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ac44: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x16AC44u;
    {
        const bool branch_taken_0x16ac44 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16AC48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16AC44u;
            // 0x16ac48: 0x260382d  daddu       $a3, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16ac44) {
            ctx->pc = 0x16AC80u;
            goto label_16ac80;
        }
    }
    ctx->pc = 0x16AC4Cu;
    // 0x16ac4c: 0xc05aebc  jal         func_16BAF0
    ctx->pc = 0x16AC4Cu;
    SET_GPR_U32(ctx, 31, 0x16AC54u);
    ctx->pc = 0x16BAF0u;
    if (runtime->hasFunction(0x16BAF0u)) {
        auto targetFn = runtime->lookupFunction(0x16BAF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AC54u; }
        if (ctx->pc != 0x16AC54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016BAF0_0x16baf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AC54u; }
        if (ctx->pc != 0x16AC54u) { return; }
    }
    ctx->pc = 0x16AC54u;
label_16ac54:
    // 0x16ac54: 0x2646ffee  addiu       $a2, $s2, -0x12
    ctx->pc = 0x16ac54u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967278));
    // 0x16ac58: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x16ac58u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16ac5c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x16ac5cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ac60: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x16ac60u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16ac64: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x16AC64u;
    {
        const bool branch_taken_0x16ac64 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16AC68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16AC64u;
            // 0x16ac68: 0x26670012  addiu       $a3, $s3, 0x12 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 19), 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16ac64) {
            ctx->pc = 0x16AC74u;
            goto label_16ac74;
        }
    }
    ctx->pc = 0x16AC6Cu;
    // 0x16ac6c: 0xc05ab2a  jal         func_16ACA8
    ctx->pc = 0x16AC6Cu;
    SET_GPR_U32(ctx, 31, 0x16AC74u);
    ctx->pc = 0x16ACA8u;
    if (runtime->hasFunction(0x16ACA8u)) {
        auto targetFn = runtime->lookupFunction(0x16ACA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AC74u; }
        if (ctx->pc != 0x16AC74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016ACA8_0x16aca8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AC74u; }
        if (ctx->pc != 0x16AC74u) { return; }
    }
    ctx->pc = 0x16AC74u;
label_16ac74:
    // 0x16ac74: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x16AC74u;
    {
        const bool branch_taken_0x16ac74 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16AC78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16AC74u;
            // 0x16ac78: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16ac74) {
            ctx->pc = 0x16AC88u;
            goto label_16ac88;
        }
    }
    ctx->pc = 0x16AC7Cu;
    // 0x16ac7c: 0x0  nop
    ctx->pc = 0x16ac7cu;
    // NOP
label_16ac80:
    // 0x16ac80: 0xc05ab2a  jal         func_16ACA8
    ctx->pc = 0x16AC80u;
    SET_GPR_U32(ctx, 31, 0x16AC88u);
    ctx->pc = 0x16AC84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16AC80u;
            // 0x16ac84: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16ACA8u;
    if (runtime->hasFunction(0x16ACA8u)) {
        auto targetFn = runtime->lookupFunction(0x16ACA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AC88u; }
        if (ctx->pc != 0x16AC88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016ACA8_0x16aca8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16AC88u; }
        if (ctx->pc != 0x16AC88u) { return; }
    }
    ctx->pc = 0x16AC88u;
label_16ac88:
    // 0x16ac88: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x16ac88u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16ac8c: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x16ac8cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16ac90: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x16ac90u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16ac94: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x16ac94u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16ac98: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x16ac98u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16ac9c: 0x3e00008  jr          $ra
    ctx->pc = 0x16AC9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16ACA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16AC9Cu;
            // 0x16aca0: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16AC38u: goto label_16ac38;
            case 0x16AC54u: goto label_16ac54;
            case 0x16AC74u: goto label_16ac74;
            case 0x16AC80u: goto label_16ac80;
            case 0x16AC88u: goto label_16ac88;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16ACA4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
