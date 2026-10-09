#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F2810
// Address: 0x1f2810 - 0x1f2b08
void sub_001F2810_0x1f2810(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F2810_0x1f2810");
#endif

    switch (ctx->pc) {
        case 0x1f2840u: goto label_1f2840;
        case 0x1f2868u: goto label_1f2868;
        case 0x1f2888u: goto label_1f2888;
        case 0x1f28acu: goto label_1f28ac;
        case 0x1f28d8u: goto label_1f28d8;
        case 0x1f28ecu: goto label_1f28ec;
        case 0x1f2914u: goto label_1f2914;
        case 0x1f2920u: goto label_1f2920;
        case 0x1f2940u: goto label_1f2940;
        case 0x1f296cu: goto label_1f296c;
        case 0x1f29a0u: goto label_1f29a0;
        case 0x1f29bcu: goto label_1f29bc;
        case 0x1f29ecu: goto label_1f29ec;
        case 0x1f29f8u: goto label_1f29f8;
        case 0x1f2a18u: goto label_1f2a18;
        case 0x1f2a44u: goto label_1f2a44;
        case 0x1f2a78u: goto label_1f2a78;
        case 0x1f2a94u: goto label_1f2a94;
        case 0x1f2ac4u: goto label_1f2ac4;
        default: break;
    }

    ctx->pc = 0x1f2810u;

    // 0x1f2810: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1f2810u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1f2814: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1f2814u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1f2818: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1f2818u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1f281c: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f281cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2820: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f2820u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f2824: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1f2824u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1f2828: 0xafc00008  sw          $zero, 0x8($fp)
    ctx->pc = 0x1f2828u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 0));
    // 0x1f282c: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f282cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f2830: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1f2830u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1f2834: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1f2834u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f2838: 0xc07cb99  jal         func_1F2E64
    ctx->pc = 0x1F2838u;
    SET_GPR_U32(ctx, 31, 0x1F2840u);
    ctx->pc = 0x1F2E64u;
    if (runtime->hasFunction(0x1F2E64u)) {
        auto targetFn = runtime->lookupFunction(0x1F2E64u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2840u; }
        if (ctx->pc != 0x1F2840u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2E64_0x1f2e64(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2840u; }
        if (ctx->pc != 0x1F2840u) { return; }
    }
    ctx->pc = 0x1F2840u;
label_1f2840:
    // 0x1f2840: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1f2840u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1f2844: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f2844u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f2848: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F2848u;
    {
        const bool branch_taken_0x1f2848 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f2848) {
            ctx->pc = 0x1F285Cu;
            goto label_1f285c;
        }
    }
    ctx->pc = 0x1F2850u;
    // 0x1f2850: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f2850u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f2854: 0x1000009c  b           . + 4 + (0x9C << 2)
    ctx->pc = 0x1F2854u;
    {
        const bool branch_taken_0x1f2854 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f2854) {
            ctx->pc = 0x1F2AC8u;
            goto label_1f2ac8;
        }
    }
    ctx->pc = 0x1F285Cu;
label_1f285c:
    // 0x1f285c: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1f285cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f2860: 0xc07c6cd  jal         func_1F1B34
    ctx->pc = 0x1F2860u;
    SET_GPR_U32(ctx, 31, 0x1F2868u);
    ctx->pc = 0x1F1B34u;
    if (runtime->hasFunction(0x1F1B34u)) {
        auto targetFn = runtime->lookupFunction(0x1F1B34u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2868u; }
        if (ctx->pc != 0x1F2868u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1B34_0x1f1b34(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2868u; }
        if (ctx->pc != 0x1F2868u) { return; }
    }
    ctx->pc = 0x1F2868u;
label_1f2868:
    // 0x1f2868: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1f2868u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f286c: 0x9463005e  lhu         $v1, 0x5E($v1)
    ctx->pc = 0x1f286cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 94)));
    // 0x1f2870: 0x14430028  bne         $v0, $v1, . + 4 + (0x28 << 2)
    ctx->pc = 0x1F2870u;
    {
        const bool branch_taken_0x1f2870 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1f2870) {
            ctx->pc = 0x1F2914u;
            goto label_1f2914;
        }
    }
    ctx->pc = 0x1F2878u;
    // 0x1f2878: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1f2878u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f287c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1f287cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2880: 0xc07c6a9  jal         func_1F1AA4
    ctx->pc = 0x1F2880u;
    SET_GPR_U32(ctx, 31, 0x1F2888u);
    ctx->pc = 0x1F1AA4u;
    if (runtime->hasFunction(0x1F1AA4u)) {
        auto targetFn = runtime->lookupFunction(0x1F1AA4u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2888u; }
        if (ctx->pc != 0x1F2888u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1AA4_0x1f1aa4(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2888u; }
        if (ctx->pc != 0x1F2888u) { return; }
    }
    ctx->pc = 0x1F2888u;
label_1f2888:
    // 0x1f2888: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1f2888u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f288c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f288cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2890: 0x8c420040  lw          $v0, 0x40($v0)
    ctx->pc = 0x1f2890u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 64)));
    // 0x1f2894: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1f2894u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1f2898: 0xac620040  sw          $v0, 0x40($v1)
    ctx->pc = 0x1f2898u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 64), GPR_U32(ctx, 2));
    // 0x1f289c: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f289cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f28a0: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1f28a0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f28a4: 0xc07c47a  jal         func_1F11E8
    ctx->pc = 0x1F28A4u;
    SET_GPR_U32(ctx, 31, 0x1F28ACu);
    ctx->pc = 0x1F11E8u;
    if (runtime->hasFunction(0x1F11E8u)) {
        auto targetFn = runtime->lookupFunction(0x1F11E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F28ACu; }
        if (ctx->pc != 0x1F28ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F11E8_0x1f11e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F28ACu; }
        if (ctx->pc != 0x1F28ACu) { return; }
    }
    ctx->pc = 0x1F28ACu;
label_1f28ac:
    // 0x1f28ac: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1f28acu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1f28b0: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f28b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f28b4: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F28B4u;
    {
        const bool branch_taken_0x1f28b4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f28b4) {
            ctx->pc = 0x1F28C8u;
            goto label_1f28c8;
        }
    }
    ctx->pc = 0x1F28BCu;
    // 0x1f28bc: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f28bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f28c0: 0x10000081  b           . + 4 + (0x81 << 2)
    ctx->pc = 0x1F28C0u;
    {
        const bool branch_taken_0x1f28c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f28c0) {
            ctx->pc = 0x1F2AC8u;
            goto label_1f2ac8;
        }
    }
    ctx->pc = 0x1F28C8u;
label_1f28c8:
    // 0x1f28c8: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f28c8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f28cc: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1f28ccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f28d0: 0xc07c44b  jal         func_1F112C
    ctx->pc = 0x1F28D0u;
    SET_GPR_U32(ctx, 31, 0x1F28D8u);
    ctx->pc = 0x1F112Cu;
    if (runtime->hasFunction(0x1F112Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F112Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F28D8u; }
        if (ctx->pc != 0x1F28D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F112C_0x1f112c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F28D8u; }
        if (ctx->pc != 0x1F28D8u) { return; }
    }
    ctx->pc = 0x1F28D8u;
label_1f28d8:
    // 0x1f28d8: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1F28D8u;
    {
        const bool branch_taken_0x1f28d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f28d8) {
            ctx->pc = 0x1F2914u;
            goto label_1f2914;
        }
    }
    ctx->pc = 0x1F28E0u;
    // 0x1f28e0: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f28e0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f28e4: 0xc07c441  jal         func_1F1104
    ctx->pc = 0x1F28E4u;
    SET_GPR_U32(ctx, 31, 0x1F28ECu);
    ctx->pc = 0x1F1104u;
    if (runtime->hasFunction(0x1F1104u)) {
        auto targetFn = runtime->lookupFunction(0x1F1104u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F28ECu; }
        if (ctx->pc != 0x1F28ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1104_0x1f1104(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F28ECu; }
        if (ctx->pc != 0x1F28ECu) { return; }
    }
    ctx->pc = 0x1F28ECu;
label_1f28ec:
    // 0x1f28ec: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1f28ecu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f28f0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f28f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f28f4: 0x94420070  lhu         $v0, 0x70($v0)
    ctx->pc = 0x1f28f4u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 112)));
    // 0x1f28f8: 0x43102b  sltu        $v0, $v0, $v1
    ctx->pc = 0x1f28f8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1f28fc: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1F28FCu;
    {
        const bool branch_taken_0x1f28fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f28fc) {
            ctx->pc = 0x1F2914u;
            goto label_1f2914;
        }
    }
    ctx->pc = 0x1F2904u;
    // 0x1f2904: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f2904u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2908: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1f2908u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f290c: 0xc07c46b  jal         func_1F11AC
    ctx->pc = 0x1F290Cu;
    SET_GPR_U32(ctx, 31, 0x1F2914u);
    ctx->pc = 0x1F11ACu;
    if (runtime->hasFunction(0x1F11ACu)) {
        auto targetFn = runtime->lookupFunction(0x1F11ACu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2914u; }
        if (ctx->pc != 0x1F2914u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F11AC_0x1f11ac(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2914u; }
        if (ctx->pc != 0x1F2914u) { return; }
    }
    ctx->pc = 0x1F2914u;
label_1f2914:
    // 0x1f2914: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1f2914u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f2918: 0xc07c6cd  jal         func_1F1B34
    ctx->pc = 0x1F2918u;
    SET_GPR_U32(ctx, 31, 0x1F2920u);
    ctx->pc = 0x1F1B34u;
    if (runtime->hasFunction(0x1F1B34u)) {
        auto targetFn = runtime->lookupFunction(0x1F1B34u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2920u; }
        if (ctx->pc != 0x1F2920u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1B34_0x1f1b34(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2920u; }
        if (ctx->pc != 0x1F2920u) { return; }
    }
    ctx->pc = 0x1F2920u;
label_1f2920:
    // 0x1f2920: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1f2920u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2924: 0x94630064  lhu         $v1, 0x64($v1)
    ctx->pc = 0x1f2924u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 100)));
    // 0x1f2928: 0x14430030  bne         $v0, $v1, . + 4 + (0x30 << 2)
    ctx->pc = 0x1F2928u;
    {
        const bool branch_taken_0x1f2928 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1f2928) {
            ctx->pc = 0x1F29ECu;
            goto label_1f29ec;
        }
    }
    ctx->pc = 0x1F2930u;
    // 0x1f2930: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1f2930u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f2934: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1f2934u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f2938: 0xc07c6a9  jal         func_1F1AA4
    ctx->pc = 0x1F2938u;
    SET_GPR_U32(ctx, 31, 0x1F2940u);
    ctx->pc = 0x1F1AA4u;
    if (runtime->hasFunction(0x1F1AA4u)) {
        auto targetFn = runtime->lookupFunction(0x1F1AA4u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2940u; }
        if (ctx->pc != 0x1F2940u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1AA4_0x1f1aa4(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2940u; }
        if (ctx->pc != 0x1F2940u) { return; }
    }
    ctx->pc = 0x1F2940u;
label_1f2940:
    // 0x1f2940: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1f2940u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2944: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f2944u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2948: 0x8c420048  lw          $v0, 0x48($v0)
    ctx->pc = 0x1f2948u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 72)));
    // 0x1f294c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1f294cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1f2950: 0xac620048  sw          $v0, 0x48($v1)
    ctx->pc = 0x1f2950u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 72), GPR_U32(ctx, 2));
    // 0x1f2954: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f2954u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2958: 0x24420014  addiu       $v0, $v0, 0x14
    ctx->pc = 0x1f2958u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 20));
    // 0x1f295c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f295cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2960: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1f2960u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f2964: 0xc07c47a  jal         func_1F11E8
    ctx->pc = 0x1F2964u;
    SET_GPR_U32(ctx, 31, 0x1F296Cu);
    ctx->pc = 0x1F11E8u;
    if (runtime->hasFunction(0x1F11E8u)) {
        auto targetFn = runtime->lookupFunction(0x1F11E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F296Cu; }
        if (ctx->pc != 0x1F296Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F11E8_0x1f11e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F296Cu; }
        if (ctx->pc != 0x1F296Cu) { return; }
    }
    ctx->pc = 0x1F296Cu;
label_1f296c:
    // 0x1f296c: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1f296cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1f2970: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f2970u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f2974: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F2974u;
    {
        const bool branch_taken_0x1f2974 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f2974) {
            ctx->pc = 0x1F2988u;
            goto label_1f2988;
        }
    }
    ctx->pc = 0x1F297Cu;
    // 0x1f297c: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f297cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f2980: 0x10000051  b           . + 4 + (0x51 << 2)
    ctx->pc = 0x1F2980u;
    {
        const bool branch_taken_0x1f2980 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f2980) {
            ctx->pc = 0x1F2AC8u;
            goto label_1f2ac8;
        }
    }
    ctx->pc = 0x1F2988u;
label_1f2988:
    // 0x1f2988: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f2988u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f298c: 0x24420014  addiu       $v0, $v0, 0x14
    ctx->pc = 0x1f298cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 20));
    // 0x1f2990: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f2990u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2994: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1f2994u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f2998: 0xc07c44b  jal         func_1F112C
    ctx->pc = 0x1F2998u;
    SET_GPR_U32(ctx, 31, 0x1F29A0u);
    ctx->pc = 0x1F112Cu;
    if (runtime->hasFunction(0x1F112Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F112Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F29A0u; }
        if (ctx->pc != 0x1F29A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F112C_0x1f112c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F29A0u; }
        if (ctx->pc != 0x1F29A0u) { return; }
    }
    ctx->pc = 0x1F29A0u;
label_1f29a0:
    // 0x1f29a0: 0x10400012  beqz        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x1F29A0u;
    {
        const bool branch_taken_0x1f29a0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f29a0) {
            ctx->pc = 0x1F29ECu;
            goto label_1f29ec;
        }
    }
    ctx->pc = 0x1F29A8u;
    // 0x1f29a8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f29a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f29ac: 0x24420014  addiu       $v0, $v0, 0x14
    ctx->pc = 0x1f29acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 20));
    // 0x1f29b0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f29b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f29b4: 0xc07c441  jal         func_1F1104
    ctx->pc = 0x1F29B4u;
    SET_GPR_U32(ctx, 31, 0x1F29BCu);
    ctx->pc = 0x1F1104u;
    if (runtime->hasFunction(0x1F1104u)) {
        auto targetFn = runtime->lookupFunction(0x1F1104u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F29BCu; }
        if (ctx->pc != 0x1F29BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1104_0x1f1104(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F29BCu; }
        if (ctx->pc != 0x1F29BCu) { return; }
    }
    ctx->pc = 0x1F29BCu;
label_1f29bc:
    // 0x1f29bc: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1f29bcu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f29c0: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f29c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f29c4: 0x94420072  lhu         $v0, 0x72($v0)
    ctx->pc = 0x1f29c4u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 114)));
    // 0x1f29c8: 0x43102b  sltu        $v0, $v0, $v1
    ctx->pc = 0x1f29c8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1f29cc: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1F29CCu;
    {
        const bool branch_taken_0x1f29cc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f29cc) {
            ctx->pc = 0x1F29ECu;
            goto label_1f29ec;
        }
    }
    ctx->pc = 0x1F29D4u;
    // 0x1f29d4: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f29d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f29d8: 0x24420014  addiu       $v0, $v0, 0x14
    ctx->pc = 0x1f29d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 20));
    // 0x1f29dc: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f29dcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f29e0: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1f29e0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f29e4: 0xc07c46b  jal         func_1F11AC
    ctx->pc = 0x1F29E4u;
    SET_GPR_U32(ctx, 31, 0x1F29ECu);
    ctx->pc = 0x1F11ACu;
    if (runtime->hasFunction(0x1F11ACu)) {
        auto targetFn = runtime->lookupFunction(0x1F11ACu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F29ECu; }
        if (ctx->pc != 0x1F29ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F11AC_0x1f11ac(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F29ECu; }
        if (ctx->pc != 0x1F29ECu) { return; }
    }
    ctx->pc = 0x1F29ECu;
label_1f29ec:
    // 0x1f29ec: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1f29ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f29f0: 0xc07c6cd  jal         func_1F1B34
    ctx->pc = 0x1F29F0u;
    SET_GPR_U32(ctx, 31, 0x1F29F8u);
    ctx->pc = 0x1F1B34u;
    if (runtime->hasFunction(0x1F1B34u)) {
        auto targetFn = runtime->lookupFunction(0x1F1B34u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F29F8u; }
        if (ctx->pc != 0x1F29F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1B34_0x1f1b34(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F29F8u; }
        if (ctx->pc != 0x1F29F8u) { return; }
    }
    ctx->pc = 0x1F29F8u;
label_1f29f8:
    // 0x1f29f8: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1f29f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f29fc: 0x9463006a  lhu         $v1, 0x6A($v1)
    ctx->pc = 0x1f29fcu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 106)));
    // 0x1f2a00: 0x14430030  bne         $v0, $v1, . + 4 + (0x30 << 2)
    ctx->pc = 0x1F2A00u;
    {
        const bool branch_taken_0x1f2a00 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1f2a00) {
            ctx->pc = 0x1F2AC4u;
            goto label_1f2ac4;
        }
    }
    ctx->pc = 0x1F2A08u;
    // 0x1f2a08: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1f2a08u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f2a0c: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x1f2a0cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1f2a10: 0xc07c6a9  jal         func_1F1AA4
    ctx->pc = 0x1F2A10u;
    SET_GPR_U32(ctx, 31, 0x1F2A18u);
    ctx->pc = 0x1F1AA4u;
    if (runtime->hasFunction(0x1F1AA4u)) {
        auto targetFn = runtime->lookupFunction(0x1F1AA4u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2A18u; }
        if (ctx->pc != 0x1F2A18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1AA4_0x1f1aa4(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2A18u; }
        if (ctx->pc != 0x1F2A18u) { return; }
    }
    ctx->pc = 0x1F2A18u;
label_1f2a18:
    // 0x1f2a18: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1f2a18u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2a1c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f2a1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2a20: 0x8c420050  lw          $v0, 0x50($v0)
    ctx->pc = 0x1f2a20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 80)));
    // 0x1f2a24: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1f2a24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1f2a28: 0xac620050  sw          $v0, 0x50($v1)
    ctx->pc = 0x1f2a28u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 80), GPR_U32(ctx, 2));
    // 0x1f2a2c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f2a2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2a30: 0x24420028  addiu       $v0, $v0, 0x28
    ctx->pc = 0x1f2a30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 40));
    // 0x1f2a34: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f2a34u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2a38: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1f2a38u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1f2a3c: 0xc07c47a  jal         func_1F11E8
    ctx->pc = 0x1F2A3Cu;
    SET_GPR_U32(ctx, 31, 0x1F2A44u);
    ctx->pc = 0x1F11E8u;
    if (runtime->hasFunction(0x1F11E8u)) {
        auto targetFn = runtime->lookupFunction(0x1F11E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2A44u; }
        if (ctx->pc != 0x1F2A44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F11E8_0x1f11e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2A44u; }
        if (ctx->pc != 0x1F2A44u) { return; }
    }
    ctx->pc = 0x1F2A44u;
label_1f2a44:
    // 0x1f2a44: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1f2a44u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1f2a48: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f2a48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f2a4c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F2A4Cu;
    {
        const bool branch_taken_0x1f2a4c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f2a4c) {
            ctx->pc = 0x1F2A60u;
            goto label_1f2a60;
        }
    }
    ctx->pc = 0x1F2A54u;
    // 0x1f2a54: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f2a54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f2a58: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x1F2A58u;
    {
        const bool branch_taken_0x1f2a58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f2a58) {
            ctx->pc = 0x1F2AC8u;
            goto label_1f2ac8;
        }
    }
    ctx->pc = 0x1F2A60u;
label_1f2a60:
    // 0x1f2a60: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f2a60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2a64: 0x24420028  addiu       $v0, $v0, 0x28
    ctx->pc = 0x1f2a64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 40));
    // 0x1f2a68: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f2a68u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2a6c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1f2a6cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f2a70: 0xc07c44b  jal         func_1F112C
    ctx->pc = 0x1F2A70u;
    SET_GPR_U32(ctx, 31, 0x1F2A78u);
    ctx->pc = 0x1F112Cu;
    if (runtime->hasFunction(0x1F112Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F112Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2A78u; }
        if (ctx->pc != 0x1F2A78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F112C_0x1f112c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2A78u; }
        if (ctx->pc != 0x1F2A78u) { return; }
    }
    ctx->pc = 0x1F2A78u;
label_1f2a78:
    // 0x1f2a78: 0x10400012  beqz        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x1F2A78u;
    {
        const bool branch_taken_0x1f2a78 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f2a78) {
            ctx->pc = 0x1F2AC4u;
            goto label_1f2ac4;
        }
    }
    ctx->pc = 0x1F2A80u;
    // 0x1f2a80: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f2a80u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2a84: 0x24420028  addiu       $v0, $v0, 0x28
    ctx->pc = 0x1f2a84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 40));
    // 0x1f2a88: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f2a88u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2a8c: 0xc07c441  jal         func_1F1104
    ctx->pc = 0x1F2A8Cu;
    SET_GPR_U32(ctx, 31, 0x1F2A94u);
    ctx->pc = 0x1F1104u;
    if (runtime->hasFunction(0x1F1104u)) {
        auto targetFn = runtime->lookupFunction(0x1F1104u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2A94u; }
        if (ctx->pc != 0x1F2A94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1104_0x1f1104(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2A94u; }
        if (ctx->pc != 0x1F2A94u) { return; }
    }
    ctx->pc = 0x1F2A94u;
label_1f2a94:
    // 0x1f2a94: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1f2a94u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2a98: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f2a98u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2a9c: 0x94420074  lhu         $v0, 0x74($v0)
    ctx->pc = 0x1f2a9cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 116)));
    // 0x1f2aa0: 0x43102b  sltu        $v0, $v0, $v1
    ctx->pc = 0x1f2aa0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1f2aa4: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1F2AA4u;
    {
        const bool branch_taken_0x1f2aa4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f2aa4) {
            ctx->pc = 0x1F2AC4u;
            goto label_1f2ac4;
        }
    }
    ctx->pc = 0x1F2AACu;
    // 0x1f2aac: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f2aacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2ab0: 0x24420028  addiu       $v0, $v0, 0x28
    ctx->pc = 0x1f2ab0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 40));
    // 0x1f2ab4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1f2ab4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2ab8: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1f2ab8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f2abc: 0xc07c46b  jal         func_1F11AC
    ctx->pc = 0x1F2ABCu;
    SET_GPR_U32(ctx, 31, 0x1F2AC4u);
    ctx->pc = 0x1F11ACu;
    if (runtime->hasFunction(0x1F11ACu)) {
        auto targetFn = runtime->lookupFunction(0x1F11ACu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2AC4u; }
        if (ctx->pc != 0x1F2AC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F11AC_0x1f11ac(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2AC4u; }
        if (ctx->pc != 0x1F2AC4u) { return; }
    }
    ctx->pc = 0x1F2AC4u;
label_1f2ac4:
    // 0x1f2ac4: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1f2ac4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
label_1f2ac8:
    // 0x1f2ac8: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f2ac8u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2acc: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1f2accu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1f2ad0: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1f2ad0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1f2ad4: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1f2ad4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1f2ad8: 0x3e00008  jr          $ra
    ctx->pc = 0x1F2AD8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F2840u: goto label_1f2840;
            case 0x1F285Cu: goto label_1f285c;
            case 0x1F2868u: goto label_1f2868;
            case 0x1F2888u: goto label_1f2888;
            case 0x1F28ACu: goto label_1f28ac;
            case 0x1F28C8u: goto label_1f28c8;
            case 0x1F28D8u: goto label_1f28d8;
            case 0x1F28ECu: goto label_1f28ec;
            case 0x1F2914u: goto label_1f2914;
            case 0x1F2920u: goto label_1f2920;
            case 0x1F2940u: goto label_1f2940;
            case 0x1F296Cu: goto label_1f296c;
            case 0x1F2988u: goto label_1f2988;
            case 0x1F29A0u: goto label_1f29a0;
            case 0x1F29BCu: goto label_1f29bc;
            case 0x1F29ECu: goto label_1f29ec;
            case 0x1F29F8u: goto label_1f29f8;
            case 0x1F2A18u: goto label_1f2a18;
            case 0x1F2A44u: goto label_1f2a44;
            case 0x1F2A60u: goto label_1f2a60;
            case 0x1F2A78u: goto label_1f2a78;
            case 0x1F2A94u: goto label_1f2a94;
            case 0x1F2AC4u: goto label_1f2ac4;
            case 0x1F2AC8u: goto label_1f2ac8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F2AE0u;
    // 0x1f2ae0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f2ae0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f2ae4: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1f2ae4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1f2ae8: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f2ae8u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2aec: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f2aecu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f2af0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f2af0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2af4: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f2af4u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2af8: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1f2af8u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f2afc: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1f2afcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1f2b00: 0x3e00008  jr          $ra
    ctx->pc = 0x1F2B00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F2840u: goto label_1f2840;
            case 0x1F285Cu: goto label_1f285c;
            case 0x1F2868u: goto label_1f2868;
            case 0x1F2888u: goto label_1f2888;
            case 0x1F28ACu: goto label_1f28ac;
            case 0x1F28C8u: goto label_1f28c8;
            case 0x1F28D8u: goto label_1f28d8;
            case 0x1F28ECu: goto label_1f28ec;
            case 0x1F2914u: goto label_1f2914;
            case 0x1F2920u: goto label_1f2920;
            case 0x1F2940u: goto label_1f2940;
            case 0x1F296Cu: goto label_1f296c;
            case 0x1F2988u: goto label_1f2988;
            case 0x1F29A0u: goto label_1f29a0;
            case 0x1F29BCu: goto label_1f29bc;
            case 0x1F29ECu: goto label_1f29ec;
            case 0x1F29F8u: goto label_1f29f8;
            case 0x1F2A18u: goto label_1f2a18;
            case 0x1F2A44u: goto label_1f2a44;
            case 0x1F2A60u: goto label_1f2a60;
            case 0x1F2A78u: goto label_1f2a78;
            case 0x1F2A94u: goto label_1f2a94;
            case 0x1F2AC4u: goto label_1f2ac4;
            case 0x1F2AC8u: goto label_1f2ac8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F2B08u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
