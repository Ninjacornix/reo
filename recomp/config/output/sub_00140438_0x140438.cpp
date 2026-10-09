#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00140438
// Address: 0x140438 - 0x14058c
void sub_00140438_0x140438(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00140438_0x140438");
#endif

    switch (ctx->pc) {
        case 0x140478u: goto label_140478;
        case 0x1404a0u: goto label_1404a0;
        case 0x1404b8u: goto label_1404b8;
        case 0x140538u: goto label_140538;
        default: break;
    }

    ctx->pc = 0x140438u;

    // 0x140438: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x140438u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x14043c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x14043cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x140440: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x140440u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140444: 0x2e420004  sltiu       $v0, $s2, 0x4
    ctx->pc = 0x140444u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)(int64_t)(int32_t)4) ? 1 : 0);
    // 0x140448: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x140448u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x14044c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x14044cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x140450: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x140450u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140454: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x140454u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x140458: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x140458u;
    {
        const bool branch_taken_0x140458 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x14045Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140458u;
            // 0x14045c: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x140458) {
            ctx->pc = 0x140480u;
            goto label_140480;
        }
    }
    ctx->pc = 0x140460u;
    // 0x140460: 0x8e020028  lw          $v0, 0x28($s0)
    ctx->pc = 0x140460u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x140464: 0x50400044  beql        $v0, $zero, . + 4 + (0x44 << 2)
    ctx->pc = 0x140464u;
    {
        const bool branch_taken_0x140464 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x140464) {
            ctx->pc = 0x140468u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x140464u;
            // 0x140468: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x140578u;
            goto label_140578;
        }
    }
    ctx->pc = 0x14046Cu;
    // 0x14046c: 0x8e04002c  lw          $a0, 0x2C($s0)
    ctx->pc = 0x14046cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x140470: 0x40f809  jalr        $v0
    ctx->pc = 0x140470u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x140478u);
        ctx->pc = 0x140474u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140470u;
            // 0x140474: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x140478u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140478u: goto label_140478;
            case 0x140480u: goto label_140480;
            case 0x1404A0u: goto label_1404a0;
            case 0x1404B8u: goto label_1404b8;
            case 0x1404D4u: goto label_1404d4;
            case 0x140518u: goto label_140518;
            case 0x140538u: goto label_140538;
            case 0x140540u: goto label_140540;
            case 0x14055Cu: goto label_14055c;
            case 0x140560u: goto label_140560;
            case 0x140578u: goto label_140578;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x140478u; }
            if (ctx->pc != 0x140478u) { return; }
        }
        }
    }
    ctx->pc = 0x140478u;
label_140478:
    // 0x140478: 0x1000003f  b           . + 4 + (0x3F << 2)
    ctx->pc = 0x140478u;
    {
        const bool branch_taken_0x140478 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x14047Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140478u;
            // 0x14047c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x140478) {
            ctx->pc = 0x140578u;
            goto label_140578;
        }
    }
    ctx->pc = 0x140480u;
label_140480:
    // 0x140480: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x140480u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x140484: 0x5840003c  blezl       $v0, . + 4 + (0x3C << 2)
    ctx->pc = 0x140484u;
    {
        const bool branch_taken_0x140484 = (GPR_S64(ctx, 2) <= 0);
        if (branch_taken_0x140484) {
            ctx->pc = 0x140488u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x140484u;
            // 0x140488: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x140578u;
            goto label_140578;
        }
    }
    ctx->pc = 0x14048Cu;
    // 0x14048c: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x14048cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x140490: 0x50400039  beql        $v0, $zero, . + 4 + (0x39 << 2)
    ctx->pc = 0x140490u;
    {
        const bool branch_taken_0x140490 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x140490) {
            ctx->pc = 0x140494u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x140490u;
            // 0x140494: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x140578u;
            goto label_140578;
        }
    }
    ctx->pc = 0x140498u;
    // 0x140498: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x140498u;
    SET_GPR_U32(ctx, 31, 0x1404A0u);
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1404A0u; }
        if (ctx->pc != 0x1404A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1404A0u; }
        if (ctx->pc != 0x1404A0u) { return; }
    }
    ctx->pc = 0x1404A0u;
label_1404a0:
    // 0x1404a0: 0x121080  sll         $v0, $s2, 2
    ctx->pc = 0x1404a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
    // 0x1404a4: 0x2021021  addu        $v0, $s0, $v0
    ctx->pc = 0x1404a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1404a8: 0x24450018  addiu       $a1, $v0, 0x18
    ctx->pc = 0x1404a8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 24));
    // 0x1404ac: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x1404acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1404b0: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1404B0u;
    {
        const bool branch_taken_0x1404b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1404B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1404B0u;
            // 0x1404b4: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1404b0) {
            ctx->pc = 0x1404D4u;
            goto label_1404d4;
        }
    }
    ctx->pc = 0x1404B8u;
label_1404b8:
    // 0x1404b8: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1404b8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1404bc: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1404bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1404c0: 0x0  nop
    ctx->pc = 0x1404c0u;
    // NOP
    // 0x1404c4: 0x0  nop
    ctx->pc = 0x1404c4u;
    // NOP
    // 0x1404c8: 0x0  nop
    ctx->pc = 0x1404c8u;
    // NOP
    // 0x1404cc: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1404CCu;
    {
        const bool branch_taken_0x1404cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1404D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1404CCu;
            // 0x1404d0: 0x80282d  daddu       $a1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1404cc) {
            ctx->pc = 0x1404B8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1404b8;
        }
    }
    ctx->pc = 0x1404D4u;
label_1404d4:
    // 0x1404d4: 0x82030005  lb          $v1, 0x5($s0)
    ctx->pc = 0x1404d4u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 5)));
    // 0x1404d8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1404d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1404dc: 0x5462000e  bnel        $v1, $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1404DCu;
    {
        const bool branch_taken_0x1404dc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1404dc) {
            ctx->pc = 0x1404E0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1404DCu;
            // 0x1404e0: 0x8e040014  lw          $a0, 0x14($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x140518u;
            goto label_140518;
        }
    }
    ctx->pc = 0x1404E4u;
    // 0x1404e4: 0x5080000c  beql        $a0, $zero, . + 4 + (0xC << 2)
    ctx->pc = 0x1404E4u;
    {
        const bool branch_taken_0x1404e4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1404e4) {
            ctx->pc = 0x1404E8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1404E4u;
            // 0x1404e8: 0x8e040014  lw          $a0, 0x14($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x140518u;
            goto label_140518;
        }
    }
    ctx->pc = 0x1404ECu;
    // 0x1404ec: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x1404ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1404f0: 0x8c86000c  lw          $a2, 0xC($a0)
    ctx->pc = 0x1404f0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x1404f4: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x1404f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1404f8: 0x461021  addu        $v0, $v0, $a2
    ctx->pc = 0x1404f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x1404fc: 0x54430006  bnel        $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1404FCu;
    {
        const bool branch_taken_0x1404fc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1404fc) {
            ctx->pc = 0x140500u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1404FCu;
            // 0x140500: 0x8e040014  lw          $a0, 0x14($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x140518u;
            goto label_140518;
        }
    }
    ctx->pc = 0x140504u;
    // 0x140504: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x140504u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x140508: 0xc21021  addu        $v0, $a2, $v0
    ctx->pc = 0x140508u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x14050c: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x14050Cu;
    {
        const bool branch_taken_0x14050c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x140510u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14050Cu;
            // 0x140510: 0xac82000c  sw          $v0, 0xC($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14050c) {
            ctx->pc = 0x14055Cu;
            goto label_14055c;
        }
    }
    ctx->pc = 0x140514u;
    // 0x140514: 0x0  nop
    ctx->pc = 0x140514u;
    // NOP
label_140518:
    // 0x140518: 0x54800009  bnel        $a0, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x140518u;
    {
        const bool branch_taken_0x140518 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        if (branch_taken_0x140518) {
            ctx->pc = 0x14051Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x140518u;
            // 0x14051c: 0x8c820000  lw          $v0, 0x0($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x140540u;
            goto label_140540;
        }
    }
    ctx->pc = 0x140520u;
    // 0x140520: 0x8e020028  lw          $v0, 0x28($s0)
    ctx->pc = 0x140520u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x140524: 0x5040000e  beql        $v0, $zero, . + 4 + (0xE << 2)
    ctx->pc = 0x140524u;
    {
        const bool branch_taken_0x140524 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x140524) {
            ctx->pc = 0x140528u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x140524u;
            // 0x140528: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x140560u;
            goto label_140560;
        }
    }
    ctx->pc = 0x14052Cu;
    // 0x14052c: 0x8e04002c  lw          $a0, 0x2C($s0)
    ctx->pc = 0x14052cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x140530: 0x40f809  jalr        $v0
    ctx->pc = 0x140530u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x140538u);
        ctx->pc = 0x140534u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140530u;
            // 0x140534: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x140538u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140478u: goto label_140478;
            case 0x140480u: goto label_140480;
            case 0x1404A0u: goto label_1404a0;
            case 0x1404B8u: goto label_1404b8;
            case 0x1404D4u: goto label_1404d4;
            case 0x140518u: goto label_140518;
            case 0x140538u: goto label_140538;
            case 0x140540u: goto label_140540;
            case 0x14055Cu: goto label_14055c;
            case 0x140560u: goto label_140560;
            case 0x140578u: goto label_140578;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x140538u; }
            if (ctx->pc != 0x140538u) { return; }
        }
        }
    }
    ctx->pc = 0x140538u;
label_140538:
    // 0x140538: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x140538u;
    {
        const bool branch_taken_0x140538 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x14053Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140538u;
            // 0x14053c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x140538) {
            ctx->pc = 0x140560u;
            goto label_140560;
        }
    }
    ctx->pc = 0x140540u;
label_140540:
    // 0x140540: 0x6a230007  ldl         $v1, 0x7($s1)
    ctx->pc = 0x140540u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x140544: 0x6e230000  ldr         $v1, 0x0($s1)
    ctx->pc = 0x140544u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 17), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x140548: 0xb083000f  sdl         $v1, 0xF($a0)
    ctx->pc = 0x140548u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x14054c: 0xb4830008  sdr         $v1, 0x8($a0)
    ctx->pc = 0x14054cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x140550: 0xae020014  sw          $v0, 0x14($s0)
    ctx->pc = 0x140550u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
    // 0x140554: 0xac800000  sw          $zero, 0x0($a0)
    ctx->pc = 0x140554u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x140558: 0xaca40000  sw          $a0, 0x0($a1)
    ctx->pc = 0x140558u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 4));
label_14055c:
    // 0x14055c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x14055cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_140560:
    // 0x140560: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x140560u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x140564: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x140564u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x140568: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x140568u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x14056c: 0x804fc9c  j           func_13F270
    ctx->pc = 0x14056Cu;
    ctx->pc = 0x140570u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14056Cu;
            // 0x140570: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F270_0x13f270(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x140574u;
    // 0x140574: 0x0  nop
    ctx->pc = 0x140574u;
    // NOP
label_140578:
    // 0x140578: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x140578u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x14057c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x14057cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x140580: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x140580u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x140584: 0x3e00008  jr          $ra
    ctx->pc = 0x140584u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x140588u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140584u;
            // 0x140588: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140478u: goto label_140478;
            case 0x140480u: goto label_140480;
            case 0x1404A0u: goto label_1404a0;
            case 0x1404B8u: goto label_1404b8;
            case 0x1404D4u: goto label_1404d4;
            case 0x140518u: goto label_140518;
            case 0x140538u: goto label_140538;
            case 0x140540u: goto label_140540;
            case 0x14055Cu: goto label_14055c;
            case 0x140560u: goto label_140560;
            case 0x140578u: goto label_140578;
            default: break;
        }
        return;
    }
    ctx->pc = 0x14058Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
