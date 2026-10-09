#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C4C8
// Address: 0x12c4c8 - 0x12c630
void sub_0012C4C8_0x12c4c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C4C8_0x12c4c8");
#endif

    switch (ctx->pc) {
        case 0x12c50cu: goto label_12c50c;
        case 0x12c54cu: goto label_12c54c;
        case 0x12c584u: goto label_12c584;
        case 0x12c5bcu: goto label_12c5bc;
        default: break;
    }

    ctx->pc = 0x12c4c8u;

    // 0x12c4c8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c4c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c4cc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c4ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c4d0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c4d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c4d4: 0x804f6a2  j           func_13DA88
    ctx->pc = 0x12C4D4u;
    ctx->pc = 0x12C4D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C4D4u;
            // 0x12c4d8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13DA88u;
    if (runtime->hasFunction(0x13DA88u)) {
        auto targetFn = runtime->lookupFunction(0x13DA88u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013DA88_0x13da88(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12C4DCu;
    // 0x12c4dc: 0x0  nop
    ctx->pc = 0x12c4dcu;
    // NOP
    // 0x12c4e0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c4e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c4e4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c4e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c4e8: 0x8c82000c  lw          $v0, 0xC($a0)
    ctx->pc = 0x12c4e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x12c4ec: 0x52080  sll         $a0, $a1, 2
    ctx->pc = 0x12c4ecu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x12c4f0: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x12c4f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x12c4f4: 0x8c430008  lw          $v1, 0x8($v0)
    ctx->pc = 0x12c4f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x12c4f8: 0x8c640008  lw          $a0, 0x8($v1)
    ctx->pc = 0x12c4f8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x12c4fc: 0x8c860000  lw          $a2, 0x0($a0)
    ctx->pc = 0x12c4fcu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x12c500: 0x8cc20024  lw          $v0, 0x24($a2)
    ctx->pc = 0x12c500u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 36)));
    // 0x12c504: 0x40f809  jalr        $v0
    ctx->pc = 0x12C504u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12C50Cu);
        ctx->pc = 0x12C508u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12C504u;
            // 0x12c508: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12C50Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12C50Cu: goto label_12c50c;
            case 0x12C54Cu: goto label_12c54c;
            case 0x12C584u: goto label_12c584;
            case 0x12C5BCu: goto label_12c5bc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12C50Cu; }
            if (ctx->pc != 0x12C50Cu) { return; }
        }
        }
    }
    ctx->pc = 0x12C50Cu;
label_12c50c:
    // 0x12c50c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c50cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c510: 0x21042  srl         $v0, $v0, 1
    ctx->pc = 0x12c510u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 1));
    // 0x12c514: 0x3e00008  jr          $ra
    ctx->pc = 0x12C514u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12C518u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12C514u;
            // 0x12c518: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12C50Cu: goto label_12c50c;
            case 0x12C54Cu: goto label_12c54c;
            case 0x12C584u: goto label_12c584;
            case 0x12C5BCu: goto label_12c5bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12C51Cu;
    // 0x12c51c: 0x0  nop
    ctx->pc = 0x12c51cu;
    // NOP
    // 0x12c520: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c520u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c524: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c524u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c528: 0x8c82000c  lw          $v0, 0xC($a0)
    ctx->pc = 0x12c528u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x12c52c: 0x52080  sll         $a0, $a1, 2
    ctx->pc = 0x12c52cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x12c530: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x12c530u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x12c534: 0x8c430008  lw          $v1, 0x8($v0)
    ctx->pc = 0x12c534u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x12c538: 0x8c640008  lw          $a0, 0x8($v1)
    ctx->pc = 0x12c538u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x12c53c: 0x8c860000  lw          $a2, 0x0($a0)
    ctx->pc = 0x12c53cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x12c540: 0x8cc20024  lw          $v0, 0x24($a2)
    ctx->pc = 0x12c540u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 36)));
    // 0x12c544: 0x40f809  jalr        $v0
    ctx->pc = 0x12C544u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12C54Cu);
        ctx->pc = 0x12C548u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12C544u;
            // 0x12c548: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12C54Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12C50Cu: goto label_12c50c;
            case 0x12C54Cu: goto label_12c54c;
            case 0x12C584u: goto label_12c584;
            case 0x12C5BCu: goto label_12c5bc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12C54Cu; }
            if (ctx->pc != 0x12C54Cu) { return; }
        }
        }
    }
    ctx->pc = 0x12C54Cu;
label_12c54c:
    // 0x12c54c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c54cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c550: 0x21042  srl         $v0, $v0, 1
    ctx->pc = 0x12c550u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 1));
    // 0x12c554: 0x3e00008  jr          $ra
    ctx->pc = 0x12C554u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12C558u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12C554u;
            // 0x12c558: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12C50Cu: goto label_12c50c;
            case 0x12C54Cu: goto label_12c54c;
            case 0x12C584u: goto label_12c584;
            case 0x12C5BCu: goto label_12c5bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12C55Cu;
    // 0x12c55c: 0x0  nop
    ctx->pc = 0x12c55cu;
    // NOP
    // 0x12c560: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c560u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c564: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c564u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c568: 0x8c82000c  lw          $v0, 0xC($a0)
    ctx->pc = 0x12c568u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x12c56c: 0x52080  sll         $a0, $a1, 2
    ctx->pc = 0x12c56cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x12c570: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12c570u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12c574: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x12c574u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x12c578: 0x8c430008  lw          $v1, 0x8($v0)
    ctx->pc = 0x12c578u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x12c57c: 0xc050374  jal         func_140DD0
    ctx->pc = 0x12C57Cu;
    SET_GPR_U32(ctx, 31, 0x12C584u);
    ctx->pc = 0x12C580u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C57Cu;
            // 0x12c580: 0x8c640004  lw          $a0, 0x4($v1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x140DD0u;
    if (runtime->hasFunction(0x140DD0u)) {
        auto targetFn = runtime->lookupFunction(0x140DD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C584u; }
        if (ctx->pc != 0x12C584u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00140DD0_0x140dd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C584u; }
        if (ctx->pc != 0x12C584u) { return; }
    }
    ctx->pc = 0x12C584u;
label_12c584:
    // 0x12c584: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c584u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c588: 0x21042  srl         $v0, $v0, 1
    ctx->pc = 0x12c588u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 1));
    // 0x12c58c: 0x3e00008  jr          $ra
    ctx->pc = 0x12C58Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12C590u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12C58Cu;
            // 0x12c590: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12C50Cu: goto label_12c50c;
            case 0x12C54Cu: goto label_12c54c;
            case 0x12C584u: goto label_12c584;
            case 0x12C5BCu: goto label_12c5bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12C594u;
    // 0x12c594: 0x0  nop
    ctx->pc = 0x12c594u;
    // NOP
    // 0x12c598: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c598u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c59c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c59cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c5a0: 0x8c82000c  lw          $v0, 0xC($a0)
    ctx->pc = 0x12c5a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x12c5a4: 0x52080  sll         $a0, $a1, 2
    ctx->pc = 0x12c5a4u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x12c5a8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12c5a8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12c5ac: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x12c5acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x12c5b0: 0x8c430008  lw          $v1, 0x8($v0)
    ctx->pc = 0x12c5b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x12c5b4: 0xc050374  jal         func_140DD0
    ctx->pc = 0x12C5B4u;
    SET_GPR_U32(ctx, 31, 0x12C5BCu);
    ctx->pc = 0x12C5B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C5B4u;
            // 0x12c5b8: 0x8c640004  lw          $a0, 0x4($v1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x140DD0u;
    if (runtime->hasFunction(0x140DD0u)) {
        auto targetFn = runtime->lookupFunction(0x140DD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C5BCu; }
        if (ctx->pc != 0x12C5BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00140DD0_0x140dd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C5BCu; }
        if (ctx->pc != 0x12C5BCu) { return; }
    }
    ctx->pc = 0x12C5BCu;
label_12c5bc:
    // 0x12c5bc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c5bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c5c0: 0x21042  srl         $v0, $v0, 1
    ctx->pc = 0x12c5c0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 1));
    // 0x12c5c4: 0x3e00008  jr          $ra
    ctx->pc = 0x12C5C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12C5C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12C5C4u;
            // 0x12c5c8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12C50Cu: goto label_12c50c;
            case 0x12C54Cu: goto label_12c54c;
            case 0x12C584u: goto label_12c584;
            case 0x12C5BCu: goto label_12c5bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12C5CCu;
    // 0x12c5cc: 0x0  nop
    ctx->pc = 0x12c5ccu;
    // NOP
    // 0x12c5d0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c5d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c5d4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c5d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c5d8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c5d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c5dc: 0x804f95a  j           func_13E568
    ctx->pc = 0x12C5DCu;
    ctx->pc = 0x12C5E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C5DCu;
            // 0x12c5e0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13E568u;
    if (runtime->hasFunction(0x13E568u)) {
        auto targetFn = runtime->lookupFunction(0x13E568u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013E568_0x13e568(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12C5E4u;
    // 0x12c5e4: 0x0  nop
    ctx->pc = 0x12c5e4u;
    // NOP
    // 0x12c5e8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c5e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c5ec: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c5ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c5f0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c5f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c5f4: 0x804f97a  j           func_13E5E8
    ctx->pc = 0x12C5F4u;
    ctx->pc = 0x12C5F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C5F4u;
            // 0x12c5f8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13E5E8u;
    if (runtime->hasFunction(0x13E5E8u)) {
        auto targetFn = runtime->lookupFunction(0x13E5E8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013E5E8_0x13e5e8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12C5FCu;
    // 0x12c5fc: 0x0  nop
    ctx->pc = 0x12c5fcu;
    // NOP
    // 0x12c600: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c600u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c604: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c604u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c608: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c608u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c60c: 0x804f990  j           func_13E640
    ctx->pc = 0x12C60Cu;
    ctx->pc = 0x12C610u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C60Cu;
            // 0x12c610: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13E640u;
    if (runtime->hasFunction(0x13E640u)) {
        auto targetFn = runtime->lookupFunction(0x13E640u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013E640_0x13e640(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12C614u;
    // 0x12c614: 0x0  nop
    ctx->pc = 0x12c614u;
    // NOP
    // 0x12c618: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c618u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c61c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c61cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c620: 0x8c84000c  lw          $a0, 0xC($a0)
    ctx->pc = 0x12c620u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x12c624: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c624u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c628: 0x804f9a2  j           func_13E688
    ctx->pc = 0x12C628u;
    ctx->pc = 0x12C62Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C628u;
            // 0x12c62c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13E688u;
    if (runtime->hasFunction(0x13E688u)) {
        auto targetFn = runtime->lookupFunction(0x13E688u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013E688_0x13e688(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12C630u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
