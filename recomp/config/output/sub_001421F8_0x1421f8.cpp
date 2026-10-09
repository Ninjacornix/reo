#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001421F8
// Address: 0x1421f8 - 0x14221c
void sub_001421F8_0x1421f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001421F8_0x1421f8");
#endif

    ctx->pc = 0x1421f8u;

    // 0x1421f8: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1421f8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1421fc: 0x244549f8  addiu       $a1, $v0, 0x49F8
    ctx->pc = 0x1421fcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 18936));
    // 0x142200: 0x8ca30000  lw          $v1, 0x0($a1)
    ctx->pc = 0x142200u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x142204: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x142204u;
    {
        const bool branch_taken_0x142204 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x142208u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x142204u;
            // 0x142208: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x142204) {
            ctx->pc = 0x142214u;
            goto label_142214;
        }
    }
    ctx->pc = 0x14220Cu;
    // 0x14220c: 0xaca40000  sw          $a0, 0x0($a1)
    ctx->pc = 0x14220cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 4));
    // 0x142210: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x142210u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_142214:
    // 0x142214: 0x3e00008  jr          $ra
    ctx->pc = 0x142214u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x142214u: goto label_142214;
            default: break;
        }
        return;
    }
    ctx->pc = 0x14221Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
