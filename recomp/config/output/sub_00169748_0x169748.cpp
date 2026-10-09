#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00169748
// Address: 0x169748 - 0x1698e0
void sub_00169748_0x169748(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00169748_0x169748");
#endif

    switch (ctx->pc) {
        case 0x16978cu: goto label_16978c;
        case 0x1697a4u: goto label_1697a4;
        case 0x1697bcu: goto label_1697bc;
        case 0x1697e4u: goto label_1697e4;
        case 0x1697f8u: goto label_1697f8;
        case 0x169828u: goto label_169828;
        case 0x169840u: goto label_169840;
        case 0x169858u: goto label_169858;
        case 0x169870u: goto label_169870;
        case 0x169888u: goto label_169888;
        case 0x1698a0u: goto label_1698a0;
        case 0x1698b8u: goto label_1698b8;
        default: break;
    }

    ctx->pc = 0x169748u;

    // 0x169748: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x169748u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x16974c: 0x3c020018  lui         $v0, 0x18
    ctx->pc = 0x16974cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)24 << 16));
    // 0x169750: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x169750u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x169754: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x169754u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169758: 0x24469f68  addiu       $a2, $v0, -0x6098
    ctx->pc = 0x169758u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 4294942568));
    // 0x16975c: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x16975cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x169760: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x169760u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x169764: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x169764u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169768: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x169768u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x16976c: 0x26130008  addiu       $s3, $s0, 0x8
    ctx->pc = 0x16976cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
    // 0x169770: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x169770u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x169774: 0x2614000c  addiu       $s4, $s0, 0xC
    ctx->pc = 0x169774u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 16), 12));
    // 0x169778: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x169778u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x16977c: 0x325500ff  andi        $s5, $s2, 0xFF
    ctx->pc = 0x16977cu;
    SET_GPR_U64(ctx, 21, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)255);
    // 0x169780: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x169780u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x169784: 0xc05a646  jal         func_169918
    ctx->pc = 0x169784u;
    SET_GPR_U32(ctx, 31, 0x16978Cu);
    ctx->pc = 0x169788u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169784u;
            // 0x169788: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169918u;
    if (runtime->hasFunction(0x169918u)) {
        auto targetFn = runtime->lookupFunction(0x169918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16978Cu; }
        if (ctx->pc != 0x16978Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169918_0x169918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16978Cu; }
        if (ctx->pc != 0x16978Cu) { return; }
    }
    ctx->pc = 0x16978Cu;
label_16978c:
    // 0x16978c: 0x3c060018  lui         $a2, 0x18
    ctx->pc = 0x16978cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)24 << 16));
    // 0x169790: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x169790u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x169794: 0x24c69fd0  addiu       $a2, $a2, -0x6030
    ctx->pc = 0x169794u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294942672));
    // 0x169798: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x169798u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16979c: 0xc05a646  jal         func_169918
    ctx->pc = 0x16979Cu;
    SET_GPR_U32(ctx, 31, 0x1697A4u);
    ctx->pc = 0x1697A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16979Cu;
            // 0x1697a0: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169918u;
    if (runtime->hasFunction(0x169918u)) {
        auto targetFn = runtime->lookupFunction(0x169918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1697A4u; }
        if (ctx->pc != 0x1697A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169918_0x169918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1697A4u; }
        if (ctx->pc != 0x1697A4u) { return; }
    }
    ctx->pc = 0x1697A4u;
label_1697a4:
    // 0x1697a4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1697a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1697a8: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x1697a8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x1697ac: 0x2a0282d  daddu       $a1, $s5, $zero
    ctx->pc = 0x1697acu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1697b0: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x1697b0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1697b4: 0xc05e810  jal         func_17A040
    ctx->pc = 0x1697B4u;
    SET_GPR_U32(ctx, 31, 0x1697BCu);
    ctx->pc = 0x1697B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1697B4u;
            // 0x1697b8: 0x280382d  daddu       $a3, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17A040u;
    if (runtime->hasFunction(0x17A040u)) {
        auto targetFn = runtime->lookupFunction(0x17A040u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1697BCu; }
        if (ctx->pc != 0x1697BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A040_0x17a040(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1697BCu; }
        if (ctx->pc != 0x1697BCu) { return; }
    }
    ctx->pc = 0x1697BCu;
label_1697bc:
    // 0x1697bc: 0x3c060018  lui         $a2, 0x18
    ctx->pc = 0x1697bcu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)24 << 16));
    // 0x1697c0: 0x24c6a0e8  addiu       $a2, $a2, -0x5F18
    ctx->pc = 0x1697c0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294942952));
    // 0x1697c4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1697c4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1697c8: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1697c8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1697cc: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1697CCu;
    {
        const bool branch_taken_0x1697cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1697D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1697CCu;
            // 0x1697d0: 0x2403ffff  addiu       $v1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1697cc) {
            ctx->pc = 0x1697DCu;
            goto label_1697dc;
        }
    }
    ctx->pc = 0x1697D4u;
    // 0x1697d4: 0xae630000  sw          $v1, 0x0($s3)
    ctx->pc = 0x1697d4u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
    // 0x1697d8: 0xae830000  sw          $v1, 0x0($s4)
    ctx->pc = 0x1697d8u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 3));
label_1697dc:
    // 0x1697dc: 0xc05a646  jal         func_169918
    ctx->pc = 0x1697DCu;
    SET_GPR_U32(ctx, 31, 0x1697E4u);
    ctx->pc = 0x169918u;
    if (runtime->hasFunction(0x169918u)) {
        auto targetFn = runtime->lookupFunction(0x169918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1697E4u; }
        if (ctx->pc != 0x1697E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169918_0x169918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1697E4u; }
        if (ctx->pc != 0x1697E4u) { return; }
    }
    ctx->pc = 0x1697E4u;
label_1697e4:
    // 0x1697e4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1697e4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1697e8: 0xae020010  sw          $v0, 0x10($s0)
    ctx->pc = 0x1697e8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
    // 0x1697ec: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x1697ecu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1697f0: 0xc05e51a  jal         func_179468
    ctx->pc = 0x1697F0u;
    SET_GPR_U32(ctx, 31, 0x1697F8u);
    ctx->pc = 0x1697F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1697F0u;
            // 0x1697f4: 0x2a0282d  daddu       $a1, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179468u;
    if (runtime->hasFunction(0x179468u)) {
        auto targetFn = runtime->lookupFunction(0x179468u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1697F8u; }
        if (ctx->pc != 0x1697F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179468_0x179468(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1697F8u; }
        if (ctx->pc != 0x1697F8u) { return; }
    }
    ctx->pc = 0x1697F8u;
label_1697f8:
    // 0x1697f8: 0x3c060018  lui         $a2, 0x18
    ctx->pc = 0x1697f8u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)24 << 16));
    // 0x1697fc: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x1697fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x169800: 0x24c6a158  addiu       $a2, $a2, -0x5EA8
    ctx->pc = 0x169800u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294943064));
    // 0x169804: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x169804u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169808: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x169808u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16980c: 0x2180a  movz        $v1, $zero, $v0
    ctx->pc = 0x16980cu;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 0));
    // 0x169810: 0x3102b  sltu        $v0, $zero, $v1
    ctx->pc = 0x169810u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x169814: 0xafa30000  sw          $v1, 0x0($sp)
    ctx->pc = 0x169814u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
    // 0x169818: 0x10600028  beqz        $v1, . + 4 + (0x28 << 2)
    ctx->pc = 0x169818u;
    {
        const bool branch_taken_0x169818 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x16981Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x169818u;
            // 0x16981c: 0xae020014  sw          $v0, 0x14($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x169818) {
            ctx->pc = 0x1698BCu;
            goto label_1698bc;
        }
    }
    ctx->pc = 0x169820u;
    // 0x169820: 0xc05a646  jal         func_169918
    ctx->pc = 0x169820u;
    SET_GPR_U32(ctx, 31, 0x169828u);
    ctx->pc = 0x169918u;
    if (runtime->hasFunction(0x169918u)) {
        auto targetFn = runtime->lookupFunction(0x169918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169828u; }
        if (ctx->pc != 0x169828u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169918_0x169918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169828u; }
        if (ctx->pc != 0x169828u) { return; }
    }
    ctx->pc = 0x169828u;
label_169828:
    // 0x169828: 0x3c060018  lui         $a2, 0x18
    ctx->pc = 0x169828u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)24 << 16));
    // 0x16982c: 0xae020018  sw          $v0, 0x18($s0)
    ctx->pc = 0x16982cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 2));
    // 0x169830: 0x24c6a1c0  addiu       $a2, $a2, -0x5E40
    ctx->pc = 0x169830u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294943168));
    // 0x169834: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x169834u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169838: 0xc05a646  jal         func_169918
    ctx->pc = 0x169838u;
    SET_GPR_U32(ctx, 31, 0x169840u);
    ctx->pc = 0x16983Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169838u;
            // 0x16983c: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169918u;
    if (runtime->hasFunction(0x169918u)) {
        auto targetFn = runtime->lookupFunction(0x169918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169840u; }
        if (ctx->pc != 0x169840u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169918_0x169918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169840u; }
        if (ctx->pc != 0x169840u) { return; }
    }
    ctx->pc = 0x169840u;
label_169840:
    // 0x169840: 0x3c060018  lui         $a2, 0x18
    ctx->pc = 0x169840u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)24 << 16));
    // 0x169844: 0xae02001c  sw          $v0, 0x1C($s0)
    ctx->pc = 0x169844u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 2));
    // 0x169848: 0x24c6a228  addiu       $a2, $a2, -0x5DD8
    ctx->pc = 0x169848u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294943272));
    // 0x16984c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x16984cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169850: 0xc05a646  jal         func_169918
    ctx->pc = 0x169850u;
    SET_GPR_U32(ctx, 31, 0x169858u);
    ctx->pc = 0x169854u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169850u;
            // 0x169854: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169918u;
    if (runtime->hasFunction(0x169918u)) {
        auto targetFn = runtime->lookupFunction(0x169918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169858u; }
        if (ctx->pc != 0x169858u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169918_0x169918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169858u; }
        if (ctx->pc != 0x169858u) { return; }
    }
    ctx->pc = 0x169858u;
label_169858:
    // 0x169858: 0x3c060018  lui         $a2, 0x18
    ctx->pc = 0x169858u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)24 << 16));
    // 0x16985c: 0xae020020  sw          $v0, 0x20($s0)
    ctx->pc = 0x16985cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 2));
    // 0x169860: 0x24c6a298  addiu       $a2, $a2, -0x5D68
    ctx->pc = 0x169860u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294943384));
    // 0x169864: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x169864u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169868: 0xc05a646  jal         func_169918
    ctx->pc = 0x169868u;
    SET_GPR_U32(ctx, 31, 0x169870u);
    ctx->pc = 0x16986Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169868u;
            // 0x16986c: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169918u;
    if (runtime->hasFunction(0x169918u)) {
        auto targetFn = runtime->lookupFunction(0x169918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169870u; }
        if (ctx->pc != 0x169870u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169918_0x169918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169870u; }
        if (ctx->pc != 0x169870u) { return; }
    }
    ctx->pc = 0x169870u;
label_169870:
    // 0x169870: 0x3c060018  lui         $a2, 0x18
    ctx->pc = 0x169870u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)24 << 16));
    // 0x169874: 0xae020024  sw          $v0, 0x24($s0)
    ctx->pc = 0x169874u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
    // 0x169878: 0x24c6a308  addiu       $a2, $a2, -0x5CF8
    ctx->pc = 0x169878u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294943496));
    // 0x16987c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x16987cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169880: 0xc05a646  jal         func_169918
    ctx->pc = 0x169880u;
    SET_GPR_U32(ctx, 31, 0x169888u);
    ctx->pc = 0x169884u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169880u;
            // 0x169884: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169918u;
    if (runtime->hasFunction(0x169918u)) {
        auto targetFn = runtime->lookupFunction(0x169918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169888u; }
        if (ctx->pc != 0x169888u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169918_0x169918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169888u; }
        if (ctx->pc != 0x169888u) { return; }
    }
    ctx->pc = 0x169888u;
label_169888:
    // 0x169888: 0x3c060018  lui         $a2, 0x18
    ctx->pc = 0x169888u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)24 << 16));
    // 0x16988c: 0xae020028  sw          $v0, 0x28($s0)
    ctx->pc = 0x16988cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 2));
    // 0x169890: 0x24c6a370  addiu       $a2, $a2, -0x5C90
    ctx->pc = 0x169890u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294943600));
    // 0x169894: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x169894u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169898: 0xc05a646  jal         func_169918
    ctx->pc = 0x169898u;
    SET_GPR_U32(ctx, 31, 0x1698A0u);
    ctx->pc = 0x16989Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169898u;
            // 0x16989c: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169918u;
    if (runtime->hasFunction(0x169918u)) {
        auto targetFn = runtime->lookupFunction(0x169918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1698A0u; }
        if (ctx->pc != 0x1698A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169918_0x169918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1698A0u; }
        if (ctx->pc != 0x1698A0u) { return; }
    }
    ctx->pc = 0x1698A0u;
label_1698a0:
    // 0x1698a0: 0x3c060018  lui         $a2, 0x18
    ctx->pc = 0x1698a0u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)24 << 16));
    // 0x1698a4: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x1698a4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
    // 0x1698a8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1698a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1698ac: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1698acu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1698b0: 0xc05a646  jal         func_169918
    ctx->pc = 0x1698B0u;
    SET_GPR_U32(ctx, 31, 0x1698B8u);
    ctx->pc = 0x1698B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1698B0u;
            // 0x1698b4: 0x24c6a3e8  addiu       $a2, $a2, -0x5C18 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294943720));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169918u;
    if (runtime->hasFunction(0x169918u)) {
        auto targetFn = runtime->lookupFunction(0x169918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1698B8u; }
        if (ctx->pc != 0x1698B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169918_0x169918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1698B8u; }
        if (ctx->pc != 0x1698B8u) { return; }
    }
    ctx->pc = 0x1698B8u;
label_1698b8:
    // 0x1698b8: 0xae020030  sw          $v0, 0x30($s0)
    ctx->pc = 0x1698b8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 2));
label_1698bc:
    // 0x1698bc: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1698bcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1698c0: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x1698c0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1698c4: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x1698c4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1698c8: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x1698c8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1698cc: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x1698ccu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1698d0: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x1698d0u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1698d4: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1698d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1698d8: 0x3e00008  jr          $ra
    ctx->pc = 0x1698D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1698DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1698D8u;
            // 0x1698dc: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16978Cu: goto label_16978c;
            case 0x1697A4u: goto label_1697a4;
            case 0x1697BCu: goto label_1697bc;
            case 0x1697DCu: goto label_1697dc;
            case 0x1697E4u: goto label_1697e4;
            case 0x1697F8u: goto label_1697f8;
            case 0x169828u: goto label_169828;
            case 0x169840u: goto label_169840;
            case 0x169858u: goto label_169858;
            case 0x169870u: goto label_169870;
            case 0x169888u: goto label_169888;
            case 0x1698A0u: goto label_1698a0;
            case 0x1698B8u: goto label_1698b8;
            case 0x1698BCu: goto label_1698bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1698E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
