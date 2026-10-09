#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00140768
// Address: 0x140768 - 0x1407a4
void sub_00140768_0x140768(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00140768_0x140768");
#endif

    switch (ctx->pc) {
        case 0x140780u: goto label_140780;
        default: break;
    }

    ctx->pc = 0x140768u;

    // 0x140768: 0x52880  sll         $a1, $a1, 2
    ctx->pc = 0x140768u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x14076c: 0xa42821  addu        $a1, $a1, $a0
    ctx->pc = 0x14076cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x140770: 0x8ca30018  lw          $v1, 0x18($a1)
    ctx->pc = 0x140770u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 24)));
    // 0x140774: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x140774u;
    {
        const bool branch_taken_0x140774 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x140778u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140774u;
            // 0x140778: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x140774) {
            ctx->pc = 0x14079Cu;
            goto label_14079c;
        }
    }
    ctx->pc = 0x14077Cu;
    // 0x14077c: 0x0  nop
    ctx->pc = 0x14077cu;
    // NOP
label_140780:
    // 0x140780: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x140780u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x140784: 0x0  nop
    ctx->pc = 0x140784u;
    // NOP
    // 0x140788: 0x0  nop
    ctx->pc = 0x140788u;
    // NOP
    // 0x14078c: 0x0  nop
    ctx->pc = 0x14078cu;
    // NOP
    // 0x140790: 0x0  nop
    ctx->pc = 0x140790u;
    // NOP
    // 0x140794: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x140794u;
    {
        const bool branch_taken_0x140794 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x140798u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140794u;
            // 0x140798: 0x24420001  addiu       $v0, $v0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x140794) {
            ctx->pc = 0x140780u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_140780;
        }
    }
    ctx->pc = 0x14079Cu;
label_14079c:
    // 0x14079c: 0x3e00008  jr          $ra
    ctx->pc = 0x14079Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140780u: goto label_140780;
            case 0x14079Cu: goto label_14079c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1407A4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
