#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C15E8
// Address: 0x1c15e8 - 0x1c1728
void sub_001C15E8_0x1c15e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C15E8_0x1c15e8");
#endif

    switch (ctx->pc) {
        case 0x1c160cu: goto label_1c160c;
        case 0x1c1638u: goto label_1c1638;
        case 0x1c1640u: goto label_1c1640;
        case 0x1c1658u: goto label_1c1658;
        case 0x1c16b8u: goto label_1c16b8;
        case 0x1c16d0u: goto label_1c16d0;
        case 0x1c16f8u: goto label_1c16f8;
        case 0x1c1710u: goto label_1c1710;
        default: break;
    }

    ctx->pc = 0x1c15e8u;

label_1c15e8:
    // 0x1c15e8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c15e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c15ec: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x1c15ecu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x1c15f0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1c15f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1c15f4: 0x806252d8  lb          $v0, 0x52D8($v1)
    ctx->pc = 0x1c15f4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 21208)));
    // 0x1c15f8: 0x247052d8  addiu       $s0, $v1, 0x52D8
    ctx->pc = 0x1c15f8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), 21208));
    // 0x1c15fc: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C15FCu;
    {
        const bool branch_taken_0x1c15fc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C1600u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C15FCu;
            // 0x1c1600: 0xffbf0010  sd          $ra, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c15fc) {
            ctx->pc = 0x1C160Cu;
            goto label_1c160c;
        }
    }
    ctx->pc = 0x1C1604u;
    // 0x1c1604: 0xc07055e  jal         func_1C1578
    ctx->pc = 0x1C1604u;
    SET_GPR_U32(ctx, 31, 0x1C160Cu);
    ctx->pc = 0x1C1578u;
    if (runtime->hasFunction(0x1C1578u)) {
        auto targetFn = runtime->lookupFunction(0x1C1578u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C160Cu; }
        if (ctx->pc != 0x1C160Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C1578_0x1c1578(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C160Cu; }
        if (ctx->pc != 0x1C160Cu) { return; }
    }
    ctx->pc = 0x1C160Cu;
label_1c160c:
    // 0x1c160c: 0x82020004  lb          $v0, 0x4($s0)
    ctx->pc = 0x1c160cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1c1610: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c1610u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c1614: 0x38420054  xori        $v0, $v0, 0x54
    ctx->pc = 0x1c1614u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)84);
    // 0x1c1618: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1c1618u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c161c: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x1c161cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x1c1620: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1620u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C1624u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1620u;
            // 0x1c1624: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C15E8u: goto label_1c15e8;
            case 0x1C160Cu: goto label_1c160c;
            case 0x1C1638u: goto label_1c1638;
            case 0x1C1640u: goto label_1c1640;
            case 0x1C1650u: goto label_1c1650;
            case 0x1C1658u: goto label_1c1658;
            case 0x1C1678u: goto label_1c1678;
            case 0x1C167Cu: goto label_1c167c;
            case 0x1C16B8u: goto label_1c16b8;
            case 0x1C16C8u: goto label_1c16c8;
            case 0x1C16D0u: goto label_1c16d0;
            case 0x1C16DCu: goto label_1c16dc;
            case 0x1C16F8u: goto label_1c16f8;
            case 0x1C1708u: goto label_1c1708;
            case 0x1C1710u: goto label_1c1710;
            case 0x1C1718u: goto label_1c1718;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C1628u;
    // 0x1c1628: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c1628u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c162c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c162cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c1630: 0xc0451b4  jal         func_1146D0
    ctx->pc = 0x1C1630u;
    SET_GPR_U32(ctx, 31, 0x1C1638u);
    ctx->pc = 0x1C1634u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1630u;
            // 0x1c1634: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1146D0u;
    if (runtime->hasFunction(0x1146D0u)) {
        auto targetFn = runtime->lookupFunction(0x1146D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1638u; }
        if (ctx->pc != 0x1C1638u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001146D0_0x1146d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1638u; }
        if (ctx->pc != 0x1C1638u) { return; }
    }
    ctx->pc = 0x1C1638u;
label_1c1638:
    // 0x1c1638: 0xc07057a  jal         func_1C15E8
    ctx->pc = 0x1C1638u;
    SET_GPR_U32(ctx, 31, 0x1C1640u);
    ctx->pc = 0x1C15E8u;
    goto label_1c15e8;
    ctx->pc = 0x1C1640u;
label_1c1640:
    // 0x1c1640: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C1640u;
    {
        const bool branch_taken_0x1c1640 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C1644u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1640u;
            // 0x1c1644: 0x3c020023  lui         $v0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1640) {
            ctx->pc = 0x1C1650u;
            goto label_1c1650;
        }
    }
    ctx->pc = 0x1C1648u;
    // 0x1c1648: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1C1648u;
    {
        const bool branch_taken_0x1c1648 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C164Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1648u;
            // 0x1c164c: 0x904252d4  lbu         $v0, 0x52D4($v0) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 21204)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1648) {
            ctx->pc = 0x1C167Cu;
            goto label_1c167c;
        }
    }
    ctx->pc = 0x1C1650u;
label_1c1650:
    // 0x1c1650: 0xc0451b4  jal         func_1146D0
    ctx->pc = 0x1C1650u;
    SET_GPR_U32(ctx, 31, 0x1C1658u);
    ctx->pc = 0x1C1654u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1650u;
            // 0x1c1654: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1146D0u;
    if (runtime->hasFunction(0x1146D0u)) {
        auto targetFn = runtime->lookupFunction(0x1146D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1658u; }
        if (ctx->pc != 0x1C1658u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001146D0_0x1146d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1658u; }
        if (ctx->pc != 0x1C1658u) { return; }
    }
    ctx->pc = 0x1C1658u;
label_1c1658:
    // 0x1c1658: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x1c1658u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c165c: 0x31342  srl         $v0, $v1, 13
    ctx->pc = 0x1c165cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 13));
    // 0x1c1660: 0x30420007  andi        $v0, $v0, 0x7
    ctx->pc = 0x1c1660u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)7);
    // 0x1c1664: 0x54400004  bnel        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x1C1664u;
    {
        const bool branch_taken_0x1c1664 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1c1664) {
            ctx->pc = 0x1C1668u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1664u;
            // 0x1c1668: 0x31402  srl         $v0, $v1, 16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1C1678u;
            goto label_1c1678;
        }
    }
    ctx->pc = 0x1C166Cu;
    // 0x1c166c: 0x31102  srl         $v0, $v1, 4
    ctx->pc = 0x1c166cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 4));
    // 0x1c1670: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1C1670u;
    {
        const bool branch_taken_0x1c1670 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C1674u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1670u;
            // 0x1c1674: 0x30420001  andi        $v0, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1670) {
            ctx->pc = 0x1C167Cu;
            goto label_1c167c;
        }
    }
    ctx->pc = 0x1C1678u;
label_1c1678:
    // 0x1c1678: 0x3042001f  andi        $v0, $v0, 0x1F
    ctx->pc = 0x1c1678u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)31);
label_1c167c:
    // 0x1c167c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c167cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c1680: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1680u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C1684u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1680u;
            // 0x1c1684: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C15E8u: goto label_1c15e8;
            case 0x1C160Cu: goto label_1c160c;
            case 0x1C1638u: goto label_1c1638;
            case 0x1C1640u: goto label_1c1640;
            case 0x1C1650u: goto label_1c1650;
            case 0x1C1658u: goto label_1c1658;
            case 0x1C1678u: goto label_1c1678;
            case 0x1C167Cu: goto label_1c167c;
            case 0x1C16B8u: goto label_1c16b8;
            case 0x1C16C8u: goto label_1c16c8;
            case 0x1C16D0u: goto label_1c16d0;
            case 0x1C16DCu: goto label_1c16dc;
            case 0x1C16F8u: goto label_1c16f8;
            case 0x1C1708u: goto label_1c1708;
            case 0x1C1710u: goto label_1c1710;
            case 0x1C1718u: goto label_1c1718;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C1688u;
    // 0x1c1688: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1c1688u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1c168c: 0x244752d0  addiu       $a3, $v0, 0x52D0
    ctx->pc = 0x1c168cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 2), 21200));
    // 0x1c1690: 0x68830007  ldl         $v1, 0x7($a0)
    ctx->pc = 0x1c1690u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x1c1694: 0x6c830000  ldr         $v1, 0x0($a0)
    ctx->pc = 0x1c1694u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x1c1698: 0xb0e30007  sdl         $v1, 0x7($a3)
    ctx->pc = 0x1c1698u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1c169c: 0x3e00008  jr          $ra
    ctx->pc = 0x1C169Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C16A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C169Cu;
            // 0x1c16a0: 0xb4e30000  sdr         $v1, 0x0($a3) (Delay Slot)
        { uint32_t addr = ADD32(GPR_U32(ctx, 7), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C15E8u: goto label_1c15e8;
            case 0x1C160Cu: goto label_1c160c;
            case 0x1C1638u: goto label_1c1638;
            case 0x1C1640u: goto label_1c1640;
            case 0x1C1650u: goto label_1c1650;
            case 0x1C1658u: goto label_1c1658;
            case 0x1C1678u: goto label_1c1678;
            case 0x1C167Cu: goto label_1c167c;
            case 0x1C16B8u: goto label_1c16b8;
            case 0x1C16C8u: goto label_1c16c8;
            case 0x1C16D0u: goto label_1c16d0;
            case 0x1C16DCu: goto label_1c16dc;
            case 0x1C16F8u: goto label_1c16f8;
            case 0x1C1708u: goto label_1c1708;
            case 0x1C1710u: goto label_1c1710;
            case 0x1C1718u: goto label_1c1718;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C16A4u;
    // 0x1c16a4: 0x0  nop
    ctx->pc = 0x1c16a4u;
    // NOP
    // 0x1c16a8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c16a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c16ac: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c16acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c16b0: 0xc07057a  jal         func_1C15E8
    ctx->pc = 0x1C16B0u;
    SET_GPR_U32(ctx, 31, 0x1C16B8u);
    ctx->pc = 0x1C15E8u;
    goto label_1c15e8;
    ctx->pc = 0x1C16B8u;
label_1c16b8:
    // 0x1c16b8: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C16B8u;
    {
        const bool branch_taken_0x1c16b8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C16BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C16B8u;
            // 0x1c16bc: 0x3c030023  lui         $v1, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c16b8) {
            ctx->pc = 0x1C16C8u;
            goto label_1c16c8;
        }
    }
    ctx->pc = 0x1C16C0u;
    // 0x1c16c0: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1C16C0u;
    {
        const bool branch_taken_0x1c16c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C16C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C16C0u;
            // 0x1c16c4: 0x906252d2  lbu         $v0, 0x52D2($v1) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 21202)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c16c0) {
            ctx->pc = 0x1C16DCu;
            goto label_1c16dc;
        }
    }
    ctx->pc = 0x1C16C8u;
label_1c16c8:
    // 0x1c16c8: 0xc0451b4  jal         func_1146D0
    ctx->pc = 0x1C16C8u;
    SET_GPR_U32(ctx, 31, 0x1C16D0u);
    ctx->pc = 0x1C16CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C16C8u;
            // 0x1c16cc: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1146D0u;
    if (runtime->hasFunction(0x1146D0u)) {
        auto targetFn = runtime->lookupFunction(0x1146D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C16D0u; }
        if (ctx->pc != 0x1C16D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001146D0_0x1146d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C16D0u; }
        if (ctx->pc != 0x1C16D0u) { return; }
    }
    ctx->pc = 0x1C16D0u;
label_1c16d0:
    // 0x1c16d0: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x1c16d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c16d4: 0x21042  srl         $v0, $v0, 1
    ctx->pc = 0x1c16d4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 1));
    // 0x1c16d8: 0x30420003  andi        $v0, $v0, 0x3
    ctx->pc = 0x1c16d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)3);
label_1c16dc:
    // 0x1c16dc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c16dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c16e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1C16E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C16E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C16E0u;
            // 0x1c16e4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C15E8u: goto label_1c15e8;
            case 0x1C160Cu: goto label_1c160c;
            case 0x1C1638u: goto label_1c1638;
            case 0x1C1640u: goto label_1c1640;
            case 0x1C1650u: goto label_1c1650;
            case 0x1C1658u: goto label_1c1658;
            case 0x1C1678u: goto label_1c1678;
            case 0x1C167Cu: goto label_1c167c;
            case 0x1C16B8u: goto label_1c16b8;
            case 0x1C16C8u: goto label_1c16c8;
            case 0x1C16D0u: goto label_1c16d0;
            case 0x1C16DCu: goto label_1c16dc;
            case 0x1C16F8u: goto label_1c16f8;
            case 0x1C1708u: goto label_1c1708;
            case 0x1C1710u: goto label_1c1710;
            case 0x1C1718u: goto label_1c1718;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C16E8u;
    // 0x1c16e8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c16e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c16ec: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c16ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c16f0: 0xc07057a  jal         func_1C15E8
    ctx->pc = 0x1C16F0u;
    SET_GPR_U32(ctx, 31, 0x1C16F8u);
    ctx->pc = 0x1C15E8u;
    goto label_1c15e8;
    ctx->pc = 0x1C16F8u;
label_1c16f8:
    // 0x1c16f8: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C16F8u;
    {
        const bool branch_taken_0x1c16f8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C16FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C16F8u;
            // 0x1c16fc: 0x3c030023  lui         $v1, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c16f8) {
            ctx->pc = 0x1C1708u;
            goto label_1c1708;
        }
    }
    ctx->pc = 0x1C1700u;
    // 0x1c1700: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1C1700u;
    {
        const bool branch_taken_0x1c1700 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C1704u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1700u;
            // 0x1c1704: 0x906252d5  lbu         $v0, 0x52D5($v1) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 21205)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1700) {
            ctx->pc = 0x1C1718u;
            goto label_1c1718;
        }
    }
    ctx->pc = 0x1C1708u;
label_1c1708:
    // 0x1c1708: 0xc0451b4  jal         func_1146D0
    ctx->pc = 0x1C1708u;
    SET_GPR_U32(ctx, 31, 0x1C1710u);
    ctx->pc = 0x1C170Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1708u;
            // 0x1c170c: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1146D0u;
    if (runtime->hasFunction(0x1146D0u)) {
        auto targetFn = runtime->lookupFunction(0x1146D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1710u; }
        if (ctx->pc != 0x1C1710u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001146D0_0x1146d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1710u; }
        if (ctx->pc != 0x1C1710u) { return; }
    }
    ctx->pc = 0x1C1710u;
label_1c1710:
    // 0x1c1710: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x1c1710u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c1714: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x1c1714u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
label_1c1718:
    // 0x1c1718: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c1718u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c171c: 0x3e00008  jr          $ra
    ctx->pc = 0x1C171Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C1720u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C171Cu;
            // 0x1c1720: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C15E8u: goto label_1c15e8;
            case 0x1C160Cu: goto label_1c160c;
            case 0x1C1638u: goto label_1c1638;
            case 0x1C1640u: goto label_1c1640;
            case 0x1C1650u: goto label_1c1650;
            case 0x1C1658u: goto label_1c1658;
            case 0x1C1678u: goto label_1c1678;
            case 0x1C167Cu: goto label_1c167c;
            case 0x1C16B8u: goto label_1c16b8;
            case 0x1C16C8u: goto label_1c16c8;
            case 0x1C16D0u: goto label_1c16d0;
            case 0x1C16DCu: goto label_1c16dc;
            case 0x1C16F8u: goto label_1c16f8;
            case 0x1C1708u: goto label_1c1708;
            case 0x1C1710u: goto label_1c1710;
            case 0x1C1718u: goto label_1c1718;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C1724u;
    // 0x1c1724: 0x0  nop
    ctx->pc = 0x1c1724u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
