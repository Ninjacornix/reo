#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E5FB8
// Address: 0x1e5fb8 - 0x1e6188
void sub_001E5FB8_0x1e5fb8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E5FB8_0x1e5fb8");
#endif

    switch (ctx->pc) {
        case 0x1e6068u: goto label_1e6068;
        case 0x1e6094u: goto label_1e6094;
        case 0x1e60ccu: goto label_1e60cc;
        case 0x1e60f0u: goto label_1e60f0;
        case 0x1e6118u: goto label_1e6118;
        case 0x1e613cu: goto label_1e613c;
        case 0x1e616cu: goto label_1e616c;
        default: break;
    }

    ctx->pc = 0x1e5fb8u;

    // 0x1e5fb8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e5fb8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e5fbc: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e5fbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e5fc0: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e5fc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e5fc4: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e5fc4u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e5fc8: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e5fc8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e5fcc: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e5fccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e5fd0: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e5fd0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e5fd4: 0xafc00014  sw          $zero, 0x14($fp)
    ctx->pc = 0x1e5fd4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
    // 0x1e5fd8: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e5fd8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5fdc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e5fdcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e5fe0: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E5FE0u;
    {
        const bool branch_taken_0x1e5fe0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e5fe0) {
            ctx->pc = 0x1E6008u;
            goto label_1e6008;
        }
    }
    ctx->pc = 0x1E5FE8u;
    // 0x1e5fe8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e5fe8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e5fec: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e5fecu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e5ff0: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e5ff0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e5ff4: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e5ff4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e5ff8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e5ff8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e5ffc: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e5ffcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e6000: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E6000u;
    {
        const bool branch_taken_0x1e6000 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e6000) {
            ctx->pc = 0x1E601Cu;
            goto label_1e601c;
        }
    }
    ctx->pc = 0x1E6008u;
label_1e6008:
    // 0x1e6008: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e6008u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e600c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e600cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e6010: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e6010u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6014: 0x10000056  b           . + 4 + (0x56 << 2)
    ctx->pc = 0x1E6014u;
    {
        const bool branch_taken_0x1e6014 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6014) {
            ctx->pc = 0x1E6170u;
            goto label_1e6170;
        }
    }
    ctx->pc = 0x1E601Cu;
label_1e601c:
    // 0x1e601c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e601cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e6020: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e6020u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e6024: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e6024u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e6028: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e6028u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e602c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e602cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e6030: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e6030u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e6034: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e6034u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e6038: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e6038u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e603c: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e603cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e6040: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E6040u;
    {
        const bool branch_taken_0x1e6040 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6040) {
            ctx->pc = 0x1E605Cu;
            goto label_1e605c;
        }
    }
    ctx->pc = 0x1E6048u;
    // 0x1e6048: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e6048u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e604c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e604cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e6050: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e6050u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6054: 0x10000046  b           . + 4 + (0x46 << 2)
    ctx->pc = 0x1E6054u;
    {
        const bool branch_taken_0x1e6054 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6054) {
            ctx->pc = 0x1E6170u;
            goto label_1e6170;
        }
    }
    ctx->pc = 0x1E605Cu;
label_1e605c:
    // 0x1e605c: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1e605cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e6060: 0xc042c56  jal         func_10B158
    ctx->pc = 0x1E6060u;
    SET_GPR_U32(ctx, 31, 0x1E6068u);
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6068u; }
        if (ctx->pc != 0x1E6068u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6068u; }
        if (ctx->pc != 0x1E6068u) { return; }
    }
    ctx->pc = 0x1E6068u;
label_1e6068:
    // 0x1e6068: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e6068u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
    // 0x1e606c: 0x8fc20018  lw          $v0, 0x18($fp)
    ctx->pc = 0x1e606cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e6070: 0x2c420369  sltiu       $v0, $v0, 0x369
    ctx->pc = 0x1e6070u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)873) ? 1 : 0);
    // 0x1e6074: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1E6074u;
    {
        const bool branch_taken_0x1e6074 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e6074) {
            ctx->pc = 0x1E6084u;
            goto label_1e6084;
        }
    }
    ctx->pc = 0x1E607Cu;
    // 0x1e607c: 0x24020368  addiu       $v0, $zero, 0x368
    ctx->pc = 0x1e607cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 872));
    // 0x1e6080: 0xafc20018  sw          $v0, 0x18($fp)
    ctx->pc = 0x1e6080u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 24), GPR_U32(ctx, 2));
label_1e6084:
    // 0x1e6084: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e6084u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e6088: 0x8fc50018  lw          $a1, 0x18($fp)
    ctx->pc = 0x1e6088u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e608c: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E608Cu;
    SET_GPR_U32(ctx, 31, 0x1E6094u);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6094u; }
        if (ctx->pc != 0x1E6094u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6094u; }
        if (ctx->pc != 0x1E6094u) { return; }
    }
    ctx->pc = 0x1E6094u;
label_1e6094:
    // 0x1e6094: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e6094u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e6098: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e6098u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e609c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E609Cu;
    {
        const bool branch_taken_0x1e609c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e609c) {
            ctx->pc = 0x1E60B8u;
            goto label_1e60b8;
        }
    }
    ctx->pc = 0x1E60A4u;
    // 0x1e60a4: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e60a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e60a8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e60a8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e60ac: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e60acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e60b0: 0x1000002f  b           . + 4 + (0x2F << 2)
    ctx->pc = 0x1E60B0u;
    {
        const bool branch_taken_0x1e60b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e60b0) {
            ctx->pc = 0x1E6170u;
            goto label_1e6170;
        }
    }
    ctx->pc = 0x1E60B8u;
label_1e60b8:
    // 0x1e60b8: 0x97c20018  lhu         $v0, 0x18($fp)
    ctx->pc = 0x1e60b8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e60bc: 0x8fc40010  lw          $a0, 0x10($fp)
    ctx->pc = 0x1e60bcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e60c0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1e60c0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e60c4: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E60C4u;
    SET_GPR_U32(ctx, 31, 0x1E60CCu);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E60CCu; }
        if (ctx->pc != 0x1E60CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E60CCu; }
        if (ctx->pc != 0x1E60CCu) { return; }
    }
    ctx->pc = 0x1E60CCu;
label_1e60cc:
    // 0x1e60cc: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e60ccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e60d0: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e60d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e60d4: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E60D4u;
    {
        const bool branch_taken_0x1e60d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e60d4) {
            ctx->pc = 0x1E6104u;
            goto label_1e6104;
        }
    }
    ctx->pc = 0x1E60DCu;
    // 0x1e60dc: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e60dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e60e0: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e60e0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e60e4: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e60e4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e60e8: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E60E8u;
    SET_GPR_U32(ctx, 31, 0x1E60F0u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E60F0u; }
        if (ctx->pc != 0x1E60F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E60F0u; }
        if (ctx->pc != 0x1E60F0u) { return; }
    }
    ctx->pc = 0x1E60F0u;
label_1e60f0:
    // 0x1e60f0: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e60f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e60f4: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e60f4u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e60f8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e60f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e60fc: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x1E60FCu;
    {
        const bool branch_taken_0x1e60fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e60fc) {
            ctx->pc = 0x1E6170u;
            goto label_1e6170;
        }
    }
    ctx->pc = 0x1E6104u;
label_1e6104:
    // 0x1e6104: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e6104u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e6108: 0x8fc50004  lw          $a1, 0x4($fp)
    ctx->pc = 0x1e6108u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e610c: 0x8fc60018  lw          $a2, 0x18($fp)
    ctx->pc = 0x1e610cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e6110: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x1E6110u;
    SET_GPR_U32(ctx, 31, 0x1E6118u);
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6118u; }
        if (ctx->pc != 0x1E6118u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E6118u; }
        if (ctx->pc != 0x1E6118u) { return; }
    }
    ctx->pc = 0x1E6118u;
label_1e6118:
    // 0x1e6118: 0x97c20018  lhu         $v0, 0x18($fp)
    ctx->pc = 0x1e6118u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 24)));
    // 0x1e611c: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e611cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e6120: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e6120u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e6124: 0x3406b000  ori         $a2, $zero, 0xB000
    ctx->pc = 0x1e6124u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)45056);
    // 0x1e6128: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x1e6128u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e612c: 0x24080034  addiu       $t0, $zero, 0x34
    ctx->pc = 0x1e612cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 52));
    // 0x1e6130: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e6130u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6134: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E6134u;
    SET_GPR_U32(ctx, 31, 0x1E613Cu);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E613Cu; }
        if (ctx->pc != 0x1E613Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E613Cu; }
        if (ctx->pc != 0x1E613Cu) { return; }
    }
    ctx->pc = 0x1E613Cu;
label_1e613c:
    // 0x1e613c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E613Cu;
    {
        const bool branch_taken_0x1e613c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e613c) {
            ctx->pc = 0x1E6158u;
            goto label_1e6158;
        }
    }
    ctx->pc = 0x1E6144u;
    // 0x1e6144: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e6144u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e6148: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e6148u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e614c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e614cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e6150: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1E6150u;
    {
        const bool branch_taken_0x1e6150 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e6150) {
            ctx->pc = 0x1E6170u;
            goto label_1e6170;
        }
    }
    ctx->pc = 0x1E6158u;
label_1e6158:
    // 0x1e6158: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e6158u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e615c: 0x2405002a  addiu       $a1, $zero, 0x2A
    ctx->pc = 0x1e615cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 42));
    // 0x1e6160: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1e6160u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e6164: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E6164u;
    SET_GPR_U32(ctx, 31, 0x1E616Cu);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E616Cu; }
        if (ctx->pc != 0x1E616Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E616Cu; }
        if (ctx->pc != 0x1E616Cu) { return; }
    }
    ctx->pc = 0x1E616Cu;
label_1e616c:
    // 0x1e616c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e616cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e6170:
    // 0x1e6170: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e6170u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e6174: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e6174u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e6178: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e6178u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e617c: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e617cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e6180: 0x3e00008  jr          $ra
    ctx->pc = 0x1E6180u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E6008u: goto label_1e6008;
            case 0x1E601Cu: goto label_1e601c;
            case 0x1E605Cu: goto label_1e605c;
            case 0x1E6068u: goto label_1e6068;
            case 0x1E6084u: goto label_1e6084;
            case 0x1E6094u: goto label_1e6094;
            case 0x1E60B8u: goto label_1e60b8;
            case 0x1E60CCu: goto label_1e60cc;
            case 0x1E60F0u: goto label_1e60f0;
            case 0x1E6104u: goto label_1e6104;
            case 0x1E6118u: goto label_1e6118;
            case 0x1E613Cu: goto label_1e613c;
            case 0x1E6158u: goto label_1e6158;
            case 0x1E616Cu: goto label_1e616c;
            case 0x1E6170u: goto label_1e6170;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E6188u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
