#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C17E0
// Address: 0x1c17e0 - 0x1c18b0
void sub_001C17E0_0x1c17e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C17E0_0x1c17e0");
#endif

    switch (ctx->pc) {
        case 0x1c17f0u: goto label_1c17f0;
        case 0x1c1808u: goto label_1c1808;
        case 0x1c1830u: goto label_1c1830;
        case 0x1c1858u: goto label_1c1858;
        case 0x1c1870u: goto label_1c1870;
        case 0x1c1898u: goto label_1c1898;
        default: break;
    }

    ctx->pc = 0x1c17e0u;

    // 0x1c17e0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c17e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c17e4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c17e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c17e8: 0xc07057a  jal         func_1C15E8
    ctx->pc = 0x1C17E8u;
    SET_GPR_U32(ctx, 31, 0x1C17F0u);
    ctx->pc = 0x1C15E8u;
    if (runtime->hasFunction(0x1C15E8u)) {
        auto targetFn = runtime->lookupFunction(0x1C15E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C17F0u; }
        if (ctx->pc != 0x1C17F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C15E8_0x1c15e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C17F0u; }
        if (ctx->pc != 0x1C17F0u) { return; }
    }
    ctx->pc = 0x1C17F0u;
label_1c17f0:
    // 0x1c17f0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C17F0u;
    {
        const bool branch_taken_0x1c17f0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C17F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C17F0u;
            // 0x1c17f4: 0x3c020023  lui         $v0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c17f0) {
            ctx->pc = 0x1C1800u;
            goto label_1c1800;
        }
    }
    ctx->pc = 0x1C17F8u;
    // 0x1c17f8: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1C17F8u;
    {
        const bool branch_taken_0x1c17f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C17FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C17F8u;
            // 0x1c17fc: 0x904252d6  lbu         $v0, 0x52D6($v0) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 21206)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c17f8) {
            ctx->pc = 0x1C183Cu;
            goto label_1c183c;
        }
    }
    ctx->pc = 0x1C1800u;
label_1c1800:
    // 0x1c1800: 0xc0451b4  jal         func_1146D0
    ctx->pc = 0x1C1800u;
    SET_GPR_U32(ctx, 31, 0x1C1808u);
    ctx->pc = 0x1C1804u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1800u;
            // 0x1c1804: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1146D0u;
    if (runtime->hasFunction(0x1146D0u)) {
        auto targetFn = runtime->lookupFunction(0x1146D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1808u; }
        if (ctx->pc != 0x1C1808u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001146D0_0x1146d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1808u; }
        if (ctx->pc != 0x1C1808u) { return; }
    }
    ctx->pc = 0x1C1808u;
label_1c1808:
    // 0x1c1808: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x1c1808u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c180c: 0x21342  srl         $v0, $v0, 13
    ctx->pc = 0x1c180cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 13));
    // 0x1c1810: 0x30420007  andi        $v0, $v0, 0x7
    ctx->pc = 0x1c1810u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)7);
    // 0x1c1814: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C1814u;
    {
        const bool branch_taken_0x1c1814 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C1818u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1814u;
            // 0x1c1818: 0x37a40004  ori         $a0, $sp, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 29) | (uint64_t)(uint16_t)4);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1814) {
            ctx->pc = 0x1C1824u;
            goto label_1c1824;
        }
    }
    ctx->pc = 0x1C181Cu;
    // 0x1c181c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1C181Cu;
    {
        const bool branch_taken_0x1c181c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C1820u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C181Cu;
            // 0x1c1820: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c181c) {
            ctx->pc = 0x1C183Cu;
            goto label_1c183c;
        }
    }
    ctx->pc = 0x1C1824u;
label_1c1824:
    // 0x1c1824: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1c1824u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c1828: 0xc04524c  jal         func_114930
    ctx->pc = 0x1C1828u;
    SET_GPR_U32(ctx, 31, 0x1C1830u);
    ctx->pc = 0x1C182Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1828u;
            // 0x1c182c: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114930u;
    if (runtime->hasFunction(0x114930u)) {
        auto targetFn = runtime->lookupFunction(0x114930u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1830u; }
        if (ctx->pc != 0x1C1830u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114930_0x114930(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1830u; }
        if (ctx->pc != 0x1C1830u) { return; }
    }
    ctx->pc = 0x1C1830u;
label_1c1830:
    // 0x1c1830: 0x93a30004  lbu         $v1, 0x4($sp)
    ctx->pc = 0x1c1830u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x1c1834: 0x31902  srl         $v1, $v1, 4
    ctx->pc = 0x1c1834u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 4));
    // 0x1c1838: 0x30620001  andi        $v0, $v1, 0x1
    ctx->pc = 0x1c1838u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
label_1c183c:
    // 0x1c183c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c183cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c1840: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1840u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C1844u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1840u;
            // 0x1c1844: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C17F0u: goto label_1c17f0;
            case 0x1C1800u: goto label_1c1800;
            case 0x1C1808u: goto label_1c1808;
            case 0x1C1824u: goto label_1c1824;
            case 0x1C1830u: goto label_1c1830;
            case 0x1C183Cu: goto label_1c183c;
            case 0x1C1858u: goto label_1c1858;
            case 0x1C1868u: goto label_1c1868;
            case 0x1C1870u: goto label_1c1870;
            case 0x1C188Cu: goto label_1c188c;
            case 0x1C1898u: goto label_1c1898;
            case 0x1C18A4u: goto label_1c18a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C1848u;
    // 0x1c1848: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c1848u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c184c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c184cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c1850: 0xc07057a  jal         func_1C15E8
    ctx->pc = 0x1C1850u;
    SET_GPR_U32(ctx, 31, 0x1C1858u);
    ctx->pc = 0x1C15E8u;
    if (runtime->hasFunction(0x1C15E8u)) {
        auto targetFn = runtime->lookupFunction(0x1C15E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1858u; }
        if (ctx->pc != 0x1C1858u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C15E8_0x1c15e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1858u; }
        if (ctx->pc != 0x1C1858u) { return; }
    }
    ctx->pc = 0x1C1858u;
label_1c1858:
    // 0x1c1858: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C1858u;
    {
        const bool branch_taken_0x1c1858 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C185Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1858u;
            // 0x1c185c: 0x3c020023  lui         $v0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1858) {
            ctx->pc = 0x1C1868u;
            goto label_1c1868;
        }
    }
    ctx->pc = 0x1C1860u;
    // 0x1c1860: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1C1860u;
    {
        const bool branch_taken_0x1c1860 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C1864u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1860u;
            // 0x1c1864: 0x904252d7  lbu         $v0, 0x52D7($v0) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 21207)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1860) {
            ctx->pc = 0x1C18A4u;
            goto label_1c18a4;
        }
    }
    ctx->pc = 0x1C1868u;
label_1c1868:
    // 0x1c1868: 0xc0451b4  jal         func_1146D0
    ctx->pc = 0x1C1868u;
    SET_GPR_U32(ctx, 31, 0x1C1870u);
    ctx->pc = 0x1C186Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1868u;
            // 0x1c186c: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1146D0u;
    if (runtime->hasFunction(0x1146D0u)) {
        auto targetFn = runtime->lookupFunction(0x1146D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1870u; }
        if (ctx->pc != 0x1C1870u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001146D0_0x1146d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1870u; }
        if (ctx->pc != 0x1C1870u) { return; }
    }
    ctx->pc = 0x1C1870u;
label_1c1870:
    // 0x1c1870: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x1c1870u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c1874: 0x21342  srl         $v0, $v0, 13
    ctx->pc = 0x1c1874u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 13));
    // 0x1c1878: 0x30420007  andi        $v0, $v0, 0x7
    ctx->pc = 0x1c1878u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)7);
    // 0x1c187c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C187Cu;
    {
        const bool branch_taken_0x1c187c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C1880u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C187Cu;
            // 0x1c1880: 0x37a40004  ori         $a0, $sp, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 29) | (uint64_t)(uint16_t)4);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c187c) {
            ctx->pc = 0x1C188Cu;
            goto label_1c188c;
        }
    }
    ctx->pc = 0x1C1884u;
    // 0x1c1884: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1C1884u;
    {
        const bool branch_taken_0x1c1884 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C1888u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1884u;
            // 0x1c1888: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1884) {
            ctx->pc = 0x1C18A4u;
            goto label_1c18a4;
        }
    }
    ctx->pc = 0x1C188Cu;
label_1c188c:
    // 0x1c188c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1c188cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c1890: 0xc04524c  jal         func_114930
    ctx->pc = 0x1C1890u;
    SET_GPR_U32(ctx, 31, 0x1C1898u);
    ctx->pc = 0x1C1894u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1890u;
            // 0x1c1894: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114930u;
    if (runtime->hasFunction(0x114930u)) {
        auto targetFn = runtime->lookupFunction(0x114930u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1898u; }
        if (ctx->pc != 0x1C1898u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114930_0x114930(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1898u; }
        if (ctx->pc != 0x1C1898u) { return; }
    }
    ctx->pc = 0x1C1898u;
label_1c1898:
    // 0x1c1898: 0x93a30004  lbu         $v1, 0x4($sp)
    ctx->pc = 0x1c1898u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x1c189c: 0x31942  srl         $v1, $v1, 5
    ctx->pc = 0x1c189cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 5));
    // 0x1c18a0: 0x30620001  andi        $v0, $v1, 0x1
    ctx->pc = 0x1c18a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)1);
label_1c18a4:
    // 0x1c18a4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c18a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c18a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1C18A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C18ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C18A8u;
            // 0x1c18ac: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C17F0u: goto label_1c17f0;
            case 0x1C1800u: goto label_1c1800;
            case 0x1C1808u: goto label_1c1808;
            case 0x1C1824u: goto label_1c1824;
            case 0x1C1830u: goto label_1c1830;
            case 0x1C183Cu: goto label_1c183c;
            case 0x1C1858u: goto label_1c1858;
            case 0x1C1868u: goto label_1c1868;
            case 0x1C1870u: goto label_1c1870;
            case 0x1C188Cu: goto label_1c188c;
            case 0x1C1898u: goto label_1c1898;
            case 0x1C18A4u: goto label_1c18a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C18B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
