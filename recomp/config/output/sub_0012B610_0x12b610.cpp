#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012B610
// Address: 0x12b610 - 0x12b620
void sub_0012B610_0x12b610(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012B610_0x12b610");
#endif

    ctx->pc = 0x12b610u;

    // 0x12b610: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12b610u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12b614: 0x8c620454  lw          $v0, 0x454($v1)
    ctx->pc = 0x12b614u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 1108)));
    // 0x12b618: 0x3e00008  jr          $ra
    ctx->pc = 0x12B618u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12B61Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12B618u;
            // 0x12b61c: 0x2102b  sltu        $v0, $zero, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x12B620u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
