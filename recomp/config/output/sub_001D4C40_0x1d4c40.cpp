#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D4C40
// Address: 0x1d4c40 - 0x1d4c94
void sub_001D4C40_0x1d4c40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D4C40_0x1d4c40");
#endif

    switch (ctx->pc) {
        case 0x1d4c50u: goto label_1d4c50;
        case 0x1d4c64u: goto label_1d4c64;
        case 0x1d4c70u: goto label_1d4c70;
        case 0x1d4c88u: goto label_1d4c88;
        default: break;
    }

    ctx->pc = 0x1d4c40u;

    // 0x1d4c40: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x1d4c40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x1d4c44: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d4c44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d4c48: 0xc0dee54  jal         func_37B950
    ctx->pc = 0x1D4C48u;
    SET_GPR_U32(ctx, 31, 0x1D4C50u);
    ctx->pc = 0x37B950u;
    {
        auto targetFn = runtime->lookupFunction(0x37B950u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4C50u; }
        if (ctx->pc != 0x1D4C50u) { return; }
    }
    ctx->pc = 0x1D4C50u;
label_1d4c50:
    // 0x1d4c50: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d4c50u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d4c54: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1d4c54u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4c58: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x1d4c58u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1d4c5c: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D4C5Cu;
    SET_GPR_U32(ctx, 31, 0x1D4C64u);
    ctx->pc = 0x1D4C60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4C5Cu;
            // 0x1d4c60: 0x24a56dc0  addiu       $a1, $a1, 0x6DC0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 28096));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4C64u; }
        if (ctx->pc != 0x1D4C64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4C64u; }
        if (ctx->pc != 0x1D4C64u) { return; }
    }
    ctx->pc = 0x1D4C64u;
label_1d4c64:
    // 0x1d4c64: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x1d4c64u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1d4c68: 0xc074f70  jal         func_1D3DC0
    ctx->pc = 0x1D4C68u;
    SET_GPR_U32(ctx, 31, 0x1D4C70u);
    ctx->pc = 0x1D4C6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4C68u;
            // 0x1d4c6c: 0x2405000c  addiu       $a1, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D3DC0u;
    if (runtime->hasFunction(0x1D3DC0u)) {
        auto targetFn = runtime->lookupFunction(0x1D3DC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4C70u; }
        if (ctx->pc != 0x1D4C70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D3DC0_0x1d3dc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4C70u; }
        if (ctx->pc != 0x1D4C70u) { return; }
    }
    ctx->pc = 0x1D4C70u;
label_1d4c70:
    // 0x1d4c70: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1d4c70u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d4c74: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1d4c74u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1d4c78: 0x24062500  addiu       $a2, $zero, 0x2500
    ctx->pc = 0x1d4c78u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 9472));
    // 0x1d4c7c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1d4c7cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4c80: 0xc06b3e0  jal         func_1ACF80
    ctx->pc = 0x1D4C80u;
    SET_GPR_U32(ctx, 31, 0x1D4C88u);
    ctx->pc = 0x1D4C84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4C80u;
            // 0x1d4c84: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ACF80u;
    if (runtime->hasFunction(0x1ACF80u)) {
        auto targetFn = runtime->lookupFunction(0x1ACF80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4C88u; }
        if (ctx->pc != 0x1D4C88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ACF80_0x1acf80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4C88u; }
        if (ctx->pc != 0x1D4C88u) { return; }
    }
    ctx->pc = 0x1D4C88u;
label_1d4c88:
    // 0x1d4c88: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d4c88u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d4c8c: 0x3e00008  jr          $ra
    ctx->pc = 0x1D4C8Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D4C90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4C8Cu;
            // 0x1d4c90: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D4C50u: goto label_1d4c50;
            case 0x1D4C64u: goto label_1d4c64;
            case 0x1D4C70u: goto label_1d4c70;
            case 0x1D4C88u: goto label_1d4c88;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D4C94u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
