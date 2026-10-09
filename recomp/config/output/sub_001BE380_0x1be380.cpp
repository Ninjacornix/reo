#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BE380
// Address: 0x1be380 - 0x1be3b0
void sub_001BE380_0x1be380(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BE380_0x1be380");
#endif

    switch (ctx->pc) {
        case 0x1be39cu: goto label_1be39c;
        case 0x1be3a4u: goto label_1be3a4;
        default: break;
    }

    ctx->pc = 0x1be380u;

    // 0x1be380: 0x27bdfef0  addiu       $sp, $sp, -0x110
    ctx->pc = 0x1be380u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967024));
    // 0x1be384: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1be384u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1be388: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1be388u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1be38c: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x1be38cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1be390: 0x24a50440  addiu       $a1, $a1, 0x440
    ctx->pc = 0x1be390u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1088));
    // 0x1be394: 0xc06f918  jal         func_1BE460
    ctx->pc = 0x1BE394u;
    SET_GPR_U32(ctx, 31, 0x1BE39Cu);
    ctx->pc = 0x1BE398u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE394u;
            // 0x1be398: 0x24061234  addiu       $a2, $zero, 0x1234 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4660));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BE460u;
    if (runtime->hasFunction(0x1BE460u)) {
        auto targetFn = runtime->lookupFunction(0x1BE460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE39Cu; }
        if (ctx->pc != 0x1BE39Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BE460_0x1be460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE39Cu; }
        if (ctx->pc != 0x1BE39Cu) { return; }
    }
    ctx->pc = 0x1BE39Cu;
label_1be39c:
    // 0x1be39c: 0xc046734  jal         func_119CD0
    ctx->pc = 0x1BE39Cu;
    SET_GPR_U32(ctx, 31, 0x1BE3A4u);
    ctx->pc = 0x1BE3A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE39Cu;
            // 0x1be3a0: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x119CD0u;
    if (runtime->hasFunction(0x119CD0u)) {
        auto targetFn = runtime->lookupFunction(0x119CD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE3A4u; }
        if (ctx->pc != 0x1BE3A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00119CD0_0x119cd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE3A4u; }
        if (ctx->pc != 0x1BE3A4u) { return; }
    }
    ctx->pc = 0x1BE3A4u;
label_1be3a4:
    // 0x1be3a4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1be3a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1be3a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1BE3A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BE3ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE3A8u;
            // 0x1be3ac: 0x27bd0110  addiu       $sp, $sp, 0x110 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 272));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BE39Cu: goto label_1be39c;
            case 0x1BE3A4u: goto label_1be3a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BE3B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
