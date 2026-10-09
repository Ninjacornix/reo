#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001562D0
// Address: 0x1562d0 - 0x156398
void sub_001562D0_0x1562d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001562D0_0x1562d0");
#endif

    switch (ctx->pc) {
        case 0x1562e0u: goto label_1562e0;
        case 0x156308u: goto label_156308;
        default: break;
    }

    ctx->pc = 0x1562d0u;

    // 0x1562d0: 0x61080  sll         $v0, $a2, 2
    ctx->pc = 0x1562d0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x1562d4: 0x30c3000f  andi        $v1, $a2, 0xF
    ctx->pc = 0x1562d4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)15);
    // 0x1562d8: 0x10600008  beqz        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1562D8u;
    {
        const bool branch_taken_0x1562d8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1562DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1562D8u;
            // 0x1562dc: 0x822021  addu        $a0, $a0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1562d8) {
            ctx->pc = 0x1562FCu;
            goto label_1562fc;
        }
    }
    ctx->pc = 0x1562E0u;
label_1562e0:
    // 0x1562e0: 0x2484fffc  addiu       $a0, $a0, -0x4
    ctx->pc = 0x1562e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967292));
    // 0x1562e4: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1562e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1562e8: 0x0  nop
    ctx->pc = 0x1562e8u;
    // NOP
    // 0x1562ec: 0x0  nop
    ctx->pc = 0x1562ecu;
    // NOP
    // 0x1562f0: 0x0  nop
    ctx->pc = 0x1562f0u;
    // NOP
    // 0x1562f4: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1562F4u;
    {
        const bool branch_taken_0x1562f4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1562F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1562F4u;
            // 0x1562f8: 0xac850000  sw          $a1, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1562f4) {
            ctx->pc = 0x1562E0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1562e0;
        }
    }
    ctx->pc = 0x1562FCu;
label_1562fc:
    // 0x1562fc: 0x63102  srl         $a2, $a2, 4
    ctx->pc = 0x1562fcu;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 6), 4));
    // 0x156300: 0x10c00023  beqz        $a2, . + 4 + (0x23 << 2)
    ctx->pc = 0x156300u;
    {
        const bool branch_taken_0x156300 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x156300) {
            ctx->pc = 0x156390u;
            goto label_156390;
        }
    }
    ctx->pc = 0x156308u;
label_156308:
    // 0x156308: 0x2484fffc  addiu       $a0, $a0, -0x4
    ctx->pc = 0x156308u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967292));
    // 0x15630c: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x15630cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x156310: 0xac850000  sw          $a1, 0x0($a0)
    ctx->pc = 0x156310u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
    // 0x156314: 0x2484fffc  addiu       $a0, $a0, -0x4
    ctx->pc = 0x156314u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967292));
    // 0x156318: 0xac850000  sw          $a1, 0x0($a0)
    ctx->pc = 0x156318u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
    // 0x15631c: 0x2484fffc  addiu       $a0, $a0, -0x4
    ctx->pc = 0x15631cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967292));
    // 0x156320: 0xac850000  sw          $a1, 0x0($a0)
    ctx->pc = 0x156320u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
    // 0x156324: 0x2484fffc  addiu       $a0, $a0, -0x4
    ctx->pc = 0x156324u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967292));
    // 0x156328: 0xac850000  sw          $a1, 0x0($a0)
    ctx->pc = 0x156328u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
    // 0x15632c: 0x2484fffc  addiu       $a0, $a0, -0x4
    ctx->pc = 0x15632cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967292));
    // 0x156330: 0xac850000  sw          $a1, 0x0($a0)
    ctx->pc = 0x156330u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
    // 0x156334: 0x2484fffc  addiu       $a0, $a0, -0x4
    ctx->pc = 0x156334u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967292));
    // 0x156338: 0xac850000  sw          $a1, 0x0($a0)
    ctx->pc = 0x156338u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
    // 0x15633c: 0x2484fffc  addiu       $a0, $a0, -0x4
    ctx->pc = 0x15633cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967292));
    // 0x156340: 0xac850000  sw          $a1, 0x0($a0)
    ctx->pc = 0x156340u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
    // 0x156344: 0x2484fffc  addiu       $a0, $a0, -0x4
    ctx->pc = 0x156344u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967292));
    // 0x156348: 0xac850000  sw          $a1, 0x0($a0)
    ctx->pc = 0x156348u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
    // 0x15634c: 0x2484fffc  addiu       $a0, $a0, -0x4
    ctx->pc = 0x15634cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967292));
    // 0x156350: 0xac850000  sw          $a1, 0x0($a0)
    ctx->pc = 0x156350u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
    // 0x156354: 0x2484fffc  addiu       $a0, $a0, -0x4
    ctx->pc = 0x156354u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967292));
    // 0x156358: 0xac850000  sw          $a1, 0x0($a0)
    ctx->pc = 0x156358u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
    // 0x15635c: 0x2484fffc  addiu       $a0, $a0, -0x4
    ctx->pc = 0x15635cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967292));
    // 0x156360: 0xac850000  sw          $a1, 0x0($a0)
    ctx->pc = 0x156360u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
    // 0x156364: 0x2484fffc  addiu       $a0, $a0, -0x4
    ctx->pc = 0x156364u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967292));
    // 0x156368: 0xac850000  sw          $a1, 0x0($a0)
    ctx->pc = 0x156368u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
    // 0x15636c: 0x2484fffc  addiu       $a0, $a0, -0x4
    ctx->pc = 0x15636cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967292));
    // 0x156370: 0xac850000  sw          $a1, 0x0($a0)
    ctx->pc = 0x156370u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
    // 0x156374: 0x2484fffc  addiu       $a0, $a0, -0x4
    ctx->pc = 0x156374u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967292));
    // 0x156378: 0xac850000  sw          $a1, 0x0($a0)
    ctx->pc = 0x156378u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
    // 0x15637c: 0x2484fffc  addiu       $a0, $a0, -0x4
    ctx->pc = 0x15637cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967292));
    // 0x156380: 0xac850000  sw          $a1, 0x0($a0)
    ctx->pc = 0x156380u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
    // 0x156384: 0x2484fffc  addiu       $a0, $a0, -0x4
    ctx->pc = 0x156384u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967292));
    // 0x156388: 0x14c0ffdf  bnez        $a2, . + 4 + (-0x21 << 2)
    ctx->pc = 0x156388u;
    {
        const bool branch_taken_0x156388 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x15638Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x156388u;
            // 0x15638c: 0xac850000  sw          $a1, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x156388) {
            ctx->pc = 0x156308u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_156308;
        }
    }
    ctx->pc = 0x156390u;
label_156390:
    // 0x156390: 0x3e00008  jr          $ra
    ctx->pc = 0x156390u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1562E0u: goto label_1562e0;
            case 0x1562FCu: goto label_1562fc;
            case 0x156308u: goto label_156308;
            case 0x156390u: goto label_156390;
            default: break;
        }
        return;
    }
    ctx->pc = 0x156398u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
