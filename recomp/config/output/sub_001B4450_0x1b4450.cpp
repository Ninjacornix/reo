#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B4450
// Address: 0x1b4450 - 0x1b4590
void sub_001B4450_0x1b4450(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B4450_0x1b4450");
#endif

    switch (ctx->pc) {
        case 0x1b4464u: goto label_1b4464;
        case 0x1b448cu: goto label_1b448c;
        case 0x1b4534u: goto label_1b4534;
        case 0x1b4544u: goto label_1b4544;
        case 0x1b4548u: goto label_1b4548;
        case 0x1b456cu: goto label_1b456c;
        default: break;
    }

    ctx->pc = 0x1b4450u;

label_1b4450:
    // 0x1b4450: 0x3c0c0031  lui         $t4, 0x31
    ctx->pc = 0x1b4450u;
    SET_GPR_S32(ctx, 12, (int32_t)((uint32_t)49 << 16));
    // 0x1b4454: 0x3c0b0031  lui         $t3, 0x31
    ctx->pc = 0x1b4454u;
    SET_GPR_S32(ctx, 11, (int32_t)((uint32_t)49 << 16));
    // 0x1b4458: 0x258c51c0  addiu       $t4, $t4, 0x51C0
    ctx->pc = 0x1b4458u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 12), 20928));
    // 0x1b445c: 0x256b51d0  addiu       $t3, $t3, 0x51D0
    ctx->pc = 0x1b445cu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 20944));
    // 0x1b4460: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1b4460u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1b4464:
    // 0x1b4464: 0x85630000  lh          $v1, 0x0($t3)
    ctx->pc = 0x1b4464u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x1b4468: 0x1060001f  beqz        $v1, . + 4 + (0x1F << 2)
    ctx->pc = 0x1B4468u;
    {
        const bool branch_taken_0x1b4468 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b4468) {
            ctx->pc = 0x1B44E8u;
            goto label_1b44e8;
        }
    }
    ctx->pc = 0x1B4470u;
    // 0x1b4470: 0x85660004  lh          $a2, 0x4($t3)
    ctx->pc = 0x1b4470u;
    SET_GPR_S32(ctx, 6, (int16_t)READ16(ADD32(GPR_U32(ctx, 11), 4)));
    // 0x1b4474: 0x258a0010  addiu       $t2, $t4, 0x10
    ctx->pc = 0x1b4474u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 12), 16));
    // 0x1b4478: 0x91630008  lbu         $v1, 0x8($t3)
    ctx->pc = 0x1b4478u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 8)));
    // 0x1b447c: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1b447cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b4480: 0x9167000b  lbu         $a3, 0xB($t3)
    ctx->pc = 0x1b4480u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 11)));
    // 0x1b4484: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1B4484u;
    {
        const bool branch_taken_0x1b4484 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B4488u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4484u;
            // 0x1b4488: 0xc32821  addu        $a1, $a2, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4484) {
            ctx->pc = 0x1B44DCu;
            goto label_1b44dc;
        }
    }
    ctx->pc = 0x1B448Cu;
label_1b448c:
    // 0x1b448c: 0x85430000  lh          $v1, 0x0($t2)
    ctx->pc = 0x1b448cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x1b4490: 0x10600010  beqz        $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1B4490u;
    {
        const bool branch_taken_0x1b4490 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b4490) {
            ctx->pc = 0x1B44D4u;
            goto label_1b44d4;
        }
    }
    ctx->pc = 0x1B4498u;
    // 0x1b4498: 0x9143000b  lbu         $v1, 0xB($t2)
    ctx->pc = 0x1b4498u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 10), 11)));
    // 0x1b449c: 0x67082a  slt         $at, $v1, $a3
    ctx->pc = 0x1b449cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 7)) ? 1 : 0);
    // 0x1b44a0: 0x1020000c  beqz        $at, . + 4 + (0xC << 2)
    ctx->pc = 0x1B44A0u;
    {
        const bool branch_taken_0x1b44a0 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b44a0) {
            ctx->pc = 0x1B44D4u;
            goto label_1b44d4;
        }
    }
    ctx->pc = 0x1B44A8u;
    // 0x1b44a8: 0x85440004  lh          $a0, 0x4($t2)
    ctx->pc = 0x1b44a8u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 10), 4)));
    // 0x1b44ac: 0x85082a  slt         $at, $a0, $a1
    ctx->pc = 0x1b44acu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x1b44b0: 0x10200008  beqz        $at, . + 4 + (0x8 << 2)
    ctx->pc = 0x1B44B0u;
    {
        const bool branch_taken_0x1b44b0 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b44b0) {
            ctx->pc = 0x1B44D4u;
            goto label_1b44d4;
        }
    }
    ctx->pc = 0x1B44B8u;
    // 0x1b44b8: 0x91430008  lbu         $v1, 0x8($t2)
    ctx->pc = 0x1b44b8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 10), 8)));
    // 0x1b44bc: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x1b44bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1b44c0: 0xc3082a  slt         $at, $a2, $v1
    ctx->pc = 0x1b44c0u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1b44c4: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B44C4u;
    {
        const bool branch_taken_0x1b44c4 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b44c4) {
            ctx->pc = 0x1B44D4u;
            goto label_1b44d4;
        }
    }
    ctx->pc = 0x1B44CCu;
    // 0x1b44cc: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1B44CCu;
    {
        const bool branch_taken_0x1b44cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B44D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B44CCu;
            // 0x1b44d0: 0xa5600000  sh          $zero, 0x0($t3) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 11), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b44cc) {
            ctx->pc = 0x1B44E8u;
            goto label_1b44e8;
        }
    }
    ctx->pc = 0x1B44D4u;
label_1b44d4:
    // 0x1b44d4: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1b44d4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1b44d8: 0x254a008c  addiu       $t2, $t2, 0x8C
    ctx->pc = 0x1b44d8u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 140));
label_1b44dc:
    // 0x1b44dc: 0x29030020  slti        $v1, $t0, 0x20
    ctx->pc = 0x1b44dcu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 8) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x1b44e0: 0x1460ffea  bnez        $v1, . + 4 + (-0x16 << 2)
    ctx->pc = 0x1B44E0u;
    {
        const bool branch_taken_0x1b44e0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b44e0) {
            ctx->pc = 0x1B448Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b448c;
        }
    }
    ctx->pc = 0x1B44E8u;
label_1b44e8:
    // 0x1b44e8: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1b44e8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1b44ec: 0x29230020  slti        $v1, $t1, 0x20
    ctx->pc = 0x1b44ecu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 9) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x1b44f0: 0x1460ffdc  bnez        $v1, . + 4 + (-0x24 << 2)
    ctx->pc = 0x1B44F0u;
    {
        const bool branch_taken_0x1b44f0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B44F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B44F0u;
            // 0x1b44f4: 0x256b008c  addiu       $t3, $t3, 0x8C (Delay Slot)
        SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 140));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b44f0) {
            ctx->pc = 0x1B4464u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b4464;
        }
    }
    ctx->pc = 0x1B44F8u;
    // 0x1b44f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1B44F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B4450u: goto label_1b4450;
            case 0x1B4464u: goto label_1b4464;
            case 0x1B448Cu: goto label_1b448c;
            case 0x1B44D4u: goto label_1b44d4;
            case 0x1B44DCu: goto label_1b44dc;
            case 0x1B44E8u: goto label_1b44e8;
            case 0x1B4534u: goto label_1b4534;
            case 0x1B4544u: goto label_1b4544;
            case 0x1B4548u: goto label_1b4548;
            case 0x1B456Cu: goto label_1b456c;
            case 0x1B457Cu: goto label_1b457c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B4500u;
    // 0x1b4500: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1b4500u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1b4504: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b4504u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b4508: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1b4508u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1b450c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b450cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b4510: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b4510u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b4514: 0x902343d6  lbu         $v1, 0x43D6($at)
    ctx->pc = 0x1b4514u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17366)));
    // 0x1b4518: 0x10600018  beqz        $v1, . + 4 + (0x18 << 2)
    ctx->pc = 0x1B4518u;
    {
        const bool branch_taken_0x1b4518 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B451Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4518u;
            // 0x1b451c: 0x3c01004c  lui         $at, 0x4C (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4518) {
            ctx->pc = 0x1B457Cu;
            goto label_1b457c;
        }
    }
    ctx->pc = 0x1B4520u;
    // 0x1b4520: 0x9023ae94  lbu         $v1, -0x516C($at)
    ctx->pc = 0x1b4520u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294946452)));
    // 0x1b4524: 0x14600015  bnez        $v1, . + 4 + (0x15 << 2)
    ctx->pc = 0x1B4524u;
    {
        const bool branch_taken_0x1b4524 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b4524) {
            ctx->pc = 0x1B457Cu;
            goto label_1b457c;
        }
    }
    ctx->pc = 0x1B452Cu;
    // 0x1b452c: 0xc06d114  jal         func_1B4450
    ctx->pc = 0x1B452Cu;
    SET_GPR_U32(ctx, 31, 0x1B4534u);
    ctx->pc = 0x1B4450u;
    goto label_1b4450;
    ctx->pc = 0x1B4534u;
label_1b4534:
    // 0x1b4534: 0x3c110031  lui         $s1, 0x31
    ctx->pc = 0x1b4534u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)49 << 16));
    // 0x1b4538: 0x2404fffe  addiu       $a0, $zero, -0x2
    ctx->pc = 0x1b4538u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x1b453c: 0xc06d584  jal         func_1B5610
    ctx->pc = 0x1B453Cu;
    SET_GPR_U32(ctx, 31, 0x1B4544u);
    ctx->pc = 0x1B4540u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B453Cu;
            // 0x1b4540: 0x263151d0  addiu       $s1, $s1, 0x51D0 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 20944));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B5610u;
    if (runtime->hasFunction(0x1B5610u)) {
        auto targetFn = runtime->lookupFunction(0x1B5610u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4544u; }
        if (ctx->pc != 0x1B4544u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B5610_0x1b5610(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4544u; }
        if (ctx->pc != 0x1B4544u) { return; }
    }
    ctx->pc = 0x1B4544u;
label_1b4544:
    // 0x1b4544: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1b4544u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1b4548:
    // 0x1b4548: 0x86230000  lh          $v1, 0x0($s1)
    ctx->pc = 0x1b4548u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1b454c: 0x10600007  beqz        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1B454Cu;
    {
        const bool branch_taken_0x1b454c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b454c) {
            ctx->pc = 0x1B456Cu;
            goto label_1b456c;
        }
    }
    ctx->pc = 0x1B4554u;
    // 0x1b4554: 0x86240002  lh          $a0, 0x2($s1)
    ctx->pc = 0x1b4554u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x1b4558: 0x86250004  lh          $a1, 0x4($s1)
    ctx->pc = 0x1b4558u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1b455c: 0x92260008  lbu         $a2, 0x8($s1)
    ctx->pc = 0x1b455cu;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1b4560: 0x9228000a  lbu         $t0, 0xA($s1)
    ctx->pc = 0x1b4560u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 10)));
    // 0x1b4564: 0xc06d040  jal         func_1B4100
    ctx->pc = 0x1B4564u;
    SET_GPR_U32(ctx, 31, 0x1B456Cu);
    ctx->pc = 0x1B4568u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4564u;
            // 0x1b4568: 0x2627000c  addiu       $a3, $s1, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 17), 12));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B4100u;
    if (runtime->hasFunction(0x1B4100u)) {
        auto targetFn = runtime->lookupFunction(0x1B4100u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B456Cu; }
        if (ctx->pc != 0x1B456Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B4100_0x1b4100(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B456Cu; }
        if (ctx->pc != 0x1B456Cu) { return; }
    }
    ctx->pc = 0x1B456Cu;
label_1b456c:
    // 0x1b456c: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1b456cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1b4570: 0x2a030020  slti        $v1, $s0, 0x20
    ctx->pc = 0x1b4570u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x1b4574: 0x1460fff4  bnez        $v1, . + 4 + (-0xC << 2)
    ctx->pc = 0x1B4574u;
    {
        const bool branch_taken_0x1b4574 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B4578u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4574u;
            // 0x1b4578: 0x2631008c  addiu       $s1, $s1, 0x8C (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 140));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4574) {
            ctx->pc = 0x1B4548u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b4548;
        }
    }
    ctx->pc = 0x1B457Cu;
label_1b457c:
    // 0x1b457c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1b457cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b4580: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b4580u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b4584: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b4584u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b4588: 0x3e00008  jr          $ra
    ctx->pc = 0x1B4588u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B458Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4588u;
            // 0x1b458c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B4450u: goto label_1b4450;
            case 0x1B4464u: goto label_1b4464;
            case 0x1B448Cu: goto label_1b448c;
            case 0x1B44D4u: goto label_1b44d4;
            case 0x1B44DCu: goto label_1b44dc;
            case 0x1B44E8u: goto label_1b44e8;
            case 0x1B4534u: goto label_1b4534;
            case 0x1B4544u: goto label_1b4544;
            case 0x1B4548u: goto label_1b4548;
            case 0x1B456Cu: goto label_1b456c;
            case 0x1B457Cu: goto label_1b457c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B4590u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
