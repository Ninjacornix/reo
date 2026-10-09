#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012DA88
// Address: 0x12da88 - 0x12dabc
void sub_0012DA88_0x12da88(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012DA88_0x12da88");
#endif

    switch (ctx->pc) {
        case 0x12daacu: goto label_12daac;
        default: break;
    }

    ctx->pc = 0x12da88u;

    // 0x12da88: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x12da88u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x12da8c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12da8cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12da90: 0x8c43874c  lw          $v1, -0x78B4($v0)
    ctx->pc = 0x12da90u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294936396)));
    // 0x12da94: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x12da94u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12da98: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x12DA98u;
    {
        const bool branch_taken_0x12da98 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x12DA9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12DA98u;
            // 0x12da9c: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12da98) {
            ctx->pc = 0x12DAACu;
            goto label_12daac;
        }
    }
    ctx->pc = 0x12DAA0u;
    // 0x12daa0: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x12daa0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x12daa4: 0x60f809  jalr        $v1
    ctx->pc = 0x12DAA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x12DAACu);
        ctx->pc = 0x12DAA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12DAA4u;
            // 0x12daa8: 0x8c448750  lw          $a0, -0x78B0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294936400)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12DAACu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12DAACu: goto label_12daac;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12DAACu; }
            if (ctx->pc != 0x12DAACu) { return; }
        }
        }
    }
    ctx->pc = 0x12DAACu;
label_12daac:
    // 0x12daac: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12daacu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12dab0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x12dab0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12dab4: 0x3e00008  jr          $ra
    ctx->pc = 0x12DAB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12DAB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12DAB4u;
            // 0x12dab8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12DAACu: goto label_12daac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12DABCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
