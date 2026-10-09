#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00177E08
// Address: 0x177e08 - 0x177e20
void sub_00177E08_0x177e08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00177E08_0x177e08");
#endif

    ctx->pc = 0x177e08u;

    // 0x177e08: 0xdca20000  ld          $v0, 0x0($a1)
    ctx->pc = 0x177e08u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x177e0c: 0xfc820158  sd          $v0, 0x158($a0)
    ctx->pc = 0x177e0cu;
    WRITE64(ADD32(GPR_U32(ctx, 4), 344), GPR_U64(ctx, 2));
    // 0x177e10: 0xdca30008  ld          $v1, 0x8($a1)
    ctx->pc = 0x177e10u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x177e14: 0x3e00008  jr          $ra
    ctx->pc = 0x177E14u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x177E18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177E14u;
            // 0x177e18: 0xfc830160  sd          $v1, 0x160($a0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 4), 352), GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x177E1Cu;
    // 0x177e1c: 0x0  nop
    ctx->pc = 0x177e1cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
