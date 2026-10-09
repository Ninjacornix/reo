#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00184360
// Address: 0x184360 - 0x184828
void sub_00184360_0x184360(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00184360_0x184360");
#endif

    switch (ctx->pc) {
        case 0x1843c4u: goto label_1843c4;
        case 0x184408u: goto label_184408;
        case 0x184418u: goto label_184418;
        case 0x184438u: goto label_184438;
        case 0x184464u: goto label_184464;
        case 0x184478u: goto label_184478;
        case 0x184498u: goto label_184498;
        case 0x1844c0u: goto label_1844c0;
        case 0x1844dcu: goto label_1844dc;
        case 0x18453cu: goto label_18453c;
        case 0x184580u: goto label_184580;
        case 0x1845a0u: goto label_1845a0;
        case 0x1845acu: goto label_1845ac;
        case 0x1845bcu: goto label_1845bc;
        case 0x1845d0u: goto label_1845d0;
        case 0x184620u: goto label_184620;
        case 0x184674u: goto label_184674;
        case 0x1846d0u: goto label_1846d0;
        case 0x184758u: goto label_184758;
        case 0x1847b8u: goto label_1847b8;
        default: break;
    }

    ctx->pc = 0x184360u;

    // 0x184360: 0x27bdfb00  addiu       $sp, $sp, -0x500
    ctx->pc = 0x184360u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966016));
    // 0x184364: 0xffb104b8  sd          $s1, 0x4B8($sp)
    ctx->pc = 0x184364u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1208), GPR_U64(ctx, 17));
    // 0x184368: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x184368u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18436c: 0x111040  sll         $v0, $s1, 1
    ctx->pc = 0x18436cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 1));
    // 0x184370: 0xffb004b0  sd          $s0, 0x4B0($sp)
    ctx->pc = 0x184370u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1200), GPR_U64(ctx, 16));
    // 0x184374: 0x511021  addu        $v0, $v0, $s1
    ctx->pc = 0x184374u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x184378: 0xffb304c8  sd          $s3, 0x4C8($sp)
    ctx->pc = 0x184378u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1224), GPR_U64(ctx, 19));
    // 0x18437c: 0x21140  sll         $v0, $v0, 5
    ctx->pc = 0x18437cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x184380: 0xffbe04f0  sd          $fp, 0x4F0($sp)
    ctx->pc = 0x184380u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1264), GPR_U64(ctx, 30));
    // 0x184384: 0x511021  addu        $v0, $v0, $s1
    ctx->pc = 0x184384u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x184388: 0xffb204c0  sd          $s2, 0x4C0($sp)
    ctx->pc = 0x184388u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1216), GPR_U64(ctx, 18));
    // 0x18438c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x18438cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x184390: 0xffb404d0  sd          $s4, 0x4D0($sp)
    ctx->pc = 0x184390u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1232), GPR_U64(ctx, 20));
    // 0x184394: 0xffb504d8  sd          $s5, 0x4D8($sp)
    ctx->pc = 0x184394u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1240), GPR_U64(ctx, 21));
    // 0x184398: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x184398u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18439c: 0xffb604e0  sd          $s6, 0x4E0($sp)
    ctx->pc = 0x18439cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1248), GPR_U64(ctx, 22));
    // 0x1843a0: 0xc0f02d  daddu       $fp, $a2, $zero
    ctx->pc = 0x1843a0u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1843a4: 0xffb704e8  sd          $s7, 0x4E8($sp)
    ctx->pc = 0x1843a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1256), GPR_U64(ctx, 23));
    // 0x1843a8: 0x3c130023  lui         $s3, 0x23
    ctx->pc = 0x1843a8u;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)35 << 16));
    // 0x1843ac: 0x2673fa18  addiu       $s3, $s3, -0x5E8
    ctx->pc = 0x1843acu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294965784));
    // 0x1843b0: 0x2629821  addu        $s3, $s3, $v0
    ctx->pc = 0x1843b0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
    // 0x1843b4: 0xffbf04f8  sd          $ra, 0x4F8($sp)
    ctx->pc = 0x1843b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 1272), GPR_U64(ctx, 31));
    // 0x1843b8: 0xafa704a4  sw          $a3, 0x4A4($sp)
    ctx->pc = 0x1843b8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 1188), GPR_U32(ctx, 7));
    // 0x1843bc: 0xc062210  jal         func_188840
    ctx->pc = 0x1843BCu;
    SET_GPR_U32(ctx, 31, 0x1843C4u);
    ctx->pc = 0x1843C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1843BCu;
            // 0x1843c0: 0xafa804a8  sw          $t0, 0x4A8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 1192), GPR_U32(ctx, 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x188840u;
    if (runtime->hasFunction(0x188840u)) {
        auto targetFn = runtime->lookupFunction(0x188840u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1843C4u; }
        if (ctx->pc != 0x1843C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00188840_0x188840(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1843C4u; }
        if (ctx->pc != 0x1843C4u) { return; }
    }
    ctx->pc = 0x1843C4u;
label_1843c4:
    // 0x1843c4: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1843C4u;
    {
        const bool branch_taken_0x1843c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1843C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1843C4u;
            // 0x1843c8: 0x24030898  addiu       $v1, $zero, 0x898 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2200));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1843c4) {
            ctx->pc = 0x1843D8u;
            goto label_1843d8;
        }
    }
    ctx->pc = 0x1843CCu;
    // 0x1843cc: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1843ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x1843d0: 0x10000108  b           . + 4 + (0x108 << 2)
    ctx->pc = 0x1843D0u;
    {
        const bool branch_taken_0x1843d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1843D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1843D0u;
            // 0x1843d4: 0x34420013  ori         $v0, $v0, 0x13 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)19);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1843d0) {
            ctx->pc = 0x1847F4u;
            goto label_1847f4;
        }
    }
    ctx->pc = 0x1843D8u;
label_1843d8:
    // 0x1843d8: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1843d8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x1843dc: 0x2231818  mult        $v1, $s1, $v1
    ctx->pc = 0x1843dcu;
    { int64_t result = (int64_t)GPR_S32(ctx, 17) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1843e0: 0x3c040028  lui         $a0, 0x28
    ctx->pc = 0x1843e0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)40 << 16));
    // 0x1843e4: 0x832021  addu        $a0, $a0, $v1
    ctx->pc = 0x1843e4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1843e8: 0x8c8463d4  lw          $a0, 0x63D4($a0)
    ctx->pc = 0x1843e8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 25556)));
    // 0x1843ec: 0x10800101  beqz        $a0, . + 4 + (0x101 << 2)
    ctx->pc = 0x1843ECu;
    {
        const bool branch_taken_0x1843ec = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1843F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1843ECu;
            // 0x1843f0: 0x3442006f  ori         $v0, $v0, 0x6F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)111);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1843ec) {
            ctx->pc = 0x1847F4u;
            goto label_1847f4;
        }
    }
    ctx->pc = 0x1843F4u;
    // 0x1843f4: 0x27b20420  addiu       $s2, $sp, 0x420
    ctx->pc = 0x1843f4u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 29), 1056));
    // 0x1843f8: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1843f8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1843fc: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1843fcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184400: 0xc0609a2  jal         func_182688
    ctx->pc = 0x184400u;
    SET_GPR_U32(ctx, 31, 0x184408u);
    ctx->pc = 0x184404u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x184400u;
            // 0x184404: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182688u;
    if (runtime->hasFunction(0x182688u)) {
        auto targetFn = runtime->lookupFunction(0x182688u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184408u; }
        if (ctx->pc != 0x184408u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182688_0x182688(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184408u; }
        if (ctx->pc != 0x184408u) { return; }
    }
    ctx->pc = 0x184408u;
label_184408:
    // 0x184408: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x184408u;
    {
        const bool branch_taken_0x184408 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x184408) {
            ctx->pc = 0x184420u;
            goto label_184420;
        }
    }
    ctx->pc = 0x184410u;
    // 0x184410: 0xc06089c  jal         func_182270
    ctx->pc = 0x184410u;
    SET_GPR_U32(ctx, 31, 0x184418u);
    ctx->pc = 0x184414u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x184410u;
            // 0x184414: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182270u;
    if (runtime->hasFunction(0x182270u)) {
        auto targetFn = runtime->lookupFunction(0x182270u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184418u; }
        if (ctx->pc != 0x184418u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182270_0x182270(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184418u; }
        if (ctx->pc != 0x184418u) { return; }
    }
    ctx->pc = 0x184418u;
label_184418:
    // 0x184418: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x184418u;
    {
        const bool branch_taken_0x184418 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x184418) {
            ctx->pc = 0x184430u;
            goto label_184430;
        }
    }
    ctx->pc = 0x184420u;
label_184420:
    // 0x184420: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x184420u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x184424: 0x100000f3  b           . + 4 + (0xF3 << 2)
    ctx->pc = 0x184424u;
    {
        const bool branch_taken_0x184424 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x184428u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184424u;
            // 0x184428: 0x34420016  ori         $v0, $v0, 0x16 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)22);
        ctx->in_delay_slot = false;
        if (branch_taken_0x184424) {
            ctx->pc = 0x1847F4u;
            goto label_1847f4;
        }
    }
    ctx->pc = 0x18442Cu;
    // 0x18442c: 0x0  nop
    ctx->pc = 0x18442cu;
    // NOP
label_184430:
    // 0x184430: 0xc060880  jal         func_182200
    ctx->pc = 0x184430u;
    SET_GPR_U32(ctx, 31, 0x184438u);
    ctx->pc = 0x184434u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x184430u;
            // 0x184434: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182200u;
    if (runtime->hasFunction(0x182200u)) {
        auto targetFn = runtime->lookupFunction(0x182200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184438u; }
        if (ctx->pc != 0x184438u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182200_0x182200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184438u; }
        if (ctx->pc != 0x184438u) { return; }
    }
    ctx->pc = 0x184438u;
label_184438:
    // 0x184438: 0x54400005  bnel        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x184438u;
    {
        const bool branch_taken_0x184438 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x184438) {
            ctx->pc = 0x18443Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x184438u;
            // 0x18443c: 0x8e66003c  lw          $a2, 0x3C($s3) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 60)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x184450u;
            goto label_184450;
        }
    }
    ctx->pc = 0x184440u;
    // 0x184440: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x184440u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x184444: 0x100000eb  b           . + 4 + (0xEB << 2)
    ctx->pc = 0x184444u;
    {
        const bool branch_taken_0x184444 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x184448u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184444u;
            // 0x184448: 0x3442005b  ori         $v0, $v0, 0x5B (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)91);
        ctx->in_delay_slot = false;
        if (branch_taken_0x184444) {
            ctx->pc = 0x1847F4u;
            goto label_1847f4;
        }
    }
    ctx->pc = 0x18444Cu;
    // 0x18444c: 0x0  nop
    ctx->pc = 0x18444cu;
    // NOP
label_184450:
    // 0x184450: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x184450u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184454: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x184454u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184458: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x184458u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18445c: 0xc060c02  jal         func_183008
    ctx->pc = 0x18445Cu;
    SET_GPR_U32(ctx, 31, 0x184464u);
    ctx->pc = 0x184460u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18445Cu;
            // 0x184460: 0xa82d  daddu       $s5, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x183008u;
    if (runtime->hasFunction(0x183008u)) {
        auto targetFn = runtime->lookupFunction(0x183008u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184464u; }
        if (ctx->pc != 0x184464u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00183008_0x183008(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184464u; }
        if (ctx->pc != 0x184464u) { return; }
    }
    ctx->pc = 0x184464u;
label_184464:
    // 0x184464: 0x144000e4  bnez        $v0, . + 4 + (0xE4 << 2)
    ctx->pc = 0x184464u;
    {
        const bool branch_taken_0x184464 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x184468u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184464u;
            // 0x184468: 0xdfb004b0  ld          $s0, 0x4B0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 1200)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x184464) {
            ctx->pc = 0x1847F8u;
            goto label_1847f8;
        }
    }
    ctx->pc = 0x18446Cu;
    // 0x18446c: 0x27b00040  addiu       $s0, $sp, 0x40
    ctx->pc = 0x18446cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
    // 0x184470: 0xc042c56  jal         func_10B158
    ctx->pc = 0x184470u;
    SET_GPR_U32(ctx, 31, 0x184478u);
    ctx->pc = 0x184474u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x184470u;
            // 0x184474: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184478u; }
        if (ctx->pc != 0x184478u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184478u; }
        if (ctx->pc != 0x184478u) { return; }
    }
    ctx->pc = 0x184478u;
label_184478:
    // 0x184478: 0x2c430020  sltiu       $v1, $v0, 0x20
    ctx->pc = 0x184478u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)32) ? 1 : 0);
    // 0x18447c: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x18447cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x184480: 0x106000dc  beqz        $v1, . + 4 + (0xDC << 2)
    ctx->pc = 0x184480u;
    {
        const bool branch_taken_0x184480 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x184484u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184480u;
            // 0x184484: 0x34429002  ori         $v0, $v0, 0x9002 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)36866);
        ctx->in_delay_slot = false;
        if (branch_taken_0x184480) {
            ctx->pc = 0x1847F4u;
            goto label_1847f4;
        }
    }
    ctx->pc = 0x184488u;
    // 0x184488: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x184488u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x18448c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x18448cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184490: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x184490u;
    SET_GPR_U32(ctx, 31, 0x184498u);
    ctx->pc = 0x184494u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x184490u;
            // 0x184494: 0x24a517b0  addiu       $a1, $a1, 0x17B0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 6064));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184498u; }
        if (ctx->pc != 0x184498u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184498u; }
        if (ctx->pc != 0x184498u) { return; }
    }
    ctx->pc = 0x184498u;
label_184498:
    // 0x184498: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x184498u;
    {
        const bool branch_taken_0x184498 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x184498) {
            ctx->pc = 0x18449Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x184498u;
            // 0x18449c: 0x3c020024  lui         $v0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1844B0u;
            goto label_1844b0;
        }
    }
    ctx->pc = 0x1844A0u;
    // 0x1844a0: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1844a0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x1844a4: 0x100000d3  b           . + 4 + (0xD3 << 2)
    ctx->pc = 0x1844A4u;
    {
        const bool branch_taken_0x1844a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1844A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1844A4u;
            // 0x1844a8: 0x34429002  ori         $v0, $v0, 0x9002 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)36866);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1844a4) {
            ctx->pc = 0x1847F4u;
            goto label_1847f4;
        }
    }
    ctx->pc = 0x1844ACu;
    // 0x1844ac: 0x0  nop
    ctx->pc = 0x1844acu;
    // NOP
label_1844b0:
    // 0x1844b0: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1844b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1844b4: 0x245017c8  addiu       $s0, $v0, 0x17C8
    ctx->pc = 0x1844b4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 6088));
    // 0x1844b8: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x1844B8u;
    SET_GPR_U32(ctx, 31, 0x1844C0u);
    ctx->pc = 0x1844BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1844B8u;
            // 0x1844bc: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1844C0u; }
        if (ctx->pc != 0x1844C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1844C0u; }
        if (ctx->pc != 0x1844C0u) { return; }
    }
    ctx->pc = 0x1844C0u;
label_1844c0:
    // 0x1844c0: 0x1440002d  bnez        $v0, . + 4 + (0x2D << 2)
    ctx->pc = 0x1844C0u;
    {
        const bool branch_taken_0x1844c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1844C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1844C0u;
            // 0x1844c4: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1844c0) {
            ctx->pc = 0x184578u;
            goto label_184578;
        }
    }
    ctx->pc = 0x1844C8u;
    // 0x1844c8: 0x3c0302d  daddu       $a2, $fp, $zero
    ctx->pc = 0x1844c8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1844cc: 0x30c20007  andi        $v0, $a2, 0x7
    ctx->pc = 0x1844ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)7);
    // 0x1844d0: 0x10400019  beqz        $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x1844D0u;
    {
        const bool branch_taken_0x1844d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1844D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1844D0u;
            // 0x1844d4: 0x3a0182d  daddu       $v1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1844d0) {
            ctx->pc = 0x184538u;
            goto label_184538;
        }
    }
    ctx->pc = 0x1844D8u;
    // 0x1844d8: 0x27a20200  addiu       $v0, $sp, 0x200
    ctx->pc = 0x1844d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 512));
label_1844dc:
    // 0x1844dc: 0x68640007  ldl         $a0, 0x7($v1)
    ctx->pc = 0x1844dcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x1844e0: 0x6c640000  ldr         $a0, 0x0($v1)
    ctx->pc = 0x1844e0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x1844e4: 0x6865000f  ldl         $a1, 0xF($v1)
    ctx->pc = 0x1844e4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x1844e8: 0x6c650008  ldr         $a1, 0x8($v1)
    ctx->pc = 0x1844e8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x1844ec: 0x68670017  ldl         $a3, 0x17($v1)
    ctx->pc = 0x1844ecu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem << shift)); }
    // 0x1844f0: 0x6c670010  ldr         $a3, 0x10($v1)
    ctx->pc = 0x1844f0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem >> shift)); }
    // 0x1844f4: 0x6868001f  ldl         $t0, 0x1F($v1)
    ctx->pc = 0x1844f4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x1844f8: 0x6c680018  ldr         $t0, 0x18($v1)
    ctx->pc = 0x1844f8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x1844fc: 0xb0c40007  sdl         $a0, 0x7($a2)
    ctx->pc = 0x1844fcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x184500: 0xb4c40000  sdr         $a0, 0x0($a2)
    ctx->pc = 0x184500u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x184504: 0xb0c5000f  sdl         $a1, 0xF($a2)
    ctx->pc = 0x184504u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x184508: 0xb4c50008  sdr         $a1, 0x8($a2)
    ctx->pc = 0x184508u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x18450c: 0xb0c70017  sdl         $a3, 0x17($a2)
    ctx->pc = 0x18450cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x184510: 0xb4c70010  sdr         $a3, 0x10($a2)
    ctx->pc = 0x184510u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x184514: 0xb0c8001f  sdl         $t0, 0x1F($a2)
    ctx->pc = 0x184514u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x184518: 0xb4c80018  sdr         $t0, 0x18($a2)
    ctx->pc = 0x184518u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x18451c: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x18451cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x184520: 0x0  nop
    ctx->pc = 0x184520u;
    // NOP
    // 0x184524: 0x0  nop
    ctx->pc = 0x184524u;
    // NOP
    // 0x184528: 0x1462ffec  bne         $v1, $v0, . + 4 + (-0x14 << 2)
    ctx->pc = 0x184528u;
    {
        const bool branch_taken_0x184528 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x18452Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184528u;
            // 0x18452c: 0x24c60020  addiu       $a2, $a2, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x184528) {
            ctx->pc = 0x1844DCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1844dc;
        }
    }
    ctx->pc = 0x184530u;
    // 0x184530: 0x1000007d  b           . + 4 + (0x7D << 2)
    ctx->pc = 0x184530u;
    {
        const bool branch_taken_0x184530 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x184530) {
            ctx->pc = 0x184728u;
            goto label_184728;
        }
    }
    ctx->pc = 0x184538u;
label_184538:
    // 0x184538: 0x27a20200  addiu       $v0, $sp, 0x200
    ctx->pc = 0x184538u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 512));
label_18453c:
    // 0x18453c: 0xdc640000  ld          $a0, 0x0($v1)
    ctx->pc = 0x18453cu;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x184540: 0xdc650008  ld          $a1, 0x8($v1)
    ctx->pc = 0x184540u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x184544: 0xdc670010  ld          $a3, 0x10($v1)
    ctx->pc = 0x184544u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x184548: 0xdc680018  ld          $t0, 0x18($v1)
    ctx->pc = 0x184548u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x18454c: 0xfcc40000  sd          $a0, 0x0($a2)
    ctx->pc = 0x18454cu;
    WRITE64(ADD32(GPR_U32(ctx, 6), 0), GPR_U64(ctx, 4));
    // 0x184550: 0xfcc50008  sd          $a1, 0x8($a2)
    ctx->pc = 0x184550u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 8), GPR_U64(ctx, 5));
    // 0x184554: 0xfcc70010  sd          $a3, 0x10($a2)
    ctx->pc = 0x184554u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 16), GPR_U64(ctx, 7));
    // 0x184558: 0xfcc80018  sd          $t0, 0x18($a2)
    ctx->pc = 0x184558u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 24), GPR_U64(ctx, 8));
    // 0x18455c: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x18455cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x184560: 0x0  nop
    ctx->pc = 0x184560u;
    // NOP
    // 0x184564: 0x0  nop
    ctx->pc = 0x184564u;
    // NOP
    // 0x184568: 0x1462fff4  bne         $v1, $v0, . + 4 + (-0xC << 2)
    ctx->pc = 0x184568u;
    {
        const bool branch_taken_0x184568 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x18456Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184568u;
            // 0x18456c: 0x24c60020  addiu       $a2, $a2, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x184568) {
            ctx->pc = 0x18453Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18453c;
        }
    }
    ctx->pc = 0x184570u;
    // 0x184570: 0x1000006d  b           . + 4 + (0x6D << 2)
    ctx->pc = 0x184570u;
    {
        const bool branch_taken_0x184570 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x184570) {
            ctx->pc = 0x184728u;
            goto label_184728;
        }
    }
    ctx->pc = 0x184578u;
label_184578:
    // 0x184578: 0xc060948  jal         func_182520
    ctx->pc = 0x184578u;
    SET_GPR_U32(ctx, 31, 0x184580u);
    ctx->pc = 0x18457Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x184578u;
            // 0x18457c: 0x27a40421  addiu       $a0, $sp, 0x421 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 1057));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182520u;
    if (runtime->hasFunction(0x182520u)) {
        auto targetFn = runtime->lookupFunction(0x182520u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184580u; }
        if (ctx->pc != 0x184580u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182520_0x182520(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184580u; }
        if (ctx->pc != 0x184580u) { return; }
    }
    ctx->pc = 0x184580u;
label_184580:
    // 0x184580: 0x3c168101  lui         $s6, 0x8101
    ctx->pc = 0x184580u;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)33025 << 16));
    // 0x184584: 0x3c178101  lui         $s7, 0x8101
    ctx->pc = 0x184584u;
    SET_GPR_S32(ctx, 23, (int32_t)((uint32_t)33025 << 16));
    // 0x184588: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x184588u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18458c: 0x27b20200  addiu       $s2, $sp, 0x200
    ctx->pc = 0x18458cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 29), 512));
    // 0x184590: 0x27b30400  addiu       $s3, $sp, 0x400
    ctx->pc = 0x184590u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 1024));
    // 0x184594: 0x24140001  addiu       $s4, $zero, 0x1
    ctx->pc = 0x184594u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x184598: 0x36d60002  ori         $s6, $s6, 0x2
    ctx->pc = 0x184598u;
    SET_GPR_U64(ctx, 22, GPR_U64(ctx, 22) | (uint64_t)(uint16_t)2);
    // 0x18459c: 0x36f79fff  ori         $s7, $s7, 0x9FFF
    ctx->pc = 0x18459cu;
    SET_GPR_U64(ctx, 23, GPR_U64(ctx, 23) | (uint64_t)(uint16_t)40959);
label_1845a0:
    // 0x1845a0: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1845a0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1845a4: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1845A4u;
    SET_GPR_U32(ctx, 31, 0x1845ACu);
    ctx->pc = 0x1845A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1845A4u;
            // 0x1845a8: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1845ACu; }
        if (ctx->pc != 0x1845ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1845ACu; }
        if (ctx->pc != 0x1845ACu) { return; }
    }
    ctx->pc = 0x1845ACu;
label_1845ac:
    // 0x1845ac: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1845acu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1845b0: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x1845b0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x1845b4: 0xc060948  jal         func_182520
    ctx->pc = 0x1845B4u;
    SET_GPR_U32(ctx, 31, 0x1845BCu);
    ctx->pc = 0x1845B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1845B4u;
            // 0x1845b8: 0x244517c8  addiu       $a1, $v0, 0x17C8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 6088));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182520u;
    if (runtime->hasFunction(0x182520u)) {
        auto targetFn = runtime->lookupFunction(0x182520u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1845BCu; }
        if (ctx->pc != 0x1845BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182520_0x182520(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1845BCu; }
        if (ctx->pc != 0x1845BCu) { return; }
    }
    ctx->pc = 0x1845BCu;
label_1845bc:
    // 0x1845bc: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1845bcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1845c0: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1845c0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1845c4: 0x240102d  daddu       $v0, $s2, $zero
    ctx->pc = 0x1845c4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1845c8: 0x290a80a  movz        $s5, $s4, $s0
    ctx->pc = 0x1845c8u;
    if (GPR_U64(ctx, 16) == 0) SET_GPR_VEC(ctx, 21, GPR_VEC(ctx, 20));
    // 0x1845cc: 0x3a0182d  daddu       $v1, $sp, $zero
    ctx->pc = 0x1845ccu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
label_1845d0:
    // 0x1845d0: 0xdc650000  ld          $a1, 0x0($v1)
    ctx->pc = 0x1845d0u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1845d4: 0xdc660008  ld          $a2, 0x8($v1)
    ctx->pc = 0x1845d4u;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x1845d8: 0xdc670010  ld          $a3, 0x10($v1)
    ctx->pc = 0x1845d8u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x1845dc: 0xdc680018  ld          $t0, 0x18($v1)
    ctx->pc = 0x1845dcu;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x1845e0: 0xfc450000  sd          $a1, 0x0($v0)
    ctx->pc = 0x1845e0u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 5));
    // 0x1845e4: 0xfc460008  sd          $a2, 0x8($v0)
    ctx->pc = 0x1845e4u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 6));
    // 0x1845e8: 0xfc470010  sd          $a3, 0x10($v0)
    ctx->pc = 0x1845e8u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 16), GPR_U64(ctx, 7));
    // 0x1845ec: 0xfc480018  sd          $t0, 0x18($v0)
    ctx->pc = 0x1845ecu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 24), GPR_U64(ctx, 8));
    // 0x1845f0: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x1845f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x1845f4: 0x0  nop
    ctx->pc = 0x1845f4u;
    // NOP
    // 0x1845f8: 0x0  nop
    ctx->pc = 0x1845f8u;
    // NOP
    // 0x1845fc: 0x1464fff4  bne         $v1, $a0, . + 4 + (-0xC << 2)
    ctx->pc = 0x1845FCu;
    {
        const bool branch_taken_0x1845fc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        ctx->pc = 0x184600u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1845FCu;
            // 0x184600: 0x24420020  addiu       $v0, $v0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1845fc) {
            ctx->pc = 0x1845D0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1845d0;
        }
    }
    ctx->pc = 0x184604u;
    // 0x184604: 0x8fa80210  lw          $t0, 0x210($sp)
    ctx->pc = 0x184604u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 528)));
    // 0x184608: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x184608u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18460c: 0x8fa90204  lw          $t1, 0x204($sp)
    ctx->pc = 0x18460cu;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 516)));
    // 0x184610: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x184610u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184614: 0x27a604a0  addiu       $a2, $sp, 0x4A0
    ctx->pc = 0x184614u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 1184));
    // 0x184618: 0xc061038  jal         func_1840E0
    ctx->pc = 0x184618u;
    SET_GPR_U32(ctx, 31, 0x184620u);
    ctx->pc = 0x18461Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x184618u;
            // 0x18461c: 0x260382d  daddu       $a3, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1840E0u;
    if (runtime->hasFunction(0x1840E0u)) {
        auto targetFn = runtime->lookupFunction(0x1840E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184620u; }
        if (ctx->pc != 0x184620u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001840E0_0x1840e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x184620u; }
        if (ctx->pc != 0x184620u) { return; }
    }
    ctx->pc = 0x184620u;
label_184620:
    // 0x184620: 0x97a30000  lhu         $v1, 0x0($sp)
    ctx->pc = 0x184620u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x184624: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x184624u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x184628: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x184628u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x18462c: 0x30632000  andi        $v1, $v1, 0x2000
    ctx->pc = 0x18462cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)8192);
    // 0x184630: 0x14600070  bnez        $v1, . + 4 + (0x70 << 2)
    ctx->pc = 0x184630u;
    {
        const bool branch_taken_0x184630 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x184634u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184630u;
            // 0x184634: 0x3442000d  ori         $v0, $v0, 0xD (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)13);
        ctx->in_delay_slot = false;
        if (branch_taken_0x184630) {
            ctx->pc = 0x1847F4u;
            goto label_1847f4;
        }
    }
    ctx->pc = 0x184638u;
    // 0x184638: 0x12b40007  beq         $s5, $s4, . + 4 + (0x7 << 2)
    ctx->pc = 0x184638u;
    {
        const bool branch_taken_0x184638 = (GPR_U64(ctx, 21) == GPR_U64(ctx, 20));
        if (branch_taken_0x184638) {
            ctx->pc = 0x184658u;
            goto label_184658;
        }
    }
    ctx->pc = 0x184640u;
    // 0x184640: 0x1080ffd7  beqz        $a0, . + 4 + (-0x29 << 2)
    ctx->pc = 0x184640u;
    {
        const bool branch_taken_0x184640 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x184644u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184640u;
            // 0x184644: 0x961826  xor         $v1, $a0, $s6 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) ^ GPR_U64(ctx, 22));
        ctx->in_delay_slot = false;
        if (branch_taken_0x184640) {
            ctx->pc = 0x1845A0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1845a0;
        }
    }
    ctx->pc = 0x184648u;
    // 0x184648: 0x2e0102d  daddu       $v0, $s7, $zero
    ctx->pc = 0x184648u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18464c: 0x10000069  b           . + 4 + (0x69 << 2)
    ctx->pc = 0x18464Cu;
    {
        const bool branch_taken_0x18464c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x184650u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18464Cu;
            // 0x184650: 0x83100b  movn        $v0, $a0, $v1 (Delay Slot)
        if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18464c) {
            ctx->pc = 0x1847F4u;
            goto label_1847f4;
        }
    }
    ctx->pc = 0x184654u;
    // 0x184654: 0x0  nop
    ctx->pc = 0x184654u;
    // NOP
label_184658:
    // 0x184658: 0x14800037  bnez        $a0, . + 4 + (0x37 << 2)
    ctx->pc = 0x184658u;
    {
        const bool branch_taken_0x184658 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        if (branch_taken_0x184658) {
            ctx->pc = 0x184738u;
            goto label_184738;
        }
    }
    ctx->pc = 0x184660u;
    // 0x184660: 0x13c00028  beqz        $fp, . + 4 + (0x28 << 2)
    ctx->pc = 0x184660u;
    {
        const bool branch_taken_0x184660 = (GPR_U64(ctx, 30) == GPR_U64(ctx, 0));
        ctx->pc = 0x184664u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184660u;
            // 0x184664: 0x3c0302d  daddu       $a2, $fp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x184660) {
            ctx->pc = 0x184704u;
            goto label_184704;
        }
    }
    ctx->pc = 0x184668u;
    // 0x184668: 0x30c20007  andi        $v0, $a2, 0x7
    ctx->pc = 0x184668u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)7);
    // 0x18466c: 0x10400018  beqz        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x18466Cu;
    {
        const bool branch_taken_0x18466c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x184670u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18466Cu;
            // 0x184670: 0x3a0182d  daddu       $v1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18466c) {
            ctx->pc = 0x1846D0u;
            goto label_1846d0;
        }
    }
    ctx->pc = 0x184674u;
label_184674:
    // 0x184674: 0x68620007  ldl         $v0, 0x7($v1)
    ctx->pc = 0x184674u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x184678: 0x6c620000  ldr         $v0, 0x0($v1)
    ctx->pc = 0x184678u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x18467c: 0x6864000f  ldl         $a0, 0xF($v1)
    ctx->pc = 0x18467cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x184680: 0x6c640008  ldr         $a0, 0x8($v1)
    ctx->pc = 0x184680u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x184684: 0x68650017  ldl         $a1, 0x17($v1)
    ctx->pc = 0x184684u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x184688: 0x6c650010  ldr         $a1, 0x10($v1)
    ctx->pc = 0x184688u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x18468c: 0x6867001f  ldl         $a3, 0x1F($v1)
    ctx->pc = 0x18468cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem << shift)); }
    // 0x184690: 0x6c670018  ldr         $a3, 0x18($v1)
    ctx->pc = 0x184690u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & keepMask) | (mem >> shift)); }
    // 0x184694: 0xb0c20007  sdl         $v0, 0x7($a2)
    ctx->pc = 0x184694u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x184698: 0xb4c20000  sdr         $v0, 0x0($a2)
    ctx->pc = 0x184698u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x18469c: 0xb0c4000f  sdl         $a0, 0xF($a2)
    ctx->pc = 0x18469cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1846a0: 0xb4c40008  sdr         $a0, 0x8($a2)
    ctx->pc = 0x1846a0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1846a4: 0xb0c50017  sdl         $a1, 0x17($a2)
    ctx->pc = 0x1846a4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1846a8: 0xb4c50010  sdr         $a1, 0x10($a2)
    ctx->pc = 0x1846a8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1846ac: 0xb0c7001f  sdl         $a3, 0x1F($a2)
    ctx->pc = 0x1846acu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1846b0: 0xb4c70018  sdr         $a3, 0x18($a2)
    ctx->pc = 0x1846b0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 7); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1846b4: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x1846b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x1846b8: 0x0  nop
    ctx->pc = 0x1846b8u;
    // NOP
    // 0x1846bc: 0x0  nop
    ctx->pc = 0x1846bcu;
    // NOP
    // 0x1846c0: 0x1472ffec  bne         $v1, $s2, . + 4 + (-0x14 << 2)
    ctx->pc = 0x1846C0u;
    {
        const bool branch_taken_0x1846c0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 18));
        ctx->pc = 0x1846C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1846C0u;
            // 0x1846c4: 0x24c60020  addiu       $a2, $a2, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1846c0) {
            ctx->pc = 0x184674u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_184674;
        }
    }
    ctx->pc = 0x1846C8u;
    // 0x1846c8: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1846C8u;
    {
        const bool branch_taken_0x1846c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1846CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1846C8u;
            // 0x1846cc: 0x8fa604a8  lw          $a2, 0x4A8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 1192)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1846c8) {
            ctx->pc = 0x184708u;
            goto label_184708;
        }
    }
    ctx->pc = 0x1846D0u;
label_1846d0:
    // 0x1846d0: 0xdc680000  ld          $t0, 0x0($v1)
    ctx->pc = 0x1846d0u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1846d4: 0xdc620008  ld          $v0, 0x8($v1)
    ctx->pc = 0x1846d4u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x1846d8: 0xdc640010  ld          $a0, 0x10($v1)
    ctx->pc = 0x1846d8u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x1846dc: 0xdc650018  ld          $a1, 0x18($v1)
    ctx->pc = 0x1846dcu;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x1846e0: 0xfcc80000  sd          $t0, 0x0($a2)
    ctx->pc = 0x1846e0u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 0), GPR_U64(ctx, 8));
    // 0x1846e4: 0xfcc20008  sd          $v0, 0x8($a2)
    ctx->pc = 0x1846e4u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 8), GPR_U64(ctx, 2));
    // 0x1846e8: 0xfcc40010  sd          $a0, 0x10($a2)
    ctx->pc = 0x1846e8u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 16), GPR_U64(ctx, 4));
    // 0x1846ec: 0xfcc50018  sd          $a1, 0x18($a2)
    ctx->pc = 0x1846ecu;
    WRITE64(ADD32(GPR_U32(ctx, 6), 24), GPR_U64(ctx, 5));
    // 0x1846f0: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x1846f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x1846f4: 0x0  nop
    ctx->pc = 0x1846f4u;
    // NOP
    // 0x1846f8: 0x0  nop
    ctx->pc = 0x1846f8u;
    // NOP
    // 0x1846fc: 0x1472fff4  bne         $v1, $s2, . + 4 + (-0xC << 2)
    ctx->pc = 0x1846FCu;
    {
        const bool branch_taken_0x1846fc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 18));
        ctx->pc = 0x184700u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1846FCu;
            // 0x184700: 0x24c60020  addiu       $a2, $a2, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1846fc) {
            ctx->pc = 0x1846D0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1846d0;
        }
    }
    ctx->pc = 0x184704u;
label_184704:
    // 0x184704: 0x8fa604a8  lw          $a2, 0x4A8($sp)
    ctx->pc = 0x184704u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 1192)));
label_184708:
    // 0x184708: 0x10c00002  beqz        $a2, . + 4 + (0x2 << 2)
    ctx->pc = 0x184708u;
    {
        const bool branch_taken_0x184708 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x18470Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184708u;
            // 0x18470c: 0x8fa204a0  lw          $v0, 0x4A0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 1184)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x184708) {
            ctx->pc = 0x184714u;
            goto label_184714;
        }
    }
    ctx->pc = 0x184710u;
    // 0x184710: 0xacc20000  sw          $v0, 0x0($a2)
    ctx->pc = 0x184710u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
label_184714:
    // 0x184714: 0x8fa704a4  lw          $a3, 0x4A4($sp)
    ctx->pc = 0x184714u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 1188)));
    // 0x184718: 0x10e00003  beqz        $a3, . + 4 + (0x3 << 2)
    ctx->pc = 0x184718u;
    {
        const bool branch_taken_0x184718 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        if (branch_taken_0x184718) {
            ctx->pc = 0x184728u;
            goto label_184728;
        }
    }
    ctx->pc = 0x184720u;
    // 0x184720: 0x8fa20210  lw          $v0, 0x210($sp)
    ctx->pc = 0x184720u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 528)));
    // 0x184724: 0xace20000  sw          $v0, 0x0($a3)
    ctx->pc = 0x184724u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 2));
label_184728:
    // 0x184728: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x184728u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x18472c: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x18472Cu;
    {
        const bool branch_taken_0x18472c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x184730u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18472Cu;
            // 0x184730: 0x34420011  ori         $v0, $v0, 0x11 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)17);
        ctx->in_delay_slot = false;
        if (branch_taken_0x18472c) {
            ctx->pc = 0x1847F4u;
            goto label_1847f4;
        }
    }
    ctx->pc = 0x184734u;
    // 0x184734: 0x0  nop
    ctx->pc = 0x184734u;
    // NOP
label_184738:
    // 0x184738: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x184738u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x18473c: 0x34420002  ori         $v0, $v0, 0x2
    ctx->pc = 0x18473cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)2);
    // 0x184740: 0x1482002c  bne         $a0, $v0, . + 4 + (0x2C << 2)
    ctx->pc = 0x184740u;
    {
        const bool branch_taken_0x184740 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        ctx->pc = 0x184744u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184740u;
            // 0x184744: 0x80102d  daddu       $v0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x184740) {
            ctx->pc = 0x1847F4u;
            goto label_1847f4;
        }
    }
    ctx->pc = 0x184748u;
    // 0x184748: 0x3c0302d  daddu       $a2, $fp, $zero
    ctx->pc = 0x184748u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18474c: 0x30c20007  andi        $v0, $a2, 0x7
    ctx->pc = 0x18474cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)7);
    // 0x184750: 0x10400019  beqz        $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x184750u;
    {
        const bool branch_taken_0x184750 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x184754u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x184750u;
            // 0x184754: 0x240182d  daddu       $v1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x184750) {
            ctx->pc = 0x1847B8u;
            goto label_1847b8;
        }
    }
    ctx->pc = 0x184758u;
label_184758:
    // 0x184758: 0x68680007  ldl         $t0, 0x7($v1)
    ctx->pc = 0x184758u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem << shift)); }
    // 0x18475c: 0x6c680000  ldr         $t0, 0x0($v1)
    ctx->pc = 0x18475cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & keepMask) | (mem >> shift)); }
    // 0x184760: 0x6862000f  ldl         $v0, 0xF($v1)
    ctx->pc = 0x184760u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem << shift)); }
    // 0x184764: 0x6c620008  ldr         $v0, 0x8($v1)
    ctx->pc = 0x184764u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & keepMask) | (mem >> shift)); }
    // 0x184768: 0x68640017  ldl         $a0, 0x17($v1)
    ctx->pc = 0x184768u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem << shift)); }
    // 0x18476c: 0x6c640010  ldr         $a0, 0x10($v1)
    ctx->pc = 0x18476cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & keepMask) | (mem >> shift)); }
    // 0x184770: 0x6865001f  ldl         $a1, 0x1F($v1)
    ctx->pc = 0x184770u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = (7u - offset) << 3; uint64_t keepMask = (shift == 0) ? 0ull : ((1ull << shift) - 1ull); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem << shift)); }
    // 0x184774: 0x6c650018  ldr         $a1, 0x18($v1)
    ctx->pc = 0x184774u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint64_t mem = READ64(aligned_addr); uint32_t shift = offset << 3; uint64_t keepMask = (offset == 0) ? 0ull : (0xFFFFFFFFFFFFFFFFull << ((8u - offset) << 3)); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & keepMask) | (mem >> shift)); }
    // 0x184778: 0xb0c80007  sdl         $t0, 0x7($a2)
    ctx->pc = 0x184778u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 7); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x18477c: 0xb4c80000  sdr         $t0, 0x0($a2)
    ctx->pc = 0x18477cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 0); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 8); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x184780: 0xb0c2000f  sdl         $v0, 0xF($a2)
    ctx->pc = 0x184780u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 15); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x184784: 0xb4c20008  sdr         $v0, 0x8($a2)
    ctx->pc = 0x184784u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 8); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 2); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x184788: 0xb0c40017  sdl         $a0, 0x17($a2)
    ctx->pc = 0x184788u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 23); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x18478c: 0xb4c40010  sdr         $a0, 0x10($a2)
    ctx->pc = 0x18478cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 16); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 4); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x184790: 0xb0c5001f  sdl         $a1, 0x1F($a2)
    ctx->pc = 0x184790u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 31); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = (7u - offset) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull >> shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x184794: 0xb4c50018  sdr         $a1, 0x18($a2)
    ctx->pc = 0x184794u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 6), 24); uint32_t aligned_addr = addr & ~7u; uint32_t offset = addr & 7u; uint32_t shift = offset << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFull << shift; uint64_t old_data = READ64(aligned_addr); uint64_t val = GPR_U64(ctx, 5); uint64_t new_data = (old_data & ~mask) | ((val << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x184798: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x184798u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x18479c: 0x0  nop
    ctx->pc = 0x18479cu;
    // NOP
    // 0x1847a0: 0x0  nop
    ctx->pc = 0x1847a0u;
    // NOP
    // 0x1847a4: 0x1473ffec  bne         $v1, $s3, . + 4 + (-0x14 << 2)
    ctx->pc = 0x1847A4u;
    {
        const bool branch_taken_0x1847a4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 19));
        ctx->pc = 0x1847A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1847A4u;
            // 0x1847a8: 0x24c60020  addiu       $a2, $a2, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1847a4) {
            ctx->pc = 0x184758u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_184758;
        }
    }
    ctx->pc = 0x1847ACu;
    // 0x1847ac: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1847ACu;
    {
        const bool branch_taken_0x1847ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1847ac) {
            ctx->pc = 0x1847ECu;
            goto label_1847ec;
        }
    }
    ctx->pc = 0x1847B4u;
    // 0x1847b4: 0x0  nop
    ctx->pc = 0x1847b4u;
    // NOP
label_1847b8:
    // 0x1847b8: 0xdc670000  ld          $a3, 0x0($v1)
    ctx->pc = 0x1847b8u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1847bc: 0xdc680008  ld          $t0, 0x8($v1)
    ctx->pc = 0x1847bcu;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x1847c0: 0xdc620010  ld          $v0, 0x10($v1)
    ctx->pc = 0x1847c0u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x1847c4: 0xdc640018  ld          $a0, 0x18($v1)
    ctx->pc = 0x1847c4u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x1847c8: 0xfcc70000  sd          $a3, 0x0($a2)
    ctx->pc = 0x1847c8u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 0), GPR_U64(ctx, 7));
    // 0x1847cc: 0xfcc80008  sd          $t0, 0x8($a2)
    ctx->pc = 0x1847ccu;
    WRITE64(ADD32(GPR_U32(ctx, 6), 8), GPR_U64(ctx, 8));
    // 0x1847d0: 0xfcc20010  sd          $v0, 0x10($a2)
    ctx->pc = 0x1847d0u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 16), GPR_U64(ctx, 2));
    // 0x1847d4: 0xfcc40018  sd          $a0, 0x18($a2)
    ctx->pc = 0x1847d4u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 24), GPR_U64(ctx, 4));
    // 0x1847d8: 0x24630020  addiu       $v1, $v1, 0x20
    ctx->pc = 0x1847d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 32));
    // 0x1847dc: 0x0  nop
    ctx->pc = 0x1847dcu;
    // NOP
    // 0x1847e0: 0x0  nop
    ctx->pc = 0x1847e0u;
    // NOP
    // 0x1847e4: 0x1473fff4  bne         $v1, $s3, . + 4 + (-0xC << 2)
    ctx->pc = 0x1847E4u;
    {
        const bool branch_taken_0x1847e4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 19));
        ctx->pc = 0x1847E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1847E4u;
            // 0x1847e8: 0x24c60020  addiu       $a2, $a2, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1847e4) {
            ctx->pc = 0x1847B8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1847b8;
        }
    }
    ctx->pc = 0x1847ECu;
label_1847ec:
    // 0x1847ec: 0x3c028101  lui         $v0, 0x8101
    ctx->pc = 0x1847ecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33025 << 16));
    // 0x1847f0: 0x34420002  ori         $v0, $v0, 0x2
    ctx->pc = 0x1847f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)2);
label_1847f4:
    // 0x1847f4: 0xdfb004b0  ld          $s0, 0x4B0($sp)
    ctx->pc = 0x1847f4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 1200)));
label_1847f8:
    // 0x1847f8: 0xdfb104b8  ld          $s1, 0x4B8($sp)
    ctx->pc = 0x1847f8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 1208)));
    // 0x1847fc: 0xdfb204c0  ld          $s2, 0x4C0($sp)
    ctx->pc = 0x1847fcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 1216)));
    // 0x184800: 0xdfb304c8  ld          $s3, 0x4C8($sp)
    ctx->pc = 0x184800u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 1224)));
    // 0x184804: 0xdfb404d0  ld          $s4, 0x4D0($sp)
    ctx->pc = 0x184804u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 1232)));
    // 0x184808: 0xdfb504d8  ld          $s5, 0x4D8($sp)
    ctx->pc = 0x184808u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 1240)));
    // 0x18480c: 0xdfb604e0  ld          $s6, 0x4E0($sp)
    ctx->pc = 0x18480cu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 1248)));
    // 0x184810: 0xdfb704e8  ld          $s7, 0x4E8($sp)
    ctx->pc = 0x184810u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 1256)));
    // 0x184814: 0xdfbe04f0  ld          $fp, 0x4F0($sp)
    ctx->pc = 0x184814u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 1264)));
    // 0x184818: 0xdfbf04f8  ld          $ra, 0x4F8($sp)
    ctx->pc = 0x184818u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 1272)));
    // 0x18481c: 0x3e00008  jr          $ra
    ctx->pc = 0x18481Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x184820u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18481Cu;
            // 0x184820: 0x27bd0500  addiu       $sp, $sp, 0x500 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 1280));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1843C4u: goto label_1843c4;
            case 0x1843D8u: goto label_1843d8;
            case 0x184408u: goto label_184408;
            case 0x184418u: goto label_184418;
            case 0x184420u: goto label_184420;
            case 0x184430u: goto label_184430;
            case 0x184438u: goto label_184438;
            case 0x184450u: goto label_184450;
            case 0x184464u: goto label_184464;
            case 0x184478u: goto label_184478;
            case 0x184498u: goto label_184498;
            case 0x1844B0u: goto label_1844b0;
            case 0x1844C0u: goto label_1844c0;
            case 0x1844DCu: goto label_1844dc;
            case 0x184538u: goto label_184538;
            case 0x18453Cu: goto label_18453c;
            case 0x184578u: goto label_184578;
            case 0x184580u: goto label_184580;
            case 0x1845A0u: goto label_1845a0;
            case 0x1845ACu: goto label_1845ac;
            case 0x1845BCu: goto label_1845bc;
            case 0x1845D0u: goto label_1845d0;
            case 0x184620u: goto label_184620;
            case 0x184658u: goto label_184658;
            case 0x184674u: goto label_184674;
            case 0x1846D0u: goto label_1846d0;
            case 0x184704u: goto label_184704;
            case 0x184708u: goto label_184708;
            case 0x184714u: goto label_184714;
            case 0x184728u: goto label_184728;
            case 0x184738u: goto label_184738;
            case 0x184758u: goto label_184758;
            case 0x1847B8u: goto label_1847b8;
            case 0x1847ECu: goto label_1847ec;
            case 0x1847F4u: goto label_1847f4;
            case 0x1847F8u: goto label_1847f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x184824u;
    // 0x184824: 0x0  nop
    ctx->pc = 0x184824u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
