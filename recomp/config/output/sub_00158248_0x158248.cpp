#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00158248
// Address: 0x158248 - 0x158280
void sub_00158248_0x158248(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00158248_0x158248");
#endif

    switch (ctx->pc) {
        case 0x158270u: goto label_158270;
        default: break;
    }

    ctx->pc = 0x158248u;

    // 0x158248: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x158248u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15824c: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x15824cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x158250: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x158250u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x158254: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x158254u;
    {
        const bool branch_taken_0x158254 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x158258u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158254u;
            // 0x158258: 0xac820008  sw          $v0, 0x8($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158254) {
            ctx->pc = 0x158270u;
            goto label_158270;
        }
    }
    ctx->pc = 0x15825Cu;
    // 0x15825c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x15825cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x158260: 0x50400004  beql        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x158260u;
    {
        const bool branch_taken_0x158260 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x158260) {
            ctx->pc = 0x158264u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x158260u;
            // 0x158264: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x158274u;
            goto label_158274;
        }
    }
    ctx->pc = 0x158268u;
    // 0x158268: 0x40f809  jalr        $v0
    ctx->pc = 0x158268u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x158270u);
        ctx->pc = 0x15826Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158268u;
            // 0x15826c: 0x8c840004  lw          $a0, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x158270u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x158270u: goto label_158270;
            case 0x158274u: goto label_158274;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x158270u; }
            if (ctx->pc != 0x158270u) { return; }
        }
        }
    }
    ctx->pc = 0x158270u;
label_158270:
    // 0x158270: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x158270u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_158274:
    // 0x158274: 0x3e00008  jr          $ra
    ctx->pc = 0x158274u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x158278u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158274u;
            // 0x158278: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x158270u: goto label_158270;
            case 0x158274u: goto label_158274;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15827Cu;
    // 0x15827c: 0x0  nop
    ctx->pc = 0x15827cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
