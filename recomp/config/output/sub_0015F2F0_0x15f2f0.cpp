#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015F2F0
// Address: 0x15f2f0 - 0x15f3f0
void sub_0015F2F0_0x15f2f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015F2F0_0x15f2f0");
#endif

    switch (ctx->pc) {
        case 0x15f318u: goto label_15f318;
        case 0x15f324u: goto label_15f324;
        case 0x15f334u: goto label_15f334;
        case 0x15f340u: goto label_15f340;
        case 0x15f348u: goto label_15f348;
        case 0x15f39cu: goto label_15f39c;
        case 0x15f3c8u: goto label_15f3c8;
        case 0x15f3d4u: goto label_15f3d4;
        default: break;
    }

    ctx->pc = 0x15f2f0u;

label_15f2f0:
    // 0x15f2f0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15f2f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15f2f4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15f2f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15f2f8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x15f2f8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f2fc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15f2fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15f300: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x15f300u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x15f304: 0x8e110040  lw          $s1, 0x40($s0)
    ctx->pc = 0x15f304u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
    // 0x15f308: 0x5220001a  beql        $s1, $zero, . + 4 + (0x1A << 2)
    ctx->pc = 0x15F308u;
    {
        const bool branch_taken_0x15f308 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        if (branch_taken_0x15f308) {
            ctx->pc = 0x15F30Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15F308u;
            // 0x15f30c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15F374u;
            goto label_15f374;
        }
    }
    ctx->pc = 0x15F310u;
    // 0x15f310: 0xc0590ec  jal         func_1643B0
    ctx->pc = 0x15F310u;
    SET_GPR_U32(ctx, 31, 0x15F318u);
    ctx->pc = 0x1643B0u;
    if (runtime->hasFunction(0x1643B0u)) {
        auto targetFn = runtime->lookupFunction(0x1643B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F318u; }
        if (ctx->pc != 0x15F318u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001643B0_0x1643b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F318u; }
        if (ctx->pc != 0x15F318u) { return; }
    }
    ctx->pc = 0x15F318u;
label_15f318:
    // 0x15f318: 0xae000008  sw          $zero, 0x8($s0)
    ctx->pc = 0x15f318u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
    // 0x15f31c: 0xc05ceca  jal         func_173B28
    ctx->pc = 0x15F31Cu;
    SET_GPR_U32(ctx, 31, 0x15F324u);
    ctx->pc = 0x15F320u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F31Cu;
            // 0x15f320: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x173B28u;
    if (runtime->hasFunction(0x173B28u)) {
        auto targetFn = runtime->lookupFunction(0x173B28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F324u; }
        if (ctx->pc != 0x15F324u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00173B28_0x173b28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F324u; }
        if (ctx->pc != 0x15F324u) { return; }
    }
    ctx->pc = 0x15F324u;
label_15f324:
    // 0x15f324: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x15F324u;
    {
        const bool branch_taken_0x15f324 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15F328u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F324u;
            // 0x15f328: 0x2404fecc  addiu       $a0, $zero, -0x134 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966988));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15f324) {
            ctx->pc = 0x15F340u;
            goto label_15f340;
        }
    }
    ctx->pc = 0x15F32Cu;
    // 0x15f32c: 0xc057abc  jal         func_15EAF0
    ctx->pc = 0x15F32Cu;
    SET_GPR_U32(ctx, 31, 0x15F334u);
    ctx->pc = 0x15EAF0u;
    if (runtime->hasFunction(0x15EAF0u)) {
        auto targetFn = runtime->lookupFunction(0x15EAF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F334u; }
        if (ctx->pc != 0x15F334u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015EAF0_0x15eaf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F334u; }
        if (ctx->pc != 0x15F334u) { return; }
    }
    ctx->pc = 0x15F334u;
label_15f334:
    // 0x15f334: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15f334u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15f338: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15F338u;
    SET_GPR_U32(ctx, 31, 0x15F340u);
    ctx->pc = 0x15F33Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F338u;
            // 0x15f33c: 0x2484f180  addiu       $a0, $a0, -0xE80 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294963584));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F340u; }
        if (ctx->pc != 0x15F340u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F340u; }
        if (ctx->pc != 0x15F340u) { return; }
    }
    ctx->pc = 0x15F340u;
label_15f340:
    // 0x15f340: 0xc058bd2  jal         func_162F48
    ctx->pc = 0x15F340u;
    SET_GPR_U32(ctx, 31, 0x15F348u);
    ctx->pc = 0x15F344u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F340u;
            // 0x15f344: 0x260401ec  addiu       $a0, $s0, 0x1EC (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 492));
        ctx->in_delay_slot = false;
    ctx->pc = 0x162F48u;
    if (runtime->hasFunction(0x162F48u)) {
        auto targetFn = runtime->lookupFunction(0x162F48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F348u; }
        if (ctx->pc != 0x15F348u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00162F48_0x162f48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F348u; }
        if (ctx->pc != 0x15F348u) { return; }
    }
    ctx->pc = 0x15F348u;
label_15f348:
    // 0x15f348: 0xae00020c  sw          $zero, 0x20C($s0)
    ctx->pc = 0x15f348u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 524), GPR_U32(ctx, 0));
    // 0x15f34c: 0x8e020044  lw          $v0, 0x44($s0)
    ctx->pc = 0x15f34cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x15f350: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x15F350u;
    {
        const bool branch_taken_0x15f350 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15F354u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F350u;
            // 0x15f354: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15f350) {
            ctx->pc = 0x15F370u;
            goto label_15f370;
        }
    }
    ctx->pc = 0x15F358u;
    // 0x15f358: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f358u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f35c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15f35cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f360: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15f360u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15f364: 0x80591b6  j           func_1646D8
    ctx->pc = 0x15F364u;
    ctx->pc = 0x15F368u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F364u;
            // 0x15f368: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1646D8u;
    if (runtime->hasFunction(0x1646D8u)) {
        auto targetFn = runtime->lookupFunction(0x1646D8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001646D8_0x1646d8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15F36Cu;
    // 0x15f36c: 0x0  nop
    ctx->pc = 0x15f36cu;
    // NOP
label_15f370:
    // 0x15f370: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f370u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_15f374:
    // 0x15f374: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15f374u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f378: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15f378u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15f37c: 0x3e00008  jr          $ra
    ctx->pc = 0x15F37Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15F380u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F37Cu;
            // 0x15f380: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15F2F0u: goto label_15f2f0;
            case 0x15F318u: goto label_15f318;
            case 0x15F324u: goto label_15f324;
            case 0x15F334u: goto label_15f334;
            case 0x15F340u: goto label_15f340;
            case 0x15F348u: goto label_15f348;
            case 0x15F370u: goto label_15f370;
            case 0x15F374u: goto label_15f374;
            case 0x15F39Cu: goto label_15f39c;
            case 0x15F3C0u: goto label_15f3c0;
            case 0x15F3C8u: goto label_15f3c8;
            case 0x15F3D4u: goto label_15f3d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15F384u;
    // 0x15f384: 0x0  nop
    ctx->pc = 0x15f384u;
    // NOP
    // 0x15f388: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15f388u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15f38c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15f38cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15f390: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x15f390u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x15f394: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x15F394u;
    SET_GPR_U32(ctx, 31, 0x15F39Cu);
    ctx->pc = 0x15F398u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F394u;
            // 0x15f398: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F39Cu; }
        if (ctx->pc != 0x15F39Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F39Cu; }
        if (ctx->pc != 0x15F39Cu) { return; }
    }
    ctx->pc = 0x15F39Cu;
label_15f39c:
    // 0x15f39c: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x15F39Cu;
    {
        const bool branch_taken_0x15f39c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15F3A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F39Cu;
            // 0x15f3a0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15f39c) {
            ctx->pc = 0x15F3C0u;
            goto label_15f3c0;
        }
    }
    ctx->pc = 0x15F3A4u;
    // 0x15f3a4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15f3a4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15f3a8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f3a8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f3ac: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x15f3acu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f3b0: 0x2484f1a0  addiu       $a0, $a0, -0xE60
    ctx->pc = 0x15f3b0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294963616));
    // 0x15f3b4: 0x8058dd4  j           func_163750
    ctx->pc = 0x15F3B4u;
    ctx->pc = 0x15F3B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F3B4u;
            // 0x15f3b8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15F3BCu;
    // 0x15f3bc: 0x0  nop
    ctx->pc = 0x15f3bcu;
    // NOP
label_15f3c0:
    // 0x15f3c0: 0xc057cbc  jal         func_15F2F0
    ctx->pc = 0x15F3C0u;
    SET_GPR_U32(ctx, 31, 0x15F3C8u);
    ctx->pc = 0x15F2F0u;
    goto label_15f2f0;
    ctx->pc = 0x15F3C8u;
label_15f3c8:
    // 0x15f3c8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15f3c8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f3cc: 0xc058abe  jal         func_162AF8
    ctx->pc = 0x15F3CCu;
    SET_GPR_U32(ctx, 31, 0x15F3D4u);
    ctx->pc = 0x15F3D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F3CCu;
            // 0x15f3d0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x162AF8u;
    if (runtime->hasFunction(0x162AF8u)) {
        auto targetFn = runtime->lookupFunction(0x162AF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F3D4u; }
        if (ctx->pc != 0x15F3D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00162AF8_0x162af8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F3D4u; }
        if (ctx->pc != 0x15F3D4u) { return; }
    }
    ctx->pc = 0x15F3D4u;
label_15f3d4:
    // 0x15f3d4: 0xae000074  sw          $zero, 0x74($s0)
    ctx->pc = 0x15f3d4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 116), GPR_U32(ctx, 0));
    // 0x15f3d8: 0x8e04004c  lw          $a0, 0x4C($s0)
    ctx->pc = 0x15f3d8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 76)));
    // 0x15f3dc: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x15f3dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f3e0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f3e0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f3e4: 0x804f3de  j           func_13CF78
    ctx->pc = 0x15F3E4u;
    ctx->pc = 0x15F3E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F3E4u;
            // 0x15f3e8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13CF78u;
    if (runtime->hasFunction(0x13CF78u)) {
        auto targetFn = runtime->lookupFunction(0x13CF78u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013CF78_0x13cf78(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15F3ECu;
    // 0x15f3ec: 0x0  nop
    ctx->pc = 0x15f3ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
