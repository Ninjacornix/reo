#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013ADC8
// Address: 0x13adc8 - 0x13adec
void sub_0013ADC8_0x13adc8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013ADC8_0x13adc8");
#endif

    switch (ctx->pc) {
        case 0x13add8u: goto label_13add8;
        default: break;
    }

    ctx->pc = 0x13adc8u;

    // 0x13adc8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x13adc8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x13adcc: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x13adccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x13add0: 0xc04ea80  jal         func_13AA00
    ctx->pc = 0x13ADD0u;
    SET_GPR_U32(ctx, 31, 0x13ADD8u);
    ctx->pc = 0x13ADD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13ADD0u;
            // 0x13add4: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13AA00u;
    if (runtime->hasFunction(0x13AA00u)) {
        auto targetFn = runtime->lookupFunction(0x13AA00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13ADD8u; }
        if (ctx->pc != 0x13ADD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013AA00_0x13aa00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13ADD8u; }
        if (ctx->pc != 0x13ADD8u) { return; }
    }
    ctx->pc = 0x13ADD8u;
label_13add8:
    // 0x13add8: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x13add8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13addc: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x13addcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x13ade0: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x13ade0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x13ade4: 0x3e00008  jr          $ra
    ctx->pc = 0x13ADE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13ADE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13ADE4u;
            // 0x13ade8: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13ADD8u: goto label_13add8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13ADECu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
