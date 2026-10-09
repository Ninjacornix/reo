#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001653E8
// Address: 0x1653e8 - 0x165578
void sub_001653E8_0x1653e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001653E8_0x1653e8");
#endif

    switch (ctx->pc) {
        case 0x165424u: goto label_165424;
        case 0x165430u: goto label_165430;
        case 0x16544cu: goto label_16544c;
        case 0x165494u: goto label_165494;
        case 0x1654acu: goto label_1654ac;
        case 0x1654c8u: goto label_1654c8;
        case 0x1654e4u: goto label_1654e4;
        case 0x165500u: goto label_165500;
        case 0x165508u: goto label_165508;
        default: break;
    }

    ctx->pc = 0x1653e8u;

    // 0x1653e8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1653e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1653ec: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1653ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1653f0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1653f0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1653f4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1653f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1653f8: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x1653f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x1653fc: 0x26340f60  addiu       $s4, $s1, 0xF60
    ctx->pc = 0x1653fcu;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 17), 3936));
    // 0x165400: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x165400u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x165404: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x165404u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165408: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x165408u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16540c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x16540cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x165410: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x165410u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x165414: 0x8e331b74  lw          $s3, 0x1B74($s1)
    ctx->pc = 0x165414u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 7028)));
    // 0x165418: 0x8e700000  lw          $s0, 0x0($s3)
    ctx->pc = 0x165418u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x16541c: 0xc04c7be  jal         func_131EF8
    ctx->pc = 0x16541Cu;
    SET_GPR_U32(ctx, 31, 0x165424u);
    ctx->pc = 0x165420u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16541Cu;
            // 0x165420: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x131EF8u;
    if (runtime->hasFunction(0x131EF8u)) {
        auto targetFn = runtime->lookupFunction(0x131EF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165424u; }
        if (ctx->pc != 0x165424u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131EF8_0x131ef8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165424u; }
        if (ctx->pc != 0x165424u) { return; }
    }
    ctx->pc = 0x165424u;
label_165424:
    // 0x165424: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x165424u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165428: 0xc04cb3c  jal         func_132CF0
    ctx->pc = 0x165428u;
    SET_GPR_U32(ctx, 31, 0x165430u);
    ctx->pc = 0x16542Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165428u;
            // 0x16542c: 0x40902d  daddu       $s2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x132CF0u;
    if (runtime->hasFunction(0x132CF0u)) {
        auto targetFn = runtime->lookupFunction(0x132CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165430u; }
        if (ctx->pc != 0x165430u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00132CF0_0x132cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165430u; }
        if (ctx->pc != 0x165430u) { return; }
    }
    ctx->pc = 0x165430u;
label_165430:
    // 0x165430: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x165430u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165434: 0x12000002  beqz        $s0, . + 4 + (0x2 << 2)
    ctx->pc = 0x165434u;
    {
        const bool branch_taken_0x165434 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x165438u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165434u;
            // 0x165438: 0x3c020027  lui         $v0, 0x27 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)39 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x165434) {
            ctx->pc = 0x165440u;
            goto label_165440;
        }
    }
    ctx->pc = 0x16543Cu;
    // 0x16543c: 0xac50076c  sw          $s0, 0x76C($v0)
    ctx->pc = 0x16543cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 1900), GPR_U32(ctx, 16));
label_165440:
    // 0x165440: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x165440u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x165444: 0xc05d58a  jal         func_175628
    ctx->pc = 0x165444u;
    SET_GPR_U32(ctx, 31, 0x16544Cu);
    ctx->pc = 0x165448u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165444u;
            // 0x165448: 0x2405001a  addiu       $a1, $zero, 0x1A (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 26));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16544Cu; }
        if (ctx->pc != 0x16544Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16544Cu; }
        if (ctx->pc != 0x16544Cu) { return; }
    }
    ctx->pc = 0x16544Cu;
label_16544c:
    // 0x16544c: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x16544cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x165450: 0x2800a  movz        $s0, $zero, $v0
    ctx->pc = 0x165450u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 0));
    // 0x165454: 0x1203000c  beq         $s0, $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x165454u;
    {
        const bool branch_taken_0x165454 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 3));
        ctx->pc = 0x165458u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165454u;
            // 0x165458: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x165454) {
            ctx->pc = 0x165488u;
            goto label_165488;
        }
    }
    ctx->pc = 0x16545Cu;
    // 0x16545c: 0x6010006  bgez        $s0, . + 4 + (0x6 << 2)
    ctx->pc = 0x16545Cu;
    {
        const bool branch_taken_0x16545c = (GPR_S64(ctx, 16) >= 0);
        ctx->pc = 0x165460u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16545Cu;
            // 0x165460: 0x2402fffe  addiu       $v0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16545c) {
            ctx->pc = 0x165478u;
            goto label_165478;
        }
    }
    ctx->pc = 0x165464u;
    // 0x165464: 0x1202000e  beq         $s0, $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x165464u;
    {
        const bool branch_taken_0x165464 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        if (branch_taken_0x165464) {
            ctx->pc = 0x1654A0u;
            goto label_1654a0;
        }
    }
    ctx->pc = 0x16546Cu;
    // 0x16546c: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x16546Cu;
    {
        const bool branch_taken_0x16546c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x16546c) {
            ctx->pc = 0x1654B8u;
            goto label_1654b8;
        }
    }
    ctx->pc = 0x165474u;
    // 0x165474: 0x0  nop
    ctx->pc = 0x165474u;
    // NOP
label_165478:
    // 0x165478: 0x12000014  beqz        $s0, . + 4 + (0x14 << 2)
    ctx->pc = 0x165478u;
    {
        const bool branch_taken_0x165478 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x16547Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165478u;
            // 0x16547c: 0x2642fffc  addiu       $v0, $s2, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967292));
        ctx->in_delay_slot = false;
        if (branch_taken_0x165478) {
            ctx->pc = 0x1654CCu;
            goto label_1654cc;
        }
    }
    ctx->pc = 0x165480u;
    // 0x165480: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x165480u;
    {
        const bool branch_taken_0x165480 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x165480) {
            ctx->pc = 0x1654B8u;
            goto label_1654b8;
        }
    }
    ctx->pc = 0x165488u;
label_165488:
    // 0x165488: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x165488u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x16548c: 0xc05a704  jal         func_169C10
    ctx->pc = 0x16548Cu;
    SET_GPR_U32(ctx, 31, 0x165494u);
    ctx->pc = 0x165490u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16548Cu;
            // 0x165490: 0x34a50c08  ori         $a1, $a1, 0xC08 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3080);
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165494u; }
        if (ctx->pc != 0x165494u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165494u; }
        if (ctx->pc != 0x165494u) { return; }
    }
    ctx->pc = 0x165494u;
label_165494:
    // 0x165494: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x165494u;
    {
        const bool branch_taken_0x165494 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x165498u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165494u;
            // 0x165498: 0x2642fffc  addiu       $v0, $s2, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967292));
        ctx->in_delay_slot = false;
        if (branch_taken_0x165494) {
            ctx->pc = 0x1654CCu;
            goto label_1654cc;
        }
    }
    ctx->pc = 0x16549Cu;
    // 0x16549c: 0x0  nop
    ctx->pc = 0x16549cu;
    // NOP
label_1654a0:
    // 0x1654a0: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1654a0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1654a4: 0xc05a704  jal         func_169C10
    ctx->pc = 0x1654A4u;
    SET_GPR_U32(ctx, 31, 0x1654ACu);
    ctx->pc = 0x1654A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1654A4u;
            // 0x1654a8: 0x34a50c09  ori         $a1, $a1, 0xC09 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3081);
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1654ACu; }
        if (ctx->pc != 0x1654ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1654ACu; }
        if (ctx->pc != 0x1654ACu) { return; }
    }
    ctx->pc = 0x1654ACu;
label_1654ac:
    // 0x1654ac: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1654ACu;
    {
        const bool branch_taken_0x1654ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1654B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1654ACu;
            // 0x1654b0: 0x2642fffc  addiu       $v0, $s2, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967292));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1654ac) {
            ctx->pc = 0x1654CCu;
            goto label_1654cc;
        }
    }
    ctx->pc = 0x1654B4u;
    // 0x1654b4: 0x0  nop
    ctx->pc = 0x1654b4u;
    // NOP
label_1654b8:
    // 0x1654b8: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1654b8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1654bc: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1654bcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1654c0: 0xc05a704  jal         func_169C10
    ctx->pc = 0x1654C0u;
    SET_GPR_U32(ctx, 31, 0x1654C8u);
    ctx->pc = 0x1654C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1654C0u;
            // 0x1654c4: 0x34a50c07  ori         $a1, $a1, 0xC07 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3079);
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1654C8u; }
        if (ctx->pc != 0x1654C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1654C8u; }
        if (ctx->pc != 0x1654C8u) { return; }
    }
    ctx->pc = 0x1654C8u;
label_1654c8:
    // 0x1654c8: 0x2642fffc  addiu       $v0, $s2, -0x4
    ctx->pc = 0x1654c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967292));
label_1654cc:
    // 0x1654cc: 0x2c420002  sltiu       $v0, $v0, 0x2
    ctx->pc = 0x1654ccu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x1654d0: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x1654D0u;
    {
        const bool branch_taken_0x1654d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1654d0) {
            ctx->pc = 0x1654D4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1654D0u;
            // 0x1654d4: 0x24020005  addiu       $v0, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1654E8u;
            goto label_1654e8;
        }
    }
    ctx->pc = 0x1654D8u;
    // 0x1654d8: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1654d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1654dc: 0xc05df94  jal         func_177E50
    ctx->pc = 0x1654DCu;
    SET_GPR_U32(ctx, 31, 0x1654E4u);
    ctx->pc = 0x1654E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1654DCu;
            // 0x1654e0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177E50u;
    if (runtime->hasFunction(0x177E50u)) {
        auto targetFn = runtime->lookupFunction(0x177E50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1654E4u; }
        if (ctx->pc != 0x1654E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177E50_0x177e50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1654E4u; }
        if (ctx->pc != 0x1654E4u) { return; }
    }
    ctx->pc = 0x1654E4u;
label_1654e4:
    // 0x1654e4: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1654e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
label_1654e8:
    // 0x1654e8: 0x12420003  beq         $s2, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1654E8u;
    {
        const bool branch_taken_0x1654e8 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 2));
        ctx->pc = 0x1654ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1654E8u;
            // 0x1654ec: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1654e8) {
            ctx->pc = 0x1654F8u;
            goto label_1654f8;
        }
    }
    ctx->pc = 0x1654F0u;
    // 0x1654f0: 0x12000003  beqz        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1654F0u;
    {
        const bool branch_taken_0x1654f0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        if (branch_taken_0x1654f0) {
            ctx->pc = 0x165500u;
            goto label_165500;
        }
    }
    ctx->pc = 0x1654F8u;
label_1654f8:
    // 0x1654f8: 0xc059584  jal         func_165610
    ctx->pc = 0x1654F8u;
    SET_GPR_U32(ctx, 31, 0x165500u);
    ctx->pc = 0x1654FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1654F8u;
            // 0x1654fc: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x165610u;
    if (runtime->hasFunction(0x165610u)) {
        auto targetFn = runtime->lookupFunction(0x165610u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165500u; }
        if (ctx->pc != 0x165500u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00165610_0x165610(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165500u; }
        if (ctx->pc != 0x165500u) { return; }
    }
    ctx->pc = 0x165500u;
label_165500:
    // 0x165500: 0xc059578  jal         func_1655E0
    ctx->pc = 0x165500u;
    SET_GPR_U32(ctx, 31, 0x165508u);
    ctx->pc = 0x165504u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x165500u;
            // 0x165504: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1655E0u;
    if (runtime->hasFunction(0x1655E0u)) {
        auto targetFn = runtime->lookupFunction(0x1655E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165508u; }
        if (ctx->pc != 0x165508u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001655E0_0x1655e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x165508u; }
        if (ctx->pc != 0x165508u) { return; }
    }
    ctx->pc = 0x165508u;
label_165508:
    // 0x165508: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x165508u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16550c: 0x14430012  bne         $v0, $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x16550Cu;
    {
        const bool branch_taken_0x16550c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x165510u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16550Cu;
            // 0x165510: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16550c) {
            ctx->pc = 0x165558u;
            goto label_165558;
        }
    }
    ctx->pc = 0x165514u;
    // 0x165514: 0x56a00011  bnel        $s5, $zero, . + 4 + (0x11 << 2)
    ctx->pc = 0x165514u;
    {
        const bool branch_taken_0x165514 = (GPR_U64(ctx, 21) != GPR_U64(ctx, 0));
        if (branch_taken_0x165514) {
            ctx->pc = 0x165518u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x165514u;
            // 0x165518: 0xdfb10008  ld          $s1, 0x8($sp) (Delay Slot)
        SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16555Cu;
            goto label_16555c;
        }
    }
    ctx->pc = 0x16551Cu;
    // 0x16551c: 0x8e620048  lw          $v0, 0x48($s3)
    ctx->pc = 0x16551cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 72)));
    // 0x165520: 0x5440000e  bnel        $v0, $zero, . + 4 + (0xE << 2)
    ctx->pc = 0x165520u;
    {
        const bool branch_taken_0x165520 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x165520) {
            ctx->pc = 0x165524u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x165520u;
            // 0x165524: 0xdfb10008  ld          $s1, 0x8($sp) (Delay Slot)
        SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16555Cu;
            goto label_16555c;
        }
    }
    ctx->pc = 0x165528u;
    // 0x165528: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x165528u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16552c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16552cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x165530: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x165530u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x165534: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x165534u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x165538: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x165538u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16553c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x16553cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x165540: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x165540u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x165544: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x165544u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x165548: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x165548u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16554c: 0x8059584  j           func_165610
    ctx->pc = 0x16554Cu;
    ctx->pc = 0x165550u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16554Cu;
            // 0x165550: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x165610u;
    if (runtime->hasFunction(0x165610u)) {
        auto targetFn = runtime->lookupFunction(0x165610u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00165610_0x165610(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x165554u;
    // 0x165554: 0x0  nop
    ctx->pc = 0x165554u;
    // NOP
label_165558:
    // 0x165558: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x165558u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
label_16555c:
    // 0x16555c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16555cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x165560: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x165560u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x165564: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x165564u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x165568: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x165568u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16556c: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x16556cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x165570: 0x3e00008  jr          $ra
    ctx->pc = 0x165570u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x165574u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x165570u;
            // 0x165574: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x165424u: goto label_165424;
            case 0x165430u: goto label_165430;
            case 0x165440u: goto label_165440;
            case 0x16544Cu: goto label_16544c;
            case 0x165478u: goto label_165478;
            case 0x165488u: goto label_165488;
            case 0x165494u: goto label_165494;
            case 0x1654A0u: goto label_1654a0;
            case 0x1654ACu: goto label_1654ac;
            case 0x1654B8u: goto label_1654b8;
            case 0x1654C8u: goto label_1654c8;
            case 0x1654CCu: goto label_1654cc;
            case 0x1654E4u: goto label_1654e4;
            case 0x1654E8u: goto label_1654e8;
            case 0x1654F8u: goto label_1654f8;
            case 0x165500u: goto label_165500;
            case 0x165508u: goto label_165508;
            case 0x165558u: goto label_165558;
            case 0x16555Cu: goto label_16555c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x165578u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
