#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00115838
// Address: 0x115838 - 0x115868
void sub_00115838_0x115838(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00115838_0x115838");
#endif

    switch (ctx->pc) {
        case 0x11585cu: goto label_11585c;
        default: break;
    }

    ctx->pc = 0x115838u;

    // 0x115838: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x115838u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11583c: 0x308400ff  andi        $a0, $a0, 0xFF
    ctx->pc = 0x11583cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x115840: 0xafa50004  sw          $a1, 0x4($sp)
    ctx->pc = 0x115840u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 5));
    // 0x115844: 0xafa40000  sw          $a0, 0x0($sp)
    ctx->pc = 0x115844u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 4));
    // 0x115848: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x115848u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11584c: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x11584cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x115850: 0x24040020  addiu       $a0, $zero, 0x20
    ctx->pc = 0x115850u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x115854: 0xc045294  jal         func_114A50
    ctx->pc = 0x115854u;
    SET_GPR_U32(ctx, 31, 0x11585Cu);
    ctx->pc = 0x115858u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115854u;
            // 0x115858: 0xafa60008  sw          $a2, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114A50u;
    if (runtime->hasFunction(0x114A50u)) {
        auto targetFn = runtime->lookupFunction(0x114A50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11585Cu; }
        if (ctx->pc != 0x11585Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114A50_0x114a50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11585Cu; }
        if (ctx->pc != 0x11585Cu) { return; }
    }
    ctx->pc = 0x11585Cu;
label_11585c:
    // 0x11585c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x11585cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x115860: 0x3e00008  jr          $ra
    ctx->pc = 0x115860u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x115864u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115860u;
            // 0x115864: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11585Cu: goto label_11585c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x115868u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
