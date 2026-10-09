#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012FDB8
// Address: 0x12fdb8 - 0x12fdc0
void sub_0012FDB8_0x12fdb8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012FDB8_0x12fdb8");
#endif

    ctx->pc = 0x12fdb8u;

    // 0x12fdb8: 0x3e00008  jr          $ra
    ctx->pc = 0x12FDB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12FDBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FDB8u;
            // 0x12fdbc: 0xac850030  sw          $a1, 0x30($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 48), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12FDC0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
