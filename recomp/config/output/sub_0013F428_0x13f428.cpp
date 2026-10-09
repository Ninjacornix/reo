#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013F428
// Address: 0x13f428 - 0x13f45c
void sub_0013F428_0x13f428(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013F428_0x13f428");
#endif

    switch (ctx->pc) {
        case 0x13f448u: goto label_13f448;
        default: break;
    }

    ctx->pc = 0x13f428u;

    // 0x13f428: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13f428u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13f42c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13f42cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13f430: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x13f430u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f434: 0x12000005  beqz        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x13F434u;
    {
        const bool branch_taken_0x13f434 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x13F438u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F434u;
            // 0x13f438: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f434) {
            ctx->pc = 0x13F44Cu;
            goto label_13f44c;
        }
    }
    ctx->pc = 0x13F43Cu;
    // 0x13f43c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13f43cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f440: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x13F440u;
    SET_GPR_U32(ctx, 31, 0x13F448u);
    ctx->pc = 0x13F444u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F440u;
            // 0x13f444: 0x24060024  addiu       $a2, $zero, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 36));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F448u; }
        if (ctx->pc != 0x13F448u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F448u; }
        if (ctx->pc != 0x13F448u) { return; }
    }
    ctx->pc = 0x13F448u;
label_13f448:
    // 0x13f448: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x13f448u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
label_13f44c:
    // 0x13f44c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13f44cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13f450: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x13f450u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13f454: 0x3e00008  jr          $ra
    ctx->pc = 0x13F454u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F458u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F454u;
            // 0x13f458: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13F448u: goto label_13f448;
            case 0x13F44Cu: goto label_13f44c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13F45Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
