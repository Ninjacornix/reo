#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00111328
// Address: 0x111328 - 0x1113d0
void sub_00111328_0x111328(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00111328_0x111328");
#endif

    switch (ctx->pc) {
        case 0x111350u: goto label_111350;
        case 0x111360u: goto label_111360;
        case 0x111370u: goto label_111370;
        case 0x111390u: goto label_111390;
        case 0x1113acu: goto label_1113ac;
        case 0x1113bcu: goto label_1113bc;
        default: break;
    }

    ctx->pc = 0x111328u;

    // 0x111328: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x111328u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x11132c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11132cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x111330: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x111330u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111334: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x111334u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x111338: 0x10203f  dsra32      $a0, $s0, 0
    ctx->pc = 0x111338u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 16) >> (32 + 0));
    // 0x11133c: 0x341181e0  ori         $s1, $zero, 0x81E0
    ctx->pc = 0x11133cu;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33248);
    // 0x111340: 0x118bfc  dsll32      $s1, $s1, 15
    ctx->pc = 0x111340u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) << (32 + 15));
    // 0x111344: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x111344u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x111348: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x111348u;
    SET_GPR_U32(ctx, 31, 0x111350u);
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111350u; }
        if (ctx->pc != 0x111350u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111350u; }
        if (ctx->pc != 0x111350u) { return; }
    }
    ctx->pc = 0x111350u;
label_111350:
    // 0x111350: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x111350u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111354: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x111354u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111358: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x111358u;
    SET_GPR_U32(ctx, 31, 0x111360u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111360u; }
        if (ctx->pc != 0x111360u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111360u; }
        if (ctx->pc != 0x111360u) { return; }
    }
    ctx->pc = 0x111360u;
label_111360:
    // 0x111360: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x111360u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111364: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x111364u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111368: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x111368u;
    SET_GPR_U32(ctx, 31, 0x111370u);
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111370u; }
        if (ctx->pc != 0x111370u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111370u; }
        if (ctx->pc != 0x111370u) { return; }
    }
    ctx->pc = 0x111370u;
label_111370:
    // 0x111370: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x111370u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111374: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x111374u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x111378: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x111378u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x11137c: 0x2028024  and         $s0, $s0, $v0
    ctx->pc = 0x11137cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) & GPR_U64(ctx, 2));
    // 0x111380: 0x10803c  dsll32      $s0, $s0, 0
    ctx->pc = 0x111380u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) << (32 + 0));
    // 0x111384: 0x10803f  dsra32      $s0, $s0, 0
    ctx->pc = 0x111384u;
    SET_GPR_S64(ctx, 16, GPR_S64(ctx, 16) >> (32 + 0));
    // 0x111388: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x111388u;
    SET_GPR_U32(ctx, 31, 0x111390u);
    ctx->pc = 0x11138Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x111388u;
            // 0x11138c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111390u; }
        if (ctx->pc != 0x111390u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x111390u; }
        if (ctx->pc != 0x111390u) { return; }
    }
    ctx->pc = 0x111390u;
label_111390:
    // 0x111390: 0x340583e0  ori         $a1, $zero, 0x83E0
    ctx->pc = 0x111390u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33760);
    // 0x111394: 0x52bfc  dsll32      $a1, $a1, 15
    ctx->pc = 0x111394u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 15));
    // 0x111398: 0x6010004  bgez        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x111398u;
    {
        const bool branch_taken_0x111398 = (GPR_S64(ctx, 16) >= 0);
        if (branch_taken_0x111398) {
            ctx->pc = 0x1113ACu;
            goto label_1113ac;
        }
    }
    ctx->pc = 0x1113A0u;
    // 0x1113a0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1113a0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1113a4: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x1113A4u;
    SET_GPR_U32(ctx, 31, 0x1113ACu);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1113ACu; }
        if (ctx->pc != 0x1113ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1113ACu; }
        if (ctx->pc != 0x1113ACu) { return; }
    }
    ctx->pc = 0x1113ACu;
label_1113ac:
    // 0x1113ac: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1113acu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1113b0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1113b0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1113b4: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x1113B4u;
    SET_GPR_U32(ctx, 31, 0x1113BCu);
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1113BCu; }
        if (ctx->pc != 0x1113BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1113BCu; }
        if (ctx->pc != 0x1113BCu) { return; }
    }
    ctx->pc = 0x1113BCu;
label_1113bc:
    // 0x1113bc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1113bcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1113c0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1113c0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1113c4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1113c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1113c8: 0x3e00008  jr          $ra
    ctx->pc = 0x1113C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1113CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1113C8u;
            // 0x1113cc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x111350u: goto label_111350;
            case 0x111360u: goto label_111360;
            case 0x111370u: goto label_111370;
            case 0x111390u: goto label_111390;
            case 0x1113ACu: goto label_1113ac;
            case 0x1113BCu: goto label_1113bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1113D0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
