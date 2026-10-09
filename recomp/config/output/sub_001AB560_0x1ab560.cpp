#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AB560
// Address: 0x1ab560 - 0x1ab790
void sub_001AB560_0x1ab560(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AB560_0x1ab560");
#endif

    switch (ctx->pc) {
        case 0x1ab578u: goto label_1ab578;
        case 0x1ab580u: goto label_1ab580;
        case 0x1ab588u: goto label_1ab588;
        case 0x1ab590u: goto label_1ab590;
        case 0x1ab59cu: goto label_1ab59c;
        case 0x1ab5acu: goto label_1ab5ac;
        case 0x1ab5b4u: goto label_1ab5b4;
        case 0x1ab5d4u: goto label_1ab5d4;
        case 0x1ab5dcu: goto label_1ab5dc;
        case 0x1ab5e4u: goto label_1ab5e4;
        case 0x1ab5ecu: goto label_1ab5ec;
        case 0x1ab5f4u: goto label_1ab5f4;
        case 0x1ab5fcu: goto label_1ab5fc;
        case 0x1ab60cu: goto label_1ab60c;
        case 0x1ab628u: goto label_1ab628;
        case 0x1ab63cu: goto label_1ab63c;
        case 0x1ab64cu: goto label_1ab64c;
        case 0x1ab654u: goto label_1ab654;
        case 0x1ab65cu: goto label_1ab65c;
        case 0x1ab68cu: goto label_1ab68c;
        case 0x1ab698u: goto label_1ab698;
        case 0x1ab69cu: goto label_1ab69c;
        case 0x1ab6a4u: goto label_1ab6a4;
        case 0x1ab6d0u: goto label_1ab6d0;
        case 0x1ab6f8u: goto label_1ab6f8;
        case 0x1ab708u: goto label_1ab708;
        case 0x1ab71cu: goto label_1ab71c;
        case 0x1ab738u: goto label_1ab738;
        case 0x1ab740u: goto label_1ab740;
        case 0x1ab758u: goto label_1ab758;
        case 0x1ab774u: goto label_1ab774;
        default: break;
    }

    ctx->pc = 0x1ab560u;

    // 0x1ab560: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1ab560u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1ab564: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1ab564u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ab568: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1ab568u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1ab56c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1ab56cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1ab570: 0xc045c20  jal         func_117080
    ctx->pc = 0x1AB570u;
    SET_GPR_U32(ctx, 31, 0x1AB578u);
    ctx->pc = 0x1AB574u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB570u;
            // 0x1ab574: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117080u;
    if (runtime->hasFunction(0x117080u)) {
        auto targetFn = runtime->lookupFunction(0x117080u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB578u; }
        if (ctx->pc != 0x1AB578u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117080_0x117080(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB578u; }
        if (ctx->pc != 0x1AB578u) { return; }
    }
    ctx->pc = 0x1AB578u;
label_1ab578:
    // 0x1ab578: 0xc046e0a  jal         func_11B828
    ctx->pc = 0x1AB578u;
    SET_GPR_U32(ctx, 31, 0x1AB580u);
    ctx->pc = 0x11B828u;
    if (runtime->hasFunction(0x11B828u)) {
        auto targetFn = runtime->lookupFunction(0x11B828u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB580u; }
        if (ctx->pc != 0x1AB580u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011B828_0x11b828(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB580u; }
        if (ctx->pc != 0x1AB580u) { return; }
    }
    ctx->pc = 0x1AB580u;
label_1ab580:
    // 0x1ab580: 0xc04042a  jal         func_1010A8
    ctx->pc = 0x1AB580u;
    SET_GPR_U32(ctx, 31, 0x1AB588u);
    ctx->pc = 0x1AB584u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB580u;
            // 0x1ab584: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1010A8u;
    if (runtime->hasFunction(0x1010A8u)) {
        auto targetFn = runtime->lookupFunction(0x1010A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB588u; }
        if (ctx->pc != 0x1AB588u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001010A8_0x1010a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB588u; }
        if (ctx->pc != 0x1AB588u) { return; }
    }
    ctx->pc = 0x1AB588u;
label_1ab588:
    // 0x1ab588: 0xc04628e  jal         func_118A38
    ctx->pc = 0x1AB588u;
    SET_GPR_U32(ctx, 31, 0x1AB590u);
    ctx->pc = 0x118A38u;
    if (runtime->hasFunction(0x118A38u)) {
        auto targetFn = runtime->lookupFunction(0x118A38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB590u; }
        if (ctx->pc != 0x1AB590u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118A38_0x118a38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB590u; }
        if (ctx->pc != 0x1AB590u) { return; }
    }
    ctx->pc = 0x1AB590u;
label_1ab590:
    // 0x1ab590: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1ab590u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1ab594: 0xc04732a  jal         func_11CCA8
    ctx->pc = 0x1AB594u;
    SET_GPR_U32(ctx, 31, 0x1AB59Cu);
    ctx->pc = 0x1AB598u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB594u;
            // 0x1ab598: 0x2484fd40  addiu       $a0, $a0, -0x2C0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966592));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11CCA8u;
    if (runtime->hasFunction(0x11CCA8u)) {
        auto targetFn = runtime->lookupFunction(0x11CCA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB59Cu; }
        if (ctx->pc != 0x1AB59Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011CCA8_0x11cca8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB59Cu; }
        if (ctx->pc != 0x1AB59Cu) { return; }
    }
    ctx->pc = 0x1AB59Cu;
label_1ab59c:
    // 0x1ab59c: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x1ab59cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1ab5a0: 0x38420001  xori        $v0, $v0, 0x1
    ctx->pc = 0x1ab5a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
    // 0x1ab5a4: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1AB5A4u;
    {
        const bool branch_taken_0x1ab5a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1ab5a4) {
            ctx->pc = 0x1AB590u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1ab590;
        }
    }
    ctx->pc = 0x1AB5ACu;
label_1ab5ac:
    // 0x1ab5ac: 0xc047316  jal         func_11CC58
    ctx->pc = 0x1AB5ACu;
    SET_GPR_U32(ctx, 31, 0x1AB5B4u);
    ctx->pc = 0x11CC58u;
    if (runtime->hasFunction(0x11CC58u)) {
        auto targetFn = runtime->lookupFunction(0x11CC58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB5B4u; }
        if (ctx->pc != 0x1AB5B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011CC58_0x11cc58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB5B4u; }
        if (ctx->pc != 0x1AB5B4u) { return; }
    }
    ctx->pc = 0x1AB5B4u;
label_1ab5b4:
    // 0x1ab5b4: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x1ab5b4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1ab5b8: 0x38420001  xori        $v0, $v0, 0x1
    ctx->pc = 0x1ab5b8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
    // 0x1ab5bc: 0x0  nop
    ctx->pc = 0x1ab5bcu;
    // NOP
    // 0x1ab5c0: 0x0  nop
    ctx->pc = 0x1ab5c0u;
    // NOP
    // 0x1ab5c4: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1AB5C4u;
    {
        const bool branch_taken_0x1ab5c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1ab5c4) {
            ctx->pc = 0x1AB5ACu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1ab5ac;
        }
    }
    ctx->pc = 0x1AB5CCu;
    // 0x1ab5cc: 0xc045c20  jal         func_117080
    ctx->pc = 0x1AB5CCu;
    SET_GPR_U32(ctx, 31, 0x1AB5D4u);
    ctx->pc = 0x1AB5D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB5CCu;
            // 0x1ab5d0: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117080u;
    if (runtime->hasFunction(0x117080u)) {
        auto targetFn = runtime->lookupFunction(0x117080u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB5D4u; }
        if (ctx->pc != 0x1AB5D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117080_0x117080(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB5D4u; }
        if (ctx->pc != 0x1AB5D4u) { return; }
    }
    ctx->pc = 0x1AB5D4u;
label_1ab5d4:
    // 0x1ab5d4: 0xc046fc2  jal         func_11BF08
    ctx->pc = 0x1AB5D4u;
    SET_GPR_U32(ctx, 31, 0x1AB5DCu);
    ctx->pc = 0x11BF08u;
    if (runtime->hasFunction(0x11BF08u)) {
        auto targetFn = runtime->lookupFunction(0x11BF08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB5DCu; }
        if (ctx->pc != 0x1AB5DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011BF08_0x11bf08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB5DCu; }
        if (ctx->pc != 0x1AB5DCu) { return; }
    }
    ctx->pc = 0x1AB5DCu;
label_1ab5dc:
    // 0x1ab5dc: 0xc04628e  jal         func_118A38
    ctx->pc = 0x1AB5DCu;
    SET_GPR_U32(ctx, 31, 0x1AB5E4u);
    ctx->pc = 0x118A38u;
    if (runtime->hasFunction(0x118A38u)) {
        auto targetFn = runtime->lookupFunction(0x118A38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB5E4u; }
        if (ctx->pc != 0x1AB5E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118A38_0x118a38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB5E4u; }
        if (ctx->pc != 0x1AB5E4u) { return; }
    }
    ctx->pc = 0x1AB5E4u;
label_1ab5e4:
    // 0x1ab5e4: 0xc046e0a  jal         func_11B828
    ctx->pc = 0x1AB5E4u;
    SET_GPR_U32(ctx, 31, 0x1AB5ECu);
    ctx->pc = 0x11B828u;
    if (runtime->hasFunction(0x11B828u)) {
        auto targetFn = runtime->lookupFunction(0x11B828u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB5ECu; }
        if (ctx->pc != 0x1AB5ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011B828_0x11b828(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB5ECu; }
        if (ctx->pc != 0x1AB5ECu) { return; }
    }
    ctx->pc = 0x1AB5ECu;
label_1ab5ec:
    // 0x1ab5ec: 0xc04042a  jal         func_1010A8
    ctx->pc = 0x1AB5ECu;
    SET_GPR_U32(ctx, 31, 0x1AB5F4u);
    ctx->pc = 0x1AB5F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB5ECu;
            // 0x1ab5f0: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1010A8u;
    if (runtime->hasFunction(0x1010A8u)) {
        auto targetFn = runtime->lookupFunction(0x1010A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB5F4u; }
        if (ctx->pc != 0x1AB5F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001010A8_0x1010a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB5F4u; }
        if (ctx->pc != 0x1AB5F4u) { return; }
    }
    ctx->pc = 0x1AB5F4u;
label_1ab5f4:
    // 0x1ab5f4: 0xc04070e  jal         func_101C38
    ctx->pc = 0x1AB5F4u;
    SET_GPR_U32(ctx, 31, 0x1AB5FCu);
    ctx->pc = 0x1AB5F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB5F4u;
            // 0x1ab5f8: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x101C38u;
    if (runtime->hasFunction(0x101C38u)) {
        auto targetFn = runtime->lookupFunction(0x101C38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB5FCu; }
        if (ctx->pc != 0x1AB5FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00101C38_0x101c38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB5FCu; }
        if (ctx->pc != 0x1AB5FCu) { return; }
    }
    ctx->pc = 0x1AB5FCu;
label_1ab5fc:
    // 0x1ab5fc: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1ab5fcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1ab600: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1ab600u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ab604: 0xc04629c  jal         func_118A70
    ctx->pc = 0x1AB604u;
    SET_GPR_U32(ctx, 31, 0x1AB60Cu);
    ctx->pc = 0x1AB608u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB604u;
            // 0x1ab608: 0x2484fd70  addiu       $a0, $a0, -0x290 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966640));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118A70u;
    if (runtime->hasFunction(0x118A70u)) {
        auto targetFn = runtime->lookupFunction(0x118A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB60Cu; }
        if (ctx->pc != 0x1AB60Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118A70_0x118a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB60Cu; }
        if (ctx->pc != 0x1AB60Cu) { return; }
    }
    ctx->pc = 0x1AB60Cu;
label_1ab60c:
    // 0x1ab60c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1ab60cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ab610: 0x440fffa  bltz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1AB610u;
    {
        const bool branch_taken_0x1ab610 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1ab610) {
            ctx->pc = 0x1AB5FCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1ab5fc;
        }
    }
    ctx->pc = 0x1AB618u;
    // 0x1ab618: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1ab618u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ab61c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1ab61cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ab620: 0xc04639e  jal         func_118E78
    ctx->pc = 0x1AB620u;
    SET_GPR_U32(ctx, 31, 0x1AB628u);
    ctx->pc = 0x1AB624u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB620u;
            // 0x1ab624: 0x24060002  addiu       $a2, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118E78u;
    if (runtime->hasFunction(0x118E78u)) {
        auto targetFn = runtime->lookupFunction(0x118E78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB628u; }
        if (ctx->pc != 0x1AB628u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118E78_0x118e78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB628u; }
        if (ctx->pc != 0x1AB628u) { return; }
    }
    ctx->pc = 0x1AB628u;
label_1ab628:
    // 0x1ab628: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x1ab628u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ab62c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1ab62cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ab630: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1ab630u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ab634: 0xc04639e  jal         func_118E78
    ctx->pc = 0x1AB634u;
    SET_GPR_U32(ctx, 31, 0x1AB63Cu);
    ctx->pc = 0x1AB638u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB634u;
            // 0x1ab638: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118E78u;
    if (runtime->hasFunction(0x118E78u)) {
        auto targetFn = runtime->lookupFunction(0x118E78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB63Cu; }
        if (ctx->pc != 0x1AB63Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118E78_0x118e78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB63Cu; }
        if (ctx->pc != 0x1AB63Cu) { return; }
    }
    ctx->pc = 0x1AB63Cu;
label_1ab63c:
    // 0x1ab63c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1ab63cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ab640: 0x3c050100  lui         $a1, 0x100
    ctx->pc = 0x1ab640u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)256 << 16));
    // 0x1ab644: 0xc04642c  jal         func_1190B0
    ctx->pc = 0x1AB644u;
    SET_GPR_U32(ctx, 31, 0x1AB64Cu);
    ctx->pc = 0x1AB648u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB644u;
            // 0x1ab648: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1190B0u;
    if (runtime->hasFunction(0x1190B0u)) {
        auto targetFn = runtime->lookupFunction(0x1190B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB64Cu; }
        if (ctx->pc != 0x1AB64Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001190B0_0x1190b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB64Cu; }
        if (ctx->pc != 0x1AB64Cu) { return; }
    }
    ctx->pc = 0x1AB64Cu;
label_1ab64c:
    // 0x1ab64c: 0xc04633e  jal         func_118CF8
    ctx->pc = 0x1AB64Cu;
    SET_GPR_U32(ctx, 31, 0x1AB654u);
    ctx->pc = 0x1AB650u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB64Cu;
            // 0x1ab650: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118CF8u;
    if (runtime->hasFunction(0x118CF8u)) {
        auto targetFn = runtime->lookupFunction(0x118CF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB654u; }
        if (ctx->pc != 0x1AB654u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118CF8_0x118cf8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB654u; }
        if (ctx->pc != 0x1AB654u) { return; }
    }
    ctx->pc = 0x1AB654u;
label_1ab654:
    // 0x1ab654: 0xc046e2c  jal         func_11B8B0
    ctx->pc = 0x1AB654u;
    SET_GPR_U32(ctx, 31, 0x1AB65Cu);
    ctx->pc = 0x1AB658u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB654u;
            // 0x1ab658: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11B8B0u;
    if (runtime->hasFunction(0x11B8B0u)) {
        auto targetFn = runtime->lookupFunction(0x11B8B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB65Cu; }
        if (ctx->pc != 0x1AB65Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011B8B0_0x11b8b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB65Cu; }
        if (ctx->pc != 0x1AB65Cu) { return; }
    }
    ctx->pc = 0x1AB65Cu;
label_1ab65c:
    // 0x1ab65c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1ab65cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ab660: 0x0  nop
    ctx->pc = 0x1ab660u;
    // NOP
    // 0x1ab664: 0x0  nop
    ctx->pc = 0x1ab664u;
    // NOP
    // 0x1ab668: 0x1040fffa  beqz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1AB668u;
    {
        const bool branch_taken_0x1ab668 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ab668) {
            ctx->pc = 0x1AB654u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1ab654;
        }
    }
    ctx->pc = 0x1AB670u;
    // 0x1ab670: 0x3c020100  lui         $v0, 0x100
    ctx->pc = 0x1ab670u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)256 << 16));
    // 0x1ab674: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1ab674u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ab678: 0xafa20030  sw          $v0, 0x30($sp)
    ctx->pc = 0x1ab678u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 2));
    // 0x1ab67c: 0xafb10038  sw          $s1, 0x38($sp)
    ctx->pc = 0x1ab67cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 17));
    // 0x1ab680: 0xafb00034  sw          $s0, 0x34($sp)
    ctx->pc = 0x1ab680u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 16));
    // 0x1ab684: 0xc045228  jal         func_1148A0
    ctx->pc = 0x1AB684u;
    SET_GPR_U32(ctx, 31, 0x1AB68Cu);
    ctx->pc = 0x1AB688u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB684u;
            // 0x1ab688: 0xafa0003c  sw          $zero, 0x3C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1148A0u;
    if (runtime->hasFunction(0x1148A0u)) {
        auto targetFn = runtime->lookupFunction(0x1148A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB68Cu; }
        if (ctx->pc != 0x1AB68Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001148A0_0x1148a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB68Cu; }
        if (ctx->pc != 0x1AB68Cu) { return; }
    }
    ctx->pc = 0x1AB68Cu;
label_1ab68c:
    // 0x1ab68c: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1ab68cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1ab690: 0xc045278  jal         func_1149E0
    ctx->pc = 0x1AB690u;
    SET_GPR_U32(ctx, 31, 0x1AB698u);
    ctx->pc = 0x1AB694u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB690u;
            // 0x1ab694: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1149E0u;
    if (runtime->hasFunction(0x1149E0u)) {
        auto targetFn = runtime->lookupFunction(0x1149E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB698u; }
        if (ctx->pc != 0x1AB698u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001149E0_0x1149e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB698u; }
        if (ctx->pc != 0x1AB698u) { return; }
    }
    ctx->pc = 0x1AB698u;
label_1ab698:
    // 0x1ab698: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x1ab698u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_1ab69c:
    // 0x1ab69c: 0xc045270  jal         func_1149C0
    ctx->pc = 0x1AB69Cu;
    SET_GPR_U32(ctx, 31, 0x1AB6A4u);
    ctx->pc = 0x1AB6A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB69Cu;
            // 0x1ab6a0: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1149C0u;
    if (runtime->hasFunction(0x1149C0u)) {
        auto targetFn = runtime->lookupFunction(0x1149C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB6A4u; }
        if (ctx->pc != 0x1AB6A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001149C0_0x1149c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB6A4u; }
        if (ctx->pc != 0x1AB6A4u) { return; }
    }
    ctx->pc = 0x1AB6A4u;
label_1ab6a4:
    // 0x1ab6a4: 0x0  nop
    ctx->pc = 0x1ab6a4u;
    // NOP
    // 0x1ab6a8: 0x0  nop
    ctx->pc = 0x1ab6a8u;
    // NOP
    // 0x1ab6ac: 0x0  nop
    ctx->pc = 0x1ab6acu;
    // NOP
    // 0x1ab6b0: 0x441fffa  bgez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1AB6B0u;
    {
        const bool branch_taken_0x1ab6b0 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1ab6b0) {
            ctx->pc = 0x1AB69Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1ab69c;
        }
    }
    ctx->pc = 0x1AB6B8u;
    // 0x1ab6b8: 0x3c010100  lui         $at, 0x100
    ctx->pc = 0x1ab6b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)256 << 16));
    // 0x1ab6bc: 0x3c050100  lui         $a1, 0x100
    ctx->pc = 0x1ab6bcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)256 << 16));
    // 0x1ab6c0: 0x8c230004  lw          $v1, 0x4($at)
    ctx->pc = 0x1ab6c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4)));
    // 0x1ab6c4: 0x24a50008  addiu       $a1, $a1, 0x8
    ctx->pc = 0x1ab6c4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8));
    // 0x1ab6c8: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1AB6C8u;
    {
        const bool branch_taken_0x1ab6c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AB6CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB6C8u;
            // 0x1ab6cc: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ab6c8) {
            ctx->pc = 0x1AB6E4u;
            goto label_1ab6e4;
        }
    }
    ctx->pc = 0x1AB6D0u;
label_1ab6d0:
    // 0x1ab6d0: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x1ab6d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1ab6d4: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1ab6d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1ab6d8: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1ab6d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1ab6dc: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1ab6dcu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1ab6e0: 0x24a50008  addiu       $a1, $a1, 0x8
    ctx->pc = 0x1ab6e0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8));
label_1ab6e4:
    // 0x1ab6e4: 0x83102a  slt         $v0, $a0, $v1
    ctx->pc = 0x1ab6e4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1ab6e8: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1AB6E8u;
    {
        const bool branch_taken_0x1ab6e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AB6ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB6E8u;
            // 0x1ab6ec: 0x3c110023  lui         $s1, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ab6e8) {
            ctx->pc = 0x1AB6D0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1ab6d0;
        }
    }
    ctx->pc = 0x1AB6F0u;
    // 0x1ab6f0: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1AB6F0u;
    {
        const bool branch_taken_0x1ab6f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AB6F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB6F0u;
            // 0x1ab6f4: 0x26313e70  addiu       $s1, $s1, 0x3E70 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 15984));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ab6f0) {
            ctx->pc = 0x1AB720u;
            goto label_1ab720;
        }
    }
    ctx->pc = 0x1AB6F8u;
label_1ab6f8:
    // 0x1ab6f8: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AB6F8u;
    {
        const bool branch_taken_0x1ab6f8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1AB6FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB6F8u;
            // 0x1ab6fc: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ab6f8) {
            ctx->pc = 0x1AB708u;
            goto label_1ab708;
        }
    }
    ctx->pc = 0x1AB700u;
    // 0x1ab700: 0xc04b132  jal         func_12C4C8
    ctx->pc = 0x1AB700u;
    SET_GPR_U32(ctx, 31, 0x1AB708u);
    ctx->pc = 0x1AB704u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB700u;
            // 0x1ab704: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12C4C8u;
    if (runtime->hasFunction(0x12C4C8u)) {
        auto targetFn = runtime->lookupFunction(0x12C4C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB708u; }
        if (ctx->pc != 0x1AB708u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C4C8_0x12c4c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB708u; }
        if (ctx->pc != 0x1AB708u) { return; }
    }
    ctx->pc = 0x1AB708u;
label_1ab708:
    // 0x1ab708: 0x8e250000  lw          $a1, 0x0($s1)
    ctx->pc = 0x1ab708u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1ab70c: 0x8e260004  lw          $a2, 0x4($s1)
    ctx->pc = 0x1ab70cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1ab710: 0x8e270008  lw          $a3, 0x8($s1)
    ctx->pc = 0x1ab710u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1ab714: 0xc06ad40  jal         func_1AB500
    ctx->pc = 0x1AB714u;
    SET_GPR_U32(ctx, 31, 0x1AB71Cu);
    ctx->pc = 0x1AB718u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB714u;
            // 0x1ab718: 0x3c040100  lui         $a0, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)256 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AB500u;
    if (runtime->hasFunction(0x1AB500u)) {
        auto targetFn = runtime->lookupFunction(0x1AB500u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB71Cu; }
        if (ctx->pc != 0x1AB71Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AB500_0x1ab500(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB71Cu; }
        if (ctx->pc != 0x1AB71Cu) { return; }
    }
    ctx->pc = 0x1AB71Cu;
label_1ab71c:
    // 0x1ab71c: 0x2631000c  addiu       $s1, $s1, 0xC
    ctx->pc = 0x1ab71cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 12));
label_1ab720:
    // 0x1ab720: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x1ab720u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1ab724: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1ab724u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1ab728: 0x1462fff3  bne         $v1, $v0, . + 4 + (-0xD << 2)
    ctx->pc = 0x1AB728u;
    {
        const bool branch_taken_0x1ab728 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1AB72Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB728u;
            // 0x1ab72c: 0x24020009  addiu       $v0, $zero, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ab728) {
            ctx->pc = 0x1AB6F8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1ab6f8;
        }
    }
    ctx->pc = 0x1AB730u;
    // 0x1ab730: 0xc046e86  jal         func_11BA18
    ctx->pc = 0x1AB730u;
    SET_GPR_U32(ctx, 31, 0x1AB738u);
    ctx->pc = 0x1AB734u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB730u;
            // 0x1ab734: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11BA18u;
    if (runtime->hasFunction(0x11BA18u)) {
        auto targetFn = runtime->lookupFunction(0x11BA18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB738u; }
        if (ctx->pc != 0x1AB738u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011BA18_0x11ba18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB738u; }
        if (ctx->pc != 0x1AB738u) { return; }
    }
    ctx->pc = 0x1AB738u;
label_1ab738:
    // 0x1ab738: 0xc06f3d8  jal         func_1BCF60
    ctx->pc = 0x1AB738u;
    SET_GPR_U32(ctx, 31, 0x1AB740u);
    ctx->pc = 0x1BCF60u;
    if (runtime->hasFunction(0x1BCF60u)) {
        auto targetFn = runtime->lookupFunction(0x1BCF60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB740u; }
        if (ctx->pc != 0x1AB740u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BCF60_0x1bcf60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB740u; }
        if (ctx->pc != 0x1AB740u) { return; }
    }
    ctx->pc = 0x1AB740u;
label_1ab740:
    // 0x1ab740: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1ab740u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1ab744: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1ab744u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ab748: 0x2484fd90  addiu       $a0, $a0, -0x270
    ctx->pc = 0x1ab748u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966672));
    // 0x1ab74c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1ab74cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ab750: 0xc0635dc  jal         func_18D770
    ctx->pc = 0x1AB750u;
    SET_GPR_U32(ctx, 31, 0x1AB758u);
    ctx->pc = 0x1AB754u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB750u;
            // 0x1ab754: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18D770u;
    if (runtime->hasFunction(0x18D770u)) {
        auto targetFn = runtime->lookupFunction(0x18D770u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB758u; }
        if (ctx->pc != 0x1AB758u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018D770_0x18d770(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB758u; }
        if (ctx->pc != 0x1AB758u) { return; }
    }
    ctx->pc = 0x1AB758u;
label_1ab758:
    // 0x1ab758: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1ab758u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1ab75c: 0x3c060025  lui         $a2, 0x25
    ctx->pc = 0x1ab75cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)37 << 16));
    // 0x1ab760: 0x2484fdb0  addiu       $a0, $a0, -0x250
    ctx->pc = 0x1ab760u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966704));
    // 0x1ab764: 0x24050010  addiu       $a1, $zero, 0x10
    ctx->pc = 0x1ab764u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1ab768: 0x24c6fdd0  addiu       $a2, $a2, -0x230
    ctx->pc = 0x1ab768u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294966736));
    // 0x1ab76c: 0xc0635dc  jal         func_18D770
    ctx->pc = 0x1AB76Cu;
    SET_GPR_U32(ctx, 31, 0x1AB774u);
    ctx->pc = 0x1AB770u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB76Cu;
            // 0x1ab770: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18D770u;
    if (runtime->hasFunction(0x18D770u)) {
        auto targetFn = runtime->lookupFunction(0x18D770u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB774u; }
        if (ctx->pc != 0x1AB774u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018D770_0x18d770(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB774u; }
        if (ctx->pc != 0x1AB774u) { return; }
    }
    ctx->pc = 0x1AB774u;
label_1ab774:
    // 0x1ab774: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1ab774u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1ab778: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1ab778u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ab77c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ab77cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ab780: 0x3e00008  jr          $ra
    ctx->pc = 0x1AB780u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AB784u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB780u;
            // 0x1ab784: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AB578u: goto label_1ab578;
            case 0x1AB580u: goto label_1ab580;
            case 0x1AB588u: goto label_1ab588;
            case 0x1AB590u: goto label_1ab590;
            case 0x1AB59Cu: goto label_1ab59c;
            case 0x1AB5ACu: goto label_1ab5ac;
            case 0x1AB5B4u: goto label_1ab5b4;
            case 0x1AB5D4u: goto label_1ab5d4;
            case 0x1AB5DCu: goto label_1ab5dc;
            case 0x1AB5E4u: goto label_1ab5e4;
            case 0x1AB5ECu: goto label_1ab5ec;
            case 0x1AB5F4u: goto label_1ab5f4;
            case 0x1AB5FCu: goto label_1ab5fc;
            case 0x1AB60Cu: goto label_1ab60c;
            case 0x1AB628u: goto label_1ab628;
            case 0x1AB63Cu: goto label_1ab63c;
            case 0x1AB64Cu: goto label_1ab64c;
            case 0x1AB654u: goto label_1ab654;
            case 0x1AB65Cu: goto label_1ab65c;
            case 0x1AB68Cu: goto label_1ab68c;
            case 0x1AB698u: goto label_1ab698;
            case 0x1AB69Cu: goto label_1ab69c;
            case 0x1AB6A4u: goto label_1ab6a4;
            case 0x1AB6D0u: goto label_1ab6d0;
            case 0x1AB6E4u: goto label_1ab6e4;
            case 0x1AB6F8u: goto label_1ab6f8;
            case 0x1AB708u: goto label_1ab708;
            case 0x1AB71Cu: goto label_1ab71c;
            case 0x1AB720u: goto label_1ab720;
            case 0x1AB738u: goto label_1ab738;
            case 0x1AB740u: goto label_1ab740;
            case 0x1AB758u: goto label_1ab758;
            case 0x1AB774u: goto label_1ab774;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AB788u;
    // 0x1ab788: 0x0  nop
    ctx->pc = 0x1ab788u;
    // NOP
    // 0x1ab78c: 0x0  nop
    ctx->pc = 0x1ab78cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
