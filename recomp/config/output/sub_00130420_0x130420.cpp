#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00130420
// Address: 0x130420 - 0x130478
void sub_00130420_0x130420(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00130420_0x130420");
#endif

    switch (ctx->pc) {
        case 0x13043cu: goto label_13043c;
        case 0x130444u: goto label_130444;
        default: break;
    }

    ctx->pc = 0x130420u;

    // 0x130420: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x130420u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x130424: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x130424u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x130428: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x130428u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13042c: 0x1200000e  beqz        $s0, . + 4 + (0xE << 2)
    ctx->pc = 0x13042Cu;
    {
        const bool branch_taken_0x13042c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x130430u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13042Cu;
            // 0x130430: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13042c) {
            ctx->pc = 0x130468u;
            goto label_130468;
        }
    }
    ctx->pc = 0x130434u;
    // 0x130434: 0xc04c1d2  jal         func_130748
    ctx->pc = 0x130434u;
    SET_GPR_U32(ctx, 31, 0x13043Cu);
    ctx->pc = 0x130748u;
    if (runtime->hasFunction(0x130748u)) {
        auto targetFn = runtime->lookupFunction(0x130748u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13043Cu; }
        if (ctx->pc != 0x13043Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130748_0x130748(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13043Cu; }
        if (ctx->pc != 0x13043Cu) { return; }
    }
    ctx->pc = 0x13043Cu;
label_13043c:
    // 0x13043c: 0xc04c158  jal         func_130560
    ctx->pc = 0x13043Cu;
    SET_GPR_U32(ctx, 31, 0x130444u);
    ctx->pc = 0x130440u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13043Cu;
            // 0x130440: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130560u;
    if (runtime->hasFunction(0x130560u)) {
        auto targetFn = runtime->lookupFunction(0x130560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130444u; }
        if (ctx->pc != 0x130444u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130560_0x130560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130444u; }
        if (ctx->pc != 0x130444u) { return; }
    }
    ctx->pc = 0x130444u;
label_130444:
    // 0x130444: 0xa2000000  sb          $zero, 0x0($s0)
    ctx->pc = 0x130444u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x130448: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x130448u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13044c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13044cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x130450: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x130450u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x130454: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x130454u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130458: 0x2406005c  addiu       $a2, $zero, 0x5C
    ctx->pc = 0x130458u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 92));
    // 0x13045c: 0x8041f1a  j           func_107C68
    ctx->pc = 0x13045Cu;
    ctx->pc = 0x130460u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13045Cu;
            // 0x130460: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x130464u;
    // 0x130464: 0x0  nop
    ctx->pc = 0x130464u;
    // NOP
label_130468:
    // 0x130468: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x130468u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13046c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x13046cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x130470: 0x3e00008  jr          $ra
    ctx->pc = 0x130470u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130474u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130470u;
            // 0x130474: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13043Cu: goto label_13043c;
            case 0x130444u: goto label_130444;
            case 0x130468u: goto label_130468;
            default: break;
        }
        return;
    }
    ctx->pc = 0x130478u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
