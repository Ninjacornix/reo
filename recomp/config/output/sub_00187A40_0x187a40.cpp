#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00187A40
// Address: 0x187a40 - 0x187a70
void sub_00187A40_0x187a40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00187A40_0x187a40");
#endif

    ctx->pc = 0x187a40u;

    // 0x187a40: 0x418c0  sll         $v1, $a0, 3
    ctx->pc = 0x187a40u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x187a44: 0x2c850002  sltiu       $a1, $a0, 0x2
    ctx->pc = 0x187a44u;
    SET_GPR_U64(ctx, 5, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x187a48: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x187a48u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187a4c: 0x10a00006  beqz        $a1, . + 4 + (0x6 << 2)
    ctx->pc = 0x187A4Cu;
    {
        const bool branch_taken_0x187a4c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x187A50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x187A4Cu;
            // 0x187a50: 0x641823  subu        $v1, $v1, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x187a4c) {
            ctx->pc = 0x187A68u;
            goto label_187a68;
        }
    }
    ctx->pc = 0x187A54u;
    // 0x187a54: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x187a54u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x187a58: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x187a58u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x187a5c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x187a5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x187a60: 0x8c42b8c8  lw          $v0, -0x4738($v0)
    ctx->pc = 0x187a60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294949064)));
    // 0x187a64: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x187a64u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
label_187a68:
    // 0x187a68: 0x3e00008  jr          $ra
    ctx->pc = 0x187A68u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x187A68u: goto label_187a68;
            default: break;
        }
        return;
    }
    ctx->pc = 0x187A70u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
