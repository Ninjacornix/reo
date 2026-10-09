#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D7260
// Address: 0x1d7260 - 0x1d7290
void sub_001D7260_0x1d7260(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D7260_0x1d7260");
#endif

    switch (ctx->pc) {
        case 0x1d7270u: goto label_1d7270;
        default: break;
    }

    ctx->pc = 0x1d7260u;

    // 0x1d7260: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d7260u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d7264: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d7264u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d7268: 0xc076250  jal         func_1D8940
    ctx->pc = 0x1D7268u;
    SET_GPR_U32(ctx, 31, 0x1D7270u);
    ctx->pc = 0x1D8940u;
    if (runtime->hasFunction(0x1D8940u)) {
        auto targetFn = runtime->lookupFunction(0x1D8940u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7270u; }
        if (ctx->pc != 0x1D7270u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D8940_0x1d8940(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7270u; }
        if (ctx->pc != 0x1D7270u) { return; }
    }
    ctx->pc = 0x1D7270u;
label_1d7270:
    // 0x1d7270: 0x24030005  addiu       $v1, $zero, 0x5
    ctx->pc = 0x1d7270u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1d7274: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d7274u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d7278: 0xac2345e8  sw          $v1, 0x45E8($at)
    ctx->pc = 0x1d7278u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17896), GPR_U32(ctx, 3));
    // 0x1d727c: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1d727cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d7280: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d7280u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d7284: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d7284u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d7288: 0x3e00008  jr          $ra
    ctx->pc = 0x1D7288u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D728Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7288u;
            // 0x1d728c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D7270u: goto label_1d7270;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D7290u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
