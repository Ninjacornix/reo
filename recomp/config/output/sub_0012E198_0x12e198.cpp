#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012E198
// Address: 0x12e198 - 0x12e1cc
void sub_0012E198_0x12e198(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012E198_0x12e198");
#endif

    ctx->pc = 0x12e198u;

    // 0x12e198: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12e198u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12e19c: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x12e19cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12e1a0: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x12E1A0u;
    {
        const bool branch_taken_0x12e1a0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x12E1A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E1A0u;
            // 0x12e1a4: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12e1a0) {
            ctx->pc = 0x12E1C0u;
            goto label_12e1c0;
        }
    }
    ctx->pc = 0x12E1A8u;
    // 0x12e1a8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12e1a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12e1ac: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12e1acu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12e1b0: 0x2406000c  addiu       $a2, $zero, 0xC
    ctx->pc = 0x12e1b0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x12e1b4: 0xa0400000  sb          $zero, 0x0($v0)
    ctx->pc = 0x12e1b4u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x12e1b8: 0x8041f1a  j           func_107C68
    ctx->pc = 0x12E1B8u;
    ctx->pc = 0x12E1BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12E1B8u;
            // 0x12e1bc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12E1C0u;
label_12e1c0:
    // 0x12e1c0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12e1c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12e1c4: 0x3e00008  jr          $ra
    ctx->pc = 0x12E1C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12E1C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E1C4u;
            // 0x12e1c8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12E1C0u: goto label_12e1c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12E1CCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
