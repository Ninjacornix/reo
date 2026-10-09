#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C6690
// Address: 0x1c6690 - 0x1c66b0
void sub_001C6690_0x1c6690(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C6690_0x1c6690");
#endif

    switch (ctx->pc) {
        case 0x1c66a0u: goto label_1c66a0;
        default: break;
    }

    ctx->pc = 0x1c6690u;

    // 0x1c6690: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1c6690u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1c6694: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1c6694u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1c6698: 0xc072208  jal         func_1C8820
    ctx->pc = 0x1C6698u;
    SET_GPR_U32(ctx, 31, 0x1C66A0u);
    ctx->pc = 0x1C669Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C6698u;
            // 0x1c669c: 0x24840028  addiu       $a0, $a0, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 40));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8820u;
    if (runtime->hasFunction(0x1C8820u)) {
        auto targetFn = runtime->lookupFunction(0x1C8820u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C66A0u; }
        if (ctx->pc != 0x1C66A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8820_0x1c8820(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C66A0u; }
        if (ctx->pc != 0x1C66A0u) { return; }
    }
    ctx->pc = 0x1C66A0u;
label_1c66a0:
    // 0x1c66a0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1c66a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c66a4: 0x90420000  lbu         $v0, 0x0($v0)
    ctx->pc = 0x1c66a4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1c66a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1C66A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C66ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C66A8u;
            // 0x1c66ac: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C66A0u: goto label_1c66a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C66B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
