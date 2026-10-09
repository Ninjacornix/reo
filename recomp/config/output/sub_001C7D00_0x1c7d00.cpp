#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C7D00
// Address: 0x1c7d00 - 0x1c7d30
void sub_001C7D00_0x1c7d00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C7D00_0x1c7d00");
#endif

    switch (ctx->pc) {
        case 0x1c7d14u: goto label_1c7d14;
        default: break;
    }

    ctx->pc = 0x1c7d00u;

    // 0x1c7d00: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c7d00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c7d04: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c7d04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c7d08: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c7d08u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c7d0c: 0xc072250  jal         func_1C8940
    ctx->pc = 0x1C7D0Cu;
    SET_GPR_U32(ctx, 31, 0x1C7D14u);
    ctx->pc = 0x1C7D10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7D0Cu;
            // 0x1c7d10: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8940u;
    if (runtime->hasFunction(0x1C8940u)) {
        auto targetFn = runtime->lookupFunction(0x1C8940u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7D14u; }
        if (ctx->pc != 0x1C7D14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8940_0x1c8940(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C7D14u; }
        if (ctx->pc != 0x1C7D14u) { return; }
    }
    ctx->pc = 0x1C7D14u;
label_1c7d14:
    // 0x1c7d14: 0xae000014  sw          $zero, 0x14($s0)
    ctx->pc = 0x1c7d14u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
    // 0x1c7d18: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c7d18u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c7d1c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c7d1cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c7d20: 0x3e00008  jr          $ra
    ctx->pc = 0x1C7D20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C7D24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7D20u;
            // 0x1c7d24: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C7D14u: goto label_1c7d14;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C7D28u;
    // 0x1c7d28: 0x0  nop
    ctx->pc = 0x1c7d28u;
    // NOP
    // 0x1c7d2c: 0x0  nop
    ctx->pc = 0x1c7d2cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
