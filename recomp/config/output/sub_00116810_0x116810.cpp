#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00116810
// Address: 0x116810 - 0x116848
void sub_00116810_0x116810(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00116810_0x116810");
#endif

    switch (ctx->pc) {
        case 0x11683cu: goto label_11683c;
        default: break;
    }

    ctx->pc = 0x116810u;

    // 0x116810: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x116810u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x116814: 0xffa50058  sd          $a1, 0x58($sp)
    ctx->pc = 0x116814u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 5));
    // 0x116818: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x116818u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x11681c: 0x27a50058  addiu       $a1, $sp, 0x58
    ctx->pc = 0x11681cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 88));
    // 0x116820: 0xffa60060  sd          $a2, 0x60($sp)
    ctx->pc = 0x116820u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 6));
    // 0x116824: 0xffa70068  sd          $a3, 0x68($sp)
    ctx->pc = 0x116824u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 7));
    // 0x116828: 0xffa80070  sd          $t0, 0x70($sp)
    ctx->pc = 0x116828u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 8));
    // 0x11682c: 0xffa90078  sd          $t1, 0x78($sp)
    ctx->pc = 0x11682cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 120), GPR_U64(ctx, 9));
    // 0x116830: 0xffaa0080  sd          $t2, 0x80($sp)
    ctx->pc = 0x116830u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 10));
    // 0x116834: 0xc045886  jal         func_116218
    ctx->pc = 0x116834u;
    SET_GPR_U32(ctx, 31, 0x11683Cu);
    ctx->pc = 0x116838u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x116834u;
            // 0x116838: 0xffab0088  sd          $t3, 0x88($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 136), GPR_U64(ctx, 11));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116218u;
    if (runtime->hasFunction(0x116218u)) {
        auto targetFn = runtime->lookupFunction(0x116218u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11683Cu; }
        if (ctx->pc != 0x11683Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116218_0x116218(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11683Cu; }
        if (ctx->pc != 0x11683Cu) { return; }
    }
    ctx->pc = 0x11683Cu;
label_11683c:
    // 0x11683c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x11683cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x116840: 0x3e00008  jr          $ra
    ctx->pc = 0x116840u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x116844u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x116840u;
            // 0x116844: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11683Cu: goto label_11683c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x116848u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
