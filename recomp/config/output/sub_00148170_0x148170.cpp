#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00148170
// Address: 0x148170 - 0x148328
void sub_00148170_0x148170(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00148170_0x148170");
#endif

    switch (ctx->pc) {
        case 0x1481b8u: goto label_1481b8;
        case 0x1481d4u: goto label_1481d4;
        case 0x1481dcu: goto label_1481dc;
        case 0x1481e4u: goto label_1481e4;
        case 0x1481f8u: goto label_1481f8;
        case 0x148200u: goto label_148200;
        case 0x148208u: goto label_148208;
        case 0x148260u: goto label_148260;
        case 0x148288u: goto label_148288;
        case 0x1482acu: goto label_1482ac;
        case 0x1482d0u: goto label_1482d0;
        default: break;
    }

    ctx->pc = 0x148170u;

    // 0x148170: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x148170u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x148174: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x148174u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x148178: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x148178u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x14817c: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x14817cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148180: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x148180u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x148184: 0x24120001  addiu       $s2, $zero, 0x1
    ctx->pc = 0x148184u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x148188: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x148188u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x14818c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x14818cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148190: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x148190u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x148194: 0x8e300040  lw          $s0, 0x40($s1)
    ctx->pc = 0x148194u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 64)));
    // 0x148198: 0x8e0600f0  lw          $a2, 0xF0($s0)
    ctx->pc = 0x148198u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 240)));
    // 0x14819c: 0x30c2003f  andi        $v0, $a2, 0x3F
    ctx->pc = 0x14819cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)63);
    // 0x1481a0: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1481A0u;
    {
        const bool branch_taken_0x1481a0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1481A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1481A0u;
            // 0x1481a4: 0xae000000  sw          $zero, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1481a0) {
            ctx->pc = 0x1481C0u;
            goto label_1481c0;
        }
    }
    ctx->pc = 0x1481A8u;
    // 0x1481a8: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x1481a8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x1481ac: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1481acu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1481b0: 0xc05220e  jal         func_148838
    ctx->pc = 0x1481B0u;
    SET_GPR_U32(ctx, 31, 0x1481B8u);
    ctx->pc = 0x1481B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1481B0u;
            // 0x1481b4: 0x24a5e058  addiu       $a1, $a1, -0x1FA8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294959192));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148838u;
    if (runtime->hasFunction(0x148838u)) {
        auto targetFn = runtime->lookupFunction(0x148838u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1481B8u; }
        if (ctx->pc != 0x1481B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00148838_0x148838(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1481B8u; }
        if (ctx->pc != 0x1481B8u) { return; }
    }
    ctx->pc = 0x1481B8u;
label_1481b8:
    // 0x1481b8: 0x10000053  b           . + 4 + (0x53 << 2)
    ctx->pc = 0x1481B8u;
    {
        const bool branch_taken_0x1481b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1481BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1481B8u;
            // 0x1481bc: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1481b8) {
            ctx->pc = 0x148308u;
            goto label_148308;
        }
    }
    ctx->pc = 0x1481C0u;
label_1481c0:
    // 0x1481c0: 0x8e0210a0  lw          $v0, 0x10A0($s0)
    ctx->pc = 0x1481c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4256)));
    // 0x1481c4: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1481C4u;
    {
        const bool branch_taken_0x1481c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1481C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1481C4u;
            // 0x1481c8: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1481c4) {
            ctx->pc = 0x1481ECu;
            goto label_1481ec;
        }
    }
    ctx->pc = 0x1481CCu;
    // 0x1481cc: 0xc045a12  jal         func_116848
    ctx->pc = 0x1481CCu;
    SET_GPR_U32(ctx, 31, 0x1481D4u);
    ctx->pc = 0x1481D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1481CCu;
            // 0x1481d0: 0x2484e098  addiu       $a0, $a0, -0x1F68 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294959256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1481D4u; }
        if (ctx->pc != 0x1481D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1481D4u; }
        if (ctx->pc != 0x1481D4u) { return; }
    }
    ctx->pc = 0x1481D4u;
label_1481d4:
    // 0x1481d4: 0x1000004c  b           . + 4 + (0x4C << 2)
    ctx->pc = 0x1481D4u;
    {
        const bool branch_taken_0x1481d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1481D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1481D4u;
            // 0x1481d8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1481d4) {
            ctx->pc = 0x148308u;
            goto label_148308;
        }
    }
    ctx->pc = 0x1481DCu;
label_1481dc:
    // 0x1481dc: 0xc045a12  jal         func_116848
    ctx->pc = 0x1481DCu;
    SET_GPR_U32(ctx, 31, 0x1481E4u);
    ctx->pc = 0x1481E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1481DCu;
            // 0x1481e0: 0x2484e0d8  addiu       $a0, $a0, -0x1F28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294959320));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1481E4u; }
        if (ctx->pc != 0x1481E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1481E4u; }
        if (ctx->pc != 0x1481E4u) { return; }
    }
    ctx->pc = 0x1481E4u;
label_1481e4:
    // 0x1481e4: 0x10000048  b           . + 4 + (0x48 << 2)
    ctx->pc = 0x1481E4u;
    {
        const bool branch_taken_0x1481e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1481E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1481E4u;
            // 0x1481e8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1481e4) {
            ctx->pc = 0x148308u;
            goto label_148308;
        }
    }
    ctx->pc = 0x1481ECu;
label_1481ec:
    // 0x1481ec: 0xae000838  sw          $zero, 0x838($s0)
    ctx->pc = 0x1481ecu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 2104), GPR_U32(ctx, 0));
    // 0x1481f0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1481f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1481f4: 0x0  nop
    ctx->pc = 0x1481f4u;
    // NOP
label_1481f8:
    // 0x1481f8: 0x1262000f  beq         $s3, $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x1481F8u;
    {
        const bool branch_taken_0x1481f8 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 2));
        ctx->pc = 0x1481FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1481F8u;
            // 0x1481fc: 0x2e420005  sltiu       $v0, $s2, 0x5 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)(int64_t)(int32_t)5) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1481f8) {
            ctx->pc = 0x148238u;
            goto label_148238;
        }
    }
    ctx->pc = 0x148200u;
label_148200:
    // 0x148200: 0xc051710  jal         func_145C40
    ctx->pc = 0x148200u;
    SET_GPR_U32(ctx, 31, 0x148208u);
    ctx->pc = 0x148204u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148200u;
            // 0x148204: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145C40u;
    if (runtime->hasFunction(0x145C40u)) {
        auto targetFn = runtime->lookupFunction(0x145C40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148208u; }
        if (ctx->pc != 0x148208u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145C40_0x145c40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148208u; }
        if (ctx->pc != 0x148208u) { return; }
    }
    ctx->pc = 0x148208u;
label_148208:
    // 0x148208: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x148208u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14820c: 0x640003e  bltz        $s2, . + 4 + (0x3E << 2)
    ctx->pc = 0x14820Cu;
    {
        const bool branch_taken_0x14820c = (GPR_S64(ctx, 18) < 0);
        ctx->pc = 0x148210u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14820Cu;
            // 0x148210: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14820c) {
            ctx->pc = 0x148308u;
            goto label_148308;
        }
    }
    ctx->pc = 0x148214u;
    // 0x148214: 0x12400008  beqz        $s2, . + 4 + (0x8 << 2)
    ctx->pc = 0x148214u;
    {
        const bool branch_taken_0x148214 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x148218u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148214u;
            // 0x148218: 0x2e420005  sltiu       $v0, $s2, 0x5 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)(int64_t)(int32_t)5) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x148214) {
            ctx->pc = 0x148238u;
            goto label_148238;
        }
    }
    ctx->pc = 0x14821Cu;
    // 0x14821c: 0x8e03018c  lw          $v1, 0x18C($s0)
    ctx->pc = 0x14821cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 396)));
    // 0x148220: 0x8e0200ec  lw          $v0, 0xEC($s0)
    ctx->pc = 0x148220u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 236)));
    // 0x148224: 0x10620004  beq         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x148224u;
    {
        const bool branch_taken_0x148224 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x148228u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148224u;
            // 0x148228: 0x2e420005  sltiu       $v0, $s2, 0x5 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)(int64_t)(int32_t)5) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x148224) {
            ctx->pc = 0x148238u;
            goto label_148238;
        }
    }
    ctx->pc = 0x14822Cu;
    // 0x14822c: 0x8e020860  lw          $v0, 0x860($s0)
    ctx->pc = 0x14822cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 2144)));
    // 0x148230: 0x1440fff3  bnez        $v0, . + 4 + (-0xD << 2)
    ctx->pc = 0x148230u;
    {
        const bool branch_taken_0x148230 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x148234u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148230u;
            // 0x148234: 0x2e420005  sltiu       $v0, $s2, 0x5 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)(int64_t)(int32_t)5) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x148230) {
            ctx->pc = 0x148200u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_148200;
        }
    }
    ctx->pc = 0x148238u;
label_148238:
    // 0x148238: 0x10400029  beqz        $v0, . + 4 + (0x29 << 2)
    ctx->pc = 0x148238u;
    {
        const bool branch_taken_0x148238 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x14823Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148238u;
            // 0x14823c: 0x3c020024  lui         $v0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x148238) {
            ctx->pc = 0x1482E0u;
            goto label_1482e0;
        }
    }
    ctx->pc = 0x148240u;
    // 0x148240: 0x121880  sll         $v1, $s2, 2
    ctx->pc = 0x148240u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
    // 0x148244: 0x2442e100  addiu       $v0, $v0, -0x1F00
    ctx->pc = 0x148244u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294959360));
    // 0x148248: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x148248u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x14824c: 0x8c640000  lw          $a0, 0x0($v1)
    ctx->pc = 0x14824cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x148250: 0x800008  jr          $a0
    ctx->pc = 0x148250u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 4);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x148258u: goto label_148258;
            case 0x14826Cu: goto label_14826c;
            case 0x14829Cu: goto label_14829c;
            case 0x1482C0u: goto label_1482c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x148258u;
label_148258:
    // 0x148258: 0xc052182  jal         func_148608
    ctx->pc = 0x148258u;
    SET_GPR_U32(ctx, 31, 0x148260u);
    ctx->pc = 0x14825Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148258u;
            // 0x14825c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148608u;
    if (runtime->hasFunction(0x148608u)) {
        auto targetFn = runtime->lookupFunction(0x148608u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148260u; }
        if (ctx->pc != 0x148260u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00148608_0x148608(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148260u; }
        if (ctx->pc != 0x148260u) { return; }
    }
    ctx->pc = 0x148260u;
label_148260:
    // 0x148260: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x148260u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x148264: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x148264u;
    {
        const bool branch_taken_0x148264 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x148268u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148264u;
            // 0x148268: 0xae030000  sw          $v1, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x148264) {
            ctx->pc = 0x1482E0u;
            goto label_1482e0;
        }
    }
    ctx->pc = 0x14826Cu;
label_14826c:
    // 0x14826c: 0xae0000c0  sw          $zero, 0xC0($s0)
    ctx->pc = 0x14826cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 192), GPR_U32(ctx, 0));
    // 0x148270: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x148270u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148274: 0xae0000bc  sw          $zero, 0xBC($s0)
    ctx->pc = 0x148274u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 188), GPR_U32(ctx, 0));
    // 0x148278: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x148278u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14827c: 0xae0000b8  sw          $zero, 0xB8($s0)
    ctx->pc = 0x14827cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 184), GPR_U32(ctx, 0));
    // 0x148280: 0xc052112  jal         func_148448
    ctx->pc = 0x148280u;
    SET_GPR_U32(ctx, 31, 0x148288u);
    ctx->pc = 0x148284u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x148280u;
            // 0x148284: 0x8e0600ac  lw          $a2, 0xAC($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 172)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148448u;
    if (runtime->hasFunction(0x148448u)) {
        auto targetFn = runtime->lookupFunction(0x148448u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148288u; }
        if (ctx->pc != 0x148288u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00148448_0x148448(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148288u; }
        if (ctx->pc != 0x148288u) { return; }
    }
    ctx->pc = 0x148288u;
label_148288:
    // 0x148288: 0x8e0300b8  lw          $v1, 0xB8($s0)
    ctx->pc = 0x148288u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 184)));
    // 0x14828c: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x14828cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148290: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x148290u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x148294: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x148294u;
    {
        const bool branch_taken_0x148294 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x148298u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148294u;
            // 0x148298: 0xae0300b8  sw          $v1, 0xB8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 184), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x148294) {
            ctx->pc = 0x1482E0u;
            goto label_1482e0;
        }
    }
    ctx->pc = 0x14829Cu;
label_14829c:
    // 0x14829c: 0x8e0500bc  lw          $a1, 0xBC($s0)
    ctx->pc = 0x14829cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 188)));
    // 0x1482a0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1482a0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1482a4: 0xc052112  jal         func_148448
    ctx->pc = 0x1482A4u;
    SET_GPR_U32(ctx, 31, 0x1482ACu);
    ctx->pc = 0x1482A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1482A4u;
            // 0x1482a8: 0x8e0600b0  lw          $a2, 0xB0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 176)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148448u;
    if (runtime->hasFunction(0x148448u)) {
        auto targetFn = runtime->lookupFunction(0x148448u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1482ACu; }
        if (ctx->pc != 0x1482ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00148448_0x148448(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1482ACu; }
        if (ctx->pc != 0x1482ACu) { return; }
    }
    ctx->pc = 0x1482ACu;
label_1482ac:
    // 0x1482ac: 0x8e0300bc  lw          $v1, 0xBC($s0)
    ctx->pc = 0x1482acu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 188)));
    // 0x1482b0: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x1482b0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1482b4: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1482b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1482b8: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1482B8u;
    {
        const bool branch_taken_0x1482b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1482BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1482B8u;
            // 0x1482bc: 0xae0300bc  sw          $v1, 0xBC($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 188), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1482b8) {
            ctx->pc = 0x1482E0u;
            goto label_1482e0;
        }
    }
    ctx->pc = 0x1482C0u;
label_1482c0:
    // 0x1482c0: 0x8e0500c0  lw          $a1, 0xC0($s0)
    ctx->pc = 0x1482c0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 192)));
    // 0x1482c4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1482c4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1482c8: 0xc052112  jal         func_148448
    ctx->pc = 0x1482C8u;
    SET_GPR_U32(ctx, 31, 0x1482D0u);
    ctx->pc = 0x1482CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1482C8u;
            // 0x1482cc: 0x8e0600b4  lw          $a2, 0xB4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 180)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148448u;
    if (runtime->hasFunction(0x148448u)) {
        auto targetFn = runtime->lookupFunction(0x148448u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1482D0u; }
        if (ctx->pc != 0x1482D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00148448_0x148448(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1482D0u; }
        if (ctx->pc != 0x1482D0u) { return; }
    }
    ctx->pc = 0x1482D0u;
label_1482d0:
    // 0x1482d0: 0x8e0300c0  lw          $v1, 0xC0($s0)
    ctx->pc = 0x1482d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 192)));
    // 0x1482d4: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x1482d4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1482d8: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1482d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1482dc: 0xae0300c0  sw          $v1, 0xC0($s0)
    ctx->pc = 0x1482dcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 192), GPR_U32(ctx, 3));
label_1482e0:
    // 0x1482e0: 0x8e0210a0  lw          $v0, 0x10A0($s0)
    ctx->pc = 0x1482e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4256)));
    // 0x1482e4: 0x1440ffbd  bnez        $v0, . + 4 + (-0x43 << 2)
    ctx->pc = 0x1482E4u;
    {
        const bool branch_taken_0x1482e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1482E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1482E4u;
            // 0x1482e8: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1482e4) {
            ctx->pc = 0x1481DCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1481dc;
        }
    }
    ctx->pc = 0x1482ECu;
    // 0x1482ec: 0x8e020838  lw          $v0, 0x838($s0)
    ctx->pc = 0x1482ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 2104)));
    // 0x1482f0: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1482F0u;
    {
        const bool branch_taken_0x1482f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1482F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1482F0u;
            // 0x1482f4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1482f0) {
            ctx->pc = 0x148308u;
            goto label_148308;
        }
    }
    ctx->pc = 0x1482F8u;
    // 0x1482f8: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x1482f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1482fc: 0x1040ffbe  beqz        $v0, . + 4 + (-0x42 << 2)
    ctx->pc = 0x1482FCu;
    {
        const bool branch_taken_0x1482fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x148300u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1482FCu;
            // 0x148300: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1482fc) {
            ctx->pc = 0x1481F8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1481f8;
        }
    }
    ctx->pc = 0x148304u;
    // 0x148304: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x148304u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_148308:
    // 0x148308: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x148308u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x14830c: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x14830cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x148310: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x148310u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x148314: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x148314u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x148318: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x148318u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x14831c: 0x3e00008  jr          $ra
    ctx->pc = 0x14831Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x148320u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14831Cu;
            // 0x148320: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1481B8u: goto label_1481b8;
            case 0x1481C0u: goto label_1481c0;
            case 0x1481D4u: goto label_1481d4;
            case 0x1481DCu: goto label_1481dc;
            case 0x1481E4u: goto label_1481e4;
            case 0x1481ECu: goto label_1481ec;
            case 0x1481F8u: goto label_1481f8;
            case 0x148200u: goto label_148200;
            case 0x148208u: goto label_148208;
            case 0x148238u: goto label_148238;
            case 0x148258u: goto label_148258;
            case 0x148260u: goto label_148260;
            case 0x14826Cu: goto label_14826c;
            case 0x148288u: goto label_148288;
            case 0x14829Cu: goto label_14829c;
            case 0x1482ACu: goto label_1482ac;
            case 0x1482C0u: goto label_1482c0;
            case 0x1482D0u: goto label_1482d0;
            case 0x1482E0u: goto label_1482e0;
            case 0x148308u: goto label_148308;
            default: break;
        }
        return;
    }
    ctx->pc = 0x148324u;
    // 0x148324: 0x0  nop
    ctx->pc = 0x148324u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
