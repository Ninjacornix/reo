#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B2810
// Address: 0x1b2810 - 0x1b2850
void sub_001B2810_0x1b2810(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B2810_0x1b2810");
#endif

    ctx->pc = 0x1b2810u;

    // 0x1b2810: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1b2810u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1b2814: 0x842368c8  lh          $v1, 0x68C8($at)
    ctx->pc = 0x1b2814u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 26824)));
    // 0x1b2818: 0x28610100  slti        $at, $v1, 0x100
    ctx->pc = 0x1b2818u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)256) ? 1 : 0);
    // 0x1b281c: 0x10200008  beqz        $at, . + 4 + (0x8 << 2)
    ctx->pc = 0x1B281Cu;
    {
        const bool branch_taken_0x1b281c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B2820u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B281Cu;
            // 0x1b2820: 0x3c010031  lui         $at, 0x31 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b281c) {
            ctx->pc = 0x1B2840u;
            goto label_1b2840;
        }
    }
    ctx->pc = 0x1B2824u;
    // 0x1b2824: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1b2824u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1b2828: 0x8c2466b0  lw          $a0, 0x66B0($at)
    ctx->pc = 0x1b2828u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 26288)));
    // 0x1b282c: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1b282cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1b2830: 0xa42368c8  sh          $v1, 0x68C8($at)
    ctx->pc = 0x1b2830u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 26824), (uint16_t)GPR_U32(ctx, 3));
    // 0x1b2834: 0x2483fffe  addiu       $v1, $a0, -0x2
    ctx->pc = 0x1b2834u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967294));
    // 0x1b2838: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1b2838u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1b283c: 0xac2366b0  sw          $v1, 0x66B0($at)
    ctx->pc = 0x1b283cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 26288), GPR_U32(ctx, 3));
label_1b2840:
    // 0x1b2840: 0x3e00008  jr          $ra
    ctx->pc = 0x1B2840u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B2840u: goto label_1b2840;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B2848u;
    // 0x1b2848: 0x0  nop
    ctx->pc = 0x1b2848u;
    // NOP
    // 0x1b284c: 0x0  nop
    ctx->pc = 0x1b284cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
