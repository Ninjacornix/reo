#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F3754
// Address: 0x1f3754 - 0x1f3840
void sub_001F3754_0x1f3754(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F3754_0x1f3754");
#endif

    switch (ctx->pc) {
        case 0x1f377cu: goto label_1f377c;
        case 0x1f378cu: goto label_1f378c;
        case 0x1f37b0u: goto label_1f37b0;
        case 0x1f37d4u: goto label_1f37d4;
        case 0x1f37e0u: goto label_1f37e0;
        case 0x1f37f0u: goto label_1f37f0;
        case 0x1f3800u: goto label_1f3800;
        case 0x1f3810u: goto label_1f3810;
        case 0x1f3820u: goto label_1f3820;
        default: break;
    }

    ctx->pc = 0x1f3754u;

    // 0x1f3754: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1f3754u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1f3758: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x1f3758u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1f375c: 0xffbe0018  sd          $fp, 0x18($sp)
    ctx->pc = 0x1f375cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 30));
    // 0x1f3760: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1f3760u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1f3764: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f3764u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3768: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f3768u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f376c: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1f376cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1f3770: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1f3770u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f3774: 0xc07c6cd  jal         func_1F1B34
    ctx->pc = 0x1F3774u;
    SET_GPR_U32(ctx, 31, 0x1F377Cu);
    ctx->pc = 0x1F1B34u;
    if (runtime->hasFunction(0x1F1B34u)) {
        auto targetFn = runtime->lookupFunction(0x1F1B34u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F377Cu; }
        if (ctx->pc != 0x1F377Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1B34_0x1f1b34(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F377Cu; }
        if (ctx->pc != 0x1F377Cu) { return; }
    }
    ctx->pc = 0x1F377Cu;
label_1f377c:
    // 0x1f377c: 0x2450ffd4  addiu       $s0, $v0, -0x2C
    ctx->pc = 0x1f377cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967252));
    // 0x1f3780: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f3780u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f3784: 0xc07c6b6  jal         func_1F1AD8
    ctx->pc = 0x1F3784u;
    SET_GPR_U32(ctx, 31, 0x1F378Cu);
    ctx->pc = 0x1F1AD8u;
    if (runtime->hasFunction(0x1F1AD8u)) {
        auto targetFn = runtime->lookupFunction(0x1F1AD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F378Cu; }
        if (ctx->pc != 0x1F378Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1AD8_0x1f1ad8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F378Cu; }
        if (ctx->pc != 0x1F378Cu) { return; }
    }
    ctx->pc = 0x1F378Cu;
label_1f378c:
    // 0x1f378c: 0x202102b  sltu        $v0, $s0, $v0
    ctx->pc = 0x1f378cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1f3790: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F3790u;
    {
        const bool branch_taken_0x1f3790 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f3790) {
            ctx->pc = 0x1F37A4u;
            goto label_1f37a4;
        }
    }
    ctx->pc = 0x1F3798u;
    // 0x1f3798: 0x2402e0c2  addiu       $v0, $zero, -0x1F3E
    ctx->pc = 0x1f3798u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294959298));
    // 0x1f379c: 0x10000021  b           . + 4 + (0x21 << 2)
    ctx->pc = 0x1F379Cu;
    {
        const bool branch_taken_0x1f379c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f379c) {
            ctx->pc = 0x1F3824u;
            goto label_1f3824;
        }
    }
    ctx->pc = 0x1F37A4u;
label_1f37a4:
    // 0x1f37a4: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f37a4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f37a8: 0xc07c6b6  jal         func_1F1AD8
    ctx->pc = 0x1F37A8u;
    SET_GPR_U32(ctx, 31, 0x1F37B0u);
    ctx->pc = 0x1F1AD8u;
    if (runtime->hasFunction(0x1F1AD8u)) {
        auto targetFn = runtime->lookupFunction(0x1F1AD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F37B0u; }
        if (ctx->pc != 0x1F37B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1AD8_0x1f1ad8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F37B0u; }
        if (ctx->pc != 0x1F37B0u) { return; }
    }
    ctx->pc = 0x1F37B0u;
label_1f37b0:
    // 0x1f37b0: 0x2446001c  addiu       $a2, $v0, 0x1C
    ctx->pc = 0x1f37b0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 28));
    // 0x1f37b4: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f37b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f37b8: 0x24430010  addiu       $v1, $v0, 0x10
    ctx->pc = 0x1f37b8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 16));
    // 0x1f37bc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f37bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f37c0: 0x24420010  addiu       $v0, $v0, 0x10
    ctx->pc = 0x1f37c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 16));
    // 0x1f37c4: 0x60202d  daddu       $a0, $v1, $zero
    ctx->pc = 0x1f37c4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f37c8: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1f37c8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f37cc: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F37CCu;
    SET_GPR_U32(ctx, 31, 0x1F37D4u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F37D4u; }
        if (ctx->pc != 0x1F37D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F37D4u; }
        if (ctx->pc != 0x1F37D4u) { return; }
    }
    ctx->pc = 0x1F37D4u;
label_1f37d4:
    // 0x1f37d4: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f37d4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f37d8: 0xc07c6b6  jal         func_1F1AD8
    ctx->pc = 0x1F37D8u;
    SET_GPR_U32(ctx, 31, 0x1F37E0u);
    ctx->pc = 0x1F1AD8u;
    if (runtime->hasFunction(0x1F1AD8u)) {
        auto targetFn = runtime->lookupFunction(0x1F1AD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F37E0u; }
        if (ctx->pc != 0x1F37E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1AD8_0x1f1ad8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F37E0u; }
        if (ctx->pc != 0x1F37E0u) { return; }
    }
    ctx->pc = 0x1F37E0u;
label_1f37e0:
    // 0x1f37e0: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1f37e0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f37e4: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1f37e4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f37e8: 0xc07c6c0  jal         func_1F1B00
    ctx->pc = 0x1F37E8u;
    SET_GPR_U32(ctx, 31, 0x1F37F0u);
    ctx->pc = 0x1F1B00u;
    if (runtime->hasFunction(0x1F1B00u)) {
        auto targetFn = runtime->lookupFunction(0x1F1B00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F37F0u; }
        if (ctx->pc != 0x1F37F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1B00_0x1f1b00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F37F0u; }
        if (ctx->pc != 0x1F37F0u) { return; }
    }
    ctx->pc = 0x1F37F0u;
label_1f37f0:
    // 0x1f37f0: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1f37f0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f37f4: 0x3405ffff  ori         $a1, $zero, 0xFFFF
    ctx->pc = 0x1f37f4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1f37f8: 0xc07c690  jal         func_1F1A40
    ctx->pc = 0x1F37F8u;
    SET_GPR_U32(ctx, 31, 0x1F3800u);
    ctx->pc = 0x1F1A40u;
    if (runtime->hasFunction(0x1F1A40u)) {
        auto targetFn = runtime->lookupFunction(0x1F1A40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3800u; }
        if (ctx->pc != 0x1F3800u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1A40_0x1f1a40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3800u; }
        if (ctx->pc != 0x1F3800u) { return; }
    }
    ctx->pc = 0x1F3800u;
label_1f3800:
    // 0x1f3800: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f3800u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f3804: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1f3804u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3808: 0xc07c680  jal         func_1F1A00
    ctx->pc = 0x1F3808u;
    SET_GPR_U32(ctx, 31, 0x1F3810u);
    ctx->pc = 0x1F1A00u;
    if (runtime->hasFunction(0x1F1A00u)) {
        auto targetFn = runtime->lookupFunction(0x1F1A00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3810u; }
        if (ctx->pc != 0x1F3810u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1A00_0x1f1a00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3810u; }
        if (ctx->pc != 0x1F3810u) { return; }
    }
    ctx->pc = 0x1F3810u;
label_1f3810:
    // 0x1f3810: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1f3810u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f3814: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1f3814u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3818: 0xc07c680  jal         func_1F1A00
    ctx->pc = 0x1F3818u;
    SET_GPR_U32(ctx, 31, 0x1F3820u);
    ctx->pc = 0x1F1A00u;
    if (runtime->hasFunction(0x1F1A00u)) {
        auto targetFn = runtime->lookupFunction(0x1F1A00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3820u; }
        if (ctx->pc != 0x1F3820u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1A00_0x1f1a00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3820u; }
        if (ctx->pc != 0x1F3820u) { return; }
    }
    ctx->pc = 0x1F3820u;
label_1f3820:
    // 0x1f3820: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f3820u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1f3824:
    // 0x1f3824: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f3824u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3828: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1f3828u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f382c: 0xdfbe0018  ld          $fp, 0x18($sp)
    ctx->pc = 0x1f382cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1f3830: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1f3830u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1f3834: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1f3834u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1f3838: 0x3e00008  jr          $ra
    ctx->pc = 0x1F3838u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F377Cu: goto label_1f377c;
            case 0x1F378Cu: goto label_1f378c;
            case 0x1F37A4u: goto label_1f37a4;
            case 0x1F37B0u: goto label_1f37b0;
            case 0x1F37D4u: goto label_1f37d4;
            case 0x1F37E0u: goto label_1f37e0;
            case 0x1F37F0u: goto label_1f37f0;
            case 0x1F3800u: goto label_1f3800;
            case 0x1F3810u: goto label_1f3810;
            case 0x1F3820u: goto label_1f3820;
            case 0x1F3824u: goto label_1f3824;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F3840u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
