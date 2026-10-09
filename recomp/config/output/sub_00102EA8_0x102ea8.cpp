#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00102EA8
// Address: 0x102ea8 - 0x102f08
void sub_00102EA8_0x102ea8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00102EA8_0x102ea8");
#endif

    switch (ctx->pc) {
        case 0x102ed0u: goto label_102ed0;
        default: break;
    }

    ctx->pc = 0x102ea8u;

    // 0x102ea8: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x102ea8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x102eac: 0x10a00012  beqz        $a1, . + 4 + (0x12 << 2)
    ctx->pc = 0x102EACu;
    {
        const bool branch_taken_0x102eac = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x102EB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102EACu;
            // 0x102eb0: 0x24a3ffff  addiu       $v1, $a1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x102eac) {
            ctx->pc = 0x102EF8u;
            goto label_102ef8;
        }
    }
    ctx->pc = 0x102EB4u;
    // 0x102eb4: 0x3c061000  lui         $a2, 0x1000
    ctx->pc = 0x102eb4u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)4096 << 16));
    // 0x102eb8: 0x3c051000  lui         $a1, 0x1000
    ctx->pc = 0x102eb8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4096 << 16));
    // 0x102ebc: 0x34c63c00  ori         $a2, $a2, 0x3C00
    ctx->pc = 0x102ebcu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)15360);
    // 0x102ec0: 0x3c091f00  lui         $t1, 0x1F00
    ctx->pc = 0x102ec0u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)7936 << 16));
    // 0x102ec4: 0x34a55000  ori         $a1, $a1, 0x5000
    ctx->pc = 0x102ec4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)20480);
    // 0x102ec8: 0x2408ffff  addiu       $t0, $zero, -0x1
    ctx->pc = 0x102ec8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x102ecc: 0x0  nop
    ctx->pc = 0x102eccu;
    // NOP
label_102ed0:
    // 0x102ed0: 0x8cc20000  lw          $v0, 0x0($a2)
    ctx->pc = 0x102ed0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x102ed4: 0x491024  and         $v0, $v0, $t1
    ctx->pc = 0x102ed4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 9));
    // 0x102ed8: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x102ED8u;
    {
        const bool branch_taken_0x102ed8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x102EDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102ED8u;
            // 0x102edc: 0xe0102d  daddu       $v0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x102ed8) {
            ctx->pc = 0x102F00u;
            goto label_102f00;
        }
    }
    ctx->pc = 0x102EE0u;
    // 0x102ee0: 0x78a20000  lq          $v0, 0x0($a1)
    ctx->pc = 0x102ee0u;
    SET_GPR_VEC(ctx, 2, READ128(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x102ee4: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x102ee4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x102ee8: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x102ee8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x102eec: 0x7c820000  sq          $v0, 0x0($a0)
    ctx->pc = 0x102eecu;
    WRITE128(ADD32(GPR_U32(ctx, 4), 0), GPR_VEC(ctx, 2));
    // 0x102ef0: 0x1468fff7  bne         $v1, $t0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x102EF0u;
    {
        const bool branch_taken_0x102ef0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 8));
        ctx->pc = 0x102EF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102EF0u;
            // 0x102ef4: 0x24840010  addiu       $a0, $a0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x102ef0) {
            ctx->pc = 0x102ED0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_102ed0;
        }
    }
    ctx->pc = 0x102EF8u;
label_102ef8:
    // 0x102ef8: 0x3e00008  jr          $ra
    ctx->pc = 0x102EF8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102EFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102EF8u;
            // 0x102efc: 0xe0102d  daddu       $v0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x102ED0u: goto label_102ed0;
            case 0x102EF8u: goto label_102ef8;
            case 0x102F00u: goto label_102f00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102F00u;
label_102f00:
    // 0x102f00: 0x3e00008  jr          $ra
    ctx->pc = 0x102F00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x102ED0u: goto label_102ed0;
            case 0x102EF8u: goto label_102ef8;
            case 0x102F00u: goto label_102f00;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102F08u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
