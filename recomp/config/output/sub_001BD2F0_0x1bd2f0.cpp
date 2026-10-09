#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BD2F0
// Address: 0x1bd2f0 - 0x1bd410
void sub_001BD2F0_0x1bd2f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BD2F0_0x1bd2f0");
#endif

    switch (ctx->pc) {
        case 0x1bd310u: goto label_1bd310;
        case 0x1bd324u: goto label_1bd324;
        case 0x1bd32cu: goto label_1bd32c;
        case 0x1bd33cu: goto label_1bd33c;
        case 0x1bd358u: goto label_1bd358;
        case 0x1bd364u: goto label_1bd364;
        case 0x1bd384u: goto label_1bd384;
        case 0x1bd394u: goto label_1bd394;
        case 0x1bd3acu: goto label_1bd3ac;
        case 0x1bd3b8u: goto label_1bd3b8;
        case 0x1bd3f4u: goto label_1bd3f4;
        default: break;
    }

    ctx->pc = 0x1bd2f0u;

    // 0x1bd2f0: 0x27bdfed0  addiu       $sp, $sp, -0x130
    ctx->pc = 0x1bd2f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966992));
    // 0x1bd2f4: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1bd2f4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bd2f8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1bd2f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1bd2fc: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1bd2fcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1bd300: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1bd300u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1bd304: 0x3c100023  lui         $s0, 0x23
    ctx->pc = 0x1bd304u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)35 << 16));
    // 0x1bd308: 0xc06f8ec  jal         func_1BE3B0
    ctx->pc = 0x1BD308u;
    SET_GPR_U32(ctx, 31, 0x1BD310u);
    ctx->pc = 0x1BD30Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD308u;
            // 0x1bd30c: 0x26104f30  addiu       $s0, $s0, 0x4F30 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 20272));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BE3B0u;
    if (runtime->hasFunction(0x1BE3B0u)) {
        auto targetFn = runtime->lookupFunction(0x1BE3B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD310u; }
        if (ctx->pc != 0x1BD310u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BE3B0_0x1be3b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD310u; }
        if (ctx->pc != 0x1BD310u) { return; }
    }
    ctx->pc = 0x1BD310u;
label_1bd310:
    // 0x1bd310: 0x4400030  bltz        $v0, . + 4 + (0x30 << 2)
    ctx->pc = 0x1BD310u;
    {
        const bool branch_taken_0x1bd310 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1BD314u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD310u;
            // 0x1bd314: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd310) {
            ctx->pc = 0x1BD3D4u;
            goto label_1bd3d4;
        }
    }
    ctx->pc = 0x1BD318u;
    // 0x1bd318: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bd318u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bd31c: 0x1000002d  b           . + 4 + (0x2D << 2)
    ctx->pc = 0x1BD31Cu;
    {
        const bool branch_taken_0x1bd31c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BD320u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD31Cu;
            // 0x1bd320: 0xac2344e0  sw          $v1, 0x44E0($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 17632), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd31c) {
            ctx->pc = 0x1BD3D4u;
            goto label_1bd3d4;
        }
    }
    ctx->pc = 0x1BD324u;
label_1bd324:
    // 0x1bd324: 0xc06f904  jal         func_1BE410
    ctx->pc = 0x1BD324u;
    SET_GPR_U32(ctx, 31, 0x1BD32Cu);
    ctx->pc = 0x1BD328u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD324u;
            // 0x1bd328: 0x27a40030  addiu       $a0, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BE410u;
    if (runtime->hasFunction(0x1BE410u)) {
        auto targetFn = runtime->lookupFunction(0x1BE410u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD32Cu; }
        if (ctx->pc != 0x1BD32Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BE410_0x1be410(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD32Cu; }
        if (ctx->pc != 0x1BD32Cu) { return; }
    }
    ctx->pc = 0x1BD32Cu;
label_1bd32c:
    // 0x1bd32c: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1bd32cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1bd330: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1bd330u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bd334: 0xc04629c  jal         func_118A70
    ctx->pc = 0x1BD334u;
    SET_GPR_U32(ctx, 31, 0x1BD33Cu);
    ctx->pc = 0x1BD338u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD334u;
            // 0x1bd338: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118A70u;
    if (runtime->hasFunction(0x118A70u)) {
        auto targetFn = runtime->lookupFunction(0x118A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD33Cu; }
        if (ctx->pc != 0x1BD33Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118A70_0x118a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD33Cu; }
        if (ctx->pc != 0x1BD33Cu) { return; }
    }
    ctx->pc = 0x1BD33Cu;
label_1bd33c:
    // 0x1bd33c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x1bd33cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd340: 0x440fffa  bltz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1BD340u;
    {
        const bool branch_taken_0x1bd340 = (GPR_S64(ctx, 2) < 0);
        if (branch_taken_0x1bd340) {
            ctx->pc = 0x1BD32Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bd32c;
        }
    }
    ctx->pc = 0x1BD348u;
    // 0x1bd348: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1bd348u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd34c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1bd34cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd350: 0xc04639e  jal         func_118E78
    ctx->pc = 0x1BD350u;
    SET_GPR_U32(ctx, 31, 0x1BD358u);
    ctx->pc = 0x1BD354u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD350u;
            // 0x1bd354: 0x24060002  addiu       $a2, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118E78u;
    if (runtime->hasFunction(0x118E78u)) {
        auto targetFn = runtime->lookupFunction(0x118E78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD358u; }
        if (ctx->pc != 0x1BD358u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118E78_0x118e78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD358u; }
        if (ctx->pc != 0x1BD358u) { return; }
    }
    ctx->pc = 0x1BD358u;
label_1bd358:
    // 0x1bd358: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1bd358u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd35c: 0xc04633e  jal         func_118CF8
    ctx->pc = 0x1BD35Cu;
    SET_GPR_U32(ctx, 31, 0x1BD364u);
    ctx->pc = 0x1BD360u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD35Cu;
            // 0x1bd360: 0xae020004  sw          $v0, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118CF8u;
    if (runtime->hasFunction(0x118CF8u)) {
        auto targetFn = runtime->lookupFunction(0x118CF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD364u; }
        if (ctx->pc != 0x1BD364u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118CF8_0x118cf8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD364u; }
        if (ctx->pc != 0x1BD364u) { return; }
    }
    ctx->pc = 0x1BD364u;
label_1bd364:
    // 0x1bd364: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bd364u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bd368: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1bd368u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bd36c: 0x8c2444e0  lw          $a0, 0x44E0($at)
    ctx->pc = 0x1bd36cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17632)));
    // 0x1bd370: 0x14830017  bne         $a0, $v1, . + 4 + (0x17 << 2)
    ctx->pc = 0x1BD370u;
    {
        const bool branch_taken_0x1bd370 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        if (branch_taken_0x1bd370) {
            ctx->pc = 0x1BD3D0u;
            goto label_1bd3d0;
        }
    }
    ctx->pc = 0x1BD378u;
    // 0x1bd378: 0x8e050000  lw          $a1, 0x0($s0)
    ctx->pc = 0x1bd378u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1bd37c: 0xc06f914  jal         func_1BE450
    ctx->pc = 0x1BD37Cu;
    SET_GPR_U32(ctx, 31, 0x1BD384u);
    ctx->pc = 0x1BD380u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD37Cu;
            // 0x1bd380: 0x27a40030  addiu       $a0, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BE450u;
    if (runtime->hasFunction(0x1BE450u)) {
        auto targetFn = runtime->lookupFunction(0x1BE450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD384u; }
        if (ctx->pc != 0x1BD384u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BE450_0x1be450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD384u; }
        if (ctx->pc != 0x1BD384u) { return; }
    }
    ctx->pc = 0x1BD384u;
label_1bd384:
    // 0x1bd384: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1bd384u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1bd388: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1bd388u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bd38c: 0xc04629c  jal         func_118A70
    ctx->pc = 0x1BD38Cu;
    SET_GPR_U32(ctx, 31, 0x1BD394u);
    ctx->pc = 0x1BD390u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD38Cu;
            // 0x1bd390: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118A70u;
    if (runtime->hasFunction(0x118A70u)) {
        auto targetFn = runtime->lookupFunction(0x118A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD394u; }
        if (ctx->pc != 0x1BD394u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118A70_0x118a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD394u; }
        if (ctx->pc != 0x1BD394u) { return; }
    }
    ctx->pc = 0x1BD394u;
label_1bd394:
    // 0x1bd394: 0x4400008  bltz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1BD394u;
    {
        const bool branch_taken_0x1bd394 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1BD398u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD394u;
            // 0x1bd398: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd394) {
            ctx->pc = 0x1BD3B8u;
            goto label_1bd3b8;
        }
    }
    ctx->pc = 0x1BD39Cu;
    // 0x1bd39c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1bd39cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd3a0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1bd3a0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd3a4: 0xc04639e  jal         func_118E78
    ctx->pc = 0x1BD3A4u;
    SET_GPR_U32(ctx, 31, 0x1BD3ACu);
    ctx->pc = 0x1BD3A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD3A4u;
            // 0x1bd3a8: 0x24060002  addiu       $a2, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118E78u;
    if (runtime->hasFunction(0x118E78u)) {
        auto targetFn = runtime->lookupFunction(0x118E78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD3ACu; }
        if (ctx->pc != 0x1BD3ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118E78_0x118e78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD3ACu; }
        if (ctx->pc != 0x1BD3ACu) { return; }
    }
    ctx->pc = 0x1BD3ACu;
label_1bd3ac:
    // 0x1bd3ac: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1bd3acu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd3b0: 0xc04633e  jal         func_118CF8
    ctx->pc = 0x1BD3B0u;
    SET_GPR_U32(ctx, 31, 0x1BD3B8u);
    ctx->pc = 0x1BD3B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD3B0u;
            // 0x1bd3b4: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118CF8u;
    if (runtime->hasFunction(0x118CF8u)) {
        auto targetFn = runtime->lookupFunction(0x118CF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD3B8u; }
        if (ctx->pc != 0x1BD3B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118CF8_0x118cf8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD3B8u; }
        if (ctx->pc != 0x1BD3B8u) { return; }
    }
    ctx->pc = 0x1BD3B8u;
label_1bd3b8:
    // 0x1bd3b8: 0x8e040008  lw          $a0, 0x8($s0)
    ctx->pc = 0x1bd3b8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1bd3bc: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x1bd3bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1bd3c0: 0x10830003  beq         $a0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BD3C0u;
    {
        const bool branch_taken_0x1bd3c0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1BD3C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD3C0u;
            // 0x1bd3c4: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd3c0) {
            ctx->pc = 0x1BD3D0u;
            goto label_1bd3d0;
        }
    }
    ctx->pc = 0x1BD3C8u;
    // 0x1bd3c8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1bd3c8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1bd3cc: 0xac2344e0  sw          $v1, 0x44E0($at)
    ctx->pc = 0x1bd3ccu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17632), GPR_U32(ctx, 3));
label_1bd3d0:
    // 0x1bd3d0: 0x2610000c  addiu       $s0, $s0, 0xC
    ctx->pc = 0x1bd3d0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 12));
label_1bd3d4:
    // 0x1bd3d4: 0x8e050000  lw          $a1, 0x0($s0)
    ctx->pc = 0x1bd3d4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1bd3d8: 0x14a0ffd2  bnez        $a1, . + 4 + (-0x2E << 2)
    ctx->pc = 0x1BD3D8u;
    {
        const bool branch_taken_0x1bd3d8 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x1BD3DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD3D8u;
            // 0x1bd3dc: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bd3d8) {
            ctx->pc = 0x1BD324u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bd324;
        }
    }
    ctx->pc = 0x1BD3E0u;
    // 0x1bd3e0: 0x8c2344e0  lw          $v1, 0x44E0($at)
    ctx->pc = 0x1bd3e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17632)));
    // 0x1bd3e4: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BD3E4u;
    {
        const bool branch_taken_0x1bd3e4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1bd3e4) {
            ctx->pc = 0x1BD3F4u;
            goto label_1bd3f4;
        }
    }
    ctx->pc = 0x1BD3ECu;
    // 0x1bd3ec: 0xc06f900  jal         func_1BE400
    ctx->pc = 0x1BD3ECu;
    SET_GPR_U32(ctx, 31, 0x1BD3F4u);
    ctx->pc = 0x1BE400u;
    if (runtime->hasFunction(0x1BE400u)) {
        auto targetFn = runtime->lookupFunction(0x1BE400u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD3F4u; }
        if (ctx->pc != 0x1BD3F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BE400_0x1be400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD3F4u; }
        if (ctx->pc != 0x1BD3F4u) { return; }
    }
    ctx->pc = 0x1BD3F4u;
label_1bd3f4:
    // 0x1bd3f4: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1bd3f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1bd3f8: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1bd3f8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1bd3fc: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1bd3fcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bd400: 0x3e00008  jr          $ra
    ctx->pc = 0x1BD400u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BD404u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BD400u;
            // 0x1bd404: 0x27bd0130  addiu       $sp, $sp, 0x130 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 304));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BD310u: goto label_1bd310;
            case 0x1BD324u: goto label_1bd324;
            case 0x1BD32Cu: goto label_1bd32c;
            case 0x1BD33Cu: goto label_1bd33c;
            case 0x1BD358u: goto label_1bd358;
            case 0x1BD364u: goto label_1bd364;
            case 0x1BD384u: goto label_1bd384;
            case 0x1BD394u: goto label_1bd394;
            case 0x1BD3ACu: goto label_1bd3ac;
            case 0x1BD3B8u: goto label_1bd3b8;
            case 0x1BD3D0u: goto label_1bd3d0;
            case 0x1BD3D4u: goto label_1bd3d4;
            case 0x1BD3F4u: goto label_1bd3f4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BD408u;
    // 0x1bd408: 0x0  nop
    ctx->pc = 0x1bd408u;
    // NOP
    // 0x1bd40c: 0x0  nop
    ctx->pc = 0x1bd40cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
