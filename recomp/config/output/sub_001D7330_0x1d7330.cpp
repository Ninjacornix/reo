#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D7330
// Address: 0x1d7330 - 0x1d7360
void sub_001D7330_0x1d7330(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D7330_0x1d7330");
#endif

    switch (ctx->pc) {
        case 0x1d7340u: goto label_1d7340;
        default: break;
    }

    ctx->pc = 0x1d7330u;

    // 0x1d7330: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d7330u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d7334: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d7334u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d7338: 0xc0762f8  jal         func_1D8BE0
    ctx->pc = 0x1D7338u;
    SET_GPR_U32(ctx, 31, 0x1D7340u);
    ctx->pc = 0x1D8BE0u;
    if (runtime->hasFunction(0x1D8BE0u)) {
        auto targetFn = runtime->lookupFunction(0x1D8BE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7340u; }
        if (ctx->pc != 0x1D7340u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D8BE0_0x1d8be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7340u; }
        if (ctx->pc != 0x1D7340u) { return; }
    }
    ctx->pc = 0x1D7340u;
label_1d7340:
    // 0x1d7340: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1d7340u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d7344: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d7344u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d7348: 0xac2345e8  sw          $v1, 0x45E8($at)
    ctx->pc = 0x1d7348u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17896), GPR_U32(ctx, 3));
    // 0x1d734c: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1d734cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d7350: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d7350u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d7354: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d7354u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d7358: 0x3e00008  jr          $ra
    ctx->pc = 0x1D7358u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D735Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7358u;
            // 0x1d735c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D7340u: goto label_1d7340;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D7360u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
