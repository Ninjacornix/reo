#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001300A8
// Address: 0x1300a8 - 0x1300c4
void sub_001300A8_0x1300a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001300A8_0x1300a8");
#endif

    ctx->pc = 0x1300a8u;

    // 0x1300a8: 0x24020028  addiu       $v0, $zero, 0x28
    ctx->pc = 0x1300a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
    // 0x1300ac: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x1300acu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x1300b0: 0x441023  subu        $v0, $v0, $a0
    ctx->pc = 0x1300b0u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1300b4: 0x3c050022  lui         $a1, 0x22
    ctx->pc = 0x1300b4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)34 << 16));
    // 0x1300b8: 0xac62a8a8  sw          $v0, -0x5758($v1)
    ctx->pc = 0x1300b8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294944936), GPR_U32(ctx, 2));
    // 0x1300bc: 0x3e00008  jr          $ra
    ctx->pc = 0x1300BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1300C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1300BCu;
            // 0x1300c0: 0xaca4a8ac  sw          $a0, -0x5754($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 4294944940), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1300C4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
