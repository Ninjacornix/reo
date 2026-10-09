#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00138F30
// Address: 0x138f30 - 0x138f5c
void sub_00138F30_0x138f30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00138F30_0x138f30");
#endif

    ctx->pc = 0x138f30u;

    // 0x138f30: 0x41900  sll         $v1, $a0, 4
    ctx->pc = 0x138f30u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x138f34: 0x2c850008  sltiu       $a1, $a0, 0x8
    ctx->pc = 0x138f34u;
    SET_GPR_U64(ctx, 5, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)8) ? 1 : 0);
    // 0x138f38: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x138f38u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138f3c: 0x10a00005  beqz        $a1, . + 4 + (0x5 << 2)
    ctx->pc = 0x138F3Cu;
    {
        const bool branch_taken_0x138f3c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x138F40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138F3Cu;
            // 0x138f40: 0x641821  addu        $v1, $v1, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x138f3c) {
            ctx->pc = 0x138F54u;
            goto label_138f54;
        }
    }
    ctx->pc = 0x138F44u;
    // 0x138f44: 0x31080  sll         $v0, $v1, 2
    ctx->pc = 0x138f44u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x138f48: 0x3c010022  lui         $at, 0x22
    ctx->pc = 0x138f48u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)34 << 16));
    // 0x138f4c: 0x2421c430  addiu       $at, $at, -0x3BD0
    ctx->pc = 0x138f4cu;
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), 4294951984));
    // 0x138f50: 0x221021  addu        $v0, $at, $v0
    ctx->pc = 0x138f50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_138f54:
    // 0x138f54: 0x3e00008  jr          $ra
    ctx->pc = 0x138F54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138F54u: goto label_138f54;
            default: break;
        }
        return;
    }
    ctx->pc = 0x138F5Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
