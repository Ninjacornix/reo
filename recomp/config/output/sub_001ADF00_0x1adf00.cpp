#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001ADF00
// Address: 0x1adf00 - 0x1adf50
void sub_001ADF00_0x1adf00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001ADF00_0x1adf00");
#endif

    switch (ctx->pc) {
        case 0x1adf40u: goto label_1adf40;
        default: break;
    }

    ctx->pc = 0x1adf00u;

    // 0x1adf00: 0x41040  sll         $v0, $a0, 1
    ctx->pc = 0x1adf00u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1adf04: 0x3c06002c  lui         $a2, 0x2C
    ctx->pc = 0x1adf04u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)44 << 16));
    // 0x1adf08: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x1adf08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1adf0c: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x1adf0cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1adf10: 0x220c0  sll         $a0, $v0, 3
    ctx->pc = 0x1adf10u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1adf14: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1adf14u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1adf18: 0x24c68d70  addiu       $a2, $a2, -0x7290
    ctx->pc = 0x1adf18u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294937968));
    // 0x1adf1c: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1adf1cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1adf20: 0x24428dc8  addiu       $v0, $v0, -0x7238
    ctx->pc = 0x1adf20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294938056));
    // 0x1adf24: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1adf24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1adf28: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1adf28u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1adf2c: 0xc42021  addu        $a0, $a2, $a0
    ctx->pc = 0x1adf2cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
    // 0x1adf30: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1adf30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1adf34: 0xa0850000  sb          $a1, 0x0($a0)
    ctx->pc = 0x1adf34u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 5));
    // 0x1adf38: 0xc04cb94  jal         func_132E50
    ctx->pc = 0x1ADF38u;
    SET_GPR_U32(ctx, 31, 0x1ADF40u);
    ctx->pc = 0x1ADF3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADF38u;
            // 0x1adf3c: 0x8c440000  lw          $a0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x132E50u;
    if (runtime->hasFunction(0x132E50u)) {
        auto targetFn = runtime->lookupFunction(0x132E50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADF40u; }
        if (ctx->pc != 0x1ADF40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00132E50_0x132e50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ADF40u; }
        if (ctx->pc != 0x1ADF40u) { return; }
    }
    ctx->pc = 0x1ADF40u;
label_1adf40:
    // 0x1adf40: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1adf40u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1adf44: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1adf44u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1adf48: 0x3e00008  jr          $ra
    ctx->pc = 0x1ADF48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1ADF4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ADF48u;
            // 0x1adf4c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1ADF40u: goto label_1adf40;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1ADF50u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
