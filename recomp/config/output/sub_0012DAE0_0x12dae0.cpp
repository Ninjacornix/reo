#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012DAE0
// Address: 0x12dae0 - 0x12db00
void sub_0012DAE0_0x12dae0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012DAE0_0x12dae0");
#endif

    ctx->pc = 0x12dae0u;

    // 0x12dae0: 0x3c040022  lui         $a0, 0x22
    ctx->pc = 0x12dae0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)34 << 16));
    // 0x12dae4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x12dae4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12dae8: 0x24848748  addiu       $a0, $a0, -0x78B8
    ctx->pc = 0x12dae8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294936392));
    // 0x12daec: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x12daecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x12daf0: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x12daf0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x12daf4: 0x3e00008  jr          $ra
    ctx->pc = 0x12DAF4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12DAF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12DAF4u;
            // 0x12daf8: 0xac830000  sw          $v1, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12DAFCu;
    // 0x12dafc: 0x0  nop
    ctx->pc = 0x12dafcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
