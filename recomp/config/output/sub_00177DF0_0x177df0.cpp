#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00177DF0
// Address: 0x177df0 - 0x177e08
void sub_00177DF0_0x177df0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00177DF0_0x177df0");
#endif

    ctx->pc = 0x177df0u;

    // 0x177df0: 0xdca20000  ld          $v0, 0x0($a1)
    ctx->pc = 0x177df0u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x177df4: 0xfc820148  sd          $v0, 0x148($a0)
    ctx->pc = 0x177df4u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 328), GPR_U64(ctx, 2));
    // 0x177df8: 0xdca30008  ld          $v1, 0x8($a1)
    ctx->pc = 0x177df8u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x177dfc: 0x3e00008  jr          $ra
    ctx->pc = 0x177DFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x177E00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177DFCu;
            // 0x177e00: 0xfc830150  sd          $v1, 0x150($a0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 4), 336), GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x177E04u;
    // 0x177e04: 0x0  nop
    ctx->pc = 0x177e04u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
