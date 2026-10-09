#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00167648
// Address: 0x167648 - 0x16767c
void sub_00167648_0x167648(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00167648_0x167648");
#endif

    ctx->pc = 0x167648u;

    // 0x167648: 0x510c0  sll         $v0, $a1, 3
    ctx->pc = 0x167648u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x16764c: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x16764cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x167650: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x167650u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x167654: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x167654u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x167658: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x167658u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x16765c: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x16765cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x167660: 0x24841150  addiu       $a0, $a0, 0x1150
    ctx->pc = 0x167660u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4432));
    // 0x167664: 0x8c820024  lw          $v0, 0x24($a0)
    ctx->pc = 0x167664u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 36)));
    // 0x167668: 0x4400002  bltz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x167668u;
    {
        const bool branch_taken_0x167668 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x16766Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167668u;
            // 0x16766c: 0x461821  addu        $v1, $v0, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167668) {
            ctx->pc = 0x167674u;
            goto label_167674;
        }
    }
    ctx->pc = 0x167670u;
    // 0x167670: 0xac830024  sw          $v1, 0x24($a0)
    ctx->pc = 0x167670u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 36), GPR_U32(ctx, 3));
label_167674:
    // 0x167674: 0x3e00008  jr          $ra
    ctx->pc = 0x167674u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x167674u: goto label_167674;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16767Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
