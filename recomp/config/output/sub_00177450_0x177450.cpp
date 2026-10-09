#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00177450
// Address: 0x177450 - 0x177470
void sub_00177450_0x177450(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00177450_0x177450");
#endif

    ctx->pc = 0x177450u;

    // 0x177450: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x177450u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x177454: 0x2107a  dsrl        $v0, $v0, 1
    ctx->pc = 0x177454u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> 1);
    // 0x177458: 0xac800018  sw          $zero, 0x18($a0)
    ctx->pc = 0x177458u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 0));
    // 0x17745c: 0xfc820008  sd          $v0, 0x8($a0)
    ctx->pc = 0x17745cu;
    WRITE64(ADD32(GPR_U32(ctx, 4), 8), GPR_U64(ctx, 2));
    // 0x177460: 0xfc800000  sd          $zero, 0x0($a0)
    ctx->pc = 0x177460u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 0), GPR_U64(ctx, 0));
    // 0x177464: 0x3e00008  jr          $ra
    ctx->pc = 0x177464u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x177468u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177464u;
            // 0x177468: 0xfc800010  sd          $zero, 0x10($a0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 4), 16), GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17746Cu;
    // 0x17746c: 0x0  nop
    ctx->pc = 0x17746cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
