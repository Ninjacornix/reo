#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BA520
// Address: 0x1ba520 - 0x1ba5e0
void sub_001BA520_0x1ba520(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BA520_0x1ba520");
#endif

    switch (ctx->pc) {
        case 0x1ba544u: goto label_1ba544;
        case 0x1ba560u: goto label_1ba560;
        default: break;
    }

    ctx->pc = 0x1ba520u;

    // 0x1ba520: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1ba520u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1ba524: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x1ba524u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ba528: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1ba528u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1ba52c: 0x240300ff  addiu       $v1, $zero, 0xFF
    ctx->pc = 0x1ba52cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1ba530: 0x90840119  lbu         $a0, 0x119($a0)
    ctx->pc = 0x1ba530u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 281)));
    // 0x1ba534: 0x10830005  beq         $a0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1BA534u;
    {
        const bool branch_taken_0x1ba534 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1BA538u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA534u;
            // 0x1ba538: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba534) {
            ctx->pc = 0x1BA54Cu;
            goto label_1ba54c;
        }
    }
    ctx->pc = 0x1BA53Cu;
    // 0x1ba53c: 0xc198cd4  jal         func_663350
    ctx->pc = 0x1BA53Cu;
    SET_GPR_U32(ctx, 31, 0x1BA544u);
    ctx->pc = 0x1BA540u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA53Cu;
            // 0x1ba540: 0x90a5011a  lbu         $a1, 0x11A($a1) (Delay Slot)
        SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 282)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x663350u;
    {
        auto targetFn = runtime->lookupFunction(0x663350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA544u; }
        if (ctx->pc != 0x1BA544u) { return; }
    }
    ctx->pc = 0x1BA544u;
label_1ba544:
    // 0x1ba544: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1BA544u;
    {
        const bool branch_taken_0x1ba544 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ba544) {
            ctx->pc = 0x1BA560u;
            goto label_1ba560;
        }
    }
    ctx->pc = 0x1BA54Cu;
label_1ba54c:
    // 0x1ba54c: 0x90a40117  lbu         $a0, 0x117($a1)
    ctx->pc = 0x1ba54cu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 279)));
    // 0x1ba550: 0x10830003  beq         $a0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BA550u;
    {
        const bool branch_taken_0x1ba550 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1ba550) {
            ctx->pc = 0x1BA560u;
            goto label_1ba560;
        }
    }
    ctx->pc = 0x1BA558u;
    // 0x1ba558: 0xc198cd4  jal         func_663350
    ctx->pc = 0x1BA558u;
    SET_GPR_U32(ctx, 31, 0x1BA560u);
    ctx->pc = 0x1BA55Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA558u;
            // 0x1ba55c: 0x90a50118  lbu         $a1, 0x118($a1) (Delay Slot)
        SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 280)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x663350u;
    {
        auto targetFn = runtime->lookupFunction(0x663350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA560u; }
        if (ctx->pc != 0x1BA560u) { return; }
    }
    ctx->pc = 0x1BA560u;
label_1ba560:
    // 0x1ba560: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BA560u;
    {
        const bool branch_taken_0x1ba560 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1ba560) {
            ctx->pc = 0x1BA570u;
            goto label_1ba570;
        }
    }
    ctx->pc = 0x1BA568u;
    // 0x1ba568: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x1BA568u;
    {
        const bool branch_taken_0x1ba568 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA56Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA568u;
            // 0x1ba56c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba568) {
            ctx->pc = 0x1BA5D4u;
            goto label_1ba5d4;
        }
    }
    ctx->pc = 0x1BA570u;
label_1ba570:
    // 0x1ba570: 0x90440002  lbu         $a0, 0x2($v0)
    ctx->pc = 0x1ba570u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x1ba574: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1ba574u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ba578: 0x1083000d  beq         $a0, $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x1BA578u;
    {
        const bool branch_taken_0x1ba578 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1BA57Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA578u;
            // 0x1ba57c: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba578) {
            ctx->pc = 0x1BA5B0u;
            goto label_1ba5b0;
        }
    }
    ctx->pc = 0x1BA580u;
    // 0x1ba580: 0x10830005  beq         $a0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1BA580u;
    {
        const bool branch_taken_0x1ba580 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1ba580) {
            ctx->pc = 0x1BA598u;
            goto label_1ba598;
        }
    }
    ctx->pc = 0x1BA588u;
    // 0x1ba588: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BA588u;
    {
        const bool branch_taken_0x1ba588 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ba588) {
            ctx->pc = 0x1BA598u;
            goto label_1ba598;
        }
    }
    ctx->pc = 0x1BA590u;
    // 0x1ba590: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1BA590u;
    {
        const bool branch_taken_0x1ba590 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA594u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA590u;
            // 0x1ba594: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba590) {
            ctx->pc = 0x1BA5C8u;
            goto label_1ba5c8;
        }
    }
    ctx->pc = 0x1BA598u;
label_1ba598:
    // 0x1ba598: 0x8c420ba0  lw          $v0, 0xBA0($v0)
    ctx->pc = 0x1ba598u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 2976)));
    // 0x1ba59c: 0x30420008  andi        $v0, $v0, 0x8
    ctx->pc = 0x1ba59cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)8);
    // 0x1ba5a0: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1BA5A0u;
    {
        const bool branch_taken_0x1ba5a0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ba5a0) {
            ctx->pc = 0x1BA5D0u;
            goto label_1ba5d0;
        }
    }
    ctx->pc = 0x1BA5A8u;
    // 0x1ba5a8: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1BA5A8u;
    {
        const bool branch_taken_0x1ba5a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA5ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA5A8u;
            // 0x1ba5ac: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba5a8) {
            ctx->pc = 0x1BA5D4u;
            goto label_1ba5d4;
        }
    }
    ctx->pc = 0x1BA5B0u;
label_1ba5b0:
    // 0x1ba5b0: 0x8c420c94  lw          $v0, 0xC94($v0)
    ctx->pc = 0x1ba5b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 3220)));
    // 0x1ba5b4: 0x30420400  andi        $v0, $v0, 0x400
    ctx->pc = 0x1ba5b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1024);
    // 0x1ba5b8: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1BA5B8u;
    {
        const bool branch_taken_0x1ba5b8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ba5b8) {
            ctx->pc = 0x1BA5D0u;
            goto label_1ba5d0;
        }
    }
    ctx->pc = 0x1BA5C0u;
    // 0x1ba5c0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1BA5C0u;
    {
        const bool branch_taken_0x1ba5c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA5C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA5C0u;
            // 0x1ba5c4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba5c0) {
            ctx->pc = 0x1BA5D4u;
            goto label_1ba5d4;
        }
    }
    ctx->pc = 0x1BA5C8u;
label_1ba5c8:
    // 0x1ba5c8: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1BA5C8u;
    {
        const bool branch_taken_0x1ba5c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA5CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA5C8u;
            // 0x1ba5cc: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba5c8) {
            ctx->pc = 0x1BA5D8u;
            goto label_1ba5d8;
        }
    }
    ctx->pc = 0x1BA5D0u;
label_1ba5d0:
    // 0x1ba5d0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1ba5d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1ba5d4:
    // 0x1ba5d4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1ba5d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1ba5d8:
    // 0x1ba5d8: 0x3e00008  jr          $ra
    ctx->pc = 0x1BA5D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BA5DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA5D8u;
            // 0x1ba5dc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BA544u: goto label_1ba544;
            case 0x1BA54Cu: goto label_1ba54c;
            case 0x1BA560u: goto label_1ba560;
            case 0x1BA570u: goto label_1ba570;
            case 0x1BA598u: goto label_1ba598;
            case 0x1BA5B0u: goto label_1ba5b0;
            case 0x1BA5C8u: goto label_1ba5c8;
            case 0x1BA5D0u: goto label_1ba5d0;
            case 0x1BA5D4u: goto label_1ba5d4;
            case 0x1BA5D8u: goto label_1ba5d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BA5E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
