#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A2AF0
// Address: 0x1a2af0 - 0x1a2b30
void sub_001A2AF0_0x1a2af0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A2AF0_0x1a2af0");
#endif

    switch (ctx->pc) {
        case 0x1a2b00u: goto label_1a2b00;
        default: break;
    }

    ctx->pc = 0x1a2af0u;

    // 0x1a2af0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a2af0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a2af4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a2af4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a2af8: 0xc068b20  jal         func_1A2C80
    ctx->pc = 0x1A2AF8u;
    SET_GPR_U32(ctx, 31, 0x1A2B00u);
    ctx->pc = 0x1A2C80u;
    if (runtime->hasFunction(0x1A2C80u)) {
        auto targetFn = runtime->lookupFunction(0x1A2C80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2B00u; }
        if (ctx->pc != 0x1A2B00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A2C80_0x1a2c80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2B00u; }
        if (ctx->pc != 0x1A2B00u) { return; }
    }
    ctx->pc = 0x1A2B00u;
label_1a2b00:
    // 0x1a2b00: 0x8c440004  lw          $a0, 0x4($v0)
    ctx->pc = 0x1a2b00u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1a2b04: 0x3c038000  lui         $v1, 0x8000
    ctx->pc = 0x1a2b04u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32768 << 16));
    // 0x1a2b08: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1a2b08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1a2b0c: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x1a2b0cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x1a2b10: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1A2B10u;
    {
        const bool branch_taken_0x1a2b10 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a2b10) {
            ctx->pc = 0x1A2B1Cu;
            goto label_1a2b1c;
        }
    }
    ctx->pc = 0x1A2B18u;
    // 0x1a2b18: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x1a2b18u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
label_1a2b1c:
    // 0x1a2b1c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a2b1cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a2b20: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1a2b20u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a2b24: 0x3e00008  jr          $ra
    ctx->pc = 0x1A2B24u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A2B28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2B24u;
            // 0x1a2b28: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A2B00u: goto label_1a2b00;
            case 0x1A2B1Cu: goto label_1a2b1c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A2B2Cu;
    // 0x1a2b2c: 0x0  nop
    ctx->pc = 0x1a2b2cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
