#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00119310
// Address: 0x119310 - 0x1195d0
void sub_00119310_0x119310(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00119310_0x119310");
#endif

    switch (ctx->pc) {
        case 0x119350u: goto label_119350;
        case 0x11935cu: goto label_11935c;
        case 0x119374u: goto label_119374;
        case 0x119398u: goto label_119398;
        case 0x1193d8u: goto label_1193d8;
        case 0x119404u: goto label_119404;
        case 0x119440u: goto label_119440;
        case 0x11947cu: goto label_11947c;
        case 0x1194c8u: goto label_1194c8;
        case 0x1194e0u: goto label_1194e0;
        case 0x119530u: goto label_119530;
        case 0x119540u: goto label_119540;
        case 0x119548u: goto label_119548;
        case 0x11955cu: goto label_11955c;
        case 0x11956cu: goto label_11956c;
        case 0x119584u: goto label_119584;
        case 0x119594u: goto label_119594;
        case 0x11959cu: goto label_11959c;
        default: break;
    }

    ctx->pc = 0x119310u;

    // 0x119310: 0x27bdff20  addiu       $sp, $sp, -0xE0
    ctx->pc = 0x119310u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967072));
    // 0x119314: 0xffb50090  sd          $s5, 0x90($sp)
    ctx->pc = 0x119314u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 21));
    // 0x119318: 0xffb10050  sd          $s1, 0x50($sp)
    ctx->pc = 0x119318u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 17));
    // 0x11931c: 0xc0a82d  daddu       $s5, $a2, $zero
    ctx->pc = 0x11931cu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x119320: 0xffb700b0  sd          $s7, 0xB0($sp)
    ctx->pc = 0x119320u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 23));
    // 0x119324: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x119324u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x119328: 0xffb20060  sd          $s2, 0x60($sp)
    ctx->pc = 0x119328u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 18));
    // 0x11932c: 0x3c170026  lui         $s7, 0x26
    ctx->pc = 0x11932cu;
    SET_GPR_S32(ctx, 23, (int32_t)((uint32_t)38 << 16));
    // 0x119330: 0xffb00040  sd          $s0, 0x40($sp)
    ctx->pc = 0x119330u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x119334: 0x26f2ca40  addiu       $s2, $s7, -0x35C0
    ctx->pc = 0x119334u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 23), 4294953536));
    // 0x119338: 0xffbf00d0  sd          $ra, 0xD0($sp)
    ctx->pc = 0x119338u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 208), GPR_U64(ctx, 31));
    // 0x11933c: 0xffbe00c0  sd          $fp, 0xC0($sp)
    ctx->pc = 0x11933cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 192), GPR_U64(ctx, 30));
    // 0x119340: 0xffb600a0  sd          $s6, 0xA0($sp)
    ctx->pc = 0x119340u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 22));
    // 0x119344: 0xffb40080  sd          $s4, 0x80($sp)
    ctx->pc = 0x119344u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 20));
    // 0x119348: 0xc04607e  jal         func_1181F8
    ctx->pc = 0x119348u;
    SET_GPR_U32(ctx, 31, 0x119350u);
    ctx->pc = 0x11934Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119348u;
            // 0x11934c: 0xffb30070  sd          $s3, 0x70($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 19));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1181F8u;
    if (runtime->hasFunction(0x1181F8u)) {
        auto targetFn = runtime->lookupFunction(0x1181F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119350u; }
        if (ctx->pc != 0x119350u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001181F8_0x1181f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119350u; }
        if (ctx->pc != 0x119350u) { return; }
    }
    ctx->pc = 0x119350u;
label_119350:
    // 0x119350: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x119350u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x119354: 0xc04619c  jal         func_118670
    ctx->pc = 0x119354u;
    SET_GPR_U32(ctx, 31, 0x11935Cu);
    ctx->pc = 0x119358u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119354u;
            // 0x119358: 0x24040003  addiu       $a0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x118670u;
    if (runtime->hasFunction(0x118670u)) {
        auto targetFn = runtime->lookupFunction(0x118670u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11935Cu; }
        if (ctx->pc != 0x11935Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00118670_0x118670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11935Cu; }
        if (ctx->pc != 0x11935Cu) { return; }
    }
    ctx->pc = 0x11935Cu;
label_11935c:
    // 0x11935c: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x11935cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x119360: 0x8c629ddc  lw          $v0, -0x6224($v1)
    ctx->pc = 0x119360u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294942172)));
    // 0x119364: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x119364u;
    {
        const bool branch_taken_0x119364 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x119364) {
            ctx->pc = 0x11937Cu;
            goto label_11937c;
        }
    }
    ctx->pc = 0x11936Cu;
    // 0x11936c: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x11936Cu;
    SET_GPR_U32(ctx, 31, 0x119374u);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119374u; }
        if (ctx->pc != 0x119374u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119374u; }
        if (ctx->pc != 0x119374u) { return; }
    }
    ctx->pc = 0x119374u;
label_119374:
    // 0x119374: 0x1000008a  b           . + 4 + (0x8A << 2)
    ctx->pc = 0x119374u;
    {
        const bool branch_taken_0x119374 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x119378u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119374u;
            // 0x119378: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x119374) {
            ctx->pc = 0x1195A0u;
            goto label_1195a0;
        }
    }
    ctx->pc = 0x11937Cu;
label_11937c:
    // 0x11937c: 0x12000004  beqz        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x11937Cu;
    {
        const bool branch_taken_0x11937c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x11937c) {
            ctx->pc = 0x119390u;
            goto label_119390;
        }
    }
    ctx->pc = 0x119384u;
    // 0x119384: 0x8e160004  lw          $s6, 0x4($s0)
    ctx->pc = 0x119384u;
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x119388: 0x56c00005  bnel        $s6, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x119388u;
    {
        const bool branch_taken_0x119388 = (GPR_U64(ctx, 22) != GPR_U64(ctx, 0));
        if (branch_taken_0x119388) {
            ctx->pc = 0x11938Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x119388u;
            // 0x11938c: 0x8e030000  lw          $v1, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1193A0u;
            goto label_1193a0;
        }
    }
    ctx->pc = 0x119390u;
label_119390:
    // 0x119390: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x119390u;
    SET_GPR_U32(ctx, 31, 0x119398u);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119398u; }
        if (ctx->pc != 0x119398u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119398u; }
        if (ctx->pc != 0x119398u) { return; }
    }
    ctx->pc = 0x119398u;
label_119398:
    // 0x119398: 0x10000081  b           . + 4 + (0x81 << 2)
    ctx->pc = 0x119398u;
    {
        const bool branch_taken_0x119398 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11939Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119398u;
            // 0x11939c: 0x2402fff7  addiu       $v0, $zero, -0x9 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967287));
        ctx->in_delay_slot = false;
        if (branch_taken_0x119398) {
            ctx->pc = 0x1195A0u;
            goto label_1195a0;
        }
    }
    ctx->pc = 0x1193A0u;
label_1193a0:
    // 0x1193a0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1193a0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1193a4: 0x2442df40  addiu       $v0, $v0, -0x20C0
    ctx->pc = 0x1193a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294958912));
    // 0x1193a8: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1193a8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1193ac: 0xae43000c  sw          $v1, 0xC($s2)
    ctx->pc = 0x1193acu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 12), GPR_U32(ctx, 3));
    // 0x1193b0: 0x2021023  subu        $v0, $s0, $v0
    ctx->pc = 0x1193b0u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1193b4: 0xafa40014  sw          $a0, 0x14($sp)
    ctx->pc = 0x1193b4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 4));
    // 0x1193b8: 0x21103  sra         $v0, $v0, 4
    ctx->pc = 0x1193b8u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 4));
    // 0x1193bc: 0xae42002c  sw          $v0, 0x2C($s2)
    ctx->pc = 0x1193bcu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 44), GPR_U32(ctx, 2));
    // 0x1193c0: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x1193c0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1193c4: 0xae550014  sw          $s5, 0x14($s2)
    ctx->pc = 0x1193c4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 20), GPR_U32(ctx, 21));
    // 0x1193c8: 0xae510010  sw          $s1, 0x10($s2)
    ctx->pc = 0x1193c8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 17));
    // 0x1193cc: 0xafa00018  sw          $zero, 0x18($sp)
    ctx->pc = 0x1193ccu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
    // 0x1193d0: 0xc045188  jal         func_114620
    ctx->pc = 0x1193D0u;
    SET_GPR_U32(ctx, 31, 0x1193D8u);
    ctx->pc = 0x1193D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1193D0u;
            // 0x1193d4: 0xafa00024  sw          $zero, 0x24($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1193D8u; }
        if (ctx->pc != 0x1193D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1193D8u; }
        if (ctx->pc != 0x1193D8u) { return; }
    }
    ctx->pc = 0x1193D8u;
label_1193d8:
    // 0x1193d8: 0x40a02d  daddu       $s4, $v0, $zero
    ctx->pc = 0x1193d8u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1193dc: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1193dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1193e0: 0x27a20030  addiu       $v0, $sp, 0x30
    ctx->pc = 0x1193e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1193e4: 0xae430008  sw          $v1, 0x8($s2)
    ctx->pc = 0x1193e4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 8), GPR_U32(ctx, 3));
    // 0x1193e8: 0xae420004  sw          $v0, 0x4($s2)
    ctx->pc = 0x1193e8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 2));
    // 0x1193ec: 0x32c28000  andi        $v0, $s6, 0x8000
    ctx->pc = 0x1193ecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 22) & (uint64_t)(uint16_t)32768);
    // 0x1193f0: 0x10400024  beqz        $v0, . + 4 + (0x24 << 2)
    ctx->pc = 0x1193F0u;
    {
        const bool branch_taken_0x1193f0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1193F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1193F0u;
            // 0x1193f4: 0xaef4ca40  sw          $s4, -0x35C0($s7) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 23), 4294953536), GPR_U32(ctx, 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1193f0) {
            ctx->pc = 0x119484u;
            goto label_119484;
        }
    }
    ctx->pc = 0x1193F8u;
    // 0x1193f8: 0x3c130021  lui         $s3, 0x21
    ctx->pc = 0x1193f8u;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)33 << 16));
    // 0x1193fc: 0xc045198  jal         func_114660
    ctx->pc = 0x1193FCu;
    SET_GPR_U32(ctx, 31, 0x119404u);
    ctx->pc = 0x119400u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1193FCu;
            // 0x119400: 0x8e649dec  lw          $a0, -0x6214($s3) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 4294942188)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119404u; }
        if (ctx->pc != 0x119404u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119404u; }
        if (ctx->pc != 0x119404u) { return; }
    }
    ctx->pc = 0x119404u;
label_119404:
    // 0x119404: 0x3c070021  lui         $a3, 0x21
    ctx->pc = 0x119404u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)33 << 16));
    // 0x119408: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x119408u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11940c: 0x8ce39d58  lw          $v1, -0x62A8($a3)
    ctx->pc = 0x11940cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 4294942040)));
    // 0x119410: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x119410u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x119414: 0x14620008  bne         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x119414u;
    {
        const bool branch_taken_0x119414 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x119418u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119414u;
            // 0x119418: 0x3230000f  andi        $s0, $s1, 0xF (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)15);
        ctx->in_delay_slot = false;
        if (branch_taken_0x119414) {
            ctx->pc = 0x119438u;
            goto label_119438;
        }
    }
    ctx->pc = 0x11941Cu;
    // 0x11941c: 0x8ee3ca40  lw          $v1, -0x35C0($s7)
    ctx->pc = 0x11941cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 23), 4294953536)));
    // 0x119420: 0x3c1e0026  lui         $fp, 0x26
    ctx->pc = 0x119420u;
    SET_GPR_S32(ctx, 30, (int32_t)((uint32_t)38 << 16));
    // 0x119424: 0x31023  negu        $v0, $v1
    ctx->pc = 0x119424u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 3)));
    // 0x119428: 0xace39d58  sw          $v1, -0x62A8($a3)
    ctx->pc = 0x119428u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 4294942040), GPR_U32(ctx, 3));
    // 0x11942c: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x11942Cu;
    {
        const bool branch_taken_0x11942c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x119430u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11942Cu;
            // 0x119430: 0xaee2ca40  sw          $v0, -0x35C0($s7) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 23), 4294953536), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11942c) {
            ctx->pc = 0x119474u;
            goto label_119474;
        }
    }
    ctx->pc = 0x119434u;
    // 0x119434: 0x0  nop
    ctx->pc = 0x119434u;
    // NOP
label_119438:
    // 0x119438: 0x3c1e0026  lui         $fp, 0x26
    ctx->pc = 0x119438u;
    SET_GPR_S32(ctx, 30, (int32_t)((uint32_t)38 << 16));
    // 0x11943c: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x11943cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
label_119440:
    // 0x119440: 0x28c20020  slti        $v0, $a2, 0x20
    ctx->pc = 0x119440u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x119444: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x119444u;
    {
        const bool branch_taken_0x119444 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x119448u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119444u;
            // 0x119448: 0x61080  sll         $v0, $a2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x119444) {
            ctx->pc = 0x119474u;
            goto label_119474;
        }
    }
    ctx->pc = 0x11944Cu;
    // 0x11944c: 0x24e39d58  addiu       $v1, $a3, -0x62A8
    ctx->pc = 0x11944cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), 4294942040));
    // 0x119450: 0x432821  addu        $a1, $v0, $v1
    ctx->pc = 0x119450u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x119454: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x119454u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x119458: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x119458u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x11945c: 0x1444fff8  bne         $v0, $a0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x11945Cu;
    {
        const bool branch_taken_0x11945c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        ctx->pc = 0x119460u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11945Cu;
            // 0x119460: 0x24c60001  addiu       $a2, $a2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11945c) {
            ctx->pc = 0x119440u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_119440;
        }
    }
    ctx->pc = 0x119464u;
    // 0x119464: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x119464u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x119468: 0x21823  negu        $v1, $v0
    ctx->pc = 0x119468u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 2)));
    // 0x11946c: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x11946cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x119470: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x119470u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
label_119474:
    // 0x119474: 0xc045190  jal         func_114640
    ctx->pc = 0x119474u;
    SET_GPR_U32(ctx, 31, 0x11947Cu);
    ctx->pc = 0x119478u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119474u;
            // 0x119478: 0x8e649dec  lw          $a0, -0x6214($s3) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 4294942188)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11947Cu; }
        if (ctx->pc != 0x11947Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11947Cu; }
        if (ctx->pc != 0x11947Cu) { return; }
    }
    ctx->pc = 0x11947Cu;
label_11947c:
    // 0x11947c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x11947Cu;
    {
        const bool branch_taken_0x11947c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x11947c) {
            ctx->pc = 0x11948Cu;
            goto label_11948c;
        }
    }
    ctx->pc = 0x119484u;
label_119484:
    // 0x119484: 0x3230000f  andi        $s0, $s1, 0xF
    ctx->pc = 0x119484u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)15);
    // 0x119488: 0x3c1e0026  lui         $fp, 0x26
    ctx->pc = 0x119488u;
    SET_GPR_S32(ctx, 30, (int32_t)((uint32_t)38 << 16));
label_11948c:
    // 0x11948c: 0x16000003  bnez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x11948Cu;
    {
        const bool branch_taken_0x11948c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x119490u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11948Cu;
            // 0x119490: 0x111102  srl         $v0, $s1, 4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 17), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11948c) {
            ctx->pc = 0x11949Cu;
            goto label_11949c;
        }
    }
    ctx->pc = 0x119494u;
    // 0x119494: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x119494u;
    {
        const bool branch_taken_0x119494 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x119498u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119494u;
            // 0x119498: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x119494) {
            ctx->pc = 0x1194A8u;
            goto label_1194a8;
        }
    }
    ctx->pc = 0x11949Cu;
label_11949c:
    // 0x11949c: 0x2623fff0  addiu       $v1, $s1, -0x10
    ctx->pc = 0x11949cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967280));
    // 0x1194a0: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x1194a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x1194a4: 0x438023  subu        $s0, $v0, $v1
    ctx->pc = 0x1194a4u;
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_1194a8:
    // 0x1194a8: 0x2b0182a  slt         $v1, $s5, $s0
    ctx->pc = 0x1194a8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 21) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x1194ac: 0x3c132000  lui         $s3, 0x2000
    ctx->pc = 0x1194acu;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)8192 << 16));
    // 0x1194b0: 0x2d31024  and         $v0, $s6, $s3
    ctx->pc = 0x1194b0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 22) & GPR_U64(ctx, 19));
    // 0x1194b4: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1194B4u;
    {
        const bool branch_taken_0x1194b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1194B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1194B4u;
            // 0x1194b8: 0x2a3800b  movn        $s0, $s5, $v1 (Delay Slot)
        if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 21));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1194b4) {
            ctx->pc = 0x1194C8u;
            goto label_1194c8;
        }
    }
    ctx->pc = 0x1194BCu;
    // 0x1194bc: 0x2a0282d  daddu       $a1, $s5, $zero
    ctx->pc = 0x1194bcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1194c0: 0xc045bf4  jal         func_116FD0
    ctx->pc = 0x1194C0u;
    SET_GPR_U32(ctx, 31, 0x1194C8u);
    ctx->pc = 0x1194C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1194C0u;
            // 0x1194c4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116FD0u;
    if (runtime->hasFunction(0x116FD0u)) {
        auto targetFn = runtime->lookupFunction(0x116FD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1194C8u; }
        if (ctx->pc != 0x1194C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116FD0_0x116fd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1194C8u; }
        if (ctx->pc != 0x1194C8u) { return; }
    }
    ctx->pc = 0x1194C8u;
label_1194c8:
    // 0x1194c8: 0x2338825  or          $s1, $s1, $s3
    ctx->pc = 0x1194c8u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | GPR_U64(ctx, 19));
    // 0x1194cc: 0xae500018  sw          $s0, 0x18($s2)
    ctx->pc = 0x1194ccu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 24), GPR_U32(ctx, 16));
    // 0x1194d0: 0x1a00000b  blez        $s0, . + 4 + (0xB << 2)
    ctx->pc = 0x1194D0u;
    {
        const bool branch_taken_0x1194d0 = (GPR_S64(ctx, 16) <= 0);
        ctx->pc = 0x1194D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1194D0u;
            // 0x1194d4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1194d0) {
            ctx->pc = 0x119500u;
            goto label_119500;
        }
    }
    ctx->pc = 0x1194D8u;
    // 0x1194d8: 0x2646001c  addiu       $a2, $s2, 0x1C
    ctx->pc = 0x1194d8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), 28));
    // 0x1194dc: 0x0  nop
    ctx->pc = 0x1194dcu;
    // NOP
label_1194e0:
    // 0x1194e0: 0x2251021  addu        $v0, $s1, $a1
    ctx->pc = 0x1194e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 5)));
    // 0x1194e4: 0xc52021  addu        $a0, $a2, $a1
    ctx->pc = 0x1194e4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x1194e8: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x1194e8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1194ec: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1194ecu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1194f0: 0xb0102a  slt         $v0, $a1, $s0
    ctx->pc = 0x1194f0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x1194f4: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x1194f4u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1194f8: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1194F8u;
    {
        const bool branch_taken_0x1194f8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1194f8) {
            ctx->pc = 0x1194E0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1194e0;
        }
    }
    ctx->pc = 0x119500u;
label_119500:
    // 0x119500: 0x27d0d680  addiu       $s0, $fp, -0x2980
    ctx->pc = 0x119500u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 30), 4294956672));
    // 0x119504: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x119504u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x119508: 0x2444e140  addiu       $a0, $v0, -0x1EC0
    ctx->pc = 0x119508u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 4294959424));
    // 0x11950c: 0x26e7ca40  addiu       $a3, $s7, -0x35C0
    ctx->pc = 0x11950cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 23), 4294953536));
    // 0x119510: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x119510u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x119514: 0x24050003  addiu       $a1, $zero, 0x3
    ctx->pc = 0x119514u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x119518: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x119518u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11951c: 0x24080030  addiu       $t0, $zero, 0x30
    ctx->pc = 0x11951cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x119520: 0x200482d  daddu       $t1, $s0, $zero
    ctx->pc = 0x119520u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x119524: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x119524u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x119528: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x119528u;
    SET_GPR_U32(ctx, 31, 0x119530u);
    ctx->pc = 0x11952Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119528u;
            // 0x11952c: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119530u; }
        if (ctx->pc != 0x119530u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119530u; }
        if (ctx->pc != 0x119530u) { return; }
    }
    ctx->pc = 0x119530u;
label_119530:
    // 0x119530: 0x4410007  bgez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x119530u;
    {
        const bool branch_taken_0x119530 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x119534u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119530u;
            // 0x119534: 0x3c022000  lui         $v0, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x119530) {
            ctx->pc = 0x119550u;
            goto label_119550;
        }
    }
    ctx->pc = 0x119538u;
    // 0x119538: 0xc04518c  jal         func_114630
    ctx->pc = 0x119538u;
    SET_GPR_U32(ctx, 31, 0x119540u);
    ctx->pc = 0x11953Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119538u;
            // 0x11953c: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119540u; }
        if (ctx->pc != 0x119540u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119540u; }
        if (ctx->pc != 0x119540u) { return; }
    }
    ctx->pc = 0x119540u;
label_119540:
    // 0x119540: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x119540u;
    SET_GPR_U32(ctx, 31, 0x119548u);
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119548u; }
        if (ctx->pc != 0x119548u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119548u; }
        if (ctx->pc != 0x119548u) { return; }
    }
    ctx->pc = 0x119548u;
label_119548:
    // 0x119548: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x119548u;
    {
        const bool branch_taken_0x119548 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11954Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119548u;
            // 0x11954c: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x119548) {
            ctx->pc = 0x1195A0u;
            goto label_1195a0;
        }
    }
    ctx->pc = 0x119550u;
label_119550:
    // 0x119550: 0x2021025  or          $v0, $s0, $v0
    ctx->pc = 0x119550u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x119554: 0xc0461a8  jal         func_1186A0
    ctx->pc = 0x119554u;
    SET_GPR_U32(ctx, 31, 0x11955Cu);
    ctx->pc = 0x119558u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119554u;
            // 0x119558: 0x8c500000  lw          $s0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1186A0u;
    if (runtime->hasFunction(0x1186A0u)) {
        auto targetFn = runtime->lookupFunction(0x1186A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11955Cu; }
        if (ctx->pc != 0x11955Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001186A0_0x1186a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11955Cu; }
        if (ctx->pc != 0x11955Cu) { return; }
    }
    ctx->pc = 0x11955Cu;
label_11955c:
    // 0x11955c: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x11955Cu;
    {
        const bool branch_taken_0x11955c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x119560u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11955Cu;
            // 0x119560: 0x32c28000  andi        $v0, $s6, 0x8000 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 22) & (uint64_t)(uint16_t)32768);
        ctx->in_delay_slot = false;
        if (branch_taken_0x11955c) {
            ctx->pc = 0x119574u;
            goto label_119574;
        }
    }
    ctx->pc = 0x119564u;
    // 0x119564: 0xc04518c  jal         func_114630
    ctx->pc = 0x119564u;
    SET_GPR_U32(ctx, 31, 0x11956Cu);
    ctx->pc = 0x119568u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119564u;
            // 0x119568: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11956Cu; }
        if (ctx->pc != 0x11956Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11956Cu; }
        if (ctx->pc != 0x11956Cu) { return; }
    }
    ctx->pc = 0x11956Cu;
label_11956c:
    // 0x11956c: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x11956Cu;
    {
        const bool branch_taken_0x11956c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x119570u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11956Cu;
            // 0x119570: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11956c) {
            ctx->pc = 0x1195A0u;
            goto label_1195a0;
        }
    }
    ctx->pc = 0x119574u;
label_119574:
    // 0x119574: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x119574u;
    {
        const bool branch_taken_0x119574 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x119574) {
            ctx->pc = 0x11958Cu;
            goto label_11958c;
        }
    }
    ctx->pc = 0x11957Cu;
    // 0x11957c: 0xc04518c  jal         func_114630
    ctx->pc = 0x11957Cu;
    SET_GPR_U32(ctx, 31, 0x119584u);
    ctx->pc = 0x119580u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11957Cu;
            // 0x119580: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119584u; }
        if (ctx->pc != 0x119584u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119584u; }
        if (ctx->pc != 0x119584u) { return; }
    }
    ctx->pc = 0x119584u;
label_119584:
    // 0x119584: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x119584u;
    {
        const bool branch_taken_0x119584 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x119588u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x119584u;
            // 0x119588: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x119584) {
            ctx->pc = 0x1195A0u;
            goto label_1195a0;
        }
    }
    ctx->pc = 0x11958Cu;
label_11958c:
    // 0x11958c: 0xc045198  jal         func_114660
    ctx->pc = 0x11958Cu;
    SET_GPR_U32(ctx, 31, 0x119594u);
    ctx->pc = 0x119590u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11958Cu;
            // 0x119590: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119594u; }
        if (ctx->pc != 0x119594u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x119594u; }
        if (ctx->pc != 0x119594u) { return; }
    }
    ctx->pc = 0x119594u;
label_119594:
    // 0x119594: 0xc04518c  jal         func_114630
    ctx->pc = 0x119594u;
    SET_GPR_U32(ctx, 31, 0x11959Cu);
    ctx->pc = 0x119598u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x119594u;
            // 0x119598: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11959Cu; }
        if (ctx->pc != 0x11959Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11959Cu; }
        if (ctx->pc != 0x11959Cu) { return; }
    }
    ctx->pc = 0x11959Cu;
label_11959c:
    // 0x11959c: 0x8fa20030  lw          $v0, 0x30($sp)
    ctx->pc = 0x11959cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_1195a0:
    // 0x1195a0: 0xdfbf00d0  ld          $ra, 0xD0($sp)
    ctx->pc = 0x1195a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 208)));
    // 0x1195a4: 0xdfbe00c0  ld          $fp, 0xC0($sp)
    ctx->pc = 0x1195a4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 192)));
    // 0x1195a8: 0xdfb700b0  ld          $s7, 0xB0($sp)
    ctx->pc = 0x1195a8u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x1195ac: 0xdfb600a0  ld          $s6, 0xA0($sp)
    ctx->pc = 0x1195acu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x1195b0: 0xdfb50090  ld          $s5, 0x90($sp)
    ctx->pc = 0x1195b0u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x1195b4: 0xdfb40080  ld          $s4, 0x80($sp)
    ctx->pc = 0x1195b4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x1195b8: 0xdfb30070  ld          $s3, 0x70($sp)
    ctx->pc = 0x1195b8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1195bc: 0xdfb20060  ld          $s2, 0x60($sp)
    ctx->pc = 0x1195bcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1195c0: 0xdfb10050  ld          $s1, 0x50($sp)
    ctx->pc = 0x1195c0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1195c4: 0xdfb00040  ld          $s0, 0x40($sp)
    ctx->pc = 0x1195c4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1195c8: 0x3e00008  jr          $ra
    ctx->pc = 0x1195C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1195CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1195C8u;
            // 0x1195cc: 0x27bd00e0  addiu       $sp, $sp, 0xE0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 224));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x119350u: goto label_119350;
            case 0x11935Cu: goto label_11935c;
            case 0x119374u: goto label_119374;
            case 0x11937Cu: goto label_11937c;
            case 0x119390u: goto label_119390;
            case 0x119398u: goto label_119398;
            case 0x1193A0u: goto label_1193a0;
            case 0x1193D8u: goto label_1193d8;
            case 0x119404u: goto label_119404;
            case 0x119438u: goto label_119438;
            case 0x119440u: goto label_119440;
            case 0x119474u: goto label_119474;
            case 0x11947Cu: goto label_11947c;
            case 0x119484u: goto label_119484;
            case 0x11948Cu: goto label_11948c;
            case 0x11949Cu: goto label_11949c;
            case 0x1194A8u: goto label_1194a8;
            case 0x1194C8u: goto label_1194c8;
            case 0x1194E0u: goto label_1194e0;
            case 0x119500u: goto label_119500;
            case 0x119530u: goto label_119530;
            case 0x119540u: goto label_119540;
            case 0x119548u: goto label_119548;
            case 0x119550u: goto label_119550;
            case 0x11955Cu: goto label_11955c;
            case 0x11956Cu: goto label_11956c;
            case 0x119574u: goto label_119574;
            case 0x119584u: goto label_119584;
            case 0x11958Cu: goto label_11958c;
            case 0x119594u: goto label_119594;
            case 0x11959Cu: goto label_11959c;
            case 0x1195A0u: goto label_1195a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1195D0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
