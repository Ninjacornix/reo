#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B2D80
// Address: 0x1b2d80 - 0x1b2dcc
void sub_001B2D80_0x1b2d80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B2D80_0x1b2d80");
#endif

    switch (ctx->pc) {
        case 0x1b2dacu: goto label_1b2dac;
        case 0x1b2dc0u: goto label_1b2dc0;
        default: break;
    }

    ctx->pc = 0x1b2d80u;

    // 0x1b2d80: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b2d80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b2d84: 0x3c04004c  lui         $a0, 0x4C
    ctx->pc = 0x1b2d84u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)76 << 16));
    // 0x1b2d88: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b2d88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b2d8c: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b2d8cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b2d90: 0xa420a82c  sh          $zero, -0x57D4($at)
    ctx->pc = 0x1b2d90u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 4294944812), (uint16_t)GPR_U32(ctx, 0));
    // 0x1b2d94: 0x2484a830  addiu       $a0, $a0, -0x57D0
    ctx->pc = 0x1b2d94u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294944816));
    // 0x1b2d98: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b2d98u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b2d9c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b2d9cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b2da0: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1b2da0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1b2da4: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1B2DA4u;
    SET_GPR_U32(ctx, 31, 0x1B2DACu);
    ctx->pc = 0x1B2DA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2DA4u;
            // 0x1b2da8: 0xa420a82e  sh          $zero, -0x57D2($at) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 1), 4294944814), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2DACu; }
        if (ctx->pc != 0x1B2DACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2DACu; }
        if (ctx->pc != 0x1B2DACu) { return; }
    }
    ctx->pc = 0x1B2DACu;
label_1b2dac:
    // 0x1b2dac: 0x3c04004c  lui         $a0, 0x4C
    ctx->pc = 0x1b2dacu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)76 << 16));
    // 0x1b2db0: 0x240500ff  addiu       $a1, $zero, 0xFF
    ctx->pc = 0x1b2db0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1b2db4: 0x24849680  addiu       $a0, $a0, -0x6980
    ctx->pc = 0x1b2db4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294940288));
    // 0x1b2db8: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1B2DB8u;
    SET_GPR_U32(ctx, 31, 0x1B2DC0u);
    ctx->pc = 0x1B2DBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2DB8u;
            // 0x1b2dbc: 0x24060400  addiu       $a2, $zero, 0x400 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2DC0u; }
        if (ctx->pc != 0x1B2DC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2DC0u; }
        if (ctx->pc != 0x1B2DC0u) { return; }
    }
    ctx->pc = 0x1B2DC0u;
label_1b2dc0:
    // 0x1b2dc0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b2dc0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b2dc4: 0x3e00008  jr          $ra
    ctx->pc = 0x1B2DC4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B2DC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2DC4u;
            // 0x1b2dc8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B2DACu: goto label_1b2dac;
            case 0x1B2DC0u: goto label_1b2dc0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B2DCCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
