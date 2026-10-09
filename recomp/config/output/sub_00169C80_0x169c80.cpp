#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00169C80
// Address: 0x169c80 - 0x169cc0
void sub_00169C80_0x169c80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00169C80_0x169c80");
#endif

    switch (ctx->pc) {
        case 0x169cb4u: goto label_169cb4;
        default: break;
    }

    ctx->pc = 0x169c80u;

    // 0x169c80: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x169c80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x169c84: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x169c84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x169c88: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x169c88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x169c8c: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x169C8Cu;
    {
        const bool branch_taken_0x169c8c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x169C90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x169C8Cu;
            // 0x169c90: 0xa0182d  daddu       $v1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x169c8c) {
            ctx->pc = 0x169C98u;
            goto label_169c98;
        }
    }
    ctx->pc = 0x169C94u;
    // 0x169c94: 0xac830008  sw          $v1, 0x8($a0)
    ctx->pc = 0x169c94u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 3));
label_169c98:
    // 0x169c98: 0x10600007  beqz        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x169C98u;
    {
        const bool branch_taken_0x169c98 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x169C9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x169C98u;
            // 0x169c9c: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x169c98) {
            ctx->pc = 0x169CB8u;
            goto label_169cb8;
        }
    }
    ctx->pc = 0x169CA0u;
    // 0x169ca0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x169ca0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x169ca4: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x169CA4u;
    {
        const bool branch_taken_0x169ca4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x169ca4) {
            ctx->pc = 0x169CB8u;
            goto label_169cb8;
        }
    }
    ctx->pc = 0x169CACu;
    // 0x169cac: 0x40f809  jalr        $v0
    ctx->pc = 0x169CACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x169CB4u);
        ctx->pc = 0x169CB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x169CACu;
            // 0x169cb0: 0x8c840004  lw          $a0, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x169CB4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x169C98u: goto label_169c98;
            case 0x169CB4u: goto label_169cb4;
            case 0x169CB8u: goto label_169cb8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x169CB4u; }
            if (ctx->pc != 0x169CB4u) { return; }
        }
        }
    }
    ctx->pc = 0x169CB4u;
label_169cb4:
    // 0x169cb4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x169cb4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_169cb8:
    // 0x169cb8: 0x3e00008  jr          $ra
    ctx->pc = 0x169CB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x169CBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x169CB8u;
            // 0x169cbc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x169C98u: goto label_169c98;
            case 0x169CB4u: goto label_169cb4;
            case 0x169CB8u: goto label_169cb8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x169CC0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
