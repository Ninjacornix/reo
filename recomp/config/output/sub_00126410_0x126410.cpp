#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00126410
// Address: 0x126410 - 0x1264d0
void sub_00126410_0x126410(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00126410_0x126410");
#endif

    switch (ctx->pc) {
        case 0x126430u: goto label_126430;
        case 0x12644cu: goto label_12644c;
        default: break;
    }

    ctx->pc = 0x126410u;

    // 0x126410: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x126410u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x126414: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x126414u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x126418: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x126418u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x12641c: 0x24a59bd0  addiu       $a1, $a1, -0x6430
    ctx->pc = 0x12641cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294941648));
    // 0x126420: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x126420u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x126424: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x126424u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x126428: 0xc041e86  jal         func_107A18
    ctx->pc = 0x126428u;
    SET_GPR_U32(ctx, 31, 0x126430u);
    ctx->pc = 0x12642Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x126428u;
            // 0x12642c: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107A18u;
    if (runtime->hasFunction(0x107A18u)) {
        auto targetFn = runtime->lookupFunction(0x107A18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x126430u; }
        if (ctx->pc != 0x126430u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107A18_0x107a18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x126430u; }
        if (ctx->pc != 0x126430u) { return; }
    }
    ctx->pc = 0x126430u;
label_126430:
    // 0x126430: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x126430u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x126434: 0x26040008  addiu       $a0, $s0, 0x8
    ctx->pc = 0x126434u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
    // 0x126438: 0x24a59bd8  addiu       $a1, $a1, -0x6428
    ctx->pc = 0x126438u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294941656));
    // 0x12643c: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x12643Cu;
    {
        const bool branch_taken_0x12643c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x126440u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12643Cu;
            // 0x126440: 0x24060004  addiu       $a2, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12643c) {
            ctx->pc = 0x126460u;
            goto label_126460;
        }
    }
    ctx->pc = 0x126444u;
    // 0x126444: 0xc041e86  jal         func_107A18
    ctx->pc = 0x126444u;
    SET_GPR_U32(ctx, 31, 0x12644Cu);
    ctx->pc = 0x107A18u;
    if (runtime->hasFunction(0x107A18u)) {
        auto targetFn = runtime->lookupFunction(0x107A18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12644Cu; }
        if (ctx->pc != 0x12644Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107A18_0x107a18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12644Cu; }
        if (ctx->pc != 0x12644Cu) { return; }
    }
    ctx->pc = 0x12644Cu;
label_12644c:
    // 0x12644c: 0x54400005  bnel        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x12644Cu;
    {
        const bool branch_taken_0x12644c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x12644c) {
            ctx->pc = 0x126450u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12644Cu;
            // 0x126450: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x126464u;
            goto label_126464;
        }
    }
    ctx->pc = 0x126454u;
    // 0x126454: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x126454u;
    {
        const bool branch_taken_0x126454 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x126458u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126454u;
            // 0x126458: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126454) {
            ctx->pc = 0x126464u;
            goto label_126464;
        }
    }
    ctx->pc = 0x12645Cu;
    // 0x12645c: 0x0  nop
    ctx->pc = 0x12645cu;
    // NOP
label_126460:
    // 0x126460: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x126460u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_126464:
    // 0x126464: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x126464u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x126468: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x126468u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12646c: 0x3e00008  jr          $ra
    ctx->pc = 0x12646Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x126470u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12646Cu;
            // 0x126470: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x126430u: goto label_126430;
            case 0x12644Cu: goto label_12644c;
            case 0x126460u: goto label_126460;
            case 0x126464u: goto label_126464;
            case 0x1264A0u: goto label_1264a0;
            case 0x1264B0u: goto label_1264b0;
            case 0x1264C8u: goto label_1264c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x126474u;
    // 0x126474: 0x0  nop
    ctx->pc = 0x126474u;
    // NOP
    // 0x126478: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x126478u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12647c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x12647cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x126480: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x126480u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x126484: 0x8483009a  lh          $v1, 0x9A($a0)
    ctx->pc = 0x126484u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 154)));
    // 0x126488: 0x14620005  bne         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x126488u;
    {
        const bool branch_taken_0x126488 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x12648Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126488u;
            // 0x12648c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126488) {
            ctx->pc = 0x1264A0u;
            goto label_1264a0;
        }
    }
    ctx->pc = 0x126490u;
    // 0x126490: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x126490u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x126494: 0x804989c  j           func_126270
    ctx->pc = 0x126494u;
    ctx->pc = 0x126498u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x126494u;
            // 0x126498: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x126270u;
    if (runtime->hasFunction(0x126270u)) {
        auto targetFn = runtime->lookupFunction(0x126270u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00126270_0x126270(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12649Cu;
    // 0x12649c: 0x0  nop
    ctx->pc = 0x12649cu;
    // NOP
label_1264a0:
    // 0x1264a0: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1264A0u;
    {
        const bool branch_taken_0x1264a0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1264A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1264A0u;
            // 0x1264a4: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1264a0) {
            ctx->pc = 0x1264B0u;
            goto label_1264b0;
        }
    }
    ctx->pc = 0x1264A8u;
    // 0x1264a8: 0x8049836  j           func_1260D8
    ctx->pc = 0x1264A8u;
    ctx->pc = 0x1264ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1264A8u;
            // 0x1264ac: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1260D8u;
    if (runtime->hasFunction(0x1260D8u)) {
        auto targetFn = runtime->lookupFunction(0x1260D8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001260D8_0x1260d8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1264B0u;
label_1264b0:
    // 0x1264b0: 0x14600005  bnez        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1264B0u;
    {
        const bool branch_taken_0x1264b0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1264b0) {
            ctx->pc = 0x1264C8u;
            goto label_1264c8;
        }
    }
    ctx->pc = 0x1264B8u;
    // 0x1264b8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1264b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1264bc: 0x80497d8  j           func_125F60
    ctx->pc = 0x1264BCu;
    ctx->pc = 0x1264C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1264BCu;
            // 0x1264c0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x125F60u;
    if (runtime->hasFunction(0x125F60u)) {
        auto targetFn = runtime->lookupFunction(0x125F60u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00125F60_0x125f60(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1264C4u;
    // 0x1264c4: 0x0  nop
    ctx->pc = 0x1264c4u;
    // NOP
label_1264c8:
    // 0x1264c8: 0x3e00008  jr          $ra
    ctx->pc = 0x1264C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1264CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1264C8u;
            // 0x1264cc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x126430u: goto label_126430;
            case 0x12644Cu: goto label_12644c;
            case 0x126460u: goto label_126460;
            case 0x126464u: goto label_126464;
            case 0x1264A0u: goto label_1264a0;
            case 0x1264B0u: goto label_1264b0;
            case 0x1264C8u: goto label_1264c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1264D0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
