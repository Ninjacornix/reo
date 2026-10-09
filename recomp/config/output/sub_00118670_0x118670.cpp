#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00118670
// Address: 0x118670 - 0x1186a0
void sub_00118670_0x118670(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00118670_0x118670");
#endif

    switch (ctx->pc) {
        case 0x118680u: goto label_118680;
        case 0x11868cu: goto label_11868c;
        default: break;
    }

    ctx->pc = 0x118670u;

    // 0x118670: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x118670u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x118674: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x118674u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x118678: 0xc046188  jal         func_118620
    ctx->pc = 0x118678u;
    SET_GPR_U32(ctx, 31, 0x118680u);
    ctx->pc = 0x118620u;
    if (runtime->hasFunction(0x118620u)) {
        auto targetFn = runtime->lookupFunction(0x118620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118680u; }
        if (ctx->pc != 0x118680u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118620_0x118620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118680u; }
        if (ctx->pc != 0x118680u) { return; }
    }
    ctx->pc = 0x118680u;
label_118680:
    // 0x118680: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x118680u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x118684: 0xc045198  jal         func_114660
    ctx->pc = 0x118684u;
    SET_GPR_U32(ctx, 31, 0x11868Cu);
    ctx->pc = 0x118688u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118684u;
            // 0x118688: 0x8c449de4  lw          $a0, -0x621C($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294942180)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11868Cu; }
        if (ctx->pc != 0x11868Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11868Cu; }
        if (ctx->pc != 0x11868Cu) { return; }
    }
    ctx->pc = 0x11868Cu;
label_11868c:
    // 0x11868c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x11868cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x118690: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x118690u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x118694: 0x3e00008  jr          $ra
    ctx->pc = 0x118694u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x118698u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118694u;
            // 0x118698: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x118680u: goto label_118680;
            case 0x11868Cu: goto label_11868c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11869Cu;
    // 0x11869c: 0x0  nop
    ctx->pc = 0x11869cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
