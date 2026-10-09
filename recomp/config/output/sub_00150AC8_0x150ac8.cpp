#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00150AC8
// Address: 0x150ac8 - 0x150aec
void sub_00150AC8_0x150ac8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00150AC8_0x150ac8");
#endif

    ctx->pc = 0x150ac8u;

    // 0x150ac8: 0x51040  sll         $v0, $a1, 1
    ctx->pc = 0x150ac8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x150acc: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x150accu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x150ad0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x150ad0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x150ad4: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x150ad4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x150ad8: 0x248400ec  addiu       $a0, $a0, 0xEC
    ctx->pc = 0x150ad8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 236));
    // 0x150adc: 0xac880008  sw          $t0, 0x8($a0)
    ctx->pc = 0x150adcu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 8));
    // 0x150ae0: 0xac860000  sw          $a2, 0x0($a0)
    ctx->pc = 0x150ae0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 6));
    // 0x150ae4: 0x3e00008  jr          $ra
    ctx->pc = 0x150AE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x150AE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150AE4u;
            // 0x150ae8: 0xac870004  sw          $a3, 0x4($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 7));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x150AECu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
