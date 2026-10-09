#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017A7D0
// Address: 0x17a7d0 - 0x17a818
void sub_0017A7D0_0x17a7d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017A7D0_0x17a7d0");
#endif

    ctx->pc = 0x17a7d0u;

    // 0x17a7d0: 0x3e00008  jr          $ra
    ctx->pc = 0x17A7D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A7D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A7D0u;
            // 0x17a7d4: 0x8c820004  lw          $v0, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17A7D8u;
    // 0x17a7d8: 0x24820008  addiu       $v0, $a0, 0x8
    ctx->pc = 0x17a7d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
    // 0x17a7dc: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x17a7dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17a7e0: 0xac460008  sw          $a2, 0x8($v0)
    ctx->pc = 0x17a7e0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 6));
    // 0x17a7e4: 0xac470000  sw          $a3, 0x0($v0)
    ctx->pc = 0x17a7e4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 7));
    // 0x17a7e8: 0xac450004  sw          $a1, 0x4($v0)
    ctx->pc = 0x17a7e8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 5));
    // 0x17a7ec: 0x3e00008  jr          $ra
    ctx->pc = 0x17A7ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A7F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A7ECu;
            // 0x17a7f0: 0xac830004  sw          $v1, 0x4($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17A7F4u;
    // 0x17a7f4: 0x0  nop
    ctx->pc = 0x17a7f4u;
    // NOP
    // 0x17a7f8: 0x24840008  addiu       $a0, $a0, 0x8
    ctx->pc = 0x17a7f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
    // 0x17a7fc: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x17a7fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x17a800: 0xace20000  sw          $v0, 0x0($a3)
    ctx->pc = 0x17a800u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 2));
    // 0x17a804: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x17a804u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x17a808: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x17a808u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x17a80c: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x17a80cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x17a810: 0x3e00008  jr          $ra
    ctx->pc = 0x17A810u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A814u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A810u;
            // 0x17a814: 0xacc20000  sw          $v0, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17A818u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
