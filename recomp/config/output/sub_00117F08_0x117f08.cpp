#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00117F08
// Address: 0x117f08 - 0x1180d0
void sub_00117F08_0x117f08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00117F08_0x117f08");
#endif

    switch (ctx->pc) {
        case 0x117f40u: goto label_117f40;
        case 0x117f60u: goto label_117f60;
        case 0x117f70u: goto label_117f70;
        case 0x117f78u: goto label_117f78;
        case 0x117f94u: goto label_117f94;
        case 0x117fa8u: goto label_117fa8;
        case 0x117fb4u: goto label_117fb4;
        case 0x117fd8u: goto label_117fd8;
        case 0x117ff8u: goto label_117ff8;
        case 0x118070u: goto label_118070;
        case 0x118078u: goto label_118078;
        case 0x118088u: goto label_118088;
        default: break;
    }

    ctx->pc = 0x117f08u;

    // 0x117f08: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x117f08u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x117f0c: 0xffb40060  sd          $s4, 0x60($sp)
    ctx->pc = 0x117f0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 20));
    // 0x117f10: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x117f10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x117f14: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x117f14u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117f18: 0xffb10030  sd          $s1, 0x30($sp)
    ctx->pc = 0x117f18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 17));
    // 0x117f1c: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x117f1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x117f20: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x117f20u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117f24: 0xffb30050  sd          $s3, 0x50($sp)
    ctx->pc = 0x117f24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 19));
    // 0x117f28: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x117f28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x117f2c: 0x8e220004  lw          $v0, 0x4($s1)
    ctx->pc = 0x117f2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x117f30: 0x8e240024  lw          $a0, 0x24($s1)
    ctx->pc = 0x117f30u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x117f34: 0x8e250008  lw          $a1, 0x8($s1)
    ctx->pc = 0x117f34u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x117f38: 0x40f809  jalr        $v0
    ctx->pc = 0x117F38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x117F40u);
        ctx->pc = 0x117F3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117F38u;
            // 0x117f3c: 0x8e26000c  lw          $a2, 0xC($s1) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x117F40u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x117F40u: goto label_117f40;
            case 0x117F4Cu: goto label_117f4c;
            case 0x117F60u: goto label_117f60;
            case 0x117F70u: goto label_117f70;
            case 0x117F78u: goto label_117f78;
            case 0x117F94u: goto label_117f94;
            case 0x117F9Cu: goto label_117f9c;
            case 0x117FA8u: goto label_117fa8;
            case 0x117FACu: goto label_117fac;
            case 0x117FB4u: goto label_117fb4;
            case 0x117FD8u: goto label_117fd8;
            case 0x117FF8u: goto label_117ff8;
            case 0x118008u: goto label_118008;
            case 0x11802Cu: goto label_11802c;
            case 0x118070u: goto label_118070;
            case 0x118078u: goto label_118078;
            case 0x118088u: goto label_118088;
            case 0x1180B0u: goto label_1180b0;
            case 0x1180B4u: goto label_1180b4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x117F40u; }
            if (ctx->pc != 0x117F40u) { return; }
        }
        }
    }
    ctx->pc = 0x117F40u;
label_117f40:
    // 0x117f40: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x117f40u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117f44: 0x56400001  bnel        $s2, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x117F44u;
    {
        const bool branch_taken_0x117f44 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        if (branch_taken_0x117f44) {
            ctx->pc = 0x117F48u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x117F44u;
            // 0x117f48: 0x8e34002c  lw          $s4, 0x2C($s1) (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 44)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x117F4Cu;
            goto label_117f4c;
        }
    }
    ctx->pc = 0x117F4Cu;
label_117f4c:
    // 0x117f4c: 0x8e25000c  lw          $a1, 0xC($s1)
    ctx->pc = 0x117f4cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x117f50: 0x18a00003  blez        $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x117F50u;
    {
        const bool branch_taken_0x117f50 = (GPR_S64(ctx, 5) <= 0);
        if (branch_taken_0x117f50) {
            ctx->pc = 0x117F60u;
            goto label_117f60;
        }
    }
    ctx->pc = 0x117F58u;
    // 0x117f58: 0xc045bf4  jal         func_116FD0
    ctx->pc = 0x117F58u;
    SET_GPR_U32(ctx, 31, 0x117F60u);
    ctx->pc = 0x117F5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117F58u;
            // 0x117f5c: 0x8e240008  lw          $a0, 0x8($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116FD0u;
    if (runtime->hasFunction(0x116FD0u)) {
        auto targetFn = runtime->lookupFunction(0x116FD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117F60u; }
        if (ctx->pc != 0x117F60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116FD0_0x116fd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117F60u; }
        if (ctx->pc != 0x117F60u) { return; }
    }
    ctx->pc = 0x117F60u;
label_117f60:
    // 0x117f60: 0x1a800003  blez        $s4, . + 4 + (0x3 << 2)
    ctx->pc = 0x117F60u;
    {
        const bool branch_taken_0x117f60 = (GPR_S64(ctx, 20) <= 0);
        ctx->pc = 0x117F64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117F60u;
            // 0x117f64: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x117f60) {
            ctx->pc = 0x117F70u;
            goto label_117f70;
        }
    }
    ctx->pc = 0x117F68u;
    // 0x117f68: 0xc045bf4  jal         func_116FD0
    ctx->pc = 0x117F68u;
    SET_GPR_U32(ctx, 31, 0x117F70u);
    ctx->pc = 0x117F6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117F68u;
            // 0x117f6c: 0x280282d  daddu       $a1, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116FD0u;
    if (runtime->hasFunction(0x116FD0u)) {
        auto targetFn = runtime->lookupFunction(0x116FD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117F70u; }
        if (ctx->pc != 0x117F70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116FD0_0x116fd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117F70u; }
        if (ctx->pc != 0x117F70u) { return; }
    }
    ctx->pc = 0x117F70u;
label_117f70:
    // 0x117f70: 0xc047598  jal         func_11D660
    ctx->pc = 0x117F70u;
    SET_GPR_U32(ctx, 31, 0x117F78u);
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117F78u; }
        if (ctx->pc != 0x117F78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117F78u; }
        if (ctx->pc != 0x117F78u) { return; }
    }
    ctx->pc = 0x117F78u;
label_117f78:
    // 0x117f78: 0x8e250034  lw          $a1, 0x34($s1)
    ctx->pc = 0x117f78u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 52)));
    // 0x117f7c: 0x30a20004  andi        $v0, $a1, 0x4
    ctx->pc = 0x117f7cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)4);
    // 0x117f80: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x117F80u;
    {
        const bool branch_taken_0x117f80 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x117F84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117F80u;
            // 0x117f84: 0x52c02  srl         $a1, $a1, 16 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 5), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x117f80) {
            ctx->pc = 0x117F9Cu;
            goto label_117f9c;
        }
    }
    ctx->pc = 0x117F88u;
    // 0x117f88: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x117f88u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x117f8c: 0xc045cd0  jal         func_117340
    ctx->pc = 0x117F8Cu;
    SET_GPR_U32(ctx, 31, 0x117F94u);
    ctx->pc = 0x117F90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117F8Cu;
            // 0x117f90: 0x2484c9c0  addiu       $a0, $a0, -0x3640 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294953408));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117340u;
    if (runtime->hasFunction(0x117340u)) {
        auto targetFn = runtime->lookupFunction(0x117340u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117F94u; }
        if (ctx->pc != 0x117F94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117340_0x117340(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117F94u; }
        if (ctx->pc != 0x117F94u) { return; }
    }
    ctx->pc = 0x117F94u;
label_117f94:
    // 0x117f94: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x117F94u;
    {
        const bool branch_taken_0x117f94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x117F98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117F94u;
            // 0x117f98: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x117f94) {
            ctx->pc = 0x117FACu;
            goto label_117fac;
        }
    }
    ctx->pc = 0x117F9Cu;
label_117f9c:
    // 0x117f9c: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x117f9cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x117fa0: 0xc045cc4  jal         func_117310
    ctx->pc = 0x117FA0u;
    SET_GPR_U32(ctx, 31, 0x117FA8u);
    ctx->pc = 0x117FA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117FA0u;
            // 0x117fa4: 0x2484c9c0  addiu       $a0, $a0, -0x3640 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294953408));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117310u;
    if (runtime->hasFunction(0x117310u)) {
        auto targetFn = runtime->lookupFunction(0x117310u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117FA8u; }
        if (ctx->pc != 0x117FA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117310_0x117310(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117FA8u; }
        if (ctx->pc != 0x117FA8u) { return; }
    }
    ctx->pc = 0x117FA8u;
label_117fa8:
    // 0x117fa8: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x117fa8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_117fac:
    // 0x117fac: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x117FACu;
    SET_GPR_U32(ctx, 31, 0x117FB4u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117FB4u; }
        if (ctx->pc != 0x117FB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117FB4u; }
        if (ctx->pc != 0x117FB4u) { return; }
    }
    ctx->pc = 0x117FB4u;
label_117fb4:
    // 0x117fb4: 0x3c038000  lui         $v1, 0x8000
    ctx->pc = 0x117fb4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32768 << 16));
    // 0x117fb8: 0x8e24001c  lw          $a0, 0x1C($s1)
    ctx->pc = 0x117fb8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x117fbc: 0x3463000a  ori         $v1, $v1, 0xA
    ctx->pc = 0x117fbcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)10);
    // 0x117fc0: 0xae030020  sw          $v1, 0x20($s0)
    ctx->pc = 0x117fc0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 3));
    // 0x117fc4: 0xae04001c  sw          $a0, 0x1C($s0)
    ctx->pc = 0x117fc4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 4));
    // 0x117fc8: 0x8e220030  lw          $v0, 0x30($s1)
    ctx->pc = 0x117fc8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 48)));
    // 0x117fcc: 0x5040000e  beql        $v0, $zero, . + 4 + (0xE << 2)
    ctx->pc = 0x117FCCu;
    {
        const bool branch_taken_0x117fcc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x117fcc) {
            ctx->pc = 0x117FD0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x117FCCu;
            // 0x117fd0: 0xae000018  sw          $zero, 0x18($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x118008u;
            goto label_118008;
        }
    }
    ctx->pc = 0x117FD4u;
    // 0x117fd4: 0x0  nop
    ctx->pc = 0x117fd4u;
    // NOP
label_117fd8:
    // 0x117fd8: 0x3c048000  lui         $a0, 0x8000
    ctx->pc = 0x117fd8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32768 << 16));
    // 0x117fdc: 0x8e280028  lw          $t0, 0x28($s1)
    ctx->pc = 0x117fdcu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 40)));
    // 0x117fe0: 0x34840008  ori         $a0, $a0, 0x8
    ctx->pc = 0x117fe0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)8);
    // 0x117fe4: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x117fe4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117fe8: 0x24060040  addiu       $a2, $zero, 0x40
    ctx->pc = 0x117fe8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x117fec: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x117fecu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117ff0: 0xc045b82  jal         func_116E08
    ctx->pc = 0x117FF0u;
    SET_GPR_U32(ctx, 31, 0x117FF8u);
    ctx->pc = 0x117FF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117FF0u;
            // 0x117ff4: 0x280482d  daddu       $t1, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116E08u;
    if (runtime->hasFunction(0x116E08u)) {
        auto targetFn = runtime->lookupFunction(0x116E08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117FF8u; }
        if (ctx->pc != 0x117FF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116E08_0x116e08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117FF8u; }
        if (ctx->pc != 0x117FF8u) { return; }
    }
    ctx->pc = 0x117FF8u;
label_117ff8:
    // 0x117ff8: 0x1040fff7  beqz        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x117FF8u;
    {
        const bool branch_taken_0x117ff8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x117FFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117FF8u;
            // 0x117ffc: 0xdfbf0070  ld          $ra, 0x70($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x117ff8) {
            ctx->pc = 0x117FD8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_117fd8;
        }
    }
    ctx->pc = 0x118000u;
    // 0x118000: 0x1000002c  b           . + 4 + (0x2C << 2)
    ctx->pc = 0x118000u;
    {
        const bool branch_taken_0x118000 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x118004u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118000u;
            // 0x118004: 0xdfb40060  ld          $s4, 0x60($sp) (Delay Slot)
        SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 96)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118000) {
            ctx->pc = 0x1180B4u;
            goto label_1180b4;
        }
    }
    ctx->pc = 0x118008u;
label_118008:
    // 0x118008: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x118008u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11800c: 0x1a800007  blez        $s4, . + 4 + (0x7 << 2)
    ctx->pc = 0x11800Cu;
    {
        const bool branch_taken_0x11800c = (GPR_S64(ctx, 20) <= 0);
        ctx->pc = 0x118010u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11800Cu;
            // 0x118010: 0xae000010  sw          $zero, 0x10($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11800c) {
            ctx->pc = 0x11802Cu;
            goto label_11802c;
        }
    }
    ctx->pc = 0x118014u;
    // 0x118014: 0x8e220028  lw          $v0, 0x28($s1)
    ctx->pc = 0x118014u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 40)));
    // 0x118018: 0x24130001  addiu       $s3, $zero, 0x1
    ctx->pc = 0x118018u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x11801c: 0xafb20000  sw          $s2, 0x0($sp)
    ctx->pc = 0x11801cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 18));
    // 0x118020: 0xafa20004  sw          $v0, 0x4($sp)
    ctx->pc = 0x118020u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
    // 0x118024: 0xafb40008  sw          $s4, 0x8($sp)
    ctx->pc = 0x118024u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 20));
    // 0x118028: 0xafa0000c  sw          $zero, 0xC($sp)
    ctx->pc = 0x118028u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 0));
label_11802c:
    // 0x11802c: 0x132900  sll         $a1, $s3, 4
    ctx->pc = 0x11802cu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 19), 4));
    // 0x118030: 0x8e240020  lw          $a0, 0x20($s1)
    ctx->pc = 0x118030u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x118034: 0x3a51821  addu        $v1, $sp, $a1
    ctx->pc = 0x118034u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 5)));
    // 0x118038: 0x27a20004  addiu       $v0, $sp, 0x4
    ctx->pc = 0x118038u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x11803c: 0xac700000  sw          $s0, 0x0($v1)
    ctx->pc = 0x11803cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 16));
    // 0x118040: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x118040u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x118044: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x118044u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x118048: 0x27a30008  addiu       $v1, $sp, 0x8
    ctx->pc = 0x118048u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
    // 0x11804c: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x11804cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x118050: 0x24040040  addiu       $a0, $zero, 0x40
    ctx->pc = 0x118050u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x118054: 0x27a2000c  addiu       $v0, $sp, 0xC
    ctx->pc = 0x118054u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 12));
    // 0x118058: 0xac640000  sw          $a0, 0x0($v1)
    ctx->pc = 0x118058u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4));
    // 0x11805c: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x11805cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x118060: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x118060u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x118064: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x118064u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x118068: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x118068u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11806c: 0x0  nop
    ctx->pc = 0x11806cu;
    // NOP
label_118070:
    // 0x118070: 0xc045278  jal         func_1149E0
    ctx->pc = 0x118070u;
    SET_GPR_U32(ctx, 31, 0x118078u);
    ctx->pc = 0x118074u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x118070u;
            // 0x118074: 0x260282d  daddu       $a1, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1149E0u;
    if (runtime->hasFunction(0x1149E0u)) {
        auto targetFn = runtime->lookupFunction(0x1149E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118078u; }
        if (ctx->pc != 0x118078u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001149E0_0x1149e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x118078u; }
        if (ctx->pc != 0x118078u) { return; }
    }
    ctx->pc = 0x118078u;
label_118078:
    // 0x118078: 0x1440000d  bnez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x118078u;
    {
        const bool branch_taken_0x118078 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x11807Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x118078u;
            // 0x11807c: 0xdfbf0070  ld          $ra, 0x70($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x118078) {
            ctx->pc = 0x1180B0u;
            goto label_1180b0;
        }
    }
    ctx->pc = 0x118080u;
    // 0x118080: 0x3c030010  lui         $v1, 0x10
    ctx->pc = 0x118080u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16 << 16));
    // 0x118084: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x118084u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_118088:
    // 0x118088: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x118088u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x11808c: 0x0  nop
    ctx->pc = 0x11808cu;
    // NOP
    // 0x118090: 0x0  nop
    ctx->pc = 0x118090u;
    // NOP
    // 0x118094: 0x0  nop
    ctx->pc = 0x118094u;
    // NOP
    // 0x118098: 0x0  nop
    ctx->pc = 0x118098u;
    // NOP
    // 0x11809c: 0x1464fffa  bne         $v1, $a0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x11809Cu;
    {
        const bool branch_taken_0x11809c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        if (branch_taken_0x11809c) {
            ctx->pc = 0x118088u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_118088;
        }
    }
    ctx->pc = 0x1180A4u;
    // 0x1180a4: 0x5040fff2  beql        $v0, $zero, . + 4 + (-0xE << 2)
    ctx->pc = 0x1180A4u;
    {
        const bool branch_taken_0x1180a4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1180a4) {
            ctx->pc = 0x1180A8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1180A4u;
            // 0x1180a8: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x118070u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_118070;
        }
    }
    ctx->pc = 0x1180ACu;
    // 0x1180ac: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x1180acu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
label_1180b0:
    // 0x1180b0: 0xdfb40060  ld          $s4, 0x60($sp)
    ctx->pc = 0x1180b0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 96)));
label_1180b4:
    // 0x1180b4: 0xdfb30050  ld          $s3, 0x50($sp)
    ctx->pc = 0x1180b4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1180b8: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x1180b8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1180bc: 0xdfb10030  ld          $s1, 0x30($sp)
    ctx->pc = 0x1180bcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1180c0: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x1180c0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1180c4: 0x3e00008  jr          $ra
    ctx->pc = 0x1180C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1180C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1180C4u;
            // 0x1180c8: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x117F40u: goto label_117f40;
            case 0x117F4Cu: goto label_117f4c;
            case 0x117F60u: goto label_117f60;
            case 0x117F70u: goto label_117f70;
            case 0x117F78u: goto label_117f78;
            case 0x117F94u: goto label_117f94;
            case 0x117F9Cu: goto label_117f9c;
            case 0x117FA8u: goto label_117fa8;
            case 0x117FACu: goto label_117fac;
            case 0x117FB4u: goto label_117fb4;
            case 0x117FD8u: goto label_117fd8;
            case 0x117FF8u: goto label_117ff8;
            case 0x118008u: goto label_118008;
            case 0x11802Cu: goto label_11802c;
            case 0x118070u: goto label_118070;
            case 0x118078u: goto label_118078;
            case 0x118088u: goto label_118088;
            case 0x1180B0u: goto label_1180b0;
            case 0x1180B4u: goto label_1180b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1180CCu;
    // 0x1180cc: 0x0  nop
    ctx->pc = 0x1180ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
