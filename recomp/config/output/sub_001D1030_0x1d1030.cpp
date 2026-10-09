#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D1030
// Address: 0x1d1030 - 0x1d1220
void sub_001D1030_0x1d1030(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D1030_0x1d1030");
#endif

    switch (ctx->pc) {
        case 0x1d1048u: goto label_1d1048;
        case 0x1d1054u: goto label_1d1054;
        case 0x1d1060u: goto label_1d1060;
        case 0x1d106cu: goto label_1d106c;
        case 0x1d1078u: goto label_1d1078;
        case 0x1d1084u: goto label_1d1084;
        case 0x1d1090u: goto label_1d1090;
        case 0x1d109cu: goto label_1d109c;
        case 0x1d10a8u: goto label_1d10a8;
        case 0x1d10b4u: goto label_1d10b4;
        case 0x1d10c8u: goto label_1d10c8;
        case 0x1d1100u: goto label_1d1100;
        case 0x1d1114u: goto label_1d1114;
        case 0x1d112cu: goto label_1d112c;
        case 0x1d1144u: goto label_1d1144;
        case 0x1d1190u: goto label_1d1190;
        case 0x1d11a8u: goto label_1d11a8;
        case 0x1d11d0u: goto label_1d11d0;
        case 0x1d11e8u: goto label_1d11e8;
        case 0x1d1200u: goto label_1d1200;
        default: break;
    }

    ctx->pc = 0x1d1030u;

    // 0x1d1030: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1d1030u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1d1034: 0x24042000  addiu       $a0, $zero, 0x2000
    ctx->pc = 0x1d1034u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
    // 0x1d1038: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1d1038u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1d103c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d103cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d1040: 0xc073470  jal         func_1CD1C0
    ctx->pc = 0x1D1040u;
    SET_GPR_U32(ctx, 31, 0x1D1048u);
    ctx->pc = 0x1D1044u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1040u;
            // 0x1d1044: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CD1C0u;
    if (runtime->hasFunction(0x1CD1C0u)) {
        auto targetFn = runtime->lookupFunction(0x1CD1C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1048u; }
        if (ctx->pc != 0x1D1048u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD1C0_0x1cd1c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1048u; }
        if (ctx->pc != 0x1D1048u) { return; }
    }
    ctx->pc = 0x1D1048u;
label_1d1048:
    // 0x1d1048: 0x24040015  addiu       $a0, $zero, 0x15
    ctx->pc = 0x1d1048u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
    // 0x1d104c: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D104Cu;
    SET_GPR_U32(ctx, 31, 0x1D1054u);
    ctx->pc = 0x1D1050u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D104Cu;
            // 0x1d1050: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1054u; }
        if (ctx->pc != 0x1D1054u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1054u; }
        if (ctx->pc != 0x1D1054u) { return; }
    }
    ctx->pc = 0x1D1054u;
label_1d1054:
    // 0x1d1054: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1d1054u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d1058: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D1058u;
    SET_GPR_U32(ctx, 31, 0x1D1060u);
    ctx->pc = 0x1D105Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1058u;
            // 0x1d105c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1060u; }
        if (ctx->pc != 0x1D1060u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1060u; }
        if (ctx->pc != 0x1D1060u) { return; }
    }
    ctx->pc = 0x1D1060u;
label_1d1060:
    // 0x1d1060: 0x24040012  addiu       $a0, $zero, 0x12
    ctx->pc = 0x1d1060u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1d1064: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D1064u;
    SET_GPR_U32(ctx, 31, 0x1D106Cu);
    ctx->pc = 0x1D1068u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1064u;
            // 0x1d1068: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D106Cu; }
        if (ctx->pc != 0x1D106Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D106Cu; }
        if (ctx->pc != 0x1D106Cu) { return; }
    }
    ctx->pc = 0x1D106Cu;
label_1d106c:
    // 0x1d106c: 0x24040062  addiu       $a0, $zero, 0x62
    ctx->pc = 0x1d106cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 98));
    // 0x1d1070: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D1070u;
    SET_GPR_U32(ctx, 31, 0x1D1078u);
    ctx->pc = 0x1D1074u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1070u;
            // 0x1d1074: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1078u; }
        if (ctx->pc != 0x1D1078u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1078u; }
        if (ctx->pc != 0x1D1078u) { return; }
    }
    ctx->pc = 0x1D1078u;
label_1d1078:
    // 0x1d1078: 0x2404000c  addiu       $a0, $zero, 0xC
    ctx->pc = 0x1d1078u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x1d107c: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D107Cu;
    SET_GPR_U32(ctx, 31, 0x1D1084u);
    ctx->pc = 0x1D1080u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D107Cu;
            // 0x1d1080: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1084u; }
        if (ctx->pc != 0x1D1084u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1084u; }
        if (ctx->pc != 0x1D1084u) { return; }
    }
    ctx->pc = 0x1D1084u;
label_1d1084:
    // 0x1d1084: 0x24040066  addiu       $a0, $zero, 0x66
    ctx->pc = 0x1d1084u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1d1088: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D1088u;
    SET_GPR_U32(ctx, 31, 0x1D1090u);
    ctx->pc = 0x1D108Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1088u;
            // 0x1d108c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1090u; }
        if (ctx->pc != 0x1D1090u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1090u; }
        if (ctx->pc != 0x1D1090u) { return; }
    }
    ctx->pc = 0x1D1090u;
label_1d1090:
    // 0x1d1090: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1d1090u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d1094: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D1094u;
    SET_GPR_U32(ctx, 31, 0x1D109Cu);
    ctx->pc = 0x1D1098u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1094u;
            // 0x1d1098: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D109Cu; }
        if (ctx->pc != 0x1D109Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D109Cu; }
        if (ctx->pc != 0x1D109Cu) { return; }
    }
    ctx->pc = 0x1D109Cu;
label_1d109c:
    // 0x1d109c: 0x24040012  addiu       $a0, $zero, 0x12
    ctx->pc = 0x1d109cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1d10a0: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D10A0u;
    SET_GPR_U32(ctx, 31, 0x1D10A8u);
    ctx->pc = 0x1D10A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D10A0u;
            // 0x1d10a4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D10A8u; }
        if (ctx->pc != 0x1D10A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D10A8u; }
        if (ctx->pc != 0x1D10A8u) { return; }
    }
    ctx->pc = 0x1D10A8u;
label_1d10a8:
    // 0x1d10a8: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1d10a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d10ac: 0xc06bde0  jal         func_1AF780
    ctx->pc = 0x1D10ACu;
    SET_GPR_U32(ctx, 31, 0x1D10B4u);
    ctx->pc = 0x1D10B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D10ACu;
            // 0x1d10b0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D10B4u; }
        if (ctx->pc != 0x1D10B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF780_0x1af780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D10B4u; }
        if (ctx->pc != 0x1D10B4u) { return; }
    }
    ctx->pc = 0x1D10B4u;
label_1d10b4:
    // 0x1d10b4: 0x3c10003c  lui         $s0, 0x3C
    ctx->pc = 0x1d10b4u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)60 << 16));
    // 0x1d10b8: 0x24040400  addiu       $a0, $zero, 0x400
    ctx->pc = 0x1d10b8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
    // 0x1d10bc: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1d10bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1d10c0: 0xc06ca9c  jal         func_1B2A70
    ctx->pc = 0x1D10C0u;
    SET_GPR_U32(ctx, 31, 0x1D10C8u);
    ctx->pc = 0x1D10C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D10C0u;
            // 0x1d10c4: 0x261085b0  addiu       $s0, $s0, -0x7A50 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294935984));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B2A70u;
    if (runtime->hasFunction(0x1B2A70u)) {
        auto targetFn = runtime->lookupFunction(0x1B2A70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D10C8u; }
        if (ctx->pc != 0x1D10C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B2A70_0x1b2a70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D10C8u; }
        if (ctx->pc != 0x1D10C8u) { return; }
    }
    ctx->pc = 0x1D10C8u;
label_1d10c8:
    // 0x1d10c8: 0x3c01003c  lui         $at, 0x3C
    ctx->pc = 0x1d10c8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)60 << 16));
    // 0x1d10cc: 0xac228db8  sw          $v0, -0x7248($at)
    ctx->pc = 0x1d10ccu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294938040), GPR_U32(ctx, 2));
    // 0x1d10d0: 0x3c01003c  lui         $at, 0x3C
    ctx->pc = 0x1d10d0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)60 << 16));
    // 0x1d10d4: 0xac208dc8  sw          $zero, -0x7238($at)
    ctx->pc = 0x1d10d4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294938056), GPR_U32(ctx, 0));
    // 0x1d10d8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d10d8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d10dc: 0x802243d7  lb          $v0, 0x43D7($at)
    ctx->pc = 0x1d10dcu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d10e0: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1D10E0u;
    {
        const bool branch_taken_0x1d10e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D10E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D10E0u;
            // 0x1d10e4: 0x27a40030  addiu       $a0, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d10e0) {
            ctx->pc = 0x1D1108u;
            goto label_1d1108;
        }
    }
    ctx->pc = 0x1D10E8u;
    // 0x1d10e8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d10e8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d10ec: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1d10ecu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d10f0: 0x942443da  lhu         $a0, 0x43DA($at)
    ctx->pc = 0x1d10f0u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d10f4: 0x2405ffff  addiu       $a1, $zero, -0x1
    ctx->pc = 0x1d10f4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d10f8: 0xc073844  jal         func_1CE110
    ctx->pc = 0x1D10F8u;
    SET_GPR_U32(ctx, 31, 0x1D1100u);
    ctx->pc = 0x1D10FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D10F8u;
            // 0x1d10fc: 0x24070002  addiu       $a3, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CE110u;
    if (runtime->hasFunction(0x1CE110u)) {
        auto targetFn = runtime->lookupFunction(0x1CE110u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1100u; }
        if (ctx->pc != 0x1D1100u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CE110_0x1ce110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1100u; }
        if (ctx->pc != 0x1D1100u) { return; }
    }
    ctx->pc = 0x1D1100u;
label_1d1100:
    // 0x1d1100: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1D1100u;
    {
        const bool branch_taken_0x1d1100 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d1100) {
            ctx->pc = 0x1D1144u;
            goto label_1d1144;
        }
    }
    ctx->pc = 0x1D1108u;
label_1d1108:
    // 0x1d1108: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1d1108u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d110c: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1D110Cu;
    SET_GPR_U32(ctx, 31, 0x1D1114u);
    ctx->pc = 0x1D1110u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D110Cu;
            // 0x1d1110: 0x24060020  addiu       $a2, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1114u; }
        if (ctx->pc != 0x1D1114u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1114u; }
        if (ctx->pc != 0x1D1114u) { return; }
    }
    ctx->pc = 0x1D1114u;
label_1d1114:
    // 0x1d1114: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d1114u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d1118: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d1118u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d111c: 0x942643da  lhu         $a2, 0x43DA($at)
    ctx->pc = 0x1d111cu;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d1120: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1d1120u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1d1124: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D1124u;
    SET_GPR_U32(ctx, 31, 0x1D112Cu);
    ctx->pc = 0x1D1128u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1124u;
            // 0x1d1128: 0x24a56300  addiu       $a1, $a1, 0x6300 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25344));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D112Cu; }
        if (ctx->pc != 0x1D112Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D112Cu; }
        if (ctx->pc != 0x1D112Cu) { return; }
    }
    ctx->pc = 0x1D112Cu;
label_1d112c:
    // 0x1d112c: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x1d112cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x1d1130: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1d1130u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1134: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1d1134u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1d1138: 0x24062000  addiu       $a2, $zero, 0x2000
    ctx->pc = 0x1d1138u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
    // 0x1d113c: 0xc06aab4  jal         func_1AAAD0
    ctx->pc = 0x1D113Cu;
    SET_GPR_U32(ctx, 31, 0x1D1144u);
    ctx->pc = 0x1D1140u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D113Cu;
            // 0x1d1140: 0x34470002  ori         $a3, $v0, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)2);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AAAD0u;
    if (runtime->hasFunction(0x1AAAD0u)) {
        auto targetFn = runtime->lookupFunction(0x1AAAD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1144u; }
        if (ctx->pc != 0x1D1144u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AAAD0_0x1aaad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1144u; }
        if (ctx->pc != 0x1D1144u) { return; }
    }
    ctx->pc = 0x1D1144u;
label_1d1144:
    // 0x1d1144: 0x3c010039  lui         $at, 0x39
    ctx->pc = 0x1d1144u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)57 << 16));
    // 0x1d1148: 0x3c02003c  lui         $v0, 0x3C
    ctx->pc = 0x1d1148u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)60 << 16));
    // 0x1d114c: 0xac202690  sw          $zero, 0x2690($at)
    ctx->pc = 0x1d114cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 9872), GPR_U32(ctx, 0));
    // 0x1d1150: 0x3c100039  lui         $s0, 0x39
    ctx->pc = 0x1d1150u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)57 << 16));
    // 0x1d1154: 0x3c010039  lui         $at, 0x39
    ctx->pc = 0x1d1154u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)57 << 16));
    // 0x1d1158: 0x244285b0  addiu       $v0, $v0, -0x7A50
    ctx->pc = 0x1d1158u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294935984));
    // 0x1d115c: 0xac202694  sw          $zero, 0x2694($at)
    ctx->pc = 0x1d115cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 9876), GPR_U32(ctx, 0));
    // 0x1d1160: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1d1160u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1d1164: 0x3c010039  lui         $at, 0x39
    ctx->pc = 0x1d1164u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)57 << 16));
    // 0x1d1168: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1d1168u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d116c: 0xac222688  sw          $v0, 0x2688($at)
    ctx->pc = 0x1d116cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 9864), GPR_U32(ctx, 2));
    // 0x1d1170: 0x24060020  addiu       $a2, $zero, 0x20
    ctx->pc = 0x1d1170u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1d1174: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d1174u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d1178: 0x3c02002f  lui         $v0, 0x2F
    ctx->pc = 0x1d1178u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)47 << 16));
    // 0x1d117c: 0x8c23440c  lw          $v1, 0x440C($at)
    ctx->pc = 0x1d117cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d1180: 0x3442f000  ori         $v0, $v0, 0xF000
    ctx->pc = 0x1d1180u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)61440);
    // 0x1d1184: 0x26102670  addiu       $s0, $s0, 0x2670
    ctx->pc = 0x1d1184u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 9840));
    // 0x1d1188: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1D1188u;
    SET_GPR_U32(ctx, 31, 0x1D1190u);
    ctx->pc = 0x1D118Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1188u;
            // 0x1d118c: 0x628821  addu        $s1, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1190u; }
        if (ctx->pc != 0x1D1190u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1190u; }
        if (ctx->pc != 0x1D1190u) { return; }
    }
    ctx->pc = 0x1D1190u;
label_1d1190:
    // 0x1d1190: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d1190u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d1194: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d1194u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d1198: 0x942643da  lhu         $a2, 0x43DA($at)
    ctx->pc = 0x1d1198u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d119c: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1d119cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1d11a0: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D11A0u;
    SET_GPR_U32(ctx, 31, 0x1D11A8u);
    ctx->pc = 0x1D11A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D11A0u;
            // 0x1d11a4: 0x24a56310  addiu       $a1, $a1, 0x6310 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25360));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D11A8u; }
        if (ctx->pc != 0x1D11A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D11A8u; }
        if (ctx->pc != 0x1D11A8u) { return; }
    }
    ctx->pc = 0x1D11A8u;
label_1d11a8:
    // 0x1d11a8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d11a8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d11ac: 0x802243d7  lb          $v0, 0x43D7($at)
    ctx->pc = 0x1d11acu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d11b0: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1D11B0u;
    {
        const bool branch_taken_0x1d11b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D11B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D11B0u;
            // 0x1d11b4: 0x3c020001  lui         $v0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d11b0) {
            ctx->pc = 0x1D11D4u;
            goto label_1d11d4;
        }
    }
    ctx->pc = 0x1D11B8u;
    // 0x1d11b8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d11b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d11bc: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d11bcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d11c0: 0x942643da  lhu         $a2, 0x43DA($at)
    ctx->pc = 0x1d11c0u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d11c4: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1d11c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1d11c8: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D11C8u;
    SET_GPR_U32(ctx, 31, 0x1D11D0u);
    ctx->pc = 0x1D11CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D11C8u;
            // 0x1d11cc: 0x24a56330  addiu       $a1, $a1, 0x6330 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25392));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D11D0u; }
        if (ctx->pc != 0x1D11D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D11D0u; }
        if (ctx->pc != 0x1D11D0u) { return; }
    }
    ctx->pc = 0x1D11D0u;
label_1d11d0:
    // 0x1d11d0: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x1d11d0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
label_1d11d4:
    // 0x1d11d4: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1d11d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1d11d8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1d11d8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d11dc: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1d11dcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d11e0: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D11E0u;
    SET_GPR_U32(ctx, 31, 0x1D11E8u);
    ctx->pc = 0x1D11E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D11E0u;
            // 0x1d11e4: 0x34460001  ori         $a2, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D11E8u; }
        if (ctx->pc != 0x1D11E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D11E8u; }
        if (ctx->pc != 0x1D11E8u) { return; }
    }
    ctx->pc = 0x1D11E8u;
label_1d11e8:
    // 0x1d11e8: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1d11e8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d11ec: 0x10c00007  beqz        $a2, . + 4 + (0x7 << 2)
    ctx->pc = 0x1D11ECu;
    {
        const bool branch_taken_0x1d11ec = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D11F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D11ECu;
            // 0x1d11f0: 0x3c040039  lui         $a0, 0x39 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)57 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d11ec) {
            ctx->pc = 0x1D120Cu;
            goto label_1d120c;
        }
    }
    ctx->pc = 0x1D11F4u;
    // 0x1d11f4: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1d11f4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d11f8: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1D11F8u;
    SET_GPR_U32(ctx, 31, 0x1D1200u);
    ctx->pc = 0x1D11FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D11F8u;
            // 0x1d11fc: 0x248426d0  addiu       $a0, $a0, 0x26D0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9936));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1200u; }
        if (ctx->pc != 0x1D1200u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1200u; }
        if (ctx->pc != 0x1D1200u) { return; }
    }
    ctx->pc = 0x1D1200u;
label_1d1200:
    // 0x1d1200: 0x3c030039  lui         $v1, 0x39
    ctx->pc = 0x1d1200u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)57 << 16));
    // 0x1d1204: 0x24632ad0  addiu       $v1, $v1, 0x2AD0
    ctx->pc = 0x1d1204u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 10960));
    // 0x1d1208: 0xae03001c  sw          $v1, 0x1C($s0)
    ctx->pc = 0x1d1208u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 3));
label_1d120c:
    // 0x1d120c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1d120cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d1210: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d1210u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d1214: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d1214u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d1218: 0x3e00008  jr          $ra
    ctx->pc = 0x1D1218u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D121Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1218u;
            // 0x1d121c: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D1048u: goto label_1d1048;
            case 0x1D1054u: goto label_1d1054;
            case 0x1D1060u: goto label_1d1060;
            case 0x1D106Cu: goto label_1d106c;
            case 0x1D1078u: goto label_1d1078;
            case 0x1D1084u: goto label_1d1084;
            case 0x1D1090u: goto label_1d1090;
            case 0x1D109Cu: goto label_1d109c;
            case 0x1D10A8u: goto label_1d10a8;
            case 0x1D10B4u: goto label_1d10b4;
            case 0x1D10C8u: goto label_1d10c8;
            case 0x1D1100u: goto label_1d1100;
            case 0x1D1108u: goto label_1d1108;
            case 0x1D1114u: goto label_1d1114;
            case 0x1D112Cu: goto label_1d112c;
            case 0x1D1144u: goto label_1d1144;
            case 0x1D1190u: goto label_1d1190;
            case 0x1D11A8u: goto label_1d11a8;
            case 0x1D11D0u: goto label_1d11d0;
            case 0x1D11D4u: goto label_1d11d4;
            case 0x1D11E8u: goto label_1d11e8;
            case 0x1D1200u: goto label_1d1200;
            case 0x1D120Cu: goto label_1d120c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D1220u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
