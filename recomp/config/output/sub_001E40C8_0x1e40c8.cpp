#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E40C8
// Address: 0x1e40c8 - 0x1e42a0
void sub_001E40C8_0x1e40c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E40C8_0x1e40c8");
#endif

    switch (ctx->pc) {
        case 0x1e417cu: goto label_1e417c;
        case 0x1e41b0u: goto label_1e41b0;
        case 0x1e41d4u: goto label_1e41d4;
        case 0x1e4254u: goto label_1e4254;
        case 0x1e4284u: goto label_1e4284;
        default: break;
    }

    ctx->pc = 0x1e40c8u;

    // 0x1e40c8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1e40c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1e40cc: 0xffbe0020  sd          $fp, 0x20($sp)
    ctx->pc = 0x1e40ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 30));
    // 0x1e40d0: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x1e40d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x1e40d4: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e40d4u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e40d8: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e40d8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e40dc: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1e40dcu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1e40e0: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e40e0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e40e4: 0xafc00014  sw          $zero, 0x14($fp)
    ctx->pc = 0x1e40e4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 0));
    // 0x1e40e8: 0x8fc30000  lw          $v1, 0x0($fp)
    ctx->pc = 0x1e40e8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e40ec: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1e40ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1e40f0: 0x14620009  bne         $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1E40F0u;
    {
        const bool branch_taken_0x1e40f0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1e40f0) {
            ctx->pc = 0x1E4118u;
            goto label_1e4118;
        }
    }
    ctx->pc = 0x1E40F8u;
    // 0x1e40f8: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e40f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e40fc: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e40fcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e4100: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e4100u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e4104: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e4104u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e4108: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e4108u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e410c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e410cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4110: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4110u;
    {
        const bool branch_taken_0x1e4110 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e4110) {
            ctx->pc = 0x1E412Cu;
            goto label_1e412c;
        }
    }
    ctx->pc = 0x1E4118u;
label_1e4118:
    // 0x1e4118: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1e4118u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1e411c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e411cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4120: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4120u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4124: 0x10000058  b           . + 4 + (0x58 << 2)
    ctx->pc = 0x1E4124u;
    {
        const bool branch_taken_0x1e4124 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4124) {
            ctx->pc = 0x1E4288u;
            goto label_1e4288;
        }
    }
    ctx->pc = 0x1E412Cu;
label_1e412c:
    // 0x1e412c: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1e412cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e4130: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1e4130u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1e4134: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1e4134u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1e4138: 0x24429d08  addiu       $v0, $v0, -0x62F8
    ctx->pc = 0x1e4138u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1e413c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1e413cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1e4140: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1e4140u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e4144: 0xafc20014  sw          $v0, 0x14($fp)
    ctx->pc = 0x1e4144u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 20), GPR_U32(ctx, 2));
    // 0x1e4148: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e4148u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e414c: 0x8c42050c  lw          $v0, 0x50C($v0)
    ctx->pc = 0x1e414cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1e4150: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4150u;
    {
        const bool branch_taken_0x1e4150 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4150) {
            ctx->pc = 0x1E416Cu;
            goto label_1e416c;
        }
    }
    ctx->pc = 0x1E4158u;
    // 0x1e4158: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e4158u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e415c: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e415cu;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4160: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4160u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4164: 0x10000048  b           . + 4 + (0x48 << 2)
    ctx->pc = 0x1E4164u;
    {
        const bool branch_taken_0x1e4164 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4164) {
            ctx->pc = 0x1E4288u;
            goto label_1e4288;
        }
    }
    ctx->pc = 0x1E416Cu;
label_1e416c:
    // 0x1e416c: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e416cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e4170: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1e4170u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e4174: 0xc076c2e  jal         func_1DB0B8
    ctx->pc = 0x1E4174u;
    SET_GPR_U32(ctx, 31, 0x1E417Cu);
    ctx->pc = 0x1DB0B8u;
    if (runtime->hasFunction(0x1DB0B8u)) {
        auto targetFn = runtime->lookupFunction(0x1DB0B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E417Cu; }
        if (ctx->pc != 0x1E417Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB0B8_0x1db0b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E417Cu; }
        if (ctx->pc != 0x1E417Cu) { return; }
    }
    ctx->pc = 0x1E417Cu;
label_1e417c:
    // 0x1e417c: 0xafc2000c  sw          $v0, 0xC($fp)
    ctx->pc = 0x1e417cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 12), GPR_U32(ctx, 2));
    // 0x1e4180: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x1e4180u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e4184: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4184u;
    {
        const bool branch_taken_0x1e4184 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e4184) {
            ctx->pc = 0x1E41A0u;
            goto label_1e41a0;
        }
    }
    ctx->pc = 0x1E418Cu;
    // 0x1e418c: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e418cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e4190: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4190u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4194: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4194u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4198: 0x1000003b  b           . + 4 + (0x3B << 2)
    ctx->pc = 0x1E4198u;
    {
        const bool branch_taken_0x1e4198 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4198) {
            ctx->pc = 0x1E4288u;
            goto label_1e4288;
        }
    }
    ctx->pc = 0x1E41A0u;
label_1e41a0:
    // 0x1e41a0: 0x8fc4000c  lw          $a0, 0xC($fp)
    ctx->pc = 0x1e41a0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e41a4: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1e41a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e41a8: 0xc07cc3c  jal         func_1F30F0
    ctx->pc = 0x1E41A8u;
    SET_GPR_U32(ctx, 31, 0x1E41B0u);
    ctx->pc = 0x1F30F0u;
    if (runtime->hasFunction(0x1F30F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F30F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E41B0u; }
        if (ctx->pc != 0x1E41B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E41B0u; }
        if (ctx->pc != 0x1E41B0u) { return; }
    }
    ctx->pc = 0x1E41B0u;
label_1e41b0:
    // 0x1e41b0: 0xafc20010  sw          $v0, 0x10($fp)
    ctx->pc = 0x1e41b0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1e41b4: 0x8fc20010  lw          $v0, 0x10($fp)
    ctx->pc = 0x1e41b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e41b8: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1E41B8u;
    {
        const bool branch_taken_0x1e41b8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1e41b8) {
            ctx->pc = 0x1E41E8u;
            goto label_1e41e8;
        }
    }
    ctx->pc = 0x1E41C0u;
    // 0x1e41c0: 0x8fc20014  lw          $v0, 0x14($fp)
    ctx->pc = 0x1e41c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e41c4: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1e41c4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1e41c8: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e41c8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e41cc: 0xc07ca04  jal         func_1F2810
    ctx->pc = 0x1E41CCu;
    SET_GPR_U32(ctx, 31, 0x1E41D4u);
    ctx->pc = 0x1F2810u;
    if (runtime->hasFunction(0x1F2810u)) {
        auto targetFn = runtime->lookupFunction(0x1F2810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E41D4u; }
        if (ctx->pc != 0x1E41D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E41D4u; }
        if (ctx->pc != 0x1E41D4u) { return; }
    }
    ctx->pc = 0x1E41D4u;
label_1e41d4:
    // 0x1e41d4: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x1e41d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x1e41d8: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e41d8u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e41dc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e41dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e41e0: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x1E41E0u;
    {
        const bool branch_taken_0x1e41e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e41e0) {
            ctx->pc = 0x1E4288u;
            goto label_1e4288;
        }
    }
    ctx->pc = 0x1E41E8u;
label_1e41e8:
    // 0x1e41e8: 0x8fc50010  lw          $a1, 0x10($fp)
    ctx->pc = 0x1e41e8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1e41ec: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e41ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e41f0: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1e41f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1e41f4: 0x21e00  sll         $v1, $v0, 24
    ctx->pc = 0x1e41f4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x1e41f8: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1e41f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e41fc: 0x3042ff00  andi        $v0, $v0, 0xFF00
    ctx->pc = 0x1e41fcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65280);
    // 0x1e4200: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1e4200u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1e4204: 0x622025  or          $a0, $v1, $v0
    ctx->pc = 0x1e4204u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1e4208: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e4208u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e420c: 0x3c0200ff  lui         $v0, 0xFF
    ctx->pc = 0x1e420cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
    // 0x1e4210: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e4210u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e4214: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1e4214u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1e4218: 0x822025  or          $a0, $a0, $v0
    ctx->pc = 0x1e4218u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e421c: 0x8fc30004  lw          $v1, 0x4($fp)
    ctx->pc = 0x1e421cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1e4220: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1e4220u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1e4224: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1e4224u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1e4228: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1e4228u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1e422c: 0x821025  or          $v0, $a0, $v0
    ctx->pc = 0x1e422cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x1e4230: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1e4230u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1e4234: 0x8fc40014  lw          $a0, 0x14($fp)
    ctx->pc = 0x1e4234u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1e4238: 0x8fc5000c  lw          $a1, 0xC($fp)
    ctx->pc = 0x1e4238u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x1e423c: 0x3406a000  ori         $a2, $zero, 0xA000
    ctx->pc = 0x1e423cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)40960);
    // 0x1e4240: 0x24070004  addiu       $a3, $zero, 0x4
    ctx->pc = 0x1e4240u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1e4244: 0x24080043  addiu       $t0, $zero, 0x43
    ctx->pc = 0x1e4244u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 67));
    // 0x1e4248: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1e4248u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e424c: 0xc079d8f  jal         func_1E763C
    ctx->pc = 0x1E424Cu;
    SET_GPR_U32(ctx, 31, 0x1E4254u);
    ctx->pc = 0x1E763Cu;
    if (runtime->hasFunction(0x1E763Cu)) {
        auto targetFn = runtime->lookupFunction(0x1E763Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4254u; }
        if (ctx->pc != 0x1E4254u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4254u; }
        if (ctx->pc != 0x1E4254u) { return; }
    }
    ctx->pc = 0x1E4254u;
label_1e4254:
    // 0x1e4254: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1E4254u;
    {
        const bool branch_taken_0x1e4254 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4254) {
            ctx->pc = 0x1E4270u;
            goto label_1e4270;
        }
    }
    ctx->pc = 0x1E425Cu;
    // 0x1e425c: 0x24020066  addiu       $v0, $zero, 0x66
    ctx->pc = 0x1e425cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x1e4260: 0xaf828020  sw          $v0, -0x7FE0($gp)
    ctx->pc = 0x1e4260u;
    WRITE32(ADD32(GPR_U32(ctx, 28), 4294934560), GPR_U32(ctx, 2));
    // 0x1e4264: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1e4264u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1e4268: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1E4268u;
    {
        const bool branch_taken_0x1e4268 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1e4268) {
            ctx->pc = 0x1E4288u;
            goto label_1e4288;
        }
    }
    ctx->pc = 0x1E4270u;
label_1e4270:
    // 0x1e4270: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1e4270u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1e4274: 0x2405002e  addiu       $a1, $zero, 0x2E
    ctx->pc = 0x1e4274u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 46));
    // 0x1e4278: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1e4278u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e427c: 0xc076ad5  jal         func_1DAB54
    ctx->pc = 0x1E427Cu;
    SET_GPR_U32(ctx, 31, 0x1E4284u);
    ctx->pc = 0x1DAB54u;
    if (runtime->hasFunction(0x1DAB54u)) {
        auto targetFn = runtime->lookupFunction(0x1DAB54u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4284u; }
        if (ctx->pc != 0x1E4284u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAB54_0x1dab54(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E4284u; }
        if (ctx->pc != 0x1E4284u) { return; }
    }
    ctx->pc = 0x1E4284u;
label_1e4284:
    // 0x1e4284: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1e4284u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1e4288:
    // 0x1e4288: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e4288u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e428c: 0xdfbe0020  ld          $fp, 0x20($sp)
    ctx->pc = 0x1e428cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1e4290: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1e4290u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1e4294: 0x27bd0030  addiu       $sp, $sp, 0x30
    ctx->pc = 0x1e4294u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1e4298: 0x3e00008  jr          $ra
    ctx->pc = 0x1E4298u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E4118u: goto label_1e4118;
            case 0x1E412Cu: goto label_1e412c;
            case 0x1E416Cu: goto label_1e416c;
            case 0x1E417Cu: goto label_1e417c;
            case 0x1E41A0u: goto label_1e41a0;
            case 0x1E41B0u: goto label_1e41b0;
            case 0x1E41D4u: goto label_1e41d4;
            case 0x1E41E8u: goto label_1e41e8;
            case 0x1E4254u: goto label_1e4254;
            case 0x1E4270u: goto label_1e4270;
            case 0x1E4284u: goto label_1e4284;
            case 0x1E4288u: goto label_1e4288;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E42A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
