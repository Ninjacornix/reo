#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00163440
// Address: 0x163440 - 0x163480
void sub_00163440_0x163440(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00163440_0x163440");
#endif

    switch (ctx->pc) {
        case 0x163454u: goto label_163454;
        default: break;
    }

    ctx->pc = 0x163440u;

    // 0x163440: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x163440u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x163444: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x163444u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x163448: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x163448u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x16344c: 0xc058d08  jal         func_163420
    ctx->pc = 0x16344Cu;
    SET_GPR_U32(ctx, 31, 0x163454u);
    ctx->pc = 0x163450u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16344Cu;
            // 0x163450: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163420u;
    if (runtime->hasFunction(0x163420u)) {
        auto targetFn = runtime->lookupFunction(0x163420u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163454u; }
        if (ctx->pc != 0x163454u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163420_0x163420(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163454u; }
        if (ctx->pc != 0x163454u) { return; }
    }
    ctx->pc = 0x163454u;
label_163454:
    // 0x163454: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x163454u;
    {
        const bool branch_taken_0x163454 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x163458u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163454u;
            // 0x163458: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x163454) {
            ctx->pc = 0x163470u;
            goto label_163470;
        }
    }
    ctx->pc = 0x16345Cu;
    // 0x16345c: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x16345cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x163460: 0x14640003  bne         $v1, $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x163460u;
    {
        const bool branch_taken_0x163460 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        ctx->pc = 0x163464u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163460u;
            // 0x163464: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x163460) {
            ctx->pc = 0x163470u;
            goto label_163470;
        }
    }
    ctx->pc = 0x163468u;
    // 0x163468: 0x8e020014  lw          $v0, 0x14($s0)
    ctx->pc = 0x163468u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x16346c: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x16346cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
label_163470:
    // 0x163470: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x163470u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x163474: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x163474u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x163478: 0x3e00008  jr          $ra
    ctx->pc = 0x163478u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16347Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163478u;
            // 0x16347c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x163454u: goto label_163454;
            case 0x163470u: goto label_163470;
            default: break;
        }
        return;
    }
    ctx->pc = 0x163480u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
