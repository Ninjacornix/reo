#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001244C8
// Address: 0x1244c8 - 0x1244e0
void sub_001244C8_0x1244c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001244C8_0x1244c8");
#endif

    ctx->pc = 0x1244c8u;

    // 0x1244c8: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x1244c8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x1244cc: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x1244ccu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x1244d0: 0xac44b940  sw          $a0, -0x46C0($v0)
    ctx->pc = 0x1244d0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294949184), GPR_U32(ctx, 4));
    // 0x1244d4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1244d4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1244d8: 0x3e00008  jr          $ra
    ctx->pc = 0x1244D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1244DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1244D8u;
            // 0x1244dc: 0xac65b944  sw          $a1, -0x46BC($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 4294949188), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1244E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
