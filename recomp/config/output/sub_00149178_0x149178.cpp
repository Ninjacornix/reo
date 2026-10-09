#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00149178
// Address: 0x149178 - 0x14919c
void sub_00149178_0x149178(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00149178_0x149178");
#endif

    switch (ctx->pc) {
        case 0x14918cu: goto label_14918c;
        default: break;
    }

    ctx->pc = 0x149178u;

    // 0x149178: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x149178u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x14917c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x14917cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x149180: 0x8c840040  lw          $a0, 0x40($a0)
    ctx->pc = 0x149180u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x149184: 0xc044f26  jal         func_113C98
    ctx->pc = 0x149184u;
    SET_GPR_U32(ctx, 31, 0x14918Cu);
    ctx->pc = 0x149188u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x149184u;
            // 0x149188: 0x24840068  addiu       $a0, $a0, 0x68 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 104));
        ctx->in_delay_slot = false;
    ctx->pc = 0x113C98u;
    if (runtime->hasFunction(0x113C98u)) {
        auto targetFn = runtime->lookupFunction(0x113C98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14918Cu; }
        if (ctx->pc != 0x14918Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00113C98_0x113c98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14918Cu; }
        if (ctx->pc != 0x14918Cu) { return; }
    }
    ctx->pc = 0x14918Cu;
label_14918c:
    // 0x14918c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x14918cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x149190: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x149190u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x149194: 0x3e00008  jr          $ra
    ctx->pc = 0x149194u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x149198u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x149194u;
            // 0x149198: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x14918Cu: goto label_14918c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x14919Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
