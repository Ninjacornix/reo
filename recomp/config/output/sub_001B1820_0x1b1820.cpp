#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B1820
// Address: 0x1b1820 - 0x1b18f0
void sub_001B1820_0x1b1820(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B1820_0x1b1820");
#endif

    switch (ctx->pc) {
        case 0x1b1848u: goto label_1b1848;
        case 0x1b1884u: goto label_1b1884;
        case 0x1b1894u: goto label_1b1894;
        case 0x1b18bcu: goto label_1b18bc;
        case 0x1b18c4u: goto label_1b18c4;
        default: break;
    }

    ctx->pc = 0x1b1820u;

    // 0x1b1820: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1b1820u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1b1824: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1b1824u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1b1828: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b1828u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b182c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b182cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b1830: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b1830u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b1834: 0x8c830808  lw          $v1, 0x808($a0)
    ctx->pc = 0x1b1834u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 2056)));
    // 0x1b1838: 0x10600024  beqz        $v1, . + 4 + (0x24 << 2)
    ctx->pc = 0x1B1838u;
    {
        const bool branch_taken_0x1b1838 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B183Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1838u;
            // 0x1b183c: 0x80902d  daddu       $s2, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b1838) {
            ctx->pc = 0x1B18CCu;
            goto label_1b18cc;
        }
    }
    ctx->pc = 0x1B1840u;
    // 0x1b1840: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1B1840u;
    {
        const bool branch_taken_0x1b1840 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B1844u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1840u;
            // 0x1b1844: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b1840) {
            ctx->pc = 0x1B18A4u;
            goto label_1b18a4;
        }
    }
    ctx->pc = 0x1B1848u;
label_1b1848:
    // 0x1b1848: 0x8e430808  lw          $v1, 0x808($s2)
    ctx->pc = 0x1b1848u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 2056)));
    // 0x1b184c: 0x1110c0  sll         $v0, $s1, 3
    ctx->pc = 0x1b184cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x1b1850: 0x512021  addu        $a0, $v0, $s1
    ctx->pc = 0x1b1850u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x1b1854: 0x42040  sll         $a0, $a0, 1
    ctx->pc = 0x1b1854u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1b1858: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1b1858u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1b185c: 0x912021  addu        $a0, $a0, $s1
    ctx->pc = 0x1b185cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 17)));
    // 0x1b1860: 0x480c0  sll         $s0, $a0, 3
    ctx->pc = 0x1b1860u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x1b1864: 0x701821  addu        $v1, $v1, $s0
    ctx->pc = 0x1b1864u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1b1868: 0x8c640000  lw          $a0, 0x0($v1)
    ctx->pc = 0x1b1868u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1b186c: 0x1082000c  beq         $a0, $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1B186Cu;
    {
        const bool branch_taken_0x1b186c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        if (branch_taken_0x1b186c) {
            ctx->pc = 0x1B18A0u;
            goto label_1b18a0;
        }
    }
    ctx->pc = 0x1B1874u;
    // 0x1b1874: 0x1080000a  beqz        $a0, . + 4 + (0xA << 2)
    ctx->pc = 0x1B1874u;
    {
        const bool branch_taken_0x1b1874 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b1874) {
            ctx->pc = 0x1B18A0u;
            goto label_1b18a0;
        }
    }
    ctx->pc = 0x1B187Cu;
    // 0x1b187c: 0xc063128  jal         func_18C4A0
    ctx->pc = 0x1B187Cu;
    SET_GPR_U32(ctx, 31, 0x1B1884u);
    ctx->pc = 0x18C4A0u;
    if (runtime->hasFunction(0x18C4A0u)) {
        auto targetFn = runtime->lookupFunction(0x18C4A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1884u; }
        if (ctx->pc != 0x1B1884u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C4A0_0x18c4a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1884u; }
        if (ctx->pc != 0x1B1884u) { return; }
    }
    ctx->pc = 0x1B1884u;
label_1b1884:
    // 0x1b1884: 0x8e420808  lw          $v0, 0x808($s2)
    ctx->pc = 0x1b1884u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 2056)));
    // 0x1b1888: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1b1888u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1b188c: 0xc06c410  jal         func_1B1040
    ctx->pc = 0x1B188Cu;
    SET_GPR_U32(ctx, 31, 0x1B1894u);
    ctx->pc = 0x1B1890u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B188Cu;
            // 0x1b1890: 0x8c440000  lw          $a0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B1040u;
    if (runtime->hasFunction(0x1B1040u)) {
        auto targetFn = runtime->lookupFunction(0x1B1040u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1894u; }
        if (ctx->pc != 0x1B1894u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1040_0x1b1040(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1894u; }
        if (ctx->pc != 0x1B1894u) { return; }
    }
    ctx->pc = 0x1B1894u;
label_1b1894:
    // 0x1b1894: 0x8e420808  lw          $v0, 0x808($s2)
    ctx->pc = 0x1b1894u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 2056)));
    // 0x1b1898: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1b1898u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1b189c: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x1b189cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
label_1b18a0:
    // 0x1b18a0: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1b18a0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
label_1b18a4:
    // 0x1b18a4: 0x96420812  lhu         $v0, 0x812($s2)
    ctx->pc = 0x1b18a4u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 2066)));
    // 0x1b18a8: 0x222102a  slt         $v0, $s1, $v0
    ctx->pc = 0x1b18a8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1b18ac: 0x1440ffe6  bnez        $v0, . + 4 + (-0x1A << 2)
    ctx->pc = 0x1B18ACu;
    {
        const bool branch_taken_0x1b18ac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B18B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B18ACu;
            // 0x1b18b0: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b18ac) {
            ctx->pc = 0x1B1848u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b1848;
        }
    }
    ctx->pc = 0x1B18B4u;
    // 0x1b18b4: 0xc06c6a4  jal         func_1B1A90
    ctx->pc = 0x1B18B4u;
    SET_GPR_U32(ctx, 31, 0x1B18BCu);
    ctx->pc = 0x1B1A90u;
    if (runtime->hasFunction(0x1B1A90u)) {
        auto targetFn = runtime->lookupFunction(0x1B1A90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B18BCu; }
        if (ctx->pc != 0x1B18BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1A90_0x1b1a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B18BCu; }
        if (ctx->pc != 0x1B18BCu) { return; }
    }
    ctx->pc = 0x1B18BCu;
label_1b18bc:
    // 0x1b18bc: 0xc06cae4  jal         func_1B2B90
    ctx->pc = 0x1B18BCu;
    SET_GPR_U32(ctx, 31, 0x1B18C4u);
    ctx->pc = 0x1B18C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B18BCu;
            // 0x1b18c0: 0x8e440808  lw          $a0, 0x808($s2) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 2056)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2B90u;
    if (runtime->hasFunction(0x1B2B90u)) {
        auto targetFn = runtime->lookupFunction(0x1B2B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B18C4u; }
        if (ctx->pc != 0x1B18C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2B90_0x1b2b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B18C4u; }
        if (ctx->pc != 0x1B18C4u) { return; }
    }
    ctx->pc = 0x1B18C4u;
label_1b18c4:
    // 0x1b18c4: 0xae400808  sw          $zero, 0x808($s2)
    ctx->pc = 0x1b18c4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 2056), GPR_U32(ctx, 0));
    // 0x1b18c8: 0xa6400812  sh          $zero, 0x812($s2)
    ctx->pc = 0x1b18c8u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 2066), (uint16_t)GPR_U32(ctx, 0));
label_1b18cc:
    // 0x1b18cc: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1b18ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b18d0: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b18d0u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b18d4: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b18d4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b18d8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b18d8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b18dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1B18DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B18E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B18DCu;
            // 0x1b18e0: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B1848u: goto label_1b1848;
            case 0x1B1884u: goto label_1b1884;
            case 0x1B1894u: goto label_1b1894;
            case 0x1B18A0u: goto label_1b18a0;
            case 0x1B18A4u: goto label_1b18a4;
            case 0x1B18BCu: goto label_1b18bc;
            case 0x1B18C4u: goto label_1b18c4;
            case 0x1B18CCu: goto label_1b18cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B18E4u;
    // 0x1b18e4: 0x0  nop
    ctx->pc = 0x1b18e4u;
    // NOP
    // 0x1b18e8: 0x0  nop
    ctx->pc = 0x1b18e8u;
    // NOP
    // 0x1b18ec: 0x0  nop
    ctx->pc = 0x1b18ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
