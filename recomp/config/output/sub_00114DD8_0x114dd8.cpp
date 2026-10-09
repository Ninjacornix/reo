#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00114DD8
// Address: 0x114dd8 - 0x114df8
void sub_00114DD8_0x114dd8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00114DD8_0x114dd8");
#endif

    ctx->pc = 0x114dd8u;

    // 0x114dd8: 0x24022000  addiu       $v0, $zero, 0x2000
    ctx->pc = 0x114dd8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
    // 0x114ddc: 0xfca00048  sd          $zero, 0x48($a1)
    ctx->pc = 0x114ddcu;
    WRITE64(ADD32(GPR_U32(ctx, 5), 72), GPR_U64(ctx, 0));
    // 0x114de0: 0xaca20004  sw          $v0, 0x4($a1)
    ctx->pc = 0x114de0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
    // 0x114de4: 0x3e00008  jr          $ra
    ctx->pc = 0x114DE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x114DE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x114DE4u;
            // 0x114de8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114DECu;
    // 0x114dec: 0x0  nop
    ctx->pc = 0x114decu;
    // NOP
    // 0x114df0: 0x3e00008  jr          $ra
    ctx->pc = 0x114DF0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x114DF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x114DF0u;
            // 0x114df4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x114DF8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
