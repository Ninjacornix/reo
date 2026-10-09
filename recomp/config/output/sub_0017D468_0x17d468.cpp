#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017D468
// Address: 0x17d468 - 0x17d490
void sub_0017D468_0x17d468(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017D468_0x17d468");
#endif

    switch (ctx->pc) {
        case 0x17d470u: goto label_17d470;
        case 0x17d478u: goto label_17d478;
        case 0x17d480u: goto label_17d480;
        case 0x17d488u: goto label_17d488;
        default: break;
    }

    ctx->pc = 0x17d468u;

    // 0x17d468: 0x3e00008  jr          $ra
    ctx->pc = 0x17D468u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D46Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D468u;
            // 0x17d46c: 0x8c820034  lw          $v0, 0x34($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 52)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17D470u: goto label_17d470;
            case 0x17D478u: goto label_17d478;
            case 0x17D480u: goto label_17d480;
            case 0x17D488u: goto label_17d488;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17D470u;
label_17d470:
    // 0x17d470: 0x3e00008  jr          $ra
    ctx->pc = 0x17D470u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D474u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D470u;
            // 0x17d474: 0xac850064  sw          $a1, 0x64($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 100), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17D470u: goto label_17d470;
            case 0x17D478u: goto label_17d478;
            case 0x17D480u: goto label_17d480;
            case 0x17D488u: goto label_17d488;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17D478u;
label_17d478:
    // 0x17d478: 0x3e00008  jr          $ra
    ctx->pc = 0x17D478u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D47Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D478u;
            // 0x17d47c: 0x8c820064  lw          $v0, 0x64($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 100)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17D470u: goto label_17d470;
            case 0x17D478u: goto label_17d478;
            case 0x17D480u: goto label_17d480;
            case 0x17D488u: goto label_17d488;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17D480u;
label_17d480:
    // 0x17d480: 0x3e00008  jr          $ra
    ctx->pc = 0x17D480u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D484u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D480u;
            // 0x17d484: 0xac850068  sw          $a1, 0x68($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 104), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17D470u: goto label_17d470;
            case 0x17D478u: goto label_17d478;
            case 0x17D480u: goto label_17d480;
            case 0x17D488u: goto label_17d488;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17D488u;
label_17d488:
    // 0x17d488: 0x3e00008  jr          $ra
    ctx->pc = 0x17D488u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17D48Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17D488u;
            // 0x17d48c: 0x8c820068  lw          $v0, 0x68($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 104)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17D470u: goto label_17d470;
            case 0x17D478u: goto label_17d478;
            case 0x17D480u: goto label_17d480;
            case 0x17D488u: goto label_17d488;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17D490u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
