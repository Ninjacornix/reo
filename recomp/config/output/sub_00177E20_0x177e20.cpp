#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00177E20
// Address: 0x177e20 - 0x177e38
void sub_00177E20_0x177e20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00177E20_0x177e20");
#endif

    ctx->pc = 0x177e20u;

    // 0x177e20: 0xdca20000  ld          $v0, 0x0($a1)
    ctx->pc = 0x177e20u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x177e24: 0xfc820168  sd          $v0, 0x168($a0)
    ctx->pc = 0x177e24u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 360), GPR_U64(ctx, 2));
    // 0x177e28: 0xdca30008  ld          $v1, 0x8($a1)
    ctx->pc = 0x177e28u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x177e2c: 0x3e00008  jr          $ra
    ctx->pc = 0x177E2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x177E30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177E2Cu;
            // 0x177e30: 0xfc830170  sd          $v1, 0x170($a0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 4), 368), GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x177E34u;
    // 0x177e34: 0x0  nop
    ctx->pc = 0x177e34u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
