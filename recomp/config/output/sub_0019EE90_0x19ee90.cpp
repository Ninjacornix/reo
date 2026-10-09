#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019EE90
// Address: 0x19ee90 - 0x19eed0
void sub_0019EE90_0x19ee90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019EE90_0x19ee90");
#endif

    switch (ctx->pc) {
        case 0x19ee9cu: goto label_19ee9c;
        case 0x19eea4u: goto label_19eea4;
        default: break;
    }

    ctx->pc = 0x19ee90u;

    // 0x19ee90: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x19ee90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x19ee94: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x19EE94u;
    {
        const bool branch_taken_0x19ee94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19EE98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19EE94u;
            // 0x19ee98: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19ee94) {
            ctx->pc = 0x19EEA4u;
            goto label_19eea4;
        }
    }
    ctx->pc = 0x19EE9Cu;
label_19ee9c:
    // 0x19ee9c: 0xc067adc  jal         func_19EB70
    ctx->pc = 0x19EE9Cu;
    SET_GPR_U32(ctx, 31, 0x19EEA4u);
    ctx->pc = 0x19EB70u;
    if (runtime->hasFunction(0x19EB70u)) {
        auto targetFn = runtime->lookupFunction(0x19EB70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19EEA4u; }
        if (ctx->pc != 0x19EEA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019EB70_0x19eb70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19EEA4u; }
        if (ctx->pc != 0x19EEA4u) { return; }
    }
    ctx->pc = 0x19EEA4u;
label_19eea4:
    // 0x19eea4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19eea4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19eea8: 0x8c24bed0  lw          $a0, -0x4130($at)
    ctx->pc = 0x19eea8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294950608)));
    // 0x19eeac: 0x0  nop
    ctx->pc = 0x19eeacu;
    // NOP
    // 0x19eeb0: 0x0  nop
    ctx->pc = 0x19eeb0u;
    // NOP
    // 0x19eeb4: 0x1480fff9  bnez        $a0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x19EEB4u;
    {
        const bool branch_taken_0x19eeb4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        if (branch_taken_0x19eeb4) {
            ctx->pc = 0x19EE9Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19ee9c;
        }
    }
    ctx->pc = 0x19EEBCu;
    // 0x19eebc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x19eebcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19eec0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x19eec0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19eec4: 0x3e00008  jr          $ra
    ctx->pc = 0x19EEC4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19EEC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19EEC4u;
            // 0x19eec8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19EE9Cu: goto label_19ee9c;
            case 0x19EEA4u: goto label_19eea4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19EECCu;
    // 0x19eecc: 0x0  nop
    ctx->pc = 0x19eeccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
