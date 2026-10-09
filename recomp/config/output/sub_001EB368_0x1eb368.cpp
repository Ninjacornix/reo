#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001EB368
// Address: 0x1eb368 - 0x1eb4f8
void sub_001EB368_0x1eb368(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001EB368_0x1eb368");
#endif

    switch (ctx->pc) {
        case 0x1eb398u: goto label_1eb398;
        case 0x1eb3b0u: goto label_1eb3b0;
        case 0x1eb3f4u: goto label_1eb3f4;
        case 0x1eb438u: goto label_1eb438;
        case 0x1eb448u: goto label_1eb448;
        case 0x1eb468u: goto label_1eb468;
        case 0x1eb474u: goto label_1eb474;
        case 0x1eb484u: goto label_1eb484;
        case 0x1eb4dcu: goto label_1eb4dc;
        default: break;
    }

    ctx->pc = 0x1eb368u;

    // 0x1eb368: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1eb368u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1eb36c: 0xffbe0040  sd          $fp, 0x40($sp)
    ctx->pc = 0x1eb36cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 30));
    // 0x1eb370: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x1eb370u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x1eb374: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1eb374u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1eb378: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1eb378u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1eb37c: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1eb37cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1eb380: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1eb380u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1eb384: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1eb384u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1eb388: 0xafc80010  sw          $t0, 0x10($fp)
    ctx->pc = 0x1eb388u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 8));
    // 0x1eb38c: 0x24041048  addiu       $a0, $zero, 0x1048
    ctx->pc = 0x1eb38cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4168));
    // 0x1eb390: 0xc041bb8  jal         func_106EE0
    ctx->pc = 0x1EB390u;
    SET_GPR_U32(ctx, 31, 0x1EB398u);
    ctx->pc = 0x106EE0u;
    if (runtime->hasFunction(0x106EE0u)) {
        auto targetFn = runtime->lookupFunction(0x106EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EB398u; }
        if (ctx->pc != 0x1EB398u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00106EE0_0x106ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EB398u; }
        if (ctx->pc != 0x1EB398u) { return; }
    }
    ctx->pc = 0x1EB398u;
label_1eb398:
    // 0x1eb398: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1eb398u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1eb39c: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1eb39cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1eb3a0: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1eb3a0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1eb3a4: 0x8fc6000c  lw          $a2, 0xC($fp)
    ctx->pc = 0x1eb3a4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1eb3a8: 0xc07ac19  jal         func_1EB064
    ctx->pc = 0x1EB3A8u;
    SET_GPR_U32(ctx, 31, 0x1EB3B0u);
    ctx->pc = 0x1EB064u;
    if (runtime->hasFunction(0x1EB064u)) {
        auto targetFn = runtime->lookupFunction(0x1EB064u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EB3B0u; }
        if (ctx->pc != 0x1EB3B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001EB064_0x1eb064(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EB3B0u; }
        if (ctx->pc != 0x1EB3B0u) { return; }
    }
    ctx->pc = 0x1EB3B0u;
label_1eb3b0:
    // 0x1eb3b0: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1eb3b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1eb3b4: 0x24420007  addiu       $v0, $v0, 0x7
    ctx->pc = 0x1eb3b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 7));
    // 0x1eb3b8: 0xafc20030  sw          $v0, 0x30($fp)
    ctx->pc = 0x1eb3b8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 2));
    // 0x1eb3bc: 0x8fc20030  lw          $v0, 0x30($fp)
    ctx->pc = 0x1eb3bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1eb3c0: 0x4410004  bgez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1EB3C0u;
    {
        const bool branch_taken_0x1eb3c0 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1eb3c0) {
            ctx->pc = 0x1EB3D4u;
            goto label_1eb3d4;
        }
    }
    ctx->pc = 0x1EB3C8u;
    // 0x1eb3c8: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1eb3c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1eb3cc: 0x24630007  addiu       $v1, $v1, 0x7
    ctx->pc = 0x1eb3ccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 7));
    // 0x1eb3d0: 0xafc30030  sw          $v1, 0x30($fp)
    ctx->pc = 0x1eb3d0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 48), GPR_U32(ctx, 3));
label_1eb3d4:
    // 0x1eb3d4: 0x8fc30030  lw          $v1, 0x30($fp)
    ctx->pc = 0x1eb3d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 48)));
    // 0x1eb3d8: 0x310c3  sra         $v0, $v1, 3
    ctx->pc = 0x1eb3d8u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 3));
    // 0x1eb3dc: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1eb3dcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1eb3e0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1eb3e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb3e4: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1eb3e4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1eb3e8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1eb3e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb3ec: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1eb3ecu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1eb3f0: 0xafc0001c  sw          $zero, 0x1C($fp)
    ctx->pc = 0x1eb3f0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 0));
label_1eb3f4:
    // 0x1eb3f4: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1eb3f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1eb3f8: 0x8fc30018  lw          $v1, 0x18($fp)
    ctx->pc = 0x1eb3f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1eb3fc: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x1eb3fcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1eb400: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1EB400u;
    {
        const bool branch_taken_0x1eb400 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1eb400) {
            ctx->pc = 0x1EB410u;
            goto label_1eb410;
        }
    }
    ctx->pc = 0x1EB408u;
    // 0x1eb408: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x1EB408u;
    {
        const bool branch_taken_0x1eb408 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1eb408) {
            ctx->pc = 0x1EB4D0u;
            goto label_1eb4d0;
        }
    }
    ctx->pc = 0x1EB410u;
label_1eb410:
    // 0x1eb410: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1eb410u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1eb414: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1eb414u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1eb418: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1eb418u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1eb41c: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1eb41cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1eb420: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x1eb420u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1eb424: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1eb424u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1eb428: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1eb428u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1eb42c: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1eb42cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1eb430: 0xc07a071  jal         func_1E81C4
    ctx->pc = 0x1EB430u;
    SET_GPR_U32(ctx, 31, 0x1EB438u);
    ctx->pc = 0x1E81C4u;
    if (runtime->hasFunction(0x1E81C4u)) {
        auto targetFn = runtime->lookupFunction(0x1E81C4u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EB438u; }
        if (ctx->pc != 0x1EB438u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E81C4_0x1e81c4(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EB438u; }
        if (ctx->pc != 0x1EB438u) { return; }
    }
    ctx->pc = 0x1EB438u;
label_1eb438:
    // 0x1eb438: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1eb438u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1eb43c: 0x8fc40024  lw          $a0, 0x24($fp)
    ctx->pc = 0x1eb43cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1eb440: 0xc07a071  jal         func_1E81C4
    ctx->pc = 0x1EB440u;
    SET_GPR_U32(ctx, 31, 0x1EB448u);
    ctx->pc = 0x1E81C4u;
    if (runtime->hasFunction(0x1E81C4u)) {
        auto targetFn = runtime->lookupFunction(0x1E81C4u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EB448u; }
        if (ctx->pc != 0x1EB448u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E81C4_0x1e81c4(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EB448u; }
        if (ctx->pc != 0x1EB448u) { return; }
    }
    ctx->pc = 0x1EB448u;
label_1eb448:
    // 0x1eb448: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1eb448u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1eb44c: 0x27c20020  addiu       $v0, $fp, 0x20
    ctx->pc = 0x1eb44cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 32));
    // 0x1eb450: 0x27c30024  addiu       $v1, $fp, 0x24
    ctx->pc = 0x1eb450u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 36));
    // 0x1eb454: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1eb454u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1eb458: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1eb458u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1eb45c: 0x60302d  daddu       $a2, $v1, $zero
    ctx->pc = 0x1eb45cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1eb460: 0xc07abcd  jal         func_1EAF34
    ctx->pc = 0x1EB460u;
    SET_GPR_U32(ctx, 31, 0x1EB468u);
    ctx->pc = 0x1EAF34u;
    if (runtime->hasFunction(0x1EAF34u)) {
        auto targetFn = runtime->lookupFunction(0x1EAF34u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EB468u; }
        if (ctx->pc != 0x1EB468u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001EAF34_0x1eaf34(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EB468u; }
        if (ctx->pc != 0x1EB468u) { return; }
    }
    ctx->pc = 0x1EB468u;
label_1eb468:
    // 0x1eb468: 0x8fc40020  lw          $a0, 0x20($fp)
    ctx->pc = 0x1eb468u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1eb46c: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1EB46Cu;
    SET_GPR_U32(ctx, 31, 0x1EB474u);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EB474u; }
        if (ctx->pc != 0x1EB474u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EB474u; }
        if (ctx->pc != 0x1EB474u) { return; }
    }
    ctx->pc = 0x1EB474u;
label_1eb474:
    // 0x1eb474: 0xafc20020  sw          $v0, 0x20($fp)
    ctx->pc = 0x1eb474u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 32), GPR_U32(ctx, 2));
    // 0x1eb478: 0x8fc40024  lw          $a0, 0x24($fp)
    ctx->pc = 0x1eb478u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1eb47c: 0xc07a04d  jal         func_1E8134
    ctx->pc = 0x1EB47Cu;
    SET_GPR_U32(ctx, 31, 0x1EB484u);
    ctx->pc = 0x1E8134u;
    if (runtime->hasFunction(0x1E8134u)) {
        auto targetFn = runtime->lookupFunction(0x1E8134u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EB484u; }
        if (ctx->pc != 0x1EB484u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8134_0x1e8134(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EB484u; }
        if (ctx->pc != 0x1EB484u) { return; }
    }
    ctx->pc = 0x1EB484u;
label_1eb484:
    // 0x1eb484: 0xafc20024  sw          $v0, 0x24($fp)
    ctx->pc = 0x1eb484u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 36), GPR_U32(ctx, 2));
    // 0x1eb488: 0x8fc3002c  lw          $v1, 0x2C($fp)
    ctx->pc = 0x1eb488u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1eb48c: 0x8fc20020  lw          $v0, 0x20($fp)
    ctx->pc = 0x1eb48cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 32)));
    // 0x1eb490: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1eb490u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1eb494: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1eb494u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1eb498: 0x24430004  addiu       $v1, $v0, 0x4
    ctx->pc = 0x1eb498u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x1eb49c: 0x8fc20024  lw          $v0, 0x24($fp)
    ctx->pc = 0x1eb49cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 36)));
    // 0x1eb4a0: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1eb4a0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1eb4a4: 0x8fc2001c  lw          $v0, 0x1C($fp)
    ctx->pc = 0x1eb4a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 28)));
    // 0x1eb4a8: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1eb4a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1eb4ac: 0xafc2001c  sw          $v0, 0x1C($fp)
    ctx->pc = 0x1eb4acu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 28), GPR_U32(ctx, 2));
    // 0x1eb4b0: 0x8fc20028  lw          $v0, 0x28($fp)
    ctx->pc = 0x1eb4b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 40)));
    // 0x1eb4b4: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1eb4b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1eb4b8: 0xafc20028  sw          $v0, 0x28($fp)
    ctx->pc = 0x1eb4b8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 40), GPR_U32(ctx, 2));
    // 0x1eb4bc: 0x8fc2002c  lw          $v0, 0x2C($fp)
    ctx->pc = 0x1eb4bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 44)));
    // 0x1eb4c0: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1eb4c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1eb4c4: 0xafc2002c  sw          $v0, 0x2C($fp)
    ctx->pc = 0x1eb4c4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 44), GPR_U32(ctx, 2));
    // 0x1eb4c8: 0x1000ffca  b           . + 4 + (-0x36 << 2)
    ctx->pc = 0x1EB4C8u;
    {
        const bool branch_taken_0x1eb4c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1eb4c8) {
            ctx->pc = 0x1EB3F4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1eb3f4;
        }
    }
    ctx->pc = 0x1EB4D0u;
label_1eb4d0:
    // 0x1eb4d0: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1eb4d0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1eb4d4: 0xc041bce  jal         func_106F38
    ctx->pc = 0x1EB4D4u;
    SET_GPR_U32(ctx, 31, 0x1EB4DCu);
    ctx->pc = 0x106F38u;
    if (runtime->hasFunction(0x106F38u)) {
        auto targetFn = runtime->lookupFunction(0x106F38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EB4DCu; }
        if (ctx->pc != 0x1EB4DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00106F38_0x106f38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1EB4DCu; }
        if (ctx->pc != 0x1EB4DCu) { return; }
    }
    ctx->pc = 0x1EB4DCu;
label_1eb4dc:
    // 0x1eb4dc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1eb4dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1eb4e0: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1eb4e0u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1eb4e4: 0xdfbe0040  ld          $fp, 0x40($sp)
    ctx->pc = 0x1eb4e4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1eb4e8: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x1eb4e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1eb4ec: 0x27bd0050  addiu       $sp, $sp, 0x50
    ctx->pc = 0x1eb4ecu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
    // 0x1eb4f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1EB4F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1EB398u: goto label_1eb398;
            case 0x1EB3B0u: goto label_1eb3b0;
            case 0x1EB3D4u: goto label_1eb3d4;
            case 0x1EB3F4u: goto label_1eb3f4;
            case 0x1EB410u: goto label_1eb410;
            case 0x1EB438u: goto label_1eb438;
            case 0x1EB448u: goto label_1eb448;
            case 0x1EB468u: goto label_1eb468;
            case 0x1EB474u: goto label_1eb474;
            case 0x1EB484u: goto label_1eb484;
            case 0x1EB4D0u: goto label_1eb4d0;
            case 0x1EB4DCu: goto label_1eb4dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1EB4F8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
