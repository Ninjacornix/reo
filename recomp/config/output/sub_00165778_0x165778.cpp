#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00165778
// Address: 0x165778 - 0x1658cc
void sub_00165778_0x165778(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00165778_0x165778");
#endif

    switch (ctx->pc) {
        case 0x1657a4u: goto label_1657a4;
        case 0x1657b8u: goto label_1657b8;
        case 0x1657c8u: goto label_1657c8;
        case 0x165808u: goto label_165808;
        case 0x165898u: goto label_165898;
        case 0x1658a4u: goto label_1658a4;
        case 0x1658acu: goto label_1658ac;
        default: break;
    }

    ctx->pc = 0x165778u;

    // 0x165778: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x165778u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x16577c: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x16577cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x165780: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x165780u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x165784: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x165784u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165788: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x165788u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16578c: 0x261129b8  addiu       $s1, $s0, 0x29B8
    ctx->pc = 0x16578cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 10680));
    // 0x165790: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x165790u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x165794: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x165794u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x165798: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x165798u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x16579c: 0xc05d58a  jal         func_175628
    ctx->pc = 0x16579Cu;
    SET_GPR_U32(ctx, 31, 0x1657A4u);
    ctx->pc = 0x1657A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16579Cu;
            // 0x1657a0: 0x261329b0  addiu       $s3, $s0, 0x29B0 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 16), 10672));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1657A4u; }
        if (ctx->pc != 0x1657A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1657A4u; }
        if (ctx->pc != 0x1657A4u) { return; }
    }
    ctx->pc = 0x1657A4u;
label_1657a4:
    // 0x1657a4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1657a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1657a8: 0x10400041  beqz        $v0, . + 4 + (0x41 << 2)
    ctx->pc = 0x1657A8u;
    {
        const bool branch_taken_0x1657a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1657ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1657A8u;
            // 0x1657ac: 0x260282d  daddu       $a1, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1657a8) {
            ctx->pc = 0x1658B0u;
            goto label_1658b0;
        }
    }
    ctx->pc = 0x1657B0u;
    // 0x1657b0: 0xc059634  jal         func_1658D0
    ctx->pc = 0x1657B0u;
    SET_GPR_U32(ctx, 31, 0x1657B8u);
    ctx->pc = 0x1657B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1657B0u;
            // 0x1657b4: 0xae131b74  sw          $s3, 0x1B74($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 7028), GPR_U32(ctx, 19));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1658D0u;
    if (runtime->hasFunction(0x1658D0u)) {
        auto targetFn = runtime->lookupFunction(0x1658D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1657B8u; }
        if (ctx->pc != 0x1657B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001658D0_0x1658d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1657B8u; }
        if (ctx->pc != 0x1657B8u) { return; }
    }
    ctx->pc = 0x1657B8u;
label_1657b8:
    // 0x1657b8: 0x1440003d  bnez        $v0, . + 4 + (0x3D << 2)
    ctx->pc = 0x1657B8u;
    {
        const bool branch_taken_0x1657b8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1657BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1657B8u;
            // 0x1657bc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1657b8) {
            ctx->pc = 0x1658B0u;
            goto label_1658b0;
        }
    }
    ctx->pc = 0x1657C0u;
    // 0x1657c0: 0xc0596a2  jal         func_165A88
    ctx->pc = 0x1657C0u;
    SET_GPR_U32(ctx, 31, 0x1657C8u);
    ctx->pc = 0x165A88u;
    if (runtime->hasFunction(0x165A88u)) {
        auto targetFn = runtime->lookupFunction(0x165A88u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1657C8u; }
        if (ctx->pc != 0x1657C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00165A88_0x165a88(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1657C8u; }
        if (ctx->pc != 0x1657C8u) { return; }
    }
    ctx->pc = 0x1657C8u;
label_1657c8:
    // 0x1657c8: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1657c8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1657cc: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x1657ccu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1657d0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1657d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1657d4: 0x16400008  bnez        $s2, . + 4 + (0x8 << 2)
    ctx->pc = 0x1657D4u;
    {
        const bool branch_taken_0x1657d4 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        ctx->pc = 0x1657D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1657D4u;
            // 0x1657d8: 0x34a50c04  ori         $a1, $a1, 0xC04 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3076);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1657d4) {
            ctx->pc = 0x1657F8u;
            goto label_1657f8;
        }
    }
    ctx->pc = 0x1657DCu;
    // 0x1657dc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1657dcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1657e0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1657e0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1657e4: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1657e4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1657e8: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1657e8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1657ec: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1657ecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1657f0: 0x805a704  j           func_169C10
    ctx->pc = 0x1657F0u;
    ctx->pc = 0x1657F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1657F0u;
            // 0x1657f4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1657F8u;
label_1657f8:
    // 0x1657f8: 0x8e260004  lw          $a2, 0x4($s1)
    ctx->pc = 0x1657f8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1657fc: 0x8e240008  lw          $a0, 0x8($s1)
    ctx->pc = 0x1657fcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x165800: 0xc04fe2a  jal         func_13F8A8
    ctx->pc = 0x165800u;
    SET_GPR_U32(ctx, 31, 0x165808u);
    ctx->pc = 0x165804u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165800u;
            // 0x165804: 0x8e250000  lw          $a1, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F8A8u;
    if (runtime->hasFunction(0x13F8A8u)) {
        auto targetFn = runtime->lookupFunction(0x13F8A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165808u; }
        if (ctx->pc != 0x165808u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F8A8_0x13f8a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165808u; }
        if (ctx->pc != 0x165808u) { return; }
    }
    ctx->pc = 0x165808u;
label_165808:
    // 0x165808: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x165808u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16580c: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x16580cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165810: 0x3c020016  lui         $v0, 0x16
    ctx->pc = 0x165810u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)22 << 16));
    // 0x165814: 0x3c050016  lui         $a1, 0x16
    ctx->pc = 0x165814u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)22 << 16));
    // 0x165818: 0x3c030016  lui         $v1, 0x16
    ctx->pc = 0x165818u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)22 << 16));
    // 0x16581c: 0x3c060016  lui         $a2, 0x16
    ctx->pc = 0x16581cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)22 << 16));
    // 0x165820: 0x3c070016  lui         $a3, 0x16
    ctx->pc = 0x165820u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)22 << 16));
    // 0x165824: 0x24ab4820  addiu       $t3, $a1, 0x4820
    ctx->pc = 0x165824u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 5), 18464));
    // 0x165828: 0x120282d  daddu       $a1, $t1, $zero
    ctx->pc = 0x165828u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16582c: 0x26082a5c  addiu       $t0, $s0, 0x2A5C
    ctx->pc = 0x16582cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 16), 10844));
    // 0x165830: 0x244a47e0  addiu       $t2, $v0, 0x47E0
    ctx->pc = 0x165830u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 2), 18400));
    // 0x165834: 0x24634800  addiu       $v1, $v1, 0x4800
    ctx->pc = 0x165834u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 18432));
    // 0x165838: 0x24c64840  addiu       $a2, $a2, 0x4840
    ctx->pc = 0x165838u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 18496));
    // 0x16583c: 0x1520000a  bnez        $t1, . + 4 + (0xA << 2)
    ctx->pc = 0x16583Cu;
    {
        const bool branch_taken_0x16583c = (GPR_U64(ctx, 9) != GPR_U64(ctx, 0));
        ctx->pc = 0x165840u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16583Cu;
            // 0x165840: 0x24e74860  addiu       $a3, $a3, 0x4860 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 18528));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16583c) {
            ctx->pc = 0x165868u;
            goto label_165868;
        }
    }
    ctx->pc = 0x165844u;
    // 0x165844: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x165844u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x165848: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x165848u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16584c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16584cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x165850: 0x34a50c05  ori         $a1, $a1, 0xC05
    ctx->pc = 0x165850u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3077);
    // 0x165854: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x165854u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x165858: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x165858u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16585c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x16585cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x165860: 0x805a704  j           func_169C10
    ctx->pc = 0x165860u;
    ctx->pc = 0x165864u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165860u;
            // 0x165864: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x165868u;
label_165868:
    // 0x165868: 0xae690004  sw          $t1, 0x4($s3)
    ctx->pc = 0x165868u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 9));
    // 0x16586c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x16586cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165870: 0xae720000  sw          $s2, 0x0($s3)
    ctx->pc = 0x165870u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 18));
    // 0x165874: 0xae081c84  sw          $t0, 0x1C84($s0)
    ctx->pc = 0x165874u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 7300), GPR_U32(ctx, 8));
    // 0x165878: 0xad070014  sw          $a3, 0x14($t0)
    ctx->pc = 0x165878u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 20), GPR_U32(ctx, 7));
    // 0x16587c: 0x8e42000c  lw          $v0, 0xC($s2)
    ctx->pc = 0x16587cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 12)));
    // 0x165880: 0xad0a0004  sw          $t2, 0x4($t0)
    ctx->pc = 0x165880u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 4), GPR_U32(ctx, 10));
    // 0x165884: 0xad020000  sw          $v0, 0x0($t0)
    ctx->pc = 0x165884u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 0), GPR_U32(ctx, 2));
    // 0x165888: 0xad030008  sw          $v1, 0x8($t0)
    ctx->pc = 0x165888u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 8), GPR_U32(ctx, 3));
    // 0x16588c: 0xad0b000c  sw          $t3, 0xC($t0)
    ctx->pc = 0x16588cu;
    WRITE32(ADD32(GPR_U32(ctx, 8), 12), GPR_U32(ctx, 11));
    // 0x165890: 0xc04c746  jal         func_131D18
    ctx->pc = 0x165890u;
    SET_GPR_U32(ctx, 31, 0x165898u);
    ctx->pc = 0x165894u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165890u;
            // 0x165894: 0xad060010  sw          $a2, 0x10($t0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 8), 16), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x131D18u;
    if (runtime->hasFunction(0x131D18u)) {
        auto targetFn = runtime->lookupFunction(0x131D18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165898u; }
        if (ctx->pc != 0x165898u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131D18_0x131d18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165898u; }
        if (ctx->pc != 0x165898u) { return; }
    }
    ctx->pc = 0x165898u;
label_165898:
    // 0x165898: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x165898u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16589c: 0xc0597bc  jal         func_165EF0
    ctx->pc = 0x16589Cu;
    SET_GPR_U32(ctx, 31, 0x1658A4u);
    ctx->pc = 0x1658A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16589Cu;
            // 0x1658a0: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x165EF0u;
    if (runtime->hasFunction(0x165EF0u)) {
        auto targetFn = runtime->lookupFunction(0x165EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1658A4u; }
        if (ctx->pc != 0x1658A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00165EF0_0x165ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1658A4u; }
        if (ctx->pc != 0x1658A4u) { return; }
    }
    ctx->pc = 0x1658A4u;
label_1658a4:
    // 0x1658a4: 0xc0596c2  jal         func_165B08
    ctx->pc = 0x1658A4u;
    SET_GPR_U32(ctx, 31, 0x1658ACu);
    ctx->pc = 0x1658A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1658A4u;
            // 0x1658a8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x165B08u;
    if (runtime->hasFunction(0x165B08u)) {
        auto targetFn = runtime->lookupFunction(0x165B08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1658ACu; }
        if (ctx->pc != 0x1658ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00165B08_0x165b08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1658ACu; }
        if (ctx->pc != 0x1658ACu) { return; }
    }
    ctx->pc = 0x1658ACu;
label_1658ac:
    // 0x1658ac: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1658acu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1658b0:
    // 0x1658b0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1658b0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1658b4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1658b4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1658b8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1658b8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1658bc: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1658bcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1658c0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1658c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1658c4: 0x3e00008  jr          $ra
    ctx->pc = 0x1658C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1658C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1658C4u;
            // 0x1658c8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1657A4u: goto label_1657a4;
            case 0x1657B8u: goto label_1657b8;
            case 0x1657C8u: goto label_1657c8;
            case 0x1657F8u: goto label_1657f8;
            case 0x165808u: goto label_165808;
            case 0x165868u: goto label_165868;
            case 0x165898u: goto label_165898;
            case 0x1658A4u: goto label_1658a4;
            case 0x1658ACu: goto label_1658ac;
            case 0x1658B0u: goto label_1658b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1658CCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
