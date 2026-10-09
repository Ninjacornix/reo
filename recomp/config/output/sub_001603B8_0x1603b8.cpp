#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001603B8
// Address: 0x1603b8 - 0x160460
void sub_001603B8_0x1603b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001603B8_0x1603b8");
#endif

    switch (ctx->pc) {
        case 0x1603dcu: goto label_1603dc;
        case 0x1603f8u: goto label_1603f8;
        case 0x160408u: goto label_160408;
        case 0x160418u: goto label_160418;
        case 0x160424u: goto label_160424;
        default: break;
    }

    ctx->pc = 0x1603b8u;

    // 0x1603b8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1603b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1603bc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1603bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1603c0: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1603c0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1603c4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1603c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1603c8: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x1603c8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1603cc: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1603ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1603d0: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1603d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1603d4: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x1603D4u;
    SET_GPR_U32(ctx, 31, 0x1603DCu);
    ctx->pc = 0x1603D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1603D4u;
            // 0x1603d8: 0x80902d  daddu       $s2, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1603DCu; }
        if (ctx->pc != 0x1603DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1603DCu; }
        if (ctx->pc != 0x1603DCu) { return; }
    }
    ctx->pc = 0x1603DCu;
label_1603dc:
    // 0x1603dc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1603dcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1603e0: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1603e0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1603e4: 0x2484f660  addiu       $a0, $a0, -0x9A0
    ctx->pc = 0x1603e4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294964832));
    // 0x1603e8: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1603E8u;
    {
        const bool branch_taken_0x1603e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1603ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1603E8u;
            // 0x1603ec: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1603e8) {
            ctx->pc = 0x160400u;
            goto label_160400;
        }
    }
    ctx->pc = 0x1603F0u;
    // 0x1603f0: 0xc058dd4  jal         func_163750
    ctx->pc = 0x1603F0u;
    SET_GPR_U32(ctx, 31, 0x1603F8u);
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1603F8u; }
        if (ctx->pc != 0x1603F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1603F8u; }
        if (ctx->pc != 0x1603F8u) { return; }
    }
    ctx->pc = 0x1603F8u;
label_1603f8:
    // 0x1603f8: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1603F8u;
    {
        const bool branch_taken_0x1603f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1603FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1603F8u;
            // 0x1603fc: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1603f8) {
            ctx->pc = 0x160440u;
            goto label_160440;
        }
    }
    ctx->pc = 0x160400u;
label_160400:
    // 0x160400: 0xc05d866  jal         func_176198
    ctx->pc = 0x160400u;
    SET_GPR_U32(ctx, 31, 0x160408u);
    ctx->pc = 0x160404u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160400u;
            // 0x160404: 0x8e440040  lw          $a0, 0x40($s2) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 64)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176198u;
    if (runtime->hasFunction(0x176198u)) {
        auto targetFn = runtime->lookupFunction(0x176198u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160408u; }
        if (ctx->pc != 0x160408u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00176198_0x176198(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160408u; }
        if (ctx->pc != 0x160408u) { return; }
    }
    ctx->pc = 0x160408u;
label_160408:
    // 0x160408: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x160408u;
    {
        const bool branch_taken_0x160408 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16040Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160408u;
            // 0x16040c: 0x2404fecb  addiu       $a0, $zero, -0x135 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966987));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160408) {
            ctx->pc = 0x160430u;
            goto label_160430;
        }
    }
    ctx->pc = 0x160410u;
    // 0x160410: 0xc057abc  jal         func_15EAF0
    ctx->pc = 0x160410u;
    SET_GPR_U32(ctx, 31, 0x160418u);
    ctx->pc = 0x15EAF0u;
    if (runtime->hasFunction(0x15EAF0u)) {
        auto targetFn = runtime->lookupFunction(0x15EAF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160418u; }
        if (ctx->pc != 0x160418u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015EAF0_0x15eaf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160418u; }
        if (ctx->pc != 0x160418u) { return; }
    }
    ctx->pc = 0x160418u;
label_160418:
    // 0x160418: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x160418u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x16041c: 0xc058dd4  jal         func_163750
    ctx->pc = 0x16041Cu;
    SET_GPR_U32(ctx, 31, 0x160424u);
    ctx->pc = 0x160420u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16041Cu;
            // 0x160420: 0x2484f690  addiu       $a0, $a0, -0x970 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294964880));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160424u; }
        if (ctx->pc != 0x160424u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160424u; }
        if (ctx->pc != 0x160424u) { return; }
    }
    ctx->pc = 0x160424u;
label_160424:
    // 0x160424: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x160424u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x160428: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x160428u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16042c: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x16042cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
label_160430:
    // 0x160430: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x160430u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x160434: 0x4430005  bgezl       $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x160434u;
    {
        const bool branch_taken_0x160434 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x160434) {
            ctx->pc = 0x160438u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x160434u;
            // 0x160438: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16044Cu;
            goto label_16044c;
        }
    }
    ctx->pc = 0x16043Cu;
    // 0x16043c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x16043cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_160440:
    // 0x160440: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x160440u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x160444: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x160444u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x160448: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x160448u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_16044c:
    // 0x16044c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16044cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x160450: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x160450u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x160454: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x160454u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x160458: 0x3e00008  jr          $ra
    ctx->pc = 0x160458u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16045Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160458u;
            // 0x16045c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1603DCu: goto label_1603dc;
            case 0x1603F8u: goto label_1603f8;
            case 0x160400u: goto label_160400;
            case 0x160408u: goto label_160408;
            case 0x160418u: goto label_160418;
            case 0x160424u: goto label_160424;
            case 0x160430u: goto label_160430;
            case 0x160440u: goto label_160440;
            case 0x16044Cu: goto label_16044c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x160460u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
