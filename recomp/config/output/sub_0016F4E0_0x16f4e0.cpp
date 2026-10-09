#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016F4E0
// Address: 0x16f4e0 - 0x16f658
void sub_0016F4E0_0x16f4e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016F4E0_0x16f4e0");
#endif

    switch (ctx->pc) {
        case 0x16f538u: goto label_16f538;
        case 0x16f548u: goto label_16f548;
        case 0x16f55cu: goto label_16f55c;
        case 0x16f5c0u: goto label_16f5c0;
        case 0x16f5d4u: goto label_16f5d4;
        case 0x16f5ecu: goto label_16f5ec;
        case 0x16f630u: goto label_16f630;
        default: break;
    }

    ctx->pc = 0x16f4e0u;

    // 0x16f4e0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x16f4e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x16f4e4: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x16f4e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x16f4e8: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x16f4e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x16f4ec: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x16f4ecu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f4f0: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x16f4f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x16f4f4: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x16f4f4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f4f8: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x16f4f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x16f4fc: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x16f4fcu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f500: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x16f500u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x16f504: 0xe0a82d  daddu       $s5, $a3, $zero
    ctx->pc = 0x16f504u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f508: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x16f508u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x16f50c: 0x3c067fff  lui         $a2, 0x7FFF
    ctx->pc = 0x16f50cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)32767 << 16));
    // 0x16f510: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x16f510u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x16f514: 0x3a0382d  daddu       $a3, $sp, $zero
    ctx->pc = 0x16f514u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f518: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x16f518u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x16f51c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x16f51cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16f520: 0x8e630000  lw          $v1, 0x0($s3)
    ctx->pc = 0x16f520u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x16f524: 0x34c6ffff  ori         $a2, $a2, 0xFFFF
    ctx->pc = 0x16f524u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)65535);
    // 0x16f528: 0xae800000  sw          $zero, 0x0($s4)
    ctx->pc = 0x16f528u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 0));
    // 0x16f52c: 0x8c620018  lw          $v0, 0x18($v1)
    ctx->pc = 0x16f52cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x16f530: 0x40f809  jalr        $v0
    ctx->pc = 0x16F530u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x16F538u);
        ctx->pc = 0x16F534u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16F530u;
            // 0x16f534: 0xaea00000  sw          $zero, 0x0($s5) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x16F538u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16F538u: goto label_16f538;
            case 0x16F548u: goto label_16f548;
            case 0x16F55Cu: goto label_16f55c;
            case 0x16F5C0u: goto label_16f5c0;
            case 0x16F5D4u: goto label_16f5d4;
            case 0x16F5ECu: goto label_16f5ec;
            case 0x16F5F8u: goto label_16f5f8;
            case 0x16F610u: goto label_16f610;
            case 0x16F618u: goto label_16f618;
            case 0x16F61Cu: goto label_16f61c;
            case 0x16F630u: goto label_16f630;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x16F538u; }
            if (ctx->pc != 0x16F538u) { return; }
        }
        }
    }
    ctx->pc = 0x16F538u;
label_16f538:
    // 0x16f538: 0x240600cc  addiu       $a2, $zero, 0xCC
    ctx->pc = 0x16f538u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 204));
    // 0x16f53c: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x16f53cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16f540: 0xc0561d4  jal         func_158750
    ctx->pc = 0x16F540u;
    SET_GPR_U32(ctx, 31, 0x16F548u);
    ctx->pc = 0x16F544u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16F540u;
            // 0x16f544: 0x8fa50004  lw          $a1, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158750u;
    if (runtime->hasFunction(0x158750u)) {
        auto targetFn = runtime->lookupFunction(0x158750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F548u; }
        if (ctx->pc != 0x16F548u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00158750_0x158750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F548u; }
        if (ctx->pc != 0x16F548u) { return; }
    }
    ctx->pc = 0x16F548u;
label_16f548:
    // 0x16f548: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x16f548u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f54c: 0x1200002a  beqz        $s0, . + 4 + (0x2A << 2)
    ctx->pc = 0x16F54Cu;
    {
        const bool branch_taken_0x16f54c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x16F550u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16F54Cu;
            // 0x16f550: 0x3c030023  lui         $v1, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16f54c) {
            ctx->pc = 0x16F5F8u;
            goto label_16f5f8;
        }
    }
    ctx->pc = 0x16F554u;
    // 0x16f554: 0xc05616e  jal         func_1585B8
    ctx->pc = 0x16F554u;
    SET_GPR_U32(ctx, 31, 0x16F55Cu);
    ctx->pc = 0x16F558u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16F554u;
            // 0x16f558: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1585B8u;
    if (runtime->hasFunction(0x1585B8u)) {
        auto targetFn = runtime->lookupFunction(0x1585B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F55Cu; }
        if (ctx->pc != 0x16F55Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001585B8_0x1585b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F55Cu; }
        if (ctx->pc != 0x16F55Cu) { return; }
    }
    ctx->pc = 0x16F55Cu;
label_16f55c:
    // 0x16f55c: 0x30420004  andi        $v0, $v0, 0x4
    ctx->pc = 0x16f55cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)4);
    // 0x16f560: 0x1040002d  beqz        $v0, . + 4 + (0x2D << 2)
    ctx->pc = 0x16F560u;
    {
        const bool branch_taken_0x16f560 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16F564u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16F560u;
            // 0x16f564: 0x8fa50004  lw          $a1, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16f560) {
            ctx->pc = 0x16F618u;
            goto label_16f618;
        }
    }
    ctx->pc = 0x16F568u;
    // 0x16f568: 0x8fa60000  lw          $a2, 0x0($sp)
    ctx->pc = 0x16f568u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16f56c: 0x2061023  subu        $v0, $s0, $a2
    ctx->pc = 0x16f56cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 6)));
    // 0x16f570: 0x24420006  addiu       $v0, $v0, 0x6
    ctx->pc = 0x16f570u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 6));
    // 0x16f574: 0xa2102a  slt         $v0, $a1, $v0
    ctx->pc = 0x16f574u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x16f578: 0x1440001f  bnez        $v0, . + 4 + (0x1F << 2)
    ctx->pc = 0x16F578u;
    {
        const bool branch_taken_0x16f578 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16F57Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16F578u;
            // 0x16f57c: 0x3c030023  lui         $v1, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16f578) {
            ctx->pc = 0x16F5F8u;
            goto label_16f5f8;
        }
    }
    ctx->pc = 0x16F580u;
    // 0x16f580: 0x92020005  lbu         $v0, 0x5($s0)
    ctx->pc = 0x16f580u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 5)));
    // 0x16f584: 0x24040003  addiu       $a0, $zero, 0x3
    ctx->pc = 0x16f584u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x16f588: 0x210fa  dsrl        $v0, $v0, 3
    ctx->pc = 0x16f588u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> 3);
    // 0x16f58c: 0x30420007  andi        $v0, $v0, 0x7
    ctx->pc = 0x16f58cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)7);
    // 0x16f590: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x16f590u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x16f594: 0x3c030024  lui         $v1, 0x24
    ctx->pc = 0x16f594u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
    // 0x16f598: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x16f598u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x16f59c: 0x8c630900  lw          $v1, 0x900($v1)
    ctx->pc = 0x16f59cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 2304)));
    // 0x16f5a0: 0x1464001d  bne         $v1, $a0, . + 4 + (0x1D << 2)
    ctx->pc = 0x16F5A0u;
    {
        const bool branch_taken_0x16f5a0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        ctx->pc = 0x16F5A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16F5A0u;
            // 0x16f5a4: 0xae230000  sw          $v1, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16f5a0) {
            ctx->pc = 0x16F618u;
            goto label_16f618;
        }
    }
    ctx->pc = 0x16F5A8u;
    // 0x16f5a8: 0xd01023  subu        $v0, $a2, $s0
    ctx->pc = 0x16f5a8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 16)));
    // 0x16f5ac: 0x24060022  addiu       $a2, $zero, 0x22
    ctx->pc = 0x16f5acu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 34));
    // 0x16f5b0: 0x459021  addu        $s2, $v0, $a1
    ctx->pc = 0x16f5b0u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x16f5b4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16f5b4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f5b8: 0xc0561d4  jal         func_158750
    ctx->pc = 0x16F5B8u;
    SET_GPR_U32(ctx, 31, 0x16F5C0u);
    ctx->pc = 0x16F5BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16F5B8u;
            // 0x16f5bc: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158750u;
    if (runtime->hasFunction(0x158750u)) {
        auto targetFn = runtime->lookupFunction(0x158750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F5C0u; }
        if (ctx->pc != 0x16F5C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00158750_0x158750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F5C0u; }
        if (ctx->pc != 0x16F5C0u) { return; }
    }
    ctx->pc = 0x16F5C0u;
label_16f5c0:
    // 0x16f5c0: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x16f5c0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f5c4: 0x52200015  beql        $s1, $zero, . + 4 + (0x15 << 2)
    ctx->pc = 0x16F5C4u;
    {
        const bool branch_taken_0x16f5c4 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        if (branch_taken_0x16f5c4) {
            ctx->pc = 0x16F5C8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x16F5C4u;
            // 0x16f5c8: 0x8e630000  lw          $v1, 0x0($s3) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16F61Cu;
            goto label_16f61c;
        }
    }
    ctx->pc = 0x16F5CCu;
    // 0x16f5cc: 0xc05616e  jal         func_1585B8
    ctx->pc = 0x16F5CCu;
    SET_GPR_U32(ctx, 31, 0x16F5D4u);
    ctx->pc = 0x16F5D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16F5CCu;
            // 0x16f5d0: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1585B8u;
    if (runtime->hasFunction(0x1585B8u)) {
        auto targetFn = runtime->lookupFunction(0x1585B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F5D4u; }
        if (ctx->pc != 0x16F5D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001585B8_0x1585b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F5D4u; }
        if (ctx->pc != 0x16F5D4u) { return; }
    }
    ctx->pc = 0x16F5D4u;
label_16f5d4:
    // 0x16f5d4: 0x30420020  andi        $v0, $v0, 0x20
    ctx->pc = 0x16f5d4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)32);
    // 0x16f5d8: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x16F5D8u;
    {
        const bool branch_taken_0x16f5d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16F5DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16F5D8u;
            // 0x16f5dc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16f5d8) {
            ctx->pc = 0x16F618u;
            goto label_16f618;
        }
    }
    ctx->pc = 0x16F5E0u;
    // 0x16f5e0: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x16f5e0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f5e4: 0xc0561d4  jal         func_158750
    ctx->pc = 0x16F5E4u;
    SET_GPR_U32(ctx, 31, 0x16F5ECu);
    ctx->pc = 0x16F5E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16F5E4u;
            // 0x16f5e8: 0x24060002  addiu       $a2, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158750u;
    if (runtime->hasFunction(0x158750u)) {
        auto targetFn = runtime->lookupFunction(0x158750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F5ECu; }
        if (ctx->pc != 0x16F5ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00158750_0x158750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16F5ECu; }
        if (ctx->pc != 0x16F5ECu) { return; }
    }
    ctx->pc = 0x16F5ECu;
label_16f5ec:
    // 0x16f5ec: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x16F5ECu;
    {
        const bool branch_taken_0x16f5ec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16F5F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16F5ECu;
            // 0x16f5f0: 0x511023  subu        $v0, $v0, $s1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16f5ec) {
            ctx->pc = 0x16F610u;
            goto label_16f610;
        }
    }
    ctx->pc = 0x16F5F4u;
    // 0x16f5f4: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x16f5f4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
label_16f5f8:
    // 0x16f5f8: 0x2463f1bc  addiu       $v1, $v1, -0xE44
    ctx->pc = 0x16f5f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294963644));
    // 0x16f5fc: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x16f5fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x16f600: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x16f600u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x16f604: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x16F604u;
    {
        const bool branch_taken_0x16f604 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16F608u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16F604u;
            // 0x16f608: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16f604) {
            ctx->pc = 0x16F618u;
            goto label_16f618;
        }
    }
    ctx->pc = 0x16F60Cu;
    // 0x16f60c: 0x0  nop
    ctx->pc = 0x16f60cu;
    // NOP
label_16f610:
    // 0x16f610: 0xae910000  sw          $s1, 0x0($s4)
    ctx->pc = 0x16f610u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 17));
    // 0x16f614: 0xaea20000  sw          $v0, 0x0($s5)
    ctx->pc = 0x16f614u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 2));
label_16f618:
    // 0x16f618: 0x8e630000  lw          $v1, 0x0($s3)
    ctx->pc = 0x16f618u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
label_16f61c:
    // 0x16f61c: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x16f61cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16f620: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x16f620u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16f624: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x16f624u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x16f628: 0x40f809  jalr        $v0
    ctx->pc = 0x16F628u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x16F630u);
        ctx->pc = 0x16F62Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16F628u;
            // 0x16f62c: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x16F630u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16F538u: goto label_16f538;
            case 0x16F548u: goto label_16f548;
            case 0x16F55Cu: goto label_16f55c;
            case 0x16F5C0u: goto label_16f5c0;
            case 0x16F5D4u: goto label_16f5d4;
            case 0x16F5ECu: goto label_16f5ec;
            case 0x16F5F8u: goto label_16f5f8;
            case 0x16F610u: goto label_16f610;
            case 0x16F618u: goto label_16f618;
            case 0x16F61Cu: goto label_16f61c;
            case 0x16F630u: goto label_16f630;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x16F630u; }
            if (ctx->pc != 0x16F630u) { return; }
        }
        }
    }
    ctx->pc = 0x16F630u;
label_16f630:
    // 0x16f630: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x16f630u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16f634: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x16f634u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16f638: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x16f638u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16f63c: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x16f63cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16f640: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x16f640u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16f644: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x16f644u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x16f648: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x16f648u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x16f64c: 0x3e00008  jr          $ra
    ctx->pc = 0x16F64Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16F650u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16F64Cu;
            // 0x16f650: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16F538u: goto label_16f538;
            case 0x16F548u: goto label_16f548;
            case 0x16F55Cu: goto label_16f55c;
            case 0x16F5C0u: goto label_16f5c0;
            case 0x16F5D4u: goto label_16f5d4;
            case 0x16F5ECu: goto label_16f5ec;
            case 0x16F5F8u: goto label_16f5f8;
            case 0x16F610u: goto label_16f610;
            case 0x16F618u: goto label_16f618;
            case 0x16F61Cu: goto label_16f61c;
            case 0x16F630u: goto label_16f630;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16F654u;
    // 0x16f654: 0x0  nop
    ctx->pc = 0x16f654u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
