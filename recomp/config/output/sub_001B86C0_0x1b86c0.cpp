#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B86C0
// Address: 0x1b86c0 - 0x1b86f0
void sub_001B86C0_0x1b86c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B86C0_0x1b86c0");
#endif

    switch (ctx->pc) {
        case 0x1b86d4u: goto label_1b86d4;
        case 0x1b86dcu: goto label_1b86dc;
        default: break;
    }

    ctx->pc = 0x1b86c0u;

    // 0x1b86c0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1b86c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b86c4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b86c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b86c8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b86c8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b86cc: 0xc06b3d8  jal         func_1ACF60
    ctx->pc = 0x1B86CCu;
    SET_GPR_U32(ctx, 31, 0x1B86D4u);
    ctx->pc = 0x1B86D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B86CCu;
            // 0x1b86d0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ACF60u;
    if (runtime->hasFunction(0x1ACF60u)) {
        auto targetFn = runtime->lookupFunction(0x1ACF60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B86D4u; }
        if (ctx->pc != 0x1B86D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ACF60_0x1acf60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B86D4u; }
        if (ctx->pc != 0x1B86D4u) { return; }
    }
    ctx->pc = 0x1B86D4u;
label_1b86d4:
    // 0x1b86d4: 0xc06b8f4  jal         func_1AE3D0
    ctx->pc = 0x1B86D4u;
    SET_GPR_U32(ctx, 31, 0x1B86DCu);
    ctx->pc = 0x1B86D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B86D4u;
            // 0x1b86d8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AE3D0u;
    if (runtime->hasFunction(0x1AE3D0u)) {
        auto targetFn = runtime->lookupFunction(0x1AE3D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B86DCu; }
        if (ctx->pc != 0x1B86DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AE3D0_0x1ae3d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B86DCu; }
        if (ctx->pc != 0x1B86DCu) { return; }
    }
    ctx->pc = 0x1B86DCu;
label_1b86dc:
    // 0x1b86dc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b86dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b86e0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b86e0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b86e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1B86E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B86E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B86E4u;
            // 0x1b86e8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B86D4u: goto label_1b86d4;
            case 0x1B86DCu: goto label_1b86dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B86ECu;
    // 0x1b86ec: 0x0  nop
    ctx->pc = 0x1b86ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
