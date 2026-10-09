#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00100338
// Address: 0x100338 - 0x100408
void sub_00100338_0x100338(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00100338_0x100338");
#endif

    switch (ctx->pc) {
        case 0x100388u: goto label_100388;
        case 0x100390u: goto label_100390;
        case 0x1003b8u: goto label_1003b8;
        case 0x1003d0u: goto label_1003d0;
        case 0x1003f8u: goto label_1003f8;
        default: break;
    }

    ctx->pc = 0x100338u;

    // 0x100338: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x100338u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x10033c: 0xffbe0080  sd          $fp, 0x80($sp)
    ctx->pc = 0x10033cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 30));
    // 0x100340: 0xffb70070  sd          $s7, 0x70($sp)
    ctx->pc = 0x100340u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 23));
    // 0x100344: 0x3c1e0026  lui         $fp, 0x26
    ctx->pc = 0x100344u;
    SET_GPR_S32(ctx, 30, (int32_t)((uint32_t)38 << 16));
    // 0x100348: 0xffb60060  sd          $s6, 0x60($sp)
    ctx->pc = 0x100348u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 22));
    // 0x10034c: 0x3c170020  lui         $s7, 0x20
    ctx->pc = 0x10034cu;
    SET_GPR_S32(ctx, 23, (int32_t)((uint32_t)32 << 16));
    // 0x100350: 0xffb50050  sd          $s5, 0x50($sp)
    ctx->pc = 0x100350u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 21));
    // 0x100354: 0x3c160023  lui         $s6, 0x23
    ctx->pc = 0x100354u;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)35 << 16));
    // 0x100358: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x100358u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x10035c: 0x3c150026  lui         $s5, 0x26
    ctx->pc = 0x10035cu;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)38 << 16));
    // 0x100360: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x100360u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x100364: 0x3c140020  lui         $s4, 0x20
    ctx->pc = 0x100364u;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)32 << 16));
    // 0x100368: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x100368u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x10036c: 0x3c130020  lui         $s3, 0x20
    ctx->pc = 0x10036cu;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)32 << 16));
    // 0x100370: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x100370u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x100374: 0x3c120026  lui         $s2, 0x26
    ctx->pc = 0x100374u;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)38 << 16));
    // 0x100378: 0xffbf0090  sd          $ra, 0x90($sp)
    ctx->pc = 0x100378u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 31));
    // 0x10037c: 0x3c110020  lui         $s1, 0x20
    ctx->pc = 0x10037cu;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)32 << 16));
    // 0x100380: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x100380u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x100384: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x100384u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
label_100388:
    // 0x100388: 0xc045198  jal         func_114660
    ctx->pc = 0x100388u;
    SET_GPR_U32(ctx, 31, 0x100390u);
    ctx->pc = 0x10038Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x100388u;
            // 0x10038c: 0x8c447920  lw          $a0, 0x7920($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 31008)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100390u; }
        if (ctx->pc != 0x100390u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100390u; }
        if (ctx->pc != 0x100390u) { return; }
    }
    ctx->pc = 0x100390u;
label_100390:
    // 0x100390: 0x8e837958  lw          $v1, 0x7958($s4)
    ctx->pc = 0x100390u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 31064)));
    // 0x100394: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x100394u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x100398: 0x14620008  bne         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x100398u;
    {
        const bool branch_taken_0x100398 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x10039Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100398u;
            // 0x10039c: 0x8ee27910  lw          $v0, 0x7910($s7) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 23), 30992)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100398) {
            ctx->pc = 0x1003BCu;
            goto label_1003bc;
        }
    }
    ctx->pc = 0x1003A0u;
    // 0x1003a0: 0xae607934  sw          $zero, 0x7934($s3)
    ctx->pc = 0x1003a0u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 31028), GPR_U32(ctx, 0));
    // 0x1003a4: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x1003a4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x1003a8: 0xae807958  sw          $zero, 0x7958($s4)
    ctx->pc = 0x1003a8u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 31064), GPR_U32(ctx, 0));
    // 0x1003ac: 0x0  nop
    ctx->pc = 0x1003acu;
    // NOP
    // 0x1003b0: 0xc045118  jal         func_114460
    ctx->pc = 0x1003B0u;
    SET_GPR_U32(ctx, 31, 0x1003B8u);
    ctx->pc = 0x1003B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1003B0u;
            // 0x1003b4: 0xafc09f94  sw          $zero, -0x606C($fp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 30), 4294942612), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114460u;
    if (runtime->hasFunction(0x114460u)) {
        auto targetFn = runtime->lookupFunction(0x114460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1003B8u; }
        if (ctx->pc != 0x1003B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114460_0x114460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1003B8u; }
        if (ctx->pc != 0x1003B8u) { return; }
    }
    ctx->pc = 0x1003B8u;
label_1003b8:
    // 0x1003b8: 0x8ee27910  lw          $v0, 0x7910($s7)
    ctx->pc = 0x1003b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 23), 30992)));
label_1003bc:
    // 0x1003bc: 0x18400004  blez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1003BCu;
    {
        const bool branch_taken_0x1003bc = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1003C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1003BCu;
            // 0x1003c0: 0x26c47480  addiu       $a0, $s6, 0x7480 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), 29824));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1003bc) {
            ctx->pc = 0x1003D0u;
            goto label_1003d0;
        }
    }
    ctx->pc = 0x1003C4u;
    // 0x1003c4: 0x8e459f80  lw          $a1, -0x6080($s2)
    ctx->pc = 0x1003c4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4294942592)));
    // 0x1003c8: 0xc045a12  jal         func_116848
    ctx->pc = 0x1003C8u;
    SET_GPR_U32(ctx, 31, 0x1003D0u);
    ctx->pc = 0x1003CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1003C8u;
            // 0x1003cc: 0x8e26795c  lw          $a2, 0x795C($s1) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 31068)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1003D0u; }
        if (ctx->pc != 0x1003D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1003D0u; }
        if (ctx->pc != 0x1003D0u) { return; }
    }
    ctx->pc = 0x1003D0u;
label_1003d0:
    // 0x1003d0: 0x8e439f80  lw          $v1, -0x6080($s2)
    ctx->pc = 0x1003d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4294942592)));
    // 0x1003d4: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1003D4u;
    {
        const bool branch_taken_0x1003d4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1003d4) {
            ctx->pc = 0x1003FCu;
            goto label_1003fc;
        }
    }
    ctx->pc = 0x1003DCu;
    // 0x1003dc: 0x8e22795c  lw          $v0, 0x795C($s1)
    ctx->pc = 0x1003dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 31068)));
    // 0x1003e0: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1003E0u;
    {
        const bool branch_taken_0x1003e0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1003e0) {
            ctx->pc = 0x1003FCu;
            goto label_1003fc;
        }
    }
    ctx->pc = 0x1003E8u;
    // 0x1003e8: 0x380802d  daddu       $s0, $gp, $zero
    ctx->pc = 0x1003e8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 28) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1003ec: 0x8ebc9f84  lw          $gp, -0x607C($s5)
    ctx->pc = 0x1003ecu;
    SET_GPR_S32(ctx, 28, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 4294942596)));
    // 0x1003f0: 0x60f809  jalr        $v1
    ctx->pc = 0x1003F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x1003F8u);
        ctx->pc = 0x1003F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1003F0u;
            // 0x1003f4: 0x8e24795c  lw          $a0, 0x795C($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 31068)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1003F8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x100388u: goto label_100388;
            case 0x100390u: goto label_100390;
            case 0x1003B8u: goto label_1003b8;
            case 0x1003BCu: goto label_1003bc;
            case 0x1003D0u: goto label_1003d0;
            case 0x1003F8u: goto label_1003f8;
            case 0x1003FCu: goto label_1003fc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1003F8u; }
            if (ctx->pc != 0x1003F8u) { return; }
        }
        }
    }
    ctx->pc = 0x1003F8u;
label_1003f8:
    // 0x1003f8: 0x200e02d  daddu       $gp, $s0, $zero
    ctx->pc = 0x1003f8u;
    SET_GPR_U64(ctx, 28, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1003fc:
    // 0x1003fc: 0xae607934  sw          $zero, 0x7934($s3)
    ctx->pc = 0x1003fcu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 31028), GPR_U32(ctx, 0));
    // 0x100400: 0x1000ffe1  b           . + 4 + (-0x1F << 2)
    ctx->pc = 0x100400u;
    {
        const bool branch_taken_0x100400 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x100404u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100400u;
            // 0x100404: 0x3c020020  lui         $v0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100400) {
            ctx->pc = 0x100388u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_100388;
        }
    }
    ctx->pc = 0x100408u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
