#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011DEC0
// Address: 0x11dec0 - 0x11df28
void sub_0011DEC0_0x11dec0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011DEC0_0x11dec0");
#endif

    switch (ctx->pc) {
        case 0x11ded8u: goto label_11ded8;
        default: break;
    }

    ctx->pc = 0x11dec0u;

    // 0x11dec0: 0x40036000  mfc0        $v1, Status
    ctx->pc = 0x11dec0u;
    SET_GPR_S32(ctx, 3, (int32_t)ctx->cop0_status);
    // 0x11dec4: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x11dec4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x11dec8: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x11dec8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x11decc: 0x1060000b  beqz        $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x11DECCu;
    {
        const bool branch_taken_0x11decc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x11DED0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11DECCu;
            // 0x11ded0: 0x3c060001  lui         $a2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)1 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11decc) {
            ctx->pc = 0x11DEFCu;
            goto label_11defc;
        }
    }
    ctx->pc = 0x11DED4u;
    // 0x11ded4: 0x0  nop
    ctx->pc = 0x11ded4u;
    // NOP
label_11ded8:
    // 0x11ded8: 0x42000039  di
    ctx->pc = 0x11ded8u;
    ctx->cop0_status &= ~0x10000; // Disable interrupts
    // 0x11dedc: 0x40f  sync.p
    ctx->pc = 0x11dedcu;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11dee0: 0x40026000  mfc0        $v0, Status
    ctx->pc = 0x11dee0u;
    SET_GPR_S32(ctx, 2, (int32_t)ctx->cop0_status);
    // 0x11dee4: 0x461024  and         $v0, $v0, $a2
    ctx->pc = 0x11dee4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 6));
    // 0x11dee8: 0x0  nop
    ctx->pc = 0x11dee8u;
    // NOP
    // 0x11deec: 0x0  nop
    ctx->pc = 0x11deecu;
    // NOP
    // 0x11def0: 0x0  nop
    ctx->pc = 0x11def0u;
    // NOP
    // 0x11def4: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x11DEF4u;
    {
        const bool branch_taken_0x11def4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11def4) {
            ctx->pc = 0x11DED8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_11ded8;
        }
    }
    ctx->pc = 0x11DEFCu;
label_11defc:
    // 0x11defc: 0x40026000  mfc0        $v0, Status
    ctx->pc = 0x11defcu;
    SET_GPR_S32(ctx, 2, (int32_t)ctx->cop0_status);
    // 0x11df00: 0x40f  sync.p
    ctx->pc = 0x11df00u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11df04: 0x34420006  ori         $v0, $v0, 0x6
    ctx->pc = 0x11df04u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)6);
    // 0x11df08: 0x38420002  xori        $v0, $v0, 0x2
    ctx->pc = 0x11df08u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)2);
    // 0x11df0c: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x11df0cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x11df10: 0x40826000  mtc0        $v0, Status
    ctx->pc = 0x11df10u;
    ctx->cop0_status = GPR_U32(ctx, 2) & 0xFF57FFFF;
    // 0x11df14: 0x40f  sync.p
    ctx->pc = 0x11df14u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11df18: 0xac850000  sw          $a1, 0x0($a0)
    ctx->pc = 0x11df18u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
    // 0x11df1c: 0x409ff000  mtc0        $ra, ErrorEPC
    ctx->pc = 0x11df1cu;
    ctx->cop0_errorepc = GPR_U32(ctx, 31);
    // 0x11df20: 0x40f  sync.p
    ctx->pc = 0x11df20u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11df24: 0x42000018  eret
    ctx->pc = 0x11df24u;
    if (ctx->cop0_status & 0x4) { 
    ctx->pc = ctx->cop0_errorepc; 
    ctx->cop0_status &= ~0x4; 
} else { 
    ctx->pc = ctx->cop0_epc; 
    ctx->cop0_status &= ~0x2; 
} 
runtime->clearLLBit(ctx); 
return;
    ctx->pc = GPR_U32(ctx, 31); return;
}
