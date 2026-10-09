#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00138EC0
// Address: 0x138ec0 - 0x138f30
void sub_00138EC0_0x138ec0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00138EC0_0x138ec0");
#endif

    switch (ctx->pc) {
        case 0x138ee0u: goto label_138ee0;
        case 0x138f14u: goto label_138f14;
        default: break;
    }

    ctx->pc = 0x138ec0u;

    // 0x138ec0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x138ec0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x138ec4: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x138ec4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138ec8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x138ec8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x138ecc: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x138eccu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138ed0: 0x18c0000a  blez        $a2, . + 4 + (0xA << 2)
    ctx->pc = 0x138ED0u;
    {
        const bool branch_taken_0x138ed0 = (GPR_S64(ctx, 6) <= 0);
        ctx->pc = 0x138ED4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138ED0u;
            // 0x138ed4: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x138ed0) {
            ctx->pc = 0x138EFCu;
            goto label_138efc;
        }
    }
    ctx->pc = 0x138ED8u;
    // 0x138ed8: 0x2407ffaa  addiu       $a3, $zero, -0x56
    ctx->pc = 0x138ed8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967210));
    // 0x138edc: 0x0  nop
    ctx->pc = 0x138edcu;
    // NOP
label_138ee0:
    // 0x138ee0: 0x851821  addu        $v1, $a0, $a1
    ctx->pc = 0x138ee0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x138ee4: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x138ee4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x138ee8: 0xa6102a  slt         $v0, $a1, $a2
    ctx->pc = 0x138ee8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x138eec: 0x0  nop
    ctx->pc = 0x138eecu;
    // NOP
    // 0x138ef0: 0x0  nop
    ctx->pc = 0x138ef0u;
    // NOP
    // 0x138ef4: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x138EF4u;
    {
        const bool branch_taken_0x138ef4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x138EF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138EF4u;
            // 0x138ef8: 0xa0670000  sb          $a3, 0x0($v1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x138ef4) {
            ctx->pc = 0x138EE0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_138ee0;
        }
    }
    ctx->pc = 0x138EFCu;
label_138efc:
    // 0x138efc: 0x3c100022  lui         $s0, 0x22
    ctx->pc = 0x138efcu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)34 << 16));
    // 0x138f00: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x138f00u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x138f04: 0x2610c424  addiu       $s0, $s0, -0x3BDC
    ctx->pc = 0x138f04u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294951972));
    // 0x138f08: 0x24a5c950  addiu       $a1, $a1, -0x36B0
    ctx->pc = 0x138f08u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294953296));
    // 0x138f0c: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x138F0Cu;
    SET_GPR_U32(ctx, 31, 0x138F14u);
    ctx->pc = 0x138F10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138F0Cu;
            // 0x138f10: 0x8e060000  lw          $a2, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138F14u; }
        if (ctx->pc != 0x138F14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138F14u; }
        if (ctx->pc != 0x138F14u) { return; }
    }
    ctx->pc = 0x138F14u;
label_138f14:
    // 0x138f14: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x138f14u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x138f18: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x138f18u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x138f1c: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x138f1cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x138f20: 0xae030000  sw          $v1, 0x0($s0)
    ctx->pc = 0x138f20u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
    // 0x138f24: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x138f24u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x138f28: 0x3e00008  jr          $ra
    ctx->pc = 0x138F28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138F2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138F28u;
            // 0x138f2c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138EE0u: goto label_138ee0;
            case 0x138EFCu: goto label_138efc;
            case 0x138F14u: goto label_138f14;
            default: break;
        }
        return;
    }
    ctx->pc = 0x138F30u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
