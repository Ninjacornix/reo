#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0020B0A0
// Address: 0x20b0a0 - 0x20b0c4
void sub_0020B0A0_0x20b0a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0020B0A0_0x20b0a0");
#endif

    ctx->pc = 0x20b0a0u;

    // 0x20b0a0: 0x3c02b000  lui         $v0, 0xB000
    ctx->pc = 0x20b0a0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)45056 << 16));
    // 0x20b0a4: 0x34421820  ori         $v0, $v0, 0x1820
    ctx->pc = 0x20b0a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)6176);
    // 0x20b0a8: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x20b0a8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x20b0ac: 0xf  sync
    ctx->pc = 0x20b0acu;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x20b0b0: 0x3c02b000  lui         $v0, 0xB000
    ctx->pc = 0x20b0b0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)45056 << 16));
    // 0x20b0b4: 0x24030583  addiu       $v1, $zero, 0x583
    ctx->pc = 0x20b0b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1411));
    // 0x20b0b8: 0x34421810  ori         $v0, $v0, 0x1810
    ctx->pc = 0x20b0b8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)6160);
    // 0x20b0bc: 0x3e00008  jr          $ra
    ctx->pc = 0x20B0BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x20B0C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20B0BCu;
            // 0x20b0c0: 0xac430000  sw          $v1, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x20B0C4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
