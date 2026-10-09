#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BA4C0
// Address: 0x1ba4c0 - 0x1ba720
void sub_001BA4C0_0x1ba4c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BA4C0_0x1ba4c0");
#endif

    switch (ctx->pc) {
        case 0x1ba4f8u: goto label_1ba4f8;
        case 0x1ba508u: goto label_1ba508;
        case 0x1ba544u: goto label_1ba544;
        case 0x1ba560u: goto label_1ba560;
        case 0x1ba614u: goto label_1ba614;
        case 0x1ba644u: goto label_1ba644;
        case 0x1ba65cu: goto label_1ba65c;
        case 0x1ba674u: goto label_1ba674;
        case 0x1ba6b8u: goto label_1ba6b8;
        case 0x1ba6dcu: goto label_1ba6dc;
        case 0x1ba708u: goto label_1ba708;
        default: break;
    }

    ctx->pc = 0x1ba4c0u;

label_1ba4c0:
    // 0x1ba4c0: 0x30a600ff  andi        $a2, $a1, 0xFF
    ctx->pc = 0x1ba4c0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x1ba4c4: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1ba4c4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1ba4c8: 0x30c50040  andi        $a1, $a2, 0x40
    ctx->pc = 0x1ba4c8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)64);
    // 0x1ba4cc: 0x24030040  addiu       $v1, $zero, 0x40
    ctx->pc = 0x1ba4ccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x1ba4d0: 0x10a3000b  beq         $a1, $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x1BA4D0u;
    {
        const bool branch_taken_0x1ba4d0 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 3));
        ctx->pc = 0x1BA4D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA4D0u;
            // 0x1ba4d4: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba4d0) {
            ctx->pc = 0x1BA500u;
            goto label_1ba500;
        }
    }
    ctx->pc = 0x1BA4D8u;
    // 0x1ba4d8: 0x10a00003  beqz        $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BA4D8u;
    {
        const bool branch_taken_0x1ba4d8 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ba4d8) {
            ctx->pc = 0x1BA4E8u;
            goto label_1ba4e8;
        }
    }
    ctx->pc = 0x1BA4E0u;
    // 0x1ba4e0: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1BA4E0u;
    {
        const bool branch_taken_0x1ba4e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA4E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA4E0u;
            // 0x1ba4e4: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba4e0) {
            ctx->pc = 0x1BA50Cu;
            goto label_1ba50c;
        }
    }
    ctx->pc = 0x1BA4E8u;
label_1ba4e8:
    // 0x1ba4e8: 0x30c5003f  andi        $a1, $a2, 0x3F
    ctx->pc = 0x1ba4e8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)63);
    // 0x1ba4ec: 0x30c20080  andi        $v0, $a2, 0x80
    ctx->pc = 0x1ba4ecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)128);
    // 0x1ba4f0: 0xc06e478  jal         func_1B91E0
    ctx->pc = 0x1BA4F0u;
    SET_GPR_U32(ctx, 31, 0x1BA4F8u);
    ctx->pc = 0x1BA4F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA4F0u;
            // 0x1ba4f4: 0x2302b  sltu        $a2, $zero, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 6, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B91E0u;
    if (runtime->hasFunction(0x1B91E0u)) {
        auto targetFn = runtime->lookupFunction(0x1B91E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA4F8u; }
        if (ctx->pc != 0x1BA4F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B91E0_0x1b91e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA4F8u; }
        if (ctx->pc != 0x1BA4F8u) { return; }
    }
    ctx->pc = 0x1BA4F8u;
label_1ba4f8:
    // 0x1ba4f8: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1BA4F8u;
    {
        const bool branch_taken_0x1ba4f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ba4f8) {
            ctx->pc = 0x1BA508u;
            goto label_1ba508;
        }
    }
    ctx->pc = 0x1BA500u;
label_1ba500:
    // 0x1ba500: 0xc06e2ec  jal         func_1B8BB0
    ctx->pc = 0x1BA500u;
    SET_GPR_U32(ctx, 31, 0x1BA508u);
    ctx->pc = 0x1BA504u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA500u;
            // 0x1ba504: 0x30c5003f  andi        $a1, $a2, 0x3F (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)63);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B8BB0u;
    if (runtime->hasFunction(0x1B8BB0u)) {
        auto targetFn = runtime->lookupFunction(0x1B8BB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA508u; }
        if (ctx->pc != 0x1BA508u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B8BB0_0x1b8bb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA508u; }
        if (ctx->pc != 0x1BA508u) { return; }
    }
    ctx->pc = 0x1BA508u;
label_1ba508:
    // 0x1ba508: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1ba508u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1ba50c:
    // 0x1ba50c: 0x3e00008  jr          $ra
    ctx->pc = 0x1BA50Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BA510u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA50Cu;
            // 0x1ba510: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BA4C0u: goto label_1ba4c0;
            case 0x1BA4E8u: goto label_1ba4e8;
            case 0x1BA4F8u: goto label_1ba4f8;
            case 0x1BA500u: goto label_1ba500;
            case 0x1BA508u: goto label_1ba508;
            case 0x1BA50Cu: goto label_1ba50c;
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
            case 0x1BA60Cu: goto label_1ba60c;
            case 0x1BA614u: goto label_1ba614;
            case 0x1BA61Cu: goto label_1ba61c;
            case 0x1BA63Cu: goto label_1ba63c;
            case 0x1BA644u: goto label_1ba644;
            case 0x1BA64Cu: goto label_1ba64c;
            case 0x1BA65Cu: goto label_1ba65c;
            case 0x1BA664u: goto label_1ba664;
            case 0x1BA674u: goto label_1ba674;
            case 0x1BA678u: goto label_1ba678;
            case 0x1BA6B0u: goto label_1ba6b0;
            case 0x1BA6B8u: goto label_1ba6b8;
            case 0x1BA6D4u: goto label_1ba6d4;
            case 0x1BA6DCu: goto label_1ba6dc;
            case 0x1BA700u: goto label_1ba700;
            case 0x1BA708u: goto label_1ba708;
            case 0x1BA70Cu: goto label_1ba70c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BA514u;
    // 0x1ba514: 0x0  nop
    ctx->pc = 0x1ba514u;
    // NOP
    // 0x1ba518: 0x0  nop
    ctx->pc = 0x1ba518u;
    // NOP
    // 0x1ba51c: 0x0  nop
    ctx->pc = 0x1ba51cu;
    // NOP
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
            case 0x1BA4C0u: goto label_1ba4c0;
            case 0x1BA4E8u: goto label_1ba4e8;
            case 0x1BA4F8u: goto label_1ba4f8;
            case 0x1BA500u: goto label_1ba500;
            case 0x1BA508u: goto label_1ba508;
            case 0x1BA50Cu: goto label_1ba50c;
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
            case 0x1BA60Cu: goto label_1ba60c;
            case 0x1BA614u: goto label_1ba614;
            case 0x1BA61Cu: goto label_1ba61c;
            case 0x1BA63Cu: goto label_1ba63c;
            case 0x1BA644u: goto label_1ba644;
            case 0x1BA64Cu: goto label_1ba64c;
            case 0x1BA65Cu: goto label_1ba65c;
            case 0x1BA664u: goto label_1ba664;
            case 0x1BA674u: goto label_1ba674;
            case 0x1BA678u: goto label_1ba678;
            case 0x1BA6B0u: goto label_1ba6b0;
            case 0x1BA6B8u: goto label_1ba6b8;
            case 0x1BA6D4u: goto label_1ba6d4;
            case 0x1BA6DCu: goto label_1ba6dc;
            case 0x1BA700u: goto label_1ba700;
            case 0x1BA708u: goto label_1ba708;
            case 0x1BA70Cu: goto label_1ba70c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BA5E0u;
    // 0x1ba5e0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1ba5e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1ba5e4: 0x10800023  beqz        $a0, . + 4 + (0x23 << 2)
    ctx->pc = 0x1BA5E4u;
    {
        const bool branch_taken_0x1ba5e4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA5E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA5E4u;
            // 0x1ba5e8: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba5e4) {
            ctx->pc = 0x1BA674u;
            goto label_1ba674;
        }
    }
    ctx->pc = 0x1BA5ECu;
    // 0x1ba5ec: 0x90860002  lbu         $a2, 0x2($a0)
    ctx->pc = 0x1ba5ecu;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x1ba5f0: 0x24030009  addiu       $v1, $zero, 0x9
    ctx->pc = 0x1ba5f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1ba5f4: 0x10c30009  beq         $a2, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1BA5F4u;
    {
        const bool branch_taken_0x1ba5f4 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 3));
        if (branch_taken_0x1ba5f4) {
            ctx->pc = 0x1BA61Cu;
            goto label_1ba61c;
        }
    }
    ctx->pc = 0x1BA5FCu;
    // 0x1ba5fc: 0x10c00003  beqz        $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BA5FCu;
    {
        const bool branch_taken_0x1ba5fc = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ba5fc) {
            ctx->pc = 0x1BA60Cu;
            goto label_1ba60c;
        }
    }
    ctx->pc = 0x1BA604u;
    // 0x1ba604: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1BA604u;
    {
        const bool branch_taken_0x1ba604 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA608u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA604u;
            // 0x1ba608: 0x30a200ff  andi        $v0, $a1, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba604) {
            ctx->pc = 0x1BA664u;
            goto label_1ba664;
        }
    }
    ctx->pc = 0x1BA60Cu;
label_1ba60c:
    // 0x1ba60c: 0xc06e930  jal         func_1BA4C0
    ctx->pc = 0x1BA60Cu;
    SET_GPR_U32(ctx, 31, 0x1BA614u);
    ctx->pc = 0x1BA4C0u;
    goto label_1ba4c0;
    ctx->pc = 0x1BA614u;
label_1ba614:
    // 0x1ba614: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1BA614u;
    {
        const bool branch_taken_0x1ba614 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA618u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA614u;
            // 0x1ba618: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba614) {
            ctx->pc = 0x1BA678u;
            goto label_1ba678;
        }
    }
    ctx->pc = 0x1BA61Cu;
label_1ba61c:
    // 0x1ba61c: 0x8c840028  lw          $a0, 0x28($a0)
    ctx->pc = 0x1ba61cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 40)));
    // 0x1ba620: 0x10800014  beqz        $a0, . + 4 + (0x14 << 2)
    ctx->pc = 0x1BA620u;
    {
        const bool branch_taken_0x1ba620 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ba620) {
            ctx->pc = 0x1BA674u;
            goto label_1ba674;
        }
    }
    ctx->pc = 0x1BA628u;
    // 0x1ba628: 0x90820002  lbu         $v0, 0x2($a0)
    ctx->pc = 0x1ba628u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x1ba62c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BA62Cu;
    {
        const bool branch_taken_0x1ba62c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ba62c) {
            ctx->pc = 0x1BA63Cu;
            goto label_1ba63c;
        }
    }
    ctx->pc = 0x1BA634u;
    // 0x1ba634: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1BA634u;
    {
        const bool branch_taken_0x1ba634 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA638u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA634u;
            // 0x1ba638: 0x30a200ff  andi        $v0, $a1, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba634) {
            ctx->pc = 0x1BA64Cu;
            goto label_1ba64c;
        }
    }
    ctx->pc = 0x1BA63Cu;
label_1ba63c:
    // 0x1ba63c: 0xc06e930  jal         func_1BA4C0
    ctx->pc = 0x1BA63Cu;
    SET_GPR_U32(ctx, 31, 0x1BA644u);
    ctx->pc = 0x1BA4C0u;
    goto label_1ba4c0;
    ctx->pc = 0x1BA644u;
label_1ba644:
    // 0x1ba644: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1BA644u;
    {
        const bool branch_taken_0x1ba644 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ba644) {
            ctx->pc = 0x1BA674u;
            goto label_1ba674;
        }
    }
    ctx->pc = 0x1BA64Cu;
label_1ba64c:
    // 0x1ba64c: 0x3045007f  andi        $a1, $v0, 0x7F
    ctx->pc = 0x1ba64cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)127);
    // 0x1ba650: 0x30420080  andi        $v0, $v0, 0x80
    ctx->pc = 0x1ba650u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)128);
    // 0x1ba654: 0xc06e478  jal         func_1B91E0
    ctx->pc = 0x1BA654u;
    SET_GPR_U32(ctx, 31, 0x1BA65Cu);
    ctx->pc = 0x1BA658u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA654u;
            // 0x1ba658: 0x2302b  sltu        $a2, $zero, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 6, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B91E0u;
    if (runtime->hasFunction(0x1B91E0u)) {
        auto targetFn = runtime->lookupFunction(0x1B91E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA65Cu; }
        if (ctx->pc != 0x1BA65Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B91E0_0x1b91e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA65Cu; }
        if (ctx->pc != 0x1BA65Cu) { return; }
    }
    ctx->pc = 0x1BA65Cu;
label_1ba65c:
    // 0x1ba65c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1BA65Cu;
    {
        const bool branch_taken_0x1ba65c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ba65c) {
            ctx->pc = 0x1BA674u;
            goto label_1ba674;
        }
    }
    ctx->pc = 0x1BA664u;
label_1ba664:
    // 0x1ba664: 0x3045007f  andi        $a1, $v0, 0x7F
    ctx->pc = 0x1ba664u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)127);
    // 0x1ba668: 0x30420080  andi        $v0, $v0, 0x80
    ctx->pc = 0x1ba668u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)128);
    // 0x1ba66c: 0xc06e478  jal         func_1B91E0
    ctx->pc = 0x1BA66Cu;
    SET_GPR_U32(ctx, 31, 0x1BA674u);
    ctx->pc = 0x1BA670u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA66Cu;
            // 0x1ba670: 0x2302b  sltu        $a2, $zero, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 6, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B91E0u;
    if (runtime->hasFunction(0x1B91E0u)) {
        auto targetFn = runtime->lookupFunction(0x1B91E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA674u; }
        if (ctx->pc != 0x1BA674u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B91E0_0x1b91e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA674u; }
        if (ctx->pc != 0x1BA674u) { return; }
    }
    ctx->pc = 0x1BA674u;
label_1ba674:
    // 0x1ba674: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1ba674u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1ba678:
    // 0x1ba678: 0x3e00008  jr          $ra
    ctx->pc = 0x1BA678u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BA67Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA678u;
            // 0x1ba67c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BA4C0u: goto label_1ba4c0;
            case 0x1BA4E8u: goto label_1ba4e8;
            case 0x1BA4F8u: goto label_1ba4f8;
            case 0x1BA500u: goto label_1ba500;
            case 0x1BA508u: goto label_1ba508;
            case 0x1BA50Cu: goto label_1ba50c;
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
            case 0x1BA60Cu: goto label_1ba60c;
            case 0x1BA614u: goto label_1ba614;
            case 0x1BA61Cu: goto label_1ba61c;
            case 0x1BA63Cu: goto label_1ba63c;
            case 0x1BA644u: goto label_1ba644;
            case 0x1BA64Cu: goto label_1ba64c;
            case 0x1BA65Cu: goto label_1ba65c;
            case 0x1BA664u: goto label_1ba664;
            case 0x1BA674u: goto label_1ba674;
            case 0x1BA678u: goto label_1ba678;
            case 0x1BA6B0u: goto label_1ba6b0;
            case 0x1BA6B8u: goto label_1ba6b8;
            case 0x1BA6D4u: goto label_1ba6d4;
            case 0x1BA6DCu: goto label_1ba6dc;
            case 0x1BA700u: goto label_1ba700;
            case 0x1BA708u: goto label_1ba708;
            case 0x1BA70Cu: goto label_1ba70c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BA680u;
    // 0x1ba680: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1ba680u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1ba684: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1ba684u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ba688: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1ba688u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1ba68c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1ba68cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1ba690: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1ba690u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ba694: 0x90840008  lbu         $a0, 0x8($a0)
    ctx->pc = 0x1ba694u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1ba698: 0x1083000e  beq         $a0, $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x1BA698u;
    {
        const bool branch_taken_0x1ba698 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1ba698) {
            ctx->pc = 0x1BA6D4u;
            goto label_1ba6d4;
        }
    }
    ctx->pc = 0x1BA6A0u;
    // 0x1ba6a0: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BA6A0u;
    {
        const bool branch_taken_0x1ba6a0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ba6a0) {
            ctx->pc = 0x1BA6B0u;
            goto label_1ba6b0;
        }
    }
    ctx->pc = 0x1BA6A8u;
    // 0x1ba6a8: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1BA6A8u;
    {
        const bool branch_taken_0x1ba6a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA6ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA6A8u;
            // 0x1ba6ac: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba6a8) {
            ctx->pc = 0x1BA70Cu;
            goto label_1ba70c;
        }
    }
    ctx->pc = 0x1BA6B0u;
label_1ba6b0:
    // 0x1ba6b0: 0xc06e9c8  jal         func_1BA720
    ctx->pc = 0x1BA6B0u;
    SET_GPR_U32(ctx, 31, 0x1BA6B8u);
    ctx->pc = 0x1BA720u;
    if (runtime->hasFunction(0x1BA720u)) {
        auto targetFn = runtime->lookupFunction(0x1BA720u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA6B8u; }
        if (ctx->pc != 0x1BA6B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BA720_0x1ba720(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA6B8u; }
        if (ctx->pc != 0x1BA6B8u) { return; }
    }
    ctx->pc = 0x1BA6B8u;
label_1ba6b8:
    // 0x1ba6b8: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1ba6b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1ba6bc: 0xac20656c  sw          $zero, 0x656C($at)
    ctx->pc = 0x1ba6bcu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 25964), GPR_U32(ctx, 0));
    // 0x1ba6c0: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1ba6c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1ba6c4: 0xac206568  sw          $zero, 0x6568($at)
    ctx->pc = 0x1ba6c4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 25960), GPR_U32(ctx, 0));
    // 0x1ba6c8: 0x92020008  lbu         $v0, 0x8($s0)
    ctx->pc = 0x1ba6c8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1ba6cc: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1ba6ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1ba6d0: 0xa2020008  sb          $v0, 0x8($s0)
    ctx->pc = 0x1ba6d0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 8), (uint8_t)GPR_U32(ctx, 2));
label_1ba6d4:
    // 0x1ba6d4: 0xc06e9d0  jal         func_1BA740
    ctx->pc = 0x1BA6D4u;
    SET_GPR_U32(ctx, 31, 0x1BA6DCu);
    ctx->pc = 0x1BA6D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA6D4u;
            // 0x1ba6d8: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BA740u;
    if (runtime->hasFunction(0x1BA740u)) {
        auto targetFn = runtime->lookupFunction(0x1BA740u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA6DCu; }
        if (ctx->pc != 0x1BA6DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BA740_0x1ba740(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA6DCu; }
        if (ctx->pc != 0x1BA6DCu) { return; }
    }
    ctx->pc = 0x1BA6DCu;
label_1ba6dc:
    // 0x1ba6dc: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1ba6dcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1ba6e0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1ba6e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ba6e4: 0x90246571  lbu         $a0, 0x6571($at)
    ctx->pc = 0x1ba6e4u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 25969)));
    // 0x1ba6e8: 0x10830005  beq         $a0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1BA6E8u;
    {
        const bool branch_taken_0x1ba6e8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1ba6e8) {
            ctx->pc = 0x1BA700u;
            goto label_1ba700;
        }
    }
    ctx->pc = 0x1BA6F0u;
    // 0x1ba6f0: 0x10800005  beqz        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1BA6F0u;
    {
        const bool branch_taken_0x1ba6f0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ba6f0) {
            ctx->pc = 0x1BA708u;
            goto label_1ba708;
        }
    }
    ctx->pc = 0x1BA6F8u;
    // 0x1ba6f8: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1BA6F8u;
    {
        const bool branch_taken_0x1ba6f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ba6f8) {
            ctx->pc = 0x1BA708u;
            goto label_1ba708;
        }
    }
    ctx->pc = 0x1BA700u;
label_1ba700:
    // 0x1ba700: 0xc06ea48  jal         func_1BA920
    ctx->pc = 0x1BA700u;
    SET_GPR_U32(ctx, 31, 0x1BA708u);
    ctx->pc = 0x1BA704u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA700u;
            // 0x1ba704: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BA920u;
    if (runtime->hasFunction(0x1BA920u)) {
        auto targetFn = runtime->lookupFunction(0x1BA920u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA708u; }
        if (ctx->pc != 0x1BA708u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BA920_0x1ba920(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA708u; }
        if (ctx->pc != 0x1BA708u) { return; }
    }
    ctx->pc = 0x1BA708u;
label_1ba708:
    // 0x1ba708: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1ba708u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1ba70c:
    // 0x1ba70c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ba70cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ba710: 0x3e00008  jr          $ra
    ctx->pc = 0x1BA710u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BA714u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA710u;
            // 0x1ba714: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BA4C0u: goto label_1ba4c0;
            case 0x1BA4E8u: goto label_1ba4e8;
            case 0x1BA4F8u: goto label_1ba4f8;
            case 0x1BA500u: goto label_1ba500;
            case 0x1BA508u: goto label_1ba508;
            case 0x1BA50Cu: goto label_1ba50c;
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
            case 0x1BA60Cu: goto label_1ba60c;
            case 0x1BA614u: goto label_1ba614;
            case 0x1BA61Cu: goto label_1ba61c;
            case 0x1BA63Cu: goto label_1ba63c;
            case 0x1BA644u: goto label_1ba644;
            case 0x1BA64Cu: goto label_1ba64c;
            case 0x1BA65Cu: goto label_1ba65c;
            case 0x1BA664u: goto label_1ba664;
            case 0x1BA674u: goto label_1ba674;
            case 0x1BA678u: goto label_1ba678;
            case 0x1BA6B0u: goto label_1ba6b0;
            case 0x1BA6B8u: goto label_1ba6b8;
            case 0x1BA6D4u: goto label_1ba6d4;
            case 0x1BA6DCu: goto label_1ba6dc;
            case 0x1BA700u: goto label_1ba700;
            case 0x1BA708u: goto label_1ba708;
            case 0x1BA70Cu: goto label_1ba70c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BA718u;
    // 0x1ba718: 0x0  nop
    ctx->pc = 0x1ba718u;
    // NOP
    // 0x1ba71c: 0x0  nop
    ctx->pc = 0x1ba71cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
