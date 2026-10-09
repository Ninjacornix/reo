#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012D338
// Address: 0x12d338 - 0x12d638
void sub_0012D338_0x12d338(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012D338_0x12d338");
#endif

    switch (ctx->pc) {
        case 0x12d384u: goto label_12d384;
        case 0x12d390u: goto label_12d390;
        case 0x12d39cu: goto label_12d39c;
        case 0x12d3c8u: goto label_12d3c8;
        case 0x12d3e0u: goto label_12d3e0;
        case 0x12d3f8u: goto label_12d3f8;
        case 0x12d400u: goto label_12d400;
        case 0x12d408u: goto label_12d408;
        case 0x12d428u: goto label_12d428;
        case 0x12d444u: goto label_12d444;
        case 0x12d460u: goto label_12d460;
        case 0x12d468u: goto label_12d468;
        case 0x12d4ccu: goto label_12d4cc;
        case 0x12d500u: goto label_12d500;
        case 0x12d528u: goto label_12d528;
        case 0x12d534u: goto label_12d534;
        case 0x12d540u: goto label_12d540;
        case 0x12d5b0u: goto label_12d5b0;
        case 0x12d5c0u: goto label_12d5c0;
        case 0x12d5c8u: goto label_12d5c8;
        case 0x12d5d0u: goto label_12d5d0;
        case 0x12d5e4u: goto label_12d5e4;
        default: break;
    }

    ctx->pc = 0x12d338u;

label_12d338:
    // 0x12d338: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x12d338u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x12d33c: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x12d33cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x12d340: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x12d340u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x12d344: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x12d344u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d348: 0xffb30048  sd          $s3, 0x48($sp)
    ctx->pc = 0x12d348u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 19));
    // 0x12d34c: 0xffb40050  sd          $s4, 0x50($sp)
    ctx->pc = 0x12d34cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 20));
    // 0x12d350: 0x2654000c  addiu       $s4, $s2, 0xC
    ctx->pc = 0x12d350u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 18), 12));
    // 0x12d354: 0xffb50058  sd          $s5, 0x58($sp)
    ctx->pc = 0x12d354u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 21));
    // 0x12d358: 0x2655001c  addiu       $s5, $s2, 0x1C
    ctx->pc = 0x12d358u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 18), 28));
    // 0x12d35c: 0xffb60060  sd          $s6, 0x60($sp)
    ctx->pc = 0x12d35cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 22));
    // 0x12d360: 0xb02d  daddu       $s6, $zero, $zero
    ctx->pc = 0x12d360u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d364: 0xffbe0070  sd          $fp, 0x70($sp)
    ctx->pc = 0x12d364u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 30));
    // 0x12d368: 0xffb10038  sd          $s1, 0x38($sp)
    ctx->pc = 0x12d368u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x12d36c: 0xffb70068  sd          $s7, 0x68($sp)
    ctx->pc = 0x12d36cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 23));
    // 0x12d370: 0xffbf0078  sd          $ra, 0x78($sp)
    ctx->pc = 0x12d370u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 120), GPR_U64(ctx, 31));
    // 0x12d374: 0x8e570004  lw          $s7, 0x4($s2)
    ctx->pc = 0x12d374u;
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x12d378: 0x8e510008  lw          $s1, 0x8($s2)
    ctx->pc = 0x12d378u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x12d37c: 0xc0493be  jal         func_124EF8
    ctx->pc = 0x12D37Cu;
    SET_GPR_U32(ctx, 31, 0x12D384u);
    ctx->pc = 0x12D380u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D37Cu;
            // 0x12d380: 0x2e0202d  daddu       $a0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124EF8u;
    if (runtime->hasFunction(0x124EF8u)) {
        auto targetFn = runtime->lookupFunction(0x124EF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D384u; }
        if (ctx->pc != 0x12D384u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00124EF8_0x124ef8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D384u; }
        if (ctx->pc != 0x12D384u) { return; }
    }
    ctx->pc = 0x12D384u;
label_12d384:
    // 0x12d384: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x12d384u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d388: 0xc0494ae  jal         func_1252B8
    ctx->pc = 0x12D388u;
    SET_GPR_U32(ctx, 31, 0x12D390u);
    ctx->pc = 0x12D38Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D388u;
            // 0x12d38c: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1252B8u;
    if (runtime->hasFunction(0x1252B8u)) {
        auto targetFn = runtime->lookupFunction(0x1252B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D390u; }
        if (ctx->pc != 0x12D390u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001252B8_0x1252b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D390u; }
        if (ctx->pc != 0x12D390u) { return; }
    }
    ctx->pc = 0x12D390u;
label_12d390:
    // 0x12d390: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x12d390u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d394: 0xc0494b0  jal         func_1252C0
    ctx->pc = 0x12D394u;
    SET_GPR_U32(ctx, 31, 0x12D39Cu);
    ctx->pc = 0x12D398u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D394u;
            // 0x12d398: 0xafa20020  sw          $v0, 0x20($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1252C0u;
    if (runtime->hasFunction(0x1252C0u)) {
        auto targetFn = runtime->lookupFunction(0x1252C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D39Cu; }
        if (ctx->pc != 0x12D39Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001252C0_0x1252c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D39Cu; }
        if (ctx->pc != 0x12D39Cu) { return; }
    }
    ctx->pc = 0x12D39Cu;
label_12d39c:
    // 0x12d39c: 0x26440014  addiu       $a0, $s2, 0x14
    ctx->pc = 0x12d39cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), 20));
    // 0x12d3a0: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x12d3a0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d3a4: 0x8e420034  lw          $v0, 0x34($s2)
    ctx->pc = 0x12d3a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 52)));
    // 0x12d3a8: 0x27be0010  addiu       $fp, $sp, 0x10
    ctx->pc = 0x12d3a8u;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x12d3ac: 0x8fa50020  lw          $a1, 0x20($sp)
    ctx->pc = 0x12d3acu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12d3b0: 0x2028023  subu        $s0, $s0, $v0
    ctx->pc = 0x12d3b0u;
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x12d3b4: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x12d3b4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d3b8: 0x270102a  slt         $v0, $s3, $s0
    ctx->pc = 0x12d3b8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x12d3bc: 0x3c0382d  daddu       $a3, $fp, $zero
    ctx->pc = 0x12d3bcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d3c0: 0xc0501f8  jal         func_1407E0
    ctx->pc = 0x12D3C0u;
    SET_GPR_U32(ctx, 31, 0x12D3C8u);
    ctx->pc = 0x12D3C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D3C0u;
            // 0x12d3c4: 0x202980a  movz        $s3, $s0, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 19, GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1407E0u;
    if (runtime->hasFunction(0x1407E0u)) {
        auto targetFn = runtime->lookupFunction(0x1407E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D3C8u; }
        if (ctx->pc != 0x12D3C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001407E0_0x1407e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D3C8u; }
        if (ctx->pc != 0x12D3C8u) { return; }
    }
    ctx->pc = 0x12D3C8u;
label_12d3c8:
    // 0x12d3c8: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x12d3c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x12d3cc: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x12d3ccu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d3d0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x12d3d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d3d4: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x12d3d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x12d3d8: 0x40f809  jalr        $v0
    ctx->pc = 0x12D3D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12D3E0u);
        ctx->pc = 0x12D3DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D3D8u;
            // 0x12d3dc: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12D3E0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12D338u: goto label_12d338;
            case 0x12D384u: goto label_12d384;
            case 0x12D390u: goto label_12d390;
            case 0x12D39Cu: goto label_12d39c;
            case 0x12D3C8u: goto label_12d3c8;
            case 0x12D3E0u: goto label_12d3e0;
            case 0x12D3F8u: goto label_12d3f8;
            case 0x12D400u: goto label_12d400;
            case 0x12D408u: goto label_12d408;
            case 0x12D428u: goto label_12d428;
            case 0x12D444u: goto label_12d444;
            case 0x12D460u: goto label_12d460;
            case 0x12D468u: goto label_12d468;
            case 0x12D4CCu: goto label_12d4cc;
            case 0x12D500u: goto label_12d500;
            case 0x12D528u: goto label_12d528;
            case 0x12D534u: goto label_12d534;
            case 0x12D540u: goto label_12d540;
            case 0x12D5B0u: goto label_12d5b0;
            case 0x12D5C0u: goto label_12d5c0;
            case 0x12D5C8u: goto label_12d5c8;
            case 0x12D5D0u: goto label_12d5d0;
            case 0x12D5E4u: goto label_12d5e4;
            case 0x12D60Cu: goto label_12d60c;
            case 0x12D628u: goto label_12d628;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12D3E0u; }
            if (ctx->pc != 0x12D3E0u) { return; }
        }
        }
    }
    ctx->pc = 0x12D3E0u;
label_12d3e0:
    // 0x12d3e0: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x12d3e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x12d3e4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x12d3e4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d3e8: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12d3e8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12d3ec: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x12d3ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x12d3f0: 0x40f809  jalr        $v0
    ctx->pc = 0x12D3F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12D3F8u);
        ctx->pc = 0x12D3F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D3F0u;
            // 0x12d3f4: 0x3c0302d  daddu       $a2, $fp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12D3F8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12D338u: goto label_12d338;
            case 0x12D384u: goto label_12d384;
            case 0x12D390u: goto label_12d390;
            case 0x12D39Cu: goto label_12d39c;
            case 0x12D3C8u: goto label_12d3c8;
            case 0x12D3E0u: goto label_12d3e0;
            case 0x12D3F8u: goto label_12d3f8;
            case 0x12D400u: goto label_12d400;
            case 0x12D408u: goto label_12d408;
            case 0x12D428u: goto label_12d428;
            case 0x12D444u: goto label_12d444;
            case 0x12D460u: goto label_12d460;
            case 0x12D468u: goto label_12d468;
            case 0x12D4CCu: goto label_12d4cc;
            case 0x12D500u: goto label_12d500;
            case 0x12D528u: goto label_12d528;
            case 0x12D534u: goto label_12d534;
            case 0x12D540u: goto label_12d540;
            case 0x12D5B0u: goto label_12d5b0;
            case 0x12D5C0u: goto label_12d5c0;
            case 0x12D5C8u: goto label_12d5c8;
            case 0x12D5D0u: goto label_12d5d0;
            case 0x12D5E4u: goto label_12d5e4;
            case 0x12D60Cu: goto label_12d60c;
            case 0x12D628u: goto label_12d628;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12D3F8u; }
            if (ctx->pc != 0x12D3F8u) { return; }
        }
        }
    }
    ctx->pc = 0x12D3F8u;
label_12d3f8:
    // 0x12d3f8: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x12D3F8u;
    {
        const bool branch_taken_0x12d3f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x12d3f8) {
            ctx->pc = 0x12D460u;
            goto label_12d460;
        }
    }
    ctx->pc = 0x12D400u;
label_12d400:
    // 0x12d400: 0xc0501f8  jal         func_1407E0
    ctx->pc = 0x12D400u;
    SET_GPR_U32(ctx, 31, 0x12D408u);
    ctx->pc = 0x1407E0u;
    if (runtime->hasFunction(0x1407E0u)) {
        auto targetFn = runtime->lookupFunction(0x1407E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D408u; }
        if (ctx->pc != 0x12D408u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001407E0_0x1407e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D408u; }
        if (ctx->pc != 0x12D408u) { return; }
    }
    ctx->pc = 0x12D408u;
label_12d408:
    // 0x12d408: 0x8e420050  lw          $v0, 0x50($s2)
    ctx->pc = 0x12d408u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 80)));
    // 0x12d40c: 0x2c0282d  daddu       $a1, $s6, $zero
    ctx->pc = 0x12d40cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d410: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x12D410u;
    {
        const bool branch_taken_0x12d410 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x12D414u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D410u;
            // 0x12d414: 0x26d60001  addiu       $s6, $s6, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12d410) {
            ctx->pc = 0x12D428u;
            goto label_12d428;
        }
    }
    ctx->pc = 0x12D418u;
    // 0x12d418: 0x8e440054  lw          $a0, 0x54($s2)
    ctx->pc = 0x12d418u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 84)));
    // 0x12d41c: 0x8fa60000  lw          $a2, 0x0($sp)
    ctx->pc = 0x12d41cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12d420: 0x40f809  jalr        $v0
    ctx->pc = 0x12D420u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12D428u);
        ctx->pc = 0x12D424u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D420u;
            // 0x12d424: 0x8fa70004  lw          $a3, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12D428u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12D338u: goto label_12d338;
            case 0x12D384u: goto label_12d384;
            case 0x12D390u: goto label_12d390;
            case 0x12D39Cu: goto label_12d39c;
            case 0x12D3C8u: goto label_12d3c8;
            case 0x12D3E0u: goto label_12d3e0;
            case 0x12D3F8u: goto label_12d3f8;
            case 0x12D400u: goto label_12d400;
            case 0x12D408u: goto label_12d408;
            case 0x12D428u: goto label_12d428;
            case 0x12D444u: goto label_12d444;
            case 0x12D460u: goto label_12d460;
            case 0x12D468u: goto label_12d468;
            case 0x12D4CCu: goto label_12d4cc;
            case 0x12D500u: goto label_12d500;
            case 0x12D528u: goto label_12d528;
            case 0x12D534u: goto label_12d534;
            case 0x12D540u: goto label_12d540;
            case 0x12D5B0u: goto label_12d5b0;
            case 0x12D5C0u: goto label_12d5c0;
            case 0x12D5C8u: goto label_12d5c8;
            case 0x12D5D0u: goto label_12d5d0;
            case 0x12D5E4u: goto label_12d5e4;
            case 0x12D60Cu: goto label_12d60c;
            case 0x12D628u: goto label_12d628;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12D428u; }
            if (ctx->pc != 0x12D428u) { return; }
        }
        }
    }
    ctx->pc = 0x12D428u;
label_12d428:
    // 0x12d428: 0x8e840000  lw          $a0, 0x0($s4)
    ctx->pc = 0x12d428u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x12d42c: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x12d42cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d430: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x12d430u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12d434: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x12d434u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x12d438: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x12d438u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x12d43c: 0x40f809  jalr        $v0
    ctx->pc = 0x12D43Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12D444u);
        ctx->pc = 0x12D440u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D43Cu;
            // 0x12d440: 0x26b50008  addiu       $s5, $s5, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 8));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12D444u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12D338u: goto label_12d338;
            case 0x12D384u: goto label_12d384;
            case 0x12D390u: goto label_12d390;
            case 0x12D39Cu: goto label_12d39c;
            case 0x12D3C8u: goto label_12d3c8;
            case 0x12D3E0u: goto label_12d3e0;
            case 0x12D3F8u: goto label_12d3f8;
            case 0x12D400u: goto label_12d400;
            case 0x12D408u: goto label_12d408;
            case 0x12D428u: goto label_12d428;
            case 0x12D444u: goto label_12d444;
            case 0x12D460u: goto label_12d460;
            case 0x12D468u: goto label_12d468;
            case 0x12D4CCu: goto label_12d4cc;
            case 0x12D500u: goto label_12d500;
            case 0x12D528u: goto label_12d528;
            case 0x12D534u: goto label_12d534;
            case 0x12D540u: goto label_12d540;
            case 0x12D5B0u: goto label_12d5b0;
            case 0x12D5C0u: goto label_12d5c0;
            case 0x12D5C8u: goto label_12d5c8;
            case 0x12D5D0u: goto label_12d5d0;
            case 0x12D5E4u: goto label_12d5e4;
            case 0x12D60Cu: goto label_12d60c;
            case 0x12D628u: goto label_12d628;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12D444u; }
            if (ctx->pc != 0x12D444u) { return; }
        }
        }
    }
    ctx->pc = 0x12D444u;
label_12d444:
    // 0x12d444: 0x8e840000  lw          $a0, 0x0($s4)
    ctx->pc = 0x12d444u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x12d448: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12d448u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d44c: 0x3c0302d  daddu       $a2, $fp, $zero
    ctx->pc = 0x12d44cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d450: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x12d450u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x12d454: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x12d454u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x12d458: 0x40f809  jalr        $v0
    ctx->pc = 0x12D458u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12D460u);
        ctx->pc = 0x12D45Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D458u;
            // 0x12d45c: 0x26940004  addiu       $s4, $s4, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 4));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12D460u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12D338u: goto label_12d338;
            case 0x12D384u: goto label_12d384;
            case 0x12D390u: goto label_12d390;
            case 0x12D39Cu: goto label_12d39c;
            case 0x12D3C8u: goto label_12d3c8;
            case 0x12D3E0u: goto label_12d3e0;
            case 0x12D3F8u: goto label_12d3f8;
            case 0x12D400u: goto label_12d400;
            case 0x12D408u: goto label_12d408;
            case 0x12D428u: goto label_12d428;
            case 0x12D444u: goto label_12d444;
            case 0x12D460u: goto label_12d460;
            case 0x12D468u: goto label_12d468;
            case 0x12D4CCu: goto label_12d4cc;
            case 0x12D500u: goto label_12d500;
            case 0x12D528u: goto label_12d528;
            case 0x12D534u: goto label_12d534;
            case 0x12D540u: goto label_12d540;
            case 0x12D5B0u: goto label_12d5b0;
            case 0x12D5C0u: goto label_12d5c0;
            case 0x12D5C8u: goto label_12d5c8;
            case 0x12D5D0u: goto label_12d5d0;
            case 0x12D5E4u: goto label_12d5e4;
            case 0x12D60Cu: goto label_12d60c;
            case 0x12D628u: goto label_12d628;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12D460u; }
            if (ctx->pc != 0x12D460u) { return; }
        }
        }
    }
    ctx->pc = 0x12D460u;
label_12d460:
    // 0x12d460: 0xc04939e  jal         func_124E78
    ctx->pc = 0x12D460u;
    SET_GPR_U32(ctx, 31, 0x12D468u);
    ctx->pc = 0x12D464u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D460u;
            // 0x12d464: 0x8e440004  lw          $a0, 0x4($s2) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124E78u;
    if (runtime->hasFunction(0x124E78u)) {
        auto targetFn = runtime->lookupFunction(0x124E78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D468u; }
        if (ctx->pc != 0x12D468u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00124E78_0x124e78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D468u; }
        if (ctx->pc != 0x12D468u) { return; }
    }
    ctx->pc = 0x12D468u;
label_12d468:
    // 0x12d468: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x12d468u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d46c: 0x2c2102a  slt         $v0, $s6, $v0
    ctx->pc = 0x12d46cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 22) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x12d470: 0x132840  sll         $a1, $s3, 1
    ctx->pc = 0x12d470u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 19), 1));
    // 0x12d474: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x12d474u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d478: 0x1440ffe1  bnez        $v0, . + 4 + (-0x1F << 2)
    ctx->pc = 0x12D478u;
    {
        const bool branch_taken_0x12d478 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12D47Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D478u;
            // 0x12d47c: 0x3c0382d  daddu       $a3, $fp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12d478) {
            ctx->pc = 0x12D400u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12d400;
        }
    }
    ctx->pc = 0x12D480u;
    // 0x12d480: 0x8e43002c  lw          $v1, 0x2C($s2)
    ctx->pc = 0x12d480u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 44)));
    // 0x12d484: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x12d484u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d488: 0x8fa20020  lw          $v0, 0x20($sp)
    ctx->pc = 0x12d488u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12d48c: 0x731821  addu        $v1, $v1, $s3
    ctx->pc = 0x12d48cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 19)));
    // 0x12d490: 0x8e450030  lw          $a1, 0x30($s2)
    ctx->pc = 0x12d490u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 48)));
    // 0x12d494: 0xae43002c  sw          $v1, 0x2C($s2)
    ctx->pc = 0x12d494u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 44), GPR_U32(ctx, 3));
    // 0x12d498: 0x8e470034  lw          $a3, 0x34($s2)
    ctx->pc = 0x12d498u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 52)));
    // 0x12d49c: 0xa22821  addu        $a1, $a1, $v0
    ctx->pc = 0x12d49cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x12d4a0: 0x8fa30020  lw          $v1, 0x20($sp)
    ctx->pc = 0x12d4a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12d4a4: 0x8e460040  lw          $a2, 0x40($s2)
    ctx->pc = 0x12d4a4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 64)));
    // 0x12d4a8: 0xf33821  addu        $a3, $a3, $s3
    ctx->pc = 0x12d4a8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 19)));
    // 0x12d4ac: 0x8e420044  lw          $v0, 0x44($s2)
    ctx->pc = 0x12d4acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 68)));
    // 0x12d4b0: 0xd33021  addu        $a2, $a2, $s3
    ctx->pc = 0x12d4b0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x12d4b4: 0xae450030  sw          $a1, 0x30($s2)
    ctx->pc = 0x12d4b4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 48), GPR_U32(ctx, 5));
    // 0x12d4b8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x12d4b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x12d4bc: 0xae470034  sw          $a3, 0x34($s2)
    ctx->pc = 0x12d4bcu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 52), GPR_U32(ctx, 7));
    // 0x12d4c0: 0xae420044  sw          $v0, 0x44($s2)
    ctx->pc = 0x12d4c0u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 68), GPR_U32(ctx, 2));
    // 0x12d4c4: 0xc04949e  jal         func_125278
    ctx->pc = 0x12D4C4u;
    SET_GPR_U32(ctx, 31, 0x12D4CCu);
    ctx->pc = 0x12D4C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D4C4u;
            // 0x12d4c8: 0xae460040  sw          $a2, 0x40($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 64), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x125278u;
    if (runtime->hasFunction(0x125278u)) {
        auto targetFn = runtime->lookupFunction(0x125278u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D4CCu; }
        if (ctx->pc != 0x12D4CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00125278_0x125278(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D4CCu; }
        if (ctx->pc != 0x12D4CCu) { return; }
    }
    ctx->pc = 0x12D4CCu;
label_12d4cc:
    // 0x12d4cc: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x12d4ccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12d4d0: 0xdfb10038  ld          $s1, 0x38($sp)
    ctx->pc = 0x12d4d0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x12d4d4: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x12d4d4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x12d4d8: 0xdfb30048  ld          $s3, 0x48($sp)
    ctx->pc = 0x12d4d8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x12d4dc: 0xdfb40050  ld          $s4, 0x50($sp)
    ctx->pc = 0x12d4dcu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x12d4e0: 0xdfb50058  ld          $s5, 0x58($sp)
    ctx->pc = 0x12d4e0u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x12d4e4: 0xdfb60060  ld          $s6, 0x60($sp)
    ctx->pc = 0x12d4e4u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x12d4e8: 0xdfb70068  ld          $s7, 0x68($sp)
    ctx->pc = 0x12d4e8u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x12d4ec: 0xdfbe0070  ld          $fp, 0x70($sp)
    ctx->pc = 0x12d4ecu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x12d4f0: 0xdfbf0078  ld          $ra, 0x78($sp)
    ctx->pc = 0x12d4f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 120)));
    // 0x12d4f4: 0x3e00008  jr          $ra
    ctx->pc = 0x12D4F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12D4F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D4F4u;
            // 0x12d4f8: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12D338u: goto label_12d338;
            case 0x12D384u: goto label_12d384;
            case 0x12D390u: goto label_12d390;
            case 0x12D39Cu: goto label_12d39c;
            case 0x12D3C8u: goto label_12d3c8;
            case 0x12D3E0u: goto label_12d3e0;
            case 0x12D3F8u: goto label_12d3f8;
            case 0x12D400u: goto label_12d400;
            case 0x12D408u: goto label_12d408;
            case 0x12D428u: goto label_12d428;
            case 0x12D444u: goto label_12d444;
            case 0x12D460u: goto label_12d460;
            case 0x12D468u: goto label_12d468;
            case 0x12D4CCu: goto label_12d4cc;
            case 0x12D500u: goto label_12d500;
            case 0x12D528u: goto label_12d528;
            case 0x12D534u: goto label_12d534;
            case 0x12D540u: goto label_12d540;
            case 0x12D5B0u: goto label_12d5b0;
            case 0x12D5C0u: goto label_12d5c0;
            case 0x12D5C8u: goto label_12d5c8;
            case 0x12D5D0u: goto label_12d5d0;
            case 0x12D5E4u: goto label_12d5e4;
            case 0x12D60Cu: goto label_12d60c;
            case 0x12D628u: goto label_12d628;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12D4FCu;
    // 0x12d4fc: 0x0  nop
    ctx->pc = 0x12d4fcu;
    // NOP
label_12d500:
    // 0x12d500: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x12d500u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x12d504: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12d504u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12d508: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x12d508u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12d50c: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x12d50cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d510: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x12d510u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x12d514: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x12d514u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x12d518: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12d518u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12d51c: 0x8e510004  lw          $s1, 0x4($s2)
    ctx->pc = 0x12d51cu;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x12d520: 0xc0493be  jal         func_124EF8
    ctx->pc = 0x12D520u;
    SET_GPR_U32(ctx, 31, 0x12D528u);
    ctx->pc = 0x12D524u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D520u;
            // 0x12d524: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124EF8u;
    if (runtime->hasFunction(0x124EF8u)) {
        auto targetFn = runtime->lookupFunction(0x124EF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D528u; }
        if (ctx->pc != 0x12D528u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00124EF8_0x124ef8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D528u; }
        if (ctx->pc != 0x12D528u) { return; }
    }
    ctx->pc = 0x12D528u;
label_12d528:
    // 0x12d528: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x12d528u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d52c: 0xc0494ae  jal         func_1252B8
    ctx->pc = 0x12D52Cu;
    SET_GPR_U32(ctx, 31, 0x12D534u);
    ctx->pc = 0x12D530u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D52Cu;
            // 0x12d530: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1252B8u;
    if (runtime->hasFunction(0x1252B8u)) {
        auto targetFn = runtime->lookupFunction(0x1252B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D534u; }
        if (ctx->pc != 0x12D534u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001252B8_0x1252b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D534u; }
        if (ctx->pc != 0x12D534u) { return; }
    }
    ctx->pc = 0x12D534u;
label_12d534:
    // 0x12d534: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x12d534u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d538: 0xc0494b0  jal         func_1252C0
    ctx->pc = 0x12D538u;
    SET_GPR_U32(ctx, 31, 0x12D540u);
    ctx->pc = 0x12D53Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D538u;
            // 0x12d53c: 0x40982d  daddu       $s3, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1252C0u;
    if (runtime->hasFunction(0x1252C0u)) {
        auto targetFn = runtime->lookupFunction(0x1252C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D540u; }
        if (ctx->pc != 0x12D540u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001252C0_0x1252c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D540u; }
        if (ctx->pc != 0x12D540u) { return; }
    }
    ctx->pc = 0x12D540u;
label_12d540:
    // 0x12d540: 0x8e440034  lw          $a0, 0x34($s2)
    ctx->pc = 0x12d540u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 52)));
    // 0x12d544: 0x8e46002c  lw          $a2, 0x2C($s2)
    ctx->pc = 0x12d544u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 44)));
    // 0x12d548: 0x2048023  subu        $s0, $s0, $a0
    ctx->pc = 0x12d548u;
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 4)));
    // 0x12d54c: 0x8e450030  lw          $a1, 0x30($s2)
    ctx->pc = 0x12d54cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 48)));
    // 0x12d550: 0x50182a  slt         $v1, $v0, $s0
    ctx->pc = 0x12d550u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x12d554: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12d554u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12d558: 0x43800b  movn        $s0, $v0, $v1
    ctx->pc = 0x12d558u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 2));
    // 0x12d55c: 0xb32821  addu        $a1, $a1, $s3
    ctx->pc = 0x12d55cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 19)));
    // 0x12d560: 0x902021  addu        $a0, $a0, $s0
    ctx->pc = 0x12d560u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 16)));
    // 0x12d564: 0xd03021  addu        $a2, $a2, $s0
    ctx->pc = 0x12d564u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 16)));
    // 0x12d568: 0xae440034  sw          $a0, 0x34($s2)
    ctx->pc = 0x12d568u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 52), GPR_U32(ctx, 4));
    // 0x12d56c: 0xae46002c  sw          $a2, 0x2C($s2)
    ctx->pc = 0x12d56cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 44), GPR_U32(ctx, 6));
    // 0x12d570: 0xae450030  sw          $a1, 0x30($s2)
    ctx->pc = 0x12d570u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 48), GPR_U32(ctx, 5));
    // 0x12d574: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12d574u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12d578: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x12d578u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12d57c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x12d57cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12d580: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x12d580u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12d584: 0x3e00008  jr          $ra
    ctx->pc = 0x12D584u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12D588u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D584u;
            // 0x12d588: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12D338u: goto label_12d338;
            case 0x12D384u: goto label_12d384;
            case 0x12D390u: goto label_12d390;
            case 0x12D39Cu: goto label_12d39c;
            case 0x12D3C8u: goto label_12d3c8;
            case 0x12D3E0u: goto label_12d3e0;
            case 0x12D3F8u: goto label_12d3f8;
            case 0x12D400u: goto label_12d400;
            case 0x12D408u: goto label_12d408;
            case 0x12D428u: goto label_12d428;
            case 0x12D444u: goto label_12d444;
            case 0x12D460u: goto label_12d460;
            case 0x12D468u: goto label_12d468;
            case 0x12D4CCu: goto label_12d4cc;
            case 0x12D500u: goto label_12d500;
            case 0x12D528u: goto label_12d528;
            case 0x12D534u: goto label_12d534;
            case 0x12D540u: goto label_12d540;
            case 0x12D5B0u: goto label_12d5b0;
            case 0x12D5C0u: goto label_12d5c0;
            case 0x12D5C8u: goto label_12d5c8;
            case 0x12D5D0u: goto label_12d5d0;
            case 0x12D5E4u: goto label_12d5e4;
            case 0x12D60Cu: goto label_12d60c;
            case 0x12D628u: goto label_12d628;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12D58Cu;
    // 0x12d58c: 0x0  nop
    ctx->pc = 0x12d58cu;
    // NOP
    // 0x12d590: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x12d590u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x12d594: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12d594u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12d598: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x12d598u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d59c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12d59cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12d5a0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x12d5a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x12d5a4: 0x8e300004  lw          $s0, 0x4($s1)
    ctx->pc = 0x12d5a4u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x12d5a8: 0xc049468  jal         func_1251A0
    ctx->pc = 0x12D5A8u;
    SET_GPR_U32(ctx, 31, 0x12D5B0u);
    ctx->pc = 0x12D5ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D5A8u;
            // 0x12d5ac: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1251A0u;
    if (runtime->hasFunction(0x1251A0u)) {
        auto targetFn = runtime->lookupFunction(0x1251A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D5B0u; }
        if (ctx->pc != 0x12D5B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001251A0_0x1251a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D5B0u; }
        if (ctx->pc != 0x12D5B0u) { return; }
    }
    ctx->pc = 0x12D5B0u;
label_12d5b0:
    // 0x12d5b0: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x12D5B0u;
    {
        const bool branch_taken_0x12d5b0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12D5B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D5B0u;
            // 0x12d5b4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12d5b0) {
            ctx->pc = 0x12D5C0u;
            goto label_12d5c0;
        }
    }
    ctx->pc = 0x12D5B8u;
    // 0x12d5b8: 0xc04b3f6  jal         func_12CFD8
    ctx->pc = 0x12D5B8u;
    SET_GPR_U32(ctx, 31, 0x12D5C0u);
    ctx->pc = 0x12CFD8u;
    if (runtime->hasFunction(0x12CFD8u)) {
        auto targetFn = runtime->lookupFunction(0x12CFD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D5C0u; }
        if (ctx->pc != 0x12D5C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012CFD8_0x12cfd8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D5C0u; }
        if (ctx->pc != 0x12D5C0u) { return; }
    }
    ctx->pc = 0x12D5C0u;
label_12d5c0:
    // 0x12d5c0: 0xc0495da  jal         func_125768
    ctx->pc = 0x12D5C0u;
    SET_GPR_U32(ctx, 31, 0x12D5C8u);
    ctx->pc = 0x12D5C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D5C0u;
            // 0x12d5c4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x125768u;
    if (runtime->hasFunction(0x125768u)) {
        auto targetFn = runtime->lookupFunction(0x125768u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D5C8u; }
        if (ctx->pc != 0x12D5C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00125768_0x125768(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D5C8u; }
        if (ctx->pc != 0x12D5C8u) { return; }
    }
    ctx->pc = 0x12D5C8u;
label_12d5c8:
    // 0x12d5c8: 0xc049468  jal         func_1251A0
    ctx->pc = 0x12D5C8u;
    SET_GPR_U32(ctx, 31, 0x12D5D0u);
    ctx->pc = 0x12D5CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D5C8u;
            // 0x12d5cc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1251A0u;
    if (runtime->hasFunction(0x1251A0u)) {
        auto targetFn = runtime->lookupFunction(0x1251A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D5D0u; }
        if (ctx->pc != 0x12D5D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001251A0_0x1251a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D5D0u; }
        if (ctx->pc != 0x12D5D0u) { return; }
    }
    ctx->pc = 0x12D5D0u;
label_12d5d0:
    // 0x12d5d0: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x12d5d0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x12d5d4: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x12D5D4u;
    {
        const bool branch_taken_0x12d5d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x12D5D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D5D4u;
            // 0x12d5d8: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12d5d4) {
            ctx->pc = 0x12D5E4u;
            goto label_12d5e4;
        }
    }
    ctx->pc = 0x12D5DCu;
    // 0x12d5dc: 0xc04b4ce  jal         func_12D338
    ctx->pc = 0x12D5DCu;
    SET_GPR_U32(ctx, 31, 0x12D5E4u);
    ctx->pc = 0x12D338u;
    goto label_12d338;
    ctx->pc = 0x12D5E4u;
label_12d5e4:
    // 0x12d5e4: 0x86040098  lh          $a0, 0x98($s0)
    ctx->pc = 0x12d5e4u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 152)));
    // 0x12d5e8: 0x2402000a  addiu       $v0, $zero, 0xA
    ctx->pc = 0x12d5e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x12d5ec: 0x10820007  beq         $a0, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x12D5ECu;
    {
        const bool branch_taken_0x12d5ec = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x12D5F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D5ECu;
            // 0x12d5f0: 0x24020014  addiu       $v0, $zero, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12d5ec) {
            ctx->pc = 0x12D60Cu;
            goto label_12d60c;
        }
    }
    ctx->pc = 0x12D5F4u;
    // 0x12d5f4: 0x10820005  beq         $a0, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x12D5F4u;
    {
        const bool branch_taken_0x12d5f4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x12D5F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D5F4u;
            // 0x12d5f8: 0x2402000b  addiu       $v0, $zero, 0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12d5f4) {
            ctx->pc = 0x12D60Cu;
            goto label_12d60c;
        }
    }
    ctx->pc = 0x12D5FCu;
    // 0x12d5fc: 0x10820003  beq         $a0, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x12D5FCu;
    {
        const bool branch_taken_0x12d5fc = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x12D600u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D5FCu;
            // 0x12d600: 0x2402000f  addiu       $v0, $zero, 0xF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12d5fc) {
            ctx->pc = 0x12D60Cu;
            goto label_12d60c;
        }
    }
    ctx->pc = 0x12D604u;
    // 0x12d604: 0x14820008  bne         $a0, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x12D604u;
    {
        const bool branch_taken_0x12d604 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        ctx->pc = 0x12D608u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D604u;
            // 0x12d608: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12d604) {
            ctx->pc = 0x12D628u;
            goto label_12d628;
        }
    }
    ctx->pc = 0x12D60Cu;
label_12d60c:
    // 0x12d60c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x12d60cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d610: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12d610u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12d614: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12d614u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12d618: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x12d618u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12d61c: 0x804b540  j           func_12D500
    ctx->pc = 0x12D61Cu;
    ctx->pc = 0x12D620u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D61Cu;
            // 0x12d620: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12D500u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_12d500;
    ctx->pc = 0x12D624u;
    // 0x12d624: 0x0  nop
    ctx->pc = 0x12d624u;
    // NOP
label_12d628:
    // 0x12d628: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12d628u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12d62c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x12d62cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12d630: 0x3e00008  jr          $ra
    ctx->pc = 0x12D630u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12D634u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D630u;
            // 0x12d634: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12D338u: goto label_12d338;
            case 0x12D384u: goto label_12d384;
            case 0x12D390u: goto label_12d390;
            case 0x12D39Cu: goto label_12d39c;
            case 0x12D3C8u: goto label_12d3c8;
            case 0x12D3E0u: goto label_12d3e0;
            case 0x12D3F8u: goto label_12d3f8;
            case 0x12D400u: goto label_12d400;
            case 0x12D408u: goto label_12d408;
            case 0x12D428u: goto label_12d428;
            case 0x12D444u: goto label_12d444;
            case 0x12D460u: goto label_12d460;
            case 0x12D468u: goto label_12d468;
            case 0x12D4CCu: goto label_12d4cc;
            case 0x12D500u: goto label_12d500;
            case 0x12D528u: goto label_12d528;
            case 0x12D534u: goto label_12d534;
            case 0x12D540u: goto label_12d540;
            case 0x12D5B0u: goto label_12d5b0;
            case 0x12D5C0u: goto label_12d5c0;
            case 0x12D5C8u: goto label_12d5c8;
            case 0x12D5D0u: goto label_12d5d0;
            case 0x12D5E4u: goto label_12d5e4;
            case 0x12D60Cu: goto label_12d60c;
            case 0x12D628u: goto label_12d628;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12D638u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
