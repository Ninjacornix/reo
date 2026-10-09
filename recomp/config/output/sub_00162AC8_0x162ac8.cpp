#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00162AC8
// Address: 0x162ac8 - 0x162af4
void sub_00162AC8_0x162ac8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00162AC8_0x162ac8");
#endif

    switch (ctx->pc) {
        case 0x162ae0u: goto label_162ae0;
        default: break;
    }

    ctx->pc = 0x162ac8u;

    // 0x162ac8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x162ac8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x162acc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x162accu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x162ad0: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x162ad0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162ad4: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x162ad4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x162ad8: 0xc04f4f0  jal         func_13D3C0
    ctx->pc = 0x162AD8u;
    SET_GPR_U32(ctx, 31, 0x162AE0u);
    ctx->pc = 0x162ADCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162AD8u;
            // 0x162adc: 0x8c84004c  lw          $a0, 0x4C($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 76)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D3C0u;
    if (runtime->hasFunction(0x13D3C0u)) {
        auto targetFn = runtime->lookupFunction(0x13D3C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162AE0u; }
        if (ctx->pc != 0x162AE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D3C0_0x13d3c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162AE0u; }
        if (ctx->pc != 0x162AE0u) { return; }
    }
    ctx->pc = 0x162AE0u;
label_162ae0:
    // 0x162ae0: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x162ae0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x162ae4: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x162ae4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x162ae8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x162ae8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162aec: 0x3e00008  jr          $ra
    ctx->pc = 0x162AECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x162AF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162AECu;
            // 0x162af0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x162AE0u: goto label_162ae0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x162AF4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
