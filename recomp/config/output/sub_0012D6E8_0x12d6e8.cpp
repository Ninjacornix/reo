#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012D6E8
// Address: 0x12d6e8 - 0x12d738
void sub_0012D6E8_0x12d6e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012D6E8_0x12d6e8");
#endif

    ctx->pc = 0x12d6e8u;

    // 0x12d6e8: 0x3e00008  jr          $ra
    ctx->pc = 0x12D6E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12D6ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D6E8u;
            // 0x12d6ec: 0xac850034  sw          $a1, 0x34($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 52), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12D6F0u;
    // 0x12d6f0: 0x3e00008  jr          $ra
    ctx->pc = 0x12D6F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12D6F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D6F0u;
            // 0x12d6f4: 0x8c820034  lw          $v0, 0x34($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 52)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12D6F8u;
    // 0x12d6f8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12d6f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12d6fc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12d6fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12d700: 0x8c840004  lw          $a0, 0x4($a0)
    ctx->pc = 0x12d700u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x12d704: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12d704u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12d708: 0x80493fc  j           func_124FF0
    ctx->pc = 0x12D708u;
    ctx->pc = 0x12D70Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D708u;
            // 0x12d70c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124FF0u;
    if (runtime->hasFunction(0x124FF0u)) {
        auto targetFn = runtime->lookupFunction(0x124FF0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00124FF0_0x124ff0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12D710u;
    // 0x12d710: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12d710u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12d714: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12d714u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12d718: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12d718u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12d71c: 0x8049416  j           func_125058
    ctx->pc = 0x12D71Cu;
    ctx->pc = 0x12D720u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D71Cu;
            // 0x12d720: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x125058u;
    if (runtime->hasFunction(0x125058u)) {
        auto targetFn = runtime->lookupFunction(0x125058u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00125058_0x125058(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12D724u;
    // 0x12d724: 0x0  nop
    ctx->pc = 0x12d724u;
    // NOP
    // 0x12d728: 0xac860054  sw          $a2, 0x54($a0)
    ctx->pc = 0x12d728u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 84), GPR_U32(ctx, 6));
    // 0x12d72c: 0x3e00008  jr          $ra
    ctx->pc = 0x12D72Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12D730u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D72Cu;
            // 0x12d730: 0xac850050  sw          $a1, 0x50($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 80), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12D734u;
    // 0x12d734: 0x0  nop
    ctx->pc = 0x12d734u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
