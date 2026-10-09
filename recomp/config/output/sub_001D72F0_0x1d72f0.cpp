#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D72F0
// Address: 0x1d72f0 - 0x1d7330
void sub_001D72F0_0x1d72f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D72F0_0x1d72f0");
#endif

    switch (ctx->pc) {
        case 0x1d7310u: goto label_1d7310;
        default: break;
    }

    ctx->pc = 0x1d72f0u;

    // 0x1d72f0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d72f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d72f4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d72f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d72f8: 0x8c850004  lw          $a1, 0x4($a0)
    ctx->pc = 0x1d72f8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1d72fc: 0x8c840000  lw          $a0, 0x0($a0)
    ctx->pc = 0x1d72fcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1d7300: 0x851024  and         $v0, $a0, $a1
    ctx->pc = 0x1d7300u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 5));
    // 0x1d7304: 0x401027  not         $v0, $v0
    ctx->pc = 0x1d7304u;
    SET_GPR_U64(ctx, 2, ~(GPR_U64(ctx, 2) | GPR_U64(ctx, 0)));
    // 0x1d7308: 0xc075e8c  jal         func_1D7A30
    ctx->pc = 0x1D7308u;
    SET_GPR_U32(ctx, 31, 0x1D7310u);
    ctx->pc = 0x1D730Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7308u;
            // 0x1d730c: 0x823025  or          $a2, $a0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7A30u;
    if (runtime->hasFunction(0x1D7A30u)) {
        auto targetFn = runtime->lookupFunction(0x1D7A30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7310u; }
        if (ctx->pc != 0x1D7310u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7A30_0x1d7a30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7310u; }
        if (ctx->pc != 0x1D7310u) { return; }
    }
    ctx->pc = 0x1D7310u;
label_1d7310:
    // 0x1d7310: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d7310u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d7314: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1d7314u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d7318: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d7318u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d731c: 0x40102a  slt         $v0, $v0, $zero
    ctx->pc = 0x1d731cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 0)) ? 1 : 0);
    // 0x1d7320: 0x21023  negu        $v0, $v0
    ctx->pc = 0x1d7320u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 2)));
    // 0x1d7324: 0x3e00008  jr          $ra
    ctx->pc = 0x1D7324u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D7328u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7324u;
            // 0x1d7328: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D7310u: goto label_1d7310;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D732Cu;
    // 0x1d732c: 0x0  nop
    ctx->pc = 0x1d732cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
