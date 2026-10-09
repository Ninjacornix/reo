#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D6090
// Address: 0x1d6090 - 0x1d6114
void sub_001D6090_0x1d6090(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D6090_0x1d6090");
#endif

    switch (ctx->pc) {
        case 0x1d60b0u: goto label_1d60b0;
        default: break;
    }

    ctx->pc = 0x1d6090u;

    // 0x1d6090: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1d6090u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1d6094: 0x8ca22840  lw          $v0, 0x2840($a1)
    ctx->pc = 0x1d6094u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 10304)));
    // 0x1d6098: 0x1840001a  blez        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x1D6098u;
    {
        const bool branch_taken_0x1d6098 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1D609Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6098u;
            // 0x1d609c: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d6098) {
            ctx->pc = 0x1D6104u;
            goto label_1d6104;
        }
    }
    ctx->pc = 0x1D60A0u;
    // 0x1d60a0: 0x24a22840  addiu       $v0, $a1, 0x2840
    ctx->pc = 0x1d60a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 10304));
    // 0x1d60a4: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x1d60a4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1d60a8: 0x24630010  addiu       $v1, $v1, 0x10
    ctx->pc = 0x1d60a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 16));
    // 0x1d60ac: 0x0  nop
    ctx->pc = 0x1d60acu;
    // NOP
label_1d60b0:
    // 0x1d60b0: 0x8c620008  lw          $v0, 0x8($v1)
    ctx->pc = 0x1d60b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x1d60b4: 0x1840000f  blez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1D60B4u;
    {
        const bool branch_taken_0x1d60b4 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1D60B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D60B4u;
            // 0x1d60b8: 0x8ca22840  lw          $v0, 0x2840($a1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 10304)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d60b4) {
            ctx->pc = 0x1D60F4u;
            goto label_1d60f4;
        }
    }
    ctx->pc = 0x1D60BCu;
    // 0x1d60bc: 0x8c62000c  lw          $v0, 0xC($v1)
    ctx->pc = 0x1d60bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x1d60c0: 0x1840000c  blez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1D60C0u;
    {
        const bool branch_taken_0x1d60c0 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1D60C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D60C0u;
            // 0x1d60c4: 0x8ca22840  lw          $v0, 0x2840($a1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 10304)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d60c0) {
            ctx->pc = 0x1D60F4u;
            goto label_1d60f4;
        }
    }
    ctx->pc = 0x1D60C8u;
    // 0x1d60c8: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1d60c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1d60cc: 0x50400009  beql        $v0, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x1D60CCu;
    {
        const bool branch_taken_0x1d60cc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d60cc) {
            ctx->pc = 0x1D60D0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1D60CCu;
            // 0x1d60d0: 0x8ca22840  lw          $v0, 0x2840($a1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 10304)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1D60F4u;
            goto label_1d60f4;
        }
    }
    ctx->pc = 0x1D60D4u;
    // 0x1d60d4: 0x4400006  bltz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D60D4u;
    {
        const bool branch_taken_0x1d60d4 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1D60D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D60D4u;
            // 0x1d60d8: 0x28420003  slti        $v0, $v0, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)3) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d60d4) {
            ctx->pc = 0x1D60F0u;
            goto label_1d60f0;
        }
    }
    ctx->pc = 0x1D60DCu;
    // 0x1d60dc: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1D60DCu;
    {
        const bool branch_taken_0x1d60dc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D60E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D60DCu;
            // 0x1d60e0: 0x8ca22840  lw          $v0, 0x2840($a1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 10304)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d60dc) {
            ctx->pc = 0x1D60F4u;
            goto label_1d60f4;
        }
    }
    ctx->pc = 0x1D60E4u;
    // 0x1d60e4: 0x8c620004  lw          $v0, 0x4($v1)
    ctx->pc = 0x1d60e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x1d60e8: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1d60e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1d60ec: 0xac620004  sw          $v0, 0x4($v1)
    ctx->pc = 0x1d60ecu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 2));
label_1d60f0:
    // 0x1d60f0: 0x8ca22840  lw          $v0, 0x2840($a1)
    ctx->pc = 0x1d60f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 10304)));
label_1d60f4:
    // 0x1d60f4: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1d60f4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1d60f8: 0x82102a  slt         $v0, $a0, $v0
    ctx->pc = 0x1d60f8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1d60fc: 0x1440ffec  bnez        $v0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x1D60FCu;
    {
        const bool branch_taken_0x1d60fc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D6100u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D60FCu;
            // 0x1d6100: 0x24630038  addiu       $v1, $v1, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 56));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d60fc) {
            ctx->pc = 0x1D60B0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d60b0;
        }
    }
    ctx->pc = 0x1D6104u;
label_1d6104:
    // 0x1d6104: 0xf  sync
    ctx->pc = 0x1d6104u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x1d6108: 0x42000038  ei
    ctx->pc = 0x1d6108u;
    ctx->cop0_status |= 0x10000; // Enable interrupts
    // 0x1d610c: 0x3e00008  jr          $ra
    ctx->pc = 0x1D610Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D6110u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D610Cu;
            // 0x1d6110: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D60B0u: goto label_1d60b0;
            case 0x1D60F0u: goto label_1d60f0;
            case 0x1D60F4u: goto label_1d60f4;
            case 0x1D6104u: goto label_1d6104;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D6114u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
