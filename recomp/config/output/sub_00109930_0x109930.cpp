#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00109930
// Address: 0x109930 - 0x109948
void sub_00109930_0x109930(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00109930_0x109930");
#endif

    ctx->pc = 0x109930u;

    // 0x109930: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x109930u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x109934: 0x4203c  dsll32      $a0, $a0, 0
    ctx->pc = 0x109934u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
    // 0x109938: 0x8c4397f0  lw          $v1, -0x6810($v0)
    ctx->pc = 0x109938u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294940656)));
    // 0x10993c: 0x4203e  dsrl32      $a0, $a0, 0
    ctx->pc = 0x10993cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) >> (32 + 0));
    // 0x109940: 0x3e00008  jr          $ra
    ctx->pc = 0x109940u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x109944u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109940u;
            // 0x109944: 0xfc6400a8  sd          $a0, 0xA8($v1) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 3), 168), GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x109948u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
