#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CCA30
// Address: 0x1cca30 - 0x1cca80
void sub_001CCA30_0x1cca30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CCA30_0x1cca30");
#endif

    switch (ctx->pc) {
        case 0x1cca54u: goto label_1cca54;
        case 0x1cca70u: goto label_1cca70;
        default: break;
    }

    ctx->pc = 0x1cca30u;

    // 0x1cca30: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1cca30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1cca34: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1cca34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1cca38: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1cca38u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cca3c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1cca3cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cca40: 0x3084ffff  andi        $a0, $a0, 0xFFFF
    ctx->pc = 0x1cca40u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
    // 0x1cca44: 0x10800004  beqz        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1CCA44u;
    {
        const bool branch_taken_0x1cca44 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CCA48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CCA44u;
            // 0x1cca48: 0x3c03ffff  lui         $v1, 0xFFFF (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)65535 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cca44) {
            ctx->pc = 0x1CCA58u;
            goto label_1cca58;
        }
    }
    ctx->pc = 0x1CCA4Cu;
    // 0x1cca4c: 0xc067510  jal         func_19D440
    ctx->pc = 0x1CCA4Cu;
    SET_GPR_U32(ctx, 31, 0x1CCA54u);
    ctx->pc = 0x19D440u;
    if (runtime->hasFunction(0x19D440u)) {
        auto targetFn = runtime->lookupFunction(0x19D440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CCA54u; }
        if (ctx->pc != 0x1CCA54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019D440_0x19d440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CCA54u; }
        if (ctx->pc != 0x1CCA54u) { return; }
    }
    ctx->pc = 0x1CCA54u;
label_1cca54:
    // 0x1cca54: 0x3c03ffff  lui         $v1, 0xFFFF
    ctx->pc = 0x1cca54u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)65535 << 16));
label_1cca58:
    // 0x1cca58: 0x2031824  and         $v1, $s0, $v1
    ctx->pc = 0x1cca58u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) & GPR_U64(ctx, 3));
    // 0x1cca5c: 0x32402  srl         $a0, $v1, 16
    ctx->pc = 0x1cca5cu;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 3), 16));
    // 0x1cca60: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CCA60u;
    {
        const bool branch_taken_0x1cca60 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cca60) {
            ctx->pc = 0x1CCA70u;
            goto label_1cca70;
        }
    }
    ctx->pc = 0x1CCA68u;
    // 0x1cca68: 0xc06756c  jal         func_19D5B0
    ctx->pc = 0x1CCA68u;
    SET_GPR_U32(ctx, 31, 0x1CCA70u);
    ctx->pc = 0x19D5B0u;
    if (runtime->hasFunction(0x19D5B0u)) {
        auto targetFn = runtime->lookupFunction(0x19D5B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CCA70u; }
        if (ctx->pc != 0x1CCA70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019D5B0_0x19d5b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CCA70u; }
        if (ctx->pc != 0x1CCA70u) { return; }
    }
    ctx->pc = 0x1CCA70u;
label_1cca70:
    // 0x1cca70: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1cca70u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1cca74: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cca74u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cca78: 0x3e00008  jr          $ra
    ctx->pc = 0x1CCA78u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CCA7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CCA78u;
            // 0x1cca7c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CCA54u: goto label_1cca54;
            case 0x1CCA58u: goto label_1cca58;
            case 0x1CCA70u: goto label_1cca70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CCA80u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
