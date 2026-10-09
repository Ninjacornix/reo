#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00134FD0
// Address: 0x134fd0 - 0x135020
void sub_00134FD0_0x134fd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00134FD0_0x134fd0");
#endif

    ctx->pc = 0x134fd0u;

    // 0x134fd0: 0x8c82000c  lw          $v0, 0xC($a0)
    ctx->pc = 0x134fd0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x134fd4: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x134FD4u;
    {
        const bool branch_taken_0x134fd4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x134FD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134FD4u;
            // 0x134fd8: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134fd4) {
            ctx->pc = 0x134FF8u;
            goto label_134ff8;
        }
    }
    ctx->pc = 0x134FDCu;
    // 0x134fdc: 0xac880024  sw          $t0, 0x24($a0)
    ctx->pc = 0x134fdcu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 36), GPR_U32(ctx, 8));
    // 0x134fe0: 0xac850018  sw          $a1, 0x18($a0)
    ctx->pc = 0x134fe0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 5));
    // 0x134fe4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x134fe4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x134fe8: 0xac86001c  sw          $a2, 0x1C($a0)
    ctx->pc = 0x134fe8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 6));
    // 0x134fec: 0xac830014  sw          $v1, 0x14($a0)
    ctx->pc = 0x134fecu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 3));
    // 0x134ff0: 0x3e00008  jr          $ra
    ctx->pc = 0x134FF0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x134FF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134FF0u;
            // 0x134ff4: 0xac870020  sw          $a3, 0x20($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 32), GPR_U32(ctx, 7));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x134FF8u: goto label_134ff8;
            case 0x135014u: goto label_135014;
            default: break;
        }
        return;
    }
    ctx->pc = 0x134FF8u;
label_134ff8:
    // 0x134ff8: 0x3e00008  jr          $ra
    ctx->pc = 0x134FF8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x134FFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134FF8u;
            // 0x134ffc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x134FF8u: goto label_134ff8;
            case 0x135014u: goto label_135014;
            default: break;
        }
        return;
    }
    ctx->pc = 0x135000u;
    // 0x135000: 0x8c82000c  lw          $v0, 0xC($a0)
    ctx->pc = 0x135000u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x135004: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x135004u;
    {
        const bool branch_taken_0x135004 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x135008u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135004u;
            // 0x135008: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135004) {
            ctx->pc = 0x135014u;
            goto label_135014;
        }
    }
    ctx->pc = 0x13500Cu;
    // 0x13500c: 0xac800010  sw          $zero, 0x10($a0)
    ctx->pc = 0x13500cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 0));
    // 0x135010: 0xac82000c  sw          $v0, 0xC($a0)
    ctx->pc = 0x135010u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 2));
label_135014:
    // 0x135014: 0x3e00008  jr          $ra
    ctx->pc = 0x135014u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x134FF8u: goto label_134ff8;
            case 0x135014u: goto label_135014;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13501Cu;
    // 0x13501c: 0x0  nop
    ctx->pc = 0x13501cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
