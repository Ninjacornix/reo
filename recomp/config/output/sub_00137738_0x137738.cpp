#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00137738
// Address: 0x137738 - 0x137868
void sub_00137738_0x137738(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00137738_0x137738");
#endif

    switch (ctx->pc) {
        case 0x137760u: goto label_137760;
        case 0x13777cu: goto label_13777c;
        case 0x137798u: goto label_137798;
        case 0x1377a0u: goto label_1377a0;
        case 0x1377b0u: goto label_1377b0;
        case 0x1377e0u: goto label_1377e0;
        case 0x1377fcu: goto label_1377fc;
        default: break;
    }

    ctx->pc = 0x137738u;

label_137738:
    // 0x137738: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x137738u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x13773c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13773cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x137740: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x137740u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x137744: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x137744u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x137748: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x137748u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13774c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13774cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x137750: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x137750u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x137754: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x137754u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x137758: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x137758u;
    {
        const bool branch_taken_0x137758 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13775Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137758u;
            // 0x13775c: 0x3c130022  lui         $s3, 0x22 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)34 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x137758) {
            ctx->pc = 0x137768u;
            goto label_137768;
        }
    }
    ctx->pc = 0x137760u;
label_137760:
    // 0x137760: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x137760u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x137764: 0x28403  sra         $s0, $v0, 16
    ctx->pc = 0x137764u;
    SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 2), 16));
label_137768:
    // 0x137768: 0x2a0203e8  slti        $v0, $s0, 0x3E8
    ctx->pc = 0x137768u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)1000) ? 1 : 0);
    // 0x13776c: 0x50400011  beql        $v0, $zero, . + 4 + (0x11 << 2)
    ctx->pc = 0x13776Cu;
    {
        const bool branch_taken_0x13776c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x13776c) {
            ctx->pc = 0x137770u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13776Cu;
            // 0x137770: 0x82320002  lb          $s2, 0x2($s1) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1377B4u;
            goto label_1377b4;
        }
    }
    ctx->pc = 0x137774u;
    // 0x137774: 0xc0505b4  jal         func_1416D0
    ctx->pc = 0x137774u;
    SET_GPR_U32(ctx, 31, 0x13777Cu);
    ctx->pc = 0x1416D0u;
    if (runtime->hasFunction(0x1416D0u)) {
        auto targetFn = runtime->lookupFunction(0x1416D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13777Cu; }
        if (ctx->pc != 0x13777Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001416D0_0x1416d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13777Cu; }
        if (ctx->pc != 0x13777Cu) { return; }
    }
    ctx->pc = 0x13777Cu;
label_13777c:
    // 0x13777c: 0x2664bbc4  addiu       $a0, $s3, -0x443C
    ctx->pc = 0x13777cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 4294949828));
    // 0x137780: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x137780u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x137784: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x137784u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x137788: 0x14430007  bne         $v0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x137788u;
    {
        const bool branch_taken_0x137788 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x137788) {
            ctx->pc = 0x1377A8u;
            goto label_1377a8;
        }
    }
    ctx->pc = 0x137790u;
    // 0x137790: 0xc0505ba  jal         func_1416E8
    ctx->pc = 0x137790u;
    SET_GPR_U32(ctx, 31, 0x137798u);
    ctx->pc = 0x1416E8u;
    if (runtime->hasFunction(0x1416E8u)) {
        auto targetFn = runtime->lookupFunction(0x1416E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137798u; }
        if (ctx->pc != 0x137798u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001416E8_0x1416e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137798u; }
        if (ctx->pc != 0x137798u) { return; }
    }
    ctx->pc = 0x137798u;
label_137798:
    // 0x137798: 0xc04dd84  jal         func_137610
    ctx->pc = 0x137798u;
    SET_GPR_U32(ctx, 31, 0x1377A0u);
    ctx->pc = 0x137610u;
    if (runtime->hasFunction(0x137610u)) {
        auto targetFn = runtime->lookupFunction(0x137610u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1377A0u; }
        if (ctx->pc != 0x1377A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00137610_0x137610(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1377A0u; }
        if (ctx->pc != 0x1377A0u) { return; }
    }
    ctx->pc = 0x1377A0u;
label_1377a0:
    // 0x1377a0: 0x1000ffef  b           . + 4 + (-0x11 << 2)
    ctx->pc = 0x1377A0u;
    {
        const bool branch_taken_0x1377a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1377A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1377A0u;
            // 0x1377a4: 0x26020001  addiu       $v0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1377a0) {
            ctx->pc = 0x137760u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_137760;
        }
    }
    ctx->pc = 0x1377A8u;
label_1377a8:
    // 0x1377a8: 0xc0505ba  jal         func_1416E8
    ctx->pc = 0x1377A8u;
    SET_GPR_U32(ctx, 31, 0x1377B0u);
    ctx->pc = 0x1377ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1377A8u;
            // 0x1377ac: 0xac830000  sw          $v1, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1416E8u;
    if (runtime->hasFunction(0x1416E8u)) {
        auto targetFn = runtime->lookupFunction(0x1416E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1377B0u; }
        if (ctx->pc != 0x1377B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001416E8_0x1416e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1377B0u; }
        if (ctx->pc != 0x1377B0u) { return; }
    }
    ctx->pc = 0x1377B0u;
label_1377b0:
    // 0x1377b0: 0x82320002  lb          $s2, 0x2($s1)
    ctx->pc = 0x1377b0u;
    SET_GPR_S32(ctx, 18, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
label_1377b4:
    // 0x1377b4: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1377b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1377b8: 0x5642001b  bnel        $s2, $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x1377B8u;
    {
        const bool branch_taken_0x1377b8 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 2));
        if (branch_taken_0x1377b8) {
            ctx->pc = 0x1377BCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1377B8u;
            // 0x1377bc: 0xae60bbc4  sw          $zero, -0x443C($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 4294949828), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x137828u;
            goto label_137828;
        }
    }
    ctx->pc = 0x1377C0u;
    // 0x1377c0: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x1377c0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x1377c4: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1377c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1377c8: 0x2450bb88  addiu       $s0, $v0, -0x4478
    ctx->pc = 0x1377c8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949768));
    // 0x1377cc: 0x82030001  lb          $v1, 0x1($s0)
    ctx->pc = 0x1377ccu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x1377d0: 0x14640004  bne         $v1, $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1377D0u;
    {
        const bool branch_taken_0x1377d0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        ctx->pc = 0x1377D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1377D0u;
            // 0x1377d4: 0x92020001  lbu         $v0, 0x1($s0) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1377d0) {
            ctx->pc = 0x1377E4u;
            goto label_1377e4;
        }
    }
    ctx->pc = 0x1377D8u;
    // 0x1377d8: 0xc04dd90  jal         func_137640
    ctx->pc = 0x1377D8u;
    SET_GPR_U32(ctx, 31, 0x1377E0u);
    ctx->pc = 0x1377DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1377D8u;
            // 0x1377dc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x137640u;
    if (runtime->hasFunction(0x137640u)) {
        auto targetFn = runtime->lookupFunction(0x137640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1377E0u; }
        if (ctx->pc != 0x1377E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00137640_0x137640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1377E0u; }
        if (ctx->pc != 0x1377E0u) { return; }
    }
    ctx->pc = 0x1377E0u;
label_1377e0:
    // 0x1377e0: 0x92020001  lbu         $v0, 0x1($s0)
    ctx->pc = 0x1377e0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
label_1377e4:
    // 0x1377e4: 0x21600  sll         $v0, $v0, 24
    ctx->pc = 0x1377e4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1377e8: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x1377e8u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x1377ec: 0x54520004  bnel        $v0, $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x1377ECu;
    {
        const bool branch_taken_0x1377ec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 18));
        if (branch_taken_0x1377ec) {
            ctx->pc = 0x1377F0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1377ECu;
            // 0x1377f0: 0x82230002  lb          $v1, 0x2($s1) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x137800u;
            goto label_137800;
        }
    }
    ctx->pc = 0x1377F4u;
    // 0x1377f4: 0xc04dd9a  jal         func_137668
    ctx->pc = 0x1377F4u;
    SET_GPR_U32(ctx, 31, 0x1377FCu);
    ctx->pc = 0x1377F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1377F4u;
            // 0x1377f8: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x137668u;
    if (runtime->hasFunction(0x137668u)) {
        auto targetFn = runtime->lookupFunction(0x137668u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1377FCu; }
        if (ctx->pc != 0x1377FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00137668_0x137668(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1377FCu; }
        if (ctx->pc != 0x1377FCu) { return; }
    }
    ctx->pc = 0x1377FCu;
label_1377fc:
    // 0x1377fc: 0x82230002  lb          $v1, 0x2($s1)
    ctx->pc = 0x1377fcu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
label_137800:
    // 0x137800: 0x24020009  addiu       $v0, $zero, 0x9
    ctx->pc = 0x137800u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x137804: 0x10620007  beq         $v1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x137804u;
    {
        const bool branch_taken_0x137804 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x137808u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137804u;
            // 0x137808: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x137804) {
            ctx->pc = 0x137824u;
            goto label_137824;
        }
    }
    ctx->pc = 0x13780Cu;
    // 0x13780c: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13780cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x137810: 0xa2220002  sb          $v0, 0x2($s1)
    ctx->pc = 0x137810u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 2));
    // 0x137814: 0x2463bbe4  addiu       $v1, $v1, -0x441C
    ctx->pc = 0x137814u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294949860));
    // 0x137818: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x137818u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x13781c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x13781cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x137820: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x137820u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
label_137824:
    // 0x137824: 0xae60bbc4  sw          $zero, -0x443C($s3)
    ctx->pc = 0x137824u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4294949828), GPR_U32(ctx, 0));
label_137828:
    // 0x137828: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x137828u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13782c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13782cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x137830: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x137830u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x137834: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x137834u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x137838: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x137838u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13783c: 0x3e00008  jr          $ra
    ctx->pc = 0x13783Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x137840u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13783Cu;
            // 0x137840: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137738u: goto label_137738;
            case 0x137760u: goto label_137760;
            case 0x137768u: goto label_137768;
            case 0x13777Cu: goto label_13777c;
            case 0x137798u: goto label_137798;
            case 0x1377A0u: goto label_1377a0;
            case 0x1377A8u: goto label_1377a8;
            case 0x1377B0u: goto label_1377b0;
            case 0x1377B4u: goto label_1377b4;
            case 0x1377E0u: goto label_1377e0;
            case 0x1377E4u: goto label_1377e4;
            case 0x1377FCu: goto label_1377fc;
            case 0x137800u: goto label_137800;
            case 0x137824u: goto label_137824;
            case 0x137828u: goto label_137828;
            default: break;
        }
        return;
    }
    ctx->pc = 0x137844u;
    // 0x137844: 0x0  nop
    ctx->pc = 0x137844u;
    // NOP
    // 0x137848: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x137848u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13784c: 0x3c040022  lui         $a0, 0x22
    ctx->pc = 0x13784cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)34 << 16));
    // 0x137850: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x137850u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x137854: 0x2484bb88  addiu       $a0, $a0, -0x4478
    ctx->pc = 0x137854u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949768));
    // 0x137858: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x137858u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13785c: 0x804ddce  j           func_137738
    ctx->pc = 0x13785Cu;
    ctx->pc = 0x137860u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13785Cu;
            // 0x137860: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x137738u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_137738;
    ctx->pc = 0x137864u;
    // 0x137864: 0x0  nop
    ctx->pc = 0x137864u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
