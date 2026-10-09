#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B6670
// Address: 0x1b6670 - 0x1b66c0
void sub_001B6670_0x1b6670(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B6670_0x1b6670");
#endif

    ctx->pc = 0x1b6670u;

    // 0x1b6670: 0x308300ff  andi        $v1, $a0, 0xFF
    ctx->pc = 0x1b6670u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1b6674: 0x28610060  slti        $at, $v1, 0x60
    ctx->pc = 0x1b6674u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)96) ? 1 : 0);
    // 0x1b6678: 0x10200004  beqz        $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B6678u;
    {
        const bool branch_taken_0x1b6678 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B667Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6678u;
            // 0x1b667c: 0x28610080  slti        $at, $v1, 0x80 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)128) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6678) {
            ctx->pc = 0x1B668Cu;
            goto label_1b668c;
        }
    }
    ctx->pc = 0x1B6680u;
    // 0x1b6680: 0x24627fff  addiu       $v0, $v1, 0x7FFF
    ctx->pc = 0x1b6680u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 32767));
    // 0x1b6684: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1B6684u;
    {
        const bool branch_taken_0x1b6684 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6688u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6684u;
            // 0x1b6688: 0x24420520  addiu       $v0, $v0, 0x520 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1312));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6684) {
            ctx->pc = 0x1B66B8u;
            goto label_1b66b8;
        }
    }
    ctx->pc = 0x1B668Cu;
label_1b668c:
    // 0x1b668c: 0x10200004  beqz        $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B668Cu;
    {
        const bool branch_taken_0x1b668c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6690u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B668Cu;
            // 0x1b6690: 0x240200a5  addiu       $v0, $zero, 0xA5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 165));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b668c) {
            ctx->pc = 0x1B66A0u;
            goto label_1b66a0;
        }
    }
    ctx->pc = 0x1B6694u;
    // 0x1b6694: 0x24627fff  addiu       $v0, $v1, 0x7FFF
    ctx->pc = 0x1b6694u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 32767));
    // 0x1b6698: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1B6698u;
    {
        const bool branch_taken_0x1b6698 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B669Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6698u;
            // 0x1b669c: 0x24420521  addiu       $v0, $v0, 0x521 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1313));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6698) {
            ctx->pc = 0x1B66B8u;
            goto label_1b66b8;
        }
    }
    ctx->pc = 0x1B66A0u;
label_1b66a0:
    // 0x1b66a0: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B66A0u;
    {
        const bool branch_taken_0x1b66a0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1b66a0) {
            ctx->pc = 0x1B66B0u;
            goto label_1b66b0;
        }
    }
    ctx->pc = 0x1B66A8u;
    // 0x1b66a8: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1B66A8u;
    {
        const bool branch_taken_0x1b66a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B66ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B66A8u;
            // 0x1b66ac: 0x340285a3  ori         $v0, $zero, 0x85A3 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)34211);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b66a8) {
            ctx->pc = 0x1B66B8u;
            goto label_1b66b8;
        }
    }
    ctx->pc = 0x1B66B0u;
label_1b66b0:
    // 0x1b66b0: 0x24627fff  addiu       $v0, $v1, 0x7FFF
    ctx->pc = 0x1b66b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 32767));
    // 0x1b66b4: 0x244204ff  addiu       $v0, $v0, 0x4FF
    ctx->pc = 0x1b66b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1279));
label_1b66b8:
    // 0x1b66b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1B66B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B668Cu: goto label_1b668c;
            case 0x1B66A0u: goto label_1b66a0;
            case 0x1B66B0u: goto label_1b66b0;
            case 0x1B66B8u: goto label_1b66b8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B66C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
