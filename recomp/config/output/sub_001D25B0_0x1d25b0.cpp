#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D25B0
// Address: 0x1d25b0 - 0x1d27d0
void sub_001D25B0_0x1d25b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D25B0_0x1d25b0");
#endif

    switch (ctx->pc) {
        case 0x1d25e4u: goto label_1d25e4;
        case 0x1d25f0u: goto label_1d25f0;
        case 0x1d25f8u: goto label_1d25f8;
        case 0x1d260cu: goto label_1d260c;
        case 0x1d2648u: goto label_1d2648;
        case 0x1d2658u: goto label_1d2658;
        case 0x1d2670u: goto label_1d2670;
        case 0x1d2680u: goto label_1d2680;
        default: break;
    }

    ctx->pc = 0x1d25b0u;

    // 0x1d25b0: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x1d25b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x1d25b4: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x1d25b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x1d25b8: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1d25b8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1d25bc: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1d25bcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1d25c0: 0x80a82d  daddu       $s5, $a0, $zero
    ctx->pc = 0x1d25c0u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d25c4: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d25c4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d25c8: 0xa0a02d  daddu       $s4, $a1, $zero
    ctx->pc = 0x1d25c8u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d25cc: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d25ccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d25d0: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x1d25d0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d25d4: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d25d4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d25d8: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1d25d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d25dc: 0xc068cac  jal         func_1A32B0
    ctx->pc = 0x1D25DCu;
    SET_GPR_U32(ctx, 31, 0x1D25E4u);
    ctx->pc = 0x1D25E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D25DCu;
            // 0x1d25e0: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A32B0u;
    if (runtime->hasFunction(0x1A32B0u)) {
        auto targetFn = runtime->lookupFunction(0x1A32B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D25E4u; }
        if (ctx->pc != 0x1D25E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A32B0_0x1a32b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D25E4u; }
        if (ctx->pc != 0x1D25E4u) { return; }
    }
    ctx->pc = 0x1D25E4u;
label_1d25e4:
    // 0x1d25e4: 0xa6a20814  sh          $v0, 0x814($s5)
    ctx->pc = 0x1d25e4u;
    WRITE16(ADD32(GPR_U32(ctx, 21), 2068), (uint16_t)GPR_U32(ctx, 2));
    // 0x1d25e8: 0x1000006a  b           . + 4 + (0x6A << 2)
    ctx->pc = 0x1D25E8u;
    {
        const bool branch_taken_0x1d25e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D25ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D25E8u;
            // 0x1d25ec: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d25e8) {
            ctx->pc = 0x1D2794u;
            goto label_1d2794;
        }
    }
    ctx->pc = 0x1D25F0u;
label_1d25f0:
    // 0x1d25f0: 0xc068cec  jal         func_1A33B0
    ctx->pc = 0x1D25F0u;
    SET_GPR_U32(ctx, 31, 0x1D25F8u);
    ctx->pc = 0x1D25F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D25F0u;
            // 0x1d25f4: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A33B0u;
    if (runtime->hasFunction(0x1A33B0u)) {
        auto targetFn = runtime->lookupFunction(0x1A33B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D25F8u; }
        if (ctx->pc != 0x1D25F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A33B0_0x1a33b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D25F8u; }
        if (ctx->pc != 0x1D25F8u) { return; }
    }
    ctx->pc = 0x1D25F8u;
label_1d25f8:
    // 0x1d25f8: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x1d25f8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d25fc: 0x101040  sll         $v0, $s0, 1
    ctx->pc = 0x1d25fcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
    // 0x1d2600: 0x2a21021  addu        $v0, $s5, $v0
    ctx->pc = 0x1d2600u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 2)));
    // 0x1d2604: 0xc06c4d8  jal         func_1B1360
    ctx->pc = 0x1D2604u;
    SET_GPR_U32(ctx, 31, 0x1D260Cu);
    ctx->pc = 0x1D2608u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2604u;
            // 0x1d2608: 0x24510008  addiu       $s1, $v0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B1360u;
    if (runtime->hasFunction(0x1B1360u)) {
        auto targetFn = runtime->lookupFunction(0x1B1360u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D260Cu; }
        if (ctx->pc != 0x1D260Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1360_0x1b1360(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D260Cu; }
        if (ctx->pc != 0x1D260Cu) { return; }
    }
    ctx->pc = 0x1D260Cu;
label_1d260c:
    // 0x1d260c: 0xa6220000  sh          $v0, 0x0($s1)
    ctx->pc = 0x1d260cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1d2610: 0x3c04004f  lui         $a0, 0x4F
    ctx->pc = 0x1d2610u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)79 << 16));
    // 0x1d2614: 0x96260000  lhu         $a2, 0x0($s1)
    ctx->pc = 0x1d2614u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1d2618: 0x2484dd90  addiu       $a0, $a0, -0x2270
    ctx->pc = 0x1d2618u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294958480));
    // 0x1d261c: 0x8e430034  lw          $v1, 0x34($s2)
    ctx->pc = 0x1d261cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 52)));
    // 0x1d2620: 0x628c0  sll         $a1, $a2, 3
    ctx->pc = 0x1d2620u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 6), 3));
    // 0x1d2624: 0xa62821  addu        $a1, $a1, $a2
    ctx->pc = 0x1d2624u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0x1d2628: 0x52840  sll         $a1, $a1, 1
    ctx->pc = 0x1d2628u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x1d262c: 0xa62821  addu        $a1, $a1, $a2
    ctx->pc = 0x1d262cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0x1d2630: 0x52880  sll         $a1, $a1, 2
    ctx->pc = 0x1d2630u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x1d2634: 0x10600034  beqz        $v1, . + 4 + (0x34 << 2)
    ctx->pc = 0x1D2634u;
    {
        const bool branch_taken_0x1d2634 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D2638u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2634u;
            // 0x1d2638: 0x858821  addu        $s1, $a0, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2634) {
            ctx->pc = 0x1D2708u;
            goto label_1d2708;
        }
    }
    ctx->pc = 0x1D263Cu;
    // 0x1d263c: 0x8e450100  lw          $a1, 0x100($s2)
    ctx->pc = 0x1d263cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 256)));
    // 0x1d2640: 0xc068d20  jal         func_1A3480
    ctx->pc = 0x1D2640u;
    SET_GPR_U32(ctx, 31, 0x1D2648u);
    ctx->pc = 0x1D2644u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2640u;
            // 0x1d2644: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A3480u;
    if (runtime->hasFunction(0x1A3480u)) {
        auto targetFn = runtime->lookupFunction(0x1A3480u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2648u; }
        if (ctx->pc != 0x1D2648u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A3480_0x1a3480(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2648u; }
        if (ctx->pc != 0x1D2648u) { return; }
    }
    ctx->pc = 0x1D2648u;
label_1d2648:
    // 0x1d2648: 0x1660000b  bnez        $s3, . + 4 + (0xB << 2)
    ctx->pc = 0x1D2648u;
    {
        const bool branch_taken_0x1d2648 = (GPR_U64(ctx, 19) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D264Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2648u;
            // 0x1d264c: 0x8c450000  lw          $a1, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2648) {
            ctx->pc = 0x1D2678u;
            goto label_1d2678;
        }
    }
    ctx->pc = 0x1D2650u;
    // 0x1d2650: 0xc073478  jal         func_1CD1E0
    ctx->pc = 0x1D2650u;
    SET_GPR_U32(ctx, 31, 0x1D2658u);
    ctx->pc = 0x1D2654u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2650u;
            // 0x1d2654: 0xa0202d  daddu       $a0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD1E0u;
    if (runtime->hasFunction(0x1CD1E0u)) {
        auto targetFn = runtime->lookupFunction(0x1CD1E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2658u; }
        if (ctx->pc != 0x1D2658u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD1E0_0x1cd1e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2658u; }
        if (ctx->pc != 0x1D2658u) { return; }
    }
    ctx->pc = 0x1D2658u;
label_1d2658:
    // 0x1d2658: 0xae220044  sw          $v0, 0x44($s1)
    ctx->pc = 0x1d2658u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 68), GPR_U32(ctx, 2));
    // 0x1d265c: 0x8e230044  lw          $v1, 0x44($s1)
    ctx->pc = 0x1d265cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 68)));
    // 0x1d2660: 0x14600008  bnez        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1D2660u;
    {
        const bool branch_taken_0x1d2660 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D2664u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2660u;
            // 0x1d2664: 0x24040ff0  addiu       $a0, $zero, 0xFF0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4080));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2660) {
            ctx->pc = 0x1D2684u;
            goto label_1d2684;
        }
    }
    ctx->pc = 0x1D2668u;
    // 0x1d2668: 0xc073494  jal         func_1CD250
    ctx->pc = 0x1D2668u;
    SET_GPR_U32(ctx, 31, 0x1D2670u);
    ctx->pc = 0x1CD250u;
    if (runtime->hasFunction(0x1CD250u)) {
        auto targetFn = runtime->lookupFunction(0x1CD250u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2670u; }
        if (ctx->pc != 0x1D2670u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD250_0x1cd250(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2670u; }
        if (ctx->pc != 0x1D2670u) { return; }
    }
    ctx->pc = 0x1D2670u;
label_1d2670:
    // 0x1d2670: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1D2670u;
    {
        const bool branch_taken_0x1d2670 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D2674u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2670u;
            // 0x1d2674: 0xae220044  sw          $v0, 0x44($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 68), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2670) {
            ctx->pc = 0x1D2684u;
            goto label_1d2684;
        }
    }
    ctx->pc = 0x1D2678u;
label_1d2678:
    // 0x1d2678: 0xc0734b0  jal         func_1CD2C0
    ctx->pc = 0x1D2678u;
    SET_GPR_U32(ctx, 31, 0x1D2680u);
    ctx->pc = 0x1D267Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2678u;
            // 0x1d267c: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD2C0u;
    if (runtime->hasFunction(0x1CD2C0u)) {
        auto targetFn = runtime->lookupFunction(0x1CD2C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2680u; }
        if (ctx->pc != 0x1D2680u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD2C0_0x1cd2c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D2680u; }
        if (ctx->pc != 0x1D2680u) { return; }
    }
    ctx->pc = 0x1D2680u;
label_1d2680:
    // 0x1d2680: 0xae220044  sw          $v0, 0x44($s1)
    ctx->pc = 0x1d2680u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 68), GPR_U32(ctx, 2));
label_1d2684:
    // 0x1d2684: 0xc6400010  lwc1        $f0, 0x10($s2)
    ctx->pc = 0x1d2684u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1d2688: 0xe6200004  swc1        $f0, 0x4($s1)
    ctx->pc = 0x1d2688u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 4), bits); }
    // 0x1d268c: 0xc6400014  lwc1        $f0, 0x14($s2)
    ctx->pc = 0x1d268cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 20)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1d2690: 0xe6200008  swc1        $f0, 0x8($s1)
    ctx->pc = 0x1d2690u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 8), bits); }
    // 0x1d2694: 0xc6400018  lwc1        $f0, 0x18($s2)
    ctx->pc = 0x1d2694u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 24)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1d2698: 0xe620000c  swc1        $f0, 0xC($s1)
    ctx->pc = 0x1d2698u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 12), bits); }
    // 0x1d269c: 0xc640001c  lwc1        $f0, 0x1C($s2)
    ctx->pc = 0x1d269cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 28)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1d26a0: 0xe6200010  swc1        $f0, 0x10($s1)
    ctx->pc = 0x1d26a0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 16), bits); }
    // 0x1d26a4: 0xc6400000  lwc1        $f0, 0x0($s2)
    ctx->pc = 0x1d26a4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1d26a8: 0xe6200024  swc1        $f0, 0x24($s1)
    ctx->pc = 0x1d26a8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 36), bits); }
    // 0x1d26ac: 0xc6400004  lwc1        $f0, 0x4($s2)
    ctx->pc = 0x1d26acu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1d26b0: 0xe6200028  swc1        $f0, 0x28($s1)
    ctx->pc = 0x1d26b0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 40), bits); }
    // 0x1d26b4: 0xc6400008  lwc1        $f0, 0x8($s2)
    ctx->pc = 0x1d26b4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1d26b8: 0xe620002c  swc1        $f0, 0x2C($s1)
    ctx->pc = 0x1d26b8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 44), bits); }
    // 0x1d26bc: 0xc640000c  lwc1        $f0, 0xC($s2)
    ctx->pc = 0x1d26bcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1d26c0: 0xe6200030  swc1        $f0, 0x30($s1)
    ctx->pc = 0x1d26c0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 48), bits); }
    // 0x1d26c4: 0xc6400020  lwc1        $f0, 0x20($s2)
    ctx->pc = 0x1d26c4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 32)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1d26c8: 0xe6200014  swc1        $f0, 0x14($s1)
    ctx->pc = 0x1d26c8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 20), bits); }
    // 0x1d26cc: 0xc6400024  lwc1        $f0, 0x24($s2)
    ctx->pc = 0x1d26ccu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1d26d0: 0xe6200018  swc1        $f0, 0x18($s1)
    ctx->pc = 0x1d26d0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 24), bits); }
    // 0x1d26d4: 0xc6400028  lwc1        $f0, 0x28($s2)
    ctx->pc = 0x1d26d4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 40)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1d26d8: 0xe620001c  swc1        $f0, 0x1C($s1)
    ctx->pc = 0x1d26d8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 28), bits); }
    // 0x1d26dc: 0xc640002c  lwc1        $f0, 0x2C($s2)
    ctx->pc = 0x1d26dcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 44)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1d26e0: 0xe6200020  swc1        $f0, 0x20($s1)
    ctx->pc = 0x1d26e0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 32), bits); }
    // 0x1d26e4: 0xae200040  sw          $zero, 0x40($s1)
    ctx->pc = 0x1d26e4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 64), GPR_U32(ctx, 0));
    // 0x1d26e8: 0xae20003c  sw          $zero, 0x3C($s1)
    ctx->pc = 0x1d26e8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 60), GPR_U32(ctx, 0));
    // 0x1d26ec: 0xae200038  sw          $zero, 0x38($s1)
    ctx->pc = 0x1d26ecu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 56), GPR_U32(ctx, 0));
    // 0x1d26f0: 0xae200034  sw          $zero, 0x34($s1)
    ctx->pc = 0x1d26f0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 52), GPR_U32(ctx, 0));
    // 0x1d26f4: 0xc6400030  lwc1        $f0, 0x30($s2)
    ctx->pc = 0x1d26f4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1d26f8: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1d26f8u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1d26fc: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x1d26fcu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1d2700: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x1D2700u;
    {
        const bool branch_taken_0x1d2700 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D2704u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D2700u;
            // 0x1d2704: 0xae230048  sw          $v1, 0x48($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 72), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d2700) {
            ctx->pc = 0x1D2790u;
            goto label_1d2790;
        }
    }
    ctx->pc = 0x1D2708u;
label_1d2708:
    // 0x1d2708: 0xc6400010  lwc1        $f0, 0x10($s2)
    ctx->pc = 0x1d2708u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1d270c: 0xe6200004  swc1        $f0, 0x4($s1)
    ctx->pc = 0x1d270cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 4), bits); }
    // 0x1d2710: 0xc6400014  lwc1        $f0, 0x14($s2)
    ctx->pc = 0x1d2710u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 20)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1d2714: 0xe6200008  swc1        $f0, 0x8($s1)
    ctx->pc = 0x1d2714u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 8), bits); }
    // 0x1d2718: 0xc6400018  lwc1        $f0, 0x18($s2)
    ctx->pc = 0x1d2718u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 24)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1d271c: 0xe620000c  swc1        $f0, 0xC($s1)
    ctx->pc = 0x1d271cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 12), bits); }
    // 0x1d2720: 0xc640001c  lwc1        $f0, 0x1C($s2)
    ctx->pc = 0x1d2720u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 28)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1d2724: 0xe6200010  swc1        $f0, 0x10($s1)
    ctx->pc = 0x1d2724u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 16), bits); }
    // 0x1d2728: 0xc6400000  lwc1        $f0, 0x0($s2)
    ctx->pc = 0x1d2728u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1d272c: 0xe6200024  swc1        $f0, 0x24($s1)
    ctx->pc = 0x1d272cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 36), bits); }
    // 0x1d2730: 0xc6400004  lwc1        $f0, 0x4($s2)
    ctx->pc = 0x1d2730u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1d2734: 0xe6200028  swc1        $f0, 0x28($s1)
    ctx->pc = 0x1d2734u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 40), bits); }
    // 0x1d2738: 0xc6400008  lwc1        $f0, 0x8($s2)
    ctx->pc = 0x1d2738u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1d273c: 0xe620002c  swc1        $f0, 0x2C($s1)
    ctx->pc = 0x1d273cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 44), bits); }
    // 0x1d2740: 0xc640000c  lwc1        $f0, 0xC($s2)
    ctx->pc = 0x1d2740u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 12)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1d2744: 0xe6200030  swc1        $f0, 0x30($s1)
    ctx->pc = 0x1d2744u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 48), bits); }
    // 0x1d2748: 0xc6400020  lwc1        $f0, 0x20($s2)
    ctx->pc = 0x1d2748u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 32)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1d274c: 0xe6200014  swc1        $f0, 0x14($s1)
    ctx->pc = 0x1d274cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 20), bits); }
    // 0x1d2750: 0xc6400024  lwc1        $f0, 0x24($s2)
    ctx->pc = 0x1d2750u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1d2754: 0xe6200018  swc1        $f0, 0x18($s1)
    ctx->pc = 0x1d2754u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 24), bits); }
    // 0x1d2758: 0xc6400028  lwc1        $f0, 0x28($s2)
    ctx->pc = 0x1d2758u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 40)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1d275c: 0xe620001c  swc1        $f0, 0x1C($s1)
    ctx->pc = 0x1d275cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 28), bits); }
    // 0x1d2760: 0xc640002c  lwc1        $f0, 0x2C($s2)
    ctx->pc = 0x1d2760u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 44)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1d2764: 0xe6200020  swc1        $f0, 0x20($s1)
    ctx->pc = 0x1d2764u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 17), 32), bits); }
    // 0x1d2768: 0xae200040  sw          $zero, 0x40($s1)
    ctx->pc = 0x1d2768u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 64), GPR_U32(ctx, 0));
    // 0x1d276c: 0xae20003c  sw          $zero, 0x3C($s1)
    ctx->pc = 0x1d276cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 60), GPR_U32(ctx, 0));
    // 0x1d2770: 0xae200038  sw          $zero, 0x38($s1)
    ctx->pc = 0x1d2770u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 56), GPR_U32(ctx, 0));
    // 0x1d2774: 0xae200034  sw          $zero, 0x34($s1)
    ctx->pc = 0x1d2774u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 52), GPR_U32(ctx, 0));
    // 0x1d2778: 0xc6400030  lwc1        $f0, 0x30($s2)
    ctx->pc = 0x1d2778u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 18), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1d277c: 0x46000024  .word       0x46000024                   # cvt.w.s     $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1d277cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1d2780: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x1d2780u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1d2784: 0x0  nop
    ctx->pc = 0x1d2784u;
    // NOP
    // 0x1d2788: 0xae230048  sw          $v1, 0x48($s1)
    ctx->pc = 0x1d2788u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 72), GPR_U32(ctx, 3));
    // 0x1d278c: 0xae200044  sw          $zero, 0x44($s1)
    ctx->pc = 0x1d278cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 68), GPR_U32(ctx, 0));
label_1d2790:
    // 0x1d2790: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1d2790u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_1d2794:
    // 0x1d2794: 0x96a30814  lhu         $v1, 0x814($s5)
    ctx->pc = 0x1d2794u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 21), 2068)));
    // 0x1d2798: 0x203182a  slt         $v1, $s0, $v1
    ctx->pc = 0x1d2798u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1d279c: 0x1460ff94  bnez        $v1, . + 4 + (-0x6C << 2)
    ctx->pc = 0x1D279Cu;
    {
        const bool branch_taken_0x1d279c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D27A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D279Cu;
            // 0x1d27a0: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d279c) {
            ctx->pc = 0x1D25F0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d25f0;
        }
    }
    ctx->pc = 0x1D27A4u;
    // 0x1d27a4: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x1d27a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1d27a8: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1d27a8u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1d27ac: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1d27acu;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d27b0: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d27b0u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d27b4: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d27b4u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d27b8: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d27b8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d27bc: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d27bcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d27c0: 0x3e00008  jr          $ra
    ctx->pc = 0x1D27C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D27C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D27C0u;
            // 0x1d27c4: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D25E4u: goto label_1d25e4;
            case 0x1D25F0u: goto label_1d25f0;
            case 0x1D25F8u: goto label_1d25f8;
            case 0x1D260Cu: goto label_1d260c;
            case 0x1D2648u: goto label_1d2648;
            case 0x1D2658u: goto label_1d2658;
            case 0x1D2670u: goto label_1d2670;
            case 0x1D2678u: goto label_1d2678;
            case 0x1D2680u: goto label_1d2680;
            case 0x1D2684u: goto label_1d2684;
            case 0x1D2708u: goto label_1d2708;
            case 0x1D2790u: goto label_1d2790;
            case 0x1D2794u: goto label_1d2794;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D27C8u;
    // 0x1d27c8: 0x0  nop
    ctx->pc = 0x1d27c8u;
    // NOP
    // 0x1d27cc: 0x0  nop
    ctx->pc = 0x1d27ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
