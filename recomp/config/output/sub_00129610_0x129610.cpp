#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00129610
// Address: 0x129610 - 0x12979c
void sub_00129610_0x129610(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00129610_0x129610");
#endif

    switch (ctx->pc) {
        case 0x129650u: goto label_129650;
        case 0x129688u: goto label_129688;
        case 0x1296b0u: goto label_1296b0;
        case 0x1296ccu: goto label_1296cc;
        case 0x1296e0u: goto label_1296e0;
        case 0x129708u: goto label_129708;
        case 0x129710u: goto label_129710;
        case 0x129720u: goto label_129720;
        case 0x129734u: goto label_129734;
        case 0x129750u: goto label_129750;
        case 0x12975cu: goto label_12975c;
        case 0x129778u: goto label_129778;
        default: break;
    }

    ctx->pc = 0x129610u;

    // 0x129610: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x129610u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x129614: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x129614u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x129618: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x129618u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12961c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x12961cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x129620: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x129620u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129624: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x129624u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x129628: 0xa0a02d  daddu       $s4, $a1, $zero
    ctx->pc = 0x129628u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12962c: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x12962cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x129630: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x129630u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129634: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x129634u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129638: 0x280382d  daddu       $a3, $s4, $zero
    ctx->pc = 0x129638u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12963c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12963cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x129640: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x129640u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x129644: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x129644u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x129648: 0xc04a13e  jal         func_1284F8
    ctx->pc = 0x129648u;
    SET_GPR_U32(ctx, 31, 0x129650u);
    ctx->pc = 0x12964Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129648u;
            // 0x12964c: 0x260402d  daddu       $t0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1284F8u;
    if (runtime->hasFunction(0x1284F8u)) {
        auto targetFn = runtime->lookupFunction(0x1284F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129650u; }
        if (ctx->pc != 0x129650u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001284F8_0x1284f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129650u; }
        if (ctx->pc != 0x129650u) { return; }
    }
    ctx->pc = 0x129650u;
label_129650:
    // 0x129650: 0x16000003  bnez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x129650u;
    {
        const bool branch_taken_0x129650 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x129654u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129650u;
            // 0x129654: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129650) {
            ctx->pc = 0x129660u;
            goto label_129660;
        }
    }
    ctx->pc = 0x129658u;
    // 0x129658: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x129658u;
    {
        const bool branch_taken_0x129658 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12965Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129658u;
            // 0x12965c: 0x24849f70  addiu       $a0, $a0, -0x6090 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294942576));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129658) {
            ctx->pc = 0x129680u;
            goto label_129680;
        }
    }
    ctx->pc = 0x129660u;
label_129660:
    // 0x129660: 0x6810003  bgez        $s4, . + 4 + (0x3 << 2)
    ctx->pc = 0x129660u;
    {
        const bool branch_taken_0x129660 = (GPR_S64(ctx, 20) >= 0);
        ctx->pc = 0x129664u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129660u;
            // 0x129664: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129660) {
            ctx->pc = 0x129670u;
            goto label_129670;
        }
    }
    ctx->pc = 0x129668u;
    // 0x129668: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x129668u;
    {
        const bool branch_taken_0x129668 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12966Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129668u;
            // 0x12966c: 0x24849f98  addiu       $a0, $a0, -0x6068 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294942616));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129668) {
            ctx->pc = 0x129680u;
            goto label_129680;
        }
    }
    ctx->pc = 0x129670u;
label_129670:
    // 0x129670: 0x56600007  bnel        $s3, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x129670u;
    {
        const bool branch_taken_0x129670 = (GPR_U64(ctx, 19) != GPR_U64(ctx, 0));
        if (branch_taken_0x129670) {
            ctx->pc = 0x129674u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x129670u;
            // 0x129674: 0x82040001  lb          $a0, 0x1($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x129690u;
            goto label_129690;
        }
    }
    ctx->pc = 0x129678u;
    // 0x129678: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x129678u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x12967c: 0x24849fc8  addiu       $a0, $a0, -0x6038
    ctx->pc = 0x12967cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294942664));
label_129680:
    // 0x129680: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x129680u;
    SET_GPR_U32(ctx, 31, 0x129688u);
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129688u; }
        if (ctx->pc != 0x129688u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129688u; }
        if (ctx->pc != 0x129688u) { return; }
    }
    ctx->pc = 0x129688u;
label_129688:
    // 0x129688: 0x1000003c  b           . + 4 + (0x3C << 2)
    ctx->pc = 0x129688u;
    {
        const bool branch_taken_0x129688 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12968Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129688u;
            // 0x12968c: 0x2402fffd  addiu       $v0, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129688) {
            ctx->pc = 0x12977Cu;
            goto label_12977c;
        }
    }
    ctx->pc = 0x129690u;
label_129690:
    // 0x129690: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x129690u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x129694: 0x10830039  beq         $a0, $v1, . + 4 + (0x39 << 2)
    ctx->pc = 0x129694u;
    {
        const bool branch_taken_0x129694 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x129698u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129694u;
            // 0x129698: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129694) {
            ctx->pc = 0x12977Cu;
            goto label_12977c;
        }
    }
    ctx->pc = 0x12969Cu;
    // 0x12969c: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x12969cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1296a0: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1296A0u;
    {
        const bool branch_taken_0x1296a0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1296A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1296A0u;
            // 0x1296a4: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1296a0) {
            ctx->pc = 0x1296B8u;
            goto label_1296b8;
        }
    }
    ctx->pc = 0x1296A8u;
    // 0x1296a8: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x1296A8u;
    SET_GPR_U32(ctx, 31, 0x1296B0u);
    ctx->pc = 0x1296ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1296A8u;
            // 0x1296ac: 0x24849ff0  addiu       $a0, $a0, -0x6010 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294942704));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1296B0u; }
        if (ctx->pc != 0x1296B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1296B0u; }
        if (ctx->pc != 0x1296B0u) { return; }
    }
    ctx->pc = 0x1296B0u;
label_1296b0:
    // 0x1296b0: 0x10000032  b           . + 4 + (0x32 << 2)
    ctx->pc = 0x1296B0u;
    {
        const bool branch_taken_0x1296b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1296B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1296B0u;
            // 0x1296b4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1296b0) {
            ctx->pc = 0x12977Cu;
            goto label_12977c;
        }
    }
    ctx->pc = 0x1296B8u;
label_1296b8:
    // 0x1296b8: 0x1492c0  sll         $s2, $s4, 11
    ctx->pc = 0x1296b8u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 20), 11));
    // 0x1296bc: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1296bcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1296c0: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1296c0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1296c4: 0xc04fe2a  jal         func_13F8A8
    ctx->pc = 0x1296C4u;
    SET_GPR_U32(ctx, 31, 0x1296CCu);
    ctx->pc = 0x1296C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1296C4u;
            // 0x1296c8: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F8A8u;
    if (runtime->hasFunction(0x13F8A8u)) {
        auto targetFn = runtime->lookupFunction(0x13F8A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1296CCu; }
        if (ctx->pc != 0x1296CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F8A8_0x13f8a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1296CCu; }
        if (ctx->pc != 0x1296CCu) { return; }
    }
    ctx->pc = 0x1296CCu;
label_1296cc:
    // 0x1296cc: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x1296ccu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1296d0: 0x1220002a  beqz        $s1, . + 4 + (0x2A << 2)
    ctx->pc = 0x1296D0u;
    {
        const bool branch_taken_0x1296d0 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x1296D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1296D0u;
            // 0x1296d4: 0x2402fffe  addiu       $v0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1296d0) {
            ctx->pc = 0x12977Cu;
            goto label_12977c;
        }
    }
    ctx->pc = 0x1296D8u;
    // 0x1296d8: 0xc049938  jal         func_1264E0
    ctx->pc = 0x1296D8u;
    SET_GPR_U32(ctx, 31, 0x1296E0u);
    ctx->pc = 0x1264E0u;
    if (runtime->hasFunction(0x1264E0u)) {
        auto targetFn = runtime->lookupFunction(0x1264E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1296E0u; }
        if (ctx->pc != 0x1296E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264E0_0x1264e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1296E0u; }
        if (ctx->pc != 0x1296E0u) { return; }
    }
    ctx->pc = 0x1296E0u;
label_1296e0:
    // 0x1296e0: 0xae130024  sw          $s3, 0x24($s0)
    ctx->pc = 0x1296e0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 19));
    // 0x1296e4: 0xae110008  sw          $s1, 0x8($s0)
    ctx->pc = 0x1296e4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 17));
    // 0x1296e8: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x1296e8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x1296ec: 0xae120028  sw          $s2, 0x28($s0)
    ctx->pc = 0x1296ecu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 18));
    // 0x1296f0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1296f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1296f4: 0x8c82d100  lw          $v0, -0x2F00($a0)
    ctx->pc = 0x1296f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4294955264)));
    // 0x1296f8: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1296F8u;
    {
        const bool branch_taken_0x1296f8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x1296FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1296F8u;
            // 0x1296fc: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1296f8) {
            ctx->pc = 0x129708u;
            goto label_129708;
        }
    }
    ctx->pc = 0x129700u;
    // 0x129700: 0xc04a0ca  jal         func_128328
    ctx->pc = 0x129700u;
    SET_GPR_U32(ctx, 31, 0x129708u);
    ctx->pc = 0x129704u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129700u;
            // 0x129704: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x128328u;
    if (runtime->hasFunction(0x128328u)) {
        auto targetFn = runtime->lookupFunction(0x128328u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129708u; }
        if (ctx->pc != 0x129708u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00128328_0x128328(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129708u; }
        if (ctx->pc != 0x129708u) { return; }
    }
    ctx->pc = 0x129708u;
label_129708:
    // 0x129708: 0xc04993e  jal         func_1264F8
    ctx->pc = 0x129708u;
    SET_GPR_U32(ctx, 31, 0x129710u);
    ctx->pc = 0x1264F8u;
    if (runtime->hasFunction(0x1264F8u)) {
        auto targetFn = runtime->lookupFunction(0x1264F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129710u; }
        if (ctx->pc != 0x129710u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264F8_0x1264f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129710u; }
        if (ctx->pc != 0x129710u) { return; }
    }
    ctx->pc = 0x129710u;
label_129710:
    // 0x129710: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x129710u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129714: 0x8e060008  lw          $a2, 0x8($s0)
    ctx->pc = 0x129714u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x129718: 0xc04a51a  jal         func_129468
    ctx->pc = 0x129718u;
    SET_GPR_U32(ctx, 31, 0x129720u);
    ctx->pc = 0x12971Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129718u;
            // 0x12971c: 0x280282d  daddu       $a1, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129468u;
    if (runtime->hasFunction(0x129468u)) {
        auto targetFn = runtime->lookupFunction(0x129468u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129720u; }
        if (ctx->pc != 0x129720u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129468_0x129468(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129720u; }
        if (ctx->pc != 0x129720u) { return; }
    }
    ctx->pc = 0x129720u;
label_129720:
    // 0x129720: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x129720u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129724: 0x5e20000e  bgtzl       $s1, . + 4 + (0xE << 2)
    ctx->pc = 0x129724u;
    {
        const bool branch_taken_0x129724 = (GPR_S64(ctx, 17) > 0);
        if (branch_taken_0x129724) {
            ctx->pc = 0x129728u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x129724u;
            // 0x129728: 0xa2000002  sb          $zero, 0x2($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x129760u;
            goto label_129760;
        }
    }
    ctx->pc = 0x12972Cu;
    // 0x12972c: 0xc049938  jal         func_1264E0
    ctx->pc = 0x12972Cu;
    SET_GPR_U32(ctx, 31, 0x129734u);
    ctx->pc = 0x1264E0u;
    if (runtime->hasFunction(0x1264E0u)) {
        auto targetFn = runtime->lookupFunction(0x1264E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129734u; }
        if (ctx->pc != 0x129734u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264E0_0x1264e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129734u; }
        if (ctx->pc != 0x129734u) { return; }
    }
    ctx->pc = 0x129734u;
label_129734:
    // 0x129734: 0x8e040008  lw          $a0, 0x8($s0)
    ctx->pc = 0x129734u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x129738: 0x10800006  beqz        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x129738u;
    {
        const bool branch_taken_0x129738 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x129738) {
            ctx->pc = 0x129754u;
            goto label_129754;
        }
    }
    ctx->pc = 0x129740u;
    // 0x129740: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x129740u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x129744: 0x8c62000c  lw          $v0, 0xC($v1)
    ctx->pc = 0x129744u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
    // 0x129748: 0x40f809  jalr        $v0
    ctx->pc = 0x129748u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x129750u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x129750u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x129650u: goto label_129650;
            case 0x129660u: goto label_129660;
            case 0x129670u: goto label_129670;
            case 0x129680u: goto label_129680;
            case 0x129688u: goto label_129688;
            case 0x129690u: goto label_129690;
            case 0x1296B0u: goto label_1296b0;
            case 0x1296B8u: goto label_1296b8;
            case 0x1296CCu: goto label_1296cc;
            case 0x1296E0u: goto label_1296e0;
            case 0x129708u: goto label_129708;
            case 0x129710u: goto label_129710;
            case 0x129720u: goto label_129720;
            case 0x129734u: goto label_129734;
            case 0x129750u: goto label_129750;
            case 0x129754u: goto label_129754;
            case 0x12975Cu: goto label_12975c;
            case 0x129760u: goto label_129760;
            case 0x129778u: goto label_129778;
            case 0x12977Cu: goto label_12977c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x129750u; }
            if (ctx->pc != 0x129750u) { return; }
        }
        }
    }
    ctx->pc = 0x129750u;
label_129750:
    // 0x129750: 0xae000008  sw          $zero, 0x8($s0)
    ctx->pc = 0x129750u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
label_129754:
    // 0x129754: 0xc04993e  jal         func_1264F8
    ctx->pc = 0x129754u;
    SET_GPR_U32(ctx, 31, 0x12975Cu);
    ctx->pc = 0x1264F8u;
    if (runtime->hasFunction(0x1264F8u)) {
        auto targetFn = runtime->lookupFunction(0x1264F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12975Cu; }
        if (ctx->pc != 0x12975Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264F8_0x1264f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12975Cu; }
        if (ctx->pc != 0x12975Cu) { return; }
    }
    ctx->pc = 0x12975Cu;
label_12975c:
    // 0x12975c: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x12975cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
label_129760:
    // 0x129760: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x129760u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129764: 0x280382d  daddu       $a3, $s4, $zero
    ctx->pc = 0x129764u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129768: 0x260402d  daddu       $t0, $s3, $zero
    ctx->pc = 0x129768u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12976c: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x12976cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x129770: 0xc04a13e  jal         func_1284F8
    ctx->pc = 0x129770u;
    SET_GPR_U32(ctx, 31, 0x129778u);
    ctx->pc = 0x129774u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129770u;
            // 0x129774: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1284F8u;
    if (runtime->hasFunction(0x1284F8u)) {
        auto targetFn = runtime->lookupFunction(0x1284F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129778u; }
        if (ctx->pc != 0x129778u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001284F8_0x1284f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129778u; }
        if (ctx->pc != 0x129778u) { return; }
    }
    ctx->pc = 0x129778u;
label_129778:
    // 0x129778: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x129778u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_12977c:
    // 0x12977c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12977cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x129780: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x129780u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x129784: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x129784u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x129788: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x129788u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12978c: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x12978cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x129790: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x129790u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x129794: 0x3e00008  jr          $ra
    ctx->pc = 0x129794u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x129798u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129794u;
            // 0x129798: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x129650u: goto label_129650;
            case 0x129660u: goto label_129660;
            case 0x129670u: goto label_129670;
            case 0x129680u: goto label_129680;
            case 0x129688u: goto label_129688;
            case 0x129690u: goto label_129690;
            case 0x1296B0u: goto label_1296b0;
            case 0x1296B8u: goto label_1296b8;
            case 0x1296CCu: goto label_1296cc;
            case 0x1296E0u: goto label_1296e0;
            case 0x129708u: goto label_129708;
            case 0x129710u: goto label_129710;
            case 0x129720u: goto label_129720;
            case 0x129734u: goto label_129734;
            case 0x129750u: goto label_129750;
            case 0x129754u: goto label_129754;
            case 0x12975Cu: goto label_12975c;
            case 0x129760u: goto label_129760;
            case 0x129778u: goto label_129778;
            case 0x12977Cu: goto label_12977c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12979Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
