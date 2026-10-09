#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A9870
// Address: 0x1a9870 - 0x1a99e0
void sub_001A9870_0x1a9870(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A9870_0x1a9870");
#endif

    switch (ctx->pc) {
        case 0x1a9890u: goto label_1a9890;
        case 0x1a98a8u: goto label_1a98a8;
        case 0x1a98b0u: goto label_1a98b0;
        case 0x1a98dcu: goto label_1a98dc;
        case 0x1a98f4u: goto label_1a98f4;
        case 0x1a98fcu: goto label_1a98fc;
        case 0x1a9928u: goto label_1a9928;
        case 0x1a9940u: goto label_1a9940;
        case 0x1a9948u: goto label_1a9948;
        case 0x1a9970u: goto label_1a9970;
        case 0x1a99d0u: goto label_1a99d0;
        default: break;
    }

    ctx->pc = 0x1a9870u;

    // 0x1a9870: 0x27bdfef0  addiu       $sp, $sp, -0x110
    ctx->pc = 0x1a9870u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967024));
    // 0x1a9874: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x1a9874u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x1a9878: 0x3c06002b  lui         $a2, 0x2B
    ctx->pc = 0x1a9878u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)43 << 16));
    // 0x1a987c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a987cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a9880: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x1a9880u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1a9884: 0x24a52830  addiu       $a1, $a1, 0x2830
    ctx->pc = 0x1a9884u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 10288));
    // 0x1a9888: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1A9888u;
    SET_GPR_U32(ctx, 31, 0x1A9890u);
    ctx->pc = 0x1A988Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9888u;
            // 0x1a988c: 0x24c60fe0  addiu       $a2, $a2, 0xFE0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4064));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9890u; }
        if (ctx->pc != 0x1A9890u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9890u; }
        if (ctx->pc != 0x1A9890u) { return; }
    }
    ctx->pc = 0x1A9890u;
label_1a9890:
    // 0x1a9890: 0x3c07002b  lui         $a3, 0x2B
    ctx->pc = 0x1a9890u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)43 << 16));
    // 0x1a9894: 0x2404000a  addiu       $a0, $zero, 0xA
    ctx->pc = 0x1a9894u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1a9898: 0x27a50010  addiu       $a1, $sp, 0x10
    ctx->pc = 0x1a9898u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1a989c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1a989cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a98a0: 0xc04a1c4  jal         func_128710
    ctx->pc = 0x1A98A0u;
    SET_GPR_U32(ctx, 31, 0x1A98A8u);
    ctx->pc = 0x1A98A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A98A0u;
            // 0x1a98a4: 0x24e735b0  addiu       $a3, $a3, 0x35B0 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 13744));
        ctx->in_delay_slot = false;
    ctx->pc = 0x128710u;
    if (runtime->hasFunction(0x128710u)) {
        auto targetFn = runtime->lookupFunction(0x128710u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A98A8u; }
        if (ctx->pc != 0x1A98A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00128710_0x128710(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A98A8u; }
        if (ctx->pc != 0x1A98A8u) { return; }
    }
    ctx->pc = 0x1A98A8u;
label_1a98a8:
    // 0x1a98a8: 0xc04a2c6  jal         func_128B18
    ctx->pc = 0x1A98A8u;
    SET_GPR_U32(ctx, 31, 0x1A98B0u);
    ctx->pc = 0x1A98ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A98A8u;
            // 0x1a98ac: 0x2404000a  addiu       $a0, $zero, 0xA (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
        ctx->in_delay_slot = false;
    ctx->pc = 0x128B18u;
    if (runtime->hasFunction(0x128B18u)) {
        auto targetFn = runtime->lookupFunction(0x128B18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A98B0u; }
        if (ctx->pc != 0x1A98B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00128B18_0x128b18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A98B0u; }
        if (ctx->pc != 0x1A98B0u) { return; }
    }
    ctx->pc = 0x1A98B0u;
label_1a98b0:
    // 0x1a98b0: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1a98b0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1a98b4: 0x0  nop
    ctx->pc = 0x1a98b4u;
    // NOP
    // 0x1a98b8: 0x0  nop
    ctx->pc = 0x1a98b8u;
    // NOP
    // 0x1a98bc: 0x1443fffa  bne         $v0, $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1A98BCu;
    {
        const bool branch_taken_0x1a98bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1a98bc) {
            ctx->pc = 0x1A98A8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a98a8;
        }
    }
    ctx->pc = 0x1A98C4u;
    // 0x1a98c4: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x1a98c4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x1a98c8: 0x3c06002b  lui         $a2, 0x2B
    ctx->pc = 0x1a98c8u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)43 << 16));
    // 0x1a98cc: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x1a98ccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1a98d0: 0x24a52840  addiu       $a1, $a1, 0x2840
    ctx->pc = 0x1a98d0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 10304));
    // 0x1a98d4: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1A98D4u;
    SET_GPR_U32(ctx, 31, 0x1A98DCu);
    ctx->pc = 0x1A98D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A98D4u;
            // 0x1a98d8: 0x24c60fd0  addiu       $a2, $a2, 0xFD0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4048));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A98DCu; }
        if (ctx->pc != 0x1A98DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A98DCu; }
        if (ctx->pc != 0x1A98DCu) { return; }
    }
    ctx->pc = 0x1A98DCu;
label_1a98dc:
    // 0x1a98dc: 0x3c07002b  lui         $a3, 0x2B
    ctx->pc = 0x1a98dcu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)43 << 16));
    // 0x1a98e0: 0x2404000d  addiu       $a0, $zero, 0xD
    ctx->pc = 0x1a98e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x1a98e4: 0x27a50010  addiu       $a1, $sp, 0x10
    ctx->pc = 0x1a98e4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1a98e8: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1a98e8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a98ec: 0xc04a1c4  jal         func_128710
    ctx->pc = 0x1A98ECu;
    SET_GPR_U32(ctx, 31, 0x1A98F4u);
    ctx->pc = 0x1A98F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A98ECu;
            // 0x1a98f0: 0x24e73460  addiu       $a3, $a3, 0x3460 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 13408));
        ctx->in_delay_slot = false;
    ctx->pc = 0x128710u;
    if (runtime->hasFunction(0x128710u)) {
        auto targetFn = runtime->lookupFunction(0x128710u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A98F4u; }
        if (ctx->pc != 0x1A98F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00128710_0x128710(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A98F4u; }
        if (ctx->pc != 0x1A98F4u) { return; }
    }
    ctx->pc = 0x1A98F4u;
label_1a98f4:
    // 0x1a98f4: 0xc04a2c6  jal         func_128B18
    ctx->pc = 0x1A98F4u;
    SET_GPR_U32(ctx, 31, 0x1A98FCu);
    ctx->pc = 0x1A98F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A98F4u;
            // 0x1a98f8: 0x2404000d  addiu       $a0, $zero, 0xD (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
        ctx->in_delay_slot = false;
    ctx->pc = 0x128B18u;
    if (runtime->hasFunction(0x128B18u)) {
        auto targetFn = runtime->lookupFunction(0x128B18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A98FCu; }
        if (ctx->pc != 0x1A98FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00128B18_0x128b18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A98FCu; }
        if (ctx->pc != 0x1A98FCu) { return; }
    }
    ctx->pc = 0x1A98FCu;
label_1a98fc:
    // 0x1a98fc: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1a98fcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1a9900: 0x0  nop
    ctx->pc = 0x1a9900u;
    // NOP
    // 0x1a9904: 0x0  nop
    ctx->pc = 0x1a9904u;
    // NOP
    // 0x1a9908: 0x1443fffa  bne         $v0, $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1A9908u;
    {
        const bool branch_taken_0x1a9908 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1a9908) {
            ctx->pc = 0x1A98F4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a98f4;
        }
    }
    ctx->pc = 0x1A9910u;
    // 0x1a9910: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x1a9910u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x1a9914: 0x3c06002b  lui         $a2, 0x2B
    ctx->pc = 0x1a9914u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)43 << 16));
    // 0x1a9918: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x1a9918u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1a991c: 0x24a52850  addiu       $a1, $a1, 0x2850
    ctx->pc = 0x1a991cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 10320));
    // 0x1a9920: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1A9920u;
    SET_GPR_U32(ctx, 31, 0x1A9928u);
    ctx->pc = 0x1A9924u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9920u;
            // 0x1a9924: 0x24c60fd0  addiu       $a2, $a2, 0xFD0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4048));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9928u; }
        if (ctx->pc != 0x1A9928u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9928u; }
        if (ctx->pc != 0x1A9928u) { return; }
    }
    ctx->pc = 0x1A9928u;
label_1a9928:
    // 0x1a9928: 0x3c07002b  lui         $a3, 0x2B
    ctx->pc = 0x1a9928u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)43 << 16));
    // 0x1a992c: 0x2404000e  addiu       $a0, $zero, 0xE
    ctx->pc = 0x1a992cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1a9930: 0x27a50010  addiu       $a1, $sp, 0x10
    ctx->pc = 0x1a9930u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1a9934: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1a9934u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a9938: 0xc04a1c4  jal         func_128710
    ctx->pc = 0x1A9938u;
    SET_GPR_U32(ctx, 31, 0x1A9940u);
    ctx->pc = 0x1A993Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9938u;
            // 0x1a993c: 0x24e73320  addiu       $a3, $a3, 0x3320 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 13088));
        ctx->in_delay_slot = false;
    ctx->pc = 0x128710u;
    if (runtime->hasFunction(0x128710u)) {
        auto targetFn = runtime->lookupFunction(0x128710u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9940u; }
        if (ctx->pc != 0x1A9940u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00128710_0x128710(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9940u; }
        if (ctx->pc != 0x1A9940u) { return; }
    }
    ctx->pc = 0x1A9940u;
label_1a9940:
    // 0x1a9940: 0xc04a2c6  jal         func_128B18
    ctx->pc = 0x1A9940u;
    SET_GPR_U32(ctx, 31, 0x1A9948u);
    ctx->pc = 0x1A9944u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9940u;
            // 0x1a9944: 0x2404000e  addiu       $a0, $zero, 0xE (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
        ctx->in_delay_slot = false;
    ctx->pc = 0x128B18u;
    if (runtime->hasFunction(0x128B18u)) {
        auto targetFn = runtime->lookupFunction(0x128B18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9948u; }
        if (ctx->pc != 0x1A9948u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00128B18_0x128b18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9948u; }
        if (ctx->pc != 0x1A9948u) { return; }
    }
    ctx->pc = 0x1A9948u;
label_1a9948:
    // 0x1a9948: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1a9948u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1a994c: 0x0  nop
    ctx->pc = 0x1a994cu;
    // NOP
    // 0x1a9950: 0x0  nop
    ctx->pc = 0x1a9950u;
    // NOP
    // 0x1a9954: 0x1443fffa  bne         $v0, $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1A9954u;
    {
        const bool branch_taken_0x1a9954 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1a9954) {
            ctx->pc = 0x1A9940u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a9940;
        }
    }
    ctx->pc = 0x1A995Cu;
    // 0x1a995c: 0x3c04002b  lui         $a0, 0x2B
    ctx->pc = 0x1a995cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)43 << 16));
    // 0x1a9960: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1a9960u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a9964: 0x248432d0  addiu       $a0, $a0, 0x32D0
    ctx->pc = 0x1a9964u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 13008));
    // 0x1a9968: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1A9968u;
    SET_GPR_U32(ctx, 31, 0x1A9970u);
    ctx->pc = 0x1A996Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9968u;
            // 0x1a996c: 0x24060048  addiu       $a2, $zero, 0x48 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 72));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9970u; }
        if (ctx->pc != 0x1A9970u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9970u; }
        if (ctx->pc != 0x1A9970u) { return; }
    }
    ctx->pc = 0x1A9970u;
label_1a9970:
    // 0x1a9970: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a9970u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a9974: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1a9974u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1a9978: 0x246332d0  addiu       $v1, $v1, 0x32D0
    ctx->pc = 0x1a9978u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 13008));
    // 0x1a997c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a997cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a9980: 0xac231698  sw          $v1, 0x1698($at)
    ctx->pc = 0x1a9980u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 5784), GPR_U32(ctx, 3));
    // 0x1a9984: 0x244232f4  addiu       $v0, $v0, 0x32F4
    ctx->pc = 0x1a9984u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 13044));
    // 0x1a9988: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a9988u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a998c: 0x2405000b  addiu       $a1, $zero, 0xB
    ctx->pc = 0x1a998cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x1a9990: 0xac2216a0  sw          $v0, 0x16A0($at)
    ctx->pc = 0x1a9990u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 5792), GPR_U32(ctx, 2));
    // 0x1a9994: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1a9994u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a9998: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a9998u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a999c: 0x2403000c  addiu       $v1, $zero, 0xC
    ctx->pc = 0x1a999cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x1a99a0: 0x8c221698  lw          $v0, 0x1698($at)
    ctx->pc = 0x1a99a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 5784)));
    // 0x1a99a4: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x1a99a4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x1a99a8: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a99a8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a99ac: 0x8c221698  lw          $v0, 0x1698($at)
    ctx->pc = 0x1a99acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 5784)));
    // 0x1a99b0: 0xac450020  sw          $a1, 0x20($v0)
    ctx->pc = 0x1a99b0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 32), GPR_U32(ctx, 5));
    // 0x1a99b4: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a99b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a99b8: 0x8c2216a0  lw          $v0, 0x16A0($at)
    ctx->pc = 0x1a99b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 5792)));
    // 0x1a99bc: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x1a99bcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x1a99c0: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a99c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a99c4: 0x8c2216a0  lw          $v0, 0x16A0($at)
    ctx->pc = 0x1a99c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 5792)));
    // 0x1a99c8: 0xc06a844  jal         func_1AA110
    ctx->pc = 0x1A99C8u;
    SET_GPR_U32(ctx, 31, 0x1A99D0u);
    ctx->pc = 0x1A99CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A99C8u;
            // 0x1a99cc: 0xac430020  sw          $v1, 0x20($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 32), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AA110u;
    if (runtime->hasFunction(0x1AA110u)) {
        auto targetFn = runtime->lookupFunction(0x1AA110u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A99D0u; }
        if (ctx->pc != 0x1A99D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AA110_0x1aa110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A99D0u; }
        if (ctx->pc != 0x1A99D0u) { return; }
    }
    ctx->pc = 0x1A99D0u;
label_1a99d0:
    // 0x1a99d0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a99d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a99d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1A99D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A99D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A99D4u;
            // 0x1a99d8: 0x27bd0110  addiu       $sp, $sp, 0x110 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 272));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A9890u: goto label_1a9890;
            case 0x1A98A8u: goto label_1a98a8;
            case 0x1A98B0u: goto label_1a98b0;
            case 0x1A98DCu: goto label_1a98dc;
            case 0x1A98F4u: goto label_1a98f4;
            case 0x1A98FCu: goto label_1a98fc;
            case 0x1A9928u: goto label_1a9928;
            case 0x1A9940u: goto label_1a9940;
            case 0x1A9948u: goto label_1a9948;
            case 0x1A9970u: goto label_1a9970;
            case 0x1A99D0u: goto label_1a99d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A99DCu;
    // 0x1a99dc: 0x0  nop
    ctx->pc = 0x1a99dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
