#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019EB10
// Address: 0x19eb10 - 0x19eb70
void sub_0019EB10_0x19eb10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019EB10_0x19eb10");
#endif

    switch (ctx->pc) {
        case 0x19eb20u: goto label_19eb20;
        default: break;
    }

    ctx->pc = 0x19eb10u;

    // 0x19eb10: 0x3c04002a  lui         $a0, 0x2A
    ctx->pc = 0x19eb10u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)42 << 16));
    // 0x19eb14: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x19eb14u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19eb18: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x19EB18u;
    {
        const bool branch_taken_0x19eb18 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19EB1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19EB18u;
            // 0x19eb1c: 0x2484bee0  addiu       $a0, $a0, -0x4120 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950624));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19eb18) {
            ctx->pc = 0x19EB50u;
            goto label_19eb50;
        }
    }
    ctx->pc = 0x19EB20u;
label_19eb20:
    // 0x19eb20: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x19eb20u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x19eb24: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x19eb24u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x19eb28: 0x821021  addu        $v0, $a0, $v0
    ctx->pc = 0x19eb28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x19eb2c: 0x84430014  lh          $v1, 0x14($v0)
    ctx->pc = 0x19eb2cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x19eb30: 0x14600006  bnez        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x19EB30u;
    {
        const bool branch_taken_0x19eb30 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x19EB34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19EB30u;
            // 0x19eb34: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19eb30) {
            ctx->pc = 0x19EB4Cu;
            goto label_19eb4c;
        }
    }
    ctx->pc = 0x19EB38u;
    // 0x19eb38: 0x8c23bec8  lw          $v1, -0x4138($at)
    ctx->pc = 0x19eb38u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294950600)));
    // 0x19eb3c: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x19eb3cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x19eb40: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19eb40u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19eb44: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x19EB44u;
    {
        const bool branch_taken_0x19eb44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19EB48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19EB44u;
            // 0x19eb48: 0xac23bec8  sw          $v1, -0x4138($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294950600), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19eb44) {
            ctx->pc = 0x19EB60u;
            goto label_19eb60;
        }
    }
    ctx->pc = 0x19EB4Cu;
label_19eb4c:
    // 0x19eb4c: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x19eb4cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
label_19eb50:
    // 0x19eb50: 0x28a20200  slti        $v0, $a1, 0x200
    ctx->pc = 0x19eb50u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)512) ? 1 : 0);
    // 0x19eb54: 0x1440fff2  bnez        $v0, . + 4 + (-0xE << 2)
    ctx->pc = 0x19EB54u;
    {
        const bool branch_taken_0x19eb54 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x19EB58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19EB54u;
            // 0x19eb58: 0x510c0  sll         $v0, $a1, 3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19eb54) {
            ctx->pc = 0x19EB20u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19eb20;
        }
    }
    ctx->pc = 0x19EB5Cu;
    // 0x19eb5c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x19eb5cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_19eb60:
    // 0x19eb60: 0x3e00008  jr          $ra
    ctx->pc = 0x19EB60u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19EB20u: goto label_19eb20;
            case 0x19EB4Cu: goto label_19eb4c;
            case 0x19EB50u: goto label_19eb50;
            case 0x19EB60u: goto label_19eb60;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19EB68u;
    // 0x19eb68: 0x0  nop
    ctx->pc = 0x19eb68u;
    // NOP
    // 0x19eb6c: 0x0  nop
    ctx->pc = 0x19eb6cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
