#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001159A8
// Address: 0x1159a8 - 0x1159d0
void sub_001159A8_0x1159a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001159A8_0x1159a8");
#endif

    ctx->pc = 0x1159a8u;

    // 0x1159a8: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1159a8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1159ac: 0x2443aa80  addiu       $v1, $v0, -0x5580
    ctx->pc = 0x1159acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 4294945408));
    // 0x1159b0: 0xac44aa80  sw          $a0, -0x5580($v0)
    ctx->pc = 0x1159b0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294945408), GPR_U32(ctx, 4));
    // 0x1159b4: 0x24640010  addiu       $a0, $v1, 0x10
    ctx->pc = 0x1159b4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 16));
    // 0x1159b8: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1159b8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1159bc: 0xac640008  sw          $a0, 0x8($v1)
    ctx->pc = 0x1159bcu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 4));
    // 0x1159c0: 0xac600004  sw          $zero, 0x4($v1)
    ctx->pc = 0x1159c0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 0));
    // 0x1159c4: 0x3e00008  jr          $ra
    ctx->pc = 0x1159C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1159C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1159C4u;
            // 0x1159c8: 0xac64000c  sw          $a0, 0xC($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 12), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1159CCu;
    // 0x1159cc: 0x0  nop
    ctx->pc = 0x1159ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
