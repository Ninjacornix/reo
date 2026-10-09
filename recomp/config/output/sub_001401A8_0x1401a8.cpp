#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001401A8
// Address: 0x1401a8 - 0x1401dc
void sub_001401A8_0x1401a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001401A8_0x1401a8");
#endif

    switch (ctx->pc) {
        case 0x1401c8u: goto label_1401c8;
        default: break;
    }

    ctx->pc = 0x1401a8u;

    // 0x1401a8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1401a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1401ac: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1401acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1401b0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1401b0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1401b4: 0x12000005  beqz        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1401B4u;
    {
        const bool branch_taken_0x1401b4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x1401B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1401B4u;
            // 0x1401b8: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1401b4) {
            ctx->pc = 0x1401CCu;
            goto label_1401cc;
        }
    }
    ctx->pc = 0x1401BCu;
    // 0x1401bc: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1401bcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1401c0: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1401C0u;
    SET_GPR_U32(ctx, 31, 0x1401C8u);
    ctx->pc = 0x1401C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1401C0u;
            // 0x1401c4: 0x24060030  addiu       $a2, $zero, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1401C8u; }
        if (ctx->pc != 0x1401C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1401C8u; }
        if (ctx->pc != 0x1401C8u) { return; }
    }
    ctx->pc = 0x1401C8u;
label_1401c8:
    // 0x1401c8: 0xa2000004  sb          $zero, 0x4($s0)
    ctx->pc = 0x1401c8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 4), (uint8_t)GPR_U32(ctx, 0));
label_1401cc:
    // 0x1401cc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1401ccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1401d0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1401d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1401d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1401D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1401D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1401D4u;
            // 0x1401d8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1401C8u: goto label_1401c8;
            case 0x1401CCu: goto label_1401cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1401DCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
