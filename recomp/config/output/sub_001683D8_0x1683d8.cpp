#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001683D8
// Address: 0x1683d8 - 0x168490
void sub_001683D8_0x1683d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001683D8_0x1683d8");
#endif

    switch (ctx->pc) {
        case 0x168400u: goto label_168400;
        case 0x168454u: goto label_168454;
        case 0x168464u: goto label_168464;
        case 0x168474u: goto label_168474;
        default: break;
    }

    ctx->pc = 0x1683d8u;

    // 0x1683d8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1683d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1683dc: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x1683dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1683e0: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x1683e0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1683e4: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x1683e4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1683e8: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x1683e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x1683ec: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x1683ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x1683f0: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1683f0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1683f4: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1683f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1683f8: 0xc05a124  jal         func_168490
    ctx->pc = 0x1683F8u;
    SET_GPR_U32(ctx, 31, 0x168400u);
    ctx->pc = 0x1683FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1683F8u;
            // 0x1683fc: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x168490u;
    if (runtime->hasFunction(0x168490u)) {
        auto targetFn = runtime->lookupFunction(0x168490u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168400u; }
        if (ctx->pc != 0x168400u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00168490_0x168490(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168400u; }
        if (ctx->pc != 0x168400u) { return; }
    }
    ctx->pc = 0x168400u;
label_168400:
    // 0x168400: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x168400u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168404: 0x1060001c  beqz        $v1, . + 4 + (0x1C << 2)
    ctx->pc = 0x168404u;
    {
        const bool branch_taken_0x168404 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x168408u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168404u;
            // 0x168408: 0x2404ffff  addiu       $a0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168404) {
            ctx->pc = 0x168478u;
            goto label_168478;
        }
    }
    ctx->pc = 0x16840Cu;
    // 0x16840c: 0xae030010  sw          $v1, 0x10($s0)
    ctx->pc = 0x16840cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 3));
    // 0x168410: 0x10640019  beq         $v1, $a0, . + 4 + (0x19 << 2)
    ctx->pc = 0x168410u;
    {
        const bool branch_taken_0x168410 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x168414u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168410u;
            // 0x168414: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168410) {
            ctx->pc = 0x168478u;
            goto label_168478;
        }
    }
    ctx->pc = 0x168418u;
    // 0x168418: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x168418u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16841c: 0x18600006  blez        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x16841Cu;
    {
        const bool branch_taken_0x16841c = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x168420u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16841Cu;
            // 0x168420: 0x31040  sll         $v0, $v1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16841c) {
            ctx->pc = 0x168438u;
            goto label_168438;
        }
    }
    ctx->pc = 0x168424u;
    // 0x168424: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x168424u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x168428: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x168428u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x16842c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x16842cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x168430: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x168430u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x168434: 0xae02001c  sw          $v0, 0x1C($s0)
    ctx->pc = 0x168434u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 2));
label_168438:
    // 0x168438: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x168438u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x16843c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x16843cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168440: 0x24420818  addiu       $v0, $v0, 0x818
    ctx->pc = 0x168440u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2072));
    // 0x168444: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x168444u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168448: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x168448u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x16844c: 0xc05a184  jal         func_168610
    ctx->pc = 0x16844Cu;
    SET_GPR_U32(ctx, 31, 0x168454u);
    ctx->pc = 0x168450u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16844Cu;
            // 0x168450: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x168610u;
    if (runtime->hasFunction(0x168610u)) {
        auto targetFn = runtime->lookupFunction(0x168610u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168454u; }
        if (ctx->pc != 0x168454u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00168610_0x168610(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168454u; }
        if (ctx->pc != 0x168454u) { return; }
    }
    ctx->pc = 0x168454u;
label_168454:
    // 0x168454: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x168454u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168458: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x168458u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16845c: 0xc05a1c6  jal         func_168718
    ctx->pc = 0x16845Cu;
    SET_GPR_U32(ctx, 31, 0x168464u);
    ctx->pc = 0x168460u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16845Cu;
            // 0x168460: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x168718u;
    if (runtime->hasFunction(0x168718u)) {
        auto targetFn = runtime->lookupFunction(0x168718u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168464u; }
        if (ctx->pc != 0x168464u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00168718_0x168718(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168464u; }
        if (ctx->pc != 0x168464u) { return; }
    }
    ctx->pc = 0x168464u;
label_168464:
    // 0x168464: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x168464u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168468: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x168468u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16846c: 0xc05a370  jal         func_168DC0
    ctx->pc = 0x16846Cu;
    SET_GPR_U32(ctx, 31, 0x168474u);
    ctx->pc = 0x168470u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16846Cu;
            // 0x168470: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x168DC0u;
    if (runtime->hasFunction(0x168DC0u)) {
        auto targetFn = runtime->lookupFunction(0x168DC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168474u; }
        if (ctx->pc != 0x168474u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00168DC0_0x168dc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168474u; }
        if (ctx->pc != 0x168474u) { return; }
    }
    ctx->pc = 0x168474u;
label_168474:
    // 0x168474: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x168474u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_168478:
    // 0x168478: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x168478u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16847c: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x16847cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x168480: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x168480u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x168484: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x168484u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x168488: 0x3e00008  jr          $ra
    ctx->pc = 0x168488u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16848Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168488u;
            // 0x16848c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x168400u: goto label_168400;
            case 0x168438u: goto label_168438;
            case 0x168454u: goto label_168454;
            case 0x168464u: goto label_168464;
            case 0x168474u: goto label_168474;
            case 0x168478u: goto label_168478;
            default: break;
        }
        return;
    }
    ctx->pc = 0x168490u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
