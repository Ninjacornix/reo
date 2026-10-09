#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A5F00
// Address: 0x1a5f00 - 0x1a5f50
void sub_001A5F00_0x1a5f00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A5F00_0x1a5f00");
#endif

    ctx->pc = 0x1a5f00u;

    // 0x1a5f00: 0x448c0  sll         $t1, $a0, 3
    ctx->pc = 0x1a5f00u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x1a5f04: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a5f04u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a5f08: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a5f08u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a5f0c: 0x24630a02  addiu       $v1, $v1, 0xA02
    ctx->pc = 0x1a5f0cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2562));
    // 0x1a5f10: 0x24840a00  addiu       $a0, $a0, 0xA00
    ctx->pc = 0x1a5f10u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2560));
    // 0x1a5f14: 0x894021  addu        $t0, $a0, $t1
    ctx->pc = 0x1a5f14u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 9)));
    // 0x1a5f18: 0x85080000  lh          $t0, 0x0($t0)
    ctx->pc = 0x1a5f18u;
    SET_GPR_S32(ctx, 8, (int16_t)READ16(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1a5f1c: 0x692021  addu        $a0, $v1, $t1
    ctx->pc = 0x1a5f1cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x1a5f20: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a5f20u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a5f24: 0x24630a04  addiu       $v1, $v1, 0xA04
    ctx->pc = 0x1a5f24u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2564));
    // 0x1a5f28: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x1a5f28u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x1a5f2c: 0xa4a80000  sh          $t0, 0x0($a1)
    ctx->pc = 0x1a5f2cu;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 8));
    // 0x1a5f30: 0x84840000  lh          $a0, 0x0($a0)
    ctx->pc = 0x1a5f30u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1a5f34: 0xa4c40000  sh          $a0, 0x0($a2)
    ctx->pc = 0x1a5f34u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 4));
    // 0x1a5f38: 0x84630000  lh          $v1, 0x0($v1)
    ctx->pc = 0x1a5f38u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1a5f3c: 0x3e00008  jr          $ra
    ctx->pc = 0x1A5F3Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A5F40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5F3Cu;
            // 0x1a5f40: 0xa4e30000  sh          $v1, 0x0($a3) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 7), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1A5F44u;
    // 0x1a5f44: 0x0  nop
    ctx->pc = 0x1a5f44u;
    // NOP
    // 0x1a5f48: 0x0  nop
    ctx->pc = 0x1a5f48u;
    // NOP
    // 0x1a5f4c: 0x0  nop
    ctx->pc = 0x1a5f4cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
