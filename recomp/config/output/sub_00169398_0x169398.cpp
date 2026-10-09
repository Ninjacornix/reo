#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00169398
// Address: 0x169398 - 0x1694f0
void sub_00169398_0x169398(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00169398_0x169398");
#endif

    switch (ctx->pc) {
        case 0x1693bcu: goto label_1693bc;
        case 0x1693e0u: goto label_1693e0;
        case 0x169424u: goto label_169424;
        case 0x169454u: goto label_169454;
        case 0x169460u: goto label_169460;
        case 0x169470u: goto label_169470;
        case 0x169484u: goto label_169484;
        case 0x169498u: goto label_169498;
        case 0x1694acu: goto label_1694ac;
        case 0x1694c0u: goto label_1694c0;
        case 0x1694d0u: goto label_1694d0;
        default: break;
    }

    ctx->pc = 0x169398u;

    // 0x169398: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x169398u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x16939c: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x16939cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x1693a0: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1693a0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1693a4: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x1693a4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1693a8: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x1693a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x1693ac: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x1693acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1693b0: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1693b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1693b4: 0xc05e4c2  jal         func_179308
    ctx->pc = 0x1693B4u;
    SET_GPR_U32(ctx, 31, 0x1693BCu);
    ctx->pc = 0x1693B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1693B4u;
            // 0x1693b8: 0x80902d  daddu       $s2, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179308u;
    if (runtime->hasFunction(0x179308u)) {
        auto targetFn = runtime->lookupFunction(0x179308u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1693BCu; }
        if (ctx->pc != 0x1693BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179308_0x179308(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1693BCu; }
        if (ctx->pc != 0x1693BCu) { return; }
    }
    ctx->pc = 0x1693BCu;
label_1693bc:
    // 0x1693bc: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x1693bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1693c0: 0x27a50004  addiu       $a1, $sp, 0x4
    ctx->pc = 0x1693c0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x1693c4: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1693c4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1693c8: 0x27a60008  addiu       $a2, $sp, 0x8
    ctx->pc = 0x1693c8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
    // 0x1693cc: 0x2180a  movz        $v1, $zero, $v0
    ctx->pc = 0x1693ccu;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 0));
    // 0x1693d0: 0x10600041  beqz        $v1, . + 4 + (0x41 << 2)
    ctx->pc = 0x1693D0u;
    {
        const bool branch_taken_0x1693d0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1693D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1693D0u;
            // 0x1693d4: 0xafa30000  sw          $v1, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1693d0) {
            ctx->pc = 0x1694D8u;
            goto label_1694d8;
        }
    }
    ctx->pc = 0x1693D8u;
    // 0x1693d8: 0xc05e5bc  jal         func_1796F0
    ctx->pc = 0x1693D8u;
    SET_GPR_U32(ctx, 31, 0x1693E0u);
    ctx->pc = 0x1796F0u;
    if (runtime->hasFunction(0x1796F0u)) {
        auto targetFn = runtime->lookupFunction(0x1796F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1693E0u; }
        if (ctx->pc != 0x1693E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001796F0_0x1796f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1693E0u; }
        if (ctx->pc != 0x1693E0u) { return; }
    }
    ctx->pc = 0x1693E0u;
label_1693e0:
    // 0x1693e0: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1693E0u;
    {
        const bool branch_taken_0x1693e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1693E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1693E0u;
            // 0x1693e4: 0x8fa20004  lw          $v0, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1693e0) {
            ctx->pc = 0x1693F4u;
            goto label_1693f4;
        }
    }
    ctx->pc = 0x1693E8u;
    // 0x1693e8: 0xafa00004  sw          $zero, 0x4($sp)
    ctx->pc = 0x1693e8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 0));
    // 0x1693ec: 0xafa00008  sw          $zero, 0x8($sp)
    ctx->pc = 0x1693ecu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 0));
    // 0x1693f0: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x1693f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
label_1693f4:
    // 0x1693f4: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1693f4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1693f8: 0x8fa30008  lw          $v1, 0x8($sp)
    ctx->pc = 0x1693f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1693fc: 0x27a5000c  addiu       $a1, $sp, 0xC
    ctx->pc = 0x1693fcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 12));
    // 0x169400: 0x28040  sll         $s0, $v0, 1
    ctx->pc = 0x169400u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x169404: 0xae220004  sw          $v0, 0x4($s1)
    ctx->pc = 0x169404u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    // 0x169408: 0x2028021  addu        $s0, $s0, $v0
    ctx->pc = 0x169408u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x16940c: 0xae230008  sw          $v1, 0x8($s1)
    ctx->pc = 0x16940cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 3));
    // 0x169410: 0x1080c0  sll         $s0, $s0, 3
    ctx->pc = 0x169410u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 3));
    // 0x169414: 0x2028021  addu        $s0, $s0, $v0
    ctx->pc = 0x169414u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x169418: 0x108080  sll         $s0, $s0, 2
    ctx->pc = 0x169418u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x16941c: 0xc05e6ce  jal         func_179B38
    ctx->pc = 0x16941Cu;
    SET_GPR_U32(ctx, 31, 0x169424u);
    ctx->pc = 0x169420u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16941Cu;
            // 0x169420: 0x2038021  addu        $s0, $s0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179B38u;
    if (runtime->hasFunction(0x179B38u)) {
        auto targetFn = runtime->lookupFunction(0x179B38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169424u; }
        if (ctx->pc != 0x169424u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179B38_0x179b38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169424u; }
        if (ctx->pc != 0x169424u) { return; }
    }
    ctx->pc = 0x169424u;
label_169424:
    // 0x169424: 0x8fa3000c  lw          $v1, 0xC($sp)
    ctx->pc = 0x169424u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x169428: 0x2a10006e  slti        $s0, $s0, 0x6E
    ctx->pc = 0x169428u;
    SET_GPR_U64(ctx, 16, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)110) ? 1 : 0);
    // 0x16942c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x16942cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169430: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x169430u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169434: 0x2180a  movz        $v1, $zero, $v0
    ctx->pc = 0x169434u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 0));
    // 0x169438: 0x31023  negu        $v0, $v1
    ctx->pc = 0x169438u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 3)));
    // 0x16943c: 0x12000002  beqz        $s0, . + 4 + (0x2 << 2)
    ctx->pc = 0x16943Cu;
    {
        const bool branch_taken_0x16943c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x169440u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16943Cu;
            // 0x169440: 0xafa3000c  sw          $v1, 0xC($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16943c) {
            ctx->pc = 0x169448u;
            goto label_169448;
        }
    }
    ctx->pc = 0x169444u;
    // 0x169444: 0xafa2000c  sw          $v0, 0xC($sp)
    ctx->pc = 0x169444u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 2));
label_169448:
    // 0x169448: 0x8fa2000c  lw          $v0, 0xC($sp)
    ctx->pc = 0x169448u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x16944c: 0xc05a53c  jal         func_1694F0
    ctx->pc = 0x16944Cu;
    SET_GPR_U32(ctx, 31, 0x169454u);
    ctx->pc = 0x169450u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16944Cu;
            // 0x169450: 0xae22000c  sw          $v0, 0xC($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1694F0u;
    if (runtime->hasFunction(0x1694F0u)) {
        auto targetFn = runtime->lookupFunction(0x1694F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169454u; }
        if (ctx->pc != 0x169454u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001694F0_0x1694f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169454u; }
        if (ctx->pc != 0x169454u) { return; }
    }
    ctx->pc = 0x169454u;
label_169454:
    // 0x169454: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x169454u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169458: 0xc05a560  jal         func_169580
    ctx->pc = 0x169458u;
    SET_GPR_U32(ctx, 31, 0x169460u);
    ctx->pc = 0x16945Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169458u;
            // 0x16945c: 0x26250020  addiu       $a1, $s1, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169580u;
    if (runtime->hasFunction(0x169580u)) {
        auto targetFn = runtime->lookupFunction(0x169580u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169460u; }
        if (ctx->pc != 0x169460u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169580_0x169580(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169460u; }
        if (ctx->pc != 0x169460u) { return; }
    }
    ctx->pc = 0x169460u;
label_169460:
    // 0x169460: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x169460u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169464: 0x240500bd  addiu       $a1, $zero, 0xBD
    ctx->pc = 0x169464u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 189));
    // 0x169468: 0xc05a58e  jal         func_169638
    ctx->pc = 0x169468u;
    SET_GPR_U32(ctx, 31, 0x169470u);
    ctx->pc = 0x16946Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169468u;
            // 0x16946c: 0x240600bd  addiu       $a2, $zero, 0xBD (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 189));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169638u;
    if (runtime->hasFunction(0x169638u)) {
        auto targetFn = runtime->lookupFunction(0x169638u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169470u; }
        if (ctx->pc != 0x169470u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169638_0x169638(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169470u; }
        if (ctx->pc != 0x169470u) { return; }
    }
    ctx->pc = 0x169470u;
label_169470:
    // 0x169470: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x169470u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169474: 0xae22003c  sw          $v0, 0x3C($s1)
    ctx->pc = 0x169474u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 60), GPR_U32(ctx, 2));
    // 0x169478: 0x240500bf  addiu       $a1, $zero, 0xBF
    ctx->pc = 0x169478u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 191));
    // 0x16947c: 0xc05a58e  jal         func_169638
    ctx->pc = 0x16947Cu;
    SET_GPR_U32(ctx, 31, 0x169484u);
    ctx->pc = 0x169480u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16947Cu;
            // 0x169480: 0x240600bf  addiu       $a2, $zero, 0xBF (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 191));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169638u;
    if (runtime->hasFunction(0x169638u)) {
        auto targetFn = runtime->lookupFunction(0x169638u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169484u; }
        if (ctx->pc != 0x169484u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169638_0x169638(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169484u; }
        if (ctx->pc != 0x169484u) { return; }
    }
    ctx->pc = 0x169484u;
label_169484:
    // 0x169484: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x169484u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169488: 0xae220040  sw          $v0, 0x40($s1)
    ctx->pc = 0x169488u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 64), GPR_U32(ctx, 2));
    // 0x16948c: 0x240500c0  addiu       $a1, $zero, 0xC0
    ctx->pc = 0x16948cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 192));
    // 0x169490: 0xc05a58e  jal         func_169638
    ctx->pc = 0x169490u;
    SET_GPR_U32(ctx, 31, 0x169498u);
    ctx->pc = 0x169494u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169490u;
            // 0x169494: 0x240600df  addiu       $a2, $zero, 0xDF (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 223));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169638u;
    if (runtime->hasFunction(0x169638u)) {
        auto targetFn = runtime->lookupFunction(0x169638u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169498u; }
        if (ctx->pc != 0x169498u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169638_0x169638(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169498u; }
        if (ctx->pc != 0x169498u) { return; }
    }
    ctx->pc = 0x169498u;
label_169498:
    // 0x169498: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x169498u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16949c: 0xae220044  sw          $v0, 0x44($s1)
    ctx->pc = 0x16949cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 68), GPR_U32(ctx, 2));
    // 0x1694a0: 0x240500e0  addiu       $a1, $zero, 0xE0
    ctx->pc = 0x1694a0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 224));
    // 0x1694a4: 0xc05a58e  jal         func_169638
    ctx->pc = 0x1694A4u;
    SET_GPR_U32(ctx, 31, 0x1694ACu);
    ctx->pc = 0x1694A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1694A4u;
            // 0x1694a8: 0x240600ef  addiu       $a2, $zero, 0xEF (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 239));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169638u;
    if (runtime->hasFunction(0x169638u)) {
        auto targetFn = runtime->lookupFunction(0x169638u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1694ACu; }
        if (ctx->pc != 0x1694ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169638_0x169638(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1694ACu; }
        if (ctx->pc != 0x1694ACu) { return; }
    }
    ctx->pc = 0x1694ACu;
label_1694ac:
    // 0x1694ac: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1694acu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1694b0: 0xae220048  sw          $v0, 0x48($s1)
    ctx->pc = 0x1694b0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 72), GPR_U32(ctx, 2));
    // 0x1694b4: 0x2626004c  addiu       $a2, $s1, 0x4C
    ctx->pc = 0x1694b4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), 76));
    // 0x1694b8: 0xc05a5ac  jal         func_1696B0
    ctx->pc = 0x1694B8u;
    SET_GPR_U32(ctx, 31, 0x1694C0u);
    ctx->pc = 0x1694BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1694B8u;
            // 0x1694bc: 0x8e250044  lw          $a1, 0x44($s1) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 68)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1696B0u;
    if (runtime->hasFunction(0x1696B0u)) {
        auto targetFn = runtime->lookupFunction(0x1696B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1694C0u; }
        if (ctx->pc != 0x1694C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001696B0_0x1696b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1694C0u; }
        if (ctx->pc != 0x1694C0u) { return; }
    }
    ctx->pc = 0x1694C0u;
label_1694c0:
    // 0x1694c0: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1694c0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1694c4: 0x8e250048  lw          $a1, 0x48($s1)
    ctx->pc = 0x1694c4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 72)));
    // 0x1694c8: 0xc05a5d2  jal         func_169748
    ctx->pc = 0x1694C8u;
    SET_GPR_U32(ctx, 31, 0x1694D0u);
    ctx->pc = 0x1694CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1694C8u;
            // 0x1694cc: 0x2626005c  addiu       $a2, $s1, 0x5C (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), 92));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169748u;
    if (runtime->hasFunction(0x169748u)) {
        auto targetFn = runtime->lookupFunction(0x169748u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1694D0u; }
        if (ctx->pc != 0x1694D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169748_0x169748(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1694D0u; }
        if (ctx->pc != 0x1694D0u) { return; }
    }
    ctx->pc = 0x1694D0u;
label_1694d0:
    // 0x1694d0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1694d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1694d4: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x1694d4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
label_1694d8:
    // 0x1694d8: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1694d8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1694dc: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x1694dcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1694e0: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x1694e0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1694e4: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1694e4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1694e8: 0x3e00008  jr          $ra
    ctx->pc = 0x1694E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1694ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1694E8u;
            // 0x1694ec: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1693BCu: goto label_1693bc;
            case 0x1693E0u: goto label_1693e0;
            case 0x1693F4u: goto label_1693f4;
            case 0x169424u: goto label_169424;
            case 0x169448u: goto label_169448;
            case 0x169454u: goto label_169454;
            case 0x169460u: goto label_169460;
            case 0x169470u: goto label_169470;
            case 0x169484u: goto label_169484;
            case 0x169498u: goto label_169498;
            case 0x1694ACu: goto label_1694ac;
            case 0x1694C0u: goto label_1694c0;
            case 0x1694D0u: goto label_1694d0;
            case 0x1694D8u: goto label_1694d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1694F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
