#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E78F8
// Address: 0x1e78f8 - 0x1e7a40
void sub_001E78F8_0x1e78f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E78F8_0x1e78f8");
#endif

    switch (ctx->pc) {
        case 0x1e7940u: goto label_1e7940;
        case 0x1e7990u: goto label_1e7990;
        case 0x1e79f0u: goto label_1e79f0;
        case 0x1e7a00u: goto label_1e7a00;
        case 0x1e7a14u: goto label_1e7a14;
        case 0x1e7a28u: goto label_1e7a28;
        default: break;
    }

    ctx->pc = 0x1e78f8u;

    // 0x1e78f8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e78f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e78fc: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e78fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e7900: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e7900u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e7904: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e7904u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7908: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e7908u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e790c: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e790cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e7910: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e7910u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e7914: 0xafc7000c  sw          $a3, 0xC($fp)
    ctx->pc = 0x1e7914u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 7));
    // 0x1e7918: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e7918u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e791c: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1e791cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1e7920: 0x27c30010  addiu       $v1, $fp, 0x10
    ctx->pc = 0x1e7920u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 16));
    // 0x1e7924: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e7924u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7928: 0x60282d  daddu       $a1, $v1, $zero
    ctx->pc = 0x1e7928u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e792c: 0x3c06001f  lui         $a2, 0x1F
    ctx->pc = 0x1e792cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)31 << 16));
    // 0x1e7930: 0x24c63e00  addiu       $a2, $a2, 0x3E00
    ctx->pc = 0x1e7930u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 15872));
    // 0x1e7934: 0x8fc70008  lw          $a3, 0x8($fp)
    ctx->pc = 0x1e7934u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e7938: 0xc07c56d  jal         func_1F15B4
    ctx->pc = 0x1E7938u;
    SET_GPR_U32(ctx, 31, 0x1E7940u);
    ctx->pc = 0x1F15B4u;
    if (runtime->hasFunction(0x1F15B4u)) {
        auto targetFn = runtime->lookupFunction(0x1F15B4u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7940u; }
        if (ctx->pc != 0x1E7940u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F15B4_0x1f15b4(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7940u; }
        if (ctx->pc != 0x1E7940u) { return; }
    }
    ctx->pc = 0x1E7940u;
label_1e7940:
    // 0x1e7940: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e7940u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e7944: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e7944u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e7948: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E7948u;
    {
        const bool branch_taken_0x1e7948 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1e7948) {
            ctx->pc = 0x1E7958u;
            goto label_1e7958;
        }
    }
    ctx->pc = 0x1E7950u;
    // 0x1e7950: 0x10000035  b           . + 4 + (0x35 << 2)
    ctx->pc = 0x1E7950u;
    {
        const bool branch_taken_0x1e7950 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e7950) {
            ctx->pc = 0x1E7A28u;
            goto label_1e7a28;
        }
    }
    ctx->pc = 0x1E7958u;
label_1e7958:
    // 0x1e7958: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e7958u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e795c: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x1E795Cu;
    {
        const bool branch_taken_0x1e795c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e795c) {
            ctx->pc = 0x1E79D4u;
            goto label_1e79d4;
        }
    }
    ctx->pc = 0x1E7964u;
    // 0x1e7964: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e7964u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e7968: 0x8c420060  lw          $v0, 0x60($v0)
    ctx->pc = 0x1e7968u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 96)));
    // 0x1e796c: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1e796cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1e7970: 0x27c30010  addiu       $v1, $fp, 0x10
    ctx->pc = 0x1e7970u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 16));
    // 0x1e7974: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1e7974u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7978: 0x60282d  daddu       $a1, $v1, $zero
    ctx->pc = 0x1e7978u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e797c: 0x3c06001f  lui         $a2, 0x1F
    ctx->pc = 0x1e797cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)31 << 16));
    // 0x1e7980: 0x24c63e00  addiu       $a2, $a2, 0x3E00
    ctx->pc = 0x1e7980u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 15872));
    // 0x1e7984: 0x8fc70008  lw          $a3, 0x8($fp)
    ctx->pc = 0x1e7984u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e7988: 0xc07c56d  jal         func_1F15B4
    ctx->pc = 0x1E7988u;
    SET_GPR_U32(ctx, 31, 0x1E7990u);
    ctx->pc = 0x1F15B4u;
    if (runtime->hasFunction(0x1F15B4u)) {
        auto targetFn = runtime->lookupFunction(0x1F15B4u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7990u; }
        if (ctx->pc != 0x1E7990u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F15B4_0x1f15b4(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7990u; }
        if (ctx->pc != 0x1E7990u) { return; }
    }
    ctx->pc = 0x1E7990u;
label_1e7990:
    // 0x1e7990: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e7990u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e7994: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e7994u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e7998: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E7998u;
    {
        const bool branch_taken_0x1e7998 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1e7998) {
            ctx->pc = 0x1E79A8u;
            goto label_1e79a8;
        }
    }
    ctx->pc = 0x1E79A0u;
    // 0x1e79a0: 0x10000021  b           . + 4 + (0x21 << 2)
    ctx->pc = 0x1E79A0u;
    {
        const bool branch_taken_0x1e79a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e79a0) {
            ctx->pc = 0x1E7A28u;
            goto label_1e7a28;
        }
    }
    ctx->pc = 0x1E79A8u;
label_1e79a8:
    // 0x1e79a8: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e79a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e79ac: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E79ACu;
    {
        const bool branch_taken_0x1e79ac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e79ac) {
            ctx->pc = 0x1E79BCu;
            goto label_1e79bc;
        }
    }
    ctx->pc = 0x1E79B4u;
    // 0x1e79b4: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x1E79B4u;
    {
        const bool branch_taken_0x1e79b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e79b4) {
            ctx->pc = 0x1E7A28u;
            goto label_1e7a28;
        }
    }
    ctx->pc = 0x1E79BCu;
label_1e79bc:
    // 0x1e79bc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e79bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e79c0: 0x8c420060  lw          $v0, 0x60($v0)
    ctx->pc = 0x1e79c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 96)));
    // 0x1e79c4: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1e79c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1e79c8: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e79c8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e79cc: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1E79CCu;
    {
        const bool branch_taken_0x1e79cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e79cc) {
            ctx->pc = 0x1E79E0u;
            goto label_1e79e0;
        }
    }
    ctx->pc = 0x1E79D4u;
label_1e79d4:
    // 0x1e79d4: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e79d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e79d8: 0x24420008  addiu       $v0, $v0, 0x8
    ctx->pc = 0x1e79d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
    // 0x1e79dc: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e79dcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
label_1e79e0:
    // 0x1e79e0: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e79e0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e79e4: 0x24050800  addiu       $a1, $zero, 0x800
    ctx->pc = 0x1e79e4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
    // 0x1e79e8: 0xc07c680  jal         func_1F1A00
    ctx->pc = 0x1E79E8u;
    SET_GPR_U32(ctx, 31, 0x1E79F0u);
    ctx->pc = 0x1F1A00u;
    if (runtime->hasFunction(0x1F1A00u)) {
        auto targetFn = runtime->lookupFunction(0x1F1A00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E79F0u; }
        if (ctx->pc != 0x1E79F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1A00_0x1f1a00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E79F0u; }
        if (ctx->pc != 0x1E79F0u) { return; }
    }
    ctx->pc = 0x1E79F0u;
label_1e79f0:
    // 0x1e79f0: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e79f0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e79f4: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e79f4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e79f8: 0xc07c4c3  jal         func_1F130C
    ctx->pc = 0x1E79F8u;
    SET_GPR_U32(ctx, 31, 0x1E7A00u);
    ctx->pc = 0x1F130Cu;
    if (runtime->hasFunction(0x1F130Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F130Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7A00u; }
        if (ctx->pc != 0x1E7A00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F130C_0x1f130c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7A00u; }
        if (ctx->pc != 0x1E7A00u) { return; }
    }
    ctx->pc = 0x1E7A00u;
label_1e7a00:
    // 0x1e7a00: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e7a00u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e7a04: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e7a04u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e7a08: 0x8fc6000c  lw          $a2, 0xC($fp)
    ctx->pc = 0x1e7a08u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e7a0c: 0xc079dfd  jal         func_1E77F4
    ctx->pc = 0x1E7A0Cu;
    SET_GPR_U32(ctx, 31, 0x1E7A14u);
    ctx->pc = 0x1E77F4u;
    if (runtime->hasFunction(0x1E77F4u)) {
        auto targetFn = runtime->lookupFunction(0x1E77F4u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7A14u; }
        if (ctx->pc != 0x1E7A14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E77F4_0x1e77f4(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7A14u; }
        if (ctx->pc != 0x1E7A14u) { return; }
    }
    ctx->pc = 0x1E7A14u;
label_1e7a14:
    // 0x1e7a14: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e7a14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e7a18: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e7a18u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e7a1c: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e7a1cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e7a20: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E7A20u;
    SET_GPR_U32(ctx, 31, 0x1E7A28u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7A28u; }
        if (ctx->pc != 0x1E7A28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7A28u; }
        if (ctx->pc != 0x1E7A28u) { return; }
    }
    ctx->pc = 0x1E7A28u;
label_1e7a28:
    // 0x1e7a28: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e7a28u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7a2c: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e7a2cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e7a30: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e7a30u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e7a34: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e7a34u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e7a38: 0x3e00008  jr          $ra
    ctx->pc = 0x1E7A38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E7940u: goto label_1e7940;
            case 0x1E7958u: goto label_1e7958;
            case 0x1E7990u: goto label_1e7990;
            case 0x1E79A8u: goto label_1e79a8;
            case 0x1E79BCu: goto label_1e79bc;
            case 0x1E79D4u: goto label_1e79d4;
            case 0x1E79E0u: goto label_1e79e0;
            case 0x1E79F0u: goto label_1e79f0;
            case 0x1E7A00u: goto label_1e7a00;
            case 0x1E7A14u: goto label_1e7a14;
            case 0x1E7A28u: goto label_1e7a28;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E7A40u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
