#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010A610
// Address: 0x10a610 - 0x10a6a8
void sub_0010A610_0x10a610(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010A610_0x10a610");
#endif

    switch (ctx->pc) {
        case 0x10a648u: goto label_10a648;
        case 0x10a690u: goto label_10a690;
        default: break;
    }

    ctx->pc = 0x10a610u;

    // 0x10a610: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x10a610u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x10a614: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x10a614u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10a618: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x10a618u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x10a61c: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x10a61cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10a620: 0x2e030020  sltiu       $v1, $s0, 0x20
    ctx->pc = 0x10a620u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)32) ? 1 : 0);
    // 0x10a624: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x10a624u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x10a628: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x10a628u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x10a62c: 0x10600019  beqz        $v1, . + 4 + (0x19 << 2)
    ctx->pc = 0x10A62Cu;
    {
        const bool branch_taken_0x10a62c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x10A630u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A62Cu;
            // 0x10a630: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a62c) {
            ctx->pc = 0x10A694u;
            goto label_10a694;
        }
    }
    ctx->pc = 0x10A634u;
    // 0x10a634: 0x8e2501d4  lw          $a1, 0x1D4($s1)
    ctx->pc = 0x10a634u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 468)));
    // 0x10a638: 0x14a00008  bnez        $a1, . + 4 + (0x8 << 2)
    ctx->pc = 0x10A638u;
    {
        const bool branch_taken_0x10a638 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x10A63Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A638u;
            // 0x10a63c: 0x101880  sll         $v1, $s0, 2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a638) {
            ctx->pc = 0x10A65Cu;
            goto label_10a65c;
        }
    }
    ctx->pc = 0x10A640u;
    // 0x10a640: 0xc042912  jal         func_10A448
    ctx->pc = 0x10A640u;
    SET_GPR_U32(ctx, 31, 0x10A648u);
    ctx->pc = 0x10A448u;
    if (runtime->hasFunction(0x10A448u)) {
        auto targetFn = runtime->lookupFunction(0x10A448u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10A648u; }
        if (ctx->pc != 0x10A648u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A448_0x10a448(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10A648u; }
        if (ctx->pc != 0x10A648u) { return; }
    }
    ctx->pc = 0x10A648u;
label_10a648:
    // 0x10a648: 0x50400003  beql        $v0, $zero, . + 4 + (0x3 << 2)
    ctx->pc = 0x10A648u;
    {
        const bool branch_taken_0x10a648 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10a648) {
            ctx->pc = 0x10A64Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10A648u;
            // 0x10a64c: 0x8e2501d4  lw          $a1, 0x1D4($s1) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 468)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10A658u;
            goto label_10a658;
        }
    }
    ctx->pc = 0x10A650u;
    // 0x10a650: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x10A650u;
    {
        const bool branch_taken_0x10a650 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10A654u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A650u;
            // 0x10a654: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a650) {
            ctx->pc = 0x10A694u;
            goto label_10a694;
        }
    }
    ctx->pc = 0x10A658u;
label_10a658:
    // 0x10a658: 0x101880  sll         $v1, $s0, 2
    ctx->pc = 0x10a658u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
label_10a65c:
    // 0x10a65c: 0x652021  addu        $a0, $v1, $a1
    ctx->pc = 0x10a65cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x10a660: 0x8c850000  lw          $a1, 0x0($a0)
    ctx->pc = 0x10a660u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x10a664: 0x10a0000b  beqz        $a1, . + 4 + (0xB << 2)
    ctx->pc = 0x10A664u;
    {
        const bool branch_taken_0x10a664 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x10A668u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A664u;
            // 0x10a668: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a664) {
            ctx->pc = 0x10A694u;
            goto label_10a694;
        }
    }
    ctx->pc = 0x10A66Cu;
    // 0x10a66c: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x10a66cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10a670: 0x10a30008  beq         $a1, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x10A670u;
    {
        const bool branch_taken_0x10a670 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        ctx->pc = 0x10A674u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A670u;
            // 0x10a674: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a670) {
            ctx->pc = 0x10A694u;
            goto label_10a694;
        }
    }
    ctx->pc = 0x10A678u;
    // 0x10a678: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x10a678u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x10a67c: 0x10a30005  beq         $a1, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x10A67Cu;
    {
        const bool branch_taken_0x10a67c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        ctx->pc = 0x10A680u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A67Cu;
            // 0x10a680: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10a67c) {
            ctx->pc = 0x10A694u;
            goto label_10a694;
        }
    }
    ctx->pc = 0x10A684u;
    // 0x10a684: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x10a684u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x10a688: 0xa0f809  jalr        $a1
    ctx->pc = 0x10A688u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 5);
        SET_GPR_U32(ctx, 31, 0x10A690u);
        ctx->pc = 0x10A68Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A688u;
            // 0x10a68c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x10A690u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10A648u: goto label_10a648;
            case 0x10A658u: goto label_10a658;
            case 0x10A65Cu: goto label_10a65c;
            case 0x10A690u: goto label_10a690;
            case 0x10A694u: goto label_10a694;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x10A690u; }
            if (ctx->pc != 0x10A690u) { return; }
        }
        }
    }
    ctx->pc = 0x10A690u;
label_10a690:
    // 0x10a690: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x10a690u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_10a694:
    // 0x10a694: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x10a694u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10a698: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x10a698u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x10a69c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x10a69cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x10a6a0: 0x3e00008  jr          $ra
    ctx->pc = 0x10A6A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10A6A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10A6A0u;
            // 0x10a6a4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10A648u: goto label_10a648;
            case 0x10A658u: goto label_10a658;
            case 0x10A65Cu: goto label_10a65c;
            case 0x10A690u: goto label_10a690;
            case 0x10A694u: goto label_10a694;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10A6A8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
