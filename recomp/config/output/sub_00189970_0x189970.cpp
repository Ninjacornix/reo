#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00189970
// Address: 0x189970 - 0x1899f0
void sub_00189970_0x189970(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00189970_0x189970");
#endif

    ctx->pc = 0x189970u;

    // 0x189970: 0x24e2ffff  addiu       $v0, $a3, -0x1
    ctx->pc = 0x189970u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x189974: 0xac850000  sw          $a1, 0x0($a0)
    ctx->pc = 0x189974u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
    // 0x189978: 0x401827  not         $v1, $v0
    ctx->pc = 0x189978u;
    SET_GPR_U64(ctx, 3, ~(GPR_U64(ctx, 2) | GPR_U64(ctx, 0)));
    // 0x18997c: 0xac870014  sw          $a3, 0x14($a0)
    ctx->pc = 0x18997cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 7));
    // 0x189980: 0xc71021  addu        $v0, $a2, $a3
    ctx->pc = 0x189980u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x189984: 0x8c850000  lw          $a1, 0x0($a0)
    ctx->pc = 0x189984u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x189988: 0x8c870014  lw          $a3, 0x14($a0)
    ctx->pc = 0x189988u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x18998c: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x18998cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x189990: 0x623024  and         $a2, $v1, $v0
    ctx->pc = 0x189990u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x189994: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x189994u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x189998: 0x24e3ffff  addiu       $v1, $a3, -0x1
    ctx->pc = 0x189998u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x18999c: 0xa72821  addu        $a1, $a1, $a3
    ctx->pc = 0x18999cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 7)));
    // 0x1899a0: 0x601827  not         $v1, $v1
    ctx->pc = 0x1899a0u;
    SET_GPR_U64(ctx, 3, ~(GPR_U64(ctx, 3) | GPR_U64(ctx, 0)));
    // 0x1899a4: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x1899a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x1899a8: 0x651824  and         $v1, $v1, $a1
    ctx->pc = 0x1899a8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 5));
    // 0x1899ac: 0xac830004  sw          $v1, 0x4($a0)
    ctx->pc = 0x1899acu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 3));
    // 0x1899b0: 0x8c850000  lw          $a1, 0x0($a0)
    ctx->pc = 0x1899b0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1899b4: 0x8c870014  lw          $a3, 0x14($a0)
    ctx->pc = 0x1899b4u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x1899b8: 0xa62821  addu        $a1, $a1, $a2
    ctx->pc = 0x1899b8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0x1899bc: 0x24e3ffff  addiu       $v1, $a3, -0x1
    ctx->pc = 0x1899bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x1899c0: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x1899c0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x1899c4: 0x601827  not         $v1, $v1
    ctx->pc = 0x1899c4u;
    SET_GPR_U64(ctx, 3, ~(GPR_U64(ctx, 3) | GPR_U64(ctx, 0)));
    // 0x1899c8: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x1899c8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x1899cc: 0x651824  and         $v1, $v1, $a1
    ctx->pc = 0x1899ccu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 5));
    // 0x1899d0: 0xac830008  sw          $v1, 0x8($a0)
    ctx->pc = 0x1899d0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 3));
    // 0x1899d4: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x1899d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1899d8: 0xac83000c  sw          $v1, 0xC($a0)
    ctx->pc = 0x1899d8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 3));
    // 0x1899dc: 0x8c830008  lw          $v1, 0x8($a0)
    ctx->pc = 0x1899dcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1899e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1899E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1899E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1899E0u;
            // 0x1899e4: 0xac830010  sw          $v1, 0x10($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1899E8u;
    // 0x1899e8: 0x0  nop
    ctx->pc = 0x1899e8u;
    // NOP
    // 0x1899ec: 0x0  nop
    ctx->pc = 0x1899ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
