#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F45D0
// Address: 0x1f45d0 - 0x1f4600
void sub_001F45D0_0x1f45d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F45D0_0x1f45d0");
#endif

    switch (ctx->pc) {
        case 0x1f45ecu: goto label_1f45ec;
        default: break;
    }

    ctx->pc = 0x1f45d0u;

    // 0x1f45d0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f45d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f45d4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1f45d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1f45d8: 0xafa40018  sw          $a0, 0x18($sp)
    ctx->pc = 0x1f45d8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 4));
    // 0x1f45dc: 0xa7a5001c  sh          $a1, 0x1C($sp)
    ctx->pc = 0x1f45dcu;
    WRITE16(ADD32(GPR_U32(ctx, 29), 28), (uint16_t)GPR_U32(ctx, 5));
    // 0x1f45e0: 0x27a40018  addiu       $a0, $sp, 0x18
    ctx->pc = 0x1f45e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
    // 0x1f45e4: 0xc075a3c  jal         func_1D68F0
    ctx->pc = 0x1F45E4u;
    SET_GPR_U32(ctx, 31, 0x1F45ECu);
    ctx->pc = 0x1F45E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F45E4u;
            // 0x1f45e8: 0xa7a0001e  sh          $zero, 0x1E($sp) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 29), 30), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D68F0u;
    if (runtime->hasFunction(0x1D68F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D68F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F45ECu; }
        if (ctx->pc != 0x1F45ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D68F0_0x1d68f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F45ECu; }
        if (ctx->pc != 0x1F45ECu) { return; }
    }
    ctx->pc = 0x1F45ECu;
label_1f45ec:
    // 0x1f45ec: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1f45ecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f45f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1F45F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F45F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F45F0u;
            // 0x1f45f4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F45ECu: goto label_1f45ec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F45F8u;
    // 0x1f45f8: 0x0  nop
    ctx->pc = 0x1f45f8u;
    // NOP
    // 0x1f45fc: 0x0  nop
    ctx->pc = 0x1f45fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
