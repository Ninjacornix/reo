#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00193030
// Address: 0x193030 - 0x193140
void sub_00193030_0x193030(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00193030_0x193030");
#endif

    switch (ctx->pc) {
        case 0x19304cu: goto label_19304c;
        case 0x19307cu: goto label_19307c;
        case 0x1930a0u: goto label_1930a0;
        case 0x1930acu: goto label_1930ac;
        case 0x1930c0u: goto label_1930c0;
        case 0x1930d4u: goto label_1930d4;
        case 0x19310cu: goto label_19310c;
        case 0x19311cu: goto label_19311c;
        default: break;
    }

    ctx->pc = 0x193030u;

label_193030:
    // 0x193030: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x193030u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x193034: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x193034u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x193038: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x193038u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x19303c: 0xe7b40000  swc1        $f20, 0x0($sp)
    ctx->pc = 0x19303cu;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x193040: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x193040u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193044: 0x46006506  mov.s       $f20, $f12
    ctx->pc = 0x193044u;
    ctx->f[20] = FPU_MOV_S(ctx->f[12]);
    // 0x193048: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x193048u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_19304c:
    // 0x19304c: 0x41080  sll         $v0, $a0, 2
    ctx->pc = 0x19304cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x193050: 0x2021821  addu        $v1, $s0, $v0
    ctx->pc = 0x193050u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x193054: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x193054u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x193058: 0xc46000dc  lwc1        $f0, 0xDC($v1)
    ctx->pc = 0x193058u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 220)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19305c: 0x2882000a  slti        $v0, $a0, 0xA
    ctx->pc = 0x19305cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)10) ? 1 : 0);
    // 0x193060: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x193060u;
    {
        const bool branch_taken_0x193060 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x193064u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193060u;
            // 0x193064: 0xe4600104  swc1        $f0, 0x104($v1) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 260), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x193060) {
            ctx->pc = 0x19304Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19304c;
        }
    }
    ctx->pc = 0x193068u;
    // 0x193068: 0x8e0400d4  lw          $a0, 0xD4($s0)
    ctx->pc = 0x193068u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 212)));
    // 0x19306c: 0x1080000c  beqz        $a0, . + 4 + (0xC << 2)
    ctx->pc = 0x19306Cu;
    {
        const bool branch_taken_0x19306c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x19306c) {
            ctx->pc = 0x1930A0u;
            goto label_1930a0;
        }
    }
    ctx->pc = 0x193074u;
    // 0x193074: 0xc064914  jal         func_192450
    ctx->pc = 0x193074u;
    SET_GPR_U32(ctx, 31, 0x19307Cu);
    ctx->pc = 0x192450u;
    if (runtime->hasFunction(0x192450u)) {
        auto targetFn = runtime->lookupFunction(0x192450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19307Cu; }
        if (ctx->pc != 0x19307Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00192450_0x192450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19307Cu; }
        if (ctx->pc != 0x19307Cu) { return; }
    }
    ctx->pc = 0x19307Cu;
label_19307c:
    // 0x19307c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19307cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x193080: 0x8e0300d8  lw          $v1, 0xD8($s0)
    ctx->pc = 0x193080u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 216)));
    // 0x193084: 0x8c224168  lw          $v0, 0x4168($at)
    ctx->pc = 0x193084u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16744)));
    // 0x193088: 0x260500dc  addiu       $a1, $s0, 0xDC
    ctx->pc = 0x193088u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 220));
    // 0x19308c: 0x26060104  addiu       $a2, $s0, 0x104
    ctx->pc = 0x19308cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 260));
    // 0x193090: 0x2607015c  addiu       $a3, $s0, 0x15C
    ctx->pc = 0x193090u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 348));
    // 0x193094: 0x4600a306  mov.s       $f12, $f20
    ctx->pc = 0x193094u;
    ctx->f[12] = FPU_MOV_S(ctx->f[20]);
    // 0x193098: 0xc064f20  jal         func_193C80
    ctx->pc = 0x193098u;
    SET_GPR_U32(ctx, 31, 0x1930A0u);
    ctx->pc = 0x19309Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193098u;
            // 0x19309c: 0x622021  addu        $a0, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193C80u;
    if (runtime->hasFunction(0x193C80u)) {
        auto targetFn = runtime->lookupFunction(0x193C80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1930A0u; }
        if (ctx->pc != 0x1930A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193C80_0x193c80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1930A0u; }
        if (ctx->pc != 0x1930A0u) { return; }
    }
    ctx->pc = 0x1930A0u;
label_1930a0:
    // 0x1930a0: 0x26040040  addiu       $a0, $s0, 0x40
    ctx->pc = 0x1930a0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 64));
    // 0x1930a4: 0xc064e68  jal         func_1939A0
    ctx->pc = 0x1930A4u;
    SET_GPR_U32(ctx, 31, 0x1930ACu);
    ctx->pc = 0x1930A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1930A4u;
            // 0x1930a8: 0x26050104  addiu       $a1, $s0, 0x104 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 260));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1939A0u;
    if (runtime->hasFunction(0x1939A0u)) {
        auto targetFn = runtime->lookupFunction(0x1939A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1930ACu; }
        if (ctx->pc != 0x1930ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001939A0_0x1939a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1930ACu; }
        if (ctx->pc != 0x1930ACu) { return; }
    }
    ctx->pc = 0x1930ACu;
label_1930ac:
    // 0x1930ac: 0x8e0400d0  lw          $a0, 0xD0($s0)
    ctx->pc = 0x1930acu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 208)));
    // 0x1930b0: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1930B0u;
    {
        const bool branch_taken_0x1930b0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1930B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1930B0u;
            // 0x1930b4: 0x4600a306  mov.s       $f12, $f20 (Delay Slot)
        ctx->f[12] = FPU_MOV_S(ctx->f[20]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1930b0) {
            ctx->pc = 0x1930C0u;
            goto label_1930c0;
        }
    }
    ctx->pc = 0x1930B8u;
    // 0x1930b8: 0xc064c0c  jal         func_193030
    ctx->pc = 0x1930B8u;
    SET_GPR_U32(ctx, 31, 0x1930C0u);
    ctx->pc = 0x193030u;
    goto label_193030;
    ctx->pc = 0x1930C0u;
label_1930c0:
    // 0x1930c0: 0x8e0400cc  lw          $a0, 0xCC($s0)
    ctx->pc = 0x1930c0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 204)));
    // 0x1930c4: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1930C4u;
    {
        const bool branch_taken_0x1930c4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1930C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1930C4u;
            // 0x1930c8: 0x4600a306  mov.s       $f12, $f20 (Delay Slot)
        ctx->f[12] = FPU_MOV_S(ctx->f[20]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1930c4) {
            ctx->pc = 0x1930D4u;
            goto label_1930d4;
        }
    }
    ctx->pc = 0x1930CCu;
    // 0x1930cc: 0xc064c0c  jal         func_193030
    ctx->pc = 0x1930CCu;
    SET_GPR_U32(ctx, 31, 0x1930D4u);
    ctx->pc = 0x193030u;
    goto label_193030;
    ctx->pc = 0x1930D4u;
label_1930d4:
    // 0x1930d4: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1930d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1930d8: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x1930d8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x1930dc: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x1930dcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1930e0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1930e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1930e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1930E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1930E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1930E4u;
            // 0x1930e8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x193030u: goto label_193030;
            case 0x19304Cu: goto label_19304c;
            case 0x19307Cu: goto label_19307c;
            case 0x1930A0u: goto label_1930a0;
            case 0x1930ACu: goto label_1930ac;
            case 0x1930C0u: goto label_1930c0;
            case 0x1930D4u: goto label_1930d4;
            case 0x19310Cu: goto label_19310c;
            case 0x19311Cu: goto label_19311c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1930ECu;
    // 0x1930ec: 0x0  nop
    ctx->pc = 0x1930ecu;
    // NOP
    // 0x1930f0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1930f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1930f4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1930f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1930f8: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x1930f8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x1930fc: 0xe7b40000  swc1        $f20, 0x0($sp)
    ctx->pc = 0x1930fcu;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x193100: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x193100u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193104: 0xc064b44  jal         func_192D10
    ctx->pc = 0x193104u;
    SET_GPR_U32(ctx, 31, 0x19310Cu);
    ctx->pc = 0x193108u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193104u;
            // 0x193108: 0x46006506  mov.s       $f20, $f12 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[12]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x192D10u;
    if (runtime->hasFunction(0x192D10u)) {
        auto targetFn = runtime->lookupFunction(0x192D10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19310Cu; }
        if (ctx->pc != 0x19310Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00192D10_0x192d10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19310Cu; }
        if (ctx->pc != 0x19310Cu) { return; }
    }
    ctx->pc = 0x19310Cu;
label_19310c:
    // 0x19310c: 0x4600a306  mov.s       $f12, $f20
    ctx->pc = 0x19310cu;
    ctx->f[12] = FPU_MOV_S(ctx->f[20]);
    // 0x193110: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x193110u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193114: 0xc064c50  jal         func_193140
    ctx->pc = 0x193114u;
    SET_GPR_U32(ctx, 31, 0x19311Cu);
    ctx->pc = 0x193118u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193114u;
            // 0x193118: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193140u;
    if (runtime->hasFunction(0x193140u)) {
        auto targetFn = runtime->lookupFunction(0x193140u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19311Cu; }
        if (ctx->pc != 0x19311Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193140_0x193140(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19311Cu; }
        if (ctx->pc != 0x19311Cu) { return; }
    }
    ctx->pc = 0x19311Cu;
label_19311c:
    // 0x19311c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x19311cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x193120: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x193120u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x193124: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x193124u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x193128: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x193128u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19312c: 0x3e00008  jr          $ra
    ctx->pc = 0x19312Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x193130u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19312Cu;
            // 0x193130: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x193030u: goto label_193030;
            case 0x19304Cu: goto label_19304c;
            case 0x19307Cu: goto label_19307c;
            case 0x1930A0u: goto label_1930a0;
            case 0x1930ACu: goto label_1930ac;
            case 0x1930C0u: goto label_1930c0;
            case 0x1930D4u: goto label_1930d4;
            case 0x19310Cu: goto label_19310c;
            case 0x19311Cu: goto label_19311c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x193134u;
    // 0x193134: 0x0  nop
    ctx->pc = 0x193134u;
    // NOP
    // 0x193138: 0x0  nop
    ctx->pc = 0x193138u;
    // NOP
    // 0x19313c: 0x0  nop
    ctx->pc = 0x19313cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
