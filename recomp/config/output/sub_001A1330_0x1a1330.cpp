#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A1330
// Address: 0x1a1330 - 0x1a136c
void sub_001A1330_0x1a1330(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A1330_0x1a1330");
#endif

    ctx->pc = 0x1a1330u;

    // 0x1a1330: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1a1330u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1a1334: 0x24a3ffff  addiu       $v1, $a1, -0x1
    ctx->pc = 0x1a1334u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x1a1338: 0x62082a  slt         $at, $v1, $v0
    ctx->pc = 0x1a1338u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1a133c: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A133Cu;
    {
        const bool branch_taken_0x1a133c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A1340u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A133Cu;
            // 0x1a1340: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a133c) {
            ctx->pc = 0x1A134Cu;
            goto label_1a134c;
        }
    }
    ctx->pc = 0x1A1344u;
    // 0x1a1344: 0x14a00003  bnez        $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A1344u;
    {
        const bool branch_taken_0x1a1344 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a1344) {
            ctx->pc = 0x1A1354u;
            goto label_1a1354;
        }
    }
    ctx->pc = 0x1A134Cu;
label_1a134c:
    // 0x1a134c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1A134Cu;
    {
        const bool branch_taken_0x1a134c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a134c) {
            ctx->pc = 0x1A1364u;
            goto label_1a1364;
        }
    }
    ctx->pc = 0x1A1354u;
label_1a1354:
    // 0x1a1354: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x1a1354u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1a1358: 0x31900  sll         $v1, $v1, 4
    ctx->pc = 0x1a1358u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1a135c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1a135cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a1360: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1a1360u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_1a1364:
    // 0x1a1364: 0x3e00008  jr          $ra
    ctx->pc = 0x1A1364u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A134Cu: goto label_1a134c;
            case 0x1A1354u: goto label_1a1354;
            case 0x1A1364u: goto label_1a1364;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A136Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
