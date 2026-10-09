#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B1D60
// Address: 0x1b1d60 - 0x1b1da0
void sub_001B1D60_0x1b1d60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B1D60_0x1b1d60");
#endif

    switch (ctx->pc) {
        case 0x1b1d74u: goto label_1b1d74;
        case 0x1b1d80u: goto label_1b1d80;
        case 0x1b1d8cu: goto label_1b1d8c;
        default: break;
    }

    ctx->pc = 0x1b1d60u;

    // 0x1b1d60: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b1d60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b1d64: 0x3c04004f  lui         $a0, 0x4F
    ctx->pc = 0x1b1d64u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)79 << 16));
    // 0x1b1d68: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b1d68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b1d6c: 0xc06c6f0  jal         func_1B1BC0
    ctx->pc = 0x1B1D6Cu;
    SET_GPR_U32(ctx, 31, 0x1B1D74u);
    ctx->pc = 0x1B1D70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1D6Cu;
            // 0x1b1d70: 0x2484a8c0  addiu       $a0, $a0, -0x5740 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294944960));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B1BC0u;
    if (runtime->hasFunction(0x1B1BC0u)) {
        auto targetFn = runtime->lookupFunction(0x1B1BC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1D74u; }
        if (ctx->pc != 0x1B1D74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1BC0_0x1b1bc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1D74u; }
        if (ctx->pc != 0x1B1D74u) { return; }
    }
    ctx->pc = 0x1B1D74u;
label_1b1d74:
    // 0x1b1d74: 0x3c04004f  lui         $a0, 0x4F
    ctx->pc = 0x1b1d74u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)79 << 16));
    // 0x1b1d78: 0xc06c6f0  jal         func_1B1BC0
    ctx->pc = 0x1B1D78u;
    SET_GPR_U32(ctx, 31, 0x1B1D80u);
    ctx->pc = 0x1B1D7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1D78u;
            // 0x1b1d7c: 0x24848970  addiu       $a0, $a0, -0x7690 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294936944));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B1BC0u;
    if (runtime->hasFunction(0x1B1BC0u)) {
        auto targetFn = runtime->lookupFunction(0x1B1BC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1D80u; }
        if (ctx->pc != 0x1B1D80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1BC0_0x1b1bc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1D80u; }
        if (ctx->pc != 0x1B1D80u) { return; }
    }
    ctx->pc = 0x1B1D80u;
label_1b1d80:
    // 0x1b1d80: 0x3c04004e  lui         $a0, 0x4E
    ctx->pc = 0x1b1d80u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)78 << 16));
    // 0x1b1d84: 0xc06c6f0  jal         func_1B1BC0
    ctx->pc = 0x1B1D84u;
    SET_GPR_U32(ctx, 31, 0x1B1D8Cu);
    ctx->pc = 0x1B1D88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1D84u;
            // 0x1b1d88: 0x24846a20  addiu       $a0, $a0, 0x6A20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 27168));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B1BC0u;
    if (runtime->hasFunction(0x1B1BC0u)) {
        auto targetFn = runtime->lookupFunction(0x1B1BC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1D8Cu; }
        if (ctx->pc != 0x1B1D8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1BC0_0x1b1bc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1D8Cu; }
        if (ctx->pc != 0x1B1D8Cu) { return; }
    }
    ctx->pc = 0x1B1D8Cu;
label_1b1d8c:
    // 0x1b1d8c: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b1d8cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b1d90: 0xa020ae0f  sb          $zero, -0x51F1($at)
    ctx->pc = 0x1b1d90u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294946319), (uint8_t)GPR_U32(ctx, 0));
    // 0x1b1d94: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b1d94u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b1d98: 0x3e00008  jr          $ra
    ctx->pc = 0x1B1D98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B1D9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1D98u;
            // 0x1b1d9c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B1D74u: goto label_1b1d74;
            case 0x1B1D80u: goto label_1b1d80;
            case 0x1B1D8Cu: goto label_1b1d8c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B1DA0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
