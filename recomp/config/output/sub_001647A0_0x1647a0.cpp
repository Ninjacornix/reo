#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001647A0
// Address: 0x1647a0 - 0x1647dc
void sub_001647A0_0x1647a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001647A0_0x1647a0");
#endif

    ctx->pc = 0x1647a0u;

    // 0x1647a0: 0x24020012  addiu       $v0, $zero, 0x12
    ctx->pc = 0x1647a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1647a4: 0x28a50012  slti        $a1, $a1, 0x12
    ctx->pc = 0x1647a4u;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)18) ? 1 : 0);
    // 0x1647a8: 0xacc20000  sw          $v0, 0x0($a2)
    ctx->pc = 0x1647a8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x1647ac: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x1647acu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1647b0: 0x14a00008  bnez        $a1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1647B0u;
    {
        const bool branch_taken_0x1647b0 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x1647B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1647B0u;
            // 0x1647b4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1647b0) {
            ctx->pc = 0x1647D4u;
            goto label_1647d4;
        }
    }
    ctx->pc = 0x1647B8u;
    // 0x1647b8: 0x90c40000  lbu         $a0, 0x0($a2)
    ctx->pc = 0x1647b8u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1647bc: 0x24030080  addiu       $v1, $zero, 0x80
    ctx->pc = 0x1647bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x1647c0: 0x14830004  bne         $a0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1647C0u;
    {
        const bool branch_taken_0x1647c0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        if (branch_taken_0x1647c0) {
            ctx->pc = 0x1647D4u;
            goto label_1647d4;
        }
    }
    ctx->pc = 0x1647C8u;
    // 0x1647c8: 0x90c20001  lbu         $v0, 0x1($a2)
    ctx->pc = 0x1647c8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 1)));
    // 0x1647cc: 0x38420001  xori        $v0, $v0, 0x1
    ctx->pc = 0x1647ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
    // 0x1647d0: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x1647d0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
label_1647d4:
    // 0x1647d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1647D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1647D4u: goto label_1647d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1647DCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
