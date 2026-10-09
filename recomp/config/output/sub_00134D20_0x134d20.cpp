#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00134D20
// Address: 0x134d20 - 0x134d8c
void sub_00134D20_0x134d20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00134D20_0x134d20");
#endif

    ctx->pc = 0x134d20u;

    // 0x134d20: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x134d20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x134d24: 0x80182d  daddu       $v1, $a0, $zero
    ctx->pc = 0x134d24u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x134d28: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x134d28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x134d2c: 0x10600014  beqz        $v1, . + 4 + (0x14 << 2)
    ctx->pc = 0x134D2Cu;
    {
        const bool branch_taken_0x134d2c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x134D30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134D2Cu;
            // 0x134d30: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134d2c) {
            ctx->pc = 0x134D80u;
            goto label_134d80;
        }
    }
    ctx->pc = 0x134D34u;
    // 0x134d34: 0x8c620008  lw          $v0, 0x8($v1)
    ctx->pc = 0x134d34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x134d38: 0x1440000d  bnez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x134D38u;
    {
        const bool branch_taken_0x134d38 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x134D3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134D38u;
            // 0x134d3c: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134d38) {
            ctx->pc = 0x134D70u;
            goto label_134d70;
        }
    }
    ctx->pc = 0x134D40u;
    // 0x134d40: 0x8c640094  lw          $a0, 0x94($v1)
    ctx->pc = 0x134d40u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 148)));
    // 0x134d44: 0x1080000e  beqz        $a0, . + 4 + (0xE << 2)
    ctx->pc = 0x134D44u;
    {
        const bool branch_taken_0x134d44 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x134D48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134D44u;
            // 0x134d48: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134d44) {
            ctx->pc = 0x134D80u;
            goto label_134d80;
        }
    }
    ctx->pc = 0x134D4Cu;
    // 0x134d4c: 0x8c820028  lw          $v0, 0x28($a0)
    ctx->pc = 0x134d4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 40)));
    // 0x134d50: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x134D50u;
    {
        const bool branch_taken_0x134d50 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x134D54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134D50u;
            // 0x134d54: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134d50) {
            ctx->pc = 0x134D68u;
            goto label_134d68;
        }
    }
    ctx->pc = 0x134D58u;
    // 0x134d58: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x134d58u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x134d5c: 0x804c3f8  j           func_130FE0
    ctx->pc = 0x134D5Cu;
    ctx->pc = 0x134D60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134D5Cu;
            // 0x134d60: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130FE0u;
    if (runtime->hasFunction(0x130FE0u)) {
        auto targetFn = runtime->lookupFunction(0x130FE0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00130FE0_0x130fe0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x134D64u;
    // 0x134d64: 0x0  nop
    ctx->pc = 0x134d64u;
    // NOP
label_134d68:
    // 0x134d68: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x134D68u;
    {
        const bool branch_taken_0x134d68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x134D6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134D68u;
            // 0x134d6c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134d68) {
            ctx->pc = 0x134D80u;
            goto label_134d80;
        }
    }
    ctx->pc = 0x134D70u;
label_134d70:
    // 0x134d70: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x134d70u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x134d74: 0x804c3f8  j           func_130FE0
    ctx->pc = 0x134D74u;
    ctx->pc = 0x134D78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x134D74u;
            // 0x134d78: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130FE0u;
    if (runtime->hasFunction(0x130FE0u)) {
        auto targetFn = runtime->lookupFunction(0x130FE0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00130FE0_0x130fe0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x134D7Cu;
    // 0x134d7c: 0x0  nop
    ctx->pc = 0x134d7cu;
    // NOP
label_134d80:
    // 0x134d80: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x134d80u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x134d84: 0x3e00008  jr          $ra
    ctx->pc = 0x134D84u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x134D88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134D84u;
            // 0x134d88: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x134D68u: goto label_134d68;
            case 0x134D70u: goto label_134d70;
            case 0x134D80u: goto label_134d80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x134D8Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
