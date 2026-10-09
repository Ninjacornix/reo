#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00193140
// Address: 0x193140 - 0x193240
void sub_00193140_0x193140(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00193140_0x193140");
#endif

    switch (ctx->pc) {
        case 0x193168u: goto label_193168;
        case 0x193178u: goto label_193178;
        case 0x1931c4u: goto label_1931c4;
        case 0x1931d0u: goto label_1931d0;
        case 0x1931e4u: goto label_1931e4;
        case 0x1931f8u: goto label_1931f8;
        default: break;
    }

    ctx->pc = 0x193140u;

label_193140:
    // 0x193140: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x193140u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x193144: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x193144u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x193148: 0x7fb10020  sq          $s1, 0x20($sp)
    ctx->pc = 0x193148u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 17));
    // 0x19314c: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x19314cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x193150: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x193150u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193154: 0xe7b40000  swc1        $f20, 0x0($sp)
    ctx->pc = 0x193154u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x193158: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x193158u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19315c: 0x8c8400d4  lw          $a0, 0xD4($a0)
    ctx->pc = 0x19315cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 212)));
    // 0x193160: 0xc064914  jal         func_192450
    ctx->pc = 0x193160u;
    SET_GPR_U32(ctx, 31, 0x193168u);
    ctx->pc = 0x193164u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193160u;
            // 0x193164: 0x46006506  mov.s       $f20, $f12 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[12]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x192450u;
    if (runtime->hasFunction(0x192450u)) {
        auto targetFn = runtime->lookupFunction(0x192450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193168u; }
        if (ctx->pc != 0x193168u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00192450_0x192450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x193168u; }
        if (ctx->pc != 0x193168u) { return; }
    }
    ctx->pc = 0x193168u;
label_193168:
    // 0x193168: 0x962300c6  lhu         $v1, 0xC6($s1)
    ctx->pc = 0x193168u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 198)));
    // 0x19316c: 0x3202ffff  andi        $v0, $s0, 0xFFFF
    ctx->pc = 0x19316cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)65535);
    // 0x193170: 0x1462001c  bne         $v1, $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x193170u;
    {
        const bool branch_taken_0x193170 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x193174u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193170u;
            // 0x193174: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x193170) {
            ctx->pc = 0x1931E4u;
            goto label_1931e4;
        }
    }
    ctx->pc = 0x193178u;
label_193178:
    // 0x193178: 0x41080  sll         $v0, $a0, 2
    ctx->pc = 0x193178u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x19317c: 0x2221821  addu        $v1, $s1, $v0
    ctx->pc = 0x19317cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x193180: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x193180u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x193184: 0xc46000dc  lwc1        $f0, 0xDC($v1)
    ctx->pc = 0x193184u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 220)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x193188: 0x2882000a  slti        $v0, $a0, 0xA
    ctx->pc = 0x193188u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)10) ? 1 : 0);
    // 0x19318c: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x19318Cu;
    {
        const bool branch_taken_0x19318c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x193190u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19318Cu;
            // 0x193190: 0xe4600104  swc1        $f0, 0x104($v1) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 260), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x19318c) {
            ctx->pc = 0x193178u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_193178;
        }
    }
    ctx->pc = 0x193194u;
    // 0x193194: 0x8e2200d4  lw          $v0, 0xD4($s1)
    ctx->pc = 0x193194u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 212)));
    // 0x193198: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x193198u;
    {
        const bool branch_taken_0x193198 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x19319Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x193198u;
            // 0x19319c: 0x26240040  addiu       $a0, $s1, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 64));
        ctx->in_delay_slot = false;
        if (branch_taken_0x193198) {
            ctx->pc = 0x1931C8u;
            goto label_1931c8;
        }
    }
    ctx->pc = 0x1931A0u;
    // 0x1931a0: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x1931a0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x1931a4: 0x8e2300d8  lw          $v1, 0xD8($s1)
    ctx->pc = 0x1931a4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 216)));
    // 0x1931a8: 0x8c224168  lw          $v0, 0x4168($at)
    ctx->pc = 0x1931a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16744)));
    // 0x1931ac: 0x262500dc  addiu       $a1, $s1, 0xDC
    ctx->pc = 0x1931acu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 220));
    // 0x1931b0: 0x26260104  addiu       $a2, $s1, 0x104
    ctx->pc = 0x1931b0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), 260));
    // 0x1931b4: 0x2627015c  addiu       $a3, $s1, 0x15C
    ctx->pc = 0x1931b4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 17), 348));
    // 0x1931b8: 0x4600a306  mov.s       $f12, $f20
    ctx->pc = 0x1931b8u;
    ctx->f[12] = FPU_MOV_S(ctx->f[20]);
    // 0x1931bc: 0xc064f20  jal         func_193C80
    ctx->pc = 0x1931BCu;
    SET_GPR_U32(ctx, 31, 0x1931C4u);
    ctx->pc = 0x1931C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1931BCu;
            // 0x1931c0: 0x622021  addu        $a0, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193C80u;
    if (runtime->hasFunction(0x193C80u)) {
        auto targetFn = runtime->lookupFunction(0x193C80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1931C4u; }
        if (ctx->pc != 0x1931C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193C80_0x193c80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1931C4u; }
        if (ctx->pc != 0x1931C4u) { return; }
    }
    ctx->pc = 0x1931C4u;
label_1931c4:
    // 0x1931c4: 0x26240040  addiu       $a0, $s1, 0x40
    ctx->pc = 0x1931c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 64));
label_1931c8:
    // 0x1931c8: 0xc064e68  jal         func_1939A0
    ctx->pc = 0x1931C8u;
    SET_GPR_U32(ctx, 31, 0x1931D0u);
    ctx->pc = 0x1931CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1931C8u;
            // 0x1931cc: 0x26250104  addiu       $a1, $s1, 0x104 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 260));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1939A0u;
    if (runtime->hasFunction(0x1939A0u)) {
        auto targetFn = runtime->lookupFunction(0x1939A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1931D0u; }
        if (ctx->pc != 0x1931D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001939A0_0x1939a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1931D0u; }
        if (ctx->pc != 0x1931D0u) { return; }
    }
    ctx->pc = 0x1931D0u;
label_1931d0:
    // 0x1931d0: 0x8e2400d0  lw          $a0, 0xD0($s1)
    ctx->pc = 0x1931d0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 208)));
    // 0x1931d4: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1931D4u;
    {
        const bool branch_taken_0x1931d4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1931D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1931D4u;
            // 0x1931d8: 0x4600a306  mov.s       $f12, $f20 (Delay Slot)
        ctx->f[12] = FPU_MOV_S(ctx->f[20]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1931d4) {
            ctx->pc = 0x1931E4u;
            goto label_1931e4;
        }
    }
    ctx->pc = 0x1931DCu;
    // 0x1931dc: 0xc064c50  jal         func_193140
    ctx->pc = 0x1931DCu;
    SET_GPR_U32(ctx, 31, 0x1931E4u);
    ctx->pc = 0x1931E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1931DCu;
            // 0x1931e0: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193140u;
    goto label_193140;
    ctx->pc = 0x1931E4u;
label_1931e4:
    // 0x1931e4: 0x8e2400cc  lw          $a0, 0xCC($s1)
    ctx->pc = 0x1931e4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 204)));
    // 0x1931e8: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1931E8u;
    {
        const bool branch_taken_0x1931e8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1931ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1931E8u;
            // 0x1931ec: 0x4600a306  mov.s       $f12, $f20 (Delay Slot)
        ctx->f[12] = FPU_MOV_S(ctx->f[20]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1931e8) {
            ctx->pc = 0x1931F8u;
            goto label_1931f8;
        }
    }
    ctx->pc = 0x1931F0u;
    // 0x1931f0: 0xc064c50  jal         func_193140
    ctx->pc = 0x1931F0u;
    SET_GPR_U32(ctx, 31, 0x1931F8u);
    ctx->pc = 0x1931F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1931F0u;
            // 0x1931f4: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193140u;
    goto label_193140;
    ctx->pc = 0x1931F8u;
label_1931f8:
    // 0x1931f8: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1931f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1931fc: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x1931fcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x193200: 0x7bb10020  lq          $s1, 0x20($sp)
    ctx->pc = 0x193200u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x193204: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x193204u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x193208: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x193208u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19320c: 0x3e00008  jr          $ra
    ctx->pc = 0x19320Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x193210u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19320Cu;
            // 0x193210: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x193140u: goto label_193140;
            case 0x193168u: goto label_193168;
            case 0x193178u: goto label_193178;
            case 0x1931C4u: goto label_1931c4;
            case 0x1931C8u: goto label_1931c8;
            case 0x1931D0u: goto label_1931d0;
            case 0x1931E4u: goto label_1931e4;
            case 0x1931F8u: goto label_1931f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x193214u;
    // 0x193214: 0x0  nop
    ctx->pc = 0x193214u;
    // NOP
    // 0x193218: 0x0  nop
    ctx->pc = 0x193218u;
    // NOP
    // 0x19321c: 0x0  nop
    ctx->pc = 0x19321cu;
    // NOP
    // 0x193220: 0x8064c0c  j           func_193030
    ctx->pc = 0x193220u;
    ctx->pc = 0x193030u;
    if (runtime->hasFunction(0x193030u)) {
        auto targetFn = runtime->lookupFunction(0x193030u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00193030_0x193030(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x193228u;
    // 0x193228: 0x0  nop
    ctx->pc = 0x193228u;
    // NOP
    // 0x19322c: 0x0  nop
    ctx->pc = 0x19322cu;
    // NOP
    // 0x193230: 0x8064c3c  j           func_1930F0
    ctx->pc = 0x193230u;
    ctx->pc = 0x1930F0u;
    if (runtime->hasFunction(0x1930F0u)) {
        auto targetFn = runtime->lookupFunction(0x1930F0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001930F0_0x1930f0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x193238u;
    // 0x193238: 0x0  nop
    ctx->pc = 0x193238u;
    // NOP
    // 0x19323c: 0x0  nop
    ctx->pc = 0x19323cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
