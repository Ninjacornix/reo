#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A5EC0
// Address: 0x1a5ec0 - 0x1a5ef8
void sub_001A5EC0_0x1a5ec0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A5EC0_0x1a5ec0");
#endif

    ctx->pc = 0x1a5ec0u;

    // 0x1a5ec0: 0x448c0  sll         $t1, $a0, 3
    ctx->pc = 0x1a5ec0u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x1a5ec4: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a5ec4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a5ec8: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a5ec8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a5ecc: 0x24630a02  addiu       $v1, $v1, 0xA02
    ctx->pc = 0x1a5eccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2562));
    // 0x1a5ed0: 0x24840a00  addiu       $a0, $a0, 0xA00
    ctx->pc = 0x1a5ed0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2560));
    // 0x1a5ed4: 0x894021  addu        $t0, $a0, $t1
    ctx->pc = 0x1a5ed4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 9)));
    // 0x1a5ed8: 0x692021  addu        $a0, $v1, $t1
    ctx->pc = 0x1a5ed8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x1a5edc: 0xa5050000  sh          $a1, 0x0($t0)
    ctx->pc = 0x1a5edcu;
    WRITE16(ADD32(GPR_U32(ctx, 8), 0), (uint16_t)GPR_U32(ctx, 5));
    // 0x1a5ee0: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a5ee0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a5ee4: 0xa4860000  sh          $a2, 0x0($a0)
    ctx->pc = 0x1a5ee4u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 6));
    // 0x1a5ee8: 0x24630a04  addiu       $v1, $v1, 0xA04
    ctx->pc = 0x1a5ee8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2564));
    // 0x1a5eec: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x1a5eecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x1a5ef0: 0x3e00008  jr          $ra
    ctx->pc = 0x1A5EF0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A5EF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5EF0u;
            // 0x1a5ef4: 0xa4670000  sh          $a3, 0x0($v1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 7));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1A5EF8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
