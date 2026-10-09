#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00187AD0
// Address: 0x187ad0 - 0x187b18
void sub_00187AD0_0x187ad0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00187AD0_0x187ad0");
#endif

    switch (ctx->pc) {
        case 0x187ae0u: goto label_187ae0;
        default: break;
    }

    ctx->pc = 0x187ad0u;

    // 0x187ad0: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x187ad0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x187ad4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x187ad4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187ad8: 0x2446b8c8  addiu       $a2, $v0, -0x4738
    ctx->pc = 0x187ad8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949064));
    // 0x187adc: 0x0  nop
    ctx->pc = 0x187adcu;
    // NOP
label_187ae0:
    // 0x187ae0: 0x8cc20000  lw          $v0, 0x0($a2)
    ctx->pc = 0x187ae0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x187ae4: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x187AE4u;
    {
        const bool branch_taken_0x187ae4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x187ae4) {
            ctx->pc = 0x187AE8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x187AE4u;
            // 0x187ae8: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x187AFCu;
            goto label_187afc;
        }
    }
    ctx->pc = 0x187AECu;
    // 0x187aec: 0x8cc30004  lw          $v1, 0x4($a2)
    ctx->pc = 0x187aecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x187af0: 0x10640007  beq         $v1, $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x187AF0u;
    {
        const bool branch_taken_0x187af0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x187AF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x187AF0u;
            // 0x187af4: 0xa0102d  daddu       $v0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x187af0) {
            ctx->pc = 0x187B10u;
            goto label_187b10;
        }
    }
    ctx->pc = 0x187AF8u;
    // 0x187af8: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x187af8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
label_187afc:
    // 0x187afc: 0x28a20002  slti        $v0, $a1, 0x2
    ctx->pc = 0x187afcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x187b00: 0x0  nop
    ctx->pc = 0x187b00u;
    // NOP
    // 0x187b04: 0x1440fff6  bnez        $v0, . + 4 + (-0xA << 2)
    ctx->pc = 0x187B04u;
    {
        const bool branch_taken_0x187b04 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x187B08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x187B04u;
            // 0x187b08: 0x24c6001c  addiu       $a2, $a2, 0x1C (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 28));
        ctx->in_delay_slot = false;
        if (branch_taken_0x187b04) {
            ctx->pc = 0x187AE0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_187ae0;
        }
    }
    ctx->pc = 0x187B0Cu;
    // 0x187b0c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x187b0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_187b10:
    // 0x187b10: 0x3e00008  jr          $ra
    ctx->pc = 0x187B10u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x187AE0u: goto label_187ae0;
            case 0x187AFCu: goto label_187afc;
            case 0x187B10u: goto label_187b10;
            default: break;
        }
        return;
    }
    ctx->pc = 0x187B18u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
