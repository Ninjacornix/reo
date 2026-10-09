#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00177560
// Address: 0x177560 - 0x1775e0
void sub_00177560_0x177560(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00177560_0x177560");
#endif

    switch (ctx->pc) {
        case 0x177588u: goto label_177588;
        case 0x1775b8u: goto label_1775b8;
        default: break;
    }

    ctx->pc = 0x177560u;

    // 0x177560: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x177560u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x177564: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x177564u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x177568: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x177568u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17756c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x17756cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177570: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x177570u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x177574: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x177574u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177578: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x177578u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17757c: 0x59080  sll         $s2, $a1, 2
    ctx->pc = 0x17757cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x177580: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x177580u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177584: 0x2a22000f  slti        $v0, $s1, 0xF
    ctx->pc = 0x177584u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)15) ? 1 : 0);
label_177588:
    // 0x177588: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x177588u;
    {
        const bool branch_taken_0x177588 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17758Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177588u;
            // 0x17758c: 0x26310001  addiu       $s1, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x177588) {
            ctx->pc = 0x1775C4u;
            goto label_1775c4;
        }
    }
    ctx->pc = 0x177590u;
    // 0x177590: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x177590u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x177594: 0x26100004  addiu       $s0, $s0, 0x4
    ctx->pc = 0x177594u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x177598: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x177598u;
    {
        const bool branch_taken_0x177598 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17759Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177598u;
            // 0x17759c: 0x2421821  addu        $v1, $s2, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x177598) {
            ctx->pc = 0x1775C4u;
            goto label_1775c4;
        }
    }
    ctx->pc = 0x1775A0u;
    // 0x1775a0: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1775a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1775a4: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1775a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1775a8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1775a8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1775ac: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1775acu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1775b0: 0x40f809  jalr        $v0
    ctx->pc = 0x1775B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1775B8u);
        ctx->pc = 0x1775B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1775B0u;
            // 0x1775b4: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1775B8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x177588u: goto label_177588;
            case 0x1775B8u: goto label_1775b8;
            case 0x1775C4u: goto label_1775c4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1775B8u; }
            if (ctx->pc != 0x1775B8u) { return; }
        }
        }
    }
    ctx->pc = 0x1775B8u;
label_1775b8:
    // 0x1775b8: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1775b8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1775bc: 0x1080fff2  beqz        $a0, . + 4 + (-0xE << 2)
    ctx->pc = 0x1775BCu;
    {
        const bool branch_taken_0x1775bc = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1775C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1775BCu;
            // 0x1775c0: 0x2a22000f  slti        $v0, $s1, 0xF (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)15) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1775bc) {
            ctx->pc = 0x177588u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_177588;
        }
    }
    ctx->pc = 0x1775C4u;
label_1775c4:
    // 0x1775c4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1775c4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1775c8: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1775c8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1775cc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1775ccu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1775d0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1775d0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1775d4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1775d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1775d8: 0x3e00008  jr          $ra
    ctx->pc = 0x1775D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1775DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1775D8u;
            // 0x1775dc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x177588u: goto label_177588;
            case 0x1775B8u: goto label_1775b8;
            case 0x1775C4u: goto label_1775c4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1775E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
