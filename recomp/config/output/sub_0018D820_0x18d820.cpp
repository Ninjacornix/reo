#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018D820
// Address: 0x18d820 - 0x18d8f4
void sub_0018D820_0x18d820(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018D820_0x18d820");
#endif

    switch (ctx->pc) {
        case 0x18d850u: goto label_18d850;
        case 0x18d858u: goto label_18d858;
        case 0x18d86cu: goto label_18d86c;
        case 0x18d874u: goto label_18d874;
        case 0x18d884u: goto label_18d884;
        case 0x18d88cu: goto label_18d88c;
        case 0x18d894u: goto label_18d894;
        case 0x18d8a0u: goto label_18d8a0;
        case 0x18d8b4u: goto label_18d8b4;
        case 0x18d8c8u: goto label_18d8c8;
        case 0x18d8d0u: goto label_18d8d0;
        case 0x18d8d8u: goto label_18d8d8;
        default: break;
    }

    ctx->pc = 0x18d820u;

    // 0x18d820: 0x27bdf7c0  addiu       $sp, $sp, -0x840
    ctx->pc = 0x18d820u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294965184));
    // 0x18d824: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x18d824u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x18d828: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x18d828u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x18d82c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x18d82cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x18d830: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x18d830u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18d834: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x18d834u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x18d838: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x18d838u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x18d83c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x18d83cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18d840: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x18d840u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18d844: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x18d844u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x18d848: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x18D848u;
    SET_GPR_U32(ctx, 31, 0x18D850u);
    ctx->pc = 0x18D84Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18D848u;
            // 0x18d84c: 0x24a51c68  addiu       $a1, $a1, 0x1C68 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 7272));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D850u; }
        if (ctx->pc != 0x18D850u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D850u; }
        if (ctx->pc != 0x18D850u) { return; }
    }
    ctx->pc = 0x18D850u;
label_18d850:
    // 0x18d850: 0xc042c56  jal         func_10B158
    ctx->pc = 0x18D850u;
    SET_GPR_U32(ctx, 31, 0x18D858u);
    ctx->pc = 0x18D854u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18D850u;
            // 0x18d854: 0x27a40040  addiu       $a0, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D858u; }
        if (ctx->pc != 0x18D858u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D858u; }
        if (ctx->pc != 0x18D858u) { return; }
    }
    ctx->pc = 0x18D858u;
label_18d858:
    // 0x18d858: 0x5d1021  addu        $v0, $v0, $sp
    ctx->pc = 0x18d858u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 29)));
    // 0x18d85c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x18d85cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18d860: 0x24500040  addiu       $s0, $v0, 0x40
    ctx->pc = 0x18d860u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 64));
    // 0x18d864: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x18D864u;
    SET_GPR_U32(ctx, 31, 0x18D86Cu);
    ctx->pc = 0x18D868u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18D864u;
            // 0x18d868: 0x27a40040  addiu       $a0, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D86Cu; }
        if (ctx->pc != 0x18D86Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D86Cu; }
        if (ctx->pc != 0x18D86Cu) { return; }
    }
    ctx->pc = 0x18D86Cu;
label_18d86c:
    // 0x18d86c: 0xc04336a  jal         func_10CDA8
    ctx->pc = 0x18D86Cu;
    SET_GPR_U32(ctx, 31, 0x18D874u);
    ctx->pc = 0x18D870u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18D86Cu;
            // 0x18d870: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10CDA8u;
    if (runtime->hasFunction(0x10CDA8u)) {
        auto targetFn = runtime->lookupFunction(0x10CDA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D874u; }
        if (ctx->pc != 0x18D874u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010CDA8_0x10cda8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D874u; }
        if (ctx->pc != 0x18D874u) { return; }
    }
    ctx->pc = 0x18D874u;
label_18d874:
    // 0x18d874: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x18d874u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x18d878: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x18d878u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x18d87c: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x18D87Cu;
    SET_GPR_U32(ctx, 31, 0x18D884u);
    ctx->pc = 0x18D880u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18D87Cu;
            // 0x18d880: 0x24a51c70  addiu       $a1, $a1, 0x1C70 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 7280));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D884u; }
        if (ctx->pc != 0x18D884u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D884u; }
        if (ctx->pc != 0x18D884u) { return; }
    }
    ctx->pc = 0x18D884u;
label_18d884:
    // 0x18d884: 0xc0635d8  jal         func_18D760
    ctx->pc = 0x18D884u;
    SET_GPR_U32(ctx, 31, 0x18D88Cu);
    ctx->pc = 0x18D888u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18D884u;
            // 0x18d888: 0x27a40040  addiu       $a0, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18D760u;
    if (runtime->hasFunction(0x18D760u)) {
        auto targetFn = runtime->lookupFunction(0x18D760u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D88Cu; }
        if (ctx->pc != 0x18D88Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018D760_0x18d760(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D88Cu; }
        if (ctx->pc != 0x18D88Cu) { return; }
    }
    ctx->pc = 0x18D88Cu;
label_18d88c:
    // 0x18d88c: 0xc06ade4  jal         func_1AB790
    ctx->pc = 0x18D88Cu;
    SET_GPR_U32(ctx, 31, 0x18D894u);
    ctx->pc = 0x1AB790u;
    if (runtime->hasFunction(0x1AB790u)) {
        auto targetFn = runtime->lookupFunction(0x1AB790u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D894u; }
        if (ctx->pc != 0x18D894u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AB790_0x1ab790(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D894u; }
        if (ctx->pc != 0x18D894u) { return; }
    }
    ctx->pc = 0x18D894u;
label_18d894:
    // 0x18d894: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x18d894u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x18d898: 0xc04629c  jal         func_118A70
    ctx->pc = 0x18D898u;
    SET_GPR_U32(ctx, 31, 0x18D8A0u);
    ctx->pc = 0x18D89Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18D898u;
            // 0x18d89c: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118A70u;
    if (runtime->hasFunction(0x118A70u)) {
        auto targetFn = runtime->lookupFunction(0x118A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D8A0u; }
        if (ctx->pc != 0x18D8A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118A70_0x118a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D8A0u; }
        if (ctx->pc != 0x18D8A0u) { return; }
    }
    ctx->pc = 0x18D8A0u;
label_18d8a0:
    // 0x18d8a0: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x18d8a0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18d8a4: 0x6010005  bgez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x18D8A4u;
    {
        const bool branch_taken_0x18d8a4 = (GPR_S64(ctx, 16) >= 0);
        ctx->pc = 0x18D8A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18D8A4u;
            // 0x18d8a8: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18d8a4) {
            ctx->pc = 0x18D8BCu;
            goto label_18d8bc;
        }
    }
    ctx->pc = 0x18D8ACu;
    // 0x18d8ac: 0xc06adfc  jal         func_1AB7F0
    ctx->pc = 0x18D8ACu;
    SET_GPR_U32(ctx, 31, 0x18D8B4u);
    ctx->pc = 0x1AB7F0u;
    if (runtime->hasFunction(0x1AB7F0u)) {
        auto targetFn = runtime->lookupFunction(0x1AB7F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D8B4u; }
        if (ctx->pc != 0x18D8B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AB7F0_0x1ab7f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D8B4u; }
        if (ctx->pc != 0x18D8B4u) { return; }
    }
    ctx->pc = 0x18D8B4u;
label_18d8b4:
    // 0x18d8b4: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x18D8B4u;
    {
        const bool branch_taken_0x18d8b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18D8B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18D8B4u;
            // 0x18d8b8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18d8b4) {
            ctx->pc = 0x18D8DCu;
            goto label_18d8dc;
        }
    }
    ctx->pc = 0x18D8BCu;
label_18d8bc:
    // 0x18d8bc: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x18d8bcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18d8c0: 0xc04642c  jal         func_1190B0
    ctx->pc = 0x18D8C0u;
    SET_GPR_U32(ctx, 31, 0x18D8C8u);
    ctx->pc = 0x18D8C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18D8C0u;
            // 0x18d8c4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1190B0u;
    if (runtime->hasFunction(0x1190B0u)) {
        auto targetFn = runtime->lookupFunction(0x1190B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D8C8u; }
        if (ctx->pc != 0x18D8C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001190B0_0x1190b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D8C8u; }
        if (ctx->pc != 0x18D8C8u) { return; }
    }
    ctx->pc = 0x18D8C8u;
label_18d8c8:
    // 0x18d8c8: 0xc04633e  jal         func_118CF8
    ctx->pc = 0x18D8C8u;
    SET_GPR_U32(ctx, 31, 0x18D8D0u);
    ctx->pc = 0x18D8CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18D8C8u;
            // 0x18d8cc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118CF8u;
    if (runtime->hasFunction(0x118CF8u)) {
        auto targetFn = runtime->lookupFunction(0x118CF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D8D0u; }
        if (ctx->pc != 0x18D8D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118CF8_0x118cf8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D8D0u; }
        if (ctx->pc != 0x18D8D0u) { return; }
    }
    ctx->pc = 0x18D8D0u;
label_18d8d0:
    // 0x18d8d0: 0xc06adfc  jal         func_1AB7F0
    ctx->pc = 0x18D8D0u;
    SET_GPR_U32(ctx, 31, 0x18D8D8u);
    ctx->pc = 0x1AB7F0u;
    if (runtime->hasFunction(0x1AB7F0u)) {
        auto targetFn = runtime->lookupFunction(0x1AB7F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D8D8u; }
        if (ctx->pc != 0x18D8D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AB7F0_0x1ab7f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D8D8u; }
        if (ctx->pc != 0x18D8D8u) { return; }
    }
    ctx->pc = 0x18D8D8u;
label_18d8d8:
    // 0x18d8d8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x18d8d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_18d8dc:
    // 0x18d8dc: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x18d8dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x18d8e0: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x18d8e0u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x18d8e4: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x18d8e4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18d8e8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x18d8e8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x18d8ec: 0x3e00008  jr          $ra
    ctx->pc = 0x18D8ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18D8F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18D8ECu;
            // 0x18d8f0: 0x27bd0840  addiu       $sp, $sp, 0x840 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 2112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18D850u: goto label_18d850;
            case 0x18D858u: goto label_18d858;
            case 0x18D86Cu: goto label_18d86c;
            case 0x18D874u: goto label_18d874;
            case 0x18D884u: goto label_18d884;
            case 0x18D88Cu: goto label_18d88c;
            case 0x18D894u: goto label_18d894;
            case 0x18D8A0u: goto label_18d8a0;
            case 0x18D8B4u: goto label_18d8b4;
            case 0x18D8BCu: goto label_18d8bc;
            case 0x18D8C8u: goto label_18d8c8;
            case 0x18D8D0u: goto label_18d8d0;
            case 0x18D8D8u: goto label_18d8d8;
            case 0x18D8DCu: goto label_18d8dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18D8F4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
