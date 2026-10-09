#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015D878
// Address: 0x15d878 - 0x15d9d8
void sub_0015D878_0x15d878(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015D878_0x15d878");
#endif

    switch (ctx->pc) {
        case 0x15d8a4u: goto label_15d8a4;
        case 0x15d8b8u: goto label_15d8b8;
        case 0x15d8c8u: goto label_15d8c8;
        case 0x15d8d8u: goto label_15d8d8;
        case 0x15d900u: goto label_15d900;
        case 0x15d910u: goto label_15d910;
        case 0x15d920u: goto label_15d920;
        case 0x15d938u: goto label_15d938;
        case 0x15d954u: goto label_15d954;
        case 0x15d974u: goto label_15d974;
        case 0x15d984u: goto label_15d984;
        case 0x15d990u: goto label_15d990;
        case 0x15d99cu: goto label_15d99c;
        case 0x15d9a4u: goto label_15d9a4;
        case 0x15d9b0u: goto label_15d9b0;
        default: break;
    }

    ctx->pc = 0x15d878u;

    // 0x15d878: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x15d878u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x15d87c: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x15d87cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x15d880: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x15d880u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d884: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x15d884u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x15d888: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x15d888u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x15d88c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x15d88cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x15d890: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x15d890u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x15d894: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x15d894u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x15d898: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x15d898u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x15d89c: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x15D89Cu;
    SET_GPR_U32(ctx, 31, 0x15D8A4u);
    ctx->pc = 0x15D8A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D89Cu;
            // 0x15d8a0: 0xa0982d  daddu       $s3, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D8A4u; }
        if (ctx->pc != 0x15D8A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D8A4u; }
        if (ctx->pc != 0x15D8A4u) { return; }
    }
    ctx->pc = 0x15D8A4u;
label_15d8a4:
    // 0x15d8a4: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x15D8A4u;
    {
        const bool branch_taken_0x15d8a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x15d8a4) {
            ctx->pc = 0x15D8C0u;
            goto label_15d8c0;
        }
    }
    ctx->pc = 0x15D8ACu;
    // 0x15d8ac: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15d8acu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15d8b0: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15D8B0u;
    SET_GPR_U32(ctx, 31, 0x15D8B8u);
    ctx->pc = 0x15D8B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D8B0u;
            // 0x15d8b4: 0x2484ec50  addiu       $a0, $a0, -0x13B0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294962256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D8B8u; }
        if (ctx->pc != 0x15D8B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D8B8u; }
        if (ctx->pc != 0x15D8B8u) { return; }
    }
    ctx->pc = 0x15D8B8u;
label_15d8b8:
    // 0x15d8b8: 0x1000003e  b           . + 4 + (0x3E << 2)
    ctx->pc = 0x15D8B8u;
    {
        const bool branch_taken_0x15d8b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15D8BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D8B8u;
            // 0x15d8bc: 0xae600000  sw          $zero, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d8b8) {
            ctx->pc = 0x15D9B4u;
            goto label_15d9b4;
        }
    }
    ctx->pc = 0x15D8C0u;
label_15d8c0:
    // 0x15d8c0: 0xc057ec8  jal         func_15FB20
    ctx->pc = 0x15D8C0u;
    SET_GPR_U32(ctx, 31, 0x15D8C8u);
    ctx->pc = 0x15D8C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D8C0u;
            // 0x15d8c4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FB20u;
    if (runtime->hasFunction(0x15FB20u)) {
        auto targetFn = runtime->lookupFunction(0x15FB20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D8C8u; }
        if (ctx->pc != 0x15D8C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FB20_0x15fb20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D8C8u; }
        if (ctx->pc != 0x15D8C8u) { return; }
    }
    ctx->pc = 0x15D8C8u;
label_15d8c8:
    // 0x15d8c8: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x15d8c8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d8cc: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x15d8ccu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d8d0: 0xc05cfec  jal         func_173FB0
    ctx->pc = 0x15D8D0u;
    SET_GPR_U32(ctx, 31, 0x15D8D8u);
    ctx->pc = 0x15D8D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D8D0u;
            // 0x15d8d4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x173FB0u;
    if (runtime->hasFunction(0x173FB0u)) {
        auto targetFn = runtime->lookupFunction(0x173FB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D8D8u; }
        if (ctx->pc != 0x15D8D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00173FB0_0x173fb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D8D8u; }
        if (ctx->pc != 0x15D8D8u) { return; }
    }
    ctx->pc = 0x15D8D8u;
label_15d8d8:
    // 0x15d8d8: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x15d8d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15d8dc: 0x50600035  beql        $v1, $zero, . + 4 + (0x35 << 2)
    ctx->pc = 0x15D8DCu;
    {
        const bool branch_taken_0x15d8dc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x15d8dc) {
            ctx->pc = 0x15D8E0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15D8DCu;
            // 0x15d8e0: 0xae600000  sw          $zero, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15D9B4u;
            goto label_15d9b4;
        }
    }
    ctx->pc = 0x15D8E4u;
    // 0x15d8e4: 0x8e020054  lw          $v0, 0x54($s0)
    ctx->pc = 0x15d8e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 84)));
    // 0x15d8e8: 0x14400016  bnez        $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x15D8E8u;
    {
        const bool branch_taken_0x15d8e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15D8ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D8E8u;
            // 0x15d8ec: 0x902d  daddu       $s2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d8e8) {
            ctx->pc = 0x15D944u;
            goto label_15d944;
        }
    }
    ctx->pc = 0x15D8F0u;
    // 0x15d8f0: 0x8e14001c  lw          $s4, 0x1C($s0)
    ctx->pc = 0x15d8f0u;
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x15d8f4: 0x24150001  addiu       $s5, $zero, 0x1
    ctx->pc = 0x15d8f4u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15d8f8: 0x254102a  slt         $v0, $s2, $s4
    ctx->pc = 0x15d8f8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 20)) ? 1 : 0);
    // 0x15d8fc: 0x0  nop
    ctx->pc = 0x15d8fcu;
    // NOP
label_15d900:
    // 0x15d900: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x15D900u;
    {
        const bool branch_taken_0x15d900 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15D904u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D900u;
            // 0x15d904: 0x26520001  addiu       $s2, $s2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d900) {
            ctx->pc = 0x15D940u;
            goto label_15d940;
        }
    }
    ctx->pc = 0x15D908u;
    // 0x15d908: 0xc0578fc  jal         func_15E3F0
    ctx->pc = 0x15D908u;
    SET_GPR_U32(ctx, 31, 0x15D910u);
    ctx->pc = 0x15D90Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D908u;
            // 0x15d90c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15E3F0u;
    if (runtime->hasFunction(0x15E3F0u)) {
        auto targetFn = runtime->lookupFunction(0x15E3F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D910u; }
        if (ctx->pc != 0x15D910u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E3F0_0x15e3f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D910u; }
        if (ctx->pc != 0x15D910u) { return; }
    }
    ctx->pc = 0x15D910u;
label_15d910:
    // 0x15d910: 0x1455000b  bne         $v0, $s5, . + 4 + (0xB << 2)
    ctx->pc = 0x15D910u;
    {
        const bool branch_taken_0x15d910 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 21));
        ctx->pc = 0x15D914u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D910u;
            // 0x15d914: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d910) {
            ctx->pc = 0x15D940u;
            goto label_15d940;
        }
    }
    ctx->pc = 0x15D918u;
    // 0x15d918: 0xc05d00c  jal         func_174030
    ctx->pc = 0x15D918u;
    SET_GPR_U32(ctx, 31, 0x15D920u);
    ctx->pc = 0x15D91Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D918u;
            // 0x15d91c: 0x8fa50000  lw          $a1, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x174030u;
    if (runtime->hasFunction(0x174030u)) {
        auto targetFn = runtime->lookupFunction(0x174030u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D920u; }
        if (ctx->pc != 0x15D920u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00174030_0x174030(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D920u; }
        if (ctx->pc != 0x15D920u) { return; }
    }
    ctx->pc = 0x15D920u;
label_15d920:
    // 0x15d920: 0x8e030084  lw          $v1, 0x84($s0)
    ctx->pc = 0x15d920u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 132)));
    // 0x15d924: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x15d924u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d928: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x15d928u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d92c: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x15d92cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x15d930: 0xc05cfec  jal         func_173FB0
    ctx->pc = 0x15D930u;
    SET_GPR_U32(ctx, 31, 0x15D938u);
    ctx->pc = 0x15D934u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D930u;
            // 0x15d934: 0xae030084  sw          $v1, 0x84($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 132), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x173FB0u;
    if (runtime->hasFunction(0x173FB0u)) {
        auto targetFn = runtime->lookupFunction(0x173FB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D938u; }
        if (ctx->pc != 0x15D938u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00173FB0_0x173fb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D938u; }
        if (ctx->pc != 0x15D938u) { return; }
    }
    ctx->pc = 0x15D938u;
label_15d938:
    // 0x15d938: 0x1000fff1  b           . + 4 + (-0xF << 2)
    ctx->pc = 0x15D938u;
    {
        const bool branch_taken_0x15d938 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15D93Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D938u;
            // 0x15d93c: 0x254102a  slt         $v0, $s2, $s4 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 20)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d938) {
            ctx->pc = 0x15D900u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_15d900;
        }
    }
    ctx->pc = 0x15D940u;
label_15d940:
    // 0x15d940: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x15d940u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_15d944:
    // 0x15d944: 0x5060001b  beql        $v1, $zero, . + 4 + (0x1B << 2)
    ctx->pc = 0x15D944u;
    {
        const bool branch_taken_0x15d944 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x15d944) {
            ctx->pc = 0x15D948u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15D944u;
            // 0x15d948: 0xae600000  sw          $zero, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15D9B4u;
            goto label_15d9b4;
        }
    }
    ctx->pc = 0x15D94Cu;
    // 0x15d94c: 0xc0577aa  jal         func_15DEA8
    ctx->pc = 0x15D94Cu;
    SET_GPR_U32(ctx, 31, 0x15D954u);
    ctx->pc = 0x15D950u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D94Cu;
            // 0x15d950: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15DEA8u;
    if (runtime->hasFunction(0x15DEA8u)) {
        auto targetFn = runtime->lookupFunction(0x15DEA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D954u; }
        if (ctx->pc != 0x15D954u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015DEA8_0x15dea8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D954u; }
        if (ctx->pc != 0x15D954u) { return; }
    }
    ctx->pc = 0x15D954u;
label_15d954:
    // 0x15d954: 0x8e02007c  lw          $v0, 0x7C($s0)
    ctx->pc = 0x15d954u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 124)));
    // 0x15d958: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x15d958u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15d95c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15d95cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d960: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x15d960u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x15d964: 0xae02007c  sw          $v0, 0x7C($s0)
    ctx->pc = 0x15d964u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 124), GPR_U32(ctx, 2));
    // 0x15d968: 0x60282d  daddu       $a1, $v1, $zero
    ctx->pc = 0x15d968u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d96c: 0xc057798  jal         func_15DE60
    ctx->pc = 0x15D96Cu;
    SET_GPR_U32(ctx, 31, 0x15D974u);
    ctx->pc = 0x15D970u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D96Cu;
            // 0x15d970: 0xae030078  sw          $v1, 0x78($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 120), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15DE60u;
    if (runtime->hasFunction(0x15DE60u)) {
        auto targetFn = runtime->lookupFunction(0x15DE60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D974u; }
        if (ctx->pc != 0x15D974u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015DE60_0x15de60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D974u; }
        if (ctx->pc != 0x15D974u) { return; }
    }
    ctx->pc = 0x15D974u;
label_15d974:
    // 0x15d974: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15d974u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d978: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x15d978u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15d97c: 0xc0576aa  jal         func_15DAA8
    ctx->pc = 0x15D97Cu;
    SET_GPR_U32(ctx, 31, 0x15D984u);
    ctx->pc = 0x15D980u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D97Cu;
            // 0x15d980: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15DAA8u;
    if (runtime->hasFunction(0x15DAA8u)) {
        auto targetFn = runtime->lookupFunction(0x15DAA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D984u; }
        if (ctx->pc != 0x15D984u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015DAA8_0x15daa8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D984u; }
        if (ctx->pc != 0x15D984u) { return; }
    }
    ctx->pc = 0x15D984u;
label_15d984:
    // 0x15d984: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15d984u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d988: 0xc057812  jal         func_15E048
    ctx->pc = 0x15D988u;
    SET_GPR_U32(ctx, 31, 0x15D990u);
    ctx->pc = 0x15D98Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D988u;
            // 0x15d98c: 0x8fa50000  lw          $a1, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15E048u;
    if (runtime->hasFunction(0x15E048u)) {
        auto targetFn = runtime->lookupFunction(0x15E048u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D990u; }
        if (ctx->pc != 0x15D990u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E048_0x15e048(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D990u; }
        if (ctx->pc != 0x15D990u) { return; }
    }
    ctx->pc = 0x15D990u;
label_15d990:
    // 0x15d990: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15d990u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d994: 0xc057676  jal         func_15D9D8
    ctx->pc = 0x15D994u;
    SET_GPR_U32(ctx, 31, 0x15D99Cu);
    ctx->pc = 0x15D998u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D994u;
            // 0x15d998: 0x260282d  daddu       $a1, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15D9D8u;
    if (runtime->hasFunction(0x15D9D8u)) {
        auto targetFn = runtime->lookupFunction(0x15D9D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D99Cu; }
        if (ctx->pc != 0x15D99Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015D9D8_0x15d9d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D99Cu; }
        if (ctx->pc != 0x15D99Cu) { return; }
    }
    ctx->pc = 0x15D99Cu;
label_15d99c:
    // 0x15d99c: 0xc05768a  jal         func_15DA28
    ctx->pc = 0x15D99Cu;
    SET_GPR_U32(ctx, 31, 0x15D9A4u);
    ctx->pc = 0x15D9A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D99Cu;
            // 0x15d9a0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15DA28u;
    if (runtime->hasFunction(0x15DA28u)) {
        auto targetFn = runtime->lookupFunction(0x15DA28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D9A4u; }
        if (ctx->pc != 0x15D9A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015DA28_0x15da28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D9A4u; }
        if (ctx->pc != 0x15D9A4u) { return; }
    }
    ctx->pc = 0x15D9A4u;
label_15d9a4:
    // 0x15d9a4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15d9a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d9a8: 0xc05776e  jal         func_15DDB8
    ctx->pc = 0x15D9A8u;
    SET_GPR_U32(ctx, 31, 0x15D9B0u);
    ctx->pc = 0x15D9ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D9A8u;
            // 0x15d9ac: 0x8fa50000  lw          $a1, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15DDB8u;
    if (runtime->hasFunction(0x15DDB8u)) {
        auto targetFn = runtime->lookupFunction(0x15DDB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D9B0u; }
        if (ctx->pc != 0x15D9B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015DDB8_0x15ddb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D9B0u; }
        if (ctx->pc != 0x15D9B0u) { return; }
    }
    ctx->pc = 0x15D9B0u;
label_15d9b0:
    // 0x15d9b0: 0xae620048  sw          $v0, 0x48($s3)
    ctx->pc = 0x15d9b0u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 72), GPR_U32(ctx, 2));
label_15d9b4:
    // 0x15d9b4: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x15d9b4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15d9b8: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x15d9b8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15d9bc: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x15d9bcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x15d9c0: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x15d9c0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x15d9c4: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x15d9c4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x15d9c8: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x15d9c8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x15d9cc: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x15d9ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x15d9d0: 0x3e00008  jr          $ra
    ctx->pc = 0x15D9D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15D9D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D9D0u;
            // 0x15d9d4: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15D8A4u: goto label_15d8a4;
            case 0x15D8B8u: goto label_15d8b8;
            case 0x15D8C0u: goto label_15d8c0;
            case 0x15D8C8u: goto label_15d8c8;
            case 0x15D8D8u: goto label_15d8d8;
            case 0x15D900u: goto label_15d900;
            case 0x15D910u: goto label_15d910;
            case 0x15D920u: goto label_15d920;
            case 0x15D938u: goto label_15d938;
            case 0x15D940u: goto label_15d940;
            case 0x15D944u: goto label_15d944;
            case 0x15D954u: goto label_15d954;
            case 0x15D974u: goto label_15d974;
            case 0x15D984u: goto label_15d984;
            case 0x15D990u: goto label_15d990;
            case 0x15D99Cu: goto label_15d99c;
            case 0x15D9A4u: goto label_15d9a4;
            case 0x15D9B0u: goto label_15d9b0;
            case 0x15D9B4u: goto label_15d9b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15D9D8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
