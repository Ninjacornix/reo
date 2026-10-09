#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001665A0
// Address: 0x1665a0 - 0x1665e8
void sub_001665A0_0x1665a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001665A0_0x1665a0");
#endif

    switch (ctx->pc) {
        case 0x1665b8u: goto label_1665b8;
        case 0x1665d8u: goto label_1665d8;
        default: break;
    }

    ctx->pc = 0x1665a0u;

    // 0x1665a0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1665a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1665a4: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x1665a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1665a8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1665a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1665ac: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1665acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1665b0: 0xc05d58a  jal         func_175628
    ctx->pc = 0x1665B0u;
    SET_GPR_U32(ctx, 31, 0x1665B8u);
    ctx->pc = 0x1665B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1665B0u;
            // 0x1665b4: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1665B8u; }
        if (ctx->pc != 0x1665B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1665B8u; }
        if (ctx->pc != 0x1665B8u) { return; }
    }
    ctx->pc = 0x1665B8u;
label_1665b8:
    // 0x1665b8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1665b8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1665bc: 0x24050003  addiu       $a1, $zero, 0x3
    ctx->pc = 0x1665bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1665c0: 0x24060006  addiu       $a2, $zero, 0x6
    ctx->pc = 0x1665c0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1665c4: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1665c4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1665c8: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1665C8u;
    {
        const bool branch_taken_0x1665c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1665CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1665C8u;
            // 0x1665cc: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1665c8) {
            ctx->pc = 0x1665D8u;
            goto label_1665d8;
        }
    }
    ctx->pc = 0x1665D0u;
    // 0x1665d0: 0xc05def8  jal         func_177BE0
    ctx->pc = 0x1665D0u;
    SET_GPR_U32(ctx, 31, 0x1665D8u);
    ctx->pc = 0x177BE0u;
    if (runtime->hasFunction(0x177BE0u)) {
        auto targetFn = runtime->lookupFunction(0x177BE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1665D8u; }
        if (ctx->pc != 0x1665D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177BE0_0x177be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1665D8u; }
        if (ctx->pc != 0x1665D8u) { return; }
    }
    ctx->pc = 0x1665D8u;
label_1665d8:
    // 0x1665d8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1665d8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1665dc: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1665dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1665e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1665E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1665E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1665E0u;
            // 0x1665e4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1665B8u: goto label_1665b8;
            case 0x1665D8u: goto label_1665d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1665E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
