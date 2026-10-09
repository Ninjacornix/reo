#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C92B0
// Address: 0x1c92b0 - 0x1c92f0
void sub_001C92B0_0x1c92b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C92B0_0x1c92b0");
#endif

    switch (ctx->pc) {
        case 0x1c92ccu: goto label_1c92cc;
        default: break;
    }

    ctx->pc = 0x1c92b0u;

    // 0x1c92b0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1c92b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1c92b4: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1c92b4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1c92b8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1c92b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1c92bc: 0x2484d170  addiu       $a0, $a0, -0x2E90
    ctx->pc = 0x1c92bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955376));
    // 0x1c92c0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1c92c0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c92c4: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1C92C4u;
    SET_GPR_U32(ctx, 31, 0x1C92CCu);
    ctx->pc = 0x1C92C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C92C4u;
            // 0x1c92c8: 0x24060820  addiu       $a2, $zero, 0x820 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2080));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C92CCu; }
        if (ctx->pc != 0x1C92CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C92CCu; }
        if (ctx->pc != 0x1C92CCu) { return; }
    }
    ctx->pc = 0x1C92CCu;
label_1c92cc:
    // 0x1c92cc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c92ccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c92d0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1c92d0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c92d4: 0xac20d160  sw          $zero, -0x2EA0($at)
    ctx->pc = 0x1c92d4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294955360), GPR_U32(ctx, 0));
    // 0x1c92d8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1c92d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c92dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1C92DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C92E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C92DCu;
            // 0x1c92e0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C92CCu: goto label_1c92cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C92E4u;
    // 0x1c92e4: 0x0  nop
    ctx->pc = 0x1c92e4u;
    // NOP
    // 0x1c92e8: 0x0  nop
    ctx->pc = 0x1c92e8u;
    // NOP
    // 0x1c92ec: 0x0  nop
    ctx->pc = 0x1c92ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
