#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D3D00
// Address: 0x1d3d00 - 0x1d3d38
void sub_001D3D00_0x1d3d00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D3D00_0x1d3d00");
#endif

    switch (ctx->pc) {
        case 0x1d3d20u: goto label_1d3d20;
        case 0x1d3d2cu: goto label_1d3d2c;
        default: break;
    }

    ctx->pc = 0x1d3d00u;

    // 0x1d3d00: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x1d3d00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x1d3d04: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d3d04u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d3d08: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d3d08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d3d0c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d3d0cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d3d10: 0x942643da  lhu         $a2, 0x43DA($at)
    ctx->pc = 0x1d3d10u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d3d14: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x1d3d14u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1d3d18: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D3D18u;
    SET_GPR_U32(ctx, 31, 0x1D3D20u);
    ctx->pc = 0x1D3D1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3D18u;
            // 0x1d3d1c: 0x24a566a8  addiu       $a1, $a1, 0x66A8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 26280));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3D20u; }
        if (ctx->pc != 0x1D3D20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3D20u; }
        if (ctx->pc != 0x1D3D20u) { return; }
    }
    ctx->pc = 0x1D3D20u;
label_1d3d20:
    // 0x1d3d20: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x1d3d20u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1d3d24: 0xc074f70  jal         func_1D3DC0
    ctx->pc = 0x1D3D24u;
    SET_GPR_U32(ctx, 31, 0x1D3D2Cu);
    ctx->pc = 0x1D3D28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3D24u;
            // 0x1d3d28: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D3DC0u;
    if (runtime->hasFunction(0x1D3DC0u)) {
        auto targetFn = runtime->lookupFunction(0x1D3DC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3D2Cu; }
        if (ctx->pc != 0x1D3D2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D3DC0_0x1d3dc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3D2Cu; }
        if (ctx->pc != 0x1D3D2Cu) { return; }
    }
    ctx->pc = 0x1D3D2Cu;
label_1d3d2c:
    // 0x1d3d2c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d3d2cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d3d30: 0x3e00008  jr          $ra
    ctx->pc = 0x1D3D30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D3D34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3D30u;
            // 0x1d3d34: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D3D20u: goto label_1d3d20;
            case 0x1D3D2Cu: goto label_1d3d2c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D3D38u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
