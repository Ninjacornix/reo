#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D68B0
// Address: 0x1d68b0 - 0x1d68f0
void sub_001D68B0_0x1d68b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D68B0_0x1d68b0");
#endif

    switch (ctx->pc) {
        case 0x1d68c0u: goto label_1d68c0;
        default: break;
    }

    ctx->pc = 0x1d68b0u;

    // 0x1d68b0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d68b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d68b4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d68b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d68b8: 0xc075e64  jal         func_1D7990
    ctx->pc = 0x1D68B8u;
    SET_GPR_U32(ctx, 31, 0x1D68C0u);
    ctx->pc = 0x1D7990u;
    if (runtime->hasFunction(0x1D7990u)) {
        auto targetFn = runtime->lookupFunction(0x1D7990u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D68C0u; }
        if (ctx->pc != 0x1D68C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7990_0x1d7990(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D68C0u; }
        if (ctx->pc != 0x1D68C0u) { return; }
    }
    ctx->pc = 0x1D68C0u;
label_1d68c0:
    // 0x1d68c0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1d68c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d68c4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d68c4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d68c8: 0xa0234600  sb          $v1, 0x4600($at)
    ctx->pc = 0x1d68c8u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17920), (uint8_t)GPR_U32(ctx, 3));
    // 0x1d68cc: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1d68ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d68d0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d68d0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d68d4: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d68d4u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d68d8: 0xac2345e8  sw          $v1, 0x45E8($at)
    ctx->pc = 0x1d68d8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17896), GPR_U32(ctx, 3));
    // 0x1d68dc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d68dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d68e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1D68E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D68E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D68E0u;
            // 0x1d68e4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D68C0u: goto label_1d68c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D68E8u;
    // 0x1d68e8: 0x0  nop
    ctx->pc = 0x1d68e8u;
    // NOP
    // 0x1d68ec: 0x0  nop
    ctx->pc = 0x1d68ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
