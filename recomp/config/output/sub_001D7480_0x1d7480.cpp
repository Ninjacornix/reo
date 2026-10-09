#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D7480
// Address: 0x1d7480 - 0x1d74b0
void sub_001D7480_0x1d7480(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D7480_0x1d7480");
#endif

    switch (ctx->pc) {
        case 0x1d7490u: goto label_1d7490;
        default: break;
    }

    ctx->pc = 0x1d7480u;

    // 0x1d7480: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d7480u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d7484: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d7484u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d7488: 0xc0762e4  jal         func_1D8B90
    ctx->pc = 0x1D7488u;
    SET_GPR_U32(ctx, 31, 0x1D7490u);
    ctx->pc = 0x1D8B90u;
    if (runtime->hasFunction(0x1D8B90u)) {
        auto targetFn = runtime->lookupFunction(0x1D8B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7490u; }
        if (ctx->pc != 0x1D7490u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D8B90_0x1d8b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7490u; }
        if (ctx->pc != 0x1D7490u) { return; }
    }
    ctx->pc = 0x1D7490u;
label_1d7490:
    // 0x1d7490: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d7490u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d7494: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1d7494u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d7498: 0xa0204602  sb          $zero, 0x4602($at)
    ctx->pc = 0x1d7498u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17922), (uint8_t)GPR_U32(ctx, 0));
    // 0x1d749c: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d749cu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d74a0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d74a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d74a4: 0x3e00008  jr          $ra
    ctx->pc = 0x1D74A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D74A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D74A4u;
            // 0x1d74a8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D7490u: goto label_1d7490;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D74ACu;
    // 0x1d74ac: 0x0  nop
    ctx->pc = 0x1d74acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
