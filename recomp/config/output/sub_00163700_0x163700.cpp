#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00163700
// Address: 0x163700 - 0x163720
void sub_00163700_0x163700(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00163700_0x163700");
#endif

    switch (ctx->pc) {
        case 0x163710u: goto label_163710;
        default: break;
    }

    ctx->pc = 0x163700u;

    // 0x163700: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x163700u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x163704: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x163704u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x163708: 0xc0505d2  jal         func_141748
    ctx->pc = 0x163708u;
    SET_GPR_U32(ctx, 31, 0x163710u);
    ctx->pc = 0x141748u;
    if (runtime->hasFunction(0x141748u)) {
        auto targetFn = runtime->lookupFunction(0x141748u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163710u; }
        if (ctx->pc != 0x163710u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141748_0x141748(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163710u; }
        if (ctx->pc != 0x163710u) { return; }
    }
    ctx->pc = 0x163710u;
label_163710:
    // 0x163710: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x163710u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x163714: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x163714u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x163718: 0x3e00008  jr          $ra
    ctx->pc = 0x163718u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16371Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163718u;
            // 0x16371c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x163710u: goto label_163710;
            default: break;
        }
        return;
    }
    ctx->pc = 0x163720u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
