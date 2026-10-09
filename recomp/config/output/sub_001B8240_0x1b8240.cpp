#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B8240
// Address: 0x1b8240 - 0x1b8278
void sub_001B8240_0x1b8240(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B8240_0x1b8240");
#endif

    switch (ctx->pc) {
        case 0x1b8250u: goto label_1b8250;
        case 0x1b8260u: goto label_1b8260;
        case 0x1b826cu: goto label_1b826c;
        default: break;
    }

    ctx->pc = 0x1b8240u;

    // 0x1b8240: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b8240u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b8244: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b8244u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b8248: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1B8248u;
    SET_GPR_U32(ctx, 31, 0x1B8250u);
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8250u; }
        if (ctx->pc != 0x1B8250u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8250u; }
        if (ctx->pc != 0x1B8250u) { return; }
    }
    ctx->pc = 0x1B8250u;
label_1b8250:
    // 0x1b8250: 0x3c04005c  lui         $a0, 0x5C
    ctx->pc = 0x1b8250u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)92 << 16));
    // 0x1b8254: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1b8254u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1b8258: 0xc06dfd0  jal         func_1B7F40
    ctx->pc = 0x1B8258u;
    SET_GPR_U32(ctx, 31, 0x1B8260u);
    ctx->pc = 0x1B825Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8258u;
            // 0x1b825c: 0x2484a1f0  addiu       $a0, $a0, -0x5E10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294943216));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B7F40u;
    if (runtime->hasFunction(0x1B7F40u)) {
        auto targetFn = runtime->lookupFunction(0x1B7F40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8260u; }
        if (ctx->pc != 0x1B8260u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B7F40_0x1b7f40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8260u; }
        if (ctx->pc != 0x1B8260u) { return; }
    }
    ctx->pc = 0x1B8260u;
label_1b8260:
    // 0x1b8260: 0x24040003  addiu       $a0, $zero, 0x3
    ctx->pc = 0x1b8260u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1b8264: 0xc06e034  jal         func_1B80D0
    ctx->pc = 0x1B8264u;
    SET_GPR_U32(ctx, 31, 0x1B826Cu);
    ctx->pc = 0x1B8268u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8264u;
            // 0x1b8268: 0x24050008  addiu       $a1, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B80D0u;
    if (runtime->hasFunction(0x1B80D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B80D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B826Cu; }
        if (ctx->pc != 0x1B826Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B80D0_0x1b80d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B826Cu; }
        if (ctx->pc != 0x1B826Cu) { return; }
    }
    ctx->pc = 0x1B826Cu;
label_1b826c:
    // 0x1b826c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b826cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b8270: 0x3e00008  jr          $ra
    ctx->pc = 0x1B8270u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B8274u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8270u;
            // 0x1b8274: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B8250u: goto label_1b8250;
            case 0x1B8260u: goto label_1b8260;
            case 0x1B826Cu: goto label_1b826c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B8278u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
