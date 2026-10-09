#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00134FA0
// Address: 0x134fa0 - 0x134fd0
void sub_00134FA0_0x134fa0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00134FA0_0x134fa0");
#endif

    ctx->pc = 0x134fa0u;

    // 0x134fa0: 0x8c82000c  lw          $v0, 0xC($a0)
    ctx->pc = 0x134fa0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x134fa4: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x134FA4u;
    {
        const bool branch_taken_0x134fa4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x134FA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134FA4u;
            // 0x134fa8: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x134fa4) {
            ctx->pc = 0x134FC8u;
            goto label_134fc8;
        }
    }
    ctx->pc = 0x134FACu;
    // 0x134fac: 0xac850018  sw          $a1, 0x18($a0)
    ctx->pc = 0x134facu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 5));
    // 0x134fb0: 0xac86001c  sw          $a2, 0x1C($a0)
    ctx->pc = 0x134fb0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 6));
    // 0x134fb4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x134fb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x134fb8: 0xac870020  sw          $a3, 0x20($a0)
    ctx->pc = 0x134fb8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 32), GPR_U32(ctx, 7));
    // 0x134fbc: 0xac830014  sw          $v1, 0x14($a0)
    ctx->pc = 0x134fbcu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 3));
    // 0x134fc0: 0x3e00008  jr          $ra
    ctx->pc = 0x134FC0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x134FC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134FC0u;
            // 0x134fc4: 0xac800024  sw          $zero, 0x24($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 36), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x134FC8u: goto label_134fc8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x134FC8u;
label_134fc8:
    // 0x134fc8: 0x3e00008  jr          $ra
    ctx->pc = 0x134FC8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x134FCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x134FC8u;
            // 0x134fcc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x134FC8u: goto label_134fc8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x134FD0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
