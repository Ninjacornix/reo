#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D77E0
// Address: 0x1d77e0 - 0x1d7810
void sub_001D77E0_0x1d77e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D77E0_0x1d77e0");
#endif

    switch (ctx->pc) {
        case 0x1d77f4u: goto label_1d77f4;
        default: break;
    }

    ctx->pc = 0x1d77e0u;

    // 0x1d77e0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d77e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d77e4: 0x3c040035  lui         $a0, 0x35
    ctx->pc = 0x1d77e4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)53 << 16));
    // 0x1d77e8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d77e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d77ec: 0xc045ef8  jal         func_117BE0
    ctx->pc = 0x1D77ECu;
    SET_GPR_U32(ctx, 31, 0x1D77F4u);
    ctx->pc = 0x1D77F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D77ECu;
            // 0x1d77f0: 0x24848290  addiu       $a0, $a0, -0x7D70 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294935184));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117BE0u;
    if (runtime->hasFunction(0x117BE0u)) {
        auto targetFn = runtime->lookupFunction(0x117BE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D77F4u; }
        if (ctx->pc != 0x1D77F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117BE0_0x117be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D77F4u; }
        if (ctx->pc != 0x1D77F4u) { return; }
    }
    ctx->pc = 0x1D77F4u;
label_1d77f4:
    // 0x1d77f4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d77f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d77f8: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x1d77f8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1d77fc: 0x38420001  xori        $v0, $v0, 0x1
    ctx->pc = 0x1d77fcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
    // 0x1d7800: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1d7800u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d7804: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d7804u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d7808: 0x3e00008  jr          $ra
    ctx->pc = 0x1D7808u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D780Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7808u;
            // 0x1d780c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D77F4u: goto label_1d77f4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D7810u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
