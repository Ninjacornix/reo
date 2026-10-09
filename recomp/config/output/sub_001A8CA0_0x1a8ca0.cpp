#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A8CA0
// Address: 0x1a8ca0 - 0x1a8ce0
void sub_001A8CA0_0x1a8ca0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A8CA0_0x1a8ca0");
#endif

    switch (ctx->pc) {
        case 0x1a8cc0u: goto label_1a8cc0;
        default: break;
    }

    ctx->pc = 0x1a8ca0u;

    // 0x1a8ca0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a8ca0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a8ca4: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a8ca4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a8ca8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a8ca8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a8cac: 0x80231050  lb          $v1, 0x1050($at)
    ctx->pc = 0x1a8cacu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 4176)));
    // 0x1a8cb0: 0x10600005  beqz        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1A8CB0u;
    {
        const bool branch_taken_0x1a8cb0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A8CB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8CB0u;
            // 0x1a8cb4: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a8cb0) {
            ctx->pc = 0x1A8CC8u;
            goto label_1a8cc8;
        }
    }
    ctx->pc = 0x1A8CB8u;
    // 0x1a8cb8: 0xc04c464  jal         func_131190
    ctx->pc = 0x1A8CB8u;
    SET_GPR_U32(ctx, 31, 0x1A8CC0u);
    ctx->pc = 0x131190u;
    if (runtime->hasFunction(0x131190u)) {
        auto targetFn = runtime->lookupFunction(0x131190u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8CC0u; }
        if (ctx->pc != 0x1A8CC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131190_0x131190(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A8CC0u; }
        if (ctx->pc != 0x1A8CC0u) { return; }
    }
    ctx->pc = 0x1A8CC0u;
label_1a8cc0:
    // 0x1a8cc0: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a8cc0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a8cc4: 0xa0201050  sb          $zero, 0x1050($at)
    ctx->pc = 0x1a8cc4u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4176), (uint8_t)GPR_U32(ctx, 0));
label_1a8cc8:
    // 0x1a8cc8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a8cc8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a8ccc: 0x3e00008  jr          $ra
    ctx->pc = 0x1A8CCCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A8CD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A8CCCu;
            // 0x1a8cd0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A8CC0u: goto label_1a8cc0;
            case 0x1A8CC8u: goto label_1a8cc8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A8CD4u;
    // 0x1a8cd4: 0x0  nop
    ctx->pc = 0x1a8cd4u;
    // NOP
    // 0x1a8cd8: 0x0  nop
    ctx->pc = 0x1a8cd8u;
    // NOP
    // 0x1a8cdc: 0x0  nop
    ctx->pc = 0x1a8cdcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
