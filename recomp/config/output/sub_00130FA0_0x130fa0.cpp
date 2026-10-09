#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00130FA0
// Address: 0x130fa0 - 0x130fac
void sub_00130FA0_0x130fa0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00130FA0_0x130fa0");
#endif

    ctx->pc = 0x130fa0u;

    // 0x130fa0: 0x52ac0  sll         $a1, $a1, 11
    ctx->pc = 0x130fa0u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 11));
    // 0x130fa4: 0x3e00008  jr          $ra
    ctx->pc = 0x130FA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130FA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130FA4u;
            // 0x130fa8: 0xac850010  sw          $a1, 0x10($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x130FACu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
