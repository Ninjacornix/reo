#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001399F8
// Address: 0x1399f8 - 0x139a30
void sub_001399F8_0x1399f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001399F8_0x1399f8");
#endif

    switch (ctx->pc) {
        case 0x139a08u: goto label_139a08;
        default: break;
    }

    ctx->pc = 0x1399f8u;

    // 0x1399f8: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x1399f8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x1399fc: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1399fcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x139a00: 0x2443cc60  addiu       $v1, $v0, -0x33A0
    ctx->pc = 0x139a00u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 4294954080));
    // 0x139a04: 0x24040027  addiu       $a0, $zero, 0x27
    ctx->pc = 0x139a04u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 39));
label_139a08:
    // 0x139a08: 0x80620000  lb          $v0, 0x0($v1)
    ctx->pc = 0x139a08u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x139a0c: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x139a0cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x139a10: 0x38420000  xori        $v0, $v0, 0x0
    ctx->pc = 0x139a10u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)0);
    // 0x139a14: 0x62280a  movz        $a1, $v1, $v0
    ctx->pc = 0x139a14u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 3));
    // 0x139a18: 0x0  nop
    ctx->pc = 0x139a18u;
    // NOP
    // 0x139a1c: 0x481fffa  bgez        $a0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x139A1Cu;
    {
        const bool branch_taken_0x139a1c = (GPR_S64(ctx, 4) >= 0);
        ctx->pc = 0x139A20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139A1Cu;
            // 0x139a20: 0x24630048  addiu       $v1, $v1, 0x48 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 72));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139a1c) {
            ctx->pc = 0x139A08u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_139a08;
        }
    }
    ctx->pc = 0x139A24u;
    // 0x139a24: 0x3e00008  jr          $ra
    ctx->pc = 0x139A24u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x139A28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139A24u;
            // 0x139a28: 0xa0102d  daddu       $v0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x139A08u: goto label_139a08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x139A2Cu;
    // 0x139a2c: 0x0  nop
    ctx->pc = 0x139a2cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
