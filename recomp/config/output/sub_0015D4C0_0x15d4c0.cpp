#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015D4C0
// Address: 0x15d4c0 - 0x15d5a0
void sub_0015D4C0_0x15d4c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015D4C0_0x15d4c0");
#endif

    switch (ctx->pc) {
        case 0x15d57cu: goto label_15d57c;
        default: break;
    }

    ctx->pc = 0x15d4c0u;

    // 0x15d4c0: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x15d4c0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d4c4: 0x8cc70004  lw          $a3, 0x4($a2)
    ctx->pc = 0x15d4c4u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x15d4c8: 0x10e00021  beqz        $a3, . + 4 + (0x21 << 2)
    ctx->pc = 0x15D4C8u;
    {
        const bool branch_taken_0x15d4c8 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        ctx->pc = 0x15D4CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D4C8u;
            // 0x15d4cc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d4c8) {
            ctx->pc = 0x15D550u;
            goto label_15d550;
        }
    }
    ctx->pc = 0x15D4D0u;
    // 0x15d4d0: 0x8cc40008  lw          $a0, 0x8($a2)
    ctx->pc = 0x15d4d0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 8)));
    // 0x15d4d4: 0x3c030006  lui         $v1, 0x6
    ctx->pc = 0x15d4d4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)6 << 16));
    // 0x15d4d8: 0x8cc5000c  lw          $a1, 0xC($a2)
    ctx->pc = 0x15d4d8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 12)));
    // 0x15d4dc: 0x34635400  ori         $v1, $v1, 0x5400
    ctx->pc = 0x15d4dcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)21504);
    // 0x15d4e0: 0x852018  mult        $a0, $a0, $a1
    ctx->pc = 0x15d4e0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 5); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x15d4e4: 0x64182a  slt         $v1, $v1, $a0
    ctx->pc = 0x15d4e4u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x15d4e8: 0x14600019  bnez        $v1, . + 4 + (0x19 << 2)
    ctx->pc = 0x15D4E8u;
    {
        const bool branch_taken_0x15d4e8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x15D4ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D4E8u;
            // 0x15d4ec: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d4e8) {
            ctx->pc = 0x15D550u;
            goto label_15d550;
        }
    }
    ctx->pc = 0x15D4F0u;
    // 0x15d4f0: 0x10e30017  beq         $a3, $v1, . + 4 + (0x17 << 2)
    ctx->pc = 0x15D4F0u;
    {
        const bool branch_taken_0x15d4f0 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 3));
        if (branch_taken_0x15d4f0) {
            ctx->pc = 0x15D550u;
            goto label_15d550;
        }
    }
    ctx->pc = 0x15D4F8u;
    // 0x15d4f8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x15d4f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15d4fc: 0x14e20014  bne         $a3, $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x15D4FCu;
    {
        const bool branch_taken_0x15d4fc = (GPR_U64(ctx, 7) != GPR_U64(ctx, 2));
        if (branch_taken_0x15d4fc) {
            ctx->pc = 0x15D550u;
            goto label_15d550;
        }
    }
    ctx->pc = 0x15D504u;
    // 0x15d504: 0x8cc40014  lw          $a0, 0x14($a2)
    ctx->pc = 0x15d504u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 20)));
    // 0x15d508: 0x24022ee0  addiu       $v0, $zero, 0x2EE0
    ctx->pc = 0x15d508u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 12000));
    // 0x15d50c: 0x10820010  beq         $a0, $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x15D50Cu;
    {
        const bool branch_taken_0x15d50c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x15D510u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D50Cu;
            // 0x15d510: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d50c) {
            ctx->pc = 0x15D550u;
            goto label_15d550;
        }
    }
    ctx->pc = 0x15D514u;
    // 0x15d514: 0x28822ee1  slti        $v0, $a0, 0x2EE1
    ctx->pc = 0x15d514u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)12001) ? 1 : 0);
    // 0x15d518: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x15D518u;
    {
        const bool branch_taken_0x15d518 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15D51Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D518u;
            // 0x15d51c: 0x24025dc0  addiu       $v0, $zero, 0x5DC0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 24000));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d518) {
            ctx->pc = 0x15D530u;
            goto label_15d530;
        }
    }
    ctx->pc = 0x15D520u;
    // 0x15d520: 0x5080000b  beql        $a0, $zero, . + 4 + (0xB << 2)
    ctx->pc = 0x15D520u;
    {
        const bool branch_taken_0x15d520 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x15d520) {
            ctx->pc = 0x15D524u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15D520u;
            // 0x15d524: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15D550u;
            goto label_15d550;
        }
    }
    ctx->pc = 0x15D528u;
    // 0x15d528: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x15D528u;
    {
        const bool branch_taken_0x15d528 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15D52Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D528u;
            // 0x15d52c: 0x24021770  addiu       $v0, $zero, 0x1770 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6000));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d528) {
            ctx->pc = 0x15D53Cu;
            goto label_15d53c;
        }
    }
    ctx->pc = 0x15D530u;
label_15d530:
    // 0x15d530: 0x10820007  beq         $a0, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x15D530u;
    {
        const bool branch_taken_0x15d530 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x15D534u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D530u;
            // 0x15d534: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d530) {
            ctx->pc = 0x15D550u;
            goto label_15d550;
        }
    }
    ctx->pc = 0x15D538u;
    // 0x15d538: 0x3402bb80  ori         $v0, $zero, 0xBB80
    ctx->pc = 0x15d538u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)48000);
label_15d53c:
    // 0x15d53c: 0x50820004  beql        $a0, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x15D53Cu;
    {
        const bool branch_taken_0x15d53c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        if (branch_taken_0x15d53c) {
            ctx->pc = 0x15D540u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15D53Cu;
            // 0x15d540: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15D550u;
            goto label_15d550;
        }
    }
    ctx->pc = 0x15D544u;
    // 0x15d544: 0x3e00008  jr          $ra
    ctx->pc = 0x15D544u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15D548u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D544u;
            // 0x15d548: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15D530u: goto label_15d530;
            case 0x15D53Cu: goto label_15d53c;
            case 0x15D550u: goto label_15d550;
            case 0x15D57Cu: goto label_15d57c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15D54Cu;
    // 0x15d54c: 0x0  nop
    ctx->pc = 0x15d54cu;
    // NOP
label_15d550:
    // 0x15d550: 0x3e00008  jr          $ra
    ctx->pc = 0x15D550u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15D530u: goto label_15d530;
            case 0x15D53Cu: goto label_15d53c;
            case 0x15D550u: goto label_15d550;
            case 0x15D57Cu: goto label_15d57c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15D558u;
    // 0x15d558: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15d558u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15d55c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15d55cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15d560: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x15d560u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d564: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15d564u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15d568: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x15d568u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d56c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x15d56cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x15d570: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x15d570u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x15d574: 0xc05799e  jal         func_15E678
    ctx->pc = 0x15D574u;
    SET_GPR_U32(ctx, 31, 0x15D57Cu);
    ctx->pc = 0x15D578u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D574u;
            // 0x15d578: 0xa0902d  daddu       $s2, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15E678u;
    if (runtime->hasFunction(0x15E678u)) {
        auto targetFn = runtime->lookupFunction(0x15E678u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D57Cu; }
        if (ctx->pc != 0x15D57Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015E678_0x15e678(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D57Cu; }
        if (ctx->pc != 0x15D57Cu) { return; }
    }
    ctx->pc = 0x15D57Cu;
label_15d57c:
    // 0x15d57c: 0xac500030  sw          $s0, 0x30($v0)
    ctx->pc = 0x15d57cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 48), GPR_U32(ctx, 16));
    // 0x15d580: 0xac510028  sw          $s1, 0x28($v0)
    ctx->pc = 0x15d580u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 40), GPR_U32(ctx, 17));
    // 0x15d584: 0xac52002c  sw          $s2, 0x2C($v0)
    ctx->pc = 0x15d584u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 44), GPR_U32(ctx, 18));
    // 0x15d588: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15d588u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15d58c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15d58cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15d590: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x15d590u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15d594: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x15d594u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15d598: 0x3e00008  jr          $ra
    ctx->pc = 0x15D598u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15D59Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D598u;
            // 0x15d59c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15D530u: goto label_15d530;
            case 0x15D53Cu: goto label_15d53c;
            case 0x15D550u: goto label_15d550;
            case 0x15D57Cu: goto label_15d57c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15D5A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
