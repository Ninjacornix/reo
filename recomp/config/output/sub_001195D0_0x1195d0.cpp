#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001195D0
// Address: 0x1195d0 - 0x119948
void sub_001195D0_0x1195d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001195D0_0x1195d0");
#endif

    switch (ctx->pc) {
        case 0x119610u: goto label_119610;
        case 0x11961cu: goto label_11961c;
        case 0x119638u: goto label_119638;
        case 0x119654u: goto label_119654;
        case 0x11969cu: goto label_11969c;
        case 0x1196c0u: goto label_1196c0;
        case 0x119700u: goto label_119700;
        case 0x119768u: goto label_119768;
        case 0x1197bcu: goto label_1197bc;
        case 0x119828u: goto label_119828;
        case 0x119878u: goto label_119878;
        case 0x11989cu: goto label_11989c;
        case 0x1198c4u: goto label_1198c4;
        case 0x1198d4u: goto label_1198d4;
        case 0x1198dcu: goto label_1198dc;
        case 0x1198f0u: goto label_1198f0;
        case 0x119900u: goto label_119900;
        case 0x119910u: goto label_119910;
        case 0x119918u: goto label_119918;
        default: break;
    }

    ctx->pc = 0x1195d0u;

    // 0x1195d0: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x1195d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x1195d4: 0xffb20060  sd          $s2, 0x60($sp)
    ctx->pc = 0x1195d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 18));
    // 0x1195d8: 0xffb10050  sd          $s1, 0x50($sp)
    ctx->pc = 0x1195d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 17));
    // 0x1195dc: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x1195dcu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1195e0: 0xffb600a0  sd          $s6, 0xA0($sp)
    ctx->pc = 0x1195e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 22));
    // 0x1195e4: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1195e4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1195e8: 0xffb50090  sd          $s5, 0x90($sp)
    ctx->pc = 0x1195e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 21));
    // 0x1195ec: 0x3c160026  lui         $s6, 0x26
    ctx->pc = 0x1195ecu;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)38 << 16));
    // 0x1195f0: 0xffb40080  sd          $s4, 0x80($sp)
    ctx->pc = 0x1195f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 20));
    // 0x1195f4: 0x24150001  addiu       $s5, $zero, 0x1
    ctx->pc = 0x1195f4u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1195f8: 0xffb30070  sd          $s3, 0x70($sp)
    ctx->pc = 0x1195f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 19));
    // 0x1195fc: 0x3c140026  lui         $s4, 0x26
    ctx->pc = 0x1195fcu;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)38 << 16));
    // 0x119600: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x119600u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x119604: 0xffbf00b0  sd          $ra, 0xB0($sp)
    ctx->pc = 0x119604u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 31));
    // 0x119608: 0xc04607e  jal         func_1181F8
    ctx->pc = 0x119608u;
    SET_GPR_U32(ctx, 31, 0x119610u);
    ctx->pc = 0x11960Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119608u;
            // 0x11960c: 0x26d3ca40  addiu       $s3, $s6, -0x35C0 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 22), 4294953536));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1181F8u;
    if (runtime->hasFunction(0x1181F8u)) {
        auto targetFn = runtime->lookupFunction(0x1181F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119610u; }
        if (ctx->pc != 0x119610u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001181F8_0x1181f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119610u; }
        if (ctx->pc != 0x119610u) { return; }
    }
    ctx->pc = 0x119610u;
label_119610:
    // 0x119610: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x119610u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x119614: 0xc04619c  jal         func_118670
    ctx->pc = 0x119614u;
    SET_GPR_U32(ctx, 31, 0x11961Cu);
    ctx->pc = 0x119618u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119614u;
            // 0x119618: 0x24040005  addiu       $a0, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118670u;
    if (runtime->hasFunction(0x118670u)) {
        auto targetFn = runtime->lookupFunction(0x118670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11961Cu; }
        if (ctx->pc != 0x11961Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118670_0x118670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11961Cu; }
        if (ctx->pc != 0x11961Cu) { return; }
    }
    ctx->pc = 0x11961Cu;
label_11961c:
    // 0x11961c: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11961cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x119620: 0xae92ca08  sw          $s2, -0x35F8($s4)
    ctx->pc = 0x119620u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 4294953480), GPR_U32(ctx, 18));
    // 0x119624: 0x8c439ddc  lw          $v1, -0x6224($v0)
    ctx->pc = 0x119624u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294942172)));
    // 0x119628: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x119628u;
    {
        const bool branch_taken_0x119628 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x119628) {
            ctx->pc = 0x119638u;
            goto label_119638;
        }
    }
    ctx->pc = 0x119630u;
    // 0x119630: 0xc0461e8  jal         func_1187A0
    ctx->pc = 0x119630u;
    SET_GPR_U32(ctx, 31, 0x119638u);
    ctx->pc = 0x1187A0u;
    if (runtime->hasFunction(0x1187A0u)) {
        auto targetFn = runtime->lookupFunction(0x1187A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119638u; }
        if (ctx->pc != 0x119638u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001187A0_0x1187a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119638u; }
        if (ctx->pc != 0x119638u) { return; }
    }
    ctx->pc = 0x119638u;
label_119638:
    // 0x119638: 0x12000004  beqz        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x119638u;
    {
        const bool branch_taken_0x119638 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x119638) {
            ctx->pc = 0x11964Cu;
            goto label_11964c;
        }
    }
    ctx->pc = 0x119640u;
    // 0x119640: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x119640u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x119644: 0x54400005  bnel        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x119644u;
    {
        const bool branch_taken_0x119644 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x119644) {
            ctx->pc = 0x119648u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x119644u;
            // 0x119648: 0xae600414  sw          $zero, 0x414($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 1044), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11965Cu;
            goto label_11965c;
        }
    }
    ctx->pc = 0x11964Cu;
label_11964c:
    // 0x11964c: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x11964Cu;
    SET_GPR_U32(ctx, 31, 0x119654u);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119654u; }
        if (ctx->pc != 0x119654u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119654u; }
        if (ctx->pc != 0x119654u) { return; }
    }
    ctx->pc = 0x119654u;
label_119654:
    // 0x119654: 0x100000b1  b           . + 4 + (0xB1 << 2)
    ctx->pc = 0x119654u;
    {
        const bool branch_taken_0x119654 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x119658u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119654u;
            // 0x119658: 0x2402fff7  addiu       $v0, $zero, -0x9 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967287));
        ctx->in_delay_slot = false;
        if (branch_taken_0x119654) {
            ctx->pc = 0x11991Cu;
            goto label_11991c;
        }
    }
    ctx->pc = 0x11965Cu;
label_11965c:
    // 0x11965c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x11965cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x119660: 0x12220029  beq         $s1, $v0, . + 4 + (0x29 << 2)
    ctx->pc = 0x119660u;
    {
        const bool branch_taken_0x119660 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 2));
        ctx->pc = 0x119664u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119660u;
            // 0x119664: 0xae600418  sw          $zero, 0x418($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 1048), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x119660) {
            ctx->pc = 0x119708u;
            goto label_119708;
        }
    }
    ctx->pc = 0x119668u;
    // 0x119668: 0x2a220003  slti        $v0, $s1, 0x3
    ctx->pc = 0x119668u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x11966c: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x11966Cu;
    {
        const bool branch_taken_0x11966c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x119670u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11966Cu;
            // 0x119670: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11966c) {
            ctx->pc = 0x119684u;
            goto label_119684;
        }
    }
    ctx->pc = 0x119674u;
    // 0x119674: 0x52350007  beql        $s1, $s5, . + 4 + (0x7 << 2)
    ctx->pc = 0x119674u;
    {
        const bool branch_taken_0x119674 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 21));
        if (branch_taken_0x119674) {
            ctx->pc = 0x119678u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x119674u;
            // 0x119678: 0x3c100021  lui         $s0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x119694u;
            goto label_119694;
        }
    }
    ctx->pc = 0x11967Cu;
    // 0x11967c: 0x1000003c  b           . + 4 + (0x3C << 2)
    ctx->pc = 0x11967Cu;
    {
        const bool branch_taken_0x11967c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x119680u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11967Cu;
            // 0x119680: 0x8e020000  lw          $v0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11967c) {
            ctx->pc = 0x119770u;
            goto label_119770;
        }
    }
    ctx->pc = 0x119684u;
label_119684:
    // 0x119684: 0x1222002c  beq         $s1, $v0, . + 4 + (0x2C << 2)
    ctx->pc = 0x119684u;
    {
        const bool branch_taken_0x119684 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 2));
        ctx->pc = 0x119688u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119684u;
            // 0x119688: 0x3c040021  lui         $a0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x119684) {
            ctx->pc = 0x119738u;
            goto label_119738;
        }
    }
    ctx->pc = 0x11968Cu;
    // 0x11968c: 0x10000038  b           . + 4 + (0x38 << 2)
    ctx->pc = 0x11968Cu;
    {
        const bool branch_taken_0x11968c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x119690u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11968Cu;
            // 0x119690: 0x8e020000  lw          $v0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11968c) {
            ctx->pc = 0x119770u;
            goto label_119770;
        }
    }
    ctx->pc = 0x119694u;
label_119694:
    // 0x119694: 0xc045198  jal         func_114660
    ctx->pc = 0x119694u;
    SET_GPR_U32(ctx, 31, 0x11969Cu);
    ctx->pc = 0x119698u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119694u;
            // 0x119698: 0x8e049dec  lw          $a0, -0x6214($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294942188)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11969Cu; }
        if (ctx->pc != 0x11969Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11969Cu; }
        if (ctx->pc != 0x11969Cu) { return; }
    }
    ctx->pc = 0x11969Cu;
label_11969c:
    // 0x11969c: 0x3c050021  lui         $a1, 0x21
    ctx->pc = 0x11969cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)33 << 16));
    // 0x1196a0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1196a0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1196a4: 0x8ca39d58  lw          $v1, -0x62A8($a1)
    ctx->pc = 0x1196a4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4294942040)));
    // 0x1196a8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1196a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1196ac: 0x1462000b  bne         $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1196ACu;
    {
        const bool branch_taken_0x1196ac = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1196B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1196ACu;
            // 0x1196b0: 0x24020020  addiu       $v0, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1196ac) {
            ctx->pc = 0x1196DCu;
            goto label_1196dc;
        }
    }
    ctx->pc = 0x1196B4u;
    // 0x1196b4: 0x24a39d58  addiu       $v1, $a1, -0x62A8
    ctx->pc = 0x1196b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), 4294942040));
    // 0x1196b8: 0x2405ffff  addiu       $a1, $zero, -0x1
    ctx->pc = 0x1196b8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1196bc: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1196bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
label_1196c0:
    // 0x1196c0: 0x28820020  slti        $v0, $a0, 0x20
    ctx->pc = 0x1196c0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x1196c4: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1196C4u;
    {
        const bool branch_taken_0x1196c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1196C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1196C4u;
            // 0x1196c8: 0x24630004  addiu       $v1, $v1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1196c4) {
            ctx->pc = 0x1196D8u;
            goto label_1196d8;
        }
    }
    ctx->pc = 0x1196CCu;
    // 0x1196cc: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1196ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1196d0: 0x5045fffb  beql        $v0, $a1, . + 4 + (-0x5 << 2)
    ctx->pc = 0x1196D0u;
    {
        const bool branch_taken_0x1196d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 5));
        if (branch_taken_0x1196d0) {
            ctx->pc = 0x1196D4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1196D0u;
            // 0x1196d4: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1196C0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1196c0;
        }
    }
    ctx->pc = 0x1196D8u;
label_1196d8:
    // 0x1196d8: 0x24020020  addiu       $v0, $zero, 0x20
    ctx->pc = 0x1196d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
label_1196dc:
    // 0x1196dc: 0x14820004  bne         $a0, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1196DCu;
    {
        const bool branch_taken_0x1196dc = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        ctx->pc = 0x1196E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1196DCu;
            // 0x1196e0: 0x8e83ca08  lw          $v1, -0x35F8($s4) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 4294953480)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1196dc) {
            ctx->pc = 0x1196F0u;
            goto label_1196f0;
        }
    }
    ctx->pc = 0x1196E4u;
    // 0x1196e4: 0x8e82ca08  lw          $v0, -0x35F8($s4)
    ctx->pc = 0x1196e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 4294953480)));
    // 0x1196e8: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1196E8u;
    {
        const bool branch_taken_0x1196e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1196ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1196E8u;
            // 0x1196ec: 0xac400000  sw          $zero, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1196e8) {
            ctx->pc = 0x1196F8u;
            goto label_1196f8;
        }
    }
    ctx->pc = 0x1196F0u;
label_1196f0:
    // 0x1196f0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1196f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1196f4: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1196f4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
label_1196f8:
    // 0x1196f8: 0xc045190  jal         func_114640
    ctx->pc = 0x1196F8u;
    SET_GPR_U32(ctx, 31, 0x119700u);
    ctx->pc = 0x1196FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1196F8u;
            // 0x1196fc: 0x8e049dec  lw          $a0, -0x6214($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294942188)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119700u; }
        if (ctx->pc != 0x119700u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119700u; }
        if (ctx->pc != 0x119700u) { return; }
    }
    ctx->pc = 0x119700u;
label_119700:
    // 0x119700: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x119700u;
    {
        const bool branch_taken_0x119700 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x119700) {
            ctx->pc = 0x119760u;
            goto label_119760;
        }
    }
    ctx->pc = 0x119708u;
label_119708:
    // 0x119708: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x119708u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x11970c: 0x24050440  addiu       $a1, $zero, 0x440
    ctx->pc = 0x11970cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1088));
    // 0x119710: 0x8c829dd8  lw          $v0, -0x6228($a0)
    ctx->pc = 0x119710u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4294942168)));
    // 0x119714: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x119714u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x119718: 0x2463d6d0  addiu       $v1, $v1, -0x2930
    ctx->pc = 0x119718u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294956752));
    // 0x11971c: 0x3c042000  lui         $a0, 0x2000
    ctx->pc = 0x11971cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)8192 << 16));
    // 0x119720: 0x451018  mult        $v0, $v0, $a1
    ctx->pc = 0x119720u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 5); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x119724: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x119724u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x119728: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x119728u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x11972c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x11972cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x119730: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x119730u;
    {
        const bool branch_taken_0x119730 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x119734u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119730u;
            // 0x119734: 0xae430000  sw          $v1, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x119730) {
            ctx->pc = 0x119760u;
            goto label_119760;
        }
    }
    ctx->pc = 0x119738u;
label_119738:
    // 0x119738: 0x24050440  addiu       $a1, $zero, 0x440
    ctx->pc = 0x119738u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1088));
    // 0x11973c: 0x8c829dd8  lw          $v0, -0x6228($a0)
    ctx->pc = 0x11973cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4294942168)));
    // 0x119740: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x119740u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x119744: 0x2463d6d0  addiu       $v1, $v1, -0x2930
    ctx->pc = 0x119744u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294956752));
    // 0x119748: 0x3c042000  lui         $a0, 0x2000
    ctx->pc = 0x119748u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)8192 << 16));
    // 0x11974c: 0x451018  mult        $v0, $v0, $a1
    ctx->pc = 0x11974cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 5); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x119750: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x119750u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x119754: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x119754u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x119758: 0xdc430000  ld          $v1, 0x0($v0)
    ctx->pc = 0x119758u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x11975c: 0xfe430000  sd          $v1, 0x0($s2)
    ctx->pc = 0x11975cu;
    WRITE64(ADD32(GPR_U32(ctx, 18), 0), GPR_U64(ctx, 3));
label_119760:
    // 0x119760: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x119760u;
    SET_GPR_U32(ctx, 31, 0x119768u);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119768u; }
        if (ctx->pc != 0x119768u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119768u; }
        if (ctx->pc != 0x119768u) { return; }
    }
    ctx->pc = 0x119768u;
label_119768:
    // 0x119768: 0x1000006c  b           . + 4 + (0x6C << 2)
    ctx->pc = 0x119768u;
    {
        const bool branch_taken_0x119768 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11976Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119768u;
            // 0x11976c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x119768) {
            ctx->pc = 0x11991Cu;
            goto label_11991c;
        }
    }
    ctx->pc = 0x119770u;
label_119770:
    // 0x119770: 0xae710010  sw          $s1, 0x10($s3)
    ctx->pc = 0x119770u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 17));
    // 0x119774: 0x16400006  bnez        $s2, . + 4 + (0x6 << 2)
    ctx->pc = 0x119774u;
    {
        const bool branch_taken_0x119774 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        ctx->pc = 0x119778u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119774u;
            // 0x119778: 0xae62000c  sw          $v0, 0xC($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 12), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x119774) {
            ctx->pc = 0x119790u;
            goto label_119790;
        }
    }
    ctx->pc = 0x11977Cu;
    // 0x11977c: 0xae60041c  sw          $zero, 0x41C($s3)
    ctx->pc = 0x11977cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 1052), GPR_U32(ctx, 0));
    // 0x119780: 0x27b20030  addiu       $s2, $sp, 0x30
    ctx->pc = 0x119780u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x119784: 0x3c150026  lui         $s5, 0x26
    ctx->pc = 0x119784u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)38 << 16));
    // 0x119788: 0x10000034  b           . + 4 + (0x34 << 2)
    ctx->pc = 0x119788u;
    {
        const bool branch_taken_0x119788 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11978Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119788u;
            // 0x11978c: 0x3c110026  lui         $s1, 0x26 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)38 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x119788) {
            ctx->pc = 0x11985Cu;
            goto label_11985c;
        }
    }
    ctx->pc = 0x119790u;
label_119790:
    // 0x119790: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x119790u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x119794: 0x26640014  addiu       $a0, $s3, 0x14
    ctx->pc = 0x119794u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 20));
    // 0x119798: 0x24030400  addiu       $v1, $zero, 0x400
    ctx->pc = 0x119798u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
    // 0x11979c: 0xc41025  or          $v0, $a2, $a0
    ctx->pc = 0x11979cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) | GPR_U64(ctx, 4));
    // 0x1197a0: 0x30420007  andi        $v0, $v0, 0x7
    ctx->pc = 0x1197a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)7);
    // 0x1197a4: 0x1040001c  beqz        $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x1197A4u;
    {
        const bool branch_taken_0x1197a4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1197A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1197A4u;
            // 0x1197a8: 0xae63041c  sw          $v1, 0x41C($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 1052), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1197a4) {
            ctx->pc = 0x119818u;
            goto label_119818;
        }
    }
    ctx->pc = 0x1197ACu;
    // 0x1197ac: 0x24c20400  addiu       $v0, $a2, 0x400
    ctx->pc = 0x1197acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 1024));
    // 0x1197b0: 0x27b20030  addiu       $s2, $sp, 0x30
    ctx->pc = 0x1197b0u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1197b4: 0x3c150026  lui         $s5, 0x26
    ctx->pc = 0x1197b4u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)38 << 16));
    // 0x1197b8: 0x3c110026  lui         $s1, 0x26
    ctx->pc = 0x1197b8u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)38 << 16));
label_1197bc:
    // 0x1197bc: 0x68c30007  ldl         $v1, 0x7($a2)
    ctx->pc = 0x1197bcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem << shift)); }
    // 0x1197c0: 0x6cc30000  ldr         $v1, 0x0($a2)
    ctx->pc = 0x1197c0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & keepMask) | (mem >> shift)); }
    // 0x1197c4: 0x68c5000f  ldl         $a1, 0xF($a2)
    ctx->pc = 0x1197c4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x1197c8: 0x6cc50008  ldr         $a1, 0x8($a2)
    ctx->pc = 0x1197c8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x1197cc: 0x68c70017  ldl         $a3, 0x17($a2)
    ctx->pc = 0x1197ccu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem << shift)); }
    // 0x1197d0: 0x6cc70010  ldr         $a3, 0x10($a2)
    ctx->pc = 0x1197d0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem >> shift)); }
    // 0x1197d4: 0x68c8001f  ldl         $t0, 0x1F($a2)
    ctx->pc = 0x1197d4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x1197d8: 0x6cc80018  ldr         $t0, 0x18($a2)
    ctx->pc = 0x1197d8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x1197dc: 0xb0830007  sdl         $v1, 0x7($a0)
    ctx->pc = 0x1197dcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1197e0: 0xb4830000  sdr         $v1, 0x0($a0)
    ctx->pc = 0x1197e0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 3); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1197e4: 0xb085000f  sdl         $a1, 0xF($a0)
    ctx->pc = 0x1197e4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1197e8: 0xb4850008  sdr         $a1, 0x8($a0)
    ctx->pc = 0x1197e8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1197ec: 0xb0870017  sdl         $a3, 0x17($a0)
    ctx->pc = 0x1197ecu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1197f0: 0xb4870010  sdr         $a3, 0x10($a0)
    ctx->pc = 0x1197f0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1197f4: 0xb088001f  sdl         $t0, 0x1F($a0)
    ctx->pc = 0x1197f4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1197f8: 0xb4880018  sdr         $t0, 0x18($a0)
    ctx->pc = 0x1197f8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1197fc: 0x24c60020  addiu       $a2, $a2, 0x20
    ctx->pc = 0x1197fcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 32));
    // 0x119800: 0x24840020  addiu       $a0, $a0, 0x20
    ctx->pc = 0x119800u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
    // 0x119804: 0x0  nop
    ctx->pc = 0x119804u;
    // NOP
    // 0x119808: 0x14c2ffec  bne         $a2, $v0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x119808u;
    {
        const bool branch_taken_0x119808 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 2));
        if (branch_taken_0x119808) {
            ctx->pc = 0x1197BCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1197bc;
        }
    }
    ctx->pc = 0x119810u;
    // 0x119810: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x119810u;
    {
        const bool branch_taken_0x119810 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x119814u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119810u;
            // 0x119814: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x119810) {
            ctx->pc = 0x119860u;
            goto label_119860;
        }
    }
    ctx->pc = 0x119818u;
label_119818:
    // 0x119818: 0x24c20400  addiu       $v0, $a2, 0x400
    ctx->pc = 0x119818u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 1024));
    // 0x11981c: 0x27b20030  addiu       $s2, $sp, 0x30
    ctx->pc = 0x11981cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x119820: 0x3c150026  lui         $s5, 0x26
    ctx->pc = 0x119820u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)38 << 16));
    // 0x119824: 0x3c110026  lui         $s1, 0x26
    ctx->pc = 0x119824u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)38 << 16));
label_119828:
    // 0x119828: 0xdcc30000  ld          $v1, 0x0($a2)
    ctx->pc = 0x119828u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x11982c: 0xdcc50008  ld          $a1, 0x8($a2)
    ctx->pc = 0x11982cu;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 6), 8)));
    // 0x119830: 0xdcc70010  ld          $a3, 0x10($a2)
    ctx->pc = 0x119830u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 6), 16)));
    // 0x119834: 0xdcc80018  ld          $t0, 0x18($a2)
    ctx->pc = 0x119834u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 6), 24)));
    // 0x119838: 0xfc830000  sd          $v1, 0x0($a0)
    ctx->pc = 0x119838u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 0), GPR_U64(ctx, 3));
    // 0x11983c: 0xfc850008  sd          $a1, 0x8($a0)
    ctx->pc = 0x11983cu;
    WRITE64(ADD32(GPR_U32(ctx, 4), 8), GPR_U64(ctx, 5));
    // 0x119840: 0xfc870010  sd          $a3, 0x10($a0)
    ctx->pc = 0x119840u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 16), GPR_U64(ctx, 7));
    // 0x119844: 0xfc880018  sd          $t0, 0x18($a0)
    ctx->pc = 0x119844u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 24), GPR_U64(ctx, 8));
    // 0x119848: 0x24c60020  addiu       $a2, $a2, 0x20
    ctx->pc = 0x119848u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 32));
    // 0x11984c: 0x24840020  addiu       $a0, $a0, 0x20
    ctx->pc = 0x11984cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
    // 0x119850: 0x0  nop
    ctx->pc = 0x119850u;
    // NOP
    // 0x119854: 0x14c2fff4  bne         $a2, $v0, . + 4 + (-0xC << 2)
    ctx->pc = 0x119854u;
    {
        const bool branch_taken_0x119854 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 2));
        if (branch_taken_0x119854) {
            ctx->pc = 0x119828u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_119828;
        }
    }
    ctx->pc = 0x11985Cu;
label_11985c:
    // 0x11985c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x11985cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_119860:
    // 0x119860: 0xafa00018  sw          $zero, 0x18($sp)
    ctx->pc = 0x119860u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
    // 0x119864: 0xafa20014  sw          $v0, 0x14($sp)
    ctx->pc = 0x119864u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x119868: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x119868u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x11986c: 0xafa00024  sw          $zero, 0x24($sp)
    ctx->pc = 0x11986cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 0));
    // 0x119870: 0xc045188  jal         func_114620
    ctx->pc = 0x119870u;
    SET_GPR_U32(ctx, 31, 0x119878u);
    ctx->pc = 0x119874u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119870u;
            // 0x119874: 0x2634d680  addiu       $s4, $s1, -0x2980 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 17), 4294956672));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119878u; }
        if (ctx->pc != 0x119878u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119878u; }
        if (ctx->pc != 0x119878u) { return; }
    }
    ctx->pc = 0x119878u;
label_119878:
    // 0x119878: 0x26d0ca40  addiu       $s0, $s6, -0x35C0
    ctx->pc = 0x119878u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 22), 4294953536));
    // 0x11987c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x11987cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x119880: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x119880u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x119884: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x119884u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x119888: 0xae720004  sw          $s2, 0x4($s3)
    ctx->pc = 0x119888u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 18));
    // 0x11988c: 0xae620008  sw          $v0, 0x8($s3)
    ctx->pc = 0x11988cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 8), GPR_U32(ctx, 2));
    // 0x119890: 0x24050420  addiu       $a1, $zero, 0x420
    ctx->pc = 0x119890u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1056));
    // 0x119894: 0xc045bf4  jal         func_116FD0
    ctx->pc = 0x119894u;
    SET_GPR_U32(ctx, 31, 0x11989Cu);
    ctx->pc = 0x119898u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119894u;
            // 0x119898: 0xae710000  sw          $s1, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116FD0u;
    if (runtime->hasFunction(0x116FD0u)) {
        auto targetFn = runtime->lookupFunction(0x116FD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11989Cu; }
        if (ctx->pc != 0x11989Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116FD0_0x116fd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11989Cu; }
        if (ctx->pc != 0x11989Cu) { return; }
    }
    ctx->pc = 0x11989Cu;
label_11989c:
    // 0x11989c: 0x26a4e140  addiu       $a0, $s5, -0x1EC0
    ctx->pc = 0x11989cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 21), 4294959424));
    // 0x1198a0: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x1198a0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1198a4: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x1198a4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x1198a8: 0x24050005  addiu       $a1, $zero, 0x5
    ctx->pc = 0x1198a8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1198ac: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1198acu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1198b0: 0x24080420  addiu       $t0, $zero, 0x420
    ctx->pc = 0x1198b0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1056));
    // 0x1198b4: 0x280482d  daddu       $t1, $s4, $zero
    ctx->pc = 0x1198b4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1198b8: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x1198b8u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1198bc: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x1198BCu;
    SET_GPR_U32(ctx, 31, 0x1198C4u);
    ctx->pc = 0x1198C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1198BCu;
            // 0x1198c0: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1198C4u; }
        if (ctx->pc != 0x1198C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1198C4u; }
        if (ctx->pc != 0x1198C4u) { return; }
    }
    ctx->pc = 0x1198C4u;
label_1198c4:
    // 0x1198c4: 0x4410007  bgez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1198C4u;
    {
        const bool branch_taken_0x1198c4 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1198C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1198C4u;
            // 0x1198c8: 0x3c022000  lui         $v0, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1198c4) {
            ctx->pc = 0x1198E4u;
            goto label_1198e4;
        }
    }
    ctx->pc = 0x1198CCu;
    // 0x1198cc: 0xc04518c  jal         func_114630
    ctx->pc = 0x1198CCu;
    SET_GPR_U32(ctx, 31, 0x1198D4u);
    ctx->pc = 0x1198D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1198CCu;
            // 0x1198d0: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1198D4u; }
        if (ctx->pc != 0x1198D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1198D4u; }
        if (ctx->pc != 0x1198D4u) { return; }
    }
    ctx->pc = 0x1198D4u;
label_1198d4:
    // 0x1198d4: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x1198D4u;
    SET_GPR_U32(ctx, 31, 0x1198DCu);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1198DCu; }
        if (ctx->pc != 0x1198DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1198DCu; }
        if (ctx->pc != 0x1198DCu) { return; }
    }
    ctx->pc = 0x1198DCu;
label_1198dc:
    // 0x1198dc: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1198DCu;
    {
        const bool branch_taken_0x1198dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1198E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1198DCu;
            // 0x1198e0: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1198dc) {
            ctx->pc = 0x11991Cu;
            goto label_11991c;
        }
    }
    ctx->pc = 0x1198E4u;
label_1198e4:
    // 0x1198e4: 0x2821025  or          $v0, $s4, $v0
    ctx->pc = 0x1198e4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) | GPR_U64(ctx, 2));
    // 0x1198e8: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x1198E8u;
    SET_GPR_U32(ctx, 31, 0x1198F0u);
    ctx->pc = 0x1198ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1198E8u;
            // 0x1198ec: 0x8c500000  lw          $s0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1198F0u; }
        if (ctx->pc != 0x1198F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1198F0u; }
        if (ctx->pc != 0x1198F0u) { return; }
    }
    ctx->pc = 0x1198F0u;
label_1198f0:
    // 0x1198f0: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1198F0u;
    {
        const bool branch_taken_0x1198f0 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x1198f0) {
            ctx->pc = 0x119908u;
            goto label_119908;
        }
    }
    ctx->pc = 0x1198F8u;
    // 0x1198f8: 0xc04518c  jal         func_114630
    ctx->pc = 0x1198F8u;
    SET_GPR_U32(ctx, 31, 0x119900u);
    ctx->pc = 0x1198FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1198F8u;
            // 0x1198fc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119900u; }
        if (ctx->pc != 0x119900u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119900u; }
        if (ctx->pc != 0x119900u) { return; }
    }
    ctx->pc = 0x119900u;
label_119900:
    // 0x119900: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x119900u;
    {
        const bool branch_taken_0x119900 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x119904u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119900u;
            // 0x119904: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x119900) {
            ctx->pc = 0x11991Cu;
            goto label_11991c;
        }
    }
    ctx->pc = 0x119908u;
label_119908:
    // 0x119908: 0xc045198  jal         func_114660
    ctx->pc = 0x119908u;
    SET_GPR_U32(ctx, 31, 0x119910u);
    ctx->pc = 0x11990Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119908u;
            // 0x11990c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119910u; }
        if (ctx->pc != 0x119910u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119910u; }
        if (ctx->pc != 0x119910u) { return; }
    }
    ctx->pc = 0x119910u;
label_119910:
    // 0x119910: 0xc04518c  jal         func_114630
    ctx->pc = 0x119910u;
    SET_GPR_U32(ctx, 31, 0x119918u);
    ctx->pc = 0x119914u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119910u;
            // 0x119914: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119918u; }
        if (ctx->pc != 0x119918u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119918u; }
        if (ctx->pc != 0x119918u) { return; }
    }
    ctx->pc = 0x119918u;
label_119918:
    // 0x119918: 0x8fa20030  lw          $v0, 0x30($sp)
    ctx->pc = 0x119918u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_11991c:
    // 0x11991c: 0xdfbf00b0  ld          $ra, 0xB0($sp)
    ctx->pc = 0x11991cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x119920: 0xdfb600a0  ld          $s6, 0xA0($sp)
    ctx->pc = 0x119920u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x119924: 0xdfb50090  ld          $s5, 0x90($sp)
    ctx->pc = 0x119924u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x119928: 0xdfb40080  ld          $s4, 0x80($sp)
    ctx->pc = 0x119928u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x11992c: 0xdfb30070  ld          $s3, 0x70($sp)
    ctx->pc = 0x11992cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x119930: 0xdfb20060  ld          $s2, 0x60($sp)
    ctx->pc = 0x119930u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x119934: 0xdfb10050  ld          $s1, 0x50($sp)
    ctx->pc = 0x119934u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x119938: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x119938u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11993c: 0x3e00008  jr          $ra
    ctx->pc = 0x11993Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x119940u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11993Cu;
            // 0x119940: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x119610u: goto label_119610;
            case 0x11961Cu: goto label_11961c;
            case 0x119638u: goto label_119638;
            case 0x11964Cu: goto label_11964c;
            case 0x119654u: goto label_119654;
            case 0x11965Cu: goto label_11965c;
            case 0x119684u: goto label_119684;
            case 0x119694u: goto label_119694;
            case 0x11969Cu: goto label_11969c;
            case 0x1196C0u: goto label_1196c0;
            case 0x1196D8u: goto label_1196d8;
            case 0x1196DCu: goto label_1196dc;
            case 0x1196F0u: goto label_1196f0;
            case 0x1196F8u: goto label_1196f8;
            case 0x119700u: goto label_119700;
            case 0x119708u: goto label_119708;
            case 0x119738u: goto label_119738;
            case 0x119760u: goto label_119760;
            case 0x119768u: goto label_119768;
            case 0x119770u: goto label_119770;
            case 0x119790u: goto label_119790;
            case 0x1197BCu: goto label_1197bc;
            case 0x119818u: goto label_119818;
            case 0x119828u: goto label_119828;
            case 0x11985Cu: goto label_11985c;
            case 0x119860u: goto label_119860;
            case 0x119878u: goto label_119878;
            case 0x11989Cu: goto label_11989c;
            case 0x1198C4u: goto label_1198c4;
            case 0x1198D4u: goto label_1198d4;
            case 0x1198DCu: goto label_1198dc;
            case 0x1198E4u: goto label_1198e4;
            case 0x1198F0u: goto label_1198f0;
            case 0x119900u: goto label_119900;
            case 0x119908u: goto label_119908;
            case 0x119910u: goto label_119910;
            case 0x119918u: goto label_119918;
            case 0x11991Cu: goto label_11991c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x119944u;
    // 0x119944: 0x0  nop
    ctx->pc = 0x119944u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
