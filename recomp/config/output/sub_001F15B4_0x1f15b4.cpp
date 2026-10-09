#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F15B4
// Address: 0x1f15b4 - 0x1f1688
void sub_001F15B4_0x1f15b4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F15B4_0x1f15b4");
#endif

    switch (ctx->pc) {
        case 0x1f15ecu: goto label_1f15ec;
        case 0x1f1618u: goto label_1f1618;
        default: break;
    }

    ctx->pc = 0x1f15b4u;

    // 0x1f15b4: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1f15b4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1f15b8: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1f15b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1f15bc: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1f15bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1f15c0: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f15c0u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f15c4: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f15c4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f15c8: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1f15c8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1f15cc: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1f15ccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1f15d0: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1f15d0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1f15d4: 0xafc00010  sw          $zero, 0x10($fp)
    ctx->pc = 0x1f15d4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 0));
    // 0x1f15d8: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f15d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f15dc: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x1f15dcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x1f15e0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f15e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f15e4: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1f15e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1f15e8: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1f15e8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
label_1f15ec:
    // 0x1f15ec: 0x8fc30014  lw          $v1, 0x14($fp)
    ctx->pc = 0x1f15ecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1f15f0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f15f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f15f4: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F15F4u;
    {
        const bool branch_taken_0x1f15f4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1f15f4) {
            ctx->pc = 0x1F1604u;
            goto label_1f1604;
        }
    }
    ctx->pc = 0x1F15FCu;
    // 0x1f15fc: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x1F15FCu;
    {
        const bool branch_taken_0x1f15fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f15fc) {
            ctx->pc = 0x1F166Cu;
            goto label_1f166c;
        }
    }
    ctx->pc = 0x1F1604u;
label_1f1604:
    // 0x1f1604: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f1604u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f1608: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1f1608u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1f160c: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1f160cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f1610: 0x40f809  jalr        $v0
    ctx->pc = 0x1F1610u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1F1618u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1F1618u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F15ECu: goto label_1f15ec;
            case 0x1F1604u: goto label_1f1604;
            case 0x1F1618u: goto label_1f1618;
            case 0x1F1640u: goto label_1f1640;
            case 0x1F1658u: goto label_1f1658;
            case 0x1F166Cu: goto label_1f166c;
            case 0x1F1670u: goto label_1f1670;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1F1618u; }
            if (ctx->pc != 0x1F1618u) { return; }
        }
        }
    }
    ctx->pc = 0x1F1618u;
label_1f1618:
    // 0x1f1618: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1f1618u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1f161c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f161cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1620: 0x18400007  blez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1F1620u;
    {
        const bool branch_taken_0x1f1620 = (GPR_S64(ctx, 2) <= 0);
        if (branch_taken_0x1f1620) {
            ctx->pc = 0x1F1640u;
            goto label_1f1640;
        }
    }
    ctx->pc = 0x1F1628u;
    // 0x1f1628: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1f1628u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f162c: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1f162cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1f1630: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1f1630u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1f1634: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f1634u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1638: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1F1638u;
    {
        const bool branch_taken_0x1f1638 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1638) {
            ctx->pc = 0x1F1670u;
            goto label_1f1670;
        }
    }
    ctx->pc = 0x1F1640u;
label_1f1640:
    // 0x1f1640: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f1640u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1644: 0x4410004  bgez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F1644u;
    {
        const bool branch_taken_0x1f1644 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1f1644) {
            ctx->pc = 0x1F1658u;
            goto label_1f1658;
        }
    }
    ctx->pc = 0x1F164Cu;
    // 0x1f164c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f164cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1f1650: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1F1650u;
    {
        const bool branch_taken_0x1f1650 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1650) {
            ctx->pc = 0x1F1670u;
            goto label_1f1670;
        }
    }
    ctx->pc = 0x1F1658u;
label_1f1658:
    // 0x1f1658: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1f1658u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1f165c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1f165cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1f1660: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1f1660u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1f1664: 0x1000ffe1  b           . + 4 + (-0x1F << 2)
    ctx->pc = 0x1F1664u;
    {
        const bool branch_taken_0x1f1664 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f1664) {
            ctx->pc = 0x1F15ECu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f15ec;
        }
    }
    ctx->pc = 0x1F166Cu;
label_1f166c:
    // 0x1f166c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1f166cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
label_1f1670:
    // 0x1f1670: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f1670u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f1674: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1f1674u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1f1678: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1f1678u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1f167c: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1f167cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1f1680: 0x3e00008  jr          $ra
    ctx->pc = 0x1F1680u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F15ECu: goto label_1f15ec;
            case 0x1F1604u: goto label_1f1604;
            case 0x1F1618u: goto label_1f1618;
            case 0x1F1640u: goto label_1f1640;
            case 0x1F1658u: goto label_1f1658;
            case 0x1F166Cu: goto label_1f166c;
            case 0x1F1670u: goto label_1f1670;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F1688u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
