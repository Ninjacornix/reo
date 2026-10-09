#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00177DD8
// Address: 0x177dd8 - 0x177df0
void sub_00177DD8_0x177dd8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00177DD8_0x177dd8");
#endif

    ctx->pc = 0x177dd8u;

    // 0x177dd8: 0xdca20000  ld          $v0, 0x0($a1)
    ctx->pc = 0x177dd8u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x177ddc: 0xfc820138  sd          $v0, 0x138($a0)
    ctx->pc = 0x177ddcu;
    WRITE64(ADD32(GPR_U32(ctx, 4), 312), GPR_U64(ctx, 2));
    // 0x177de0: 0xdca30008  ld          $v1, 0x8($a1)
    ctx->pc = 0x177de0u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x177de4: 0x3e00008  jr          $ra
    ctx->pc = 0x177DE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x177DE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177DE4u;
            // 0x177de8: 0xfc830140  sd          $v1, 0x140($a0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 4), 320), GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x177DECu;
    // 0x177dec: 0x0  nop
    ctx->pc = 0x177decu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
