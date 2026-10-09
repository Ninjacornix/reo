#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00136688
// Address: 0x136688 - 0x13675c
void sub_00136688_0x136688(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00136688_0x136688");
#endif

    switch (ctx->pc) {
        case 0x1366c4u: goto label_1366c4;
        case 0x1366dcu: goto label_1366dc;
        case 0x1366f4u: goto label_1366f4;
        case 0x13670cu: goto label_13670c;
        case 0x136714u: goto label_136714;
        case 0x136734u: goto label_136734;
        default: break;
    }

    ctx->pc = 0x136688u;

    // 0x136688: 0x27bdfd70  addiu       $sp, $sp, -0x290
    ctx->pc = 0x136688u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966640));
    // 0x13668c: 0xffb00260  sd          $s0, 0x260($sp)
    ctx->pc = 0x13668cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 608), GPR_U64(ctx, 16));
    // 0x136690: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x136690u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136694: 0xffb10268  sd          $s1, 0x268($sp)
    ctx->pc = 0x136694u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 616), GPR_U64(ctx, 17));
    // 0x136698: 0x27b10130  addiu       $s1, $sp, 0x130
    ctx->pc = 0x136698u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 304));
    // 0x13669c: 0xffb20270  sd          $s2, 0x270($sp)
    ctx->pc = 0x13669cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 624), GPR_U64(ctx, 18));
    // 0x1366a0: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1366a0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1366a4: 0xffb30278  sd          $s3, 0x278($sp)
    ctx->pc = 0x1366a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 632), GPR_U64(ctx, 19));
    // 0x1366a8: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x1366a8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1366ac: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1366acu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1366b0: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1366b0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1366b4: 0xffb40280  sd          $s4, 0x280($sp)
    ctx->pc = 0x1366b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 640), GPR_U64(ctx, 20));
    // 0x1366b8: 0xffbf0288  sd          $ra, 0x288($sp)
    ctx->pc = 0x1366b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 648), GPR_U64(ctx, 31));
    // 0x1366bc: 0xc04d6b4  jal         func_135AD0
    ctx->pc = 0x1366BCu;
    SET_GPR_U32(ctx, 31, 0x1366C4u);
    ctx->pc = 0x1366C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1366BCu;
            // 0x1366c0: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135AD0u;
    if (runtime->hasFunction(0x135AD0u)) {
        auto targetFn = runtime->lookupFunction(0x135AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1366C4u; }
        if (ctx->pc != 0x1366C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135AD0_0x135ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1366C4u; }
        if (ctx->pc != 0x1366C4u) { return; }
    }
    ctx->pc = 0x1366C4u;
label_1366c4:
    // 0x1366c4: 0x83a20000  lb          $v0, 0x0($sp)
    ctx->pc = 0x1366c4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1366c8: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x1366c8u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1366cc: 0x1440000c  bnez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1366CCu;
    {
        const bool branch_taken_0x1366cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1366D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1366CCu;
            // 0x1366d0: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1366cc) {
            ctx->pc = 0x136700u;
            goto label_136700;
        }
    }
    ctx->pc = 0x1366D4u;
    // 0x1366d4: 0xc04d706  jal         func_135C18
    ctx->pc = 0x1366D4u;
    SET_GPR_U32(ctx, 31, 0x1366DCu);
    ctx->pc = 0x135C18u;
    if (runtime->hasFunction(0x135C18u)) {
        auto targetFn = runtime->lookupFunction(0x135C18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1366DCu; }
        if (ctx->pc != 0x1366DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135C18_0x135c18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1366DCu; }
        if (ctx->pc != 0x1366DCu) { return; }
    }
    ctx->pc = 0x1366DCu;
label_1366dc:
    // 0x1366dc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1366dcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1366e0: 0x83a20000  lb          $v0, 0x0($sp)
    ctx->pc = 0x1366e0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1366e4: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1366E4u;
    {
        const bool branch_taken_0x1366e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1366E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1366E4u;
            // 0x1366e8: 0x2484be20  addiu       $a0, $a0, -0x41E0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950432));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1366e4) {
            ctx->pc = 0x136700u;
            goto label_136700;
        }
    }
    ctx->pc = 0x1366ECu;
    // 0x1366ec: 0xc04d480  jal         func_135200
    ctx->pc = 0x1366ECu;
    SET_GPR_U32(ctx, 31, 0x1366F4u);
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1366F4u; }
        if (ctx->pc != 0x1366F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1366F4u; }
        if (ctx->pc != 0x1366F4u) { return; }
    }
    ctx->pc = 0x1366F4u;
label_1366f4:
    // 0x1366f4: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1366F4u;
    {
        const bool branch_taken_0x1366f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1366F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1366F4u;
            // 0x1366f8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1366f4) {
            ctx->pc = 0x13673Cu;
            goto label_13673c;
        }
    }
    ctx->pc = 0x1366FCu;
    // 0x1366fc: 0x0  nop
    ctx->pc = 0x1366fcu;
    // NOP
label_136700:
    // 0x136700: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x136700u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136704: 0xc04dbfa  jal         func_136FE8
    ctx->pc = 0x136704u;
    SET_GPR_U32(ctx, 31, 0x13670Cu);
    ctx->pc = 0x136708u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136704u;
            // 0x136708: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x136FE8u;
    if (runtime->hasFunction(0x136FE8u)) {
        auto targetFn = runtime->lookupFunction(0x136FE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13670Cu; }
        if (ctx->pc != 0x13670Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00136FE8_0x136fe8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13670Cu; }
        if (ctx->pc != 0x13670Cu) { return; }
    }
    ctx->pc = 0x13670Cu;
label_13670c:
    // 0x13670c: 0xc04d558  jal         func_135560
    ctx->pc = 0x13670Cu;
    SET_GPR_U32(ctx, 31, 0x136714u);
    ctx->pc = 0x136710u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13670Cu;
            // 0x136710: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135560u;
    if (runtime->hasFunction(0x135560u)) {
        auto targetFn = runtime->lookupFunction(0x135560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136714u; }
        if (ctx->pc != 0x136714u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135560_0x135560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136714u; }
        if (ctx->pc != 0x136714u) { return; }
    }
    ctx->pc = 0x136714u;
label_136714:
    // 0x136714: 0x50400009  beql        $v0, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x136714u;
    {
        const bool branch_taken_0x136714 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x136714) {
            ctx->pc = 0x136718u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x136714u;
            // 0x136718: 0x280102d  daddu       $v0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13673Cu;
            goto label_13673c;
        }
    }
    ctx->pc = 0x13671Cu;
    // 0x13671c: 0x8c420048  lw          $v0, 0x48($v0)
    ctx->pc = 0x13671cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 72)));
    // 0x136720: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x136720u;
    {
        const bool branch_taken_0x136720 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x136724u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136720u;
            // 0x136724: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136720) {
            ctx->pc = 0x136738u;
            goto label_136738;
        }
    }
    ctx->pc = 0x136728u;
    // 0x136728: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x136728u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13672c: 0x40f809  jalr        $v0
    ctx->pc = 0x13672Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x136734u);
        ctx->pc = 0x136730u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13672Cu;
            // 0x136730: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x136734u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1366C4u: goto label_1366c4;
            case 0x1366DCu: goto label_1366dc;
            case 0x1366F4u: goto label_1366f4;
            case 0x136700u: goto label_136700;
            case 0x13670Cu: goto label_13670c;
            case 0x136714u: goto label_136714;
            case 0x136734u: goto label_136734;
            case 0x136738u: goto label_136738;
            case 0x13673Cu: goto label_13673c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136734u; }
            if (ctx->pc != 0x136734u) { return; }
        }
        }
    }
    ctx->pc = 0x136734u;
label_136734:
    // 0x136734: 0x40a02d  daddu       $s4, $v0, $zero
    ctx->pc = 0x136734u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_136738:
    // 0x136738: 0x280102d  daddu       $v0, $s4, $zero
    ctx->pc = 0x136738u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
label_13673c:
    // 0x13673c: 0xdfb00260  ld          $s0, 0x260($sp)
    ctx->pc = 0x13673cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 608)));
    // 0x136740: 0xdfb10268  ld          $s1, 0x268($sp)
    ctx->pc = 0x136740u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 616)));
    // 0x136744: 0xdfb20270  ld          $s2, 0x270($sp)
    ctx->pc = 0x136744u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 624)));
    // 0x136748: 0xdfb30278  ld          $s3, 0x278($sp)
    ctx->pc = 0x136748u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 632)));
    // 0x13674c: 0xdfb40280  ld          $s4, 0x280($sp)
    ctx->pc = 0x13674cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 640)));
    // 0x136750: 0xdfbf0288  ld          $ra, 0x288($sp)
    ctx->pc = 0x136750u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 648)));
    // 0x136754: 0x3e00008  jr          $ra
    ctx->pc = 0x136754u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136758u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136754u;
            // 0x136758: 0x27bd0290  addiu       $sp, $sp, 0x290 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 656));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1366C4u: goto label_1366c4;
            case 0x1366DCu: goto label_1366dc;
            case 0x1366F4u: goto label_1366f4;
            case 0x136700u: goto label_136700;
            case 0x13670Cu: goto label_13670c;
            case 0x136714u: goto label_136714;
            case 0x136734u: goto label_136734;
            case 0x136738u: goto label_136738;
            case 0x13673Cu: goto label_13673c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13675Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
