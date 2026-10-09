#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E986C
// Address: 0x1e986c - 0x1e99d8
void sub_001E986C_0x1e986c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E986C_0x1e986c");
#endif

    switch (ctx->pc) {
        case 0x1e9880u: goto label_1e9880;
        case 0x1e98a4u: goto label_1e98a4;
        case 0x1e98c4u: goto label_1e98c4;
        case 0x1e9900u: goto label_1e9900;
        case 0x1e9924u: goto label_1e9924;
        case 0x1e9948u: goto label_1e9948;
        case 0x1e9958u: goto label_1e9958;
        case 0x1e996cu: goto label_1e996c;
        case 0x1e9984u: goto label_1e9984;
        case 0x1e99a8u: goto label_1e99a8;
        case 0x1e99b8u: goto label_1e99b8;
        default: break;
    }

    ctx->pc = 0x1e986cu;

    // 0x1e986c: 0x27bdf7d0  addiu       $sp, $sp, -0x830
    ctx->pc = 0x1e986cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294965200));
    // 0x1e9870: 0xffbe0820  sd          $fp, 0x820($sp)
    ctx->pc = 0x1e9870u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 2080), GPR_U64(ctx, 30));
    // 0x1e9874: 0xffbf0828  sd          $ra, 0x828($sp)
    ctx->pc = 0x1e9874u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 2088), GPR_U64(ctx, 31));
    // 0x1e9878: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e9878u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e987c: 0xafc00000  sw          $zero, 0x0($fp)
    ctx->pc = 0x1e987cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 0));
label_1e9880:
    // 0x1e9880: 0x27c20810  addiu       $v0, $fp, 0x810
    ctx->pc = 0x1e9880u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 2064));
    // 0x1e9884: 0x27c30812  addiu       $v1, $fp, 0x812
    ctx->pc = 0x1e9884u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 2066));
    // 0x1e9888: 0x27c60814  addiu       $a2, $fp, 0x814
    ctx->pc = 0x1e9888u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 30), 2068));
    // 0x1e988c: 0x27c70818  addiu       $a3, $fp, 0x818
    ctx->pc = 0x1e988cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 30), 2072));
    // 0x1e9890: 0x27c80010  addiu       $t0, $fp, 0x10
    ctx->pc = 0x1e9890u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 30), 16));
    // 0x1e9894: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e9894u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9898: 0x60282d  daddu       $a1, $v1, $zero
    ctx->pc = 0x1e9898u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e989c: 0xc076158  jal         func_1D8560
    ctx->pc = 0x1E989Cu;
    SET_GPR_U32(ctx, 31, 0x1E98A4u);
    ctx->pc = 0x1D8560u;
    if (runtime->hasFunction(0x1D8560u)) {
        auto targetFn = runtime->lookupFunction(0x1D8560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E98A4u; }
        if (ctx->pc != 0x1E98A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D8560_0x1d8560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E98A4u; }
        if (ctx->pc != 0x1E98A4u) { return; }
    }
    ctx->pc = 0x1E98A4u;
label_1e98a4:
    // 0x1e98a4: 0xafc20000  sw          $v0, 0x0($fp)
    ctx->pc = 0x1e98a4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 2));
    // 0x1e98a8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e98a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e98ac: 0x14400044  bnez        $v0, . + 4 + (0x44 << 2)
    ctx->pc = 0x1E98ACu;
    {
        const bool branch_taken_0x1e98ac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e98ac) {
            ctx->pc = 0x1E99C0u;
            goto label_1e99c0;
        }
    }
    ctx->pc = 0x1E98B4u;
    // 0x1e98b4: 0x87c20810  lh          $v0, 0x810($fp)
    ctx->pc = 0x1e98b4u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 2064)));
    // 0x1e98b8: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e98b8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e98bc: 0xc07a230  jal         func_1E88C0
    ctx->pc = 0x1E98BCu;
    SET_GPR_U32(ctx, 31, 0x1E98C4u);
    ctx->pc = 0x1E88C0u;
    if (runtime->hasFunction(0x1E88C0u)) {
        auto targetFn = runtime->lookupFunction(0x1E88C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E98C4u; }
        if (ctx->pc != 0x1E98C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E88C0_0x1e88c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E98C4u; }
        if (ctx->pc != 0x1E98C4u) { return; }
    }
    ctx->pc = 0x1E98C4u;
label_1e98c4:
    // 0x1e98c4: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1e98c4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1e98c8: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e98c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e98cc: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E98CCu;
    {
        const bool branch_taken_0x1e98cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e98cc) {
            ctx->pc = 0x1E98DCu;
            goto label_1e98dc;
        }
    }
    ctx->pc = 0x1E98D4u;
    // 0x1e98d4: 0x1000ffea  b           . + 4 + (-0x16 << 2)
    ctx->pc = 0x1E98D4u;
    {
        const bool branch_taken_0x1e98d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e98d4) {
            ctx->pc = 0x1E9880u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1e9880;
        }
    }
    ctx->pc = 0x1E98DCu;
label_1e98dc:
    // 0x1e98dc: 0x27c20008  addiu       $v0, $fp, 0x8
    ctx->pc = 0x1e98dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 8));
    // 0x1e98e0: 0x97c30812  lhu         $v1, 0x812($fp)
    ctx->pc = 0x1e98e0u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 2066)));
    // 0x1e98e4: 0x8f84802c  lw          $a0, -0x7FD4($gp)
    ctx->pc = 0x1e98e4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 28), 4294934572)));
    // 0x1e98e8: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e98e8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e98ec: 0x60302d  daddu       $a2, $v1, $zero
    ctx->pc = 0x1e98ecu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e98f0: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x1e98f0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e98f4: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1e98f4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e98f8: 0xc07c80a  jal         func_1F2028
    ctx->pc = 0x1E98F8u;
    SET_GPR_U32(ctx, 31, 0x1E9900u);
    ctx->pc = 0x1F2028u;
    if (runtime->hasFunction(0x1F2028u)) {
        auto targetFn = runtime->lookupFunction(0x1F2028u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9900u; }
        if (ctx->pc != 0x1E9900u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2028_0x1f2028(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9900u; }
        if (ctx->pc != 0x1E9900u) { return; }
    }
    ctx->pc = 0x1E9900u;
label_1e9900:
    // 0x1e9900: 0xafc20000  sw          $v0, 0x0($fp)
    ctx->pc = 0x1e9900u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 2));
    // 0x1e9904: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e9904u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e9908: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1E9908u;
    {
        const bool branch_taken_0x1e9908 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e9908) {
            ctx->pc = 0x1E992Cu;
            goto label_1e992c;
        }
    }
    ctx->pc = 0x1E9910u;
    // 0x1e9910: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x1e9910u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x1e9914: 0x24848080  addiu       $a0, $a0, -0x7F80
    ctx->pc = 0x1e9914u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294934656));
    // 0x1e9918: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1e9918u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e991c: 0xc045a12  jal         func_116848
    ctx->pc = 0x1E991Cu;
    SET_GPR_U32(ctx, 31, 0x1E9924u);
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9924u; }
        if (ctx->pc != 0x1E9924u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9924u; }
        if (ctx->pc != 0x1E9924u) { return; }
    }
    ctx->pc = 0x1E9924u;
label_1e9924:
    // 0x1e9924: 0x10000026  b           . + 4 + (0x26 << 2)
    ctx->pc = 0x1E9924u;
    {
        const bool branch_taken_0x1e9924 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e9924) {
            ctx->pc = 0x1E99C0u;
            goto label_1e99c0;
        }
    }
    ctx->pc = 0x1E992Cu;
label_1e992c:
    // 0x1e992c: 0x27c20010  addiu       $v0, $fp, 0x10
    ctx->pc = 0x1e992cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 16));
    // 0x1e9930: 0x87c30812  lh          $v1, 0x812($fp)
    ctx->pc = 0x1e9930u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 30), 2066)));
    // 0x1e9934: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1e9934u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e9938: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e9938u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e993c: 0x60302d  daddu       $a2, $v1, $zero
    ctx->pc = 0x1e993cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9940: 0xc07cd5f  jal         func_1F357C
    ctx->pc = 0x1E9940u;
    SET_GPR_U32(ctx, 31, 0x1E9948u);
    ctx->pc = 0x1F357Cu;
    if (runtime->hasFunction(0x1F357Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F357Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9948u; }
        if (ctx->pc != 0x1E9948u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F357C_0x1f357c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9948u; }
        if (ctx->pc != 0x1E9948u) { return; }
    }
    ctx->pc = 0x1E9948u;
label_1e9948:
    // 0x1e9948: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1e9948u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e994c: 0x8fc50814  lw          $a1, 0x814($fp)
    ctx->pc = 0x1e994cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 2068)));
    // 0x1e9950: 0xc07cc93  jal         func_1F324C
    ctx->pc = 0x1E9950u;
    SET_GPR_U32(ctx, 31, 0x1E9958u);
    ctx->pc = 0x1F324Cu;
    if (runtime->hasFunction(0x1F324Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F324Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9958u; }
        if (ctx->pc != 0x1E9958u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F324C_0x1f324c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9958u; }
        if (ctx->pc != 0x1E9958u) { return; }
    }
    ctx->pc = 0x1E9958u;
label_1e9958:
    // 0x1e9958: 0x97c20818  lhu         $v0, 0x818($fp)
    ctx->pc = 0x1e9958u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 2072)));
    // 0x1e995c: 0x8fc40008  lw          $a0, 0x8($fp)
    ctx->pc = 0x1e995cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e9960: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e9960u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9964: 0xc07ccd5  jal         func_1F3354
    ctx->pc = 0x1E9964u;
    SET_GPR_U32(ctx, 31, 0x1E996Cu);
    ctx->pc = 0x1F3354u;
    if (runtime->hasFunction(0x1F3354u)) {
        auto targetFn = runtime->lookupFunction(0x1F3354u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E996Cu; }
        if (ctx->pc != 0x1E996Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F3354_0x1f3354(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E996Cu; }
        if (ctx->pc != 0x1E996Cu) { return; }
    }
    ctx->pc = 0x1E996Cu;
label_1e996c:
    // 0x1e996c: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e996cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e9970: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1e9970u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1e9974: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e9974u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e9978: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e9978u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e997c: 0xc07c47a  jal         func_1F11E8
    ctx->pc = 0x1E997Cu;
    SET_GPR_U32(ctx, 31, 0x1E9984u);
    ctx->pc = 0x1F11E8u;
    if (runtime->hasFunction(0x1F11E8u)) {
        auto targetFn = runtime->lookupFunction(0x1F11E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9984u; }
        if (ctx->pc != 0x1E9984u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F11E8_0x1f11e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E9984u; }
        if (ctx->pc != 0x1E9984u) { return; }
    }
    ctx->pc = 0x1E9984u;
label_1e9984:
    // 0x1e9984: 0xafc20000  sw          $v0, 0x0($fp)
    ctx->pc = 0x1e9984u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 2));
    // 0x1e9988: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e9988u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e998c: 0x1040ffbc  beqz        $v0, . + 4 + (-0x44 << 2)
    ctx->pc = 0x1E998Cu;
    {
        const bool branch_taken_0x1e998c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e998c) {
            ctx->pc = 0x1E9880u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1e9880;
        }
    }
    ctx->pc = 0x1E9994u;
    // 0x1e9994: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x1e9994u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x1e9998: 0x248480a0  addiu       $a0, $a0, -0x7F60
    ctx->pc = 0x1e9998u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294934688));
    // 0x1e999c: 0x8fc50000  lw          $a1, 0x0($fp)
    ctx->pc = 0x1e999cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e99a0: 0xc045a12  jal         func_116848
    ctx->pc = 0x1E99A0u;
    SET_GPR_U32(ctx, 31, 0x1E99A8u);
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E99A8u; }
        if (ctx->pc != 0x1E99A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E99A8u; }
        if (ctx->pc != 0x1E99A8u) { return; }
    }
    ctx->pc = 0x1E99A8u;
label_1e99a8:
    // 0x1e99a8: 0x8f84802c  lw          $a0, -0x7FD4($gp)
    ctx->pc = 0x1e99a8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 28), 4294934572)));
    // 0x1e99ac: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e99acu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e99b0: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E99B0u;
    SET_GPR_U32(ctx, 31, 0x1E99B8u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E99B8u; }
        if (ctx->pc != 0x1E99B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E99B8u; }
        if (ctx->pc != 0x1E99B8u) { return; }
    }
    ctx->pc = 0x1E99B8u;
label_1e99b8:
    // 0x1e99b8: 0x10000001  b           . + 4 + (0x1 << 2)
    ctx->pc = 0x1E99B8u;
    {
        const bool branch_taken_0x1e99b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e99b8) {
            ctx->pc = 0x1E99C0u;
            goto label_1e99c0;
        }
    }
    ctx->pc = 0x1E99C0u;
label_1e99c0:
    // 0x1e99c0: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e99c0u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e99c4: 0xdfbe0820  ld          $fp, 0x820($sp)
    ctx->pc = 0x1e99c4u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 2080)));
    // 0x1e99c8: 0xdfbf0828  ld          $ra, 0x828($sp)
    ctx->pc = 0x1e99c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 2088)));
    // 0x1e99cc: 0x27bd0830  addiu       $sp, $sp, 0x830
    ctx->pc = 0x1e99ccu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 2096));
    // 0x1e99d0: 0x3e00008  jr          $ra
    ctx->pc = 0x1E99D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E9880u: goto label_1e9880;
            case 0x1E98A4u: goto label_1e98a4;
            case 0x1E98C4u: goto label_1e98c4;
            case 0x1E98DCu: goto label_1e98dc;
            case 0x1E9900u: goto label_1e9900;
            case 0x1E9924u: goto label_1e9924;
            case 0x1E992Cu: goto label_1e992c;
            case 0x1E9948u: goto label_1e9948;
            case 0x1E9958u: goto label_1e9958;
            case 0x1E996Cu: goto label_1e996c;
            case 0x1E9984u: goto label_1e9984;
            case 0x1E99A8u: goto label_1e99a8;
            case 0x1E99B8u: goto label_1e99b8;
            case 0x1E99C0u: goto label_1e99c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E99D8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
