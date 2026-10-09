#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001168D8
// Address: 0x1168d8 - 0x116920
void sub_001168D8_0x1168d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001168D8_0x1168d8");
#endif

    ctx->pc = 0x1168d8u;

    // 0x1168d8: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1168d8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1168dc: 0x42080  sll         $a0, $a0, 2
    ctx->pc = 0x1168dcu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1168e0: 0x2442b140  addiu       $v0, $v0, -0x4EC0
    ctx->pc = 0x1168e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294947136));
    // 0x1168e4: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x1168e4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1168e8: 0x3e00008  jr          $ra
    ctx->pc = 0x1168E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1168ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1168E8u;
            // 0x1168ec: 0x8c820000  lw          $v0, 0x0($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1168F0u;
    // 0x1168f0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1168f0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1168f4: 0x42080  sll         $a0, $a0, 2
    ctx->pc = 0x1168f4u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1168f8: 0x2442b140  addiu       $v0, $v0, -0x4EC0
    ctx->pc = 0x1168f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294947136));
    // 0x1168fc: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x1168fcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x116900: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x116900u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x116904: 0x3e00008  jr          $ra
    ctx->pc = 0x116904u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x116908u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116904u;
            // 0x116908: 0xac850000  sw          $a1, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x11690Cu;
    // 0x11690c: 0x0  nop
    ctx->pc = 0x11690cu;
    // NOP
    // 0x116910: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x116910u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x116914: 0x3e00008  jr          $ra
    ctx->pc = 0x116914u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x116918u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116914u;
            // 0x116918: 0x2442af98  addiu       $v0, $v0, -0x5068 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294946712));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x11691Cu;
    // 0x11691c: 0x0  nop
    ctx->pc = 0x11691cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
