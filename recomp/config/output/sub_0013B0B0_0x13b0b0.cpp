#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013B0B0
// Address: 0x13b0b0 - 0x13b110
void sub_0013B0B0_0x13b0b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013B0B0_0x13b0b0");
#endif

    ctx->pc = 0x13b0b0u;

    // 0x13b0b0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13b0b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13b0b4: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x13b0b4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b0b8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13b0b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13b0bc: 0x8ca40024  lw          $a0, 0x24($a1)
    ctx->pc = 0x13b0bcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 36)));
    // 0x13b0c0: 0x8ca2001c  lw          $v0, 0x1C($a1)
    ctx->pc = 0x13b0c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 28)));
    // 0x13b0c4: 0xdca30008  ld          $v1, 0x8($a1)
    ctx->pc = 0x13b0c4u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x13b0c8: 0x43ac0  sll         $a3, $a0, 11
    ctx->pc = 0x13b0c8u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 4), 11));
    // 0x13b0cc: 0x44102d  daddu       $v0, $v0, $a0
    ctx->pc = 0x13b0ccu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 4));
    // 0x13b0d0: 0x212f8  dsll        $v0, $v0, 11
    ctx->pc = 0x13b0d0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 11);
    // 0x13b0d4: 0x43202f  dsubu       $a0, $v0, $v1
    ctx->pc = 0x13b0d4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) - GPR_U64(ctx, 3));
    // 0x13b0d8: 0x62182b  sltu        $v1, $v1, $v0
    ctx->pc = 0x13b0d8u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x13b0dc: 0x4103c  dsll32      $v0, $a0, 0
    ctx->pc = 0x13b0dcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) << (32 + 0));
    // 0x13b0e0: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x13b0e0u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x13b0e4: 0x10600008  beqz        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x13B0E4u;
    {
        const bool branch_taken_0x13b0e4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x13B0E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B0E4u;
            // 0x13b0e8: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b0e4) {
            ctx->pc = 0x13B108u;
            goto label_13b108;
        }
    }
    ctx->pc = 0x13B0ECu;
    // 0x13b0ec: 0x8ca40020  lw          $a0, 0x20($a1)
    ctx->pc = 0x13b0ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 32)));
    // 0x13b0f0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13b0f0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b0f4: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x13b0f4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b0f8: 0x872021  addu        $a0, $a0, $a3
    ctx->pc = 0x13b0f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x13b0fc: 0x822023  subu        $a0, $a0, $v0
    ctx->pc = 0x13b0fcu;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x13b100: 0x8041f1a  j           func_107C68
    ctx->pc = 0x13B100u;
    ctx->pc = 0x13B104u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B100u;
            // 0x13b104: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13B108u;
label_13b108:
    // 0x13b108: 0x3e00008  jr          $ra
    ctx->pc = 0x13B108u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13B10Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B108u;
            // 0x13b10c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13B108u: goto label_13b108;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13B110u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
