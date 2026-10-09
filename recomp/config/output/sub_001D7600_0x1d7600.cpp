#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D7600
// Address: 0x1d7600 - 0x1d7630
void sub_001D7600_0x1d7600(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D7600_0x1d7600");
#endif

    switch (ctx->pc) {
        case 0x1d7614u: goto label_1d7614;
        default: break;
    }

    ctx->pc = 0x1d7600u;

    // 0x1d7600: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1d7600u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1d7604: 0x24850004  addiu       $a1, $a0, 0x4
    ctx->pc = 0x1d7604u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1d7608: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d7608u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d760c: 0xc0763b8  jal         func_1D8EE0
    ctx->pc = 0x1D760Cu;
    SET_GPR_U32(ctx, 31, 0x1D7614u);
    ctx->pc = 0x1D7610u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D760Cu;
            // 0x1d7610: 0x27a6001c  addiu       $a2, $sp, 0x1C (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 28));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D8EE0u;
    if (runtime->hasFunction(0x1D8EE0u)) {
        auto targetFn = runtime->lookupFunction(0x1D8EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7614u; }
        if (ctx->pc != 0x1D7614u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D8EE0_0x1d8ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7614u; }
        if (ctx->pc != 0x1D7614u) { return; }
    }
    ctx->pc = 0x1D7614u;
label_1d7614:
    // 0x1d7614: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d7614u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d7618: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1d7618u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d761c: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d761cu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d7620: 0x3e00008  jr          $ra
    ctx->pc = 0x1D7620u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D7624u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7620u;
            // 0x1d7624: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D7614u: goto label_1d7614;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D7628u;
    // 0x1d7628: 0x0  nop
    ctx->pc = 0x1d7628u;
    // NOP
    // 0x1d762c: 0x0  nop
    ctx->pc = 0x1d762cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
