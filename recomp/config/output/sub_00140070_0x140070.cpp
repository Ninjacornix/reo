#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00140070
// Address: 0x140070 - 0x1400c0
void sub_00140070_0x140070(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00140070_0x140070");
#endif

    ctx->pc = 0x140070u;

    // 0x140070: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x140070u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x140074: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x140074u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x140078: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x140078u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x14007c: 0x24638c90  addiu       $v1, $v1, -0x7370
    ctx->pc = 0x14007cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294937744));
    // 0x140080: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x140080u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x140084: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x140084u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x140088: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x140088u;
    {
        const bool branch_taken_0x140088 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x14008Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140088u;
            // 0x14008c: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x140088) {
            ctx->pc = 0x1400B0u;
            goto label_1400b0;
        }
    }
    ctx->pc = 0x140090u;
    // 0x140090: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x140090u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x140094: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x140094u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x140098: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x140098u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14009c: 0x24848c98  addiu       $a0, $a0, -0x7368
    ctx->pc = 0x14009cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294937752));
    // 0x1400a0: 0x24060c00  addiu       $a2, $zero, 0xC00
    ctx->pc = 0x1400a0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3072));
    // 0x1400a4: 0x8041f1a  j           func_107C68
    ctx->pc = 0x1400A4u;
    ctx->pc = 0x1400A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1400A4u;
            // 0x1400a8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1400ACu;
    // 0x1400ac: 0x0  nop
    ctx->pc = 0x1400acu;
    // NOP
label_1400b0:
    // 0x1400b0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1400b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1400b4: 0x3e00008  jr          $ra
    ctx->pc = 0x1400B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1400B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1400B4u;
            // 0x1400b8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1400B0u: goto label_1400b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1400BCu;
    // 0x1400bc: 0x0  nop
    ctx->pc = 0x1400bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
