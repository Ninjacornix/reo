#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001694F0
// Address: 0x1694f0 - 0x169580
void sub_001694F0_0x1694f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001694F0_0x1694f0");
#endif

    switch (ctx->pc) {
        case 0x169514u: goto label_169514;
        case 0x169528u: goto label_169528;
        case 0x16953cu: goto label_16953c;
        case 0x169564u: goto label_169564;
        default: break;
    }

    ctx->pc = 0x1694f0u;

    // 0x1694f0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1694f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1694f4: 0x3c020018  lui         $v0, 0x18
    ctx->pc = 0x1694f4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)24 << 16));
    // 0x1694f8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1694f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1694fc: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1694fcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169500: 0x24459810  addiu       $a1, $v0, -0x67F0
    ctx->pc = 0x169500u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 4294940688));
    // 0x169504: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x169504u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x169508: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x169508u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x16950c: 0xc05a638  jal         func_1698E0
    ctx->pc = 0x16950Cu;
    SET_GPR_U32(ctx, 31, 0x169514u);
    ctx->pc = 0x169510u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16950Cu;
            // 0x169510: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1698E0u;
    if (runtime->hasFunction(0x1698E0u)) {
        auto targetFn = runtime->lookupFunction(0x1698E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169514u; }
        if (ctx->pc != 0x169514u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001698E0_0x1698e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169514u; }
        if (ctx->pc != 0x169514u) { return; }
    }
    ctx->pc = 0x169514u;
label_169514:
    // 0x169514: 0x3c050018  lui         $a1, 0x18
    ctx->pc = 0x169514u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)24 << 16));
    // 0x169518: 0xae220010  sw          $v0, 0x10($s1)
    ctx->pc = 0x169518u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 2));
    // 0x16951c: 0x24a59858  addiu       $a1, $a1, -0x67A8
    ctx->pc = 0x16951cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294940760));
    // 0x169520: 0xc05a638  jal         func_1698E0
    ctx->pc = 0x169520u;
    SET_GPR_U32(ctx, 31, 0x169528u);
    ctx->pc = 0x169524u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169520u;
            // 0x169524: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1698E0u;
    if (runtime->hasFunction(0x1698E0u)) {
        auto targetFn = runtime->lookupFunction(0x1698E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169528u; }
        if (ctx->pc != 0x169528u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001698E0_0x1698e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169528u; }
        if (ctx->pc != 0x169528u) { return; }
    }
    ctx->pc = 0x169528u;
label_169528:
    // 0x169528: 0x3c050018  lui         $a1, 0x18
    ctx->pc = 0x169528u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)24 << 16));
    // 0x16952c: 0xae220014  sw          $v0, 0x14($s1)
    ctx->pc = 0x16952cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 20), GPR_U32(ctx, 2));
    // 0x169530: 0x24a598a0  addiu       $a1, $a1, -0x6760
    ctx->pc = 0x169530u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294940832));
    // 0x169534: 0xc05a638  jal         func_1698E0
    ctx->pc = 0x169534u;
    SET_GPR_U32(ctx, 31, 0x16953Cu);
    ctx->pc = 0x169538u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169534u;
            // 0x169538: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1698E0u;
    if (runtime->hasFunction(0x1698E0u)) {
        auto targetFn = runtime->lookupFunction(0x1698E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16953Cu; }
        if (ctx->pc != 0x16953Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001698E0_0x1698e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16953Cu; }
        if (ctx->pc != 0x16953Cu) { return; }
    }
    ctx->pc = 0x16953Cu;
label_16953c:
    // 0x16953c: 0x3c050018  lui         $a1, 0x18
    ctx->pc = 0x16953cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)24 << 16));
    // 0x169540: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x169540u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x169544: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x169544u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169548: 0x24a598e8  addiu       $a1, $a1, -0x6718
    ctx->pc = 0x169548u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294940904));
    // 0x16954c: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x16954Cu;
    {
        const bool branch_taken_0x16954c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x169550u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16954Cu;
            // 0x169550: 0xae220018  sw          $v0, 0x18($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 24), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16954c) {
            ctx->pc = 0x16955Cu;
            goto label_16955c;
        }
    }
    ctx->pc = 0x169554u;
    // 0x169554: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x169554u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x169558: 0xae220018  sw          $v0, 0x18($s1)
    ctx->pc = 0x169558u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 24), GPR_U32(ctx, 2));
label_16955c:
    // 0x16955c: 0xc05a638  jal         func_1698E0
    ctx->pc = 0x16955Cu;
    SET_GPR_U32(ctx, 31, 0x169564u);
    ctx->pc = 0x1698E0u;
    if (runtime->hasFunction(0x1698E0u)) {
        auto targetFn = runtime->lookupFunction(0x1698E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169564u; }
        if (ctx->pc != 0x169564u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001698E0_0x1698e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169564u; }
        if (ctx->pc != 0x169564u) { return; }
    }
    ctx->pc = 0x169564u;
label_169564:
    // 0x169564: 0xae22001c  sw          $v0, 0x1C($s1)
    ctx->pc = 0x169564u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 28), GPR_U32(ctx, 2));
    // 0x169568: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x169568u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16956c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16956cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x169570: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x169570u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x169574: 0x3e00008  jr          $ra
    ctx->pc = 0x169574u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x169578u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x169574u;
            // 0x169578: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x169514u: goto label_169514;
            case 0x169528u: goto label_169528;
            case 0x16953Cu: goto label_16953c;
            case 0x16955Cu: goto label_16955c;
            case 0x169564u: goto label_169564;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16957Cu;
    // 0x16957c: 0x0  nop
    ctx->pc = 0x16957cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
