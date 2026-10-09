#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001583C8
// Address: 0x1583c8 - 0x1583f0
void sub_001583C8_0x1583c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001583C8_0x1583c8");
#endif

    ctx->pc = 0x1583c8u;

    // 0x1583c8: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1583c8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1583cc: 0xac444c64  sw          $a0, 0x4C64($v0)
    ctx->pc = 0x1583ccu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 19556), GPR_U32(ctx, 4));
    // 0x1583d0: 0x10800004  beqz        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1583D0u;
    {
        const bool branch_taken_0x1583d0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1583D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1583D0u;
            // 0x1583d4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1583d0) {
            ctx->pc = 0x1583E4u;
            goto label_1583e4;
        }
    }
    ctx->pc = 0x1583D8u;
    // 0x1583d8: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1583d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1583dc: 0x38630001  xori        $v1, $v1, 0x1
    ctx->pc = 0x1583dcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)1);
    // 0x1583e0: 0x3100b  movn        $v0, $zero, $v1
    ctx->pc = 0x1583e0u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 0));
label_1583e4:
    // 0x1583e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1583E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1583E4u: goto label_1583e4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1583ECu;
    // 0x1583ec: 0x0  nop
    ctx->pc = 0x1583ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
