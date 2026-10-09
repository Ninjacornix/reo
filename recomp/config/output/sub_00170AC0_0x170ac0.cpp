#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00170AC0
// Address: 0x170ac0 - 0x170ae8
void sub_00170AC0_0x170ac0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00170AC0_0x170ac0");
#endif

    ctx->pc = 0x170ac0u;

    // 0x170ac0: 0x6303c  dsll32      $a2, $a2, 0
    ctx->pc = 0x170ac0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) << (32 + 0));
    // 0x170ac4: 0x5283c  dsll32      $a1, $a1, 0
    ctx->pc = 0x170ac4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 0));
    // 0x170ac8: 0x6313a  dsrl        $a2, $a2, 4
    ctx->pc = 0x170ac8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) >> 4);
    // 0x170acc: 0x7383c  dsll32      $a3, $a3, 0
    ctx->pc = 0x170accu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) << (32 + 0));
    // 0x170ad0: 0xa62825  or          $a1, $a1, $a2
    ctx->pc = 0x170ad0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 6));
    // 0x170ad4: 0x7383e  dsrl32      $a3, $a3, 0
    ctx->pc = 0x170ad4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) >> (32 + 0));
    // 0x170ad8: 0xa72825  or          $a1, $a1, $a3
    ctx->pc = 0x170ad8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 7));
    // 0x170adc: 0x3e00008  jr          $ra
    ctx->pc = 0x170ADCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x170AE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x170ADCu;
            // 0x170ae0: 0xfc850000  sd          $a1, 0x0($a0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 4), 0), GPR_U64(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x170AE4u;
    // 0x170ae4: 0x0  nop
    ctx->pc = 0x170ae4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
