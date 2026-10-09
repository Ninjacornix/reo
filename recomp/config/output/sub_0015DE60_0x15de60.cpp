#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015DE60
// Address: 0x15de60 - 0x15dea8
void sub_0015DE60_0x15de60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015DE60_0x15de60");
#endif

    ctx->pc = 0x15de60u;

    // 0x15de60: 0x8ca20044  lw          $v0, 0x44($a1)
    ctx->pc = 0x15de60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 68)));
    // 0x15de64: 0x24840088  addiu       $a0, $a0, 0x88
    ctx->pc = 0x15de64u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 136));
    // 0x15de68: 0x8ca30050  lw          $v1, 0x50($a1)
    ctx->pc = 0x15de68u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 80)));
    // 0x15de6c: 0xac820008  sw          $v0, 0x8($a0)
    ctx->pc = 0x15de6cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 2));
    // 0x15de70: 0xac830014  sw          $v1, 0x14($a0)
    ctx->pc = 0x15de70u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 3));
    // 0x15de74: 0x8ca20048  lw          $v0, 0x48($a1)
    ctx->pc = 0x15de74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 72)));
    // 0x15de78: 0x8ca70054  lw          $a3, 0x54($a1)
    ctx->pc = 0x15de78u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 84)));
    // 0x15de7c: 0xac82000c  sw          $v0, 0xC($a0)
    ctx->pc = 0x15de7cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 2));
    // 0x15de80: 0x8ca3003c  lw          $v1, 0x3C($a1)
    ctx->pc = 0x15de80u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 60)));
    // 0x15de84: 0x8ca6004c  lw          $a2, 0x4C($a1)
    ctx->pc = 0x15de84u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 76)));
    // 0x15de88: 0x8ca20040  lw          $v0, 0x40($a1)
    ctx->pc = 0x15de88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 64)));
    // 0x15de8c: 0xac830000  sw          $v1, 0x0($a0)
    ctx->pc = 0x15de8cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
    // 0x15de90: 0xac820004  sw          $v0, 0x4($a0)
    ctx->pc = 0x15de90u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 2));
    // 0x15de94: 0xac860010  sw          $a2, 0x10($a0)
    ctx->pc = 0x15de94u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 6));
    // 0x15de98: 0xac870018  sw          $a3, 0x18($a0)
    ctx->pc = 0x15de98u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 7));
    // 0x15de9c: 0x3e00008  jr          $ra
    ctx->pc = 0x15DE9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15DEA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15DE9Cu;
            // 0x15dea0: 0xac80001c  sw          $zero, 0x1C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x15DEA4u;
    // 0x15dea4: 0x0  nop
    ctx->pc = 0x15dea4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
