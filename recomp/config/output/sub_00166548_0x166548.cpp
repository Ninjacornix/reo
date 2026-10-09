#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00166548
// Address: 0x166548 - 0x166710
void sub_00166548_0x166548(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00166548_0x166548");
#endif

    switch (ctx->pc) {
        case 0x166570u: goto label_166570;
        case 0x166590u: goto label_166590;
        case 0x1665b8u: goto label_1665b8;
        case 0x1665d8u: goto label_1665d8;
        case 0x166600u: goto label_166600;
        case 0x166620u: goto label_166620;
        case 0x166650u: goto label_166650;
        case 0x166670u: goto label_166670;
        default: break;
    }

    ctx->pc = 0x166548u;

    // 0x166548: 0x3e00008  jr          $ra
    ctx->pc = 0x166548u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x166570u: goto label_166570;
            case 0x166590u: goto label_166590;
            case 0x1665B8u: goto label_1665b8;
            case 0x1665D8u: goto label_1665d8;
            case 0x166600u: goto label_166600;
            case 0x166620u: goto label_166620;
            case 0x166650u: goto label_166650;
            case 0x166670u: goto label_166670;
            default: break;
        }
        return;
    }
    ctx->pc = 0x166550u;
    // 0x166550: 0x3e00008  jr          $ra
    ctx->pc = 0x166550u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x166554u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166550u;
            // 0x166554: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x166570u: goto label_166570;
            case 0x166590u: goto label_166590;
            case 0x1665B8u: goto label_1665b8;
            case 0x1665D8u: goto label_1665d8;
            case 0x166600u: goto label_166600;
            case 0x166620u: goto label_166620;
            case 0x166650u: goto label_166650;
            case 0x166670u: goto label_166670;
            default: break;
        }
        return;
    }
    ctx->pc = 0x166558u;
    // 0x166558: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x166558u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16655c: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x16655cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x166560: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x166560u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x166564: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x166564u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x166568: 0xc05d58a  jal         func_175628
    ctx->pc = 0x166568u;
    SET_GPR_U32(ctx, 31, 0x166570u);
    ctx->pc = 0x16656Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166568u;
            // 0x16656c: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166570u; }
        if (ctx->pc != 0x166570u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166570u; }
        if (ctx->pc != 0x166570u) { return; }
    }
    ctx->pc = 0x166570u;
label_166570:
    // 0x166570: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x166570u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166574: 0x24050003  addiu       $a1, $zero, 0x3
    ctx->pc = 0x166574u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x166578: 0x24060005  addiu       $a2, $zero, 0x5
    ctx->pc = 0x166578u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x16657c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x16657cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166580: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x166580u;
    {
        const bool branch_taken_0x166580 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x166584u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166580u;
            // 0x166584: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x166580) {
            ctx->pc = 0x166590u;
            goto label_166590;
        }
    }
    ctx->pc = 0x166588u;
    // 0x166588: 0xc05def8  jal         func_177BE0
    ctx->pc = 0x166588u;
    SET_GPR_U32(ctx, 31, 0x166590u);
    ctx->pc = 0x177BE0u;
    if (runtime->hasFunction(0x177BE0u)) {
        auto targetFn = runtime->lookupFunction(0x177BE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166590u; }
        if (ctx->pc != 0x166590u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177BE0_0x177be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166590u; }
        if (ctx->pc != 0x166590u) { return; }
    }
    ctx->pc = 0x166590u;
label_166590:
    // 0x166590: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x166590u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x166594: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x166594u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x166598: 0x3e00008  jr          $ra
    ctx->pc = 0x166598u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16659Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166598u;
            // 0x16659c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x166570u: goto label_166570;
            case 0x166590u: goto label_166590;
            case 0x1665B8u: goto label_1665b8;
            case 0x1665D8u: goto label_1665d8;
            case 0x166600u: goto label_166600;
            case 0x166620u: goto label_166620;
            case 0x166650u: goto label_166650;
            case 0x166670u: goto label_166670;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1665A0u;
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
            case 0x166570u: goto label_166570;
            case 0x166590u: goto label_166590;
            case 0x1665B8u: goto label_1665b8;
            case 0x1665D8u: goto label_1665d8;
            case 0x166600u: goto label_166600;
            case 0x166620u: goto label_166620;
            case 0x166650u: goto label_166650;
            case 0x166670u: goto label_166670;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1665E8u;
    // 0x1665e8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1665e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1665ec: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x1665ecu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1665f0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1665f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1665f4: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1665f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1665f8: 0xc05d58a  jal         func_175628
    ctx->pc = 0x1665F8u;
    SET_GPR_U32(ctx, 31, 0x166600u);
    ctx->pc = 0x1665FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1665F8u;
            // 0x1665fc: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166600u; }
        if (ctx->pc != 0x166600u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166600u; }
        if (ctx->pc != 0x166600u) { return; }
    }
    ctx->pc = 0x166600u;
label_166600:
    // 0x166600: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x166600u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166604: 0x24050003  addiu       $a1, $zero, 0x3
    ctx->pc = 0x166604u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x166608: 0x24060007  addiu       $a2, $zero, 0x7
    ctx->pc = 0x166608u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x16660c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x16660cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166610: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x166610u;
    {
        const bool branch_taken_0x166610 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x166614u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166610u;
            // 0x166614: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x166610) {
            ctx->pc = 0x166620u;
            goto label_166620;
        }
    }
    ctx->pc = 0x166618u;
    // 0x166618: 0xc05def8  jal         func_177BE0
    ctx->pc = 0x166618u;
    SET_GPR_U32(ctx, 31, 0x166620u);
    ctx->pc = 0x177BE0u;
    if (runtime->hasFunction(0x177BE0u)) {
        auto targetFn = runtime->lookupFunction(0x177BE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166620u; }
        if (ctx->pc != 0x166620u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177BE0_0x177be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166620u; }
        if (ctx->pc != 0x166620u) { return; }
    }
    ctx->pc = 0x166620u;
label_166620:
    // 0x166620: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x166620u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x166624: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x166624u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x166628: 0x3e00008  jr          $ra
    ctx->pc = 0x166628u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16662Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166628u;
            // 0x16662c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x166570u: goto label_166570;
            case 0x166590u: goto label_166590;
            case 0x1665B8u: goto label_1665b8;
            case 0x1665D8u: goto label_1665d8;
            case 0x166600u: goto label_166600;
            case 0x166620u: goto label_166620;
            case 0x166650u: goto label_166650;
            case 0x166670u: goto label_166670;
            default: break;
        }
        return;
    }
    ctx->pc = 0x166630u;
    // 0x166630: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x166630u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x166634: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x166634u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x166638: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x166638u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16663c: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x16663cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x166640: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x166640u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x166644: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x166644u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x166648: 0xc05d58a  jal         func_175628
    ctx->pc = 0x166648u;
    SET_GPR_U32(ctx, 31, 0x166650u);
    ctx->pc = 0x16664Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166648u;
            // 0x16664c: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166650u; }
        if (ctx->pc != 0x166650u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166650u; }
        if (ctx->pc != 0x166650u) { return; }
    }
    ctx->pc = 0x166650u;
label_166650:
    // 0x166650: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x166650u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166654: 0x220382d  daddu       $a3, $s1, $zero
    ctx->pc = 0x166654u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166658: 0x24050003  addiu       $a1, $zero, 0x3
    ctx->pc = 0x166658u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x16665c: 0x24060008  addiu       $a2, $zero, 0x8
    ctx->pc = 0x16665cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x166660: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x166660u;
    {
        const bool branch_taken_0x166660 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x166664u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166660u;
            // 0x166664: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x166660) {
            ctx->pc = 0x166670u;
            goto label_166670;
        }
    }
    ctx->pc = 0x166668u;
    // 0x166668: 0xc05def8  jal         func_177BE0
    ctx->pc = 0x166668u;
    SET_GPR_U32(ctx, 31, 0x166670u);
    ctx->pc = 0x177BE0u;
    if (runtime->hasFunction(0x177BE0u)) {
        auto targetFn = runtime->lookupFunction(0x177BE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166670u; }
        if (ctx->pc != 0x166670u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177BE0_0x177be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166670u; }
        if (ctx->pc != 0x166670u) { return; }
    }
    ctx->pc = 0x166670u;
label_166670:
    // 0x166670: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x166670u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x166674: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x166674u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x166678: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x166678u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16667c: 0x3e00008  jr          $ra
    ctx->pc = 0x16667Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x166680u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16667Cu;
            // 0x166680: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x166570u: goto label_166570;
            case 0x166590u: goto label_166590;
            case 0x1665B8u: goto label_1665b8;
            case 0x1665D8u: goto label_1665d8;
            case 0x166600u: goto label_166600;
            case 0x166620u: goto label_166620;
            case 0x166650u: goto label_166650;
            case 0x166670u: goto label_166670;
            default: break;
        }
        return;
    }
    ctx->pc = 0x166684u;
    // 0x166684: 0x0  nop
    ctx->pc = 0x166684u;
    // NOP
    // 0x166688: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x166688u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16668c: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16668cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x166690: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x166690u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x166694: 0x34a50a01  ori         $a1, $a1, 0xA01
    ctx->pc = 0x166694u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)2561);
    // 0x166698: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x166698u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16669c: 0x805a704  j           func_169C10
    ctx->pc = 0x16669Cu;
    ctx->pc = 0x1666A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16669Cu;
            // 0x1666a0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1666A4u;
    // 0x1666a4: 0x0  nop
    ctx->pc = 0x1666a4u;
    // NOP
    // 0x1666a8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1666a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1666ac: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1666acu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1666b0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1666b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1666b4: 0x34a50a01  ori         $a1, $a1, 0xA01
    ctx->pc = 0x1666b4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)2561);
    // 0x1666b8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1666b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1666bc: 0x805a704  j           func_169C10
    ctx->pc = 0x1666BCu;
    ctx->pc = 0x1666C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1666BCu;
            // 0x1666c0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1666C4u;
    // 0x1666c4: 0x0  nop
    ctx->pc = 0x1666c4u;
    // NOP
    // 0x1666c8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1666c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1666cc: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1666ccu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1666d0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1666d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1666d4: 0x34a50a01  ori         $a1, $a1, 0xA01
    ctx->pc = 0x1666d4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)2561);
    // 0x1666d8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1666d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1666dc: 0x805a704  j           func_169C10
    ctx->pc = 0x1666DCu;
    ctx->pc = 0x1666E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1666DCu;
            // 0x1666e0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1666E4u;
    // 0x1666e4: 0x0  nop
    ctx->pc = 0x1666e4u;
    // NOP
    // 0x1666e8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1666e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1666ec: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1666ecu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1666f0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1666f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1666f4: 0x34a50a01  ori         $a1, $a1, 0xA01
    ctx->pc = 0x1666f4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)2561);
    // 0x1666f8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1666f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1666fc: 0x805a704  j           func_169C10
    ctx->pc = 0x1666FCu;
    ctx->pc = 0x166700u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1666FCu;
            // 0x166700: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x166704u;
    // 0x166704: 0x0  nop
    ctx->pc = 0x166704u;
    // NOP
    // 0x166708: 0x3e00008  jr          $ra
    ctx->pc = 0x166708u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16670Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166708u;
            // 0x16670c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x166570u: goto label_166570;
            case 0x166590u: goto label_166590;
            case 0x1665B8u: goto label_1665b8;
            case 0x1665D8u: goto label_1665d8;
            case 0x166600u: goto label_166600;
            case 0x166620u: goto label_166620;
            case 0x166650u: goto label_166650;
            case 0x166670u: goto label_166670;
            default: break;
        }
        return;
    }
    ctx->pc = 0x166710u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
