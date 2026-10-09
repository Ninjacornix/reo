#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D98A0
// Address: 0x1d98a0 - 0x1d9a9c
void sub_001D98A0_0x1d98a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D98A0_0x1d98a0");
#endif

    switch (ctx->pc) {
        case 0x1d9928u: goto label_1d9928;
        case 0x1d9950u: goto label_1d9950;
        case 0x1d9958u: goto label_1d9958;
        case 0x1d9998u: goto label_1d9998;
        case 0x1d99a0u: goto label_1d99a0;
        case 0x1d99d0u: goto label_1d99d0;
        case 0x1d99e0u: goto label_1d99e0;
        case 0x1d99f4u: goto label_1d99f4;
        case 0x1d9a38u: goto label_1d9a38;
        default: break;
    }

    ctx->pc = 0x1d98a0u;

    // 0x1d98a0: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x1d98a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1d98a4: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1d98a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1d98a8: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d98a8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d98ac: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d98acu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d98b0: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d98b0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d98b4: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d98b4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d98b8: 0x4800005  bltz        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1D98B8u;
    {
        const bool branch_taken_0x1d98b8 = (GPR_S64(ctx, 4) < 0);
        ctx->pc = 0x1D98BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D98B8u;
            // 0x1d98bc: 0xa7a0005e  sh          $zero, 0x5E($sp) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 29), 94), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d98b8) {
            ctx->pc = 0x1D98D0u;
            goto label_1d98d0;
        }
    }
    ctx->pc = 0x1D98C0u;
    // 0x1d98c0: 0x28820003  slti        $v0, $a0, 0x3
    ctx->pc = 0x1d98c0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x1d98c4: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1D98C4u;
    {
        const bool branch_taken_0x1d98c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d98c4) {
            ctx->pc = 0x1D98E8u;
            goto label_1d98e8;
        }
    }
    ctx->pc = 0x1D98CCu;
    // 0x1d98cc: 0x0  nop
    ctx->pc = 0x1d98ccu;
    // NOP
label_1d98d0:
    // 0x1d98d0: 0x24020009  addiu       $v0, $zero, 0x9
    ctx->pc = 0x1d98d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1d98d4: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d98d4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d98d8: 0xac228c88  sw          $v0, -0x7378($at)
    ctx->pc = 0x1d98d8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 2));
    // 0x1d98dc: 0x10000068  b           . + 4 + (0x68 << 2)
    ctx->pc = 0x1D98DCu;
    {
        const bool branch_taken_0x1d98dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D98E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D98DCu;
            // 0x1d98e0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d98dc) {
            ctx->pc = 0x1D9A80u;
            goto label_1d9a80;
        }
    }
    ctx->pc = 0x1D98E4u;
    // 0x1d98e4: 0x0  nop
    ctx->pc = 0x1d98e4u;
    // NOP
label_1d98e8:
    // 0x1d98e8: 0x3c030035  lui         $v1, 0x35
    ctx->pc = 0x1d98e8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)53 << 16));
    // 0x1d98ec: 0x48080  sll         $s0, $a0, 2
    ctx->pc = 0x1d98ecu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1d98f0: 0x24638c90  addiu       $v1, $v1, -0x7370
    ctx->pc = 0x1d98f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294937744));
    // 0x1d98f4: 0x708821  addu        $s1, $v1, $s0
    ctx->pc = 0x1d98f4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1d98f8: 0x2402fffe  addiu       $v0, $zero, -0x2
    ctx->pc = 0x1d98f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x1d98fc: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x1d98fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1d9900: 0x10620005  beq         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1D9900u;
    {
        const bool branch_taken_0x1d9900 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1D9904u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9900u;
            // 0x1d9904: 0x24030009  addiu       $v1, $zero, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9900) {
            ctx->pc = 0x1D9918u;
            goto label_1d9918;
        }
    }
    ctx->pc = 0x1D9908u;
    // 0x1d9908: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d9908u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d990c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d990cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d9910: 0x1000005b  b           . + 4 + (0x5B << 2)
    ctx->pc = 0x1D9910u;
    {
        const bool branch_taken_0x1d9910 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9914u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9910u;
            // 0x1d9914: 0xac238c88  sw          $v1, -0x7378($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9910) {
            ctx->pc = 0x1D9A80u;
            goto label_1d9a80;
        }
    }
    ctx->pc = 0x1D9918u;
label_1d9918:
    // 0x1d9918: 0x8ca40004  lw          $a0, 0x4($a1)
    ctx->pc = 0x1d9918u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x1d991c: 0x94a50002  lhu         $a1, 0x2($a1)
    ctx->pc = 0x1d991cu;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 2)));
    // 0x1d9920: 0xc075ec0  jal         func_1D7B00
    ctx->pc = 0x1D9920u;
    SET_GPR_U32(ctx, 31, 0x1D9928u);
    ctx->pc = 0x1D9924u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9920u;
            // 0x1d9924: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7B00u;
    if (runtime->hasFunction(0x1D7B00u)) {
        auto targetFn = runtime->lookupFunction(0x1D7B00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9928u; }
        if (ctx->pc != 0x1D9928u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7B00_0x1d7b00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9928u; }
        if (ctx->pc != 0x1D9928u) { return; }
    }
    ctx->pc = 0x1D9928u;
label_1d9928:
    // 0x1d9928: 0x2943c  dsll32      $s2, $v0, 16
    ctx->pc = 0x1d9928u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d992c: 0x12943f  dsra32      $s2, $s2, 16
    ctx->pc = 0x1d992cu;
    SET_GPR_S64(ctx, 18, GPR_S64(ctx, 18) >> (32 + 16));
    // 0x1d9930: 0x6410005  bgez        $s2, . + 4 + (0x5 << 2)
    ctx->pc = 0x1D9930u;
    {
        const bool branch_taken_0x1d9930 = (GPR_S64(ctx, 18) >= 0);
        ctx->pc = 0x1D9934u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9930u;
            // 0x1d9934: 0x24030076  addiu       $v1, $zero, 0x76 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 118));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9930) {
            ctx->pc = 0x1D9948u;
            goto label_1d9948;
        }
    }
    ctx->pc = 0x1D9938u;
    // 0x1d9938: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d9938u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d993c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d993cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d9940: 0x1000004f  b           . + 4 + (0x4F << 2)
    ctx->pc = 0x1D9940u;
    {
        const bool branch_taken_0x1d9940 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9944u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9940u;
            // 0x1d9944: 0xac238c88  sw          $v1, -0x7378($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9940) {
            ctx->pc = 0x1D9A80u;
            goto label_1d9a80;
        }
    }
    ctx->pc = 0x1D9948u;
label_1d9948:
    // 0x1d9948: 0xc076514  jal         func_1D9450
    ctx->pc = 0x1D9948u;
    SET_GPR_U32(ctx, 31, 0x1D9950u);
    ctx->pc = 0x1D9450u;
    if (runtime->hasFunction(0x1D9450u)) {
        auto targetFn = runtime->lookupFunction(0x1D9450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9950u; }
        if (ctx->pc != 0x1D9950u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9450_0x1d9450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9950u; }
        if (ctx->pc != 0x1D9950u) { return; }
    }
    ctx->pc = 0x1D9950u;
label_1d9950:
    // 0x1d9950: 0xc076518  jal         func_1D9460
    ctx->pc = 0x1D9950u;
    SET_GPR_U32(ctx, 31, 0x1D9958u);
    ctx->pc = 0x1D9954u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9950u;
            // 0x1d9954: 0xae320000  sw          $s2, 0x0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D9460u;
    if (runtime->hasFunction(0x1D9460u)) {
        auto targetFn = runtime->lookupFunction(0x1D9460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9958u; }
        if (ctx->pc != 0x1D9958u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9460_0x1d9460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9958u; }
        if (ctx->pc != 0x1D9958u) { return; }
    }
    ctx->pc = 0x1D9958u;
label_1d9958:
    // 0x1d9958: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x1d9958u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d995c: 0x260182d  daddu       $v1, $s3, $zero
    ctx->pc = 0x1d995cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9960: 0x26620001  addiu       $v0, $s3, 0x1
    ctx->pc = 0x1d9960u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x1d9964: 0x29c3c  dsll32      $s3, $v0, 16
    ctx->pc = 0x1d9964u;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d9968: 0x3143c  dsll32      $v0, $v1, 16
    ctx->pc = 0x1d9968u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 16));
    // 0x1d996c: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d996cu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d9970: 0x284141a0  slti        $at, $v0, 0x41A0
    ctx->pc = 0x1d9970u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)16800) ? 1 : 0);
    // 0x1d9974: 0x10200038  beqz        $at, . + 4 + (0x38 << 2)
    ctx->pc = 0x1D9974u;
    {
        const bool branch_taken_0x1d9974 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9978u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9974u;
            // 0x1d9978: 0x139c3f  dsra32      $s3, $s3, 16 (Delay Slot)
        SET_GPR_S64(ctx, 19, GPR_S64(ctx, 19) >> (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9974) {
            ctx->pc = 0x1D9A58u;
            goto label_1d9a58;
        }
    }
    ctx->pc = 0x1D997Cu;
    // 0x1d997c: 0x3c030035  lui         $v1, 0x35
    ctx->pc = 0x1d997cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)53 << 16));
    // 0x1d9980: 0x3c020035  lui         $v0, 0x35
    ctx->pc = 0x1d9980u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
    // 0x1d9984: 0x24638c70  addiu       $v1, $v1, -0x7390
    ctx->pc = 0x1d9984u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294937712));
    // 0x1d9988: 0x24428c90  addiu       $v0, $v0, -0x7370
    ctx->pc = 0x1d9988u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937744));
    // 0x1d998c: 0x709021  addu        $s2, $v1, $s0
    ctx->pc = 0x1d998cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1d9990: 0x508821  addu        $s1, $v0, $s0
    ctx->pc = 0x1d9990u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1d9994: 0x0  nop
    ctx->pc = 0x1d9994u;
    // NOP
label_1d9998:
    // 0x1d9998: 0xc076514  jal         func_1D9450
    ctx->pc = 0x1D9998u;
    SET_GPR_U32(ctx, 31, 0x1D99A0u);
    ctx->pc = 0x1D9450u;
    if (runtime->hasFunction(0x1D9450u)) {
        auto targetFn = runtime->lookupFunction(0x1D9450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D99A0u; }
        if (ctx->pc != 0x1D99A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9450_0x1d9450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D99A0u; }
        if (ctx->pc != 0x1D99A0u) { return; }
    }
    ctx->pc = 0x1D99A0u;
label_1d99a0:
    // 0x1d99a0: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x1d99a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1d99a4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d99a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d99a8: 0x1462000b  bne         $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1D99A8u;
    {
        const bool branch_taken_0x1d99a8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1D99ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D99A8u;
            // 0x1d99ac: 0x3c020035  lui         $v0, 0x35 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)53 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d99a8) {
            ctx->pc = 0x1D99D8u;
            goto label_1d99d8;
        }
    }
    ctx->pc = 0x1D99B0u;
    // 0x1d99b0: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x1d99b0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d99b4: 0x24428c70  addiu       $v0, $v0, -0x7390
    ctx->pc = 0x1d99b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937712));
    // 0x1d99b8: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d99b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d99bc: 0x501821  addu        $v1, $v0, $s0
    ctx->pc = 0x1d99bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1d99c0: 0x24020071  addiu       $v0, $zero, 0x71
    ctx->pc = 0x1d99c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 113));
    // 0x1d99c4: 0xac640000  sw          $a0, 0x0($v1)
    ctx->pc = 0x1d99c4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4));
    // 0x1d99c8: 0xc076518  jal         func_1D9460
    ctx->pc = 0x1D99C8u;
    SET_GPR_U32(ctx, 31, 0x1D99D0u);
    ctx->pc = 0x1D99CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D99C8u;
            // 0x1d99cc: 0xac228c88  sw          $v0, -0x7378($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D9460u;
    if (runtime->hasFunction(0x1D9460u)) {
        auto targetFn = runtime->lookupFunction(0x1D9460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D99D0u; }
        if (ctx->pc != 0x1D99D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9460_0x1d9460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D99D0u; }
        if (ctx->pc != 0x1D99D0u) { return; }
    }
    ctx->pc = 0x1D99D0u;
label_1d99d0:
    // 0x1d99d0: 0x1000002b  b           . + 4 + (0x2B << 2)
    ctx->pc = 0x1D99D0u;
    {
        const bool branch_taken_0x1d99d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D99D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D99D0u;
            // 0x1d99d4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d99d0) {
            ctx->pc = 0x1D9A80u;
            goto label_1d9a80;
        }
    }
    ctx->pc = 0x1D99D8u;
label_1d99d8:
    // 0x1d99d8: 0xc076518  jal         func_1D9460
    ctx->pc = 0x1D99D8u;
    SET_GPR_U32(ctx, 31, 0x1D99E0u);
    ctx->pc = 0x1D9460u;
    if (runtime->hasFunction(0x1D9460u)) {
        auto targetFn = runtime->lookupFunction(0x1D9460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D99E0u; }
        if (ctx->pc != 0x1D99E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D9460_0x1d9460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D99E0u; }
        if (ctx->pc != 0x1D99E0u) { return; }
    }
    ctx->pc = 0x1D99E0u;
label_1d99e0:
    // 0x1d99e0: 0x86240000  lh          $a0, 0x0($s1)
    ctx->pc = 0x1d99e0u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1d99e4: 0x27a5005e  addiu       $a1, $sp, 0x5E
    ctx->pc = 0x1d99e4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 94));
    // 0x1d99e8: 0x27a6005c  addiu       $a2, $sp, 0x5C
    ctx->pc = 0x1d99e8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 92));
    // 0x1d99ec: 0xc075f48  jal         func_1D7D20
    ctx->pc = 0x1D99ECu;
    SET_GPR_U32(ctx, 31, 0x1D99F4u);
    ctx->pc = 0x1D99F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D99ECu;
            // 0x1d99f0: 0x27a7005a  addiu       $a3, $sp, 0x5A (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 90));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7D20u;
    if (runtime->hasFunction(0x1D7D20u)) {
        auto targetFn = runtime->lookupFunction(0x1D7D20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D99F4u; }
        if (ctx->pc != 0x1D99F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7D20_0x1d7d20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D99F4u; }
        if (ctx->pc != 0x1D99F4u) { return; }
    }
    ctx->pc = 0x1D99F4u;
label_1d99f4:
    // 0x1d99f4: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1d99f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d99f8: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d99f8u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d99fc: 0x4410006  bgez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D99FCu;
    {
        const bool branch_taken_0x1d99fc = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1D9A00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D99FCu;
            // 0x1d9a00: 0x24030068  addiu       $v1, $zero, 0x68 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 104));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d99fc) {
            ctx->pc = 0x1D9A18u;
            goto label_1d9a18;
        }
    }
    ctx->pc = 0x1D9A04u;
    // 0x1d9a04: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d9a04u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d9a08: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d9a08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d9a0c: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x1D9A0Cu;
    {
        const bool branch_taken_0x1d9a0c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9A10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9A0Cu;
            // 0x1d9a10: 0xac238c88  sw          $v1, -0x7378($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9a0c) {
            ctx->pc = 0x1D9A80u;
            goto label_1d9a80;
        }
    }
    ctx->pc = 0x1D9A14u;
    // 0x1d9a14: 0x0  nop
    ctx->pc = 0x1d9a14u;
    // NOP
label_1d9a18:
    // 0x1d9a18: 0x87a3005e  lh          $v1, 0x5E($sp)
    ctx->pc = 0x1d9a18u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 94)));
    // 0x1d9a1c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1d9a1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d9a20: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D9A20u;
    {
        const bool branch_taken_0x1d9a20 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1D9A24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9A20u;
            // 0x1d9a24: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9a20) {
            ctx->pc = 0x1D9A30u;
            goto label_1d9a30;
        }
    }
    ctx->pc = 0x1D9A28u;
    // 0x1d9a28: 0x1462000b  bne         $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1D9A28u;
    {
        const bool branch_taken_0x1d9a28 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1d9a28) {
            ctx->pc = 0x1D9A58u;
            goto label_1d9a58;
        }
    }
    ctx->pc = 0x1D9A30u;
label_1d9a30:
    // 0x1d9a30: 0xc07690c  jal         func_1DA430
    ctx->pc = 0x1D9A30u;
    SET_GPR_U32(ctx, 31, 0x1D9A38u);
    ctx->pc = 0x1DA430u;
    if (runtime->hasFunction(0x1DA430u)) {
        auto targetFn = runtime->lookupFunction(0x1DA430u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9A38u; }
        if (ctx->pc != 0x1D9A38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DA430_0x1da430(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D9A38u; }
        if (ctx->pc != 0x1D9A38u) { return; }
    }
    ctx->pc = 0x1D9A38u;
label_1d9a38:
    // 0x1d9a38: 0x260182d  daddu       $v1, $s3, $zero
    ctx->pc = 0x1d9a38u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9a3c: 0x26620001  addiu       $v0, $s3, 0x1
    ctx->pc = 0x1d9a3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x1d9a40: 0x29c3c  dsll32      $s3, $v0, 16
    ctx->pc = 0x1d9a40u;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d9a44: 0x3143c  dsll32      $v0, $v1, 16
    ctx->pc = 0x1d9a44u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << (32 + 16));
    // 0x1d9a48: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d9a48u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d9a4c: 0x284241a0  slti        $v0, $v0, 0x41A0
    ctx->pc = 0x1d9a4cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)16800) ? 1 : 0);
    // 0x1d9a50: 0x1440ffd1  bnez        $v0, . + 4 + (-0x2F << 2)
    ctx->pc = 0x1D9A50u;
    {
        const bool branch_taken_0x1d9a50 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D9A54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9A50u;
            // 0x1d9a54: 0x139c3f  dsra32      $s3, $s3, 16 (Delay Slot)
        SET_GPR_S64(ctx, 19, GPR_S64(ctx, 19) >> (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9a50) {
            ctx->pc = 0x1D9998u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d9998;
        }
    }
    ctx->pc = 0x1D9A58u;
label_1d9a58:
    // 0x1d9a58: 0x87a3005e  lh          $v1, 0x5E($sp)
    ctx->pc = 0x1d9a58u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 94)));
    // 0x1d9a5c: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1d9a5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1d9a60: 0x10620005  beq         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1D9A60u;
    {
        const bool branch_taken_0x1d9a60 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1D9A64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9A60u;
            // 0x1d9a64: 0x24030068  addiu       $v1, $zero, 0x68 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 104));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9a60) {
            ctx->pc = 0x1D9A78u;
            goto label_1d9a78;
        }
    }
    ctx->pc = 0x1D9A68u;
    // 0x1d9a68: 0x3c010035  lui         $at, 0x35
    ctx->pc = 0x1d9a68u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)53 << 16));
    // 0x1d9a6c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d9a6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d9a70: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1D9A70u;
    {
        const bool branch_taken_0x1d9a70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D9A74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9A70u;
            // 0x1d9a74: 0xac238c88  sw          $v1, -0x7378($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294937736), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d9a70) {
            ctx->pc = 0x1D9A80u;
            goto label_1d9a80;
        }
    }
    ctx->pc = 0x1D9A78u;
label_1d9a78:
    // 0x1d9a78: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1d9a78u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d9a7c: 0x0  nop
    ctx->pc = 0x1d9a7cu;
    // NOP
label_1d9a80:
    // 0x1d9a80: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1d9a80u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d9a84: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d9a84u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d9a88: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d9a88u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d9a8c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d9a8cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d9a90: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d9a90u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d9a94: 0x3e00008  jr          $ra
    ctx->pc = 0x1D9A94u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D9A98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D9A94u;
            // 0x1d9a98: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D98D0u: goto label_1d98d0;
            case 0x1D98E8u: goto label_1d98e8;
            case 0x1D9918u: goto label_1d9918;
            case 0x1D9928u: goto label_1d9928;
            case 0x1D9948u: goto label_1d9948;
            case 0x1D9950u: goto label_1d9950;
            case 0x1D9958u: goto label_1d9958;
            case 0x1D9998u: goto label_1d9998;
            case 0x1D99A0u: goto label_1d99a0;
            case 0x1D99D0u: goto label_1d99d0;
            case 0x1D99D8u: goto label_1d99d8;
            case 0x1D99E0u: goto label_1d99e0;
            case 0x1D99F4u: goto label_1d99f4;
            case 0x1D9A18u: goto label_1d9a18;
            case 0x1D9A30u: goto label_1d9a30;
            case 0x1D9A38u: goto label_1d9a38;
            case 0x1D9A58u: goto label_1d9a58;
            case 0x1D9A78u: goto label_1d9a78;
            case 0x1D9A80u: goto label_1d9a80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D9A9Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
