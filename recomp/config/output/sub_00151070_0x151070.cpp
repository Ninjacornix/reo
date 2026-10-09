#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00151070
// Address: 0x151070 - 0x1510c0
void sub_00151070_0x151070(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00151070_0x151070");
#endif

    ctx->pc = 0x151070u;

    // 0x151070: 0x8c820048  lw          $v0, 0x48($a0)
    ctx->pc = 0x151070u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 72)));
    // 0x151074: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x151074u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x151078: 0x10430008  beq         $v0, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x151078u;
    {
        const bool branch_taken_0x151078 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x15107Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x151078u;
            // 0x15107c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x151078) {
            ctx->pc = 0x15109Cu;
            goto label_15109c;
        }
    }
    ctx->pc = 0x151080u;
    // 0x151080: 0x8c820118  lw          $v0, 0x118($a0)
    ctx->pc = 0x151080u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 280)));
    // 0x151084: 0x50430005  beql        $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x151084u;
    {
        const bool branch_taken_0x151084 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x151084) {
            ctx->pc = 0x151088u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x151084u;
            // 0x151088: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15109Cu;
            goto label_15109c;
        }
    }
    ctx->pc = 0x15108Cu;
    // 0x15108c: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x15108cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x151090: 0x54450005  bnel        $v0, $a1, . + 4 + (0x5 << 2)
    ctx->pc = 0x151090u;
    {
        const bool branch_taken_0x151090 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 5));
        if (branch_taken_0x151090) {
            ctx->pc = 0x151094u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x151090u;
            // 0x151094: 0x8c820134  lw          $v0, 0x134($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 308)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1510A8u;
            goto label_1510a8;
        }
    }
    ctx->pc = 0x151098u;
    // 0x151098: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x151098u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_15109c:
    // 0x15109c: 0x3e00008  jr          $ra
    ctx->pc = 0x15109Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1510A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15109Cu;
            // 0x1510a0: 0xac820038  sw          $v0, 0x38($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 56), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15109Cu: goto label_15109c;
            case 0x1510A8u: goto label_1510a8;
            case 0x1510B8u: goto label_1510b8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1510A4u;
    // 0x1510a4: 0x0  nop
    ctx->pc = 0x1510a4u;
    // NOP
label_1510a8:
    // 0x1510a8: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1510A8u;
    {
        const bool branch_taken_0x1510a8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x1510ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1510A8u;
            // 0x1510ac: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1510a8) {
            ctx->pc = 0x1510B8u;
            goto label_1510b8;
        }
    }
    ctx->pc = 0x1510B0u;
    // 0x1510b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1510B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1510B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1510B0u;
            // 0x1510b4: 0xac820038  sw          $v0, 0x38($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 56), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15109Cu: goto label_15109c;
            case 0x1510A8u: goto label_1510a8;
            case 0x1510B8u: goto label_1510b8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1510B8u;
label_1510b8:
    // 0x1510b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1510B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1510BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1510B8u;
            // 0x1510bc: 0xac850038  sw          $a1, 0x38($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 56), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15109Cu: goto label_15109c;
            case 0x1510A8u: goto label_1510a8;
            case 0x1510B8u: goto label_1510b8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1510C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
