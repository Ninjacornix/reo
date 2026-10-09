#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00189420
// Address: 0x189420 - 0x189580
void sub_00189420_0x189420(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00189420_0x189420");
#endif

    switch (ctx->pc) {
        case 0x18946cu: goto label_18946c;
        case 0x189484u: goto label_189484;
        case 0x1894b0u: goto label_1894b0;
        case 0x1894e8u: goto label_1894e8;
        case 0x189528u: goto label_189528;
        case 0x18953cu: goto label_18953c;
        case 0x189544u: goto label_189544;
        case 0x189554u: goto label_189554;
        default: break;
    }

    ctx->pc = 0x189420u;

    // 0x189420: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x189420u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x189424: 0xffb40050  sd          $s4, 0x50($sp)
    ctx->pc = 0x189424u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 20));
    // 0x189428: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x189428u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x18942c: 0xe0a02d  daddu       $s4, $a3, $zero
    ctx->pc = 0x18942cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189430: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x189430u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x189434: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x189434u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189438: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x189438u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x18943c: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x18943cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x189440: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x189440u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189444: 0xffb50060  sd          $s5, 0x60($sp)
    ctx->pc = 0x189444u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 21));
    // 0x189448: 0xffb30040  sd          $s3, 0x40($sp)
    ctx->pc = 0x189448u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 19));
    // 0x18944c: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x18944cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x189450: 0x28621081  slti        $v0, $v1, 0x1081
    ctx->pc = 0x189450u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)4225) ? 1 : 0);
    // 0x189454: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x189454u;
    {
        const bool branch_taken_0x189454 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x189458u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189454u;
            // 0x189458: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189454) {
            ctx->pc = 0x189474u;
            goto label_189474;
        }
    }
    ctx->pc = 0x18945Cu;
    // 0x18945c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x18945cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x189460: 0x60282d  daddu       $a1, $v1, $zero
    ctx->pc = 0x189460u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189464: 0xc0625f6  jal         func_1897D8
    ctx->pc = 0x189464u;
    SET_GPR_U32(ctx, 31, 0x18946Cu);
    ctx->pc = 0x189468u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189464u;
            // 0x189468: 0x24841a28  addiu       $a0, $a0, 0x1A28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 6696));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1897D8u;
    if (runtime->hasFunction(0x1897D8u)) {
        auto targetFn = runtime->lookupFunction(0x1897D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18946Cu; }
        if (ctx->pc != 0x18946Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001897D8_0x1897d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18946Cu; }
        if (ctx->pc != 0x18946Cu) { return; }
    }
    ctx->pc = 0x18946Cu;
label_18946c:
    // 0x18946c: 0x1000003a  b           . + 4 + (0x3A << 2)
    ctx->pc = 0x18946Cu;
    {
        const bool branch_taken_0x18946c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x189470u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18946Cu;
            // 0x189470: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18946c) {
            ctx->pc = 0x189558u;
            goto label_189558;
        }
    }
    ctx->pc = 0x189474u;
label_189474:
    // 0x189474: 0x3c150029  lui         $s5, 0x29
    ctx->pc = 0x189474u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)41 << 16));
    // 0x189478: 0x3c130029  lui         $s3, 0x29
    ctx->pc = 0x189478u;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)41 << 16));
    // 0x18947c: 0xc045198  jal         func_114660
    ctx->pc = 0x18947Cu;
    SET_GPR_U32(ctx, 31, 0x189484u);
    ctx->pc = 0x189480u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18947Cu;
            // 0x189480: 0x8ea44140  lw          $a0, 0x4140($s5) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 16704)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189484u; }
        if (ctx->pc != 0x189484u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189484u; }
        if (ctx->pc != 0x189484u) { return; }
    }
    ctx->pc = 0x189484u;
label_189484:
    // 0x189484: 0xae720e80  sw          $s2, 0xE80($s3)
    ctx->pc = 0x189484u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 3712), GPR_U32(ctx, 18));
    // 0x189488: 0x26640e80  addiu       $a0, $s3, 0xE80
    ctx->pc = 0x189488u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 3712));
    // 0x18948c: 0xac910004  sw          $s1, 0x4($a0)
    ctx->pc = 0x18948cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 17));
    // 0x189490: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x189490u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x189494: 0xac820008  sw          $v0, 0x8($a0)
    ctx->pc = 0x189494u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 2));
    // 0x189498: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x189498u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x18949c: 0x1860000e  blez        $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x18949Cu;
    {
        const bool branch_taken_0x18949c = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x1894A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18949Cu;
            // 0x1894a0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18949c) {
            ctx->pc = 0x1894D8u;
            goto label_1894d8;
        }
    }
    ctx->pc = 0x1894A4u;
    // 0x1894a4: 0x2486000c  addiu       $a2, $a0, 0xC
    ctx->pc = 0x1894a4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), 12));
    // 0x1894a8: 0x3c070029  lui         $a3, 0x29
    ctx->pc = 0x1894a8u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)41 << 16));
    // 0x1894ac: 0x2851021  addu        $v0, $s4, $a1
    ctx->pc = 0x1894acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 5)));
label_1894b0:
    // 0x1894b0: 0xc52021  addu        $a0, $a2, $a1
    ctx->pc = 0x1894b0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x1894b4: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x1894b4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1894b8: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1894b8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1894bc: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x1894bcu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1894c0: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x1894c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1894c4: 0xa2102a  slt         $v0, $a1, $v0
    ctx->pc = 0x1894c4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1894c8: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1894C8u;
    {
        const bool branch_taken_0x1894c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1894CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1894C8u;
            // 0x1894cc: 0x2851021  addu        $v0, $s4, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1894c8) {
            ctx->pc = 0x1894B0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1894b0;
        }
    }
    ctx->pc = 0x1894D0u;
    // 0x1894d0: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1894D0u;
    {
        const bool branch_taken_0x1894d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1894D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1894D0u;
            // 0x1894d4: 0x24f00bb0  addiu       $s0, $a3, 0xBB0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 7), 2992));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1894d0) {
            ctx->pc = 0x1894E0u;
            goto label_1894e0;
        }
    }
    ctx->pc = 0x1894D8u;
label_1894d8:
    // 0x1894d8: 0x3c070029  lui         $a3, 0x29
    ctx->pc = 0x1894d8u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)41 << 16));
    // 0x1894dc: 0x24f00bb0  addiu       $s0, $a3, 0xBB0
    ctx->pc = 0x1894dcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 7), 2992));
label_1894e0:
    // 0x1894e0: 0xc045ef8  jal         func_117BE0
    ctx->pc = 0x1894E0u;
    SET_GPR_U32(ctx, 31, 0x1894E8u);
    ctx->pc = 0x1894E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1894E0u;
            // 0x1894e4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117BE0u;
    if (runtime->hasFunction(0x117BE0u)) {
        auto targetFn = runtime->lookupFunction(0x117BE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1894E8u; }
        if (ctx->pc != 0x1894E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117BE0_0x117be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1894E8u; }
        if (ctx->pc != 0x1894E8u) { return; }
    }
    ctx->pc = 0x1894E8u;
label_1894e8:
    // 0x1894e8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1894e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1894ec: 0x14430004  bne         $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1894ECu;
    {
        const bool branch_taken_0x1894ec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x1894F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1894ECu;
            // 0x1894f0: 0x26670e80  addiu       $a3, $s3, 0xE80 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 19), 3712));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1894ec) {
            ctx->pc = 0x189500u;
            goto label_189500;
        }
    }
    ctx->pc = 0x1894F4u;
    // 0x1894f4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1894f4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1894f8: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1894F8u;
    {
        const bool branch_taken_0x1894f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1894FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1894F8u;
            // 0x1894fc: 0x24841a58  addiu       $a0, $a0, 0x1A58 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 6744));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1894f8) {
            ctx->pc = 0x189534u;
            goto label_189534;
        }
    }
    ctx->pc = 0x189500u;
label_189500:
    // 0x189500: 0x3c058000  lui         $a1, 0x8000
    ctx->pc = 0x189500u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x189504: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x189504u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189508: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x189508u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x18950c: 0x34a5131b  ori         $a1, $a1, 0x131B
    ctx->pc = 0x18950cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)4891);
    // 0x189510: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x189510u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x189514: 0x24081090  addiu       $t0, $zero, 0x1090
    ctx->pc = 0x189514u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4240));
    // 0x189518: 0xe0482d  daddu       $t1, $a3, $zero
    ctx->pc = 0x189518u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18951c: 0x240a1090  addiu       $t2, $zero, 0x1090
    ctx->pc = 0x18951cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4240));
    // 0x189520: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x189520u;
    SET_GPR_U32(ctx, 31, 0x189528u);
    ctx->pc = 0x189524u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189520u;
            // 0x189524: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189528u; }
        if (ctx->pc != 0x189528u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189528u; }
        if (ctx->pc != 0x189528u) { return; }
    }
    ctx->pc = 0x189528u;
label_189528:
    // 0x189528: 0x4410008  bgez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x189528u;
    {
        const bool branch_taken_0x189528 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x18952Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189528u;
            // 0x18952c: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189528) {
            ctx->pc = 0x18954Cu;
            goto label_18954c;
        }
    }
    ctx->pc = 0x189530u;
    // 0x189530: 0x24841a78  addiu       $a0, $a0, 0x1A78
    ctx->pc = 0x189530u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 6776));
label_189534:
    // 0x189534: 0xc0625f6  jal         func_1897D8
    ctx->pc = 0x189534u;
    SET_GPR_U32(ctx, 31, 0x18953Cu);
    ctx->pc = 0x1897D8u;
    if (runtime->hasFunction(0x1897D8u)) {
        auto targetFn = runtime->lookupFunction(0x1897D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18953Cu; }
        if (ctx->pc != 0x18953Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001897D8_0x1897d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18953Cu; }
        if (ctx->pc != 0x18953Cu) { return; }
    }
    ctx->pc = 0x18953Cu;
label_18953c:
    // 0x18953c: 0xc045190  jal         func_114640
    ctx->pc = 0x18953Cu;
    SET_GPR_U32(ctx, 31, 0x189544u);
    ctx->pc = 0x189540u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18953Cu;
            // 0x189540: 0x8ea44140  lw          $a0, 0x4140($s5) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 16704)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189544u; }
        if (ctx->pc != 0x189544u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189544u; }
        if (ctx->pc != 0x189544u) { return; }
    }
    ctx->pc = 0x189544u;
label_189544:
    // 0x189544: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x189544u;
    {
        const bool branch_taken_0x189544 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x189548u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189544u;
            // 0x189548: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189544) {
            ctx->pc = 0x189558u;
            goto label_189558;
        }
    }
    ctx->pc = 0x18954Cu;
label_18954c:
    // 0x18954c: 0xc045190  jal         func_114640
    ctx->pc = 0x18954Cu;
    SET_GPR_U32(ctx, 31, 0x189554u);
    ctx->pc = 0x189550u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18954Cu;
            // 0x189550: 0x8ea44140  lw          $a0, 0x4140($s5) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 16704)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189554u; }
        if (ctx->pc != 0x189554u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189554u; }
        if (ctx->pc != 0x189554u) { return; }
    }
    ctx->pc = 0x189554u;
label_189554:
    // 0x189554: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x189554u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_189558:
    // 0x189558: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x189558u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x18955c: 0xdfb50060  ld          $s5, 0x60($sp)
    ctx->pc = 0x18955cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x189560: 0xdfb40050  ld          $s4, 0x50($sp)
    ctx->pc = 0x189560u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x189564: 0xdfb30040  ld          $s3, 0x40($sp)
    ctx->pc = 0x189564u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x189568: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x189568u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x18956c: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x18956cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x189570: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x189570u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x189574: 0x3e00008  jr          $ra
    ctx->pc = 0x189574u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x189578u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189574u;
            // 0x189578: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18946Cu: goto label_18946c;
            case 0x189474u: goto label_189474;
            case 0x189484u: goto label_189484;
            case 0x1894B0u: goto label_1894b0;
            case 0x1894D8u: goto label_1894d8;
            case 0x1894E0u: goto label_1894e0;
            case 0x1894E8u: goto label_1894e8;
            case 0x189500u: goto label_189500;
            case 0x189528u: goto label_189528;
            case 0x189534u: goto label_189534;
            case 0x18953Cu: goto label_18953c;
            case 0x189544u: goto label_189544;
            case 0x18954Cu: goto label_18954c;
            case 0x189554u: goto label_189554;
            case 0x189558u: goto label_189558;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18957Cu;
    // 0x18957c: 0x0  nop
    ctx->pc = 0x18957cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
