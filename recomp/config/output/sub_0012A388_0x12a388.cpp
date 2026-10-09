#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012A388
// Address: 0x12a388 - 0x12a458
void sub_0012A388_0x12a388(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012A388_0x12a388");
#endif

    switch (ctx->pc) {
        case 0x12a3bcu: goto label_12a3bc;
        case 0x12a3c4u: goto label_12a3c4;
        case 0x12a3ccu: goto label_12a3cc;
        case 0x12a3d4u: goto label_12a3d4;
        case 0x12a3dcu: goto label_12a3dc;
        case 0x12a3e8u: goto label_12a3e8;
        case 0x12a3f8u: goto label_12a3f8;
        case 0x12a408u: goto label_12a408;
        case 0x12a410u: goto label_12a410;
        case 0x12a418u: goto label_12a418;
        case 0x12a420u: goto label_12a420;
        case 0x12a428u: goto label_12a428;
        case 0x12a430u: goto label_12a430;
        case 0x12a438u: goto label_12a438;
        case 0x12a440u: goto label_12a440;
        default: break;
    }

    ctx->pc = 0x12a388u;

    // 0x12a388: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12a388u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12a38c: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12a38cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12a390: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12a390u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12a394: 0x2463f3b0  addiu       $v1, $v1, -0xC50
    ctx->pc = 0x12a394u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294964144));
    // 0x12a398: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x12a398u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x12a39c: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x12a39cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12a3a0: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x12a3a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x12a3a4: 0x14400028  bnez        $v0, . + 4 + (0x28 << 2)
    ctx->pc = 0x12A3A4u;
    {
        const bool branch_taken_0x12a3a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12A3A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12A3A4u;
            // 0x12a3a8: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12a3a4) {
            ctx->pc = 0x12A448u;
            goto label_12a448;
        }
    }
    ctx->pc = 0x12A3ACu;
    // 0x12a3ac: 0x3c100022  lui         $s0, 0x22
    ctx->pc = 0x12a3acu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)34 << 16));
    // 0x12a3b0: 0x2610c41c  addiu       $s0, $s0, -0x3BE4
    ctx->pc = 0x12a3b0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294951964));
    // 0x12a3b4: 0xc04b192  jal         func_12C648
    ctx->pc = 0x12A3B4u;
    SET_GPR_U32(ctx, 31, 0x12A3BCu);
    ctx->pc = 0x12C648u;
    if (runtime->hasFunction(0x12C648u)) {
        auto targetFn = runtime->lookupFunction(0x12C648u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A3BCu; }
        if (ctx->pc != 0x12A3BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C648_0x12c648(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A3BCu; }
        if (ctx->pc != 0x12A3BCu) { return; }
    }
    ctx->pc = 0x12A3BCu;
label_12a3bc:
    // 0x12a3bc: 0xc04a104  jal         func_128410
    ctx->pc = 0x12A3BCu;
    SET_GPR_U32(ctx, 31, 0x12A3C4u);
    ctx->pc = 0x128410u;
    if (runtime->hasFunction(0x128410u)) {
        auto targetFn = runtime->lookupFunction(0x128410u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A3C4u; }
        if (ctx->pc != 0x12A3C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00128410_0x128410(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A3C4u; }
        if (ctx->pc != 0x12A3C4u) { return; }
    }
    ctx->pc = 0x12A3C4u;
label_12a3c4:
    // 0x12a3c4: 0xc04c040  jal         func_130100
    ctx->pc = 0x12A3C4u;
    SET_GPR_U32(ctx, 31, 0x12A3CCu);
    ctx->pc = 0x130100u;
    if (runtime->hasFunction(0x130100u)) {
        auto targetFn = runtime->lookupFunction(0x130100u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A3CCu; }
        if (ctx->pc != 0x12A3CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130100_0x130100(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A3CCu; }
        if (ctx->pc != 0x12A3CCu) { return; }
    }
    ctx->pc = 0x12A3CCu;
label_12a3cc:
    // 0x12a3cc: 0xc04f586  jal         func_13D618
    ctx->pc = 0x12A3CCu;
    SET_GPR_U32(ctx, 31, 0x12A3D4u);
    ctx->pc = 0x13D618u;
    if (runtime->hasFunction(0x13D618u)) {
        auto targetFn = runtime->lookupFunction(0x13D618u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A3D4u; }
        if (ctx->pc != 0x12A3D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D618_0x13d618(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A3D4u; }
        if (ctx->pc != 0x12A3D4u) { return; }
    }
    ctx->pc = 0x12A3D4u;
label_12a3d4:
    // 0x12a3d4: 0xc049938  jal         func_1264E0
    ctx->pc = 0x12A3D4u;
    SET_GPR_U32(ctx, 31, 0x12A3DCu);
    ctx->pc = 0x1264E0u;
    if (runtime->hasFunction(0x1264E0u)) {
        auto targetFn = runtime->lookupFunction(0x1264E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A3DCu; }
        if (ctx->pc != 0x12A3DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264E0_0x1264e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A3DCu; }
        if (ctx->pc != 0x12A3DCu) { return; }
    }
    ctx->pc = 0x12A3DCu;
label_12a3dc:
    // 0x12a3dc: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x12a3dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12a3e0: 0xc0506f8  jal         func_141BE0
    ctx->pc = 0x12A3E0u;
    SET_GPR_U32(ctx, 31, 0x12A3E8u);
    ctx->pc = 0x12A3E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A3E0u;
            // 0x12a3e4: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141BE0u;
    if (runtime->hasFunction(0x141BE0u)) {
        auto targetFn = runtime->lookupFunction(0x141BE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A3E8u; }
        if (ctx->pc != 0x12A3E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141BE0_0x141be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A3E8u; }
        if (ctx->pc != 0x12A3E8u) { return; }
    }
    ctx->pc = 0x12A3E8u;
label_12a3e8:
    // 0x12a3e8: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12a3e8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12a3ec: 0x8c45f3c0  lw          $a1, -0xC40($v0)
    ctx->pc = 0x12a3ecu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294964160)));
    // 0x12a3f0: 0xc0506f8  jal         func_141BE0
    ctx->pc = 0x12A3F0u;
    SET_GPR_U32(ctx, 31, 0x12A3F8u);
    ctx->pc = 0x12A3F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A3F0u;
            // 0x12a3f4: 0x24040004  addiu       $a0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141BE0u;
    if (runtime->hasFunction(0x141BE0u)) {
        auto targetFn = runtime->lookupFunction(0x141BE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A3F8u; }
        if (ctx->pc != 0x12A3F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141BE0_0x141be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A3F8u; }
        if (ctx->pc != 0x12A3F8u) { return; }
    }
    ctx->pc = 0x12A3F8u;
label_12a3f8:
    // 0x12a3f8: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12a3f8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12a3fc: 0x8c45f3b8  lw          $a1, -0xC48($v0)
    ctx->pc = 0x12a3fcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294964152)));
    // 0x12a400: 0xc0506f8  jal         func_141BE0
    ctx->pc = 0x12A400u;
    SET_GPR_U32(ctx, 31, 0x12A408u);
    ctx->pc = 0x12A404u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12A400u;
            // 0x12a404: 0x24040005  addiu       $a0, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141BE0u;
    if (runtime->hasFunction(0x141BE0u)) {
        auto targetFn = runtime->lookupFunction(0x141BE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A408u; }
        if (ctx->pc != 0x12A408u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141BE0_0x141be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A408u; }
        if (ctx->pc != 0x12A408u) { return; }
    }
    ctx->pc = 0x12A408u;
label_12a408:
    // 0x12a408: 0xc05084e  jal         func_142138
    ctx->pc = 0x12A408u;
    SET_GPR_U32(ctx, 31, 0x12A410u);
    ctx->pc = 0x142138u;
    if (runtime->hasFunction(0x142138u)) {
        auto targetFn = runtime->lookupFunction(0x142138u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A410u; }
        if (ctx->pc != 0x12A410u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00142138_0x142138(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A410u; }
        if (ctx->pc != 0x12A410u) { return; }
    }
    ctx->pc = 0x12A410u;
label_12a410:
    // 0x12a410: 0xc04b25e  jal         func_12C978
    ctx->pc = 0x12A410u;
    SET_GPR_U32(ctx, 31, 0x12A418u);
    ctx->pc = 0x12C978u;
    if (runtime->hasFunction(0x12C978u)) {
        auto targetFn = runtime->lookupFunction(0x12C978u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A418u; }
        if (ctx->pc != 0x12A418u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C978_0x12c978(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A418u; }
        if (ctx->pc != 0x12A418u) { return; }
    }
    ctx->pc = 0x12A418u;
label_12a418:
    // 0x12a418: 0xc04a01c  jal         func_128070
    ctx->pc = 0x12A418u;
    SET_GPR_U32(ctx, 31, 0x12A420u);
    ctx->pc = 0x128070u;
    if (runtime->hasFunction(0x128070u)) {
        auto targetFn = runtime->lookupFunction(0x128070u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A420u; }
        if (ctx->pc != 0x12A420u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00128070_0x128070(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A420u; }
        if (ctx->pc != 0x12A420u) { return; }
    }
    ctx->pc = 0x12A420u;
label_12a420:
    // 0x12a420: 0xc04fcc4  jal         func_13F310
    ctx->pc = 0x12A420u;
    SET_GPR_U32(ctx, 31, 0x12A428u);
    ctx->pc = 0x13F310u;
    if (runtime->hasFunction(0x13F310u)) {
        auto targetFn = runtime->lookupFunction(0x13F310u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A428u; }
        if (ctx->pc != 0x12A428u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F310_0x13f310(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A428u; }
        if (ctx->pc != 0x12A428u) { return; }
    }
    ctx->pc = 0x12A428u;
label_12a428:
    // 0x12a428: 0xc04fe16  jal         func_13F858
    ctx->pc = 0x12A428u;
    SET_GPR_U32(ctx, 31, 0x12A430u);
    ctx->pc = 0x13F858u;
    if (runtime->hasFunction(0x13F858u)) {
        auto targetFn = runtime->lookupFunction(0x13F858u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A430u; }
        if (ctx->pc != 0x12A430u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F858_0x13f858(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A430u; }
        if (ctx->pc != 0x12A430u) { return; }
    }
    ctx->pc = 0x12A430u;
label_12a430:
    // 0x12a430: 0xc05001c  jal         func_140070
    ctx->pc = 0x12A430u;
    SET_GPR_U32(ctx, 31, 0x12A438u);
    ctx->pc = 0x140070u;
    if (runtime->hasFunction(0x140070u)) {
        auto targetFn = runtime->lookupFunction(0x140070u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A438u; }
        if (ctx->pc != 0x12A438u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00140070_0x140070(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A438u; }
        if (ctx->pc != 0x12A438u) { return; }
    }
    ctx->pc = 0x12A438u;
label_12a438:
    // 0x12a438: 0xc04993e  jal         func_1264F8
    ctx->pc = 0x12A438u;
    SET_GPR_U32(ctx, 31, 0x12A440u);
    ctx->pc = 0x1264F8u;
    if (runtime->hasFunction(0x1264F8u)) {
        auto targetFn = runtime->lookupFunction(0x1264F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A440u; }
        if (ctx->pc != 0x12A440u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264F8_0x1264f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A440u; }
        if (ctx->pc != 0x12A440u) { return; }
    }
    ctx->pc = 0x12A440u;
label_12a440:
    // 0x12a440: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x12a440u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12a444: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x12a444u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
label_12a448:
    // 0x12a448: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12a448u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a44c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x12a44cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12a450: 0x3e00008  jr          $ra
    ctx->pc = 0x12A450u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12A454u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12A450u;
            // 0x12a454: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12A3BCu: goto label_12a3bc;
            case 0x12A3C4u: goto label_12a3c4;
            case 0x12A3CCu: goto label_12a3cc;
            case 0x12A3D4u: goto label_12a3d4;
            case 0x12A3DCu: goto label_12a3dc;
            case 0x12A3E8u: goto label_12a3e8;
            case 0x12A3F8u: goto label_12a3f8;
            case 0x12A408u: goto label_12a408;
            case 0x12A410u: goto label_12a410;
            case 0x12A418u: goto label_12a418;
            case 0x12A420u: goto label_12a420;
            case 0x12A428u: goto label_12a428;
            case 0x12A430u: goto label_12a430;
            case 0x12A438u: goto label_12a438;
            case 0x12A440u: goto label_12a440;
            case 0x12A448u: goto label_12a448;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12A458u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
