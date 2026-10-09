#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013F1E0
// Address: 0x13f1e0 - 0x13f218
void sub_0013F1E0_0x13f1e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013F1E0_0x13f1e0");
#endif

    ctx->pc = 0x13f1e0u;

    // 0x13f1e0: 0x52880  sll         $a1, $a1, 2
    ctx->pc = 0x13f1e0u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x13f1e4: 0x852021  addu        $a0, $a0, $a1
    ctx->pc = 0x13f1e4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x13f1e8: 0x8c830008  lw          $v1, 0x8($a0)
    ctx->pc = 0x13f1e8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x13f1ec: 0x3e00008  jr          $ra
    ctx->pc = 0x13F1ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F1F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F1ECu;
            // 0x13f1f0: 0x8c620004  lw          $v0, 0x4($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13F1F4u;
    // 0x13f1f4: 0x0  nop
    ctx->pc = 0x13f1f4u;
    // NOP
    // 0x13f1f8: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13f1f8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13f1fc: 0x3e00008  jr          $ra
    ctx->pc = 0x13F1FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F200u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F1FCu;
            // 0x13f200: 0xac404758  sw          $zero, 0x4758($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 18264), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13F204u;
    // 0x13f204: 0x0  nop
    ctx->pc = 0x13f204u;
    // NOP
    // 0x13f208: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13f208u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13f20c: 0x3e00008  jr          $ra
    ctx->pc = 0x13F20Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F210u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F20Cu;
            // 0x13f210: 0xac404758  sw          $zero, 0x4758($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 18264), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13F214u;
    // 0x13f214: 0x0  nop
    ctx->pc = 0x13f214u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
