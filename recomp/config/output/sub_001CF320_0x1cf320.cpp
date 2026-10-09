#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CF320
// Address: 0x1cf320 - 0x1cf560
void sub_001CF320_0x1cf320(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CF320_0x1cf320");
#endif

    switch (ctx->pc) {
        case 0x1cf388u: goto label_1cf388;
        case 0x1cf3acu: goto label_1cf3ac;
        case 0x1cf3f0u: goto label_1cf3f0;
        case 0x1cf408u: goto label_1cf408;
        case 0x1cf434u: goto label_1cf434;
        case 0x1cf460u: goto label_1cf460;
        case 0x1cf478u: goto label_1cf478;
        case 0x1cf48cu: goto label_1cf48c;
        case 0x1cf4a8u: goto label_1cf4a8;
        case 0x1cf4bcu: goto label_1cf4bc;
        case 0x1cf4c4u: goto label_1cf4c4;
        case 0x1cf4d4u: goto label_1cf4d4;
        case 0x1cf4ecu: goto label_1cf4ec;
        case 0x1cf4fcu: goto label_1cf4fc;
        case 0x1cf518u: goto label_1cf518;
        case 0x1cf530u: goto label_1cf530;
        default: break;
    }

    ctx->pc = 0x1cf320u;

    // 0x1cf320: 0x27bdfe60  addiu       $sp, $sp, -0x1A0
    ctx->pc = 0x1cf320u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966880));
    // 0x1cf324: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cf324u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cf328: 0xffbf0090  sd          $ra, 0x90($sp)
    ctx->pc = 0x1cf328u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 31));
    // 0x1cf32c: 0x31020080  andi        $v0, $t0, 0x80
    ctx->pc = 0x1cf32cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 8) & (uint64_t)(uint16_t)128);
    // 0x1cf330: 0x7fbe0080  sq          $fp, 0x80($sp)
    ctx->pc = 0x1cf330u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 128), GPR_VEC(ctx, 30));
    // 0x1cf334: 0x7fb70070  sq          $s7, 0x70($sp)
    ctx->pc = 0x1cf334u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 112), GPR_VEC(ctx, 23));
    // 0x1cf338: 0x120f02d  daddu       $fp, $t1, $zero
    ctx->pc = 0x1cf338u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf33c: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x1cf33cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x1cf340: 0xe0b82d  daddu       $s7, $a3, $zero
    ctx->pc = 0x1cf340u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf344: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1cf344u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1cf348: 0xc0b02d  daddu       $s6, $a2, $zero
    ctx->pc = 0x1cf348u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf34c: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1cf34cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1cf350: 0x160a82d  daddu       $s5, $t3, $zero
    ctx->pc = 0x1cf350u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf354: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1cf354u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1cf358: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1cf358u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1cf35c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1cf35cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1cf360: 0x100982d  daddu       $s3, $t0, $zero
    ctx->pc = 0x1cf360u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf364: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1cf364u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1cf368: 0x2902b  sltu        $s2, $zero, $v0
    ctx->pc = 0x1cf368u;
    SET_GPR_U64(ctx, 18, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1cf36c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1cf36cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cf370: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1cf370u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf374: 0x8c3166c8  lw          $s1, 0x66C8($at)
    ctx->pc = 0x1cf374u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 26312)));
    // 0x1cf378: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1cf378u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf37c: 0x3085ffff  andi        $a1, $a0, 0xFFFF
    ctx->pc = 0x1cf37cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
    // 0x1cf380: 0xc0735c4  jal         func_1CD710
    ctx->pc = 0x1CF380u;
    SET_GPR_U32(ctx, 31, 0x1CF388u);
    ctx->pc = 0x1CF384u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF380u;
            // 0x1cf384: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD710u;
    if (runtime->hasFunction(0x1CD710u)) {
        auto targetFn = runtime->lookupFunction(0x1CD710u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF388u; }
        if (ctx->pc != 0x1CF388u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD710_0x1cd710(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF388u; }
        if (ctx->pc != 0x1CF388u) { return; }
    }
    ctx->pc = 0x1CF388u;
label_1cf388:
    // 0x1cf388: 0x40a02d  daddu       $s4, $v0, $zero
    ctx->pc = 0x1cf388u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf38c: 0x12800068  beqz        $s4, . + 4 + (0x68 << 2)
    ctx->pc = 0x1CF38Cu;
    {
        const bool branch_taken_0x1cf38c = (GPR_U64(ctx, 20) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CF390u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF38Cu;
            // 0x1cf390: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf38c) {
            ctx->pc = 0x1CF530u;
            goto label_1cf530;
        }
    }
    ctx->pc = 0x1CF394u;
    // 0x1cf394: 0x802343d7  lb          $v1, 0x43D7($at)
    ctx->pc = 0x1cf394u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1cf398: 0x10600028  beqz        $v1, . + 4 + (0x28 << 2)
    ctx->pc = 0x1CF398u;
    {
        const bool branch_taken_0x1cf398 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CF39Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF398u;
            // 0x1cf39c: 0x3263007f  andi        $v1, $s3, 0x7F (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)127);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf398) {
            ctx->pc = 0x1CF43Cu;
            goto label_1cf43c;
        }
    }
    ctx->pc = 0x1CF3A0u;
    // 0x1cf3a0: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1cf3a0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf3a4: 0xc042dee  jal         func_10B7B8
    ctx->pc = 0x1CF3A4u;
    SET_GPR_U32(ctx, 31, 0x1CF3ACu);
    ctx->pc = 0x1CF3A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF3A4u;
            // 0x1cf3a8: 0x2405005c  addiu       $a1, $zero, 0x5C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 92));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B7B8u;
    if (runtime->hasFunction(0x10B7B8u)) {
        auto targetFn = runtime->lookupFunction(0x10B7B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF3ACu; }
        if (ctx->pc != 0x1CF3ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B7B8_0x10b7b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF3ACu; }
        if (ctx->pc != 0x1CF3ACu) { return; }
    }
    ctx->pc = 0x1CF3ACu;
label_1cf3ac:
    // 0x1cf3ac: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1CF3ACu;
    {
        const bool branch_taken_0x1cf3ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cf3ac) {
            ctx->pc = 0x1CF3B8u;
            goto label_1cf3b8;
        }
    }
    ctx->pc = 0x1CF3B4u;
    // 0x1cf3b4: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1cf3b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_1cf3b8:
    // 0x1cf3b8: 0x80440000  lb          $a0, 0x0($v0)
    ctx->pc = 0x1cf3b8u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1cf3bc: 0x24030048  addiu       $v1, $zero, 0x48
    ctx->pc = 0x1cf3bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 72));
    // 0x1cf3c0: 0x14830002  bne         $a0, $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1CF3C0u;
    {
        const bool branch_taken_0x1cf3c0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        ctx->pc = 0x1CF3C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF3C0u;
            // 0x1cf3c4: 0x40182d  daddu       $v1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf3c0) {
            ctx->pc = 0x1CF3CCu;
            goto label_1cf3cc;
        }
    }
    ctx->pc = 0x1CF3C8u;
    // 0x1cf3c8: 0x24430001  addiu       $v1, $v0, 0x1
    ctx->pc = 0x1cf3c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_1cf3cc:
    // 0x1cf3cc: 0x80640000  lb          $a0, 0x0($v1)
    ctx->pc = 0x1cf3ccu;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1cf3d0: 0x24030045  addiu       $v1, $zero, 0x45
    ctx->pc = 0x1cf3d0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 69));
    // 0x1cf3d4: 0x14830008  bne         $a0, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1CF3D4u;
    {
        const bool branch_taken_0x1cf3d4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        ctx->pc = 0x1CF3D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF3D4u;
            // 0x1cf3d8: 0x3c050025  lui         $a1, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf3d4) {
            ctx->pc = 0x1CF3F8u;
            goto label_1cf3f8;
        }
    }
    ctx->pc = 0x1CF3DCu;
    // 0x1cf3dc: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1cf3dcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1cf3e0: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1cf3e0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf3e4: 0x27a400a0  addiu       $a0, $sp, 0xA0
    ctx->pc = 0x1cf3e4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
    // 0x1cf3e8: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1CF3E8u;
    SET_GPR_U32(ctx, 31, 0x1CF3F0u);
    ctx->pc = 0x1CF3ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF3E8u;
            // 0x1cf3ec: 0x24a56168  addiu       $a1, $a1, 0x6168 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 24936));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF3F0u; }
        if (ctx->pc != 0x1CF3F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF3F0u; }
        if (ctx->pc != 0x1CF3F0u) { return; }
    }
    ctx->pc = 0x1CF3F0u;
label_1cf3f0:
    // 0x1cf3f0: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1CF3F0u;
    {
        const bool branch_taken_0x1cf3f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CF3F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF3F0u;
            // 0x1cf3f4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf3f0) {
            ctx->pc = 0x1CF40Cu;
            goto label_1cf40c;
        }
    }
    ctx->pc = 0x1CF3F8u;
label_1cf3f8:
    // 0x1cf3f8: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1cf3f8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf3fc: 0x27a400a0  addiu       $a0, $sp, 0xA0
    ctx->pc = 0x1cf3fcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
    // 0x1cf400: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1CF400u;
    SET_GPR_U32(ctx, 31, 0x1CF408u);
    ctx->pc = 0x1CF404u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF400u;
            // 0x1cf404: 0x24a56170  addiu       $a1, $a1, 0x6170 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 24944));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF408u; }
        if (ctx->pc != 0x1CF408u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF408u; }
        if (ctx->pc != 0x1CF408u) { return; }
    }
    ctx->pc = 0x1CF408u;
label_1cf408:
    // 0x1cf408: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1cf408u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1cf40c:
    // 0x1cf40c: 0x12420002  beq         $s2, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1CF40Cu;
    {
        const bool branch_taken_0x1cf40c = (GPR_U64(ctx, 18) == GPR_U64(ctx, 2));
        ctx->pc = 0x1CF410u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF40Cu;
            // 0x1cf410: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf40c) {
            ctx->pc = 0x1CF418u;
            goto label_1cf418;
        }
    }
    ctx->pc = 0x1CF414u;
    // 0x1cf414: 0xa21e081c  sb          $fp, 0x81C($s0)
    ctx->pc = 0x1cf414u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2076), (uint8_t)GPR_U32(ctx, 30));
label_1cf418:
    // 0x1cf418: 0x2c0302d  daddu       $a2, $s6, $zero
    ctx->pc = 0x1cf418u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf41c: 0x220382d  daddu       $a3, $s1, $zero
    ctx->pc = 0x1cf41cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf420: 0x2e0402d  daddu       $t0, $s7, $zero
    ctx->pc = 0x1cf420u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf424: 0x260482d  daddu       $t1, $s3, $zero
    ctx->pc = 0x1cf424u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf428: 0x2a0502d  daddu       $t2, $s5, $zero
    ctx->pc = 0x1cf428u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf42c: 0xc06aba0  jal         func_1AAE80
    ctx->pc = 0x1CF42Cu;
    SET_GPR_U32(ctx, 31, 0x1CF434u);
    ctx->pc = 0x1CF430u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF42Cu;
            // 0x1cf430: 0x27a400a0  addiu       $a0, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AAE80u;
    if (runtime->hasFunction(0x1AAE80u)) {
        auto targetFn = runtime->lookupFunction(0x1AAE80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF434u; }
        if (ctx->pc != 0x1CF434u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AAE80_0x1aae80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF434u; }
        if (ctx->pc != 0x1CF434u) { return; }
    }
    ctx->pc = 0x1CF434u;
label_1cf434:
    // 0x1cf434: 0x1000003f  b           . + 4 + (0x3F << 2)
    ctx->pc = 0x1CF434u;
    {
        const bool branch_taken_0x1cf434 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CF438u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF434u;
            // 0x1cf438: 0xdfbf0090  ld          $ra, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf434) {
            ctx->pc = 0x1CF534u;
            goto label_1cf534;
        }
    }
    ctx->pc = 0x1CF43Cu;
label_1cf43c:
    // 0x1cf43c: 0x28610002  slti        $at, $v1, 0x2
    ctx->pc = 0x1cf43cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1cf440: 0x10200005  beqz        $at, . + 4 + (0x5 << 2)
    ctx->pc = 0x1CF440u;
    {
        const bool branch_taken_0x1cf440 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CF444u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF440u;
            // 0x1cf444: 0x27a400a0  addiu       $a0, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf440) {
            ctx->pc = 0x1CF458u;
            goto label_1cf458;
        }
    }
    ctx->pc = 0x1CF448u;
    // 0x1cf448: 0x16a00022  bnez        $s5, . + 4 + (0x22 << 2)
    ctx->pc = 0x1CF448u;
    {
        const bool branch_taken_0x1cf448 = (GPR_U64(ctx, 21) != GPR_U64(ctx, 0));
        if (branch_taken_0x1cf448) {
            ctx->pc = 0x1CF4D4u;
            goto label_1cf4d4;
        }
    }
    ctx->pc = 0x1CF450u;
    // 0x1cf450: 0x10000037  b           . + 4 + (0x37 << 2)
    ctx->pc = 0x1CF450u;
    {
        const bool branch_taken_0x1cf450 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cf450) {
            ctx->pc = 0x1CF530u;
            goto label_1cf530;
        }
    }
    ctx->pc = 0x1CF458u;
label_1cf458:
    // 0x1cf458: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1CF458u;
    SET_GPR_U32(ctx, 31, 0x1CF460u);
    ctx->pc = 0x1CF45Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF458u;
            // 0x1cf45c: 0x280282d  daddu       $a1, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF460u; }
        if (ctx->pc != 0x1CF460u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF460u; }
        if (ctx->pc != 0x1CF460u) { return; }
    }
    ctx->pc = 0x1CF460u;
label_1cf460:
    // 0x1cf460: 0x16400007  bnez        $s2, . + 4 + (0x7 << 2)
    ctx->pc = 0x1CF460u;
    {
        const bool branch_taken_0x1cf460 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CF464u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF460u;
            // 0x1cf464: 0x3c050025  lui         $a1, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf460) {
            ctx->pc = 0x1CF480u;
            goto label_1cf480;
        }
    }
    ctx->pc = 0x1CF468u;
    // 0x1cf468: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1cf468u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1cf46c: 0x27a400a0  addiu       $a0, $sp, 0xA0
    ctx->pc = 0x1cf46cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
    // 0x1cf470: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x1CF470u;
    SET_GPR_U32(ctx, 31, 0x1CF478u);
    ctx->pc = 0x1CF474u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF470u;
            // 0x1cf474: 0x24a560c8  addiu       $a1, $a1, 0x60C8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 24776));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF478u; }
        if (ctx->pc != 0x1CF478u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF478u; }
        if (ctx->pc != 0x1CF478u) { return; }
    }
    ctx->pc = 0x1CF478u;
label_1cf478:
    // 0x1cf478: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1CF478u;
    {
        const bool branch_taken_0x1cf478 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cf478) {
            ctx->pc = 0x1CF48Cu;
            goto label_1cf48c;
        }
    }
    ctx->pc = 0x1CF480u;
label_1cf480:
    // 0x1cf480: 0x27a400a0  addiu       $a0, $sp, 0xA0
    ctx->pc = 0x1cf480u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
    // 0x1cf484: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x1CF484u;
    SET_GPR_U32(ctx, 31, 0x1CF48Cu);
    ctx->pc = 0x1CF488u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF484u;
            // 0x1cf488: 0x24a56178  addiu       $a1, $a1, 0x6178 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 24952));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF48Cu; }
        if (ctx->pc != 0x1CF48Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF48Cu; }
        if (ctx->pc != 0x1CF48Cu) { return; }
    }
    ctx->pc = 0x1CF48Cu;
label_1cf48c:
    // 0x1cf48c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cf48cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cf490: 0x27a400a0  addiu       $a0, $sp, 0xA0
    ctx->pc = 0x1cf490u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
    // 0x1cf494: 0x8c330ad8  lw          $s3, 0xAD8($at)
    ctx->pc = 0x1cf494u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2776)));
    // 0x1cf498: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1cf498u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1cf49c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1cf49cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf4a0: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1CF4A0u;
    SET_GPR_U32(ctx, 31, 0x1CF4A8u);
    ctx->pc = 0x1CF4A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF4A0u;
            // 0x1cf4a4: 0x260282d  daddu       $a1, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF4A8u; }
        if (ctx->pc != 0x1CF4A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF4A8u; }
        if (ctx->pc != 0x1CF4A8u) { return; }
    }
    ctx->pc = 0x1CF4A8u;
label_1cf4a8:
    // 0x1cf4a8: 0x1840000a  blez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1CF4A8u;
    {
        const bool branch_taken_0x1cf4a8 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1CF4ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF4A8u;
            // 0x1cf4ac: 0x2c0302d  daddu       $a2, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf4a8) {
            ctx->pc = 0x1CF4D4u;
            goto label_1cf4d4;
        }
    }
    ctx->pc = 0x1CF4B0u;
    // 0x1cf4b0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1cf4b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf4b4: 0xc07496c  jal         func_1D25B0
    ctx->pc = 0x1CF4B4u;
    SET_GPR_U32(ctx, 31, 0x1CF4BCu);
    ctx->pc = 0x1CF4B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF4B4u;
            // 0x1cf4b8: 0x260282d  daddu       $a1, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D25B0u;
    if (runtime->hasFunction(0x1D25B0u)) {
        auto targetFn = runtime->lookupFunction(0x1D25B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF4BCu; }
        if (ctx->pc != 0x1CF4BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D25B0_0x1d25b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF4BCu; }
        if (ctx->pc != 0x1CF4BCu) { return; }
    }
    ctx->pc = 0x1CF4BCu;
label_1cf4bc:
    // 0x1cf4bc: 0xc06cb34  jal         func_1B2CD0
    ctx->pc = 0x1CF4BCu;
    SET_GPR_U32(ctx, 31, 0x1CF4C4u);
    ctx->pc = 0x1CF4C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF4BCu;
            // 0x1cf4c0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2CD0u;
    if (runtime->hasFunction(0x1B2CD0u)) {
        auto targetFn = runtime->lookupFunction(0x1B2CD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF4C4u; }
        if (ctx->pc != 0x1CF4C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2CD0_0x1b2cd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF4C4u; }
        if (ctx->pc != 0x1CF4C4u) { return; }
    }
    ctx->pc = 0x1CF4C4u;
label_1cf4c4:
    // 0x1cf4c4: 0x32e600ff  andi        $a2, $s7, 0xFF
    ctx->pc = 0x1cf4c4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 23) & (uint64_t)(uint16_t)255);
    // 0x1cf4c8: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1cf4c8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf4cc: 0xc0749f4  jal         func_1D27D0
    ctx->pc = 0x1CF4CCu;
    SET_GPR_U32(ctx, 31, 0x1CF4D4u);
    ctx->pc = 0x1CF4D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF4CCu;
            // 0x1cf4d0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D27D0u;
    if (runtime->hasFunction(0x1D27D0u)) {
        auto targetFn = runtime->lookupFunction(0x1D27D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF4D4u; }
        if (ctx->pc != 0x1CF4D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D27D0_0x1d27d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF4D4u; }
        if (ctx->pc != 0x1CF4D4u) { return; }
    }
    ctx->pc = 0x1CF4D4u;
label_1cf4d4:
    // 0x1cf4d4: 0x12a00016  beqz        $s5, . + 4 + (0x16 << 2)
    ctx->pc = 0x1CF4D4u;
    {
        const bool branch_taken_0x1cf4d4 = (GPR_U64(ctx, 21) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CF4D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF4D4u;
            // 0x1cf4d8: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf4d4) {
            ctx->pc = 0x1CF530u;
            goto label_1cf530;
        }
    }
    ctx->pc = 0x1CF4DCu;
    // 0x1cf4dc: 0x12430014  beq         $s2, $v1, . + 4 + (0x14 << 2)
    ctx->pc = 0x1CF4DCu;
    {
        const bool branch_taken_0x1cf4dc = (GPR_U64(ctx, 18) == GPR_U64(ctx, 3));
        ctx->pc = 0x1CF4E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF4DCu;
            // 0x1cf4e0: 0x280282d  daddu       $a1, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf4dc) {
            ctx->pc = 0x1CF530u;
            goto label_1cf530;
        }
    }
    ctx->pc = 0x1CF4E4u;
    // 0x1cf4e4: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1CF4E4u;
    SET_GPR_U32(ctx, 31, 0x1CF4ECu);
    ctx->pc = 0x1CF4E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF4E4u;
            // 0x1cf4e8: 0x27a400a0  addiu       $a0, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF4ECu; }
        if (ctx->pc != 0x1CF4ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF4ECu; }
        if (ctx->pc != 0x1CF4ECu) { return; }
    }
    ctx->pc = 0x1CF4ECu;
label_1cf4ec:
    // 0x1cf4ec: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1cf4ecu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1cf4f0: 0x27a400a0  addiu       $a0, $sp, 0xA0
    ctx->pc = 0x1cf4f0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
    // 0x1cf4f4: 0xc042aee  jal         func_10ABB8
    ctx->pc = 0x1CF4F4u;
    SET_GPR_U32(ctx, 31, 0x1CF4FCu);
    ctx->pc = 0x1CF4F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF4F4u;
            // 0x1cf4f8: 0x24a560d0  addiu       $a1, $a1, 0x60D0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 24784));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10ABB8u;
    if (runtime->hasFunction(0x10ABB8u)) {
        auto targetFn = runtime->lookupFunction(0x10ABB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF4FCu; }
        if (ctx->pc != 0x1CF4FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF4FCu; }
        if (ctx->pc != 0x1CF4FCu) { return; }
    }
    ctx->pc = 0x1CF4FCu;
label_1cf4fc:
    // 0x1cf4fc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cf4fcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cf500: 0x27a400a0  addiu       $a0, $sp, 0xA0
    ctx->pc = 0x1cf500u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
    // 0x1cf504: 0x8c320ad8  lw          $s2, 0xAD8($at)
    ctx->pc = 0x1cf504u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2776)));
    // 0x1cf508: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1cf508u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1cf50c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1cf50cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf510: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1CF510u;
    SET_GPR_U32(ctx, 31, 0x1CF518u);
    ctx->pc = 0x1CF514u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF510u;
            // 0x1cf514: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF518u; }
        if (ctx->pc != 0x1CF518u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF518u; }
        if (ctx->pc != 0x1CF518u) { return; }
    }
    ctx->pc = 0x1CF518u;
label_1cf518:
    // 0x1cf518: 0x18400005  blez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1CF518u;
    {
        const bool branch_taken_0x1cf518 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1CF51Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF518u;
            // 0x1cf51c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf518) {
            ctx->pc = 0x1CF530u;
            goto label_1cf530;
        }
    }
    ctx->pc = 0x1CF520u;
    // 0x1cf520: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1cf520u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf524: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x1cf524u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf528: 0xc0737f8  jal         func_1CDFE0
    ctx->pc = 0x1CF528u;
    SET_GPR_U32(ctx, 31, 0x1CF530u);
    ctx->pc = 0x1CF52Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF528u;
            // 0x1cf52c: 0xa21e081c  sb          $fp, 0x81C($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 2076), (uint8_t)GPR_U32(ctx, 30));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CDFE0u;
    if (runtime->hasFunction(0x1CDFE0u)) {
        auto targetFn = runtime->lookupFunction(0x1CDFE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF530u; }
        if (ctx->pc != 0x1CF530u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CDFE0_0x1cdfe0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF530u; }
        if (ctx->pc != 0x1CF530u) { return; }
    }
    ctx->pc = 0x1CF530u;
label_1cf530:
    // 0x1cf530: 0xdfbf0090  ld          $ra, 0x90($sp)
    ctx->pc = 0x1cf530u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
label_1cf534:
    // 0x1cf534: 0x7bbe0080  lq          $fp, 0x80($sp)
    ctx->pc = 0x1cf534u;
    SET_GPR_VEC(ctx, 30, READ128(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x1cf538: 0x7bb70070  lq          $s7, 0x70($sp)
    ctx->pc = 0x1cf538u;
    SET_GPR_VEC(ctx, 23, READ128(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1cf53c: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x1cf53cu;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1cf540: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1cf540u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1cf544: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1cf544u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1cf548: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1cf548u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1cf54c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1cf54cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1cf550: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1cf550u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1cf554: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cf554u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cf558: 0x3e00008  jr          $ra
    ctx->pc = 0x1CF558u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CF55Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF558u;
            // 0x1cf55c: 0x27bd01a0  addiu       $sp, $sp, 0x1A0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 416));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CF388u: goto label_1cf388;
            case 0x1CF3ACu: goto label_1cf3ac;
            case 0x1CF3B8u: goto label_1cf3b8;
            case 0x1CF3CCu: goto label_1cf3cc;
            case 0x1CF3F0u: goto label_1cf3f0;
            case 0x1CF3F8u: goto label_1cf3f8;
            case 0x1CF408u: goto label_1cf408;
            case 0x1CF40Cu: goto label_1cf40c;
            case 0x1CF418u: goto label_1cf418;
            case 0x1CF434u: goto label_1cf434;
            case 0x1CF43Cu: goto label_1cf43c;
            case 0x1CF458u: goto label_1cf458;
            case 0x1CF460u: goto label_1cf460;
            case 0x1CF478u: goto label_1cf478;
            case 0x1CF480u: goto label_1cf480;
            case 0x1CF48Cu: goto label_1cf48c;
            case 0x1CF4A8u: goto label_1cf4a8;
            case 0x1CF4BCu: goto label_1cf4bc;
            case 0x1CF4C4u: goto label_1cf4c4;
            case 0x1CF4D4u: goto label_1cf4d4;
            case 0x1CF4ECu: goto label_1cf4ec;
            case 0x1CF4FCu: goto label_1cf4fc;
            case 0x1CF518u: goto label_1cf518;
            case 0x1CF530u: goto label_1cf530;
            case 0x1CF534u: goto label_1cf534;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CF560u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
