#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F3694
// Address: 0x1f3694 - 0x1f3754
void sub_001F3694_0x1f3694(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F3694_0x1f3694");
#endif

    switch (ctx->pc) {
        case 0x1f36bcu: goto label_1f36bc;
        case 0x1f36dcu: goto label_1f36dc;
        case 0x1f36fcu: goto label_1f36fc;
        case 0x1f370cu: goto label_1f370c;
        case 0x1f3720u: goto label_1f3720;
        case 0x1f3734u: goto label_1f3734;
        default: break;
    }

    ctx->pc = 0x1f3694u;

    // 0x1f3694: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1f3694u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1f3698: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x1f3698u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1f369c: 0xffbe0018  sd          $fp, 0x18($sp)
    ctx->pc = 0x1f369cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 30));
    // 0x1f36a0: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1f36a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1f36a4: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f36a4u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f36a8: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f36a8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f36ac: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1f36acu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1f36b0: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1f36b0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f36b4: 0xc07c6b6  jal         func_1F1AD8
    ctx->pc = 0x1F36B4u;
    SET_GPR_U32(ctx, 31, 0x1F36BCu);
    ctx->pc = 0x1F1AD8u;
    if (runtime->hasFunction(0x1F1AD8u)) {
        auto targetFn = runtime->lookupFunction(0x1F1AD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F36BCu; }
        if (ctx->pc != 0x1F36BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1AD8_0x1f1ad8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F36BCu; }
        if (ctx->pc != 0x1F36BCu) { return; }
    }
    ctx->pc = 0x1F36BCu;
label_1f36bc:
    // 0x1f36bc: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1f36bcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1f36c0: 0x97c20008  lhu         $v0, 0x8($fp)
    ctx->pc = 0x1f36c0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f36c4: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1f36c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1f36c8: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1f36c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1f36cc: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f36ccu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f36d0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1f36d0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f36d4: 0xc07cc64  jal         func_1F3190
    ctx->pc = 0x1F36D4u;
    SET_GPR_U32(ctx, 31, 0x1F36DCu);
    ctx->pc = 0x1F3190u;
    if (runtime->hasFunction(0x1F3190u)) {
        auto targetFn = runtime->lookupFunction(0x1F3190u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F36DCu; }
        if (ctx->pc != 0x1F36DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F3190_0x1f3190(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F36DCu; }
        if (ctx->pc != 0x1F36DCu) { return; }
    }
    ctx->pc = 0x1F36DCu;
label_1f36dc:
    // 0x1f36dc: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F36DCu;
    {
        const bool branch_taken_0x1f36dc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f36dc) {
            ctx->pc = 0x1F36F0u;
            goto label_1f36f0;
        }
    }
    ctx->pc = 0x1F36E4u;
    // 0x1f36e4: 0x2402e0c2  addiu       $v0, $zero, -0x1F3E
    ctx->pc = 0x1f36e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294959298));
    // 0x1f36e8: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x1F36E8u;
    {
        const bool branch_taken_0x1f36e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f36e8) {
            ctx->pc = 0x1F3738u;
            goto label_1f3738;
        }
    }
    ctx->pc = 0x1F36F0u;
label_1f36f0:
    // 0x1f36f0: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f36f0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f36f4: 0xc07cc13  jal         func_1F304C
    ctx->pc = 0x1F36F4u;
    SET_GPR_U32(ctx, 31, 0x1F36FCu);
    ctx->pc = 0x1F304Cu;
    if (runtime->hasFunction(0x1F304Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F304Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F36FCu; }
        if (ctx->pc != 0x1F36FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F304C_0x1f304c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F36FCu; }
        if (ctx->pc != 0x1F36FCu) { return; }
    }
    ctx->pc = 0x1F36FCu;
label_1f36fc:
    // 0x1f36fc: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1f36fcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3700: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1f3700u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f3704: 0xc07cd3b  jal         func_1F34EC
    ctx->pc = 0x1F3704u;
    SET_GPR_U32(ctx, 31, 0x1F370Cu);
    ctx->pc = 0x1F34ECu;
    if (runtime->hasFunction(0x1F34ECu)) {
        auto targetFn = runtime->lookupFunction(0x1F34ECu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F370Cu; }
        if (ctx->pc != 0x1F370Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F34EC_0x1f34ec(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F370Cu; }
        if (ctx->pc != 0x1F370Cu) { return; }
    }
    ctx->pc = 0x1F370Cu;
label_1f370c:
    // 0x1f370c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1f370cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3710: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1f3710u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3714: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1f3714u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f3718: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F3718u;
    SET_GPR_U32(ctx, 31, 0x1F3720u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3720u; }
        if (ctx->pc != 0x1F3720u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3720u; }
        if (ctx->pc != 0x1F3720u) { return; }
    }
    ctx->pc = 0x1F3720u;
label_1f3720:
    // 0x1f3720: 0x97c20008  lhu         $v0, 0x8($fp)
    ctx->pc = 0x1f3720u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f3724: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f3724u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f3728: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1f3728u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f372c: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1F372Cu;
    SET_GPR_U32(ctx, 31, 0x1F3734u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3734u; }
        if (ctx->pc != 0x1F3734u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3734u; }
        if (ctx->pc != 0x1F3734u) { return; }
    }
    ctx->pc = 0x1F3734u;
label_1f3734:
    // 0x1f3734: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f3734u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1f3738:
    // 0x1f3738: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f3738u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f373c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1f373cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f3740: 0xdfbe0018  ld          $fp, 0x18($sp)
    ctx->pc = 0x1f3740u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1f3744: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1f3744u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1f3748: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1f3748u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1f374c: 0x3e00008  jr          $ra
    ctx->pc = 0x1F374Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F36BCu: goto label_1f36bc;
            case 0x1F36DCu: goto label_1f36dc;
            case 0x1F36F0u: goto label_1f36f0;
            case 0x1F36FCu: goto label_1f36fc;
            case 0x1F370Cu: goto label_1f370c;
            case 0x1F3720u: goto label_1f3720;
            case 0x1F3734u: goto label_1f3734;
            case 0x1F3738u: goto label_1f3738;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F3754u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
