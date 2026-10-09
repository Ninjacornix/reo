#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E74E4
// Address: 0x1e74e4 - 0x1e763c
void sub_001E74E4_0x1e74e4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E74E4_0x1e74e4");
#endif

    switch (ctx->pc) {
        case 0x1e7514u: goto label_1e7514;
        case 0x1e7518u: goto label_1e7518;
        case 0x1e7530u: goto label_1e7530;
        case 0x1e7550u: goto label_1e7550;
        case 0x1e756cu: goto label_1e756c;
        case 0x1e7590u: goto label_1e7590;
        case 0x1e75bcu: goto label_1e75bc;
        case 0x1e75f0u: goto label_1e75f0;
        case 0x1e7600u: goto label_1e7600;
        case 0x1e7610u: goto label_1e7610;
        case 0x1e7620u: goto label_1e7620;
        default: break;
    }

    ctx->pc = 0x1e74e4u;

    // 0x1e74e4: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e74e4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e74e8: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e74e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e74ec: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e74ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e74f0: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e74f0u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e74f4: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e74f4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e74f8: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e74f8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e74fc: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e74fcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e7500: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e7500u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e7504: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1e7504u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1e7508: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e7508u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e750c: 0xc07c6e1  jal         func_1F1B84
    ctx->pc = 0x1E750Cu;
    SET_GPR_U32(ctx, 31, 0x1E7514u);
    ctx->pc = 0x1F1B84u;
    if (runtime->hasFunction(0x1F1B84u)) {
        auto targetFn = runtime->lookupFunction(0x1F1B84u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7514u; }
        if (ctx->pc != 0x1E7514u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1B84_0x1f1b84(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7514u; }
        if (ctx->pc != 0x1E7514u) { return; }
    }
    ctx->pc = 0x1E7514u;
label_1e7514:
    // 0x1e7514: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e7514u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
label_1e7518:
    // 0x1e7518: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e7518u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e751c: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1e751cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1e7520: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e7520u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7524: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e7524u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e7528: 0xc07c5a2  jal         func_1F1688
    ctx->pc = 0x1E7528u;
    SET_GPR_U32(ctx, 31, 0x1E7530u);
    ctx->pc = 0x1F1688u;
    if (runtime->hasFunction(0x1F1688u)) {
        auto targetFn = runtime->lookupFunction(0x1F1688u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7530u; }
        if (ctx->pc != 0x1E7530u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1688_0x1f1688(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7530u; }
        if (ctx->pc != 0x1E7530u) { return; }
    }
    ctx->pc = 0x1E7530u;
label_1e7530:
    // 0x1e7530: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E7530u;
    {
        const bool branch_taken_0x1e7530 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7530) {
            ctx->pc = 0x1E7540u;
            goto label_1e7540;
        }
    }
    ctx->pc = 0x1E7538u;
    // 0x1e7538: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1E7538u;
    {
        const bool branch_taken_0x1e7538 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7538) {
            ctx->pc = 0x1E7578u;
            goto label_1e7578;
        }
    }
    ctx->pc = 0x1E7540u;
label_1e7540:
    // 0x1e7540: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e7540u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e7544: 0x24051000  addiu       $a1, $zero, 0x1000
    ctx->pc = 0x1e7544u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x1e7548: 0xc07c670  jal         func_1F19C0
    ctx->pc = 0x1E7548u;
    SET_GPR_U32(ctx, 31, 0x1E7550u);
    ctx->pc = 0x1F19C0u;
    if (runtime->hasFunction(0x1F19C0u)) {
        auto targetFn = runtime->lookupFunction(0x1F19C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7550u; }
        if (ctx->pc != 0x1E7550u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F19C0_0x1f19c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7550u; }
        if (ctx->pc != 0x1E7550u) { return; }
    }
    ctx->pc = 0x1E7550u;
label_1e7550:
    // 0x1e7550: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E7550u;
    {
        const bool branch_taken_0x1e7550 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e7550) {
            ctx->pc = 0x1E7560u;
            goto label_1e7560;
        }
    }
    ctx->pc = 0x1E7558u;
    // 0x1e7558: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1E7558u;
    {
        const bool branch_taken_0x1e7558 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7558) {
            ctx->pc = 0x1E7578u;
            goto label_1e7578;
        }
    }
    ctx->pc = 0x1E7560u;
label_1e7560:
    // 0x1e7560: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e7560u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e7564: 0xc07c6eb  jal         func_1F1BAC
    ctx->pc = 0x1E7564u;
    SET_GPR_U32(ctx, 31, 0x1E756Cu);
    ctx->pc = 0x1F1BACu;
    if (runtime->hasFunction(0x1F1BACu)) {
        auto targetFn = runtime->lookupFunction(0x1F1BACu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E756Cu; }
        if (ctx->pc != 0x1E756Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1BAC_0x1f1bac(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E756Cu; }
        if (ctx->pc != 0x1E756Cu) { return; }
    }
    ctx->pc = 0x1E756Cu;
label_1e756c:
    // 0x1e756c: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e756cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e7570: 0x1000ffe9  b           . + 4 + (-0x17 << 2)
    ctx->pc = 0x1E7570u;
    {
        const bool branch_taken_0x1e7570 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7570) {
            ctx->pc = 0x1E7518u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1e7518;
        }
    }
    ctx->pc = 0x1E7578u;
label_1e7578:
    // 0x1e7578: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e7578u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e757c: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1e757cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1e7580: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e7580u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7584: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e7584u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e7588: 0xc07c5a2  jal         func_1F1688
    ctx->pc = 0x1E7588u;
    SET_GPR_U32(ctx, 31, 0x1E7590u);
    ctx->pc = 0x1F1688u;
    if (runtime->hasFunction(0x1F1688u)) {
        auto targetFn = runtime->lookupFunction(0x1F1688u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7590u; }
        if (ctx->pc != 0x1E7590u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1688_0x1f1688(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7590u; }
        if (ctx->pc != 0x1E7590u) { return; }
    }
    ctx->pc = 0x1E7590u;
label_1e7590:
    // 0x1e7590: 0x1040001b  beqz        $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x1E7590u;
    {
        const bool branch_taken_0x1e7590 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7590) {
            ctx->pc = 0x1E7600u;
            goto label_1e7600;
        }
    }
    ctx->pc = 0x1E7598u;
    // 0x1e7598: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e7598u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e759c: 0x27c3000c  addiu       $v1, $fp, 0xC
    ctx->pc = 0x1e759cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 12));
    // 0x1e75a0: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e75a0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e75a4: 0x60282d  daddu       $a1, $v1, $zero
    ctx->pc = 0x1e75a4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e75a8: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x1e75a8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1e75ac: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x1e75acu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e75b0: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1e75b0u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e75b4: 0xc07c80a  jal         func_1F2028
    ctx->pc = 0x1E75B4u;
    SET_GPR_U32(ctx, 31, 0x1E75BCu);
    ctx->pc = 0x1F2028u;
    if (runtime->hasFunction(0x1F2028u)) {
        auto targetFn = runtime->lookupFunction(0x1F2028u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E75BCu; }
        if (ctx->pc != 0x1E75BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2028_0x1f2028(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E75BCu; }
        if (ctx->pc != 0x1E75BCu) { return; }
    }
    ctx->pc = 0x1E75BCu;
label_1e75bc:
    // 0x1e75bc: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e75bcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e75c0: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e75c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e75c4: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1E75C4u;
    {
        const bool branch_taken_0x1e75c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e75c4) {
            ctx->pc = 0x1E75D8u;
            goto label_1e75d8;
        }
    }
    ctx->pc = 0x1E75CCu;
    // 0x1e75cc: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e75ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e75d0: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1E75D0u;
    {
        const bool branch_taken_0x1e75d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e75d0) {
            ctx->pc = 0x1E7624u;
            goto label_1e7624;
        }
    }
    ctx->pc = 0x1E75D8u;
label_1e75d8:
    // 0x1e75d8: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e75d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e75dc: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1e75dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1e75e0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e75e0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e75e4: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e75e4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e75e8: 0xc07c47a  jal         func_1F11E8
    ctx->pc = 0x1E75E8u;
    SET_GPR_U32(ctx, 31, 0x1E75F0u);
    ctx->pc = 0x1F11E8u;
    if (runtime->hasFunction(0x1F11E8u)) {
        auto targetFn = runtime->lookupFunction(0x1F11E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E75F0u; }
        if (ctx->pc != 0x1E75F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F11E8_0x1f11e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E75F0u; }
        if (ctx->pc != 0x1E75F0u) { return; }
    }
    ctx->pc = 0x1E75F0u;
label_1e75f0:
    // 0x1e75f0: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e75f0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e75f4: 0x24050200  addiu       $a1, $zero, 0x200
    ctx->pc = 0x1e75f4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
    // 0x1e75f8: 0xc07c680  jal         func_1F1A00
    ctx->pc = 0x1E75F8u;
    SET_GPR_U32(ctx, 31, 0x1E7600u);
    ctx->pc = 0x1F1A00u;
    if (runtime->hasFunction(0x1F1A00u)) {
        auto targetFn = runtime->lookupFunction(0x1F1A00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7600u; }
        if (ctx->pc != 0x1E7600u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1A00_0x1f1a00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7600u; }
        if (ctx->pc != 0x1E7600u) { return; }
    }
    ctx->pc = 0x1E7600u;
label_1e7600:
    // 0x1e7600: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e7600u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e7604: 0x24051000  addiu       $a1, $zero, 0x1000
    ctx->pc = 0x1e7604u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x1e7608: 0xc07c680  jal         func_1F1A00
    ctx->pc = 0x1E7608u;
    SET_GPR_U32(ctx, 31, 0x1E7610u);
    ctx->pc = 0x1F1A00u;
    if (runtime->hasFunction(0x1F1A00u)) {
        auto targetFn = runtime->lookupFunction(0x1F1A00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7610u; }
        if (ctx->pc != 0x1E7610u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1A00_0x1f1a00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7610u; }
        if (ctx->pc != 0x1E7610u) { return; }
    }
    ctx->pc = 0x1E7610u;
label_1e7610:
    // 0x1e7610: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e7610u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e7614: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1e7614u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e7618: 0xc07cd19  jal         func_1F3464
    ctx->pc = 0x1E7618u;
    SET_GPR_U32(ctx, 31, 0x1E7620u);
    ctx->pc = 0x1F3464u;
    if (runtime->hasFunction(0x1F3464u)) {
        auto targetFn = runtime->lookupFunction(0x1F3464u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7620u; }
        if (ctx->pc != 0x1E7620u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F3464_0x1f3464(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7620u; }
        if (ctx->pc != 0x1E7620u) { return; }
    }
    ctx->pc = 0x1E7620u;
label_1e7620:
    // 0x1e7620: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e7620u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e7624:
    // 0x1e7624: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e7624u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7628: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e7628u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e762c: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e762cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e7630: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e7630u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e7634: 0x3e00008  jr          $ra
    ctx->pc = 0x1E7634u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E7514u: goto label_1e7514;
            case 0x1E7518u: goto label_1e7518;
            case 0x1E7530u: goto label_1e7530;
            case 0x1E7540u: goto label_1e7540;
            case 0x1E7550u: goto label_1e7550;
            case 0x1E7560u: goto label_1e7560;
            case 0x1E756Cu: goto label_1e756c;
            case 0x1E7578u: goto label_1e7578;
            case 0x1E7590u: goto label_1e7590;
            case 0x1E75BCu: goto label_1e75bc;
            case 0x1E75D8u: goto label_1e75d8;
            case 0x1E75F0u: goto label_1e75f0;
            case 0x1E7600u: goto label_1e7600;
            case 0x1E7610u: goto label_1e7610;
            case 0x1E7620u: goto label_1e7620;
            case 0x1E7624u: goto label_1e7624;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E763Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
