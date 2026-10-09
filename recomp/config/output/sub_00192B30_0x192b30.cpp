#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00192B30
// Address: 0x192b30 - 0x192b68
void sub_00192B30_0x192b30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00192B30_0x192b30");
#endif

    switch (ctx->pc) {
        case 0x192b44u: goto label_192b44;
        case 0x192b54u: goto label_192b54;
        default: break;
    }

    ctx->pc = 0x192b30u;

    // 0x192b30: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x192b30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x192b34: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x192b34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x192b38: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x192b38u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x192b3c: 0xc064b44  jal         func_192D10
    ctx->pc = 0x192B3Cu;
    SET_GPR_U32(ctx, 31, 0x192B44u);
    ctx->pc = 0x192B40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x192B3Cu;
            // 0x192b40: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x192D10u;
    if (runtime->hasFunction(0x192D10u)) {
        auto targetFn = runtime->lookupFunction(0x192D10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192B44u; }
        if (ctx->pc != 0x192B44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00192D10_0x192d10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192B44u; }
        if (ctx->pc != 0x192B44u) { return; }
    }
    ctx->pc = 0x192B44u;
label_192b44:
    // 0x192b44: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x192B44u;
    {
        const bool branch_taken_0x192b44 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x192B48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192B44u;
            // 0x192b48: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x192b44) {
            ctx->pc = 0x192B54u;
            goto label_192b54;
        }
    }
    ctx->pc = 0x192B4Cu;
    // 0x192b4c: 0xc064adc  jal         func_192B70
    ctx->pc = 0x192B4Cu;
    SET_GPR_U32(ctx, 31, 0x192B54u);
    ctx->pc = 0x192B50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x192B4Cu;
            // 0x192b50: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x192B70u;
    if (runtime->hasFunction(0x192B70u)) {
        auto targetFn = runtime->lookupFunction(0x192B70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192B54u; }
        if (ctx->pc != 0x192B54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00192B70_0x192b70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192B54u; }
        if (ctx->pc != 0x192B54u) { return; }
    }
    ctx->pc = 0x192B54u;
label_192b54:
    // 0x192b54: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x192b54u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x192b58: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x192b58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x192b5c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x192b5cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x192b60: 0x3e00008  jr          $ra
    ctx->pc = 0x192B60u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x192B64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x192B60u;
            // 0x192b64: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x192B44u: goto label_192b44;
            case 0x192B54u: goto label_192b54;
            default: break;
        }
        return;
    }
    ctx->pc = 0x192B68u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
