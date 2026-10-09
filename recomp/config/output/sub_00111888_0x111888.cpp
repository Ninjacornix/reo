#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00111888
// Address: 0x111888 - 0x1118b8
void sub_00111888_0x111888(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00111888_0x111888");
#endif

    switch (ctx->pc) {
        case 0x1118a8u: goto label_1118a8;
        default: break;
    }

    ctx->pc = 0x111888u;

    // 0x111888: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x111888u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x11188c: 0xafa40000  sw          $a0, 0x0($sp)
    ctx->pc = 0x11188cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 4));
    // 0x111890: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x111890u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111894: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x111894u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x111898: 0xafa50004  sw          $a1, 0x4($sp)
    ctx->pc = 0x111898u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 5));
    // 0x11189c: 0xafa60008  sw          $a2, 0x8($sp)
    ctx->pc = 0x11189cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 6));
    // 0x1118a0: 0xc0445dc  jal         func_111770
    ctx->pc = 0x1118A0u;
    SET_GPR_U32(ctx, 31, 0x1118A8u);
    ctx->pc = 0x1118A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1118A0u;
            // 0x1118a4: 0xafa7000c  sw          $a3, 0xC($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111770u;
    if (runtime->hasFunction(0x111770u)) {
        auto targetFn = runtime->lookupFunction(0x111770u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1118A8u; }
        if (ctx->pc != 0x1118A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111770_0x111770(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1118A8u; }
        if (ctx->pc != 0x1118A8u) { return; }
    }
    ctx->pc = 0x1118A8u;
label_1118a8:
    // 0x1118a8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1118a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1118ac: 0x3e00008  jr          $ra
    ctx->pc = 0x1118ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1118B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1118ACu;
            // 0x1118b0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1118A8u: goto label_1118a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1118B4u;
    // 0x1118b4: 0x0  nop
    ctx->pc = 0x1118b4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
