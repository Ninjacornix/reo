#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00117560
// Address: 0x117560 - 0x1176b8
void sub_00117560_0x117560(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00117560_0x117560");
#endif

    switch (ctx->pc) {
        case 0x1175a0u: goto label_1175a0;
        case 0x1175e8u: goto label_1175e8;
        case 0x1175f8u: goto label_1175f8;
        case 0x117620u: goto label_117620;
        case 0x117630u: goto label_117630;
        case 0x117638u: goto label_117638;
        case 0x117648u: goto label_117648;
        case 0x117650u: goto label_117650;
        case 0x117680u: goto label_117680;
        case 0x117690u: goto label_117690;
        default: break;
    }

    ctx->pc = 0x117560u;

    // 0x117560: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x117560u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x117564: 0xffb10030  sd          $s1, 0x30($sp)
    ctx->pc = 0x117564u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 17));
    // 0x117568: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x117568u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11756c: 0xffb50070  sd          $s5, 0x70($sp)
    ctx->pc = 0x11756cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 21));
    // 0x117570: 0xffb40060  sd          $s4, 0x60($sp)
    ctx->pc = 0x117570u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 20));
    // 0x117574: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x117574u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x117578: 0xffb30050  sd          $s3, 0x50($sp)
    ctx->pc = 0x117578u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 19));
    // 0x11757c: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x11757cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117580: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x117580u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x117584: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x117584u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117588: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x117588u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x11758c: 0xe0a82d  daddu       $s5, $a3, $zero
    ctx->pc = 0x11758cu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117590: 0xffbf0080  sd          $ra, 0x80($sp)
    ctx->pc = 0x117590u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 31));
    // 0x117594: 0x100902d  daddu       $s2, $t0, $zero
    ctx->pc = 0x117594u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117598: 0xc045c92  jal         func_117248
    ctx->pc = 0x117598u;
    SET_GPR_U32(ctx, 31, 0x1175A0u);
    ctx->pc = 0x11759Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117598u;
            // 0x11759c: 0x2484c9c0  addiu       $a0, $a0, -0x3640 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294953408));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117248u;
    if (runtime->hasFunction(0x117248u)) {
        auto targetFn = runtime->lookupFunction(0x117248u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1175A0u; }
        if (ctx->pc != 0x1175A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117248_0x117248(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1175A0u; }
        if (ctx->pc != 0x1175A0u) { return; }
    }
    ctx->pc = 0x1175A0u;
label_1175a0:
    // 0x1175a0: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1175a0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1175a4: 0x1200003b  beqz        $s0, . + 4 + (0x3B << 2)
    ctx->pc = 0x1175A4u;
    {
        const bool branch_taken_0x1175a4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x1175A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1175A4u;
            // 0x1175a8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1175a4) {
            ctx->pc = 0x117694u;
            goto label_117694;
        }
    }
    ctx->pc = 0x1175ACu;
    // 0x1175ac: 0x8e020018  lw          $v0, 0x18($s0)
    ctx->pc = 0x1175acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x1175b0: 0x32430001  andi        $v1, $s2, 0x1
    ctx->pc = 0x1175b0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)1);
    // 0x1175b4: 0xae300000  sw          $s0, 0x0($s1)
    ctx->pc = 0x1175b4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 16));
    // 0x1175b8: 0xae220004  sw          $v0, 0x4($s1)
    ctx->pc = 0x1175b8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    // 0x1175bc: 0xae130020  sw          $s3, 0x20($s0)
    ctx->pc = 0x1175bcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 19));
    // 0x1175c0: 0xae140024  sw          $s4, 0x24($s0)
    ctx->pc = 0x1175c0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 20));
    // 0x1175c4: 0xae150028  sw          $s5, 0x28($s0)
    ctx->pc = 0x1175c4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 21));
    // 0x1175c8: 0xae100014  sw          $s0, 0x14($s0)
    ctx->pc = 0x1175c8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 16));
    // 0x1175cc: 0x14600022  bnez        $v1, . + 4 + (0x22 << 2)
    ctx->pc = 0x1175CCu;
    {
        const bool branch_taken_0x1175cc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1175D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1175CCu;
            // 0x1175d0: 0xae11001c  sw          $s1, 0x1C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1175cc) {
            ctx->pc = 0x117658u;
            goto label_117658;
        }
    }
    ctx->pc = 0x1175D4u;
    // 0x1175d4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1175d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1175d8: 0xafa00008  sw          $zero, 0x8($sp)
    ctx->pc = 0x1175d8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 0));
    // 0x1175dc: 0xafa20004  sw          $v0, 0x4($sp)
    ctx->pc = 0x1175dcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
    // 0x1175e0: 0xc045188  jal         func_114620
    ctx->pc = 0x1175E0u;
    SET_GPR_U32(ctx, 31, 0x1175E8u);
    ctx->pc = 0x1175E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1175E0u;
            // 0x1175e4: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1175E8u; }
        if (ctx->pc != 0x1175E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1175E8u; }
        if (ctx->pc != 0x1175E8u) { return; }
    }
    ctx->pc = 0x1175E8u;
label_1175e8:
    // 0x1175e8: 0x4410005  bgez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1175E8u;
    {
        const bool branch_taken_0x1175e8 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1175ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1175E8u;
            // 0x1175ec: 0xae220008  sw          $v0, 0x8($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1175e8) {
            ctx->pc = 0x117600u;
            goto label_117600;
        }
    }
    ctx->pc = 0x1175F0u;
    // 0x1175f0: 0xc045cbc  jal         func_1172F0
    ctx->pc = 0x1175F0u;
    SET_GPR_U32(ctx, 31, 0x1175F8u);
    ctx->pc = 0x1175F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1175F0u;
            // 0x1175f4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1172F0u;
    if (runtime->hasFunction(0x1172F0u)) {
        auto targetFn = runtime->lookupFunction(0x1172F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1175F8u; }
        if (ctx->pc != 0x1175F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001172F0_0x1172f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1175F8u; }
        if (ctx->pc != 0x1175F8u) { return; }
    }
    ctx->pc = 0x1175F8u;
label_1175f8:
    // 0x1175f8: 0x10000026  b           . + 4 + (0x26 << 2)
    ctx->pc = 0x1175F8u;
    {
        const bool branch_taken_0x1175f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1175FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1175F8u;
            // 0x1175fc: 0x2402fffd  addiu       $v0, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1175f8) {
            ctx->pc = 0x117694u;
            goto label_117694;
        }
    }
    ctx->pc = 0x117600u;
label_117600:
    // 0x117600: 0x3c048000  lui         $a0, 0x8000
    ctx->pc = 0x117600u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32768 << 16));
    // 0x117604: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x117604u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117608: 0x3484000c  ori         $a0, $a0, 0xC
    ctx->pc = 0x117608u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)12);
    // 0x11760c: 0x24060040  addiu       $a2, $zero, 0x40
    ctx->pc = 0x11760cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x117610: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x117610u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117614: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x117614u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117618: 0xc045b82  jal         func_116E08
    ctx->pc = 0x117618u;
    SET_GPR_U32(ctx, 31, 0x117620u);
    ctx->pc = 0x11761Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117618u;
            // 0x11761c: 0x482d  daddu       $t1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116E08u;
    if (runtime->hasFunction(0x116E08u)) {
        auto targetFn = runtime->lookupFunction(0x116E08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117620u; }
        if (ctx->pc != 0x117620u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116E08_0x116e08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117620u; }
        if (ctx->pc != 0x117620u) { return; }
    }
    ctx->pc = 0x117620u;
label_117620:
    // 0x117620: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x117620u;
    {
        const bool branch_taken_0x117620 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x117620) {
            ctx->pc = 0x117640u;
            goto label_117640;
        }
    }
    ctx->pc = 0x117628u;
    // 0x117628: 0xc045cbc  jal         func_1172F0
    ctx->pc = 0x117628u;
    SET_GPR_U32(ctx, 31, 0x117630u);
    ctx->pc = 0x11762Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117628u;
            // 0x11762c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1172F0u;
    if (runtime->hasFunction(0x1172F0u)) {
        auto targetFn = runtime->lookupFunction(0x1172F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117630u; }
        if (ctx->pc != 0x117630u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001172F0_0x1172f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117630u; }
        if (ctx->pc != 0x117630u) { return; }
    }
    ctx->pc = 0x117630u;
label_117630:
    // 0x117630: 0xc04518c  jal         func_114630
    ctx->pc = 0x117630u;
    SET_GPR_U32(ctx, 31, 0x117638u);
    ctx->pc = 0x117634u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117630u;
            // 0x117634: 0x8e240008  lw          $a0, 0x8($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117638u; }
        if (ctx->pc != 0x117638u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117638u; }
        if (ctx->pc != 0x117638u) { return; }
    }
    ctx->pc = 0x117638u;
label_117638:
    // 0x117638: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x117638u;
    {
        const bool branch_taken_0x117638 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11763Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117638u;
            // 0x11763c: 0x2402fffe  addiu       $v0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        ctx->in_delay_slot = false;
        if (branch_taken_0x117638) {
            ctx->pc = 0x117694u;
            goto label_117694;
        }
    }
    ctx->pc = 0x117640u;
label_117640:
    // 0x117640: 0xc045198  jal         func_114660
    ctx->pc = 0x117640u;
    SET_GPR_U32(ctx, 31, 0x117648u);
    ctx->pc = 0x117644u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117640u;
            // 0x117644: 0x8e240008  lw          $a0, 0x8($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117648u; }
        if (ctx->pc != 0x117648u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117648u; }
        if (ctx->pc != 0x117648u) { return; }
    }
    ctx->pc = 0x117648u;
label_117648:
    // 0x117648: 0xc04518c  jal         func_114630
    ctx->pc = 0x117648u;
    SET_GPR_U32(ctx, 31, 0x117650u);
    ctx->pc = 0x11764Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117648u;
            // 0x11764c: 0x8e240008  lw          $a0, 0x8($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114630u;
    if (runtime->hasFunction(0x114630u)) {
        auto targetFn = runtime->lookupFunction(0x114630u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117650u; }
        if (ctx->pc != 0x117650u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114630_0x114630(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117650u; }
        if (ctx->pc != 0x117650u) { return; }
    }
    ctx->pc = 0x117650u;
label_117650:
    // 0x117650: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x117650u;
    {
        const bool branch_taken_0x117650 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x117654u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117650u;
            // 0x117654: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x117650) {
            ctx->pc = 0x117694u;
            goto label_117694;
        }
    }
    ctx->pc = 0x117658u;
label_117658:
    // 0x117658: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x117658u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x11765c: 0x3c048000  lui         $a0, 0x8000
    ctx->pc = 0x11765cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32768 << 16));
    // 0x117660: 0xae220008  sw          $v0, 0x8($s1)
    ctx->pc = 0x117660u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 2));
    // 0x117664: 0x3484000c  ori         $a0, $a0, 0xC
    ctx->pc = 0x117664u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)12);
    // 0x117668: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x117668u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11766c: 0x24060040  addiu       $a2, $zero, 0x40
    ctx->pc = 0x11766cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x117670: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x117670u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117674: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x117674u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117678: 0xc045b82  jal         func_116E08
    ctx->pc = 0x117678u;
    SET_GPR_U32(ctx, 31, 0x117680u);
    ctx->pc = 0x11767Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117678u;
            // 0x11767c: 0x482d  daddu       $t1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116E08u;
    if (runtime->hasFunction(0x116E08u)) {
        auto targetFn = runtime->lookupFunction(0x116E08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117680u; }
        if (ctx->pc != 0x117680u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116E08_0x116e08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117680u; }
        if (ctx->pc != 0x117680u) { return; }
    }
    ctx->pc = 0x117680u;
label_117680:
    // 0x117680: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x117680u;
    {
        const bool branch_taken_0x117680 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x117684u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117680u;
            // 0x117684: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x117680) {
            ctx->pc = 0x117694u;
            goto label_117694;
        }
    }
    ctx->pc = 0x117688u;
    // 0x117688: 0xc045cbc  jal         func_1172F0
    ctx->pc = 0x117688u;
    SET_GPR_U32(ctx, 31, 0x117690u);
    ctx->pc = 0x11768Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117688u;
            // 0x11768c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1172F0u;
    if (runtime->hasFunction(0x1172F0u)) {
        auto targetFn = runtime->lookupFunction(0x1172F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117690u; }
        if (ctx->pc != 0x117690u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001172F0_0x1172f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117690u; }
        if (ctx->pc != 0x117690u) { return; }
    }
    ctx->pc = 0x117690u;
label_117690:
    // 0x117690: 0x2402fffe  addiu       $v0, $zero, -0x2
    ctx->pc = 0x117690u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
label_117694:
    // 0x117694: 0xdfbf0080  ld          $ra, 0x80($sp)
    ctx->pc = 0x117694u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x117698: 0xdfb50070  ld          $s5, 0x70($sp)
    ctx->pc = 0x117698u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x11769c: 0xdfb40060  ld          $s4, 0x60($sp)
    ctx->pc = 0x11769cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1176a0: 0xdfb30050  ld          $s3, 0x50($sp)
    ctx->pc = 0x1176a0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1176a4: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x1176a4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1176a8: 0xdfb10030  ld          $s1, 0x30($sp)
    ctx->pc = 0x1176a8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1176ac: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x1176acu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1176b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1176B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1176B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1176B0u;
            // 0x1176b4: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1175A0u: goto label_1175a0;
            case 0x1175E8u: goto label_1175e8;
            case 0x1175F8u: goto label_1175f8;
            case 0x117600u: goto label_117600;
            case 0x117620u: goto label_117620;
            case 0x117630u: goto label_117630;
            case 0x117638u: goto label_117638;
            case 0x117640u: goto label_117640;
            case 0x117648u: goto label_117648;
            case 0x117650u: goto label_117650;
            case 0x117658u: goto label_117658;
            case 0x117680u: goto label_117680;
            case 0x117690u: goto label_117690;
            case 0x117694u: goto label_117694;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1176B8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
