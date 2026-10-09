#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010D1E0
// Address: 0x10d1e0 - 0x10e850
void sub_0010D1E0_0x10d1e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010D1E0_0x10d1e0");
#endif

    switch (ctx->pc) {
        case 0x10d220u: goto label_10d220;
        case 0x10d250u: goto label_10d250;
        case 0x10d28cu: goto label_10d28c;
        case 0x10d2b0u: goto label_10d2b0;
        case 0x10d2b8u: goto label_10d2b8;
        case 0x10d2d8u: goto label_10d2d8;
        case 0x10d338u: goto label_10d338;
        case 0x10d374u: goto label_10d374;
        case 0x10d378u: goto label_10d378;
        case 0x10d384u: goto label_10d384;
        case 0x10d388u: goto label_10d388;
        case 0x10d440u: goto label_10d440;
        case 0x10d490u: goto label_10d490;
        case 0x10d5bcu: goto label_10d5bc;
        case 0x10d5d4u: goto label_10d5d4;
        case 0x10d604u: goto label_10d604;
        case 0x10d640u: goto label_10d640;
        case 0x10d6acu: goto label_10d6ac;
        case 0x10d84cu: goto label_10d84c;
        case 0x10d878u: goto label_10d878;
        case 0x10d988u: goto label_10d988;
        case 0x10d990u: goto label_10d990;
        case 0x10d9d0u: goto label_10d9d0;
        case 0x10d9d8u: goto label_10d9d8;
        case 0x10d9f4u: goto label_10d9f4;
        case 0x10da20u: goto label_10da20;
        case 0x10dae8u: goto label_10dae8;
        case 0x10db24u: goto label_10db24;
        case 0x10db8cu: goto label_10db8c;
        case 0x10dbe4u: goto label_10dbe4;
        case 0x10dc4cu: goto label_10dc4c;
        case 0x10dc98u: goto label_10dc98;
        case 0x10dcd4u: goto label_10dcd4;
        case 0x10dd3cu: goto label_10dd3c;
        case 0x10dd78u: goto label_10dd78;
        case 0x10ddb4u: goto label_10ddb4;
        case 0x10de1cu: goto label_10de1c;
        case 0x10de70u: goto label_10de70;
        case 0x10debcu: goto label_10debc;
        case 0x10df28u: goto label_10df28;
        case 0x10df60u: goto label_10df60;
        case 0x10df98u: goto label_10df98;
        case 0x10e03cu: goto label_10e03c;
        case 0x10e0a0u: goto label_10e0a0;
        case 0x10e0d8u: goto label_10e0d8;
        case 0x10e110u: goto label_10e110;
        case 0x10e174u: goto label_10e174;
        case 0x10e1c4u: goto label_10e1c4;
        case 0x10e220u: goto label_10e220;
        case 0x10e260u: goto label_10e260;
        case 0x10e298u: goto label_10e298;
        case 0x10e2fcu: goto label_10e2fc;
        case 0x10e38cu: goto label_10e38c;
        case 0x10e3e8u: goto label_10e3e8;
        case 0x10e448u: goto label_10e448;
        case 0x10e4ccu: goto label_10e4cc;
        case 0x10e4ecu: goto label_10e4ec;
        case 0x10e53cu: goto label_10e53c;
        case 0x10e578u: goto label_10e578;
        case 0x10e5b0u: goto label_10e5b0;
        case 0x10e614u: goto label_10e614;
        case 0x10e660u: goto label_10e660;
        case 0x10e6b0u: goto label_10e6b0;
        case 0x10e6f8u: goto label_10e6f8;
        case 0x10e730u: goto label_10e730;
        case 0x10e790u: goto label_10e790;
        case 0x10e7ccu: goto label_10e7cc;
        case 0x10e7fcu: goto label_10e7fc;
        default: break;
    }

    ctx->pc = 0x10d1e0u;

    // 0x10d1e0: 0x27bdfd70  addiu       $sp, $sp, -0x290
    ctx->pc = 0x10d1e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966640));
    // 0x10d1e4: 0xffb00240  sd          $s0, 0x240($sp)
    ctx->pc = 0x10d1e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 576), GPR_U64(ctx, 16));
    // 0x10d1e8: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x10d1e8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d1ec: 0xffb60270  sd          $s6, 0x270($sp)
    ctx->pc = 0x10d1ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 624), GPR_U64(ctx, 22));
    // 0x10d1f0: 0xe0b02d  daddu       $s6, $a3, $zero
    ctx->pc = 0x10d1f0u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d1f4: 0xafa401e4  sw          $a0, 0x1E4($sp)
    ctx->pc = 0x10d1f4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 484), GPR_U32(ctx, 4));
    // 0x10d1f8: 0xffb10248  sd          $s1, 0x248($sp)
    ctx->pc = 0x10d1f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 584), GPR_U64(ctx, 17));
    // 0x10d1fc: 0xffb20250  sd          $s2, 0x250($sp)
    ctx->pc = 0x10d1fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 592), GPR_U64(ctx, 18));
    // 0x10d200: 0xffb30258  sd          $s3, 0x258($sp)
    ctx->pc = 0x10d200u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 600), GPR_U64(ctx, 19));
    // 0x10d204: 0xffb40260  sd          $s4, 0x260($sp)
    ctx->pc = 0x10d204u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 608), GPR_U64(ctx, 20));
    // 0x10d208: 0xffb50268  sd          $s5, 0x268($sp)
    ctx->pc = 0x10d208u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 616), GPR_U64(ctx, 21));
    // 0x10d20c: 0xffb70278  sd          $s7, 0x278($sp)
    ctx->pc = 0x10d20cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 632), GPR_U64(ctx, 23));
    // 0x10d210: 0xffbe0280  sd          $fp, 0x280($sp)
    ctx->pc = 0x10d210u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 640), GPR_U64(ctx, 30));
    // 0x10d214: 0xffbf0288  sd          $ra, 0x288($sp)
    ctx->pc = 0x10d214u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 648), GPR_U64(ctx, 31));
    // 0x10d218: 0xc041ab6  jal         func_106AD8
    ctx->pc = 0x10D218u;
    SET_GPR_U32(ctx, 31, 0x10D220u);
    ctx->pc = 0x10D21Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10D218u;
            // 0x10d21c: 0xafa501e8  sw          $a1, 0x1E8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 488), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x106AD8u;
    if (runtime->hasFunction(0x106AD8u)) {
        auto targetFn = runtime->lookupFunction(0x106AD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D220u; }
        if (ctx->pc != 0x10D220u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00106AD8_0x106ad8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D220u; }
        if (ctx->pc != 0x10D220u) { return; }
    }
    ctx->pc = 0x10D220u;
label_10d220:
    // 0x10d220: 0x8fa401e8  lw          $a0, 0x1E8($sp)
    ctx->pc = 0x10d220u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x10d224: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x10d224u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x10d228: 0x9483000c  lhu         $v1, 0xC($a0)
    ctx->pc = 0x10d228u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x10d22c: 0xafa201f4  sw          $v0, 0x1F4($sp)
    ctx->pc = 0x10d22cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 500), GPR_U32(ctx, 2));
    // 0x10d230: 0x30620008  andi        $v0, $v1, 0x8
    ctx->pc = 0x10d230u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)8);
    // 0x10d234: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x10D234u;
    {
        const bool branch_taken_0x10d234 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D238u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D234u;
            // 0x10d238: 0xafa001d8  sw          $zero, 0x1D8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 472), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d234) {
            ctx->pc = 0x10D248u;
            goto label_10d248;
        }
    }
    ctx->pc = 0x10D23Cu;
    // 0x10d23c: 0x8c820010  lw          $v0, 0x10($a0)
    ctx->pc = 0x10d23cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x10d240: 0x54400008  bnel        $v0, $zero, . + 4 + (0x8 << 2)
    ctx->pc = 0x10D240u;
    {
        const bool branch_taken_0x10d240 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10d240) {
            ctx->pc = 0x10D244u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10D240u;
            // 0x10d244: 0x3063001a  andi        $v1, $v1, 0x1A (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)26);
        ctx->in_delay_slot = false;
            ctx->pc = 0x10D264u;
            goto label_10d264;
        }
    }
    ctx->pc = 0x10D248u;
label_10d248:
    // 0x10d248: 0xc043e64  jal         func_10F990
    ctx->pc = 0x10D248u;
    SET_GPR_U32(ctx, 31, 0x10D250u);
    ctx->pc = 0x10D24Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10D248u;
            // 0x10d24c: 0x8fa401e8  lw          $a0, 0x1E8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10F990u;
    if (runtime->hasFunction(0x10F990u)) {
        auto targetFn = runtime->lookupFunction(0x10F990u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D250u; }
        if (ctx->pc != 0x10D250u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010F990_0x10f990(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D250u; }
        if (ctx->pc != 0x10D250u) { return; }
    }
    ctx->pc = 0x10D250u;
label_10d250:
    // 0x10d250: 0x14400573  bnez        $v0, . + 4 + (0x573 << 2)
    ctx->pc = 0x10D250u;
    {
        const bool branch_taken_0x10d250 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10D254u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D250u;
            // 0x10d254: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d250) {
            ctx->pc = 0x10E820u;
            goto label_10e820;
        }
    }
    ctx->pc = 0x10D258u;
    // 0x10d258: 0x8fa501e8  lw          $a1, 0x1E8($sp)
    ctx->pc = 0x10d258u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x10d25c: 0x94a3000c  lhu         $v1, 0xC($a1)
    ctx->pc = 0x10d25cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 12)));
    // 0x10d260: 0x3063001a  andi        $v1, $v1, 0x1A
    ctx->pc = 0x10d260u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)26);
label_10d264:
    // 0x10d264: 0x2402000a  addiu       $v0, $zero, 0xA
    ctx->pc = 0x10d264u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x10d268: 0x1462000b  bne         $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x10D268u;
    {
        const bool branch_taken_0x10d268 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x10D26Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D268u;
            // 0x10d26c: 0x27b30020  addiu       $s3, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d268) {
            ctx->pc = 0x10D298u;
            goto label_10d298;
        }
    }
    ctx->pc = 0x10D270u;
    // 0x10d270: 0x8fa601e8  lw          $a2, 0x1E8($sp)
    ctx->pc = 0x10d270u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x10d274: 0x84c2000e  lh          $v0, 0xE($a2)
    ctx->pc = 0x10d274u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 6), 14)));
    // 0x10d278: 0x4400007  bltz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x10D278u;
    {
        const bool branch_taken_0x10d278 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x10D27Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D278u;
            // 0x10d27c: 0xc0202d  daddu       $a0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d278) {
            ctx->pc = 0x10D298u;
            goto label_10d298;
        }
    }
    ctx->pc = 0x10D280u;
    // 0x10d280: 0x2c0302d  daddu       $a2, $s6, $zero
    ctx->pc = 0x10d280u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d284: 0xc04342c  jal         func_10D0B0
    ctx->pc = 0x10D284u;
    SET_GPR_U32(ctx, 31, 0x10D28Cu);
    ctx->pc = 0x10D288u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10D284u;
            // 0x10d288: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D0B0u;
    if (runtime->hasFunction(0x10D0B0u)) {
        auto targetFn = runtime->lookupFunction(0x10D0B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D28Cu; }
        if (ctx->pc != 0x10D28Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D0B0_0x10d0b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D28Cu; }
        if (ctx->pc != 0x10D28Cu) { return; }
    }
    ctx->pc = 0x10D28Cu;
label_10d28c:
    // 0x10d28c: 0x10000565  b           . + 4 + (0x565 << 2)
    ctx->pc = 0x10D28Cu;
    {
        const bool branch_taken_0x10d28c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D290u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D28Cu;
            // 0x10d290: 0xdfb00240  ld          $s0, 0x240($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 576)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d28c) {
            ctx->pc = 0x10E824u;
            goto label_10e824;
        }
    }
    ctx->pc = 0x10D294u;
    // 0x10d294: 0x0  nop
    ctx->pc = 0x10d294u;
    // NOP
label_10d298:
    // 0x10d298: 0xafa00018  sw          $zero, 0x18($sp)
    ctx->pc = 0x10d298u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
    // 0x10d29c: 0xafb30010  sw          $s3, 0x10($sp)
    ctx->pc = 0x10d29cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 19));
    // 0x10d2a0: 0x200902d  daddu       $s2, $s0, $zero
    ctx->pc = 0x10d2a0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d2a4: 0xafa00014  sw          $zero, 0x14($sp)
    ctx->pc = 0x10d2a4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    // 0x10d2a8: 0xafa001ec  sw          $zero, 0x1EC($sp)
    ctx->pc = 0x10d2a8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 492), GPR_U32(ctx, 0));
    // 0x10d2ac: 0x0  nop
    ctx->pc = 0x10d2acu;
    // NOP
label_10d2b0:
    // 0x10d2b0: 0x240a82d  daddu       $s5, $s2, $zero
    ctx->pc = 0x10d2b0u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d2b4: 0x24110025  addiu       $s1, $zero, 0x25
    ctx->pc = 0x10d2b4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 37));
label_10d2b8:
    // 0x10d2b8: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x10d2b8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x10d2bc: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x10d2bcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x10d2c0: 0x8c4497f0  lw          $a0, -0x6810($v0)
    ctx->pc = 0x10d2c0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294940656)));
    // 0x10d2c4: 0x27a501d4  addiu       $a1, $sp, 0x1D4
    ctx->pc = 0x10d2c4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 468));
    // 0x10d2c8: 0x8c6797f8  lw          $a3, -0x6808($v1)
    ctx->pc = 0x10d2c8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294940664)));
    // 0x10d2cc: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x10d2ccu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d2d0: 0xc041e40  jal         func_107900
    ctx->pc = 0x10D2D0u;
    SET_GPR_U32(ctx, 31, 0x10D2D8u);
    ctx->pc = 0x10D2D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10D2D0u;
            // 0x10d2d4: 0x27a801d8  addiu       $t0, $sp, 0x1D8 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 472));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107900u;
    if (runtime->hasFunction(0x107900u)) {
        auto targetFn = runtime->lookupFunction(0x107900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D2D8u; }
        if (ctx->pc != 0x10D2D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107900_0x107900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D2D8u; }
        if (ctx->pc != 0x10D2D8u) { return; }
    }
    ctx->pc = 0x10D2D8u;
label_10d2d8:
    // 0x10d2d8: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x10d2d8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d2dc: 0x5a000006  blezl       $s0, . + 4 + (0x6 << 2)
    ctx->pc = 0x10D2DCu;
    {
        const bool branch_taken_0x10d2dc = (GPR_S64(ctx, 16) <= 0);
        if (branch_taken_0x10d2dc) {
            ctx->pc = 0x10D2E0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10D2DCu;
            // 0x10d2e0: 0x2558823  subu        $s1, $s2, $s5 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 18), GPR_U32(ctx, 21)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10D2F8u;
            goto label_10d2f8;
        }
    }
    ctx->pc = 0x10D2E4u;
    // 0x10d2e4: 0x8fa201d4  lw          $v0, 0x1D4($sp)
    ctx->pc = 0x10d2e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 468)));
    // 0x10d2e8: 0x1451fff3  bne         $v0, $s1, . + 4 + (-0xD << 2)
    ctx->pc = 0x10D2E8u;
    {
        const bool branch_taken_0x10d2e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 17));
        ctx->pc = 0x10D2ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D2E8u;
            // 0x10d2ec: 0x2509021  addu        $s2, $s2, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d2e8) {
            ctx->pc = 0x10D2B8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10d2b8;
        }
    }
    ctx->pc = 0x10D2F0u;
    // 0x10d2f0: 0x2652ffff  addiu       $s2, $s2, -0x1
    ctx->pc = 0x10d2f0u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967295));
    // 0x10d2f4: 0x2558823  subu        $s1, $s2, $s5
    ctx->pc = 0x10d2f4u;
    SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 18), GPR_U32(ctx, 21)));
label_10d2f8:
    // 0x10d2f8: 0x12200016  beqz        $s1, . + 4 + (0x16 << 2)
    ctx->pc = 0x10D2F8u;
    {
        const bool branch_taken_0x10d2f8 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        if (branch_taken_0x10d2f8) {
            ctx->pc = 0x10D354u;
            goto label_10d354;
        }
    }
    ctx->pc = 0x10D300u;
    // 0x10d300: 0xae710004  sw          $s1, 0x4($s3)
    ctx->pc = 0x10d300u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 17));
    // 0x10d304: 0xae750000  sw          $s5, 0x0($s3)
    ctx->pc = 0x10d304u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 21));
    // 0x10d308: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x10d308u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x10d30c: 0x8fa20014  lw          $v0, 0x14($sp)
    ctx->pc = 0x10d30cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x10d310: 0x8fa30018  lw          $v1, 0x18($sp)
    ctx->pc = 0x10d310u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10d314: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x10d314u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x10d318: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x10d318u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x10d31c: 0x28440008  slti        $a0, $v0, 0x8
    ctx->pc = 0x10d31cu;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x10d320: 0xafa30018  sw          $v1, 0x18($sp)
    ctx->pc = 0x10d320u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 3));
    // 0x10d324: 0x14800008  bnez        $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x10D324u;
    {
        const bool branch_taken_0x10d324 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x10D328u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D324u;
            // 0x10d328: 0xafa20014  sw          $v0, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d324) {
            ctx->pc = 0x10D348u;
            goto label_10d348;
        }
    }
    ctx->pc = 0x10D32Cu;
    // 0x10d32c: 0x8fa401e8  lw          $a0, 0x1E8($sp)
    ctx->pc = 0x10d32cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x10d330: 0xc04341a  jal         func_10D068
    ctx->pc = 0x10D330u;
    SET_GPR_U32(ctx, 31, 0x10D338u);
    ctx->pc = 0x10D334u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10D330u;
            // 0x10d334: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D068u;
    if (runtime->hasFunction(0x10D068u)) {
        auto targetFn = runtime->lookupFunction(0x10D068u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D338u; }
        if (ctx->pc != 0x10D338u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D068_0x10d068(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D338u; }
        if (ctx->pc != 0x10D338u) { return; }
    }
    ctx->pc = 0x10D338u;
label_10d338:
    // 0x10d338: 0x14400534  bnez        $v0, . + 4 + (0x534 << 2)
    ctx->pc = 0x10D338u;
    {
        const bool branch_taken_0x10d338 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10D33Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D338u;
            // 0x10d33c: 0x8fa201e8  lw          $v0, 0x1E8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d338) {
            ctx->pc = 0x10E80Cu;
            goto label_10e80c;
        }
    }
    ctx->pc = 0x10D340u;
    // 0x10d340: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x10d340u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x10d344: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x10d344u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_10d348:
    // 0x10d348: 0x8fa501ec  lw          $a1, 0x1EC($sp)
    ctx->pc = 0x10d348u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 492)));
    // 0x10d34c: 0xb12821  addu        $a1, $a1, $s1
    ctx->pc = 0x10d34cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 17)));
    // 0x10d350: 0xafa501ec  sw          $a1, 0x1EC($sp)
    ctx->pc = 0x10d350u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 492), GPR_U32(ctx, 5));
label_10d354:
    // 0x10d354: 0x1a000525  blez        $s0, . + 4 + (0x525 << 2)
    ctx->pc = 0x10D354u;
    {
        const bool branch_taken_0x10d354 = (GPR_S64(ctx, 16) <= 0);
        ctx->pc = 0x10D358u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D354u;
            // 0x10d358: 0x8fa20018  lw          $v0, 0x18($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d354) {
            ctx->pc = 0x10E7ECu;
            goto label_10e7ec;
        }
    }
    ctx->pc = 0x10D35Cu;
    // 0x10d35c: 0xa3a001d1  sb          $zero, 0x1D1($sp)
    ctx->pc = 0x10d35cu;
    WRITE8(ADD32(GPR_U32(ctx, 29), 465), (uint8_t)GPR_U32(ctx, 0));
    // 0x10d360: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x10d360u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x10d364: 0xafa00204  sw          $zero, 0x204($sp)
    ctx->pc = 0x10d364u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 516), GPR_U32(ctx, 0));
    // 0x10d368: 0xb82d  daddu       $s7, $zero, $zero
    ctx->pc = 0x10d368u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d36c: 0xafa001f0  sw          $zero, 0x1F0($sp)
    ctx->pc = 0x10d36cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 496), GPR_U32(ctx, 0));
    // 0x10d370: 0x2414ffff  addiu       $s4, $zero, -0x1
    ctx->pc = 0x10d370u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_10d374:
    // 0x10d374: 0x92440000  lbu         $a0, 0x0($s2)
    ctx->pc = 0x10d374u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
label_10d378:
    // 0x10d378: 0x41600  sll         $v0, $a0, 24
    ctx->pc = 0x10d378u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
    // 0x10d37c: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x10d37cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x10d380: 0x28e03  sra         $s1, $v0, 24
    ctx->pc = 0x10d380u;
    SET_GPR_S32(ctx, 17, SRA32(GPR_S32(ctx, 2), 24));
label_10d384:
    // 0x10d384: 0x2623ffe0  addiu       $v1, $s1, -0x20
    ctx->pc = 0x10d384u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967264));
label_10d388:
    // 0x10d388: 0x2c620059  sltiu       $v0, $v1, 0x59
    ctx->pc = 0x10d388u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)89) ? 1 : 0);
    // 0x10d38c: 0x104001b2  beqz        $v0, . + 4 + (0x1B2 << 2)
    ctx->pc = 0x10D38Cu;
    {
        const bool branch_taken_0x10d38c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D390u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D38Cu;
            // 0x10d390: 0x31080  sll         $v0, $v1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d38c) {
            ctx->pc = 0x10DA58u;
            goto label_10da58;
        }
    }
    ctx->pc = 0x10D394u;
    // 0x10d394: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x10d394u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x10d398: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x10d398u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x10d39c: 0x8c637bc0  lw          $v1, 0x7BC0($v1)
    ctx->pc = 0x10d39cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 31680)));
    // 0x10d3a0: 0x600008  jr          $v1
    ctx->pc = 0x10D3A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10D3A8u: goto label_10d3a8;
            case 0x10D3C0u: goto label_10d3c0;
            case 0x10D3C8u: goto label_10d3c8;
            case 0x10D3E4u: goto label_10d3e4;
            case 0x10D3F0u: goto label_10d3f0;
            case 0x10D400u: goto label_10d400;
            case 0x10D480u: goto label_10d480;
            case 0x10D488u: goto label_10d488;
            case 0x10D4C0u: goto label_10d4c0;
            case 0x10D4C8u: goto label_10d4c8;
            case 0x10D4D0u: goto label_10d4d0;
            case 0x10D4E4u: goto label_10d4e4;
            case 0x10D4F8u: goto label_10d4f8;
            case 0x10D518u: goto label_10d518;
            case 0x10D51Cu: goto label_10d51c;
            case 0x10D570u: goto label_10d570;
            case 0x10D750u: goto label_10d750;
            case 0x10D7B0u: goto label_10d7b0;
            case 0x10D7B4u: goto label_10d7b4;
            case 0x10D7F8u: goto label_10d7f8;
            case 0x10D820u: goto label_10d820;
            case 0x10D880u: goto label_10d880;
            case 0x10D884u: goto label_10d884;
            case 0x10D8C8u: goto label_10d8c8;
            case 0x10D8D8u: goto label_10d8d8;
            case 0x10DA58u: goto label_10da58;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10D3A8u;
label_10d3a8:
    // 0x10d3a8: 0x83a201d1  lb          $v0, 0x1D1($sp)
    ctx->pc = 0x10d3a8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 465)));
    // 0x10d3ac: 0x5440fff2  bnel        $v0, $zero, . + 4 + (-0xE << 2)
    ctx->pc = 0x10D3ACu;
    {
        const bool branch_taken_0x10d3ac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10d3ac) {
            ctx->pc = 0x10D3B0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10D3ACu;
            // 0x10d3b0: 0x92440000  lbu         $a0, 0x0($s2) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10D378u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10d378;
        }
    }
    ctx->pc = 0x10D3B4u;
    // 0x10d3b4: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x10D3B4u;
    {
        const bool branch_taken_0x10d3b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D3B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D3B4u;
            // 0x10d3b8: 0x24020020  addiu       $v0, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d3b4) {
            ctx->pc = 0x10D3F4u;
            goto label_10d3f4;
        }
    }
    ctx->pc = 0x10D3BCu;
    // 0x10d3bc: 0x0  nop
    ctx->pc = 0x10d3bcu;
    // NOP
label_10d3c0:
    // 0x10d3c0: 0x1000ffec  b           . + 4 + (-0x14 << 2)
    ctx->pc = 0x10D3C0u;
    {
        const bool branch_taken_0x10d3c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D3C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D3C0u;
            // 0x10d3c4: 0x36f70001  ori         $s7, $s7, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 23, GPR_U64(ctx, 23) | (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d3c0) {
            ctx->pc = 0x10D374u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10d374;
        }
    }
    ctx->pc = 0x10D3C8u;
label_10d3c8:
    // 0x10d3c8: 0x2c0102d  daddu       $v0, $s6, $zero
    ctx->pc = 0x10d3c8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d3cc: 0x26d60008  addiu       $s6, $s6, 0x8
    ctx->pc = 0x10d3ccu;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 8));
    // 0x10d3d0: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x10d3d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x10d3d4: 0x441ffe7  bgez        $v0, . + 4 + (-0x19 << 2)
    ctx->pc = 0x10D3D4u;
    {
        const bool branch_taken_0x10d3d4 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x10D3D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D3D4u;
            // 0x10d3d8: 0xafa201f0  sw          $v0, 0x1F0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 496), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d3d4) {
            ctx->pc = 0x10D374u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10d374;
        }
    }
    ctx->pc = 0x10D3DCu;
    // 0x10d3dc: 0x21023  negu        $v0, $v0
    ctx->pc = 0x10d3dcu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 2)));
    // 0x10d3e0: 0xafa201f0  sw          $v0, 0x1F0($sp)
    ctx->pc = 0x10d3e0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 496), GPR_U32(ctx, 2));
label_10d3e4:
    // 0x10d3e4: 0x1000ffe3  b           . + 4 + (-0x1D << 2)
    ctx->pc = 0x10D3E4u;
    {
        const bool branch_taken_0x10d3e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D3E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D3E4u;
            // 0x10d3e8: 0x36f70004  ori         $s7, $s7, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 23, GPR_U64(ctx, 23) | (uint64_t)(uint16_t)4);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d3e4) {
            ctx->pc = 0x10D374u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10d374;
        }
    }
    ctx->pc = 0x10D3ECu;
    // 0x10d3ec: 0x0  nop
    ctx->pc = 0x10d3ecu;
    // NOP
label_10d3f0:
    // 0x10d3f0: 0x2402002b  addiu       $v0, $zero, 0x2B
    ctx->pc = 0x10d3f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 43));
label_10d3f4:
    // 0x10d3f4: 0x92440000  lbu         $a0, 0x0($s2)
    ctx->pc = 0x10d3f4u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x10d3f8: 0x1000ffdf  b           . + 4 + (-0x21 << 2)
    ctx->pc = 0x10D3F8u;
    {
        const bool branch_taken_0x10d3f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D3FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D3F8u;
            // 0x10d3fc: 0xa3a201d1  sb          $v0, 0x1D1($sp) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 29), 465), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d3f8) {
            ctx->pc = 0x10D378u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10d378;
        }
    }
    ctx->pc = 0x10D400u;
label_10d400:
    // 0x10d400: 0x82510000  lb          $s1, 0x0($s2)
    ctx->pc = 0x10d400u;
    SET_GPR_S32(ctx, 17, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x10d404: 0x2402002a  addiu       $v0, $zero, 0x2A
    ctx->pc = 0x10d404u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 42));
    // 0x10d408: 0x16220009  bne         $s1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x10D408u;
    {
        const bool branch_taken_0x10d408 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        ctx->pc = 0x10D40Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D408u;
            // 0x10d40c: 0x26520001  addiu       $s2, $s2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d408) {
            ctx->pc = 0x10D430u;
            goto label_10d430;
        }
    }
    ctx->pc = 0x10D410u;
    // 0x10d410: 0x2c0102d  daddu       $v0, $s6, $zero
    ctx->pc = 0x10d410u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d414: 0x8c500000  lw          $s0, 0x0($v0)
    ctx->pc = 0x10d414u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x10d418: 0x200a02d  daddu       $s4, $s0, $zero
    ctx->pc = 0x10d418u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d41c: 0x2a82ffff  slti        $v0, $s4, -0x1
    ctx->pc = 0x10d41cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 20) < (int64_t)(int32_t)4294967295) ? 1 : 0);
    // 0x10d420: 0x1040ffd4  beqz        $v0, . + 4 + (-0x2C << 2)
    ctx->pc = 0x10D420u;
    {
        const bool branch_taken_0x10d420 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D424u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D420u;
            // 0x10d424: 0x26d60008  addiu       $s6, $s6, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d420) {
            ctx->pc = 0x10D374u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10d374;
        }
    }
    ctx->pc = 0x10D428u;
    // 0x10d428: 0x1000ffd2  b           . + 4 + (-0x2E << 2)
    ctx->pc = 0x10D428u;
    {
        const bool branch_taken_0x10d428 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D42Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D428u;
            // 0x10d42c: 0x2414ffff  addiu       $s4, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d428) {
            ctx->pc = 0x10D374u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10d374;
        }
    }
    ctx->pc = 0x10D430u;
label_10d430:
    // 0x10d430: 0x2622ffd0  addiu       $v0, $s1, -0x30
    ctx->pc = 0x10d430u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967248));
    // 0x10d434: 0x2c42000a  sltiu       $v0, $v0, 0xA
    ctx->pc = 0x10d434u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)10) ? 1 : 0);
    // 0x10d438: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x10D438u;
    {
        const bool branch_taken_0x10d438 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D43Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D438u;
            // 0x10d43c: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d438) {
            ctx->pc = 0x10D468u;
            goto label_10d468;
        }
    }
    ctx->pc = 0x10D440u;
label_10d440:
    // 0x10d440: 0x101080  sll         $v0, $s0, 2
    ctx->pc = 0x10d440u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x10d444: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x10d444u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x10d448: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x10d448u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x10d44c: 0x511021  addu        $v0, $v0, $s1
    ctx->pc = 0x10d44cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x10d450: 0x82510000  lb          $s1, 0x0($s2)
    ctx->pc = 0x10d450u;
    SET_GPR_S32(ctx, 17, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x10d454: 0x2450ffd0  addiu       $s0, $v0, -0x30
    ctx->pc = 0x10d454u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967248));
    // 0x10d458: 0x2622ffd0  addiu       $v0, $s1, -0x30
    ctx->pc = 0x10d458u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967248));
    // 0x10d45c: 0x2c42000a  sltiu       $v0, $v0, 0xA
    ctx->pc = 0x10d45cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)10) ? 1 : 0);
    // 0x10d460: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x10D460u;
    {
        const bool branch_taken_0x10d460 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10D464u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D460u;
            // 0x10d464: 0x26520001  addiu       $s2, $s2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d460) {
            ctx->pc = 0x10D440u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10d440;
        }
    }
    ctx->pc = 0x10D468u;
label_10d468:
    // 0x10d468: 0x200a02d  daddu       $s4, $s0, $zero
    ctx->pc = 0x10d468u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d46c: 0x2a82ffff  slti        $v0, $s4, -0x1
    ctx->pc = 0x10d46cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 20) < (int64_t)(int32_t)4294967295) ? 1 : 0);
    // 0x10d470: 0x5440ffc4  bnel        $v0, $zero, . + 4 + (-0x3C << 2)
    ctx->pc = 0x10D470u;
    {
        const bool branch_taken_0x10d470 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10d470) {
            ctx->pc = 0x10D474u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10D470u;
            // 0x10d474: 0x2414ffff  addiu       $s4, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10D384u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10d384;
        }
    }
    ctx->pc = 0x10D478u;
    // 0x10d478: 0x1000ffc3  b           . + 4 + (-0x3D << 2)
    ctx->pc = 0x10D478u;
    {
        const bool branch_taken_0x10d478 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D47Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D478u;
            // 0x10d47c: 0x2623ffe0  addiu       $v1, $s1, -0x20 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967264));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d478) {
            ctx->pc = 0x10D388u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10d388;
        }
    }
    ctx->pc = 0x10D480u;
label_10d480:
    // 0x10d480: 0x1000ffbc  b           . + 4 + (-0x44 << 2)
    ctx->pc = 0x10D480u;
    {
        const bool branch_taken_0x10d480 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D484u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D480u;
            // 0x10d484: 0x36f70080  ori         $s7, $s7, 0x80 (Delay Slot)
        SET_GPR_U64(ctx, 23, GPR_U64(ctx, 23) | (uint64_t)(uint16_t)128);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d480) {
            ctx->pc = 0x10D374u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10d374;
        }
    }
    ctx->pc = 0x10D488u;
label_10d488:
    // 0x10d488: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x10d488u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d48c: 0x0  nop
    ctx->pc = 0x10d48cu;
    // NOP
label_10d490:
    // 0x10d490: 0x101080  sll         $v0, $s0, 2
    ctx->pc = 0x10d490u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x10d494: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x10d494u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x10d498: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x10d498u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x10d49c: 0x511021  addu        $v0, $v0, $s1
    ctx->pc = 0x10d49cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x10d4a0: 0x82510000  lb          $s1, 0x0($s2)
    ctx->pc = 0x10d4a0u;
    SET_GPR_S32(ctx, 17, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x10d4a4: 0x2450ffd0  addiu       $s0, $v0, -0x30
    ctx->pc = 0x10d4a4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967248));
    // 0x10d4a8: 0x2622ffd0  addiu       $v0, $s1, -0x30
    ctx->pc = 0x10d4a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967248));
    // 0x10d4ac: 0x2c42000a  sltiu       $v0, $v0, 0xA
    ctx->pc = 0x10d4acu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)10) ? 1 : 0);
    // 0x10d4b0: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x10D4B0u;
    {
        const bool branch_taken_0x10d4b0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10D4B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D4B0u;
            // 0x10d4b4: 0x26520001  addiu       $s2, $s2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d4b0) {
            ctx->pc = 0x10D490u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10d490;
        }
    }
    ctx->pc = 0x10D4B8u;
    // 0x10d4b8: 0x1000ffb2  b           . + 4 + (-0x4E << 2)
    ctx->pc = 0x10D4B8u;
    {
        const bool branch_taken_0x10d4b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D4BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D4B8u;
            // 0x10d4bc: 0xafb001f0  sw          $s0, 0x1F0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 496), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d4b8) {
            ctx->pc = 0x10D384u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10d384;
        }
    }
    ctx->pc = 0x10D4C0u;
label_10d4c0:
    // 0x10d4c0: 0x1000ffac  b           . + 4 + (-0x54 << 2)
    ctx->pc = 0x10D4C0u;
    {
        const bool branch_taken_0x10d4c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D4C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D4C0u;
            // 0x10d4c4: 0x36f70008  ori         $s7, $s7, 0x8 (Delay Slot)
        SET_GPR_U64(ctx, 23, GPR_U64(ctx, 23) | (uint64_t)(uint16_t)8);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d4c0) {
            ctx->pc = 0x10D374u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10d374;
        }
    }
    ctx->pc = 0x10D4C8u;
label_10d4c8:
    // 0x10d4c8: 0x1000ffaa  b           . + 4 + (-0x56 << 2)
    ctx->pc = 0x10D4C8u;
    {
        const bool branch_taken_0x10d4c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D4CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D4C8u;
            // 0x10d4cc: 0x36f70040  ori         $s7, $s7, 0x40 (Delay Slot)
        SET_GPR_U64(ctx, 23, GPR_U64(ctx, 23) | (uint64_t)(uint16_t)64);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d4c8) {
            ctx->pc = 0x10D374u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10d374;
        }
    }
    ctx->pc = 0x10D4D0u;
label_10d4d0:
    // 0x10d4d0: 0x82430000  lb          $v1, 0x0($s2)
    ctx->pc = 0x10d4d0u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x10d4d4: 0x2402006c  addiu       $v0, $zero, 0x6C
    ctx->pc = 0x10d4d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 108));
    // 0x10d4d8: 0x14620005  bne         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x10D4D8u;
    {
        const bool branch_taken_0x10d4d8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x10D4DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D4D8u;
            // 0x10d4dc: 0x92440000  lbu         $a0, 0x0($s2) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d4d8) {
            ctx->pc = 0x10D4F0u;
            goto label_10d4f0;
        }
    }
    ctx->pc = 0x10D4E0u;
    // 0x10d4e0: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x10d4e0u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
label_10d4e4:
    // 0x10d4e4: 0x1000ffa3  b           . + 4 + (-0x5D << 2)
    ctx->pc = 0x10D4E4u;
    {
        const bool branch_taken_0x10d4e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D4E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D4E4u;
            // 0x10d4e8: 0x36f70020  ori         $s7, $s7, 0x20 (Delay Slot)
        SET_GPR_U64(ctx, 23, GPR_U64(ctx, 23) | (uint64_t)(uint16_t)32);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d4e4) {
            ctx->pc = 0x10D374u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10d374;
        }
    }
    ctx->pc = 0x10D4ECu;
    // 0x10d4ec: 0x0  nop
    ctx->pc = 0x10d4ecu;
    // NOP
label_10d4f0:
    // 0x10d4f0: 0x1000ffa1  b           . + 4 + (-0x5F << 2)
    ctx->pc = 0x10D4F0u;
    {
        const bool branch_taken_0x10d4f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D4F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D4F0u;
            // 0x10d4f4: 0x36f70010  ori         $s7, $s7, 0x10 (Delay Slot)
        SET_GPR_U64(ctx, 23, GPR_U64(ctx, 23) | (uint64_t)(uint16_t)16);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d4f0) {
            ctx->pc = 0x10D378u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10d378;
        }
    }
    ctx->pc = 0x10D4F8u;
label_10d4f8:
    // 0x10d4f8: 0x2c0102d  daddu       $v0, $s6, $zero
    ctx->pc = 0x10d4f8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d4fc: 0x26d60008  addiu       $s6, $s6, 0x8
    ctx->pc = 0x10d4fcu;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 8));
    // 0x10d500: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x10d500u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x10d504: 0x27b50060  addiu       $s5, $sp, 0x60
    ctx->pc = 0x10d504u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x10d508: 0x241e0001  addiu       $fp, $zero, 0x1
    ctx->pc = 0x10d508u;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x10d50c: 0x10000156  b           . + 4 + (0x156 << 2)
    ctx->pc = 0x10D50Cu;
    {
        const bool branch_taken_0x10d50c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D510u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D50Cu;
            // 0x10d510: 0xa2a30000  sb          $v1, 0x0($s5) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d50c) {
            ctx->pc = 0x10DA68u;
            goto label_10da68;
        }
    }
    ctx->pc = 0x10D514u;
    // 0x10d514: 0x0  nop
    ctx->pc = 0x10d514u;
    // NOP
label_10d518:
    // 0x10d518: 0x36f70010  ori         $s7, $s7, 0x10
    ctx->pc = 0x10d518u;
    SET_GPR_U64(ctx, 23, GPR_U64(ctx, 23) | (uint64_t)(uint16_t)16);
label_10d51c:
    // 0x10d51c: 0x32e20010  andi        $v0, $s7, 0x10
    ctx->pc = 0x10d51cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) & (uint64_t)(uint16_t)16);
    // 0x10d520: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x10D520u;
    {
        const bool branch_taken_0x10d520 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D524u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D520u;
            // 0x10d524: 0x2c0102d  daddu       $v0, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d520) {
            ctx->pc = 0x10D538u;
            goto label_10d538;
        }
    }
    ctx->pc = 0x10D528u;
    // 0x10d528: 0x26d60008  addiu       $s6, $s6, 0x8
    ctx->pc = 0x10d528u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 8));
    // 0x10d52c: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x10D52Cu;
    {
        const bool branch_taken_0x10d52c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D530u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D52Cu;
            // 0x10d530: 0xdc500000  ld          $s0, 0x0($v0) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d52c) {
            ctx->pc = 0x10D558u;
            goto label_10d558;
        }
    }
    ctx->pc = 0x10D534u;
    // 0x10d534: 0x0  nop
    ctx->pc = 0x10d534u;
    // NOP
label_10d538:
    // 0x10d538: 0x32e20040  andi        $v0, $s7, 0x40
    ctx->pc = 0x10d538u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) & (uint64_t)(uint16_t)64);
    // 0x10d53c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x10D53Cu;
    {
        const bool branch_taken_0x10d53c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D540u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D53Cu;
            // 0x10d540: 0x2c0102d  daddu       $v0, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d53c) {
            ctx->pc = 0x10D550u;
            goto label_10d550;
        }
    }
    ctx->pc = 0x10D544u;
    // 0x10d544: 0x26d60008  addiu       $s6, $s6, 0x8
    ctx->pc = 0x10d544u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 8));
    // 0x10d548: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x10D548u;
    {
        const bool branch_taken_0x10d548 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D54Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D548u;
            // 0x10d54c: 0x84500000  lh          $s0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d548) {
            ctx->pc = 0x10D558u;
            goto label_10d558;
        }
    }
    ctx->pc = 0x10D550u;
label_10d550:
    // 0x10d550: 0x26d60008  addiu       $s6, $s6, 0x8
    ctx->pc = 0x10d550u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 8));
    // 0x10d554: 0x8c500000  lw          $s0, 0x0($v0)
    ctx->pc = 0x10d554u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_10d558:
    // 0x10d558: 0x60100f7  bgez        $s0, . + 4 + (0xF7 << 2)
    ctx->pc = 0x10D558u;
    {
        const bool branch_taken_0x10d558 = (GPR_S64(ctx, 16) >= 0);
        ctx->pc = 0x10D55Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D558u;
            // 0x10d55c: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d558) {
            ctx->pc = 0x10D938u;
            goto label_10d938;
        }
    }
    ctx->pc = 0x10D560u;
    // 0x10d560: 0x2402002d  addiu       $v0, $zero, 0x2D
    ctx->pc = 0x10d560u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 45));
    // 0x10d564: 0x10802f  dsubu       $s0, $zero, $s0
    ctx->pc = 0x10d564u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 0) - GPR_U64(ctx, 16));
    // 0x10d568: 0x100000f3  b           . + 4 + (0xF3 << 2)
    ctx->pc = 0x10D568u;
    {
        const bool branch_taken_0x10d568 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D56Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D568u;
            // 0x10d56c: 0xa3a201d1  sb          $v0, 0x1D1($sp) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 29), 465), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d568) {
            ctx->pc = 0x10D938u;
            goto label_10d938;
        }
    }
    ctx->pc = 0x10D570u;
label_10d570:
    // 0x10d570: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x10d570u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10d574: 0x16820004  bne         $s4, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x10D574u;
    {
        const bool branch_taken_0x10d574 = (GPR_U64(ctx, 20) != GPR_U64(ctx, 2));
        ctx->pc = 0x10D578u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D574u;
            // 0x10d578: 0x24020067  addiu       $v0, $zero, 0x67 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 103));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d574) {
            ctx->pc = 0x10D588u;
            goto label_10d588;
        }
    }
    ctx->pc = 0x10D57Cu;
    // 0x10d57c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x10D57Cu;
    {
        const bool branch_taken_0x10d57c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D580u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D57Cu;
            // 0x10d580: 0x24140006  addiu       $s4, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d57c) {
            ctx->pc = 0x10D5A0u;
            goto label_10d5a0;
        }
    }
    ctx->pc = 0x10D584u;
    // 0x10d584: 0x0  nop
    ctx->pc = 0x10d584u;
    // NOP
label_10d588:
    // 0x10d588: 0x12220003  beq         $s1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x10D588u;
    {
        const bool branch_taken_0x10d588 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 2));
        ctx->pc = 0x10D58Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D588u;
            // 0x10d58c: 0x24020047  addiu       $v0, $zero, 0x47 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 71));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d588) {
            ctx->pc = 0x10D598u;
            goto label_10d598;
        }
    }
    ctx->pc = 0x10D590u;
    // 0x10d590: 0x16220004  bne         $s1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x10D590u;
    {
        const bool branch_taken_0x10d590 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        ctx->pc = 0x10D594u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D590u;
            // 0x10d594: 0x32e20008  andi        $v0, $s7, 0x8 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) & (uint64_t)(uint16_t)8);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d590) {
            ctx->pc = 0x10D5A4u;
            goto label_10d5a4;
        }
    }
    ctx->pc = 0x10D598u;
label_10d598:
    // 0x10d598: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x10d598u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x10d59c: 0x54a00a  movz        $s4, $v0, $s4
    ctx->pc = 0x10d59cu;
    if (GPR_U64(ctx, 20) == 0) SET_GPR_VEC(ctx, 20, GPR_VEC(ctx, 2));
label_10d5a0:
    // 0x10d5a0: 0x32e20008  andi        $v0, $s7, 0x8
    ctx->pc = 0x10d5a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) & (uint64_t)(uint16_t)8);
label_10d5a4:
    // 0x10d5a4: 0x2c0102d  daddu       $v0, $s6, $zero
    ctx->pc = 0x10d5a4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d5a8: 0xdc420000  ld          $v0, 0x0($v0)
    ctx->pc = 0x10d5a8u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x10d5ac: 0xffa201f8  sd          $v0, 0x1F8($sp)
    ctx->pc = 0x10d5acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 504), GPR_U64(ctx, 2));
    // 0x10d5b0: 0xdfa401f8  ld          $a0, 0x1F8($sp)
    ctx->pc = 0x10d5b0u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 29), 504)));
    // 0x10d5b4: 0xc042874  jal         func_10A1D0
    ctx->pc = 0x10D5B4u;
    SET_GPR_U32(ctx, 31, 0x10D5BCu);
    ctx->pc = 0x10D5B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10D5B4u;
            // 0x10d5b8: 0x26d60008  addiu       $s6, $s6, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A1D0u;
    if (runtime->hasFunction(0x10A1D0u)) {
        auto targetFn = runtime->lookupFunction(0x10A1D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D5BCu; }
        if (ctx->pc != 0x10D5BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A1D0_0x10a1d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D5BCu; }
        if (ctx->pc != 0x10D5BCu) { return; }
    }
    ctx->pc = 0x10D5BCu;
label_10d5bc:
    // 0x10d5bc: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x10D5BCu;
    {
        const bool branch_taken_0x10d5bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10d5bc) {
            ctx->pc = 0x10D5F8u;
            goto label_10d5f8;
        }
    }
    ctx->pc = 0x10D5C4u;
    // 0x10d5c4: 0xdfa401f8  ld          $a0, 0x1F8($sp)
    ctx->pc = 0x10d5c4u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 29), 504)));
    // 0x10d5c8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x10d5c8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d5cc: 0xc0448a6  jal         func_112298
    ctx->pc = 0x10D5CCu;
    SET_GPR_U32(ctx, 31, 0x10D5D4u);
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D5D4u; }
        if (ctx->pc != 0x10D5D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D5D4u; }
        if (ctx->pc != 0x10D5D4u) { return; }
    }
    ctx->pc = 0x10D5D4u;
label_10d5d4:
    // 0x10d5d4: 0x4410004  bgez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x10D5D4u;
    {
        const bool branch_taken_0x10d5d4 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x10D5D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D5D4u;
            // 0x10d5d8: 0x3c020023  lui         $v0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d5d4) {
            ctx->pc = 0x10D5E8u;
            goto label_10d5e8;
        }
    }
    ctx->pc = 0x10D5DCu;
    // 0x10d5dc: 0x2402002d  addiu       $v0, $zero, 0x2D
    ctx->pc = 0x10d5dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 45));
    // 0x10d5e0: 0xa3a201d1  sb          $v0, 0x1D1($sp)
    ctx->pc = 0x10d5e0u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 465), (uint8_t)GPR_U32(ctx, 2));
    // 0x10d5e4: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x10d5e4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
label_10d5e8:
    // 0x10d5e8: 0x241e0003  addiu       $fp, $zero, 0x3
    ctx->pc = 0x10d5e8u;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x10d5ec: 0x1000011f  b           . + 4 + (0x11F << 2)
    ctx->pc = 0x10D5ECu;
    {
        const bool branch_taken_0x10d5ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D5F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D5ECu;
            // 0x10d5f0: 0x24557b40  addiu       $s5, $v0, 0x7B40 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 2), 31552));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d5ec) {
            ctx->pc = 0x10DA6Cu;
            goto label_10da6c;
        }
    }
    ctx->pc = 0x10D5F4u;
    // 0x10d5f4: 0x0  nop
    ctx->pc = 0x10d5f4u;
    // NOP
label_10d5f8:
    // 0x10d5f8: 0xdfa401f8  ld          $a0, 0x1F8($sp)
    ctx->pc = 0x10d5f8u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 29), 504)));
    // 0x10d5fc: 0xc042886  jal         func_10A218
    ctx->pc = 0x10D5FCu;
    SET_GPR_U32(ctx, 31, 0x10D604u);
    ctx->pc = 0x10A218u;
    if (runtime->hasFunction(0x10A218u)) {
        auto targetFn = runtime->lookupFunction(0x10A218u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D604u; }
        if (ctx->pc != 0x10D604u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A218_0x10a218(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D604u; }
        if (ctx->pc != 0x10D604u) { return; }
    }
    ctx->pc = 0x10D604u;
label_10d604:
    // 0x10d604: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x10D604u;
    {
        const bool branch_taken_0x10d604 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D608u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D604u;
            // 0x10d608: 0x3c020023  lui         $v0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d604) {
            ctx->pc = 0x10D618u;
            goto label_10d618;
        }
    }
    ctx->pc = 0x10D60Cu;
    // 0x10d60c: 0x241e0003  addiu       $fp, $zero, 0x3
    ctx->pc = 0x10d60cu;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x10d610: 0x10000116  b           . + 4 + (0x116 << 2)
    ctx->pc = 0x10D610u;
    {
        const bool branch_taken_0x10d610 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D614u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D610u;
            // 0x10d614: 0x24557b48  addiu       $s5, $v0, 0x7B48 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 2), 31560));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d610) {
            ctx->pc = 0x10DA6Cu;
            goto label_10da6c;
        }
    }
    ctx->pc = 0x10D618u;
label_10d618:
    // 0x10d618: 0x36f70100  ori         $s7, $s7, 0x100
    ctx->pc = 0x10d618u;
    SET_GPR_U64(ctx, 23, GPR_U64(ctx, 23) | (uint64_t)(uint16_t)256);
    // 0x10d61c: 0x8fa401e4  lw          $a0, 0x1E4($sp)
    ctx->pc = 0x10d61cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 484)));
    // 0x10d620: 0xdfa501f8  ld          $a1, 0x1F8($sp)
    ctx->pc = 0x10d620u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 29), 504)));
    // 0x10d624: 0x280302d  daddu       $a2, $s4, $zero
    ctx->pc = 0x10d624u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d628: 0x2e0382d  daddu       $a3, $s7, $zero
    ctx->pc = 0x10d628u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d62c: 0x27a801d0  addiu       $t0, $sp, 0x1D0
    ctx->pc = 0x10d62cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 464));
    // 0x10d630: 0x27a901dc  addiu       $t1, $sp, 0x1DC
    ctx->pc = 0x10d630u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 29), 476));
    // 0x10d634: 0x220502d  daddu       $t2, $s1, $zero
    ctx->pc = 0x10d634u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d638: 0xc043a14  jal         func_10E850
    ctx->pc = 0x10D638u;
    SET_GPR_U32(ctx, 31, 0x10D640u);
    ctx->pc = 0x10D63Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10D638u;
            // 0x10d63c: 0x27ab01e0  addiu       $t3, $sp, 0x1E0 (Delay Slot)
        SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 29), 480));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10E850u;
    if (runtime->hasFunction(0x10E850u)) {
        auto targetFn = runtime->lookupFunction(0x10E850u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D640u; }
        if (ctx->pc != 0x10D640u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010E850_0x10e850(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D640u; }
        if (ctx->pc != 0x10D640u) { return; }
    }
    ctx->pc = 0x10D640u;
label_10d640:
    // 0x10d640: 0x40a82d  daddu       $s5, $v0, $zero
    ctx->pc = 0x10d640u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d644: 0x24020067  addiu       $v0, $zero, 0x67
    ctx->pc = 0x10d644u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 103));
    // 0x10d648: 0x12220003  beq         $s1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x10D648u;
    {
        const bool branch_taken_0x10d648 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 2));
        ctx->pc = 0x10D64Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D648u;
            // 0x10d64c: 0x24020047  addiu       $v0, $zero, 0x47 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 71));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d648) {
            ctx->pc = 0x10D658u;
            goto label_10d658;
        }
    }
    ctx->pc = 0x10D650u;
    // 0x10d650: 0x1622000d  bne         $s1, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x10D650u;
    {
        const bool branch_taken_0x10d650 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        ctx->pc = 0x10D654u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D650u;
            // 0x10d654: 0x8fa701dc  lw          $a3, 0x1DC($sp) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 476)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d650) {
            ctx->pc = 0x10D688u;
            goto label_10d688;
        }
    }
    ctx->pc = 0x10D658u;
label_10d658:
    // 0x10d658: 0x8fa701dc  lw          $a3, 0x1DC($sp)
    ctx->pc = 0x10d658u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 476)));
    // 0x10d65c: 0x28e2fffd  slti        $v0, $a3, -0x3
    ctx->pc = 0x10d65cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 7) < (int64_t)(int32_t)4294967293) ? 1 : 0);
    // 0x10d660: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x10D660u;
    {
        const bool branch_taken_0x10d660 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10D664u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D660u;
            // 0x10d664: 0x24020065  addiu       $v0, $zero, 0x65 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d660) {
            ctx->pc = 0x10D678u;
            goto label_10d678;
        }
    }
    ctx->pc = 0x10D668u;
    // 0x10d668: 0x287102a  slt         $v0, $s4, $a3
    ctx->pc = 0x10d668u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 20) < (int64_t)GPR_S64(ctx, 7)) ? 1 : 0);
    // 0x10d66c: 0x50400006  beql        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x10D66Cu;
    {
        const bool branch_taken_0x10d66c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10d66c) {
            ctx->pc = 0x10D670u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10D66Cu;
            // 0x10d670: 0x24110067  addiu       $s1, $zero, 0x67 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 103));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10D688u;
            goto label_10d688;
        }
    }
    ctx->pc = 0x10D674u;
    // 0x10d674: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x10d674u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
label_10d678:
    // 0x10d678: 0x3a240067  xori        $a0, $s1, 0x67
    ctx->pc = 0x10d678u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) ^ (uint64_t)(uint16_t)103);
    // 0x10d67c: 0x24030045  addiu       $v1, $zero, 0x45
    ctx->pc = 0x10d67cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 69));
    // 0x10d680: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x10d680u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d684: 0x64880b  movn        $s1, $v1, $a0
    ctx->pc = 0x10d684u;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 17, GPR_VEC(ctx, 3));
label_10d688:
    // 0x10d688: 0x2a220066  slti        $v0, $s1, 0x66
    ctx->pc = 0x10d688u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)102) ? 1 : 0);
    // 0x10d68c: 0x50400012  beql        $v0, $zero, . + 4 + (0x12 << 2)
    ctx->pc = 0x10D68Cu;
    {
        const bool branch_taken_0x10d68c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10d68c) {
            ctx->pc = 0x10D690u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10D68Cu;
            // 0x10d690: 0x24020066  addiu       $v0, $zero, 0x66 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10D6D8u;
            goto label_10d6d8;
        }
    }
    ctx->pc = 0x10D694u;
    // 0x10d694: 0x24e7ffff  addiu       $a3, $a3, -0x1
    ctx->pc = 0x10d694u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x10d698: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x10d698u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d69c: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x10d69cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d6a0: 0xe0282d  daddu       $a1, $a3, $zero
    ctx->pc = 0x10d6a0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d6a4: 0xc043a84  jal         func_10EA10
    ctx->pc = 0x10D6A4u;
    SET_GPR_U32(ctx, 31, 0x10D6ACu);
    ctx->pc = 0x10D6A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10D6A4u;
            // 0x10d6a8: 0xafa701dc  sw          $a3, 0x1DC($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 476), GPR_U32(ctx, 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10EA10u;
    if (runtime->hasFunction(0x10EA10u)) {
        auto targetFn = runtime->lookupFunction(0x10EA10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D6ACu; }
        if (ctx->pc != 0x10D6ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010EA10_0x10ea10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D6ACu; }
        if (ctx->pc != 0x10D6ACu) { return; }
    }
    ctx->pc = 0x10D6ACu;
label_10d6ac:
    // 0x10d6ac: 0xafa20200  sw          $v0, 0x200($sp)
    ctx->pc = 0x10d6acu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 512), GPR_U32(ctx, 2));
    // 0x10d6b0: 0x8fa201e0  lw          $v0, 0x1E0($sp)
    ctx->pc = 0x10d6b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 480)));
    // 0x10d6b4: 0x8fa60200  lw          $a2, 0x200($sp)
    ctx->pc = 0x10d6b4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 512)));
    // 0x10d6b8: 0x28430002  slti        $v1, $v0, 0x2
    ctx->pc = 0x10d6b8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x10d6bc: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x10D6BCu;
    {
        const bool branch_taken_0x10d6bc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D6C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D6BCu;
            // 0x10d6c0: 0xc2f021  addu        $fp, $a2, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d6bc) {
            ctx->pc = 0x10D6D0u;
            goto label_10d6d0;
        }
    }
    ctx->pc = 0x10D6C4u;
    // 0x10d6c4: 0x32e20001  andi        $v0, $s7, 0x1
    ctx->pc = 0x10d6c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) & (uint64_t)(uint16_t)1);
    // 0x10d6c8: 0x1040001c  beqz        $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x10D6C8u;
    {
        const bool branch_taken_0x10d6c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D6CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D6C8u;
            // 0x10d6cc: 0x83a201d0  lb          $v0, 0x1D0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 464)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d6c8) {
            ctx->pc = 0x10D73Cu;
            goto label_10d73c;
        }
    }
    ctx->pc = 0x10D6D0u;
label_10d6d0:
    // 0x10d6d0: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x10D6D0u;
    {
        const bool branch_taken_0x10d6d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D6D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D6D0u;
            // 0x10d6d4: 0x27de0001  addiu       $fp, $fp, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 30), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d6d0) {
            ctx->pc = 0x10D738u;
            goto label_10d738;
        }
    }
    ctx->pc = 0x10D6D8u;
label_10d6d8:
    // 0x10d6d8: 0x1622000b  bne         $s1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x10D6D8u;
    {
        const bool branch_taken_0x10d6d8 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        ctx->pc = 0x10D6DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D6D8u;
            // 0x10d6dc: 0x8fa501e0  lw          $a1, 0x1E0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 480)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d6d8) {
            ctx->pc = 0x10D708u;
            goto label_10d708;
        }
    }
    ctx->pc = 0x10D6E0u;
    // 0x10d6e0: 0x18e00015  blez        $a3, . + 4 + (0x15 << 2)
    ctx->pc = 0x10D6E0u;
    {
        const bool branch_taken_0x10d6e0 = (GPR_S64(ctx, 7) <= 0);
        ctx->pc = 0x10D6E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D6E0u;
            // 0x10d6e4: 0x269e0002  addiu       $fp, $s4, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 20), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d6e0) {
            ctx->pc = 0x10D738u;
            goto label_10d738;
        }
    }
    ctx->pc = 0x10D6E8u;
    // 0x10d6e8: 0x16800004  bnez        $s4, . + 4 + (0x4 << 2)
    ctx->pc = 0x10D6E8u;
    {
        const bool branch_taken_0x10d6e8 = (GPR_U64(ctx, 20) != GPR_U64(ctx, 0));
        ctx->pc = 0x10D6ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D6E8u;
            // 0x10d6ec: 0xe0f02d  daddu       $fp, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d6e8) {
            ctx->pc = 0x10D6FCu;
            goto label_10d6fc;
        }
    }
    ctx->pc = 0x10D6F0u;
    // 0x10d6f0: 0x32e20001  andi        $v0, $s7, 0x1
    ctx->pc = 0x10d6f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) & (uint64_t)(uint16_t)1);
    // 0x10d6f4: 0x10400011  beqz        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x10D6F4u;
    {
        const bool branch_taken_0x10d6f4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D6F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D6F4u;
            // 0x10d6f8: 0x83a201d0  lb          $v0, 0x1D0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 464)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d6f4) {
            ctx->pc = 0x10D73Cu;
            goto label_10d73c;
        }
    }
    ctx->pc = 0x10D6FCu;
label_10d6fc:
    // 0x10d6fc: 0xf41021  addu        $v0, $a3, $s4
    ctx->pc = 0x10d6fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 20)));
    // 0x10d700: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x10D700u;
    {
        const bool branch_taken_0x10d700 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D704u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D700u;
            // 0x10d704: 0x245e0001  addiu       $fp, $v0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d700) {
            ctx->pc = 0x10D738u;
            goto label_10d738;
        }
    }
    ctx->pc = 0x10D708u;
label_10d708:
    // 0x10d708: 0xe5102a  slt         $v0, $a3, $a1
    ctx->pc = 0x10d708u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x10d70c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x10D70Cu;
    {
        const bool branch_taken_0x10d70c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10D710u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D70Cu;
            // 0x10d710: 0x32e20001  andi        $v0, $s7, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) & (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d70c) {
            ctx->pc = 0x10D728u;
            goto label_10d728;
        }
    }
    ctx->pc = 0x10D714u;
    // 0x10d714: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x10D714u;
    {
        const bool branch_taken_0x10d714 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D718u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D714u;
            // 0x10d718: 0xe0f02d  daddu       $fp, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d714) {
            ctx->pc = 0x10D738u;
            goto label_10d738;
        }
    }
    ctx->pc = 0x10D71Cu;
    // 0x10d71c: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x10D71Cu;
    {
        const bool branch_taken_0x10d71c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D720u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D71Cu;
            // 0x10d720: 0x24fe0001  addiu       $fp, $a3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d71c) {
            ctx->pc = 0x10D738u;
            goto label_10d738;
        }
    }
    ctx->pc = 0x10D724u;
    // 0x10d724: 0x0  nop
    ctx->pc = 0x10d724u;
    // NOP
label_10d728:
    // 0x10d728: 0x5ce00003  bgtzl       $a3, . + 4 + (0x3 << 2)
    ctx->pc = 0x10D728u;
    {
        const bool branch_taken_0x10d728 = (GPR_S64(ctx, 7) > 0);
        if (branch_taken_0x10d728) {
            ctx->pc = 0x10D72Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10D728u;
            // 0x10d72c: 0x24be0001  addiu       $fp, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10D738u;
            goto label_10d738;
        }
    }
    ctx->pc = 0x10D730u;
    // 0x10d730: 0xa71023  subu        $v0, $a1, $a3
    ctx->pc = 0x10d730u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 7)));
    // 0x10d734: 0x245e0002  addiu       $fp, $v0, 0x2
    ctx->pc = 0x10d734u;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 2), 2));
label_10d738:
    // 0x10d738: 0x83a201d0  lb          $v0, 0x1D0($sp)
    ctx->pc = 0x10d738u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 464)));
label_10d73c:
    // 0x10d73c: 0x104000cb  beqz        $v0, . + 4 + (0xCB << 2)
    ctx->pc = 0x10D73Cu;
    {
        const bool branch_taken_0x10d73c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D740u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D73Cu;
            // 0x10d740: 0x2402002d  addiu       $v0, $zero, 0x2D (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 45));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d73c) {
            ctx->pc = 0x10DA6Cu;
            goto label_10da6c;
        }
    }
    ctx->pc = 0x10D744u;
    // 0x10d744: 0x100000c9  b           . + 4 + (0xC9 << 2)
    ctx->pc = 0x10D744u;
    {
        const bool branch_taken_0x10d744 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D748u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D744u;
            // 0x10d748: 0xa3a201d1  sb          $v0, 0x1D1($sp) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 29), 465), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d744) {
            ctx->pc = 0x10DA6Cu;
            goto label_10da6c;
        }
    }
    ctx->pc = 0x10D74Cu;
    // 0x10d74c: 0x0  nop
    ctx->pc = 0x10d74cu;
    // NOP
label_10d750:
    // 0x10d750: 0x32e20010  andi        $v0, $s7, 0x10
    ctx->pc = 0x10d750u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) & (uint64_t)(uint16_t)16);
    // 0x10d754: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x10D754u;
    {
        const bool branch_taken_0x10d754 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D758u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D754u;
            // 0x10d758: 0x32e20040  andi        $v0, $s7, 0x40 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) & (uint64_t)(uint16_t)64);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d754) {
            ctx->pc = 0x10D778u;
            goto label_10d778;
        }
    }
    ctx->pc = 0x10D75Cu;
    // 0x10d75c: 0x2c0182d  daddu       $v1, $s6, $zero
    ctx->pc = 0x10d75cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d760: 0x26d60008  addiu       $s6, $s6, 0x8
    ctx->pc = 0x10d760u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 8));
    // 0x10d764: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x10d764u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x10d768: 0x8fa301ec  lw          $v1, 0x1EC($sp)
    ctx->pc = 0x10d768u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 492)));
    // 0x10d76c: 0x1000fed0  b           . + 4 + (-0x130 << 2)
    ctx->pc = 0x10D76Cu;
    {
        const bool branch_taken_0x10d76c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D770u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D76Cu;
            // 0x10d770: 0xfc430000  sd          $v1, 0x0($v0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d76c) {
            ctx->pc = 0x10D2B0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10d2b0;
        }
    }
    ctx->pc = 0x10D774u;
    // 0x10d774: 0x0  nop
    ctx->pc = 0x10d774u;
    // NOP
label_10d778:
    // 0x10d778: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x10D778u;
    {
        const bool branch_taken_0x10d778 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D77Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D778u;
            // 0x10d77c: 0x2c0182d  daddu       $v1, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d778) {
            ctx->pc = 0x10D798u;
            goto label_10d798;
        }
    }
    ctx->pc = 0x10D780u;
    // 0x10d780: 0x26d60008  addiu       $s6, $s6, 0x8
    ctx->pc = 0x10d780u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 8));
    // 0x10d784: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x10d784u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x10d788: 0x8fa401ec  lw          $a0, 0x1EC($sp)
    ctx->pc = 0x10d788u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 492)));
    // 0x10d78c: 0x1000fec8  b           . + 4 + (-0x138 << 2)
    ctx->pc = 0x10D78Cu;
    {
        const bool branch_taken_0x10d78c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D790u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D78Cu;
            // 0x10d790: 0xa4440000  sh          $a0, 0x0($v0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d78c) {
            ctx->pc = 0x10D2B0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10d2b0;
        }
    }
    ctx->pc = 0x10D794u;
    // 0x10d794: 0x0  nop
    ctx->pc = 0x10d794u;
    // NOP
label_10d798:
    // 0x10d798: 0x26d60008  addiu       $s6, $s6, 0x8
    ctx->pc = 0x10d798u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 8));
    // 0x10d79c: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x10d79cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x10d7a0: 0x8fa501ec  lw          $a1, 0x1EC($sp)
    ctx->pc = 0x10d7a0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 492)));
    // 0x10d7a4: 0x1000fec2  b           . + 4 + (-0x13E << 2)
    ctx->pc = 0x10D7A4u;
    {
        const bool branch_taken_0x10d7a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D7A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D7A4u;
            // 0x10d7a8: 0xac450000  sw          $a1, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d7a4) {
            ctx->pc = 0x10D2B0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10d2b0;
        }
    }
    ctx->pc = 0x10D7ACu;
    // 0x10d7ac: 0x0  nop
    ctx->pc = 0x10d7acu;
    // NOP
label_10d7b0:
    // 0x10d7b0: 0x36f70010  ori         $s7, $s7, 0x10
    ctx->pc = 0x10d7b0u;
    SET_GPR_U64(ctx, 23, GPR_U64(ctx, 23) | (uint64_t)(uint16_t)16);
label_10d7b4:
    // 0x10d7b4: 0x32e20010  andi        $v0, $s7, 0x10
    ctx->pc = 0x10d7b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) & (uint64_t)(uint16_t)16);
    // 0x10d7b8: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x10D7B8u;
    {
        const bool branch_taken_0x10d7b8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D7BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D7B8u;
            // 0x10d7bc: 0x2c0102d  daddu       $v0, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d7b8) {
            ctx->pc = 0x10D7D0u;
            goto label_10d7d0;
        }
    }
    ctx->pc = 0x10D7C0u;
    // 0x10d7c0: 0x26d60008  addiu       $s6, $s6, 0x8
    ctx->pc = 0x10d7c0u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 8));
    // 0x10d7c4: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x10D7C4u;
    {
        const bool branch_taken_0x10d7c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D7C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D7C4u;
            // 0x10d7c8: 0xdc500000  ld          $s0, 0x0($v0) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d7c4) {
            ctx->pc = 0x10D7F0u;
            goto label_10d7f0;
        }
    }
    ctx->pc = 0x10D7CCu;
    // 0x10d7cc: 0x0  nop
    ctx->pc = 0x10d7ccu;
    // NOP
label_10d7d0:
    // 0x10d7d0: 0x32e20040  andi        $v0, $s7, 0x40
    ctx->pc = 0x10d7d0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) & (uint64_t)(uint16_t)64);
    // 0x10d7d4: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x10D7D4u;
    {
        const bool branch_taken_0x10d7d4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D7D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D7D4u;
            // 0x10d7d8: 0x2c0102d  daddu       $v0, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d7d4) {
            ctx->pc = 0x10D7E8u;
            goto label_10d7e8;
        }
    }
    ctx->pc = 0x10D7DCu;
    // 0x10d7dc: 0x26d60008  addiu       $s6, $s6, 0x8
    ctx->pc = 0x10d7dcu;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 8));
    // 0x10d7e0: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x10D7E0u;
    {
        const bool branch_taken_0x10d7e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D7E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D7E0u;
            // 0x10d7e4: 0x94500000  lhu         $s0, 0x0($v0) (Delay Slot)
        SET_GPR_U32(ctx, 16, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d7e0) {
            ctx->pc = 0x10D7F0u;
            goto label_10d7f0;
        }
    }
    ctx->pc = 0x10D7E8u;
label_10d7e8:
    // 0x10d7e8: 0x26d60008  addiu       $s6, $s6, 0x8
    ctx->pc = 0x10d7e8u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 8));
    // 0x10d7ec: 0x9c500000  lwu         $s0, 0x0($v0)
    ctx->pc = 0x10d7ecu;
    SET_GPR_U32(ctx, 16, READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_10d7f0:
    // 0x10d7f0: 0x10000050  b           . + 4 + (0x50 << 2)
    ctx->pc = 0x10D7F0u;
    {
        const bool branch_taken_0x10d7f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D7F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D7F0u;
            // 0x10d7f4: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d7f0) {
            ctx->pc = 0x10D934u;
            goto label_10d934;
        }
    }
    ctx->pc = 0x10D7F8u;
label_10d7f8:
    // 0x10d7f8: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x10d7f8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x10d7fc: 0x2c0182d  daddu       $v1, $s6, $zero
    ctx->pc = 0x10d7fcu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d800: 0x24427b50  addiu       $v0, $v0, 0x7B50
    ctx->pc = 0x10d800u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 31568));
    // 0x10d804: 0x8c700000  lw          $s0, 0x0($v1)
    ctx->pc = 0x10d804u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x10d808: 0x26d60008  addiu       $s6, $s6, 0x8
    ctx->pc = 0x10d808u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 8));
    // 0x10d80c: 0x36f70002  ori         $s7, $s7, 0x2
    ctx->pc = 0x10d80cu;
    SET_GPR_U64(ctx, 23, GPR_U64(ctx, 23) | (uint64_t)(uint16_t)2);
    // 0x10d810: 0xafa2020c  sw          $v0, 0x20C($sp)
    ctx->pc = 0x10d810u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 524), GPR_U32(ctx, 2));
    // 0x10d814: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x10d814u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x10d818: 0x10000046  b           . + 4 + (0x46 << 2)
    ctx->pc = 0x10D818u;
    {
        const bool branch_taken_0x10d818 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D81Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D818u;
            // 0x10d81c: 0x24110078  addiu       $s1, $zero, 0x78 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 120));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d818) {
            ctx->pc = 0x10D934u;
            goto label_10d934;
        }
    }
    ctx->pc = 0x10D820u;
label_10d820:
    // 0x10d820: 0x2c0102d  daddu       $v0, $s6, $zero
    ctx->pc = 0x10d820u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d824: 0x8c550000  lw          $s5, 0x0($v0)
    ctx->pc = 0x10d824u;
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x10d828: 0x16a00003  bnez        $s5, . + 4 + (0x3 << 2)
    ctx->pc = 0x10D828u;
    {
        const bool branch_taken_0x10d828 = (GPR_U64(ctx, 21) != GPR_U64(ctx, 0));
        ctx->pc = 0x10D82Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D828u;
            // 0x10d82c: 0x26d60008  addiu       $s6, $s6, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d828) {
            ctx->pc = 0x10D838u;
            goto label_10d838;
        }
    }
    ctx->pc = 0x10D830u;
    // 0x10d830: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x10d830u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x10d834: 0x24557b68  addiu       $s5, $v0, 0x7B68
    ctx->pc = 0x10d834u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 2), 31592));
label_10d838:
    // 0x10d838: 0x680000d  bltz        $s4, . + 4 + (0xD << 2)
    ctx->pc = 0x10D838u;
    {
        const bool branch_taken_0x10d838 = (GPR_S64(ctx, 20) < 0);
        ctx->pc = 0x10D83Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D838u;
            // 0x10d83c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d838) {
            ctx->pc = 0x10D870u;
            goto label_10d870;
        }
    }
    ctx->pc = 0x10D840u;
    // 0x10d840: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x10d840u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d844: 0xc041e4e  jal         func_107938
    ctx->pc = 0x10D844u;
    SET_GPR_U32(ctx, 31, 0x10D84Cu);
    ctx->pc = 0x10D848u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10D844u;
            // 0x10d848: 0x280302d  daddu       $a2, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107938u;
    if (runtime->hasFunction(0x107938u)) {
        auto targetFn = runtime->lookupFunction(0x107938u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D84Cu; }
        if (ctx->pc != 0x10D84Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107938_0x107938(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D84Cu; }
        if (ctx->pc != 0x10D84Cu) { return; }
    }
    ctx->pc = 0x10D84Cu;
label_10d84c:
    // 0x10d84c: 0x10400086  beqz        $v0, . + 4 + (0x86 << 2)
    ctx->pc = 0x10D84Cu;
    {
        const bool branch_taken_0x10d84c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D850u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D84Cu;
            // 0x10d850: 0x280f02d  daddu       $fp, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d84c) {
            ctx->pc = 0x10DA68u;
            goto label_10da68;
        }
    }
    ctx->pc = 0x10D854u;
    // 0x10d854: 0x55f023  subu        $fp, $v0, $s5
    ctx->pc = 0x10d854u;
    SET_GPR_S32(ctx, 30, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 21)));
    // 0x10d858: 0x29e102a  slt         $v0, $s4, $fp
    ctx->pc = 0x10d858u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 20) < (int64_t)GPR_S64(ctx, 30)) ? 1 : 0);
    // 0x10d85c: 0x50400083  beql        $v0, $zero, . + 4 + (0x83 << 2)
    ctx->pc = 0x10D85Cu;
    {
        const bool branch_taken_0x10d85c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10d85c) {
            ctx->pc = 0x10D860u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10D85Cu;
            // 0x10d860: 0xa3a001d1  sb          $zero, 0x1D1($sp) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 29), 465), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10DA6Cu;
            goto label_10da6c;
        }
    }
    ctx->pc = 0x10D864u;
    // 0x10d864: 0x10000080  b           . + 4 + (0x80 << 2)
    ctx->pc = 0x10D864u;
    {
        const bool branch_taken_0x10d864 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D868u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D864u;
            // 0x10d868: 0x280f02d  daddu       $fp, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d864) {
            ctx->pc = 0x10DA68u;
            goto label_10da68;
        }
    }
    ctx->pc = 0x10D86Cu;
    // 0x10d86c: 0x0  nop
    ctx->pc = 0x10d86cu;
    // NOP
label_10d870:
    // 0x10d870: 0xc042c56  jal         func_10B158
    ctx->pc = 0x10D870u;
    SET_GPR_U32(ctx, 31, 0x10D878u);
    ctx->pc = 0x10D874u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10D870u;
            // 0x10d874: 0x2a0202d  daddu       $a0, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D878u; }
        if (ctx->pc != 0x10D878u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D878u; }
        if (ctx->pc != 0x10D878u) { return; }
    }
    ctx->pc = 0x10D878u;
label_10d878:
    // 0x10d878: 0x1000007b  b           . + 4 + (0x7B << 2)
    ctx->pc = 0x10D878u;
    {
        const bool branch_taken_0x10d878 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D87Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D878u;
            // 0x10d87c: 0x40f02d  daddu       $fp, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d878) {
            ctx->pc = 0x10DA68u;
            goto label_10da68;
        }
    }
    ctx->pc = 0x10D880u;
label_10d880:
    // 0x10d880: 0x36f70010  ori         $s7, $s7, 0x10
    ctx->pc = 0x10d880u;
    SET_GPR_U64(ctx, 23, GPR_U64(ctx, 23) | (uint64_t)(uint16_t)16);
label_10d884:
    // 0x10d884: 0x32e20010  andi        $v0, $s7, 0x10
    ctx->pc = 0x10d884u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) & (uint64_t)(uint16_t)16);
    // 0x10d888: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x10D888u;
    {
        const bool branch_taken_0x10d888 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D88Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D888u;
            // 0x10d88c: 0x2c0102d  daddu       $v0, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d888) {
            ctx->pc = 0x10D8A0u;
            goto label_10d8a0;
        }
    }
    ctx->pc = 0x10D890u;
    // 0x10d890: 0x26d60008  addiu       $s6, $s6, 0x8
    ctx->pc = 0x10d890u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 8));
    // 0x10d894: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x10D894u;
    {
        const bool branch_taken_0x10d894 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D898u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D894u;
            // 0x10d898: 0xdc500000  ld          $s0, 0x0($v0) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d894) {
            ctx->pc = 0x10D8C0u;
            goto label_10d8c0;
        }
    }
    ctx->pc = 0x10D89Cu;
    // 0x10d89c: 0x0  nop
    ctx->pc = 0x10d89cu;
    // NOP
label_10d8a0:
    // 0x10d8a0: 0x32e20040  andi        $v0, $s7, 0x40
    ctx->pc = 0x10d8a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) & (uint64_t)(uint16_t)64);
    // 0x10d8a4: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x10D8A4u;
    {
        const bool branch_taken_0x10d8a4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D8A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D8A4u;
            // 0x10d8a8: 0x2c0102d  daddu       $v0, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d8a4) {
            ctx->pc = 0x10D8B8u;
            goto label_10d8b8;
        }
    }
    ctx->pc = 0x10D8ACu;
    // 0x10d8ac: 0x26d60008  addiu       $s6, $s6, 0x8
    ctx->pc = 0x10d8acu;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 8));
    // 0x10d8b0: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x10D8B0u;
    {
        const bool branch_taken_0x10d8b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D8B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D8B0u;
            // 0x10d8b4: 0x94500000  lhu         $s0, 0x0($v0) (Delay Slot)
        SET_GPR_U32(ctx, 16, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d8b0) {
            ctx->pc = 0x10D8C0u;
            goto label_10d8c0;
        }
    }
    ctx->pc = 0x10D8B8u;
label_10d8b8:
    // 0x10d8b8: 0x26d60008  addiu       $s6, $s6, 0x8
    ctx->pc = 0x10d8b8u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 8));
    // 0x10d8bc: 0x9c500000  lwu         $s0, 0x0($v0)
    ctx->pc = 0x10d8bcu;
    SET_GPR_U32(ctx, 16, READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_10d8c0:
    // 0x10d8c0: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x10D8C0u;
    {
        const bool branch_taken_0x10d8c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D8C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D8C0u;
            // 0x10d8c4: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d8c0) {
            ctx->pc = 0x10D934u;
            goto label_10d934;
        }
    }
    ctx->pc = 0x10D8C8u;
label_10d8c8:
    // 0x10d8c8: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x10d8c8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x10d8cc: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x10D8CCu;
    {
        const bool branch_taken_0x10d8cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D8D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D8CCu;
            // 0x10d8d0: 0x24427b70  addiu       $v0, $v0, 0x7B70 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 31600));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d8cc) {
            ctx->pc = 0x10D8E0u;
            goto label_10d8e0;
        }
    }
    ctx->pc = 0x10D8D4u;
    // 0x10d8d4: 0x0  nop
    ctx->pc = 0x10d8d4u;
    // NOP
label_10d8d8:
    // 0x10d8d8: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x10d8d8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x10d8dc: 0x24427b50  addiu       $v0, $v0, 0x7B50
    ctx->pc = 0x10d8dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 31568));
label_10d8e0:
    // 0x10d8e0: 0xafa2020c  sw          $v0, 0x20C($sp)
    ctx->pc = 0x10d8e0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 524), GPR_U32(ctx, 2));
    // 0x10d8e4: 0x32e20010  andi        $v0, $s7, 0x10
    ctx->pc = 0x10d8e4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) & (uint64_t)(uint16_t)16);
    // 0x10d8e8: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x10D8E8u;
    {
        const bool branch_taken_0x10d8e8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D8ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D8E8u;
            // 0x10d8ec: 0x2c0102d  daddu       $v0, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d8e8) {
            ctx->pc = 0x10D900u;
            goto label_10d900;
        }
    }
    ctx->pc = 0x10D8F0u;
    // 0x10d8f0: 0x26d60008  addiu       $s6, $s6, 0x8
    ctx->pc = 0x10d8f0u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 8));
    // 0x10d8f4: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x10D8F4u;
    {
        const bool branch_taken_0x10d8f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D8F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D8F4u;
            // 0x10d8f8: 0xdc500000  ld          $s0, 0x0($v0) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d8f4) {
            ctx->pc = 0x10D920u;
            goto label_10d920;
        }
    }
    ctx->pc = 0x10D8FCu;
    // 0x10d8fc: 0x0  nop
    ctx->pc = 0x10d8fcu;
    // NOP
label_10d900:
    // 0x10d900: 0x32e20040  andi        $v0, $s7, 0x40
    ctx->pc = 0x10d900u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) & (uint64_t)(uint16_t)64);
    // 0x10d904: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x10D904u;
    {
        const bool branch_taken_0x10d904 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D908u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D904u;
            // 0x10d908: 0x2c0102d  daddu       $v0, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d904) {
            ctx->pc = 0x10D918u;
            goto label_10d918;
        }
    }
    ctx->pc = 0x10D90Cu;
    // 0x10d90c: 0x26d60008  addiu       $s6, $s6, 0x8
    ctx->pc = 0x10d90cu;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 8));
    // 0x10d910: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x10D910u;
    {
        const bool branch_taken_0x10d910 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D914u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D910u;
            // 0x10d914: 0x94500000  lhu         $s0, 0x0($v0) (Delay Slot)
        SET_GPR_U32(ctx, 16, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d910) {
            ctx->pc = 0x10D920u;
            goto label_10d920;
        }
    }
    ctx->pc = 0x10D918u;
label_10d918:
    // 0x10d918: 0x26d60008  addiu       $s6, $s6, 0x8
    ctx->pc = 0x10d918u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 8));
    // 0x10d91c: 0x9c500000  lwu         $s0, 0x0($v0)
    ctx->pc = 0x10d91cu;
    SET_GPR_U32(ctx, 16, READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_10d920:
    // 0x10d920: 0x32e20001  andi        $v0, $s7, 0x1
    ctx->pc = 0x10d920u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) & (uint64_t)(uint16_t)1);
    // 0x10d924: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x10D924u;
    {
        const bool branch_taken_0x10d924 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D928u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D924u;
            // 0x10d928: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d924) {
            ctx->pc = 0x10D934u;
            goto label_10d934;
        }
    }
    ctx->pc = 0x10D92Cu;
    // 0x10d92c: 0x36e20002  ori         $v0, $s7, 0x2
    ctx->pc = 0x10d92cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) | (uint64_t)(uint16_t)2);
    // 0x10d930: 0x50b80b  movn        $s7, $v0, $s0
    ctx->pc = 0x10d930u;
    if (GPR_U64(ctx, 16) != 0) SET_GPR_VEC(ctx, 23, GPR_VEC(ctx, 2));
label_10d934:
    // 0x10d934: 0xa3a001d1  sb          $zero, 0x1D1($sp)
    ctx->pc = 0x10d934u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 465), (uint8_t)GPR_U32(ctx, 0));
label_10d938:
    // 0x10d938: 0x6800003  bltz        $s4, . + 4 + (0x3 << 2)
    ctx->pc = 0x10D938u;
    {
        const bool branch_taken_0x10d938 = (GPR_S64(ctx, 20) < 0);
        ctx->pc = 0x10D93Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D938u;
            // 0x10d93c: 0xafb40204  sw          $s4, 0x204($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 516), GPR_U32(ctx, 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d938) {
            ctx->pc = 0x10D948u;
            goto label_10d948;
        }
    }
    ctx->pc = 0x10D940u;
    // 0x10d940: 0x2402ff7f  addiu       $v0, $zero, -0x81
    ctx->pc = 0x10d940u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967167));
    // 0x10d944: 0x2e2b824  and         $s7, $s7, $v0
    ctx->pc = 0x10d944u;
    SET_GPR_U64(ctx, 23, GPR_U64(ctx, 23) & GPR_U64(ctx, 2));
label_10d948:
    // 0x10d948: 0x16000004  bnez        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x10D948u;
    {
        const bool branch_taken_0x10d948 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x10D94Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D948u;
            // 0x10d94c: 0x27b501bc  addiu       $s5, $sp, 0x1BC (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 29), 444));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d948) {
            ctx->pc = 0x10D95Cu;
            goto label_10d95c;
        }
    }
    ctx->pc = 0x10D950u;
    // 0x10d950: 0x8fa60204  lw          $a2, 0x204($sp)
    ctx->pc = 0x10d950u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 516)));
    // 0x10d954: 0x10c0003d  beqz        $a2, . + 4 + (0x3D << 2)
    ctx->pc = 0x10D954u;
    {
        const bool branch_taken_0x10d954 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D958u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D954u;
            // 0x10d958: 0x3b51023  subu        $v0, $sp, $s5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 29), GPR_U32(ctx, 21)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d954) {
            ctx->pc = 0x10DA4Cu;
            goto label_10da4c;
        }
    }
    ctx->pc = 0x10D95Cu;
label_10d95c:
    // 0x10d95c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x10d95cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x10d960: 0x10620026  beq         $v1, $v0, . + 4 + (0x26 << 2)
    ctx->pc = 0x10D960u;
    {
        const bool branch_taken_0x10d960 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x10D964u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D960u;
            // 0x10d964: 0x2e02000a  sltiu       $v0, $s0, 0xA (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)10) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d960) {
            ctx->pc = 0x10D9FCu;
            goto label_10d9fc;
        }
    }
    ctx->pc = 0x10D968u;
    // 0x10d968: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x10D968u;
    {
        const bool branch_taken_0x10d968 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D96Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D968u;
            // 0x10d96c: 0x24040007  addiu       $a0, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d968) {
            ctx->pc = 0x10D990u;
            goto label_10d990;
        }
    }
    ctx->pc = 0x10D970u;
    // 0x10d970: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x10d970u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x10d974: 0x10620028  beq         $v1, $v0, . + 4 + (0x28 << 2)
    ctx->pc = 0x10D974u;
    {
        const bool branch_taken_0x10d974 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x10D978u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D974u;
            // 0x10d978: 0x3c020023  lui         $v0, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d974) {
            ctx->pc = 0x10DA18u;
            goto label_10da18;
        }
    }
    ctx->pc = 0x10D97Cu;
    // 0x10d97c: 0x24557b88  addiu       $s5, $v0, 0x7B88
    ctx->pc = 0x10d97cu;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 2), 31624));
    // 0x10d980: 0xc042c56  jal         func_10B158
    ctx->pc = 0x10D980u;
    SET_GPR_U32(ctx, 31, 0x10D988u);
    ctx->pc = 0x10D984u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10D980u;
            // 0x10d984: 0x2a0202d  daddu       $a0, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D988u; }
        if (ctx->pc != 0x10D988u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D988u; }
        if (ctx->pc != 0x10D988u) { return; }
    }
    ctx->pc = 0x10D988u;
label_10d988:
    // 0x10d988: 0x10000038  b           . + 4 + (0x38 << 2)
    ctx->pc = 0x10D988u;
    {
        const bool branch_taken_0x10d988 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D98Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D988u;
            // 0x10d98c: 0x40f02d  daddu       $fp, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d988) {
            ctx->pc = 0x10DA6Cu;
            goto label_10da6c;
        }
    }
    ctx->pc = 0x10D990u;
label_10d990:
    // 0x10d990: 0x2041024  and         $v0, $s0, $a0
    ctx->pc = 0x10d990u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & GPR_U64(ctx, 4));
    // 0x10d994: 0x1080fa  dsrl        $s0, $s0, 3
    ctx->pc = 0x10d994u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) >> 3);
    // 0x10d998: 0x64420030  daddiu      $v0, $v0, 0x30
    ctx->pc = 0x10d998u;
    SET_GPR_S64(ctx, 2, (int64_t)GPR_S64(ctx, 2) + (int64_t)(int32_t)48);
    // 0x10d99c: 0x26b5ffff  addiu       $s5, $s5, -0x1
    ctx->pc = 0x10d99cu;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 4294967295));
    // 0x10d9a0: 0x304300ff  andi        $v1, $v0, 0xFF
    ctx->pc = 0x10d9a0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x10d9a4: 0x1600fffa  bnez        $s0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x10D9A4u;
    {
        const bool branch_taken_0x10d9a4 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x10D9A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D9A4u;
            // 0x10d9a8: 0xa2a30000  sb          $v1, 0x0($s5) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d9a4) {
            ctx->pc = 0x10D990u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10d990;
        }
    }
    ctx->pc = 0x10D9ACu;
    // 0x10d9ac: 0x32e20001  andi        $v0, $s7, 0x1
    ctx->pc = 0x10d9acu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) & (uint64_t)(uint16_t)1);
    // 0x10d9b0: 0x10400025  beqz        $v0, . + 4 + (0x25 << 2)
    ctx->pc = 0x10D9B0u;
    {
        const bool branch_taken_0x10d9b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D9B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D9B0u;
            // 0x10d9b4: 0x24020030  addiu       $v0, $zero, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d9b0) {
            ctx->pc = 0x10DA48u;
            goto label_10da48;
        }
    }
    ctx->pc = 0x10D9B8u;
    // 0x10d9b8: 0x50620024  beql        $v1, $v0, . + 4 + (0x24 << 2)
    ctx->pc = 0x10D9B8u;
    {
        const bool branch_taken_0x10d9b8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x10d9b8) {
            ctx->pc = 0x10D9BCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10D9B8u;
            // 0x10d9bc: 0x3b51023  subu        $v0, $sp, $s5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 29), GPR_U32(ctx, 21)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10DA4Cu;
            goto label_10da4c;
        }
    }
    ctx->pc = 0x10D9C0u;
    // 0x10d9c0: 0x26b5ffff  addiu       $s5, $s5, -0x1
    ctx->pc = 0x10d9c0u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 4294967295));
    // 0x10d9c4: 0x10000020  b           . + 4 + (0x20 << 2)
    ctx->pc = 0x10D9C4u;
    {
        const bool branch_taken_0x10d9c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10D9C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D9C4u;
            // 0x10d9c8: 0xa2a20000  sb          $v0, 0x0($s5) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d9c4) {
            ctx->pc = 0x10DA48u;
            goto label_10da48;
        }
    }
    ctx->pc = 0x10D9CCu;
    // 0x10d9cc: 0x0  nop
    ctx->pc = 0x10d9ccu;
    // NOP
label_10d9d0:
    // 0x10d9d0: 0xc044370  jal         func_110DC0
    ctx->pc = 0x10D9D0u;
    SET_GPR_U32(ctx, 31, 0x10D9D8u);
    ctx->pc = 0x10D9D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10D9D0u;
            // 0x10d9d4: 0x2405000a  addiu       $a1, $zero, 0xA (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
        ctx->in_delay_slot = false;
    ctx->pc = 0x110DC0u;
    if (runtime->hasFunction(0x110DC0u)) {
        auto targetFn = runtime->lookupFunction(0x110DC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D9D8u; }
        if (ctx->pc != 0x10D9D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00110DC0_0x110dc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D9D8u; }
        if (ctx->pc != 0x10D9D8u) { return; }
    }
    ctx->pc = 0x10D9D8u;
label_10d9d8:
    // 0x10d9d8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x10d9d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d9dc: 0x64420030  daddiu      $v0, $v0, 0x30
    ctx->pc = 0x10d9dcu;
    SET_GPR_S64(ctx, 2, (int64_t)GPR_S64(ctx, 2) + (int64_t)(int32_t)48);
    // 0x10d9e0: 0x26b5ffff  addiu       $s5, $s5, -0x1
    ctx->pc = 0x10d9e0u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 4294967295));
    // 0x10d9e4: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x10d9e4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x10d9e8: 0x2405000a  addiu       $a1, $zero, 0xA
    ctx->pc = 0x10d9e8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x10d9ec: 0xc044210  jal         func_110840
    ctx->pc = 0x10D9ECu;
    SET_GPR_U32(ctx, 31, 0x10D9F4u);
    ctx->pc = 0x10D9F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10D9ECu;
            // 0x10d9f0: 0xa2a20000  sb          $v0, 0x0($s5) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x110840u;
    if (runtime->hasFunction(0x110840u)) {
        auto targetFn = runtime->lookupFunction(0x110840u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D9F4u; }
        if (ctx->pc != 0x10D9F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00110840_0x110840(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10D9F4u; }
        if (ctx->pc != 0x10D9F4u) { return; }
    }
    ctx->pc = 0x10D9F4u;
label_10d9f4:
    // 0x10d9f4: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x10d9f4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10d9f8: 0x2e02000a  sltiu       $v0, $s0, 0xA
    ctx->pc = 0x10d9f8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)10) ? 1 : 0);
label_10d9fc:
    // 0x10d9fc: 0x1040fff4  beqz        $v0, . + 4 + (-0xC << 2)
    ctx->pc = 0x10D9FCu;
    {
        const bool branch_taken_0x10d9fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10DA00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10D9FCu;
            // 0x10da00: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10d9fc) {
            ctx->pc = 0x10D9D0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10d9d0;
        }
    }
    ctx->pc = 0x10DA04u;
    // 0x10da04: 0x66020030  daddiu      $v0, $s0, 0x30
    ctx->pc = 0x10da04u;
    SET_GPR_S64(ctx, 2, (int64_t)GPR_S64(ctx, 16) + (int64_t)(int32_t)48);
    // 0x10da08: 0x26b5ffff  addiu       $s5, $s5, -0x1
    ctx->pc = 0x10da08u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 4294967295));
    // 0x10da0c: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x10da0cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x10da10: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x10DA10u;
    {
        const bool branch_taken_0x10da10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10DA14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DA10u;
            // 0x10da14: 0xa2a20000  sb          $v0, 0x0($s5) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10da10) {
            ctx->pc = 0x10DA48u;
            goto label_10da48;
        }
    }
    ctx->pc = 0x10DA18u;
label_10da18:
    // 0x10da18: 0x2404000f  addiu       $a0, $zero, 0xF
    ctx->pc = 0x10da18u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x10da1c: 0x0  nop
    ctx->pc = 0x10da1cu;
    // NOP
label_10da20:
    // 0x10da20: 0x8fa3020c  lw          $v1, 0x20C($sp)
    ctx->pc = 0x10da20u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 524)));
    // 0x10da24: 0x2041024  and         $v0, $s0, $a0
    ctx->pc = 0x10da24u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & GPR_U64(ctx, 4));
    // 0x10da28: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x10da28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x10da2c: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x10da2cu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x10da30: 0x26b5ffff  addiu       $s5, $s5, -0x1
    ctx->pc = 0x10da30u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 4294967295));
    // 0x10da34: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x10da34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x10da38: 0x10813a  dsrl        $s0, $s0, 4
    ctx->pc = 0x10da38u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) >> 4);
    // 0x10da3c: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x10da3cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x10da40: 0x1600fff7  bnez        $s0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x10DA40u;
    {
        const bool branch_taken_0x10da40 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x10DA44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DA40u;
            // 0x10da44: 0xa2a30000  sb          $v1, 0x0($s5) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10da40) {
            ctx->pc = 0x10DA20u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10da20;
        }
    }
    ctx->pc = 0x10DA48u;
label_10da48:
    // 0x10da48: 0x3b51023  subu        $v0, $sp, $s5
    ctx->pc = 0x10da48u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 29), GPR_U32(ctx, 21)));
label_10da4c:
    // 0x10da4c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x10DA4Cu;
    {
        const bool branch_taken_0x10da4c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10DA50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DA4Cu;
            // 0x10da50: 0x245e01bc  addiu       $fp, $v0, 0x1BC (Delay Slot)
        SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 2), 444));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10da4c) {
            ctx->pc = 0x10DA6Cu;
            goto label_10da6c;
        }
    }
    ctx->pc = 0x10DA54u;
    // 0x10da54: 0x0  nop
    ctx->pc = 0x10da54u;
    // NOP
label_10da58:
    // 0x10da58: 0x12200363  beqz        $s1, . + 4 + (0x363 << 2)
    ctx->pc = 0x10DA58u;
    {
        const bool branch_taken_0x10da58 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x10DA5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DA58u;
            // 0x10da5c: 0x27b50060  addiu       $s5, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10da58) {
            ctx->pc = 0x10E7E8u;
            goto label_10e7e8;
        }
    }
    ctx->pc = 0x10DA60u;
    // 0x10da60: 0x241e0001  addiu       $fp, $zero, 0x1
    ctx->pc = 0x10da60u;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x10da64: 0xa2b10000  sb          $s1, 0x0($s5)
    ctx->pc = 0x10da64u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 17));
label_10da68:
    // 0x10da68: 0xa3a001d1  sb          $zero, 0x1D1($sp)
    ctx->pc = 0x10da68u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 465), (uint8_t)GPR_U32(ctx, 0));
label_10da6c:
    // 0x10da6c: 0x8fa50204  lw          $a1, 0x204($sp)
    ctx->pc = 0x10da6cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 516)));
    // 0x10da70: 0x3c0202d  daddu       $a0, $fp, $zero
    ctx->pc = 0x10da70u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10da74: 0x3c0302d  daddu       $a2, $fp, $zero
    ctx->pc = 0x10da74u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10da78: 0x83a301d1  lb          $v1, 0x1D1($sp)
    ctx->pc = 0x10da78u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 465)));
    // 0x10da7c: 0x85102a  slt         $v0, $a0, $a1
    ctx->pc = 0x10da7cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x10da80: 0x93a401d1  lbu         $a0, 0x1D1($sp)
    ctx->pc = 0x10da80u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 465)));
    // 0x10da84: 0xc2280a  movz        $a1, $a2, $v0
    ctx->pc = 0x10da84u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 6));
    // 0x10da88: 0xafbe0208  sw          $fp, 0x208($sp)
    ctx->pc = 0x10da88u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 520), GPR_U32(ctx, 30));
    // 0x10da8c: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x10DA8Cu;
    {
        const bool branch_taken_0x10da8c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x10DA90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DA8Cu;
            // 0x10da90: 0xafa50208  sw          $a1, 0x208($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 520), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10da8c) {
            ctx->pc = 0x10DAA0u;
            goto label_10daa0;
        }
    }
    ctx->pc = 0x10DA94u;
    // 0x10da94: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x10da94u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x10da98: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x10DA98u;
    {
        const bool branch_taken_0x10da98 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10DA9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DA98u;
            // 0x10da9c: 0xafa50208  sw          $a1, 0x208($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 520), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10da98) {
            ctx->pc = 0x10DAB0u;
            goto label_10dab0;
        }
    }
    ctx->pc = 0x10DAA0u;
label_10daa0:
    // 0x10daa0: 0x8fa30208  lw          $v1, 0x208($sp)
    ctx->pc = 0x10daa0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 520)));
    // 0x10daa4: 0x32e20002  andi        $v0, $s7, 0x2
    ctx->pc = 0x10daa4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) & (uint64_t)(uint16_t)2);
    // 0x10daa8: 0x431821  addu        $v1, $v0, $v1
    ctx->pc = 0x10daa8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x10daac: 0xafa30208  sw          $v1, 0x208($sp)
    ctx->pc = 0x10daacu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 520), GPR_U32(ctx, 3));
label_10dab0:
    // 0x10dab0: 0x32e50084  andi        $a1, $s7, 0x84
    ctx->pc = 0x10dab0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 23) & (uint64_t)(uint16_t)132);
    // 0x10dab4: 0x14a0003a  bnez        $a1, . + 4 + (0x3A << 2)
    ctx->pc = 0x10DAB4u;
    {
        const bool branch_taken_0x10dab4 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x10DAB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DAB4u;
            // 0x10dab8: 0xafa50210  sw          $a1, 0x210($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 528), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10dab4) {
            ctx->pc = 0x10DBA0u;
            goto label_10dba0;
        }
    }
    ctx->pc = 0x10DABCu;
    // 0x10dabc: 0x8fa601f0  lw          $a2, 0x1F0($sp)
    ctx->pc = 0x10dabcu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 496)));
    // 0x10dac0: 0x8fa20208  lw          $v0, 0x208($sp)
    ctx->pc = 0x10dac0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 520)));
    // 0x10dac4: 0xc28023  subu        $s0, $a2, $v0
    ctx->pc = 0x10dac4u;
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x10dac8: 0x1a000035  blez        $s0, . + 4 + (0x35 << 2)
    ctx->pc = 0x10DAC8u;
    {
        const bool branch_taken_0x10dac8 = (GPR_S64(ctx, 16) <= 0);
        ctx->pc = 0x10DACCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DAC8u;
            // 0x10dacc: 0x2a020011  slti        $v0, $s0, 0x11 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)17) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10dac8) {
            ctx->pc = 0x10DBA0u;
            goto label_10dba0;
        }
    }
    ctx->pc = 0x10DAD0u;
    // 0x10dad0: 0x1440001f  bnez        $v0, . + 4 + (0x1F << 2)
    ctx->pc = 0x10DAD0u;
    {
        const bool branch_taken_0x10dad0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10DAD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DAD0u;
            // 0x10dad4: 0x3c070023  lui         $a3, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10dad0) {
            ctx->pc = 0x10DB50u;
            goto label_10db50;
        }
    }
    ctx->pc = 0x10DAD8u;
    // 0x10dad8: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x10dad8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x10dadc: 0x24f47b20  addiu       $s4, $a3, 0x7B20
    ctx->pc = 0x10dadcu;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 7), 31520));
    // 0x10dae0: 0xae660004  sw          $a2, 0x4($s3)
    ctx->pc = 0x10dae0u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 6));
    // 0x10dae4: 0x0  nop
    ctx->pc = 0x10dae4u;
    // NOP
label_10dae8:
    // 0x10dae8: 0xae740000  sw          $s4, 0x0($s3)
    ctx->pc = 0x10dae8u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 20));
    // 0x10daec: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x10daecu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x10daf0: 0x8fa20014  lw          $v0, 0x14($sp)
    ctx->pc = 0x10daf0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x10daf4: 0x8fa30018  lw          $v1, 0x18($sp)
    ctx->pc = 0x10daf4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10daf8: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x10daf8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x10dafc: 0x24630010  addiu       $v1, $v1, 0x10
    ctx->pc = 0x10dafcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 16));
    // 0x10db00: 0x28440008  slti        $a0, $v0, 0x8
    ctx->pc = 0x10db00u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x10db04: 0xafa30018  sw          $v1, 0x18($sp)
    ctx->pc = 0x10db04u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 3));
    // 0x10db08: 0x1480000b  bnez        $a0, . + 4 + (0xB << 2)
    ctx->pc = 0x10DB08u;
    {
        const bool branch_taken_0x10db08 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x10DB0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DB08u;
            // 0x10db0c: 0xafa20014  sw          $v0, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10db08) {
            ctx->pc = 0x10DB38u;
            goto label_10db38;
        }
    }
    ctx->pc = 0x10DB10u;
    // 0x10db10: 0x8fa401e8  lw          $a0, 0x1E8($sp)
    ctx->pc = 0x10db10u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x10db14: 0x27a50010  addiu       $a1, $sp, 0x10
    ctx->pc = 0x10db14u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x10db18: 0x7fa60220  sq          $a2, 0x220($sp)
    ctx->pc = 0x10db18u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 544), GPR_VEC(ctx, 6));
    // 0x10db1c: 0xc04341a  jal         func_10D068
    ctx->pc = 0x10DB1Cu;
    SET_GPR_U32(ctx, 31, 0x10DB24u);
    ctx->pc = 0x10DB20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10DB1Cu;
            // 0x10db20: 0x7fa70230  sq          $a3, 0x230($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 560), GPR_VEC(ctx, 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D068u;
    if (runtime->hasFunction(0x10D068u)) {
        auto targetFn = runtime->lookupFunction(0x10D068u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10DB24u; }
        if (ctx->pc != 0x10DB24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D068_0x10d068(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10DB24u; }
        if (ctx->pc != 0x10DB24u) { return; }
    }
    ctx->pc = 0x10DB24u;
label_10db24:
    // 0x10db24: 0x7ba60220  lq          $a2, 0x220($sp)
    ctx->pc = 0x10db24u;
    SET_GPR_VEC(ctx, 6, READ128(ADD32(GPR_U32(ctx, 29), 544)));
    // 0x10db28: 0x14400337  bnez        $v0, . + 4 + (0x337 << 2)
    ctx->pc = 0x10DB28u;
    {
        const bool branch_taken_0x10db28 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10DB2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DB28u;
            // 0x10db2c: 0x7ba70230  lq          $a3, 0x230($sp) (Delay Slot)
        SET_GPR_VEC(ctx, 7, READ128(ADD32(GPR_U32(ctx, 29), 560)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10db28) {
            ctx->pc = 0x10E808u;
            goto label_10e808;
        }
    }
    ctx->pc = 0x10DB30u;
    // 0x10db30: 0x27a30020  addiu       $v1, $sp, 0x20
    ctx->pc = 0x10db30u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x10db34: 0x60982d  daddu       $s3, $v1, $zero
    ctx->pc = 0x10db34u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
label_10db38:
    // 0x10db38: 0x2610fff0  addiu       $s0, $s0, -0x10
    ctx->pc = 0x10db38u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967280));
    // 0x10db3c: 0x2a020011  slti        $v0, $s0, 0x11
    ctx->pc = 0x10db3cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)17) ? 1 : 0);
    // 0x10db40: 0x5040ffe9  beql        $v0, $zero, . + 4 + (-0x17 << 2)
    ctx->pc = 0x10DB40u;
    {
        const bool branch_taken_0x10db40 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10db40) {
            ctx->pc = 0x10DB44u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10DB40u;
            // 0x10db44: 0xae660004  sw          $a2, 0x4($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10DAE8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10dae8;
        }
    }
    ctx->pc = 0x10DB48u;
    // 0x10db48: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x10DB48u;
    {
        const bool branch_taken_0x10db48 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10DB4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DB48u;
            // 0x10db4c: 0xae700004  sw          $s0, 0x4($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10db48) {
            ctx->pc = 0x10DB54u;
            goto label_10db54;
        }
    }
    ctx->pc = 0x10DB50u;
label_10db50:
    // 0x10db50: 0xae700004  sw          $s0, 0x4($s3)
    ctx->pc = 0x10db50u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 16));
label_10db54:
    // 0x10db54: 0x24e27b20  addiu       $v0, $a3, 0x7B20
    ctx->pc = 0x10db54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), 31520));
    // 0x10db58: 0xae620000  sw          $v0, 0x0($s3)
    ctx->pc = 0x10db58u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x10db5c: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x10db5cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x10db60: 0x8fa30014  lw          $v1, 0x14($sp)
    ctx->pc = 0x10db60u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x10db64: 0x8fa20018  lw          $v0, 0x18($sp)
    ctx->pc = 0x10db64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10db68: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x10db68u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x10db6c: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x10db6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x10db70: 0x28640008  slti        $a0, $v1, 0x8
    ctx->pc = 0x10db70u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x10db74: 0xafa20018  sw          $v0, 0x18($sp)
    ctx->pc = 0x10db74u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x10db78: 0x14800008  bnez        $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x10DB78u;
    {
        const bool branch_taken_0x10db78 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x10DB7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DB78u;
            // 0x10db7c: 0xafa30014  sw          $v1, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10db78) {
            ctx->pc = 0x10DB9Cu;
            goto label_10db9c;
        }
    }
    ctx->pc = 0x10DB80u;
    // 0x10db80: 0x8fa401e8  lw          $a0, 0x1E8($sp)
    ctx->pc = 0x10db80u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x10db84: 0xc04341a  jal         func_10D068
    ctx->pc = 0x10DB84u;
    SET_GPR_U32(ctx, 31, 0x10DB8Cu);
    ctx->pc = 0x10DB88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10DB84u;
            // 0x10db88: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D068u;
    if (runtime->hasFunction(0x10D068u)) {
        auto targetFn = runtime->lookupFunction(0x10D068u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10DB8Cu; }
        if (ctx->pc != 0x10DB8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D068_0x10d068(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10DB8Cu; }
        if (ctx->pc != 0x10DB8Cu) { return; }
    }
    ctx->pc = 0x10DB8Cu;
label_10db8c:
    // 0x10db8c: 0x1440031f  bnez        $v0, . + 4 + (0x31F << 2)
    ctx->pc = 0x10DB8Cu;
    {
        const bool branch_taken_0x10db8c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10DB90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DB8Cu;
            // 0x10db90: 0x8fa201e8  lw          $v0, 0x1E8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10db8c) {
            ctx->pc = 0x10E80Cu;
            goto label_10e80c;
        }
    }
    ctx->pc = 0x10DB94u;
    // 0x10db94: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x10db94u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x10db98: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x10db98u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_10db9c:
    // 0x10db9c: 0x93a401d1  lbu         $a0, 0x1D1($sp)
    ctx->pc = 0x10db9cu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 465)));
label_10dba0:
    // 0x10dba0: 0x10800015  beqz        $a0, . + 4 + (0x15 << 2)
    ctx->pc = 0x10DBA0u;
    {
        const bool branch_taken_0x10dba0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x10DBA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DBA0u;
            // 0x10dba4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10dba0) {
            ctx->pc = 0x10DBF8u;
            goto label_10dbf8;
        }
    }
    ctx->pc = 0x10DBA8u;
    // 0x10dba8: 0x27a301d1  addiu       $v1, $sp, 0x1D1
    ctx->pc = 0x10dba8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 465));
    // 0x10dbac: 0xae620004  sw          $v0, 0x4($s3)
    ctx->pc = 0x10dbacu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 2));
    // 0x10dbb0: 0xae630000  sw          $v1, 0x0($s3)
    ctx->pc = 0x10dbb0u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
    // 0x10dbb4: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x10dbb4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x10dbb8: 0x8fa30014  lw          $v1, 0x14($sp)
    ctx->pc = 0x10dbb8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x10dbbc: 0x8fa20018  lw          $v0, 0x18($sp)
    ctx->pc = 0x10dbbcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10dbc0: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x10dbc0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x10dbc4: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x10dbc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x10dbc8: 0x28640008  slti        $a0, $v1, 0x8
    ctx->pc = 0x10dbc8u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x10dbcc: 0xafa20018  sw          $v0, 0x18($sp)
    ctx->pc = 0x10dbccu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x10dbd0: 0x14800022  bnez        $a0, . + 4 + (0x22 << 2)
    ctx->pc = 0x10DBD0u;
    {
        const bool branch_taken_0x10dbd0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x10DBD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DBD0u;
            // 0x10dbd4: 0xafa30014  sw          $v1, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10dbd0) {
            ctx->pc = 0x10DC5Cu;
            goto label_10dc5c;
        }
    }
    ctx->pc = 0x10DBD8u;
    // 0x10dbd8: 0x8fa401e8  lw          $a0, 0x1E8($sp)
    ctx->pc = 0x10dbd8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x10dbdc: 0xc04341a  jal         func_10D068
    ctx->pc = 0x10DBDCu;
    SET_GPR_U32(ctx, 31, 0x10DBE4u);
    ctx->pc = 0x10DBE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10DBDCu;
            // 0x10dbe0: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D068u;
    if (runtime->hasFunction(0x10D068u)) {
        auto targetFn = runtime->lookupFunction(0x10D068u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10DBE4u; }
        if (ctx->pc != 0x10DBE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D068_0x10d068(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10DBE4u; }
        if (ctx->pc != 0x10DBE4u) { return; }
    }
    ctx->pc = 0x10DBE4u;
label_10dbe4:
    // 0x10dbe4: 0x14400309  bnez        $v0, . + 4 + (0x309 << 2)
    ctx->pc = 0x10DBE4u;
    {
        const bool branch_taken_0x10dbe4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10DBE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DBE4u;
            // 0x10dbe8: 0x8fa201e8  lw          $v0, 0x1E8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10dbe4) {
            ctx->pc = 0x10E80Cu;
            goto label_10e80c;
        }
    }
    ctx->pc = 0x10DBECu;
    // 0x10dbec: 0x27a50020  addiu       $a1, $sp, 0x20
    ctx->pc = 0x10dbecu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x10dbf0: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x10DBF0u;
    {
        const bool branch_taken_0x10dbf0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10DBF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DBF0u;
            // 0x10dbf4: 0xa0982d  daddu       $s3, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10dbf0) {
            ctx->pc = 0x10DC5Cu;
            goto label_10dc5c;
        }
    }
    ctx->pc = 0x10DBF8u;
label_10dbf8:
    // 0x10dbf8: 0x32e20002  andi        $v0, $s7, 0x2
    ctx->pc = 0x10dbf8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) & (uint64_t)(uint16_t)2);
    // 0x10dbfc: 0x10400017  beqz        $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x10DBFCu;
    {
        const bool branch_taken_0x10dbfc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10DC00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DBFCu;
            // 0x10dc00: 0x24020030  addiu       $v0, $zero, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10dbfc) {
            ctx->pc = 0x10DC5Cu;
            goto label_10dc5c;
        }
    }
    ctx->pc = 0x10DC04u;
    // 0x10dc04: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x10dc04u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x10dc08: 0xa3a201c0  sb          $v0, 0x1C0($sp)
    ctx->pc = 0x10dc08u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 448), (uint8_t)GPR_U32(ctx, 2));
    // 0x10dc0c: 0x27a301c0  addiu       $v1, $sp, 0x1C0
    ctx->pc = 0x10dc0cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 448));
    // 0x10dc10: 0xa3b101c1  sb          $s1, 0x1C1($sp)
    ctx->pc = 0x10dc10u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 449), (uint8_t)GPR_U32(ctx, 17));
    // 0x10dc14: 0xae640004  sw          $a0, 0x4($s3)
    ctx->pc = 0x10dc14u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 4));
    // 0x10dc18: 0xae630000  sw          $v1, 0x0($s3)
    ctx->pc = 0x10dc18u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
    // 0x10dc1c: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x10dc1cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x10dc20: 0x8fa30014  lw          $v1, 0x14($sp)
    ctx->pc = 0x10dc20u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x10dc24: 0x8fa20018  lw          $v0, 0x18($sp)
    ctx->pc = 0x10dc24u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10dc28: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x10dc28u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x10dc2c: 0x24420002  addiu       $v0, $v0, 0x2
    ctx->pc = 0x10dc2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2));
    // 0x10dc30: 0x28640008  slti        $a0, $v1, 0x8
    ctx->pc = 0x10dc30u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x10dc34: 0xafa20018  sw          $v0, 0x18($sp)
    ctx->pc = 0x10dc34u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x10dc38: 0x14800008  bnez        $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x10DC38u;
    {
        const bool branch_taken_0x10dc38 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x10DC3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DC38u;
            // 0x10dc3c: 0xafa30014  sw          $v1, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10dc38) {
            ctx->pc = 0x10DC5Cu;
            goto label_10dc5c;
        }
    }
    ctx->pc = 0x10DC40u;
    // 0x10dc40: 0x8fa401e8  lw          $a0, 0x1E8($sp)
    ctx->pc = 0x10dc40u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x10dc44: 0xc04341a  jal         func_10D068
    ctx->pc = 0x10DC44u;
    SET_GPR_U32(ctx, 31, 0x10DC4Cu);
    ctx->pc = 0x10DC48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10DC44u;
            // 0x10dc48: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D068u;
    if (runtime->hasFunction(0x10D068u)) {
        auto targetFn = runtime->lookupFunction(0x10D068u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10DC4Cu; }
        if (ctx->pc != 0x10DC4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D068_0x10d068(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10DC4Cu; }
        if (ctx->pc != 0x10DC4Cu) { return; }
    }
    ctx->pc = 0x10DC4Cu;
label_10dc4c:
    // 0x10dc4c: 0x144002ef  bnez        $v0, . + 4 + (0x2EF << 2)
    ctx->pc = 0x10DC4Cu;
    {
        const bool branch_taken_0x10dc4c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10DC50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DC4Cu;
            // 0x10dc50: 0x8fa201e8  lw          $v0, 0x1E8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10dc4c) {
            ctx->pc = 0x10E80Cu;
            goto label_10e80c;
        }
    }
    ctx->pc = 0x10DC54u;
    // 0x10dc54: 0x27a60020  addiu       $a2, $sp, 0x20
    ctx->pc = 0x10dc54u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x10dc58: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x10dc58u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
label_10dc5c:
    // 0x10dc5c: 0x8fa30210  lw          $v1, 0x210($sp)
    ctx->pc = 0x10dc5cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 528)));
    // 0x10dc60: 0x24020080  addiu       $v0, $zero, 0x80
    ctx->pc = 0x10dc60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x10dc64: 0x1462003a  bne         $v1, $v0, . + 4 + (0x3A << 2)
    ctx->pc = 0x10DC64u;
    {
        const bool branch_taken_0x10dc64 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x10DC68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DC64u;
            // 0x10dc68: 0x8fa40204  lw          $a0, 0x204($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 516)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10dc64) {
            ctx->pc = 0x10DD50u;
            goto label_10dd50;
        }
    }
    ctx->pc = 0x10DC6Cu;
    // 0x10dc6c: 0x8fa401f0  lw          $a0, 0x1F0($sp)
    ctx->pc = 0x10dc6cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 496)));
    // 0x10dc70: 0x8fa50208  lw          $a1, 0x208($sp)
    ctx->pc = 0x10dc70u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 520)));
    // 0x10dc74: 0x858023  subu        $s0, $a0, $a1
    ctx->pc = 0x10dc74u;
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x10dc78: 0x1a000035  blez        $s0, . + 4 + (0x35 << 2)
    ctx->pc = 0x10DC78u;
    {
        const bool branch_taken_0x10dc78 = (GPR_S64(ctx, 16) <= 0);
        ctx->pc = 0x10DC7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DC78u;
            // 0x10dc7c: 0x8fa40204  lw          $a0, 0x204($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 516)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10dc78) {
            ctx->pc = 0x10DD50u;
            goto label_10dd50;
        }
    }
    ctx->pc = 0x10DC80u;
    // 0x10dc80: 0x2a020011  slti        $v0, $s0, 0x11
    ctx->pc = 0x10dc80u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)17) ? 1 : 0);
    // 0x10dc84: 0x1440001e  bnez        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x10DC84u;
    {
        const bool branch_taken_0x10dc84 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10DC88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DC84u;
            // 0x10dc88: 0x3c070023  lui         $a3, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10dc84) {
            ctx->pc = 0x10DD00u;
            goto label_10dd00;
        }
    }
    ctx->pc = 0x10DC8Cu;
    // 0x10dc8c: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x10dc8cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x10dc90: 0x24f47b30  addiu       $s4, $a3, 0x7B30
    ctx->pc = 0x10dc90u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 7), 31536));
    // 0x10dc94: 0xae660004  sw          $a2, 0x4($s3)
    ctx->pc = 0x10dc94u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 6));
label_10dc98:
    // 0x10dc98: 0xae740000  sw          $s4, 0x0($s3)
    ctx->pc = 0x10dc98u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 20));
    // 0x10dc9c: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x10dc9cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x10dca0: 0x8fa20014  lw          $v0, 0x14($sp)
    ctx->pc = 0x10dca0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x10dca4: 0x8fa30018  lw          $v1, 0x18($sp)
    ctx->pc = 0x10dca4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10dca8: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x10dca8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x10dcac: 0x24630010  addiu       $v1, $v1, 0x10
    ctx->pc = 0x10dcacu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 16));
    // 0x10dcb0: 0x28440008  slti        $a0, $v0, 0x8
    ctx->pc = 0x10dcb0u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x10dcb4: 0xafa30018  sw          $v1, 0x18($sp)
    ctx->pc = 0x10dcb4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 3));
    // 0x10dcb8: 0x1480000b  bnez        $a0, . + 4 + (0xB << 2)
    ctx->pc = 0x10DCB8u;
    {
        const bool branch_taken_0x10dcb8 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x10DCBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DCB8u;
            // 0x10dcbc: 0xafa20014  sw          $v0, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10dcb8) {
            ctx->pc = 0x10DCE8u;
            goto label_10dce8;
        }
    }
    ctx->pc = 0x10DCC0u;
    // 0x10dcc0: 0x8fa401e8  lw          $a0, 0x1E8($sp)
    ctx->pc = 0x10dcc0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x10dcc4: 0x27a50010  addiu       $a1, $sp, 0x10
    ctx->pc = 0x10dcc4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x10dcc8: 0x7fa60220  sq          $a2, 0x220($sp)
    ctx->pc = 0x10dcc8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 544), GPR_VEC(ctx, 6));
    // 0x10dccc: 0xc04341a  jal         func_10D068
    ctx->pc = 0x10DCCCu;
    SET_GPR_U32(ctx, 31, 0x10DCD4u);
    ctx->pc = 0x10DCD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10DCCCu;
            // 0x10dcd0: 0x7fa70230  sq          $a3, 0x230($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 560), GPR_VEC(ctx, 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D068u;
    if (runtime->hasFunction(0x10D068u)) {
        auto targetFn = runtime->lookupFunction(0x10D068u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10DCD4u; }
        if (ctx->pc != 0x10DCD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D068_0x10d068(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10DCD4u; }
        if (ctx->pc != 0x10DCD4u) { return; }
    }
    ctx->pc = 0x10DCD4u;
label_10dcd4:
    // 0x10dcd4: 0x7ba60220  lq          $a2, 0x220($sp)
    ctx->pc = 0x10dcd4u;
    SET_GPR_VEC(ctx, 6, READ128(ADD32(GPR_U32(ctx, 29), 544)));
    // 0x10dcd8: 0x144002cb  bnez        $v0, . + 4 + (0x2CB << 2)
    ctx->pc = 0x10DCD8u;
    {
        const bool branch_taken_0x10dcd8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10DCDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DCD8u;
            // 0x10dcdc: 0x7ba70230  lq          $a3, 0x230($sp) (Delay Slot)
        SET_GPR_VEC(ctx, 7, READ128(ADD32(GPR_U32(ctx, 29), 560)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10dcd8) {
            ctx->pc = 0x10E808u;
            goto label_10e808;
        }
    }
    ctx->pc = 0x10DCE0u;
    // 0x10dce0: 0x27a20020  addiu       $v0, $sp, 0x20
    ctx->pc = 0x10dce0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x10dce4: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x10dce4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_10dce8:
    // 0x10dce8: 0x2610fff0  addiu       $s0, $s0, -0x10
    ctx->pc = 0x10dce8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967280));
    // 0x10dcec: 0x2a020011  slti        $v0, $s0, 0x11
    ctx->pc = 0x10dcecu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)17) ? 1 : 0);
    // 0x10dcf0: 0x5040ffe9  beql        $v0, $zero, . + 4 + (-0x17 << 2)
    ctx->pc = 0x10DCF0u;
    {
        const bool branch_taken_0x10dcf0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10dcf0) {
            ctx->pc = 0x10DCF4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10DCF0u;
            // 0x10dcf4: 0xae660004  sw          $a2, 0x4($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10DC98u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10dc98;
        }
    }
    ctx->pc = 0x10DCF8u;
    // 0x10dcf8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x10DCF8u;
    {
        const bool branch_taken_0x10dcf8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10DCFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DCF8u;
            // 0x10dcfc: 0xae700004  sw          $s0, 0x4($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10dcf8) {
            ctx->pc = 0x10DD04u;
            goto label_10dd04;
        }
    }
    ctx->pc = 0x10DD00u;
label_10dd00:
    // 0x10dd00: 0xae700004  sw          $s0, 0x4($s3)
    ctx->pc = 0x10dd00u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 16));
label_10dd04:
    // 0x10dd04: 0x24e27b30  addiu       $v0, $a3, 0x7B30
    ctx->pc = 0x10dd04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), 31536));
    // 0x10dd08: 0xae620000  sw          $v0, 0x0($s3)
    ctx->pc = 0x10dd08u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x10dd0c: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x10dd0cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x10dd10: 0x8fa30014  lw          $v1, 0x14($sp)
    ctx->pc = 0x10dd10u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x10dd14: 0x8fa20018  lw          $v0, 0x18($sp)
    ctx->pc = 0x10dd14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10dd18: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x10dd18u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x10dd1c: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x10dd1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x10dd20: 0x28640008  slti        $a0, $v1, 0x8
    ctx->pc = 0x10dd20u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x10dd24: 0xafa20018  sw          $v0, 0x18($sp)
    ctx->pc = 0x10dd24u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x10dd28: 0x14800008  bnez        $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x10DD28u;
    {
        const bool branch_taken_0x10dd28 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x10DD2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DD28u;
            // 0x10dd2c: 0xafa30014  sw          $v1, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10dd28) {
            ctx->pc = 0x10DD4Cu;
            goto label_10dd4c;
        }
    }
    ctx->pc = 0x10DD30u;
    // 0x10dd30: 0x8fa401e8  lw          $a0, 0x1E8($sp)
    ctx->pc = 0x10dd30u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x10dd34: 0xc04341a  jal         func_10D068
    ctx->pc = 0x10DD34u;
    SET_GPR_U32(ctx, 31, 0x10DD3Cu);
    ctx->pc = 0x10DD38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10DD34u;
            // 0x10dd38: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D068u;
    if (runtime->hasFunction(0x10D068u)) {
        auto targetFn = runtime->lookupFunction(0x10D068u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10DD3Cu; }
        if (ctx->pc != 0x10DD3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D068_0x10d068(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10DD3Cu; }
        if (ctx->pc != 0x10DD3Cu) { return; }
    }
    ctx->pc = 0x10DD3Cu;
label_10dd3c:
    // 0x10dd3c: 0x144002b3  bnez        $v0, . + 4 + (0x2B3 << 2)
    ctx->pc = 0x10DD3Cu;
    {
        const bool branch_taken_0x10dd3c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10DD40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DD3Cu;
            // 0x10dd40: 0x8fa201e8  lw          $v0, 0x1E8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10dd3c) {
            ctx->pc = 0x10E80Cu;
            goto label_10e80c;
        }
    }
    ctx->pc = 0x10DD44u;
    // 0x10dd44: 0x27a30020  addiu       $v1, $sp, 0x20
    ctx->pc = 0x10dd44u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x10dd48: 0x60982d  daddu       $s3, $v1, $zero
    ctx->pc = 0x10dd48u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
label_10dd4c:
    // 0x10dd4c: 0x8fa40204  lw          $a0, 0x204($sp)
    ctx->pc = 0x10dd4cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 516)));
label_10dd50:
    // 0x10dd50: 0x9e8023  subu        $s0, $a0, $fp
    ctx->pc = 0x10dd50u;
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 30)));
    // 0x10dd54: 0x1a000036  blez        $s0, . + 4 + (0x36 << 2)
    ctx->pc = 0x10DD54u;
    {
        const bool branch_taken_0x10dd54 = (GPR_S64(ctx, 16) <= 0);
        ctx->pc = 0x10DD58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DD54u;
            // 0x10dd58: 0x32e20100  andi        $v0, $s7, 0x100 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) & (uint64_t)(uint16_t)256);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10dd54) {
            ctx->pc = 0x10DE30u;
            goto label_10de30;
        }
    }
    ctx->pc = 0x10DD5Cu;
    // 0x10dd5c: 0x2a020011  slti        $v0, $s0, 0x11
    ctx->pc = 0x10dd5cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)17) ? 1 : 0);
    // 0x10dd60: 0x1440001f  bnez        $v0, . + 4 + (0x1F << 2)
    ctx->pc = 0x10DD60u;
    {
        const bool branch_taken_0x10dd60 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10DD64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DD60u;
            // 0x10dd64: 0x3c070023  lui         $a3, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10dd60) {
            ctx->pc = 0x10DDE0u;
            goto label_10dde0;
        }
    }
    ctx->pc = 0x10DD68u;
    // 0x10dd68: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x10dd68u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x10dd6c: 0x24f47b30  addiu       $s4, $a3, 0x7B30
    ctx->pc = 0x10dd6cu;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 7), 31536));
    // 0x10dd70: 0xae660004  sw          $a2, 0x4($s3)
    ctx->pc = 0x10dd70u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 6));
    // 0x10dd74: 0x0  nop
    ctx->pc = 0x10dd74u;
    // NOP
label_10dd78:
    // 0x10dd78: 0xae740000  sw          $s4, 0x0($s3)
    ctx->pc = 0x10dd78u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 20));
    // 0x10dd7c: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x10dd7cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x10dd80: 0x8fa20014  lw          $v0, 0x14($sp)
    ctx->pc = 0x10dd80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x10dd84: 0x8fa30018  lw          $v1, 0x18($sp)
    ctx->pc = 0x10dd84u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10dd88: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x10dd88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x10dd8c: 0x24630010  addiu       $v1, $v1, 0x10
    ctx->pc = 0x10dd8cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 16));
    // 0x10dd90: 0x28440008  slti        $a0, $v0, 0x8
    ctx->pc = 0x10dd90u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x10dd94: 0xafa30018  sw          $v1, 0x18($sp)
    ctx->pc = 0x10dd94u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 3));
    // 0x10dd98: 0x1480000b  bnez        $a0, . + 4 + (0xB << 2)
    ctx->pc = 0x10DD98u;
    {
        const bool branch_taken_0x10dd98 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x10DD9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DD98u;
            // 0x10dd9c: 0xafa20014  sw          $v0, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10dd98) {
            ctx->pc = 0x10DDC8u;
            goto label_10ddc8;
        }
    }
    ctx->pc = 0x10DDA0u;
    // 0x10dda0: 0x8fa401e8  lw          $a0, 0x1E8($sp)
    ctx->pc = 0x10dda0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x10dda4: 0x27a50010  addiu       $a1, $sp, 0x10
    ctx->pc = 0x10dda4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x10dda8: 0x7fa60220  sq          $a2, 0x220($sp)
    ctx->pc = 0x10dda8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 544), GPR_VEC(ctx, 6));
    // 0x10ddac: 0xc04341a  jal         func_10D068
    ctx->pc = 0x10DDACu;
    SET_GPR_U32(ctx, 31, 0x10DDB4u);
    ctx->pc = 0x10DDB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10DDACu;
            // 0x10ddb0: 0x7fa70230  sq          $a3, 0x230($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 560), GPR_VEC(ctx, 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D068u;
    if (runtime->hasFunction(0x10D068u)) {
        auto targetFn = runtime->lookupFunction(0x10D068u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10DDB4u; }
        if (ctx->pc != 0x10DDB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D068_0x10d068(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10DDB4u; }
        if (ctx->pc != 0x10DDB4u) { return; }
    }
    ctx->pc = 0x10DDB4u;
label_10ddb4:
    // 0x10ddb4: 0x7ba60220  lq          $a2, 0x220($sp)
    ctx->pc = 0x10ddb4u;
    SET_GPR_VEC(ctx, 6, READ128(ADD32(GPR_U32(ctx, 29), 544)));
    // 0x10ddb8: 0x14400293  bnez        $v0, . + 4 + (0x293 << 2)
    ctx->pc = 0x10DDB8u;
    {
        const bool branch_taken_0x10ddb8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10DDBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DDB8u;
            // 0x10ddbc: 0x7ba70230  lq          $a3, 0x230($sp) (Delay Slot)
        SET_GPR_VEC(ctx, 7, READ128(ADD32(GPR_U32(ctx, 29), 560)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ddb8) {
            ctx->pc = 0x10E808u;
            goto label_10e808;
        }
    }
    ctx->pc = 0x10DDC0u;
    // 0x10ddc0: 0x27a50020  addiu       $a1, $sp, 0x20
    ctx->pc = 0x10ddc0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x10ddc4: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x10ddc4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_10ddc8:
    // 0x10ddc8: 0x2610fff0  addiu       $s0, $s0, -0x10
    ctx->pc = 0x10ddc8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967280));
    // 0x10ddcc: 0x2a020011  slti        $v0, $s0, 0x11
    ctx->pc = 0x10ddccu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)17) ? 1 : 0);
    // 0x10ddd0: 0x5040ffe9  beql        $v0, $zero, . + 4 + (-0x17 << 2)
    ctx->pc = 0x10DDD0u;
    {
        const bool branch_taken_0x10ddd0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10ddd0) {
            ctx->pc = 0x10DDD4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10DDD0u;
            // 0x10ddd4: 0xae660004  sw          $a2, 0x4($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10DD78u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10dd78;
        }
    }
    ctx->pc = 0x10DDD8u;
    // 0x10ddd8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x10DDD8u;
    {
        const bool branch_taken_0x10ddd8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10DDDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DDD8u;
            // 0x10dddc: 0xae700004  sw          $s0, 0x4($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ddd8) {
            ctx->pc = 0x10DDE4u;
            goto label_10dde4;
        }
    }
    ctx->pc = 0x10DDE0u;
label_10dde0:
    // 0x10dde0: 0xae700004  sw          $s0, 0x4($s3)
    ctx->pc = 0x10dde0u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 16));
label_10dde4:
    // 0x10dde4: 0x24e27b30  addiu       $v0, $a3, 0x7B30
    ctx->pc = 0x10dde4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), 31536));
    // 0x10dde8: 0xae620000  sw          $v0, 0x0($s3)
    ctx->pc = 0x10dde8u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x10ddec: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x10ddecu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x10ddf0: 0x8fa30014  lw          $v1, 0x14($sp)
    ctx->pc = 0x10ddf0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x10ddf4: 0x8fa20018  lw          $v0, 0x18($sp)
    ctx->pc = 0x10ddf4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10ddf8: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x10ddf8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x10ddfc: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x10ddfcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x10de00: 0x28640008  slti        $a0, $v1, 0x8
    ctx->pc = 0x10de00u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x10de04: 0xafa20018  sw          $v0, 0x18($sp)
    ctx->pc = 0x10de04u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x10de08: 0x14800008  bnez        $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x10DE08u;
    {
        const bool branch_taken_0x10de08 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x10DE0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DE08u;
            // 0x10de0c: 0xafa30014  sw          $v1, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10de08) {
            ctx->pc = 0x10DE2Cu;
            goto label_10de2c;
        }
    }
    ctx->pc = 0x10DE10u;
    // 0x10de10: 0x8fa401e8  lw          $a0, 0x1E8($sp)
    ctx->pc = 0x10de10u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x10de14: 0xc04341a  jal         func_10D068
    ctx->pc = 0x10DE14u;
    SET_GPR_U32(ctx, 31, 0x10DE1Cu);
    ctx->pc = 0x10DE18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10DE14u;
            // 0x10de18: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D068u;
    if (runtime->hasFunction(0x10D068u)) {
        auto targetFn = runtime->lookupFunction(0x10D068u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10DE1Cu; }
        if (ctx->pc != 0x10DE1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D068_0x10d068(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10DE1Cu; }
        if (ctx->pc != 0x10DE1Cu) { return; }
    }
    ctx->pc = 0x10DE1Cu;
label_10de1c:
    // 0x10de1c: 0x1440027b  bnez        $v0, . + 4 + (0x27B << 2)
    ctx->pc = 0x10DE1Cu;
    {
        const bool branch_taken_0x10de1c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10DE20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DE1Cu;
            // 0x10de20: 0x8fa201e8  lw          $v0, 0x1E8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10de1c) {
            ctx->pc = 0x10E80Cu;
            goto label_10e80c;
        }
    }
    ctx->pc = 0x10DE24u;
    // 0x10de24: 0x27a60020  addiu       $a2, $sp, 0x20
    ctx->pc = 0x10de24u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x10de28: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x10de28u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
label_10de2c:
    // 0x10de2c: 0x32e20100  andi        $v0, $s7, 0x100
    ctx->pc = 0x10de2cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) & (uint64_t)(uint16_t)256);
label_10de30:
    // 0x10de30: 0x54400009  bnel        $v0, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x10DE30u;
    {
        const bool branch_taken_0x10de30 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10de30) {
            ctx->pc = 0x10DE34u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10DE30u;
            // 0x10de34: 0x2a220066  slti        $v0, $s1, 0x66 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)102) ? 1 : 0);
        ctx->in_delay_slot = false;
            ctx->pc = 0x10DE58u;
            goto label_10de58;
        }
    }
    ctx->pc = 0x10DE38u;
    // 0x10de38: 0xae7e0004  sw          $fp, 0x4($s3)
    ctx->pc = 0x10de38u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 30));
    // 0x10de3c: 0xae750000  sw          $s5, 0x0($s3)
    ctx->pc = 0x10de3cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 21));
    // 0x10de40: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x10de40u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x10de44: 0x8fa20014  lw          $v0, 0x14($sp)
    ctx->pc = 0x10de44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x10de48: 0x8fa30018  lw          $v1, 0x18($sp)
    ctx->pc = 0x10de48u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10de4c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x10de4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x10de50: 0x1000020f  b           . + 4 + (0x20F << 2)
    ctx->pc = 0x10DE50u;
    {
        const bool branch_taken_0x10de50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10DE54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DE50u;
            // 0x10de54: 0x7e1821  addu        $v1, $v1, $fp (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 30)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10de50) {
            ctx->pc = 0x10E690u;
            goto label_10e690;
        }
    }
    ctx->pc = 0x10DE58u;
label_10de58:
    // 0x10de58: 0x14400181  bnez        $v0, . + 4 + (0x181 << 2)
    ctx->pc = 0x10DE58u;
    {
        const bool branch_taken_0x10de58 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10DE5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DE58u;
            // 0x10de5c: 0x8fa201e0  lw          $v0, 0x1E0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 480)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10de58) {
            ctx->pc = 0x10E460u;
            goto label_10e460;
        }
    }
    ctx->pc = 0x10DE60u;
    // 0x10de60: 0xdfa401f8  ld          $a0, 0x1F8($sp)
    ctx->pc = 0x10de60u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 29), 504)));
    // 0x10de64: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x10de64u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10de68: 0xc0448a6  jal         func_112298
    ctx->pc = 0x10DE68u;
    SET_GPR_U32(ctx, 31, 0x10DE70u);
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10DE70u; }
        if (ctx->pc != 0x10DE70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10DE70u; }
        if (ctx->pc != 0x10DE70u) { return; }
    }
    ctx->pc = 0x10DE70u;
label_10de70:
    // 0x10de70: 0x1440005f  bnez        $v0, . + 4 + (0x5F << 2)
    ctx->pc = 0x10DE70u;
    {
        const bool branch_taken_0x10de70 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10DE74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DE70u;
            // 0x10de74: 0x8fa301dc  lw          $v1, 0x1DC($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 476)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10de70) {
            ctx->pc = 0x10DFF0u;
            goto label_10dff0;
        }
    }
    ctx->pc = 0x10DE78u;
    // 0x10de78: 0x24100001  addiu       $s0, $zero, 0x1
    ctx->pc = 0x10de78u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x10de7c: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x10de7cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x10de80: 0xae700004  sw          $s0, 0x4($s3)
    ctx->pc = 0x10de80u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 16));
    // 0x10de84: 0x24427ba8  addiu       $v0, $v0, 0x7BA8
    ctx->pc = 0x10de84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 31656));
    // 0x10de88: 0xae620000  sw          $v0, 0x0($s3)
    ctx->pc = 0x10de88u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x10de8c: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x10de8cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x10de90: 0x8fa30014  lw          $v1, 0x14($sp)
    ctx->pc = 0x10de90u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x10de94: 0x8fa20018  lw          $v0, 0x18($sp)
    ctx->pc = 0x10de94u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10de98: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x10de98u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x10de9c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x10de9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x10dea0: 0x28640008  slti        $a0, $v1, 0x8
    ctx->pc = 0x10dea0u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x10dea4: 0xafa20018  sw          $v0, 0x18($sp)
    ctx->pc = 0x10dea4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x10dea8: 0x14800008  bnez        $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x10DEA8u;
    {
        const bool branch_taken_0x10dea8 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x10DEACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DEA8u;
            // 0x10deac: 0xafa30014  sw          $v1, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10dea8) {
            ctx->pc = 0x10DECCu;
            goto label_10decc;
        }
    }
    ctx->pc = 0x10DEB0u;
    // 0x10deb0: 0x8fa401e8  lw          $a0, 0x1E8($sp)
    ctx->pc = 0x10deb0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x10deb4: 0xc04341a  jal         func_10D068
    ctx->pc = 0x10DEB4u;
    SET_GPR_U32(ctx, 31, 0x10DEBCu);
    ctx->pc = 0x10DEB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10DEB4u;
            // 0x10deb8: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D068u;
    if (runtime->hasFunction(0x10D068u)) {
        auto targetFn = runtime->lookupFunction(0x10D068u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10DEBCu; }
        if (ctx->pc != 0x10DEBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D068_0x10d068(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10DEBCu; }
        if (ctx->pc != 0x10DEBCu) { return; }
    }
    ctx->pc = 0x10DEBCu;
label_10debc:
    // 0x10debc: 0x14400253  bnez        $v0, . + 4 + (0x253 << 2)
    ctx->pc = 0x10DEBCu;
    {
        const bool branch_taken_0x10debc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10DEC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DEBCu;
            // 0x10dec0: 0x8fa201e8  lw          $v0, 0x1E8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10debc) {
            ctx->pc = 0x10E80Cu;
            goto label_10e80c;
        }
    }
    ctx->pc = 0x10DEC4u;
    // 0x10dec4: 0x27a30020  addiu       $v1, $sp, 0x20
    ctx->pc = 0x10dec4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x10dec8: 0x60982d  daddu       $s3, $v1, $zero
    ctx->pc = 0x10dec8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
label_10decc:
    // 0x10decc: 0x8fa201dc  lw          $v0, 0x1DC($sp)
    ctx->pc = 0x10deccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 476)));
    // 0x10ded0: 0x8fa301e0  lw          $v1, 0x1E0($sp)
    ctx->pc = 0x10ded0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 480)));
    // 0x10ded4: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x10ded4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x10ded8: 0x54400005  bnel        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x10DED8u;
    {
        const bool branch_taken_0x10ded8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10ded8) {
            ctx->pc = 0x10DEDCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10DED8u;
            // 0x10dedc: 0xae700004  sw          $s0, 0x4($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10DEF0u;
            goto label_10def0;
        }
    }
    ctx->pc = 0x10DEE0u;
    // 0x10dee0: 0x32e20001  andi        $v0, $s7, 0x1
    ctx->pc = 0x10dee0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) & (uint64_t)(uint16_t)1);
    // 0x10dee4: 0x104001f7  beqz        $v0, . + 4 + (0x1F7 << 2)
    ctx->pc = 0x10DEE4u;
    {
        const bool branch_taken_0x10dee4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10DEE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DEE4u;
            // 0x10dee8: 0x32e20004  andi        $v0, $s7, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) & (uint64_t)(uint16_t)4);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10dee4) {
            ctx->pc = 0x10E6C4u;
            goto label_10e6c4;
        }
    }
    ctx->pc = 0x10DEECu;
    // 0x10deec: 0xae700004  sw          $s0, 0x4($s3)
    ctx->pc = 0x10deecu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 16));
label_10def0:
    // 0x10def0: 0x8fa20014  lw          $v0, 0x14($sp)
    ctx->pc = 0x10def0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x10def4: 0x8fa401f4  lw          $a0, 0x1F4($sp)
    ctx->pc = 0x10def4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 500)));
    // 0x10def8: 0x8fa30018  lw          $v1, 0x18($sp)
    ctx->pc = 0x10def8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10defc: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x10defcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x10df00: 0xae640000  sw          $a0, 0x0($s3)
    ctx->pc = 0x10df00u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 4));
    // 0x10df04: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x10df04u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x10df08: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x10df08u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x10df0c: 0x28440008  slti        $a0, $v0, 0x8
    ctx->pc = 0x10df0cu;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x10df10: 0xafa30018  sw          $v1, 0x18($sp)
    ctx->pc = 0x10df10u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 3));
    // 0x10df14: 0x14800008  bnez        $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x10DF14u;
    {
        const bool branch_taken_0x10df14 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x10DF18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DF14u;
            // 0x10df18: 0xafa20014  sw          $v0, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10df14) {
            ctx->pc = 0x10DF38u;
            goto label_10df38;
        }
    }
    ctx->pc = 0x10DF1Cu;
    // 0x10df1c: 0x8fa401e8  lw          $a0, 0x1E8($sp)
    ctx->pc = 0x10df1cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x10df20: 0xc04341a  jal         func_10D068
    ctx->pc = 0x10DF20u;
    SET_GPR_U32(ctx, 31, 0x10DF28u);
    ctx->pc = 0x10DF24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10DF20u;
            // 0x10df24: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D068u;
    if (runtime->hasFunction(0x10D068u)) {
        auto targetFn = runtime->lookupFunction(0x10D068u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10DF28u; }
        if (ctx->pc != 0x10DF28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D068_0x10d068(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10DF28u; }
        if (ctx->pc != 0x10DF28u) { return; }
    }
    ctx->pc = 0x10DF28u;
label_10df28:
    // 0x10df28: 0x14400238  bnez        $v0, . + 4 + (0x238 << 2)
    ctx->pc = 0x10DF28u;
    {
        const bool branch_taken_0x10df28 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10DF2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DF28u;
            // 0x10df2c: 0x8fa201e8  lw          $v0, 0x1E8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10df28) {
            ctx->pc = 0x10E80Cu;
            goto label_10e80c;
        }
    }
    ctx->pc = 0x10DF30u;
    // 0x10df30: 0x27a50020  addiu       $a1, $sp, 0x20
    ctx->pc = 0x10df30u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x10df34: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x10df34u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_10df38:
    // 0x10df38: 0x8fa201e0  lw          $v0, 0x1E0($sp)
    ctx->pc = 0x10df38u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 480)));
    // 0x10df3c: 0x2450ffff  addiu       $s0, $v0, -0x1
    ctx->pc = 0x10df3cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x10df40: 0x1a0001e0  blez        $s0, . + 4 + (0x1E0 << 2)
    ctx->pc = 0x10DF40u;
    {
        const bool branch_taken_0x10df40 = (GPR_S64(ctx, 16) <= 0);
        ctx->pc = 0x10DF44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DF40u;
            // 0x10df44: 0x32e20004  andi        $v0, $s7, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) & (uint64_t)(uint16_t)4);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10df40) {
            ctx->pc = 0x10E6C4u;
            goto label_10e6c4;
        }
    }
    ctx->pc = 0x10DF48u;
    // 0x10df48: 0x2a020011  slti        $v0, $s0, 0x11
    ctx->pc = 0x10df48u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)17) ? 1 : 0);
    // 0x10df4c: 0x1440001c  bnez        $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x10DF4Cu;
    {
        const bool branch_taken_0x10df4c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10DF50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DF4Cu;
            // 0x10df50: 0x3c070023  lui         $a3, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10df4c) {
            ctx->pc = 0x10DFC0u;
            goto label_10dfc0;
        }
    }
    ctx->pc = 0x10DF54u;
    // 0x10df54: 0x24140010  addiu       $s4, $zero, 0x10
    ctx->pc = 0x10df54u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x10df58: 0x24f17b30  addiu       $s1, $a3, 0x7B30
    ctx->pc = 0x10df58u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 7), 31536));
    // 0x10df5c: 0xae740004  sw          $s4, 0x4($s3)
    ctx->pc = 0x10df5cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 20));
label_10df60:
    // 0x10df60: 0xae710000  sw          $s1, 0x0($s3)
    ctx->pc = 0x10df60u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 17));
    // 0x10df64: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x10df64u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x10df68: 0x8fa20014  lw          $v0, 0x14($sp)
    ctx->pc = 0x10df68u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x10df6c: 0x8fa30018  lw          $v1, 0x18($sp)
    ctx->pc = 0x10df6cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10df70: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x10df70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x10df74: 0x24630010  addiu       $v1, $v1, 0x10
    ctx->pc = 0x10df74u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 16));
    // 0x10df78: 0x28440008  slti        $a0, $v0, 0x8
    ctx->pc = 0x10df78u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x10df7c: 0xafa30018  sw          $v1, 0x18($sp)
    ctx->pc = 0x10df7cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 3));
    // 0x10df80: 0x14800009  bnez        $a0, . + 4 + (0x9 << 2)
    ctx->pc = 0x10DF80u;
    {
        const bool branch_taken_0x10df80 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x10DF84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DF80u;
            // 0x10df84: 0xafa20014  sw          $v0, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10df80) {
            ctx->pc = 0x10DFA8u;
            goto label_10dfa8;
        }
    }
    ctx->pc = 0x10DF88u;
    // 0x10df88: 0x8fa401e8  lw          $a0, 0x1E8($sp)
    ctx->pc = 0x10df88u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x10df8c: 0x27a50010  addiu       $a1, $sp, 0x10
    ctx->pc = 0x10df8cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x10df90: 0xc04341a  jal         func_10D068
    ctx->pc = 0x10DF90u;
    SET_GPR_U32(ctx, 31, 0x10DF98u);
    ctx->pc = 0x10DF94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10DF90u;
            // 0x10df94: 0x7fa70230  sq          $a3, 0x230($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 560), GPR_VEC(ctx, 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D068u;
    if (runtime->hasFunction(0x10D068u)) {
        auto targetFn = runtime->lookupFunction(0x10D068u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10DF98u; }
        if (ctx->pc != 0x10DF98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D068_0x10d068(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10DF98u; }
        if (ctx->pc != 0x10DF98u) { return; }
    }
    ctx->pc = 0x10DF98u;
label_10df98:
    // 0x10df98: 0x1440021b  bnez        $v0, . + 4 + (0x21B << 2)
    ctx->pc = 0x10DF98u;
    {
        const bool branch_taken_0x10df98 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10DF9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DF98u;
            // 0x10df9c: 0x7ba70230  lq          $a3, 0x230($sp) (Delay Slot)
        SET_GPR_VEC(ctx, 7, READ128(ADD32(GPR_U32(ctx, 29), 560)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10df98) {
            ctx->pc = 0x10E808u;
            goto label_10e808;
        }
    }
    ctx->pc = 0x10DFA0u;
    // 0x10dfa0: 0x27a60020  addiu       $a2, $sp, 0x20
    ctx->pc = 0x10dfa0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x10dfa4: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x10dfa4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
label_10dfa8:
    // 0x10dfa8: 0x2610fff0  addiu       $s0, $s0, -0x10
    ctx->pc = 0x10dfa8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967280));
    // 0x10dfac: 0x2a020011  slti        $v0, $s0, 0x11
    ctx->pc = 0x10dfacu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)17) ? 1 : 0);
    // 0x10dfb0: 0x5040ffeb  beql        $v0, $zero, . + 4 + (-0x15 << 2)
    ctx->pc = 0x10DFB0u;
    {
        const bool branch_taken_0x10dfb0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10dfb0) {
            ctx->pc = 0x10DFB4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10DFB0u;
            // 0x10dfb4: 0xae740004  sw          $s4, 0x4($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 20));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10DF60u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10df60;
        }
    }
    ctx->pc = 0x10DFB8u;
    // 0x10dfb8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x10DFB8u;
    {
        const bool branch_taken_0x10dfb8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10DFBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DFB8u;
            // 0x10dfbc: 0xae700004  sw          $s0, 0x4($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10dfb8) {
            ctx->pc = 0x10DFC4u;
            goto label_10dfc4;
        }
    }
    ctx->pc = 0x10DFC0u;
label_10dfc0:
    // 0x10dfc0: 0xae700004  sw          $s0, 0x4($s3)
    ctx->pc = 0x10dfc0u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 16));
label_10dfc4:
    // 0x10dfc4: 0x24e27b30  addiu       $v0, $a3, 0x7B30
    ctx->pc = 0x10dfc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), 31536));
    // 0x10dfc8: 0xae620000  sw          $v0, 0x0($s3)
    ctx->pc = 0x10dfc8u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x10dfcc: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x10dfccu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x10dfd0: 0x8fa30014  lw          $v1, 0x14($sp)
    ctx->pc = 0x10dfd0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x10dfd4: 0x8fa20018  lw          $v0, 0x18($sp)
    ctx->pc = 0x10dfd4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10dfd8: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x10dfd8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x10dfdc: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x10dfdcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x10dfe0: 0x28640008  slti        $a0, $v1, 0x8
    ctx->pc = 0x10dfe0u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x10dfe4: 0xafa20018  sw          $v0, 0x18($sp)
    ctx->pc = 0x10dfe4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x10dfe8: 0x100001ac  b           . + 4 + (0x1AC << 2)
    ctx->pc = 0x10DFE8u;
    {
        const bool branch_taken_0x10dfe8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10DFECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DFE8u;
            // 0x10dfec: 0xafa30014  sw          $v1, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10dfe8) {
            ctx->pc = 0x10E69Cu;
            goto label_10e69c;
        }
    }
    ctx->pc = 0x10DFF0u;
label_10dff0:
    // 0x10dff0: 0x1c600079  bgtz        $v1, . + 4 + (0x79 << 2)
    ctx->pc = 0x10DFF0u;
    {
        const bool branch_taken_0x10dff0 = (GPR_S64(ctx, 3) > 0);
        ctx->pc = 0x10DFF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10DFF0u;
            // 0x10dff4: 0x8fa201e0  lw          $v0, 0x1E0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 480)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10dff0) {
            ctx->pc = 0x10E1D8u;
            goto label_10e1d8;
        }
    }
    ctx->pc = 0x10DFF8u;
    // 0x10dff8: 0x24100001  addiu       $s0, $zero, 0x1
    ctx->pc = 0x10dff8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x10dffc: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x10dffcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x10e000: 0xae700004  sw          $s0, 0x4($s3)
    ctx->pc = 0x10e000u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 16));
    // 0x10e004: 0x24427ba8  addiu       $v0, $v0, 0x7BA8
    ctx->pc = 0x10e004u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 31656));
    // 0x10e008: 0xae620000  sw          $v0, 0x0($s3)
    ctx->pc = 0x10e008u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x10e00c: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x10e00cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x10e010: 0x8fa30014  lw          $v1, 0x14($sp)
    ctx->pc = 0x10e010u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x10e014: 0x8fa20018  lw          $v0, 0x18($sp)
    ctx->pc = 0x10e014u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10e018: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x10e018u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x10e01c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x10e01cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x10e020: 0x28640008  slti        $a0, $v1, 0x8
    ctx->pc = 0x10e020u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x10e024: 0xafa20018  sw          $v0, 0x18($sp)
    ctx->pc = 0x10e024u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x10e028: 0x14800008  bnez        $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x10E028u;
    {
        const bool branch_taken_0x10e028 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E02Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E028u;
            // 0x10e02c: 0xafa30014  sw          $v1, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e028) {
            ctx->pc = 0x10E04Cu;
            goto label_10e04c;
        }
    }
    ctx->pc = 0x10E030u;
    // 0x10e030: 0x8fa401e8  lw          $a0, 0x1E8($sp)
    ctx->pc = 0x10e030u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x10e034: 0xc04341a  jal         func_10D068
    ctx->pc = 0x10E034u;
    SET_GPR_U32(ctx, 31, 0x10E03Cu);
    ctx->pc = 0x10E038u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10E034u;
            // 0x10e038: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D068u;
    if (runtime->hasFunction(0x10D068u)) {
        auto targetFn = runtime->lookupFunction(0x10D068u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E03Cu; }
        if (ctx->pc != 0x10E03Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D068_0x10d068(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E03Cu; }
        if (ctx->pc != 0x10E03Cu) { return; }
    }
    ctx->pc = 0x10E03Cu;
label_10e03c:
    // 0x10e03c: 0x144001f3  bnez        $v0, . + 4 + (0x1F3 << 2)
    ctx->pc = 0x10E03Cu;
    {
        const bool branch_taken_0x10e03c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E040u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E03Cu;
            // 0x10e040: 0x8fa201e8  lw          $v0, 0x1E8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e03c) {
            ctx->pc = 0x10E80Cu;
            goto label_10e80c;
        }
    }
    ctx->pc = 0x10E044u;
    // 0x10e044: 0x27a30020  addiu       $v1, $sp, 0x20
    ctx->pc = 0x10e044u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x10e048: 0x60982d  daddu       $s3, $v1, $zero
    ctx->pc = 0x10e048u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
label_10e04c:
    // 0x10e04c: 0x8fa201dc  lw          $v0, 0x1DC($sp)
    ctx->pc = 0x10e04cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 476)));
    // 0x10e050: 0x54400005  bnel        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x10E050u;
    {
        const bool branch_taken_0x10e050 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10e050) {
            ctx->pc = 0x10E054u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10E050u;
            // 0x10e054: 0xae700004  sw          $s0, 0x4($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10E068u;
            goto label_10e068;
        }
    }
    ctx->pc = 0x10E058u;
    // 0x10e058: 0x8fa201e0  lw          $v0, 0x1E0($sp)
    ctx->pc = 0x10e058u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 480)));
    // 0x10e05c: 0x10400199  beqz        $v0, . + 4 + (0x199 << 2)
    ctx->pc = 0x10E05Cu;
    {
        const bool branch_taken_0x10e05c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10E060u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E05Cu;
            // 0x10e060: 0x32e20004  andi        $v0, $s7, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) & (uint64_t)(uint16_t)4);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e05c) {
            ctx->pc = 0x10E6C4u;
            goto label_10e6c4;
        }
    }
    ctx->pc = 0x10E064u;
    // 0x10e064: 0xae700004  sw          $s0, 0x4($s3)
    ctx->pc = 0x10e064u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 16));
label_10e068:
    // 0x10e068: 0x8fa20014  lw          $v0, 0x14($sp)
    ctx->pc = 0x10e068u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x10e06c: 0x8fa401f4  lw          $a0, 0x1F4($sp)
    ctx->pc = 0x10e06cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 500)));
    // 0x10e070: 0x8fa30018  lw          $v1, 0x18($sp)
    ctx->pc = 0x10e070u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10e074: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x10e074u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x10e078: 0xae640000  sw          $a0, 0x0($s3)
    ctx->pc = 0x10e078u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 4));
    // 0x10e07c: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x10e07cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x10e080: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x10e080u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x10e084: 0x28440008  slti        $a0, $v0, 0x8
    ctx->pc = 0x10e084u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x10e088: 0xafa30018  sw          $v1, 0x18($sp)
    ctx->pc = 0x10e088u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 3));
    // 0x10e08c: 0x14800008  bnez        $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x10E08Cu;
    {
        const bool branch_taken_0x10e08c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E090u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E08Cu;
            // 0x10e090: 0xafa20014  sw          $v0, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e08c) {
            ctx->pc = 0x10E0B0u;
            goto label_10e0b0;
        }
    }
    ctx->pc = 0x10E094u;
    // 0x10e094: 0x8fa401e8  lw          $a0, 0x1E8($sp)
    ctx->pc = 0x10e094u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x10e098: 0xc04341a  jal         func_10D068
    ctx->pc = 0x10E098u;
    SET_GPR_U32(ctx, 31, 0x10E0A0u);
    ctx->pc = 0x10E09Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10E098u;
            // 0x10e09c: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D068u;
    if (runtime->hasFunction(0x10D068u)) {
        auto targetFn = runtime->lookupFunction(0x10D068u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E0A0u; }
        if (ctx->pc != 0x10E0A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D068_0x10d068(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E0A0u; }
        if (ctx->pc != 0x10E0A0u) { return; }
    }
    ctx->pc = 0x10E0A0u;
label_10e0a0:
    // 0x10e0a0: 0x144001da  bnez        $v0, . + 4 + (0x1DA << 2)
    ctx->pc = 0x10E0A0u;
    {
        const bool branch_taken_0x10e0a0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E0A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E0A0u;
            // 0x10e0a4: 0x8fa201e8  lw          $v0, 0x1E8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e0a0) {
            ctx->pc = 0x10E80Cu;
            goto label_10e80c;
        }
    }
    ctx->pc = 0x10E0A8u;
    // 0x10e0a8: 0x27a50020  addiu       $a1, $sp, 0x20
    ctx->pc = 0x10e0a8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x10e0ac: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x10e0acu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_10e0b0:
    // 0x10e0b0: 0x8fa201dc  lw          $v0, 0x1DC($sp)
    ctx->pc = 0x10e0b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 476)));
    // 0x10e0b4: 0x28023  negu        $s0, $v0
    ctx->pc = 0x10e0b4u;
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 2)));
    // 0x10e0b8: 0x5a000033  blezl       $s0, . + 4 + (0x33 << 2)
    ctx->pc = 0x10E0B8u;
    {
        const bool branch_taken_0x10e0b8 = (GPR_S64(ctx, 16) <= 0);
        if (branch_taken_0x10e0b8) {
            ctx->pc = 0x10E0BCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10E0B8u;
            // 0x10e0bc: 0xae750000  sw          $s5, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 21));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10E188u;
            goto label_10e188;
        }
    }
    ctx->pc = 0x10E0C0u;
    // 0x10e0c0: 0x2a020011  slti        $v0, $s0, 0x11
    ctx->pc = 0x10e0c0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)17) ? 1 : 0);
    // 0x10e0c4: 0x1440001c  bnez        $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x10E0C4u;
    {
        const bool branch_taken_0x10e0c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E0C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E0C4u;
            // 0x10e0c8: 0x3c070023  lui         $a3, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e0c4) {
            ctx->pc = 0x10E138u;
            goto label_10e138;
        }
    }
    ctx->pc = 0x10E0CCu;
    // 0x10e0cc: 0x24140010  addiu       $s4, $zero, 0x10
    ctx->pc = 0x10e0ccu;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x10e0d0: 0x24f17b30  addiu       $s1, $a3, 0x7B30
    ctx->pc = 0x10e0d0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 7), 31536));
    // 0x10e0d4: 0xae740004  sw          $s4, 0x4($s3)
    ctx->pc = 0x10e0d4u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 20));
label_10e0d8:
    // 0x10e0d8: 0xae710000  sw          $s1, 0x0($s3)
    ctx->pc = 0x10e0d8u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 17));
    // 0x10e0dc: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x10e0dcu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x10e0e0: 0x8fa20014  lw          $v0, 0x14($sp)
    ctx->pc = 0x10e0e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x10e0e4: 0x8fa30018  lw          $v1, 0x18($sp)
    ctx->pc = 0x10e0e4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10e0e8: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x10e0e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x10e0ec: 0x24630010  addiu       $v1, $v1, 0x10
    ctx->pc = 0x10e0ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 16));
    // 0x10e0f0: 0x28440008  slti        $a0, $v0, 0x8
    ctx->pc = 0x10e0f0u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x10e0f4: 0xafa30018  sw          $v1, 0x18($sp)
    ctx->pc = 0x10e0f4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 3));
    // 0x10e0f8: 0x14800009  bnez        $a0, . + 4 + (0x9 << 2)
    ctx->pc = 0x10E0F8u;
    {
        const bool branch_taken_0x10e0f8 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E0FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E0F8u;
            // 0x10e0fc: 0xafa20014  sw          $v0, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e0f8) {
            ctx->pc = 0x10E120u;
            goto label_10e120;
        }
    }
    ctx->pc = 0x10E100u;
    // 0x10e100: 0x8fa401e8  lw          $a0, 0x1E8($sp)
    ctx->pc = 0x10e100u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x10e104: 0x27a50010  addiu       $a1, $sp, 0x10
    ctx->pc = 0x10e104u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x10e108: 0xc04341a  jal         func_10D068
    ctx->pc = 0x10E108u;
    SET_GPR_U32(ctx, 31, 0x10E110u);
    ctx->pc = 0x10E10Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10E108u;
            // 0x10e10c: 0x7fa70230  sq          $a3, 0x230($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 560), GPR_VEC(ctx, 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D068u;
    if (runtime->hasFunction(0x10D068u)) {
        auto targetFn = runtime->lookupFunction(0x10D068u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E110u; }
        if (ctx->pc != 0x10E110u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D068_0x10d068(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E110u; }
        if (ctx->pc != 0x10E110u) { return; }
    }
    ctx->pc = 0x10E110u;
label_10e110:
    // 0x10e110: 0x144001bd  bnez        $v0, . + 4 + (0x1BD << 2)
    ctx->pc = 0x10E110u;
    {
        const bool branch_taken_0x10e110 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E114u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E110u;
            // 0x10e114: 0x7ba70230  lq          $a3, 0x230($sp) (Delay Slot)
        SET_GPR_VEC(ctx, 7, READ128(ADD32(GPR_U32(ctx, 29), 560)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e110) {
            ctx->pc = 0x10E808u;
            goto label_10e808;
        }
    }
    ctx->pc = 0x10E118u;
    // 0x10e118: 0x27a60020  addiu       $a2, $sp, 0x20
    ctx->pc = 0x10e118u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x10e11c: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x10e11cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
label_10e120:
    // 0x10e120: 0x2610fff0  addiu       $s0, $s0, -0x10
    ctx->pc = 0x10e120u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967280));
    // 0x10e124: 0x2a020011  slti        $v0, $s0, 0x11
    ctx->pc = 0x10e124u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)17) ? 1 : 0);
    // 0x10e128: 0x5040ffeb  beql        $v0, $zero, . + 4 + (-0x15 << 2)
    ctx->pc = 0x10E128u;
    {
        const bool branch_taken_0x10e128 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10e128) {
            ctx->pc = 0x10E12Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10E128u;
            // 0x10e12c: 0xae740004  sw          $s4, 0x4($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 20));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10E0D8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10e0d8;
        }
    }
    ctx->pc = 0x10E130u;
    // 0x10e130: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x10E130u;
    {
        const bool branch_taken_0x10e130 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10E134u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E130u;
            // 0x10e134: 0xae700004  sw          $s0, 0x4($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e130) {
            ctx->pc = 0x10E13Cu;
            goto label_10e13c;
        }
    }
    ctx->pc = 0x10E138u;
label_10e138:
    // 0x10e138: 0xae700004  sw          $s0, 0x4($s3)
    ctx->pc = 0x10e138u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 16));
label_10e13c:
    // 0x10e13c: 0x24e27b30  addiu       $v0, $a3, 0x7B30
    ctx->pc = 0x10e13cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), 31536));
    // 0x10e140: 0xae620000  sw          $v0, 0x0($s3)
    ctx->pc = 0x10e140u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x10e144: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x10e144u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x10e148: 0x8fa30014  lw          $v1, 0x14($sp)
    ctx->pc = 0x10e148u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x10e14c: 0x8fa20018  lw          $v0, 0x18($sp)
    ctx->pc = 0x10e14cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10e150: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x10e150u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x10e154: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x10e154u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x10e158: 0x28640008  slti        $a0, $v1, 0x8
    ctx->pc = 0x10e158u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x10e15c: 0xafa20018  sw          $v0, 0x18($sp)
    ctx->pc = 0x10e15cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x10e160: 0x14800008  bnez        $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x10E160u;
    {
        const bool branch_taken_0x10e160 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E164u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E160u;
            // 0x10e164: 0xafa30014  sw          $v1, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e160) {
            ctx->pc = 0x10E184u;
            goto label_10e184;
        }
    }
    ctx->pc = 0x10E168u;
    // 0x10e168: 0x8fa401e8  lw          $a0, 0x1E8($sp)
    ctx->pc = 0x10e168u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x10e16c: 0xc04341a  jal         func_10D068
    ctx->pc = 0x10E16Cu;
    SET_GPR_U32(ctx, 31, 0x10E174u);
    ctx->pc = 0x10E170u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10E16Cu;
            // 0x10e170: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D068u;
    if (runtime->hasFunction(0x10D068u)) {
        auto targetFn = runtime->lookupFunction(0x10D068u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E174u; }
        if (ctx->pc != 0x10E174u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D068_0x10d068(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E174u; }
        if (ctx->pc != 0x10E174u) { return; }
    }
    ctx->pc = 0x10E174u;
label_10e174:
    // 0x10e174: 0x144001a5  bnez        $v0, . + 4 + (0x1A5 << 2)
    ctx->pc = 0x10E174u;
    {
        const bool branch_taken_0x10e174 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E178u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E174u;
            // 0x10e178: 0x8fa201e8  lw          $v0, 0x1E8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e174) {
            ctx->pc = 0x10E80Cu;
            goto label_10e80c;
        }
    }
    ctx->pc = 0x10E17Cu;
    // 0x10e17c: 0x27a20020  addiu       $v0, $sp, 0x20
    ctx->pc = 0x10e17cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x10e180: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x10e180u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_10e184:
    // 0x10e184: 0xae750000  sw          $s5, 0x0($s3)
    ctx->pc = 0x10e184u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 21));
label_10e188:
    // 0x10e188: 0x8fa201e0  lw          $v0, 0x1E0($sp)
    ctx->pc = 0x10e188u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 480)));
    // 0x10e18c: 0xae620004  sw          $v0, 0x4($s3)
    ctx->pc = 0x10e18cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 2));
    // 0x10e190: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x10e190u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x10e194: 0x8fa20014  lw          $v0, 0x14($sp)
    ctx->pc = 0x10e194u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x10e198: 0x8fa30018  lw          $v1, 0x18($sp)
    ctx->pc = 0x10e198u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10e19c: 0x8fa401e0  lw          $a0, 0x1E0($sp)
    ctx->pc = 0x10e19cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 480)));
    // 0x10e1a0: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x10e1a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x10e1a4: 0x28450008  slti        $a1, $v0, 0x8
    ctx->pc = 0x10e1a4u;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x10e1a8: 0xafa20014  sw          $v0, 0x14($sp)
    ctx->pc = 0x10e1a8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x10e1ac: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x10e1acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x10e1b0: 0x14a00143  bnez        $a1, . + 4 + (0x143 << 2)
    ctx->pc = 0x10E1B0u;
    {
        const bool branch_taken_0x10e1b0 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E1B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E1B0u;
            // 0x10e1b4: 0xafa30018  sw          $v1, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e1b0) {
            ctx->pc = 0x10E6C0u;
            goto label_10e6c0;
        }
    }
    ctx->pc = 0x10E1B8u;
    // 0x10e1b8: 0x8fa401e8  lw          $a0, 0x1E8($sp)
    ctx->pc = 0x10e1b8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x10e1bc: 0xc04341a  jal         func_10D068
    ctx->pc = 0x10E1BCu;
    SET_GPR_U32(ctx, 31, 0x10E1C4u);
    ctx->pc = 0x10E1C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10E1BCu;
            // 0x10e1c0: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D068u;
    if (runtime->hasFunction(0x10D068u)) {
        auto targetFn = runtime->lookupFunction(0x10D068u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E1C4u; }
        if (ctx->pc != 0x10E1C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D068_0x10d068(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E1C4u; }
        if (ctx->pc != 0x10E1C4u) { return; }
    }
    ctx->pc = 0x10E1C4u;
label_10e1c4:
    // 0x10e1c4: 0x14400191  bnez        $v0, . + 4 + (0x191 << 2)
    ctx->pc = 0x10E1C4u;
    {
        const bool branch_taken_0x10e1c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E1C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E1C4u;
            // 0x10e1c8: 0x8fa201e8  lw          $v0, 0x1E8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e1c4) {
            ctx->pc = 0x10E80Cu;
            goto label_10e80c;
        }
    }
    ctx->pc = 0x10E1CCu;
    // 0x10e1cc: 0x27a30020  addiu       $v1, $sp, 0x20
    ctx->pc = 0x10e1ccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x10e1d0: 0x1000013b  b           . + 4 + (0x13B << 2)
    ctx->pc = 0x10E1D0u;
    {
        const bool branch_taken_0x10e1d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10E1D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E1D0u;
            // 0x10e1d4: 0x60982d  daddu       $s3, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e1d0) {
            ctx->pc = 0x10E6C0u;
            goto label_10e6c0;
        }
    }
    ctx->pc = 0x10E1D8u;
label_10e1d8:
    // 0x10e1d8: 0x62102a  slt         $v0, $v1, $v0
    ctx->pc = 0x10e1d8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x10e1dc: 0x1440005c  bnez        $v0, . + 4 + (0x5C << 2)
    ctx->pc = 0x10E1DCu;
    {
        const bool branch_taken_0x10e1dc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E1E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E1DCu;
            // 0x10e1e0: 0xae750000  sw          $s5, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 21));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e1dc) {
            ctx->pc = 0x10E350u;
            goto label_10e350;
        }
    }
    ctx->pc = 0x10E1E4u;
    // 0x10e1e4: 0x8fa201e0  lw          $v0, 0x1E0($sp)
    ctx->pc = 0x10e1e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 480)));
    // 0x10e1e8: 0xae620004  sw          $v0, 0x4($s3)
    ctx->pc = 0x10e1e8u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 2));
    // 0x10e1ec: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x10e1ecu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x10e1f0: 0x8fa20014  lw          $v0, 0x14($sp)
    ctx->pc = 0x10e1f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x10e1f4: 0x8fa30018  lw          $v1, 0x18($sp)
    ctx->pc = 0x10e1f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10e1f8: 0x8fa501e0  lw          $a1, 0x1E0($sp)
    ctx->pc = 0x10e1f8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 480)));
    // 0x10e1fc: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x10e1fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x10e200: 0x28440008  slti        $a0, $v0, 0x8
    ctx->pc = 0x10e200u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x10e204: 0xafa20014  sw          $v0, 0x14($sp)
    ctx->pc = 0x10e204u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x10e208: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x10e208u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x10e20c: 0x14800009  bnez        $a0, . + 4 + (0x9 << 2)
    ctx->pc = 0x10E20Cu;
    {
        const bool branch_taken_0x10e20c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E210u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E20Cu;
            // 0x10e210: 0xafa30018  sw          $v1, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e20c) {
            ctx->pc = 0x10E234u;
            goto label_10e234;
        }
    }
    ctx->pc = 0x10E214u;
    // 0x10e214: 0x8fa401e8  lw          $a0, 0x1E8($sp)
    ctx->pc = 0x10e214u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x10e218: 0xc04341a  jal         func_10D068
    ctx->pc = 0x10E218u;
    SET_GPR_U32(ctx, 31, 0x10E220u);
    ctx->pc = 0x10E21Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10E218u;
            // 0x10e21c: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D068u;
    if (runtime->hasFunction(0x10D068u)) {
        auto targetFn = runtime->lookupFunction(0x10D068u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E220u; }
        if (ctx->pc != 0x10E220u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D068_0x10d068(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E220u; }
        if (ctx->pc != 0x10E220u) { return; }
    }
    ctx->pc = 0x10E220u;
label_10e220:
    // 0x10e220: 0x1440017a  bnez        $v0, . + 4 + (0x17A << 2)
    ctx->pc = 0x10E220u;
    {
        const bool branch_taken_0x10e220 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E224u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E220u;
            // 0x10e224: 0x8fa201e8  lw          $v0, 0x1E8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e220) {
            ctx->pc = 0x10E80Cu;
            goto label_10e80c;
        }
    }
    ctx->pc = 0x10E228u;
    // 0x10e228: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x10e228u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x10e22c: 0x8fa501e0  lw          $a1, 0x1E0($sp)
    ctx->pc = 0x10e22cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 480)));
    // 0x10e230: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x10e230u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_10e234:
    // 0x10e234: 0x8fa201dc  lw          $v0, 0x1DC($sp)
    ctx->pc = 0x10e234u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 476)));
    // 0x10e238: 0x458023  subu        $s0, $v0, $a1
    ctx->pc = 0x10e238u;
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x10e23c: 0x1a000034  blez        $s0, . + 4 + (0x34 << 2)
    ctx->pc = 0x10E23Cu;
    {
        const bool branch_taken_0x10e23c = (GPR_S64(ctx, 16) <= 0);
        ctx->pc = 0x10E240u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E23Cu;
            // 0x10e240: 0x32e20001  andi        $v0, $s7, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) & (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e23c) {
            ctx->pc = 0x10E310u;
            goto label_10e310;
        }
    }
    ctx->pc = 0x10E244u;
    // 0x10e244: 0x2a020011  slti        $v0, $s0, 0x11
    ctx->pc = 0x10e244u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)17) ? 1 : 0);
    // 0x10e248: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x10E248u;
    {
        const bool branch_taken_0x10e248 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E24Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E248u;
            // 0x10e24c: 0x3c070023  lui         $a3, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e248) {
            ctx->pc = 0x10E2C0u;
            goto label_10e2c0;
        }
    }
    ctx->pc = 0x10E250u;
    // 0x10e250: 0x24140010  addiu       $s4, $zero, 0x10
    ctx->pc = 0x10e250u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x10e254: 0x24f17b30  addiu       $s1, $a3, 0x7B30
    ctx->pc = 0x10e254u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 7), 31536));
    // 0x10e258: 0xae740004  sw          $s4, 0x4($s3)
    ctx->pc = 0x10e258u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 20));
    // 0x10e25c: 0x0  nop
    ctx->pc = 0x10e25cu;
    // NOP
label_10e260:
    // 0x10e260: 0xae710000  sw          $s1, 0x0($s3)
    ctx->pc = 0x10e260u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 17));
    // 0x10e264: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x10e264u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x10e268: 0x8fa20014  lw          $v0, 0x14($sp)
    ctx->pc = 0x10e268u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x10e26c: 0x8fa30018  lw          $v1, 0x18($sp)
    ctx->pc = 0x10e26cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10e270: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x10e270u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x10e274: 0x24630010  addiu       $v1, $v1, 0x10
    ctx->pc = 0x10e274u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 16));
    // 0x10e278: 0x28440008  slti        $a0, $v0, 0x8
    ctx->pc = 0x10e278u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x10e27c: 0xafa30018  sw          $v1, 0x18($sp)
    ctx->pc = 0x10e27cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 3));
    // 0x10e280: 0x14800009  bnez        $a0, . + 4 + (0x9 << 2)
    ctx->pc = 0x10E280u;
    {
        const bool branch_taken_0x10e280 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E284u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E280u;
            // 0x10e284: 0xafa20014  sw          $v0, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e280) {
            ctx->pc = 0x10E2A8u;
            goto label_10e2a8;
        }
    }
    ctx->pc = 0x10E288u;
    // 0x10e288: 0x8fa401e8  lw          $a0, 0x1E8($sp)
    ctx->pc = 0x10e288u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x10e28c: 0x27a50010  addiu       $a1, $sp, 0x10
    ctx->pc = 0x10e28cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x10e290: 0xc04341a  jal         func_10D068
    ctx->pc = 0x10E290u;
    SET_GPR_U32(ctx, 31, 0x10E298u);
    ctx->pc = 0x10E294u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10E290u;
            // 0x10e294: 0x7fa70230  sq          $a3, 0x230($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 560), GPR_VEC(ctx, 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D068u;
    if (runtime->hasFunction(0x10D068u)) {
        auto targetFn = runtime->lookupFunction(0x10D068u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E298u; }
        if (ctx->pc != 0x10E298u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D068_0x10d068(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E298u; }
        if (ctx->pc != 0x10E298u) { return; }
    }
    ctx->pc = 0x10E298u;
label_10e298:
    // 0x10e298: 0x1440015b  bnez        $v0, . + 4 + (0x15B << 2)
    ctx->pc = 0x10E298u;
    {
        const bool branch_taken_0x10e298 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E29Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E298u;
            // 0x10e29c: 0x7ba70230  lq          $a3, 0x230($sp) (Delay Slot)
        SET_GPR_VEC(ctx, 7, READ128(ADD32(GPR_U32(ctx, 29), 560)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e298) {
            ctx->pc = 0x10E808u;
            goto label_10e808;
        }
    }
    ctx->pc = 0x10E2A0u;
    // 0x10e2a0: 0x27a50020  addiu       $a1, $sp, 0x20
    ctx->pc = 0x10e2a0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x10e2a4: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x10e2a4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_10e2a8:
    // 0x10e2a8: 0x2610fff0  addiu       $s0, $s0, -0x10
    ctx->pc = 0x10e2a8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967280));
    // 0x10e2ac: 0x2a020011  slti        $v0, $s0, 0x11
    ctx->pc = 0x10e2acu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)17) ? 1 : 0);
    // 0x10e2b0: 0x5040ffeb  beql        $v0, $zero, . + 4 + (-0x15 << 2)
    ctx->pc = 0x10E2B0u;
    {
        const bool branch_taken_0x10e2b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10e2b0) {
            ctx->pc = 0x10E2B4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10E2B0u;
            // 0x10e2b4: 0xae740004  sw          $s4, 0x4($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 20));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10E260u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10e260;
        }
    }
    ctx->pc = 0x10E2B8u;
    // 0x10e2b8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x10E2B8u;
    {
        const bool branch_taken_0x10e2b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10E2BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E2B8u;
            // 0x10e2bc: 0xae700004  sw          $s0, 0x4($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e2b8) {
            ctx->pc = 0x10E2C4u;
            goto label_10e2c4;
        }
    }
    ctx->pc = 0x10E2C0u;
label_10e2c0:
    // 0x10e2c0: 0xae700004  sw          $s0, 0x4($s3)
    ctx->pc = 0x10e2c0u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 16));
label_10e2c4:
    // 0x10e2c4: 0x24e27b30  addiu       $v0, $a3, 0x7B30
    ctx->pc = 0x10e2c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), 31536));
    // 0x10e2c8: 0xae620000  sw          $v0, 0x0($s3)
    ctx->pc = 0x10e2c8u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x10e2cc: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x10e2ccu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x10e2d0: 0x8fa30014  lw          $v1, 0x14($sp)
    ctx->pc = 0x10e2d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x10e2d4: 0x8fa20018  lw          $v0, 0x18($sp)
    ctx->pc = 0x10e2d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10e2d8: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x10e2d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x10e2dc: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x10e2dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x10e2e0: 0x28640008  slti        $a0, $v1, 0x8
    ctx->pc = 0x10e2e0u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x10e2e4: 0xafa20018  sw          $v0, 0x18($sp)
    ctx->pc = 0x10e2e4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x10e2e8: 0x14800008  bnez        $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x10E2E8u;
    {
        const bool branch_taken_0x10e2e8 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E2ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E2E8u;
            // 0x10e2ec: 0xafa30014  sw          $v1, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e2e8) {
            ctx->pc = 0x10E30Cu;
            goto label_10e30c;
        }
    }
    ctx->pc = 0x10E2F0u;
    // 0x10e2f0: 0x8fa401e8  lw          $a0, 0x1E8($sp)
    ctx->pc = 0x10e2f0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x10e2f4: 0xc04341a  jal         func_10D068
    ctx->pc = 0x10E2F4u;
    SET_GPR_U32(ctx, 31, 0x10E2FCu);
    ctx->pc = 0x10E2F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10E2F4u;
            // 0x10e2f8: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D068u;
    if (runtime->hasFunction(0x10D068u)) {
        auto targetFn = runtime->lookupFunction(0x10D068u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E2FCu; }
        if (ctx->pc != 0x10E2FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D068_0x10d068(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E2FCu; }
        if (ctx->pc != 0x10E2FCu) { return; }
    }
    ctx->pc = 0x10E2FCu;
label_10e2fc:
    // 0x10e2fc: 0x14400143  bnez        $v0, . + 4 + (0x143 << 2)
    ctx->pc = 0x10E2FCu;
    {
        const bool branch_taken_0x10e2fc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E300u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E2FCu;
            // 0x10e300: 0x8fa201e8  lw          $v0, 0x1E8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e2fc) {
            ctx->pc = 0x10E80Cu;
            goto label_10e80c;
        }
    }
    ctx->pc = 0x10E304u;
    // 0x10e304: 0x27a60020  addiu       $a2, $sp, 0x20
    ctx->pc = 0x10e304u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x10e308: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x10e308u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
label_10e30c:
    // 0x10e30c: 0x32e20001  andi        $v0, $s7, 0x1
    ctx->pc = 0x10e30cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) & (uint64_t)(uint16_t)1);
label_10e310:
    // 0x10e310: 0x104000eb  beqz        $v0, . + 4 + (0xEB << 2)
    ctx->pc = 0x10E310u;
    {
        const bool branch_taken_0x10e310 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10E314u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E310u;
            // 0x10e314: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e310) {
            ctx->pc = 0x10E6C0u;
            goto label_10e6c0;
        }
    }
    ctx->pc = 0x10E318u;
    // 0x10e318: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x10e318u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x10e31c: 0xae630004  sw          $v1, 0x4($s3)
    ctx->pc = 0x10e31cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 3));
    // 0x10e320: 0x24427bb0  addiu       $v0, $v0, 0x7BB0
    ctx->pc = 0x10e320u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 31664));
    // 0x10e324: 0xae620000  sw          $v0, 0x0($s3)
    ctx->pc = 0x10e324u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x10e328: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x10e328u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x10e32c: 0x8fa30014  lw          $v1, 0x14($sp)
    ctx->pc = 0x10e32cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x10e330: 0x8fa20018  lw          $v0, 0x18($sp)
    ctx->pc = 0x10e330u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10e334: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x10e334u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x10e338: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x10e338u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x10e33c: 0x28640008  slti        $a0, $v1, 0x8
    ctx->pc = 0x10e33cu;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x10e340: 0xafa20018  sw          $v0, 0x18($sp)
    ctx->pc = 0x10e340u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x10e344: 0x100000d5  b           . + 4 + (0xD5 << 2)
    ctx->pc = 0x10E344u;
    {
        const bool branch_taken_0x10e344 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10E348u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E344u;
            // 0x10e348: 0xafa30014  sw          $v1, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e344) {
            ctx->pc = 0x10E69Cu;
            goto label_10e69c;
        }
    }
    ctx->pc = 0x10E34Cu;
    // 0x10e34c: 0x0  nop
    ctx->pc = 0x10e34cu;
    // NOP
label_10e350:
    // 0x10e350: 0x8fa201dc  lw          $v0, 0x1DC($sp)
    ctx->pc = 0x10e350u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 476)));
    // 0x10e354: 0xae620004  sw          $v0, 0x4($s3)
    ctx->pc = 0x10e354u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 2));
    // 0x10e358: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x10e358u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x10e35c: 0x8fa20014  lw          $v0, 0x14($sp)
    ctx->pc = 0x10e35cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x10e360: 0x8fa30018  lw          $v1, 0x18($sp)
    ctx->pc = 0x10e360u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10e364: 0x8fa701dc  lw          $a3, 0x1DC($sp)
    ctx->pc = 0x10e364u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 476)));
    // 0x10e368: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x10e368u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x10e36c: 0x28440008  slti        $a0, $v0, 0x8
    ctx->pc = 0x10e36cu;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x10e370: 0xafa20014  sw          $v0, 0x14($sp)
    ctx->pc = 0x10e370u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x10e374: 0x671821  addu        $v1, $v1, $a3
    ctx->pc = 0x10e374u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0x10e378: 0x14800009  bnez        $a0, . + 4 + (0x9 << 2)
    ctx->pc = 0x10E378u;
    {
        const bool branch_taken_0x10e378 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E37Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E378u;
            // 0x10e37c: 0xafa30018  sw          $v1, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e378) {
            ctx->pc = 0x10E3A0u;
            goto label_10e3a0;
        }
    }
    ctx->pc = 0x10E380u;
    // 0x10e380: 0x8fa401e8  lw          $a0, 0x1E8($sp)
    ctx->pc = 0x10e380u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x10e384: 0xc04341a  jal         func_10D068
    ctx->pc = 0x10E384u;
    SET_GPR_U32(ctx, 31, 0x10E38Cu);
    ctx->pc = 0x10E388u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10E384u;
            // 0x10e388: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D068u;
    if (runtime->hasFunction(0x10D068u)) {
        auto targetFn = runtime->lookupFunction(0x10D068u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E38Cu; }
        if (ctx->pc != 0x10E38Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D068_0x10d068(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E38Cu; }
        if (ctx->pc != 0x10E38Cu) { return; }
    }
    ctx->pc = 0x10E38Cu;
label_10e38c:
    // 0x10e38c: 0x1440011f  bnez        $v0, . + 4 + (0x11F << 2)
    ctx->pc = 0x10E38Cu;
    {
        const bool branch_taken_0x10e38c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E390u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E38Cu;
            // 0x10e390: 0x8fa201e8  lw          $v0, 0x1E8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e38c) {
            ctx->pc = 0x10E80Cu;
            goto label_10e80c;
        }
    }
    ctx->pc = 0x10E394u;
    // 0x10e394: 0x27a30020  addiu       $v1, $sp, 0x20
    ctx->pc = 0x10e394u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x10e398: 0x8fa701dc  lw          $a3, 0x1DC($sp)
    ctx->pc = 0x10e398u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 476)));
    // 0x10e39c: 0x60982d  daddu       $s3, $v1, $zero
    ctx->pc = 0x10e39cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
label_10e3a0:
    // 0x10e3a0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x10e3a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x10e3a4: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x10e3a4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x10e3a8: 0xae630004  sw          $v1, 0x4($s3)
    ctx->pc = 0x10e3a8u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 3));
    // 0x10e3ac: 0x24427bb0  addiu       $v0, $v0, 0x7BB0
    ctx->pc = 0x10e3acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 31664));
    // 0x10e3b0: 0xae620000  sw          $v0, 0x0($s3)
    ctx->pc = 0x10e3b0u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x10e3b4: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x10e3b4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x10e3b8: 0x8fa30014  lw          $v1, 0x14($sp)
    ctx->pc = 0x10e3b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x10e3bc: 0x2a7a821  addu        $s5, $s5, $a3
    ctx->pc = 0x10e3bcu;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 7)));
    // 0x10e3c0: 0x8fa20018  lw          $v0, 0x18($sp)
    ctx->pc = 0x10e3c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10e3c4: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x10e3c4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x10e3c8: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x10e3c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x10e3cc: 0x28640008  slti        $a0, $v1, 0x8
    ctx->pc = 0x10e3ccu;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x10e3d0: 0xafa20018  sw          $v0, 0x18($sp)
    ctx->pc = 0x10e3d0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x10e3d4: 0x14800008  bnez        $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x10E3D4u;
    {
        const bool branch_taken_0x10e3d4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E3D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E3D4u;
            // 0x10e3d8: 0xafa30014  sw          $v1, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e3d4) {
            ctx->pc = 0x10E3F8u;
            goto label_10e3f8;
        }
    }
    ctx->pc = 0x10E3DCu;
    // 0x10e3dc: 0x8fa401e8  lw          $a0, 0x1E8($sp)
    ctx->pc = 0x10e3dcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x10e3e0: 0xc04341a  jal         func_10D068
    ctx->pc = 0x10E3E0u;
    SET_GPR_U32(ctx, 31, 0x10E3E8u);
    ctx->pc = 0x10E3E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10E3E0u;
            // 0x10e3e4: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D068u;
    if (runtime->hasFunction(0x10D068u)) {
        auto targetFn = runtime->lookupFunction(0x10D068u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E3E8u; }
        if (ctx->pc != 0x10E3E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D068_0x10d068(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E3E8u; }
        if (ctx->pc != 0x10E3E8u) { return; }
    }
    ctx->pc = 0x10E3E8u;
label_10e3e8:
    // 0x10e3e8: 0x14400108  bnez        $v0, . + 4 + (0x108 << 2)
    ctx->pc = 0x10E3E8u;
    {
        const bool branch_taken_0x10e3e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E3ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E3E8u;
            // 0x10e3ec: 0x8fa201e8  lw          $v0, 0x1E8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e3e8) {
            ctx->pc = 0x10E80Cu;
            goto label_10e80c;
        }
    }
    ctx->pc = 0x10E3F0u;
    // 0x10e3f0: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x10e3f0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x10e3f4: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x10e3f4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_10e3f8:
    // 0x10e3f8: 0xae750000  sw          $s5, 0x0($s3)
    ctx->pc = 0x10e3f8u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 21));
    // 0x10e3fc: 0x8fa301dc  lw          $v1, 0x1DC($sp)
    ctx->pc = 0x10e3fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 476)));
    // 0x10e400: 0x8fa201e0  lw          $v0, 0x1E0($sp)
    ctx->pc = 0x10e400u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 480)));
    // 0x10e404: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x10e404u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x10e408: 0xae620004  sw          $v0, 0x4($s3)
    ctx->pc = 0x10e408u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 2));
    // 0x10e40c: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x10e40cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x10e410: 0x8fa30014  lw          $v1, 0x14($sp)
    ctx->pc = 0x10e410u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x10e414: 0x8fa401e0  lw          $a0, 0x1E0($sp)
    ctx->pc = 0x10e414u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 480)));
    // 0x10e418: 0x8fa501dc  lw          $a1, 0x1DC($sp)
    ctx->pc = 0x10e418u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 476)));
    // 0x10e41c: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x10e41cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x10e420: 0x8fa20018  lw          $v0, 0x18($sp)
    ctx->pc = 0x10e420u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10e424: 0x28660008  slti        $a2, $v1, 0x8
    ctx->pc = 0x10e424u;
    SET_GPR_U64(ctx, 6, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x10e428: 0x852023  subu        $a0, $a0, $a1
    ctx->pc = 0x10e428u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x10e42c: 0xafa30014  sw          $v1, 0x14($sp)
    ctx->pc = 0x10e42cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 3));
    // 0x10e430: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x10e430u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x10e434: 0x14c000a2  bnez        $a2, . + 4 + (0xA2 << 2)
    ctx->pc = 0x10E434u;
    {
        const bool branch_taken_0x10e434 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E438u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E434u;
            // 0x10e438: 0xafa20018  sw          $v0, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e434) {
            ctx->pc = 0x10E6C0u;
            goto label_10e6c0;
        }
    }
    ctx->pc = 0x10E43Cu;
    // 0x10e43c: 0x8fa401e8  lw          $a0, 0x1E8($sp)
    ctx->pc = 0x10e43cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x10e440: 0xc04341a  jal         func_10D068
    ctx->pc = 0x10E440u;
    SET_GPR_U32(ctx, 31, 0x10E448u);
    ctx->pc = 0x10E444u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10E440u;
            // 0x10e444: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D068u;
    if (runtime->hasFunction(0x10D068u)) {
        auto targetFn = runtime->lookupFunction(0x10D068u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E448u; }
        if (ctx->pc != 0x10E448u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D068_0x10d068(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E448u; }
        if (ctx->pc != 0x10E448u) { return; }
    }
    ctx->pc = 0x10E448u;
label_10e448:
    // 0x10e448: 0x144000f0  bnez        $v0, . + 4 + (0xF0 << 2)
    ctx->pc = 0x10E448u;
    {
        const bool branch_taken_0x10e448 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E44Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E448u;
            // 0x10e44c: 0x8fa201e8  lw          $v0, 0x1E8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e448) {
            ctx->pc = 0x10E80Cu;
            goto label_10e80c;
        }
    }
    ctx->pc = 0x10E450u;
    // 0x10e450: 0x27a50020  addiu       $a1, $sp, 0x20
    ctx->pc = 0x10e450u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x10e454: 0x1000009a  b           . + 4 + (0x9A << 2)
    ctx->pc = 0x10E454u;
    {
        const bool branch_taken_0x10e454 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10E458u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E454u;
            // 0x10e458: 0xa0982d  daddu       $s3, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e454) {
            ctx->pc = 0x10E6C0u;
            goto label_10e6c0;
        }
    }
    ctx->pc = 0x10E45Cu;
    // 0x10e45c: 0x0  nop
    ctx->pc = 0x10e45cu;
    // NOP
label_10e460:
    // 0x10e460: 0x28420002  slti        $v0, $v0, 0x2
    ctx->pc = 0x10e460u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x10e464: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x10E464u;
    {
        const bool branch_taken_0x10e464 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10e464) {
            ctx->pc = 0x10E468u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10E464u;
            // 0x10e468: 0x92a30000  lbu         $v1, 0x0($s5) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10E47Cu;
            goto label_10e47c;
        }
    }
    ctx->pc = 0x10E46Cu;
    // 0x10e46c: 0x32e20001  andi        $v0, $s7, 0x1
    ctx->pc = 0x10e46cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) & (uint64_t)(uint16_t)1);
    // 0x10e470: 0x1040006d  beqz        $v0, . + 4 + (0x6D << 2)
    ctx->pc = 0x10E470u;
    {
        const bool branch_taken_0x10e470 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10E474u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E470u;
            // 0x10e474: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e470) {
            ctx->pc = 0x10E628u;
            goto label_10e628;
        }
    }
    ctx->pc = 0x10E478u;
    // 0x10e478: 0x92a30000  lbu         $v1, 0x0($s5)
    ctx->pc = 0x10e478u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
label_10e47c:
    // 0x10e47c: 0x26b50001  addiu       $s5, $s5, 0x1
    ctx->pc = 0x10e47cu;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 1));
    // 0x10e480: 0x2404002e  addiu       $a0, $zero, 0x2E
    ctx->pc = 0x10e480u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 46));
    // 0x10e484: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x10e484u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x10e488: 0xa3a301c0  sb          $v1, 0x1C0($sp)
    ctx->pc = 0x10e488u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 448), (uint8_t)GPR_U32(ctx, 3));
    // 0x10e48c: 0x27a201c0  addiu       $v0, $sp, 0x1C0
    ctx->pc = 0x10e48cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 448));
    // 0x10e490: 0xa3a401c1  sb          $a0, 0x1C1($sp)
    ctx->pc = 0x10e490u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 449), (uint8_t)GPR_U32(ctx, 4));
    // 0x10e494: 0xae650004  sw          $a1, 0x4($s3)
    ctx->pc = 0x10e494u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 5));
    // 0x10e498: 0xae620000  sw          $v0, 0x0($s3)
    ctx->pc = 0x10e498u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x10e49c: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x10e49cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x10e4a0: 0x8fa30014  lw          $v1, 0x14($sp)
    ctx->pc = 0x10e4a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x10e4a4: 0x8fa20018  lw          $v0, 0x18($sp)
    ctx->pc = 0x10e4a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10e4a8: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x10e4a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x10e4ac: 0x24420002  addiu       $v0, $v0, 0x2
    ctx->pc = 0x10e4acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2));
    // 0x10e4b0: 0x28640008  slti        $a0, $v1, 0x8
    ctx->pc = 0x10e4b0u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x10e4b4: 0xafa20018  sw          $v0, 0x18($sp)
    ctx->pc = 0x10e4b4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x10e4b8: 0x14800008  bnez        $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x10E4B8u;
    {
        const bool branch_taken_0x10e4b8 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E4BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E4B8u;
            // 0x10e4bc: 0xafa30014  sw          $v1, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e4b8) {
            ctx->pc = 0x10E4DCu;
            goto label_10e4dc;
        }
    }
    ctx->pc = 0x10E4C0u;
    // 0x10e4c0: 0x8fa401e8  lw          $a0, 0x1E8($sp)
    ctx->pc = 0x10e4c0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x10e4c4: 0xc04341a  jal         func_10D068
    ctx->pc = 0x10E4C4u;
    SET_GPR_U32(ctx, 31, 0x10E4CCu);
    ctx->pc = 0x10E4C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10E4C4u;
            // 0x10e4c8: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D068u;
    if (runtime->hasFunction(0x10D068u)) {
        auto targetFn = runtime->lookupFunction(0x10D068u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E4CCu; }
        if (ctx->pc != 0x10E4CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D068_0x10d068(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E4CCu; }
        if (ctx->pc != 0x10E4CCu) { return; }
    }
    ctx->pc = 0x10E4CCu;
label_10e4cc:
    // 0x10e4cc: 0x144000cf  bnez        $v0, . + 4 + (0xCF << 2)
    ctx->pc = 0x10E4CCu;
    {
        const bool branch_taken_0x10e4cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E4D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E4CCu;
            // 0x10e4d0: 0x8fa201e8  lw          $v0, 0x1E8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e4cc) {
            ctx->pc = 0x10E80Cu;
            goto label_10e80c;
        }
    }
    ctx->pc = 0x10E4D4u;
    // 0x10e4d4: 0x27a60020  addiu       $a2, $sp, 0x20
    ctx->pc = 0x10e4d4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x10e4d8: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x10e4d8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
label_10e4dc:
    // 0x10e4dc: 0xdfa401f8  ld          $a0, 0x1F8($sp)
    ctx->pc = 0x10e4dcu;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 29), 504)));
    // 0x10e4e0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x10e4e0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10e4e4: 0xc0448a6  jal         func_112298
    ctx->pc = 0x10E4E4u;
    SET_GPR_U32(ctx, 31, 0x10E4ECu);
    ctx->pc = 0x112298u;
    if (runtime->hasFunction(0x112298u)) {
        auto targetFn = runtime->lookupFunction(0x112298u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E4ECu; }
        if (ctx->pc != 0x10E4ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E4ECu; }
        if (ctx->pc != 0x10E4ECu) { return; }
    }
    ctx->pc = 0x10E4ECu;
label_10e4ec:
    // 0x10e4ec: 0x10400018  beqz        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x10E4ECu;
    {
        const bool branch_taken_0x10e4ec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10E4F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E4ECu;
            // 0x10e4f0: 0x8fa201e0  lw          $v0, 0x1E0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 480)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e4ec) {
            ctx->pc = 0x10E550u;
            goto label_10e550;
        }
    }
    ctx->pc = 0x10E4F4u;
    // 0x10e4f4: 0xae750000  sw          $s5, 0x0($s3)
    ctx->pc = 0x10e4f4u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 21));
    // 0x10e4f8: 0x8fa201e0  lw          $v0, 0x1E0($sp)
    ctx->pc = 0x10e4f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 480)));
    // 0x10e4fc: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x10e4fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x10e500: 0xae620004  sw          $v0, 0x4($s3)
    ctx->pc = 0x10e500u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 2));
    // 0x10e504: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x10e504u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x10e508: 0x8fa30018  lw          $v1, 0x18($sp)
    ctx->pc = 0x10e508u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10e50c: 0x8fa20014  lw          $v0, 0x14($sp)
    ctx->pc = 0x10e50cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x10e510: 0x8fa401e0  lw          $a0, 0x1E0($sp)
    ctx->pc = 0x10e510u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 480)));
    // 0x10e514: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x10e514u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x10e518: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x10e518u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x10e51c: 0x28450008  slti        $a1, $v0, 0x8
    ctx->pc = 0x10e51cu;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x10e520: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x10e520u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x10e524: 0xafa20014  sw          $v0, 0x14($sp)
    ctx->pc = 0x10e524u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x10e528: 0x14a00051  bnez        $a1, . + 4 + (0x51 << 2)
    ctx->pc = 0x10E528u;
    {
        const bool branch_taken_0x10e528 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E52Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E528u;
            // 0x10e52c: 0xafa30018  sw          $v1, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e528) {
            ctx->pc = 0x10E670u;
            goto label_10e670;
        }
    }
    ctx->pc = 0x10E530u;
    // 0x10e530: 0x8fa401e8  lw          $a0, 0x1E8($sp)
    ctx->pc = 0x10e530u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x10e534: 0xc04341a  jal         func_10D068
    ctx->pc = 0x10E534u;
    SET_GPR_U32(ctx, 31, 0x10E53Cu);
    ctx->pc = 0x10E538u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10E534u;
            // 0x10e538: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D068u;
    if (runtime->hasFunction(0x10D068u)) {
        auto targetFn = runtime->lookupFunction(0x10D068u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E53Cu; }
        if (ctx->pc != 0x10E53Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D068_0x10d068(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E53Cu; }
        if (ctx->pc != 0x10E53Cu) { return; }
    }
    ctx->pc = 0x10E53Cu;
label_10e53c:
    // 0x10e53c: 0x144000b3  bnez        $v0, . + 4 + (0xB3 << 2)
    ctx->pc = 0x10E53Cu;
    {
        const bool branch_taken_0x10e53c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E540u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E53Cu;
            // 0x10e540: 0x8fa201e8  lw          $v0, 0x1E8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e53c) {
            ctx->pc = 0x10E80Cu;
            goto label_10e80c;
        }
    }
    ctx->pc = 0x10E544u;
    // 0x10e544: 0x27a20020  addiu       $v0, $sp, 0x20
    ctx->pc = 0x10e544u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x10e548: 0x10000049  b           . + 4 + (0x49 << 2)
    ctx->pc = 0x10E548u;
    {
        const bool branch_taken_0x10e548 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10E54Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E548u;
            // 0x10e54c: 0x40982d  daddu       $s3, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e548) {
            ctx->pc = 0x10E670u;
            goto label_10e670;
        }
    }
    ctx->pc = 0x10E550u;
label_10e550:
    // 0x10e550: 0x2450ffff  addiu       $s0, $v0, -0x1
    ctx->pc = 0x10e550u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x10e554: 0x1a000047  blez        $s0, . + 4 + (0x47 << 2)
    ctx->pc = 0x10E554u;
    {
        const bool branch_taken_0x10e554 = (GPR_S64(ctx, 16) <= 0);
        ctx->pc = 0x10E558u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E554u;
            // 0x10e558: 0x8fa60200  lw          $a2, 0x200($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 512)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e554) {
            ctx->pc = 0x10E674u;
            goto label_10e674;
        }
    }
    ctx->pc = 0x10E55Cu;
    // 0x10e55c: 0x2a020011  slti        $v0, $s0, 0x11
    ctx->pc = 0x10e55cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)17) ? 1 : 0);
    // 0x10e560: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x10E560u;
    {
        const bool branch_taken_0x10e560 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E564u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E560u;
            // 0x10e564: 0x3c070023  lui         $a3, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e560) {
            ctx->pc = 0x10E5D8u;
            goto label_10e5d8;
        }
    }
    ctx->pc = 0x10E568u;
    // 0x10e568: 0x24140010  addiu       $s4, $zero, 0x10
    ctx->pc = 0x10e568u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x10e56c: 0x24f17b30  addiu       $s1, $a3, 0x7B30
    ctx->pc = 0x10e56cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 7), 31536));
    // 0x10e570: 0xae740004  sw          $s4, 0x4($s3)
    ctx->pc = 0x10e570u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 20));
    // 0x10e574: 0x0  nop
    ctx->pc = 0x10e574u;
    // NOP
label_10e578:
    // 0x10e578: 0xae710000  sw          $s1, 0x0($s3)
    ctx->pc = 0x10e578u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 17));
    // 0x10e57c: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x10e57cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x10e580: 0x8fa20014  lw          $v0, 0x14($sp)
    ctx->pc = 0x10e580u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x10e584: 0x8fa30018  lw          $v1, 0x18($sp)
    ctx->pc = 0x10e584u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10e588: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x10e588u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x10e58c: 0x24630010  addiu       $v1, $v1, 0x10
    ctx->pc = 0x10e58cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 16));
    // 0x10e590: 0x28440008  slti        $a0, $v0, 0x8
    ctx->pc = 0x10e590u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x10e594: 0xafa30018  sw          $v1, 0x18($sp)
    ctx->pc = 0x10e594u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 3));
    // 0x10e598: 0x14800009  bnez        $a0, . + 4 + (0x9 << 2)
    ctx->pc = 0x10E598u;
    {
        const bool branch_taken_0x10e598 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E59Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E598u;
            // 0x10e59c: 0xafa20014  sw          $v0, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e598) {
            ctx->pc = 0x10E5C0u;
            goto label_10e5c0;
        }
    }
    ctx->pc = 0x10E5A0u;
    // 0x10e5a0: 0x8fa401e8  lw          $a0, 0x1E8($sp)
    ctx->pc = 0x10e5a0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x10e5a4: 0x27a50010  addiu       $a1, $sp, 0x10
    ctx->pc = 0x10e5a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x10e5a8: 0xc04341a  jal         func_10D068
    ctx->pc = 0x10E5A8u;
    SET_GPR_U32(ctx, 31, 0x10E5B0u);
    ctx->pc = 0x10E5ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10E5A8u;
            // 0x10e5ac: 0x7fa70230  sq          $a3, 0x230($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 560), GPR_VEC(ctx, 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D068u;
    if (runtime->hasFunction(0x10D068u)) {
        auto targetFn = runtime->lookupFunction(0x10D068u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E5B0u; }
        if (ctx->pc != 0x10E5B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D068_0x10d068(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E5B0u; }
        if (ctx->pc != 0x10E5B0u) { return; }
    }
    ctx->pc = 0x10E5B0u;
label_10e5b0:
    // 0x10e5b0: 0x14400095  bnez        $v0, . + 4 + (0x95 << 2)
    ctx->pc = 0x10E5B0u;
    {
        const bool branch_taken_0x10e5b0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E5B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E5B0u;
            // 0x10e5b4: 0x7ba70230  lq          $a3, 0x230($sp) (Delay Slot)
        SET_GPR_VEC(ctx, 7, READ128(ADD32(GPR_U32(ctx, 29), 560)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e5b0) {
            ctx->pc = 0x10E808u;
            goto label_10e808;
        }
    }
    ctx->pc = 0x10E5B8u;
    // 0x10e5b8: 0x27a30020  addiu       $v1, $sp, 0x20
    ctx->pc = 0x10e5b8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x10e5bc: 0x60982d  daddu       $s3, $v1, $zero
    ctx->pc = 0x10e5bcu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
label_10e5c0:
    // 0x10e5c0: 0x2610fff0  addiu       $s0, $s0, -0x10
    ctx->pc = 0x10e5c0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967280));
    // 0x10e5c4: 0x2a020011  slti        $v0, $s0, 0x11
    ctx->pc = 0x10e5c4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)17) ? 1 : 0);
    // 0x10e5c8: 0x5040ffeb  beql        $v0, $zero, . + 4 + (-0x15 << 2)
    ctx->pc = 0x10E5C8u;
    {
        const bool branch_taken_0x10e5c8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10e5c8) {
            ctx->pc = 0x10E5CCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10E5C8u;
            // 0x10e5cc: 0xae740004  sw          $s4, 0x4($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 20));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10E578u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10e578;
        }
    }
    ctx->pc = 0x10E5D0u;
    // 0x10e5d0: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x10E5D0u;
    {
        const bool branch_taken_0x10e5d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10E5D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E5D0u;
            // 0x10e5d4: 0xae700004  sw          $s0, 0x4($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e5d0) {
            ctx->pc = 0x10E5DCu;
            goto label_10e5dc;
        }
    }
    ctx->pc = 0x10E5D8u;
label_10e5d8:
    // 0x10e5d8: 0xae700004  sw          $s0, 0x4($s3)
    ctx->pc = 0x10e5d8u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 16));
label_10e5dc:
    // 0x10e5dc: 0x24e27b30  addiu       $v0, $a3, 0x7B30
    ctx->pc = 0x10e5dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), 31536));
    // 0x10e5e0: 0xae620000  sw          $v0, 0x0($s3)
    ctx->pc = 0x10e5e0u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x10e5e4: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x10e5e4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x10e5e8: 0x8fa30014  lw          $v1, 0x14($sp)
    ctx->pc = 0x10e5e8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x10e5ec: 0x8fa20018  lw          $v0, 0x18($sp)
    ctx->pc = 0x10e5ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10e5f0: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x10e5f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x10e5f4: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x10e5f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x10e5f8: 0x28640008  slti        $a0, $v1, 0x8
    ctx->pc = 0x10e5f8u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x10e5fc: 0xafa20018  sw          $v0, 0x18($sp)
    ctx->pc = 0x10e5fcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x10e600: 0x1480001b  bnez        $a0, . + 4 + (0x1B << 2)
    ctx->pc = 0x10E600u;
    {
        const bool branch_taken_0x10e600 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E604u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E600u;
            // 0x10e604: 0xafa30014  sw          $v1, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e600) {
            ctx->pc = 0x10E670u;
            goto label_10e670;
        }
    }
    ctx->pc = 0x10E608u;
    // 0x10e608: 0x8fa401e8  lw          $a0, 0x1E8($sp)
    ctx->pc = 0x10e608u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x10e60c: 0xc04341a  jal         func_10D068
    ctx->pc = 0x10E60Cu;
    SET_GPR_U32(ctx, 31, 0x10E614u);
    ctx->pc = 0x10E610u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10E60Cu;
            // 0x10e610: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D068u;
    if (runtime->hasFunction(0x10D068u)) {
        auto targetFn = runtime->lookupFunction(0x10D068u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E614u; }
        if (ctx->pc != 0x10E614u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D068_0x10d068(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E614u; }
        if (ctx->pc != 0x10E614u) { return; }
    }
    ctx->pc = 0x10E614u;
label_10e614:
    // 0x10e614: 0x1440007d  bnez        $v0, . + 4 + (0x7D << 2)
    ctx->pc = 0x10E614u;
    {
        const bool branch_taken_0x10e614 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E618u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E614u;
            // 0x10e618: 0x8fa201e8  lw          $v0, 0x1E8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e614) {
            ctx->pc = 0x10E80Cu;
            goto label_10e80c;
        }
    }
    ctx->pc = 0x10E61Cu;
    // 0x10e61c: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x10e61cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x10e620: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x10E620u;
    {
        const bool branch_taken_0x10e620 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10E624u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E620u;
            // 0x10e624: 0x80982d  daddu       $s3, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e620) {
            ctx->pc = 0x10E670u;
            goto label_10e670;
        }
    }
    ctx->pc = 0x10E628u;
label_10e628:
    // 0x10e628: 0xae750000  sw          $s5, 0x0($s3)
    ctx->pc = 0x10e628u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 21));
    // 0x10e62c: 0xae620004  sw          $v0, 0x4($s3)
    ctx->pc = 0x10e62cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 2));
    // 0x10e630: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x10e630u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x10e634: 0x8fa30014  lw          $v1, 0x14($sp)
    ctx->pc = 0x10e634u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x10e638: 0x8fa20018  lw          $v0, 0x18($sp)
    ctx->pc = 0x10e638u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10e63c: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x10e63cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x10e640: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x10e640u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x10e644: 0x28640008  slti        $a0, $v1, 0x8
    ctx->pc = 0x10e644u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x10e648: 0xafa20018  sw          $v0, 0x18($sp)
    ctx->pc = 0x10e648u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x10e64c: 0x14800008  bnez        $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x10E64Cu;
    {
        const bool branch_taken_0x10e64c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E650u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E64Cu;
            // 0x10e650: 0xafa30014  sw          $v1, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e64c) {
            ctx->pc = 0x10E670u;
            goto label_10e670;
        }
    }
    ctx->pc = 0x10E654u;
    // 0x10e654: 0x8fa401e8  lw          $a0, 0x1E8($sp)
    ctx->pc = 0x10e654u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x10e658: 0xc04341a  jal         func_10D068
    ctx->pc = 0x10E658u;
    SET_GPR_U32(ctx, 31, 0x10E660u);
    ctx->pc = 0x10E65Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10E658u;
            // 0x10e65c: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D068u;
    if (runtime->hasFunction(0x10D068u)) {
        auto targetFn = runtime->lookupFunction(0x10D068u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E660u; }
        if (ctx->pc != 0x10E660u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D068_0x10d068(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E660u; }
        if (ctx->pc != 0x10E660u) { return; }
    }
    ctx->pc = 0x10E660u;
label_10e660:
    // 0x10e660: 0x1440006a  bnez        $v0, . + 4 + (0x6A << 2)
    ctx->pc = 0x10E660u;
    {
        const bool branch_taken_0x10e660 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E664u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E660u;
            // 0x10e664: 0x8fa201e8  lw          $v0, 0x1E8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e660) {
            ctx->pc = 0x10E80Cu;
            goto label_10e80c;
        }
    }
    ctx->pc = 0x10E668u;
    // 0x10e668: 0x27a50020  addiu       $a1, $sp, 0x20
    ctx->pc = 0x10e668u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x10e66c: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x10e66cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_10e670:
    // 0x10e670: 0x8fa60200  lw          $a2, 0x200($sp)
    ctx->pc = 0x10e670u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 512)));
label_10e674:
    // 0x10e674: 0xae7d0000  sw          $sp, 0x0($s3)
    ctx->pc = 0x10e674u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 29));
    // 0x10e678: 0xae660004  sw          $a2, 0x4($s3)
    ctx->pc = 0x10e678u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 6));
    // 0x10e67c: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x10e67cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x10e680: 0x8fa20014  lw          $v0, 0x14($sp)
    ctx->pc = 0x10e680u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x10e684: 0x8fa30018  lw          $v1, 0x18($sp)
    ctx->pc = 0x10e684u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10e688: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x10e688u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x10e68c: 0x661821  addu        $v1, $v1, $a2
    ctx->pc = 0x10e68cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
label_10e690:
    // 0x10e690: 0x28440008  slti        $a0, $v0, 0x8
    ctx->pc = 0x10e690u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x10e694: 0xafa30018  sw          $v1, 0x18($sp)
    ctx->pc = 0x10e694u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 3));
    // 0x10e698: 0xafa20014  sw          $v0, 0x14($sp)
    ctx->pc = 0x10e698u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
label_10e69c:
    // 0x10e69c: 0x14800009  bnez        $a0, . + 4 + (0x9 << 2)
    ctx->pc = 0x10E69Cu;
    {
        const bool branch_taken_0x10e69c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E6A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E69Cu;
            // 0x10e6a0: 0x32e20004  andi        $v0, $s7, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) & (uint64_t)(uint16_t)4);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e69c) {
            ctx->pc = 0x10E6C4u;
            goto label_10e6c4;
        }
    }
    ctx->pc = 0x10E6A4u;
    // 0x10e6a4: 0x8fa401e8  lw          $a0, 0x1E8($sp)
    ctx->pc = 0x10e6a4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x10e6a8: 0xc04341a  jal         func_10D068
    ctx->pc = 0x10E6A8u;
    SET_GPR_U32(ctx, 31, 0x10E6B0u);
    ctx->pc = 0x10E6ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10E6A8u;
            // 0x10e6ac: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D068u;
    if (runtime->hasFunction(0x10D068u)) {
        auto targetFn = runtime->lookupFunction(0x10D068u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E6B0u; }
        if (ctx->pc != 0x10E6B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D068_0x10d068(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E6B0u; }
        if (ctx->pc != 0x10E6B0u) { return; }
    }
    ctx->pc = 0x10E6B0u;
label_10e6b0:
    // 0x10e6b0: 0x14400056  bnez        $v0, . + 4 + (0x56 << 2)
    ctx->pc = 0x10E6B0u;
    {
        const bool branch_taken_0x10e6b0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E6B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E6B0u;
            // 0x10e6b4: 0x8fa201e8  lw          $v0, 0x1E8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e6b0) {
            ctx->pc = 0x10E80Cu;
            goto label_10e80c;
        }
    }
    ctx->pc = 0x10E6B8u;
    // 0x10e6b8: 0x27a20020  addiu       $v0, $sp, 0x20
    ctx->pc = 0x10e6b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x10e6bc: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x10e6bcu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_10e6c0:
    // 0x10e6c0: 0x32e20004  andi        $v0, $s7, 0x4
    ctx->pc = 0x10e6c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) & (uint64_t)(uint16_t)4);
label_10e6c4:
    // 0x10e6c4: 0x10400034  beqz        $v0, . + 4 + (0x34 << 2)
    ctx->pc = 0x10E6C4u;
    {
        const bool branch_taken_0x10e6c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10E6C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E6C4u;
            // 0x10e6c8: 0x8fa301f0  lw          $v1, 0x1F0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 496)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e6c4) {
            ctx->pc = 0x10E798u;
            goto label_10e798;
        }
    }
    ctx->pc = 0x10E6CCu;
    // 0x10e6cc: 0x8fa40208  lw          $a0, 0x208($sp)
    ctx->pc = 0x10e6ccu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 520)));
    // 0x10e6d0: 0x648023  subu        $s0, $v1, $a0
    ctx->pc = 0x10e6d0u;
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x10e6d4: 0x1a000032  blez        $s0, . + 4 + (0x32 << 2)
    ctx->pc = 0x10E6D4u;
    {
        const bool branch_taken_0x10e6d4 = (GPR_S64(ctx, 16) <= 0);
        ctx->pc = 0x10E6D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E6D4u;
            // 0x10e6d8: 0x8fa60208  lw          $a2, 0x208($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 520)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e6d4) {
            ctx->pc = 0x10E7A0u;
            goto label_10e7a0;
        }
    }
    ctx->pc = 0x10E6DCu;
    // 0x10e6dc: 0x2a020011  slti        $v0, $s0, 0x11
    ctx->pc = 0x10e6dcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)17) ? 1 : 0);
    // 0x10e6e0: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x10E6E0u;
    {
        const bool branch_taken_0x10e6e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E6E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E6E0u;
            // 0x10e6e4: 0x3c070023  lui         $a3, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e6e0) {
            ctx->pc = 0x10E758u;
            goto label_10e758;
        }
    }
    ctx->pc = 0x10E6E8u;
    // 0x10e6e8: 0x24140010  addiu       $s4, $zero, 0x10
    ctx->pc = 0x10e6e8u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x10e6ec: 0x24f17b20  addiu       $s1, $a3, 0x7B20
    ctx->pc = 0x10e6ecu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 7), 31520));
    // 0x10e6f0: 0xae740004  sw          $s4, 0x4($s3)
    ctx->pc = 0x10e6f0u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 20));
    // 0x10e6f4: 0x0  nop
    ctx->pc = 0x10e6f4u;
    // NOP
label_10e6f8:
    // 0x10e6f8: 0xae710000  sw          $s1, 0x0($s3)
    ctx->pc = 0x10e6f8u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 17));
    // 0x10e6fc: 0x26730008  addiu       $s3, $s3, 0x8
    ctx->pc = 0x10e6fcu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 8));
    // 0x10e700: 0x8fa20014  lw          $v0, 0x14($sp)
    ctx->pc = 0x10e700u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x10e704: 0x8fa30018  lw          $v1, 0x18($sp)
    ctx->pc = 0x10e704u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10e708: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x10e708u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x10e70c: 0x24630010  addiu       $v1, $v1, 0x10
    ctx->pc = 0x10e70cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 16));
    // 0x10e710: 0x28440008  slti        $a0, $v0, 0x8
    ctx->pc = 0x10e710u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x10e714: 0xafa30018  sw          $v1, 0x18($sp)
    ctx->pc = 0x10e714u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 3));
    // 0x10e718: 0x14800009  bnez        $a0, . + 4 + (0x9 << 2)
    ctx->pc = 0x10E718u;
    {
        const bool branch_taken_0x10e718 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E71Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E718u;
            // 0x10e71c: 0xafa20014  sw          $v0, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e718) {
            ctx->pc = 0x10E740u;
            goto label_10e740;
        }
    }
    ctx->pc = 0x10E720u;
    // 0x10e720: 0x8fa401e8  lw          $a0, 0x1E8($sp)
    ctx->pc = 0x10e720u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x10e724: 0x27a50010  addiu       $a1, $sp, 0x10
    ctx->pc = 0x10e724u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x10e728: 0xc04341a  jal         func_10D068
    ctx->pc = 0x10E728u;
    SET_GPR_U32(ctx, 31, 0x10E730u);
    ctx->pc = 0x10E72Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10E728u;
            // 0x10e72c: 0x7fa70230  sq          $a3, 0x230($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 560), GPR_VEC(ctx, 7));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D068u;
    if (runtime->hasFunction(0x10D068u)) {
        auto targetFn = runtime->lookupFunction(0x10D068u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E730u; }
        if (ctx->pc != 0x10E730u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D068_0x10d068(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E730u; }
        if (ctx->pc != 0x10E730u) { return; }
    }
    ctx->pc = 0x10E730u;
label_10e730:
    // 0x10e730: 0x14400035  bnez        $v0, . + 4 + (0x35 << 2)
    ctx->pc = 0x10E730u;
    {
        const bool branch_taken_0x10e730 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E734u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E730u;
            // 0x10e734: 0x7ba70230  lq          $a3, 0x230($sp) (Delay Slot)
        SET_GPR_VEC(ctx, 7, READ128(ADD32(GPR_U32(ctx, 29), 560)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e730) {
            ctx->pc = 0x10E808u;
            goto label_10e808;
        }
    }
    ctx->pc = 0x10E738u;
    // 0x10e738: 0x27a50020  addiu       $a1, $sp, 0x20
    ctx->pc = 0x10e738u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x10e73c: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x10e73cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_10e740:
    // 0x10e740: 0x2610fff0  addiu       $s0, $s0, -0x10
    ctx->pc = 0x10e740u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967280));
    // 0x10e744: 0x2a020011  slti        $v0, $s0, 0x11
    ctx->pc = 0x10e744u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)17) ? 1 : 0);
    // 0x10e748: 0x5040ffeb  beql        $v0, $zero, . + 4 + (-0x15 << 2)
    ctx->pc = 0x10E748u;
    {
        const bool branch_taken_0x10e748 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10e748) {
            ctx->pc = 0x10E74Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10E748u;
            // 0x10e74c: 0xae740004  sw          $s4, 0x4($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 20));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10E6F8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10e6f8;
        }
    }
    ctx->pc = 0x10E750u;
    // 0x10e750: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x10E750u;
    {
        const bool branch_taken_0x10e750 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10E754u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E750u;
            // 0x10e754: 0xae700004  sw          $s0, 0x4($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e750) {
            ctx->pc = 0x10E75Cu;
            goto label_10e75c;
        }
    }
    ctx->pc = 0x10E758u;
label_10e758:
    // 0x10e758: 0xae700004  sw          $s0, 0x4($s3)
    ctx->pc = 0x10e758u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 16));
label_10e75c:
    // 0x10e75c: 0x24e27b20  addiu       $v0, $a3, 0x7B20
    ctx->pc = 0x10e75cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), 31520));
    // 0x10e760: 0xae620000  sw          $v0, 0x0($s3)
    ctx->pc = 0x10e760u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
    // 0x10e764: 0x8fa30014  lw          $v1, 0x14($sp)
    ctx->pc = 0x10e764u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x10e768: 0x8fa20018  lw          $v0, 0x18($sp)
    ctx->pc = 0x10e768u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10e76c: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x10e76cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x10e770: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x10e770u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x10e774: 0x28640008  slti        $a0, $v1, 0x8
    ctx->pc = 0x10e774u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x10e778: 0xafa20018  sw          $v0, 0x18($sp)
    ctx->pc = 0x10e778u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x10e77c: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x10E77Cu;
    {
        const bool branch_taken_0x10e77c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E780u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E77Cu;
            // 0x10e780: 0xafa30014  sw          $v1, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e77c) {
            ctx->pc = 0x10E798u;
            goto label_10e798;
        }
    }
    ctx->pc = 0x10E784u;
    // 0x10e784: 0x8fa401e8  lw          $a0, 0x1E8($sp)
    ctx->pc = 0x10e784u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x10e788: 0xc04341a  jal         func_10D068
    ctx->pc = 0x10E788u;
    SET_GPR_U32(ctx, 31, 0x10E790u);
    ctx->pc = 0x10E78Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10E788u;
            // 0x10e78c: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D068u;
    if (runtime->hasFunction(0x10D068u)) {
        auto targetFn = runtime->lookupFunction(0x10D068u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E790u; }
        if (ctx->pc != 0x10E790u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D068_0x10d068(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E790u; }
        if (ctx->pc != 0x10E790u) { return; }
    }
    ctx->pc = 0x10E790u;
label_10e790:
    // 0x10e790: 0x1440001e  bnez        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x10E790u;
    {
        const bool branch_taken_0x10e790 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E794u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E790u;
            // 0x10e794: 0x8fa201e8  lw          $v0, 0x1E8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e790) {
            ctx->pc = 0x10E80Cu;
            goto label_10e80c;
        }
    }
    ctx->pc = 0x10E798u;
label_10e798:
    // 0x10e798: 0x8fa60208  lw          $a2, 0x208($sp)
    ctx->pc = 0x10e798u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 520)));
    // 0x10e79c: 0x8fa301f0  lw          $v1, 0x1F0($sp)
    ctx->pc = 0x10e79cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 496)));
label_10e7a0:
    // 0x10e7a0: 0x8fa401f0  lw          $a0, 0x1F0($sp)
    ctx->pc = 0x10e7a0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 496)));
    // 0x10e7a4: 0xc3102a  slt         $v0, $a2, $v1
    ctx->pc = 0x10e7a4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x10e7a8: 0x8fa30018  lw          $v1, 0x18($sp)
    ctx->pc = 0x10e7a8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10e7ac: 0x8fa501ec  lw          $a1, 0x1EC($sp)
    ctx->pc = 0x10e7acu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 492)));
    // 0x10e7b0: 0xc2200a  movz        $a0, $a2, $v0
    ctx->pc = 0x10e7b0u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 6));
    // 0x10e7b4: 0xa42821  addu        $a1, $a1, $a0
    ctx->pc = 0x10e7b4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x10e7b8: 0x10600006  beqz        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x10E7B8u;
    {
        const bool branch_taken_0x10e7b8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x10E7BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E7B8u;
            // 0x10e7bc: 0xafa501ec  sw          $a1, 0x1EC($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 492), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e7b8) {
            ctx->pc = 0x10E7D4u;
            goto label_10e7d4;
        }
    }
    ctx->pc = 0x10E7C0u;
    // 0x10e7c0: 0x8fa401e8  lw          $a0, 0x1E8($sp)
    ctx->pc = 0x10e7c0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x10e7c4: 0xc04341a  jal         func_10D068
    ctx->pc = 0x10E7C4u;
    SET_GPR_U32(ctx, 31, 0x10E7CCu);
    ctx->pc = 0x10E7C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10E7C4u;
            // 0x10e7c8: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D068u;
    if (runtime->hasFunction(0x10D068u)) {
        auto targetFn = runtime->lookupFunction(0x10D068u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E7CCu; }
        if (ctx->pc != 0x10E7CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D068_0x10d068(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E7CCu; }
        if (ctx->pc != 0x10E7CCu) { return; }
    }
    ctx->pc = 0x10E7CCu;
label_10e7cc:
    // 0x10e7cc: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x10E7CCu;
    {
        const bool branch_taken_0x10e7cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E7D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E7CCu;
            // 0x10e7d0: 0x8fa201e8  lw          $v0, 0x1E8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e7cc) {
            ctx->pc = 0x10E80Cu;
            goto label_10e80c;
        }
    }
    ctx->pc = 0x10E7D4u;
label_10e7d4:
    // 0x10e7d4: 0x27a60020  addiu       $a2, $sp, 0x20
    ctx->pc = 0x10e7d4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x10e7d8: 0xafa00014  sw          $zero, 0x14($sp)
    ctx->pc = 0x10e7d8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    // 0x10e7dc: 0x1000fab4  b           . + 4 + (-0x54C << 2)
    ctx->pc = 0x10E7DCu;
    {
        const bool branch_taken_0x10e7dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10E7E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E7DCu;
            // 0x10e7e0: 0xc0982d  daddu       $s3, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e7dc) {
            ctx->pc = 0x10D2B0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10d2b0;
        }
    }
    ctx->pc = 0x10E7E4u;
    // 0x10e7e4: 0x0  nop
    ctx->pc = 0x10e7e4u;
    // NOP
label_10e7e8:
    // 0x10e7e8: 0x8fa20018  lw          $v0, 0x18($sp)
    ctx->pc = 0x10e7e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_10e7ec:
    // 0x10e7ec: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x10E7ECu;
    {
        const bool branch_taken_0x10e7ec = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10E7F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E7ECu;
            // 0x10e7f0: 0x8fa401e8  lw          $a0, 0x1E8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e7ec) {
            ctx->pc = 0x10E804u;
            goto label_10e804;
        }
    }
    ctx->pc = 0x10E7F4u;
    // 0x10e7f4: 0xc04341a  jal         func_10D068
    ctx->pc = 0x10E7F4u;
    SET_GPR_U32(ctx, 31, 0x10E7FCu);
    ctx->pc = 0x10E7F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10E7F4u;
            // 0x10e7f8: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10D068u;
    if (runtime->hasFunction(0x10D068u)) {
        auto targetFn = runtime->lookupFunction(0x10D068u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E7FCu; }
        if (ctx->pc != 0x10E7FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010D068_0x10d068(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10E7FCu; }
        if (ctx->pc != 0x10E7FCu) { return; }
    }
    ctx->pc = 0x10E7FCu;
label_10e7fc:
    // 0x10e7fc: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x10E7FCu;
    {
        const bool branch_taken_0x10e7fc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10E800u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E7FCu;
            // 0x10e800: 0x8fa201e8  lw          $v0, 0x1E8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10e7fc) {
            ctx->pc = 0x10E80Cu;
            goto label_10e80c;
        }
    }
    ctx->pc = 0x10E804u;
label_10e804:
    // 0x10e804: 0xafa00014  sw          $zero, 0x14($sp)
    ctx->pc = 0x10e804u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
label_10e808:
    // 0x10e808: 0x8fa201e8  lw          $v0, 0x1E8($sp)
    ctx->pc = 0x10e808u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 488)));
label_10e80c:
    // 0x10e80c: 0x8fa401ec  lw          $a0, 0x1EC($sp)
    ctx->pc = 0x10e80cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 492)));
    // 0x10e810: 0x9443000c  lhu         $v1, 0xC($v0)
    ctx->pc = 0x10e810u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x10e814: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x10e814u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10e818: 0x30630040  andi        $v1, $v1, 0x40
    ctx->pc = 0x10e818u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)64);
    // 0x10e81c: 0x83100a  movz        $v0, $a0, $v1
    ctx->pc = 0x10e81cu;
    if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 4));
label_10e820:
    // 0x10e820: 0xdfb00240  ld          $s0, 0x240($sp)
    ctx->pc = 0x10e820u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 576)));
label_10e824:
    // 0x10e824: 0xdfb10248  ld          $s1, 0x248($sp)
    ctx->pc = 0x10e824u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 584)));
    // 0x10e828: 0xdfb20250  ld          $s2, 0x250($sp)
    ctx->pc = 0x10e828u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 592)));
    // 0x10e82c: 0xdfb30258  ld          $s3, 0x258($sp)
    ctx->pc = 0x10e82cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 600)));
    // 0x10e830: 0xdfb40260  ld          $s4, 0x260($sp)
    ctx->pc = 0x10e830u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 608)));
    // 0x10e834: 0xdfb50268  ld          $s5, 0x268($sp)
    ctx->pc = 0x10e834u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 616)));
    // 0x10e838: 0xdfb60270  ld          $s6, 0x270($sp)
    ctx->pc = 0x10e838u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 624)));
    // 0x10e83c: 0xdfb70278  ld          $s7, 0x278($sp)
    ctx->pc = 0x10e83cu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 632)));
    // 0x10e840: 0xdfbe0280  ld          $fp, 0x280($sp)
    ctx->pc = 0x10e840u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 640)));
    // 0x10e844: 0xdfbf0288  ld          $ra, 0x288($sp)
    ctx->pc = 0x10e844u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 648)));
    // 0x10e848: 0x3e00008  jr          $ra
    ctx->pc = 0x10E848u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10E84Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10E848u;
            // 0x10e84c: 0x27bd0290  addiu       $sp, $sp, 0x290 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 656));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10D220u: goto label_10d220;
            case 0x10D248u: goto label_10d248;
            case 0x10D250u: goto label_10d250;
            case 0x10D264u: goto label_10d264;
            case 0x10D28Cu: goto label_10d28c;
            case 0x10D298u: goto label_10d298;
            case 0x10D2B0u: goto label_10d2b0;
            case 0x10D2B8u: goto label_10d2b8;
            case 0x10D2D8u: goto label_10d2d8;
            case 0x10D2F8u: goto label_10d2f8;
            case 0x10D338u: goto label_10d338;
            case 0x10D348u: goto label_10d348;
            case 0x10D354u: goto label_10d354;
            case 0x10D374u: goto label_10d374;
            case 0x10D378u: goto label_10d378;
            case 0x10D384u: goto label_10d384;
            case 0x10D388u: goto label_10d388;
            case 0x10D3A8u: goto label_10d3a8;
            case 0x10D3C0u: goto label_10d3c0;
            case 0x10D3C8u: goto label_10d3c8;
            case 0x10D3E4u: goto label_10d3e4;
            case 0x10D3F0u: goto label_10d3f0;
            case 0x10D3F4u: goto label_10d3f4;
            case 0x10D400u: goto label_10d400;
            case 0x10D430u: goto label_10d430;
            case 0x10D440u: goto label_10d440;
            case 0x10D468u: goto label_10d468;
            case 0x10D480u: goto label_10d480;
            case 0x10D488u: goto label_10d488;
            case 0x10D490u: goto label_10d490;
            case 0x10D4C0u: goto label_10d4c0;
            case 0x10D4C8u: goto label_10d4c8;
            case 0x10D4D0u: goto label_10d4d0;
            case 0x10D4E4u: goto label_10d4e4;
            case 0x10D4F0u: goto label_10d4f0;
            case 0x10D4F8u: goto label_10d4f8;
            case 0x10D518u: goto label_10d518;
            case 0x10D51Cu: goto label_10d51c;
            case 0x10D538u: goto label_10d538;
            case 0x10D550u: goto label_10d550;
            case 0x10D558u: goto label_10d558;
            case 0x10D570u: goto label_10d570;
            case 0x10D588u: goto label_10d588;
            case 0x10D598u: goto label_10d598;
            case 0x10D5A0u: goto label_10d5a0;
            case 0x10D5A4u: goto label_10d5a4;
            case 0x10D5BCu: goto label_10d5bc;
            case 0x10D5D4u: goto label_10d5d4;
            case 0x10D5E8u: goto label_10d5e8;
            case 0x10D5F8u: goto label_10d5f8;
            case 0x10D604u: goto label_10d604;
            case 0x10D618u: goto label_10d618;
            case 0x10D640u: goto label_10d640;
            case 0x10D658u: goto label_10d658;
            case 0x10D678u: goto label_10d678;
            case 0x10D688u: goto label_10d688;
            case 0x10D6ACu: goto label_10d6ac;
            case 0x10D6D0u: goto label_10d6d0;
            case 0x10D6D8u: goto label_10d6d8;
            case 0x10D6FCu: goto label_10d6fc;
            case 0x10D708u: goto label_10d708;
            case 0x10D728u: goto label_10d728;
            case 0x10D738u: goto label_10d738;
            case 0x10D73Cu: goto label_10d73c;
            case 0x10D750u: goto label_10d750;
            case 0x10D778u: goto label_10d778;
            case 0x10D798u: goto label_10d798;
            case 0x10D7B0u: goto label_10d7b0;
            case 0x10D7B4u: goto label_10d7b4;
            case 0x10D7D0u: goto label_10d7d0;
            case 0x10D7E8u: goto label_10d7e8;
            case 0x10D7F0u: goto label_10d7f0;
            case 0x10D7F8u: goto label_10d7f8;
            case 0x10D820u: goto label_10d820;
            case 0x10D838u: goto label_10d838;
            case 0x10D84Cu: goto label_10d84c;
            case 0x10D870u: goto label_10d870;
            case 0x10D878u: goto label_10d878;
            case 0x10D880u: goto label_10d880;
            case 0x10D884u: goto label_10d884;
            case 0x10D8A0u: goto label_10d8a0;
            case 0x10D8B8u: goto label_10d8b8;
            case 0x10D8C0u: goto label_10d8c0;
            case 0x10D8C8u: goto label_10d8c8;
            case 0x10D8D8u: goto label_10d8d8;
            case 0x10D8E0u: goto label_10d8e0;
            case 0x10D900u: goto label_10d900;
            case 0x10D918u: goto label_10d918;
            case 0x10D920u: goto label_10d920;
            case 0x10D934u: goto label_10d934;
            case 0x10D938u: goto label_10d938;
            case 0x10D948u: goto label_10d948;
            case 0x10D95Cu: goto label_10d95c;
            case 0x10D988u: goto label_10d988;
            case 0x10D990u: goto label_10d990;
            case 0x10D9D0u: goto label_10d9d0;
            case 0x10D9D8u: goto label_10d9d8;
            case 0x10D9F4u: goto label_10d9f4;
            case 0x10D9FCu: goto label_10d9fc;
            case 0x10DA18u: goto label_10da18;
            case 0x10DA20u: goto label_10da20;
            case 0x10DA48u: goto label_10da48;
            case 0x10DA4Cu: goto label_10da4c;
            case 0x10DA58u: goto label_10da58;
            case 0x10DA68u: goto label_10da68;
            case 0x10DA6Cu: goto label_10da6c;
            case 0x10DAA0u: goto label_10daa0;
            case 0x10DAB0u: goto label_10dab0;
            case 0x10DAE8u: goto label_10dae8;
            case 0x10DB24u: goto label_10db24;
            case 0x10DB38u: goto label_10db38;
            case 0x10DB50u: goto label_10db50;
            case 0x10DB54u: goto label_10db54;
            case 0x10DB8Cu: goto label_10db8c;
            case 0x10DB9Cu: goto label_10db9c;
            case 0x10DBA0u: goto label_10dba0;
            case 0x10DBE4u: goto label_10dbe4;
            case 0x10DBF8u: goto label_10dbf8;
            case 0x10DC4Cu: goto label_10dc4c;
            case 0x10DC5Cu: goto label_10dc5c;
            case 0x10DC98u: goto label_10dc98;
            case 0x10DCD4u: goto label_10dcd4;
            case 0x10DCE8u: goto label_10dce8;
            case 0x10DD00u: goto label_10dd00;
            case 0x10DD04u: goto label_10dd04;
            case 0x10DD3Cu: goto label_10dd3c;
            case 0x10DD4Cu: goto label_10dd4c;
            case 0x10DD50u: goto label_10dd50;
            case 0x10DD78u: goto label_10dd78;
            case 0x10DDB4u: goto label_10ddb4;
            case 0x10DDC8u: goto label_10ddc8;
            case 0x10DDE0u: goto label_10dde0;
            case 0x10DDE4u: goto label_10dde4;
            case 0x10DE1Cu: goto label_10de1c;
            case 0x10DE2Cu: goto label_10de2c;
            case 0x10DE30u: goto label_10de30;
            case 0x10DE58u: goto label_10de58;
            case 0x10DE70u: goto label_10de70;
            case 0x10DEBCu: goto label_10debc;
            case 0x10DECCu: goto label_10decc;
            case 0x10DEF0u: goto label_10def0;
            case 0x10DF28u: goto label_10df28;
            case 0x10DF38u: goto label_10df38;
            case 0x10DF60u: goto label_10df60;
            case 0x10DF98u: goto label_10df98;
            case 0x10DFA8u: goto label_10dfa8;
            case 0x10DFC0u: goto label_10dfc0;
            case 0x10DFC4u: goto label_10dfc4;
            case 0x10DFF0u: goto label_10dff0;
            case 0x10E03Cu: goto label_10e03c;
            case 0x10E04Cu: goto label_10e04c;
            case 0x10E068u: goto label_10e068;
            case 0x10E0A0u: goto label_10e0a0;
            case 0x10E0B0u: goto label_10e0b0;
            case 0x10E0D8u: goto label_10e0d8;
            case 0x10E110u: goto label_10e110;
            case 0x10E120u: goto label_10e120;
            case 0x10E138u: goto label_10e138;
            case 0x10E13Cu: goto label_10e13c;
            case 0x10E174u: goto label_10e174;
            case 0x10E184u: goto label_10e184;
            case 0x10E188u: goto label_10e188;
            case 0x10E1C4u: goto label_10e1c4;
            case 0x10E1D8u: goto label_10e1d8;
            case 0x10E220u: goto label_10e220;
            case 0x10E234u: goto label_10e234;
            case 0x10E260u: goto label_10e260;
            case 0x10E298u: goto label_10e298;
            case 0x10E2A8u: goto label_10e2a8;
            case 0x10E2C0u: goto label_10e2c0;
            case 0x10E2C4u: goto label_10e2c4;
            case 0x10E2FCu: goto label_10e2fc;
            case 0x10E30Cu: goto label_10e30c;
            case 0x10E310u: goto label_10e310;
            case 0x10E350u: goto label_10e350;
            case 0x10E38Cu: goto label_10e38c;
            case 0x10E3A0u: goto label_10e3a0;
            case 0x10E3E8u: goto label_10e3e8;
            case 0x10E3F8u: goto label_10e3f8;
            case 0x10E448u: goto label_10e448;
            case 0x10E460u: goto label_10e460;
            case 0x10E47Cu: goto label_10e47c;
            case 0x10E4CCu: goto label_10e4cc;
            case 0x10E4DCu: goto label_10e4dc;
            case 0x10E4ECu: goto label_10e4ec;
            case 0x10E53Cu: goto label_10e53c;
            case 0x10E550u: goto label_10e550;
            case 0x10E578u: goto label_10e578;
            case 0x10E5B0u: goto label_10e5b0;
            case 0x10E5C0u: goto label_10e5c0;
            case 0x10E5D8u: goto label_10e5d8;
            case 0x10E5DCu: goto label_10e5dc;
            case 0x10E614u: goto label_10e614;
            case 0x10E628u: goto label_10e628;
            case 0x10E660u: goto label_10e660;
            case 0x10E670u: goto label_10e670;
            case 0x10E674u: goto label_10e674;
            case 0x10E690u: goto label_10e690;
            case 0x10E69Cu: goto label_10e69c;
            case 0x10E6B0u: goto label_10e6b0;
            case 0x10E6C0u: goto label_10e6c0;
            case 0x10E6C4u: goto label_10e6c4;
            case 0x10E6F8u: goto label_10e6f8;
            case 0x10E730u: goto label_10e730;
            case 0x10E740u: goto label_10e740;
            case 0x10E758u: goto label_10e758;
            case 0x10E75Cu: goto label_10e75c;
            case 0x10E790u: goto label_10e790;
            case 0x10E798u: goto label_10e798;
            case 0x10E7A0u: goto label_10e7a0;
            case 0x10E7CCu: goto label_10e7cc;
            case 0x10E7D4u: goto label_10e7d4;
            case 0x10E7E8u: goto label_10e7e8;
            case 0x10E7ECu: goto label_10e7ec;
            case 0x10E7FCu: goto label_10e7fc;
            case 0x10E804u: goto label_10e804;
            case 0x10E808u: goto label_10e808;
            case 0x10E80Cu: goto label_10e80c;
            case 0x10E820u: goto label_10e820;
            case 0x10E824u: goto label_10e824;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10E850u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
