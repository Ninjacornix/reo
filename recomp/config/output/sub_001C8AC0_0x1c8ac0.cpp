#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C8AC0
// Address: 0x1c8ac0 - 0x1c8b20
void sub_001C8AC0_0x1c8ac0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C8AC0_0x1c8ac0");
#endif

    switch (ctx->pc) {
        case 0x1c8ad4u: goto label_1c8ad4;
        case 0x1c8b08u: goto label_1c8b08;
        default: break;
    }

    ctx->pc = 0x1c8ac0u;

    // 0x1c8ac0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c8ac0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c8ac4: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1c8ac4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1c8ac8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1c8ac8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1c8acc: 0xc072274  jal         func_1C89D0
    ctx->pc = 0x1C8ACCu;
    SET_GPR_U32(ctx, 31, 0x1C8AD4u);
    ctx->pc = 0x1C8AD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8ACCu;
            // 0x1c8ad0: 0x27a5001c  addiu       $a1, $sp, 0x1C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 28));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C89D0u;
    if (runtime->hasFunction(0x1C89D0u)) {
        auto targetFn = runtime->lookupFunction(0x1C89D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8AD4u; }
        if (ctx->pc != 0x1C8AD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C89D0_0x1c89d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8AD4u; }
        if (ctx->pc != 0x1C8AD4u) { return; }
    }
    ctx->pc = 0x1C8AD4u;
label_1c8ad4:
    // 0x1c8ad4: 0x8fa2001c  lw          $v0, 0x1C($sp)
    ctx->pc = 0x1c8ad4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x1c8ad8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1c8ad8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c8adc: 0x3e00008  jr          $ra
    ctx->pc = 0x1C8ADCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C8AE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8ADCu;
            // 0x1c8ae0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C8AD4u: goto label_1c8ad4;
            case 0x1C8B08u: goto label_1c8b08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C8AE4u;
    // 0x1c8ae4: 0x0  nop
    ctx->pc = 0x1c8ae4u;
    // NOP
    // 0x1c8ae8: 0x0  nop
    ctx->pc = 0x1c8ae8u;
    // NOP
    // 0x1c8aec: 0x0  nop
    ctx->pc = 0x1c8aecu;
    // NOP
    // 0x1c8af0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c8af0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c8af4: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1c8af4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c8af8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1c8af8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1c8afc: 0xa7a5001e  sh          $a1, 0x1E($sp)
    ctx->pc = 0x1c8afcu;
    WRITE16(ADD32(GPR_U32(ctx, 29), 30), (uint16_t)GPR_U32(ctx, 5));
    // 0x1c8b00: 0xc072258  jal         func_1C8960
    ctx->pc = 0x1C8B00u;
    SET_GPR_U32(ctx, 31, 0x1C8B08u);
    ctx->pc = 0x1C8B04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8B00u;
            // 0x1c8b04: 0x27a5001e  addiu       $a1, $sp, 0x1E (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 30));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8960u;
    if (runtime->hasFunction(0x1C8960u)) {
        auto targetFn = runtime->lookupFunction(0x1C8960u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8B08u; }
        if (ctx->pc != 0x1C8B08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8960_0x1c8960(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8B08u; }
        if (ctx->pc != 0x1C8B08u) { return; }
    }
    ctx->pc = 0x1C8B08u;
label_1c8b08:
    // 0x1c8b08: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1c8b08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c8b0c: 0x3e00008  jr          $ra
    ctx->pc = 0x1C8B0Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C8B10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8B0Cu;
            // 0x1c8b10: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C8AD4u: goto label_1c8ad4;
            case 0x1C8B08u: goto label_1c8b08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C8B14u;
    // 0x1c8b14: 0x0  nop
    ctx->pc = 0x1c8b14u;
    // NOP
    // 0x1c8b18: 0x0  nop
    ctx->pc = 0x1c8b18u;
    // NOP
    // 0x1c8b1c: 0x0  nop
    ctx->pc = 0x1c8b1cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
