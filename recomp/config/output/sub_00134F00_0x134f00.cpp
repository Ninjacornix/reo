#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00134F00
// Address: 0x134f00 - 0x134f28
void sub_00134F00_0x134f00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00134F00_0x134f00");
#endif

    ctx->pc = 0x134f00u;

    // 0x134f00: 0x94830028  lhu         $v1, 0x28($a0)
    ctx->pc = 0x134f00u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 40)));
    // 0x134f04: 0xa4a30000  sh          $v1, 0x0($a1)
    ctx->pc = 0x134f04u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x134f08: 0x9482002a  lhu         $v0, 0x2A($a0)
    ctx->pc = 0x134f08u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 42)));
    // 0x134f0c: 0xa4c20000  sh          $v0, 0x0($a2)
    ctx->pc = 0x134f0cu;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x134f10: 0x9483002c  lhu         $v1, 0x2C($a0)
    ctx->pc = 0x134f10u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 44)));
    // 0x134f14: 0xa4a30002  sh          $v1, 0x2($a1)
    ctx->pc = 0x134f14u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 2), (uint16_t)GPR_U32(ctx, 3));
    // 0x134f18: 0x9482002e  lhu         $v0, 0x2E($a0)
    ctx->pc = 0x134f18u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 46)));
    // 0x134f1c: 0x3e00008  jr          $ra
    ctx->pc = 0x134F1Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x134F20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134F1Cu;
            // 0x134f20: 0xa4c20002  sh          $v0, 0x2($a2) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 6), 2), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x134F24u;
    // 0x134f24: 0x0  nop
    ctx->pc = 0x134f24u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
