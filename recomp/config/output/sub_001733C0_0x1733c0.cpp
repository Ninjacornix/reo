#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001733C0
// Address: 0x1733c0 - 0x1733f4
void sub_001733C0_0x1733c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001733C0_0x1733c0");
#endif

    switch (ctx->pc) {
        case 0x1733d4u: goto label_1733d4;
        default: break;
    }

    ctx->pc = 0x1733c0u;

    // 0x1733c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1733c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1733c4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1733c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1733c8: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1733c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1733cc: 0xc05cf04  jal         func_173C10
    ctx->pc = 0x1733CCu;
    SET_GPR_U32(ctx, 31, 0x1733D4u);
    ctx->pc = 0x1733D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1733CCu;
            // 0x1733d0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x173C10u;
    if (runtime->hasFunction(0x173C10u)) {
        auto targetFn = runtime->lookupFunction(0x173C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1733D4u; }
        if (ctx->pc != 0x1733D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00173C10_0x173c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1733D4u; }
        if (ctx->pc != 0x1733D4u) { return; }
    }
    ctx->pc = 0x1733D4u;
label_1733d4:
    // 0x1733d4: 0x54400004  bnel        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x1733D4u;
    {
        const bool branch_taken_0x1733d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1733d4) {
            ctx->pc = 0x1733D8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1733D4u;
            // 0x1733d8: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1733E8u;
            goto label_1733e8;
        }
    }
    ctx->pc = 0x1733DCu;
    // 0x1733dc: 0x24030006  addiu       $v1, $zero, 0x6
    ctx->pc = 0x1733dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1733e0: 0xae03004c  sw          $v1, 0x4C($s0)
    ctx->pc = 0x1733e0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 76), GPR_U32(ctx, 3));
    // 0x1733e4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1733e4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1733e8:
    // 0x1733e8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1733e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1733ec: 0x3e00008  jr          $ra
    ctx->pc = 0x1733ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1733F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1733ECu;
            // 0x1733f0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1733D4u: goto label_1733d4;
            case 0x1733E8u: goto label_1733e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1733F4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
