#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013D000
// Address: 0x13d000 - 0x13d03c
void sub_0013D000_0x13d000(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013D000_0x13d000");
#endif

    ctx->pc = 0x13d000u;

    // 0x13d000: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13d000u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13d004: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x13D004u;
    {
        const bool branch_taken_0x13d004 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x13D008u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D004u;
            // 0x13d008: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d004) {
            ctx->pc = 0x13D020u;
            goto label_13d020;
        }
    }
    ctx->pc = 0x13D00Cu;
    // 0x13d00c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13d00cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13d010: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13d010u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13d014: 0x2484d368  addiu       $a0, $a0, -0x2C98
    ctx->pc = 0x13d014u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955880));
    // 0x13d018: 0x804f53e  j           func_13D4F8
    ctx->pc = 0x13D018u;
    ctx->pc = 0x13D01Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D018u;
            // 0x13d01c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D4F8u;
    if (runtime->hasFunction(0x13D4F8u)) {
        auto targetFn = runtime->lookupFunction(0x13D4F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013D4F8_0x13d4f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13D020u;
label_13d020:
    // 0x13d020: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x13d020u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13d024: 0x54a20002  bnel        $a1, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x13D024u;
    {
        const bool branch_taken_0x13d024 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        if (branch_taken_0x13d024) {
            ctx->pc = 0x13D028u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13D024u;
            // 0x13d028: 0xa0800004  sb          $zero, 0x4($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 4), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13D030u;
            goto label_13d030;
        }
    }
    ctx->pc = 0x13D02Cu;
    // 0x13d02c: 0xa0850004  sb          $a1, 0x4($a0)
    ctx->pc = 0x13d02cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 4), (uint8_t)GPR_U32(ctx, 5));
label_13d030:
    // 0x13d030: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13d030u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13d034: 0x3e00008  jr          $ra
    ctx->pc = 0x13D034u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13D038u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D034u;
            // 0x13d038: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13D020u: goto label_13d020;
            case 0x13D030u: goto label_13d030;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13D03Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
