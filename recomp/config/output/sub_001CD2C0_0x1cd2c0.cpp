#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CD2C0
// Address: 0x1cd2c0 - 0x1cd340
void sub_001CD2C0_0x1cd2c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CD2C0_0x1cd2c0");
#endif

    switch (ctx->pc) {
        case 0x1cd2fcu: goto label_1cd2fc;
        default: break;
    }

    ctx->pc = 0x1cd2c0u;

    // 0x1cd2c0: 0x28a10006  slti        $at, $a1, 0x6
    ctx->pc = 0x1cd2c0u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)6) ? 1 : 0);
    // 0x1cd2c4: 0x14200003  bnez        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CD2C4u;
    {
        const bool branch_taken_0x1cd2c4 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CD2C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD2C4u;
            // 0x1cd2c8: 0x51840  sll         $v1, $a1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cd2c4) {
            ctx->pc = 0x1CD2D4u;
            goto label_1cd2d4;
        }
    }
    ctx->pc = 0x1CD2CCu;
    // 0x1cd2cc: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1CD2CCu;
    {
        const bool branch_taken_0x1cd2cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CD2D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD2CCu;
            // 0x1cd2d0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cd2cc) {
            ctx->pc = 0x1CD330u;
            goto label_1cd330;
        }
    }
    ctx->pc = 0x1CD2D4u;
label_1cd2d4:
    // 0x1cd2d4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1cd2d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1cd2d8: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x1cd2d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1cd2dc: 0x84640000  lh          $a0, 0x0($v1)
    ctx->pc = 0x1cd2dcu;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1cd2e0: 0x14820003  bne         $a0, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CD2E0u;
    {
        const bool branch_taken_0x1cd2e0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        ctx->pc = 0x1CD2E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD2E0u;
            // 0x1cd2e4: 0x3c060034  lui         $a2, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cd2e0) {
            ctx->pc = 0x1CD2F0u;
            goto label_1cd2f0;
        }
    }
    ctx->pc = 0x1CD2E8u;
    // 0x1cd2e8: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1CD2E8u;
    {
        const bool branch_taken_0x1cd2e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CD2ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD2E8u;
            // 0x1cd2ec: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cd2e8) {
            ctx->pc = 0x1CD330u;
            goto label_1cd330;
        }
    }
    ctx->pc = 0x1CD2F0u;
label_1cd2f0:
    // 0x1cd2f0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1cd2f0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cd2f4: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1CD2F4u;
    {
        const bool branch_taken_0x1cd2f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CD2F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD2F4u;
            // 0x1cd2f8: 0x24c61640  addiu       $a2, $a2, 0x1640 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 5696));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cd2f4) {
            ctx->pc = 0x1CD324u;
            goto label_1cd324;
        }
    }
    ctx->pc = 0x1CD2FCu;
label_1cd2fc:
    // 0x1cd2fc: 0x8cc20000  lw          $v0, 0x0($a2)
    ctx->pc = 0x1cd2fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1cd300: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1CD300u;
    {
        const bool branch_taken_0x1cd300 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cd300) {
            ctx->pc = 0x1CD31Cu;
            goto label_1cd31c;
        }
    }
    ctx->pc = 0x1CD308u;
    // 0x1cd308: 0x8cc30004  lw          $v1, 0x4($a2)
    ctx->pc = 0x1cd308u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x1cd30c: 0x14640003  bne         $v1, $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CD30Cu;
    {
        const bool branch_taken_0x1cd30c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        if (branch_taken_0x1cd30c) {
            ctx->pc = 0x1CD31Cu;
            goto label_1cd31c;
        }
    }
    ctx->pc = 0x1CD314u;
    // 0x1cd314: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1CD314u;
    {
        const bool branch_taken_0x1cd314 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cd314) {
            ctx->pc = 0x1CD330u;
            goto label_1cd330;
        }
    }
    ctx->pc = 0x1CD31Cu;
label_1cd31c:
    // 0x1cd31c: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1cd31cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1cd320: 0x24c60010  addiu       $a2, $a2, 0x10
    ctx->pc = 0x1cd320u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 16));
label_1cd324:
    // 0x1cd324: 0x28a20100  slti        $v0, $a1, 0x100
    ctx->pc = 0x1cd324u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)256) ? 1 : 0);
    // 0x1cd328: 0x1440fff4  bnez        $v0, . + 4 + (-0xC << 2)
    ctx->pc = 0x1CD328u;
    {
        const bool branch_taken_0x1cd328 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CD32Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CD328u;
            // 0x1cd32c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cd328) {
            ctx->pc = 0x1CD2FCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1cd2fc;
        }
    }
    ctx->pc = 0x1CD330u;
label_1cd330:
    // 0x1cd330: 0x3e00008  jr          $ra
    ctx->pc = 0x1CD330u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CD2D4u: goto label_1cd2d4;
            case 0x1CD2F0u: goto label_1cd2f0;
            case 0x1CD2FCu: goto label_1cd2fc;
            case 0x1CD31Cu: goto label_1cd31c;
            case 0x1CD324u: goto label_1cd324;
            case 0x1CD330u: goto label_1cd330;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CD338u;
    // 0x1cd338: 0x0  nop
    ctx->pc = 0x1cd338u;
    // NOP
    // 0x1cd33c: 0x0  nop
    ctx->pc = 0x1cd33cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
