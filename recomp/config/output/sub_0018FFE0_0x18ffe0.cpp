#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018FFE0
// Address: 0x18ffe0 - 0x190014
void sub_0018FFE0_0x18ffe0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018FFE0_0x18ffe0");
#endif

    switch (ctx->pc) {
        case 0x18fff8u: goto label_18fff8;
        case 0x190004u: goto label_190004;
        default: break;
    }

    ctx->pc = 0x18ffe0u;

    // 0x18ffe0: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x18ffe0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x18ffe4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x18ffe4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x18ffe8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x18ffe8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x18ffec: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x18ffecu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18fff0: 0xc063fac  jal         func_18FEB0
    ctx->pc = 0x18FFF0u;
    SET_GPR_U32(ctx, 31, 0x18FFF8u);
    ctx->pc = 0x18FFF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18FFF0u;
            // 0x18fff4: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18FEB0u;
    if (runtime->hasFunction(0x18FEB0u)) {
        auto targetFn = runtime->lookupFunction(0x18FEB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18FFF8u; }
        if (ctx->pc != 0x18FFF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018FEB0_0x18feb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18FFF8u; }
        if (ctx->pc != 0x18FFF8u) { return; }
    }
    ctx->pc = 0x18FFF8u;
label_18fff8:
    // 0x18fff8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x18fff8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18fffc: 0xc0644f8  jal         func_1913E0
    ctx->pc = 0x18FFFCu;
    SET_GPR_U32(ctx, 31, 0x190004u);
    ctx->pc = 0x190000u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18FFFCu;
            // 0x190000: 0x27a50020  addiu       $a1, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1913E0u;
    if (runtime->hasFunction(0x1913E0u)) {
        auto targetFn = runtime->lookupFunction(0x1913E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190004u; }
        if (ctx->pc != 0x190004u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001913E0_0x1913e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190004u; }
        if (ctx->pc != 0x190004u) { return; }
    }
    ctx->pc = 0x190004u;
label_190004:
    // 0x190004: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x190004u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x190008: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x190008u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19000c: 0x3e00008  jr          $ra
    ctx->pc = 0x19000Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x190010u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19000Cu;
            // 0x190010: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18FFF8u: goto label_18fff8;
            case 0x190004u: goto label_190004;
            default: break;
        }
        return;
    }
    ctx->pc = 0x190014u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
