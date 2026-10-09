#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00180B50
// Address: 0x180b50 - 0x180b84
void sub_00180B50_0x180b50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00180B50_0x180b50");
#endif

    ctx->pc = 0x180b50u;

    // 0x180b50: 0x2c820004  sltiu       $v0, $a0, 0x4
    ctx->pc = 0x180b50u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)4) ? 1 : 0);
    // 0x180b54: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x180B54u;
    {
        const bool branch_taken_0x180b54 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x180B58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180B54u;
            // 0x180b58: 0x3c020024  lui         $v0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x180b54) {
            ctx->pc = 0x180B78u;
            goto label_180b78;
        }
    }
    ctx->pc = 0x180B5Cu;
    // 0x180b5c: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x180b5cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x180b60: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x180b60u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x180b64: 0x2442f9f0  addiu       $v0, $v0, -0x610
    ctx->pc = 0x180b64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294965744));
    // 0x180b68: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x180b68u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x180b6c: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x180b6cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x180b70: 0x8042bf0  j           func_10AFC0
    ctx->pc = 0x180B70u;
    ctx->pc = 0x180B74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x180B70u;
            // 0x180b74: 0x8c650000  lw          $a1, 0x0($v1) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x180B78u;
label_180b78:
    // 0x180b78: 0x904315f8  lbu         $v1, 0x15F8($v0)
    ctx->pc = 0x180b78u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 5624)));
    // 0x180b7c: 0x3e00008  jr          $ra
    ctx->pc = 0x180B7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x180B80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x180B7Cu;
            // 0x180b80: 0xa0a30000  sb          $v1, 0x0($a1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x180B78u: goto label_180b78;
            default: break;
        }
        return;
    }
    ctx->pc = 0x180B84u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
