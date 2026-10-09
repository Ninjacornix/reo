#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013F0B8
// Address: 0x13f0b8 - 0x13f0dc
void sub_0013F0B8_0x13f0b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013F0B8_0x13f0b8");
#endif

    switch (ctx->pc) {
        case 0x13f0ccu: goto label_13f0cc;
        default: break;
    }

    ctx->pc = 0x13f0b8u;

    // 0x13f0b8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13f0b8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13f0bc: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13f0bcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13f0c0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13f0c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13f0c4: 0xc045a12  jal         func_116848
    ctx->pc = 0x13F0C4u;
    SET_GPR_U32(ctx, 31, 0x13F0CCu);
    ctx->pc = 0x13F0C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F0C4u;
            // 0x13f0c8: 0x2484d910  addiu       $a0, $a0, -0x26F0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957328));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F0CCu; }
        if (ctx->pc != 0x13F0CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F0CCu; }
        if (ctx->pc != 0x13F0CCu) { return; }
    }
    ctx->pc = 0x13F0CCu;
label_13f0cc:
    // 0x13f0cc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x13f0ccu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f0d0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13f0d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13f0d4: 0x3e00008  jr          $ra
    ctx->pc = 0x13F0D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F0D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F0D4u;
            // 0x13f0d8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13F0CCu: goto label_13f0cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13F0DCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
