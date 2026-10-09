#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00136578
// Address: 0x136578 - 0x136688
void sub_00136578_0x136578(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00136578_0x136578");
#endif

    switch (ctx->pc) {
        case 0x1365acu: goto label_1365ac;
        case 0x1365c0u: goto label_1365c0;
        case 0x1365d8u: goto label_1365d8;
        case 0x1365e8u: goto label_1365e8;
        case 0x136620u: goto label_136620;
        case 0x136644u: goto label_136644;
        default: break;
    }

    ctx->pc = 0x136578u;

    // 0x136578: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x136578u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x13657c: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x13657cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x136580: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x136580u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136584: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x136584u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x136588: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x136588u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13658c: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x13658cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x136590: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x136590u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x136594: 0xffb50048  sd          $s5, 0x48($sp)
    ctx->pc = 0x136594u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 21));
    // 0x136598: 0xffb60050  sd          $s6, 0x50($sp)
    ctx->pc = 0x136598u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 22));
    // 0x13659c: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x13659cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x1365a0: 0xffbf0058  sd          $ra, 0x58($sp)
    ctx->pc = 0x1365a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x1365a4: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1365A4u;
    SET_GPR_U32(ctx, 31, 0x1365ACu);
    ctx->pc = 0x1365A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1365A4u;
            // 0x1365a8: 0xa02d  daddu       $s4, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1365ACu; }
        if (ctx->pc != 0x1365ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1365ACu; }
        if (ctx->pc != 0x1365ACu) { return; }
    }
    ctx->pc = 0x1365ACu;
label_1365ac:
    // 0x1365ac: 0x40a82d  daddu       $s5, $v0, $zero
    ctx->pc = 0x1365acu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1365b0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1365b0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1365b4: 0x2453206c  addiu       $s3, $v0, 0x206C
    ctx->pc = 0x1365b4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 2), 8300));
    // 0x1365b8: 0x2676fffc  addiu       $s6, $s3, -0x4
    ctx->pc = 0x1365b8u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967292));
    // 0x1365bc: 0x118100  sll         $s0, $s1, 4
    ctx->pc = 0x1365bcu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 17), 4));
label_1365c0:
    // 0x1365c0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1365c0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1365c4: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1365c4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1365c8: 0x2132821  addu        $a1, $s0, $s3
    ctx->pc = 0x1365c8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 19)));
    // 0x1365cc: 0x2a0302d  daddu       $a2, $s5, $zero
    ctx->pc = 0x1365ccu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1365d0: 0xc042d10  jal         func_10B440
    ctx->pc = 0x1365D0u;
    SET_GPR_U32(ctx, 31, 0x1365D8u);
    ctx->pc = 0x1365D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1365D0u;
            // 0x1365d4: 0x2168021  addu        $s0, $s0, $s6 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 22)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B440u;
    if (runtime->hasFunction(0x10B440u)) {
        auto targetFn = runtime->lookupFunction(0x10B440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1365D8u; }
        if (ctx->pc != 0x1365D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B440_0x10b440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1365D8u; }
        if (ctx->pc != 0x1365D8u) { return; }
    }
    ctx->pc = 0x1365D8u;
label_1365d8:
    // 0x1365d8: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1365D8u;
    {
        const bool branch_taken_0x1365d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1365DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1365D8u;
            // 0x1365dc: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1365d8) {
            ctx->pc = 0x136650u;
            goto label_136650;
        }
    }
    ctx->pc = 0x1365E0u;
    // 0x1365e0: 0xc04dbe6  jal         func_136F98
    ctx->pc = 0x1365E0u;
    SET_GPR_U32(ctx, 31, 0x1365E8u);
    ctx->pc = 0x1365E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1365E0u;
            // 0x1365e4: 0x8e100000  lw          $s0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x136F98u;
    if (runtime->hasFunction(0x136F98u)) {
        auto targetFn = runtime->lookupFunction(0x136F98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1365E8u; }
        if (ctx->pc != 0x1365E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00136F98_0x136f98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1365E8u; }
        if (ctx->pc != 0x1365E8u) { return; }
    }
    ctx->pc = 0x1365E8u;
label_1365e8:
    // 0x1365e8: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1365E8u;
    {
        const bool branch_taken_0x1365e8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1365e8) {
            ctx->pc = 0x136628u;
            goto label_136628;
        }
    }
    ctx->pc = 0x1365F0u;
    // 0x1365f0: 0x12000018  beqz        $s0, . + 4 + (0x18 << 2)
    ctx->pc = 0x1365F0u;
    {
        const bool branch_taken_0x1365f0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x1365F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1365F0u;
            // 0x1365f4: 0x2a220020  slti        $v0, $s1, 0x20 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)32) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1365f0) {
            ctx->pc = 0x136654u;
            goto label_136654;
        }
    }
    ctx->pc = 0x1365F8u;
    // 0x1365f8: 0x8e020060  lw          $v0, 0x60($s0)
    ctx->pc = 0x1365f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 96)));
    // 0x1365fc: 0x10400015  beqz        $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x1365FCu;
    {
        const bool branch_taken_0x1365fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x136600u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1365FCu;
            // 0x136600: 0x2a220020  slti        $v0, $s1, 0x20 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)32) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1365fc) {
            ctx->pc = 0x136654u;
            goto label_136654;
        }
    }
    ctx->pc = 0x136604u;
    // 0x136604: 0xafb20004  sw          $s2, 0x4($sp)
    ctx->pc = 0x136604u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 18));
    // 0x136608: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x136608u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13660c: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x13660cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x136610: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x136610u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136614: 0x8e020060  lw          $v0, 0x60($s0)
    ctx->pc = 0x136614u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 96)));
    // 0x136618: 0x40f809  jalr        $v0
    ctx->pc = 0x136618u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x136620u);
        ctx->pc = 0x13661Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136618u;
            // 0x13661c: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x136620u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1365ACu: goto label_1365ac;
            case 0x1365C0u: goto label_1365c0;
            case 0x1365D8u: goto label_1365d8;
            case 0x1365E8u: goto label_1365e8;
            case 0x136620u: goto label_136620;
            case 0x136628u: goto label_136628;
            case 0x136644u: goto label_136644;
            case 0x136650u: goto label_136650;
            case 0x136654u: goto label_136654;
            case 0x13665Cu: goto label_13665c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136620u; }
            if (ctx->pc != 0x136620u) { return; }
        }
        }
    }
    ctx->pc = 0x136620u;
label_136620:
    // 0x136620: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x136620u;
    {
        const bool branch_taken_0x136620 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136624u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136620u;
            // 0x136624: 0x40a02d  daddu       $s4, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136620) {
            ctx->pc = 0x13665Cu;
            goto label_13665c;
        }
    }
    ctx->pc = 0x136628u;
label_136628:
    // 0x136628: 0x1200000a  beqz        $s0, . + 4 + (0xA << 2)
    ctx->pc = 0x136628u;
    {
        const bool branch_taken_0x136628 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x13662Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136628u;
            // 0x13662c: 0x2a220020  slti        $v0, $s1, 0x20 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)32) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x136628) {
            ctx->pc = 0x136654u;
            goto label_136654;
        }
    }
    ctx->pc = 0x136630u;
    // 0x136630: 0x8e100044  lw          $s0, 0x44($s0)
    ctx->pc = 0x136630u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x136634: 0x12000007  beqz        $s0, . + 4 + (0x7 << 2)
    ctx->pc = 0x136634u;
    {
        const bool branch_taken_0x136634 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x136634) {
            ctx->pc = 0x136654u;
            goto label_136654;
        }
    }
    ctx->pc = 0x13663Cu;
    // 0x13663c: 0x200f809  jalr        $s0
    ctx->pc = 0x13663Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 16);
        SET_GPR_U32(ctx, 31, 0x136644u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x136644u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1365ACu: goto label_1365ac;
            case 0x1365C0u: goto label_1365c0;
            case 0x1365D8u: goto label_1365d8;
            case 0x1365E8u: goto label_1365e8;
            case 0x136620u: goto label_136620;
            case 0x136628u: goto label_136628;
            case 0x136644u: goto label_136644;
            case 0x136650u: goto label_136650;
            case 0x136654u: goto label_136654;
            case 0x13665Cu: goto label_13665c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136644u; }
            if (ctx->pc != 0x136644u) { return; }
        }
        }
    }
    ctx->pc = 0x136644u;
label_136644:
    // 0x136644: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x136644u;
    {
        const bool branch_taken_0x136644 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136648u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136644u;
            // 0x136648: 0x40a02d  daddu       $s4, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136644) {
            ctx->pc = 0x13665Cu;
            goto label_13665c;
        }
    }
    ctx->pc = 0x13664Cu;
    // 0x13664c: 0x0  nop
    ctx->pc = 0x13664cu;
    // NOP
label_136650:
    // 0x136650: 0x2a220020  slti        $v0, $s1, 0x20
    ctx->pc = 0x136650u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)32) ? 1 : 0);
label_136654:
    // 0x136654: 0x1440ffda  bnez        $v0, . + 4 + (-0x26 << 2)
    ctx->pc = 0x136654u;
    {
        const bool branch_taken_0x136654 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x136658u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136654u;
            // 0x136658: 0x118100  sll         $s0, $s1, 4 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 17), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136654) {
            ctx->pc = 0x1365C0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1365c0;
        }
    }
    ctx->pc = 0x13665Cu;
label_13665c:
    // 0x13665c: 0x280102d  daddu       $v0, $s4, $zero
    ctx->pc = 0x13665cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136660: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x136660u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x136664: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x136664u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x136668: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x136668u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x13666c: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x13666cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x136670: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x136670u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x136674: 0xdfb50048  ld          $s5, 0x48($sp)
    ctx->pc = 0x136674u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x136678: 0xdfb60050  ld          $s6, 0x50($sp)
    ctx->pc = 0x136678u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x13667c: 0xdfbf0058  ld          $ra, 0x58($sp)
    ctx->pc = 0x13667cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x136680: 0x3e00008  jr          $ra
    ctx->pc = 0x136680u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136684u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136680u;
            // 0x136684: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1365ACu: goto label_1365ac;
            case 0x1365C0u: goto label_1365c0;
            case 0x1365D8u: goto label_1365d8;
            case 0x1365E8u: goto label_1365e8;
            case 0x136620u: goto label_136620;
            case 0x136628u: goto label_136628;
            case 0x136644u: goto label_136644;
            case 0x136650u: goto label_136650;
            case 0x136654u: goto label_136654;
            case 0x13665Cu: goto label_13665c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136688u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
