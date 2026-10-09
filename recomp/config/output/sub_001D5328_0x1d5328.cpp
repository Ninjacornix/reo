#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D5328
// Address: 0x1d5328 - 0x1d53f0
void sub_001D5328_0x1d5328(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D5328_0x1d5328");
#endif

    switch (ctx->pc) {
        case 0x1d5344u: goto label_1d5344;
        case 0x1d5358u: goto label_1d5358;
        case 0x1d536cu: goto label_1d536c;
        case 0x1d537cu: goto label_1d537c;
        case 0x1d5394u: goto label_1d5394;
        case 0x1d53b0u: goto label_1d53b0;
        case 0x1d53c8u: goto label_1d53c8;
        default: break;
    }

    ctx->pc = 0x1d5328u;

    // 0x1d5328: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1d5328u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1d532c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x1d532cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x1d5330: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x1d5330u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x1d5334: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1d5334u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1d5338: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1d5338u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1d533c: 0xc047598  jal         func_11D660
    ctx->pc = 0x1D533Cu;
    SET_GPR_U32(ctx, 31, 0x1D5344u);
    ctx->pc = 0x1D5340u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D533Cu;
            // 0x1d5340: 0x902d  daddu       $s2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5344u; }
        if (ctx->pc != 0x1D5344u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5344u; }
        if (ctx->pc != 0x1D5344u) { return; }
    }
    ctx->pc = 0x1D5344u;
label_1d5344:
    // 0x1d5344: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x1d5344u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5348: 0x24040003  addiu       $a0, $zero, 0x3
    ctx->pc = 0x1d5348u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1d534c: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1d534cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1d5350: 0xc0450c8  jal         func_114320
    ctx->pc = 0x1D5350u;
    SET_GPR_U32(ctx, 31, 0x1D5358u);
    ctx->pc = 0x1D5354u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5350u;
            // 0x1d5354: 0x8c4528dc  lw          $a1, 0x28DC($v0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 10460)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114320u;
    if (runtime->hasFunction(0x114320u)) {
        auto targetFn = runtime->lookupFunction(0x114320u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5358u; }
        if (ctx->pc != 0x1D5358u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114320_0x114320(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5358u; }
        if (ctx->pc != 0x1D5358u) { return; }
    }
    ctx->pc = 0x1D5358u;
label_1d5358:
    // 0x1d5358: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1d5358u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d535c: 0x16000003  bnez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D535Cu;
    {
        const bool branch_taken_0x1d535c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d535c) {
            ctx->pc = 0x1D536Cu;
            goto label_1d536c;
        }
    }
    ctx->pc = 0x1D5364u;
    // 0x1d5364: 0xc045440  jal         func_115100
    ctx->pc = 0x1D5364u;
    SET_GPR_U32(ctx, 31, 0x1D536Cu);
    ctx->pc = 0x1D5368u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5364u;
            // 0x1d5368: 0x24040003  addiu       $a0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x115100u;
    if (runtime->hasFunction(0x115100u)) {
        auto targetFn = runtime->lookupFunction(0x115100u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D536Cu; }
        if (ctx->pc != 0x1D536Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00115100_0x115100(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D536Cu; }
        if (ctx->pc != 0x1D536Cu) { return; }
    }
    ctx->pc = 0x1D536Cu;
label_1d536c:
    // 0x1d536c: 0x12200003  beqz        $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D536Cu;
    {
        const bool branch_taken_0x1d536c = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d536c) {
            ctx->pc = 0x1D537Cu;
            goto label_1d537c;
        }
    }
    ctx->pc = 0x1D5374u;
    // 0x1d5374: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x1D5374u;
    SET_GPR_U32(ctx, 31, 0x1D537Cu);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D537Cu; }
        if (ctx->pc != 0x1D537Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D537Cu; }
        if (ctx->pc != 0x1D537Cu) { return; }
    }
    ctx->pc = 0x1D537Cu;
label_1d537c:
    // 0x1d537c: 0x6010006  bgez        $s0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D537Cu;
    {
        const bool branch_taken_0x1d537c = (GPR_S64(ctx, 16) >= 0);
        ctx->pc = 0x1D5380u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D537Cu;
            // 0x1d5380: 0x3c110023  lui         $s1, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d537c) {
            ctx->pc = 0x1D5398u;
            goto label_1d5398;
        }
    }
    ctx->pc = 0x1D5384u;
    // 0x1d5384: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1d5384u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1d5388: 0x24120001  addiu       $s2, $zero, 0x1
    ctx->pc = 0x1d5388u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d538c: 0xc045a12  jal         func_116848
    ctx->pc = 0x1D538Cu;
    SET_GPR_U32(ctx, 31, 0x1D5394u);
    ctx->pc = 0x1D5390u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D538Cu;
            // 0x1d5390: 0x24846e08  addiu       $a0, $a0, 0x6E08 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 28168));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5394u; }
        if (ctx->pc != 0x1D5394u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5394u; }
        if (ctx->pc != 0x1D5394u) { return; }
    }
    ctx->pc = 0x1D5394u;
label_1d5394:
    // 0x1d5394: 0x3c110023  lui         $s1, 0x23
    ctx->pc = 0x1d5394u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)35 << 16));
label_1d5398:
    // 0x1d5398: 0x2410ffff  addiu       $s0, $zero, -0x1
    ctx->pc = 0x1d5398u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d539c: 0x8e246998  lw          $a0, 0x6998($s1)
    ctx->pc = 0x1d539cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 27032)));
    // 0x1d53a0: 0x1090000c  beq         $a0, $s0, . + 4 + (0xC << 2)
    ctx->pc = 0x1D53A0u;
    {
        const bool branch_taken_0x1d53a0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 16));
        ctx->pc = 0x1D53A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D53A0u;
            // 0x1d53a4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d53a0) {
            ctx->pc = 0x1D53D4u;
            goto label_1d53d4;
        }
    }
    ctx->pc = 0x1D53A8u;
    // 0x1d53a8: 0xc04518c  jal         func_114630
    ctx->pc = 0x1D53A8u;
    SET_GPR_U32(ctx, 31, 0x1D53B0u);
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D53B0u; }
        if (ctx->pc != 0x1D53B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D53B0u; }
        if (ctx->pc != 0x1D53B0u) { return; }
    }
    ctx->pc = 0x1D53B0u;
label_1d53b0:
    // 0x1d53b0: 0x4430007  bgezl       $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1D53B0u;
    {
        const bool branch_taken_0x1d53b0 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1d53b0) {
            ctx->pc = 0x1D53B4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1D53B0u;
            // 0x1d53b4: 0xae306998  sw          $s0, 0x6998($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 27032), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1D53D0u;
            goto label_1d53d0;
        }
    }
    ctx->pc = 0x1D53B8u;
    // 0x1d53b8: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1d53b8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1d53bc: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x1d53bcu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x1d53c0: 0xc045a12  jal         func_116848
    ctx->pc = 0x1D53C0u;
    SET_GPR_U32(ctx, 31, 0x1D53C8u);
    ctx->pc = 0x1D53C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D53C0u;
            // 0x1d53c4: 0x24846e38  addiu       $a0, $a0, 0x6E38 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 28216));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D53C8u; }
        if (ctx->pc != 0x1D53C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D53C8u; }
        if (ctx->pc != 0x1D53C8u) { return; }
    }
    ctx->pc = 0x1D53C8u;
label_1d53c8:
    // 0x1d53c8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1D53C8u;
    {
        const bool branch_taken_0x1d53c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D53CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D53C8u;
            // 0x1d53cc: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d53c8) {
            ctx->pc = 0x1D53D4u;
            goto label_1d53d4;
        }
    }
    ctx->pc = 0x1D53D0u;
label_1d53d0:
    // 0x1d53d0: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d53d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1d53d4:
    // 0x1d53d4: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1d53d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d53d8: 0x12100a  movz        $v0, $zero, $s2
    ctx->pc = 0x1d53d8u;
    if (GPR_U64(ctx, 18) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 0));
    // 0x1d53dc: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x1d53dcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d53e0: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x1d53e0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d53e4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1d53e4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d53e8: 0x3e00008  jr          $ra
    ctx->pc = 0x1D53E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D53ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D53E8u;
            // 0x1d53ec: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D5344u: goto label_1d5344;
            case 0x1D5358u: goto label_1d5358;
            case 0x1D536Cu: goto label_1d536c;
            case 0x1D537Cu: goto label_1d537c;
            case 0x1D5394u: goto label_1d5394;
            case 0x1D5398u: goto label_1d5398;
            case 0x1D53B0u: goto label_1d53b0;
            case 0x1D53C8u: goto label_1d53c8;
            case 0x1D53D0u: goto label_1d53d0;
            case 0x1D53D4u: goto label_1d53d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D53F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
