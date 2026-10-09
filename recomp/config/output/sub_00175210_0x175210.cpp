#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00175210
// Address: 0x175210 - 0x175258
void sub_00175210_0x175210(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00175210_0x175210");
#endif

    ctx->pc = 0x175210u;

    // 0x175210: 0x24851aa0  addiu       $a1, $a0, 0x1AA0
    ctx->pc = 0x175210u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), 6816));
    // 0x175214: 0x2406ffff  addiu       $a2, $zero, -0x1
    ctx->pc = 0x175214u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x175218: 0x8ca30014  lw          $v1, 0x14($a1)
    ctx->pc = 0x175218u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 20)));
    // 0x17521c: 0x310c0  sll         $v0, $v1, 3
    ctx->pc = 0x17521cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x175220: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x175220u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x175224: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x175224u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x175228: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x175228u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x17522c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x17522cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x175230: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x175230u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x175234: 0x8c831190  lw          $v1, 0x1190($a0)
    ctx->pc = 0x175234u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4496)));
    // 0x175238: 0x31100  sll         $v0, $v1, 4
    ctx->pc = 0x175238u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x17523c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x17523cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x175240: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x175240u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x175244: 0xa22821  addu        $a1, $a1, $v0
    ctx->pc = 0x175244u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x175248: 0x8ca20020  lw          $v0, 0x20($a1)
    ctx->pc = 0x175248u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 32)));
    // 0x17524c: 0x28430000  slti        $v1, $v0, 0x0
    ctx->pc = 0x17524cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x175250: 0x3e00008  jr          $ra
    ctx->pc = 0x175250u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x175254u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175250u;
            // 0x175254: 0xc3100b  movn        $v0, $a2, $v1 (Delay Slot)
        if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 6));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x175258u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
