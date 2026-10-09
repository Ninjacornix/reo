#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CC000
// Address: 0x1cc000 - 0x1cc060
void sub_001CC000_0x1cc000(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CC000_0x1cc000");
#endif

    switch (ctx->pc) {
        case 0x1cc038u: goto label_1cc038;
        case 0x1cc044u: goto label_1cc044;
        case 0x1cc050u: goto label_1cc050;
        default: break;
    }

    ctx->pc = 0x1cc000u;

    // 0x1cc000: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1cc000u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1cc004: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc004u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc008: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1cc008u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1cc00c: 0x8c23d9f8  lw          $v1, -0x2608($at)
    ctx->pc = 0x1cc00cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294957560)));
    // 0x1cc010: 0x1460000f  bnez        $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x1CC010u;
    {
        const bool branch_taken_0x1cc010 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1cc010) {
            ctx->pc = 0x1CC050u;
            goto label_1cc050;
        }
    }
    ctx->pc = 0x1CC018u;
    // 0x1cc018: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc018u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc01c: 0x8c23da00  lw          $v1, -0x2600($at)
    ctx->pc = 0x1cc01cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294957568)));
    // 0x1cc020: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CC020u;
    {
        const bool branch_taken_0x1cc020 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cc020) {
            ctx->pc = 0x1CC030u;
            goto label_1cc030;
        }
    }
    ctx->pc = 0x1CC028u;
    // 0x1cc028: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1CC028u;
    {
        const bool branch_taken_0x1cc028 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CC02Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC028u;
            // 0x1cc02c: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cc028) {
            ctx->pc = 0x1CC054u;
            goto label_1cc054;
        }
    }
    ctx->pc = 0x1CC030u;
label_1cc030:
    // 0x1cc030: 0xc072f78  jal         func_1CBDE0
    ctx->pc = 0x1CC030u;
    SET_GPR_U32(ctx, 31, 0x1CC038u);
    ctx->pc = 0x1CBDE0u;
    if (runtime->hasFunction(0x1CBDE0u)) {
        auto targetFn = runtime->lookupFunction(0x1CBDE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC038u; }
        if (ctx->pc != 0x1CC038u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CBDE0_0x1cbde0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC038u; }
        if (ctx->pc != 0x1CC038u) { return; }
    }
    ctx->pc = 0x1CC038u;
label_1cc038:
    // 0x1cc038: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc038u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc03c: 0xc077436  jal         func_1DD0D8
    ctx->pc = 0x1CC03Cu;
    SET_GPR_U32(ctx, 31, 0x1CC044u);
    ctx->pc = 0x1CC040u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC03Cu;
            // 0x1cc040: 0x8c24c7f0  lw          $a0, -0x3810($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294952944)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1DD0D8u;
    if (runtime->hasFunction(0x1DD0D8u)) {
        auto targetFn = runtime->lookupFunction(0x1DD0D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC044u; }
        if (ctx->pc != 0x1CC044u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DD0D8_0x1dd0d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC044u; }
        if (ctx->pc != 0x1CC044u) { return; }
    }
    ctx->pc = 0x1CC044u;
label_1cc044:
    // 0x1cc044: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc044u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc048: 0xc072f7c  jal         func_1CBDF0
    ctx->pc = 0x1CC048u;
    SET_GPR_U32(ctx, 31, 0x1CC050u);
    ctx->pc = 0x1CC04Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC048u;
            // 0x1cc04c: 0xac22d9f8  sw          $v0, -0x2608($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294957560), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CBDF0u;
    if (runtime->hasFunction(0x1CBDF0u)) {
        auto targetFn = runtime->lookupFunction(0x1CBDF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC050u; }
        if (ctx->pc != 0x1CC050u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CBDF0_0x1cbdf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC050u; }
        if (ctx->pc != 0x1CC050u) { return; }
    }
    ctx->pc = 0x1CC050u;
label_1cc050:
    // 0x1cc050: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1cc050u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1cc054:
    // 0x1cc054: 0x3e00008  jr          $ra
    ctx->pc = 0x1CC054u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CC058u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC054u;
            // 0x1cc058: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CC030u: goto label_1cc030;
            case 0x1CC038u: goto label_1cc038;
            case 0x1CC044u: goto label_1cc044;
            case 0x1CC050u: goto label_1cc050;
            case 0x1CC054u: goto label_1cc054;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CC05Cu;
    // 0x1cc05c: 0x0  nop
    ctx->pc = 0x1cc05cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
