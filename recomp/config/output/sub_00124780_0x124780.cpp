#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00124780
// Address: 0x124780 - 0x1247a0
void sub_00124780_0x124780(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00124780_0x124780");
#endif

    ctx->pc = 0x124780u;

    // 0x124780: 0x94a70000  lhu         $a3, 0x0($a1)
    ctx->pc = 0x124780u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x124784: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x124784u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124788: 0x94850000  lhu         $a1, 0x0($a0)
    ctx->pc = 0x124788u;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x12478c: 0x94c30000  lhu         $v1, 0x0($a2)
    ctx->pc = 0x12478cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x124790: 0xa72818  mult        $a1, $a1, $a3
    ctx->pc = 0x124790u;
    { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 7); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
    // 0x124794: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x124794u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x124798: 0x3e00008  jr          $ra
    ctx->pc = 0x124798u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12479Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124798u;
            // 0x12479c: 0xa4830000  sh          $v1, 0x0($a0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1247A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
