#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00145228
// Address: 0x145228 - 0x145258
void sub_00145228_0x145228(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00145228_0x145228");
#endif

    ctx->pc = 0x145228u;

    // 0x145228: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x145228u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x14522c: 0x53702  srl         $a2, $a1, 28
    ctx->pc = 0x14522cu;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 5), 28));
    // 0x145230: 0x34422000  ori         $v0, $v0, 0x2000
    ctx->pc = 0x145230u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8192);
    // 0x145234: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x145234u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x145238: 0xac450000  sw          $a1, 0x0($v0)
    ctx->pc = 0x145238u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 5)); // MMIO: 0x10000000
    // 0x14523c: 0x2463a6f8  addiu       $v1, $v1, -0x5908
    ctx->pc = 0x14523cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294944504));
    // 0x145240: 0x63080  sll         $a2, $a2, 2
    ctx->pc = 0x145240u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x145244: 0xc33021  addu        $a2, $a2, $v1
    ctx->pc = 0x145244u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x145248: 0x8cc20000  lw          $v0, 0x0($a2)
    ctx->pc = 0x145248u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x14524c: 0x3e00008  jr          $ra
    ctx->pc = 0x14524Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x145250u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14524Cu;
            // 0x145250: 0xac820830  sw          $v0, 0x830($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 2096), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x145254u;
    // 0x145254: 0x0  nop
    ctx->pc = 0x145254u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
