#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00176DE8
// Address: 0x176de8 - 0x176e28
void sub_00176DE8_0x176de8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00176DE8_0x176de8");
#endif

    ctx->pc = 0x176de8u;

    // 0x176de8: 0x8c820920  lw          $v0, 0x920($a0)
    ctx->pc = 0x176de8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 2336)));
    // 0x176dec: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x176DECu;
    {
        const bool branch_taken_0x176dec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x176DF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176DECu;
            // 0x176df0: 0x21880  sll         $v1, $v0, 2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x176dec) {
            ctx->pc = 0x176E08u;
            goto label_176e08;
        }
    }
    ctx->pc = 0x176DF4u;
    // 0x176df4: 0x24027512  addiu       $v0, $zero, 0x7512
    ctx->pc = 0x176df4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 29970));
    // 0x176df8: 0xaca00000  sw          $zero, 0x0($a1)
    ctx->pc = 0x176df8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 0));
    // 0x176dfc: 0x3e00008  jr          $ra
    ctx->pc = 0x176DFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x176E00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176DFCu;
            // 0x176e00: 0xacc20000  sw          $v0, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x176E08u: goto label_176e08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x176E04u;
    // 0x176e04: 0x0  nop
    ctx->pc = 0x176e04u;
    // NOP
label_176e08:
    // 0x176e08: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x176e08u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x176e0c: 0x230821  addu        $at, $at, $v1
    ctx->pc = 0x176e0cu;
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0x176e10: 0x8c230af0  lw          $v1, 0xAF0($at)
    ctx->pc = 0x176e10u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2800)));
    // 0x176e14: 0x240203e8  addiu       $v0, $zero, 0x3E8
    ctx->pc = 0x176e14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1000));
    // 0x176e18: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x176e18u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x176e1c: 0x3e00008  jr          $ra
    ctx->pc = 0x176E1Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x176E20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176E1Cu;
            // 0x176e20: 0xacc30000  sw          $v1, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x176E08u: goto label_176e08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x176E24u;
    // 0x176e24: 0x0  nop
    ctx->pc = 0x176e24u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
