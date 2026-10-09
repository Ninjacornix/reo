#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001398A0
// Address: 0x1398a0 - 0x139928
void sub_001398A0_0x1398a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001398A0_0x1398a0");
#endif

    switch (ctx->pc) {
        case 0x1398c4u: goto label_1398c4;
        case 0x1398e4u: goto label_1398e4;
        case 0x1398ecu: goto label_1398ec;
        case 0x1398f4u: goto label_1398f4;
        case 0x1398fcu: goto label_1398fc;
        case 0x139908u: goto label_139908;
        default: break;
    }

    ctx->pc = 0x1398a0u;

    // 0x1398a0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1398a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1398a4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1398a4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1398a8: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x1398a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x1398ac: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1398acu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1398b0: 0xffb10038  sd          $s1, 0x38($sp)
    ctx->pc = 0x1398b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x1398b4: 0x12000017  beqz        $s0, . + 4 + (0x17 << 2)
    ctx->pc = 0x1398B4u;
    {
        const bool branch_taken_0x1398b4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x1398B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1398B4u;
            // 0x1398b8: 0xffbf0040  sd          $ra, 0x40($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1398b4) {
            ctx->pc = 0x139914u;
            goto label_139914;
        }
    }
    ctx->pc = 0x1398BCu;
    // 0x1398bc: 0xc04ea80  jal         func_13AA00
    ctx->pc = 0x1398BCu;
    SET_GPR_U32(ctx, 31, 0x1398C4u);
    ctx->pc = 0x1398C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1398BCu;
            // 0x1398c0: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13AA00u;
    if (runtime->hasFunction(0x13AA00u)) {
        auto targetFn = runtime->lookupFunction(0x13AA00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1398C4u; }
        if (ctx->pc != 0x1398C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013AA00_0x13aa00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1398C4u; }
        if (ctx->pc != 0x1398C4u) { return; }
    }
    ctx->pc = 0x1398C4u;
label_1398c4:
    // 0x1398c4: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x1398c4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x1398c8: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x1398c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x1398cc: 0x2471d7a0  addiu       $s1, $v1, -0x2860
    ctx->pc = 0x1398ccu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), 4294956960));
    // 0x1398d0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1398d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1398d4: 0x1440000e  bnez        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1398D4u;
    {
        const bool branch_taken_0x1398d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1398D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1398D4u;
            // 0x1398d8: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1398d4) {
            ctx->pc = 0x139910u;
            goto label_139910;
        }
    }
    ctx->pc = 0x1398DCu;
    // 0x1398dc: 0xc04e892  jal         func_13A248
    ctx->pc = 0x1398DCu;
    SET_GPR_U32(ctx, 31, 0x1398E4u);
    ctx->pc = 0x13A248u;
    if (runtime->hasFunction(0x13A248u)) {
        auto targetFn = runtime->lookupFunction(0x13A248u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1398E4u; }
        if (ctx->pc != 0x1398E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013A248_0x13a248(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1398E4u; }
        if (ctx->pc != 0x1398E4u) { return; }
    }
    ctx->pc = 0x1398E4u;
label_1398e4:
    // 0x1398e4: 0xc04e082  jal         func_138208
    ctx->pc = 0x1398E4u;
    SET_GPR_U32(ctx, 31, 0x1398ECu);
    ctx->pc = 0x1398E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1398E4u;
            // 0x1398e8: 0x34048100  ori         $a0, $zero, 0x8100 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33024);
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1398ECu; }
        if (ctx->pc != 0x1398ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1398ECu; }
        if (ctx->pc != 0x1398ECu) { return; }
    }
    ctx->pc = 0x1398ECu;
label_1398ec:
    // 0x1398ec: 0xc04035e  jal         func_100D78
    ctx->pc = 0x1398ECu;
    SET_GPR_U32(ctx, 31, 0x1398F4u);
    ctx->pc = 0x1398F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1398ECu;
            // 0x1398f0: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100D78u;
    if (runtime->hasFunction(0x100D78u)) {
        auto targetFn = runtime->lookupFunction(0x100D78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1398F4u; }
        if (ctx->pc != 0x1398F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00100D78_0x100d78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1398F4u; }
        if (ctx->pc != 0x1398F4u) { return; }
    }
    ctx->pc = 0x1398F4u;
label_1398f4:
    // 0x1398f4: 0xc04e082  jal         func_138208
    ctx->pc = 0x1398F4u;
    SET_GPR_U32(ctx, 31, 0x1398FCu);
    ctx->pc = 0x1398F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1398F4u;
            // 0x1398f8: 0x34048101  ori         $a0, $zero, 0x8101 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33025);
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1398FCu; }
        if (ctx->pc != 0x1398FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1398FCu; }
        if (ctx->pc != 0x1398FCu) { return; }
    }
    ctx->pc = 0x1398FCu;
label_1398fc:
    // 0x1398fc: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1398fcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x139900: 0xc04e58a  jal         func_139628
    ctx->pc = 0x139900u;
    SET_GPR_U32(ctx, 31, 0x139908u);
    ctx->pc = 0x139904u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x139900u;
            // 0x139904: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139628u;
    if (runtime->hasFunction(0x139628u)) {
        auto targetFn = runtime->lookupFunction(0x139628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139908u; }
        if (ctx->pc != 0x139908u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139628_0x139628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x139908u; }
        if (ctx->pc != 0x139908u) { return; }
    }
    ctx->pc = 0x139908u;
label_139908:
    // 0x139908: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x139908u;
    {
        const bool branch_taken_0x139908 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13990Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139908u;
            // 0x13990c: 0xdfb00030  ld          $s0, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x139908) {
            ctx->pc = 0x139918u;
            goto label_139918;
        }
    }
    ctx->pc = 0x139910u;
label_139910:
    // 0x139910: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x139910u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_139914:
    // 0x139914: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x139914u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_139918:
    // 0x139918: 0xdfb10038  ld          $s1, 0x38($sp)
    ctx->pc = 0x139918u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x13991c: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x13991cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x139920: 0x3e00008  jr          $ra
    ctx->pc = 0x139920u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x139924u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x139920u;
            // 0x139924: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1398C4u: goto label_1398c4;
            case 0x1398E4u: goto label_1398e4;
            case 0x1398ECu: goto label_1398ec;
            case 0x1398F4u: goto label_1398f4;
            case 0x1398FCu: goto label_1398fc;
            case 0x139908u: goto label_139908;
            case 0x139910u: goto label_139910;
            case 0x139914u: goto label_139914;
            case 0x139918u: goto label_139918;
            default: break;
        }
        return;
    }
    ctx->pc = 0x139928u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
