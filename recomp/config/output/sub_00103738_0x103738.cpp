#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00103738
// Address: 0x103738 - 0x10374c
void sub_00103738_0x103738(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00103738_0x103738");
#endif

    ctx->pc = 0x103738u;

    // 0x103738: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x103738u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x10373c: 0xac850000  sw          $a1, 0x0($a0)
    ctx->pc = 0x10373cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
    // 0x103740: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x103740u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x103744: 0x3e00008  jr          $ra
    ctx->pc = 0x103744u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x103748u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103744u;
            // 0x103748: 0x30420001  andi        $v0, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x10374Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
