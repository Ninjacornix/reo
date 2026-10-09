#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00102AC0
// Address: 0x102ac0 - 0x102b1c
void sub_00102AC0_0x102ac0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00102AC0_0x102ac0");
#endif

    switch (ctx->pc) {
        case 0x102ae8u: goto label_102ae8;
        default: break;
    }

    ctx->pc = 0x102ac0u;

    // 0x102ac0: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x102ac0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x102ac4: 0x10a00013  beqz        $a1, . + 4 + (0x13 << 2)
    ctx->pc = 0x102AC4u;
    {
        const bool branch_taken_0x102ac4 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x102AC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102AC4u;
            // 0x102ac8: 0x24a3ffff  addiu       $v1, $a1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x102ac4) {
            ctx->pc = 0x102B14u;
            goto label_102b14;
        }
    }
    ctx->pc = 0x102ACCu;
    // 0x102acc: 0x3c061000  lui         $a2, 0x1000
    ctx->pc = 0x102accu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)4096 << 16));
    // 0x102ad0: 0x3c051000  lui         $a1, 0x1000
    ctx->pc = 0x102ad0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4096 << 16));
    // 0x102ad4: 0x34c63800  ori         $a2, $a2, 0x3800
    ctx->pc = 0x102ad4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)14336);
    // 0x102ad8: 0x3c091000  lui         $t1, 0x1000
    ctx->pc = 0x102ad8u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)4096 << 16));
    // 0x102adc: 0x34a54000  ori         $a1, $a1, 0x4000
    ctx->pc = 0x102adcu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)16384);
    // 0x102ae0: 0x2408ffff  addiu       $t0, $zero, -0x1
    ctx->pc = 0x102ae0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x102ae4: 0x0  nop
    ctx->pc = 0x102ae4u;
    // NOP
label_102ae8:
    // 0x102ae8: 0x8cc20000  lw          $v0, 0x0($a2)
    ctx->pc = 0x102ae8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x102aec: 0x491024  and         $v0, $v0, $t1
    ctx->pc = 0x102aecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 9));
    // 0x102af0: 0x50400003  beql        $v0, $zero, . + 4 + (0x3 << 2)
    ctx->pc = 0x102AF0u;
    {
        const bool branch_taken_0x102af0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x102af0) {
            ctx->pc = 0x102AF4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x102AF0u;
            // 0x102af4: 0x78820000  lq          $v0, 0x0($a0) (Delay Slot)
        SET_GPR_VEC(ctx, 2, READ128(ADD32(GPR_U32(ctx, 4), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x102B00u;
            goto label_102b00;
        }
    }
    ctx->pc = 0x102AF8u;
    // 0x102af8: 0x3e00008  jr          $ra
    ctx->pc = 0x102AF8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102AFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102AF8u;
            // 0x102afc: 0xe0102d  daddu       $v0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x102AE8u: goto label_102ae8;
            case 0x102B00u: goto label_102b00;
            case 0x102B14u: goto label_102b14;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102B00u;
label_102b00:
    // 0x102b00: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x102b00u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x102b04: 0x24840010  addiu       $a0, $a0, 0x10
    ctx->pc = 0x102b04u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16));
    // 0x102b08: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x102b08u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x102b0c: 0x1468fff6  bne         $v1, $t0, . + 4 + (-0xA << 2)
    ctx->pc = 0x102B0Cu;
    {
        const bool branch_taken_0x102b0c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 8));
        ctx->pc = 0x102B10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102B0Cu;
            // 0x102b10: 0x7ca20000  sq          $v0, 0x0($a1) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 5), 0), GPR_VEC(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x102b0c) {
            ctx->pc = 0x102AE8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_102ae8;
        }
    }
    ctx->pc = 0x102B14u;
label_102b14:
    // 0x102b14: 0x3e00008  jr          $ra
    ctx->pc = 0x102B14u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102B18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102B14u;
            // 0x102b18: 0xe0102d  daddu       $v0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x102AE8u: goto label_102ae8;
            case 0x102B00u: goto label_102b00;
            case 0x102B14u: goto label_102b14;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102B1Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
