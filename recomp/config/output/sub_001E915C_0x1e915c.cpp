#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E915C
// Address: 0x1e915c - 0x1e930c
void sub_001E915C_0x1e915c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E915C_0x1e915c");
#endif

    switch (ctx->pc) {
        case 0x1e9184u: goto label_1e9184;
        case 0x1e9194u: goto label_1e9194;
        case 0x1e91acu: goto label_1e91ac;
        case 0x1e91e0u: goto label_1e91e0;
        case 0x1e9204u: goto label_1e9204;
        case 0x1e921cu: goto label_1e921c;
        case 0x1e9264u: goto label_1e9264;
        case 0x1e929cu: goto label_1e929c;
        case 0x1e92d8u: goto label_1e92d8;
        default: break;
    }

    ctx->pc = 0x1e915cu;

    // 0x1e915c: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e915cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e9160: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e9160u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e9164: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e9164u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e9168: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e9168u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e916c: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e916cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e9170: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e9170u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e9174: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e9174u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e9178: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1e9178u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1e917c: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E917Cu;
    SET_GPR_U32(ctx, 31, 0x1E9184u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9184u; }
        if (ctx->pc != 0x1E9184u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9184u; }
        if (ctx->pc != 0x1E9184u) { return; }
    }
    ctx->pc = 0x1E9184u;
label_1e9184:
    // 0x1e9184: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x1e9184u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x1e9188: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e9188u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e918c: 0xc07a216  jal         func_1E8858
    ctx->pc = 0x1E918Cu;
    SET_GPR_U32(ctx, 31, 0x1E9194u);
    ctx->pc = 0x1E8858u;
    if (runtime->hasFunction(0x1E8858u)) {
        auto targetFn = runtime->lookupFunction(0x1E8858u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9194u; }
        if (ctx->pc != 0x1E9194u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E8858_0x1e8858(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9194u; }
        if (ctx->pc != 0x1E9194u) { return; }
    }
    ctx->pc = 0x1E9194u;
label_1e9194:
    // 0x1e9194: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e9194u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e9198: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e9198u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e919c: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E919Cu;
    {
        const bool branch_taken_0x1e919c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e919c) {
            ctx->pc = 0x1E91C4u;
            goto label_1e91c4;
        }
    }
    ctx->pc = 0x1E91A4u;
    // 0x1e91a4: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E91A4u;
    SET_GPR_U32(ctx, 31, 0x1E91ACu);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E91ACu; }
        if (ctx->pc != 0x1E91ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E91ACu; }
        if (ctx->pc != 0x1E91ACu) { return; }
    }
    ctx->pc = 0x1E91ACu;
label_1e91ac:
    // 0x1e91ac: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e91acu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e91b0: 0x2402000e  addiu       $v0, $zero, 0xE
    ctx->pc = 0x1e91b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1e91b4: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e91b4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e91b8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e91b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e91bc: 0x1000004d  b           . + 4 + (0x4D << 2)
    ctx->pc = 0x1E91BCu;
    {
        const bool branch_taken_0x1e91bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e91bc) {
            ctx->pc = 0x1E92F4u;
            goto label_1e92f4;
        }
    }
    ctx->pc = 0x1E91C4u;
label_1e91c4:
    // 0x1e91c4: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e91c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e91c8: 0x94430002  lhu         $v1, 0x2($v0)
    ctx->pc = 0x1e91c8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x1e91cc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e91ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e91d0: 0x10620009  beq         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E91D0u;
    {
        const bool branch_taken_0x1e91d0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e91d0) {
            ctx->pc = 0x1E91F8u;
            goto label_1e91f8;
        }
    }
    ctx->pc = 0x1E91D8u;
    // 0x1e91d8: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E91D8u;
    SET_GPR_U32(ctx, 31, 0x1E91E0u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E91E0u; }
        if (ctx->pc != 0x1E91E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E91E0u; }
        if (ctx->pc != 0x1E91E0u) { return; }
    }
    ctx->pc = 0x1E91E0u;
label_1e91e0:
    // 0x1e91e0: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e91e0u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e91e4: 0x2402006b  addiu       $v0, $zero, 0x6B
    ctx->pc = 0x1e91e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 107));
    // 0x1e91e8: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e91e8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e91ec: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e91ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e91f0: 0x10000040  b           . + 4 + (0x40 << 2)
    ctx->pc = 0x1E91F0u;
    {
        const bool branch_taken_0x1e91f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e91f0) {
            ctx->pc = 0x1E92F4u;
            goto label_1e92f4;
        }
    }
    ctx->pc = 0x1E91F8u;
label_1e91f8:
    // 0x1e91f8: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e91f8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e91fc: 0xc07aa87  jal         func_1EAA1C
    ctx->pc = 0x1E91FCu;
    SET_GPR_U32(ctx, 31, 0x1E9204u);
    ctx->pc = 0x1EAA1Cu;
    if (runtime->hasFunction(0x1EAA1Cu)) {
        auto targetFn = runtime->lookupFunction(0x1EAA1Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9204u; }
        if (ctx->pc != 0x1E9204u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001EAA1C_0x1eaa1c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9204u; }
        if (ctx->pc != 0x1E9204u) { return; }
    }
    ctx->pc = 0x1E9204u;
label_1e9204:
    // 0x1e9204: 0xa7c20014  sh          $v0, 0x14($fp)
    ctx->pc = 0x1e9204u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 20), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e9208: 0x87c20014  lh          $v0, 0x14($fp)
    ctx->pc = 0x1e9208u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e920c: 0x4410009  bgez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E920Cu;
    {
        const bool branch_taken_0x1e920c = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1e920c) {
            ctx->pc = 0x1E9234u;
            goto label_1e9234;
        }
    }
    ctx->pc = 0x1E9214u;
    // 0x1e9214: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E9214u;
    SET_GPR_U32(ctx, 31, 0x1E921Cu);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E921Cu; }
        if (ctx->pc != 0x1E921Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E921Cu; }
        if (ctx->pc != 0x1E921Cu) { return; }
    }
    ctx->pc = 0x1E921Cu;
label_1e921c:
    // 0x1e921c: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e921cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9220: 0x24020009  addiu       $v0, $zero, 0x9
    ctx->pc = 0x1e9220u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1e9224: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e9224u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e9228: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e9228u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e922c: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x1E922Cu;
    {
        const bool branch_taken_0x1e922c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e922c) {
            ctx->pc = 0x1E92F4u;
            goto label_1e92f4;
        }
    }
    ctx->pc = 0x1E9234u;
label_1e9234:
    // 0x1e9234: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e9234u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e9238: 0x94430004  lhu         $v1, 0x4($v0)
    ctx->pc = 0x1e9238u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e923c: 0x24020ff4  addiu       $v0, $zero, 0xFF4
    ctx->pc = 0x1e923cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4084));
    // 0x1e9240: 0x1062000e  beq         $v1, $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1E9240u;
    {
        const bool branch_taken_0x1e9240 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e9240) {
            ctx->pc = 0x1E927Cu;
            goto label_1e927c;
        }
    }
    ctx->pc = 0x1E9248u;
    // 0x1e9248: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e9248u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e924c: 0x94430004  lhu         $v1, 0x4($v0)
    ctx->pc = 0x1e924cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1e9250: 0x2402007f  addiu       $v0, $zero, 0x7F
    ctx->pc = 0x1e9250u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x1e9254: 0x10620009  beq         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E9254u;
    {
        const bool branch_taken_0x1e9254 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1e9254) {
            ctx->pc = 0x1E927Cu;
            goto label_1e927c;
        }
    }
    ctx->pc = 0x1E925Cu;
    // 0x1e925c: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E925Cu;
    SET_GPR_U32(ctx, 31, 0x1E9264u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9264u; }
        if (ctx->pc != 0x1E9264u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9264u; }
        if (ctx->pc != 0x1E9264u) { return; }
    }
    ctx->pc = 0x1E9264u;
label_1e9264:
    // 0x1e9264: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e9264u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9268: 0x24020009  addiu       $v0, $zero, 0x9
    ctx->pc = 0x1e9268u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1e926c: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e926cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e9270: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e9270u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e9274: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x1E9274u;
    {
        const bool branch_taken_0x1e9274 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e9274) {
            ctx->pc = 0x1E92F4u;
            goto label_1e92f4;
        }
    }
    ctx->pc = 0x1E927Cu;
label_1e927c:
    // 0x1e927c: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e927cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e9280: 0x84420000  lh          $v0, 0x0($v0)
    ctx->pc = 0x1e9280u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e9284: 0x87c30008  lh          $v1, 0x8($fp)
    ctx->pc = 0x1e9284u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e9288: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e9288u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e928c: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1e928cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e9290: 0x60302d  daddu       $a2, $v1, $zero
    ctx->pc = 0x1e9290u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9294: 0xc075fa4  jal         func_1D7E90
    ctx->pc = 0x1E9294u;
    SET_GPR_U32(ctx, 31, 0x1E929Cu);
    ctx->pc = 0x1D7E90u;
    if (runtime->hasFunction(0x1D7E90u)) {
        auto targetFn = runtime->lookupFunction(0x1D7E90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E929Cu; }
        if (ctx->pc != 0x1E929Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7E90_0x1d7e90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E929Cu; }
        if (ctx->pc != 0x1E929Cu) { return; }
    }
    ctx->pc = 0x1E929Cu;
label_1e929c:
    // 0x1e929c: 0xa7c20014  sh          $v0, 0x14($fp)
    ctx->pc = 0x1e929cu;
    WRITE16(ADD32(GPR_U32(ctx, 30), 20), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e92a0: 0x87c30014  lh          $v1, 0x14($fp)
    ctx->pc = 0x1e92a0u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e92a4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e92a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e92a8: 0x14620006  bne         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E92A8u;
    {
        const bool branch_taken_0x1e92a8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e92a8) {
            ctx->pc = 0x1E92C4u;
            goto label_1e92c4;
        }
    }
    ctx->pc = 0x1E92B0u;
    // 0x1e92b0: 0x8fc30010  lw          $v1, 0x10($fp)
    ctx->pc = 0x1e92b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e92b4: 0x24020ff2  addiu       $v0, $zero, 0xFF2
    ctx->pc = 0x1e92b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4082));
    // 0x1e92b8: 0xa4620004  sh          $v0, 0x4($v1)
    ctx->pc = 0x1e92b8u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e92bc: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1E92BCu;
    {
        const bool branch_taken_0x1e92bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e92bc) {
            ctx->pc = 0x1E92F0u;
            goto label_1e92f0;
        }
    }
    ctx->pc = 0x1E92C4u;
label_1e92c4:
    // 0x1e92c4: 0x87c20014  lh          $v0, 0x14($fp)
    ctx->pc = 0x1e92c4u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e92c8: 0x4410009  bgez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E92C8u;
    {
        const bool branch_taken_0x1e92c8 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1e92c8) {
            ctx->pc = 0x1E92F0u;
            goto label_1e92f0;
        }
    }
    ctx->pc = 0x1E92D0u;
    // 0x1e92d0: 0xc0413bc  jal         func_104EF0
    ctx->pc = 0x1E92D0u;
    SET_GPR_U32(ctx, 31, 0x1E92D8u);
    ctx->pc = 0x104EF0u;
    if (runtime->hasFunction(0x104EF0u)) {
        auto targetFn = runtime->lookupFunction(0x104EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E92D8u; }
        if (ctx->pc != 0x1E92D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00104EF0_0x104ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E92D8u; }
        if (ctx->pc != 0x1E92D8u) { return; }
    }
    ctx->pc = 0x1E92D8u;
label_1e92d8:
    // 0x1e92d8: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1e92d8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e92dc: 0x2402000e  addiu       $v0, $zero, 0xE
    ctx->pc = 0x1e92dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1e92e0: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1e92e0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1e92e4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e92e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e92e8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1E92E8u;
    {
        const bool branch_taken_0x1e92e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e92e8) {
            ctx->pc = 0x1E92F4u;
            goto label_1e92f4;
        }
    }
    ctx->pc = 0x1E92F0u;
label_1e92f0:
    // 0x1e92f0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e92f0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e92f4:
    // 0x1e92f4: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e92f4u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e92f8: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e92f8u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e92fc: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e92fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e9300: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e9300u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e9304: 0x3e00008  jr          $ra
    ctx->pc = 0x1E9304u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E9184u: goto label_1e9184;
            case 0x1E9194u: goto label_1e9194;
            case 0x1E91ACu: goto label_1e91ac;
            case 0x1E91C4u: goto label_1e91c4;
            case 0x1E91E0u: goto label_1e91e0;
            case 0x1E91F8u: goto label_1e91f8;
            case 0x1E9204u: goto label_1e9204;
            case 0x1E921Cu: goto label_1e921c;
            case 0x1E9234u: goto label_1e9234;
            case 0x1E9264u: goto label_1e9264;
            case 0x1E927Cu: goto label_1e927c;
            case 0x1E929Cu: goto label_1e929c;
            case 0x1E92C4u: goto label_1e92c4;
            case 0x1E92D8u: goto label_1e92d8;
            case 0x1E92F0u: goto label_1e92f0;
            case 0x1E92F4u: goto label_1e92f4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E930Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
