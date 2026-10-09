#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00134ED8
// Address: 0x134ed8 - 0x134f00
void sub_00134ED8_0x134ed8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00134ED8_0x134ed8");
#endif

    ctx->pc = 0x134ed8u;

    // 0x134ed8: 0x94a30000  lhu         $v1, 0x0($a1)
    ctx->pc = 0x134ed8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x134edc: 0xa4830028  sh          $v1, 0x28($a0)
    ctx->pc = 0x134edcu;
    WRITE16(ADD32(GPR_U32(ctx, 4), 40), (uint16_t)GPR_U32(ctx, 3));
    // 0x134ee0: 0x94c20000  lhu         $v0, 0x0($a2)
    ctx->pc = 0x134ee0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x134ee4: 0xa482002a  sh          $v0, 0x2A($a0)
    ctx->pc = 0x134ee4u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 42), (uint16_t)GPR_U32(ctx, 2));
    // 0x134ee8: 0x94a30002  lhu         $v1, 0x2($a1)
    ctx->pc = 0x134ee8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 2)));
    // 0x134eec: 0xa483002c  sh          $v1, 0x2C($a0)
    ctx->pc = 0x134eecu;
    WRITE16(ADD32(GPR_U32(ctx, 4), 44), (uint16_t)GPR_U32(ctx, 3));
    // 0x134ef0: 0x94c20002  lhu         $v0, 0x2($a2)
    ctx->pc = 0x134ef0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 6), 2)));
    // 0x134ef4: 0x3e00008  jr          $ra
    ctx->pc = 0x134EF4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x134EF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134EF4u;
            // 0x134ef8: 0xa482002e  sh          $v0, 0x2E($a0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 4), 46), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x134EFCu;
    // 0x134efc: 0x0  nop
    ctx->pc = 0x134efcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
