#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018B4A0
// Address: 0x18b4a0 - 0x18baa0
void sub_0018B4A0_0x18b4a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018B4A0_0x18b4a0");
#endif

    switch (ctx->pc) {
        case 0x18b510u: goto label_18b510;
        case 0x18b520u: goto label_18b520;
        case 0x18b564u: goto label_18b564;
        case 0x18b5b8u: goto label_18b5b8;
        case 0x18b5dcu: goto label_18b5dc;
        case 0x18b5ecu: goto label_18b5ec;
        case 0x18b6acu: goto label_18b6ac;
        case 0x18b6d0u: goto label_18b6d0;
        case 0x18b6e0u: goto label_18b6e0;
        case 0x18b724u: goto label_18b724;
        case 0x18b87cu: goto label_18b87c;
        case 0x18b8a0u: goto label_18b8a0;
        case 0x18b8b0u: goto label_18b8b0;
        case 0x18b8f4u: goto label_18b8f4;
        case 0x18b8fcu: goto label_18b8fc;
        case 0x18b920u: goto label_18b920;
        case 0x18b930u: goto label_18b930;
        case 0x18b9a8u: goto label_18b9a8;
        case 0x18b9ccu: goto label_18b9cc;
        case 0x18b9dcu: goto label_18b9dc;
        case 0x18ba50u: goto label_18ba50;
        case 0x18ba84u: goto label_18ba84;
        default: break;
    }

    ctx->pc = 0x18b4a0u;

    // 0x18b4a0: 0x740c0  sll         $t0, $a3, 3
    ctx->pc = 0x18b4a0u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x18b4a4: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x18b4a4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x18b4a8: 0x1074021  addu        $t0, $t0, $a3
    ctx->pc = 0x18b4a8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 7)));
    // 0x18b4ac: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x18b4acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x18b4b0: 0x84040  sll         $t0, $t0, 1
    ctx->pc = 0x18b4b0u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x18b4b4: 0x3c030029  lui         $v1, 0x29
    ctx->pc = 0x18b4b4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)41 << 16));
    // 0x18b4b8: 0x1073821  addu        $a3, $t0, $a3
    ctx->pc = 0x18b4b8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 7)));
    // 0x18b4bc: 0x7fb10040  sq          $s1, 0x40($sp)
    ctx->pc = 0x18b4bcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 17));
    // 0x18b4c0: 0x24634340  addiu       $v1, $v1, 0x4340
    ctx->pc = 0x18b4c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 17216));
    // 0x18b4c4: 0x73880  sll         $a3, $a3, 2
    ctx->pc = 0x18b4c4u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 2));
    // 0x18b4c8: 0x2cc10006  sltiu       $at, $a2, 0x6
    ctx->pc = 0x18b4c8u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)6) ? 1 : 0);
    // 0x18b4cc: 0x7fb00030  sq          $s0, 0x30($sp)
    ctx->pc = 0x18b4ccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 16));
    // 0x18b4d0: 0x1020016c  beqz        $at, . + 4 + (0x16C << 2)
    ctx->pc = 0x18B4D0u;
    {
        const bool branch_taken_0x18b4d0 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x18B4D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18B4D0u;
            // 0x18b4d4: 0x678821  addu        $s1, $v1, $a3 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18b4d0) {
            ctx->pc = 0x18BA84u;
            goto label_18ba84;
        }
    }
    ctx->pc = 0x18B4D8u;
    // 0x18b4d8: 0x61880  sll         $v1, $a2, 2
    ctx->pc = 0x18b4d8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x18b4dc: 0x3c060024  lui         $a2, 0x24
    ctx->pc = 0x18b4dcu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
    // 0x18b4e0: 0x24c61bb0  addiu       $a2, $a2, 0x1BB0
    ctx->pc = 0x18b4e0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 7088));
    // 0x18b4e4: 0x661821  addu        $v1, $v1, $a2
    ctx->pc = 0x18b4e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x18b4e8: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x18b4e8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x18b4ec: 0x600008  jr          $v1
    ctx->pc = 0x18B4ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18B4F4u: goto label_18b4f4;
            case 0x18B5C0u: goto label_18b5c0;
            case 0x18B6B4u: goto label_18b6b4;
            case 0x18B884u: goto label_18b884;
            case 0x18B904u: goto label_18b904;
            case 0x18B9B0u: goto label_18b9b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18B4F4u;
label_18b4f4:
    // 0x18b4f4: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x18b4f4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18b4f8: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x18b4f8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18b4fc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x18b4fcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18b500: 0x2405000c  addiu       $a1, $zero, 0xC
    ctx->pc = 0x18b500u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x18b504: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x18b504u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18b508: 0xc0631cc  jal         func_18C730
    ctx->pc = 0x18B508u;
    SET_GPR_U32(ctx, 31, 0x18B510u);
    ctx->pc = 0x18B50Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18B508u;
            // 0x18b50c: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18C730u;
    if (runtime->hasFunction(0x18C730u)) {
        auto targetFn = runtime->lookupFunction(0x18C730u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B510u; }
        if (ctx->pc != 0x18B510u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C730_0x18c730(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B510u; }
        if (ctx->pc != 0x18B510u) { return; }
    }
    ctx->pc = 0x18B510u;
label_18b510:
    // 0x18b510: 0x26040010  addiu       $a0, $s0, 0x10
    ctx->pc = 0x18b510u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
    // 0x18b514: 0x2405000a  addiu       $a1, $zero, 0xA
    ctx->pc = 0x18b514u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x18b518: 0xc063204  jal         func_18C810
    ctx->pc = 0x18B518u;
    SET_GPR_U32(ctx, 31, 0x18B520u);
    ctx->pc = 0x18B51Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18B518u;
            // 0x18b51c: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18C810u;
    if (runtime->hasFunction(0x18C810u)) {
        auto targetFn = runtime->lookupFunction(0x18C810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B520u; }
        if (ctx->pc != 0x18B520u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C810_0x18c810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B520u; }
        if (ctx->pc != 0x18B520u) { return; }
    }
    ctx->pc = 0x18B520u;
label_18b520:
    // 0x18b520: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x18b520u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x18b524: 0x7e000020  sq          $zero, 0x20($s0)
    ctx->pc = 0x18b524u;
    WRITE128(ADD32(GPR_U32(ctx, 16), 32), GPR_VEC(ctx, 0));
    // 0x18b528: 0x2183c  dsll32      $v1, $v0, 0
    ctx->pc = 0x18b528u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 0));
    // 0x18b52c: 0x26050040  addiu       $a1, $s0, 0x40
    ctx->pc = 0x18b52cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 64));
    // 0x18b530: 0x34028006  ori         $v0, $zero, 0x8006
    ctx->pc = 0x18b530u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32774);
    // 0x18b534: 0x26060050  addiu       $a2, $s0, 0x50
    ctx->pc = 0x18b534u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 80));
    // 0x18b538: 0x431825  or          $v1, $v0, $v1
    ctx->pc = 0x18b538u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x18b53c: 0x26070060  addiu       $a3, $s0, 0x60
    ctx->pc = 0x18b53cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 96));
    // 0x18b540: 0x2402000e  addiu       $v0, $zero, 0xE
    ctx->pc = 0x18b540u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x18b544: 0xfe030030  sd          $v1, 0x30($s0)
    ctx->pc = 0x18b544u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 48), GPR_U64(ctx, 3));
    // 0x18b548: 0xae020038  sw          $v0, 0x38($s0)
    ctx->pc = 0x18b548u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 2));
    // 0x18b54c: 0x26080070  addiu       $t0, $s0, 0x70
    ctx->pc = 0x18b54cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 16), 112));
    // 0x18b550: 0xae00003c  sw          $zero, 0x3C($s0)
    ctx->pc = 0x18b550u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 0));
    // 0x18b554: 0x26090080  addiu       $t1, $s0, 0x80
    ctx->pc = 0x18b554u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 16), 128));
    // 0x18b558: 0x8e240044  lw          $a0, 0x44($s1)
    ctx->pc = 0x18b558u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 68)));
    // 0x18b55c: 0xc062f1c  jal         func_18BC70
    ctx->pc = 0x18B55Cu;
    SET_GPR_U32(ctx, 31, 0x18B564u);
    ctx->pc = 0x18B560u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18B55Cu;
            // 0x18b560: 0x260a0090  addiu       $t2, $s0, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 16), 144));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18BC70u;
    if (runtime->hasFunction(0x18BC70u)) {
        auto targetFn = runtime->lookupFunction(0x18BC70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B564u; }
        if (ctx->pc != 0x18B564u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018BC70_0x18bc70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B564u; }
        if (ctx->pc != 0x18B564u) { return; }
    }
    ctx->pc = 0x18B564u;
label_18b564:
    // 0x18b564: 0xc6200004  lwc1        $f0, 0x4($s1)
    ctx->pc = 0x18b564u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18b568: 0x3c024300  lui         $v0, 0x4300
    ctx->pc = 0x18b568u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17152 << 16));
    // 0x18b56c: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x18b56cu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x18b570: 0x260400c0  addiu       $a0, $s0, 0xC0
    ctx->pc = 0x18b570u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 192));
    // 0x18b574: 0xe60000a0  swc1        $f0, 0xA0($s0)
    ctx->pc = 0x18b574u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 160), bits); }
    // 0x18b578: 0xc6200008  lwc1        $f0, 0x8($s1)
    ctx->pc = 0x18b578u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18b57c: 0xe60000a4  swc1        $f0, 0xA4($s0)
    ctx->pc = 0x18b57cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 164), bits); }
    // 0x18b580: 0xc620000c  lwc1        $f0, 0xC($s1)
    ctx->pc = 0x18b580u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18b584: 0xe60000a8  swc1        $f0, 0xA8($s0)
    ctx->pc = 0x18b584u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 168), bits); }
    // 0x18b588: 0xc6200010  lwc1        $f0, 0x10($s1)
    ctx->pc = 0x18b588u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18b58c: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x18b58cu;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x18b590: 0xe60000ac  swc1        $f0, 0xAC($s0)
    ctx->pc = 0x18b590u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 172), bits); }
    // 0x18b594: 0xc6200024  lwc1        $f0, 0x24($s1)
    ctx->pc = 0x18b594u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18b598: 0xe60000b0  swc1        $f0, 0xB0($s0)
    ctx->pc = 0x18b598u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 176), bits); }
    // 0x18b59c: 0xc6200028  lwc1        $f0, 0x28($s1)
    ctx->pc = 0x18b59cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 40)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18b5a0: 0xe60000b4  swc1        $f0, 0xB4($s0)
    ctx->pc = 0x18b5a0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 180), bits); }
    // 0x18b5a4: 0xc620002c  lwc1        $f0, 0x2C($s1)
    ctx->pc = 0x18b5a4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 44)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18b5a8: 0xe60000b8  swc1        $f0, 0xB8($s0)
    ctx->pc = 0x18b5a8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 184), bits); }
    // 0x18b5ac: 0xc6200030  lwc1        $f0, 0x30($s1)
    ctx->pc = 0x18b5acu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18b5b0: 0xc0631fc  jal         func_18C7F0
    ctx->pc = 0x18B5B0u;
    SET_GPR_U32(ctx, 31, 0x18B5B8u);
    ctx->pc = 0x18B5B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18B5B0u;
            // 0x18b5b4: 0xe60000bc  swc1        $f0, 0xBC($s0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 188), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x18C7F0u;
    if (runtime->hasFunction(0x18C7F0u)) {
        auto targetFn = runtime->lookupFunction(0x18C7F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B5B8u; }
        if (ctx->pc != 0x18B5B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C7F0_0x18c7f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B5B8u; }
        if (ctx->pc != 0x18B5B8u) { return; }
    }
    ctx->pc = 0x18B5B8u;
label_18b5b8:
    // 0x18b5b8: 0x10000133  b           . + 4 + (0x133 << 2)
    ctx->pc = 0x18B5B8u;
    {
        const bool branch_taken_0x18b5b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18B5BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18B5B8u;
            // 0x18b5bc: 0xdfbf0050  ld          $ra, 0x50($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18b5b8) {
            ctx->pc = 0x18BA88u;
            goto label_18ba88;
        }
    }
    ctx->pc = 0x18B5C0u;
label_18b5c0:
    // 0x18b5c0: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x18b5c0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18b5c4: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x18b5c4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18b5c8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x18b5c8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18b5cc: 0x2405000c  addiu       $a1, $zero, 0xC
    ctx->pc = 0x18b5ccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x18b5d0: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x18b5d0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18b5d4: 0xc0631cc  jal         func_18C730
    ctx->pc = 0x18B5D4u;
    SET_GPR_U32(ctx, 31, 0x18B5DCu);
    ctx->pc = 0x18B5D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18B5D4u;
            // 0x18b5d8: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18C730u;
    if (runtime->hasFunction(0x18C730u)) {
        auto targetFn = runtime->lookupFunction(0x18C730u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B5DCu; }
        if (ctx->pc != 0x18B5DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C730_0x18c730(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B5DCu; }
        if (ctx->pc != 0x18B5DCu) { return; }
    }
    ctx->pc = 0x18B5DCu;
label_18b5dc:
    // 0x18b5dc: 0x26040010  addiu       $a0, $s0, 0x10
    ctx->pc = 0x18b5dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
    // 0x18b5e0: 0x2405000a  addiu       $a1, $zero, 0xA
    ctx->pc = 0x18b5e0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x18b5e4: 0xc063204  jal         func_18C810
    ctx->pc = 0x18B5E4u;
    SET_GPR_U32(ctx, 31, 0x18B5ECu);
    ctx->pc = 0x18B5E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18B5E4u;
            // 0x18b5e8: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18C810u;
    if (runtime->hasFunction(0x18C810u)) {
        auto targetFn = runtime->lookupFunction(0x18C810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B5ECu; }
        if (ctx->pc != 0x18B5ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C810_0x18c810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B5ECu; }
        if (ctx->pc != 0x18B5ECu) { return; }
    }
    ctx->pc = 0x18B5ECu;
label_18b5ec:
    // 0x18b5ec: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x18b5ecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x18b5f0: 0x7e000020  sq          $zero, 0x20($s0)
    ctx->pc = 0x18b5f0u;
    WRITE128(ADD32(GPR_U32(ctx, 16), 32), GPR_VEC(ctx, 0));
    // 0x18b5f4: 0x2183c  dsll32      $v1, $v0, 0
    ctx->pc = 0x18b5f4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 0));
    // 0x18b5f8: 0x24040006  addiu       $a0, $zero, 0x6
    ctx->pc = 0x18b5f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x18b5fc: 0x34028006  ori         $v0, $zero, 0x8006
    ctx->pc = 0x18b5fcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32774);
    // 0x18b600: 0x24060008  addiu       $a2, $zero, 0x8
    ctx->pc = 0x18b600u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x18b604: 0x431825  or          $v1, $v0, $v1
    ctx->pc = 0x18b604u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x18b608: 0x24050034  addiu       $a1, $zero, 0x34
    ctx->pc = 0x18b608u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 52));
    // 0x18b60c: 0xfe030030  sd          $v1, 0x30($s0)
    ctx->pc = 0x18b60cu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 48), GPR_U64(ctx, 3));
    // 0x18b610: 0x2402000e  addiu       $v0, $zero, 0xE
    ctx->pc = 0x18b610u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x18b614: 0xae020038  sw          $v0, 0x38($s0)
    ctx->pc = 0x18b614u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 2));
    // 0x18b618: 0x2403003b  addiu       $v1, $zero, 0x3B
    ctx->pc = 0x18b618u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 59));
    // 0x18b61c: 0xae00003c  sw          $zero, 0x3C($s0)
    ctx->pc = 0x18b61cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 0));
    // 0x18b620: 0x24020014  addiu       $v0, $zero, 0x14
    ctx->pc = 0x18b620u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x18b624: 0xfe000040  sd          $zero, 0x40($s0)
    ctx->pc = 0x18b624u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 64), GPR_U64(ctx, 0));
    // 0x18b628: 0xfe030048  sd          $v1, 0x48($s0)
    ctx->pc = 0x18b628u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 72), GPR_U64(ctx, 3));
    // 0x18b62c: 0xfe000050  sd          $zero, 0x50($s0)
    ctx->pc = 0x18b62cu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 80), GPR_U64(ctx, 0));
    // 0x18b630: 0x24030036  addiu       $v1, $zero, 0x36
    ctx->pc = 0x18b630u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 54));
    // 0x18b634: 0xfe020058  sd          $v0, 0x58($s0)
    ctx->pc = 0x18b634u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 88), GPR_U64(ctx, 2));
    // 0x18b638: 0xfe000060  sd          $zero, 0x60($s0)
    ctx->pc = 0x18b638u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 96), GPR_U64(ctx, 0));
    // 0x18b63c: 0x3c024300  lui         $v0, 0x4300
    ctx->pc = 0x18b63cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17152 << 16));
    // 0x18b640: 0xfe040068  sd          $a0, 0x68($s0)
    ctx->pc = 0x18b640u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 104), GPR_U64(ctx, 4));
    // 0x18b644: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x18b644u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x18b648: 0xfe000070  sd          $zero, 0x70($s0)
    ctx->pc = 0x18b648u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 112), GPR_U64(ctx, 0));
    // 0x18b64c: 0x260400c0  addiu       $a0, $s0, 0xC0
    ctx->pc = 0x18b64cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 192));
    // 0x18b650: 0xfe060078  sd          $a2, 0x78($s0)
    ctx->pc = 0x18b650u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 120), GPR_U64(ctx, 6));
    // 0x18b654: 0xfe000080  sd          $zero, 0x80($s0)
    ctx->pc = 0x18b654u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 128), GPR_U64(ctx, 0));
    // 0x18b658: 0xfe050088  sd          $a1, 0x88($s0)
    ctx->pc = 0x18b658u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 136), GPR_U64(ctx, 5));
    // 0x18b65c: 0xfe000090  sd          $zero, 0x90($s0)
    ctx->pc = 0x18b65cu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 144), GPR_U64(ctx, 0));
    // 0x18b660: 0xfe030098  sd          $v1, 0x98($s0)
    ctx->pc = 0x18b660u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 152), GPR_U64(ctx, 3));
    // 0x18b664: 0xc6200004  lwc1        $f0, 0x4($s1)
    ctx->pc = 0x18b664u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18b668: 0xe60000a0  swc1        $f0, 0xA0($s0)
    ctx->pc = 0x18b668u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 160), bits); }
    // 0x18b66c: 0xc6200008  lwc1        $f0, 0x8($s1)
    ctx->pc = 0x18b66cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18b670: 0xe60000a4  swc1        $f0, 0xA4($s0)
    ctx->pc = 0x18b670u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 164), bits); }
    // 0x18b674: 0xc620000c  lwc1        $f0, 0xC($s1)
    ctx->pc = 0x18b674u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18b678: 0xe60000a8  swc1        $f0, 0xA8($s0)
    ctx->pc = 0x18b678u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 168), bits); }
    // 0x18b67c: 0xc6200010  lwc1        $f0, 0x10($s1)
    ctx->pc = 0x18b67cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18b680: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x18b680u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x18b684: 0xe60000ac  swc1        $f0, 0xAC($s0)
    ctx->pc = 0x18b684u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 172), bits); }
    // 0x18b688: 0xc6200024  lwc1        $f0, 0x24($s1)
    ctx->pc = 0x18b688u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18b68c: 0xe60000b0  swc1        $f0, 0xB0($s0)
    ctx->pc = 0x18b68cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 176), bits); }
    // 0x18b690: 0xc6200028  lwc1        $f0, 0x28($s1)
    ctx->pc = 0x18b690u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 40)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18b694: 0xe60000b4  swc1        $f0, 0xB4($s0)
    ctx->pc = 0x18b694u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 180), bits); }
    // 0x18b698: 0xc620002c  lwc1        $f0, 0x2C($s1)
    ctx->pc = 0x18b698u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 44)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18b69c: 0xe60000b8  swc1        $f0, 0xB8($s0)
    ctx->pc = 0x18b69cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 184), bits); }
    // 0x18b6a0: 0xc6200030  lwc1        $f0, 0x30($s1)
    ctx->pc = 0x18b6a0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18b6a4: 0xc0631fc  jal         func_18C7F0
    ctx->pc = 0x18B6A4u;
    SET_GPR_U32(ctx, 31, 0x18B6ACu);
    ctx->pc = 0x18B6A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18B6A4u;
            // 0x18b6a8: 0xe60000bc  swc1        $f0, 0xBC($s0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 188), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x18C7F0u;
    if (runtime->hasFunction(0x18C7F0u)) {
        auto targetFn = runtime->lookupFunction(0x18C7F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B6ACu; }
        if (ctx->pc != 0x18B6ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C7F0_0x18c7f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B6ACu; }
        if (ctx->pc != 0x18B6ACu) { return; }
    }
    ctx->pc = 0x18B6ACu;
label_18b6ac:
    // 0x18b6ac: 0x100000f5  b           . + 4 + (0xF5 << 2)
    ctx->pc = 0x18B6ACu;
    {
        const bool branch_taken_0x18b6ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x18b6ac) {
            ctx->pc = 0x18BA84u;
            goto label_18ba84;
        }
    }
    ctx->pc = 0x18B6B4u;
label_18b6b4:
    // 0x18b6b4: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x18b6b4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18b6b8: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x18b6b8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18b6bc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x18b6bcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18b6c0: 0x2405000e  addiu       $a1, $zero, 0xE
    ctx->pc = 0x18b6c0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x18b6c4: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x18b6c4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18b6c8: 0xc0631cc  jal         func_18C730
    ctx->pc = 0x18B6C8u;
    SET_GPR_U32(ctx, 31, 0x18B6D0u);
    ctx->pc = 0x18B6CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18B6C8u;
            // 0x18b6cc: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18C730u;
    if (runtime->hasFunction(0x18C730u)) {
        auto targetFn = runtime->lookupFunction(0x18C730u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B6D0u; }
        if (ctx->pc != 0x18B6D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C730_0x18c730(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B6D0u; }
        if (ctx->pc != 0x18B6D0u) { return; }
    }
    ctx->pc = 0x18B6D0u;
label_18b6d0:
    // 0x18b6d0: 0x26040010  addiu       $a0, $s0, 0x10
    ctx->pc = 0x18b6d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
    // 0x18b6d4: 0x2405000c  addiu       $a1, $zero, 0xC
    ctx->pc = 0x18b6d4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x18b6d8: 0xc063204  jal         func_18C810
    ctx->pc = 0x18B6D8u;
    SET_GPR_U32(ctx, 31, 0x18B6E0u);
    ctx->pc = 0x18B6DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18B6D8u;
            // 0x18b6dc: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18C810u;
    if (runtime->hasFunction(0x18C810u)) {
        auto targetFn = runtime->lookupFunction(0x18C810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B6E0u; }
        if (ctx->pc != 0x18B6E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C810_0x18c810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B6E0u; }
        if (ctx->pc != 0x18B6E0u) { return; }
    }
    ctx->pc = 0x18B6E0u;
label_18b6e0:
    // 0x18b6e0: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x18b6e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x18b6e4: 0x7e000020  sq          $zero, 0x20($s0)
    ctx->pc = 0x18b6e4u;
    WRITE128(ADD32(GPR_U32(ctx, 16), 32), GPR_VEC(ctx, 0));
    // 0x18b6e8: 0x2183c  dsll32      $v1, $v0, 0
    ctx->pc = 0x18b6e8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 0));
    // 0x18b6ec: 0x26050040  addiu       $a1, $s0, 0x40
    ctx->pc = 0x18b6ecu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 64));
    // 0x18b6f0: 0x34028006  ori         $v0, $zero, 0x8006
    ctx->pc = 0x18b6f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32774);
    // 0x18b6f4: 0x26060050  addiu       $a2, $s0, 0x50
    ctx->pc = 0x18b6f4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 80));
    // 0x18b6f8: 0x431825  or          $v1, $v0, $v1
    ctx->pc = 0x18b6f8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x18b6fc: 0x26070060  addiu       $a3, $s0, 0x60
    ctx->pc = 0x18b6fcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 96));
    // 0x18b700: 0x2402000e  addiu       $v0, $zero, 0xE
    ctx->pc = 0x18b700u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x18b704: 0xfe030030  sd          $v1, 0x30($s0)
    ctx->pc = 0x18b704u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 48), GPR_U64(ctx, 3));
    // 0x18b708: 0xae020038  sw          $v0, 0x38($s0)
    ctx->pc = 0x18b708u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 2));
    // 0x18b70c: 0x26080070  addiu       $t0, $s0, 0x70
    ctx->pc = 0x18b70cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 16), 112));
    // 0x18b710: 0xae00003c  sw          $zero, 0x3C($s0)
    ctx->pc = 0x18b710u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 0));
    // 0x18b714: 0x26090080  addiu       $t1, $s0, 0x80
    ctx->pc = 0x18b714u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 16), 128));
    // 0x18b718: 0x8e240044  lw          $a0, 0x44($s1)
    ctx->pc = 0x18b718u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 68)));
    // 0x18b71c: 0xc062f1c  jal         func_18BC70
    ctx->pc = 0x18B71Cu;
    SET_GPR_U32(ctx, 31, 0x18B724u);
    ctx->pc = 0x18B720u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18B71Cu;
            // 0x18b720: 0x260a0090  addiu       $t2, $s0, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 16), 144));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18BC70u;
    if (runtime->hasFunction(0x18BC70u)) {
        auto targetFn = runtime->lookupFunction(0x18BC70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B724u; }
        if (ctx->pc != 0x18B724u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018BC70_0x18bc70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B724u; }
        if (ctx->pc != 0x18B724u) { return; }
    }
    ctx->pc = 0x18B724u;
label_18b724:
    // 0x18b724: 0xc6200004  lwc1        $f0, 0x4($s1)
    ctx->pc = 0x18b724u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18b728: 0x3c024300  lui         $v0, 0x4300
    ctx->pc = 0x18b728u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17152 << 16));
    // 0x18b72c: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x18b72cu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x18b730: 0x24020100  addiu       $v0, $zero, 0x100
    ctx->pc = 0x18b730u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x18b734: 0xe60000a0  swc1        $f0, 0xA0($s0)
    ctx->pc = 0x18b734u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 160), bits); }
    // 0x18b738: 0xc6200008  lwc1        $f0, 0x8($s1)
    ctx->pc = 0x18b738u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18b73c: 0xe60000a4  swc1        $f0, 0xA4($s0)
    ctx->pc = 0x18b73cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 164), bits); }
    // 0x18b740: 0xc620000c  lwc1        $f0, 0xC($s1)
    ctx->pc = 0x18b740u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18b744: 0xe60000a8  swc1        $f0, 0xA8($s0)
    ctx->pc = 0x18b744u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 168), bits); }
    // 0x18b748: 0xc6200010  lwc1        $f0, 0x10($s1)
    ctx->pc = 0x18b748u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18b74c: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x18b74cu;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x18b750: 0xe60000ac  swc1        $f0, 0xAC($s0)
    ctx->pc = 0x18b750u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 172), bits); }
    // 0x18b754: 0xc6200024  lwc1        $f0, 0x24($s1)
    ctx->pc = 0x18b754u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18b758: 0xe60000b0  swc1        $f0, 0xB0($s0)
    ctx->pc = 0x18b758u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 176), bits); }
    // 0x18b75c: 0xc6200028  lwc1        $f0, 0x28($s1)
    ctx->pc = 0x18b75cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 40)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18b760: 0xe60000b4  swc1        $f0, 0xB4($s0)
    ctx->pc = 0x18b760u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 180), bits); }
    // 0x18b764: 0xc620002c  lwc1        $f0, 0x2C($s1)
    ctx->pc = 0x18b764u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 44)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18b768: 0xe60000b8  swc1        $f0, 0xB8($s0)
    ctx->pc = 0x18b768u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 184), bits); }
    // 0x18b76c: 0xc6200030  lwc1        $f0, 0x30($s1)
    ctx->pc = 0x18b76cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18b770: 0xe60000bc  swc1        $f0, 0xBC($s0)
    ctx->pc = 0x18b770u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 188), bits); }
    // 0x18b774: 0xc6200014  lwc1        $f0, 0x14($s1)
    ctx->pc = 0x18b774u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 20)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18b778: 0xe60000c0  swc1        $f0, 0xC0($s0)
    ctx->pc = 0x18b778u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 192), bits); }
    // 0x18b77c: 0xc6200018  lwc1        $f0, 0x18($s1)
    ctx->pc = 0x18b77cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 24)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18b780: 0xe60000c4  swc1        $f0, 0xC4($s0)
    ctx->pc = 0x18b780u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 196), bits); }
    // 0x18b784: 0xc620001c  lwc1        $f0, 0x1C($s1)
    ctx->pc = 0x18b784u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 28)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18b788: 0xe60000c8  swc1        $f0, 0xC8($s0)
    ctx->pc = 0x18b788u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 200), bits); }
    // 0x18b78c: 0xc6200020  lwc1        $f0, 0x20($s1)
    ctx->pc = 0x18b78cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 32)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18b790: 0xe60000cc  swc1        $f0, 0xCC($s0)
    ctx->pc = 0x18b790u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 204), bits); }
    // 0x18b794: 0x8e230048  lw          $v1, 0x48($s1)
    ctx->pc = 0x18b794u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 72)));
    // 0x18b798: 0x1062002e  beq         $v1, $v0, . + 4 + (0x2E << 2)
    ctx->pc = 0x18B798u;
    {
        const bool branch_taken_0x18b798 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x18B79Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18B798u;
            // 0x18b79c: 0x24020080  addiu       $v0, $zero, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18b798) {
            ctx->pc = 0x18B854u;
            goto label_18b854;
        }
    }
    ctx->pc = 0x18B7A0u;
    // 0x18b7a0: 0x10620029  beq         $v1, $v0, . + 4 + (0x29 << 2)
    ctx->pc = 0x18B7A0u;
    {
        const bool branch_taken_0x18b7a0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x18b7a0) {
            ctx->pc = 0x18B848u;
            goto label_18b848;
        }
    }
    ctx->pc = 0x18B7A8u;
    // 0x18b7a8: 0x24020040  addiu       $v0, $zero, 0x40
    ctx->pc = 0x18b7a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x18b7ac: 0x10620023  beq         $v1, $v0, . + 4 + (0x23 << 2)
    ctx->pc = 0x18B7ACu;
    {
        const bool branch_taken_0x18b7ac = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x18B7B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18B7ACu;
            // 0x18b7b0: 0x24020020  addiu       $v0, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18b7ac) {
            ctx->pc = 0x18B83Cu;
            goto label_18b83c;
        }
    }
    ctx->pc = 0x18B7B4u;
    // 0x18b7b4: 0x1062001e  beq         $v1, $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x18B7B4u;
    {
        const bool branch_taken_0x18b7b4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x18b7b4) {
            ctx->pc = 0x18B830u;
            goto label_18b830;
        }
    }
    ctx->pc = 0x18B7BCu;
    // 0x18b7bc: 0x24020010  addiu       $v0, $zero, 0x10
    ctx->pc = 0x18b7bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x18b7c0: 0x10620018  beq         $v1, $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x18B7C0u;
    {
        const bool branch_taken_0x18b7c0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x18B7C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18B7C0u;
            // 0x18b7c4: 0x24020008  addiu       $v0, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18b7c0) {
            ctx->pc = 0x18B824u;
            goto label_18b824;
        }
    }
    ctx->pc = 0x18B7C8u;
    // 0x18b7c8: 0x10620013  beq         $v1, $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x18B7C8u;
    {
        const bool branch_taken_0x18b7c8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x18b7c8) {
            ctx->pc = 0x18B818u;
            goto label_18b818;
        }
    }
    ctx->pc = 0x18B7D0u;
    // 0x18b7d0: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x18b7d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x18b7d4: 0x1062000d  beq         $v1, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x18B7D4u;
    {
        const bool branch_taken_0x18b7d4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x18B7D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18B7D4u;
            // 0x18b7d8: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18b7d4) {
            ctx->pc = 0x18B80Cu;
            goto label_18b80c;
        }
    }
    ctx->pc = 0x18B7DCu;
    // 0x18b7dc: 0x10620008  beq         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x18B7DCu;
    {
        const bool branch_taken_0x18b7dc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x18b7dc) {
            ctx->pc = 0x18B800u;
            goto label_18b800;
        }
    }
    ctx->pc = 0x18B7E4u;
    // 0x18b7e4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x18b7e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18b7e8: 0x10620005  beq         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x18B7E8u;
    {
        const bool branch_taken_0x18b7e8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x18b7e8) {
            ctx->pc = 0x18B800u;
            goto label_18b800;
        }
    }
    ctx->pc = 0x18B7F0u;
    // 0x18b7f0: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x18B7F0u;
    {
        const bool branch_taken_0x18b7f0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x18b7f0) {
            ctx->pc = 0x18B800u;
            goto label_18b800;
        }
    }
    ctx->pc = 0x18B7F8u;
    // 0x18b7f8: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x18B7F8u;
    {
        const bool branch_taken_0x18b7f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18B7FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18B7F8u;
            // 0x18b7fc: 0x2463ffff  addiu       $v1, $v1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18b7f8) {
            ctx->pc = 0x18B860u;
            goto label_18b860;
        }
    }
    ctx->pc = 0x18B800u;
label_18b800:
    // 0x18b800: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x18b800u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18b804: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x18B804u;
    {
        const bool branch_taken_0x18b804 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18B808u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18B804u;
            // 0x18b808: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18b804) {
            ctx->pc = 0x18B864u;
            goto label_18b864;
        }
    }
    ctx->pc = 0x18B80Cu;
label_18b80c:
    // 0x18b80c: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x18b80cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x18b810: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x18B810u;
    {
        const bool branch_taken_0x18b810 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18B814u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18B810u;
            // 0x18b814: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18b810) {
            ctx->pc = 0x18B864u;
            goto label_18b864;
        }
    }
    ctx->pc = 0x18B818u;
label_18b818:
    // 0x18b818: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x18b818u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x18b81c: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x18B81Cu;
    {
        const bool branch_taken_0x18b81c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18B820u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18B81Cu;
            // 0x18b820: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18b81c) {
            ctx->pc = 0x18B864u;
            goto label_18b864;
        }
    }
    ctx->pc = 0x18B824u;
label_18b824:
    // 0x18b824: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x18b824u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x18b828: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x18B828u;
    {
        const bool branch_taken_0x18b828 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18B82Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18B828u;
            // 0x18b82c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18b828) {
            ctx->pc = 0x18B864u;
            goto label_18b864;
        }
    }
    ctx->pc = 0x18B830u;
label_18b830:
    // 0x18b830: 0x24030005  addiu       $v1, $zero, 0x5
    ctx->pc = 0x18b830u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x18b834: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x18B834u;
    {
        const bool branch_taken_0x18b834 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18B838u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18B834u;
            // 0x18b838: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18b834) {
            ctx->pc = 0x18B864u;
            goto label_18b864;
        }
    }
    ctx->pc = 0x18B83Cu;
label_18b83c:
    // 0x18b83c: 0x24030006  addiu       $v1, $zero, 0x6
    ctx->pc = 0x18b83cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x18b840: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x18B840u;
    {
        const bool branch_taken_0x18b840 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18B844u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18B840u;
            // 0x18b844: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18b840) {
            ctx->pc = 0x18B864u;
            goto label_18b864;
        }
    }
    ctx->pc = 0x18B848u;
label_18b848:
    // 0x18b848: 0x24030007  addiu       $v1, $zero, 0x7
    ctx->pc = 0x18b848u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x18b84c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x18B84Cu;
    {
        const bool branch_taken_0x18b84c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18B850u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18B84Cu;
            // 0x18b850: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18b84c) {
            ctx->pc = 0x18B864u;
            goto label_18b864;
        }
    }
    ctx->pc = 0x18B854u;
label_18b854:
    // 0x18b854: 0x24030008  addiu       $v1, $zero, 0x8
    ctx->pc = 0x18b854u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x18b858: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x18B858u;
    {
        const bool branch_taken_0x18b858 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18B85Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18B858u;
            // 0x18b85c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18b858) {
            ctx->pc = 0x18B864u;
            goto label_18b864;
        }
    }
    ctx->pc = 0x18B860u;
label_18b860:
    // 0x18b860: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x18b860u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_18b864:
    // 0x18b864: 0xae0300d0  sw          $v1, 0xD0($s0)
    ctx->pc = 0x18b864u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 208), GPR_U32(ctx, 3));
    // 0x18b868: 0x260400e0  addiu       $a0, $s0, 0xE0
    ctx->pc = 0x18b868u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 224));
    // 0x18b86c: 0xae0200d4  sw          $v0, 0xD4($s0)
    ctx->pc = 0x18b86cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 212), GPR_U32(ctx, 2));
    // 0x18b870: 0xae0000d8  sw          $zero, 0xD8($s0)
    ctx->pc = 0x18b870u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 216), GPR_U32(ctx, 0));
    // 0x18b874: 0xc0631fc  jal         func_18C7F0
    ctx->pc = 0x18B874u;
    SET_GPR_U32(ctx, 31, 0x18B87Cu);
    ctx->pc = 0x18B878u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18B874u;
            // 0x18b878: 0xae0000dc  sw          $zero, 0xDC($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 220), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18C7F0u;
    if (runtime->hasFunction(0x18C7F0u)) {
        auto targetFn = runtime->lookupFunction(0x18C7F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B87Cu; }
        if (ctx->pc != 0x18B87Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C7F0_0x18c7f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B87Cu; }
        if (ctx->pc != 0x18B87Cu) { return; }
    }
    ctx->pc = 0x18B87Cu;
label_18b87c:
    // 0x18b87c: 0x10000081  b           . + 4 + (0x81 << 2)
    ctx->pc = 0x18B87Cu;
    {
        const bool branch_taken_0x18b87c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x18b87c) {
            ctx->pc = 0x18BA84u;
            goto label_18ba84;
        }
    }
    ctx->pc = 0x18B884u;
label_18b884:
    // 0x18b884: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x18b884u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18b888: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x18b888u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18b88c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x18b88cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18b890: 0x2405000a  addiu       $a1, $zero, 0xA
    ctx->pc = 0x18b890u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x18b894: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x18b894u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18b898: 0xc0631cc  jal         func_18C730
    ctx->pc = 0x18B898u;
    SET_GPR_U32(ctx, 31, 0x18B8A0u);
    ctx->pc = 0x18B89Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18B898u;
            // 0x18b89c: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18C730u;
    if (runtime->hasFunction(0x18C730u)) {
        auto targetFn = runtime->lookupFunction(0x18C730u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B8A0u; }
        if (ctx->pc != 0x18B8A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C730_0x18c730(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B8A0u; }
        if (ctx->pc != 0x18B8A0u) { return; }
    }
    ctx->pc = 0x18B8A0u;
label_18b8a0:
    // 0x18b8a0: 0x26040010  addiu       $a0, $s0, 0x10
    ctx->pc = 0x18b8a0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
    // 0x18b8a4: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x18b8a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x18b8a8: 0xc063204  jal         func_18C810
    ctx->pc = 0x18B8A8u;
    SET_GPR_U32(ctx, 31, 0x18B8B0u);
    ctx->pc = 0x18B8ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18B8A8u;
            // 0x18b8ac: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18C810u;
    if (runtime->hasFunction(0x18C810u)) {
        auto targetFn = runtime->lookupFunction(0x18C810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B8B0u; }
        if (ctx->pc != 0x18B8B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C810_0x18c810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B8B0u; }
        if (ctx->pc != 0x18B8B0u) { return; }
    }
    ctx->pc = 0x18B8B0u;
label_18b8b0:
    // 0x18b8b0: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x18b8b0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x18b8b4: 0x7e000020  sq          $zero, 0x20($s0)
    ctx->pc = 0x18b8b4u;
    WRITE128(ADD32(GPR_U32(ctx, 16), 32), GPR_VEC(ctx, 0));
    // 0x18b8b8: 0x2183c  dsll32      $v1, $v0, 0
    ctx->pc = 0x18b8b8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 0));
    // 0x18b8bc: 0x26050040  addiu       $a1, $s0, 0x40
    ctx->pc = 0x18b8bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 64));
    // 0x18b8c0: 0x34028006  ori         $v0, $zero, 0x8006
    ctx->pc = 0x18b8c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32774);
    // 0x18b8c4: 0x26060050  addiu       $a2, $s0, 0x50
    ctx->pc = 0x18b8c4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 80));
    // 0x18b8c8: 0x431825  or          $v1, $v0, $v1
    ctx->pc = 0x18b8c8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x18b8cc: 0x26070060  addiu       $a3, $s0, 0x60
    ctx->pc = 0x18b8ccu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 96));
    // 0x18b8d0: 0x2402000e  addiu       $v0, $zero, 0xE
    ctx->pc = 0x18b8d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x18b8d4: 0xfe030030  sd          $v1, 0x30($s0)
    ctx->pc = 0x18b8d4u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 48), GPR_U64(ctx, 3));
    // 0x18b8d8: 0xae020038  sw          $v0, 0x38($s0)
    ctx->pc = 0x18b8d8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 2));
    // 0x18b8dc: 0x26080070  addiu       $t0, $s0, 0x70
    ctx->pc = 0x18b8dcu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 16), 112));
    // 0x18b8e0: 0xae00003c  sw          $zero, 0x3C($s0)
    ctx->pc = 0x18b8e0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 0));
    // 0x18b8e4: 0x26090080  addiu       $t1, $s0, 0x80
    ctx->pc = 0x18b8e4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 16), 128));
    // 0x18b8e8: 0x8e240044  lw          $a0, 0x44($s1)
    ctx->pc = 0x18b8e8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 68)));
    // 0x18b8ec: 0xc062f1c  jal         func_18BC70
    ctx->pc = 0x18B8ECu;
    SET_GPR_U32(ctx, 31, 0x18B8F4u);
    ctx->pc = 0x18B8F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18B8ECu;
            // 0x18b8f0: 0x260a0090  addiu       $t2, $s0, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 16), 144));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18BC70u;
    if (runtime->hasFunction(0x18BC70u)) {
        auto targetFn = runtime->lookupFunction(0x18BC70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B8F4u; }
        if (ctx->pc != 0x18B8F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018BC70_0x18bc70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B8F4u; }
        if (ctx->pc != 0x18B8F4u) { return; }
    }
    ctx->pc = 0x18B8F4u;
label_18b8f4:
    // 0x18b8f4: 0xc0631fc  jal         func_18C7F0
    ctx->pc = 0x18B8F4u;
    SET_GPR_U32(ctx, 31, 0x18B8FCu);
    ctx->pc = 0x18B8F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18B8F4u;
            // 0x18b8f8: 0x260400a0  addiu       $a0, $s0, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 160));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18C7F0u;
    if (runtime->hasFunction(0x18C7F0u)) {
        auto targetFn = runtime->lookupFunction(0x18C7F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B8FCu; }
        if (ctx->pc != 0x18B8FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C7F0_0x18c7f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B8FCu; }
        if (ctx->pc != 0x18B8FCu) { return; }
    }
    ctx->pc = 0x18B8FCu;
label_18b8fc:
    // 0x18b8fc: 0x10000061  b           . + 4 + (0x61 << 2)
    ctx->pc = 0x18B8FCu;
    {
        const bool branch_taken_0x18b8fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x18b8fc) {
            ctx->pc = 0x18BA84u;
            goto label_18ba84;
        }
    }
    ctx->pc = 0x18B904u;
label_18b904:
    // 0x18b904: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x18b904u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18b908: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x18b908u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18b90c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x18b90cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18b910: 0x2405000b  addiu       $a1, $zero, 0xB
    ctx->pc = 0x18b910u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x18b914: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x18b914u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18b918: 0xc0631cc  jal         func_18C730
    ctx->pc = 0x18B918u;
    SET_GPR_U32(ctx, 31, 0x18B920u);
    ctx->pc = 0x18B91Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18B918u;
            // 0x18b91c: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18C730u;
    if (runtime->hasFunction(0x18C730u)) {
        auto targetFn = runtime->lookupFunction(0x18C730u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B920u; }
        if (ctx->pc != 0x18B920u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C730_0x18c730(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B920u; }
        if (ctx->pc != 0x18B920u) { return; }
    }
    ctx->pc = 0x18B920u;
label_18b920:
    // 0x18b920: 0x26040010  addiu       $a0, $s0, 0x10
    ctx->pc = 0x18b920u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
    // 0x18b924: 0x24050009  addiu       $a1, $zero, 0x9
    ctx->pc = 0x18b924u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x18b928: 0xc063204  jal         func_18C810
    ctx->pc = 0x18B928u;
    SET_GPR_U32(ctx, 31, 0x18B930u);
    ctx->pc = 0x18B92Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18B928u;
            // 0x18b92c: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18C810u;
    if (runtime->hasFunction(0x18C810u)) {
        auto targetFn = runtime->lookupFunction(0x18C810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B930u; }
        if (ctx->pc != 0x18B930u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C810_0x18c810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B930u; }
        if (ctx->pc != 0x18B930u) { return; }
    }
    ctx->pc = 0x18B930u;
label_18b930:
    // 0x18b930: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x18b930u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x18b934: 0x7e000020  sq          $zero, 0x20($s0)
    ctx->pc = 0x18b934u;
    WRITE128(ADD32(GPR_U32(ctx, 16), 32), GPR_VEC(ctx, 0));
    // 0x18b938: 0x2183c  dsll32      $v1, $v0, 0
    ctx->pc = 0x18b938u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 0));
    // 0x18b93c: 0x24040014  addiu       $a0, $zero, 0x14
    ctx->pc = 0x18b93cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x18b940: 0x34028006  ori         $v0, $zero, 0x8006
    ctx->pc = 0x18b940u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32774);
    // 0x18b944: 0x24060006  addiu       $a2, $zero, 0x6
    ctx->pc = 0x18b944u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x18b948: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x18b948u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x18b94c: 0x24050008  addiu       $a1, $zero, 0x8
    ctx->pc = 0x18b94cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x18b950: 0xfe020030  sd          $v0, 0x30($s0)
    ctx->pc = 0x18b950u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 48), GPR_U64(ctx, 2));
    // 0x18b954: 0x2403000e  addiu       $v1, $zero, 0xE
    ctx->pc = 0x18b954u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x18b958: 0xae030038  sw          $v1, 0x38($s0)
    ctx->pc = 0x18b958u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 3));
    // 0x18b95c: 0x2402003b  addiu       $v0, $zero, 0x3B
    ctx->pc = 0x18b95cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 59));
    // 0x18b960: 0xae00003c  sw          $zero, 0x3C($s0)
    ctx->pc = 0x18b960u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 0));
    // 0x18b964: 0x24030034  addiu       $v1, $zero, 0x34
    ctx->pc = 0x18b964u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 52));
    // 0x18b968: 0xfe000040  sd          $zero, 0x40($s0)
    ctx->pc = 0x18b968u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 64), GPR_U64(ctx, 0));
    // 0x18b96c: 0xfe020048  sd          $v0, 0x48($s0)
    ctx->pc = 0x18b96cu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 72), GPR_U64(ctx, 2));
    // 0x18b970: 0xfe000050  sd          $zero, 0x50($s0)
    ctx->pc = 0x18b970u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 80), GPR_U64(ctx, 0));
    // 0x18b974: 0x24020036  addiu       $v0, $zero, 0x36
    ctx->pc = 0x18b974u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 54));
    // 0x18b978: 0xfe040058  sd          $a0, 0x58($s0)
    ctx->pc = 0x18b978u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 88), GPR_U64(ctx, 4));
    // 0x18b97c: 0xfe000060  sd          $zero, 0x60($s0)
    ctx->pc = 0x18b97cu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 96), GPR_U64(ctx, 0));
    // 0x18b980: 0x260400b0  addiu       $a0, $s0, 0xB0
    ctx->pc = 0x18b980u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 176));
    // 0x18b984: 0xfe060068  sd          $a2, 0x68($s0)
    ctx->pc = 0x18b984u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 104), GPR_U64(ctx, 6));
    // 0x18b988: 0xfe000070  sd          $zero, 0x70($s0)
    ctx->pc = 0x18b988u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 112), GPR_U64(ctx, 0));
    // 0x18b98c: 0xfe050078  sd          $a1, 0x78($s0)
    ctx->pc = 0x18b98cu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 120), GPR_U64(ctx, 5));
    // 0x18b990: 0xfe000080  sd          $zero, 0x80($s0)
    ctx->pc = 0x18b990u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 128), GPR_U64(ctx, 0));
    // 0x18b994: 0xfe030088  sd          $v1, 0x88($s0)
    ctx->pc = 0x18b994u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 136), GPR_U64(ctx, 3));
    // 0x18b998: 0xfe000090  sd          $zero, 0x90($s0)
    ctx->pc = 0x18b998u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 144), GPR_U64(ctx, 0));
    // 0x18b99c: 0xfe020098  sd          $v0, 0x98($s0)
    ctx->pc = 0x18b99cu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 152), GPR_U64(ctx, 2));
    // 0x18b9a0: 0xc0631fc  jal         func_18C7F0
    ctx->pc = 0x18B9A0u;
    SET_GPR_U32(ctx, 31, 0x18B9A8u);
    ctx->pc = 0x18B9A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18B9A0u;
            // 0x18b9a4: 0x7e0000a0  sq          $zero, 0xA0($s0) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 16), 160), GPR_VEC(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18C7F0u;
    if (runtime->hasFunction(0x18C7F0u)) {
        auto targetFn = runtime->lookupFunction(0x18C7F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B9A8u; }
        if (ctx->pc != 0x18B9A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C7F0_0x18c7f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B9A8u; }
        if (ctx->pc != 0x18B9A8u) { return; }
    }
    ctx->pc = 0x18B9A8u;
label_18b9a8:
    // 0x18b9a8: 0x10000036  b           . + 4 + (0x36 << 2)
    ctx->pc = 0x18B9A8u;
    {
        const bool branch_taken_0x18b9a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x18b9a8) {
            ctx->pc = 0x18BA84u;
            goto label_18ba84;
        }
    }
    ctx->pc = 0x18B9B0u;
label_18b9b0:
    // 0x18b9b0: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x18b9b0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18b9b4: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x18b9b4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18b9b8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x18b9b8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18b9bc: 0x24050010  addiu       $a1, $zero, 0x10
    ctx->pc = 0x18b9bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x18b9c0: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x18b9c0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18b9c4: 0xc0631cc  jal         func_18C730
    ctx->pc = 0x18B9C4u;
    SET_GPR_U32(ctx, 31, 0x18B9CCu);
    ctx->pc = 0x18B9C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18B9C4u;
            // 0x18b9c8: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18C730u;
    if (runtime->hasFunction(0x18C730u)) {
        auto targetFn = runtime->lookupFunction(0x18C730u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B9CCu; }
        if (ctx->pc != 0x18B9CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C730_0x18c730(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B9CCu; }
        if (ctx->pc != 0x18B9CCu) { return; }
    }
    ctx->pc = 0x18B9CCu;
label_18b9cc:
    // 0x18b9cc: 0x26040010  addiu       $a0, $s0, 0x10
    ctx->pc = 0x18b9ccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
    // 0x18b9d0: 0x2405000e  addiu       $a1, $zero, 0xE
    ctx->pc = 0x18b9d0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x18b9d4: 0xc063204  jal         func_18C810
    ctx->pc = 0x18B9D4u;
    SET_GPR_U32(ctx, 31, 0x18B9DCu);
    ctx->pc = 0x18B9D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18B9D4u;
            // 0x18b9d8: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18C810u;
    if (runtime->hasFunction(0x18C810u)) {
        auto targetFn = runtime->lookupFunction(0x18C810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B9DCu; }
        if (ctx->pc != 0x18B9DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C810_0x18c810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18B9DCu; }
        if (ctx->pc != 0x18B9DCu) { return; }
    }
    ctx->pc = 0x18B9DCu;
label_18b9dc:
    // 0x18b9dc: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x18b9dcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x18b9e0: 0x7e000020  sq          $zero, 0x20($s0)
    ctx->pc = 0x18b9e0u;
    WRITE128(ADD32(GPR_U32(ctx, 16), 32), GPR_VEC(ctx, 0));
    // 0x18b9e4: 0x2183c  dsll32      $v1, $v0, 0
    ctx->pc = 0x18b9e4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 0));
    // 0x18b9e8: 0x260400c0  addiu       $a0, $s0, 0xC0
    ctx->pc = 0x18b9e8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 192));
    // 0x18b9ec: 0x3402800b  ori         $v0, $zero, 0x800B
    ctx->pc = 0x18b9ecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32779);
    // 0x18b9f0: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x18b9f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x18b9f4: 0x431825  or          $v1, $v0, $v1
    ctx->pc = 0x18b9f4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x18b9f8: 0x26050040  addiu       $a1, $s0, 0x40
    ctx->pc = 0x18b9f8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 64));
    // 0x18b9fc: 0xfe030030  sd          $v1, 0x30($s0)
    ctx->pc = 0x18b9fcu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 48), GPR_U64(ctx, 3));
    // 0x18ba00: 0x2402000e  addiu       $v0, $zero, 0xE
    ctx->pc = 0x18ba00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x18ba04: 0xae020038  sw          $v0, 0x38($s0)
    ctx->pc = 0x18ba04u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 2));
    // 0x18ba08: 0x260300a0  addiu       $v1, $s0, 0xA0
    ctx->pc = 0x18ba08u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 160));
    // 0x18ba0c: 0xae00003c  sw          $zero, 0x3C($s0)
    ctx->pc = 0x18ba0cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 0));
    // 0x18ba10: 0x260200b0  addiu       $v0, $s0, 0xB0
    ctx->pc = 0x18ba10u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 176));
    // 0x18ba14: 0xffa30000  sd          $v1, 0x0($sp)
    ctx->pc = 0x18ba14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 3));
    // 0x18ba18: 0x26060050  addiu       $a2, $s0, 0x50
    ctx->pc = 0x18ba18u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 80));
    // 0x18ba1c: 0xffa20008  sd          $v0, 0x8($sp)
    ctx->pc = 0x18ba1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 2));
    // 0x18ba20: 0x260300d0  addiu       $v1, $s0, 0xD0
    ctx->pc = 0x18ba20u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 208));
    // 0x18ba24: 0xffa40010  sd          $a0, 0x10($sp)
    ctx->pc = 0x18ba24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 4));
    // 0x18ba28: 0x260200e0  addiu       $v0, $s0, 0xE0
    ctx->pc = 0x18ba28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 224));
    // 0x18ba2c: 0xffa30018  sd          $v1, 0x18($sp)
    ctx->pc = 0x18ba2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 3));
    // 0x18ba30: 0x26070060  addiu       $a3, $s0, 0x60
    ctx->pc = 0x18ba30u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 96));
    // 0x18ba34: 0xffa20020  sd          $v0, 0x20($sp)
    ctx->pc = 0x18ba34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 2));
    // 0x18ba38: 0x26080070  addiu       $t0, $s0, 0x70
    ctx->pc = 0x18ba38u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 16), 112));
    // 0x18ba3c: 0x8e240044  lw          $a0, 0x44($s1)
    ctx->pc = 0x18ba3cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 68)));
    // 0x18ba40: 0x26090080  addiu       $t1, $s0, 0x80
    ctx->pc = 0x18ba40u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 16), 128));
    // 0x18ba44: 0x8c2b4e64  lw          $t3, 0x4E64($at)
    ctx->pc = 0x18ba44u;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 20068)));
    // 0x18ba48: 0xc062f58  jal         func_18BD60
    ctx->pc = 0x18BA48u;
    SET_GPR_U32(ctx, 31, 0x18BA50u);
    ctx->pc = 0x18BA4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18BA48u;
            // 0x18ba4c: 0x260a0090  addiu       $t2, $s0, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 16), 144));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18BD60u;
    if (runtime->hasFunction(0x18BD60u)) {
        auto targetFn = runtime->lookupFunction(0x18BD60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18BA50u; }
        if (ctx->pc != 0x18BA50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018BD60_0x18bd60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18BA50u; }
        if (ctx->pc != 0x18BA50u) { return; }
    }
    ctx->pc = 0x18BA50u;
label_18ba50:
    // 0x18ba50: 0xc6200004  lwc1        $f0, 0x4($s1)
    ctx->pc = 0x18ba50u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18ba54: 0x3c024300  lui         $v0, 0x4300
    ctx->pc = 0x18ba54u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17152 << 16));
    // 0x18ba58: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x18ba58u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x18ba5c: 0x26040100  addiu       $a0, $s0, 0x100
    ctx->pc = 0x18ba5cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 256));
    // 0x18ba60: 0xe60000f0  swc1        $f0, 0xF0($s0)
    ctx->pc = 0x18ba60u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 240), bits); }
    // 0x18ba64: 0xc6200008  lwc1        $f0, 0x8($s1)
    ctx->pc = 0x18ba64u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18ba68: 0xe60000f4  swc1        $f0, 0xF4($s0)
    ctx->pc = 0x18ba68u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 244), bits); }
    // 0x18ba6c: 0xc620000c  lwc1        $f0, 0xC($s1)
    ctx->pc = 0x18ba6cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18ba70: 0xe60000f8  swc1        $f0, 0xF8($s0)
    ctx->pc = 0x18ba70u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 248), bits); }
    // 0x18ba74: 0xc6200010  lwc1        $f0, 0x10($s1)
    ctx->pc = 0x18ba74u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x18ba78: 0x46000802  mul.s       $f0, $f1, $f0
    ctx->pc = 0x18ba78u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x18ba7c: 0xc0631fc  jal         func_18C7F0
    ctx->pc = 0x18BA7Cu;
    SET_GPR_U32(ctx, 31, 0x18BA84u);
    ctx->pc = 0x18BA80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18BA7Cu;
            // 0x18ba80: 0xe60000fc  swc1        $f0, 0xFC($s0) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 252), bits); }
        ctx->in_delay_slot = false;
    ctx->pc = 0x18C7F0u;
    if (runtime->hasFunction(0x18C7F0u)) {
        auto targetFn = runtime->lookupFunction(0x18C7F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18BA84u; }
        if (ctx->pc != 0x18BA84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C7F0_0x18c7f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18BA84u; }
        if (ctx->pc != 0x18BA84u) { return; }
    }
    ctx->pc = 0x18BA84u;
label_18ba84:
    // 0x18ba84: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x18ba84u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
label_18ba88:
    // 0x18ba88: 0x7bb10040  lq          $s1, 0x40($sp)
    ctx->pc = 0x18ba88u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x18ba8c: 0x7bb00030  lq          $s0, 0x30($sp)
    ctx->pc = 0x18ba8cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x18ba90: 0x3e00008  jr          $ra
    ctx->pc = 0x18BA90u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18BA94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18BA90u;
            // 0x18ba94: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18B4F4u: goto label_18b4f4;
            case 0x18B510u: goto label_18b510;
            case 0x18B520u: goto label_18b520;
            case 0x18B564u: goto label_18b564;
            case 0x18B5B8u: goto label_18b5b8;
            case 0x18B5C0u: goto label_18b5c0;
            case 0x18B5DCu: goto label_18b5dc;
            case 0x18B5ECu: goto label_18b5ec;
            case 0x18B6ACu: goto label_18b6ac;
            case 0x18B6B4u: goto label_18b6b4;
            case 0x18B6D0u: goto label_18b6d0;
            case 0x18B6E0u: goto label_18b6e0;
            case 0x18B724u: goto label_18b724;
            case 0x18B800u: goto label_18b800;
            case 0x18B80Cu: goto label_18b80c;
            case 0x18B818u: goto label_18b818;
            case 0x18B824u: goto label_18b824;
            case 0x18B830u: goto label_18b830;
            case 0x18B83Cu: goto label_18b83c;
            case 0x18B848u: goto label_18b848;
            case 0x18B854u: goto label_18b854;
            case 0x18B860u: goto label_18b860;
            case 0x18B864u: goto label_18b864;
            case 0x18B87Cu: goto label_18b87c;
            case 0x18B884u: goto label_18b884;
            case 0x18B8A0u: goto label_18b8a0;
            case 0x18B8B0u: goto label_18b8b0;
            case 0x18B8F4u: goto label_18b8f4;
            case 0x18B8FCu: goto label_18b8fc;
            case 0x18B904u: goto label_18b904;
            case 0x18B920u: goto label_18b920;
            case 0x18B930u: goto label_18b930;
            case 0x18B9A8u: goto label_18b9a8;
            case 0x18B9B0u: goto label_18b9b0;
            case 0x18B9CCu: goto label_18b9cc;
            case 0x18B9DCu: goto label_18b9dc;
            case 0x18BA50u: goto label_18ba50;
            case 0x18BA84u: goto label_18ba84;
            case 0x18BA88u: goto label_18ba88;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18BA98u;
    // 0x18ba98: 0x0  nop
    ctx->pc = 0x18ba98u;
    // NOP
    // 0x18ba9c: 0x0  nop
    ctx->pc = 0x18ba9cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
