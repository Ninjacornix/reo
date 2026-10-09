#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00102350
// Address: 0x102350 - 0x102498
void sub_00102350_0x102350(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00102350_0x102350");
#endif

    switch (ctx->pc) {
        case 0x10237cu: goto label_10237c;
        case 0x1023dcu: goto label_1023dc;
        case 0x1023fcu: goto label_1023fc;
        case 0x102404u: goto label_102404;
        default: break;
    }

    ctx->pc = 0x102350u;

    // 0x102350: 0x4842e000  cfc2.ni     $v0, $vi28
    ctx->pc = 0x102350u;
    SET_GPR_U32(ctx, 2, ctx->vu0_itop);
    // 0x102354: 0x34420200  ori         $v0, $v0, 0x200
    ctx->pc = 0x102354u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)512);
    // 0x102358: 0x48c2e000  ctc2.ni     $v0, $vi28
    ctx->pc = 0x102358u;
    ctx->vu0_itop = GPR_U32(ctx, 2) & 0x3FF;
    // 0x10235c: 0x3e00008  jr          $ra
    ctx->pc = 0x10235Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10237Cu: goto label_10237c;
            case 0x1023A4u: goto label_1023a4;
            case 0x1023B0u: goto label_1023b0;
            case 0x1023B4u: goto label_1023b4;
            case 0x1023DCu: goto label_1023dc;
            case 0x1023FCu: goto label_1023fc;
            case 0x102404u: goto label_102404;
            case 0x102408u: goto label_102408;
            case 0x10240Cu: goto label_10240c;
            case 0x102430u: goto label_102430;
            case 0x10243Cu: goto label_10243c;
            case 0x102460u: goto label_102460;
            case 0x10246Cu: goto label_10246c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102364u;
    // 0x102364: 0x0  nop
    ctx->pc = 0x102364u;
    // NOP
    // 0x102368: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x102368u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x10236c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x10236cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x102370: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x102370u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x102374: 0xc040926  jal         func_102498
    ctx->pc = 0x102374u;
    SET_GPR_U32(ctx, 31, 0x10237Cu);
    ctx->pc = 0x102378u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x102374u;
            // 0x102378: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x102498u;
    if (runtime->hasFunction(0x102498u)) {
        auto targetFn = runtime->lookupFunction(0x102498u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10237Cu; }
        if (ctx->pc != 0x10237Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00102498_0x102498(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10237Cu; }
        if (ctx->pc != 0x10237Cu) { return; }
    }
    ctx->pc = 0x10237Cu;
label_10237c:
    // 0x10237c: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x10237cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x102380: 0x2c620005  sltiu       $v0, $v1, 0x5
    ctx->pc = 0x102380u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)5) ? 1 : 0);
    // 0x102384: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x102384u;
    {
        const bool branch_taken_0x102384 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x102388u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102384u;
            // 0x102388: 0x3c020023  lui         $v0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x102384) {
            ctx->pc = 0x1023B4u;
            goto label_1023b4;
        }
    }
    ctx->pc = 0x10238Cu;
    // 0x10238c: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x10238cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x102390: 0x244276e0  addiu       $v0, $v0, 0x76E0
    ctx->pc = 0x102390u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 30432));
    // 0x102394: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x102394u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x102398: 0x8c640000  lw          $a0, 0x0($v1)
    ctx->pc = 0x102398u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x10239c: 0x800008  jr          $a0
    ctx->pc = 0x10239Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 4);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1023A4u: goto label_1023a4;
            case 0x1023B0u: goto label_1023b0;
            case 0x1023B4u: goto label_1023b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1023A4u;
label_1023a4:
    // 0x1023a4: 0x4842e000  cfc2.ni     $v0, $vi28
    ctx->pc = 0x1023a4u;
    SET_GPR_U32(ctx, 2, ctx->vu0_itop);
    // 0x1023a8: 0x34420100  ori         $v0, $v0, 0x100
    ctx->pc = 0x1023a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)256);
    // 0x1023ac: 0x48c2e000  ctc2.ni     $v0, $vi28
    ctx->pc = 0x1023acu;
    ctx->vu0_itop = GPR_U32(ctx, 2) & 0x3FF;
label_1023b0:
    // 0x1023b0: 0x24100001  addiu       $s0, $zero, 0x1
    ctx->pc = 0x1023b0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1023b4:
    // 0x1023b4: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1023b4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1023b8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1023b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1023bc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1023bcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1023c0: 0x3e00008  jr          $ra
    ctx->pc = 0x1023C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1023C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1023C0u;
            // 0x1023c4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10237Cu: goto label_10237c;
            case 0x1023A4u: goto label_1023a4;
            case 0x1023B0u: goto label_1023b0;
            case 0x1023B4u: goto label_1023b4;
            case 0x1023DCu: goto label_1023dc;
            case 0x1023FCu: goto label_1023fc;
            case 0x102404u: goto label_102404;
            case 0x102408u: goto label_102408;
            case 0x10240Cu: goto label_10240c;
            case 0x102430u: goto label_102430;
            case 0x10243Cu: goto label_10243c;
            case 0x102460u: goto label_102460;
            case 0x10246Cu: goto label_10246c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1023C8u;
    // 0x1023c8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1023c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1023cc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1023ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1023d0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1023d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1023d4: 0xc040926  jal         func_102498
    ctx->pc = 0x1023D4u;
    SET_GPR_U32(ctx, 31, 0x1023DCu);
    ctx->pc = 0x1023D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1023D4u;
            // 0x1023d8: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x102498u;
    if (runtime->hasFunction(0x102498u)) {
        auto targetFn = runtime->lookupFunction(0x102498u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1023DCu; }
        if (ctx->pc != 0x1023DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00102498_0x102498(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1023DCu; }
        if (ctx->pc != 0x1023DCu) { return; }
    }
    ctx->pc = 0x1023DCu;
label_1023dc:
    // 0x1023dc: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1023dcu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1023e0: 0x28620004  slti        $v0, $v1, 0x4
    ctx->pc = 0x1023e0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1023e4: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1023E4u;
    {
        const bool branch_taken_0x1023e4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1023E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1023E4u;
            // 0x1023e8: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1023e4) {
            ctx->pc = 0x102408u;
            goto label_102408;
        }
    }
    ctx->pc = 0x1023ECu;
    // 0x1023ec: 0x18600007  blez        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1023ECu;
    {
        const bool branch_taken_0x1023ec = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x1023F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1023ECu;
            // 0x1023f0: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1023ec) {
            ctx->pc = 0x10240Cu;
            goto label_10240c;
        }
    }
    ctx->pc = 0x1023F4u;
    // 0x1023f4: 0xc04093c  jal         func_1024F0
    ctx->pc = 0x1023F4u;
    SET_GPR_U32(ctx, 31, 0x1023FCu);
    ctx->pc = 0x1023F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1023F4u;
            // 0x1023f8: 0x24100001  addiu       $s0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1024F0u;
    if (runtime->hasFunction(0x1024F0u)) {
        auto targetFn = runtime->lookupFunction(0x1024F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1023FCu; }
        if (ctx->pc != 0x1023FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001024F0_0x1024f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1023FCu; }
        if (ctx->pc != 0x1023FCu) { return; }
    }
    ctx->pc = 0x1023FCu;
label_1023fc:
    // 0x1023fc: 0xc040938  jal         func_1024E0
    ctx->pc = 0x1023FCu;
    SET_GPR_U32(ctx, 31, 0x102404u);
    ctx->pc = 0x102400u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1023FCu;
            // 0x102400: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1024E0u;
    if (runtime->hasFunction(0x1024E0u)) {
        auto targetFn = runtime->lookupFunction(0x1024E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102404u; }
        if (ctx->pc != 0x102404u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001024E0_0x1024e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102404u; }
        if (ctx->pc != 0x102404u) { return; }
    }
    ctx->pc = 0x102404u;
label_102404:
    // 0x102404: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x102404u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_102408:
    // 0x102408: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x102408u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_10240c:
    // 0x10240c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x10240cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x102410: 0x3e00008  jr          $ra
    ctx->pc = 0x102410u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102414u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102410u;
            // 0x102414: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10237Cu: goto label_10237c;
            case 0x1023A4u: goto label_1023a4;
            case 0x1023B0u: goto label_1023b0;
            case 0x1023B4u: goto label_1023b4;
            case 0x1023DCu: goto label_1023dc;
            case 0x1023FCu: goto label_1023fc;
            case 0x102404u: goto label_102404;
            case 0x102408u: goto label_102408;
            case 0x10240Cu: goto label_10240c;
            case 0x102430u: goto label_102430;
            case 0x10243Cu: goto label_10243c;
            case 0x102460u: goto label_102460;
            case 0x10246Cu: goto label_10246c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102418u;
    // 0x102418: 0x4843e000  cfc2.ni     $v1, $vi28
    ctx->pc = 0x102418u;
    SET_GPR_U32(ctx, 3, ctx->vu0_itop);
    // 0x10241c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x10241cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x102420: 0x14820003  bne         $a0, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x102420u;
    {
        const bool branch_taken_0x102420 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        if (branch_taken_0x102420) {
            ctx->pc = 0x102430u;
            goto label_102430;
        }
    }
    ctx->pc = 0x102428u;
    // 0x102428: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x102428u;
    {
        const bool branch_taken_0x102428 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10242Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102428u;
            // 0x10242c: 0x34630400  ori         $v1, $v1, 0x400 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1024);
        ctx->in_delay_slot = false;
        if (branch_taken_0x102428) {
            ctx->pc = 0x10243Cu;
            goto label_10243c;
        }
    }
    ctx->pc = 0x102430u;
label_102430:
    // 0x102430: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x102430u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x102434: 0x3442fbff  ori         $v0, $v0, 0xFBFF
    ctx->pc = 0x102434u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)64511);
    // 0x102438: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x102438u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
label_10243c:
    // 0x10243c: 0x48c3e000  ctc2.ni     $v1, $vi28
    ctx->pc = 0x10243cu;
    ctx->vu0_itop = GPR_U32(ctx, 3) & 0x3FF;
    // 0x102440: 0x3e00008  jr          $ra
    ctx->pc = 0x102440u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10237Cu: goto label_10237c;
            case 0x1023A4u: goto label_1023a4;
            case 0x1023B0u: goto label_1023b0;
            case 0x1023B4u: goto label_1023b4;
            case 0x1023DCu: goto label_1023dc;
            case 0x1023FCu: goto label_1023fc;
            case 0x102404u: goto label_102404;
            case 0x102408u: goto label_102408;
            case 0x10240Cu: goto label_10240c;
            case 0x102430u: goto label_102430;
            case 0x10243Cu: goto label_10243c;
            case 0x102460u: goto label_102460;
            case 0x10246Cu: goto label_10246c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102448u;
    // 0x102448: 0x4843e000  cfc2.ni     $v1, $vi28
    ctx->pc = 0x102448u;
    SET_GPR_U32(ctx, 3, ctx->vu0_itop);
    // 0x10244c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x10244cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x102450: 0x14820003  bne         $a0, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x102450u;
    {
        const bool branch_taken_0x102450 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        if (branch_taken_0x102450) {
            ctx->pc = 0x102460u;
            goto label_102460;
        }
    }
    ctx->pc = 0x102458u;
    // 0x102458: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x102458u;
    {
        const bool branch_taken_0x102458 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10245Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102458u;
            // 0x10245c: 0x34630800  ori         $v1, $v1, 0x800 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)2048);
        ctx->in_delay_slot = false;
        if (branch_taken_0x102458) {
            ctx->pc = 0x10246Cu;
            goto label_10246c;
        }
    }
    ctx->pc = 0x102460u;
label_102460:
    // 0x102460: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x102460u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x102464: 0x3442f7ff  ori         $v0, $v0, 0xF7FF
    ctx->pc = 0x102464u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)63487);
    // 0x102468: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x102468u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
label_10246c:
    // 0x10246c: 0x48c3e000  ctc2.ni     $v1, $vi28
    ctx->pc = 0x10246cu;
    ctx->vu0_itop = GPR_U32(ctx, 3) & 0x3FF;
    // 0x102470: 0x3e00008  jr          $ra
    ctx->pc = 0x102470u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10237Cu: goto label_10237c;
            case 0x1023A4u: goto label_1023a4;
            case 0x1023B0u: goto label_1023b0;
            case 0x1023B4u: goto label_1023b4;
            case 0x1023DCu: goto label_1023dc;
            case 0x1023FCu: goto label_1023fc;
            case 0x102404u: goto label_102404;
            case 0x102408u: goto label_102408;
            case 0x10240Cu: goto label_10240c;
            case 0x102430u: goto label_102430;
            case 0x10243Cu: goto label_10243c;
            case 0x102460u: goto label_102460;
            case 0x10246Cu: goto label_10246c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102478u;
    // 0x102478: 0x4842e000  cfc2.ni     $v0, $vi28
    ctx->pc = 0x102478u;
    SET_GPR_U32(ctx, 2, ctx->vu0_itop);
    // 0x10247c: 0x21282  srl         $v0, $v0, 10
    ctx->pc = 0x10247cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 10));
    // 0x102480: 0x3e00008  jr          $ra
    ctx->pc = 0x102480u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102484u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102480u;
            // 0x102484: 0x30420001  andi        $v0, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10237Cu: goto label_10237c;
            case 0x1023A4u: goto label_1023a4;
            case 0x1023B0u: goto label_1023b0;
            case 0x1023B4u: goto label_1023b4;
            case 0x1023DCu: goto label_1023dc;
            case 0x1023FCu: goto label_1023fc;
            case 0x102404u: goto label_102404;
            case 0x102408u: goto label_102408;
            case 0x10240Cu: goto label_10240c;
            case 0x102430u: goto label_102430;
            case 0x10243Cu: goto label_10243c;
            case 0x102460u: goto label_102460;
            case 0x10246Cu: goto label_10246c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102488u;
    // 0x102488: 0x4842e000  cfc2.ni     $v0, $vi28
    ctx->pc = 0x102488u;
    SET_GPR_U32(ctx, 2, ctx->vu0_itop);
    // 0x10248c: 0x212c2  srl         $v0, $v0, 11
    ctx->pc = 0x10248cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 11));
    // 0x102490: 0x3e00008  jr          $ra
    ctx->pc = 0x102490u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102494u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102490u;
            // 0x102494: 0x30420001  andi        $v0, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10237Cu: goto label_10237c;
            case 0x1023A4u: goto label_1023a4;
            case 0x1023B0u: goto label_1023b0;
            case 0x1023B4u: goto label_1023b4;
            case 0x1023DCu: goto label_1023dc;
            case 0x1023FCu: goto label_1023fc;
            case 0x102404u: goto label_102404;
            case 0x102408u: goto label_102408;
            case 0x10240Cu: goto label_10240c;
            case 0x102430u: goto label_102430;
            case 0x10243Cu: goto label_10243c;
            case 0x102460u: goto label_102460;
            case 0x10246Cu: goto label_10246c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102498u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
