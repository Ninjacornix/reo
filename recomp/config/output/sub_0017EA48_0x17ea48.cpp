#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017EA48
// Address: 0x17ea48 - 0x17ea64
void sub_0017EA48_0x17ea48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017EA48_0x17ea48");
#endif

    ctx->pc = 0x17ea48u;

    // 0x17ea48: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x17ea48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x17ea4c: 0x2107a  dsrl        $v0, $v0, 1
    ctx->pc = 0x17ea4cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> 1);
    // 0x17ea50: 0xac800018  sw          $zero, 0x18($a0)
    ctx->pc = 0x17ea50u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 0));
    // 0x17ea54: 0xfc820008  sd          $v0, 0x8($a0)
    ctx->pc = 0x17ea54u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 8), GPR_U64(ctx, 2));
    // 0x17ea58: 0xfc800000  sd          $zero, 0x0($a0)
    ctx->pc = 0x17ea58u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 0), GPR_U64(ctx, 0));
    // 0x17ea5c: 0x3e00008  jr          $ra
    ctx->pc = 0x17EA5Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17EA60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17EA5Cu;
            // 0x17ea60: 0xfc800010  sd          $zero, 0x10($a0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 4), 16), GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17EA64u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
