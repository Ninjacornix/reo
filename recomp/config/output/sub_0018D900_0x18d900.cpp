#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018D900
// Address: 0x18d900 - 0x18d9d0
void sub_0018D900_0x18d900(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018D900_0x18d900");
#endif

    switch (ctx->pc) {
        case 0x18d930u: goto label_18d930;
        case 0x18d938u: goto label_18d938;
        case 0x18d94cu: goto label_18d94c;
        case 0x18d954u: goto label_18d954;
        case 0x18d964u: goto label_18d964;
        case 0x18d96cu: goto label_18d96c;
        case 0x18d978u: goto label_18d978;
        case 0x18d988u: goto label_18d988;
        case 0x18d9a0u: goto label_18d9a0;
        case 0x18d9a8u: goto label_18d9a8;
        case 0x18d9b0u: goto label_18d9b0;
        default: break;
    }

    ctx->pc = 0x18d900u;

    // 0x18d900: 0x27bdf7c0  addiu       $sp, $sp, -0x840
    ctx->pc = 0x18d900u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294965184));
    // 0x18d904: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x18d904u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x18d908: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x18d908u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x18d90c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x18d90cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x18d910: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x18d910u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18d914: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x18d914u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x18d918: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x18d918u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x18d91c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x18d91cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18d920: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x18d920u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18d924: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x18d924u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x18d928: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x18D928u;
    SET_GPR_U32(ctx, 31, 0x18D930u);
    ctx->pc = 0x18D92Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18D928u;
            // 0x18d92c: 0x24a51c68  addiu       $a1, $a1, 0x1C68 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 7272));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D930u; }
        if (ctx->pc != 0x18D930u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D930u; }
        if (ctx->pc != 0x18D930u) { return; }
    }
    ctx->pc = 0x18D930u;
label_18d930:
    // 0x18d930: 0xc042c56  jal         func_10B158
    ctx->pc = 0x18D930u;
    SET_GPR_U32(ctx, 31, 0x18D938u);
    ctx->pc = 0x18D934u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18D930u;
            // 0x18d934: 0x27a40040  addiu       $a0, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D938u; }
        if (ctx->pc != 0x18D938u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D938u; }
        if (ctx->pc != 0x18D938u) { return; }
    }
    ctx->pc = 0x18D938u;
label_18d938:
    // 0x18d938: 0x5d1021  addu        $v0, $v0, $sp
    ctx->pc = 0x18d938u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 29)));
    // 0x18d93c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x18d93cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18d940: 0x24500040  addiu       $s0, $v0, 0x40
    ctx->pc = 0x18d940u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 64));
    // 0x18d944: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x18D944u;
    SET_GPR_U32(ctx, 31, 0x18D94Cu);
    ctx->pc = 0x18D948u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18D944u;
            // 0x18d948: 0x27a40040  addiu       $a0, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D94Cu; }
        if (ctx->pc != 0x18D94Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D94Cu; }
        if (ctx->pc != 0x18D94Cu) { return; }
    }
    ctx->pc = 0x18D94Cu;
label_18d94c:
    // 0x18d94c: 0xc04336a  jal         func_10CDA8
    ctx->pc = 0x18D94Cu;
    SET_GPR_U32(ctx, 31, 0x18D954u);
    ctx->pc = 0x18D950u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18D94Cu;
            // 0x18d950: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10CDA8u;
    if (runtime->hasFunction(0x10CDA8u)) {
        auto targetFn = runtime->lookupFunction(0x10CDA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D954u; }
        if (ctx->pc != 0x18D954u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010CDA8_0x10cda8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D954u; }
        if (ctx->pc != 0x18D954u) { return; }
    }
    ctx->pc = 0x18D954u;
label_18d954:
    // 0x18d954: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x18d954u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x18d958: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x18d958u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x18d95c: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x18D95Cu;
    SET_GPR_U32(ctx, 31, 0x18D964u);
    ctx->pc = 0x18D960u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18D95Cu;
            // 0x18d960: 0x24a51c70  addiu       $a1, $a1, 0x1C70 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 7280));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D964u; }
        if (ctx->pc != 0x18D964u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D964u; }
        if (ctx->pc != 0x18D964u) { return; }
    }
    ctx->pc = 0x18D964u;
label_18d964:
    // 0x18d964: 0xc06ade4  jal         func_1AB790
    ctx->pc = 0x18D964u;
    SET_GPR_U32(ctx, 31, 0x18D96Cu);
    ctx->pc = 0x1AB790u;
    if (runtime->hasFunction(0x1AB790u)) {
        auto targetFn = runtime->lookupFunction(0x1AB790u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D96Cu; }
        if (ctx->pc != 0x18D96Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AB790_0x1ab790(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D96Cu; }
        if (ctx->pc != 0x18D96Cu) { return; }
    }
    ctx->pc = 0x18D96Cu;
label_18d96c:
    // 0x18d96c: 0x27a40040  addiu       $a0, $sp, 0x40
    ctx->pc = 0x18d96cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x18d970: 0xc04629c  jal         func_118A70
    ctx->pc = 0x18D970u;
    SET_GPR_U32(ctx, 31, 0x18D978u);
    ctx->pc = 0x18D974u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18D970u;
            // 0x18d974: 0x24050602  addiu       $a1, $zero, 0x602 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1538));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118A70u;
    if (runtime->hasFunction(0x118A70u)) {
        auto targetFn = runtime->lookupFunction(0x118A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D978u; }
        if (ctx->pc != 0x18D978u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118A70_0x118a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D978u; }
        if (ctx->pc != 0x18D978u) { return; }
    }
    ctx->pc = 0x18D978u;
label_18d978:
    // 0x18d978: 0x4410005  bgez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x18D978u;
    {
        const bool branch_taken_0x18d978 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x18D97Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18D978u;
            // 0x18d97c: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18d978) {
            ctx->pc = 0x18D990u;
            goto label_18d990;
        }
    }
    ctx->pc = 0x18D980u;
    // 0x18d980: 0xc06adfc  jal         func_1AB7F0
    ctx->pc = 0x18D980u;
    SET_GPR_U32(ctx, 31, 0x18D988u);
    ctx->pc = 0x1AB7F0u;
    if (runtime->hasFunction(0x1AB7F0u)) {
        auto targetFn = runtime->lookupFunction(0x1AB7F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D988u; }
        if (ctx->pc != 0x18D988u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AB7F0_0x1ab7f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D988u; }
        if (ctx->pc != 0x18D988u) { return; }
    }
    ctx->pc = 0x18D988u;
label_18d988:
    // 0x18d988: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x18D988u;
    {
        const bool branch_taken_0x18d988 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18D98Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18D988u;
            // 0x18d98c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18d988) {
            ctx->pc = 0x18D9B4u;
            goto label_18d9b4;
        }
    }
    ctx->pc = 0x18D990u;
label_18d990:
    // 0x18d990: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x18d990u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18d994: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x18d994u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18d998: 0xc0464c4  jal         func_119310
    ctx->pc = 0x18D998u;
    SET_GPR_U32(ctx, 31, 0x18D9A0u);
    ctx->pc = 0x18D99Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18D998u;
            // 0x18d99c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x119310u;
    if (runtime->hasFunction(0x119310u)) {
        auto targetFn = runtime->lookupFunction(0x119310u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D9A0u; }
        if (ctx->pc != 0x18D9A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00119310_0x119310(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D9A0u; }
        if (ctx->pc != 0x18D9A0u) { return; }
    }
    ctx->pc = 0x18D9A0u;
label_18d9a0:
    // 0x18d9a0: 0xc04633e  jal         func_118CF8
    ctx->pc = 0x18D9A0u;
    SET_GPR_U32(ctx, 31, 0x18D9A8u);
    ctx->pc = 0x18D9A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18D9A0u;
            // 0x18d9a4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118CF8u;
    if (runtime->hasFunction(0x118CF8u)) {
        auto targetFn = runtime->lookupFunction(0x118CF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D9A8u; }
        if (ctx->pc != 0x18D9A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118CF8_0x118cf8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D9A8u; }
        if (ctx->pc != 0x18D9A8u) { return; }
    }
    ctx->pc = 0x18D9A8u;
label_18d9a8:
    // 0x18d9a8: 0xc06adfc  jal         func_1AB7F0
    ctx->pc = 0x18D9A8u;
    SET_GPR_U32(ctx, 31, 0x18D9B0u);
    ctx->pc = 0x1AB7F0u;
    if (runtime->hasFunction(0x1AB7F0u)) {
        auto targetFn = runtime->lookupFunction(0x1AB7F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D9B0u; }
        if (ctx->pc != 0x18D9B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AB7F0_0x1ab7f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D9B0u; }
        if (ctx->pc != 0x18D9B0u) { return; }
    }
    ctx->pc = 0x18D9B0u;
label_18d9b0:
    // 0x18d9b0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x18d9b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_18d9b4:
    // 0x18d9b4: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x18d9b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x18d9b8: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x18d9b8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x18d9bc: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x18d9bcu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18d9c0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x18d9c0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x18d9c4: 0x3e00008  jr          $ra
    ctx->pc = 0x18D9C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18D9C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18D9C4u;
            // 0x18d9c8: 0x27bd0840  addiu       $sp, $sp, 0x840 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 2112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18D930u: goto label_18d930;
            case 0x18D938u: goto label_18d938;
            case 0x18D94Cu: goto label_18d94c;
            case 0x18D954u: goto label_18d954;
            case 0x18D964u: goto label_18d964;
            case 0x18D96Cu: goto label_18d96c;
            case 0x18D978u: goto label_18d978;
            case 0x18D988u: goto label_18d988;
            case 0x18D990u: goto label_18d990;
            case 0x18D9A0u: goto label_18d9a0;
            case 0x18D9A8u: goto label_18d9a8;
            case 0x18D9B0u: goto label_18d9b0;
            case 0x18D9B4u: goto label_18d9b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18D9CCu;
    // 0x18d9cc: 0x0  nop
    ctx->pc = 0x18d9ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
