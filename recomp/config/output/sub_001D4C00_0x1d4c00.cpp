#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D4C00
// Address: 0x1d4c00 - 0x1d4c34
void sub_001D4C00_0x1d4c00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D4C00_0x1d4c00");
#endif

    switch (ctx->pc) {
        case 0x1d4c18u: goto label_1d4c18;
        case 0x1d4c28u: goto label_1d4c28;
        default: break;
    }

    ctx->pc = 0x1d4c00u;

    // 0x1d4c00: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d4c00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d4c04: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1d4c04u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1d4c08: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d4c08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d4c0c: 0x24846db0  addiu       $a0, $a0, 0x6DB0
    ctx->pc = 0x1d4c0cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 28080));
    // 0x1d4c10: 0xc074f70  jal         func_1D3DC0
    ctx->pc = 0x1D4C10u;
    SET_GPR_U32(ctx, 31, 0x1D4C18u);
    ctx->pc = 0x1D4C14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4C10u;
            // 0x1d4c14: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D3DC0u;
    if (runtime->hasFunction(0x1D3DC0u)) {
        auto targetFn = runtime->lookupFunction(0x1D3DC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4C18u; }
        if (ctx->pc != 0x1D4C18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D3DC0_0x1d3dc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4C18u; }
        if (ctx->pc != 0x1D4C18u) { return; }
    }
    ctx->pc = 0x1D4C18u;
label_1d4c18:
    // 0x1d4c18: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1d4c18u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1d4c1c: 0x2405000c  addiu       $a1, $zero, 0xC
    ctx->pc = 0x1d4c1cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x1d4c20: 0xc074f70  jal         func_1D3DC0
    ctx->pc = 0x1D4C20u;
    SET_GPR_U32(ctx, 31, 0x1D4C28u);
    ctx->pc = 0x1D4C24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4C20u;
            // 0x1d4c24: 0x24846db8  addiu       $a0, $a0, 0x6DB8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 28088));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D3DC0u;
    if (runtime->hasFunction(0x1D3DC0u)) {
        auto targetFn = runtime->lookupFunction(0x1D3DC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4C28u; }
        if (ctx->pc != 0x1D4C28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D3DC0_0x1d3dc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4C28u; }
        if (ctx->pc != 0x1D4C28u) { return; }
    }
    ctx->pc = 0x1D4C28u;
label_1d4c28:
    // 0x1d4c28: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d4c28u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d4c2c: 0x3e00008  jr          $ra
    ctx->pc = 0x1D4C2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D4C30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4C2Cu;
            // 0x1d4c30: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D4C18u: goto label_1d4c18;
            case 0x1D4C28u: goto label_1d4c28;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D4C34u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
