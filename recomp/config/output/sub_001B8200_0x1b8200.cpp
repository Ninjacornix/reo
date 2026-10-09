#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B8200
// Address: 0x1b8200 - 0x1b8238
void sub_001B8200_0x1b8200(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B8200_0x1b8200");
#endif

    switch (ctx->pc) {
        case 0x1b8210u: goto label_1b8210;
        case 0x1b8220u: goto label_1b8220;
        case 0x1b822cu: goto label_1b822c;
        default: break;
    }

    ctx->pc = 0x1b8200u;

    // 0x1b8200: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b8200u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b8204: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b8204u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b8208: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1B8208u;
    SET_GPR_U32(ctx, 31, 0x1B8210u);
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8210u; }
        if (ctx->pc != 0x1B8210u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8210u; }
        if (ctx->pc != 0x1B8210u) { return; }
    }
    ctx->pc = 0x1B8210u;
label_1b8210:
    // 0x1b8210: 0x3c04005c  lui         $a0, 0x5C
    ctx->pc = 0x1b8210u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)92 << 16));
    // 0x1b8214: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1b8214u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1b8218: 0xc06dfd0  jal         func_1B7F40
    ctx->pc = 0x1B8218u;
    SET_GPR_U32(ctx, 31, 0x1B8220u);
    ctx->pc = 0x1B821Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8218u;
            // 0x1b821c: 0x2484a010  addiu       $a0, $a0, -0x5FF0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294942736));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B7F40u;
    if (runtime->hasFunction(0x1B7F40u)) {
        auto targetFn = runtime->lookupFunction(0x1B7F40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8220u; }
        if (ctx->pc != 0x1B8220u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B7F40_0x1b7f40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8220u; }
        if (ctx->pc != 0x1B8220u) { return; }
    }
    ctx->pc = 0x1B8220u;
label_1b8220:
    // 0x1b8220: 0x24040003  addiu       $a0, $zero, 0x3
    ctx->pc = 0x1b8220u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1b8224: 0xc06e034  jal         func_1B80D0
    ctx->pc = 0x1B8224u;
    SET_GPR_U32(ctx, 31, 0x1B822Cu);
    ctx->pc = 0x1B8228u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8224u;
            // 0x1b8228: 0x24050008  addiu       $a1, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B80D0u;
    if (runtime->hasFunction(0x1B80D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B80D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B822Cu; }
        if (ctx->pc != 0x1B822Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B80D0_0x1b80d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B822Cu; }
        if (ctx->pc != 0x1B822Cu) { return; }
    }
    ctx->pc = 0x1B822Cu;
label_1b822c:
    // 0x1b822c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b822cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b8230: 0x3e00008  jr          $ra
    ctx->pc = 0x1B8230u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B8234u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8230u;
            // 0x1b8234: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B8210u: goto label_1b8210;
            case 0x1B8220u: goto label_1b8220;
            case 0x1B822Cu: goto label_1b822c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B8238u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
