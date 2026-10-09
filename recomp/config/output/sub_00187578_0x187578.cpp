#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00187578
// Address: 0x187578 - 0x1876c8
void sub_00187578_0x187578(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00187578_0x187578");
#endif

    switch (ctx->pc) {
        case 0x1875f0u: goto label_1875f0;
        case 0x187614u: goto label_187614;
        case 0x187640u: goto label_187640;
        default: break;
    }

    ctx->pc = 0x187578u;

    // 0x187578: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x187578u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x18757c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x18757cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x187580: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x187580u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187584: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x187584u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x187588: 0x24120001  addiu       $s2, $zero, 0x1
    ctx->pc = 0x187588u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18758c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x18758cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x187590: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x187590u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x187594: 0xa0a02d  daddu       $s4, $a1, $zero
    ctx->pc = 0x187594u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187598: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x187598u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x18759c: 0x3c050029  lui         $a1, 0x29
    ctx->pc = 0x18759cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)41 << 16));
    // 0x1875a0: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x1875a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x1875a4: 0xb02d  daddu       $s6, $zero, $zero
    ctx->pc = 0x1875a4u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1875a8: 0xffbe0040  sd          $fp, 0x40($sp)
    ctx->pc = 0x1875a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 30));
    // 0x1875ac: 0x80f02d  daddu       $fp, $a0, $zero
    ctx->pc = 0x1875acu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1875b0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1875b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1875b4: 0x24b3b0c0  addiu       $s3, $a1, -0x4F40
    ctx->pc = 0x1875b4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 5), 4294947008));
    // 0x1875b8: 0xffb70038  sd          $s7, 0x38($sp)
    ctx->pc = 0x1875b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 23));
    // 0x1875bc: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x1875bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x1875c0: 0x8e820004  lw          $v0, 0x4($s4)
    ctx->pc = 0x1875c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 4)));
    // 0x1875c4: 0x8e830008  lw          $v1, 0x8($s4)
    ctx->pc = 0x1875c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 8)));
    // 0x1875c8: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x1875C8u;
    {
        const bool branch_taken_0x1875c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1875c8) {
            ctx->pc = 0x1875CCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1875C8u;
            // 0x1875cc: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x1875D0u;
            goto label_1875d0;
        }
    }
    ctx->pc = 0x1875D0u;
label_1875d0:
    // 0x1875d0: 0x62001a  div         $zero, $v1, $v0
    ctx->pc = 0x1875d0u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1875d4: 0xa812  mflo        $s5
    ctx->pc = 0x1875d4u;
    SET_GPR_U64(ctx, 21, ctx->lo);
    // 0x1875d8: 0x255102a  slt         $v0, $s2, $s5
    ctx->pc = 0x1875d8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 21)) ? 1 : 0);
    // 0x1875dc: 0x1040002d  beqz        $v0, . + 4 + (0x2D << 2)
    ctx->pc = 0x1875DCu;
    {
        const bool branch_taken_0x1875dc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1875E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1875DCu;
            // 0x1875e0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1875dc) {
            ctx->pc = 0x187694u;
            goto label_187694;
        }
    }
    ctx->pc = 0x1875E4u;
    // 0x1875e4: 0x2417ffff  addiu       $s7, $zero, -0x1
    ctx->pc = 0x1875e4u;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1875e8: 0x2ac30020  slti        $v1, $s6, 0x20
    ctx->pc = 0x1875e8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 22) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x1875ec: 0x0  nop
    ctx->pc = 0x1875ecu;
    // NOP
label_1875f0:
    // 0x1875f0: 0x10600028  beqz        $v1, . + 4 + (0x28 << 2)
    ctx->pc = 0x1875F0u;
    {
        const bool branch_taken_0x1875f0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1875F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1875F0u;
            // 0x1875f4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1875f0) {
            ctx->pc = 0x187694u;
            goto label_187694;
        }
    }
    ctx->pc = 0x1875F8u;
    // 0x1875f8: 0x3c0202d  daddu       $a0, $fp, $zero
    ctx->pc = 0x1875f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1875fc: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1875fcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187600: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x187600u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187604: 0x24070002  addiu       $a3, $zero, 0x2
    ctx->pc = 0x187604u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x187608: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x187608u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18760c: 0xc06204e  jal         func_188138
    ctx->pc = 0x18760Cu;
    SET_GPR_U32(ctx, 31, 0x187614u);
    ctx->pc = 0x187610u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18760Cu;
            // 0x187610: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x188138u;
    if (runtime->hasFunction(0x188138u)) {
        auto targetFn = runtime->lookupFunction(0x188138u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187614u; }
        if (ctx->pc != 0x187614u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00188138_0x188138(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187614u; }
        if (ctx->pc != 0x187614u) { return; }
    }
    ctx->pc = 0x187614u;
label_187614:
    // 0x187614: 0x50400020  beql        $v0, $zero, . + 4 + (0x20 << 2)
    ctx->pc = 0x187614u;
    {
        const bool branch_taken_0x187614 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x187614) {
            ctx->pc = 0x187618u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x187614u;
            // 0x187618: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x187698u;
            goto label_187698;
        }
    }
    ctx->pc = 0x18761Cu;
    // 0x18761c: 0x8e840000  lw          $a0, 0x0($s4)
    ctx->pc = 0x18761cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x187620: 0x417c2  srl         $v0, $a0, 31
    ctx->pc = 0x187620u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), 31));
    // 0x187624: 0x821021  addu        $v0, $a0, $v0
    ctx->pc = 0x187624u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x187628: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x187628u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x18762c: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x18762Cu;
    {
        const bool branch_taken_0x18762c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x187630u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18762Cu;
            // 0x187630: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18762c) {
            ctx->pc = 0x18766Cu;
            goto label_18766c;
        }
    }
    ctx->pc = 0x187634u;
    // 0x187634: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x187634u;
    {
        const bool branch_taken_0x187634 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x187638u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x187634u;
            // 0x187638: 0x8e620000  lw          $v0, 0x0($s3) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x187634) {
            ctx->pc = 0x187660u;
            goto label_187660;
        }
    }
    ctx->pc = 0x18763Cu;
    // 0x18763c: 0x0  nop
    ctx->pc = 0x18763cu;
    // NOP
label_187640:
    // 0x187640: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x187640u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x187644: 0x821021  addu        $v0, $a0, $v0
    ctx->pc = 0x187644u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x187648: 0x51880  sll         $v1, $a1, 2
    ctx->pc = 0x187648u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x18764c: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x18764cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x187650: 0xa2102b  sltu        $v0, $a1, $v0
    ctx->pc = 0x187650u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x187654: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x187654u;
    {
        const bool branch_taken_0x187654 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x187658u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x187654u;
            // 0x187658: 0x731821  addu        $v1, $v1, $s3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 19)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x187654) {
            ctx->pc = 0x18766Cu;
            goto label_18766c;
        }
    }
    ctx->pc = 0x18765Cu;
    // 0x18765c: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x18765cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
label_187660:
    // 0x187660: 0x1057fff7  beq         $v0, $s7, . + 4 + (-0x9 << 2)
    ctx->pc = 0x187660u;
    {
        const bool branch_taken_0x187660 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 23));
        ctx->pc = 0x187664u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x187660u;
            // 0x187664: 0x417c2  srl         $v0, $a0, 31 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x187660) {
            ctx->pc = 0x187640u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_187640;
        }
    }
    ctx->pc = 0x187668u;
    // 0x187668: 0x24100001  addiu       $s0, $zero, 0x1
    ctx->pc = 0x187668u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_18766c:
    // 0x18766c: 0x5a000005  blezl       $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x18766Cu;
    {
        const bool branch_taken_0x18766c = (GPR_S64(ctx, 16) <= 0);
        if (branch_taken_0x18766c) {
            ctx->pc = 0x187670u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x18766Cu;
            // 0x187670: 0x26520001  addiu       $s2, $s2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x187684u;
            goto label_187684;
        }
    }
    ctx->pc = 0x187674u;
    // 0x187674: 0xae320000  sw          $s2, 0x0($s1)
    ctx->pc = 0x187674u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 18));
    // 0x187678: 0x26310004  addiu       $s1, $s1, 0x4
    ctx->pc = 0x187678u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
    // 0x18767c: 0x26d60001  addiu       $s6, $s6, 0x1
    ctx->pc = 0x18767cu;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 1));
    // 0x187680: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x187680u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
label_187684:
    // 0x187684: 0x255102a  slt         $v0, $s2, $s5
    ctx->pc = 0x187684u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 21)) ? 1 : 0);
    // 0x187688: 0x1440ffd9  bnez        $v0, . + 4 + (-0x27 << 2)
    ctx->pc = 0x187688u;
    {
        const bool branch_taken_0x187688 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x18768Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x187688u;
            // 0x18768c: 0x2ac30020  slti        $v1, $s6, 0x20 (Delay Slot)
        SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 22) < (int64_t)(int32_t)32) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x187688) {
            ctx->pc = 0x1875F0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1875f0;
        }
    }
    ctx->pc = 0x187690u;
    // 0x187690: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x187690u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_187694:
    // 0x187694: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x187694u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_187698:
    // 0x187698: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x187698u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x18769c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x18769cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1876a0: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1876a0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1876a4: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x1876a4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1876a8: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x1876a8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1876ac: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x1876acu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1876b0: 0xdfb70038  ld          $s7, 0x38($sp)
    ctx->pc = 0x1876b0u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1876b4: 0xdfbe0040  ld          $fp, 0x40($sp)
    ctx->pc = 0x1876b4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1876b8: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x1876b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1876bc: 0x3e00008  jr          $ra
    ctx->pc = 0x1876BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1876C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1876BCu;
            // 0x1876c0: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1875D0u: goto label_1875d0;
            case 0x1875F0u: goto label_1875f0;
            case 0x187614u: goto label_187614;
            case 0x187640u: goto label_187640;
            case 0x187660u: goto label_187660;
            case 0x18766Cu: goto label_18766c;
            case 0x187684u: goto label_187684;
            case 0x187694u: goto label_187694;
            case 0x187698u: goto label_187698;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1876C4u;
    // 0x1876c4: 0x0  nop
    ctx->pc = 0x1876c4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
