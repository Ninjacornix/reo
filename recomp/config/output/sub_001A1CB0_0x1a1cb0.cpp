#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A1CB0
// Address: 0x1a1cb0 - 0x1a1d30
void sub_001A1CB0_0x1a1cb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A1CB0_0x1a1cb0");
#endif

    switch (ctx->pc) {
        case 0x1a1cc4u: goto label_1a1cc4;
        default: break;
    }

    ctx->pc = 0x1a1cb0u;

    // 0x1a1cb0: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1a1cb0u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a1cb4: 0x3c070024  lui         $a3, 0x24
    ctx->pc = 0x1a1cb4u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)36 << 16));
    // 0x1a1cb8: 0x240500ff  addiu       $a1, $zero, 0xFF
    ctx->pc = 0x1a1cb8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1a1cbc: 0x24e71b10  addiu       $a3, $a3, 0x1B10
    ctx->pc = 0x1a1cbcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 6928));
    // 0x1a1cc0: 0x9443c  dsll32      $t0, $t1, 16
    ctx->pc = 0x1a1cc0u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 9) << (32 + 16));
label_1a1cc4:
    // 0x1a1cc4: 0x8c860008  lw          $a2, 0x8($a0)
    ctx->pc = 0x1a1cc4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1a1cc8: 0x8443f  dsra32      $t0, $t0, 16
    ctx->pc = 0x1a1cc8u;
    SET_GPR_S64(ctx, 8, GPR_S64(ctx, 8) >> (32 + 16));
    // 0x1a1ccc: 0x81880  sll         $v1, $t0, 2
    ctx->pc = 0x1a1cccu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 8), 2));
    // 0x1a1cd0: 0xe31821  addu        $v1, $a3, $v1
    ctx->pc = 0x1a1cd0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 3)));
    // 0x1a1cd4: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1a1cd4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1a1cd8: 0xc31824  and         $v1, $a2, $v1
    ctx->pc = 0x1a1cd8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) & GPR_U64(ctx, 3));
    // 0x1a1cdc: 0x1060000a  beqz        $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x1A1CDCu;
    {
        const bool branch_taken_0x1a1cdc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A1CE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1CDCu;
            // 0x1a1ce0: 0x81840  sll         $v1, $t0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a1cdc) {
            ctx->pc = 0x1A1D08u;
            goto label_1a1d08;
        }
    }
    ctx->pc = 0x1A1CE4u;
    // 0x1a1ce4: 0x81840  sll         $v1, $t0, 1
    ctx->pc = 0x1a1ce4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x1a1ce8: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x1a1ce8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1a1cec: 0x24660038  addiu       $a2, $v1, 0x38
    ctx->pc = 0x1a1cecu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), 56));
    // 0x1a1cf0: 0x90630038  lbu         $v1, 0x38($v1)
    ctx->pc = 0x1a1cf0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 56)));
    // 0x1a1cf4: 0x10650006  beq         $v1, $a1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A1CF4u;
    {
        const bool branch_taken_0x1a1cf4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 5));
        if (branch_taken_0x1a1cf4) {
            ctx->pc = 0x1A1D10u;
            goto label_1a1d10;
        }
    }
    ctx->pc = 0x1A1CFCu;
    // 0x1a1cfc: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1a1cfcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1a1d00: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1A1D00u;
    {
        const bool branch_taken_0x1a1d00 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A1D04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1D00u;
            // 0x1a1d04: 0xa0c30000  sb          $v1, 0x0($a2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a1d00) {
            ctx->pc = 0x1A1D10u;
            goto label_1a1d10;
        }
    }
    ctx->pc = 0x1A1D08u;
label_1a1d08:
    // 0x1a1d08: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x1a1d08u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1a1d0c: 0xa4600038  sh          $zero, 0x38($v1)
    ctx->pc = 0x1a1d0cu;
    WRITE16(ADD32(GPR_U32(ctx, 3), 56), (uint16_t)GPR_U32(ctx, 0));
label_1a1d10:
    // 0x1a1d10: 0x25230001  addiu       $v1, $t1, 0x1
    ctx->pc = 0x1a1d10u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1a1d14: 0x34c3c  dsll32      $t1, $v1, 16
    ctx->pc = 0x1a1d14u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 3) << (32 + 16));
    // 0x1a1d18: 0x94c3f  dsra32      $t1, $t1, 16
    ctx->pc = 0x1a1d18u;
    SET_GPR_S64(ctx, 9, GPR_S64(ctx, 9) >> (32 + 16));
    // 0x1a1d1c: 0x29230018  slti        $v1, $t1, 0x18
    ctx->pc = 0x1a1d1cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 9) < (int64_t)(int32_t)24) ? 1 : 0);
    // 0x1a1d20: 0x1460ffe8  bnez        $v1, . + 4 + (-0x18 << 2)
    ctx->pc = 0x1A1D20u;
    {
        const bool branch_taken_0x1a1d20 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A1D24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1D20u;
            // 0x1a1d24: 0x9443c  dsll32      $t0, $t1, 16 (Delay Slot)
        SET_GPR_U64(ctx, 8, GPR_U64(ctx, 9) << (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a1d20) {
            ctx->pc = 0x1A1CC4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a1cc4;
        }
    }
    ctx->pc = 0x1A1D28u;
    // 0x1a1d28: 0x3e00008  jr          $ra
    ctx->pc = 0x1A1D28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A1CC4u: goto label_1a1cc4;
            case 0x1A1D08u: goto label_1a1d08;
            case 0x1A1D10u: goto label_1a1d10;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A1D30u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
