#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C8850
// Address: 0x1c8850 - 0x1c8930
void sub_001C8850_0x1c8850(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C8850_0x1c8850");
#endif

    switch (ctx->pc) {
        case 0x1c88c0u: goto label_1c88c0;
        case 0x1c88d0u: goto label_1c88d0;
        case 0x1c88dcu: goto label_1c88dc;
        case 0x1c88e8u: goto label_1c88e8;
        case 0x1c88f8u: goto label_1c88f8;
        case 0x1c8900u: goto label_1c8900;
        default: break;
    }

    ctx->pc = 0x1c8850u;

    // 0x1c8850: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c8850u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c8854: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8854u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8858: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c8858u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c885c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c885cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c8860: 0x9022b200  lbu         $v0, -0x4E00($at)
    ctx->pc = 0x1c8860u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294947328)));
    // 0x1c8864: 0x1440000c  bnez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1C8864u;
    {
        const bool branch_taken_0x1c8864 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C8868u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8864u;
            // 0x1c8868: 0x3c011000  lui         $at, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4096 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c8864) {
            ctx->pc = 0x1C8898u;
            goto label_1c8898;
        }
    }
    ctx->pc = 0x1C886Cu;
    // 0x1c886c: 0x3c011000  lui         $at, 0x1000
    ctx->pc = 0x1c886cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4096 << 16));
    // 0x1c8870: 0x24030083  addiu       $v1, $zero, 0x83
    ctx->pc = 0x1c8870u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 131));
    // 0x1c8874: 0xac200810  sw          $zero, 0x810($at)
    ctx->pc = 0x1c8874u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 2064), GPR_U32(ctx, 0)); // MMIO: 0x10000810
    // 0x1c8878: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c8878u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c887c: 0x3c011000  lui         $at, 0x1000
    ctx->pc = 0x1c887cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4096 << 16));
    // 0x1c8880: 0xac200800  sw          $zero, 0x800($at)
    ctx->pc = 0x1c8880u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 2048), GPR_U32(ctx, 0)); // MMIO: 0x10000800
    // 0x1c8884: 0x3c011000  lui         $at, 0x1000
    ctx->pc = 0x1c8884u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4096 << 16));
    // 0x1c8888: 0xac230810  sw          $v1, 0x810($at)
    ctx->pc = 0x1c8888u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 2064), GPR_U32(ctx, 3)); // MMIO: 0x10000810
    // 0x1c888c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c888cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8890: 0xa022b200  sb          $v0, -0x4E00($at)
    ctx->pc = 0x1c8890u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294947328), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c8894: 0x3c011000  lui         $at, 0x1000
    ctx->pc = 0x1c8894u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4096 << 16));
label_1c8898:
    // 0x1c8898: 0x8c230800  lw          $v1, 0x800($at)
    ctx->pc = 0x1c8898u;
    SET_GPR_S32(ctx, 3, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 2048))); // MMIO: 0x10000800
    // 0x1c889c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c889cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c88a0: 0x8c22b208  lw          $v0, -0x4DF8($at)
    ctx->pc = 0x1c88a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294947336)));
    // 0x1c88a4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c88a4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c88a8: 0x621023  subu        $v0, $v1, $v0
    ctx->pc = 0x1c88a8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1c88ac: 0x18400019  blez        $v0, . + 4 + (0x19 << 2)
    ctx->pc = 0x1C88ACu;
    {
        const bool branch_taken_0x1c88ac = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1C88B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C88ACu;
            // 0x1c88b0: 0xac23b208  sw          $v1, -0x4DF8($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294947336), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c88ac) {
            ctx->pc = 0x1C8914u;
            goto label_1c8914;
        }
    }
    ctx->pc = 0x1C88B4u;
    // 0x1c88b4: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1c88b4u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1c88b8: 0xc04462e  jal         func_1118B8
    ctx->pc = 0x1C88B8u;
    SET_GPR_U32(ctx, 31, 0x1C88C0u);
    ctx->pc = 0x1C88BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C88B8u;
            // 0x1c88bc: 0x46800320  cvt.s.w     $f12, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[12] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x1118B8u;
    if (runtime->hasFunction(0x1118B8u)) {
        auto targetFn = runtime->lookupFunction(0x1118B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C88C0u; }
        if (ctx->pc != 0x1C88C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001118B8_0x1118b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C88C0u; }
        if (ctx->pc != 0x1C88C0u) { return; }
    }
    ctx->pc = 0x1C88C0u;
label_1c88c0:
    // 0x1c88c0: 0x3c034030  lui         $v1, 0x4030
    ctx->pc = 0x1c88c0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16432 << 16));
    // 0x1c88c4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1c88c4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c88c8: 0xc04480e  jal         func_112038
    ctx->pc = 0x1C88C8u;
    SET_GPR_U32(ctx, 31, 0x1C88D0u);
    ctx->pc = 0x1C88CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C88C8u;
            // 0x1c88cc: 0x3283c  dsll32      $a1, $v1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) << (32 + 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112038u;
    if (runtime->hasFunction(0x112038u)) {
        auto targetFn = runtime->lookupFunction(0x112038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C88D0u; }
        if (ctx->pc != 0x1C88D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112038_0x112038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C88D0u; }
        if (ctx->pc != 0x1C88D0u) { return; }
    }
    ctx->pc = 0x1C88D0u;
label_1c88d0:
    // 0x1c88d0: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1c88d0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c88d4: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x1C88D4u;
    SET_GPR_U32(ctx, 31, 0x1C88DCu);
    ctx->pc = 0x1C88D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C88D4u;
            // 0x1c88d8: 0x240403e8  addiu       $a0, $zero, 0x3E8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1000));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C88DCu; }
        if (ctx->pc != 0x1C88DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C88DCu; }
        if (ctx->pc != 0x1C88DCu) { return; }
    }
    ctx->pc = 0x1C88DCu;
label_1c88dc:
    // 0x1c88dc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1c88dcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c88e0: 0xc04480e  jal         func_112038
    ctx->pc = 0x1C88E0u;
    SET_GPR_U32(ctx, 31, 0x1C88E8u);
    ctx->pc = 0x1C88E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C88E0u;
            // 0x1c88e4: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112038u;
    if (runtime->hasFunction(0x112038u)) {
        auto targetFn = runtime->lookupFunction(0x112038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C88E8u; }
        if (ctx->pc != 0x1C88E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112038_0x112038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C88E8u; }
        if (ctx->pc != 0x1C88E8u) { return; }
    }
    ctx->pc = 0x1C88E8u;
label_1c88e8:
    // 0x1c88e8: 0x3c010025  lui         $at, 0x25
    ctx->pc = 0x1c88e8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)37 << 16));
    // 0x1c88ec: 0xdc242dd0  ld          $a0, 0x2DD0($at)
    ctx->pc = 0x1c88ecu;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 1), 11728)));
    // 0x1c88f0: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x1C88F0u;
    SET_GPR_U32(ctx, 31, 0x1C88F8u);
    ctx->pc = 0x1C88F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C88F0u;
            // 0x1c88f4: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C88F8u; }
        if (ctx->pc != 0x1C88F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C88F8u; }
        if (ctx->pc != 0x1C88F8u) { return; }
    }
    ctx->pc = 0x1C88F8u;
label_1c88f8:
    // 0x1c88f8: 0xc04491c  jal         func_112470
    ctx->pc = 0x1C88F8u;
    SET_GPR_U32(ctx, 31, 0x1C8900u);
    ctx->pc = 0x1C88FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C88F8u;
            // 0x1c88fc: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112470u;
    if (runtime->hasFunction(0x112470u)) {
        auto targetFn = runtime->lookupFunction(0x112470u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8900u; }
        if (ctx->pc != 0x1C8900u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112470_0x112470(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8900u; }
        if (ctx->pc != 0x1C8900u) { return; }
    }
    ctx->pc = 0x1C8900u;
label_1c8900:
    // 0x1c8900: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8900u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8904: 0xc421b210  lwc1        $f1, -0x4DF0($at)
    ctx->pc = 0x1c8904u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294947344)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1c8908: 0x46000800  add.s       $f0, $f1, $f0
    ctx->pc = 0x1c8908u;
    ctx->f[0] = FPU_ADD_S(ctx->f[1], ctx->f[0]);
    // 0x1c890c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c890cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8910: 0xe420b210  swc1        $f0, -0x4DF0($at)
    ctx->pc = 0x1c8910u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 4294947344), bits); }
label_1c8914:
    // 0x1c8914: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8914u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8918: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c8918u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c891c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c891cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c8920: 0xc420b210  lwc1        $f0, -0x4DF0($at)
    ctx->pc = 0x1c8920u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294947344)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1c8924: 0x3e00008  jr          $ra
    ctx->pc = 0x1C8924u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C8928u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8924u;
            // 0x1c8928: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C8898u: goto label_1c8898;
            case 0x1C88C0u: goto label_1c88c0;
            case 0x1C88D0u: goto label_1c88d0;
            case 0x1C88DCu: goto label_1c88dc;
            case 0x1C88E8u: goto label_1c88e8;
            case 0x1C88F8u: goto label_1c88f8;
            case 0x1C8900u: goto label_1c8900;
            case 0x1C8914u: goto label_1c8914;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C892Cu;
    // 0x1c892c: 0x0  nop
    ctx->pc = 0x1c892cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
