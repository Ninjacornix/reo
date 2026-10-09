#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C748
// Address: 0x12c748 - 0x12c798
void sub_0012C748_0x12c748(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C748_0x12c748");
#endif

    switch (ctx->pc) {
        case 0x12c774u: goto label_12c774;
        case 0x12c778u: goto label_12c778;
        default: break;
    }

    ctx->pc = 0x12c748u;

    // 0x12c748: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c748u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c74c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c74cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c750: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c750u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c754: 0x804fb3c  j           func_13ECF0
    ctx->pc = 0x12C754u;
    ctx->pc = 0x12C758u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C754u;
            // 0x12c758: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13ECF0u;
    if (runtime->hasFunction(0x13ECF0u)) {
        auto targetFn = runtime->lookupFunction(0x13ECF0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013ECF0_0x13ecf0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12C75Cu;
    // 0x12c75c: 0x0  nop
    ctx->pc = 0x12c75cu;
    // NOP
    // 0x12c760: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x12c760u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x12c764: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c764u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c768: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c768u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c76c: 0xc045a12  jal         func_116848
    ctx->pc = 0x12C76Cu;
    SET_GPR_U32(ctx, 31, 0x12C774u);
    ctx->pc = 0x12C770u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C76Cu;
            // 0x12c770: 0x2484ad28  addiu       $a0, $a0, -0x52D8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294946088));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C774u; }
        if (ctx->pc != 0x12C774u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C774u; }
        if (ctx->pc != 0x12C774u) { return; }
    }
    ctx->pc = 0x12C774u;
label_12c774:
    // 0x12c774: 0x0  nop
    ctx->pc = 0x12c774u;
    // NOP
label_12c778:
    // 0x12c778: 0x0  nop
    ctx->pc = 0x12c778u;
    // NOP
    // 0x12c77c: 0x0  nop
    ctx->pc = 0x12c77cu;
    // NOP
    // 0x12c780: 0x0  nop
    ctx->pc = 0x12c780u;
    // NOP
    // 0x12c784: 0x0  nop
    ctx->pc = 0x12c784u;
    // NOP
    // 0x12c788: 0x0  nop
    ctx->pc = 0x12c788u;
    // NOP
    // 0x12c78c: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x12C78Cu;
    {
        const bool branch_taken_0x12c78c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x12c78c) {
            ctx->pc = 0x12C778u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12c778;
        }
    }
    ctx->pc = 0x12C794u;
    // 0x12c794: 0x0  nop
    ctx->pc = 0x12c794u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
