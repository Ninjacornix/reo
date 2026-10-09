#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00162C10
// Address: 0x162c10 - 0x162c40
void sub_00162C10_0x162c10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00162C10_0x162c10");
#endif

    ctx->pc = 0x162c10u;

    // 0x162c10: 0x3c020002  lui         $v0, 0x2
    ctx->pc = 0x162c10u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)2 << 16));
    // 0x162c14: 0x24070800  addiu       $a3, $zero, 0x800
    ctx->pc = 0x162c14u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
    // 0x162c18: 0x344249e4  ori         $v0, $v0, 0x49E4
    ctx->pc = 0x162c18u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)18916);
    // 0x162c1c: 0x24036d60  addiu       $v1, $zero, 0x6D60
    ctx->pc = 0x162c1cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 28000));
    // 0x162c20: 0xac820000  sw          $v0, 0x0($a0)
    ctx->pc = 0x162c20u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x162c24: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x162c24u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x162c28: 0xacc70000  sw          $a3, 0x0($a2)
    ctx->pc = 0x162c28u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 7));
    // 0x162c2c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x162c2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x162c30: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x162c30u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x162c34: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x162c34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x162c38: 0x3e00008  jr          $ra
    ctx->pc = 0x162C38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x162C3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162C38u;
            // 0x162c3c: 0x471021  addu        $v0, $v0, $a3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x162C40u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
