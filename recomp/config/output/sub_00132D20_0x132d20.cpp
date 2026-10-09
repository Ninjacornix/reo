#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00132D20
// Address: 0x132d20 - 0x132d5c
void sub_00132D20_0x132d20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00132D20_0x132d20");
#endif

    ctx->pc = 0x132d20u;

    // 0x132d20: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x132d20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x132d24: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x132D24u;
    {
        const bool branch_taken_0x132d24 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x132D28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132D24u;
            // 0x132d28: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x132d24) {
            ctx->pc = 0x132D40u;
            goto label_132d40;
        }
    }
    ctx->pc = 0x132D2Cu;
    // 0x132d2c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x132d2cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x132d30: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x132d30u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132d34: 0x2484b390  addiu       $a0, $a0, -0x4C70
    ctx->pc = 0x132d34u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294947728));
    // 0x132d38: 0x804a034  j           func_1280D0
    ctx->pc = 0x132D38u;
    ctx->pc = 0x132D3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132D38u;
            // 0x132d3c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x132D40u;
label_132d40:
    // 0x132d40: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x132d40u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x132d44: 0xa480006a  sh          $zero, 0x6A($a0)
    ctx->pc = 0x132d44u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 106), (uint16_t)GPR_U32(ctx, 0));
    // 0x132d48: 0xa4800060  sh          $zero, 0x60($a0)
    ctx->pc = 0x132d48u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 96), (uint16_t)GPR_U32(ctx, 0));
    // 0x132d4c: 0xac800064  sw          $zero, 0x64($a0)
    ctx->pc = 0x132d4cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 100), GPR_U32(ctx, 0));
    // 0x132d50: 0xa4800068  sh          $zero, 0x68($a0)
    ctx->pc = 0x132d50u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 104), (uint16_t)GPR_U32(ctx, 0));
    // 0x132d54: 0x3e00008  jr          $ra
    ctx->pc = 0x132D54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x132D58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x132D54u;
            // 0x132d58: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x132D40u: goto label_132d40;
            default: break;
        }
        return;
    }
    ctx->pc = 0x132D5Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
