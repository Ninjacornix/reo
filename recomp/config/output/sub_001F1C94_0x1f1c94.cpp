#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F1C94
// Address: 0x1f1c94 - 0x1f1d00
void sub_001F1C94_0x1f1c94(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F1C94_0x1f1c94");
#endif

    switch (ctx->pc) {
        case 0x1f1cdcu: goto label_1f1cdc;
        default: break;
    }

    ctx->pc = 0x1f1c94u;

    // 0x1f1c94: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f1c94u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f1c98: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1f1c98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1f1c9c: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1f1c9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1f1ca0: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f1ca0u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1ca4: 0xafc40004  sw          $a0, 0x4($fp)
    ctx->pc = 0x1f1ca4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 4));
    // 0x1f1ca8: 0xafc00000  sw          $zero, 0x0($fp)
    ctx->pc = 0x1f1ca8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 0));
    // 0x1f1cac: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1f1cacu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f1cb0: 0x8c620008  lw          $v0, 0x8($v1)
    ctx->pc = 0x1f1cb0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x1f1cb4: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1F1CB4u;
    {
        const bool branch_taken_0x1f1cb4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1cb4) {
            ctx->pc = 0x1F1CE0u;
            goto label_1f1ce0;
        }
    }
    ctx->pc = 0x1F1CBCu;
    // 0x1f1cbc: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1f1cbcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f1cc0: 0x24820010  addiu       $v0, $a0, 0x10
    ctx->pc = 0x1f1cc0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 16));
    // 0x1f1cc4: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1f1cc4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f1cc8: 0x8c830008  lw          $v1, 0x8($a0)
    ctx->pc = 0x1f1cc8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1f1ccc: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f1cccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1cd0: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1f1cd0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f1cd4: 0x60f809  jalr        $v1
    ctx->pc = 0x1F1CD4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x1F1CDCu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1F1CDCu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F1CDCu: goto label_1f1cdc;
            case 0x1F1CE0u: goto label_1f1ce0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1F1CDCu; }
            if (ctx->pc != 0x1F1CDCu) { return; }
        }
        }
    }
    ctx->pc = 0x1F1CDCu;
label_1f1cdc:
    // 0x1f1cdc: 0xafc20000  sw          $v0, 0x0($fp)
    ctx->pc = 0x1f1cdcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 2));
label_1f1ce0:
    // 0x1f1ce0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f1ce0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f1ce4: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f1ce4u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1ce8: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1f1ce8u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f1cec: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1f1cecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1f1cf0: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1f1cf0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1f1cf4: 0x3e00008  jr          $ra
    ctx->pc = 0x1F1CF4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F1CDCu: goto label_1f1cdc;
            case 0x1F1CE0u: goto label_1f1ce0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F1CFCu;
    // 0x1f1cfc: 0x0  nop
    ctx->pc = 0x1f1cfcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
