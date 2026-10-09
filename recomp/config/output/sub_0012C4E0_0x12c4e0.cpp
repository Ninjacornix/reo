#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C4E0
// Address: 0x12c4e0 - 0x12c51c
void sub_0012C4E0_0x12c4e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C4E0_0x12c4e0");
#endif

    switch (ctx->pc) {
        case 0x12c50cu: goto label_12c50c;
        default: break;
    }

    ctx->pc = 0x12c4e0u;

    // 0x12c4e0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c4e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c4e4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c4e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c4e8: 0x8c82000c  lw          $v0, 0xC($a0)
    ctx->pc = 0x12c4e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x12c4ec: 0x52080  sll         $a0, $a1, 2
    ctx->pc = 0x12c4ecu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x12c4f0: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x12c4f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x12c4f4: 0x8c430008  lw          $v1, 0x8($v0)
    ctx->pc = 0x12c4f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x12c4f8: 0x8c640008  lw          $a0, 0x8($v1)
    ctx->pc = 0x12c4f8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x12c4fc: 0x8c860000  lw          $a2, 0x0($a0)
    ctx->pc = 0x12c4fcu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x12c500: 0x8cc20024  lw          $v0, 0x24($a2)
    ctx->pc = 0x12c500u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 36)));
    // 0x12c504: 0x40f809  jalr        $v0
    ctx->pc = 0x12C504u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12C50Cu);
        ctx->pc = 0x12C508u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12C504u;
            // 0x12c508: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12C50Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12C50Cu: goto label_12c50c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12C50Cu; }
            if (ctx->pc != 0x12C50Cu) { return; }
        }
        }
    }
    ctx->pc = 0x12C50Cu;
label_12c50c:
    // 0x12c50c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c50cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c510: 0x21042  srl         $v0, $v0, 1
    ctx->pc = 0x12c510u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 1));
    // 0x12c514: 0x3e00008  jr          $ra
    ctx->pc = 0x12C514u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12C518u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12C514u;
            // 0x12c518: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12C50Cu: goto label_12c50c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12C51Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
