#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00174878
// Address: 0x174878 - 0x1748bc
void sub_00174878_0x174878(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00174878_0x174878");
#endif

    switch (ctx->pc) {
        case 0x17489cu: goto label_17489c;
        default: break;
    }

    ctx->pc = 0x174878u;

    // 0x174878: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x174878u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17487c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17487cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x174880: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x174880u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174884: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x174884u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x174888: 0x8e022ab0  lw          $v0, 0x2AB0($s0)
    ctx->pc = 0x174888u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 10928)));
    // 0x17488c: 0x50400008  beql        $v0, $zero, . + 4 + (0x8 << 2)
    ctx->pc = 0x17488Cu;
    {
        const bool branch_taken_0x17488c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x17488c) {
            ctx->pc = 0x174890u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17488Cu;
            // 0x174890: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1748B0u;
            goto label_1748b0;
        }
    }
    ctx->pc = 0x174894u;
    // 0x174894: 0xc05d230  jal         func_1748C0
    ctx->pc = 0x174894u;
    SET_GPR_U32(ctx, 31, 0x17489Cu);
    ctx->pc = 0x1748C0u;
    if (runtime->hasFunction(0x1748C0u)) {
        auto targetFn = runtime->lookupFunction(0x1748C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17489Cu; }
        if (ctx->pc != 0x17489Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001748C0_0x1748c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17489Cu; }
        if (ctx->pc != 0x17489Cu) { return; }
    }
    ctx->pc = 0x17489Cu;
label_17489c:
    // 0x17489c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17489cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1748a0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1748a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1748a4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1748a4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1748a8: 0x805d448  j           func_175120
    ctx->pc = 0x1748A8u;
    ctx->pc = 0x1748ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1748A8u;
            // 0x1748ac: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175120u;
    if (runtime->hasFunction(0x175120u)) {
        auto targetFn = runtime->lookupFunction(0x175120u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00175120_0x175120(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1748B0u;
label_1748b0:
    // 0x1748b0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1748b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1748b4: 0x3e00008  jr          $ra
    ctx->pc = 0x1748B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1748B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1748B4u;
            // 0x1748b8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17489Cu: goto label_17489c;
            case 0x1748B0u: goto label_1748b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1748BCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
