#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018C810
// Address: 0x18c810 - 0x18c850
void sub_0018C810_0x18c810(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018C810_0x18c810");
#endif

    ctx->pc = 0x18c810u;

    // 0x18c810: 0x51400  sll         $v0, $a1, 16
    ctx->pc = 0x18c810u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 16));
    // 0x18c814: 0x34c38000  ori         $v1, $a2, 0x8000
    ctx->pc = 0x18c814u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)32768);
    // 0x18c818: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x18c818u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x18c81c: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x18c81cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x18c820: 0x3c026c00  lui         $v0, 0x6C00
    ctx->pc = 0x18c820u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)27648 << 16));
    // 0x18c824: 0x3c050100  lui         $a1, 0x100
    ctx->pc = 0x18c824u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)256 << 16));
    // 0x18c828: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x18c828u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x18c82c: 0xac800004  sw          $zero, 0x4($a0)
    ctx->pc = 0x18c82cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 0));
    // 0x18c830: 0x34a20404  ori         $v0, $a1, 0x404
    ctx->pc = 0x18c830u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1028);
    // 0x18c834: 0xac820008  sw          $v0, 0x8($a0)
    ctx->pc = 0x18c834u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 2));
    // 0x18c838: 0x24820010  addiu       $v0, $a0, 0x10
    ctx->pc = 0x18c838u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 16));
    // 0x18c83c: 0x3e00008  jr          $ra
    ctx->pc = 0x18C83Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18C840u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18C83Cu;
            // 0x18c840: 0xac83000c  sw          $v1, 0xC($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x18C844u;
    // 0x18c844: 0x0  nop
    ctx->pc = 0x18c844u;
    // NOP
    // 0x18c848: 0x0  nop
    ctx->pc = 0x18c848u;
    // NOP
    // 0x18c84c: 0x0  nop
    ctx->pc = 0x18c84cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
