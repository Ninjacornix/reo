#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00116BF0
// Address: 0x116bf0 - 0x116c08
void sub_00116BF0_0x116bf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00116BF0_0x116bf0");
#endif

    ctx->pc = 0x116bf0u;

    // 0x116bf0: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x116bf0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x116bf4: 0x2463af98  addiu       $v1, $v1, -0x5068
    ctx->pc = 0x116bf4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294946712));
    // 0x116bf8: 0x8c62000c  lw          $v0, 0xC($v1)
    ctx->pc = 0x116bf8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x116bfc: 0xac650010  sw          $a1, 0x10($v1)
    ctx->pc = 0x116bfcu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 16), GPR_U32(ctx, 5));
    // 0x116c00: 0x3e00008  jr          $ra
    ctx->pc = 0x116C00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x116C04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116C00u;
            // 0x116c04: 0xac64000c  sw          $a0, 0xC($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 12), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x116C08u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
