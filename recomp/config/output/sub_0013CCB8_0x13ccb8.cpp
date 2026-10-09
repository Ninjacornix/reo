#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013CCB8
// Address: 0x13ccb8 - 0x13cd08
void sub_0013CCB8_0x13ccb8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013CCB8_0x13ccb8");
#endif

    switch (ctx->pc) {
        case 0x13ccd4u: goto label_13ccd4;
        default: break;
    }

    ctx->pc = 0x13ccb8u;

    // 0x13ccb8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13ccb8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13ccbc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13ccbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13ccc0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x13ccc0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ccc4: 0x1200000c  beqz        $s0, . + 4 + (0xC << 2)
    ctx->pc = 0x13CCC4u;
    {
        const bool branch_taken_0x13ccc4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x13CCC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CCC4u;
            // 0x13ccc8: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ccc4) {
            ctx->pc = 0x13CCF8u;
            goto label_13ccf8;
        }
    }
    ctx->pc = 0x13CCCCu;
    // 0x13cccc: 0xc04f3de  jal         func_13CF78
    ctx->pc = 0x13CCCCu;
    SET_GPR_U32(ctx, 31, 0x13CCD4u);
    ctx->pc = 0x13CF78u;
    if (runtime->hasFunction(0x13CF78u)) {
        auto targetFn = runtime->lookupFunction(0x13CF78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13CCD4u; }
        if (ctx->pc != 0x13CCD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013CF78_0x13cf78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13CCD4u; }
        if (ctx->pc != 0x13CCD4u) { return; }
    }
    ctx->pc = 0x13CCD4u;
label_13ccd4:
    // 0x13ccd4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13ccd4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13ccd8: 0xa2000000  sb          $zero, 0x0($s0)
    ctx->pc = 0x13ccd8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x13ccdc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x13ccdcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13cce0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x13cce0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13cce4: 0x24060238  addiu       $a2, $zero, 0x238
    ctx->pc = 0x13cce4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 568));
    // 0x13cce8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13cce8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13ccec: 0x8041f1a  j           func_107C68
    ctx->pc = 0x13CCECu;
    ctx->pc = 0x13CCF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13CCECu;
            // 0x13ccf0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13CCF4u;
    // 0x13ccf4: 0x0  nop
    ctx->pc = 0x13ccf4u;
    // NOP
label_13ccf8:
    // 0x13ccf8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13ccf8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13ccfc: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x13ccfcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13cd00: 0x3e00008  jr          $ra
    ctx->pc = 0x13CD00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13CD04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CD00u;
            // 0x13cd04: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13CCD4u: goto label_13ccd4;
            case 0x13CCF8u: goto label_13ccf8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13CD08u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
