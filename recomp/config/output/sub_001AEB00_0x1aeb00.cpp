#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AEB00
// Address: 0x1aeb00 - 0x1aeb58
void sub_001AEB00_0x1aeb00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AEB00_0x1aeb00");
#endif

    switch (ctx->pc) {
        case 0x1aeb18u: goto label_1aeb18;
        case 0x1aeb40u: goto label_1aeb40;
        case 0x1aeb48u: goto label_1aeb48;
        default: break;
    }

    ctx->pc = 0x1aeb00u;

    // 0x1aeb00: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1aeb00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1aeb04: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1aeb04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1aeb08: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1aeb08u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1aeb0c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1aeb0cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1aeb10: 0xc06e0a8  jal         func_1B82A0
    ctx->pc = 0x1AEB10u;
    SET_GPR_U32(ctx, 31, 0x1AEB18u);
    ctx->pc = 0x1AEB14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEB10u;
            // 0x1aeb14: 0x2404000e  addiu       $a0, $zero, 0xE (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B82A0u;
    if (runtime->hasFunction(0x1B82A0u)) {
        auto targetFn = runtime->lookupFunction(0x1B82A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEB18u; }
        if (ctx->pc != 0x1AEB18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B82A0_0x1b82a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEB18u; }
        if (ctx->pc != 0x1AEB18u) { return; }
    }
    ctx->pc = 0x1AEB18u;
label_1aeb18:
    // 0x1aeb18: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1AEB18u;
    {
        const bool branch_taken_0x1aeb18 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AEB1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEB18u;
            // 0x1aeb1c: 0x3c03002c  lui         $v1, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)44 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1aeb18) {
            ctx->pc = 0x1AEB48u;
            goto label_1aeb48;
        }
    }
    ctx->pc = 0x1AEB20u;
    // 0x1aeb20: 0x102080  sll         $a0, $s0, 2
    ctx->pc = 0x1aeb20u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1aeb24: 0x24638dc8  addiu       $v1, $v1, -0x7238
    ctx->pc = 0x1aeb24u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294938056));
    // 0x1aeb28: 0x648021  addu        $s0, $v1, $a0
    ctx->pc = 0x1aeb28u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1aeb2c: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x1aeb2cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1aeb30: 0x10800005  beqz        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1AEB30u;
    {
        const bool branch_taken_0x1aeb30 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1aeb30) {
            ctx->pc = 0x1AEB48u;
            goto label_1aeb48;
        }
    }
    ctx->pc = 0x1AEB38u;
    // 0x1aeb38: 0xc04aa3a  jal         func_12A8E8
    ctx->pc = 0x1AEB38u;
    SET_GPR_U32(ctx, 31, 0x1AEB40u);
    ctx->pc = 0x12A8E8u;
    if (runtime->hasFunction(0x12A8E8u)) {
        auto targetFn = runtime->lookupFunction(0x12A8E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEB40u; }
        if (ctx->pc != 0x1AEB40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012A8E8_0x12a8e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEB40u; }
        if (ctx->pc != 0x1AEB40u) { return; }
    }
    ctx->pc = 0x1AEB40u;
label_1aeb40:
    // 0x1aeb40: 0xc04c78e  jal         func_131E38
    ctx->pc = 0x1AEB40u;
    SET_GPR_U32(ctx, 31, 0x1AEB48u);
    ctx->pc = 0x1AEB44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEB40u;
            // 0x1aeb44: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x131E38u;
    if (runtime->hasFunction(0x131E38u)) {
        auto targetFn = runtime->lookupFunction(0x131E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEB48u; }
        if (ctx->pc != 0x1AEB48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131E38_0x131e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AEB48u; }
        if (ctx->pc != 0x1AEB48u) { return; }
    }
    ctx->pc = 0x1AEB48u;
label_1aeb48:
    // 0x1aeb48: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1aeb48u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1aeb4c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1aeb4cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1aeb50: 0x3e00008  jr          $ra
    ctx->pc = 0x1AEB50u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AEB54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AEB50u;
            // 0x1aeb54: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AEB18u: goto label_1aeb18;
            case 0x1AEB40u: goto label_1aeb40;
            case 0x1AEB48u: goto label_1aeb48;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AEB58u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
