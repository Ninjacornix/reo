#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B90C0
// Address: 0x1b90c0 - 0x1b91d4
void sub_001B90C0_0x1b90c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B90C0_0x1b90c0");
#endif

    switch (ctx->pc) {
        case 0x1b90f4u: goto label_1b90f4;
        case 0x1b916cu: goto label_1b916c;
        case 0x1b9198u: goto label_1b9198;
        case 0x1b91c0u: goto label_1b91c0;
        default: break;
    }

    ctx->pc = 0x1b90c0u;

    // 0x1b90c0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1b90c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1b90c4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1b90c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1b90c8: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b90c8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b90cc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b90ccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b90d0: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1b90d0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b90d4: 0x12000012  beqz        $s0, . + 4 + (0x12 << 2)
    ctx->pc = 0x1B90D4u;
    {
        const bool branch_taken_0x1b90d4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B90D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B90D4u;
            // 0x1b90d8: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b90d4) {
            ctx->pc = 0x1B9120u;
            goto label_1b9120;
        }
    }
    ctx->pc = 0x1B90DCu;
    // 0x1b90dc: 0x92240c7c  lbu         $a0, 0xC7C($s1)
    ctx->pc = 0x1b90dcu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 3196)));
    // 0x1b90e0: 0x240300ff  addiu       $v1, $zero, 0xFF
    ctx->pc = 0x1b90e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1b90e4: 0x10830036  beq         $a0, $v1, . + 4 + (0x36 << 2)
    ctx->pc = 0x1B90E4u;
    {
        const bool branch_taken_0x1b90e4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1b90e4) {
            ctx->pc = 0x1B91C0u;
            goto label_1b91c0;
        }
    }
    ctx->pc = 0x1B90ECu;
    // 0x1b90ec: 0xc16d338  jal         func_5B4CE0
    ctx->pc = 0x1B90ECu;
    SET_GPR_U32(ctx, 31, 0x1B90F4u);
    ctx->pc = 0x1B90F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B90ECu;
            // 0x1b90f0: 0x308400ff  andi        $a0, $a0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
    ctx->pc = 0x5B4CE0u;
    {
        auto targetFn = runtime->lookupFunction(0x5B4CE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B90F4u; }
        if (ctx->pc != 0x1B90F4u) { return; }
    }
    ctx->pc = 0x1B90F4u;
label_1b90f4:
    // 0x1b90f4: 0x2263c  dsll32      $a0, $v0, 24
    ctx->pc = 0x1b90f4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (32 + 24));
    // 0x1b90f8: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1b90f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1b90fc: 0x4263f  dsra32      $a0, $a0, 24
    ctx->pc = 0x1b90fcu;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 24));
    // 0x1b9100: 0x1083002f  beq         $a0, $v1, . + 4 + (0x2F << 2)
    ctx->pc = 0x1B9100u;
    {
        const bool branch_taken_0x1b9100 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1B9104u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9100u;
            // 0x1b9104: 0x3c030023  lui         $v1, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9100) {
            ctx->pc = 0x1B91C0u;
            goto label_1b91c0;
        }
    }
    ctx->pc = 0x1B9108u;
    // 0x1b9108: 0x24634c20  addiu       $v1, $v1, 0x4C20
    ctx->pc = 0x1b9108u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 19488));
    // 0x1b910c: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1b910cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1b9110: 0x90700000  lbu         $s0, 0x0($v1)
    ctx->pc = 0x1b9110u;
    SET_GPR_U32(ctx, 16, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1b9114: 0x2a010004  slti        $at, $s0, 0x4
    ctx->pc = 0x1b9114u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1b9118: 0x10200029  beqz        $at, . + 4 + (0x29 << 2)
    ctx->pc = 0x1B9118u;
    {
        const bool branch_taken_0x1b9118 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b9118) {
            ctx->pc = 0x1B91C0u;
            goto label_1b91c0;
        }
    }
    ctx->pc = 0x1B9120u;
label_1b9120:
    // 0x1b9120: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b9120u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b9124: 0x3c03004a  lui         $v1, 0x4A
    ctx->pc = 0x1b9124u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)74 << 16));
    // 0x1b9128: 0x9026aded  lbu         $a2, -0x5213($at)
    ctx->pc = 0x1b9128u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294946285)));
    // 0x1b912c: 0x24635e12  addiu       $v1, $v1, 0x5E12
    ctx->pc = 0x1b912cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 24082));
    // 0x1b9130: 0x962401e2  lhu         $a0, 0x1E2($s1)
    ctx->pc = 0x1b9130u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 482)));
    // 0x1b9134: 0x62900  sll         $a1, $a2, 4
    ctx->pc = 0x1b9134u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 6), 4));
    // 0x1b9138: 0xa63023  subu        $a2, $a1, $a2
    ctx->pc = 0x1b9138u;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0x1b913c: 0x628c0  sll         $a1, $a2, 3
    ctx->pc = 0x1b913cu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 6), 3));
    // 0x1b9140: 0xc52821  addu        $a1, $a2, $a1
    ctx->pc = 0x1b9140u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x1b9144: 0x53140  sll         $a2, $a1, 5
    ctx->pc = 0x1b9144u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 5), 5));
    // 0x1b9148: 0x661821  addu        $v1, $v1, $a2
    ctx->pc = 0x1b9148u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x1b914c: 0x94630000  lhu         $v1, 0x0($v1)
    ctx->pc = 0x1b914cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1b9150: 0x1083001b  beq         $a0, $v1, . + 4 + (0x1B << 2)
    ctx->pc = 0x1B9150u;
    {
        const bool branch_taken_0x1b9150 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1b9150) {
            ctx->pc = 0x1B91C0u;
            goto label_1b91c0;
        }
    }
    ctx->pc = 0x1B9158u;
    // 0x1b9158: 0x3c02004a  lui         $v0, 0x4A
    ctx->pc = 0x1b9158u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)74 << 16));
    // 0x1b915c: 0x26250038  addiu       $a1, $s1, 0x38
    ctx->pc = 0x1b915cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 56));
    // 0x1b9160: 0x24425c30  addiu       $v0, $v0, 0x5C30
    ctx->pc = 0x1b9160u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 23600));
    // 0x1b9164: 0xc199770  jal         func_665DC0
    ctx->pc = 0x1B9164u;
    SET_GPR_U32(ctx, 31, 0x1B916Cu);
    ctx->pc = 0x1B9168u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9164u;
            // 0x1b9168: 0x462021  addu        $a0, $v0, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x665DC0u;
    {
        auto targetFn = runtime->lookupFunction(0x665DC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B916Cu; }
        if (ctx->pc != 0x1B916Cu) { return; }
    }
    ctx->pc = 0x1B916Cu;
label_1b916c:
    // 0x1b916c: 0x3c0344fa  lui         $v1, 0x44FA
    ctx->pc = 0x1b916cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)17658 << 16));
    // 0x1b9170: 0x44830800  mtc1        $v1, $f1
    ctx->pc = 0x1b9170u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1b9174: 0x0  nop
    ctx->pc = 0x1b9174u;
    // NOP
    // 0x1b9178: 0x46000834  c.lt.s      $f1, $f0
    ctx->pc = 0x1b9178u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1b917c: 0x45010010  bc1t        . + 4 + (0x10 << 2)
    ctx->pc = 0x1B917Cu;
    {
        const bool branch_taken_0x1b917c = ((ctx->fcr31 & 0x800000));
        ctx->pc = 0x1B9180u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B917Cu;
            // 0x1b9180: 0x3c010023  lui         $at, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b917c) {
            ctx->pc = 0x1B91C0u;
            goto label_1b91c0;
        }
    }
    ctx->pc = 0x1B9184u;
    // 0x1b9184: 0x26240038  addiu       $a0, $s1, 0x38
    ctx->pc = 0x1b9184u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 56));
    // 0x1b9188: 0x8c254c08  lw          $a1, 0x4C08($at)
    ctx->pc = 0x1b9188u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 19464)));
    // 0x1b918c: 0x27a60038  addiu       $a2, $sp, 0x38
    ctx->pc = 0x1b918cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
    // 0x1b9190: 0xc06e52c  jal         func_1B94B0
    ctx->pc = 0x1B9190u;
    SET_GPR_U32(ctx, 31, 0x1B9198u);
    ctx->pc = 0x1B9194u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9190u;
            // 0x1b9194: 0x27a7003c  addiu       $a3, $sp, 0x3C (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 60));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B94B0u;
    if (runtime->hasFunction(0x1B94B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B94B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9198u; }
        if (ctx->pc != 0x1B9198u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B94B0_0x1b94b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9198u; }
        if (ctx->pc != 0x1B9198u) { return; }
    }
    ctx->pc = 0x1B9198u;
label_1b9198:
    // 0x1b9198: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1B9198u;
    {
        const bool branch_taken_0x1b9198 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b9198) {
            ctx->pc = 0x1B91C0u;
            goto label_1b91c0;
        }
    }
    ctx->pc = 0x1B91A0u;
    // 0x1b91a0: 0x8fa70038  lw          $a3, 0x38($sp)
    ctx->pc = 0x1b91a0u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1b91a4: 0x26050004  addiu       $a1, $s0, 0x4
    ctx->pc = 0x1b91a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
    // 0x1b91a8: 0x8fa8003c  lw          $t0, 0x3C($sp)
    ctx->pc = 0x1b91a8u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x1b91ac: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1b91acu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b91b0: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1b91b0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b91b4: 0x2409ffff  addiu       $t1, $zero, -0x1
    ctx->pc = 0x1b91b4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1b91b8: 0xc06b1fc  jal         func_1AC7F0
    ctx->pc = 0x1B91B8u;
    SET_GPR_U32(ctx, 31, 0x1B91C0u);
    ctx->pc = 0x1B91BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B91B8u;
            // 0x1b91bc: 0x502d  daddu       $t2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AC7F0u;
    if (runtime->hasFunction(0x1AC7F0u)) {
        auto targetFn = runtime->lookupFunction(0x1AC7F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B91C0u; }
        if (ctx->pc != 0x1B91C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AC7F0_0x1ac7f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B91C0u; }
        if (ctx->pc != 0x1B91C0u) { return; }
    }
    ctx->pc = 0x1B91C0u;
label_1b91c0:
    // 0x1b91c0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1b91c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b91c4: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b91c4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b91c8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b91c8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b91cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1B91CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B91D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B91CCu;
            // 0x1b91d0: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B90F4u: goto label_1b90f4;
            case 0x1B9120u: goto label_1b9120;
            case 0x1B916Cu: goto label_1b916c;
            case 0x1B9198u: goto label_1b9198;
            case 0x1B91C0u: goto label_1b91c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B91D4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
